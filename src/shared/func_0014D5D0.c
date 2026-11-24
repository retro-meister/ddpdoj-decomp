#include "common.h"

extern s8 D_0028E408;

s32 func_0014DDB0();
s32 func_0014E130();
extern u16 D_0028E7D4;
extern u16 D_0028E8A8;
extern u8 D_002BBB40[];
extern u8 D_002BF2E0[];
extern u8 D_002BF330[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_0014D5D0(void) {
    u8 *save_a2;
    u8 *save_a3;

    reg_a3 = (u8 *)D_002BF330;
    reg_tmp.h[1] = *(u16 *) (reg_a3 + 0);
    reg_tmp.h[0] = *(u16 *) (reg_a3 + 2);
    reg_a2 = (u8 *) reg_tmp.w;
loop_1:
    reg_d0.h[0] = *(u16 *) (reg_a2 + 0);
    if (reg_d0.h[0] == 0xFFFF) goto next_3;
    if ((s16) D_0028E8A8 > (s16) reg_d0.h[0]) goto next_2;
    if (D_0028E8A8 != reg_d0.h[0]) goto next_3;
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *) (reg_a2 + 5);
    reg_d1.h[1] = *(u16 *) (reg_a2 + 4);
    reg_d1.h[0] = *(u16 *) (reg_a2 + 6);
    reg_d1.w &= 0xFFF000;
    reg_d7.w = 0x10;
    reg_d1.w = (u32) reg_d1.w >> reg_d7.w;
    reg_d7.h[0] = *(u16 *) (reg_a2 + 6);
    reg_d7.h[0] &= 0xFFF;
    reg_tmp.h[1] = *(u16 *) (reg_a3 + 4);
    reg_tmp.h[0] = *(u16 *) (reg_a3 + 6);
    reg_a1 = (u8 *) reg_tmp.w;
    reg_d7.h[0] += reg_d7.h[0];
    reg_d7.h[0] = (reg_d7.h[0] != 0) ? *(u16 *) (reg_a1 + ((s16) reg_d7.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[1] = *(u16 *) (reg_a3 + 8);
    reg_tmp.h[0] = *(u16 *) (reg_a3 + 0xA);
    reg_a1 = (u8 *) reg_tmp.w;
    reg_a1 += reg_d7.h[0];
    func_0014E130();
    if (D_0028E408 != 0) goto next_2;
    *(u16 *) (reg_a0 + 0xA) = *(u16 *) (reg_a2 + 2);
    reg_tmp.w = (u32) reg_a1;
    *(u16 *) (reg_a0 + 0x12) = reg_tmp.h[1];
    *(u16 *) (reg_a0 + 0x14) = reg_tmp.h[0];
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    reg_a5 = reg_a0;
    func_0014DDB0();
    reg_a3 = save_a3;
    reg_a2 = save_a2;
next_2:
    reg_a2 += 8;
    goto loop_1;
next_3:
    reg_tmp.w = (u32) reg_a2;
    (*(u16 *)((u8 *)(reg_a3) + (0))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a3) + (2))) = (u16) reg_tmp.h[0];
loop_11:
    reg_d6.h[0] = D_0028E7D4;
    if (D_0028E7D4 != 0) {
        reg_a4 = (u8 *)D_002BBB40;
        reg_d6.h[0] -= 0x50;
        reg_a4 += reg_d6.h[0];
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
        func_0014E130();
        if (D_0028E408 == 0) {
            (*(u8 *)((u8 *)(reg_a0) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (3)));
            (*(u16 *)((u8 *)(reg_a0) + (0x12))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x12)));
            (*(u16 *)((u8 *)(reg_a0) + (0x14))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x14)));
            (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x16)));
            (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x18)));
            (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x1A)));
            (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x1C)));
            (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x1E)));
            (*(u16 *)((u8 *)(reg_a0) + (0x20))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x20)));
            (*(u16 *)((u8 *)(reg_a0) + (0x22))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x22)));
            (*(u16 *)((u8 *)(reg_a0) + (0x24))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x24)));
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x26)));
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x28)));
            (*(u16 *)((u8 *)(reg_a0) + (0x2A))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x2A)));
            (*(u16 *)((u8 *)(reg_a0) + (0x2C))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x2C)));
            (*(u16 *)((u8 *)(reg_a0) + (0x2E))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x2E)));
            (*(u16 *)((u8 *)(reg_a0) + (0x30))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x30)));
            (*(u16 *)((u8 *)(reg_a0) + (0x32))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x32)));
            (*(u16 *)((u8 *)(reg_a0) + (0x34))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x34)));
            (*(u16 *)((u8 *)(reg_a0) + (0x36))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x36)));
            (*(u16 *)((u8 *)(reg_a0) + (0x38))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x38)));
            (*(u16 *)((u8 *)(reg_a0) + (0x3A))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x3A)));
            (*(u16 *)((u8 *)(reg_a0) + (0x3C))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x3C)));
            (*(u16 *)((u8 *)(reg_a0) + (0x3E))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x3E)));
            (*(u16 *)((u8 *)(reg_a0) + (0x40))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x40)));
            (*(u16 *)((u8 *)(reg_a0) + (0x42))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x42)));
            (*(u16 *)((u8 *)(reg_a0) + (0x44))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x44)));
            (*(u16 *)((u8 *)(reg_a0) + (0x46))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x46)));
            (*(u16 *)((u8 *)(reg_a0) + (0x48))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x48)));
            (*(u16 *)((u8 *)(reg_a0) + (0x4A))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x4A)));
        }
        D_0028E7D4 = reg_d6.h[0];
        if (D_002BF2E0 != reg_a0) {
            reg_a5 = reg_a0;
            func_0014DDB0();
        }
        if (D_0028E7D4 != 0) {
            goto loop_11;
        }
    }
}
