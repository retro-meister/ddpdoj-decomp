#include "gallery/gallery.h"
#include "disc_image.h"
#include "gs.h"

#include <SDL3/SDL.h>

_Alignas(64) u8 g_gif_buf[2][0x10000];
void *g_dma_gif;
GalleryContext *g_gallery;

static void require(bool condition, const char *message)
{
    if (!condition) {
        SDL_LogError(SDL_LOG_CATEGORY_TEST, "%s (%s)", message, SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

static void expect_pixel(SDL_Surface *surface, int x, int y, u8 red, u8 green, u8 blue)
{
    u8 r, g, b;
    require(SDL_ReadSurfacePixel(surface, x, y, &r, &g, &b, NULL), "Read Gallery pixel");
    if (SDL_abs((int)r - red) > 1 || SDL_abs((int)g - green) > 1 ||
        SDL_abs((int)b - blue) > 1) {
        SDL_LogError(SDL_LOG_CATEGORY_TEST, "(%d,%d) read (%u,%u,%u), expected (%u,%u,%u)",
                     x, y, r, g, b, red, green, blue);
        exit(EXIT_FAILURE);
    }
}

static void upload(s16 base, s16 format, s16 x, s16 y, s16 width, s16 height, const void *data)
{
    sceGsLoadImage packet;
    require(sceGsSetDefLoadImage(&packet, base, 16, format, x, y, width, height) == 0 &&
            sceGsExecLoadImage(&packet, data) == 0, "Upload Gallery image data");
}

static void add_register(sceGifPacket *packet, u64 address, u64 value)
{
    sceGifPkAddGsData(packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(packet, value);
    sceGifPkAddGsData(packet, address);
}

static void send_packet(sceGifPacket *packet)
{
    sceGifPkTerminate(packet);
    sceDmaSendN(g_dma_gif, g_gif_buf, sceGifPkSize(packet));
    require(pc_gs_ok(), "Submit Gallery texture packet");
}

static void draw_texture(u64 tex0, unsigned x, unsigned y)
{
    sceGifPacket packet;
    sceGifPkInit(&packet, g_gif_buf);
    add_register(&packet, SCE_GS_TEX0_1, tex0);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 6));
    sceGifPkAddGsData(&packet, 0x535310);
    sceGifPkAddGsData(&packet, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 0, 0, 1, 0, 0));
    sceGifPkAddGsData(&packet, SCE_GS_SET_RGBAQ(0x80, 0x80, 0x80, 0x80, 0));
    sceGifPkAddGsData(&packet, 0);
    sceGifPkAddGsData(&packet, SCE_GS_SET_XYZ2(x * 16 + 0x6C00, y * 8 + 0x7900, 0));
    sceGifPkAddGsData(&packet, SCE_GS_SET_UV(4 * 16, 2 * 16));
    sceGifPkAddGsData(&packet, SCE_GS_SET_XYZ2((x + 32) * 16 + 0x6C00, (y + 16) * 8 + 0x7900, 0));
    send_packet(&packet);
}

static void draw_packed_texture(u64 tex0)
{
    sceGifPacket packet;
    sceGifPkInit(&packet, g_gif_buf);
    add_register(&packet, SCE_GS_TEX0_1, tex0);
    u64 prim = SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 0, 0, 1, 0, 0);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 1, prim, SCE_GIF_PACKED, 6));
    sceGifPkAddGsData(&packet, 0x531531);
    for (unsigned i = 0; i < 2; i++) {
        sceGifPkAddGsData(&packet, 0x8000000080ULL);
        sceGifPkAddGsData(&packet, 0x8000000080ULL);
        sceGifPkAddGsData(&packet, i ? (2ULL << 36) | (4 << 4) : 0);
        sceGifPkAddGsData(&packet, 0);
        unsigned x = 200 + 32 * i;
        unsigned y = 8 + 16 * i;
        sceGifPkAddGsData(&packet, ((u64)(y * 8 + 0x7900) << 32) | (x * 16 + 0x6C00));
        sceGifPkAddGsData(&packet, 0);
    }
    sceGifPkTerminate(&packet);

    u64 chain[24] = {0};
    s32 quadwords = sceGifPkSize(&packet);
    chain[0] = 0x10000000 | quadwords;
    SDL_memcpy(chain + 2, g_gif_buf, quadwords * 16);
    chain[2 + quadwords * 2] = 0x70000000;
    pc_dma_send_chain(g_dma_gif, chain, sizeof(chain));
    require(pc_gs_ok(), "Submit a packed Gallery sprite through a DMA chain");
}

enum { FONT_BASE = 0x1E40, FONT_PALETTE = 0x3830, FONT_WIDTH = 1024, FONT_HEIGHT = 512 };

static void draw_loading_letter(const u8 *atlas, const u16 *palette, unsigned x, unsigned y)
{
    upload(FONT_PALETTE, SCE_GS_PSMCT16, 0, 0, 8, 2, palette);
    for (int row = 0; row < FONT_HEIGHT; row += 256) {
        upload(FONT_BASE, SCE_GS_PSMT4, 0, row, FONT_WIDTH, 256, atlas + row * (FONT_WIDTH / 2));
    }
    sceGifPacket packet;
    sceGifPkInit(&packet, g_gif_buf);
    add_register(&packet, SCE_GS_TEXA, SCE_GS_SET_TEXA(0, 0, 0x80));
    add_register(&packet, SCE_GS_TEX0_1,
                 SCE_GS_SET_TEX0(FONT_BASE, 16, SCE_GS_PSMT4, 10, 10, 1, 0, FONT_PALETTE,
                                SCE_GS_PSMCT16, 0, 0, 1));
    bmp_draw_ascii_char(&packet, x, y, 'A');
    send_packet(&packet);
}

static void check_texture_draws(SDL_Renderer *renderer)
{
    enum { BASE = 0x1400, PALETTE = 0x1700 };
    g_gallery = SDL_calloc(1, sizeof(*g_gallery));
    require(g_gallery != NULL, "Allocate Gallery BMP scratch space");
    u8 palette[256][4] = { [8] = { 96, 64, 24, 0 }, [22] = { 32, 24, 192, 0 } };
    const u8 pixels[2][4] = { { 8, 22, 0, 8 }, { 22, 22, 8, 8 } };
    u64 tex0 = SCE_GS_SET_TEX0(BASE, 16, SCE_GS_PSMT8, 2, 1, 1, 0, PALETTE, SCE_GS_PSMCT32, 0, 0, 1);
    bmp_upload_clut(PALETTE, &palette[0][0], 256);
    upload(BASE, SCE_GS_PSMT8, 0, 0, 4, 2, pixels);
    require(SDL_SetRenderDrawColor(renderer, 20, 30, 40, 255) && SDL_RenderClear(renderer),
            "Clear the textured Gallery target");
    draw_texture(tex0, 8, 8);

    /* Update one texel and draw again before SDL has presented the old texture. */
    const u8 changed[1] = {22};
    upload(BASE, SCE_GS_PSMT8, 0, 0, 1, 1, changed);
    draw_texture(tex0, 48, 8);

    /* Recoloring the CLUT must refresh both the updated and the untouched texels. */
    palette[22][0] = 216;
    bmp_upload_clut(PALETTE, &palette[0][0], 256);
    draw_texture(tex0, 88, 8);
    draw_packed_texture(tex0);

    /* Exercise the loading-screen code's real triangle-fan ASCII packet. */
    static u8 atlas[FONT_HEIGHT * FONT_WIDTH / 2];
    SDL_memset(atlas, 0x11, sizeof(atlas));
    const u16 font_palette[16] = { [1] = (u16)RGBA5551(15, 9, 30, 1) };
    draw_loading_letter(atlas, font_palette, 160, 8);

    SDL_Surface *surface = SDL_RenderReadPixels(renderer, NULL);
    require(surface != NULL, "Read the textured Gallery frame");
    expect_pixel(surface, 11, 11, 24, 64, 96);
    expect_pixel(surface, 19, 11, 192, 24, 32);
    expect_pixel(surface, 27, 11, 20, 30, 40);
    expect_pixel(surface, 51, 11, 192, 24, 32);
    expect_pixel(surface, 51, 19, 192, 24, 32);
    expect_pixel(surface, 91, 11, 192, 24, 216);
    expect_pixel(surface, 99, 19, 192, 24, 216);
    expect_pixel(surface, 166, 11, 120, 72, 240);
    expect_pixel(surface, 166, 21, 120, 72, 240);
    expect_pixel(surface, 203, 11, 192, 24, 216);
    expect_pixel(surface, 219, 11, 20, 30, 40);
    SDL_DestroySurface(surface);
    SDL_free(g_gallery);
    g_gallery = NULL;
}

static void check_retail_loading_letter(SDL_Renderer *renderer, const char *iso)
{
    static u8 atlas[FONT_WIDTH * FONT_HEIGHT / 2];
    extern s16 g_tex_clut_palette_16[16];
    u16 palette[16];
    DiscExtent entry;
    DiscImage *disc = disc_image_open(iso);
    require(disc != NULL && disc_image_find(disc, "DATA/DDON3_02.DAT", &entry) &&
            entry.size == sizeof(atlas) &&
            disc_image_read(disc, (u64)entry.lba * DISC_SECTOR_SIZE, atlas, sizeof(atlas)),
            "Read the retail Gallery font from the disc");
    disc_image_close(disc);
    for (unsigned int i = 0; i < 16; i++) {
        palette[i] = g_tex_clut_palette_16[i] | (i == 15 ? 0 : 0x8000);
    }
    require(SDL_SetRenderDrawColor(renderer, 12, 24, 36, 255) && SDL_RenderClear(renderer),
            "Clear the retail Gallery frame");
    draw_loading_letter(atlas, palette, 0, 0);
    SDL_Surface *surface = SDL_RenderReadPixels(renderer, NULL);
    require(surface != NULL, "Read the retail Gallery frame");
    expect_pixel(surface, 0, 0, 12, 24, 36);
    expect_pixel(surface, 7, 3, 80, 48, 40);
    expect_pixel(surface, 16, 0, 12, 24, 36);
    SDL_DestroySurface(surface);
}

int main(int argc, char **argv)
{
    const char *driver = NULL;
    int next = 1;
    if (argc > next && SDL_strcmp(argv[next], "--retail") != 0) {
        driver = argv[next++];
    }
    require(argc == next || (argc == next + 2 && SDL_strcmp(argv[next], "--retail") == 0),
            "Expected an optional SDL renderer and --retail followed by the ISO path");
    SDL_Window *window = NULL;
    SDL_Surface *canvas = NULL;
    SDL_Renderer *renderer;
    require(SDL_Init(driver ? SDL_INIT_VIDEO : 0), "Initialize SDL");
    if (driver) {
        window = SDL_CreateWindow("Gallery draw test", 640, 448, SDL_WINDOW_HIDDEN);
        require(window != NULL, "Open Gallery window");
        renderer = SDL_CreateRenderer(window, driver);
    } else {
        canvas = SDL_CreateSurface(640, 448, SDL_PIXELFORMAT_RGBA32);
        require(canvas != NULL, "Create Gallery surface");
        renderer = SDL_CreateSoftwareRenderer(canvas);
    }
    require(renderer != NULL, "Create Gallery renderer");
    pc_gs_bind_gallery(renderer);
    g_dma_gif = sceDmaGetChan(SCE_DMA_GIF);
    require(g_dma_gif != NULL, "Get GIF channel");
    require(SDL_SetRenderDrawColor(renderer, 16, 32, 64, 255) && SDL_RenderClear(renderer),
            "Clear Gallery target");

    gallery_draw_solid_rect(32, 80, 64, 120, 112, 128, 160, 64, 0);
    gallery_draw_solid_rect(32, 80, 48, 100, 80, 64, 32, 64, 1);
    if (driver) {
        gallery_draw_solid_rect(32, 80, 48, 100, 20, 32, 36, 0x80, 2);
    }
    require(pc_gs_ok(), "Submit Gallery overlays");
    SDL_Surface *readback = SDL_RenderReadPixels(renderer, NULL);
    require(readback != NULL, "Read Gallery frame");
    expect_pixel(readback, 31, 80, 16, 32, 64);
    expect_pixel(readback, 40, 79, 16, 32, 64);
    expect_pixel(readback, 48, 100, 64, 80, 112);
    expect_pixel(readback, 63, 119, 64, 80, 112);
    expect_pixel(readback, 64, 119, 16, 32, 64);
    expect_pixel(readback, 47, 99, driver ? 84 : 104, driver ? 80 : 112, driver ? 92 : 128);
    SDL_DestroySurface(readback);

    /* The preceding rectangle wrote five quadwords of GIF data. */
    u64 chain[14] = { 0x10000005 };
    SDL_memcpy(chain + 2, g_gif_buf[0], 5 * 16);
    pc_dma_send_chain(g_dma_gif, chain, sizeof(chain) - 16);
    require(!pc_gs_ok(), "Reject a GIF chain with no END tag");
    pc_gs_bind_gallery(renderer);
    pc_dma_send_chain(g_dma_gif, chain, sizeof(chain) - 17);
    require(!pc_gs_ok(), "Reject a GIF chain shorter than its payload");
    pc_gs_bind_gallery(renderer);
    require(SDL_SetRenderDrawColor(renderer, 160, 160, 160, 255) && SDL_RenderClear(renderer),
            "Clear the target before resubmitting the DMA payload");
    chain[12] = 0x70000000;
    pc_dma_send_chain(g_dma_gif, chain, sizeof(chain));
    require(pc_gs_ok(), "Accept a complete GIF DMA chain");
    readback = SDL_RenderReadPixels(renderer, NULL);
    require(readback != NULL, "Read the output of a GIF DMA chain");
    expect_pixel(readback, 47, 99, driver ? 140 : 200, driver ? 128 : 192, driver ? 124 : 176);
    expect_pixel(readback, 48, 100, 160, 160, 160);
    SDL_DestroySurface(readback);

    check_texture_draws(renderer);
    if (argc > next) {
        check_retail_loading_letter(renderer, argv[next + 1]);
    }

    pc_gs_bind_gallery(NULL);
    SDL_DestroyRenderer(renderer);
    SDL_DestroySurface(canvas);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
