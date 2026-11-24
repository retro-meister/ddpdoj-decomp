#include "common.h"

typedef void (*Fn)();

s32 func_001292C0();
s32 func_00129410();
s32 func_001D7940();
extern Fn jtbl_0028E3F4_as_Fn;
extern u8 *reg_a4;
extern u8 *reg_a6;

#define LOOKUP(d) (((d) != 0) ? *(u16 *)(reg_a6 + ((s16)(d) & ~1)) : *(u16 *)reg_a6)

void func_001D82E0(u32 arg0, u32 arg1, s32 (*arg2)(void *)) {
    reg_tmp.b[0] = reg_a4[5];
    reg_a4[5] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_2;
    reg_a4[5] = reg_a4[4];
    jtbl_0028E3F4_as_Fn = (Fn) arg2;
    jtbl_0028E3F4_as_Fn();
    reg_d0.h[0] = LOOKUP(arg0);
    func_001D7940();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    func_00129410();
    reg_d1.b[0] += 0xA;
    func_001292C0();
    reg_d1.b[0] += 0xA;
    func_001292C0();
    reg_d1.b[0] -= 0x1E;
    func_001292C0();
    reg_d1.b[0] -= 0xA;
    func_001292C0();
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d0.h[0] += 8;
    func_001D7940();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    func_00129410();
    reg_d1.b[0] += 0xA;
    func_001292C0();
    reg_d1.b[0] += 0xA;
    func_001292C0();
    reg_d1.b[0] -= 0x1E;
    func_001292C0();
    reg_d1.b[0] -= 0xA;
    func_001292C0();
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d0.h[0] += 0x10;
    func_001D7940();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    func_001292C0();
    reg_d1.b[0] += 0xA;
    func_001292C0();
    reg_d1.b[0] += 0xA;
    func_001292C0();
    reg_d1.b[0] -= 0x1E;
    func_001292C0();
    reg_d1.b[0] -= 0xA;
    func_001292C0();
    *(u16 *)(reg_a4 + 0xA) += 1;
    if (*(s16 *)(reg_a4 + 0xA) < 3) goto next_1;
    *(u16 *)(reg_a4 + 0xA) = 0;
next_1:
    *(u16 *)(reg_a4 + 6) -= 1;
    if (*(s16 *)(reg_a4 + 6) != 0) goto next_2;
    *(u16 *)reg_a4 = 0;
next_2:;
}
