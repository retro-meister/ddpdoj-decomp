#include "common.h"

s32 func_00125310();
s32 func_001ECBD0();
s32 func_00202A80();
extern u8 D_00262A50[];
extern s16 D_0028E88C;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001ECE40() {
    u16 temp_v0_2;
    u16 temp_v0_3;
    u8 temp_v0;

    D_0028E88C = 0;
    func_00202A80();
    if ((s32) reg_d0.h[0] < 0x2000) {
        D_0028E88C = 1;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (7)));
        reg_a1 = D_00262A50;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x10)));
        func_001ECBD0();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x11)));
        (*(u8 *)((u8 *)(reg_a4) + (0x10))) += reg_d0.b[0];
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(s8 *)((u8 *)(reg_a6) + (0x1F1))) = (s8) ~(*(s8 *)((u8 *)(reg_a6) + (0x1F1)));
            temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x1F0)));
            if ((s32) temp_v0 < 0x95) {
                (*(u8 *)((u8 *)(reg_a6) + (0x1F0))) = (u8) (temp_v0 + 0xA);
            }
            temp_v0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x1F2)));
            if ((s32) temp_v0_2 < 2) {
                (*(u16 *)((u8 *)(reg_a6) + (0x1F2))) = (u16) (temp_v0_2 + 1);
            }
            temp_v0_3 = (*(u16 *)((u8 *)(reg_a6) + (0x1F4)));
            if ((s32) temp_v0_3 < 3) {
                (*(u16 *)((u8 *)(reg_a6) + (0x1F4))) = (u16) (temp_v0_3 + 1);
            }
            reg_d0.w = 0xA;
            func_00125310();
        }
    }
}
