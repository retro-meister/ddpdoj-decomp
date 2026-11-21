#include "gallery/gallery.h"

typedef struct
{
    s32 type;
    s32 dbw;
    s32 x;
    s32 y;
    s32 width;
    s32 height;
} TexUploadInfo;

extern s16 D_00128BE0[];
extern s16 D_00128CE0[];
static TexUploadInfo g_tex_upload_table[6] = {
    { 0, 16, 0, 0,  256, 128 },
    { 1, 16, 0, 0,  256, 192 },
    { 0, 16, 0, 0, 1024, 512 },
    { 1,  8, 0, 0,  256, 192 },
    { 1,  8, 0, 0,  512, 256 },
    { 1,  8, 0, 0,   48, 416 },
};

static s16 g_tex_clut_palette[32] = {
    0, -28406, -15655, -11361, -31611, -29496, -16679, -12451,
    -17736, -20940, -19850, -24111, -23054, -14565, -26291, -1,
};
extern u16 D_0012B2B8;
extern u16 D_0012B2BC;
extern u16 D_0012B2C0;
extern u16 D_0012B2C4;
extern u8 D_0012B2C8;
extern u8 D_0012B2CC;
extern s32 D_0012B310;
extern s32 D_0012B314;
extern u8 D_0012B380;
extern u8 D_0012B381;
extern s32 D_00132620[];
extern u32 D_00132624[];
extern u32 D_00132670[];
extern u32 D_00132674[];
extern s16 D_00135280[];
extern u8 D_00135A80[];

void tex_upload_step(void)
{
    cd_read_async(g_vram_load_buf, D_00132620[0], D_00132624[0]);
}

void tex_upload_reset(void)
{
    s16 *source;
    s16 *palette;
    s32 colorIndex;

    source = g_tex_clut_palette;
    palette = D_00135280;
    for (colorIndex = 0; colorIndex < 16; colorIndex++) {
        palette[colorIndex] = *source++;
    }
    D_0012B314 = 0x3832;
    tex_upload_clut_slot((u8 *)D_00135280, 0, 1);

    palette = D_00135280;
    source = D_00128CE0;
    for (colorIndex = 0; colorIndex < 15; colorIndex++) {
        palette[colorIndex] = *source++ | 0x8000;
    }
    palette[colorIndex] = *source;
    D_0012B314 = 0x3830;
    tex_upload_clut_slot((u8 *)D_00135280, 0, 1);

    palette = D_00135280;
    source = D_00128BE0;
    for (colorIndex = 0; colorIndex < 31; colorIndex++) {
        palette[colorIndex] = *source++ | 0x8000;
    }
    palette[colorIndex] = *source;
    D_0012B314 = 0x383A;
    tex_upload_clut_slot((u8 *)D_00135280, 1, 1);
}

void tex_upload_init_vram(void)
{
    D_0012B310 = 0x1E40;
    cd_read_sync(D_00135A80, D_00132670[0], D_00132674[0]);
    tex_upload_bitmap(2);
    printf("tex load end\n");
}

void tex_upload_clut_slot(u8 *destination, s32 mode, s32 blockCount)
{
    s32 blockIndex;

    sceGsSyncPath(0, 0);

    switch (mode) {
    case 0:
        for (blockIndex = 0; blockIndex < blockCount; blockIndex++) {
            sceGsSetDefLoadImage(g_gs_load_image, (s16)D_0012B314, 1, 2, 0, 0, 8, 2);
            FlushCache(0);
            sceGsExecLoadImage(g_gs_load_image, destination);
            sceGsSyncPath(0, 0);
            D_0012B314 += 1;
            destination += 0x80;
        }
        break;
    case 1:
        for (blockIndex = 0; blockIndex < blockCount; blockIndex++) {
            sceGsSetDefLoadImage(g_gs_load_image, (s16)D_0012B314, 1, 2, 0, 0, 16, 16);
            FlushCache(0);
            sceGsExecLoadImage(g_gs_load_image, destination);
            sceGsSyncPath(0, 0);
            D_0012B314 += 4;
            destination += 0x80;
        }
        break;
    case 2:
        break;
    }
}

void tex_upload_bitmap(s32 index)
{
    s32 type;
    s32 chunkHeight;
    s32 remaining;
    s32 yOffset;
    u8 *src;
    u8 *src1;

    type = g_tex_upload_table[index].type;
    if (g_tex_upload_table[index].width != 0x400) {
        switch (type) {
            case 0:
                remaining = g_tex_upload_table[index].dbw;
                sceGsSetDefLoadImage(
                    g_gs_load_image,
                    D_0012B310,
                    remaining,
                    0x14,
                    g_tex_upload_table[index].x,
                    g_tex_upload_table[index].y,
                    g_tex_upload_table[index].width,
                    g_tex_upload_table[index].height
                );
                FlushCache(0);
                sceGsExecLoadImage(g_gs_load_image, D_00135A80);
                sceGsSyncPath(0, 0);
                break;

            case 1:
                chunkHeight = g_tex_upload_table[index].height;
                sceGsSetDefLoadImage(
                    g_gs_load_image,
                    D_0012B310,
                    g_tex_upload_table[index].dbw,
                    0x13,
                    g_tex_upload_table[index].x,
                    g_tex_upload_table[index].y,
                    g_tex_upload_table[index].width,
                    chunkHeight
                );
                FlushCache(0);
                sceGsExecLoadImage(g_gs_load_image, D_00135A80);
                sceGsSyncPath(0, 0);
                break;

            case 2:
                break;
        }
        return;
    }

    switch (type) {
        case 0:
            remaining = g_tex_upload_table[index].height;
            yOffset = 0;
            src = D_00135A80;
            loop0:
            if (remaining > 0x100) {
                chunkHeight = 0x100;
            } else {
                chunkHeight = remaining;
            }
            sceGsSetDefLoadImage(
                g_gs_load_image,
                D_0012B310,
                g_tex_upload_table[index].dbw,
                0x14,
                g_tex_upload_table[index].x,
                yOffset + g_tex_upload_table[index].y,
                0x400,
                chunkHeight
            );
            FlushCache(0);
            sceGsExecLoadImage(g_gs_load_image, src);
            sceGsSyncPath(0, 0);
            remaining -= chunkHeight;
            src += 0x20000;
            yOffset += 0x100;
            if (remaining != 0) {
                goto loop0;
            } else {
                goto done;
            }

        case 1:
            remaining = g_tex_upload_table[index].height;
            yOffset = 0;
            src1 = D_00135A80;
            do {
                if (remaining > 0x80) {
                    chunkHeight = 0x80;
                } else {
                    chunkHeight = remaining;
                }
                sceGsSetDefLoadImage(
                    g_gs_load_image,
                    D_0012B310,
                    g_tex_upload_table[index].dbw,
                    0x13,
                    g_tex_upload_table[index].x,
                    yOffset + g_tex_upload_table[index].y,
                    0x400,
                    chunkHeight
                );
                FlushCache(0);
                sceGsExecLoadImage(g_gs_load_image, src1);
                sceGsSyncPath(0, 0);
                remaining -= chunkHeight;
                src1 += 0x20000;
                yOffset += 0x80;
            } while (remaining != 0);
            break;

        case 2:
            break;
    }

done:
    return;
}

void pad_update_vibration(void)
{
    if (g_system_mute == 0) {
        switch (D_0012B2CC) {
            case 0:
                break;
            case 1:
                D_0012B381 = (u8)D_0012B2BC;
                scePadSetActDirect(0, 0, &D_0012B380);
                D_0012B2CC++;
                break;
            case 2:
                D_0012B2C4--;
                if (D_0012B2C4 <= 0) {
                    D_0012B2CC++;
                }
                break;
            case 3:
                D_0012B381 = 0;
                scePadSetActDirect(0, 0, &D_0012B380);
                D_0012B2CC = 0;
                break;
        }

        switch (D_0012B2C8) {
            case 0:
                break;
            case 1:
                D_0012B381 = (u8)D_0012B2B8;
                scePadSetActDirect(1, 0, &D_0012B380);
                D_0012B2C8++;
                break;
            case 2:
                D_0012B2C0--;
                if (D_0012B2C0 <= 0) {
                    D_0012B2C8++;
                }
                break;
            case 3:
                D_0012B381 = 0;
                scePadSetActDirect(1, 0, &D_0012B380);
                D_0012B2C8 = 0;
                break;
        }
    }
}

void vram_clear_all(void)
{
    u32 *buffer;
    u32 wordIndex;
    s32 vramBase;
    u32 blockIndex;

    buffer = malloc(0x40000);
    for (wordIndex = 0; wordIndex < 0x10000; wordIndex++) {
        buffer[wordIndex] = 0;
    }

    for (blockIndex = 0, vramBase = 0; blockIndex < 0x10; blockIndex++, vramBase += 0x400) {
        sceGsSetDefLoadImage(g_gs_load_image, (s16)vramBase, 4, 0, 0, 0, 0x100, 0x100);
        FlushCache(0);
        sceGsExecLoadImage(g_gs_load_image, buffer);
        sceGsSyncPath(0, 0);
    }

    free(buffer);
}
