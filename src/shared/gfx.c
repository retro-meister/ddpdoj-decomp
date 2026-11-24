#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

void func_00219860(void);
void func_00219A80(s32 arg0, s32 arg1);
void func_00219DF0(s32 col, s32 row);
void quad_flush(void);
void quad_build_packet(Qword *pkt, s32 first, s32 count);
void glyph_queue_clear(void);
void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 alpha, s32 attr, s32 wide);
void glyph_queue_flush(void);
void glyph_queue_emit(s32 index);

typedef struct
{
    s32 type;
    s32 dbw;
    s32 x;
    s32 y;
    s32 width;
    s32 height;
} TexUploadInfo;

extern TexUploadInfo D_0026F870[];
extern s32 D_0028EA74;
extern u8 D_004ED000[];
extern u8 D_004ED180[];

void func_002184A0(void)
{
    extern sceGsLoadImage g_gs_load_image;
    D_0028EA74 = 0x2240;
    switch (D_0026F870[4].type) {
    case 0:
        sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, D_0026F870[4].dbw, SCE_GS_PSMT4, D_0026F870[4].x, D_0026F870[4].y,
                             D_0026F870[4].width, D_0026F870[4].height);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, D_004ED000);
        sceGsSyncPath(0, 0);
        break;
    case 1:
        sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, D_0026F870[4].dbw, SCE_GS_PSMT8, D_0026F870[4].x, D_0026F870[4].y,
                             D_0026F870[4].width, D_0026F870[4].height);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, D_004ED180);
        sceGsSyncPath(0, 0);
        break;
    case 2:
        break;
    }
}

extern u16 D_0028E91C;
extern u8 D_004CCF80[];

void func_002185B0(void)
{
    extern sceGsLoadImage g_gs_load_image;
    D_0028EA74 = 0x2240;
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, D_0026F870[5].dbw, SCE_GS_PSMT8, D_0026F870[5].x, D_0026F870[5].y,
                         D_0026F870[5].width, D_0026F870[5].height);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, D_004CCF80 + D_0028E91C * 0x4E00 + 0x200);
    sceGsSyncPath(0, 0);
}

void func_00218650(s32 index)
{
    extern u8 D_0050D780[];
    extern sceGsLoadImage g_gs_load_image;
    s32 type;
    s32 chunkHeight;
    s32 remaining;
    s32 yOffset;
    s32 src;
    s32 src1;

    type = D_0026F870[index].type;
    if (D_0026F870[index].width != 0x400) {
        switch (type) {
            case 0:
                remaining = D_0026F870[index].dbw;
                sceGsSetDefLoadImage(
                    &g_gs_load_image,
                    D_0028EA74,
                    remaining,
                    SCE_GS_PSMT4,
                    D_0026F870[index].x,
                    D_0026F870[index].y,
                    D_0026F870[index].width,
                    D_0026F870[index].height
                );
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, D_0050D780);
                sceGsSyncPath(0, 0);
                break;

            case 1:
                chunkHeight = D_0026F870[index].height;
                sceGsSetDefLoadImage(
                    &g_gs_load_image,
                    D_0028EA74,
                    D_0026F870[index].dbw,
                    SCE_GS_PSMT8,
                    D_0026F870[index].x,
                    D_0026F870[index].y,
                    D_0026F870[index].width,
                    chunkHeight
                );
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, D_0050D780);
                sceGsSyncPath(0, 0);
                break;

            case 2:
                break;
        }
        return;
    }

    switch (type) {
        case 0:
            remaining = D_0026F870[index].height;
            yOffset = 0;
            src = 0;
        loop0:
            if (remaining > 0x100) {
                chunkHeight = 0x100;
            } else {
                chunkHeight = remaining;
            }
            sceGsSetDefLoadImage(
                &g_gs_load_image,
                D_0028EA74,
                D_0026F870[index].dbw,
                SCE_GS_PSMT4,
                D_0026F870[index].x,
                yOffset + D_0026F870[index].y,
                0x400,
                chunkHeight
            );
            FlushCache(0);
            sceGsExecLoadImage(&g_gs_load_image, D_0050D780 + src);
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
            remaining = D_0026F870[index].height;
            yOffset = 0;
            src1 = 0;
            do {
                if (remaining > 0x80) {
                    chunkHeight = 0x80;
                } else {
                    chunkHeight = remaining;
                }
                sceGsSetDefLoadImage(
                    &g_gs_load_image,
                    D_0028EA74,
                    D_0026F870[index].dbw,
                    SCE_GS_PSMT8,
                    D_0026F870[index].x,
                    yOffset + D_0026F870[index].y,
                    0x400,
                    chunkHeight
                );
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, D_0050D780 + src1);
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

extern s32 g_clut_upload_cbp;

void clut_upload(u8 *src, s32 mode, s32 count) {
    extern sceGsLoadImage g_gs_load_image;
    s32 i;
    s32 offset;
    s32 off2;

    sceGsSyncPath(0, 0);
    switch (mode) {
    case 0:
        if (0 < count) {
            i = 0;
            offset = 0;
            do {
                sceGsSetDefLoadImage(&g_gs_load_image, g_clut_upload_cbp, 1, SCE_GS_PSMCT16, 0, 0, 8, 2);
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, src + offset);
                sceGsSyncPath(0, 0);
                g_clut_upload_cbp += 1;
                i++;
                offset += 0x80;
            } while (i < count);
        }
        break;
    case 1:
        if (0 < count) {
            i = 0;
            off2 = 0;
            do {
                sceGsSetDefLoadImage(&g_gs_load_image, g_clut_upload_cbp, 1, SCE_GS_PSMCT16, 0, 0, 16, 16);
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, src + off2);
                sceGsSyncPath(0, 0);
                g_clut_upload_cbp += 4;
                i++;
                off2 += 0x80;
            } while (i < count);
        }
        break;
    case 2:
        break;
    }
}

s32 cd_read_sync(s32 *, s32, s32);         /* extern */
extern s32 D_0029CB00[];
extern s32 D_0029CB04[];

void tex_load_common(void) {
    extern s32 D_0050D780[];
    D_0028EA74 = 0x1E40;
    cd_read_sync(D_0050D780, D_0029CB00[0], D_0029CB04[0]);
    func_00218650(2);
    printf("tex load end\n");
}

extern void func_0018DEE0(void);
extern void cd_read_async(u8 *dst, s32 a, s32 b);
extern void func_002182F0(void);
extern void func_0021C7B0(s32 size);
extern s32 func_0021C7E0(void);
extern u8 D_0028E350;
extern s16 D_0028E3FC;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern s32 D_0028EA58;
extern u8 *D_0028EA9C;
extern s32 D_0029CAB0[];
extern s32 D_0029CAB4[];
extern s32 D_0029CB50[];
extern s32 D_0029CB54[];
extern u8 D_002C4F80[];

void stage_load_step(void) {
    extern u8 D_00587000[];
    u8 *buffer;

    buffer = D_0028EA9C + 0x5DC800;
    if (D_0028E91C != D_0028E3FC) {
    switch (D_0028E350) {
    case 0:
#ifdef DEATH_LABEL
        printf("stage load start\n");
#else
        printf("stage load start[%d]\n", D_0028E91C);
#endif
        func_0018DEE0();
        func_002182F0();
        D_0028E350++;
        break;
    case 1:
        D_0028E350++;
        if (g_cd_async_state != 0) {
            sceCdBreak();
        }
        g_cd_async_state = 0;
        g_cd_async_busy = 1;
        break;
    case 2:
        cd_read_async(D_00587000, D_0029CB50[D_0028E91C * 4], D_0029CB54[D_0028E91C * 4]);
        if (g_cd_async_busy != 0) {
            break;
        }
        g_cd_async_state = 0;
        g_cd_async_busy = 1;
        D_0028E350++;
    case 3:
        cd_read_async(D_002C4F80, D_0029CB50[(D_0028E91C * 2 + 1) * 2], D_0029CB54[(D_0028E91C * 2 + 1) * 2]);
        if (g_cd_async_busy != 0) {
            break;
        }
        g_cd_async_state = 0;
        g_cd_async_busy = 1;
        D_0028E350++;
    case 4:
        cd_read_async(buffer, D_0029CAB0[(D_0028E91C + 5) * 2], D_0029CAB4[(D_0028E91C + 5) * 2]);
        if (g_cd_async_busy != 0) {
            break;
        }
        D_0028EA58 = 0;
        g_cd_async_busy = 1;
        g_cd_async_state = 0;
        D_0028E350++;
        break;
    case 5:
        switch (D_0028EA58) {
        case 0:
            func_0021C7B0(0x14000);
            D_0028EA58++;
            break;
        }
        if (func_0021C7E0() != 0) {
            D_0028E350++;
        }
        break;
    case 6:
        printf("stage load end\n");
        D_0028E350 = 0;
        D_0028E3FC = D_0028E91C;
        break;
    case 7:
        break;
    }
    } else {
        func_002182F0();
        D_0028E350 = 0;
    }
}

extern s16 D_0026F900[];
extern s16 D_00269140[];
extern s16 D_002554B0[];

void clut_upload_defaults(void)
{
    extern s16 D_0058D800[];
    s16 *source;
    s16 *palette;
    s32 colorIndex;

    source = D_0026F900;
    palette = D_0058D800;
    for (colorIndex = 0; colorIndex < 16; colorIndex++) {
        palette[colorIndex] = *source++;
    }
    g_clut_upload_cbp = 0x3832;
    clut_upload((u8 *)D_0058D800, 0, 1);

    source = D_00269140;
    palette = D_0058D800;
    for (colorIndex = 0; colorIndex < 15; colorIndex++) {
        palette[colorIndex] = *source++ | 0x8000;
    }
    palette[colorIndex] = *source;
    g_clut_upload_cbp = 0x3830;
    clut_upload((u8 *)D_0058D800, 0, 1);

    source = D_002554B0;
    palette = D_0058D800;
    for (colorIndex = 0; colorIndex < 31; colorIndex++) {
        palette[colorIndex] = *source++ | 0x8000;
    }
    palette[colorIndex] = *source;
    g_clut_upload_cbp = 0x383A;
    clut_upload((u8 *)D_0058D800, 1, 1);
}

extern u16 D_002B2750[];
void func_00219010(void) {
    extern u8 D_0058D800[];
    s32 var_v0;
    s32 var_v1;
    s16 *var_a0;
    u8 *var_a1;
    s16 *temp_a2;
    s32 var_a2;
    u8 *temp_a3;
    s16 temp_a3_3;
    s16 temp_t2;
    s32 var_t2;

    var_a0 = (s16 *)(D_002B2750);
    var_a1 = (u8 *)(D_0058D800);
    var_v0 = 0;
    do {
        var_v1 = 0;
        var_a2 = 0;
loop_2:
        temp_a3 = (u8 *)(var_a1 + var_a2);
        var_v1 += 8;
        var_a2 += 0x10;
        (*(s16 *)((u8 *)(temp_a3) + (0))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (0))) | 0x8000);
        (*(s16 *)((u8 *)(temp_a3) + (2))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (2))) | 0x8000);
        (*(s16 *)((u8 *)(temp_a3) + (4))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (4))) | 0x8000);
        (*(s16 *)((u8 *)(temp_a3) + (6))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (6))) | 0x8000);
        (*(s16 *)((u8 *)(temp_a3) + (8))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (8))) | 0x8000);
        (*(s16 *)((u8 *)(temp_a3) + (0xA))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (0xA))) | 0x8000);
        (*(s16 *)((u8 *)(temp_a3) + (0xC))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (0xC))) | 0x8000);
        temp_t2 = (*(s16 *)((u8 *)(var_a0) + (0xE))) | 0x8000;
        var_a0 += 8;
        (*(s16 *)((u8 *)(temp_a3) + (0xE))) = temp_t2;
        if (var_v1 < 7) {
            goto loop_2;
        }
        var_t2 = var_v1 * 2;
        if (var_v1 < 0xF) {
            do {
                var_v1 += 1;
                *(s16 *)(var_a1 + var_t2) = *var_a0++ | 0x8000;
                var_t2 += 2;
            } while (var_v1 < 0xF);
        }
        temp_a3_3 = *var_a0;
        var_v0 += 1;
        temp_a2 = (s16 *)(var_a1 + (var_v1 * 2));
        *temp_a2 = temp_a3_3;
        var_a1 += 0x80;
        var_a0 += 1;
    } while (var_v0 < 0x10);
    g_clut_upload_cbp = 0x37B0;
    clut_upload(D_0058D800, 0, 0x10);
}

extern u8 D_002B3150[];
void func_00219120(void) {
    extern u8 D_0058C800[];
    s32 var_v0;
    u8 *var_v1;
    u8 *var_a0;
    s16 temp_a3;

    var_v1 = (u8 *)(D_002B3150);
    var_a0 = (u8 *)(D_0058C800);
    var_v0 = 0;
    do {
        var_v0 += 1;
        (*(s16 *)((u8 *)(var_a0) + (0))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (2))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (2))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (4))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (4))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (6))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (6))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (8))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (8))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0xA))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0xA))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0xC))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0xC))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0xE))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0xE))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x20))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x10))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x22))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x12))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x24))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x14))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x26))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x16))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x28))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x18))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x2A))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x1A))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x2C))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x1C))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x2E))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x1E))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x10))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x20))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x12))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x22))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x14))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x24))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x16))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x26))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x18))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x28))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x1A))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x2A))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x1C))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x2C))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x1E))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x2E))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x30))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x30))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x32))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x32))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x34))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x34))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x36))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x36))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x38))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x38))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x3A))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x3A))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x3C))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x3C))) | 0x8000);
        temp_a3 = (*(s16 *)((u8 *)(var_v1) + (0x3E)));
        (*(s16 *)((u8 *)(var_a0) + (0x3E))) = temp_a3;
        var_v1 += 0x40;
        var_a0 += 0x80;
    } while (var_v0 < 0x20);
    g_clut_upload_cbp = 0x3730;
    clut_upload(D_0058C800, 1, 0x20);
}

extern u8 D_002B2950[];
extern u8 D_0058B800[];
void func_002192F0(void) {
    s32 var_v0;
    u8 *var_v1;
    u8 *var_a0;

    var_v1 = (u8 *)(D_002B2950);
    var_a0 = (u8 *)(D_0058B800);
    var_v0 = 0;
    do {
        var_v0 += 1;
        (*(s16 *)((u8 *)(var_a0) + (0))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (2))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (2))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (4))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (4))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (6))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (6))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (8))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (8))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0xA))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0xA))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0xC))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0xC))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0xE))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0xE))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x20))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x10))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x22))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x12))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x24))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x14))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x26))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x16))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x28))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x18))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x2A))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x1A))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x2C))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x1C))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x2E))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x1E))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x10))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x20))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x12))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x22))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x14))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x24))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x16))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x26))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x18))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x28))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x1A))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x2A))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x1C))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x2C))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x1E))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x2E))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x30))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x30))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x32))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x32))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x34))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x34))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x36))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x36))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x38))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x38))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x3A))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x3A))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x3C))) = (s16) ((*(s16 *)((u8 *)(var_v1) + (0x3C))) | 0x8000);
        (*(s16 *)((u8 *)(var_a0) + (0x3E))) = (*(s16 *)((u8 *)(var_v1) + (0x3E)));
        var_v1 += 0x40;
        var_a0 += 0x80;
    } while (var_v0 < 0x20);
    g_clut_upload_cbp = 0x36B0;
    clut_upload(D_0058B800, 1, 0x20);
}

#ifndef DEATH_LABEL
extern u8 D_0028E2F4;
extern s32 g_quad_count;
extern s16 D_00592002[];
extern s16 D_00592008[];
extern s16 D_0059200A[];
extern s16 D_00592010[];
extern s16 D_00592012[];
extern s16 D_00592018[];
extern s16 D_0059201A[];
extern s16 D_00592020[];
extern s32 D_00592024[];
extern s32 D_00592028[];
extern s16 D_0059202C[];
extern s16 D_0059202E[];
extern s16 D_00592030[];
void func_002194C0(void) {
    extern s16 g_quad_queue[];
    if (D_0028E2F4 != 0) {
        g_quad_queue[0] = 0;
        D_00592020[0] = 1;
        D_0059202E[0] = 0x80;
        g_quad_count = 1;
        D_00592024[0] = 0x2240;
        D_00592028[0] = 0x3836;
        D_00592030[0] = 0x80;
        D_0059202C[0] = 1;
        D_00592008[0] = 0;
        D_00592002[0] = 0x1C0;
        D_00592012[0] = 0x1C0;
        D_0059200A[0] = 0xE0;
        D_0059201A[0] = 0xE0;
        D_00592010[0] = 0;
        D_00592018[0] = 0;
        quad_flush();
    }
}
#endif

extern s32 D_0028E9DC;
extern s32 D_0028EA5C;
extern s32 D_0028EA60;
extern s32 D_0028EA64;
extern s32 D_0028EA68;
extern s32 D_0028EA6C;
extern s32 D_0028EA70;

void func_00219570(void) {
    extern s8 D_0028E2F0;
    D_0028E2F0 = 0;
    D_0028EA6C = 0x80;
    D_0028EA64 = 0;
    D_0028EA68 = 1;
    D_0028EA70 = 0;
    D_0028EA60 = 0;
    D_0028EA5C = 0;
    D_0028E9DC = 0;
}


void func_002195A0(void) {
    extern s8 D_0028E2F0;
    func_00219570();
    D_0028EA70 = 0;
    D_0028E2F0 = 1;
    D_0028EA64 = 1;
}

void func_002195D0(void) {
    extern s8 D_0028E2F0;
    D_0028E2F0 = 1;
    D_0028EA64 = 2;
    D_0028EA70 = 0x80;
}

extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
extern s32 D_0026F940[];
extern s32 D_0028DC98;
extern u8 D_0028E28C;
extern u8 D_0028E36C;

void func_002195F0(void) {
    extern u8 D_0028E2F0;
    s32 level;
    s32 top;
    s32 h;

    if (D_0028E2F0 == 0) {
        return;
    }
    switch (D_0028EA64) {
    case 0:
        break;
    case 1:
        D_0028EA70 += 8;
        if (D_0028EA70 >= 0x80) {
            D_0028EA64 = 3;
            D_0028EA70 = 0x80;
        }
        break;
    case 2:
        D_0028EA70 -= 8;
        if (D_0028EA70 <= 0) {
            D_0028EA70 = 0;
            D_0028EA64 = 0;
            D_0028E2F0 = 0;
        }
        break;
    case 3:
        break;
    }
    if (D_0028E36C == 0) {
        D_0028EA6C += D_0028EA68;
    }
    if (D_0028EA68 >= 0) {
        if (D_0028EA6C >= 0xFF) {
            D_0028EA6C = 0xFF;
            D_0028EA68 = -1;
        }
    } else if (D_0028EA6C <= 0x80) {
        D_0028EA6C = 0x80;
        D_0028EA68 = 1;
    }
    if ((D_0028DC98 == 2 || D_0028DC98 == 3) && D_0028EA70 != 0 && D_0028E28C != 0) {
        func_00219860();
        level = D_0028E9DC * D_0026F940[D_0028E91C] / 1000;
        level += 2;
        if (level >= 0x170) {
            level = 0x170;
        }
        top = 0x190 - level;
        h = top - 0x20;
        if (h > 0) {
            gfx_draw_color_box(0x188, -0x50, 0x20, h, 12, D_0028EA70, 1, 1, 1);
        }
        gfx_draw_color_box(0x188, top - 0x50, 0x20, 2, 12, D_0028EA70, D_0028EA6C, 0, 0);
        gfx_draw_color_box(0x188, top - 0x70, 0x20, 2, 12, D_0028EA70, D_0028EA6C, 0, 0);
        gfx_draw_color_box(0x188, top - 0x70, 2, 0x20, 12, D_0028EA70, D_0028EA6C, 0, 0);
        gfx_draw_color_box(0x1A6, top - 0x70, 2, 0x20, 12, D_0028EA70, D_0028EA6C, 0, 0);
    }
}

extern s32 g_quad_count;

typedef struct {
    s16 f00, f02, f04, f06, f08, f0A, f0C, f0E;
    s16 f10, f12, f14, f16, f18, f1A, f1C, f1E;
    s16 f20, f22;
    s32 f24, f28;
    s16 f2C, f2E, f30, f32;
} Unk592000;


void func_00219860(void) {
    extern Unk592000 g_quad_queue[];
    func_002185B0();
    g_quad_queue[0].f10 = 0;
    g_quad_queue[0].f20 = 0xA;
    g_quad_queue[0].f24 = 0x2240;
    g_quad_queue[0].f2C = 1;
    g_quad_queue[0].f28 = 0x3838;
    g_quad_queue[0].f30 = 0x80;
    g_quad_queue[0].f00 = 0x180;
    g_quad_queue[0].f08 = -0x58;
    g_quad_queue[0].f02 = 0x1B0;
    g_quad_queue[0].f0A = 0x148;
    g_quad_queue[0].f12 = 0x30;
    g_quad_queue[0].f1A = 0x1A0;
    g_quad_queue[0].f18 = 0;
    g_quad_queue[0].f2E = D_0028EA70;
    g_quad_count = 1;
    quad_flush();
}

#ifndef DEATH_LABEL
#pragma push
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
extern u32 D_002B4D50[];


void func_00219930(void) {
    s32 i;
    u32 *p;
    s32 row;
    s32 x1;
    s32 x2;
    s32 idx;

    i = 0;
    row = 0;
    do {
        x1 = 54;
        p = D_002B4D50;
        p += x1 + row;
        *p = 0;
        x2 = 55;
        idx = x2 + row;
        i++;
        row += 64;
        p = D_002B4D50;
        p += idx;
        *p = 0;
    } while (i < 14);
}

#pragma pop
#pragma pop
#endif

#ifndef DEATH_LABEL
#pragma push
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void func_00219990(void) {
    s32 i;
    u32 *p;
    s32 row;
    s32 x1;
    s32 x2;
    s32 idx;

    i = 14;
    row = 0x380;
    do {
        x1 = 54;
        p = D_002B4D50;
        p += x1 + row;
        *p = 0;
        x2 = 55;
        idx = x2 + row;
        i++;
        row += 64;
        p = D_002B4D50;
        p += idx;
        *p = 0;
    } while (i < 27);
}

#pragma pop
#pragma pop
#endif

extern u32 D_002B4D50[];

void func_002199F0(void) {
    s32 y;
    u32 *p = D_002B4D50;
    s32 x;

    g_quad_count = 0;
    for (y = 0; y < 32; y++) {
        for (x = 0; x < 64; x++) {
            reg_d0.w = *p++;
            if (reg_d0.w != 0xC0000000 && reg_d0.w != 0) {
                func_00219A80(x, y);
            }
        }
    }
    quad_flush();
}

#pragma push
#pragma opt_propagation off
typedef struct {
    s16 x0;
    s16 x1;
    s16 pad04[2];
    s16 y0;
    s16 y1;
    s16 pad0C[2];
    s16 u0;
    s16 u1;
    s16 pad14[2];
    s16 v0;
    s16 v1;
    s16 pad1C[2];
    s16 z;
    s16 pad22;
    s32 tex;
    s32 clut;
    s16 flags;
    s16 attr;
    u16 alpha;
    s16 pad32;
} GlyphQuad;


void func_00219A80(s32 arg0, s32 arg1) {
    extern GlyphQuad g_quad_queue[];
    s32 x;
    s32 y;
    s32 code;
    s32 n;
    s32 u;
    s32 v;
    s32 palette;

    n = g_quad_count;
    x = arg0 * 8;
    y = arg1 * 8;
    palette = (reg_d0.h[0] & 0x3F) >> 1;
    code = reg_d0.h[1] & 0x1FFF;
    u = (code % 126 + 1) * 8;
    v = (code / 126 + 1) * 8;
    g_quad_queue[n].z = 0x14;
    g_quad_queue[n].attr = 0x80;
    g_quad_queue[n].tex = 0x1E40;
    g_quad_queue[n].flags = 0;
    g_quad_queue[n].clut = palette + 0x37B0;
    g_quad_queue[n].alpha = 0x80;
    g_quad_queue[n].x0 = x - 1;
    g_quad_queue[n].y0 = y;
    g_quad_queue[n].x1 = x + 7;
    g_quad_queue[n].y1 = y + 8;
    switch ((reg_d0.h[0] >> 6) & 3) {
    case 0:
        g_quad_queue[n].u0 = u;
        g_quad_queue[n].v0 = v;
        g_quad_queue[n].u1 = u + 8;
        g_quad_queue[n].v1 = v + 8;
        break;
    case 1:
        g_quad_queue[n].u0 = u + 8;
        g_quad_queue[n].v0 = v;
        g_quad_queue[n].u1 = u;
        g_quad_queue[n].v1 = v + 8;
        break;
    case 2:
        g_quad_queue[n].u0 = u;
        g_quad_queue[n].v0 = v + 8;
        g_quad_queue[n].u1 = u + 8;
        g_quad_queue[n].v1 = v;
        break;
    case 3:
        g_quad_queue[n].u0 = u + 8;
        g_quad_queue[n].v0 = v + 8;
        g_quad_queue[n].u1 = u;
        g_quad_queue[n].v1 = v;
        break;
    }
    g_quad_count = n + 1;
}
#pragma pop

extern s16 D_0028E238;
extern u8 D_002B6D50[];
void func_00219D20(void) {
    s32 var_s0;
    s32 var_s1;
    s32 temp_s2;
    s32 var_s3;
    u8 *var_s4;

    var_s4 = (u8 *)(D_002B6D50);
    var_s1 = 0;
    g_quad_count = 0;
    temp_s2 = D_0028E238 & 0x7FF;
    do {
        var_s3 = temp_s2 / 32;
        for (var_s0 = 0; var_s0 < 0xF; var_s0++) {
            reg_d0.w = *(u32 *)(var_s4 + (var_s3 * 4));
            if ((reg_d0.w != 0xC0000000) && (reg_d0.w != 0)) {
                func_00219DF0(var_s0, var_s1);
            }
            var_s3++;
            var_s3 &= 0x3F;
        }
        var_s1 += 1;
        var_s4 += 0x100;
    } while (var_s1 < 9);
    quad_flush();
}

typedef struct {
    s16 x[4];
    s16 y[4];
    s16 u[4];
    s16 v[4];
    s16 z;
    s16 pad22;
    s32 tbp;
    s32 cbp;
    s16 mode;
    s16 alpha;
    u16 color;
    s16 pad32;
} TileEntry;

extern s32 func_002180A0(u16 key);
extern s16 D_0028E234;
extern GlyphCacheEntry D_0057EF98[];
extern u32 D_005C4C80[];

void func_00219DF0(s32 col, s32 row) {
    extern sceGsLoadImage g_gs_load_image;
    extern s32 D_00587000[];
    extern TileEntry g_quad_queue[];
    s32 uploads;
    GlyphCacheEntry *cache;
    s32 u;
    s32 palette;
    s32 key;
    s32 n;
    s32 slot;
    s32 v;
    s32 x;
    s32 y;
    u32 *src;
    u32 *dst;
    s32 out;
    s32 in;
    u32 word;
    u32 fill;
    s32 count;

    uploads = 0;
    cache = D_0057EF98;
    x = D_0028E238 & 0x1F;
    x *= -1;
    y = -D_0028E234;
    x += col * 32;
    y += row * 32;
    palette = (reg_d0.h[0] & 0x3F) >> 1;
    key = reg_d0.h[1] & 0x1FFF;
    n = g_quad_count;
    slot = func_002180A0(key);
    if (slot & 0x8000) {
        slot &= 0x7FFF;
        u = cache[slot].x;
        v = cache[slot].y;
        sceGsSetDefLoadImage(&g_gs_load_image, 0x1A40, 8, SCE_GS_PSMT8, u, v, 32, 32);
        FlushCache(0);
        out = 0;
        in = 0;
        dst = D_005C4C80;
        src = (u32 *)(D_002C4F80 + D_00587000[key]);
        if (!(src[0] & 0x80000000)) {
            FlushCache(0);
            sceGsExecLoadImage(&g_gs_load_image, src);
            sceGsSyncPath(0, 0);
        } else {
            do {
                fill = src[in++];
                word = fill;
                if (!(word & 0x40000000)) {
                    dst[out++] = word & 0x1F1F1F1F;
                } else {
                    count = word & 0x3FFF;
                    fill = src[in++] & 0x1F1F1F1F;
                    for (; count >= 0; count--) {
                        dst[out++] = fill;
                    }
                }
            } while (out < 32 * 32 / 4);
            FlushCache(0);
            sceGsExecLoadImage(&g_gs_load_image, dst);
            sceGsSyncPath(0, 0);
        }
        uploads++;
    } else {
        u = cache[slot & 0x7FFF].x;
        v = cache[slot & 0x7FFF].y;
    }
    g_quad_queue[n].z = 1;
    g_quad_queue[n].alpha = 0x80;
    g_quad_queue[n].tbp = 0x1A40;
    g_quad_queue[n].mode = 1;
    g_quad_queue[n].cbp = palette * 4 + 0x36B0;
    g_quad_queue[n].color = 0x80;
    g_quad_queue[n].x[0] = x;
    g_quad_queue[n].y[0] = y;
    g_quad_queue[n].x[1] = x + 32;
    g_quad_queue[n].y[1] = y + 32;
    g_quad_queue[n].u[0] = u;
    g_quad_queue[n].v[0] = v;
    g_quad_queue[n].u[1] = u + 32;
    g_quad_queue[n].v[1] = v + 32;
    g_quad_count = n + 1;
    if (uploads != 0) {
        sceGsSyncPath(0, 0);
    }
}

extern void *g_dma_gif;

void quad_flush(void)
{
    extern u8 g_gif_buf[2][0x10000];
    u8 *packet;
    s32 bufferIndex;
    s32 firstEntry;
    s32 batchCount;
    s32 remainingEntries;

    if (g_quad_count == 0) {
        return;
    }
    bufferIndex = 0;
    firstEntry = 0;
    while ((remainingEntries = g_quad_count) != 0) {
        if (remainingEntries >= 6) {
            batchCount = 6;
        } else {
            batchCount = remainingEntries;
        }

        packet = g_gif_buf[bufferIndex];
        quad_build_packet((Qword *)packet, firstEntry, batchCount);
        sceGsSyncPath(0, 0);
        FlushCache(0);
        sceDmaSend(g_dma_gif, packet);

        bufferIndex ^= 1;
        firstEntry += batchCount;
        g_quad_count -= batchCount;
    }
    sceGsSyncPath(0, 0);
}

void quad_build_packet(Qword *pkt, s32 first, s32 count) {
    extern TileEntry g_quad_queue[];
    s32 qwc;
    s32 i;
    s32 j;

    qwc = 1;
    pkt[0].q = 0;
    pkt[0].w[0] = 0x10000000;
    for (i = 0; i < count; i++) {
        s32 x[4];
        s32 y[4];
        s32 u[4];
        s32 v[4];
        s32 z;
        s32 alpha;
        u32 color;
        s32 tbp;
        s32 cbp;
        s32 mode;

        x[0] = g_quad_queue[first].x[0];
        x[1] = g_quad_queue[first].x[1];
        x[2] = g_quad_queue[first].x[2];
        x[3] = g_quad_queue[first].x[3];
        y[0] = g_quad_queue[first].y[0];
        y[1] = g_quad_queue[first].y[1];
        y[2] = g_quad_queue[first].y[2];
        y[3] = g_quad_queue[first].y[3];
        u[0] = g_quad_queue[first].u[0];
        u[1] = g_quad_queue[first].u[1];
        u[2] = g_quad_queue[first].u[2];
        u[3] = g_quad_queue[first].u[3];
        v[0] = g_quad_queue[first].v[0];
        v[1] = g_quad_queue[first].v[1];
        v[2] = g_quad_queue[first].v[2];
        v[3] = g_quad_queue[first].v[3];
        z = g_quad_queue[first].z;
        alpha = g_quad_queue[first].alpha;
        color = g_quad_queue[first].color;
        cbp = g_quad_queue[first].cbp;
        tbp = g_quad_queue[first].tbp;
        mode = g_quad_queue[first].mode;
        first++;

        pkt[qwc].d[0] = SCE_GIF_SET_TAG(7, 1, 0, 0, SCE_GIF_PACKED, 1);
        pkt[qwc].d[1] = SCE_GIF_PACKED_AD;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = SCE_GS_TEXFLUSH;
        qwc++;

        switch (mode) {
        case 0:
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(tbp, 16, SCE_GS_PSMT4, 10, 10, 1, 0, cbp, SCE_GS_PSMCT16, 0, 0, 1);
            break;
        case 1:
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(tbp, 8, SCE_GS_PSMT8, 9, 9, 1, 0, cbp, SCE_GS_PSMCT16, 0, 0, 1);
            break;
        case 3:
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(tbp, 16, SCE_GS_PSMT8, 10, 9, 1, 0, cbp, SCE_GS_PSMCT16, 0, 0, 1);
            break;
        }
        pkt[qwc].d[1] = SCE_GS_TEX0_1;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = SCE_GS_TEX1_1;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = SCE_GS_CLAMP_1;
        qwc++;

        pkt[qwc].d[0] = 0x3000F;
        pkt[qwc].d[1] = SCE_GS_TEST_1;
        qwc++;

        pkt[qwc].d[0] = (u64)0x80 << 32;
        pkt[qwc].d[1] = SCE_GS_TEXA;
        qwc++;

        pkt[qwc].d[0] = 0x44;
        pkt[qwc].d[1] = SCE_GS_ALPHA_1;
        qwc++;

        pkt[qwc].d[0] = SCE_GIF_SET_TAG(1, 1, 1, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 1, 0, 1, 0, 0), SCE_GIF_PACKED, 6);
        pkt[qwc].d[1] = 0x431431;
        qwc++;

        for (j = 0; j < 2; j++) {
            pkt[qwc].w[0] = color;
            pkt[qwc].w[1] = color;
            pkt[qwc].w[2] = color;
            pkt[qwc].w[3] = alpha;
            qwc++;

            pkt[qwc].w[0] = u[j] << 4;
            pkt[qwc].w[1] = v[j] << 4;
            pkt[qwc].w[2] = 0;
            pkt[qwc].w[3] = 0;
            qwc++;

            pkt[qwc].w[0] = ((x[j] + 0x700) << 4) + 8;
            pkt[qwc].w[1] = ((y[j] + 0x790) << 4) + 8;
            pkt[qwc].w[2] = z << 4;
            pkt[qwc].w[3] = 0;
            qwc++;
        }
    }
    pkt[qwc].q = 0;
    pkt[qwc].w[0] = 0x70000000;
    pkt[0].w[0] = (qwc - 1) | 0x10000000;
}

typedef struct {
    u16 tbp;
    u16 psm;
    u32 width;
    u32 height;
    u16 tw;
    u16 th;
} TexInfo;


void func_0021A640(TexInfo *tex, void *buffer, s32 tbp, u32 width, u32 height) {
    sceGifPacket packet;
    u32 n;
    u32 m;
    s32 x;
    s32 y;

    n = 2;
    m = 2;
    tex->width = width;
    tex->height = height;
    tex->tbp = tbp;
    tex->psm = 2;
    tex->tw = 1;
    while (width > n) {
        tex->tw++;
        n <<= 1;
    }
    tex->th = 1;
    while (height > m) {
        tex->th++;
        m <<= 1;
    }
    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(5, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, (u64)(tex->tbp >> 5) | ((u64)((tex->width + 63) >> 6) << 16) | ((u64)tex->psm << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, (u64)((0x800 - (tex->width >> 1)) << 4) | ((u64)((0x800 - (tex->height >> 1)) << 4) << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, ((u64)(tex->width - 1) << 16) | ((u64)(tex->height - 1) << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkAddGsData(&packet, 0x3000F);
    sceGifPkAddGsData(&packet, 0x47);
    sceGifPkAddGsData(&packet, (u64)1 << 32);
    sceGifPkAddGsData(&packet, 0x4E);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 4));
    sceGifPkAddGsData(&packet, 0x5510);
    sceGifPkAddGsData(&packet, 0x106);
    sceGifPkAddGsData(&packet, (u64)0x3F800000 << 32);
    x = (0x800 - (tex->width >> 1)) << 4;
    y = (0x800 - (tex->height >> 1)) << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)y << 16));
    x += tex->width << 4;
    y += tex->height << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)y << 16));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

void func_0021A920(TexInfo *tex, void *buffer) {
    sceGifPacket packet;
    s32 x;
    s32 y;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(6, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, (u64)(tex->tbp >> 5) | ((u64)((tex->width + 63) >> 6) << 16) | ((u64)tex->psm << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, (u64)((0x800 - (tex->width >> 1)) << 4) | ((u64)((0x800 - (tex->height >> 1)) << 4) << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, ((u64)(tex->width - 1) << 16) | ((u64)(tex->height - 1) << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkAddGsData(&packet, 0x3000F);
    sceGifPkAddGsData(&packet, 0x47);
    sceGifPkAddGsData(&packet, (u64)1 << 32);
    sceGifPkAddGsData(&packet, 0x4E);
    sceGifPkAddGsData(&packet, 0);
    sceGifPkAddGsData(&packet, 0x14);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 4));
    sceGifPkAddGsData(&packet, 0x5510);
    sceGifPkAddGsData(&packet, 0x106);
    sceGifPkAddGsData(&packet, ((u64)0x80 << 24) | ((u64)0x3F800000 << 32));
    x = (0x800 - (tex->width >> 1)) << 4;
    y = (0x800 - (tex->height >> 1)) << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)y << 16));
    x += tex->width << 4;
    y += tex->height << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)y << 16));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

extern s32 g_frame_counter;
extern s32 D_0028EA54;
extern u8 g_gs_dbuff[];

void func_0021ABB0(void *buffer) {
    sceGifPacket packet;
    s32 index;
    s32 x;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(6, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    index = (g_frame_counter + 1) & 1;
    sceGifPkAddGsData(&packet, ((u64)*(u16 *)(g_gs_dbuff + index * 40 + 0x10) & 0x1FF) | ((u64)((D_0028EA54 + 63) >> 6) << 16) | ((u64)2 << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, ((0x800 - (u64)(D_0028EA54 >> 1)) << 4) | ((u64)0x7200 << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, ((u64)(D_0028EA54 - 1) << 16) | ((u64)0x1BF << 48));
    sceGifPkAddGsData(&packet, 0x40);
    if (D_0028DC98 == 2) {
        sceGifPkAddGsData(&packet, 0);
    } else {
        sceGifPkAddGsData(&packet, 0x60);
    }
    sceGifPkAddGsData(&packet, 0x14);
    sceGifPkAddGsData(&packet, 0x3000E);
    sceGifPkAddGsData(&packet, 0x47);
    sceGifPkAddGsData(&packet, 0);
    sceGifPkAddGsData(&packet, 0x3F);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 4));
    sceGifPkAddGsData(&packet, 0x5510);
    sceGifPkAddGsData(&packet, 0x106);
    sceGifPkAddGsData(&packet, 0x80000000ULL | ((u64)0x3F800000 << 32));
    x = (0x800 - (D_0028EA54 >> 1)) << 4;
    sceGifPkAddGsData(&packet, (u64)x | 0x72000000);
    x += D_0028EA54 << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)0x8E00 << 16));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

extern s32 D_0028EA50;

void func_0021AE20(TexInfo *tex, void *buffer) {
    sceGifPacket packet;
    s32 x;
    s64 right;
    s64 left;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(2, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, ((u64)(D_0028EA54 - 1) << 16) | ((u64)0x1BE << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkAddGsData(&packet, SCE_GS_SET_TEX0(tex->tbp, tex->width >> 6, tex->psm, tex->tw, tex->th, 1, 0, 0, 0, 0, 0, 0));
    sceGifPkAddGsData(&packet, SCE_GS_TEX0_1);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 10));
    sceGifPkAddGsData(&packet, 0x5353535310ULL);
    sceGifPkAddGsData(&packet, 0x115);
    sceGifPkAddGsData(&packet, 0x80808080 | ((u64)0x3F800000 << 32));
    x = ((0x800 - D_0028EA54 / 2) << 4) + 8;
    x += D_0028EA50 << 4;
    sceGifPkAddGsData(&packet, 0x1101C00);
    left = x;
    sceGifPkAddGsData(&packet, left | 0x72000000);
    sceGifPkAddGsData(&packet, 0xF101C00);
    right = x + 0xE00;
    sceGifPkAddGsData(&packet, right | 0x72000000);
    sceGifPkAddGsData(&packet, 0xF100000);
    sceGifPkAddGsData(&packet, right | ((u64)0x8E00 << 16));
    sceGifPkAddGsData(&packet, 0x1100000);
    sceGifPkAddGsData(&packet, left | ((u64)0x8E00 << 16));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

typedef struct {
    u16 tbp;
    u16 psm;
    u32 width;
    u32 height;
    u16 tw;
    u16 th;
} TexDesc;


void func_0021B080(TexDesc *tex, void *buffer) {
    sceGifPacket packet;
    s32 index;
    s32 x;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(7, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    if (D_0028DC98 == 4) {
        sceGifPkAddGsData(&packet, 0);
    } else {
        sceGifPkAddGsData(&packet, 0x60);
    }
    sceGifPkAddGsData(&packet, 0x14);
    sceGifPkAddGsData(&packet, 0x3000E);
    sceGifPkAddGsData(&packet, 0x47);
    sceGifPkAddGsData(&packet, 0);
    sceGifPkAddGsData(&packet, 0x3F);
    index = (g_frame_counter + 1) & 1;
    sceGifPkAddGsData(&packet, ((u64)*(u16 *)(g_gs_dbuff + index * 40 + 0x10) & 0x1FF) | ((u64)((D_0028EA54 + 63) >> 6) << 16) | ((u64)2 << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, ((0x800 - (u64)(D_0028EA54 >> 1)) << 4) | ((u64)0x7900 << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, ((u64)(D_0028EA50 + 0x1BF) << 16) | 1 | ((u64)1 << 32) | ((u64)0xDF << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkAddGsData(&packet, (u64)tex->tbp | ((u64)(tex->width >> 6) << 14) | ((u64)tex->psm << 20) | ((u64)tex->tw << 26) | ((u64)tex->th << 30) | ((u64)1 << 34));
    sceGifPkAddGsData(&packet, 6);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 10));
    sceGifPkAddGsData(&packet, 0x5353535310ULL);
    sceGifPkAddGsData(&packet, 0x115);
    sceGifPkAddGsData(&packet, 0x80808080ULL | ((u64)0x3F800000 << 32));
    x = ((0x800 - D_0028EA54 / 2) << 4) + 8;
    x += (D_0028EA50 + 0x1B0) << 4;
    sceGifPkAddGsData(&packet, 0x1101C10);
    sceGifPkAddGsData(&packet, (u64)x | 0x79080000);
    sceGifPkAddGsData(&packet, 0xF101C10);
    sceGifPkAddGsData(&packet, (u64)x | 0x87080000);
    sceGifPkAddGsData(&packet, 0xF100010);
    x -= 0x1A00;
    sceGifPkAddGsData(&packet, (u64)x | 0x87080000);
    sceGifPkAddGsData(&packet, 0x1100010);
    sceGifPkAddGsData(&packet, (u64)x | 0x79080000);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

void func_0021B400(void *buffer) {
    sceGifPacket packet;
    s32 index;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(3, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    index = (g_frame_counter + 1) & 1;
    sceGifPkAddGsData(&packet, ((u64)*(u16 *)(g_gs_dbuff + index * 40 + 0x10) & 0x1FF) | ((u64)((D_0028EA54 + 63) >> 6) << 16) | ((u64)2 << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, ((0x700 - (u64)D_0028EA50) << 4) | ((u64)0x7900 << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, (u64)(D_0028EA50 + 1) | ((u64)(D_0028EA50 + 0x1BF) << 16) | ((u64)1 << 32) | ((u64)0xDF << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

typedef struct {
    u32 DX : 12;
    u32 DY : 11;
    u32 MAGH : 4;
    u32 MAGV : 2;
    u32 p0 : 3;
    u32 DW : 12;
    u32 DH : 11;
    u32 p1 : 9;
} DisplayReg;

extern DisplayReg D_0057C7F8[];
extern DisplayReg D_0057C820[];

void display_set_offset(s32 x, s32 y) {
    s32 dx;
    s32 dy;
    s32 base_x;
    s32 base_y;

    switch (D_0028EA54) {
    case 0x180:
        base_x = 0x21E;
        base_y = 0x32;
        break;
    case 0x1C0:
        base_x = 0x21C;
        x = (s8)(x * 4);
        base_y = 0x19;
        break;
    case 0x200:
        base_x = 0x256;
        base_y = 0x32;
        break;
    case 0x280:
        base_x = 0x27C;
        x = (s8)(x * 4);
        base_y = 0x19;
        break;
    }
    dy = base_y + (s8)y;
    dx = base_x + (s8)(x * 2);
    D_0057C7F8[0].DX = dx;
    D_0057C7F8[0].DY = dy;
    D_0057C820[0].DX = dx;
    D_0057C820[0].DY = dy;
}

typedef struct {
    s32 interlace;
    s32 ffmode;
    s32 width;
    s32 height;
} VideoMode;

extern VideoMode D_0026F9E0[];
extern s8 D_0028E250;
extern s8 D_0028E254;
extern u8 D_0028E2DC;
typedef struct { u64 fbp:9; u64 fbw:6; u64 psm:5; } Dispfb;
extern Dispfb D_0057C7F0[];
extern Dispfb D_0057C818[];
extern u8 D_0057C830[];
extern u8 D_0057C9A0[];

void display_reset(void) {
    VideoMode *mode;

    mode = &D_0026F9E0[D_0028DC98 + D_0028E2DC * 6];
    sceGsResetGraph(0, (s16)mode->interlace, 2, (s16)mode->ffmode);
    D_0028EA54 = mode->width;
    if (mode->interlace == 0) {
        sceGsSetDefDBuffDc(g_gs_dbuff, 2, (s16)mode->width, (s16)mode->height, 1, 0x31, 1);
        D_0028EA50 = (D_0028EA54 - 0x1C0) >> 1;
    } else {
        sceGsSetDefDBuffDc(g_gs_dbuff, 2, (s16)mode->width, (s16)mode->height, 1, 0x31, 0);
        D_0028EA50 = (D_0028EA54 - 0xE0) >> 1;
        D_0057C7F0[0].fbp = 0;
        D_0057C818[0].fbp = ((((mode->width + 63) / 64 * 64) * ((mode->height + 31) / 32 * 32)) >> 11) / 2;
    }
    display_set_offset(D_0028E254, D_0028E250);
    FlushCache(0);
    sceGsSyncV(0);
    sceGsPutDrawEnv(D_0057C830);
    sceGsSyncPath(0, 0);
    sceGsPutDrawEnv(D_0057C9A0);
    sceGsSyncPath(0, 0);
}

typedef struct {
    s32 offset;
    s16 w;
    s16 h;
} ClutEntry;

extern u8 *D_0028EAA0;
extern ClutEntry *D_0028EAA4;

void func_0021B840(s32 index, u16 *src) {
    extern sceGsLoadImage g_gs_load_image;
    extern u16 D_0058C800[];
    s32 n;
    s32 i;
    u32 *data;
    s32 word;
    s16 w;
    s16 h;
    s32 row;
    u16 *dst;
    u32 *buf;
    u32 fill;

    n = 0;
    i = 0;
    buf = D_005C4C80;
    w = D_0028EAA4[index].w;
    h = D_0028EAA4[index].h;
    data = (u32 *)(D_0028EAA0 + D_0028EAA4[index].offset);
    if (!(data[0] & 0x80000000)) {
        sceGsSetDefLoadImage(&g_gs_load_image, 0x16C0, 8, 0x13, 16, 16, w, h);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, data);
    } else {
        do {
            fill = data[i++];
            word = fill;
            if (!(word & 0x40000000)) {
                buf[n++] = word & 0x1F1F1F1F;
            } else {
                word &= 0x3FFF;
                fill = data[i++] & 0x1F1F1F1F;
                for (; word >= 0; word--) {
                    buf[n++] = fill;
                }
            }
        } while (n < w * h / 4);
        sceGsSetDefLoadImage(&g_gs_load_image, 0x16C0, 8, 0x13, 16, 16, w, h);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, buf);
    }
    row = 0;
    dst = D_0058C800;
    do {
        row++;
        dst[0] = src[0] | 0x8000;
        dst[1] = src[1] | 0x8000;
        dst[2] = src[2] | 0x8000;
        dst[3] = src[3] | 0x8000;
        dst[4] = src[4] | 0x8000;
        dst[5] = src[5] | 0x8000;
        dst[6] = src[6] | 0x8000;
        dst[7] = src[7] | 0x8000;
        dst[16] = src[8] | 0x8000;
        dst[17] = src[9] | 0x8000;
        dst[18] = src[10] | 0x8000;
        dst[19] = src[11] | 0x8000;
        dst[20] = src[12] | 0x8000;
        dst[21] = src[13] | 0x8000;
        dst[22] = src[14] | 0x8000;
        dst[23] = src[15] | 0x8000;
        src += 16;
        dst += 8;
    } while (row < 2);
    g_clut_upload_cbp = 0x18C0;
    clut_upload((u8 *)D_0058C800, 1, 1);
}

typedef struct {
    s32 x;
    s32 y;
    s32 u;
    s32 v;
} Vertex;

extern Vertex D_0026FAA0[];

void func_0021BAE0(void *buffer) {
    sceGifPacket packet;
    s32 left;
    s32 i;
    Vertex *vtx;
    s32 x;
    s32 y;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, 0x253216C0 | ((u64)0x20131806 << 32));
    sceGifPkAddGsData(&packet, 6);
    left = ((0x800 - D_0028EA54 / 2) << 4) + 8;
    vtx = D_0026FAA0;
    vtx += D_0028E2DC * 8;
    for (i = 0; i < 2; i++) {
        s64 t;
        sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 10));
        sceGifPkAddGsData(&packet, 0x53535310 | ((u64)0x53 << 32));
        sceGifPkAddGsData(&packet, 0x115);
        sceGifPkAddGsData(&packet, 0x80808080 | ((u64)0x3F800000 << 32));
        sceGifPkAddGsData(&packet, vtx[0].u | ((s64)vtx[0].v << 16));
        t = (s64)(left + vtx[0].x);
        sceGifPkAddGsData(&packet, t | ((s64)(vtx[0].y + 0x7200) << 16));
        sceGifPkAddGsData(&packet, vtx[1].u | ((s64)vtx[1].v << 16));
        x = left + vtx[1].x;
        y = vtx[1].y + 0x7200;
        sceGifPkAddGsData(&packet, (s64)x | ((s64)y << 16));
        sceGifPkAddGsData(&packet, vtx[2].u | ((s64)vtx[2].v << 16));
        x = left + vtx[2].x;
        y = vtx[2].y + 0x7200;
        sceGifPkAddGsData(&packet, (s64)x | ((s64)y << 16));
        sceGifPkAddGsData(&packet, vtx[3].u | ((s64)vtx[3].v << 16));
        x = left + vtx[3].x;
        y = vtx[3].y + 0x7200;
        sceGifPkAddGsData(&packet, (s64)x | ((s64)y << 16));
        vtx += 4;
    }
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

void func_0021BD80(void *buffer, s32 x, s32 y, s32 w, s32 h) {
    sceGifPacket packet;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, (u64)x | ((u64)(x + w - 1) << 16) | ((u64)y << 32) | ((u64)(y + h - 1) << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

extern void gfx_draw_shaded_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha);
extern s32 D_0028EA48;
extern s32 D_0028EA4C;

void label_draw(s32 *rect, s32 x, s32 y, u8 *text) {
    extern u8 g_gif_buf[];
    extern u8 *reg_a0;
    u8 *saved;
    s32 bright;

    if (text == 0) {
        D_0028EA4C = 0;
        D_0028EA48 = 0;
        return;
    }
    saved = reg_a0;
    bright = 0x80;
    if (text != 0) {
        gfx_draw_shaded_box(x, y - 16, 17, (strlen((const char *)text) + 2) * 8, 100, D_0028EA48);
    } else {
        gfx_draw_shaded_box(x, y - 16, 17, 64, 100, D_0028EA48);
    }
    if (D_0028EA48 < 0x60) {
        D_0028EA48++;
        return;
    }
    if (D_0028DC98 < 2) {
        func_0021BD80(g_gif_buf, D_0028EA50 + 2 + x, 1, 16, 223);
    } else {
        func_0021BD80(g_gif_buf, x + 1, 0, 16, rect[2]);
    }
    glyph_queue_clear();
    reg_a0 = text;
    if (D_0028E36C == 0) {
        D_0028EA4C++;
    }
    switch (D_0028EA4C >> 6) {
    case 4:
        D_0028EA4C = 0;
    case 0:
    case 1:
        x += ((D_0028EA4C >> 1) & 0x1F) - 15;
        break;
    case 2:
        bright = (D_0028EA4C << 1) & 0x7F;
        break;
    case 3:
        bright = (0x7F - (D_0028EA4C << 1)) & 0x7F;
        break;
    }
    if (text != 0) {
        glyph_queue_add(x + 8, y, 100, 0, 0x80, bright, 1);
    }
    glyph_queue_flush();
    if (D_0028DC98 < 2) {
        func_0021BD80(g_gif_buf, D_0028EA50 + 1, 1, 447, 223);
    } else {
        func_0021BD80(g_gif_buf, 0, 0, rect[1], rect[2]);
    }
    reg_a0 = saved;
}

extern s32 g_glyph_queue_count;

void glyph_queue_clear(void) {
    g_glyph_queue_count = 0;
}

typedef struct {
    s16 x;
    s16 y;
    s16 page;
    s16 code;
    s16 z;
    s16 attr;
    s16 alpha;
    s16 pad;
} GlyphEntry;

extern u16 D_00269D60[];
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void glyph_queue_add(x, y, z, page, alpha, attr, wide)
    s32 x;
    s32 y;
    s32 z;
    s32 page;
    s32 alpha;
    s16 attr;
    s32 wide;
{
    extern GlyphEntry D_0058E000[];
    extern s8 *reg_a0;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    s8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    s32 count;
    GlyphEntry *entry;
    u16 code;

    save_d0 = reg_d0.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_d1 = reg_d1.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_d2 = reg_d2.w;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    count = g_glyph_queue_count;
    while (1) {
        reg_d4.w = 0;
        reg_d4.sb[0] = *reg_a0;
        reg_a0++;
        if (reg_d4.w == 0) {
            break;
        }
        reg_d4.h[0] = reg_d4.b[0];
        if (wide) {
            reg_d4.h[0] -= 0x20;
            reg_a1 = (u8 *)D_00269D60;
            reg_d4.h[0] += reg_d4.h[0];
            reg_a1 += reg_d4.h[0];
            reg_d4.h[0] = *(u16 *)reg_a1;
        }
        entry = &D_0058E000[count];
        count++;
        entry->x = x;
        entry->y = y;
        entry->z = z;
        entry->page = page;
        entry->attr = attr;
        entry->alpha = alpha;
        code = reg_d4.h[0];
        entry->code = code;
        if (wide) {
            entry = &D_0058E000[count];
            count++;
            entry->x = x - 8;
            entry->y = y;
            entry->z = z;
            entry->page = page;
            entry->attr = attr;
            entry->alpha = alpha;
            entry->code = (s16)code + 0x10;
        }
        y += 8;
    }
    g_glyph_queue_count = count;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}


void glyph_queue_flush(void)
{
    s32 index;

    if (g_glyph_queue_count != 0) {
        g_quad_count = 0;
        for (index = 0; index < g_glyph_queue_count; index++) {
            glyph_queue_emit(index);
        }
        quad_flush();
    }
}

typedef struct {
    s16 x;
    s16 y;
    s16 page;
    s16 code;
    s16 z;
    s16 attr;
    u16 alpha;
    s16 pad;
} GlyphEntry2;



void glyph_queue_emit(s32 index) {
    extern GlyphEntry2 D_0058E000[];
    extern GlyphQuad g_quad_queue[];
    u32 n;
    s32 u;
    s32 v;
    s32 x;
    s32 y;

    n = g_quad_count;
    x = D_0058E000[index].x;
    y = D_0058E000[index].y;
    u = (D_0058E000[index].code % 126 + 1) * 8;
    v = (D_0058E000[index].code / 126 + 1) * 8;
    g_quad_queue[n].z = D_0058E000[index].z;
    g_quad_queue[n].attr = D_0058E000[index].attr;
    g_quad_queue[n].tex = 0x1E40;
    g_quad_queue[n].flags = 0;
    g_quad_queue[n].clut = 0x3830;
    g_quad_queue[n].alpha = D_0058E000[index].alpha;
    g_quad_queue[n].x0 = x;
    g_quad_queue[n].y0 = y;
    g_quad_queue[n].x1 = x + 8;
    g_quad_queue[n].y1 = y + 8;
    g_quad_queue[n].u0 = u;
    g_quad_queue[n].v0 = v;
    g_quad_queue[n].u1 = u + 8;
    g_quad_queue[n].v1 = v + 8;
    g_quad_count = n + 1;
}
