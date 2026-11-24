#include "common.h"

s32 func_0016A8B0();
s32 func_0016A8C0();
s32 func_00207F40();
s32 func_00209200();
s32 func_002092F0();
s32 func_002093F0();
extern u8 D_00267D40[];
extern u8 D_0028DA60;
extern u8 D_0028DA68;
extern u8 D_0028DA70;
extern u8 D_0028DA78;
extern u8 D_0028DA80;
extern u8 D_0028DA88;
extern u8 D_0028DA90;
extern u8 D_0028E228;
extern u8 *reg_a0;

void func_00207FF0(void) {
    u8 *temp_a1;
    u8 *temp_a1_2;
    u32 temp_a0_3;
    u8 temp_a0;
    u8 temp_a0_2;

    func_00207F40();
    reg_a0 = &D_0028E228;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    if (!(reg_d0.w & 0x20)) {
        reg_d0.h[0] = 2;
        reg_a0 = &D_0028DA60;
        func_00209200();
    }
    reg_a0 = &D_0028E228;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    if (!(reg_d0.w & 0x10)) {
        reg_d0.h[0] = 2;
        reg_a0 = &D_0028DA68;
        func_00209200();
    }
    reg_a0 = &D_0028E228;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    if (!(reg_d0.w & 1)) {
        reg_d0.h[0] = 2;
        reg_a0 = &D_0028DA70;
        func_00209200();
    }
    reg_a0 = &D_0028E228;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    if (!(reg_d0.w & 2)) {
        reg_d0.h[0] = 2;
        reg_a0 = &D_0028DA78;
        func_00209200();
    }
    func_0016A8B0();
    if (reg_d0.w & 0x8000) {
        reg_d0.h[0] = 2;
        reg_a0 = &D_0028DA80;
        func_00209200();
    }
    func_0016A8C0();
    if (reg_d0.w & 0x8000) {
        reg_d0.h[0] = 2;
        reg_a0 = &D_0028DA88;
        func_00209200();
    }
    func_0016A8B0();
    reg_d0.h[0] &= 0xF;
    if (reg_d0.b[0] != 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)D_00267D40;
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d0.w = 0;
        temp_a1 = (u8 *)(reg_a0);
        reg_d0.b[0] = (*(u8 *)((u8 *)(temp_a1) + (1)));
        reg_d0.b[0] += 0xD;
        temp_a0 = (*(u8 *)((u8 *)(temp_a1) + (0)));
        reg_d2.h[0] = 2;
        reg_d1.b[0] = temp_a0;
        reg_a0 = &D_0028DA90;
        reg_d1.b[0] += 0x1E;
        func_002092F0();
    }
    func_0016A8C0();
    reg_d0.h[0] &= 0xF;
    if (reg_d0.b[0] != 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)D_00267D40;
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d0.w = 0;
        temp_a1_2 = (u8 *)(reg_a0);
        reg_d0.b[0] = (*(u8 *)((u8 *)(temp_a1_2) + (1)));
        reg_d0.b[0] += 0x15;
        temp_a0_2 = (*(u8 *)((u8 *)(temp_a1_2) + (0)));
        reg_d1.b[0] = temp_a0_2;
        reg_d2.h[0] = 2;
        reg_a0 = &D_0028DA90;
        reg_d1.b[0] += 0x1E;
        func_002092F0();
    }
    func_0016A8B0();
    reg_d0.h[0] &= 0x70;
    reg_d0.h[0] >>= 4;
    if (reg_d0.b[0] != 0) {
        reg_d7.b[0] = reg_d0.b[0];
        reg_d2.h[0] = 2;
        reg_a0 = &D_0028DA90;
        reg_d0.w = 0xD;
        reg_d1.w = 0x18;
        if (reg_d7.w & 1) {
            func_002092F0();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 2) {
            func_002092F0();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 4) {
            func_002092F0();
        }
    }
    func_0016A8C0();
    reg_d0.h[0] &= 0x70;
    reg_d0.h[0] >>= 4;
    if (reg_d0.b[0] != 0) {
        reg_d7.b[0] = reg_d0.b[0];
        reg_d2.h[0] = 2;
        reg_a0 = &D_0028DA90;
        reg_d0.w = 0x15;
        reg_d1.w = 0x18;
        if (reg_d7.w & 1) {
            func_002092F0();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 2) {
            func_002092F0();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 4) {
            func_002092F0();
        }
    }
    func_0016A8B0();
    temp_a0_3 = reg_d0.w;
    if ((temp_a0_3 & 0x8000) && (temp_a0_3 & 0x10)) {
        reg_d0.w = 0;
        func_002093F0();
    }
    reg_d0.w = 0;
}
