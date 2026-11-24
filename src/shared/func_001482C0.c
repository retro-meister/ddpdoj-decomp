#include "common.h"

s32 func_001466E0();
s32 func_00146720();
s32 func_0020A120();
s32 func_0020A1C0();
extern u16 D_0028DFD4;
extern u16 D_0028DFD8;
extern u16 D_0028E000;
extern u16 D_0028E004;
extern u16 D_0028E3EC;
extern u16 D_0028E928;
extern u8 D_0029D710[];
extern u8 D_0029D730[];
extern u16 D_0029F112[];
extern u16 D_0029F182[];
extern u16 D_0029F1F4[];
extern u16 D_0029F264[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_001482C0(void) {
    u16 temp_a2;
    u16 temp_a2_2;
    u32 temp_a1;
    u32 temp_a1_2;

    reg_a6 = (u8 *)D_0029D730;
    if ((*(s16 *)((u8 *)(reg_a6) + (0))) < 0) {
        if ((D_0028E3EC != 0) && (D_0028E928 != 0) && (D_0028E004 == 0)) {
            func_0020A120();
        }
        reg_d0.h[0] = D_0028DFD8;
        reg_d1.h[0] = D_0029F182[0];
        reg_d0.h[0] += 0x180;
        reg_d1.h[0] += 0x400;
        if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
            reg_d0.h[0] = reg_d1.h[0];
        }
        reg_a1 = (u8 *)(reg_a6 + 2);
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
        reg_a0 = (u8 *)(reg_tmp.w);
        temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
        reg_a0 += temp_a2;
        *(u16 *)reg_a1 = reg_d0.h[0];
        reg_a1 += 2;
        *(u16 *)reg_a1 = D_0029F264[0];
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a1 = (unsigned int)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a1);
        reg_a1 += 2;
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) -= 0xA;
        if ((s32) reg_tmp.h[0] < 0xA) {
            (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x18)));
        }
        if (D_0028E004 == 0) {
            func_001466E0();
        }
    }
    reg_a6 = (u8 *)D_0029D710;
    if ((*(s16 *)((u8 *)(reg_a6) + (0))) < 0) {
        if ((D_0028E3EC == 0) && (D_0028E928 != 0) && (D_0028E000 == 0)) {
            func_0020A1C0();
        }
        reg_d0.h[0] = D_0028DFD4;
        reg_d1.h[0] = D_0029F112[0];
        reg_d1.h[0] += 0x400;
        if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
            reg_d0.h[0] = reg_d1.h[0];
        }
        reg_a1 = (u8 *)(reg_a6 + 2);
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
        reg_a0 = (u8 *)(reg_tmp.w);
        temp_a2_2 = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
        reg_a0 += temp_a2_2;
        *(u16 *)reg_a1 = reg_d0.h[0];
        reg_a1 += 2;
        *(u16 *)reg_a1 = D_0029F1F4[0];
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a1_2 = (unsigned int)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a1_2);
        reg_a1 += 2;
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) -= 0xA;
        if ((s32) reg_tmp.h[0] < 0xA) {
            (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x18)));
        }
        if (D_0028E000 == 0) {
            func_00146720();
        }
    }
}
