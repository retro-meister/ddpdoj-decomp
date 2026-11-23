#include "common.h"

s32 func_00168BA0();
s32 func_0022C6F0();
s32 func_0022C710();
s32 func_00234EF0();
s32 printf();
extern u8 D_00275870[];
extern u8 D_0028ECF4;
extern s32 D_0028ED0C;
extern s32 D_006A0E40[];
extern u8 *reg_a5;

void func_00169950(void) {
    u8 temp_a0;
    u8 *temp_a1;

    temp_a1 = (u8 *)(reg_a5 + 2);
    temp_a0 = (*(u8 *)((u8 *)(reg_a5) + (2)));
    switch (temp_a0) {                              /* irregular */
    case 0:
        D_0028ED0C = 0;
        (*(u8 *)((u8 *)(reg_a5) + (2))) = 1U;
        break;
    case 1:
        func_0022C710(temp_a0, temp_a1);
        if (D_0028ED0C != 0) {
            D_0028ED0C = 0;
            printf(D_00275870, D_0028ECF4);
            if (D_0028ECF4 & 0xC) {
                (*(u8 *)((u8 *)(reg_a5) + (2))) = 2U;
                break;
            }
            (*(u8 *)((u8 *)(reg_a5) + (2))) = 3U;
            break;
        }
        break;
    case 2:
        func_0022C6F0(temp_a0, temp_a1);
        if (D_0028ED0C != 0) {
            (*(u8 *)((u8 *)(reg_a5) + (2))) = 3U;
            if (D_006A0E40[0] != 0) {
                func_00234EF0(3);
            }
            D_0028ED0C = 0;
            break;
        }
        break;
    case 3:
        reg_d0.h[0] = 0xD;
        func_00168BA0();
        break;
    }
}
