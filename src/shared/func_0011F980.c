#include "common.h"

s32 func_0011FA90();
s32 func_00120770();
s32 func_00122B00();
extern u16 D_0028DFC8;
extern u16 D_0029CEA0[];
extern u8 D_0029F110[];
extern u8 D_0029F180[];
extern u8 D_0029F1F0_as_u8_a[];
extern u8 D_0029F260_as_u8_a[];
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0011F980(void) {
    u8 *sa5;

    reg_a6 = (u8 *)(D_0029CEA0);
    reg_d0.h[0] = *(u16 *)reg_a6;
    if ((s16) reg_d0.h[0] >= 0) {
        if (D_0028DFC8 != 0) {
            D_0028DFC8 -= 1;
            if (D_0028DFC8 == 0) {
                func_00122B00();
            }
        }
    } else {
        sa5 = (u8 *)(reg_a5);
        reg_a4 = (u8 *)D_0029F180;
        reg_a5 = (u8 *)D_0029F260_as_u8_a;
        if (*(s8 *)reg_a6 < 0) {
            reg_a4 = (u8 *)D_0029F110;
            reg_a5 = (u8 *)D_0029F1F0_as_u8_a;
        }
        reg_d0.h[0] &= 7;
        switch (reg_d0.h[0]) {
        case 3:
            goto block_1;
        }
        switch (reg_d0.h[0]) {
        case 0:
        case 2:
            func_0011FA90();
            break;
        case 1:
        block_1:
            func_00120770();
            break;
        }
        reg_a5 = sa5;
    }
}
