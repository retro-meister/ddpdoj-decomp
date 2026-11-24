#include "common.h"

typedef void (*Fn)();

extern u8 D_002509E0[];
s32 func_002010A0();
s32 func_00201130();
s32 func_00201160();
s32 func_002011A0();
s32 func_002011D0();
s32 func_00201390();
extern u16 D_00250CE0[];
extern u8 D_0028E52F;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_001B8D00(void) {
    u8 flag;

    reg_a2 = (u8 *)(D_00250CE0);
    reg_d4.h[0] = 0x8000;
    reg_d0.h[0] >>= 8;
    reg_d1.b[0] = reg_d0.b[0];
    if (0 > reg_d1.sb[0]) {
        reg_d0.b[0] = ~(s8)(reg_d0.b[0]);
        if (reg_d0.h[0] & 1) {
            reg_d0.h[0] &= 0xFFFE;
            reg_d4.h[0] |= 0x400;
            reg_d1.b[0] = reg_d0.b[0];
            reg_d1.b[0] = ~(s8) reg_d1.b[0];
        }
    }
    reg_d1.h[0] = (u16) (s8) reg_d1.b[0];
    reg_d0.h[0] &= 0x1C;
    reg_d2.h[0] = reg_d0.h[0];
    reg_a2 = *(u8 **)((u8 *)D_00250CE0 + (reg_d0.h[0] & ~3));
    (*(u16 *)((u8 *)(reg_a0) + (0))) = reg_d4.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    if (0 > (s32) reg_d3.w) {
        func_00201390();
        (*(u16 *)((u8 *)(reg_a0) + (4))) += reg_d4.h[0];
    }
    (*(u16 *)((u8 *)(reg_a0) + (6))) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (8))) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d4.h[0] = reg_d0.h[0];
    reg_d4.h[0] &= 0xFF00;
    func_002011D0();
    if (reg_d0.b[0] == 0) {
        reg_d4.h[0] |= 0x1000;
    }
    reg_d4.h[0] <<= 8;
    reg_d4.h[0] = (u16) reg_d4.b[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x24))) = (u16) reg_d4.h[0];
    (*(u8 *)((u8 *)(reg_a0) + (0x1D))) = 0U;
    (*(s8 *)((u8 *)(reg_a0) + (0x1C))) = 0x1E;
    reg_d0.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (0xE))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x14))) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (0x20))) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    func_002011A0();
    reg_d0.b[0] &= 0xF;
    reg_d0.b[0] += 0x1A;
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d0.b[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x10))) = (u16) *(u16 *)reg_a2;
    (*(u16 *)((u8 *)(reg_a0) + (0x12))) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    func_00201130();
    reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
    reg_d0.h[0] += 0x30;
    (*(u16 *)((u8 *)(reg_a0) + (0x22))) = (u16) reg_d0.h[0];
    reg_a1 = (u8 *)D_002509E0;
    reg_a1 += reg_d2.h[0];
    reg_a1 = *(u8 **)reg_a1;
    jtbl_0028E3F4 = (Fn)(reg_a1);
    jtbl_0028E3F4();
    if (0 > (s16) reg_d1.h[0]) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0x20)));
        reg_d0.b[0] += 0x10;
        (*(u8 *)((u8 *)(reg_a0) + (0x21))) = (u8) reg_d0.b[0];
        func_002011A0();
        reg_d0.h[0] &= 0xF;
        if ((*(u8 *)((u8 *)(reg_a0) + (1))) & 4) {
            reg_d0.b[0] >>= 1;
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) -= 8;
        }
        (*(u8 *)((u8 *)(reg_a0) + (0x1B))) += reg_d0.b[0];
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a0) + (0x1B)));
        reg_d0.b[0] += 0x20;
        (*(u8 *)((u8 *)(reg_a0) + (0x27))) = (u8) reg_d0.b[0];
        func_002010A0();
        reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
        reg_d0.b[0] += D_0028E52F;
    } else {
        func_00201160();
        if (((s32) reg_d0.h[0] > 0x15) && ((s32) reg_d0.h[0] < 0x2B)) {
            reg_d0.h[0] += 0x20;
            reg_d0.h[0] &= 0x3F;
        }
        flag = (*(u8 *)((u8 *)(reg_a0) + (0x1E)));
        if (flag & 0x20) {
            (*(u8 *)((u8 *)(reg_a0) + (0x1E))) = flag & 0xDF;
            reg_d0.h[0] += 0x16;
            reg_d0.h[0] &= 0x3F;
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
            reg_d0.h[0] += 0x15;
        }
    }
    reg_d1.h[0] = reg_d0.h[0];
    if ((s32) reg_d1.b[0] >= 0x20) {
        (*(u8 *)((u8 *)(reg_a0) + (0x1D))) |= 0x20;
    }
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d1.b[0];
}
