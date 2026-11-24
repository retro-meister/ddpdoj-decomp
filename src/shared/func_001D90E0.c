#include "common.h"

typedef void (*Fn)();

s32 func_00129410();
s32 func_001D7940();
extern void (*jtbl_0028E3F4)();
extern s8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D90E0(s32 first, s32 second, void (*callback)(void), s8 *table) {
    jtbl_0028E3F4 = (Fn) callback;
    jtbl_0028E3F4();
    reg_a0 = table;
    reg_a0 += *(u16 *) (reg_a4 + 0xC);
    reg_d7.b[0] = *reg_a0;
    reg_tmp.b[0] = *(u8 *) (reg_a4 + 5);
    *(u8 *) (reg_a4 + 5) -= 1;
    if (reg_tmp.b[0] > 0) return;
    *(u8 *) (reg_a4 + 5) = *(u8 *) (reg_a4 + 4);
    if (*(u16 *) (reg_a4 + 0xA) != 0) goto next_1;
    reg_d0.h[0] = (first) ? *(u16 *) (reg_a6 + ((s16) first & ~1)) : *(u16 *) reg_a6;
    func_001D7940();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d0.h[0] = *(u16 *) (reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (second) ? *(u16 *) (reg_a6 + ((s16) second & ~1)) : *(u16 *) reg_a6;
    reg_d2.h[0] = (second + 2) ? *(u16 *) (reg_a6 + ((s16) (second + 2) & ~1)) : *(u16 *) reg_a6;
    reg_d4.w = 0;
    func_00129410();
next_1:
    if (*(u16 *) (reg_a4 + 0xA) != 1) goto next_2;
    reg_d0.h[0] = (first) ? *(u16 *) (reg_a6 + ((s16) first & ~1)) : *(u16 *) reg_a6;
    reg_d0.h[0] += 8;
    func_001D7940();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d0.h[0] = *(u16 *) (reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (second) ? *(u16 *) (reg_a6 + ((s16) second & ~1)) : *(u16 *) reg_a6;
    reg_d2.h[0] = (second + 2) ? *(u16 *) (reg_a6 + ((s16) (second + 2) & ~1)) : *(u16 *) reg_a6;
    reg_d4.w = 0;
    func_00129410();
next_2:
    if (*(u16 *) (reg_a4 + 0xA) != 2) goto next_3;
    reg_d0.h[0] = (first) ? *(u16 *) (reg_a6 + ((s16) first & ~1)) : *(u16 *) reg_a6;
    reg_d0.h[0] += 0x10;
    func_001D7940();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d0.h[0] = *(u16 *) (reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (second) ? *(u16 *) (reg_a6 + ((s16) second & ~1)) : *(u16 *) reg_a6;
    reg_d2.h[0] = (second + 2) ? *(u16 *) (reg_a6 + ((s16) (second + 2) & ~1)) : *(u16 *) reg_a6;
    reg_d4.w = 0;
    func_00129410();
next_3:
    *(u16 *) (reg_a4 + 8) += 1;
    *(u16 *) (reg_a4 + 0xA) += 1;
    if (*(s16 *) (reg_a4 + 0xA) <= 2) goto next_4;
    *(u16 *) (reg_a4 + 0xA) = 0;
next_4:
    *(u8 *) (reg_a4 + 7) -= 1;
    if (*(s8 *) (reg_a4 + 7) != 0) return;
    *(u8 *) (reg_a4 + 7) = *(u8 *) (reg_a4 + 6);
    *(u8 *) (reg_a4 + 5) = 4;
    *(u16 *) (reg_a4 + 0xA) = 0;
    *(u16 *) (reg_a4 + 8) = 6;
    *(u16 *) (reg_a4 + 0xC) += 1;
    if (*(u16 *) (reg_a4 + 0xC) != 3) return;
    *(s16 *) (reg_a4 + 0) = 0;
}
