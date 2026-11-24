#include "common.h"
#include "entity.h"

void func_001B39F0(void);

extern u16 *reg_a4_as_u16_p;

void func_001B23C0(void) {
    *reg_a4_as_u16_p = 0;
}

s32 func_002011A0();                            /* extern */

void func_001B23D0(void) {
    func_002011A0();
    *(u8 *)(reg_a4 + 5) = (u8) reg_d0.b[0];
    func_002011A0();
    *(u8 *)(reg_a4 + 4) = (u8) reg_d0.b[0];
}

s32 func_00201E20();

void func_001B2410(void) {
    u32 temp_a0;

    if (*(u8 *)(reg_a6 + 0x3E) != 0) {
        func_001B23C0();
        return;
    }
    reg_d1.w = 0;
    reg_d0.w = 2;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 5);
    func_00201E20();
    temp_a0 = *(u16 *)(reg_a6 + 0x26);
    *(u16 *)(reg_a6 + 0x26) = (u16) (temp_a0 + reg_d2.h[0]);
    reg_d0.w = 1;
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 4);
    func_00201E20();
    *(u16 *)(reg_a6 + 0x28) += reg_d3.h[0];
    *(u8 *)(reg_a4 + 5) += 2;
    *(u8 *)(reg_a4 + 4) += 1;
}

s32 func_002011A0();                            /* extern */

void func_001B24C0(void) {
    func_002011A0();
    *(u8 *)(reg_a4 + 5) = (u8) reg_d0.b[0];
    func_002011A0();
    *(u8 *)(reg_a4 + 4) = (u8) reg_d0.b[0];
}

void func_001B2500(void) {
    u32 temp_a0;

    if (*(u8 *)(reg_a6 + 0x7E) != 0) {
        func_001B23C0();
        return;
    }
    reg_d1.w = 0;
    reg_d0.w = 2;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 5);
    func_00201E20();
    temp_a0 = *(u16 *)(reg_a6 + 0x66);
    *(u16 *)(reg_a6 + 0x66) = (u16) (temp_a0 + reg_d2.h[0]);
    reg_d0.w = 1;
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 4);
    func_00201E20();
    *(u16 *)(reg_a6 + 0x68) += reg_d3.h[0];
    *(u8 *)(reg_a4 + 5) += 2;
    *(u8 *)(reg_a4 + 4) += 1;
}

void func_001B25B0(void) {
    reg_a4_as_u16_p[1] = 0;
}

void func_001B25C0(void) {
    if (*(u8 *)(reg_a6 + 0x3E) != 0) {
        func_001B23C0();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0x2A) += 4;
        if (*(s16 *)(reg_a6 + 0x2A) > 0xc) {
            *(u16 *)(reg_a6 + 0x2A) = 0U;
        }
    }
}

void func_001B2650(void) {
    reg_a4_as_u16_p[1] = 0;
}

void func_001B2660(void) {
    if (*(u8 *)(reg_a6 + 0x7E) != 0) {
        func_001B23C0();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0x6A) += 4;
        if (*(s16 *)(reg_a6 + 0x6A) > 0xc) {
            *(u16 *)(reg_a6 + 0x6A) = 0U;
        }
    }
}

s32 func_0013A780();

void func_001B26F0(arg2)
    u16 *arg2;
{
    u16 *var_a2;
    u16 temp_a1;

    var_a2 = (u16 *)(arg2);
loop_1:
    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        func_0013A780();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
        var_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(var_a2);
        *(u16 *)(reg_a0 + 2) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
        *(s16 *)(reg_a0 + 0x1E) = 0xC;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        if (reg_d0.h[0] != 0) {
            reg_d0.h[0] -= 1;
            *(u8 *)(reg_a4 + 2) |= ((1 << (s8) reg_d0.b[0]) & 0xFF);
        }
        goto loop_1;
    }
}

s32 func_002010A0();

void func_001B2830(void) {
    u16 *temp_a2;
    u16 temp_a1;

    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        func_0013A780();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
        temp_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(temp_a2);
        *(u16 *)(reg_a0 + 2) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
        *(s16 *)(reg_a0 + 0x1E) = 4;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(u16 *)(reg_a0 + 0x1A) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        func_002010A0();
        *(u8 *)(reg_a0 + 0x1A) += reg_d0.b[0];
        func_001B2830();
    }
}

void func_001B2960(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 4) = 8;
    *(s16 *)(reg_a4 + 6) = 5;
    *(s16 *)(reg_a4 + 8) = 7;
    *(s16 *)(reg_a4 + 0xA) = 0x1008;
    *(s16 *)(reg_a4 + 0xC) = 0;
}

s32 func_00124F00();
s32 func_0018D540();
s32 func_0018D560();
extern u8 D_0026DBD0[];
extern u8 D_0026DC40[];
extern u16 D_0029C06C[];

void func_001B29B0(void) {
    u32 temp_a1;
    u8 temp_a0;
    u8 temp_v1;

    reg_d0.h[0] = D_0029C06C[0];
    temp_a1 = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x24) = (u16) (temp_a1 - reg_d0.h[0]);
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 2) {
        func_0018D540();
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x24);
        reg_a1 = (u8 *)D_0026DC40;
        func_001B2830();
        *(s16 *)reg_a4 = 0;
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
        *(u8 *)(reg_a4 + 0xB) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
            temp_v1 = *(u8 *)(reg_a4 + 0xA);
            if (temp_v1 != 0) {
                *(u8 *)(reg_a4 + 0xA) = (u8) (temp_v1 - 1);
            }
            *(u16 *)(reg_a4 + 0xC) += 0x10;
            *(u16 *)(reg_a6 + 0x46) -= 0x800;
            *(u16 *)(reg_a6 + 0x48) -= 0x800;
            if (0 > (s16) *(u16 *)(reg_a6 + 0x48)) {
                reg_tmp.w = 0;
                *(u16 *)(reg_a6 + 0x46) = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a6 + 0x48) = (u16) reg_tmp.h[0];
                *(u16 *)(reg_a4 + 0xC) = 0U;
                *(u8 *)(reg_a4 + 3) = 2U;
                reg_d0.w = 0;
                func_00124F00();
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u8 *)(reg_a4 + 3) = 1U;
        func_0018D560();
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x24);
        reg_a1 = (u8 *)D_0026DBD0;
        func_001B26F0();
    }
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    *(u16 *)(reg_a6 + 0x22) -= reg_d0.h[0];
}

void func_001B2B70(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 4) = 8;
    *(s16 *)(reg_a4 + 6) = 5;
    *(s16 *)(reg_a4 + 8) = 7;
    *(s16 *)(reg_a4 + 0xA) = 0x1008;
    *(s16 *)(reg_a4 + 0xC) = 0;
}

extern u8 D_0026DC80[];
extern u8 D_0026DCF0[];

void func_001B2BC0(void) {
    u8 temp_a0;
    u8 temp_v1;
    u8 *var_a1;

    var_a1 = (u8 *)(reg_a6);
    reg_d0.h[0] = D_0029C06C[0];
    (*(u16 *)((u8 *)(var_a1) + (0x64))) -= reg_d0.h[0];
    if (*(u8 *)(reg_a4 + 2) & 4) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
        *(u8 *)(reg_a4 + 9) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            reg_d0.w = 0x10;
            func_0013A780();
            *(s16 *)(reg_a0 + 0x1E) = 4;
            *(s8 *)(reg_a0 + 0x1B) = 0x10;
            func_002010A0();
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 0x62);
            var_a1 = (u8 *)((void *) *(u16 *)(reg_a6 + 0x64));
            *(s16 *)(reg_a0 + 4) = (s16) var_a1;
            reg_tmp.w = 0xFDFFFC00;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
        }
    }
    if (*(u8 *)(reg_a4 + 2) & 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            reg_d0.w = 0x10;
            func_0013A780();
            *(s16 *)(reg_a0 + 0x1E) = 4;
            *(s8 *)(reg_a0 + 0x1B) = 0x10;
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 0x62);
            var_a1 = (u8 *)((void *) *(u16 *)(reg_a6 + 0x64));
            *(s16 *)(reg_a0 + 4) = (s16) var_a1;
            reg_tmp.w = 0xF2000200;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
        }
    }
    if (*(u8 *)(reg_a4 + 2) & 2) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            reg_d0.w = 6;
            func_0013A780();
            *(s16 *)(reg_a0 + 0x1E) = 8;
            *(s8 *)(reg_a0 + 0x1B) = 0xC;
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 0x62);
            var_a1 = (u8 *)((void *) *(u16 *)(reg_a6 + 0x64));
            *(s16 *)(reg_a0 + 4) = (s16) var_a1;
            reg_tmp.w = 0xF5FFFC00;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 2) {
        func_0018D540();
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x62);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x64);
        reg_a1 = D_0026DCF0;
        func_001B2830();
        *(s16 *)reg_a4 = 0;
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
        *(u8 *)(reg_a4 + 0xB) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
            temp_v1 = *(u8 *)(reg_a4 + 0xA);
            if (temp_v1 != 0) {
                *(u8 *)(reg_a4 + 0xA) = (u8) (temp_v1 - 1);
            }
            *(u16 *)(reg_a4 + 0xC) += 0x10;
            *(u16 *)(reg_a6 + 0x86) -= 0x800;
            *(u16 *)(reg_a6 + 0x88) -= 0x800;
            if (0 > (s16) *(u16 *)(reg_a6 + 0x88)) {
                reg_tmp.w = 0;
                *(u16 *)(reg_a6 + 0x86) = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a6 + 0x88) = (u16) reg_tmp.h[0];
                *(u16 *)(reg_a4 + 0xC) = 0U;
                *(u8 *)(reg_a4 + 3) = 2U;
                reg_d0.w = 1;
                func_00124F00();
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u8 *)(reg_a4 + 3) = 1U;
        func_0018D560();
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x62);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x64);
        reg_a1 = D_0026DC80;
        func_001B26F0();
    }
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    *(u16 *)(reg_a6 + 0x62) -= reg_d0.h[0];
}

void func_001B2FC0(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 4) = 8;
    *(s16 *)(reg_a4 + 6) = 0x1209;
    *(s16 *)(reg_a4 + 0xA) = 0x20;
    *(s16 *)(reg_a4 + 0xC) = 0xC;
    *(s16 *)(reg_a4 + 0xE) = 0;
    *(s16 *)(reg_a4 + 0x10) = 0;
    *(s16 *)(reg_a4 + 0x12) = 0x1010;
    *(s16 *)(reg_a4 + 0x14) = 0;
}

typedef void (*Fn)();

s32 func_00124510();
s32 func_00125410();
s32 func_00125440();
s32 func_0013A9E0();
s32 func_0013AB50();
s32 func_0013B2E0();
s32 func_0018D660();
s32 func_002011A0();
extern u8 D_0026DD30[];
extern u16 D_0026DD50[];
extern u16 D_0026DDC0[];
extern u16 D_0026DE00[];
extern u16 D_0026DF00[];
extern u8 D_0026DF70[];
extern u8 D_0026DFC0[];
extern u8 D_0028E310;

void func_001B3030(void) {
    u16 *temp_a3_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_6;
    u16 temp_a0_7;
    u16 temp_a1;
    u16 temp_a2;
    u16 temp_a3;
    u16 temp_v1;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_5;
    u8 *var_a1;

    var_a1 = (u8 *)(reg_a4);
    temp_a0 = (*(u8 *)((u8 *)(var_a1) + (3)));
    if (temp_a0 == 6) {
        (*(u16 *)((u8 *)(var_a1) + (0xA))) -= 1;
        if (*(u16 *)(reg_a4 + 0xA) == 0) {
            func_00124510();
            *(s16 *)reg_a4 = 0;
        }
        return;
    }
    if ((*(u8 *)((u8 *)(var_a1) + (2))) & 2) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a1) + (7)));
        (*(u8 *)((u8 *)(var_a1) + (7))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            reg_d0.w = 5;
            func_0013A780();
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s8 *)(reg_a0 + 0x1B) = 0x14;
            func_002010A0();
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            var_a1 = (u8 *)((void *) ENTITY(reg_a6)->x.h);
            *(u16 *)(reg_a0 + 4) = (u16) var_a1;
            reg_tmp.w = 0xF8000000;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
        }
    }
    if (*(u8 *)(reg_a4 + 2) & 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            reg_d0.w = 0x10;
            func_0013A780();
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s8 *)(reg_a0 + 0x1B) = 0x18;
            func_002010A0();
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a1;
            reg_tmp.w = 0xE8000400;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
            reg_d0.w = 0x10;
            func_0013A780();
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s8 *)(reg_a0 + 0x1B) = 0x14;
            func_002010A0();
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            var_a1 = (u8 *)((void *) ENTITY(reg_a6)->x.h);
            *(u16 *)(reg_a0 + 4) = (u16) var_a1;
            reg_tmp.w = 0xF3FFF800;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_2 == 5) {
        func_0018D660();
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_a1 = (u8 *)(D_0026DF00);
        func_001B2830();
        func_002010A0();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x40;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d2.w += 0xF8000A00;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        func_0013A9E0();
        func_002010A0();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0xB0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        reg_d2.w -= 0x800;
        func_0013A9E0();
        func_002010A0();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x80;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d2.w += 0xF4000000;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        func_0013A9E0();
        var_a1 = (u8 *)((void *)0x80);
        *(u16 *)(reg_a4 + 0xA) = 0x80U;
        *(u8 *)(reg_a4 + 3) = 6U;
    }
    temp_a0_5 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_5 == 4) {
        func_00125440();
        if (cond_flag == 0) {
            D_0028E310 = 0xA;
            reg_a0 = D_0026DFC0;
            func_0013B2E0();
            reg_d0.w = 2;
            func_00124F00();
            reg_d0.w = 4;
            func_00124F00();
            reg_d0.w = 5;
            func_00124F00();
            *(u8 *)(reg_a4 + 3) = 5U;
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 3) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x13);
        *(u8 *)(reg_a4 + 0x13) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
            reg_a0 = D_0026DD30;
            temp_a0_6 = *(u16 *)(reg_a4 + 0x14);
            reg_a0 += temp_a0_6;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x14);
            ((Fn)*(u32 *)((u8 *)D_0026DD30 + (reg_tmp.h[0] & ~3)))();
            *(u16 *)(reg_a4 + 0x14) += 4;
            *(u16 *)(reg_a4 + 0x14) &= 0x1F;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
        *(u8 *)(reg_a4 + 0xD) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            reg_a1 = (u8 *)(D_0026DE00);
            reg_a1 += *(u16 *)(reg_a4 + 0xE);
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            func_0013A780();
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a3 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a3;
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x800;
            *(u16 *)(reg_a0 + 0x1A) = *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u16 *)(reg_a4 + 0xE) += 0x10;
            if (*(u16 *)(reg_a4 + 0xE) == 0x100) {
                *(u16 *)(reg_a4 + 0xE) = 0U;
                *(u8 *)(reg_a4 + 3) = 4U;
                reg_d0.h[0] = 0x12;
                func_00125410();
                func_0018D560();
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 2) {
        temp_v1 = *(u16 *)(reg_a4 + 0xA);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 0xA) = (u16) (temp_v1 - 1);
        } else {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x13);
            *(u8 *)(reg_a4 + 0x13) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
                reg_a0 = D_0026DD30;
                temp_a0_7 = *(u16 *)(reg_a4 + 0x14);
                reg_a0 += temp_a0_7;
                reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x14);
                ((Fn)*(u32 *)((u8 *)D_0026DD30 + (reg_tmp.h[0] & ~3)))();
                *(u16 *)(reg_a4 + 0x14) += 4;
                *(u16 *)(reg_a4 + 0x14) &= 0x1F;
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
            *(u8 *)(reg_a4 + 0xD) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
                reg_a1 = (u8 *)(D_0026DE00);
                reg_a1 += *(u16 *)(reg_a4 + 0xE);
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                func_0013A780();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                temp_a3_2 = (u16 *)(reg_a1 + 2);
                reg_a1 = (u8 *)(temp_a3_2);
                *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
                temp_a2 = ENTITY(reg_a6)->x.h;
                *(u16 *)(reg_a0 + 4) = temp_a2;
                *(s16 *)(reg_a0 + 0x1E) = 0xC;
                *(s16 *)(reg_a0 + 0x12) = 0;
                *(s16 *)(reg_a0 + 0x14) = 0x800;
                *(u16 *)(reg_a0 + 0x1A) = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a4 + 0x10) += 1;
                *(u16 *)(reg_a4 + 0x10) &= 1;
                if (*(u16 *)(reg_a4 + 0x10) == 0) {
                    D_0028E310 = 0xA;
                    reg_a0 = D_0026DF70;
                    func_0013B2E0();
                    func_002011A0();
                    reg_d1.b[0] = reg_d0.b[0];
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d3.h[0] = 0xC;
                    reg_d0.h[0] = 0;
                    func_0013AB50();
                    func_0018D540();
                }
                *(u16 *)(reg_a4 + 0xE) += 0x10;
                if (*(u16 *)(reg_a4 + 0xE) == 0x80) {
                    *(u16 *)(reg_a4 + 0xE) = 0U;
                    *(u8 *)(reg_a4 + 3) = 3U;
                    *(u16 *)(reg_a4 + 0xC) = 4;
                    *(u8 *)(reg_a4 + 2) = 0U;
                    *(u16 *)(reg_a4 + 0x12) = 0x808;
                }
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        *(u16 *)(reg_a4 + 0xA) -= 1;
        if (*(u16 *)(reg_a4 + 0xA) == 0) {
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)(D_0026DDC0);
            func_001B26F0();
            *(u8 *)(reg_a4 + 3) = 2U;
            *(u16 *)(reg_a4 + 0xA) = 0x80U;
            *(u8 *)(reg_a4 + 2) |= 2;
            reg_d0.w = 3;
            func_00124F00();
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u8 *)(reg_a4 + 3) = 1U;
        func_0018D560();
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_a1 = (u8 *)(D_0026DD50);
        func_001B26F0();
    }
}


void func_001B39E0(void) {
    func_001B39F0();
}

void func_001B39F0(void) {
    u8 temp_a0;

    reg_tmp.b[0] = (*(u8 *)(reg_a6 + 0xAF));
    (*(u8 *)(reg_a6 + 0xAF)) -= 1;
    if ((s32)reg_tmp.b[0] <= 0) {
        (*(u8 *)(reg_a6 + 0xAF)) = (*(u8 *)(reg_a6 + 0xAE));
        temp_a0 = (*(u8 *)(reg_a6 + 0xAE));
        if (temp_a0 != 2) {
            if ((s8)temp_a0 >= 2) {
                (*(u8 *)(reg_a6 + 0xAE)) = temp_a0 - 1;
            } else {
                (*(u8 *)(reg_a6 + 0xAE)) = temp_a0 + 1;
            }
        }
        (*(u16 *)(reg_a6 + 0xAA)) += 4;
        if ((s16)(*(u16 *)(reg_a6 + 0xAA)) >= 0x1C) {
            (*(u16 *)(reg_a6 + 0xAA)) = 0;
        }
    }
}

void func_001B3A90(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    reg_a4[7] = 0;
}

s32 func_00124F50();
s32 func_00125120();

void func_001B3AB0() {
    u16 temp_a0;

    if (*(u8 *)(reg_a6 + 0x3E) != 0) {
        func_001B23C0();
        return;
    }
    if ((*(u8 *)(reg_a4 + 7) == 0) && (*(u16 *)(reg_a6 + 0x2A) == 0)) {
        reg_d0.w = 2;
        func_00125120();
        *(u16 *)(reg_a6 + 0x2A) = 0x10U;
        *(u8 *)(reg_a4 + 7) = 1U;
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            *(u16 *)(reg_a6 + 0x4C) += 0xC0;
            *(u8 *)(reg_a6 + 0x4B) += 2;
            *(u16 *)(reg_a6 + 0x2A) += 4;
            temp_a0 = *(u16 *)(reg_a6 + 0x2A);
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                func_00124F50();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

typedef struct WorkRegA4 {
    u8 pad0[2];
    u16 unk2;
    u8 pad4[3];
    u8 unk7;
} WorkRegA4;


void func_001B3BC0(void) {
    extern WorkRegA4 *reg_a4_as_WorkRegA4_p;
    reg_a4_as_WorkRegA4_p->unk2 = 0;
    reg_a4_as_WorkRegA4_p->unk7 = 0;
}

void func_001B3BE0() {
    u16 temp_a0;

    if (*(u8 *)(reg_a6 + 0x7E) != 0) {
        func_001B23C0();
        return;
    }
    if ((*(u8 *)(reg_a4 + 7) == 0) && (*(u16 *)(reg_a6 + 0x6A) == 0)) {
        reg_d0.w = 3;
        func_00125120();
        *(u16 *)(reg_a6 + 0x6A) = 0x10U;
        *(u8 *)(reg_a4 + 7) = 1U;
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            *(u16 *)(reg_a6 + 0x8C) += 0xC0;
            *(u8 *)(reg_a6 + 0x8B) += 2;
            *(u16 *)(reg_a6 + 0x6A) += 4;
            temp_a0 = *(u16 *)(reg_a6 + 0x6A);
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xB;
                func_00124F50();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}


void func_001B3CF0(void) {
    *(u16*)(reg_a4 + 2) = 0;
}

void func_001B3D00(void) {
    if (*(u8 *)(reg_a6 + 0x3E) != 0) {
        func_001B23C0();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0x2A) += 4;
        if (*(s16 *)(reg_a6 + 0x2A) > 0x74) {
            *(u16 *)(reg_a6 + 0x2A) = 0x68U;
        }
    }
}

extern s16 *reg_a4_as_s16_p;

void func_001B3D90(void) {
    reg_a4_as_s16_p[1] = 0;
}

void func_001B3DA0(void) {
    if (*(u8 *)(reg_a6 + 0x7E) != 0) {
        func_001B23C0();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0x6A) += 4;
        if (*(s16 *)(reg_a6 + 0x6A) > 0x74) {
            *(u16 *)(reg_a6 + 0x6A) = 0x68U;
        }
    }
}

s32 func_001251C0();
s32 func_001713B0();
s32 func_002011D0();
extern u8 D_0026DFE0[];
extern u8 D_0028DC28[];
extern u8 D_0028DC30[];

void func_001B3E30(void) {
    *(s16 *)(reg_a6 + 0x114) = 0;
    *(u8 *)(reg_a4 + 3) = 1U;
    func_002011D0();
    if (reg_d0.h[0] == 0) {
        *(u8 *)(reg_a4 + 3) = 0xFFU;
    }
    *(u8 *)(reg_a4 + 2) = (u8) *(u8 *)(reg_a4 + 3);
    *(s16 *)(reg_a4 + 4) = 0x4040;
    *(s8 *)(reg_a4 + 7) = 0;
    *(s16 *)(reg_a4 + 8) = 0x60;
    reg_tmp.w = 0;
    *(u16 *)(reg_a4 + 0xA) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0xC) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0;
    *(u16 *)(reg_a4 + 0xE) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x10) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a4 + 0x12) = 0;
    func_001713B0();
    reg_d2.w = 0;
    reg_d2.b[0] = *(D_0028DC28 + reg_d0.h[0]);
    reg_d2.b[0] -= *(u8 *)(reg_a6 + 0x113);
    if ((s8) reg_d2.b[0] < 5) {
        reg_d2.b[0] = 4;
    }
    *(u8 *)(reg_a6 + 0x113) += 1;
    if ((s8) *(u8 *)(reg_a6 + 0x113) > 4) {
        *(u8 *)(reg_a6 + 0x113) = 4U;
    }
    reg_d3.w = 0;
    reg_d3.b[0] = *(D_0028DC30 + reg_d0.h[0]);
    reg_d3.b[0] -= *(u8 *)(reg_a6 + 0x112);
    if ((s8) reg_d3.b[0] < 0x10) {
        reg_d3.b[0] = 0xF;
    }
    *(u8 *)(reg_a6 + 0x112) += 1;
    if ((s8) *(u8 *)(reg_a6 + 0x112) > 0x10) {
        *(u8 *)(reg_a6 + 0x112) = 0x10U;
    }
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)D_0026DFE0;
    reg_d4.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d0.w = 5;
    func_001251C0();
    *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
    *(u8 *)(reg_a0 + 0xA) = (u8) reg_d3.b[0];
    *(u16 *)(reg_a0 + 0xC) = (u16) reg_d4.h[0];
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a4 + 0xA) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0xC) = (u16) reg_tmp.h[0];
    reg_d0.w = 6;
    func_001251C0();
    *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
    *(u8 *)(reg_a0 + 0xA) = (u8) reg_d3.b[0];
    *(u16 *)(reg_a0 + 0xC) = (u16) reg_d4.h[0];
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a4 + 0xE) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x10) = (u16) reg_tmp.h[0];
    reg_d0.w = 0xE;
    func_001251C0();
}

s32 func_00125310();

void func_001B40C0(void) {
    u16 temp_v1;

    if (*(u8 *)(reg_a4 + 7) == 0) {
        *(u16 *)(reg_a4 + 8) -= 1;
        if (*(u16 *)(reg_a4 + 8) == 0) {
            *(u8 *)(reg_a4 + 7) = 1U;
            *(s16 *)(reg_a6 + 0x114) = 1;
            goto block_3;
        }
    } else {
block_3:
        reg_d0.b[0] = *(u8 *)(reg_a4 + 2);
        *(u8 *)(reg_a6 + 0x4A) += reg_d0.b[0];
        *(u8 *)(reg_a6 + 0x8A) += reg_d0.b[0];
        if (*(u8 *)(reg_a4 + 7) == 1) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                reg_d0.b[0] = *(u8 *)(reg_a4 + 3);
                *(u8 *)(reg_a4 + 2) += reg_d0.b[0];
                reg_d0.b[0] = *(u8 *)(reg_a4 + 2);
                if ((s8)(reg_d0.b[0]) < 0) {
                    reg_d0.b[0] *= -1;
                }
                if (reg_d0.b[0] == 2) {
                    *(u8 *)(reg_a4 + 7) = 2U;
                    *(u16 *)(reg_a4 + 4) = 0x6020;
                    *(u16 *)(reg_a4 + 0x12) = 0x100U;
                }
            }
        }
        if (*(u8 *)(reg_a4 + 7) == 2) {
            temp_v1 = *(u16 *)(reg_a4 + 0x12);
            if (temp_v1 != 0) {
                *(u16 *)(reg_a4 + 0x12) = (u16) (temp_v1 - 1);
            } else {
                reg_d0.b[0] = *(u8 *)(reg_a4 + 3);
                reg_d0.b[0] += reg_d0.b[0];
                reg_d1.b[0] = *(u8 *)(reg_a4 + 2);
                if (reg_d0.b[0] != reg_d1.b[0]) {
                    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
                    *(u8 *)(reg_a4 + 5) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                        reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xA);
                        reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xC);
                        reg_a0 = (u8 *)reg_tmp.w;
                        reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xE);
                        reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x10);
                        reg_a0 = (u8 *)reg_tmp.w;
                        reg_d0.b[0] = *(u8 *)(reg_a4 + 3);
                        *(u8 *)(reg_a4 + 2) -= reg_d0.b[0];
                    }
                } else {
                    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x4A);
                    reg_d0.b[0] &= 0xFE;
                    if (reg_d0.b[0] == 0x40) {
                        *(u8 *)(reg_a6 + 0x4A) = 0x40U;
                        *(u8 *)(reg_a6 + 0x8A) = 0xC0U;
                        *(u8 *)(reg_a4 + 7) = 3U;
                        reg_d0.w = 5;
                        func_00125310();
                        reg_d0.w = 6;
                        func_00125310();
                        reg_d0.w = 0xE;
                        func_00125310();
                    }
                }
            }
        }
        if (*(u8 *)(reg_a4 + 7) == 3) {
            *(s16 *)reg_a4 = 0;
            *(s16 *)(reg_a6 + 0x114) = 0;
        }
    }
}

typedef struct WorkRegA42 {
    u8 pad0[2];
    s16 unk2;
    s16 unk4;
    u8 pad6;
    u8 unk7;
} WorkRegA42;


void func_001B4360(void) {
    extern WorkRegA42 *reg_a4_as_WorkRegA4_p;
    reg_a4_as_WorkRegA4_p->unk2 = 0;
    reg_a4_as_WorkRegA4_p->unk4 = 0x20;
    reg_a4_as_WorkRegA4_p->unk7 = 0;
}

void func_001B4380() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if (*(u8 *)(reg_a6 + 0x3E) != 0) {
        func_001B23C0();
        return;
    }
    if (*(u8 *)(reg_a4 + 7) == 0) {
        temp_v1 = *(u16 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = *(u16 *)(reg_a6 + 0x2A);
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                func_00125120();
                *(u8 *)(reg_a4 + 7) = 1U;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            *(u16 *)(reg_a6 + 0x4C) -= 0xC0;
            *(u8 *)(reg_a6 + 0x4B) -= 2;
            *(u16 *)(reg_a6 + 0x2A) -= 4;
            temp_a0_2 = *(u16 *)(reg_a6 + 0x2A);
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 2;
                func_00124F50();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

void func_001B44A0(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    *(u16 *)(reg_a4 + 4) = 0x20;
    reg_a4[7] = 0;
}

void func_001B44C0() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if (*(u8 *)(reg_a6 + 0x7E) != 0) {
        func_001B23C0();
        return;
    }
    if (*(u8 *)(reg_a4 + 7) == 0) {
        temp_v1 = *(u16 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = *(u16 *)(reg_a6 + 0x6A);
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xB;
                func_00125120();
                *(u8 *)(reg_a4 + 7) = 1U;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            *(u16 *)(reg_a6 + 0x8C) -= 0xC0;
            *(u8 *)(reg_a6 + 0x8B) -= 2;
            *(u16 *)(reg_a6 + 0x6A) -= 4;
            temp_a0_2 = *(u16 *)(reg_a6 + 0x6A);
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 3;
                func_00124F50();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

void func_001B45E0(void) {
    *(u16 *)(reg_a4 + 2) = 0x101;
}

s32 func_00202500();

void func_001B45F0() {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_d1.w = 0;
        reg_d1.b[0] = 0x20;
        reg_d0.w = 0;
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0xAC);
        reg_d0.h[0] += 0x20;
        func_00202500();
        reg_d0.h[0] = reg_d1.h[0];
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] -= 0x20;
        *(u16 *)(reg_a6 + 0xAC) = (u16) reg_d0.h[0];
        if (reg_d1.b[0] == 0x20) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

void func_001B46A0(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    reg_a4[7] = 0;
}

void func_001B46C0() {
    u16 temp_a0;

    if (*(u8 *)(reg_a6 + 0x3E) != 0) {
        func_001B23C0();
        return;
    }
    if ((*(u8 *)(reg_a4 + 7) == 0) && (*(u16 *)(reg_a6 + 0x2A) == 0)) {
        reg_d0.w = 2;
        func_00125120();
        *(u16 *)(reg_a6 + 0x2A) = 0x10U;
        *(u8 *)(reg_a4 + 7) = 1U;
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            *(u16 *)(reg_a6 + 0x4C) += 0xC0;
            *(u8 *)(reg_a6 + 0x4B) -= 2;
            *(u16 *)(reg_a6 + 0x2A) += 4;
            temp_a0 = *(u16 *)(reg_a6 + 0x2A);
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                func_00124F50();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

struct WorkRegA4b {
    u8 unk0[2];
    s16 unk2;
    u8 unk4[3];
    u8 unk7;
};


void func_001B47D0(void) {
    extern struct WorkRegA4b *reg_a4_as_WorkRegA4_p;
    reg_a4_as_WorkRegA4_p->unk2 = 0;
    reg_a4_as_WorkRegA4_p->unk7 = 0;
}

void func_001B47F0() {
    u16 temp_a0;

    if (*(u8 *)(reg_a6 + 0x7E) != 0) {
        func_001B23C0();
        return;
    }
    if ((*(u8 *)(reg_a4 + 7) == 0) && (*(u16 *)(reg_a6 + 0x6A) == 0)) {
        reg_d0.w = 3;
        func_00125120();
        *(u16 *)(reg_a6 + 0x6A) = 0x10U;
        *(u8 *)(reg_a4 + 7) = 1U;
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            *(u16 *)(reg_a6 + 0x8C) += 0xC0;
            *(u8 *)(reg_a6 + 0x8B) -= 2;
            *(u16 *)(reg_a6 + 0x6A) += 4;
            temp_a0 = *(u16 *)(reg_a6 + 0x6A);
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xB;
                func_00124F50();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

typedef struct WorkRegA43 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u8 unk6;
    u8 unk7;
} WorkRegA43;


void func_001B4900(void) {
    extern WorkRegA43 *reg_a4_as_WorkRegA4_p;
    reg_a4_as_WorkRegA4_p->unk2 = 0;
    reg_a4_as_WorkRegA4_p->unk4 = 0x20;
    reg_a4_as_WorkRegA4_p->unk7 = 0;
}

void func_001B4920() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if (*(u8 *)(reg_a6 + 0x3E) != 0) {
        func_001B23C0();
        return;
    }
    if (*(u8 *)(reg_a4 + 7) == 0) {
        temp_v1 = *(u16 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = *(u16 *)(reg_a6 + 0x2A);
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                func_00125120();
                *(u8 *)(reg_a4 + 7) = 1U;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            *(u16 *)(reg_a6 + 0x4C) -= 0xC0;
            *(u8 *)(reg_a6 + 0x4B) += 2;
            *(u16 *)(reg_a6 + 0x2A) -= 4;
            temp_a0_2 = *(u16 *)(reg_a6 + 0x2A);
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 2;
                func_00124F50();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

void func_001B4A40(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    *(u16 *)(reg_a4 + 4) = 0x20;
    reg_a4[7] = 0;
}

void func_001B4A60() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if (*(u8 *)(reg_a6 + 0x7E) != 0) {
        func_001B23C0();
        return;
    }
    if (*(u8 *)(reg_a4 + 7) == 0) {
        temp_v1 = *(u16 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = *(u16 *)(reg_a6 + 0x6A);
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xB;
                func_00125120();
                *(u8 *)(reg_a4 + 7) = 1U;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            *(u16 *)(reg_a6 + 0x8C) -= 0xC0;
            *(u8 *)(reg_a6 + 0x8B) += 2;
            *(u16 *)(reg_a6 + 0x6A) -= 4;
            temp_a0_2 = *(u16 *)(reg_a6 + 0x6A);
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 3;
                func_00124F50();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

void func_001B4B80(void) {
    *(s16 *)(reg_a6 + 0xAE) = 0;
}

void func_001B4B90(void) {
    *(u16 *)(reg_a6 + 0xAA) += 4;
    if ((s16) *(u16 *)(reg_a6 + 0xAA) >= 0x1C) {
        *(u16 *)(reg_a6 + 0xAA) = 0U;
    }
}
