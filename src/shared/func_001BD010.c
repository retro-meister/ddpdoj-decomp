#include "common.h"

s32 func_001293C0();
s32 func_00129410();
s32 func_001368E0();
s32 func_001389D0();
s32 func_0013A780();
s32 func_0013B2E0();
s32 func_0014D220();
s32 func_0014E030();
s32 func_0014E290();
s32 func_0018D4E0();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001BC4B0();
s32 func_001BC5D0();
s32 func_001BC6F0();
s32 func_001BCA10();
s32 func_001BDD40();
s32 func_001BDEE0();
s32 func_001BDFC0();
s32 func_00201800();
s32 func_00201B80();
s32 func_002026F0();
s32 func_00217BB0();
s32 func_00217C20();
extern u8 D_00259970[];
extern u8 D_00262B50[];
extern u8 D_0028E310;
extern s8 D_0028E408;
extern u16 D_0028E890;
extern u16 D_0028E894;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001BD010(void) {
    u16 temp_v1;
    u8 temp_a0;
    u32 temp_a0_2;
    u8 temp_a1;
    u8 temp_v0_2;
    u8 temp_v0_5;
    u8 *var_a0;

    if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) != 0) {
        func_00201B80();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
        func_00201800();
        (*(u8 *)((u8 *)(reg_a5) + (0x16))) -= 1;
        temp_a0 = (*(u8 *)((u8 *)(reg_a5) + (0x16)));
        if (temp_a0 != 0) {
            if (temp_a0 >= 0x48) goto block_tail;
            if (temp_a0 == 48) {
            D_0028E894 = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            func_001389D0();
                return;
            }
        } else {
            func_0014E290();
        }
        return;
    } else {
        if (D_0028E8A8 == 0xD8) {
            (*(u8 *)((u8 *)(reg_a5) + (0x20))) = 1U;
        }
        if (D_0028E8A8 == 0xF8) {
            (*(u8 *)((u8 *)(reg_a5) + (0x20))) = 0xFFU;
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
            func_001A9000();
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
            reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1E)));
            reg_d0.b[0] ^= reg_d2.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            if ((*(u8 *)((u8 *)(reg_a5) + (0x20))) == 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x18))) = 0x3500U;
            }
            if ((*(u16 *)((u8 *)(reg_a6) + (8))) == 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x26)));
                if ((s8) (*(u8 *)((u8 *)(reg_a5) + (0x20))) < 0) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x18))) = 0x7FFFU;
                }
                goto block_18;
            }
            if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
                D_0028E890 = 1;
                reg_d0.w = 0x1C;
                func_0014E030();
                (*(u16 *)((u8 *)(reg_a5) + (0x28))) = (u16) reg_d1.h[0];
                reg_d0.w = 0x353;
                func_001A91A0();
                func_001BC6F0();
                func_00217BB0(0xB4, 0x50);
                func_00217C20(0xB4, 0x50);
                D_0028E310 = MAIN_OR_DEATH_LABEL(0x54, 0x5A);
                reg_a0 = D_00262B50;
                func_0013B2E0();
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
                func_00201800();
                (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8080;
                goto block_18;
            }
        } else {
block_18:
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1F)));
        }
        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x18)));
        reg_d7.w = 7;
        reg_a4 = reg_a6 + 0x20;
        do {
            var_a0 = (u8 *)(reg_a4);
            reg_d0.h[0] = (*(u16 *)((u8 *)(var_a0) + (0)));
            if (reg_d0.h[0] != 0x8000) {
                if ((*(u8 *)((u8 *)(var_a0) + (8))) == 0) {
                    reg_d1.w = 0x5C;
                    reg_d1.b[0] &= (*(u8 *)((u8 *)(var_a0) + (1)));
                    if (reg_d1.b[0] != 0) {
                        reg_d0.b[0] = 0xA3;
                        (*(u8 *)((u8 *)(var_a0) + (1))) &= reg_d0.b[0];
                        func_001A9000();
                        var_a0 = (u8 *)(reg_a4);
                        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
                        reg_d2.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1E)));
                        reg_d0.b[0] ^= reg_d2.b[0];
                        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) reg_d0.b[0];
                        if ((*(u8 *)((u8 *)(reg_a5) + (0x20))) == 0) {
                            (*(s16 *)((u8 *)(reg_a4) + (0x18))) = 0x400;
                        }
                        if ((*(s16 *)((u8 *)(reg_a4) + (0x18))) < 0) {
                            reg_d0.w = 0x26;
                            func_001A91A0();
block_27:
                            func_0018D4E0();
                            reg_d0.h[0] = 0x85;
                            func_0013A780();
                            var_a0 = (u8 *)((void *)1);
                            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (2)));
                            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (4)));
                            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 2;
                            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
                            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
                            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
                            (*(u16 *)((u8 *)(reg_a4) + (0))) = 0x8000U;
                        }
                    } else {
                        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) (*(u8 *)((u8 *)(var_a0) + (0x1F)));
                    }
                } else {
                    goto block_27;
                }
            }
            reg_a4 += 0x40;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) == 0) {
            if ((*(s16 *)((u8 *)(reg_a6) + (2))) >= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
            }
            goto block_35;
        }
        if ((*(s16 *)((u8 *)(reg_a6) + (2))) < -0x23FF) {
            D_0028E894 = 0;
            func_0014E290();
            return;
        }
block_35:
        func_001368E0();
        if (D_0028E8A0 == 0) {
            func_00201B80();
            func_001BCA10();
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
            (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                (*(u16 *)((u8 *)(reg_a5) + (0x24))) += 4;
                if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x24))) >= 0x14) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = 0U;
                }
            }
            temp_v0_2 = (*(u8 *)((u8 *)(reg_a6) + (0xD)));
            if (temp_v0_2 == 0) {
                if ((s8) (*(u8 *)((u8 *)(reg_a5) + (0x20))) > 0) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (7)));
                    (*(u8 *)((u8 *)(reg_a6) + (7))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (6)));
                        (*(u8 *)((u8 *)(reg_a6) + (0xD))) = 1U;
                        (*(s16 *)((u8 *)(reg_a6) + (0xA))) = 2;
#ifndef DEATH_LABEL
                        (*(u8 *)((u8 *)(reg_a6) + (0xB))) = 0U;
                        (*(u8 *)((u8 *)(reg_a6) + (0xA))) = 2;
#endif
                    }
                }
            } else if ((temp_v0_2 & 0xFF) == 1) {
                if (((*(u16 *)((u8 *)(reg_a6) + (8))) != 0) || ((*(u8 *)((u8 *)(reg_a5) + (0x1F))) == 0)) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xB)));
                    (*(u8 *)((u8 *)(reg_a6) + (0xB))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (0xB))) = (*(u8 *)((u8 *)(reg_a6) + (0xA)));
                        (*(u16 *)((u8 *)(reg_a6) + (8))) += 4;
                        if ((*(u16 *)((u8 *)(reg_a6) + (8))) == 0x7C) {
                            (*(u8 *)((u8 *)(reg_a6) + (0xD))) = 2U;
                            (*(u8 *)((u8 *)(reg_a6) + (0xC))) = 2U;
                            (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 2;
                        }
                        goto block_50;
                    }
                }
            } else {
block_50:
                if ((*(u8 *)((u8 *)(reg_a6) + (0xD))) == 2) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xF)));
                    (*(u8 *)((u8 *)(reg_a6) + (0xF))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (0xF))) = (*(u8 *)((u8 *)(reg_a6) + (0xE)));
                        temp_v1 = (*(u16 *)((u8 *)(reg_a6) + (2)));
                        if ((s32) temp_v1 >= 0x1000) {
                            reg_d0.h[0] = temp_v1;
                            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d0.h[0] += 0x2700;
                            func_002026F0();
                            if (D_0028E408 == 0) {
                                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                reg_d4.w = 0;
                                reg_d6.h[0] = reg_d1.h[0];
                                if ((*(u8 *)((u8 *)(reg_a6) + (0xC))) & 1) {
                                    reg_d0.w = 0x30003;
                                    reg_d1.h[0] -= 0xC;
                                    reg_d3.w = 0x27000000;
                                    reg_d7.w = 6;
                                    do {
                                        func_00129410();
                                        reg_d1.h[0] += 4;
                                    } while ((s16)(--reg_d7.h[0]) >= 0);
                                }
                                reg_d1.h[0] = reg_d6.h[0];
                                reg_a0 = D_00259970;
                                reg_d1.h[0] -= 0x56;
                                func_001BC4B0();
                                func_001BC5D0();
                                func_001BC4B0();
                                func_001BC5D0();
                                func_001BC4B0();
                                func_001BC5D0();
                                func_001BC4B0();
                                func_001BC5D0();
                                func_001BC4B0();
                                func_001BC5D0();
                                func_001BC4B0();
                            }
                        }
                        (*(u8 *)((u8 *)(reg_a6) + (0xC))) -= 1;
                        if ((*(u8 *)((u8 *)(reg_a6) + (0xC))) == 0) {
                            (*(u8 *)((u8 *)(reg_a6) + (0xD))) = 3U;
                            (*(s16 *)((u8 *)(reg_a6) + (0xA))) = 0x1001;
#ifndef DEATH_LABEL
                            (*(u8 *)((u8 *)(reg_a6) + (0xB))) = 0x10U;
                            (*(u8 *)((u8 *)(reg_a6) + (0xA))) = 1;
#endif
                            goto block_60;
                        }
                    }
                } else {
block_60:
                    if ((*(u8 *)((u8 *)(reg_a6) + (0xD))) == 3) {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xB)));
                        (*(u8 *)((u8 *)(reg_a6) + (0xB))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a6) + (0xB))) = (*(u8 *)((u8 *)(reg_a6) + (0xA)));
                            (*(u16 *)((u8 *)(reg_a6) + (8))) -= 4;
                            if ((*(u16 *)((u8 *)(reg_a6) + (8))) == 0) {
                                (*(u8 *)((u8 *)(reg_a6) + (0xD))) = 0U;
                            }
                        }
                    }
                }
            }
            if ((s8) (*(u8 *)((u8 *)(reg_a5) + (0x20))) > 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x21))) += 1;
                (*(u8 *)((u8 *)(reg_a5) + (0x21))) &= 7;
                reg_d7.w = 7;
                reg_a4 = reg_a6 + 0x20;
                do {
                    if ((*(u16 *)((u8 *)(reg_a4) + (0))) != 0x8000) {
                        temp_v0_5 = (*(u8 *)((u8 *)(reg_a4) + (9)));
                        if (temp_v0_5 == 0) {
                            if ((*(u8 *)((u8 *)(reg_a4) + (0x2B))) == 0) {
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
                                (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
                                    (*(u8 *)((u8 *)(reg_a4) + (0x2B))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x2A)));
                                    goto block_71;
                                }
                            } else {
block_71:
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x2D)));
                                (*(u8 *)((u8 *)(reg_a4) + (0x2D))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a4) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x2C)));
                                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
                                    reg_d1.h[0] = reg_d7.h[0];
                                    reg_d1.h[0] &= 3;
                                    reg_d0.h[0] &= 3;
                                    if (reg_d0.h[0] == reg_d1.h[0]) {
                                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                                        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
                                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1A)));
#ifdef DEATH_LABEL
                                        if (((reg_d1.sb[0] < -0x20) || (0 < reg_d1.sb[0])) && ((reg_d1.sb[0] > 0x20) || (0 > reg_d1.sb[0]))) {
#else
                                        if (((s32) reg_d1.b[0] < 0xE1) && ((s32) reg_d1.b[0] > 0x20)) {
#endif
                                            reg_d3.w = 0x02000000;
                                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
                                            reg_d0.w = 0xFFFE0007;
                                            func_001293C0();
                                            (*(u8 *)((u8 *)(reg_a4) + (0x2B))) -= 1;
                                        }
                                    }
                                }
                            }
                        } else if ((temp_v0_5 & 0xFF) == 1) {
                            if ((*(u16 *)((u8 *)(reg_a6) + (8))) == 0) {
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
                                (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
                                    (*(u16 *)((u8 *)(reg_a4) + (0xA))) += 4;
                                    if ((*(u16 *)((u8 *)(reg_a4) + (0xA))) == 0x1C) {
                                        (*(u8 *)((u8 *)(reg_a4) + (9))) = 2U;
                                        (*(s16 *)((u8 *)(reg_a4) + (0x26))) = 1;
                                        (*(u8 *)((u8 *)(reg_a4) + (0x29))) = 8U;
                                        goto block_81;
                                    }
                                }
                            }
                        } else {
block_81:
                            if ((*(u8 *)((u8 *)(reg_a4) + (9))) == 2) {
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x27)));
                                (*(u8 *)((u8 *)(reg_a4) + (0x27))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a4) + (0x27))) = (*(u8 *)((u8 *)(reg_a4) + (0x26)));
                                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1A)));
#ifdef DEATH_LABEL
                                    if (((reg_tmp.sb[0] < -0x18) || (0 < reg_tmp.sb[0])) && ((reg_tmp.sb[0] > 0x18) || (0 > reg_tmp.sb[0]))) {
#else
                                    if (((s32) reg_tmp.b[0] < 0xE9) && ((s32) reg_tmp.b[0] > 0x18)) {
#endif
                                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x29)));
                                        reg_d1.b[0] *= 4;
                                        temp_a0_2 = (*(u8 *)((u8 *)(reg_a4) + (0x1A)));
                                        temp_a1 = reg_d1.b[0];
                                        reg_d1.b[0] = temp_a1 + temp_a0_2;
                                        reg_d3.w = 0x02000000;
                                        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                                        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
                                        reg_d0.w = 0x20007;
                                        func_001293C0();
                                        (*(u8 *)((u8 *)(reg_a4) + (0x28))) += 2;
                                    }
                                    (*(u8 *)((u8 *)(reg_a4) + (0x29))) -= 1;
                                    if ((*(u8 *)((u8 *)(reg_a4) + (0x29))) == 0) {
                                        (*(u8 *)((u8 *)(reg_a4) + (9))) = 3U;
                                        (*(u8 *)((u8 *)(reg_a4) + (0xD))) = 0x20U;
                                        goto block_88;
                                    }
                                }
                            } else {
block_88:
                                if ((*(u8 *)((u8 *)(reg_a4) + (9))) == 3) {
                                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
                                    (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
                                        (*(u16 *)((u8 *)(reg_a4) + (0xA))) -= 4;
                                        if ((*(u16 *)((u8 *)(reg_a4) + (0xA))) == 0) {
                                            (*(u8 *)((u8 *)(reg_a4) + (9))) = 0U;
                                            (*(u8 *)((u8 *)(reg_a4) + (0xD))) = 0x10U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    reg_a4 += 0x40;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                reg_d6.w = 0;
                reg_d7.w = 7;
                reg_a4 = reg_a6 + 0x20;
                do {
                    if (((*(u16 *)((u8 *)(reg_a4) + (0))) != 0x8000) && ((*(u8 *)((u8 *)(reg_a4) + (9))) != 0)) {
                        reg_d6.w = 1;
                    }
                    reg_a4 += 0x40;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                if (reg_d6.h[0] == 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = 0U;
                }
            }
        }
block_tail:
        func_001BDFC0();
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
            func_001BDD40();
            func_001BDEE0();
        }
        reg_a0 = reg_a6;
        func_0014D220();
        reg_a0 = reg_a6 + 0x20;
        func_0014D220();
        reg_a0 = reg_a6 + 0x40;
        func_0014D220();
        reg_a0 = reg_a6 + 0x60;
        func_0014D220();
        reg_a0 = reg_a6 + 0x80;
        func_0014D220();
        reg_a0 = reg_a6 + 0xA0;
        func_0014D220();
        reg_a0 = reg_a6 + 0xC0;
        func_0014D220();
        reg_a0 = reg_a6 + 0xE0;
        func_0014D220();
        reg_a0 = reg_a6 + 0x100;
        func_0014D220();
        reg_a0 = reg_a6 + 0x120;
        func_0014D220();
        reg_a0 = reg_a6 + 0x140;
        func_0014D220();
        reg_a0 = reg_a6 + 0x160;
        func_0014D220();
        reg_a0 = reg_a6 + 0x180;
        func_0014D220();
        reg_a0 = reg_a6 + 0x1A0;
        func_0014D220();
        reg_a0 = reg_a6 + 0x1C0;
        func_0014D220();
        reg_a0 = reg_a6 + 0x1E0;
        func_0014D220();
    }
}
