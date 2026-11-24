#include "common.h"

s32 func_0011C4A0();
s32 func_0011C610();
s32 func_00137AD0();
s32 func_0018D9F0();
extern u32 D_00269BA0_as_u32_a[];
extern u8 D_00269BB0[];
extern u8 D_00269C00[];
extern s16 D_002BF3F6_as_s16_a[];
extern u8 *reg_a0;
extern u8 *reg_a4;
#ifdef DEATH_LABEL
s32 func_00130CC0();
extern u8 death_D_00251300[];
extern u8 death_D_00251310[];
extern u16 D_0028E314;
extern u16 D_0028E318;
#endif

void func_00134750(void) {
    s32 temp_a3;
    u32 temp_a2;
    u32 temp_a3_2;
    u8 temp_a0;

    if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
        (*(u16 *)((u8 *)(reg_a4) + (2))) = 1U;
        (*(u8 *)((u8 *)(reg_a4) + (0xD))) = 0U;
        (*(u16 *)((u8 *)(reg_a4) + (0x10))) = 0U;
        (*(s16 *)((u8 *)(reg_a4) + (0xE))) = 3;
        (*(u16 *)((u8 *)(reg_a4) + (0x14))) = 0U;
        (*(s16 *)((u8 *)(reg_a4) + (0x12))) = 1;
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x33;
        reg_a0 = (u8 *)(D_00269BA0_as_u32_a);
        reg_d2.h[0] = 2;
        func_00137AD0();
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x33;
        reg_a0 = (u8 *)(D_00269BA0_as_u32_a);
        reg_d2.h[0] = 2;
        func_00137AD0();
        D_002BF3F6_as_s16_a[0] = 0;
    }
#ifdef DEATH_LABEL
    reg_d0.h[0] = 1;
    reg_d1.h[0] = 0x32;
    reg_a0 = (u8 *)death_D_00251300;
    reg_d2.h[0] = 2;
    func_00137AD0();
    reg_d0.h[0] = 1;
    reg_d4.w = 0;
    reg_d1.h[0] = 0x32;
    reg_d2.h[0] = 2;
    reg_d4.h[0] = D_0028E318;
    reg_d0.h[0] += 0xA;
    func_00130CC0();
    reg_d0.h[0] = 0xF;
    reg_d1.h[0] = 0x32;
    reg_a0 = (u8 *)death_D_00251310;
    reg_d2.h[0] = 2;
    func_00137AD0();
    reg_d0.h[0] = 0xF;
    reg_d4.w = 0;
    reg_d1.h[0] = 0x32;
    reg_d2.h[0] = 2;
    reg_d4.h[0] = D_0028E314;
    reg_d0.h[0] += 0xA;
    func_00130CC0();
#endif
    (*(u8 *)((u8 *)(reg_a4) + (0xF))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0xF))) < 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0xF))) = (*(u8 *)((u8 *)(reg_a4) + (0xE)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
        temp_a3 = reg_tmp.h[0] & ~3;
        temp_a2 = *(u32 *)(D_00269BB0 + temp_a3);
        reg_d4.w = temp_a2;
        reg_d0.h[0] = 0x8C;
        reg_d1.h[0] = 0x400;
        reg_d2.w = 3;
        reg_d3.w = 0x13;
        func_0011C4A0();
        (*(u16 *)((u8 *)(reg_a4) + (0x10))) += 4;
        if ((*(u16 *)((u8 *)(reg_a4) + (0x10))) == 0x44) {
            (*(u16 *)((u8 *)(reg_a4) + (0x10))) = 0U;
        }
    }
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) (*(s8 *)((u8 *)(reg_a4) + (0xA)));
    reg_a0 = *(u8 **)(D_00269C00 + (reg_d4.h[0] * 4));
    reg_a0 += (*(u16 *)((u8 *)(reg_a4) + (0x14)));
    temp_a3_2 = *(u32 *)reg_a0;
    reg_d4.w = temp_a3_2;
    reg_d0.h[0] = 0x74;
    reg_d1.h[0] = 0xC00;
    reg_d2.w = 7;
    reg_d3.w = 3;
    reg_d5.h[0] = 0xC;
    func_0011C610();
    (*(u8 *)((u8 *)(reg_a4) + (0x13))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0x13))) < 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0x13))) = (*(u8 *)((u8 *)(reg_a4) + (0x12)));
        (*(u16 *)((u8 *)(reg_a4) + (0x14))) += 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (0x14))) >= 0xC) {
            (*(u16 *)((u8 *)(reg_a4) + (0x14))) = 0U;
        }
    }
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) (*(s8 *)((u8 *)(reg_a4) + (0xA)));
    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
    if (temp_a0 != reg_d4.b[0]) {
        (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) reg_d4.b[0];
        func_0018D9F0();
    }
}
