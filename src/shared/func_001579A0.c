#include "common.h"

extern s8 D_0028E408;

s32 func_00128970();
s32 func_00128A20();
s32 func_00128A70();
s32 func_0013A780();
s32 func_0014E290();
s32 func_00157740();
s32 func_0018D540();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00201C60();
s32 func_00202490();
s32 func_00202F50();
s32 func_00203060();
extern u16 D_0028E8A0;
extern u16 D_0028E91C;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001579A0(void) {
    u16 temp_a0;
    u16 temp_v1;
    u8 temp_a0_2;
    u8 *var_a0;
    u8 *var_a1;

    func_00203060();
    if (D_0028E408 != 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_4:
    func_00201C60();
    temp_v1 = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
    if ((temp_v1 != 0) && (D_0028E8A0 == 0)) {
        (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = (u16) (temp_v1 - 1);
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
            func_00202490();
        }
    }
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    var_a0 = (u8 *)(reg_a6);
    reg_d1.b[0] = (*(u8 *)((u8 *)(var_a0) + (1)));
    reg_d1.b[0] |= (*(u8 *)((u8 *)(var_a0) + (0x21)));
    reg_d1.h[0] &= 0x5C;
    var_a1 = (u8 *)(var_a0 + 1);
    if (reg_d1.h[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(var_a0) + (1))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x21))) &= reg_d0.b[0];
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x18)));
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
        reg_d2.w = 0x7FFF;
        reg_d2.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x18)));
        reg_d3.w = 0x7FFF;
        reg_d3.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x38)));
        if ((s32) reg_d2.w < (s32) reg_d3.w) {
            reg_d2.w = reg_d3.w;
        }
        var_a1 = (u8 *)(reg_a5);
        reg_tmp.h[1] = (*(u16 *)((u8 *)(var_a1) + (0x24)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(var_a1) + (0x26)));
        reg_tmp.w -= reg_d2.w;
        (*(u16 *)((u8 *)(var_a1) + (0x24))) = (u16) reg_tmp.h[1];
        var_a0 = (u8 *)((void *) reg_tmp.h[0]);
        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = (u16) var_a0;
        reg_d0.h[0] = 0x7FFF;
        (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x38))) = (u16) reg_d0.h[0];
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
        if ((s32) reg_tmp.w < 0) {
            reg_d0.w = 0x19;
            func_001A91A0();
            reg_d0.h[0] = 0x82;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a0;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d0.b[0] *= 4;
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            func_0018D540();
            if ((s32) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x3200) {
                reg_d1.w = 0;
                reg_d0.w = 0x1000C;
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d3.w = 0;
                func_00128A20();
            }
            func_0014E290();
            return;
        }
        goto block_16;
    }
    (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
block_16:
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
    (*(u8 *)((u8 *)(reg_a5) + (0x21))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x20)));
        func_00202F50();
        if (D_0028E408 == 0) {
            reg_d1.w = 0;
            temp_a0_2 = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d1.b[0] = temp_a0_2;
            if (D_0028E91C != 4) {
                reg_d0.w = 0x1000C;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d3.w = 0;
                func_00128A70();
            } else {
                reg_d0.w = 0xFFFC000C;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d3.w = 0;
                func_00128A20();
                reg_d1.h[0] += 2;
                func_00128970();
                reg_d1.h[0] -= 4;
                func_00128A20();
            }
        }
    }
    func_00157740();
}
