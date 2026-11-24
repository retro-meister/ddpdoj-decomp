#include "common.h"

extern u8 *reg_a6;
void func_001260B0(void);

void func_00126120(void) {
    void func_00125590(void);
    void func_001257E0(void);
    void func_00125930(void);
    void func_00125A00(void);
    if ((u16)(reg_d1.h[0] &= 0x1800) != 0) {
        func_001260B0();
        return;
    }
    func_00125A00();
    func_00125930();
    if (0 <= (s64)*(s16 *)(reg_a6 + 2)) {
        func_00125590();
    } else {
        func_001257E0();
    }
}

typedef void (*Fn)();

extern s8 D_0028E408;

s32 func_001256C0();
s32 func_001257B0();
s32 func_00127CA0();
s32 func_00128130();
s32 func_00170DF0();
s32 func_00170F80();
s32 func_00171100();
s32 func_0018D970();
s32 func_0019D290();
extern u8 D_00269490[];
extern u8 *jtbl_0028E3F4_as_u8_p;
extern u8 *reg_a0;

void func_001261A0(void) {
    s32 func_001257E0();
    u32 t;

    if (reg_d1.w & 1) {
        func_00128130();
        return;
    }
    reg_d0.w = 0;
    if (reg_d1.w & 0x1000) goto next_1;
    if (!(reg_d1.w & 0x800)) goto next_3;
    func_00170F80();
    goto next_2;
next_1:
    func_00170DF0();
next_2:
    func_00171100();
    func_0018D970();
    *(u8 *)(reg_a6 + 0) |= 1;
    func_00127CA0();
    return;
block_1:
    func_001257E0();
    return;
next_3:
    reg_tmp.w = 0xBBD;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    *(u16 *)(reg_a6 + 0x18) -= 1;
    if ((s16) *(u16 *)(reg_a6 + 0x18) >= 0) goto next_4;
    *(u16 *)(reg_a6 + 0x18) = 2;
    reg_tmp.w = 0xBBE;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
next_4:
    func_001256C0();
    if (D_0028E408 != 0) goto block_1;
    reg_d0.w = 4;
    reg_d1.h[0] &= reg_d0.h[0];
    t = reg_d1.h[0] ^ reg_d0.h[0];
    reg_d1.h[0] = t;
    if (t & 0xFFFF) goto next_5;
    func_001257B0();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *)(reg_tmp.w);
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn)jtbl_0028E3F4_as_u8_p)();
    return;
next_5:
    *(u16 *)(reg_a6 + 2) -= 0x60;
    *(u8 *)(reg_a6 + 0x1E) -= 1;
    if (*(u8 *)(reg_a6 + 0x1E) != 0) goto next_6;
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1F);
    reg_a0 = (u8 *)(D_00269490);
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
next_6:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x22);
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d1.h[0];
    func_0019D290();
}

s32 func_00125860();
s32 func_0018D930();
s32 func_001A9130();
extern u8 D_0028E855;
extern void (*jtbl_0028E3F4)();

void func_00126410(void) {
    s32 func_001257E0();
    u32 t;

    if ((s16)(D_0028E855) < 0) goto next_2;
    t = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t;
    if (!(t & 0xFFFF)) goto next_1;
    reg_d0.w = 1;
    func_00125860();
    reg_tmp.w = 0x50000;
    *(u16 *)(reg_a6 + 0x10) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = reg_tmp.h[0];
    reg_d0.w = 0x50;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 1);
    func_001A9130();
    func_0018D930();
    *(u8 *)reg_a6 = 0x84;
    func_00127CA0();
    return;
next_2:
    func_001257E0();
    return;
next_1:
    func_001257B0();
    func_001256C0();
    if (D_0028E408 != 0) goto next_2;
    *(u8 *)(reg_a6 + 0x19) -= 1;
    if ((s8) *(u8 *)(reg_a6 + 0x19) < 0) {
        *(u8 *)(reg_a6 + 0x19) = *(u8 *)(reg_a6 + 0x18);
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
        if (reg_tmp.w == 0xC0F) {
            reg_tmp.w = 0xBFF;
            *(u16 *)reg_a0 = reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
            *(u8 *)(reg_a6 + 0x19) = 1;
        }
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
}

s32 func_0018D950();

void func_001265B0(void) {
    s32 func_001257E0();
    u32 t;

    if ((s16)(D_0028E855) < 0) goto next_2;
    t = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t;
    if (!(t & 0xFFFF)) goto next_1;
    reg_d0.w = 2;
    func_00125860();
    reg_tmp.w = 0x10008;
    *(u16 *)(reg_a6 + 0x10) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = reg_tmp.h[0];
    reg_d0.w = 0x1000;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 1);
    func_001A9130();
    func_0018D950();
    *(u8 *)reg_a6 = 0x84;
    func_00127CA0();
    return;
next_2:
    func_001257E0();
    return;
next_1:
    func_001257B0();
    func_001256C0();
    if (D_0028E408 != 0) goto next_2;
    *(u8 *)(reg_a6 + 0x19) -= 1;
    if ((s8) *(u8 *)(reg_a6 + 0x19) < 0) {
        *(u8 *)(reg_a6 + 0x19) = *(u8 *)(reg_a6 + 0x18);
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
        if (reg_tmp.w == 0xC2F) {
            reg_tmp.w = 0xC1F;
            *(u16 *)reg_a0 = reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
            *(u8 *)(reg_a6 + 0x19) = 2;
        }
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
}

s32 func_00125810();
s32 func_00125AA0();

void func_00126760(void) {
    s32 func_00125590();
    s32 func_001257E0();
    s32 func_00125930();
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 2;
        func_00125810();
        reg_tmp.w = 0x10004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x100;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        (*(u8 *)((u8 *)(reg_a6) + (0))) = 0x84;
        func_00127CA0();
        return;
    }
    func_00125AA0();
    func_00125930();
    if ((*(s16 *)((u8 *)(reg_a6) + (2))) >= -0x200) {
        func_00125590();
        return;
    }
    func_001257E0();
}

s32 func_00125B40();

void func_00126830(void) {
    s32 func_00125590();
    s32 func_001257E0();
    s32 func_00125930();
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 4;
        func_00125810();
        reg_tmp.w = 0x50004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        (*(u8 *)((u8 *)(reg_a6) + (0))) = 0x84;
        func_00127CA0();
        return;
    }
    func_00125B40();
    func_00125930();
    if ((*(s16 *)((u8 *)(reg_a6) + (2))) >= -0x400) {
        func_00125590();
        return;
    }
    func_001257E0();
}

s32 func_00125BE0();

void func_00126900(void) {
    s32 func_00125590();
    s32 func_001257E0();
    s32 func_00125930();
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 8;
        func_00125810();
        reg_tmp.w = 0x10008;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D950();
        (*(u8 *)((u8 *)(reg_a6) + (0))) = 0x84;
        func_00127CA0();
        return;
    }
    func_00125BE0();
    func_00125930();
    if ((*(s16 *)((u8 *)(reg_a6) + (2))) >= -0x600) {
        func_00125590();
        return;
    }
    func_001257E0();
}

s32 func_001255F0();
s32 func_001258B0();
s32 func_00125C80();

void func_001269D0() {
    s32 func_001257E0();
    s32 func_00125A00();
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 1;
        func_001258B0();
        reg_tmp.w = 0x50000;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x50;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125A00();
    func_001255F0();
}

void func_00126A70() {
    s32 func_001257E0();
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 2;
        func_001258B0();
        reg_tmp.w = 0x10004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x100;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125AA0();
    func_001255F0();
}

void func_00126B10() {
    s32 func_001257E0();
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 4;
        func_001258B0();
        reg_tmp.w = 0x50004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125B40();
    func_001255F0();
}

void func_00126BB0() {
    s32 func_001257E0();
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 8;
        func_001258B0();
        reg_tmp.w = 0x10008;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125BE0();
    func_001255F0();
}

s32 func_001258F0();

void func_00126C50() {
    s32 func_001257E0();
    s32 func_00125A00();
    if (reg_d1.w & 0x800) {
        reg_d0.w = 1;
        func_001258F0();
        reg_tmp.w = 0x50000;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x50;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125A00();
    func_001255F0();
}

void func_00126CF0() {
    s32 func_001257E0();
    if (reg_d1.w & 0x800) {
        reg_d0.w = 2;
        func_001258F0();
        reg_tmp.w = 0x10004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x100;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125AA0();
    func_001255F0();
}

void func_00126D90() {
    s32 func_001257E0();
    if (reg_d1.w & 0x800) {
        reg_d0.w = 4;
        func_001258F0();
        reg_tmp.w = 0x50004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125B40();
    func_001255F0();
}

void func_00126E30() {
    s32 func_001257E0();
    if (reg_d1.w & 0x800) {
        reg_d0.w = 8;
        func_001258F0();
        reg_tmp.w = 0x10008;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125BE0();
    func_001255F0();
}
