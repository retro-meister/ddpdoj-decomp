#include "common.h"

s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0019BF00();
s32 func_001A9000();
extern Reg32 D_0028E484;
extern u16 D_0028E8A0;
extern u16 D_0029C06C[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001DE2E0(void) {
    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x5000;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x2000;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += D_0028E484.w;
        reg_d0.h[0] += 0x5000;
        if (reg_tmp.h[1] != 0) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
                func_0014E290();
                return;
            }
            goto block_5;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_5:
        (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d0.h[0] = D_0029C06C[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x24))) -= reg_d0.h[0];
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        reg_d1.b[0] |= (*(u8 *)((u8 *)(reg_a6) + (0x21)));
        reg_d1.h[0] &= 0x5C;
        if (reg_d1.h[0] != 0) {
            reg_d0.h[0] = 0xA3;
            (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x21))) &= reg_d0.b[0];
            func_001A9000();
            reg_d0.h[0] = 0x7FFF;
            (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x38))) = (u16) reg_d0.h[0];
        }
        if (D_0028E8A0 == 0) {
            reg_a0 = reg_a6;
            func_0014D220();
            reg_a0 = reg_a6 + 0x20;
            func_0014D220();
            if ((*(u8 *)((u8 *)(reg_a6) + (0x1F))) != 0) {
                reg_d0.h[0] = 0x40;
                (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d0.h[0];
                (*(u16 *)((u8 *)(reg_a6) + (0x24))) -= reg_d0.h[0];
                (*(u16 *)((u8 *)(reg_a5) + (0x18))) += reg_d0.h[0];
                if ((s32) (*(u16 *)((u8 *)(reg_a5) + (0x18))) >= 0x2A80) {
                    func_0014E290();
                    return;
                }
            }
        }
        func_0019BF00();
        if ((s32) (*(u16 *)((u8 *)(reg_a5) + (0x18))) < 0x2680) {
            reg_a6 += 0x20;
            func_0019BF00();
        }
    }
}
