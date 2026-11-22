#include "common.h"

s32 func_00129280();
s32 func_00129410();
extern u16 D_0028E910;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DAA00(void) {
    u16 temp_a1;
    u16 temp_a2;
    u8 temp_a0;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
        temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
        reg_d2.h[0] = temp_a1;
        reg_d3.w = 0xF94001C0;
        reg_d4.w = 0;
        reg_d1.w = 0;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x11)));
        reg_d0.w = 0xFFFC0016;
        if (D_0028E910 == 0) {
            func_00129410();
            reg_d1.b[0] += 0x55;
            func_00129410();
            reg_d1.b[0] += 0x55;
            func_00129410();
        } else {
            func_00129280();
            reg_d1.b[0] += 0x40;
            func_00129280();
            reg_d1.b[0] += 0x40;
            func_00129280();
            reg_d1.b[0] += 0x40;
            func_00129280();
        }
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
        temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
        reg_d2.h[0] = temp_a2;
        reg_d3.w = 0xF93FFE40;
        reg_d4.w = 0;
        reg_d1.w = 0;
        temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (0x10)));
        reg_d1.b[0] = temp_a0;
        reg_d0.w = 0xFFFC0016;
        if (D_0028E910 == 0) {
            func_00129410();
            reg_d1.b[0] += 0x55;
            func_00129410();
            reg_d1.b[0] += 0x55;
            func_00129410();
        } else {
            func_00129280();
            reg_d1.b[0] += 0x40;
            func_00129280();
            reg_d1.b[0] += 0x40;
            func_00129280();
            reg_d1.b[0] += 0x40;
            func_00129280();
        }
        (*(u8 *)((u8 *)(reg_a4) + (0x11))) -= 4;
        (*(u8 *)((u8 *)(reg_a4) + (0x10))) += 4;
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
        (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
            (*(u8 *)((u8 *)(reg_a4) + (0x11))) -= 4;
            (*(u8 *)((u8 *)(reg_a4) + (0x10))) += 4;
        }
    }
}
