#include "common.h"

s32 func_001B4BD0();
s32 func_001B57D0(void *);
extern u16 D_0028E4A2;
extern u16 D_0028E89C;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B5BB0(void) {
    u8 temp_v1;

    if ((*(u8 *)((u8 *)(reg_a6) + (0x7E))) != 0) {
        func_001B4BD0();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
        if (D_0028E89C == 0) {
            reg_d0.w = 0x100007;
            D_0028E4A2 = (*(u16 *)((u8 *)(reg_a4) + (8)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            reg_d3.w = 0;
            reg_d1.w = 0;
            temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (2)));
            if (temp_v1 == 0) {
                reg_d0.w = 0x10007;
                reg_d6.w = reg_d0.w;
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
            } else if (temp_v1 == 1) {
                func_001B57D0(reg_a4);
            } else {
                func_001B57D0(reg_a4);
            }
        }
        (*(u16 *)((u8 *)(reg_a4) + (0x10))) += 4;
        (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
        if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
