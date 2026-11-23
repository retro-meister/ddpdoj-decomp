#include "common.h"

extern s8 D_0028E408;

s32 func_0014E030();
s32 func_001D6690();
s32 func_001D66A0();
s32 func_001D66B0();
s32 func_002010A0();
s32 func_00202730();
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D61B0(s32 arg1, s32 arg2) {
    s32 var_a1;
    s32 var_a2;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;

    var_a1 = arg1;
    var_a2 = arg2;
    if ((*(u8 *)((u8 *)(reg_a6) + (0xC7))) == 0) {
        var_a2 = 0x1010;
        (*(u8 *)((u8 *)(reg_a6) + (0xC7))) = 1U;
        var_a1 = 0x505;
        (*(s16 *)((u8 *)(reg_a6) + (0xCA))) = 0x1010;
        (*(s16 *)((u8 *)(reg_a6) + (0xCC))) = 0x505;
        (*(u16 *)((u8 *)(reg_a6) + (0xDA))) = 0x60U;
    }
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2E))) != 0) {
        temp_a0 = (*(u8 *)((u8 *)(reg_a6) + (0xC7)));
        if (temp_a0 == 1) {
            func_001D66B0();
            if (D_0028E408 == 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0xDA))) -= 1;
                if ((*(u16 *)((u8 *)(reg_a6) + (0xDA))) == 0) {
                    func_001D6690();
                    (*(u8 *)((u8 *)(reg_a6) + (0xC7))) = 2U;
                }
            }
        }
        temp_a0_2 = (*(u8 *)((u8 *)(reg_a6) + (0xC7)));
        if (temp_a0_2 == 2) {
            func_001D66B0();
            if ((D_0028E408 == 0) && ((*(u8 *)((u8 *)(reg_a5) + (0x25))) == 0)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xCB)));
                (*(u8 *)((u8 *)(reg_a6) + (0xCB))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a6) + (0xCB))) = (*(u8 *)((u8 *)(reg_a6) + (0xCA)));
                    reg_d1.h[0] = 0x80;
                    func_00202730();
                    reg_d7.b[0] = reg_d1.b[0];
                    reg_d0.w = 0x13;
                    func_0014E030();
                    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
                    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
                    (*(u16 *)((u8 *)(reg_a0) + (0x16))) -= 0x800;
                    (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0;
                    func_002010A0();
                    reg_d0.b[0] += reg_d7.b[0];
                    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
                    (*(u8 *)((u8 *)(reg_a6) + (0xCD))) -= 1;
                    if ((*(u8 *)((u8 *)(reg_a6) + (0xCD))) == 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (0xC7))) = 3U;
                        (*(u16 *)((u8 *)(reg_a6) + (0xDA))) = 0x40U;
                    }
                }
            }
        }
    }
    temp_a0_3 = (*(u8 *)((u8 *)(reg_a6) + (0xC7)));
    if (temp_a0_3 == 3) {
        (*(u16 *)((u8 *)(reg_a6) + (0xDA))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a6) + (0xDA))) == 0) {
            func_001D66A0();
            (*(u16 *)((u8 *)(reg_a6) + (0xDA))) = 0x60U;
            (*(u8 *)((u8 *)(reg_a6) + (0xC7))) = 1U;
            (*(u8 *)((u8 *)(reg_a6) + (0xCD))) = (*(u8 *)((u8 *)(reg_a6) + (0xCC)));
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
            reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
            if (reg_d0.b[0] != 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0xCD))) = 0xAU;
            }
        }
    }
}
