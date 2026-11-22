#include "common.h"

s32 func_001251C0();
s32 func_00125250();
extern s8 D_0028E408;
extern u8 *reg_a4;

void func_001BA160() {
    u8 temp_a0;
    u8 temp_a0_2;

    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        }
    }
    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0 == 1) {
        reg_d0.w = 0xB;
        func_00125250();
        if (D_0028E408 == 0) {
            if ((*(u8 *)((u8 *)(reg_a4) + (9))) == 0) {
                (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
                (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
            } else {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
                (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
                    reg_d0.w = 0xB;
                    func_001251C0();
                    (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
                }
            }
        }
    }
    temp_a0_2 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if ((temp_a0_2 == 2) && (reg_d0.w = 0xC, func_00125250(), (D_0028E408 == 0))) {
        if ((*(u8 *)((u8 *)(reg_a4) + (0xD))) == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
            return;
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
        (*(u8 *)((u8 *)(reg_a4) + (0xB))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0xB))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xA)));
            reg_d0.w = 0xC;
            func_001251C0();
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
        }
    }
}
