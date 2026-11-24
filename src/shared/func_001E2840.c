#include "common.h"

s32 func_00129370();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0018D580();
s32 func_0019BF40();
s32 func_001A9000();
s32 func_001A91A0();
extern u8 D_00263DB0[];
extern u16 D_0028E46C;
extern Reg32 D_0028E484;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern u16 D_0028E8D4;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E2840(void) {
    u8 *var_a0;
    u32 temp_a3;
    u32 temp_a3_2;
    u32 temp_a3_3;
    u32 temp_a3_4;
    u8 temp_a0_2;
    u8 temp_a0_4;
    u8 temp_v0;
    u8 temp_v0_2;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x5800;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1C00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += D_0028E484.w;
        reg_d0.h[0] += 0x5800;
        if (reg_tmp.h[1] != 0) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
                func_0014E290();
                return;
            }
            goto block_5;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_5:
        var_a0 = (u8 *)(reg_a6);
        if ((*(s8 *)((u8 *)(var_a0) + (0))) >= 0) {
            reg_d1.w = 0x5C;
            reg_d1.b[0] &= (*(u8 *)((u8 *)(var_a0) + (1)));
            if (reg_d1.b[0] == 0) {
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
                if (((s32) (*(u16 *)((u8 *)(var_a0) + (0x18))) < 0x580) && (D_0028E8B8 == 0)) {
                    reg_d0.w = 0x19;
                }
                goto block_13;
            }
            (*(u8 *)((u8 *)(var_a0) + (1))) &= 0xA3;
            func_001A9000();
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
            if (reg_d0.b[0] == 0x19) {
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
            }
            reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
            reg_d0.b[0] ^= reg_d2.b[0];
            if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x18))) >= 0) {
block_13:
                (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
                if ((D_0028E8A0 == 0) && ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x1000)) {
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
                            (*(u16 *)((u8 *)(reg_a5) + (0x20))) += 4;
                            if ((*(u16 *)((u8 *)(reg_a5) + (0x20))) == 0x58) {
                                (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 2U;
                            }
                            goto block_45;
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
                        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x16)));
                            reg_d7.h[0] = 0xF300;
                            D_0028E46C = reg_d7.h[0];
                            reg_d7.h[0] = reg_d7.h[1];
                            reg_d7.h[1] = D_0028E46C;
                            reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
                            if (!((u8) (*(s8 *)((u8 *)(reg_a6) + (0))) & 0x40)) {
                                reg_d7.h[0] = 0xF100;
                                D_0028E46C = reg_d7.h[0];
                                reg_d7.h[0] = reg_d7.h[1];
                                reg_d7.h[1] = D_0028E46C;
                                reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
                            }
                            temp_a3 = reg_d7.h[0];
                            temp_a3_2 = reg_d1.h[0] + temp_a3;
                            reg_d1.h[0] = temp_a3_2;
                            D_0028E46C = temp_a3;
                            reg_d7.h[0] = reg_d7.h[1];
                            reg_d7.h[1] = D_0028E46C;
                            D_0028E46C = reg_d7.h[0];
                            reg_d0.h[0] += reg_d7.h[0];
                            reg_d7.h[0] = reg_d7.h[1];
                            reg_d7.h[1] = D_0028E46C;
                            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x31)));
                            reg_d0.b[0] = (s8) reg_d0.b[0] * 8;
                            if ((u8) (*(s8 *)((u8 *)(reg_a6) + (0))) & 0x20) {
                                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x33)));
                                reg_d0.b[0] += reg_d0.b[0];
                                reg_d0.b[0] += 0x10;
                            }
                            reg_d1.h[0] = 0x40;
                            if ((*(u8 *)((u8 *)(reg_a6) + (0x1D))) == 0x40) {
                                reg_d1.h[0] = 0xC0;
                                reg_d0.b[0] *= -1;
                            }
                            temp_a0_2 = (u8) (*(s8 *)((u8 *)(reg_a6) + (0)));
                            if (temp_a0_2 & 0x40) {
                                (*(s8 *)((u8 *)(reg_a6) + (0))) = (s8) (temp_a0_2 & 0xBF);
                            } else {
                                (*(s8 *)((u8 *)(reg_a6) + (0))) = (s8) (temp_a0_2 | 0x40);
                                reg_d0.b[0] *= -1;
                            }
                            reg_d1.b[0] += reg_d0.b[0];
                            reg_d0.w = 0x40005;
                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d3.w = reg_d7.w;
                            reg_d4.w = 0;
                            func_00129370();
                            if ((u8) (*(s8 *)((u8 *)(reg_a6) + (0))) & 0x20) {
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x33)));
                                (*(u8 *)((u8 *)(reg_a5) + (0x33))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a5) + (0x33))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x32)));
                                    (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xDF;
                                    (*(u8 *)((u8 *)(reg_a5) + (0x31))) = 0U;
                                    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = 0x10U;
                                    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 3U;
                                }
                            } else {
                                temp_v0 = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                                if (temp_v0 != 0) {
                                    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (temp_v0 - 1);
                                } else {
                                    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
                                    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = 4U;
                                    (*(u8 *)((u8 *)(reg_a5) + (0x31))) += 1;
                                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x31)));
                                    if ((*(u8 *)((u8 *)(reg_a5) + (0x30))) == reg_d0.b[0]) {
                                        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = 0x10U;
                                        (*(u8 *)((u8 *)(reg_a6) + (0))) |= 0x20;
                                    }
                                }
                            }
                        }
                    } else {
                        temp_v0_2 = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
                        if (temp_v0_2 != 0) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (temp_v0_2 - 1);
                        } else {
                            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                            (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                                (*(u16 *)((u8 *)(reg_a5) + (0x20))) -= 4;
                                if ((*(u16 *)((u8 *)(reg_a5) + (0x20))) == 0x38) {
                                    reg_d0.h[0] = 0x40;
                                    reg_d0.h[0] -= D_0028E8D4;
                                    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) reg_d0.b[0];
                                    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 0U;
                                }
block_45:
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
                                reg_a0 = (u8 *)D_00263DB0;
                                reg_a0 += reg_d0.h[0];
                                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0)));
                                reg_a0 += 2;
                                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0)));
                                reg_a0 += 2;
                            }
                        }
                    }
                }
block_objset:
                func_0019BF40();
                reg_a0 = reg_a6;
                func_0014D220();
                return;
            }
            func_0018D580();
            reg_d0.w = 0x46;
            func_001A91A0();
            (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8080;
            temp_a0_4 = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = temp_a0_4;
            reg_d0.h[0] = 0xD;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a3_3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a3_3;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xEC00;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
            reg_d0.h[0] = 0xD;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a3_4 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a3_4;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFC00;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
            reg_d0.h[0] = 0x85;
            func_0013A780();
            var_a0 = (u8 *)1;
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0xC00;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
            goto block_48;
        }
block_48:
        (*(u16 *)((u8 *)(reg_a5) + (0x2E))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x2E))) >= 0) {
            goto block_objset;
        }
        func_0014E290();
    }
}
