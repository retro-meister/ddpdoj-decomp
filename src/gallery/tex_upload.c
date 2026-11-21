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

extern s16 g_tex_clut_palette_32[];
extern s16 g_tex_clut_palette_16[];
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
extern u16 g_pad_vib_power_p2;
extern u16 g_pad_vib_power_p1;
extern u16 g_pad_vib_timer_p2;
extern u16 g_pad_vib_timer_p1;
extern u8 g_pad_vib_state_p2;
extern u8 g_pad_vib_state_p1;
extern s32 g_tex_vram_tbp;
extern s32 g_tex_vram_cbp;
extern s16 g_tex_clut_work_buf[];
extern u8 g_tex_bitmap_work_buf[];

void tex_upload_step(void)
{
    cd_read_async(g_vram_load_buf, g_data_files[0].size, g_data_files[0].lba);
}

void tex_upload_reset(void)
{
    s16 *source;
    s16 *palette;
    s32 colorIndex;

    source = g_tex_clut_palette;
    palette = g_tex_clut_work_buf;
    for (colorIndex = 0; colorIndex < 16; colorIndex++) {
        palette[colorIndex] = *source++;
    }
    g_tex_vram_cbp = 0x3832;
    tex_upload_clut_slot((u8 *)g_tex_clut_work_buf, 0, 1);

    palette = g_tex_clut_work_buf;
    source = g_tex_clut_palette_16;
    for (colorIndex = 0; colorIndex < 15; colorIndex++) {
        palette[colorIndex] = *source++ | 0x8000;
    }
    palette[colorIndex] = *source;
    g_tex_vram_cbp = 0x3830;
    tex_upload_clut_slot((u8 *)g_tex_clut_work_buf, 0, 1);

    palette = g_tex_clut_work_buf;
    source = g_tex_clut_palette_32;
    for (colorIndex = 0; colorIndex < 31; colorIndex++) {
        palette[colorIndex] = *source++ | 0x8000;
    }
    palette[colorIndex] = *source;
    g_tex_vram_cbp = 0x383A;
    tex_upload_clut_slot((u8 *)g_tex_clut_work_buf, 1, 1);
}

void tex_upload_init_vram(void)
{
    g_tex_vram_tbp = 0x1E40;
    cd_read_sync(g_tex_bitmap_work_buf, g_data_files[10].size, g_data_files[10].lba);
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
            sceGsSetDefLoadImage(g_gs_load_image, (s16)g_tex_vram_cbp, 1, 2, 0, 0, 8, 2);
            FlushCache(0);
            sceGsExecLoadImage(g_gs_load_image, destination);
            sceGsSyncPath(0, 0);
            g_tex_vram_cbp += 1;
            destination += 0x80;
        }
        break;
    case 1:
        for (blockIndex = 0; blockIndex < blockCount; blockIndex++) {
            sceGsSetDefLoadImage(g_gs_load_image, (s16)g_tex_vram_cbp, 1, 2, 0, 0, 16, 16);
            FlushCache(0);
            sceGsExecLoadImage(g_gs_load_image, destination);
            sceGsSyncPath(0, 0);
            g_tex_vram_cbp += 4;
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
                    g_tex_vram_tbp,
                    remaining,
                    0x14,
                    g_tex_upload_table[index].x,
                    g_tex_upload_table[index].y,
                    g_tex_upload_table[index].width,
                    g_tex_upload_table[index].height
                );
                FlushCache(0);
                sceGsExecLoadImage(g_gs_load_image, g_tex_bitmap_work_buf);
                sceGsSyncPath(0, 0);
                break;

            case 1:
                chunkHeight = g_tex_upload_table[index].height;
                sceGsSetDefLoadImage(
                    g_gs_load_image,
                    g_tex_vram_tbp,
                    g_tex_upload_table[index].dbw,
                    0x13,
                    g_tex_upload_table[index].x,
                    g_tex_upload_table[index].y,
                    g_tex_upload_table[index].width,
                    chunkHeight
                );
                FlushCache(0);
                sceGsExecLoadImage(g_gs_load_image, g_tex_bitmap_work_buf);
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
            src = g_tex_bitmap_work_buf;
            loop0:
            if (remaining > 0x100) {
                chunkHeight = 0x100;
            } else {
                chunkHeight = remaining;
            }
            sceGsSetDefLoadImage(
                g_gs_load_image,
                g_tex_vram_tbp,
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
            src1 = g_tex_bitmap_work_buf;
            do {
                if (remaining > 0x80) {
                    chunkHeight = 0x80;
                } else {
                    chunkHeight = remaining;
                }
                sceGsSetDefLoadImage(
                    g_gs_load_image,
                    g_tex_vram_tbp,
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
        switch (g_pad_vib_state_p1) {
            case 0:
                break;
            case 1:
                g_pad_act_direct[1] = (u8)g_pad_vib_power_p1;
                scePadSetActDirect(0, 0, g_pad_act_direct);
                g_pad_vib_state_p1++;
                break;
            case 2:
                g_pad_vib_timer_p1--;
                if (g_pad_vib_timer_p1 <= 0) {
                    g_pad_vib_state_p1++;
                }
                break;
            case 3:
                g_pad_act_direct[1] = 0;
                scePadSetActDirect(0, 0, g_pad_act_direct);
                g_pad_vib_state_p1 = 0;
                break;
        }

        switch (g_pad_vib_state_p2) {
            case 0:
                break;
            case 1:
                g_pad_act_direct[1] = (u8)g_pad_vib_power_p2;
                scePadSetActDirect(1, 0, g_pad_act_direct);
                g_pad_vib_state_p2++;
                break;
            case 2:
                g_pad_vib_timer_p2--;
                if (g_pad_vib_timer_p2 <= 0) {
                    g_pad_vib_state_p2++;
                }
                break;
            case 3:
                g_pad_act_direct[1] = 0;
                scePadSetActDirect(1, 0, g_pad_act_direct);
                g_pad_vib_state_p2 = 0;
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
