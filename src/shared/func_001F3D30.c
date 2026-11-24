#include "common.h"

s32 func_00124D90();
s32 func_00124DC0();
s32 func_00124F50();
s32 func_0018D2D0();
s32 func_001F3A10();
s32 func_001F56F0();
s32 func_001F57C0();
s32 func_00201C60();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001F3D30(void) {
    u16 temp_v0;

    temp_v0 = (*(u16 *)((u8 *)(reg_a4) + (6)));
    if (temp_v0 != 0) {
        (*(u16 *)((u8 *)(reg_a4) + (6))) = (u16) (temp_v0 - 1);
        if ((*(u16 *)((u8 *)(reg_a4) + (6))) == 0) {
            func_0018D2D0();
            reg_d0.w = 3;
            func_00124F50();
            reg_d0.w = 4;
            func_00124F50();
            reg_d0.w = 0xA;
            func_00124DC0();
            reg_d0.w = 0xE;
            func_00124DC0();
            (*(s16 *)((u8 *)(reg_a6) + (0x172))) = 0x1000;
            func_001F56F0();
            func_001F57C0();
            goto block_3;
        }
    } else {
block_3:
        func_00201C60();
        if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
            (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
                (*(u8 *)((u8 *)(reg_a4) + (4))) -= 1;
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 1;
                if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 8) {
                    (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x303;
                    (*(u16 *)((u8 *)(reg_a4) + (2))) = 1U;
                }
            }
        } else {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
            (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
                if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 4) {
                    reg_d0.w = 2;
                    func_00124D90();
                    (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
                }
            }
        }
    }
    func_001F3A10();
}
