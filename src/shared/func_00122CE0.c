#include "common.h"

void func_0013FD20(void);
void func_0013FD50(void);
void func_00141640(void);
void func_001A7E90(void);
void func_001A8070(void);
extern u8 D_0028C608[];
extern u8 D_0028E008;
extern u8 D_0028E00C;
extern u16 D_0028E018;
extern u16 D_0028E01C;
extern u16 D_0028E028;
extern u16 D_0028E02C;
extern u8 D_0028E290;
extern u8 D_0028E2EC;
extern s8 D_0028E408;
extern s16 D_0028E5B0;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u16 D_0028E748;
extern u16 D_0028E750;
extern s16 D_0028E8C4;
extern u16 D_0028E910;
extern u16 D_0028E920;
extern u16 D_0028E980;
extern u8 D_0029F1F0[];
extern u8 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_00122CE0(void) {
    if (D_0028E2EC != 0) goto block_1;
    if (D_0028E290 == 1) goto block_1;
#ifdef DEATH_LABEL
    if (D_0028E290 == 2) goto block_1;
#endif
    if (D_0028E910 != 0) goto block_1;
    if (D_0028E5FC != 0) {
        func_001A7E90();
        func_0013FD20();
    }
    if (D_0028E5F8 != 0) {
        func_001A8070();
        func_0013FD50();
    }
    func_00141640();
    D_0028E5B0 = 0;
    if (D_0028E920 == 3) goto block_1;
    reg_a0 = &D_0028E00C;
    reg_d0.h[0] = D_0028E980;
    reg_a1 = (u8 *)D_0029F260;
    reg_d1.h[0] = D_0028E01C;
    reg_d2.h[0] = D_0028E750;
    reg_d3.h[0] = D_0028E02C;
    if (0 > D_0028E8C4) {
        reg_a0 = &D_0028E008;
        reg_d1.h[0] = D_0028E018;
        reg_a1 = (u8 *)D_0029F1F0;
        reg_d2.h[0] = D_0028E748;
        reg_d3.h[0] = D_0028E028;
    }
    if (reg_d2.h[0] != 0) goto block_1;
    if (reg_d3.h[0] == 0 || reg_d1.h[0] == 0) {
        *(s16 *)(reg_a0 + 0) = 1;
    }
    if ((s32)reg_d0.h[0] < 0xC && (s32)reg_d3.h[0] > 2 && (s32)reg_d1.h[0] > 3) {
    block_1:
        D_0028E408 = 0;
        return;
    }
    reg_d0.h[0] = *(u16 *)(reg_a1 + 0x5A);
    reg_a0 = (u8 *)D_0028C608;
    reg_d0.h[0] -= 2;
    reg_a0 += reg_d0.h[0];
    *(u8 *)(reg_a1 + 0x25) = *(u8 *)(reg_a0 + 1);
    *(u8 *)(reg_a1 + 0x24) = *(u8 *)(reg_a0 + 0);
    D_0028E408 = 1;
    reg_a0 += 2;
}
