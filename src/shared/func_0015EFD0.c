#include "common.h"

extern s8 D_0028E408;

s32 func_0014E290();
s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_00202140();
extern u8 D_00259170_as_u8_a[];
extern s8 D_0025A1F8[];
extern s8 D_0025A210[];
extern s8 D_0025A230[];
extern u16 D_0028E888;
extern u16 D_0028E88C;
extern u16 D_0028E890;
extern u16 D_0028E894;
extern u16 D_0028E8D0;
extern u16 D_0028E8D8;
extern u16 D_0028E8DC;
extern u16 D_0028E910;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern s8 *reg_a0_as_s8_p;
extern u8 *reg_a2;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015EFD0(void) {
    s8 *temp_a1;

    if ((D_0028E91C == 0) && (D_0028E894 != 0)) {
        func_0014E290();
        return;
    }
    reg_a0_as_s8_p = D_0025A230;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0_as_s8_p;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0_as_s8_p = D_0025A210;
    reg_d0.w = 0xD;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a2 = D_00259170_as_u8_a;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0x240;
        func_00202140();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x2C))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        reg_a2 += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (0x28))) = (u16) (*(u16 *)((u8 *)(reg_a2) + (0)));
        (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = (u16) (*(u16 *)((u8 *)(reg_a2) + (2)));
        reg_d0.b[0] = 4;
        reg_d1.b[0] = 5;
        if ((s32) D_0028E91C > 1) {
            reg_d0.b[0] = 4;
            reg_d1.b[0] = 5;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x2F))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x2E))) = (u8) reg_d1.b[0];
        reg_d0.h[0] = D_0028E8D0;
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= reg_d0.b[0];
        reg_d0.h[0] = D_0028E8D8;
        (*(u8 *)((u8 *)(reg_a5) + (0x1E))) -= reg_d0.b[0];
        reg_d0.h[0] = D_0028E8D0;
        (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= reg_d0.b[0];
        if (D_0028E910 != 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 0x10;
        }
        reg_d0.h[0] = D_0028E8DC;
        (*(u8 *)((u8 *)(reg_a5) + (0x22))) -= reg_d0.b[0];
        reg_a0_as_s8_p = D_0025A1F8;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        (*(s8 *)((u8 *)(reg_a5) + (0x1D))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        temp_a1 = (s8 *)(reg_a0_as_s8_p + 1);
        reg_a0_as_s8_p = temp_a1;
        if (D_0028E91C == 4) {
            if (D_0028E890 != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E88C != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E888 != 0) {
                func_0014E290();
            }
        }
    }
}
