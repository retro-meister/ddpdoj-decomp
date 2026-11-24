#include "common.h"
#include "entity.h"

void func_0011DE20(void);
void func_0011DF10(void);
void func_0011E000(void);
void func_0011E0F0(void);
void func_0011E1E0(void);
void func_0011E2D0(void);
void func_0011E3C0(void);
void func_0011E4B0(void);
void func_0011E5A0(void);
void func_0011E690(void);
void func_0011E780(void);
void func_0011E870(void);
void func_0011E960(void);
void func_0011EA50(void);
void func_0011EB40(void);
void func_0011EC90(void);
void func_0011ED80(void);
void func_0011EE70(void);
void func_0011EF60(void);
void func_0011F020(void);
void func_0011F110(void);
void func_0011F200(void);
void func_0011F2F0(void);


void func_0011DDC0(void) {
    reg_tmp.w = 0x1CBF;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x38A0;
    reg_tmp.w = (u32) (u32)func_0011DE20;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

s32 func_00171330(s32 *);
s32 entity_release();
s32 entity_follow_scroll();
extern u8 D_0028E290;
extern u8 D_0028E2C8;
extern u8 D_0028ED80;
extern void func_0019C4B0();

void func_0011DE20(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011DEB0(void) {
    reg_tmp.w = 0x1CC0;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x3920;
    reg_tmp.w = (u32) (u32)func_0011DF10;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011DF10(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011DFA0(void) {
    reg_tmp.w = 0x1CC1;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x3920;
    reg_tmp.w = (u32) (u32)func_0011E000;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011E000(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011E090(void) {
    reg_tmp.w = 0x1CC2;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x1040;
    reg_tmp.w = (u32) (u32)func_0011E0F0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011E0F0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x1FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011E180(void) {
    reg_tmp.w = 0x1CC3;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x3920;
    reg_tmp.w = (u32) (u32)func_0011E1E0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011E1E0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011E270(void) {
    reg_tmp.w = 0x1CC4;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x3920;
    reg_tmp.w = (u32) (u32)func_0011E2D0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011E2D0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011E360(void) {
    reg_tmp.w = 0x1CC5;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x3920;
    reg_tmp.w = (u32) (u32)func_0011E3C0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011E3C0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011E450(void) {
    reg_tmp.w = 0x1CC6;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x1720;
    reg_tmp.w = (u32) (u32)func_0011E4B0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011E4B0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x2BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011E540(void) {
    reg_tmp.w = 0x1CC7;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x3890;
    reg_tmp.w = (u32) (u32)func_0011E5A0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011E5A0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011E630(void) {
    reg_tmp.w = 0x1CC8;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x3920;
    reg_tmp.w = (u32) (u32)func_0011E690;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011E690(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011E720(void) {
    reg_tmp.w = 0x1CC9;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x3920;
    reg_tmp.w = (u32) (u32)func_0011E780;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011E780(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011E810(void) {
    reg_tmp.w = 0x1CCA;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x3920;
    reg_tmp.w = (u32) (u32)func_0011E870;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011E870(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011E900(void) {
    reg_tmp.w = 0x1CCB;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x3920;
    reg_tmp.w = (u32) (u32)func_0011E960;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011E960(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011E9F0(void) {
    reg_tmp.w = 0x1CCC;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x1E70;
    reg_tmp.w = (u32) (u32)func_0011EA50;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011EA50(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x3BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011EAE0(void) {
    reg_tmp.w = 0x1D84;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x3520;
    reg_tmp.w = (u32) (u32)func_0011EB40;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

extern void func_0019C4F0();

void func_0011EB40(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6800) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4F0);
}

void func_0011EBD0(void) {
    reg_tmp.w = 0x1D84;
    ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->hit_x_plus.sh = 0x3520;
    reg_tmp.w = (u32) (u32)func_0011EB40;
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->sprite.sh = 0x56;
}


void func_0011EC30(void) {
    reg_tmp.w = 0x1DBE;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0xF20;
    reg_tmp.w = (u32) (u32)func_0011EC90;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x17;
}

void func_0011EC90(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x1C00) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4F0);
}


void func_0011ED20(void) {
    reg_tmp.w = 0x1DBF;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0xF20;
    reg_tmp.w = (u32) (u32)func_0011ED80;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011ED80(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x1C00) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4F0);
}


void func_0011EE10(void) {
    reg_tmp.w = 0x1DC0;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0xF20;
    reg_tmp.w = (u32) (u32)func_0011EE70;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x17;
}

void func_0011EE70(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x1C00) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4F0);
}


void func_0011EF00(void) {
    reg_tmp.w = 0x1DC1;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0xF20;
    reg_tmp.w = (u32) (u32)func_0011EF60;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x17;
}

void func_0011EF60(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x1C00) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4F0);
}


void func_0011EFC0(void) {
    reg_tmp.w = 0x1DBD;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x2F20;
    reg_tmp.w = (u32) (u32)func_0011F020;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011F020(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x5C00) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4F0);
}


void func_0011F0B0(void) {
    reg_tmp.w = 0x1F1F;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x1EA0;
    reg_tmp.w = (u32) (u32)func_0011F110;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x17;
}

void func_0011F110(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x3C00) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011F1A0(void) {
    reg_tmp.w = 0x1F20;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x2920;
    reg_tmp.w = (u32) (u32)func_0011F200;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x17;
}

void func_0011F200(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x5000) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}


void func_0011F290(void) {
    reg_tmp.w = 0x1F21;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x1250;
    reg_tmp.w = (u32) (u32)func_0011F2F0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x17;
}

void func_0011F2F0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x2400) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)func_0019C4B0);
}

extern void func_0011F3E0(void);

void func_0011F380(void) {
    reg_tmp.w = 0x1F5E;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x1B20;
    reg_tmp.w = (u32) (u32)func_0011F3E0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x17;
}
