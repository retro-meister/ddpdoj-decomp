#include "common.h"
#include "entity.h"

void func_001D3810(void);
void func_001D38E0(void);
void func_001D3A20(void);
void func_001D3B70(void);


void func_001D36C0(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xF800 & 0xFFFF;
    reg_d0.h[0] += *(u16 *)(reg_a6 + 0x26);
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x7FFF + 0x7401;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x28);
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_d1.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x7801;
    reg_d0.h[0] += *(u16 *)(reg_a6 + 0x46);
    *(u16 *)(reg_a6 + 0x42) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0xC00;
    reg_d1.h[0] += *(s16 *)(reg_a6 + 0x48);
    *(u16 *)(reg_a6 + 0x44) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a6 + 0xC2) = (u16) *(u16 *)(reg_a6 + 0x22);
    *(u16 *)(reg_a6 + 0xC4) = (u16) *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0xE2) = (u16) *(u16 *)(reg_a6 + 0x42);
    *(u16 *)(reg_a6 + 0xE4) = (u16) *(u16 *)(reg_a6 + 0x44);
}

extern s16 *reg_a4_as_s16_p;
extern void *reg_a6_as_void_p;

void func_001D37D0(void)
{
    *reg_a4_as_s16_p = 0x1818;
    ((u8 *)reg_a6_as_void_p)[0x1B] = 0xC;
    ((u8 *)reg_a6_as_void_p)[0x1A] = 0xE;
    ((u16 *)reg_a6_as_void_p)[1] = 0x4400;
    ((u16 *)reg_a6_as_void_p)[2] = 0xEC00;
    func_001D3810();
}

s32 func_00124B20();
s32 func_00124C70();
s32 func_00125060(void *);
s32 func_00201C60();

void func_001D3810(void) {
    u8 temp_v1;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 1);
    *(u8 *)(reg_a4 + 1) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 1) = (u8) *(u8 *)reg_a4;
        temp_v1 = ENTITY(reg_a6)->move.b.speed;
        if (temp_v1 != 4) {
            ENTITY(reg_a6)->move.b.speed = (u8) (temp_v1 - 1);
            goto block_5;
        }
        reg_d0.w = 7;
        func_00125060(reg_a6 + 0x1B);
        if (cond_flag == 0) {
            reg_d0.w = 0;
            func_00124C70();
            reg_d0.w = 2;
            func_00124B20();
            func_001D36C0();
            return;
        }
        goto block_5;
    }
block_5:
    func_00201C60();
    func_001D36C0();
}

extern void *reg_a4_as_void_p;


void func_001D38C0(void) {
    reg_d0.w = 0;
    ((u8 *)reg_a4_as_void_p)[1] = reg_d0.b[0];
    ((u8 *)reg_a4_as_void_p)[0] = reg_d0.b[0];
    func_001D38E0();
}

s32 func_002010A0();
s32 func_002024C0();

void func_001D38E0(void) {
    func_00201C60();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3A00) {
        reg_d0.b[0] += 0x10;
        goto block_12;
    }
    if ((s32) reg_d1.h[0] >= 0x4E00) {
        reg_d0.b[0] += 0x30;
        goto block_12;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    if ((s32) reg_d1.h[0] >= 0x5C00) {
        if ((s32) reg_d1.h[0] < 0x6400) {
            func_001D36C0();
            return;
        }
        reg_d0.b[0] += 0x20;
    goto block_12;
    }
block_12:
    reg_d0.b[0] &= 0x3F;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = 1U;
    func_001D36C0();
}


void func_001D3A00(void) {
    reg_d0.w = 0;
    reg_a4[1] = reg_d0.b[0];
    reg_a4[0] = reg_d0.b[0];
    func_001D3A20();
}

void func_001D3A20(void) {
    func_00201C60();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3600) {
        reg_d0.b[0] += 0x10;
        goto block_12;
    }
    if ((s32) reg_d1.b[0] >= 0x5200) {
        reg_d0.b[0] += 0x30;
        goto block_12;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    if ((s32) reg_d1.h[0] >= 0x6600) {
        if ((s32) reg_d1.h[0] < 0x6A00) {
            func_001D36C0();
            return;
        }
        reg_d0.b[0] += 0x20;
    goto block_12;
    }
block_12:
    reg_d0.b[0] &= 0x3F;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = 1U;
    func_001D36C0();
}


void func_001D3B50(void) {
    reg_d0.w = 0;
    reg_a4[1] = reg_d0.b[0];
    reg_a4[0] = reg_d0.b[0];
    func_001D3B70();
}

void func_001D3B70(void) {
    func_00201C60();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3C00) {
        reg_d0.b[0] += 0x10;
        goto block_12;
    }
    if ((s32) reg_d1.h[0] >= 0x4C00) {
        reg_d0.b[0] += 0x30;
        goto block_12;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    if ((s32) reg_d1.h[0] >= 0x5E00) {
        if ((s32) reg_d1.h[0] < 0x6600) {
            func_001D36C0();
            return;
        }
        reg_d0.b[0] += 0x20;
    goto block_12;
    }
block_12:
    reg_d0.b[0] &= 0x3F;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = 1U;
    func_001D36C0();
}
