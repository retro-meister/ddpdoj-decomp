#include "gallery/gallery.h"

typedef struct {
    u32 archivePosition;
    u32 entryLocation;
} GalleryArchiveEntry;

typedef struct {
    u8 readBuf[0x101000];
    u8 decodeBuf[0x303000];
    u8 textureBuffer[0x101000];
    s32 menu_params[12];
    u8 pad_505030[4];
    GalleryView sprites[2];
    GalleryView *curSprite;
    GalleryView *prevSprite;
    s32 exitRequested;
    s32 mode;
    s32 state;
    s32 unk_505150;
    s32 unk_505154;
    s32 timer;
    s32 countdown;
    s32 exitMode;
    s16 overlayEnabled;
    s16 overlayAdjustment;
    s32 unk_505168;
    s16 fadeState;
    s8 dialogState;
    s8 drawEnabled;
    SpriteInfo pageSprites[6];
    SpriteInfo allSprites[37];
    SpriteInfo viewerTextures[2];
    SpriteInfo bgSprite;
    SpriteInfo uiSprites[6];
    u8 pad_5054B0[0x30];
    SpriteInfo uiAtlasSprite;
    u8 pad_5054F0[0x8];
    s32 box_x0;
    s32 box_y0;
    s32 box_x1;
    s32 box_y1;
    u8 box_color_r;
    u8 box_color_g;
    u8 box_color_b;
    u8 box_color_a;
    u8 pad_50550C[0x1C];
    u8 cursor_color_r;
    u8 cursor_color_g;
    u8 cursor_color_b;
    u8 cursor_color_a;
    s32 unk_50552C;
    s32 unk_505530;
    u8 pad_505534[4];
    s16 scrollX;
    s16 scrollDirection;
    s32 slotIndex;
    s32 itemCount;
    s32 pageOffset;
    s32 currentThumbId;
    s8 activeBuffer;
    s8 bufferPending;
    s8 isInitialized;
    s8 dialogChoice;
    s16 uiX0[8];
    s16 uiY0[8];
    s16 uiX1[8];
    s16 uiY1[8];
    s8 uiMode[0x28];
    u8 itemStatus[0x100];
    u8 itemThumbIds[0x100];
    s8 slotFlags[6];
} GalleryWork;

extern const char D_001290E0[];
extern const char D_00129100[];
extern char *D_00129118[];
extern char *D_00129120[];
extern s32 (*D_00129150[])(void);
extern u8 D_00129170[0x100];
extern u8 D_0012B0B0[];
extern const Rect16 D_0012B0C0[6];
extern const Rect16 D_0012B0F0[6];
extern const char *D_0012B200[1];
extern s8 D_0012B2F0;
extern s8 D_0012B2F4;
extern u32 D_0012B304;
extern void *D_0012B318;
extern void *D_0012B31C;
extern u32 D_0012B388;
extern u32 D_0012B38C;
extern u32 D_0012B390;
extern u32 D_0012B394;
extern u32 D_0012B398;
extern u32 D_0012B39C;
extern u32 D_0012B3A0;
extern u32 D_0012B3A4;
extern u32 D_0012B3A8;
extern u32 D_0012B3AC;
extern u32 D_0012B3B0;
extern u32 D_0012B3B4;
extern u32 D_0012B3B8;
extern u32 D_0012B3BC;
extern u32 D_0012B3C0;
extern u32 D_0012B3C4;
extern u32 D_0012B3C8;
extern u32 D_0012B3CC;
extern u32 D_0012B3D0;
extern u32 D_0012B3D4;
extern GalleryWork *D_0012B3D8;
extern s32 D_0012B42C;
extern s32 D_0012B430;
extern s32 D_0012B434;
extern u32 D_0012B438;
extern GalleryArchiveEntry D_0012B440[1];
extern s32 D_0012B444;
extern u32 D_001328C0[];
extern u32 D_001328C4[];
extern u64 D_00180A80[];
extern u8 D_001A4AE0[0x330];
extern u8 D_001A4B30[0x170];
extern u8 D_001A4B40[];
extern u8 D_001A4BC0[];
extern u8 D_001A4CA0[0x170];
extern u8 D_001A4CB0[];
extern u8 D_001A4D30[];
extern u8 D_001A4E10[];
extern u32 D_001A5000[];
extern u32 D_001A5020[];
extern u32 D_001A5024[4];
extern volatile s8 D_001A5032[];
extern volatile s8 D_001A5033[];
extern u8 D_001AF2B0[];
extern u8 D_001B7AB0[];
extern u8 D_001C0340[1][0x800];
extern s32 D_001C0344[4];
extern s32 D_001C0348[4];
extern s32 D_001C034C[];
extern s32 D_001C0350[];
extern s8 D_001C0B40[256];
extern s8 D_001C0C40[0x100];

static inline u64 getTex0Cbp(u64 tex0)
{
    return (u64)((s32)((tex0 >> 37) & 0x3FFF));
}

void gallery_load_font_files(void)
{
    cd_load_file(D_001B7AB0, D_001290E0);
    D_0012B3D0 = D_0012B304;
    cd_load_file(D_001AF2B0, D_00129100);

    *(u8 *)&D_0012B3D4 = 0;
    *(u8 *)&D_0012B3A8 = 1;
    *(u8 *)&D_0012B3A4 = 0;
    *(u8 *)&D_0012B3AC = 0;
    *(u8 *)&D_0012B39C = 0;
    *(u8 *)&D_0012B3A0 = 0;
    *(u8 *)&D_0012B3B0 = 0;
    *(u8 *)&D_0012B398 = 0;
    D_0012B390 = 0;
    D_0012B38C = 0;
    D_0012B388 = 0;
    D_0012B3BC = 0;
    D_0012B3C8 = 0;
    D_0012B3C4 = 0;
    D_0012B3C0 = 0;
    D_0012B3B8 = 0;
    D_0012B3B4 = 0;
    *(u8 *)&D_0012B394 = 0;
    D_0012B3CC = D_0012B304;
}

void gallery_main(void)
{
    u32 archiveIndex;

    vram_clear_all();
    tex_upload_reset();
    font_init();
    sceGsResetGraph(0, 1, 2, 1);
    memset(D_001A4AE0, 0, 0x330);
    sceGsSetDefDBuffDc(D_001A4AE0, 0, 640, 224, 1, 0x31, 0);
    FlushCache(0);
    sceGsSyncV(0);
    sceGsPutDrawEnv(D_001A4B30);
    sceGsSyncPath(0, 0);
    sceGsPutDrawEnv(D_001A4CA0);
    sceGsSyncPath(0, 0);
    iop_reboot_and_load_modules();
    pad_open_ports();
    D_0012B318 = sceDmaGetChan(2);
    pad_init_system();
    D_0012B31C = D_001A4E10;
    *(volatile u32 *)0x10000010 = 0x83;
    sound_init_file_tables();

    archiveIndex = 0;
    do {
        cd_search_file(D_0012B200[archiveIndex]);
        D_0012B440[archiveIndex].archivePosition = D_001328C4[0];
        D_0012B440[archiveIndex].entryLocation = D_001328C0[0];
    } while (++archiveIndex == 0);

    archiveIndex = 0;
    do {
        cd_read_sync(D_001C0340[archiveIndex], 0x9C,
                      D_0012B440[archiveIndex].entryLocation);
    } while (++archiveIndex == 0);

    tex_upload_init_vram();
    font_upload_default_cluts();
    func_0010EA50();
    gallery_load_font_files();
    sound_init();
    D_0012B3D8 = memalign(0x40, 0x885800);
    memset(D_0012B3D8, 0, 0x5057C0);
    gallery_run_loop();
    free(D_0012B3D8);
    gallery_exit_to_elf(0);
}

void gallery_run_loop(void)
{
    s32 entryIndex;
    s32 ready;
    s8 entryState;

    D_0012B438 = 0;

    for (entryIndex = 0x20; entryIndex >= 0; entryIndex--) {
        D_001C0C40[entryIndex] = 2;
    }

    for (entryIndex = 0; entryIndex < 0x100; entryIndex++) {
        entryState = D_001C0C40[entryIndex];
        if (entryState != 0) {
            D_0012B3D8->itemStatus[entryIndex] = entryState;
            D_0012B3D8->itemThumbIds[entryIndex] = D_00129170[entryIndex];
        }
    }

    D_0012B3D8->itemStatus[0x11] = 0;
    D_0012B3D8->unk_505168 = 1;

    do {
        *(volatile u32 *)0x10000000 = 0;
        sceGsSwapDBuffDc(D_001A4AE0, D_0012B438);
        gallery_init_frame_gs();
        pad_update();

        if (D_001A5032[0] < 0) {
            D_001A5020[0] |= 0x8000;
        }
        if (D_001A5032[0] > 0) {
            D_001A5020[0] |= 0x2000;
        }
        if (D_001A5033[0] < 0) {
            D_001A5020[0] |= 0x1000;
        }
        if (D_001A5033[0] > 0) {
            D_001A5020[0] |= 0x4000;
        }

        gallery_tick_and_render();
        sound_update();
        pad_update_vibration();

        D_0012B438++;
        ready = !sceGsSyncV(0);

        if (D_0012B438 & 1) {
            sceGsSetHalfOffset(D_001A4CB0, 0x800, 0x800, (s16)ready);
            sceGsSetHalfOffset2(D_001A4D30, 0x800, 0x800, (s16)ready);
        } else {
            sceGsSetHalfOffset(D_001A4B40, 0x800, 0x800, (s16)ready);
            sceGsSetHalfOffset2(D_001A4BC0, 0x800, 0x800, (s16)ready);
        }

        FlushCache(0);
        sceGsSyncPath(0, 0);
    } while (!D_0012B3D8->exitRequested);

    D_0012B3D8 = 0;
}

void gallery_init_frame_gs(void)
{
    sceGifPacket packet;

    sceGifPkInit(&packet, D_00180A80);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, 0x1000000000008005ULL);
    sceGifPkAddGsData(&packet, 0xEULL);
    sceGifPkAddGsData(&packet, 0x8000000000ULL);
    sceGifPkAddGsData(&packet, 0x3BULL);
    sceGifPkAddGsData(&packet, 0x3000FULL);
    sceGifPkAddGsData(&packet, 0x47ULL);
    sceGifPkAddGsData(&packet, 0x100000000ULL);
    sceGifPkAddGsData(&packet, 0x4EULL);
    sceGifPkAddGsData(&packet, 0ULL);
    sceGifPkAddGsData(&packet, 0x14ULL);
    sceGifPkAddGsData(&packet, 0x44ULL);
    sceGifPkAddGsData(&packet, 0x42ULL);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(D_0012B318, D_00180A80, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

void gallery_tick_and_render(void)
{
    s32 overlayAdjustment;
    GalleryView *drawBuffer;
    s16 fadeState;
    s32 brightness;

    while (D_00129150[D_0012B3D8->mode]() != 0) {
    }

    if (D_0012B3D8 == 0) {
        return;
    }

    if (D_0012B3D8->drawEnabled != 0) {
        gallery_draw_background(0x80);
        if (D_0012B3D8->overlayEnabled != 0) {
            gallery_draw_grid_and_ui();
            overlayAdjustment = D_0012B3D8->overlayAdjustment;
            if (overlayAdjustment != 0) {
                gallery_draw_background((u8)(0x80 - ((s16)overlayAdjustment)));
            }
        }
        if ((D_0012B3D8->bufferPending != 0) && (viewer_update_and_draw(&D_0012B3D8->sprites[D_0012B3D8->activeBuffer ^ 1], 0) != 0)) {
            D_0012B3D8->bufferPending = 0;
        }
        drawBuffer = D_0012B3D8->curSprite;
        if (drawBuffer != 0) {
            viewer_update_and_draw(drawBuffer, 0);
        }
        drawBuffer = D_0012B3D8->prevSprite;
        if (drawBuffer != 0) {
            viewer_update_and_draw(drawBuffer, 1);
        }
    }

    fadeState = D_0012B3D8->fadeState;
    if (fadeState == 0) {
        brightness = 0xFF - ((D_0012B3D8->timer * 8 > 0xFF) ? 0xFF : D_0012B3D8->timer * 8);
        gallery_draw_solid_rect(0, 0, 640, 448, brightness, brightness, brightness, 0x80, 2);
    } else if (fadeState > 8) {
        brightness = (D_0012B3D8->timer * 8 > 0xFF) ? 0xFF : D_0012B3D8->timer * 8;
        gallery_draw_solid_rect(0, 0, 640, 448, brightness, brightness, brightness, 0x80, 2);
    }
}

s32 gallery_state_exit(void)
{
    s32 byteIndex;

    if (D_0012B3D8->state == 0) {
        for (byteIndex = 0; byteIndex < sizeof(D_001C0B40); byteIndex++) {
            D_001C0B40[byteIndex] = 0;
        }

        D_0012B3D8->fadeState = 9;
        D_0012B3D8->timer = 0;
        D_0012B3D8->state++;
    }

    if (D_0012B3D8->timer < 32) {
        D_0012B3D8->timer++;
        return 0;
    }

    D_0012B3D8->exitRequested = 1;
    return 0;
}

s32 gallery_state_viewer(void)
{
    switch (D_0012B3D8->state) {
    case 0:
        D_0012B434 = D_0012B3D8->pageOffset + D_0012B3D8->menu_params[0];
        D_0012B3D8->overlayEnabled = 0;
        D_0012B3D8->curSprite = 0;
        D_0012B3D8->prevSprite = 0;
        D_0012B3D8->state++;

    case 1: {
        s32 fileId = D_0012B3D8->itemThumbIds[D_0012B434];
        if (fileId > 0x25) {
            fileId = 0;
        }
        D_0012B3D8->currentThumbId = fileId;
        D_0012B3D8->currentThumbId += 3;
        D_0012B2F4 = 1;
        D_0012B2F0 = 0;
        D_0012B3D8->state++;
    }

    case 2: {
        s32 fileId = D_0012B3D8->currentThumbId;
        s32 offset = D_001C0344[fileId];
        s32 size = D_001C0348[fileId] - offset;
        if (offset != 0) {
            offset /= 0x800;
        }
        offset += D_0012B444;
        cd_read_async(D_0012B3D8->readBuf, size, offset);
        if (D_0012B2F4 == 0) {
            D_0012B3D8->state++;
        }
        break;
    }

    case 3: {
        u8 *buf = D_0012B3D8->readBuf;
        s32 fileId = D_0012B3D8->currentThumbId;
        s32 size = D_001C0348[fileId] - D_001C0344[fileId];
        s32 prev = buf[4];
        s32 i;
        for (i = 5; i < (size - 5); i++) {
            s32 cur = buf[i];
            buf[i] = cur - prev;
            prev = cur;
        }

        D_0012B3D8->unk_505154 = 0;
        D_0012B3D8->state++;
        break;
    }

    case 4:
        if (lzss_decompress_step(D_0012B3D8->decodeBuf, D_0012B3D8->readBuf) != 0) {
            D_0012B3D8->unk_505154 = 0;
            D_0012B3D8->state++;
        }
        break;

    case 5: {
        s32 slot = D_0012B3D8->activeBuffer;
        if (bmp_upload_texture(&D_0012B3D8->viewerTextures[slot], (slot * 0x1000) + 0x1788, (slot * 4) + 0x3788, D_0012B3D8->decodeBuf, 0, 0) != 0) {
            D_0012B3D8->state = 10;
        }
        break;
    }

    case 10:
        D_0012B3D8->curSprite = &D_0012B3D8->sprites[D_0012B3D8->activeBuffer];
        D_0012B3D8->prevSprite = D_0012B3D8->curSprite;
        viewer_init_image(D_0012B3D8->curSprite, &D_0012B3D8->viewerTextures[D_0012B3D8->activeBuffer], 0);
        if (D_0012B3D8->isInitialized != 2) {
            D_0012B3D8->curSprite->menuBox.alpha = 0;
        }
        D_0012B3D8->state++;

    case 11: {
        s32 action = viewer_update_and_draw(D_0012B3D8->curSprite, 2);
        if (action == 3) {
            D_0012B3D8->curSprite = 0;
            D_0012B3D8->prevSprite = 0;
            D_0012B3D8->mode = 2;
            D_0012B3D8->state = 0;
        } else if (action != 0) {
            do {
                if (action == 1) {
                    D_0012B434++;
                } else {
                    D_0012B434 += D_0012B3D8->itemCount - 1;
                }
                D_0012B434 %= D_0012B3D8->itemCount;
                if (D_0012B434 != 0) {
                    D_0012B3D8->pageOffset = (D_0012B434 / 6) * 6;
                } else {
                    D_0012B3D8->pageOffset = 0;
                }
                D_0012B3D8->menu_params[0] = D_0012B434 % 6;
            } while (D_0012B3D8->itemStatus[D_0012B434] != 2);
            D_0012B3D8->curSprite->state = 2;
            D_0012B3D8->curSprite->timer = 0x80;
            D_0012B3D8->bufferPending = 1;
            D_0012B3D8->isInitialized = 2;
            D_0012B3D8->activeBuffer ^= 1;
            D_0012B3D8->curSprite = 0;
            D_0012B3D8->state = 1;
        }
        break;
    }

    case 200:
        if (D_001A5024[0] & 0x20) {
            D_0012B3D8->mode = 2;
            D_0012B3D8->state = 0;
        }
        break;
    }

    return 0;
}

s32 gallery_state_grid(void)
{
    SpriteInfo atlasSprite;
    s32 thumbnailIndex;
    s32 previousCursor;
    s32 menuResult;

    switch (D_0012B3D8->state) {
    case 0:
        D_0012B3D8->isInitialized = 0;
        D_0012B3D8->state = 3;

    case 3:
        D_0012B3D8->unk_505154 = 0;
        while (!bmp_upload_texture(&atlasSprite, 0x1788, 0x2788, D_0012B3D8->textureBuffer, 0, 0)) {
        }

        for (thumbnailIndex = 0; thumbnailIndex < 37; thumbnailIndex++) {
            SpriteInfo *sprite = &D_0012B3D8->allSprites[thumbnailIndex];
            *sprite = atlasSprite;
            sprite->tex0 = (sprite->tex0 & (~(((u64)0x3FFF) << 37))) | (getTex0Cbp(atlasSprite.tex0) << 37);
            sprite->u += (s16)((thumbnailIndex & 7) * 128);
            sprite->v += (s16)((thumbnailIndex >> 3) * 90);
            sprite->w = 128;
            sprite->h = 90;
        }

        D_0012B3D8->timer = 0;
        D_0012B3D8->overlayEnabled = 1;
        D_0012B3D8->scrollX = 0x38;
        D_0012B3D8->unk_505530 = 0;
        for (D_0012B3D8->slotIndex = 0; D_0012B3D8->slotIndex < 6; D_0012B3D8->slotIndex++) {
            s32 itemIndex = D_0012B3D8->pageOffset + D_0012B3D8->slotIndex;
            s32 thumbnailId;
            if (itemIndex >= D_0012B3D8->itemCount) {
                break;
            }
            thumbnailId = D_0012B3D8->itemThumbIds[itemIndex];
            if (thumbnailId > 37) {
                thumbnailId = 0;
            }
            D_0012B3D8->currentThumbId = thumbnailId;
            D_0012B3D8->pageSprites[D_0012B3D8->slotIndex] = D_0012B3D8->allSprites[D_0012B3D8->currentThumbId];
            if (D_001C0B40[D_0012B3D8->currentThumbId] != 0) {
                D_0012B3D8->slotFlags[D_0012B3D8->slotIndex] = 4;
            } else {
                D_0012B3D8->slotFlags[D_0012B3D8->slotIndex] = 1;
            }
        }

        if (D_0012B3D8->isInitialized == 0) {
            D_0012B3D8->state = 10;
            return 1;
        }
        D_0012B3D8->state = 19;
        break;

    case 10:
        D_0012B3D8->overlayAdjustment = 0;
        D_0012B3D8->state++;

    case 11:
        D_0012B3D8->overlayAdjustment += 4;
        if (D_0012B3D8->overlayAdjustment >= 0x80) {
            D_0012B3D8->isInitialized = 1;
            D_0012B3D8->overlayAdjustment = 0;
            D_0012B3D8->state = 19;
        }
        break;

    case 19:
        D_0012B3D8->unk_505530 = 0;
        D_0012B3D8->fadeState = 1;
        D_0012B3D8->unk_505150 = 0;
        D_0012B3D8->state++;

    case 20:
        previousCursor = D_0012B3D8->menu_params[0];
        menuResult = viewer_update_grid_cursor(&D_0012B3D8->menu_params[0], D_001A5000);
        if (menuResult != 0) {
            if (menuResult < 0x100) {
                int directionButtons;
                D_0012B3D8->unk_505530 = 0;
                if (D_0012B3D8->itemCount <= 6) {
                    break;
                }
                directionButtons = D_001A5020[0];
                if ((directionButtons & 0x8000) && ((previousCursor == 0) || (previousCursor == 3))) {
                    D_0012B3D8->menu_params[0] = previousCursor + 2;
                    D_0012B3D8->scrollDirection = -1;
                    D_0012B3D8->pageOffset -= 6;
                    if (D_0012B3D8->pageOffset < 0) {
                        D_0012B3D8->pageOffset = ((D_0012B3D8->itemCount - 1) / 6) * 6;
                    }
                    D_0012B3D8->state = 29;
                    return 1;
                }
                if ((directionButtons & 0x2000) && ((previousCursor == 2) || (previousCursor == 5))) {
                    D_0012B3D8->menu_params[0] = previousCursor - 2;
                    D_0012B3D8->scrollDirection = 1;
                    D_0012B3D8->pageOffset += 6;
                    if (D_0012B3D8->pageOffset >= D_0012B3D8->itemCount) {
                        D_0012B3D8->pageOffset = 0;
                    }
                    D_0012B3D8->state = 29;
                    return 1;
                }
                sound_play_cursor_se();
            } else {
                s32 itemIndex = D_0012B3D8->menu_params[0] + D_0012B3D8->pageOffset;
                if ((itemIndex < D_0012B3D8->itemCount) && (D_0012B3D8->itemStatus[itemIndex] == 2)) {
                    sound_play_confirm_se();
                    D_0012B3D8->exitMode = 3;
                    D_0012B3D8->state = 100;
                }
            }
        } else {
            u32 buttons = D_001A5024[0];
            if (buttons & 0x40) {
                sound_play_confirm_se();
                D_0012B3D8->state = 40;
                break;
            } else if (buttons & 0x4) {
                if (D_0012B3D8->itemCount <= 6) {
                    break;
                }
                D_0012B3D8->scrollDirection = -1;
                D_0012B3D8->pageOffset -= 6;
                if (D_0012B3D8->pageOffset < 0) {
                    D_0012B3D8->pageOffset = ((D_0012B3D8->itemCount - 1) / 6) * 6;
                }
                D_0012B3D8->state = 29;
                return 1;
            } else if (buttons & 0x8) {
                if (D_0012B3D8->itemCount <= 6) {
                    break;
                }
                D_0012B3D8->scrollDirection = 1;
                D_0012B3D8->pageOffset += 6;
                if (D_0012B3D8->pageOffset >= D_0012B3D8->itemCount) {
                    D_0012B3D8->pageOffset = 0;
                }
                D_0012B3D8->state = 29;
                return 1;
            }
        }
        D_0012B3D8->timer++;
        break;

    case 29:
        D_0012B3D8->timer = 0;
        D_0012B3D8->unk_505530 = 0;
        sound_play_page_se();
        D_0012B3D8->fadeState = 2;
        D_0012B3D8->countdown = 0x20;
        D_0012B3D8->state = 30;

    case 30:
        D_0012B3D8->timer++;
        D_0012B3D8->scrollX -= (s16)(D_0012B3D8->timer * D_0012B3D8->scrollDirection);
        if ((--D_0012B3D8->countdown) == 0) {
            D_0012B3D8->state = 3;
        }
        break;

    case 40:
        D_0012B3D8->dialogState = 1;
        D_0012B3D8->fadeState = 2;
        D_0012B3D8->countdown = 0x10;
        D_0012B3D8->dialogChoice = 1;
        viewer_draw_yes_no_dialog(-1, 0, 0, 0);
        D_0012B3D8->state++;

    case 41:
        if (D_001A5024[0] & 0x8000) {
            if (menuResult = D_0012B3D8->dialogChoice != 0) {
                sound_play_cursor_se();
            }
            D_0012B3D8->dialogChoice = 0;
        }
        if (D_001A5024[0] & 0x2000) {
            if (D_0012B3D8->dialogChoice != 1) {
                sound_play_cursor_se();
            }
            D_0012B3D8->dialogChoice = 1;
        }
        if (D_001A5024[0] & 0x20) {
            sound_play_confirm_se();
            if (D_0012B3D8->dialogChoice == 0) {
                D_0012B3D8->dialogState = -1;
                D_0012B3D8->state = 100;
                D_0012B3D8->exitMode = 4;
            } else {
                D_0012B3D8->dialogState = 0;
                D_0012B3D8->fadeState = 1;
                D_0012B3D8->state = 20;
            }
        }
        if (D_001A5024[0] & 0x40) {
            sound_play_confirm_se();
            D_0012B3D8->dialogState = 0;
            D_0012B3D8->fadeState = 1;
            D_0012B3D8->state = 20;
        }
        break;

    case 100:
        D_0012B3D8->overlayAdjustment = 0x80;
        D_0012B3D8->state++;

    case 101:
        D_0012B3D8->overlayAdjustment -= 4;
        if (D_0012B3D8->overlayAdjustment <= 0) {
            D_0012B3D8->overlayEnabled = 0;
            D_0012B3D8->mode = D_0012B3D8->exitMode;
            D_0012B3D8->state = 0;
        }
        break;
    }

    return (unsigned long)0;
}

s32 gallery_state_fade_in(void)
{
    if (D_0012B3D8->state == 0) {
        D_0012B3D8->fadeState = 0;
        D_0012B3D8->timer = 0;
        D_0012B3D8->state++;
    }

    if (++D_0012B3D8->timer < 32) {
        return 0;
    }

    D_0012B3D8->fadeState = 1;
    D_0012B3D8->mode = 2;
    D_0012B3D8->state = 0;
    return 0;
}

s32 gallery_state_loading(void)
{
    sceGifPacket pkt;
    u32 i;
    s32 idx;
    s32 count;
    s32 *params;

    switch (D_0012B3D8->state) {
    case 0:
        D_0012B3D8->drawEnabled = 0;
        D_0012B3D8->fadeState = 0;
        D_0012B3D8->timer = 0;
        D_0012B3D8->state++;
    case 1:
        tex_upload_step();
        if (D_0012B2F4 == 0) {
            D_0012B3D8->state++;
        }
        break;
    case 2:
        if (gallery_load_ui_assets() != 0) {
            D_0012B3D8->state++;
        }
        break;
    case 3:
        D_0012B3D8->fadeState = 9;
        D_0012B3D8->timer = 0;
        D_0012B3D8->state++;
    case 4:
        if (D_0012B3D8->timer >= 0x20) {
            D_0012B3D8->fadeState = 0;
            D_0012B3D8->timer = 0;
            D_0012B3D8->state++;
        }
        break;
    case 5:
        D_0012B3D8->state++;
        break;
    case 6:
        D_0012B3D8->box_x0 = 0x38;
        D_0012B3D8->box_x1 = 0x248;
        D_0012B3D8->box_y0 = 0x50;
        D_0012B3D8->box_y1 = 0x130;
        D_0012B3D8->box_color_r = 0x80;
        D_0012B3D8->box_color_g = 0x18;
        D_0012B3D8->box_color_b = 0x80;
        D_0012B3D8->box_color_a = 0x33;
        D_0012B3D8->overlayEnabled = 0;
        D_0012B3D8->cursor_color_r = 0x18;
        D_0012B3D8->cursor_color_g = 0xFF;
        D_0012B3D8->cursor_color_b = 0x30;
        D_0012B3D8->cursor_color_a = 0x33;
        D_0012B3D8->unk_50552C = 0x80;

        params = D_0012B3D8->menu_params;
        params[0] = 0;
        params[1] = 6;
        params[2] = -3;
        params[3] = 3;
        params[4] = -1;
        params[5] = 1;
        params[6] = 0;
        params[7] = 0;
        params[8] = 0;
        params[9] = 1;
        params[10] = 0;
        params[11] = 0;

        D_0012B3D8->slotFlags[0] = 0;
        D_0012B3D8->slotFlags[1] = 0;
        D_0012B3D8->slotFlags[2] = 0;
        D_0012B3D8->slotFlags[3] = 0;
        D_0012B3D8->slotFlags[4] = 0;
        D_0012B3D8->slotFlags[5] = 0;

        count = 0;
        for (idx = 0; idx < 0x100; idx++) {
            if (D_001C0C40[idx] != 0) {
                count++;
            }
        }

        D_0012B3D8->drawEnabled = 1;
        D_0012B3D8->itemCount = count;
        D_0012B3D8->pageOffset = 0;
        D_0012B3D8->mode = 1;
        D_0012B3D8->state = 0;
        break;
    }

    if (D_0012B3D8->state < 5) {
        gallery_draw_solid_rect(0, 0, 0x280, 0x1C0, 0, 0, 0, 0x80, 0);
        sceGifPkInit(&pkt, D_00180A80);
        sceGifPkReset(&pkt);
        sceGifPkAddGsData(&pkt, 0x1000000000008002ULL);
        sceGifPkAddGsData(&pkt, 0xE);
        sceGifPkAddGsData(&pkt, 0x20170606A9441E40ULL);
        sceGifPkAddGsData(&pkt, 0x6);
        sceGifPkAddGsData(&pkt, 0);
        sceGifPkAddGsData(&pkt, 0x14);

        for (i = 0; i < 11; i++) {
            bmp_draw_ascii_char(&pkt, 0x180 + i * 16, 0x1A0, D_0012B0B0[i]);
        }

        for (i = 0; i < ((D_0012B438 & 0x7F) >> 5); i++) {
            bmp_draw_ascii_char(&pkt, 0x180 + (i + 11) * 16, 0x1A0, '.');
        }

        sceGifPkTerminate(&pkt);
        FlushCache(0);
        sceDmaSendN(D_0012B318, D_00180A80, sceGifPkSize(&pkt));
        sceGsSyncPath(0, 0);

        if (D_0012B3D8->timer < 0x20) {
            D_0012B3D8->timer++;
        }
    }

    return 0;
}

s32 gallery_load_ui_assets(void)
{
    s32 loopState[2];
    s32 size;
    s32 offset;
    u8 *buf;
    u32 k;

    switch (D_0012B3D8->unk_505150) {
    case 0:
        D_0012B2F4 = 1;
        D_0012B2F0 = 0;
        D_0012B3D8->unk_505150++;

    case 1:
        offset = D_001C0344[0];
        buf = D_0012B3D8->readBuf;
        size = D_001C0348[0] - offset;
        if (offset != 0) {
            offset /= 0x800;
        }
        offset += D_0012B444;
        cd_read_async(buf, size, offset);
        if (D_0012B2F4 == 0) {
            D_0012B3D8->unk_505150++;
        }
        break;

    case 2: {
        u8 *buf = D_0012B3D8->readBuf;
        s32 size = D_001C0348[0] - D_001C0344[0];
        s32 prev = buf[4];
        s32 i;
        for (loopState[1] = 5; loopState[1] < (size - 5); loopState[1]++) {
            s32 cur = buf[loopState[1]];
            buf[loopState[1]] = cur - prev;
            prev = cur;
        }

        D_0012B3D8->unk_505154 = 0;
        D_0012B3D8->unk_505150++;
        break;
    }

    case 3:
        if (lzss_decompress_step(D_0012B3D8->decodeBuf, D_0012B3D8->readBuf) != 0) {
            D_0012B3D8->unk_505154 = 0;
            D_0012B3D8->unk_505150++;
        }
        break;

    case 4:
        if (bmp_upload_texture(&D_0012B3D8->bgSprite, 0x1180, 0x1780, D_0012B3D8->decodeBuf, 0, 0) != 0) {
            D_0012B3D8->unk_505150 = 10;
        }
        break;

    case 10:
        D_0012B2F0 = 0;
        D_0012B2F4 = 1;
        D_0012B3D8->unk_505150++;

    case 11:
        offset = D_001C0348[0];
        buf = D_0012B3D8->readBuf;
        size = D_001C034C[0] - offset;
        if (offset != 0) {
            offset /= 0x800;
        }
        offset += D_0012B444;
        cd_read_async(buf, size, offset);
        if (D_0012B2F4 == 0) {
            D_0012B3D8->unk_505150++;
        }
        break;

    case 12: {
        u8 *buf = D_0012B3D8->readBuf;
        s32 size = D_001C034C[0] - D_001C0348[0];
        s32 prev = buf[4];
        s32 i;
        for (loopState[1] = 5; loopState[1] < (size - 5); loopState[1]++) {
            s32 cur = buf[loopState[1]];
            buf[loopState[1]] = cur - prev;
            prev = cur;
        }

        D_0012B3D8->unk_505154 = 0;
        D_0012B3D8->unk_505150++;
        break;
    }

    case 13:
        if (lzss_decompress_step(D_0012B3D8->decodeBuf, D_0012B3D8->readBuf) != 0) {
            D_0012B3D8->unk_505154 = 0;
            D_0012B3D8->unk_505150++;
        }
        break;

    case 14:
        if (bmp_upload_texture(&D_0012B3D8->uiAtlasSprite, 0x1380, 0x1784, D_0012B3D8->decodeBuf, 0, 0) != 0) {
            D_0012B3D8->unk_505150 = 20;
        }
        break;

    case 20:
        D_0012B2F0 = 0;
        D_0012B2F4 = 1;
        D_0012B3D8->unk_505150++;

    case 21:
        offset = D_001C034C[0];
        buf = D_0012B3D8->readBuf;
        size = D_001C0350[0] - offset;
        if (offset != 0) {
            offset /= 0x800;
        }
        offset += D_0012B444;
        cd_read_async(buf, size, offset);
        if (D_0012B2F4 == 0) {
            D_0012B3D8->unk_505150++;
        }
        break;

    case 22: {
        u8 *buf = D_0012B3D8->readBuf;
        s32 size = D_001C0350[0] - D_001C034C[0];
        s32 prev = buf[4];
        s32 i;
        for (loopState[1] = 5; loopState[1] < (size - 5); loopState[1]++) {
            s32 cur = buf[loopState[1]];
            buf[loopState[1]] = cur - prev;
            prev = cur;
        }

        D_0012B3D8->unk_505154 = 0;
        D_0012B3D8->unk_505150++;
        break;
    }

    case 23:
        if (lzss_decompress_step(D_0012B3D8->textureBuffer, D_0012B3D8->readBuf) != 0) {
            D_0012B3D8->unk_505150 = 30;
        }
        break;

    case 30: {
        for (k = 0; k < 6; k++) {
            SpriteInfo *src = &D_0012B3D8->uiAtlasSprite;
            s16 h = D_0012B0C0[k].h;
            s16 w = D_0012B0C0[k].w;
            s16 v = D_0012B0C0[k].v;
            s16 u = D_0012B0C0[k].u;
            SpriteInfo *dst = &D_0012B3D8->uiSprites[k];
            *dst = *src;
            dst->tex0 = (dst->tex0 & (~(((u64)0x3FFF) << 37))) | (getTex0Cbp(src->tex0) << 37);
            dst->u += u;
            dst->v += v;
            dst->w = w;
            dst->h = h;
        }

        for (loopState[1] = 0; ((u32)loopState[1]) < 6; loopState[1]++) {
            loopState[0] = D_0012B0F0[loopState[1]].u;
            D_0012B3D8->uiX0[loopState[1]] = loopState[0];
            D_0012B3D8->uiY0[loopState[1]] = D_0012B0F0[loopState[1]].v;
            D_0012B3D8->uiX1[loopState[1]] = D_0012B0F0[loopState[1]].w;
            D_0012B3D8->uiY1[loopState[1]] = D_0012B0F0[loopState[1]].h;
        }

        D_0012B3D8->uiMode[4] = 2;
        D_0012B3D8->uiMode[5] = 2;
        return 1;
    }
    }

    return 0;
}

void gallery_draw_background(u8 alpha)
{
    sceGifPacket packet;

    sceGifPkInit(&packet, D_00180A80);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, 0x1000000000008003ULL);
    sceGifPkAddGsData(&packet, 0xEULL);
    sceGifPkAddGsData(&packet, D_0012B3D8->bgSprite.tex0);
    sceGifPkAddGsData(&packet, 0x6ULL);
    sceGifPkAddGsData(&packet, 0x60ULL);
    sceGifPkAddGsData(&packet, 0x14ULL);
    sceGifPkAddGsData(&packet, 0x44ULL);
    sceGifPkAddGsData(&packet, 0x42ULL);
    sceGifPkAddGsData(&packet, 0x6400000000008001ULL);
    sceGifPkAddGsData(&packet, 0x535310ULL);

    if (alpha == 0x80) {
        sceGifPkAddGsData(&packet, 0x116ULL);
    } else {
        sceGifPkAddGsData(&packet, 0x156ULL);
    }

    sceGifPkAddGsData(&packet, ((u64)alpha << 24) | 0x3F80000000808080ULL);
    sceGifPkAddGsData(&packet, 0ULL);
    sceGifPkAddGsData(&packet, 0x79006C00ULL);
    sceGifPkAddGsData(&packet, 0x1C002000ULL);
    sceGifPkAddGsData(&packet, 0x87009400ULL);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(D_0012B318, D_00180A80, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

void gallery_draw_grid_and_ui(void)
{
    sceGifPacket pkt;
    SpriteInfo *tex;
    s32 i;
    s32 col;
    s32 row;
    s32 idx;
    s32 mode;

    sceGifPkInit(&pkt, D_00180A80);
    sceGifPkReset(&pkt);

    sceGifPkAddGsData(&pkt, 0x1000000000008001ULL);
    sceGifPkAddGsData(&pkt, 0xEULL);
    sceGifPkAddGsData(&pkt, 0x60ULL);
    sceGifPkAddGsData(&pkt, 0x14ULL);

    for (i = 0; i < 6; i++) {
        tex = &D_0012B3D8->uiSprites[i];

        sceGifPkAddGsData(&pkt, 0x1000000000008001ULL);
        sceGifPkAddGsData(&pkt, 0xEULL);
        sceGifPkAddGsData(&pkt, tex->tex0);
        sceGifPkAddGsData(&pkt, 0x6ULL);

        sceGifPkAddGsData(&pkt, 0x6400000000008001ULL);
        sceGifPkAddGsData(&pkt, 0x535310ULL);
        sceGifPkAddGsData(&pkt, 0x116ULL);

        if (D_0012B3D8->uiMode[i] == 1) {
            u8 color = ((D_0012B438 & 1) << 6) + 0x40;
            sceGifPkAddGsData(&pkt, GS_RGBAQ(color, color, color, color, 0x3F800000));
        } else if (D_0012B3D8->uiMode[i] == 2) {
            if (D_0012B3D8->itemCount <= 6) {
                sceGifPkAddGsData(&pkt, GS_RGBAQ(0, 0, 0, 0, 0x3F800000));
            } else {
                u8 pulse = (u8)(127.0f * sinf((3.1415927f * (f32)(D_0012B438 & 0x3F)) / 64.0f));
                sceGifPkAddGsData(&pkt, GS_RGBAQ(0x80, pulse, pulse, 0x80, 0x3F800000));
            }
        } else {
            sceGifPkAddGsData(&pkt, GS_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000));
        }

        sceGifPkAddGsData(&pkt, GS_UV(tex->u << 4, tex->v << 4));
        sceGifPkAddGsData(&pkt, GS_XYZ2((D_0012B3D8->uiX0[i] << 4) + 0x6C00, (D_0012B3D8->uiY0[i] << 3) + 0x7900));
        sceGifPkAddGsData(&pkt, GS_UV((tex->u + tex->w) << 4, (tex->v + tex->h) << 4));
        sceGifPkAddGsData(&pkt, GS_XYZ2((D_0012B3D8->uiX1[i] << 4) + 0x6C00, (D_0012B3D8->uiY1[i] << 3) + 0x7900));
    }

    sceGifPkAddGsData(&pkt, 0x1000000000008001ULL);
    sceGifPkAddGsData(&pkt, 0xEULL);
    sceGifPkAddGsData(&pkt, 0ULL);
    sceGifPkAddGsData(&pkt, 0x14ULL);

    if ((D_0012B3D8->timer & 0x20) == 0) {
        D_0012B42C = D_0012B3D8->timer & 0x1F;
        if (D_0012B42C >= 0x10) {
            D_0012B42C = 0x1F - D_0012B42C;
        }
    }

    idx = 0;
    for (row = 0; row < 2; row++) {
        for (col = 0; col < 3; col++) {
            tex = &D_0012B3D8->pageSprites[idx];

            if (idx >= D_0012B3D8->slotIndex) {
                break;
            }

            sceGifPkAddGsData(&pkt, 0x1000000000008001ULL);
            sceGifPkAddGsData(&pkt, 0xEULL);
            sceGifPkAddGsData(&pkt, tex->tex0);
            sceGifPkAddGsData(&pkt, 0x6ULL);

            sceGifPkAddGsData(&pkt, 0x6400000000008001ULL);
            sceGifPkAddGsData(&pkt, 0x535310ULL);

            mode = D_0012B3D8->slotFlags[idx];
            if (D_0012B3D8->fadeState == 0 || D_0012B3D8->fadeState == 2) {
                mode = D_0012B3D8->fadeState;
            }

            switch (mode) {
            default:
                sceGifPkAddGsData(&pkt, 0x116ULL);
                sceGifPkAddGsData(&pkt, GS_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000));
                break;
            case 0:
            case 2:
                sceGifPkAddGsData(&pkt, 0x156ULL);
                sceGifPkAddGsData(&pkt, GS_RGBAQ(0x80, 0x80, 0x80, D_0012B3D8->countdown << 2, 0x3F800000));
                break;
            case 4: {
                s32 bright = (D_0012B42C << 2) + 0x80;
                sceGifPkAddGsData(&pkt, 0x156ULL);
                sceGifPkAddGsData(&pkt, GS_RGBAQ(bright, bright, bright, 0x80, 0x3F800000));
                break;
            }
            }

            sceGifPkAddGsData(&pkt, GS_UV(tex->u << 4, tex->v << 4));
            sceGifPkAddGsData(
                &pkt,
                GS_XYZ2(
                    ((D_0012B3D8->scrollX + 0x38 + col * 0x90) << 4) + 0x6C00,
                    ((row * 0x6A + 0x5E) << 3) + 0x7900
                )
            );
            sceGifPkAddGsData(&pkt, GS_UV((tex->u + tex->w - 1) << 4, (tex->v + tex->h) << 4));
            sceGifPkAddGsData(
                &pkt,
                GS_XYZ2(
                    ((tex->w + (D_0012B3D8->scrollX + 0x38 + col * 0x90)) << 4) + 0x6C00,
                    ((tex->h + (row * 0x6A + 0x5E)) << 3) + 0x7900
                )
            );
            idx++;
        }
    }

    sceGifPkAddGsData(&pkt, 0x1000000000008001ULL);
    sceGifPkAddGsData(&pkt, 0xEULL);
    sceGifPkAddGsData(&pkt, 0x60ULL);
    sceGifPkAddGsData(&pkt, 0x14ULL);

    if (D_0012B3D8->fadeState == 1) {
        if ((D_0012B3D8->timer & 0x40) == 0) {
            D_0012B430 = D_0012B3D8->timer & 0x3F;
            if (D_0012B430 >= 0x20) {
                D_0012B430 = 0x3F - D_0012B430;
            }
        }

        sceGifPkAddGsData(&pkt, 0x1000000000008001ULL);
        sceGifPkAddGsData(&pkt, 0xEULL);
        sceGifPkAddGsData(&pkt, 0x48ULL);
        sceGifPkAddGsData(&pkt, 0x42ULL);

        sceGifPkAddGsData(&pkt, 0x4400000000008001ULL);
        sceGifPkAddGsData(&pkt, 0x5510ULL);
        sceGifPkAddGsData(&pkt, 0x146ULL);
        sceGifPkAddGsData(&pkt, GS_RGBAQ(0xC0, 0xC0, 0xC0, 0x60 - D_0012B430 * 2, 0x3F800000));
        sceGifPkAddGsData(
            &pkt,
            GS_XYZ2(
                (((D_0012B3D8->menu_params[0] % 3) * 0x90 + 0x70) << 4) + 0x6C00,
                (((D_0012B3D8->menu_params[0] / 3) * 0x6A + 0x5E) << 3) + 0x7900
            )
        );
        sceGifPkAddGsData(
            &pkt,
            GS_XYZ2(
                (((D_0012B3D8->menu_params[0] % 3) * 0x90 + 0xF0) << 4) + 0x6C00,
                (((D_0012B3D8->menu_params[0] / 3) * 0x6A + 0xB8) << 3) + 0x7900
            )
        );
    }

    sceGifPkTerminate(&pkt);
    FlushCache(0);
    sceDmaSendN(D_0012B318, D_00180A80, sceGifPkSize(&pkt));
    sceGsSyncPath(0, 0);

    switch (D_0012B3D8->dialogState) {
    case 0:
        sprite_clear_queue();
        for (i = 0; i < 2; i++) {
            sprite_queue_sjis_text(
                (s16)(D_0012B3D8->uiX0[2] - 0x20),
                D_0012B3D8->uiY0[2] + 0x13 + i * 0x18,
                D_00129118[i],
                0,
                0x18,
                0x18,
                0x80,
                0
            );
        }
        sprite_flush_rects();
        break;
    case 1:
        sprite_clear_queue();
        sprite_queue_sjis_text(
            (s16)(D_0012B3D8->uiX0[2] - 0x20),
            D_0012B3D8->uiY0[2] + 0x13,
            D_00129120[0],
            0,
            0x18,
            0x18,
            0x80,
            0
        );
        sprite_flush_rects();
        viewer_draw_yes_no_dialog(D_0012B3D8->dialogChoice, 0x140, D_0012B3D8->uiY0[2] + 0x33, 0x40);
        break;
    }
}
