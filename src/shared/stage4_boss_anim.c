#include "common.h"
#include "entity.h"

void func_001D7320(void);
void func_001D73A0(void);
void func_001D7420(void);
void func_001D74B0(void);
void func_001D7540(void);
void func_001D75D0(void);
void func_001D7660(void);
void func_001D76F0(void);
void func_001D7780(void);
void func_001D77F0(void);

extern s16 *reg_a4_as_s16_p;

void func_001D71C0(void) {
    *reg_a4_as_s16_p = 0;
}

s32 boss_part_show();                            /* extern */
s32 boss_part_hide();                            /* extern */

void func_001D71D0(void) {
    ENTITY(reg_a6)[8].offset_y.sh = 0;
    reg_d0.w = 0;
    boss_part_hide();
    reg_d0.w = 6;
    boss_part_show();
    *(s16 *)(reg_a4 + 2) = 0x202;
}

s32 boss_part_show();
s32 boss_part_hide();
s32 func_001E8710();
s32 func_001E8730();

void func_001D7210() {
    u16 temp_a0;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[8].offset_y.h += 4;
        temp_a0 = ENTITY(reg_a6)[8].offset_y.h;
        if (temp_a0 == 0x3C) {
            ENTITY(reg_a6)[8].offset_y.h = 0U;
            reg_d0.w = 6;
            boss_part_hide();
            reg_d0.w = 9;
            boss_part_show();
            reg_d0.w = 7;
            boss_part_show();
            reg_d0.w = 8;
            boss_part_show();
            ENTITY(reg_a6)[1].hit_y_plus.sh = 0xC00;
            ENTITY(reg_a6)[1].hit_y_minus.sh = 0xD80;
            ENTITY(reg_a6)[1].hit_x_plus.sh = 0x900;
            ENTITY(reg_a6)[1].hit_x_minus.sh = 0x900;
            reg_d0.h[0] = 0x80;
            func_001E8730();
            reg_d0.h[0] = 0xA0;
            func_001E8730();
            func_001E8710();
            func_001D71C0();
        }
    }
}


void func_001D7310(void) {
    *(s16 *)(reg_a4 + 2) = 0x202;
    func_001D7320();
}

void func_001D7320() {
    u16 temp_a0;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[3].offset_y.h += 4;
        temp_a0 = ENTITY(reg_a6)[3].offset_y.h;
        if (temp_a0 == 0x1C) {
            func_001D71C0();
        }
    }
}


void func_001D7390(void) {
    *(u16 *)(reg_a4 + 2) = 0x202;
    func_001D73A0();
}

void func_001D73A0() {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[3].offset_y.h -= 4;
        if (ENTITY(reg_a6)[3].offset_y.h == 0) {
            func_001D71C0();
        }
    }
}


void func_001D7410(void) {
    *(u16 *)(reg_a4 + 2) = 1;
    func_001D7420();
}

void func_001D7420() {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[8].offset_y.h += 4;
        if ((s16) ENTITY(reg_a6)[8].offset_y.h >= 0x3C) {
            ENTITY(reg_a6)[8].offset_y.h = 0x3CU;
            func_001D71C0();
        }
    }
}


void func_001D74A0(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    func_001D74B0();
}


void func_001D74B0(void)
{
    s32 remainingIsPositive;

    reg_tmp.b[0] = reg_a4[3];
    reg_a4[3] -= 1;

    if ((s32)reg_tmp.b[0] <= 0) {
        reg_a4[3] = reg_a4[2];
        ENTITY(reg_a6)[8].offset_y.h -= 4;

        remainingIsPositive = 0 < ENTITY(reg_a6)[8].offset_y.sh;
        if (remainingIsPositive == 0) {
            ENTITY(reg_a6)[8].offset_y.h = 0;
            func_001D71C0();
        }
    }
}


void func_001D7530(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    func_001D7540();
}

void func_001D7540() {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[4].offset_x.h += 4;
        if ((s16) ENTITY(reg_a6)[4].offset_x.h >= 0x20) {
            ENTITY(reg_a6)[4].offset_x.h = 0x20U;
            func_001D71C0();
        }
    }
}


void func_001D75C0(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    func_001D75D0();
}

void func_001D75D0(void)
{
    reg_tmp.b[0] = reg_a4[3];
    reg_a4[3]--;

    if ((s32)reg_tmp.b[0] <= 0) {
        reg_a4[3] = reg_a4[2];
        ENTITY(reg_a6)[4].offset_x.h -= 4;

        if (0 < ENTITY(reg_a6)[4].offset_x.sh) {
            return;
        }

        ENTITY(reg_a6)[4].offset_x.h = 0;
        func_001D71C0();
    }
}


void func_001D7650(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    func_001D7660();
}

void func_001D7660() {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[5].offset_x.h += 4;
        if ((s16) ENTITY(reg_a6)[5].offset_x.h >= 0x20) {
            ENTITY(reg_a6)[5].offset_x.h = 0x20U;
            func_001D71C0();
        }
    }
}


void func_001D76E0(void) {
    *(u16 *)(reg_a4 + 2) = 1;
    func_001D76F0();
}

void func_001D76F0(void)
{
    reg_tmp.b[0] = reg_a4[3];
    reg_a4[3] -= 1;
    if ((s32)reg_tmp.b[0] <= 0) {
        s16 *remaining;

        reg_a4[3] = reg_a4[2];
        ENTITY(reg_a6)[5].offset_x.h -= 4;
        remaining = (s16 *)(reg_a6 + 0xA8);
        if (0 < *remaining) {
            return;
        }
        *remaining = 0;
        func_001D71C0();
    }
}


void func_001D7770(void) {
    func_001D7780();
}

s32 aim_at_player();                            /* extern */
s32 direction_turn_toward();                            /* extern */

void func_001D7780(void) {
    reg_d0.h[0] = ENTITY(reg_a6)[8].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[8].x.h;
    aim_at_player();
    if (cond_flag == 0) {
        reg_d0.b[0] = ENTITY(reg_a6)[8].move.b.dir;
        direction_turn_toward();
        ENTITY(reg_a6)[8].move.b.dir = (u8) reg_d1.b[0];
    }
}


void func_001D77E0(void) {
    func_001D77F0();
}

void func_001D77F0(void) {
    ENTITY(reg_a6)[1].offset_y.h += 4;
    ENTITY(reg_a6)[1].offset_y.h &= 0x1F;
    ENTITY(reg_a6)[2].offset_y.h += 4;
    ENTITY(reg_a6)[2].offset_y.h &= 0x1F;
    ENTITY(reg_a6)[4].offset_y.h += 4;
    ENTITY(reg_a6)[4].offset_y.h &= 0x1F;
    ENTITY(reg_a6)[5].offset_y.h += 4;
    ENTITY(reg_a6)[5].offset_y.h &= 0x1F;
}
