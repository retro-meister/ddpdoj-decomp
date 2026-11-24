#include "common.h"

s32 func_001713A0();
s32 func_0019C530();
s32 func_0019C730();
s32 func_00201B80();
extern u16 D_002524E0[];
extern u8 D_0028E290;
extern u8 D_0028E2C0;
extern u8 D_0028E2C8;
extern Reg32 D_0028E484;
extern u16 D_0028E8A8;
extern u8 D_0028ED80;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0011DB40(void) {
    u16 temp_a2;
    u16 temp_a2_2;
    u32 temp_a3;

    if ((s32) D_0028E8A8 >= 0x22F) {
        func_001713A0();
        return;
    }
    func_00201B80();
    if (((s32) D_0028E8A8 >= 0x1F4) && (0 <= (s64)*(s16 *)((u8 *)(reg_a6) + (6)))) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x19)));
        (*(u8 *)((u8 *)(reg_a6) + (0x19))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a6) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x18)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (6)));
            reg_a0 = (u8 *)(D_002524E0);
            reg_a0 += reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            (*(u16 *)((u8 *)(reg_a6) + (6))) -= 8;
        }
    }
    if (((s32) D_0028E8A8 < 0x21A) && ((reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2))), reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4))), temp_a3 = reg_d1.w, reg_d1.w = temp_a3 + 0xFE00DC00, reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x10))), temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (0x12))), reg_d2.h[0] = temp_a2, reg_d3.h[0] = 0x2720, reg_d4.h[0] = 0x15, (D_0028ED80 == 0)) || (D_0028E2C8 == 0) || (D_0028E2C0 == 0)) && ((D_0028E290 != 2) || (D_0028E2C0 == 0))) {
        func_0019C730();
    }
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] += 0x4C00;
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = D_0028E484.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.w += 0xFE00DC00;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
    temp_a2_2 = (*(u16 *)((u8 *)(reg_a6) + (0x16)));
    reg_d2.h[0] = temp_a2_2;
    reg_d3.h[0] = 0x2320;
    reg_d4.h[0] = 0x15;
    if (((D_0028ED80 == 0) || (D_0028E2C8 == 0) || (D_0028E2C0 == 0)) && ((D_0028E290 != 2) || (D_0028E2C0 == 0))) {
        func_0019C530();
    }
}
