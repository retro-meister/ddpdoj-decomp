#include "common.h"

s32 func_002011A0();
s32 func_00201270();
extern u16 D_002642C0[];
extern u32 D_0028D9D0;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E9AA0(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_002642C0);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9D0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    func_002011A0();
    if (0 > reg_d0.sb[0]) {
        (*(u8 *)((u8 *)(reg_a4) + (0x1F))) *= -1;
        (*(u8 *)((u8 *)(reg_a4) + (0x1E))) *= -1;
        func_00201270();
        (*(u8 *)((u8 *)(reg_a4) + (0x1F))) += reg_d0.b[0];
        func_00201270();
        (*(u8 *)((u8 *)(reg_a4) + (0x1E))) += reg_d0.b[0];
    }
    (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 1;
    (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 1;
    (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 1;
    (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 1;
    (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 1;
    (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 1;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1CD)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1CE)));
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1D0)));
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x12))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x16))) += reg_d0.h[0];
}
