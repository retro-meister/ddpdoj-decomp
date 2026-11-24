#include "common.h"

void func_001E4640();
void func_001E4B70(void);
void func_001E4EF0(void);
void func_001E56D0(void);

s32 func_002011A0();                            /* extern */

void func_001E4580(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x200C;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0;
    func_002011A0();
    reg_d0.h[0] &= 0xF;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_d0.h[0];
    func_002011A0();
    reg_d0.h[0] &= 0xF;
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_d0.h[0];
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0x101;
    (*(s16 *)((u8 *)(reg_a4) + (0xE))) = 0x20;
    (*(s16 *)((u8 *)(reg_a4) + (0x10))) = 0x808;
    (*(s8 *)((u8 *)(reg_a4) + (0x13))) = 2;
    (*(s8 *)((u8 *)(reg_a4) + (0x12))) = 2;
    (*(s8 *)((u8 *)(reg_a4) + (0x15))) = 2;
    (*(s8 *)((u8 *)(reg_a4) + (0x14))) = 0x10;
    func_001E4640(2, 0x808, 0x20, 0x101);
}


s32 func_00124B20();
s32 func_001251C0();
s32 func_00125250();
s32 func_001D7880();
s32 func_001D7900();
extern u8 D_0028DC80[];

void func_001E4640() {
    u16 temp_a0;
    u16 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_3;
    u8 *var_a0;

    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        reg_d7.w = 0;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC6)));
        temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (8)));
        if (temp_a0 != reg_d0.h[0]) {
            func_001D7880();
            reg_d7.w = 1;
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE6)));
        temp_a0_2 = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
        if (temp_a0_2 != reg_d0.h[0]) {
            func_001D7900();
            reg_d7.w = 1;
        }
        if (reg_d7.h[0] == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
            if (((s32) reg_tmp.b[0] <= 0) && ((*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC))), var_a0 = reg_a4 + 4, temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (4))), (temp_v1 != 6))) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) = (u8) (temp_v1 - 1);
            } else {
                (*(u16 *)((u8 *)(reg_a4) + (0xE))) -= 1;
                var_a0 = (u8 *)(reg_a4);
                if ((s16) (*(u16 *)((u8 *)(var_a0) + (0xE))) == 0) {
                    (*(u8 *)((u8 *)(var_a0) + (3))) = 2U;
                    (*(u8 *)((u8 *)(reg_a4) + (0x14))) = 0x60U;
                }
            }
            reg_a0 = D_0028DC80;
            reg_a0 += (*(u16 *)((u8 *)(reg_a4) + (6)));
            reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
            func_001251C0();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = 0U;
            (*(u16 *)((u8 *)(reg_a4) + (6))) += 2;
            (*(u16 *)((u8 *)(reg_a4) + (6))) &= 3;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 2) {
        temp_v1_2 = (*(u8 *)((u8 *)(reg_a4) + (0x14)));
        if (temp_v1_2 != 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0x14))) = (u8) (temp_v1_2 - 1);
        } else {
            reg_d0.w = 1;
            func_00125250();
            if (cond_flag == 0) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
                (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
                    reg_d0.h[0] = 1;
                    func_001251C0();
                    (*(u16 *)((u8 *)(reg_a0) + (2))) = 1U;
                }
                reg_d0.w = 2;
                func_00125250();
                if (cond_flag == 0) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x11)));
                    (*(u8 *)((u8 *)(reg_a4) + (0x11))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a4) + (0x11))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x10)));
                        (*(u8 *)((u8 *)(reg_a4) + (0x13))) -= 1;
                        if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0x13))) == 0) {
                            (*(u8 *)((u8 *)(reg_a4) + (0x13))) = 2U;
                            (*(u8 *)((u8 *)(reg_a4) + (3))) = 3U;
                            (*(u8 *)((u8 *)(reg_a4) + (0x15))) -= 1;
                            if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0x15))) == 0) {
                                (*(u8 *)((u8 *)(reg_a4) + (3))) = 4U;
                                (*(u8 *)((u8 *)(reg_a4) + (0x14))) = 0x10U;
                            }
                        } else {
                            reg_d0.h[0] = 2;
                            func_001251C0();
                            (*(u16 *)((u8 *)(reg_a0) + (2))) = 2U;
                        }
                    }
                }
            }
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 3) {
        temp_v1_3 = (*(u8 *)((u8 *)(reg_a4) + (0x14)));
        if (temp_v1_3 != 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0x14))) = (u8) (temp_v1_3 - 1);
        } else {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
            (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
                reg_d0.h[0] = 2;
                func_001251C0();
                (*(u16 *)((u8 *)(reg_a0) + (2))) = 1U;
            }
            reg_d0.w = 1;
            func_00125250();
            if (cond_flag == 0) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x11)));
                (*(u8 *)((u8 *)(reg_a4) + (0x11))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a4) + (0x11))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x10)));
                    (*(u8 *)((u8 *)(reg_a4) + (0x12))) -= 1;
                    if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0x12))) == 0) {
                        (*(u8 *)((u8 *)(reg_a4) + (0x12))) = 2U;
                        (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
                        (*(u8 *)((u8 *)(reg_a4) + (0x15))) -= 1;
                        if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0x15))) == 0) {
                            (*(u8 *)((u8 *)(reg_a4) + (3))) = 4U;
                            (*(u8 *)((u8 *)(reg_a4) + (0x14))) = 0x10U;
                        }
                    } else {
                        reg_d0.h[0] = 1;
                        func_001251C0();
                        (*(u16 *)((u8 *)(reg_a0) + (2))) = 2U;
                    }
                }
            }
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 4) {
        (*(u8 *)((u8 *)(reg_a4) + (0x14))) -= 1;
        if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0x14))) == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 5U;
            reg_d0.h[0] = 1;
            func_001251C0();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = 3U;
            reg_d0.h[0] = 2;
            func_001251C0();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = 3U;
        }
    }
    temp_a0_3 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_3 == 5) {
        reg_d0.h[0] = 1;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.h[0] = 2;
            func_00125250();
            if (cond_flag == 0) {
                (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
                reg_d0.w = 4;
                func_00124B20();
            }
        }
    }
}

typedef struct WorkRegA4 {
    u8 pad0[3];
    u8 flag3;
    s16 field4;
    s16 field6;
} WorkRegA4;

extern WorkRegA4 *reg_a4_as_WorkRegA4_p;


void func_001E4B50(void) {
    reg_a4_as_WorkRegA4_p->flag3 = 0;
    reg_a4_as_WorkRegA4_p->field4 = 0x20;
    reg_a4_as_WorkRegA4_p->field6 = 0;
    func_001E4B70();
}

s32 func_00124F50();
s32 func_00125310();
extern u8 D_0026F1E0[];

void func_001E4B70(void) {
    u16 temp_v1;
    u8 temp_a0;

    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
            (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x20U;
            reg_d0.w = 3;
            func_001251C0();
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 1) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            reg_d0.w = 1;
            func_00124F50();
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
            (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x10U;
        }
    }
    if (((*(u8 *)((u8 *)(reg_a4) + (3))) == 2) && ((temp_v1 = (*(u16 *)((u8 *)(reg_a4) + (4))), (temp_v1 == 0)) || ((*(u16 *)((u8 *)(reg_a4) + (4))) = (u16) (temp_v1 - 1), ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) == 0)))) {
        reg_d0.w = 5;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 5;
            func_001251C0();
            reg_a1 = D_0026F1E0;
            reg_a1 += (*(u16 *)((u8 *)(reg_a4) + (6)));
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (0)));
            (*(u16 *)((u8 *)(reg_a0) + (8))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (4)));
            (*(u16 *)((u8 *)(reg_a4) + (6))) += 6;
            if ((*(u16 *)((u8 *)(reg_a4) + (6))) == 0x1E) {
                (*(u8 *)((u8 *)(reg_a4) + (3))) = 3U;
            }
        }
    }
    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0 == 3) {
        reg_d0.w = 5;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 3;
            func_00125310();
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 4U;
            (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x80U;
            reg_d0.w = 2;
            func_00124F50();
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 4) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
            reg_d0.w = 3;
            func_00124B20();
        }
    }
}

s32 func_002010A0();
s32 func_00201E20();

void func_001E4D90(s32 arg0, s32 arg1) {
    u16 *p0;
    u8 *p1;

    p0 = (u16 *)(reg_a6 + arg0);
    reg_d0.h[0] = *p0;
    p1 = reg_a6;
    p1 += arg1;
    if (reg_d0.h[0] == 0) goto next_3;
    if ((s16)reg_d0.h[0] >= 0) goto next_1;
    if (*(s16 *)p1 > 0x5A00) goto block_rts;
    reg_d1.b[0] = 0;
    func_002010A0();
    reg_d0.b[0] = (s8)reg_d0.b[0] >> 1;
    reg_d0.b[0] += 4;
    goto next_5;
next_1:
    if (*(s16 *)p1 < 0x6400) goto block_rts;
    reg_d1.b[0] = 0x80;
    func_002010A0();
    reg_d0.b[0] = (s8)reg_d0.b[0] >> 1;
    reg_d0.b[0] += 4;
    goto next_5;
next_3:
    func_002010A0();
    reg_d1.w = 0;
    if ((s8)reg_d0.b[0] >= 0) goto next_4;
    reg_d1.b[0] = 0x80;
next_4:
    func_002010A0();
    reg_d0.b[0] = (s8)reg_d0.b[0] >> 1;
    reg_d0.b[0] += 4;
next_5:
    reg_d0.h[0] = reg_d0.b[0];
    reg_d1.h[0] = reg_d1.b[0];
    func_00201E20();
    *p0 = reg_d2.h[0];
block_rts:
    return;
}

s32 func_00124D90();                            /* extern */

void func_001E4EA0(void) {
    reg_d0.w = 4;
    func_00124D90();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 1;
    (*(s8 *)((u8 *)(reg_a4) + (2))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0;
    func_001E4EF0();
}

s32 func_00124D90();
s32 func_00125060();

void func_001E4EF0(void) {
    u32 t;

    if (!(reg_a4[3] & 1)) {
        goto next_1;
    }
    if (*(u16 *)(reg_a6 + 0x18E) == -0x1000) {
        goto next_1;
    }
    *(u16 *)(reg_a4 + 6) += 4;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 6);
    *(u16 *)(reg_a6 + 0x18E) -= reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x192) += reg_d0.h[0];
    if (*(s16 *)(reg_a6 + 0x192) < 0xE00) {
        goto next_1;
    }
    *(u16 *)(reg_a6 + 0x192) = 0xE00;
    *(u16 *)(reg_a6 + 0x18E) = 0xF200;
    t = reg_a4[3];
    if (t & 1) {
        reg_a4[3] = t & 0xFE;
    }
    reg_a4[3] |= 2;
    reg_a4[3] |= 4;
    *(u16 *)(reg_a6 + 0x198) = 0;
    *(u16 *)(reg_a6 + 0x19A) = 0;
    *(u16 *)(reg_a4 + 0xA) = 0;
    func_001E4D90(0x198, 0x82);
    func_001E4D90(0x19A, 0xA2);
    *(u16 *)(reg_a4 + 4) = 0x10;
    *(u16 *)(reg_a4 + 0xC) = 0x10;
    *(u16 *)(reg_a4 + 0x10) = 0x808;
    *(u16 *)(reg_a4 + 0x12) = 0;
    *(u16 *)(reg_a4 + 0x14) = 4;
next_1:
    if (!(reg_a4[2] & 1)) {
        goto next_2;
    }
    reg_d0.w = 6;
    func_00125060();
    if (cond_flag != 0) {
        goto next_2;
    }
    reg_d0.w = 8;
    func_00125060();
    if (cond_flag != 0) {
        goto next_2;
    }
    reg_d0.w = 5;
    func_00124F50();
    reg_d0.w = 7;
    func_00124F50();
    t = reg_a4[2];
    if (t & 1) {
        reg_a4[2] = t & 0xFE;
    }
    reg_a4[2] |= 2;
next_2:
    if (!(reg_a4[2] & 2)) {
        goto next_3;
    }
    reg_d0.w = 5;
    func_00125060();
    if (cond_flag != 0) {
        goto next_3;
    }
    reg_d0.w = 7;
    func_00125060();
    if (cond_flag != 0) {
        goto next_3;
    }
    reg_d0.w = 8;
    func_001251C0();
    t = reg_a4[2];
    if (t & 2) {
        reg_a4[2] = t & 0xFD;
    }
next_3:
    if (!(reg_a4[2] & 4)) {
        goto next_4;
    }
    reg_d0.w = 6;
    func_00125060();
    if (cond_flag != 0) {
        goto next_4;
    }
    reg_d0.w = 8;
    func_00125060();
    if (cond_flag != 0) {
        goto next_4;
    }
    reg_d0.w = 5;
    func_00124F50();
    reg_d0.w = 7;
    func_00124F50();
    t = reg_a4[2];
    if (t & 4) {
        reg_a4[2] = t & 0xFB;
    }
    reg_a4[2] |= 8;
next_4:
    if (!(reg_a4[2] & 8)) {
        goto next_5;
    }
    reg_d0.w = 5;
    func_00125060();
    if (cond_flag != 0) {
        goto next_5;
    }
    reg_d0.w = 7;
    func_00125060();
    if (cond_flag != 0) {
        goto next_5;
    }
    t = reg_a4[2];
    if (t & 8) {
        reg_a4[2] = t & 0xF7;
    }
next_5:
    if (!(reg_a4[3] & 2)) {
        goto next_6;
    }
    t = *(u16 *)(reg_a4 + 4);
    if (t != 0) {
        *(u16 *)(reg_a4 + 4) = t - 1;
    }
    func_001E4D90(0x198, 0x82);
    func_001E4D90(0x19A, 0xA2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x198);
    *(u16 *)(reg_a6 + 0x18C) += reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x19A);
    *(u16 *)(reg_a6 + 0x190) += reg_d0.h[0];
next_6:
    if (!(reg_a4[3] & 4)) {
        goto next_8;
    }
    reg_d0.w = 4;
    func_00125060();
    if (cond_flag != 0) {
        goto next_8;
    }
    t = *(u16 *)(reg_a4 + 0xC);
    if (t == 0) {
        goto next_7;
    }
    *(u16 *)(reg_a4 + 0xC) = t - 1;
    if (*(s16 *)(reg_a4 + 0xC) != 0) {
        goto next_8;
    }
    reg_d0.w = 8;
    func_00125310();
    reg_d0.w = 6;
    func_001251C0();
    reg_d0.w = 0xA;
    func_001251C0();
    reg_a4[2] |= 4;
next_7:
    reg_d0.w = 0xA;
    func_00125250();
    if (cond_flag != 0) {
        goto next_8;
    }
    reg_d0.w = 6;
    func_00125310();
    reg_d0.w = 7;
    func_00125310();
    reg_d0.w = 6;
    func_00124F50();
    reg_d0.w = 8;
    func_00124F50();
    t = reg_a4[3];
    if (t & 4) {
        reg_a4[3] = t & 0xFB;
    }
    reg_a4[3] |= 8;
    *(u16 *)(reg_a4 + 0xC) = 0x40;
next_8:
    if (!(reg_a4[3] & 8)) {
        goto next_9;
    }
    *(u16 *)(reg_a4 + 0xC) -= 1;
    if (*(s16 *)(reg_a4 + 0xC) != 0) {
        goto next_9;
    }
    reg_a4[2] |= 1;
    reg_d0.w = 3;
    func_00124F50();
    reg_d0.w = 7;
    func_00124D90();
    t = reg_a4[3];
    if (t & 8) {
        reg_a4[3] = t & 0xF7;
    }
    reg_a4[3] |= 0x10;
    reg_a4[0x11] = reg_a4[0x10];
    t = reg_a4[0x10];
    if (t == 8) {
        goto next_9;
    }
    reg_a4[0x10] = t + 1;
next_9:
    if (!(reg_a4[3] & 0x10)) {
        goto next_10;
    }
    reg_d0.w = 3;
    func_00125060();
    if (cond_flag != 0) {
        goto next_10;
    }
    reg_d0.w = 9;
    func_00125250();
    if (cond_flag != 0) {
        goto next_10;
    }
    reg_tmp.b[0] = reg_a4[0x15];
    reg_a4[0x15] -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_10;
    }
    reg_a4[0x15] = reg_a4[0x14];
    reg_d0.w = 9;
    func_001251C0();
    *(u16 *)(reg_a0 + 6) = *(u16 *)(reg_a4 + 0x12);
    *(u16 *)(reg_a4 + 0x12) += 1;
    *(u16 *)(reg_a4 + 0x12) &= 1;
    t = reg_a4[3];
    if (t & 0x10) {
        reg_a4[3] = t & 0xEF;
    }
    reg_a4[3] |= 0x20;
    *(u16 *)(reg_a4 + 0xC) = 0xE0;
next_10:
    if (!(reg_a4[3] & 0x20)) {
        return;
    }
    reg_d0.w = 9;
    func_00125250();
    if (cond_flag != 0) {
        return;
    }
    *(u16 *)(reg_a4 + 0xC) -= 1;
    if (*(s16 *)(reg_a4 + 0xC) != 0) {
        return;
    }
    reg_d0.w = 4;
    func_00124D90();
    reg_d0.w = 4;
    func_00124F50();
    t = reg_a4[3];
    if (t & 0x20) {
        reg_a4[3] = t & 0xDF;
    }
    reg_a4[3] |= 4;
    *(u16 *)(reg_a4 + 0xC) = 0x40;
}

s32 func_00125120();
extern u16 D_0028E85C;
extern u16 D_0028E860;
extern u16 D_0028E864;
extern u16 D_0028E868;
extern u16 D_0028E86C;
extern u16 D_0028E910;

void func_001E55D0() {
    D_0028E85C = 2;
    D_0028E86C = 0xFFFF;
    reg_d0.w = 8;
    D_0028E868 = 0xFFFF;
    D_0028E864 = 0;
    func_00124D90();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    reg_d0.w = 4;
    func_00125120();
    reg_d0.w = 3;
    func_00124F50();
    reg_d0.w = 6;
    func_00125310();
    reg_d0.w = 7;
    func_00125310();
    reg_d0.w = 8;
    func_00125310();
    reg_d0.w = 9;
    func_00125310();
    reg_d0.w = 0xA;
    func_00125310();
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x180;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 0x100;
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 1;
    if (D_0028E910 != 0) {
        (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 3;
    }
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 8;
    (*(s16 *)((u8 *)(reg_a4) + (0xE))) = 8;
    D_0028E860 = 0;
    func_001E56D0();
}

s32 func_002011A0();
extern s16 D_0028E860_as_s16;

void func_001E56D0() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 var_a0;

    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        reg_d0.w = 3;
        func_00125060();
        if (cond_flag == 0) {
            reg_d0.w = 0xB;
            func_001251C0();
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        }
    }
    var_a0 = 1;
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 1) {
        D_0028E860_as_s16 = 0;
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            D_0028E860_as_s16 = 1;
            func_002011A0();
            reg_d0.h[0] &= 0x7F;
            reg_d0.h[0] += 0x1C0;
            var_a0 = reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a4) + (4))) = var_a0;
        }
    }
    if ((*(u16 *)((u8 *)(reg_a4) + (6))) == 0) {
        reg_d0.w = 0xD;
        func_00125250();
        if (cond_flag == 0) {
            (*(u16 *)((u8 *)(reg_a4) + (8))) -= 1;
            if ((s16) (*(u16 *)((u8 *)(reg_a4) + (8))) == 0) {
                reg_d0.w = 0xE;
                func_001251C0();
                (*(u16 *)((u8 *)(reg_a0) + (0x10))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0xC)));
                (*(u16 *)((u8 *)(reg_a4) + (6))) = 1U;
                (*(u16 *)((u8 *)(reg_a4) + (8))) = 0x30U;
            }
        }
    }
    temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (6)));
    if (temp_a0 == 1) {
        reg_d0.w = 0xE;
        func_00125250();
        if (cond_flag == 0) {
            (*(u16 *)((u8 *)(reg_a4) + (8))) -= 1;
            if ((s16) (*(u16 *)((u8 *)(reg_a4) + (8))) == 0) {
                (*(u16 *)((u8 *)(reg_a4) + (6))) = 0U;
                reg_d0.w = 0xD;
                func_001251C0();
                (*(u16 *)((u8 *)(reg_a0) + (0x10))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                (*(u16 *)((u8 *)(reg_a0) + (0x12))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0xE)));
                (*(u16 *)((u8 *)(reg_a4) + (8))) = 0x40U;
                reg_d0.h[0] = 5;
                if (D_0028E910 == 0) {
                    reg_d0.h[0] = 3;
                }
                temp_a0_2 = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                if (temp_a0_2 != reg_d0.h[0]) {
                    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) (temp_a0_2 + 1);
                }
                temp_a0_3 = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
                if (temp_a0_3 != 0x10) {
                    (*(u16 *)((u8 *)(reg_a4) + (0xE))) = (u16) (temp_a0_3 + 1);
                }
            }
        }
    }
}
