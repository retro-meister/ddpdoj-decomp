#include "common.h"

s32 func_0012FAB0();
s32 func_0012FB00();
s32 func_00168BA0();
s32 func_0018DEE0();
s32 func_00221C20();
s32 func_00224B50();
s32 func_002365A0();
s32 func_002368E0();
extern s32 D_0028EAF8;
extern s32 D_0028EC78;
extern s32 D_0028EC7C;
extern u8 *reg_a5;

void func_00169A50(void) {
    u8 temp_a0;

    temp_a0 = (*(u8 *)((u8 *)(reg_a5) + (2)));
    switch (temp_a0) {                              /* irregular */
    case 0:
        func_0012FAB0();
        func_0012FB00();
        func_0018DEE0();
        (*(u8 *)((u8 *)(reg_a5) + (2))) = 1U;
        D_0028EC7C = 0;
        D_0028EAF8 = 0;
        func_00224B50();
        break;
    case 1:
        if (func_00221C20(temp_a0) != 0) {
            (*(u8 *)((u8 *)(reg_a5) + (2))) = 2U;
            break;
        }
        break;
    case 2:
        if (func_002365A0(temp_a0) != 0) {
            (*(u8 *)((u8 *)(reg_a5) + (2))) = 3U;
            D_0028EC78 = 0;
            break;
        }
        break;
    case 3:
        if (func_002368E0(temp_a0) != 0) {
            reg_d0.h[0] = 2;
            func_00168BA0();
        }
        break;
    }
}
