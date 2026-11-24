#include "common.h"

s32 FlushCache(s32);
s32 func_0018E020();
s32 text_flush_rects();
s32 func_002168B0();
s32 func_00217040();
s32 func_00217A50();
s32 func_00217D80();
s32 func_002194C0();
s32 func_002195F0();
s32 func_002199F0();
s32 func_00219D20();
s32 func_0021ABB0();
s32 func_0021AE20();
s32 func_0021B080();
s32 func_0021BAE0();
s32 func_0021C920();
s32 func_0021FA50();
s32 func_00221CF0();
s32 func_002244E0();
s32 func_002256C0();
s32 func_00225EF0();
s32 func_0022B870();
s32 func_0022C5A0();
void sceGsSetHalfOffset(u8 *draw, s32 centerx, s32 centery, s16 halfoffset);
void sceGsSetHalfOffset2(u8 *draw, s32 centerx, s32 centery, s16 halfoffset);
s32 sceGsSyncPath(s32, s32);
s32 sceGsSyncV(s32);
extern s32 D_0028DC98;
extern u8 D_0028E21C;
extern u8 D_0028E310;
extern u16 D_0028E32C;
extern u8 D_0028E378;
extern u8 D_0028E37C;
extern u16 D_0028E3F0;
extern u16 D_0028E8A8;
extern s32 D_0028E9DC;
extern s32 D_0028E9F0;
extern u8 g_gif_buf[];
extern u8 D_0057C840[];
extern u8 D_0057C8C0[];
extern u8 D_0057C9B0[];
extern u8 D_0057CA30[];
extern u8 D_00586FF0[];
void func_00216610(void) {
    s32 half;

    func_00219D20();
#ifndef DEATH_LABEL
    func_002194C0();
#endif
    func_0021C920();
    func_002199F0();
    func_002168B0();
    func_0021FA50();
    func_00221CF0();
    func_002244E0();
    func_0022B870();
    func_00225EF0();
    func_0022C5A0();
    func_002256C0();
    func_00217A50();
    if (D_0028DC98 >= 2) {
        if (D_0028DC98 >= 4) {
            func_0021B080(D_00586FF0, g_gif_buf);
        } else {
            func_0021ABB0(g_gif_buf);
            if (D_0028E32C != 5) {
                func_0021BAE0(g_gif_buf);
            }
            func_0021AE20(D_00586FF0, g_gif_buf);
        }
    }
    func_00217040();
    func_002195F0();
    text_flush_rects();
    func_0018E020();
    func_00217D80();
    sceGsSyncPath(0, 0);
    D_0028E9F0 += 1;
    D_0028E37C = 1;
    half = (sceGsSyncV(0) != 0) ^ 1;
    if (D_0028E378 == 1) {
        D_0028E378 = 0;
    } else if (D_0028E37C != 0) {
        if (D_0028E21C == 2) {
            sceGsSyncV(0);
        } else {
            if (D_0028E310 != 0) {
                D_0028E310 -= 1;
            }
            if ((D_0028E310 != 0) && (D_0028E3F0 & 1)) {
                sceGsSyncV(0);
            }
        }
        D_0028E37C &= 1;
    }
    D_0028E21C = 0;
    if ((D_0028DC98 != 2) && (D_0028DC98 != 3)) {
        if (D_0028E9F0 & 1) {
            sceGsSetHalfOffset(D_0057C9B0, 0x800, 0x800, half);
            sceGsSetHalfOffset2(D_0057CA30, 0x800, 0x800, half);
        } else {
            sceGsSetHalfOffset(D_0057C840, 0x800, 0x800, half);
            sceGsSetHalfOffset2(D_0057C8C0, 0x800, 0x800, half);
        }
    }
    if (D_0028E8A8 > D_0028E9DC) {
        D_0028E9DC = D_0028E8A8;
    }
    FlushCache(0);
    sceGsSyncPath(0, 0);
}
