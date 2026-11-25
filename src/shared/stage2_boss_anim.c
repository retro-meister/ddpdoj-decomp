#include "common.h"
#include "entity.h"

void func_001E6C00(void);
void func_001E6D00(void);
void func_001E6DF0(void);
void func_001E6EF0(void);
void func_001E70A0(void);
void func_001E7130(void);
void func_001E71D0(void);
void func_001E7320(void);
void func_001E73A0(void);
void func_001E7420(void);
void func_001E7520(void);
void func_001E75C0(void);


void func_001E6BE0(void) {
    *(s16 *)((u8 *)((void *)reg_a6) + 0x26) = 2;
    *(s16 *)((u8 *)((void *)reg_a6) + 0x28) = 0;
    func_001E6C00();
}


void func_001E6C00(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x27);
    *(u8 *)(reg_a6 + 0x27) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a6 + 0x27) = (u8) *(u8 *)(reg_a6 + 0x26);
        *(u16 *)(reg_a6 + 0x28) += 4;
        if (*(u16 *)(reg_a6 + 0x28) == 0x20) {
            *(u16 *)(reg_a6 + 0x28) = 0U;
        }
    }
}

extern void rng_next_masked(void);

void func_001E6C70(void)
{
    extern void rng_next_bit(void);
    *(u16 *)((u8 *)((void *)reg_a4) + 4) = 0;
    rng_next_bit();
    ((u8 *)((void *)reg_a4))[4] = reg_d0.b[0];
    rng_next_masked();
    ((u8 *)((void *)reg_a4))[2] = reg_d0.b[0];
    rng_next_masked();
    *(u16 *)((u8 *)((void *)reg_a4) + 6) = reg_d0.h[0];
    ((u8 *)((void *)reg_a4))[3] = 0;
}


void func_001E6CD0(void) {
    func_001E6C70();
    func_001E6D00();
}

s32 direction_turn_toward();

void func_001E6D00() {
    u8 temp_a0;
    u8 temp_a0_2;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u16 *)(reg_a4 + 6) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 6) < 0) {
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            reg_d0.w = 0;
            reg_d1.w = 0;
            reg_d0.b[0] = *(u8 *)(reg_a6 + 0x11A);
            reg_d1.b[0] = *(u8 *)(reg_a4 + 2);
            direction_turn_toward();
            *(u8 *)(reg_a6 + 0x11A) = (u8) reg_d1.b[0];
            temp_a0_2 = *(u8 *)(reg_a4 + 2);
            if (temp_a0_2 == reg_d1.b[0]) {
                func_001E6C70();
            }
        }
    }
}



void func_001E6DD0(void) {
    *(s16 *)(reg_a4 + 2) = 3;
    *(s16 *)(reg_a4 + 4) = 0;
    func_001E6DF0();
}


extern u8 D_0026C0A0[];

void func_001E6DF0(void) {
    reg_tmp.b[0] = (*(u8 *)(reg_a4 + 3));
    (*(u8 *)(reg_a4 + 3)) -= 1;
    if ((s32)reg_tmp.b[0] <= 0) {
        (*(u8 *)(reg_a4 + 3)) = (*(u8 *)(reg_a4 + 2));
        reg_a0 = D_0026C0A0;
        reg_a0 += (*(u16 *)(reg_a4 + 4));
        (ENTITY(reg_a6)->offset_y.h) = *(u16 *)reg_a0;
        (*(u16 *)(reg_a4 + 4)) += 2;
        if ((*(u16 *)(reg_a4 + 4)) == 0xC) {
            (*(u16 *)(reg_a4 + 4)) = 0;
        }
    }
}


void func_001E6E90(void) {
    s32 rng_next_bit();
    *(s16 *)(reg_a4 + 4) = 0;
    *(u8 *)(reg_a4 + 7) = 1U;
    rng_next_bit();
    if (reg_d0.h[0] != 0) {
        func_001E6EF0();
        return;
    }
    *(u8 *)(reg_a4 + 7) *= -1;
    func_001E6EF0();
}

void func_001E6EF0(void) {
    reg_d0.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a6 + 0x11A) += reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x11A) &= 0x3F;
}

s32 aim_at_player();                            /* extern */
s32 direction_turn_toward();                            /* extern */

void func_001E6F30(void) {
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x82);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x84);
    aim_at_player();
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x9A);
    direction_turn_toward();
    *(u8 *)(reg_a6 + 0x9A) = (u8) reg_d1.b[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0xA2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xA4);
    aim_at_player();
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0xBA);
    direction_turn_toward();
    *(u8 *)(reg_a6 + 0xBA) = (u8) reg_d1.b[0];
}

s32 aim_at_player();                            /* extern */
s32 direction_turn_toward();                            /* extern */

void func_001E6FC0(void) {
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x82);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x84);
    aim_at_player();
    reg_d0.w = 0;
    reg_d1.b[0] += 0x14;
    reg_d1.b[0] &= 0x3F;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x9A);
    direction_turn_toward();
    *(u8 *)(reg_a6 + 0x9A) = (u8) reg_d1.b[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0xA2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xA4);
    aim_at_player();
    reg_d0.w = 0;
    reg_d1.b[0] += 0x2C;
    reg_d1.b[0] &= 0x3F;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0xBA);
    direction_turn_toward();
    *(u8 *)(reg_a6 + 0xBA) = (u8) reg_d1.b[0];
}


void func_001E7080(void) {
    *(u16 *)((u8 *)((void *)reg_a4) + 2) = 2;
    *(u16 *)((u8 *)((void *)reg_a4) + 4) = 0;
    func_001E70A0();
}

void func_001E70A0(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)->offset_y.h += 4;
        if (ENTITY(reg_a6)->offset_y.h == 0x1C) {
            *(s16 *)reg_a4 = 0;
        }
    }
}



void func_001E7110(void) {
    *(u16 *)(reg_a4 + 2) = 0x2002;
    *(u16 *)(reg_a4 + 4) = 0;
    func_001E7130();
}

s32 boss_animation_start();

void func_001E7130() {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)->offset_y.h -= 4;
        if (ENTITY(reg_a6)->offset_y.h == 0) {
            *(s16 *)reg_a4 = 0;
            reg_d0.w = 2;
            boss_animation_start();
        }
    }
}


void func_001E71B0(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    *(u16 *)(reg_a4 + 4) = 4;
    *(u8 *)(reg_a4 + 7) = 0;
    func_001E71D0();
}

void func_001E71D0(void) {
    if (*(u8 *)(reg_a4 + 7) == 1) {
        *(u16 *)(reg_a6 + 0x168) -= 0x20;
        if (0 > (s16) *(u16 *)(reg_a6 + 0x168)) {
            *(u16 *)(reg_a6 + 0x168) = 0U;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u16 *)(reg_a6 + 0x166) += 4;
            if (*(u16 *)(reg_a6 + 0x166) == 0x40) {
                *(u16 *)(reg_a6 + 0x166) = 0U;
                *(u16 *)(reg_a6 + 0x168) = 0U;
                *(s16 *)reg_a4 = 0;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 7) == 0) {
        *(u16 *)(reg_a6 + 0x168) += 0x100;
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            *(u16 *)(reg_a6 + 0x166) += 0x10;
            if (*(u16 *)(reg_a6 + 0x166) == 0x20) {
                *(u8 *)(reg_a4 + 7) = 1U;
                *(u16 *)(reg_a4 + 4) = 0;
            }
        }
    }
}


void func_001E7310(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    func_001E7320();
}

void func_001E7320(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0x166) += 4;
        if ((s16) *(u16 *)(reg_a6 + 0x166) >= 0x20) {
            *(u16 *)(reg_a6 + 0x166) = 0x20U;
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001E7390(void) {
    *(u16 *)(reg_a4 + 2) = 1;
    func_001E73A0();
}

void func_001E73A0(void)
{
    s16 *remaining;

    reg_tmp.b[0] = reg_a4[3];
    reg_a4[3] -= 1;
    if ((s32)(u8)reg_tmp.b[0] <= 0) {
        reg_a4[3] = reg_a4[2];
        *(u16 *)(reg_a6 + 0x166) -= 4;
        remaining = (s16 *)(reg_a6 + 0x166);
        if (0 < *remaining) {
            return;
        }
        *remaining = 0;
        *(u16 *)reg_a4 = 0;
    }
}


void func_001E7410(void) {
    ((u16 *)reg_a4)[1] = 0x202;
    func_001E7420();
}

void func_001E7420(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0x16A) += 4;
        if ((s16) *(u16 *)(reg_a6 + 0x16A) >= 0x38) {
            *(u16 *)(reg_a6 + 0x16A) = 0U;
        }
    }
}

s32 rng_next_unsigned();

void func_001E7490(void) {
    *(s16 *)(reg_a4 + 2) = 0x101;
    rng_next_unsigned();
    reg_d0.h[0] &= 0xF;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xC6) = (u16) reg_d0.h[0];
    rng_next_unsigned();
    reg_d0.h[0] &= 0xF;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xE6) = (u16) reg_d0.h[0];
    func_001E7520();
}

void func_001E7520(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0xC6) += 4;
        *(u16 *)(reg_a6 + 0xC6) &= 0x3F;
        *(u16 *)(reg_a6 + 0xE6) += 4;
        *(u16 *)(reg_a6 + 0xE6) &= 0x3F;
    }
}


void func_001E75A0(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    *(u16 *)(reg_a4 + 4) = 0;
    func_001E75C0();
}

s32 func_0014E030();
extern u8 D_0026C0B0[];

void func_001E75C0(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_d0.w = 0x4D;
        func_0014E030();
        reg_d0.h[1] = *(u16 *)(reg_a6 + 0x22);
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
        reg_a1 = D_0026C0B0;
        reg_a1 += *(u16 *)(reg_a4 + 4);
        reg_tmp.h[1] = *(u16 *)reg_a1;
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        reg_d0.w += reg_tmp.w;
        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
        *(u16 *)(reg_a4 + 4) += 4;
        *(u16 *)(reg_a4 + 4) &= 0xF;
    }
}
