#include "common.h"

s32 func_0019C570();
s32 func_0019CA40();
s32 func_001A3020();
s32 func_001B0470();
extern u8 D_00251C20[];
extern u8 D_00251D70[];
extern u8 D_00251DF0[];
extern u8 D_00260F70[];
extern u16 D_0028E3E0;
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_001B0950(void) {
    u8 flag;

    if (*(u16 *)(reg_a6 + 2) != 0) {
        *(u16 *)(reg_a6 + 2) -= 1;
        return;
    }
    flag = *(u8 *)(reg_a6 + 1);
    if (!(flag & 2)) {
        *(u8 *)(reg_a6 + 1) = flag | 2;
        reg_a0 = (u8 *)D_00260F70;
        reg_d0.w = 0x16;
        func_001A3020();
        reg_tmp.h[1] = (*(u16 *)(reg_a6 + (0x1C)));
        reg_tmp.h[0] = (*(u16 *)(reg_a6 + (0x1E)));
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.h[0] = (*(u16 *)(reg_a6 + (0xE)));
        func_001A3020();
    }
    reg_d1.h[1] = (*(u16 *)(reg_a6 + (4)));
    reg_d1.h[0] = (*(u16 *)(reg_a6 + (6)));
    reg_d1.w += 0xF400E400;
    reg_d0.h[0] = (*(u16 *)(reg_a6 + (0xA)));
    reg_a0 = (u8 *)D_00251C20;
    reg_a0 += reg_d0.h[0];
    reg_d2.h[1] = (*(u16 *)(reg_a0 + (0)));
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = 0xCE0;
    reg_d4.h[0] = 0x16;
    func_0019C570();
    if (*(u16 *)(reg_a6 + 0xC) != 0) {
        *(u16 *)(reg_a6 + 0xC) -= 1;
        reg_tmp.h[1] = (*(u16 *)(reg_a6 + (0x20)));
        reg_tmp.h[0] = (*(u16 *)(reg_a6 + (0x22)));
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.h[0] = (*(u16 *)(reg_a6 + (0x12)));
        reg_a0 += reg_d0.h[0];
        reg_d2.h[1] = (*(u16 *)(reg_a0 + (0)));
        reg_a0 += 2;
        reg_d2.h[0] = (*(u16 *)(reg_a0 + (0)));
        reg_a0 += 2;
        reg_d1.h[1] = (*(u16 *)(reg_a6 + (4)));
        reg_d1.h[0] = (*(u16 *)(reg_a6 + (6)));
        reg_d1.w += 0xF600F800;
        reg_d3.h[0] = 0xA40;
        reg_d1.h[0] += 0x7FFF + 0x6E01;
        reg_d4.h[0] = (*(u16 *)(reg_a6 + (0xE)));
        reg_d6.w = 0x80008000;
        func_0019CA40();
        if (D_0028E3E0 != 0) {
            reg_a1 = (u8 *)D_00251DF0;
            reg_d0.h[0] = 0x1E;
            reg_d6.w = 0x80005000;
            reg_d0.h[0] &= D_0028E3F0;
            reg_d0.h[0] += reg_d0.h[0];
            reg_a1 += reg_d0.h[0];
        }
        func_0019CA40();
        reg_d2.h[1] = (*(u16 *)(reg_a0 + (0)));
        reg_a0 += 2;
        reg_d2.h[0] = (*(u16 *)(reg_a0 + (0)));
        reg_a0 += 2;
        if (*(u16 *)(reg_a6 + 0x14) == 0x280) goto skip_1;
        *(u16 *)(reg_a6 + 0x14) += 8;
        goto skip_4;
skip_1:
        if (*(u16 *)(reg_a6 + 0x16) == 0x280) goto skip_2;
        *(u16 *)(reg_a6 + 0x16) += 8;
        goto skip_4;
skip_2:
        if (*(u16 *)(reg_a6 + 0x18) == 0x280) goto skip_3;
        *(u16 *)(reg_a6 + 0x18) += 8;
        goto skip_4;
skip_3:
        if (*(u16 *)(reg_a6 + 0x1A) == 0x280) goto skip_4;
        *(u16 *)(reg_a6 + 0x1A) += 8;
skip_4:
        if (D_0028E3EC != 0) {
            reg_a0 = (u8 *)D_00251D70;
            reg_d0.h[0] = 0x1E;
            reg_d0.h[0] &= D_0028E3F0;
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 += reg_d0.h[0];
            reg_d6.h[1] = (*(u16 *)(reg_a0 + (0)));
            reg_d6.h[0] = (*(u16 *)(reg_a0 + (2)));
            reg_d1.h[1] = (*(u16 *)(reg_a6 + (4)));
            reg_d1.h[0] = (*(u16 *)(reg_a6 + (6)));
            reg_d1.w += 0xFE00F000;
            reg_d1.h[0] += 0x900;
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d1.h[0] += 0x600;
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d3.h[0] = (*(u16 *)(reg_a6 + (0x14)));
            reg_d4.h[0] = (*(u16 *)(reg_a6 + (0xE)));
            func_001B0470();
            reg_d3.h[0] = (*(u16 *)(reg_a6 + (0x16)));
            if (reg_d3.h[0] != 0x200) {
                reg_d1.w += 0xFC000000;
                reg_d2.w += 1;
                func_001B0470();
            }
            reg_d3.h[0] = (*(u16 *)(reg_a6 + (0x18)));
            if (reg_d3.h[0] != 0x200) {
                reg_d1.w += 0xFC000000;
                reg_d2.w += 1;
                func_001B0470();
            }
            reg_d3.h[0] = (*(u16 *)(reg_a6 + (0x1A)));
            if (reg_d3.h[0] != 0x200) {
                reg_d1.w += 0xFC000000;
                reg_d2.w += 1;
                func_001B0470();
            }
        }
        reg_tmp.b[0] = (*(u8 *)(reg_a6 + (0x11)));
        (*(u8 *)(reg_a6 + (0x11))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)(reg_a6 + (0x11))) = (u8) (*(u8 *)(reg_a6 + (0x10)));
            (*(u16 *)(reg_a6 + (0x12))) += 8;
            if ((*(u16 *)(reg_a6 + (0x12))) == 0x28) {
                (*(u16 *)(reg_a6 + (0x12))) = 0U;
            }
        }
    } else {
        reg_tmp.b[0] = (*(u8 *)(reg_a6 + (9)));
        (*(u8 *)(reg_a6 + (9))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)(reg_a6 + (9))) = (u8) (*(u8 *)(reg_a6 + (8)));
            (*(u16 *)(reg_a6 + (0xA))) += 4;
            if (*(u16 *)(reg_a6 + 0xA) != 0x5C) goto skip_5;
            *(u16 *)(reg_a6 + 0xC) = 0x90;
            return;
skip_5:
            if (*(u16 *)(reg_a6 + 0xA) != 0x9C) return;
            *(u8 *)(reg_a6 + 1) |= 4;
        }
    }
}
