#include "common.h"

typedef void (*Fn)();

extern s8 D_0028E408;

s32 func_001256C0();
s32 func_001257B0();
s32 func_001257E0();
s32 func_00125860();
s32 func_00127CA0();
s32 func_0018D950();
s32 func_001A9130();
extern u8 D_0028E855;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001265B0(void) {
    u32 t;

    if ((s16)(D_0028E855) < 0) goto next_2;
    t = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t;
    if (!(t & 0xFFFF)) goto next_1;
    reg_d0.w = 2;
    func_00125860();
    reg_tmp.w = 0x10008;
    *(u16 *)(reg_a6 + 0x10) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = reg_tmp.h[0];
    reg_d0.w = 0x1000;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 1);
    func_001A9130();
    func_0018D950();
    *(u8 *)reg_a6 = 0x84;
    func_00127CA0();
    return;
next_2:
    func_001257E0();
    return;
next_1:
    func_001257B0();
    func_001256C0();
    if (D_0028E408 != 0) goto next_2;
    *(u8 *)(reg_a6 + 0x19) -= 1;
    if ((s8) *(u8 *)(reg_a6 + 0x19) < 0) {
        *(u8 *)(reg_a6 + 0x19) = *(u8 *)(reg_a6 + 0x18);
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
        if (reg_tmp.w == 0xC2F) {
            reg_tmp.w = 0xC1F;
            *(u16 *)reg_a0 = reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
            *(u8 *)(reg_a6 + 0x19) = 2;
        }
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
}
