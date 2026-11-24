#include "common.h"

void func_001A9370(void);
void func_001A95B0(void);
void func_001A97F0(void);
void func_001A9820(void);
void func_001A99C0(void);
void func_001A9D80(void);
void func_001AA0D0(void);
void func_001AA160(void);
void func_001AA1C0(void);
void func_001AA210(void);
void func_001AA2E0(void);
void func_001AA330();
void func_001AA380(void);
void func_001AA6D0(void);
void func_001AA730(void);
void func_001AA780(void);
void func_001AA850(void);
void func_001AA8A0();
void func_001AAB90(void);
void func_001ABF90(void);
void func_001AC160(void);
void func_001AC950(void);
void func_001AC9D0(void);

extern u16 *reg_a0_as_u16_p;

void func_001A8FC0(void) {
    s32 func_001AE9A0(Reg32 *, Reg32 *);
    reg_d0.w = 1;
    reg_d2.w = (u32) *reg_a0_as_u16_p;
    func_001AE9A0(&reg_d0, &reg_d2);
    *reg_a0_as_u16_p = reg_d2.h[0];
}

extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u8 D_0028E71C_as_u8;
extern u8 D_0028E720;
extern u8 D_0028E855;
extern u16 D_0029CEA0[];

void func_001A9000(void) {
    if (!(*(u8 *)(reg_a6 + 1) & 2)) {
        if ((D_0028E855 & 4) && (reg_d2.h[0] = D_0029CEA0[0], ((s16) reg_d2.h[0] < 0)) && (reg_d2.w & 1) && (reg_d0.w = 1, ((s8) reg_d2.b[0] >= 0))) {
            if (reg_d1.w & 0x10) {
                reg_d0.h[0] += D_0028E5FC;
                func_001AA0D0();
                goto block_7;
            }
        } else {
block_7:
            if (reg_d1.w & 0x10) {
                reg_d0.w = 1;
                reg_d0.h[0] += D_0028E5FC;
                if (reg_d1.w & 4) {
                    func_001A9D80();
                } else {
                    reg_a0 = &D_0028E720;
                    func_001A97F0();
                }
            }
        }
        if (reg_d1.w & 8) {
            reg_d0.w = 1;
            reg_d0.h[0] += D_0028E5F8;
            switch (reg_d1.w & 4) { case 0: break; default:
                func_001AA380();
                return;
            }
            reg_a0 = &D_0028E71C_as_u8;
            func_001A97F0();
        }
    }
}

extern s32 D_0028E71C;
extern s32 D_0028E720_as_s32;
extern s32 *reg_a0_as_s32_p;

void func_001A9130(void) {
    if (reg_d1.w & 0x10) {
        reg_a0_as_s32_p = &D_0028E720_as_s32;
        func_001A97F0();
    }
    if (reg_d1.w & 8) {
        reg_a0_as_s32_p = &D_0028E71C;
        func_001A97F0();
    }
}

extern void *reg_a0_as_void_p;


void func_001A9180(void) {
    reg_a0_as_void_p = &D_0028E720;
    func_001A97F0();
}

void func_001A9190(void) {
    reg_a0_as_void_p = &D_0028E71C;
    func_001A97F0();
}

extern u16 D_0028DAD8[];
extern u16 D_0028E5CC;
extern u16 D_0028E5D0;
extern u32 D_0028E66C_as_u32;
extern u32 D_0028E6AC_as_u32;
extern u16 D_0028E6DC;
extern u16 D_0028E910;

void func_001A91A0(void) {
    u32 temp_s0;
    u32 temp_s0_2;
    u32 temp_s1;
    u32 temp_s1_2;

    reg_d2.h[0] = D_0028E910;
    reg_a0 = (u8 *)(D_0028DAD8);
    reg_d2.h[0] += reg_d2.h[0];
    D_0028E6DC = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    if (reg_d1.w & 0x10) {
        func_001A9370();
        if (D_0028E5FC != 0) {
            reg_d2.h[0] = D_0028E5D0;
            reg_d2.h[0] -= 1;
            do {
                temp_s1 = reg_d2.w;
                reg_d0.w = D_0028E6AC_as_u32;
                temp_s0 = reg_d0.w;
                reg_d0.w >>= 4;
                D_0028E6AC_as_u32 = reg_d0.w;
                reg_d0.w = 0;
                func_001A9370();
                reg_d0.w = 0;
                func_001A9180();
                reg_d0.w = 0;
                func_001A9180();
                reg_d0.w = 0;
                func_001A9180();
                reg_d0.w = 0;
                func_001A9180();
                reg_d2.w = temp_s1;
                D_0028E6AC_as_u32 = temp_s0;
            } while ((s16)(--reg_d2.h[0]) >= 0);
        }
    }
    if (reg_d1.w & 8) {
        func_001A95B0();
        if (D_0028E5F8 != 0) {
            reg_d2.h[0] = D_0028E5CC;
            reg_d2.h[0] -= 1;
            do {
                temp_s0_2 = reg_d2.w;
                reg_d0.w = D_0028E66C_as_u32;
                temp_s1_2 = reg_d0.w;
                reg_d0.w >>= 4;
                D_0028E66C_as_u32 = reg_d0.w;
                reg_d0.w = 0;
                func_001A95B0();
                reg_d0.w = 0;
                func_001A9190();
                reg_d0.w = 0;
                func_001A9190();
                reg_d0.w = 0;
                func_001A9190();
                reg_d0.w = 0;
                func_001A9190();
                reg_d2.w = temp_s0_2;
                D_0028E66C_as_u32 = temp_s1_2;
            } while ((s16)(--reg_d2.h[0]) >= 0);
        }
    }
}

extern u16 D_0028DADC[];
extern u16 D_0028E614;
extern u16 D_0028E694;
extern s16 D_0028E698_as_s16;
extern u16 D_0028E69C;
extern u16 D_0028E6A0;
extern u32 D_0028E6A4_as_u32;
extern u32 D_0028E6A8_as_u32;
extern u16 D_0028E6B0;
extern u16 D_0028E6B4;
extern s16 D_0028E6B8;
extern u16 D_0028E6BC;
extern u16 D_0028E6C0;
extern s16 D_0028E6C4;
extern u16 D_0028E6C8;
extern u32 D_0028E6CC_as_u32;
extern u32 D_0028E6D0_as_u32;
extern u16 D_0028E6E4;
extern u16 D_0028E720_as_u16;
extern u8 D_0028E854;
extern u16 D_0029F2B8[];

void func_001A9370(void) {
    reg_d3.w = reg_d0.w;
    reg_d2.h[0] = D_0029F2B8[0];
    reg_a0 = (u8 *)D_0028DADC;
    D_0028E694 = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = D_0029CEA0[0];
    if ((s16) reg_d2.h[0] >= 0) {
        goto next_1;
    }
    if (reg_d2.w & 0x80) {
        goto next_1;
    }
    if (D_0028E6E4 == 0) {
        goto block_11;
    }
next_1:
    if (D_0028E854 & 1) {
        goto block_12;
    }
    D_0028E698_as_s16 = 0x1E;
    if (D_0028E5FC != 0) {
        D_0028E698_as_s16 = 1;
    }
    if (D_0028E6C8 != 0) {
        goto next_2;
    }
    func_001A9820();
block_11:
    D_0028E6A0 = 0;
block_12:
    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)&D_0028E720_as_u16;
    func_001A97F0();
    D_0028E6D0_as_u32 = reg_d3.w;
    D_0028E6CC_as_u32 = reg_d3.w;
    if (D_0028E6A4_as_u32 == 0) {
        D_0028E6C4 = 0x50;
    }
    reg_d2.w = 0;
    D_0028E6AC_as_u32 = reg_d2.w;
    D_0028E6A8_as_u32 = reg_d2.w;
    D_0028E6C0 = reg_d2.h[0];
    goto block_end;
next_2:
    if (D_0028E6D0_as_u32 != 0) {
        reg_d0.w = D_0028E6D0_as_u32;
        D_0028E6A0 = 1;
        D_0028E6AC_as_u32 = reg_d0.w;
        D_0028E6A8_as_u32 = reg_d0.w;
        reg_d0.w = 0;
        D_0028E6D0_as_u32 = reg_d0.w;
    }
    reg_a0 = (u8 *)&D_0028E6A0;
    func_001A8FC0();
    reg_d0.h[0] = D_0028E614;
    if ((s32) D_0028E6A0 > (s32) reg_d0.h[0]) {
        D_0028E614 = D_0028E6A0;
    }
    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)&D_0028E6B0;
    func_001A97F0();
    reg_d0.w = D_0028E6AC_as_u32;
    reg_a0 = (u8 *)&D_0028E6AC_as_u32;
    func_001A97F0();
    func_001A9820();
    reg_d0.w = D_0028E6AC_as_u32;
    reg_a0 = (u8 *)&D_0028E720_as_u16;
    func_001A97F0();
    if ((s32) D_0028E6A0 < 0x10) {
        if ((s32) D_0028E6A0 > 1) {
            D_0028E6C0 = 0x78;
        }
        D_0028E6BC = D_0028E6C8;
        if (D_0028E6A4_as_u32 == 0) {
            D_0028E6C4 = 0xB4;
        }
        goto block_end;
    }
    if (D_0028E6A0 == 0x10) {
        D_0028E6B0 = 0;
        D_0028E6C0 = 0;
    }
    D_0028E69C = D_0028E6A0;
    D_0028E6B8 = 0xF0;
    D_0028E6C4 = 0xF0;
    D_0028E6B4 = D_0028E6C8;
    D_0028E6A4_as_u32 = D_0028E6A8_as_u32;
block_end:
    reg_d0.w = reg_d3.w;
}

extern u16 D_0028E610;
extern s16 D_0028E658_as_s16;
extern u16 D_0028E65C;
extern u16 D_0028E660;
extern u32 D_0028E664_as_u32;
extern u32 D_0028E668_as_u32;
extern u16 D_0028E670;
extern u16 D_0028E674;
extern s16 D_0028E678;
extern u16 D_0028E67C;
extern u16 D_0028E680;
extern s16 D_0028E684;
extern u16 D_0028E688;
extern u32 D_0028E68C_as_u32;
extern u32 D_0028E690_as_u32;
extern u16 D_0028E6E0;
extern u16 D_0028E71C_as_u16;
extern u16 D_0029F248[];

void func_001A95B0(void) {
    reg_d3.w = reg_d0.w;
    reg_d2.h[0] = D_0029F248[0];
    reg_a0 = (u8 *)D_0028DADC;
    D_0028E694 = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = D_0029CEA0[0];
    if ((s16) reg_d2.h[0] >= 0) {
        goto next_1;
    }
    if (!(reg_d2.w & 0x80)) {
        goto next_1;
    }
    if (D_0028E6E0 == 0) {
        goto block_11;
    }
next_1:
    if (D_0028E854 & 1) {
        goto block_12;
    }
    D_0028E658_as_s16 = 0x1E;
    if (D_0028E5F8 != 0) {
        D_0028E658_as_s16 = 1;
    }
    if (D_0028E688 != 0) {
        goto next_2;
    }
    func_001A99C0();
block_11:
    D_0028E660 = 0;
block_12:
    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)&D_0028E71C_as_u16;
    func_001A97F0();
    D_0028E690_as_u32 = reg_d3.w;
    D_0028E68C_as_u32 = reg_d3.w;
    if (D_0028E664_as_u32 == 0) {
        D_0028E684 = 0x50;
    }
    reg_d2.w = 0;
    D_0028E66C_as_u32 = reg_d2.w;
    D_0028E668_as_u32 = reg_d2.w;
    D_0028E680 = reg_d2.h[0];
    goto block_end;
next_2:
    if (D_0028E690_as_u32 != 0) {
        reg_d0.w = D_0028E690_as_u32;
        D_0028E660 = 1;
        D_0028E66C_as_u32 = reg_d0.w;
        D_0028E668_as_u32 = reg_d0.w;
        reg_d0.w = 0;
        D_0028E690_as_u32 = reg_d0.w;
    }
    reg_a0 = (u8 *)&D_0028E660;
    func_001A8FC0();
    reg_d0.h[0] = D_0028E610;
    if ((s32) D_0028E660 > (s32) reg_d0.h[0]) {
        D_0028E610 = D_0028E660;
    }
    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)&D_0028E670;
    func_001A97F0();
    reg_d0.w = D_0028E66C_as_u32;
    reg_a0 = (u8 *)&D_0028E66C_as_u32;
    func_001A97F0();
    func_001A99C0();
    reg_d0.w = D_0028E66C_as_u32;
    reg_a0 = (u8 *)&D_0028E71C_as_u16;
    func_001A97F0();
    if ((s32) D_0028E660 < 0x10) {
        if ((s32) D_0028E660 > 1) {
            D_0028E680 = 0x78;
        }
        D_0028E67C = D_0028E688;
        if (D_0028E664_as_u32 == 0) {
            D_0028E684 = 0xB4;
        }
        goto block_end;
    }
    if (D_0028E660 == 0x10) {
        D_0028E670 = 0;
        D_0028E680 = 0;
    }
    D_0028E65C = D_0028E660;
    D_0028E678 = 0xF0;
    D_0028E684 = 0xF0;
    D_0028E674 = D_0028E688;
    D_0028E664_as_u32 = D_0028E668_as_u32;
block_end:
    reg_d0.w = reg_d3.w;
}

extern s32 *reg_a1_as_s32_p;
extern s32 reg_a0_as_s32;
extern s32 D_0028E6E8;


void func_001A97F0(void) {
    extern void func_001AE9A0(s32 *, s32);
    reg_a0_as_s32 -= 4;
    reg_a1_as_s32_p = &D_0028E6E8;
    *reg_a1_as_s32_p = reg_d0.w;
    reg_d2.sh[0] = 0;
    func_001AE9A0(reg_a1_as_s32_p, reg_a0_as_s32);
}

extern u16 D_0026B898[];
extern u16 D_0026B8A8[];
extern u16 D_0026B8B8[];
extern u16 D_0028E5C0;
extern u16 D_0028E5E4;
extern u16 D_0028E918;
extern u8 D_0028ED80;

void func_001A9820(void) {
    u32 bits;
    u16 idx;
    u16 val;
    u32 add;

    bits = reg_d1.w & 4;
    reg_d0.h[0] = D_0028E694;
    if ((bits != 0) || (D_0028E910 == 0)) {
        D_0028E6C8 += reg_d0.h[0];
        reg_d0.h[0] = D_0028E6DC;
        if ((s32) D_0028E6C8 < (s32) reg_d0.h[0]) {
        block_rts:
            return;
        }
    }
    D_0028E6C8 = D_0028E6DC;
    if ((s16) reg_d1.h[0] < 0) {
        goto block_rts;
    }
    reg_a0 = (u8 *)D_0026B8A8;
    reg_d0.h[0] = D_0028E918;
    idx = reg_d0.h[0];
    reg_a0 += idx;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_d2.h[0] = D_0028E5C0;
    if (D_0028E5FC != 0) {
        reg_d0.h[0] = D_0028E918;
        reg_a0 = (u8 *)D_0026B8B8;
        reg_a0 += idx;
        reg_d0.h[0] = *(u16 *)reg_a0;
    } else {
        reg_d2.h[0] += reg_d2.h[0];
        reg_a0 = (u8 *)D_0026B898;
        switch (reg_d2.h[0]) {
        case 0:
            goto skip_1;
        }
        val = *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1));
        goto next_1;
    skip_1:
        val = *(u16 *)reg_a0;
    next_1:
        reg_d0.h[0] += val;
    }
    if ((D_0028E5C0 != 5) && (bits == 0)) {
        reg_d0.h[0] += reg_d0.h[0];
    }
    if (D_0028ED80 != 0) {
        add = reg_d0.h[0];
        D_0028E5E4 += add;
    } else {
        D_0028E5E4 += reg_d0.h[0];
    }
    func_001ABF90();
}

extern u16 D_0028E5BC;
extern u16 D_0028E5E0;

void func_001A99C0(void) {
    u32 bits;
    u16 idx;
    u16 val;
    u32 add;

    bits = reg_d1.w & 4;
    reg_d0.h[0] = D_0028E694;
    if ((bits != 0) || (D_0028E910 == 0)) {
        D_0028E688 += reg_d0.h[0];
        reg_d0.h[0] = D_0028E6DC;
        if ((s32) D_0028E688 < (s32) reg_d0.h[0]) {
        block_rts:
            return;
        }
    }
    D_0028E688 = D_0028E6DC;
    if ((s16) reg_d1.h[0] < 0) {
        goto block_rts;
    }
    reg_a0 = (u8 *)D_0026B8A8;
    reg_d0.h[0] = D_0028E918;
    idx = reg_d0.h[0];
    reg_a0 += idx;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_d2.h[0] = D_0028E5BC;
    if (D_0028E5F8 != 0) {
        reg_d0.h[0] = D_0028E918;
        reg_a0 = (u8 *)D_0026B8B8;
        reg_a0 += idx;
        reg_d0.h[0] = *(u16 *)reg_a0;
    } else {
        reg_d2.h[0] += reg_d2.h[0];
        reg_a0 = (u8 *)D_0026B898;
        switch (reg_d2.h[0]) {
        case 0:
            goto skip_1;
        }
        val = *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1));
        goto next_1;
    skip_1:
        val = *(u16 *)reg_a0;
    next_1:
        reg_d0.h[0] += val;
    }
    if ((D_0028E5BC != 5) && (bits == 0)) {
        reg_d0.h[0] += reg_d0.h[0];
    }
    if (D_0028ED80 != 0) {
        add = reg_d0.h[0];
        D_0028E5E0 += add;
    } else {
        D_0028E5E0 += reg_d0.h[0];
    }
    func_001AC160();
}

extern u16 D_0028E60C;

void func_001A9B60(void) {
    D_0028E60C -= 1;
    if ((s16)D_0028E60C < 0) {
        reg_d2.w = 0;
        reg_d2.h[0] += 0x10;
        if (D_0028ED80 != 0) {
            D_0028E5E4 += reg_d2.h[0];
        } else {
            D_0028E5E4 += reg_d2.h[0];
        }
        func_001ABF90();
        reg_d2.w = 8;
        D_0028E60C = reg_d2.h[0];
    }
}

void func_001A9BE0(void) {
    D_0028E60C -= 1;
    if ((s16) D_0028E60C < 0) {
        reg_d2.w = 4;
        if (D_0028E5FC != 0) {
            reg_d2.w = 0x30;
        }
        if (D_0028ED80 != 0) {
            D_0028E5E4 += reg_d2.h[0];
        } else {
            D_0028E5E4 += reg_d2.h[0];
        }
        func_001ABF90();
        reg_d2.w = 8;
        D_0028E60C = reg_d2.h[0];
    }
}

extern u16 D_0028E608;

void func_001A9C70(void) {
    D_0028E608 -= 1;
    if ((s16)D_0028E608 < 0) {
        reg_d2.w = 0;
        reg_d2.h[0] += 0x10;
        if (D_0028ED80 != 0) {
            D_0028E5E0 += reg_d2.h[0];
        } else {
            D_0028E5E0 += reg_d2.h[0];
        }
        func_001AC160();
        reg_d2.w = 8;
        D_0028E608 = reg_d2.h[0];
    }
}

void func_001A9CF0(void) {
    D_0028E608 -= 1;
    if ((s16) D_0028E608 < 0) {
        reg_d2.w = 4;
        if (D_0028E5F8 != 0) {
            reg_d2.w = 0x30;
        }
        if (D_0028ED80 != 0) {
            D_0028E5E0 += reg_d2.h[0];
        } else {
            D_0028E5E0 += reg_d2.h[0];
        }
        func_001AC160();
        reg_d2.w = 8;
        D_0028E608 = reg_d2.h[0];
    }
}

extern u16 D_0028E698;
extern u32 D_0028E720_as_u32;
extern s16 D_0029CEA0_as_s16_a[];
extern u16 D_0029F282[];
extern u16 D_0029F2BA[];

void func_001A9D80(void) {
    u16 saved_d0;

    switch (D_0028E855 & 4) {
    case 0:
        break;
    default:
        func_001AA160();
        return;
    }
    reg_d3.w = reg_d0.w;
    if ((D_0029CEA0_as_s16_a[0] >= 0) && (D_0028E6C8 == 0)) {
        reg_d0.w = 0;
        D_0028E6C8 = 0xA;
        reg_d2.w = 8;
        D_0028E6D0_as_u32 = reg_d0.w;
        D_0028E6CC_as_u32 = reg_d0.w;
        D_0028E6AC_as_u32 = reg_d0.w;
        D_0028E6A8_as_u32 = reg_d0.w;
        D_0028E6A0 = reg_d0.h[0];
        D_0028E6C0 = reg_d0.h[0];
        reg_d2.h[0] -= (s16) (u16) D_0029F282[0];
        reg_d0.h[0] = reg_d2.h[0];
        reg_d0.h[0] >>= 1;
        reg_d2.h[0] += reg_d0.h[0];
        reg_d2.h[0] += 0x12;
        D_0028E60C = reg_d2.h[0];
        if (D_0028E5FC != 0) {
            reg_d2.h[0] -= 0xC;
        }
        D_0028E698 = reg_d2.h[0];
        return;
    }
    func_001A9B60();
    D_0028E698 -= 1;
    if ((s16) D_0028E698 < 0) {
        if (D_0028E5FC != 0) {
            reg_d2.w = 6;
            reg_d2.h[0] -= D_0028E5D0;
        } else {
            reg_d2.w = 8;
            reg_d2.h[0] -= (s16) (u16) D_0029F282[0];
            reg_d0.h[0] = reg_d2.h[0];
            reg_d0.h[0] >>= 1;
            reg_d2.h[0] += reg_d0.h[0];
            reg_d2.h[0] += 1;
            reg_d2.h[0] += 0x11;
            if (D_0029F2BA[0] != 2) {
                reg_d2.h[0] -= 3;
            }
        }
        D_0028E698 = reg_d2.h[0];
        if (D_0028E6D0_as_u32 != 0) {
            reg_d0.w = D_0028E6D0_as_u32;
            D_0028E6A0 = 1;
            D_0028E6AC_as_u32 = reg_d0.w;
            D_0028E6A8_as_u32 = reg_d0.w;
            reg_d0.w = 0;
            D_0028E6D0_as_u32 = reg_d0.w;
        }
        reg_a0 = (u8 *)&D_0028E6A0;
        reg_d0.w = 0;
        if (reg_d1.w & 0x40) {
            reg_d0.h[0] += reg_d0.h[0];
        }
        do {
            saved_d0 = reg_d0.h[0];
            func_001A8FC0();
            reg_d0.h[0] = saved_d0;
        } while ((s16)(--reg_d0.h[0]) >= 0);
        reg_d0.h[0] = D_0028E614;
        if ((s32) D_0028E6A0 > (s32) reg_d0.h[0]) {
            D_0028E614 = D_0028E6A0;
        }
        reg_d0.w = reg_d3.w;
        reg_a0 = (u8 *)&D_0028E6B0;
        func_001A97F0();
        reg_d0.w = D_0028E6AC_as_u32;
        reg_a0 = (u8 *)&D_0028E6AC_as_u32;
        func_001A97F0();
        reg_d0.w = D_0028E6AC_as_u32;
        reg_a0 = (u8 *)&D_0028E720_as_u32;
        func_001A97F0();
    }
    if (D_0028E5FC == 0) {
        if ((s32) D_0028E6C8 < 0xA) {
            D_0028E6C8 = 0xA;
        }
    } else if ((s32) D_0028E6C8 < 0x19) {
        D_0028E6C8 = 0x19;
    }
    if ((s32) D_0028E6A0 < 0x10) {
        if ((s32) D_0028E6A0 > 1) {
            D_0028E6C0 = 0x78;
        }
        D_0028E6BC = D_0028E6C8;
        if (D_0028E6A4_as_u32 == 0) {
            D_0028E6C4 = 0xB4;
        }
        return;
    }
    if (D_0028E6B4 == 0) {
        D_0028E6B0 = 0;
        D_0028E6C0 = 0;
    }
    D_0028E69C = D_0028E6A0;
    D_0028E6B8 = 0xF0;
    D_0028E6C4 = 0xF0;
    D_0028E6B4 = D_0028E6C8;
    D_0028E6A4_as_u32 = D_0028E6A8_as_u32;
}

extern u16 D_0028E61C;
extern u16 D_0028E650;

void func_001AA0D0(void) {
    reg_d3.w = reg_d0.w;
    if (D_0028E650 == 0) {
        func_001AA1C0();
        return;
    }
    if (D_0028E61C == 0) {
        func_001AA210();
        return;
    }
    reg_d0.w = 1;
    if (D_0028E5FC == 0) {
        func_001AA2E0();
        return;
    }
    reg_d0.h[0] += D_0028E5D0;
    func_001AA2E0();
}

void func_001AA160(void) {
    reg_d3.w = reg_d0.w;
    if (D_0029CEA0_as_s16_a[0] < 0) {
        func_001AA210();
        return;
    }
    if (D_0028E650 != 0) {
        func_001AA210();
        return;
    }
    func_001AA1C0();
}

#pragma push
#pragma opt_propagation off
extern s16 D_0028E644;
extern s16 D_0028E648_as_s16;
extern s16 D_0028E64C_as_s16;
extern s16 D_0028E650_as_s16;

void func_001AA1C0(void)
{
    u16 adjustment;

    D_0028E650_as_s16 = 10;
    adjustment = D_0029F282[0];
    D_0028E644 = 7;
    D_0028E648_as_s16 = 0;
    reg_d2.w = 8;
    D_0028E64C_as_s16 = 0;
    reg_d2.h[0] -= adjustment;
    reg_d2.h[0] += 8;
    D_0028E698 = reg_d2.h[0];
}
#pragma pop


void func_001AA210(void) {
    if (D_0028E648_as_s16 < 0) {
        D_0028E648_as_s16 = 0;
    }
    func_001A9BE0();
    D_0028E698 -= 1;
    if ((s16) D_0028E698 >= 0) {
        func_001AA330();
        return;
    }
    reg_d0.w = 1;
    reg_d2.w = 0;
    if (D_0028E5FC != 0) {
        reg_d0.h[0] += D_0028E5D0;
    } else {
        reg_d2.w = 8;
        reg_d2.h[0] -= (s16) (u16) D_0029F282[0];
        reg_d2.h[0] += 8;
        if (D_0029F2BA[0] != 2) {
            reg_d2.h[0] -= 3;
        }
    }
    D_0028E698 = reg_d2.h[0];
    func_001AA2E0();
}

extern u16 D_0028E648;

void func_001AA2E0(void) {
    extern void func_001AA330(u16);
    D_0028E648 += reg_d0.h[0];
    if (!(reg_d1.w & 0x40)) {
        func_001AA330(reg_d0.h[0]);
        return;
    }
    D_0028E648 += reg_d0.h[0];
    func_001AA330(reg_d0.h[0]);
}


void func_001AA330()
{
    if ((s32)D_0028E648 > 0x7FFF) {
        D_0028E648 = 0x7FFF;
    }

    reg_d0.w = reg_d3.w;
    reg_a0 = &D_0028E720;
    func_001A97F0();
    D_0028E650_as_s16 = 10;
    D_0028E644 = 7;
}

extern u16 D_0028E658;
extern u32 D_0028E71C_as_u32;
extern u16 D_0029F212[];
extern u16 D_0029F24A[];

void func_001AA380(void) {
    u16 saved_d0;

    switch (D_0028E855 & 4) {
    case 0:
        break;
    default:
        func_001AA6D0();
        return;
    }
    reg_d3.w = reg_d0.w;
    if ((D_0029CEA0_as_s16_a[0] >= 0) && (D_0028E688 == 0)) {
        reg_d0.w = 0;
        D_0028E688 = 0xA;
        reg_d2.w = 8;
        D_0028E690_as_u32 = reg_d0.w;
        D_0028E68C_as_u32 = reg_d0.w;
        D_0028E66C_as_u32 = reg_d0.w;
        D_0028E668_as_u32 = reg_d0.w;
        D_0028E660 = reg_d0.h[0];
        D_0028E680 = reg_d0.h[0];
        reg_d2.h[0] -= (s16) (u16) D_0029F212[0];
        reg_d0.h[0] = reg_d2.h[0];
        reg_d0.h[0] >>= 1;
        reg_d2.h[0] += reg_d0.h[0];
        reg_d2.h[0] += 0x12;
        D_0028E608 = reg_d2.h[0];
        if (D_0028E5F8 != 0) {
            reg_d2.h[0] -= 0xC;
        }
        D_0028E658 = reg_d2.h[0];
        return;
    }
    func_001A9C70();
    D_0028E658 -= 1;
    if ((s16) D_0028E658 < 0) {
        if (D_0028E5F8 != 0) {
            reg_d2.w = 6;
            reg_d2.h[0] -= D_0028E5CC;
        } else {
            reg_d2.w = 8;
            reg_d2.h[0] -= (s16) (u16) D_0029F212[0];
            reg_d0.h[0] = reg_d2.h[0];
            reg_d0.h[0] >>= 1;
            reg_d2.h[0] += reg_d0.h[0];
            reg_d2.h[0] += 1;
            reg_d2.h[0] += 0x11;
            if (D_0029F24A[0] != 2) {
                reg_d2.h[0] -= 3;
            }
        }
        D_0028E658 = reg_d2.h[0];
        if (D_0028E690_as_u32 != 0) {
            reg_d0.w = D_0028E690_as_u32;
            D_0028E660 = 1;
            D_0028E66C_as_u32 = reg_d0.w;
            D_0028E668_as_u32 = reg_d0.w;
            reg_d0.w = 0;
            D_0028E690_as_u32 = reg_d0.w;
        }
        reg_a0 = (u8 *)&D_0028E660;
        reg_d0.w = 0;
        if (reg_d1.w & 0x40) {
            reg_d0.h[0] += reg_d0.h[0];
        }
        do {
            saved_d0 = reg_d0.h[0];
            func_001A8FC0();
            reg_d0.h[0] = saved_d0;
        } while ((s16)(--reg_d0.h[0]) >= 0);
        reg_d0.h[0] = D_0028E610;
        if ((s32) D_0028E660 > (s32) reg_d0.h[0]) {
            D_0028E610 = D_0028E660;
        }
        reg_d0.w = reg_d3.w;
        reg_a0 = (u8 *)&D_0028E670;
        func_001A97F0();
        reg_d0.w = D_0028E66C_as_u32;
        reg_a0 = (u8 *)&D_0028E66C_as_u32;
        func_001A97F0();
        reg_d0.w = D_0028E66C_as_u32;
        reg_a0 = (u8 *)&D_0028E71C_as_u32;
        func_001A97F0();
    }
    if (D_0028E5F8 == 0) {
        if ((s32) D_0028E688 < 0xA) {
            D_0028E688 = 0xA;
        }
    } else if ((s32) D_0028E688 < 0x19) {
        D_0028E688 = 0x19;
    }
    if ((s32) D_0028E660 < 0x10) {
        if ((s32) D_0028E660 > 1) {
            D_0028E680 = 0x78;
        }
        D_0028E67C = D_0028E688;
        if (D_0028E664_as_u32 == 0) {
            D_0028E684 = 0xB4;
        }
        return;
    }
    if (D_0028E674 == 0) {
        D_0028E670 = 0;
        D_0028E680 = 0;
    }
    D_0028E65C = D_0028E660;
    D_0028E678 = 0xF0;
    D_0028E684 = 0xF0;
    D_0028E674 = D_0028E688;
    D_0028E664_as_u32 = D_0028E668_as_u32;
}


void func_001AA6D0(void) {
    reg_d3.w = reg_d0.w;
    if (D_0029CEA0_as_s16_a[0] < 0) {
        func_001AA780();
        return;
    }
    if (D_0028E650 != 0) {
        func_001AA780();
        return;
    }
    func_001AA730();
}

#pragma push
#pragma opt_propagation off
void func_001AA730(void)
{
    u32 adjustment;
    u32 counter;

    D_0028E650_as_s16 = 10;
    adjustment = D_0029F212[0];
    D_0028E644 = 7;
    D_0028E648_as_s16 = 0;
    reg_d2.w = 8;
    counter = reg_d2.h[0];
    D_0028E64C_as_s16 = 0;
    reg_d2.h[0] = counter - adjustment;
    reg_d2.h[0] += 8;
    D_0028E658 = reg_d2.h[0];
}
#pragma pop


void func_001AA780(void) {
    if (D_0028E648_as_s16 < 0) {
        D_0028E648_as_s16 = 0;
    }
    func_001A9CF0();
    D_0028E658 -= 1;
    if ((s16) D_0028E658 >= 0) {
        func_001AA8A0();
        return;
    }
    reg_d0.w = 1;
    reg_d2.w = 0;
    if (D_0028E5F8 != 0) {
        reg_d0.h[0] += D_0028E5CC;
    } else {
        reg_d2.w = 8;
        reg_d2.h[0] -= (s16) (u16) D_0029F212[0];
        reg_d2.h[0] += 8;
        if (D_0029F24A[0] != 2) {
            reg_d2.h[0] -= 3;
        }
    }
    D_0028E658 = reg_d2.h[0];
    func_001AA850();
}


void func_001AA850(void) {
    extern void func_001AA8A0(u16);
    D_0028E648 += reg_d0.h[0];
    if (!(reg_d1.w & 0x40)) {
        func_001AA8A0(reg_d0.h[0]);
        return;
    }
    D_0028E648 += reg_d0.h[0];
    func_001AA8A0(reg_d0.h[0]);
}

void func_001AA8A0()
{
    if ((s32)D_0028E648 > 0x7FFF) {
        D_0028E648 = 0x7FFF;
    }

    reg_d0.w = reg_d3.w;
    reg_a0_as_void_p = &D_0028E71C_as_u8;
    func_001A97F0();
    D_0028E650_as_s16 = 10;
    D_0028E644 = 7;
}

extern u16 D_0026BFF0[];
extern s8 D_0028E634;
extern u8 D_0028E635;

void func_001AA8F0(void) {
    s32 func_0011C4A0();
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x200;
    if ((D_0028E854 & 1) && (D_0028E634 >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d1.h[0] = 0;
            reg_d0.h[0] = 0xCC;
            goto block_4;
        }
    } else {
block_4:
        reg_d2.h[0] = 2;
        reg_d3.h[0] = 5;
        if (D_0028E5FC == 0) {
            reg_d4.h[0] = D_0028E5C0;
            reg_a0 = (u8 *)(D_0026BFF0);
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            func_0011C4A0();
            return;
        }
        reg_d4.w = 0x0414000A;
        func_0011C4A0();
    }
}

void func_001AAA20(void) {
    s32 func_0011C4A0();
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x1400;
    if ((D_0028E854 & 1) && (D_0028E634 >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d0.h[0] = 0xCC;
            reg_d1.h[0] = 0x1600;
            goto block_4;
        }
    } else {
block_4:
        reg_d2.h[0] = 2;
        reg_d3.h[0] = 5;
        if (D_0028E5F8 == 0) {
            reg_d4.h[0] = D_0028E5BC;
            reg_a0 = (u8 *)(D_0026BFF0);
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            func_0011C4A0();
            return;
        }
        reg_d4.w = 0x0414000A;
        func_0011C4A0();
    }
}

extern s32 D_0028E72C_as_s32;
extern s32 D_0028E734;

void func_001AAB50(void) {
    reg_a0_as_s32_p = &D_0028E734;
    reg_a1_as_s32_p = &D_0028E72C_as_s32;
    func_001AAB90();
}

extern void *reg_a1_as_void_p;
extern u8 D_0028E728_as_u8;
extern u8 D_0028E730_as_u8;

void func_001AAB70(void) {
    reg_a0_as_void_p = &D_0028E730_as_u8;
    reg_a1_as_void_p = &D_0028E728_as_u8;
    func_001AAB90();
}

extern s32 D_0026C010[];
extern u8 D_0028E388;
extern u8 D_006E5C08[];
extern u16 *reg_a1_as_u16_p;

void func_001AAB90(void)
{
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E388;
    if (D_0028ED80 != 0) {
        reg_d0.b[0] = D_006E5C08[0];
    }

    reg_a2 = (u8 *)D_0026C010;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    *reg_a0_as_s32_p = *(s32 *)(reg_a2 + reg_d0.h[0]);
    *reg_a1_as_u16_p = reg_d0.h[0];
}

extern u8 D_0026C020[];

void func_001AAC00(void) {
    s32 func_001AE9A0(Reg32 *, Reg32 *);
    u8 *a5 = reg_a5;

    reg_d0.h[0] = *(u16 *) reg_a4;
    reg_a5 = (u8 *)D_0026C020;
    reg_d1.w = *(u32 *) (reg_a5 + reg_d0.h[0]);
    if (reg_d1.w != -1U) goto next_1;
    *(u32 *) reg_a2 = -1U;
    goto block_end;
next_1:
    if (!(reg_d1.w & 0x80000000)) goto next_2;
    reg_d1.w &= 0x7FFFFFFF;
    goto next_3;
next_2:
    *(u16 *) reg_a4 = 0xC;
next_3:
    reg_d2.w = *(u32 *) reg_a2;
    reg_d0.h[0] = 0;
    func_001AE9A0(&reg_d1, &reg_d2);
    *(u32 *) reg_a2 = reg_d2.w;
block_end:
    reg_a5 = a5;
}

extern u8 D_002B4E28[];
extern u8 D_002B5728[];
extern u8 D_002B5F28[];
extern u8 D_002B6828[];
extern u16 D_002BAF30[];
extern u16 D_002BAF3A[];
extern u16 D_002BAF50[];
extern u16 D_002BAFAA[];

void func_001AACC0(void) {
    u32 t;
    s32 t2;

    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B4E28;
    reg_d3.w = 0;
    reg_d6.w = 1;
    reg_a0 = (u8 *)D_002BAF50;
loop_1:
    reg_d7.w = 8;
loop_2:
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_d1.w += 0x100;
    t2 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d1.w = (u32) D_002B5F28;
    reg_a0 = (u8 *)D_002BAFAA;
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_a0 = (u8 *)D_002BAF30;
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_tmp.w = (u32) D_002B5728;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xC030;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 = (u8 *)D_002BAF3A;
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_tmp.w = (u32) D_002B6828;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xC030;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
}

extern u8 D_0028E70C;
extern u16 D_0028E73C;
extern u32 D_0028E744;
extern u16 D_0028E750;
extern u16 D_0028E75C;
extern u32 D_0028E768;

void func_001AAEE0(void) {
    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B4E28;
    reg_d3.w = 0;
    reg_a0 = (u8 *)(D_002BAF50);
    reg_d7.w = 8;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[1];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d2.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d3.h[0];
        reg_a0 += 2;
        reg_d1.w += 0x100;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_a0 = (u8 *)(D_002BAF30);
    *(u16 *)reg_a0 = 1;
    reg_tmp.w = (u32) D_002B5728;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xC030;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_d0.w = 0;
    D_0028E768 = reg_d0.w;
    D_0028E744 = reg_d0.w;
    reg_a0 += 2;
    D_0028E75C = reg_d0.h[0];
    D_0028E70C = reg_d0.b[0];
    D_0028E73C = reg_d0.h[0];
    D_0028E750 = reg_d0.h[0];
}

extern u8 D_0028E708;
extern u16 D_0028E738;
extern u32 D_0028E740;
extern u16 D_0028E748;
extern u16 D_0028E758;
extern u32 D_0028E764;

void func_001AB070(void) {
    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B5F28;
    reg_d3.w = 0;
    reg_a0 = (u8 *)(D_002BAFAA);
    reg_d7.w = 8;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[1];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d2.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d3.h[0];
        reg_a0 += 2;
        reg_d1.w += 0x100;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_a0 = (u8 *)(D_002BAF3A);
    *(u16 *)reg_a0 = 1;
    reg_tmp.w = (u32) D_002B6828;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xC030;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_d0.w = 0;
    D_0028E764 = reg_d0.w;
    D_0028E740 = reg_d0.w;
    reg_a0 += 2;
    D_0028E758 = reg_d0.h[0];
    D_0028E708 = reg_d0.b[0];
    D_0028E738 = reg_d0.h[0];
    D_0028E748 = reg_d0.h[0];
}

void func_001AB200(void) {
    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B4E28;
    reg_d3.w = 0;
    reg_a0 = (u8 *)(D_002BAF50);
    reg_d7.w = 8;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[1];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d2.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d3.h[0];
        reg_a0 += 2;
        reg_d1.w += 0x100;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_a0 = (u8 *)(D_002BAF30);
    *(u16 *)reg_a0 = 1;
    reg_d0.w = 0;
    D_0028E768 = reg_d0.w;
    D_0028E744 = reg_d0.w;
    reg_a0 += 2;
    D_0028E75C = reg_d0.h[0];
    D_0028E70C = reg_d0.b[0];
    D_0028E73C = reg_d0.h[0];
}

void func_001AB320(void) {
    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B5F28;
    reg_d3.w = 0;
    reg_a0 = (u8 *)(D_002BAFAA);
    reg_d7.w = 8;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[1];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d2.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d3.h[0];
        reg_a0 += 2;
        reg_d1.w += 0x100;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_a0 = (u8 *)(D_002BAF3A);
    *(u16 *)reg_a0 = 1;
    reg_d0.w = 0;
    D_0028E764 = reg_d0.w;
    D_0028E740 = reg_d0.w;
    reg_a0 += 2;
    D_0028E758 = reg_d0.h[0];
    D_0028E708 = reg_d0.b[0];
    D_0028E738 = reg_d0.h[0];
}

extern s16 D_0028E69C_as_s16;
extern s16 D_0028E6A0_as_s16;
extern s32 D_0028E6A4;
extern s32 D_0028E6A8;
extern s32 D_0028E6AC;
extern s16 D_0028E6B0_as_s16;
extern s16 D_0028E6B4_as_s16;
extern s16 D_0028E6BC_as_s16;
extern s16 D_0028E6C0_as_s16;
extern s16 D_0028E6C8_as_s16;
extern s32 D_0028E6D0;

void func_001AB440(void) {
    u32 savedD0 = reg_d0.w;
    s32 zero = (u16)(reg_d0.w = 0);

    D_0028E698_as_s16 = 0;
    D_0028E69C_as_s16 = 0;
    D_0028E6A0_as_s16 = 0;
    D_0028E6A4 = zero;
    D_0028E6A8 = zero;
    D_0028E6AC = zero;
    D_0028E6B0_as_s16 = 0;
    D_0028E6B4_as_s16 = 0;
    D_0028E6B8 = 0;
    D_0028E6BC_as_s16 = 0;
    D_0028E6C0_as_s16 = 0;
    D_0028E6C4 = 0;
    D_0028E6C8_as_s16 = 0;
    D_0028E614 = reg_d0.h[0];
    D_0028E6CC_as_u32 = reg_d0.w;
    D_0028E6D0 = zero;
    reg_d0.w = savedD0;
}

extern s16 D_0028E65C_as_s16;
extern s16 D_0028E660_as_s16;
extern s32 D_0028E664;
extern s32 D_0028E668;
extern s32 D_0028E66C;
extern s16 D_0028E670_as_s16;
extern s16 D_0028E674_as_s16;
extern s16 D_0028E67C_as_s16;
extern s16 D_0028E680_as_s16;
extern s16 D_0028E688_as_s16;
extern s32 D_0028E690;

void func_001AB4A0(void)
{
    u32 savedD0;
    u32 clearedHalfword;

    savedD0 = reg_d0.w;
    clearedHalfword = (D_0028E658 = 0);
    D_0028E664 = clearedHalfword;
    D_0028E668 = clearedHalfword;
    D_0028E66C = clearedHalfword;
    D_0028E690 = clearedHalfword;
    reg_d0.w = 0;
    D_0028E65C_as_s16 = 0;
    D_0028E660_as_s16 = 0;
    D_0028E670_as_s16 = 0;
    D_0028E674_as_s16 = 0;
    D_0028E678 = 0;
    D_0028E67C_as_s16 = 0;
    D_0028E680_as_s16 = 0;
    D_0028E684 = 0;
    D_0028E688_as_s16 = 0;
    D_0028E610 = reg_d0.h[0];
    D_0028E68C_as_u32 = reg_d0.w;
    reg_d0.w = savedD0;
}

void func_001AB500() {
    *(u16 *)(reg_a0 + 6) += 1;
    *(u16 *)reg_a0 = 1;
}

extern s16 D_0028E750_as_s16;
extern u8 D_002BAF30_as_u8_a[];

void func_001AB520(void) {
    u8 *temp_s0;
    u16 temp_a0;

    temp_a0 = D_0028E750_as_s16;
    if (temp_a0 != 9) {
        temp_s0 = reg_a0;
        D_0028E750_as_s16 = temp_a0 + 1;
        reg_a0 = D_002BAF30_as_u8_a;
        func_001AB500(temp_a0);
        reg_a0 = temp_s0;
    }
}

extern s16 D_0028E748_as_s16;
extern u8 D_002BAF3A_as_u8_a[];

void func_001AB570(void) {
    u8 *temp_s0;
    u16 temp_a0;

    temp_a0 = D_0028E748_as_s16;
    if (temp_a0 != 9) {
        temp_s0 = reg_a0;
        D_0028E748_as_s16 = temp_a0 + 1;
        reg_a0 = D_002BAF3A_as_u8_a;
        func_001AB500(temp_a0);
        reg_a0 = temp_s0;
    }
}

extern u16 D_0028E598;

void func_001AB5C0(void) {
    u32 tmp;

    switch (D_0028E598) {
    case 0:
        break;
    default:
        reg_a0 = (u8 *)D_002BAF50;
        reg_d0.w = 0x11;
loop_1:
        if (*(u16 *)reg_a0 != 0) {
            *(u16 *)reg_a0 = 0;
            reg_a0 += 2;
            reg_tmp.h[1] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_tmp.h[0] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 = (u8 *)reg_tmp.w;
            *(u16 *)(reg_a1 + 2) = *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
            reg_a0 += 2;
            tmp = reg_d0.h[0] - 1;
            reg_d0.h[0] = tmp;
            if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                goto loop_1;
            }
            return;
        }
        reg_a0 += 0xA;
        tmp = reg_d0.h[0] - 1;
        reg_d0.h[0] = tmp;
        if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
        if (D_002BAF30[0] != 0) {
            reg_a0 = (u8 *)D_002BAF30;
            *(u16 *)reg_a0 = 0;
            reg_a0 += 2;
            reg_tmp.h[1] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_tmp.h[0] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 = (u8 *)reg_tmp.w;
            *(u16 *)(reg_a1 + 2) = *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
            reg_a0 += 2;
        }
        if (D_002BAF3A[0] != 0) {
            reg_a0 = (u8 *)D_002BAF3A;
            *(u16 *)reg_a0 = 0;
            reg_a0 += 2;
            reg_tmp.h[1] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_tmp.h[0] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 = (u8 *)reg_tmp.w;
            *(u16 *)(reg_a1 + 2) = *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
            reg_a0 += 2;
        }
    }
}

extern s16 D_002BAF30_as_s16_a[];
extern s16 D_002BAF50_as_s16_a[];
extern s16 *reg_a0_as_s16_p;

void func_001AB7F0(void)
{
    u32 saved_d0 = reg_d0.w;
    s16 *saved_a0 = reg_a0_as_s16_p;

    reg_a0_as_s16_p = D_002BAF50_as_s16_a;
    reg_d0.w = 8;

    do {
        *reg_a0_as_s16_p = 1;
        reg_a0_as_s16_p += 5;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.w = saved_d0;
    D_002BAF30_as_s16_a[0] = 1;
    reg_a0_as_s16_p = saved_a0;
}

extern s16 D_002BAF3A_as_s16_a[];
extern s16 D_002BAFAA_as_s16_a[];
extern u32 reg_a0_as_u32;

void func_001AB860(void)
{
    u32 saved_d0 = reg_d0.w;
    u32 saved_a0 = reg_a0_as_u32;

    reg_a0_as_u32 = (u32)D_002BAFAA_as_s16_a;
    reg_d0.w = 8;

    do {
        *(s16 *)reg_a0_as_u32 = 1;
        reg_a0_as_u32 += 10;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.w = saved_d0;
    D_002BAF3A_as_s16_a[0] = 1;
    reg_a0_as_u32 = saved_a0;
}

extern u16 D_0028DFC0;
extern void func_0019DBB0(u32 originalD1);

void func_001AB8D0(void)
{
    u32 originalD1;

    if (D_0028DFC0 == 0) {
        originalD1 = reg_d1.w;
        reg_d1.w = originalD1 + 0xF200F600u;
        reg_d3.h[0] = 0xE50;
        reg_d4.h[0] = 4;
        func_0019DBB0(originalD1);
        return;
    }
}

extern s16 D_0028E57C_as_s16;
extern s16 D_0028E584_as_s16;
extern s32 D_0028E594;

void func_001AB920(void) {
    D_0028E594 = 0x9E8;
    D_0028E584_as_s16 = 1;
    D_0028E57C_as_s16 = 1;
}

extern u8 D_0028E57C_as_u8;
extern u8 D_0028E57D;
extern u16 D_0028E584;
extern u32 D_0028E594_as_u32;
extern s16 D_0029F260[];
extern u16 D_0029F262[];
extern u16 D_0029F264[];
void func_001AB940(void) {
    if (D_0028E584 != 0) {
        if (D_0029F260[0] < 0) {
            reg_d1.h[1] = D_0029F262[0];
            reg_d1.h[0] = D_0029F264[0];
            reg_d2.w = D_0028E594_as_u32;
            func_001AB8D0();
        }
        D_0028E57D -= 1;
        if ((s8) D_0028E57D < 0) {
            D_0028E57D = D_0028E57C_as_u8;
            D_0028E594_as_u32 += 1;
            if (D_0028E594_as_u32 == 0xA04) {
                D_0028E584 = 0;
            }
        }
    }
}

extern u8 D_0026B8D0[];
extern u16 D_0028E58C;

void func_001AB9D0(void) {
    if (D_0028E58C != 0) {
        reg_d0.h[0] = D_0028E58C;
        reg_a0 = D_0026B8D0;
        D_0028E594_as_u32 = *(u32 *)(reg_a0 + reg_d0.h[0]);
        if (D_0029F260[0] < 0) {
            reg_d1.h[1] = D_0029F262[0];
            reg_d1.h[0] = D_0029F264[0];
            reg_d2.w = D_0028E594_as_u32;
            func_001AB8D0();
        }
        D_0028E58C -= 4;
    }
}

extern s16 D_0028E578_as_s16;
extern s16 D_0028E580_as_s16;
extern s32 D_0028E590;

void func_001ABA50(void) {
    D_0028E590 = 0x9E8;
    D_0028E580_as_s16 = 1;
    D_0028E578_as_s16 = 1;
}

extern u8 D_0028E578_as_u8;
extern u8 D_0028E579;
extern u16 D_0028E580;
extern u32 D_0028E590_as_u32;
extern s16 D_0029F1F0[];
extern u16 D_0029F1F2[];
extern u16 D_0029F1F4[];
void func_001ABA70(void) {
    if (D_0028E580 != 0) {
        if (D_0029F1F0[0] < 0) {
            reg_d1.h[1] = D_0029F1F2[0];
            reg_d1.h[0] = D_0029F1F4[0];
            reg_d2.w = D_0028E590_as_u32;
            func_001AB8D0();
        }
        D_0028E579 -= 1;
        if ((s8) D_0028E579 < 0) {
            D_0028E579 = D_0028E578_as_u8;
            D_0028E590_as_u32 += 1;
            if (D_0028E590_as_u32 == 0xA04) {
                D_0028E580 = 0;
            }
        }
    }
}

extern u16 D_0028E588;

void func_001ABB00(void) {
    if (D_0028E588 != 0) {
        reg_d0.h[0] = D_0028E588;
        reg_a0 = D_0026B8D0;
        D_0028E590_as_u32 = *(u32 *)(reg_a0 + reg_d0.h[0]);
        if (D_0029F1F0[0] < 0) {
            reg_d1.h[1] = D_0029F1F2[0];
            reg_d1.h[0] = D_0029F1F4[0];
            reg_d2.w = D_0028E590_as_u32;
            func_001AB8D0();
        }
        D_0028E588 -= 4;
    }
}

s32 func_0016AA30();
extern u16 D_0028E5B0;
extern u16 D_0028E5B8;
extern s16 D_0028E8C4_as_s16;
extern u8 D_0029F285[];

void func_001ABB80(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    u16 var_a0;
    if (D_0028E5B0 != 0) {
        if (D_0029F260[0] >= 0) {
            if (D_0028E8C4_as_s16 >= 0) {
                return;
            }
            goto block_5;
        }
        if (D_0029F285[0] == 0) {
            goto block_5;
        }
    } else {
block_5:
        reg_d7.h[0] = D_0028E5B8;
        if (D_0028E5B8 != 0) {
            if (D_0028E5E4 == 0x95F) {
                D_0028E5E4 = 0;
                reg_d7.h[0] += 1;
            }
            reg_d7.h[0] -= 1;
            reg_d6.h[0] = 0x7000;
            temp_s0 = reg_d0.w;
            temp_s1 = reg_d2.w;
            temp_s2 = reg_d6.w;
            temp_s3 = (s32)reg_a0;
            temp_s4 = (s32)reg_a2;
            do {
                reg_d0.w = 0xC;
                func_0016AA30();
                var_a0 = (u32)reg_d6.h[0] + 0x800;
                reg_d6.h[0] = var_a0;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d0.w = temp_s0;
            reg_d2.w = temp_s1;
            reg_d6.w = temp_s2;
            reg_a0 = (u8 *)temp_s3;
            reg_a2 = (u8 *)temp_s4;
            D_0028E5B8 = 0;
        }
    }
}

#ifndef DEATH_LABEL
void func_001ABCA0(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    u16 var_a0;
    reg_d7.h[0] = D_0028E5B8;
    if (D_0028E5B8 != 0) {
        if (D_0028E5E4 == 0x95F) {
            D_0028E5E4 = 0;
            reg_d7.h[0] += 1;
        }
        reg_d7.h[0] -= 1;
        reg_d6.h[0] = 0x7000;
        temp_s0 = reg_d0.w;
        temp_s1 = reg_d2.w;
        temp_s2 = reg_d6.w;
        temp_s3 = (s32)reg_a0;
        temp_s4 = (s32)reg_a2;
        do {
            reg_d0.w = 0xC;
            func_0016AA30();
            var_a0 = (u32)reg_d6.h[0] + 0x800;
            reg_d6.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d0.w = temp_s0;
        reg_d2.w = temp_s1;
        reg_d6.w = temp_s2;
        reg_a0 = (u8 *)temp_s3;
        reg_a2 = (u8 *)temp_s4;
        D_0028E5B8 = 0;
    }
}
#endif

extern u16 D_0028E5B4;
extern s16 D_0028E8C0_as_s16;
extern u8 D_0029F215[];

void func_001ABD80(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    u16 var_a0;
    if (D_0028E5B0 != 0) {
        if (D_0029F1F0[0] >= 0) {
            if (D_0028E8C0_as_s16 >= 0) {
                return;
            }
            goto block_5;
        }
        if (D_0029F215[0] == 0) {
            goto block_5;
        }
    } else {
block_5:
        reg_d7.h[0] = D_0028E5B4;
        if (D_0028E5B4 != 0) {
            if (D_0028E5E0 == 0x95F) {
                D_0028E5E0 = 0;
                reg_d7.h[0] += 1;
            }
            reg_d7.h[0] -= 1;
            reg_d6.h[0] = 0x7000;
            temp_s0 = reg_d0.w;
            temp_s1 = reg_d2.w;
            temp_s2 = reg_d6.w;
            temp_s3 = (s32)reg_a0;
            temp_s4 = (s32)reg_a2;
            do {
                reg_d0.w = 0x14;
                func_0016AA30();
                var_a0 = (u32)reg_d6.h[0] + 0x800;
                reg_d6.h[0] = var_a0;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d0.w = temp_s0;
            reg_d2.w = temp_s1;
            reg_d6.w = temp_s2;
            reg_a0 = (u8 *)temp_s3;
            reg_a2 = (u8 *)temp_s4;
            D_0028E5B4 = 0;
        }
    }
}

#ifndef DEATH_LABEL
void func_001ABEA0(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    u16 var_a0;
    reg_d7.h[0] = D_0028E5B4;
    if (D_0028E5B4 != 0) {
        if (D_0028E5E0 == 0x95F) {
            D_0028E5E0 = 0;
            reg_d7.h[0] += 1;
        }
        reg_d7.h[0] -= 1;
        reg_d6.h[0] = 0x7000;
        temp_s0 = reg_d0.w;
        temp_s1 = reg_d2.w;
        temp_s2 = reg_d6.w;
        temp_s3 = (s32)reg_a0;
        temp_s4 = (s32)reg_a2;
        do {
            reg_d0.w = 0x14;
            func_0016AA30();
            var_a0 = (u32)reg_d6.h[0] + 0x800;
            reg_d6.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d0.w = temp_s0;
        reg_d2.w = temp_s1;
        reg_d6.w = temp_s2;
        reg_a0 = (u8 *)temp_s3;
        reg_a2 = (u8 *)temp_s4;
        D_0028E5B4 = 0;
    }
}
#endif

extern s16 D_0028E5E4_as_s16;

void func_001ABF80(void) {
    D_0028E5E4_as_s16 = 0x95F;
}

extern u16 D_00255740[];
extern u16 D_00299764[];
extern u16 D_00299766[];

void func_001ABF90(void) {
    u32 save_d0;
    u32 save_d2;
    u32 save_d6;
    u8 *save_a0;
    u8 *save_a2;

    if (!((s32) D_0028E5E4 > 0x95F)) goto block_end;
    if (D_0028E5C0 == 5) {
        func_001ABF80();
        return;
    }
    if (D_0028E5B8 == 4) {
        func_001ABF80();
        goto block_end;
    }
    D_0028E5E4 = 0;
    switch (D_0028E5B0) { case 0: goto next_1; }
    if (D_0029F260[0] >= 0) goto next_2;
    if (D_0029F285[0] != 0) goto next_2;
next_1:
    if (D_0028E5FC == 0) goto next_3;
next_2:
    D_0028E5B8 += 1;
    if (D_0029F260[0] < 0) {
        reg_a0 = (u8 *)(D_00255740);
        reg_d0.h[0] = D_0028E5B8;
        reg_d0.h[0] -= 1;
        reg_d0.h[0] += reg_d0.h[0];
        D_00299764[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d0.w = 0x20;
        if ((D_0028E5B8 & 0xFFFF) == 5) {
            reg_d0.w = 0x2C;
        }
        D_00299766[0] = reg_d0.h[0];
    }
    return;
next_3:
    reg_d0.w = 0xC;
    save_d6 = reg_d6.w;
    save_d2 = reg_d2.w;
    save_d0 = reg_d0.w;
    save_a0 = reg_a0;
    save_a2 = reg_a2;
    reg_d6.h[0] = 0x7000;
    func_0016AA30();
    reg_d0.w = save_d0;
    reg_d2.w = save_d2;
    reg_d6.w = save_d6;
    reg_a0 = save_a0;
    reg_a2 = save_a2;
block_end:
    return;
}

void func_001AC150(void) {
    D_0028E5E0 = 0x95F;
}


void func_001AC160(void) {
    u32 save_d0;
    u32 save_d2;
    u32 save_d6;
    u8 *save_a0;
    u8 *save_a2;

    if (!((s32) D_0028E5E0 > 0x95F)) goto block_end;
    if (D_0028E5BC == 5) {
        func_001AC150();
        return;
    }
    if (D_0028E5B4 == 4) {
        func_001AC150();
        goto block_end;
    }
    D_0028E5E0 = 0;
    switch (D_0028E5B0) { case 0: goto next_1; }
    if (D_0029F1F0[0] >= 0) goto next_2;
    if (D_0029F215[0] != 0) goto next_2;
next_1:
    if (D_0028E5F8 == 0) goto next_3;
next_2:
    D_0028E5B4 += 1;
    if (D_0029F1F0[0] < 0) {
        reg_a0 = (u8 *)(D_00255740);
        reg_d0.h[0] = D_0028E5B4;
        reg_d0.h[0] -= 1;
        reg_d0.h[0] += reg_d0.h[0];
        D_00299764[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d0.w = 0x30;
        if ((D_0028E5B4 & 0xFFFF) == 5) {
            reg_d0.w = 0x3C;
        }
        D_00299766[0] = reg_d0.h[0];
    }
    return;
next_3:
    reg_d0.w = 0x14;
    save_d6 = reg_d6.w;
    save_d2 = reg_d2.w;
    save_d0 = reg_d0.w;
    save_a0 = reg_a0;
    save_a2 = reg_a2;
    reg_d6.h[0] = 0x7000;
    func_0016AA30();
    reg_d0.w = save_d0;
    reg_d2.w = save_d2;
    reg_d6.w = save_d6;
    reg_a0 = save_a0;
    reg_a2 = save_a2;
block_end:
    return;
}

extern u16 D_0028E64C;

void func_001AC320(void) {
    u16 halfword;

    D_0028E648 = 0xFFFF;
    reg_d0.w = 0x17;
    halfword = reg_d0.h[0];
    D_0028E64C = halfword;
    D_0028E650 = halfword;
}

void func_001AC340(void) {
    reg_d0.w = 0;
    D_0028E6D0_as_u32 = reg_d0.w;
    D_0028E6CC_as_u32 = reg_d0.w;
    D_0028E6C8 = reg_d0.h[0];
    D_0028E6B4 = reg_d0.h[0];
    D_0028E6A0 = reg_d0.h[0];
    D_0028E6AC_as_u32 = reg_d0.w;
    D_0028E6A8_as_u32 = reg_d0.w;
}

void func_001AC370(void) {
    reg_d0.w = 0;
    D_0028E690_as_u32 = reg_d0.w;
    D_0028E68C_as_u32 = reg_d0.w;
    D_0028E688 = reg_d0.h[0];
    D_0028E674 = reg_d0.h[0];
    D_0028E660 = reg_d0.h[0];
    D_0028E66C_as_u32 = reg_d0.w;
    D_0028E668_as_u32 = reg_d0.w;
}

extern u16 D_0028DAF8[];
extern u16 D_0028E8C4;
extern u16 D_0028E938;

void func_001AC3A0(void) {
    s32 func_0011C4A0();
    s32 func_0011C7C0();
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    reg_d0.h[0] = 0xBC;
    reg_d1.h[0] = 0x200;
    if ((D_0028E854 & 1) && (D_0028E634 >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d1.h[0] = 0;
            reg_d0.h[0] = 0xC0;
            goto block_4;
        }
    } else {
block_4:
        reg_d2.h[0] = 1;
        reg_d3.h[0] = 0;
        reg_d7.w = 5;
        reg_d6.h[0] = D_0028E8C4;
        if (D_0028E8C4 != 0) {
            reg_d6.h[0] -= 1;
            reg_d7.h[0] -= 1;
            if ((s32) reg_d6.h[0] > 5) {
                reg_d6.w = 5;
            }
            reg_a0 = (u8 *)(D_0028DAF8);
            reg_d7.h[0] -= reg_d6.h[0];
            reg_d4.h[0] = D_0028E938;
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d5.h[0] = reg_d1.h[0];
            do {
                func_0011C4A0();
                reg_d1.h[0] += 0x100;
            } while ((s16)(--reg_d6.h[0]) >= 0);
            if ((s16) reg_d7.h[0] < 0) {
                goto block_end;
            }
        }
        do {
            func_0011C7C0();
            reg_d1.h[0] += 0x100;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
block_end:
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
}

extern u16 D_0028DB00[];
extern u16 D_0028E8C0;
extern u16 D_0028E934;

void func_001AC5F0(void) {
    s32 func_0011C4A0();
    s32 func_0011C7C0();
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    reg_d0.h[0] = 0xBC;
    reg_d1.h[0] = 0x1900;
    if ((D_0028E854 & 1) && (D_0028E634 >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d0.h[0] = 0xC0;
            reg_d1.h[0] = 0x1B00;
            goto block_4;
        }
    } else {
block_4:
        reg_d2.h[0] = 1;
        reg_d3.h[0] = 0;
        reg_d7.w = 5;
        reg_d6.h[0] = D_0028E8C0;
        if (D_0028E8C0 != 0) {
            reg_d6.h[0] -= 1;
            reg_d7.h[0] -= 1;
            if ((s32) reg_d6.h[0] > 5) {
                reg_d6.w = 5;
            }
            reg_a0 = (u8 *)(D_0028DB00);
            reg_d7.h[0] -= reg_d6.h[0];
            reg_d4.h[0] = D_0028E934;
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d5.h[0] = reg_d1.h[0];
            do {
                func_0011C4A0();
                reg_d1.h[0] -= 0x100;
            } while ((s16)(--reg_d6.h[0]) >= 0);
            if ((s16) reg_d7.h[0] < 0) {
                goto block_end;
            }
        }
        do {
            func_0011C7C0();
            reg_d1.h[0] -= 0x100;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
block_end:
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
}

extern s16 D_0028E59C_as_s16;
extern u16 D_0028E630;
extern u16 g_stage;
extern u8 D_0028ED7C;
extern u16 D_006C8E5C[];

void func_001AC840(void) {
    if (!(D_0028E854 & 1)) {
        D_0028E630 = 0x53;
        if (g_stage == 0 && D_0028ED7C == 2) {
            if (D_006C8E5C[0] == 0) {
                D_0028E630 += 0x42;
            } else {
                D_0028E630 += 0x6B;
            }
        }
        if (D_0028ED80 != 0) {
            D_0028E630 = 1;
        }
    }
    D_0028E59C_as_s16 = 1;
}

void func_001AC8C0(void) {
    void func_0011C7C0(void);
    reg_d0.h[0] = 0xD4;
    reg_d2.sh[0] = 7;
    reg_d3.sh[0] = 7;
    reg_d1.h[0] = 0;
    func_0011C7C0();
}

void func_001AC8E0(void) {
    void func_0011C7C0(void);
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1400;
    reg_d2.sh[0] = 7;
    reg_d3.sh[0] = 7;
    func_0011C7C0();
}


void func_001AC900(void) {
    if (!(D_0028E854 & 1)) {
        func_001AC950();
        return;
    }
    if (D_0028E634 < 0) {
        func_001AC950();
    }
}

extern Reg32 reg_d0;
extern Reg32 reg_d1;

void func_001AC950(void) {
    extern void func_0011C4A0(void);
    reg_d0.h[0] = 0xD4;
    reg_d2.sh[0] = 7;
    reg_d3.sh[0] = 1;
    reg_d4.sw = 0x0404000A;
    reg_d1.h[0] = 0;
    func_0011C4A0();
}


void func_001AC980(void) {
    if (!(D_0028E854 & 1)) {
        func_001AC9D0();
        return;
    }
    if (D_0028E634 < 0) {
        func_001AC9D0();
    }
}

void func_001AC9D0(void) {
    extern void func_0011C4A0(void);
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1A00;
    reg_d2.sh[0] = 7;
    reg_d3.sh[0] = 1;
    reg_d4.sw = 0x3EE000A;
    func_0011C4A0();
}

void func_001ACA00(void)
{
    extern void func_0011C7C0(void);
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0;
    reg_d2.h[0] = 7;
    reg_d3.h[0] = 7;

    if ((D_0028E854 & 1) && D_0028E634 >= 0) {
        if (!(D_0028E635 & 0x10)) {
            return;
        }

        reg_d1.h[0] = 0;
        reg_d0.h[0] = 0xCC;
        reg_d2.h[0] = 5;
        reg_d3.h[0] = 5;
    }

    func_0011C7C0();
}

void func_001ACA80(void) {
    s32 func_0011C7C0();
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1400;
    reg_d2.h[0] = 7;
    reg_d3.h[0] = 7;
    if ((D_0028E854 & 1) && (D_0028E634 >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d0.h[0] = 0xCC;
            reg_d1.h[0] = 0x1600;
            reg_d2.h[0] = 5;
            reg_d3.h[0] = 5;
            goto block_4;
        }
    } else {
block_4:
        func_0011C7C0();
    }
}

void func_001ACB00(void)
{
    if (D_0028ED80 != 0) {
        D_0028E5E4 += 0x258;
    } else {
        D_0028E5E4 += 0x258;
    }

    if ((s32)D_0028E5E4 >= 0x95F) {
        D_0028E5E4 = 0x95E;
    }
}

void func_001ACB50(void)
{
    if (D_0028ED80 != 0) {
        D_0028E5E0 += 0x258;
    } else {
        D_0028E5E0 += 0x258;
    }

    if ((s32)D_0028E5E0 >= 0x95F) {
        D_0028E5E0 = 0x95E;
    }
}
