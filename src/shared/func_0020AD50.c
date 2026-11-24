#include "common.h"

s32 func_00201160();
s32 func_002011A0();
s32 func_00201D10();
s32 func_0020B5F0();
extern u16 D_00250D20[];
extern u16 *D_0028E530_as_u16_p;
extern u8 D_0029CEA0_as_u8_a[];
extern u16 D_0029F212[];
extern u16 D_0029F282[];
extern u8 *reg_a0;
extern u8 *reg_a2;

void func_0020AD50(void) {
    u32 temp_a0;
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;

    temp_s1 = reg_d0.w;
    temp_s2 = reg_d1.w;
    temp_s3 = reg_d2.w;
    reg_d3.w = 0x18;
    func_002011A0();
    if (0 > reg_d0.sb[0]) {
        reg_d3.w = 0x28;
    }
    func_0020B5F0();
    reg_d1.b[0] += reg_d3.b[0];
    reg_d1.b[0] &= 0x3F;
    func_00201160();
    temp_s0 = reg_d1.w;
    reg_d0.b[0] += 4;
    func_00201D10();
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_d2.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_d3.h[0];
    reg_a0 += 2;
    temp_a0 = (*(u16 *)((u8 *)(reg_a0) + (-0x1C)));
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) = (u16) (temp_a0 + reg_d2.h[0]);
    reg_d0.h[0] = 0xC0;
    if (0 <= (s16)(reg_d7.h[0])) {
        if (reg_d7.h[0] & 0xFFFF) {
            reg_d1.h[0] = D_0029F212[0];
        } else {
            reg_d1.h[0] = D_0029F282[0];
        }
        reg_a2 = (u8 *)(D_00250D20);
        reg_a2 += reg_d1.h[0];
        reg_d0.h[0] = *(u16 *)reg_a2;
    } else {
        reg_d3.h[0] = 2;
        if (D_0029CEA0_as_u8_a[0] & 0x80) {
            reg_d3.h[0] = 3;
        }
        (*(u8 *)((u8 *)(reg_a0) + (-0x12))) = (u8) reg_d3.b[0];
    }
    reg_d1.w = temp_s0;
    func_00201D10();
    (*(u16 *)((u8 *)(reg_a0) + (-0x1A))) += reg_d3.h[0];
    reg_d0.w = temp_s1;
    reg_d1.w = temp_s2;
    reg_d2.w = temp_s3;
    reg_a0 += 2;
    reg_a2 = (u8 *)(D_0028E530_as_u16_p);
}
