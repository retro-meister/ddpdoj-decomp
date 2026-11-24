#include "common.h"

s32 fade_reset();
s32 fade_start_out();
extern s8 D_0028E2F4_as_s8;
extern s8 D_0028E408;
extern u16 D_0028E990;
extern u16 D_0028E994;
extern s8 g_fade_state;

void func_00122C20(void) {
    switch (D_0028E994) {
    case 0:
        D_0028E2F4_as_s8 = 1;
        if (g_fade_state != 0) break;
        D_0028E994 += 1;
        break;
    case 1:
        D_0028E990 -= 1;
        if ((s32) D_0028E990 > 0) break;
        fade_start_out();
        D_0028E994 += 1;
        break;
    case 2:
        if (g_fade_state != 0) break;
        D_0028E994 += 1;
        break;
    }
    if ((s32) D_0028E994 >= 3) {
        fade_reset();
        D_0028E2F4_as_s8 = 0;
        D_0028E408 = 0;
        return;
    }
    D_0028E408 = 1;
}
