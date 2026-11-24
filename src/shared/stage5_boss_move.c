#include "common.h"

void func_001F3CC0(void);
void func_001F3D30(void);
void func_001F3F10(void);
void func_001F4050();
void func_001F4090();
void func_001F4200(void);
void func_001F4370(void);
void func_001F44E0(void);
void func_001F4630();
void func_001F4770(void);
u8 func_001F48C0(u8 arg0);
void func_001F4A30(void);


void func_001F3A10(void) {
    reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += 0x14C0;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x7FFF + 0x7181;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_d1.h[0];
    reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += 0x7FFF + 0x7B01;
    (*(u16 *)((u8 *)(reg_a6) + (0x42))) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x7FFF + 0x6E41;
    (*(u16 *)((u8 *)(reg_a6) + (0x44))) = (u16) reg_d1.h[0];
    reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += 0x7FFF + 0x6881;
    (*(u16 *)((u8 *)(reg_a6) + (0x62))) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x7FFF + 0x6EC1;
    (*(u16 *)((u8 *)(reg_a6) + (0x64))) = (u16) reg_d1.h[0];
    reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += 0x740;
    (*(u16 *)((u8 *)(reg_a6) + (0x82))) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x1040;
    (*(u16 *)((u8 *)(reg_a6) + (0x84))) = (u16) reg_d1.h[0];
    reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += 0x7FFF + 0x7781;
    (*(u16 *)((u8 *)(reg_a6) + (0xA2))) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x14C0;
    (*(u16 *)((u8 *)(reg_a6) + (0xA4))) = (u16) reg_d1.h[0];
    reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += 0x7FFF + 0x6541;
    (*(u16 *)((u8 *)(reg_a6) + (0xC2))) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x1040;
    (*(u16 *)((u8 *)(reg_a6) + (0xC4))) = (u16) reg_d1.h[0];
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A2))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x1A4))) = (u16) reg_d0.h[0];
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u16 *)((u8 *)(reg_a6) + (0x142))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x144))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x162))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x164))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x182))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a6) + (0x184))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
}

s32 func_002011A0();
extern u16 D_0029C068[];

void func_001F3C30() {
    (*(u16 *)((u8 *)(reg_a6) + (2))) = 0xB000;
    (*(u16 *)((u8 *)(reg_a6) + (4))) = 0x1C00U;
    reg_d0.h[0] = D_0029C068[0];
    (*(u16 *)((u8 *)(reg_a6) + (4))) -= reg_d0.h[0];
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d0.b[0];
    reg_d0.b[0] += 0x10;
    (*(u8 *)((u8 *)(reg_a6) + (0x130))) = (u8) reg_d0.b[0];
    reg_d0.b[0] += 0x30;
    (*(u8 *)((u8 *)(reg_a6) + (0x13C))) = (u8) reg_d0.b[0];
    func_001F3CC0();
}

s32 func_00201B80();                            /* extern */

void func_001F3CC0(void) {
    func_00201B80();
    func_001F3A10();
}


void func_001F3CF0(void) {
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x808;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x40;
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0x1A))) = 0;
    func_001F3D30();
}

s32 func_00124D90();
s32 func_00124DC0();
s32 func_00124F50();
s32 func_0018D2D0();
s32 func_001F56F0();
s32 func_001F57C0();

void func_001F3D30(void) {
    s32 func_00201C60();
    u16 temp_v0;

    temp_v0 = (*(u16 *)((u8 *)(reg_a4) + (6)));
    if (temp_v0 != 0) {
        (*(u16 *)((u8 *)(reg_a4) + (6))) = (u16) (temp_v0 - 1);
        if ((*(u16 *)((u8 *)(reg_a4) + (6))) == 0) {
            func_0018D2D0();
            reg_d0.w = 3;
            func_00124F50();
            reg_d0.w = 4;
            func_00124F50();
            reg_d0.w = 0xA;
            func_00124DC0();
            reg_d0.w = 0xE;
            func_00124DC0();
            (*(s16 *)((u8 *)(reg_a6) + (0x172))) = 0x1000;
            func_001F56F0();
            func_001F57C0();
            goto block_3;
        }
    } else {
block_3:
        func_00201C60();
        if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
            (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
                (*(u8 *)((u8 *)(reg_a4) + (4))) -= 1;
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 1;
                if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 8) {
                    (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x303;
                    (*(u16 *)((u8 *)(reg_a4) + (2))) = 1U;
                }
            }
        } else {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
            (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
                if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 4) {
                    reg_d0.w = 2;
                    func_00124D90();
                    (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
                }
            }
        }
    }
    func_001F3A10();
}

s32 func_00201160();

void func_001F3EC0() {
    reg_d0.w = 0;
    (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0))) = (u8) reg_d0.b[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 4;
    func_00201160();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d0.b[0];
    func_001F3F10();
}

s32 func_002010A0();
s32 func_002024C0();

void func_001F3F10(void) {
    s32 func_00201C60();
    func_00201C60();
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) != 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
        func_002024C0();
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) == reg_d1.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0))) = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3C00) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= 0x4C00) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x6000) {
        if ((s32) reg_d1.h[0] >= 0x6800) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0))) = 1U;
    }
    func_001F3A10();
}


void func_001F4030(void) {
    reg_a6[0x1B] = 3;
    reg_a6[0x1A] = 0x20;
    func_001F4050(3);
}

void func_001F4050() {
    void func_00201C60(void);
    func_00201C60();
}

extern void *reg_a4_as_void_p;
extern void *reg_a6_as_void_p;

void func_001F4060(void) {
    u8 val;

    reg_d0.w = 0;
    val = reg_d0.b[0];
    *((u8 *)reg_a4_as_void_p + 1) = reg_d0.b[0];
    val = reg_d0.b[0];
    *((u8 *)reg_a4_as_void_p + 0) = reg_d0.b[0];
    *((u8 *)reg_a6_as_void_p + 0x1B) = 6;
    func_001F4090(val);
}

void func_001F4090() {
    s32 func_00201C60();
    func_00201C60();
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) != 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
        func_002024C0();
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) == reg_d1.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0))) = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x3600, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x5200, 0x5600)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5E00) {
        if ((s32) reg_d1.h[0] >= 0x6200) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0))) = 1U;
    }
    func_001F3A10();
}


void func_001F41B0() {
    reg_d0.w = 0;
    (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0))) = (u8) reg_d0.b[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 8;
    func_00201160();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d0.b[0];
    func_001F4200();
}

void func_001F4200(void) {
    s32 func_00201C60();
    func_00201C60();
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) != 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
        func_002024C0();
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) == reg_d1.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0))) = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3800) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= 0x5000) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x6400) {
        if ((s32) reg_d1.h[0] >= 0x6C00) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0))) = 1U;
    }
    func_001F3A10();
}


void func_001F4320() {
    reg_d0.w = 0;
    (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0))) = (u8) reg_d0.b[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 6;
    func_00201160();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d0.b[0];
    func_001F4370();
}

void func_001F4370(void) {
    s32 func_00201C60();
    func_00201C60();
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) != 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
        func_002024C0();
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) == reg_d1.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0))) = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x4000) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= 0x4800) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5400) {
        if ((s32) reg_d1.h[0] >= 0x5C00) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0))) = 1U;
    }
    func_001F3A10();
}

s32 func_002010A0();                            /* extern */

void func_001F4490(void) {
    reg_d0.w = 0;
    (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0))) = (u8) reg_d0.b[0];
    func_002010A0();
    reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d0.b[0];
    func_001F44E0();
}

void func_001F44E0(void) {
    s32 func_00201C60();
    func_00201C60();
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) != 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
        func_002024C0();
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) == reg_d1.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0))) = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x4200) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= 0x4600) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x7B80) {
        if ((s32) reg_d1.h[0] >= 0x7C80) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0))) = 1U;
    }
    func_001F3A10();
}


void func_001F4600(void) {
    u8 value;

    reg_d0.w = 0;
    reg_a4[1] = reg_d0.b[0];
    value = reg_d0.b[0];
    reg_a4[0] = value;
    reg_a6[0x1B] = 2;
    func_001F4630(value);
}

void func_001F4630() {
    s32 func_00201C60();
    func_00201C60();
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) != 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
        func_002024C0();
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) == reg_d1.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0))) = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x4000, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x4800, 0x5200)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5200) {
        if ((s32) reg_d1.h[0] >= 0x5600) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0))) = 1U;
    }
    func_001F3A10();
}


void func_001F4750(void) {
    reg_d0.w = 0;
    reg_a4[1] = reg_d0.b[0];
    reg_a4[0] = reg_d0.b[0];
    func_001F4770();
}

void func_001F4770(void) {
    s32 func_00201C60();
    func_00201C60();
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) != 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
        func_002024C0();
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) == reg_d1.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0))) = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x4000, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x4800, 0x5200)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x6200) {
        if ((s32) reg_d1.h[0] >= 0x6600) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0))) = 1U;
    }
    func_001F3A10();
}


u8 func_001F4890(void) {
    u8 zero_byte;

    reg_d0.w = 0;
    zero_byte = reg_d0.b[0];
    reg_a4[1] = reg_d0.b[0];
    zero_byte = reg_d0.b[0];
    reg_a4[0] = reg_d0.b[0];
    reg_a6[0x1B] = 4;
    return func_001F48C0(zero_byte);
}

u8 func_001F48C0(u8 arg0) {
    s32 func_00201C60();
    func_00201C60();
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) != 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
        func_002024C0();
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) == reg_d1.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0))) = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x3600, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x5200, 0x5600)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5E00) {
        if ((s32) reg_d1.h[0] >= 0x6200) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0))) = 1U;
    }
    func_001F3A10();
}


void func_001F49E0() {
    reg_d0.w = 0;
    (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0))) = (u8) reg_d0.b[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 4;
    func_00201160();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d0.b[0];
    func_001F4A30();
}

void func_001F4A30(void) {
    s32 func_00201C60();
    func_00201C60();
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) != 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
        func_002024C0();
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) == reg_d1.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0))) = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x4000, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x4800, 0x5200)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x4800) {
        if ((s32) reg_d1.h[0] >= 0x5000) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0))) = 1U;
    }
    func_001F3A10();
}
