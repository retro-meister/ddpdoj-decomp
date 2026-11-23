#include "common.h"

extern s8 D_0028E408;

s32 func_00171400();
s32 func_001B7620();
s32 func_002026F0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B7700(void) {
    u8 temp_v1;

    if ((*(u8 *)((u8 *)(reg_a4) + (9))) == 0) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (4)));
            if ((s32) temp_v1 > 0x10) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) = (u8) (temp_v1 - 4);
            }
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            goto block_5;
        }
    } else {
block_5:
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
        (*(u8 *)((u8 *)(reg_a4) + (0xB))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0xB))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xA)));
            func_00171400();
            if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
                reg_d0.h[0] += 0x7FFF + 0x76C1;
                reg_d1.h[0] += 0x140;
                func_002026F0();
                if (D_0028E408 == 0) {
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
                    reg_d2.w += 0xF6C00140;
                    func_001B7620();
                }
            }
            if ((*(u8 *)((u8 *)(reg_a6) + (0x7E))) == 0) {
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
                reg_d0.h[0] += 0x7FFF + 0x76C1;
                reg_d1.h[0] += 0x7FFF + 0x7EC1;
                func_002026F0();
                if (D_0028E408 == 0) {
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
                    reg_d2.w += 0xF6BFFEC0;
                    func_001B7620();
                }
            }
            (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
            if ((*(u8 *)((u8 *)(reg_a4) + (9))) == 0) {
                (*(u16 *)((u8 *)(reg_a4) + (6))) += 1;
                (*(u16 *)((u8 *)(reg_a4) + (6))) &= 1;
            }
        }
    }
}
