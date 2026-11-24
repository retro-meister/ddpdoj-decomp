#include "common.h"

extern s8 D_0028E408;

s32 func_00125EB0();
s32 func_00129370();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0016D290();
s32 func_00170A60();
s32 func_00170D00();
s32 func_00170DE0();
s32 func_0018D560();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002027A0();
extern u16 D_00262D80[];
extern s16 *D_0028E44C;
extern u16 D_0028E46C;
extern Reg32 D_0028E484;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern u16 D_0028E8D4;
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C6640(void) {
    s16 *temp_v1;
    u16 temp_a0_3;
    u8 temp_v0;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x7C00;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0xA00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += D_0028E484.w;
        reg_d0.h[0] += 0x7C00;
        if (reg_tmp.h[1] != 0) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
                func_0014E290();
                return;
            }
            goto block_5;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_5:
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
            if (((s32) (*(u16 *)((u8 *)(reg_a6) + (0x18))) < 0x180) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_12;
        }
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xA3;
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
        }
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x18))) >= 0) {
block_12:
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0) && ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x2C00)) {
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
                if (reg_d0.h[0] == 0) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = 0x10U;
                        (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 1U;
                    }
                } else if ((reg_d0.h[0] & 0xFFFF) == 1) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                        (*(u16 *)((u8 *)(reg_a5) + (0x20))) += 8;
                        if ((*(u16 *)((u8 *)(reg_a5) + (0x20))) == 0x78) {
                            (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 2U;
                        }
                        goto block_38;
                    }
                } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x16)));
                        func_0016D290();
                        if (D_0028E408 == 0) {
                            reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                            reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                            if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
                                D_0028E44C = (s16 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(D_0028E44C);
                            }
                            temp_v1 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                                if (*(s16 *)reg_a1 < 0) {
                                    reg_a0 = (u8 *)(reg_a1);
                                    D_0028E44C = (s16 *)(temp_v1);
                                    reg_a1 = (u8 *)(temp_v1);
                                    goto block_30;
                                }
                            } else {
block_30:
                                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                                reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                reg_d7.h[0] = 0x300;
                                D_0028E46C = reg_d7.h[0];
                                reg_d0.h[0] += reg_d7.h[0];
                                reg_d7.h[0] = reg_d7.h[1];
                                reg_d7.h[1] = D_0028E46C;
                                reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
                                reg_d1.h[0] += reg_d7.h[0];
                                func_002027A0();
                                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                temp_a0_3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                reg_d2.h[0] = temp_a0_3;
                                reg_d3.w = reg_d7.w;
                                reg_d4.w = (u32) reg_a6;
                                reg_d0.w = 0x1000C;
                                func_00129370();
                            }
                            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                            (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
                                (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = 0x10U;
                                (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 3U;
                            }
                        }
                    }
                } else {
                    temp_v0 = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
                    if (temp_v0 != 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (temp_v0 - 1);
                    } else {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                        (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                            (*(u16 *)((u8 *)(reg_a5) + (0x20))) -= 8;
                            if ((*(u16 *)((u8 *)(reg_a5) + (0x20))) == 0) {
                                reg_d0.h[0] = 0x40;
                                reg_d0.h[0] -= D_0028E8D4;
                                (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) reg_d0.b[0];
                                (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 0U;
                            }
block_38:
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
                            reg_a0 = (u8 *)(D_00262D80);
                            reg_a0 += reg_d0.h[0];
                            (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (*(u16 *)((u8 *)(reg_a0) + (0)));
                            reg_a0 += 2;
                            (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (*(u16 *)((u8 *)(reg_a0) + (0)));
                            reg_a0 += 2;
                            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
                            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
                            reg_a1 = (u8 *) reg_tmp.w;
                            *(s16 *)reg_a1 = (s16) (*(u16 *)((u8 *)(reg_a0) + (0)));
                            reg_a0 += 2;
                        }
                    }
                }
            }
            func_00170A60();
            reg_a0 = (u8 *)(reg_a6);
            func_0014D220();
            return;
        }
        func_0018D560();
        reg_d0.w = 0x34;
        func_001A91A0();
        reg_d0.w = 8;
        func_00170DE0();
        func_00125EB0();
        reg_d0.w = 0xC;
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
        func_00170D00();
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
        (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFD00;
        (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
        func_0014E290();
    }
}
