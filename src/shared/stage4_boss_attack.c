#include "common.h"
#include "entity.h"

void func_001D7A20(void);
void func_001D7BD0(void);
void func_001D9BA0(void);
void func_001DA3C0(void);
void func_001DA580();
void func_001DAA00(void);
void func_001DAC50(void);
void func_001DAD20();
void func_001DAF90(void);
void func_001DB060(void);
void func_001DB2B0();
void func_001DB480(void);
void func_001DBA40(void);
void func_001DBBE0(void);
void func_001DBF10(void);


void func_001D7880(void) {
    ENTITY(reg_a6)[6].offset_y.h += 1;
    if ((s16) ENTITY(reg_a6)[6].offset_y.h >= 0x18) {
        ENTITY(reg_a6)[6].offset_y.h = 0U;
    }
}


void func_001D78C0(void)
{
    *(u16 *)((u8 *)((void *)reg_a6) + 0xC6) -= 1;
    if (0 > *(s16 *)((u8 *)((void *)reg_a6) + 0xC6)) {
        *(u16 *)((u8 *)((void *)reg_a6) + 0xC6) = 0x17;
    }
}

void func_001D7900(void)
{
    s16 *frameCounter;

    --*(u16 *)((u8 *)((void *)reg_a6) + 0xE6);

    frameCounter = (s16 *)((u8 *)((void *)reg_a6) + 0xE6);
    if (0 > *frameCounter) {
        *frameCounter = 0x17;
    }
}

extern u16 D_0026EBF0[];
extern u8 D_0026EC60[];

void func_001D7940(void) {
    u8 temp_a1;

    if ((s16)(reg_d0.h[0]) > 0x17) {
        reg_d0.h[0] -= 0x18;
    }
    reg_d1.w = 0;
    temp_a1 = *(D_0026EC60 + reg_d0.h[0]);
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)(D_0026EBF0);
    reg_d1.b[0] = temp_a1;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
}


void func_001D7A10(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    func_001D7A20();
}

s32 bullet_fire256();

void func_001D7A20(void) {
    u16 t;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[6].offset_y.h += 1;
        if (ENTITY(reg_a6)[6].offset_y.h == 0x18) {
            ENTITY(reg_a6)[6].offset_y.h = 0U;
        }
        reg_d0.h[0] = ENTITY(reg_a6)[6].offset_y.h;
        t = reg_d0.h[0];
        reg_d1.w = 0;
        reg_d1.b[0] = D_0026EC60[t];
        reg_d0.h[0] = t + t;
        reg_a0 = (u8 *)(D_0026EBF0);
        reg_d0.h[0] += reg_d0.h[0];
        reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.w = 7;
        reg_d2.h[1] = ENTITY(reg_a6)[6].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[6].x.h;
        bullet_fire256();
    }
}

extern void (*jtbl_0026EC80[])(void);

void func_001D7B70(void)
{
    reg_d0.h[0] = ((u16 *)((void *)reg_a4))[1];
    reg_d0.h[0] <<= 1;
    jtbl_0026EC80[(u16)reg_d0.h[0]]();
    func_001D7BD0();
}

typedef void (*Fn)(void);
extern Fn jtbl_0026EC80[];

void func_001D7BD0(void) {
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += 1;
    (*(Fn *)((u8 *)jtbl_0026EC80 + (reg_d0.h[0] << 2)))();
}

void func_001D7C20(s32 id) {
    *(u16 *)(reg_a4 + 4) = 0;
    *(u16 *)(reg_a4 + 6) = 1;
    *(u16 *)(reg_a4 + 8) = 0;
    *(u16 *)(reg_a4 + 0xA) = 0;
    reg_tmp.w = id;
    (*(u8 *)(reg_a6 + reg_tmp.h[0] + ((reg_tmp.h[0] & 1) ? -1 : 1)))++;
}


void func_001D7C80(void) {
    func_001D7C20(0x186);
}

typedef void (*Fn)();

extern Fn reg_call_target_as_Fn;

#define LOOKUP(d) (((d) != 0) ? *(u16 *)(reg_a6 + ((s16)(d) & ~1)) : ENTITY(reg_a6)->flags.h)

void func_001D7C90(u32 arg0, u32 arg1, s32 (*arg2)(void *), s32 arg3) {
    reg_tmp.b[0] = reg_a4[5];
    reg_a4[5] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_2;
    reg_a4[5] = reg_a4[4];
    reg_call_target_as_Fn = (Fn) arg2;
    reg_call_target_as_Fn();
    reg_tmp.w = arg0;
    reg_d0.h[0] = LOOKUP(reg_tmp.h[0]);
    func_001D7940();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    reg_d7.h[0] = reg_d1.h[0];
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] -= 9;
    bullet_fire256();
    reg_d1.b[0] -= 3;
    bullet_fire256();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d7.b[0] += 0x20;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.w -= 0x10000;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] -= 9;
    bullet_fire256();
    reg_d1.b[0] -= 3;
    bullet_fire256();
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d0.h[0] += 8;
    func_001D7940();
    reg_d7.h[0] = reg_d1.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] -= 9;
    bullet_fire256();
    reg_d1.b[0] -= 3;
    bullet_fire256();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d7.b[0] += 0x20;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.w -= 0x10000;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] -= 9;
    bullet_fire256();
    reg_d1.b[0] -= 3;
    bullet_fire256();
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d0.h[0] += 0x10;
    func_001D7940();
    reg_d7.h[0] = reg_d1.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] -= 9;
    bullet_fire256();
    reg_d1.b[0] -= 3;
    bullet_fire256();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d7.b[0] += 0x20;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.w -= 0x10000;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] -= 9;
    bullet_fire256();
    reg_d1.b[0] -= 3;
    bullet_fire256();
    *(u16 *)(reg_a4 + 0xA) += 1;
    if (*(s16 *)(reg_a4 + 0xA) < 3) goto next_1;
    *(u16 *)(reg_a4 + 0xA) = 0;
next_1:
    *(u16 *)(reg_a4 + 6) -= 1;
    if (*(s16 *)(reg_a4 + 6) != 0) goto next_2;
    *(u16 *)reg_a4 = 0;
next_2:;
}



void func_001D8260(void) {
    func_001D7C90(0xC6, 0xC2, (void *)func_001D7880, 0x186);
}

void func_001D8280(s32 byteOffset)
{
    u8 *counter;

    *(u16 *)(reg_a4 + 4) = 0;
    *(u16 *)(reg_a4 + 6) = 1;
    *(u16 *)(reg_a4 + 8) = 0;
    *(u16 *)(reg_a4 + 10) = 0;
    counter = reg_a6 + byteOffset + (!(byteOffset & 1) ? 1 : -1);
    *counter += 1;
}


void func_001D82D0(void) {
    func_001D8280(0x186);
}

s32 bullet_fire256_fast();

#define LOOKUP(d) (((d) != 0) ? *(u16 *)(reg_a6 + ((s16)(d) & ~1)) : ENTITY(reg_a6)->flags.h)

void func_001D82E0(arg0, arg1, arg2)
    u32 arg0;
    u32 arg1;
    s32 (*arg2)(void *);
{
    reg_tmp.b[0] = reg_a4[5];
    reg_a4[5] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_2;
    reg_a4[5] = reg_a4[4];
    reg_call_target_as_Fn = (Fn) arg2;
    reg_call_target_as_Fn();
    reg_d0.h[0] = LOOKUP(arg0);
    func_001D7940();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 0xA;
    bullet_fire256_fast();
    reg_d1.b[0] += 0xA;
    bullet_fire256_fast();
    reg_d1.b[0] -= 0x1E;
    bullet_fire256_fast();
    reg_d1.b[0] -= 0xA;
    bullet_fire256_fast();
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d0.h[0] += 8;
    func_001D7940();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 0xA;
    bullet_fire256_fast();
    reg_d1.b[0] += 0xA;
    bullet_fire256_fast();
    reg_d1.b[0] -= 0x1E;
    bullet_fire256_fast();
    reg_d1.b[0] -= 0xA;
    bullet_fire256_fast();
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d0.h[0] += 0x10;
    func_001D7940();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    bullet_fire256_fast();
    reg_d1.b[0] += 0xA;
    bullet_fire256_fast();
    reg_d1.b[0] += 0xA;
    bullet_fire256_fast();
    reg_d1.b[0] -= 0x1E;
    bullet_fire256_fast();
    reg_d1.b[0] -= 0xA;
    bullet_fire256_fast();
    *(u16 *)(reg_a4 + 0xA) += 1;
    if (*(s16 *)(reg_a4 + 0xA) < 3) goto next_1;
    *(u16 *)(reg_a4 + 0xA) = 0;
next_1:
    *(u16 *)(reg_a4 + 6) -= 1;
    if (*(s16 *)(reg_a4 + 6) != 0) goto next_2;
    *(u16 *)reg_a4 = 0;
next_2:;
}


void func_001D86E0(void) {
    func_001D82E0(0xC6, 0xC2, (void *)(&func_001D7880), 0x186);
}

void func_001D8700(void) {
    *(u16 *)(reg_a4 + 0x4) = 0x2020;
    *(u16 *)(reg_a4 + 0x6) = 5;
    *(u16 *)(reg_a4 + 0x8) = 4;
    *(u8 *)(reg_a4 + 0xB) = 0;
}


void func_001D8730(void) {
    func_001D8700();
}

s32 rng_next();
s32 rng_next_unsigned();
extern u8 D_0026ECC0[];

void func_001D8740(s32 arg0, s32 arg1, void *arg2) {
    s32 aim256_at_player();
    u32 saved;
    u32 idx;

    reg_call_target = (Fn)(arg2);
    reg_call_target();
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    *(u8 *)(reg_a4 + 5) = *(u8 *)(reg_a4 + 4);
    if (*(u8 *)(reg_a4 + 0xB) != 0) goto next_0;
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : ENTITY(reg_a6)->flags.h;
    func_001D7940();
    saved = reg_d3.w;
    reg_d0.h[0] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    reg_d0.h[0] += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    aim256_at_player();
    reg_d3.w = saved;
    rng_next();
    reg_d1.b[0] += reg_d0.b[0];
    rng_next_unsigned();
    reg_d0.h[0] &= 3;
    idx = reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 0xB;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    ((Fn)*(u32 *)((u8 *)D_0026ECC0 + (idx * 4)))();
next_0:
    if (*(u8 *)(reg_a4 + 0xB) != 1) goto next_1;
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 8;
    func_001D7940();
    saved = reg_d3.w;
    reg_d0.h[0] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    reg_d0.h[0] += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    aim256_at_player();
    reg_d3.w = saved;
    rng_next();
    reg_d1.b[0] += reg_d0.b[0];
    rng_next_unsigned();
    reg_d0.h[0] &= 3;
    idx = reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 0xB;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    ((Fn)*(u32 *)((u8 *)D_0026ECC0 + (idx * 4)))();
next_1:
    if (*(u8 *)(reg_a4 + 0xB) != 2) goto next_2;
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 0x10;
    func_001D7940();
    saved = reg_d3.w;
    reg_d0.h[0] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    reg_d0.h[0] += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    aim256_at_player();
    reg_d3.w = saved;
    rng_next();
    reg_d1.b[0] += reg_d0.b[0];
    rng_next_unsigned();
    reg_d0.h[0] &= 3;
    idx = reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 0xB;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    ((Fn)*(u32 *)((u8 *)D_0026ECC0 + (idx * 4)))();
next_2:
    *(u8 *)(reg_a4 + 0xB) += 1;
    if (*(u8 *)(reg_a4 + 0xB) != 3) goto next_3;
    *(u8 *)(reg_a4 + 0xB) = 0;
next_3:
    *(u16 *)(reg_a4 + 6) -= 1;
    if (*(s16 *)(reg_a4 + 6) != 0) return;
    *(u16 *)reg_a4 = 0;
}


void func_001D8DC0(void) {
    func_001D8740(0xC6, 0xC2, (void *)func_001D7880);
}

s32 bullet_fire256_double();

void func_001D8DE0(void) {
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
}

void func_001D8E40(void) {
    u32 temp_s0;

    temp_s0 = reg_d0.sw;
    reg_d7.sw = temp_s0;
    rng_next_unsigned();
    reg_d0.b[0] &= 7;
    reg_d0.b[0] += 3;
    reg_d6.b[0] = reg_d0.b[0];
    reg_d0.sw = temp_s0;
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d1.b[0] += reg_d6.b[0];
    reg_d0.sw = reg_d7.sw;
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256_double(reg_d6.b[0]);
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
}

s32 bullet_fire256_2way();
void func_001D8F40(void) {
    u32 temp_s0;

    temp_s0 = reg_d0.w;
    reg_d7.w = temp_s0;
    rng_next_unsigned();
    reg_d0.b[0] &= 0xF;
    reg_d0.b[0] += 6;
    reg_d6.b[0] = reg_d0.b[0];
    reg_d0.w = temp_s0;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d1.b[0] -= reg_d6.b[0];
    reg_d0.w = reg_d7.w;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d1.b[0] += reg_d6.b[0];
    reg_d0.w = reg_d7.w;
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
}

void func_001D9090(void) {
    *(s16 *)(reg_a4 + 4) = 0x4000;
    *(s16 *)(reg_a4 + 6) = 0x909;
    *(s16 *)(reg_a4 + 8) = 7;
    *(s16 *)(reg_a4 + 0xA) = 0;
    *(s16 *)(reg_a4 + 0xC) = 0;
}


void func_001D90D0(void) {
    func_001D9090();
}


void func_001D90E0(s32 first, s32 second, void (*callback)(void), s8 *table) {
    reg_call_target = (Fn) callback;
    reg_call_target();
    reg_a0 = (u8 *)table;
    reg_a0 += *(u16 *) (reg_a4 + 0xC);
    reg_d7.b[0] = *(s8 *)reg_a0;
    reg_tmp.b[0] = *(u8 *) (reg_a4 + 5);
    *(u8 *) (reg_a4 + 5) -= 1;
    if (reg_tmp.b[0] > 0) return;
    *(u8 *) (reg_a4 + 5) = *(u8 *) (reg_a4 + 4);
    if (*(u16 *) (reg_a4 + 0xA) != 0) goto next_1;
    reg_d0.h[0] = (first) ? *(u16 *) (reg_a6 + ((s16) first & ~1)) : *(u16 *) reg_a6;
    func_001D7940();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d0.h[0] = *(u16 *) (reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (second) ? *(u16 *) (reg_a6 + ((s16) second & ~1)) : *(u16 *) reg_a6;
    reg_d2.h[0] = (second + 2) ? *(u16 *) (reg_a6 + ((s16) (second + 2) & ~1)) : *(u16 *) reg_a6;
    reg_d4.w = 0;
    bullet_fire256();
next_1:
    if (*(u16 *) (reg_a4 + 0xA) != 1) goto next_2;
    reg_d0.h[0] = (first) ? *(u16 *) (reg_a6 + ((s16) first & ~1)) : *(u16 *) reg_a6;
    reg_d0.h[0] += 8;
    func_001D7940();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d0.h[0] = *(u16 *) (reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (second) ? *(u16 *) (reg_a6 + ((s16) second & ~1)) : *(u16 *) reg_a6;
    reg_d2.h[0] = (second + 2) ? *(u16 *) (reg_a6 + ((s16) (second + 2) & ~1)) : *(u16 *) reg_a6;
    reg_d4.w = 0;
    bullet_fire256();
next_2:
    if (*(u16 *) (reg_a4 + 0xA) != 2) goto next_3;
    reg_d0.h[0] = (first) ? *(u16 *) (reg_a6 + ((s16) first & ~1)) : *(u16 *) reg_a6;
    reg_d0.h[0] += 0x10;
    func_001D7940();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d0.h[0] = *(u16 *) (reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (second) ? *(u16 *) (reg_a6 + ((s16) second & ~1)) : *(u16 *) reg_a6;
    reg_d2.h[0] = (second + 2) ? *(u16 *) (reg_a6 + ((s16) (second + 2) & ~1)) : *(u16 *) reg_a6;
    reg_d4.w = 0;
    bullet_fire256();
next_3:
    *(u16 *) (reg_a4 + 8) += 1;
    *(u16 *) (reg_a4 + 0xA) += 1;
    if (*(s16 *) (reg_a4 + 0xA) <= 2) goto next_4;
    *(u16 *) (reg_a4 + 0xA) = 0;
next_4:
    *(u8 *) (reg_a4 + 7) -= 1;
    if (*(s8 *) (reg_a4 + 7) != 0) return;
    *(u8 *) (reg_a4 + 7) = *(u8 *) (reg_a4 + 6);
    *(u8 *) (reg_a4 + 5) = 4;
    *(u16 *) (reg_a4 + 0xA) = 0;
    *(u16 *) (reg_a4 + 8) = 6;
    *(u16 *) (reg_a4 + 0xC) += 1;
    if (*(u16 *) (reg_a4 + 0xC) != 3) return;
    *(s16 *) (reg_a4 + 0) = 0;
}

extern s32 D_0028DC60[];

void func_001D9500(void) {
    func_001D90E0(0xC6, 0xC2, (void *)func_001D7880, (void *)D_0028DC60);
}

#define LOOKUP(d) (((d) != 0) ? *(u16 *)(reg_a6 + ((s16)(d) & ~1)) : ENTITY(reg_a6)->flags.h)

void func_001D9520(arg0, arg1)
    u32 arg0;
    u8 arg1;
{
    s32 aim256_at_player();
    *(u16 *)(reg_a4 + 4) = 4;
    *(u16 *)(reg_a4 + 6) = 0x50;
    *(u16 *)(reg_a4 + 8) = -4;
    *(u16 *)(reg_a4 + 0xA) = 0x40;
    *(u16 *)(reg_a4 + 0xC) = 2;
    *(u16 *)(reg_a4 + 0x10) = 0;
    *(u16 *)(reg_a4 + 0x12) = 0xC;
    *(u16 *)(reg_a4 + 0x14) = 5;
    reg_a4[0x17] = 0;
    reg_a4[0x16] = arg1;
    reg_a4[0x19] = 1;
    *(u16 *)(reg_a4 + 0x1A) = 0x808;
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d1.h[0] = LOOKUP(arg0 + 2);
    aim256_at_player();
    reg_a4[0xF] = reg_d1.b[0];
    reg_d0.b[0] = reg_a4[0x16];
    reg_d0.b[0] = (s8) reg_d0.b[0] * 0x10;
    reg_a4[0xF] -= reg_d0.b[0];
}


void func_001D9660(void) {
    func_001D9520(0xC2, -1);
}

void func_001D9670(arg0, arg1, arg2)
    s32 arg0;
    s32 arg1;
    void *arg2;
{
    if (*(u8 *)(reg_a4 + 0x17) != 0) goto next_0;
    if (*(s16 *)(reg_a4 + 0xA) <= 0x10) goto next_1;
    reg_call_target = (Fn)(arg2);
    reg_call_target();
next_1:
    *(u16 *)(reg_a4 + 0xA) -= 1;
    if (*(s16 *)(reg_a4 + 0xA) != 0) goto next_0;
    *(u8 *)(reg_a4 + 0x17) = 1;
next_0:
    if (*(u8 *)(reg_a4 + 0x17) != 1) return;
    *(u8 *)(reg_a4 + 0x19) += 1;
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    *(u8 *)(reg_a4 + 5) = *(u8 *)(reg_a4 + 4);
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : ENTITY(reg_a6)->flags.h;
    func_001D7940();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    reg_d7.b[0] = *(u8 *)(reg_a4 + 0x19);
    reg_d1.b[0] -= reg_d7.b[0];
    bullet_fire256();
    reg_d0.h[0] = 9;
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire256();
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 8;
    func_001D7940();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    reg_d7.b[0] = *(u8 *)(reg_a4 + 0x19);
    reg_d1.b[0] -= reg_d7.b[0];
    bullet_fire256();
    reg_d0.h[0] = 9;
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire256();
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 0x10;
    func_001D7940();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    reg_d7.b[0] = *(u8 *)(reg_a4 + 0x19);
    reg_d1.b[0] -= reg_d7.b[0];
    bullet_fire256();
    reg_d0.h[0] = 9;
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire256();
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x1B);
    *(u8 *)(reg_a4 + 0x1B) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_2;
    *(u8 *)(reg_a4 + 0x1B) = *(u8 *)(reg_a4 + 0x1A);
    *(u16 *)(reg_a4 + 8) += 1;
next_2:
    *(u16 *)(reg_a4 + 6) -= 1;
    if (*(s16 *)(reg_a4 + 6) != 0) return;
    *(s16 *)reg_a4 = 0;
}



void func_001D9B20(void) {
    func_001D9670(0xC6, 0xC2, (void *)func_001D78C0, 0x188);
}

extern void (*jtbl_0026ECD0[])(void);

void func_001D9B40(void)
{
    reg_d0.h[0] = ((u16 *)((void *)reg_a4))[1];
    reg_d0.h[0] *= 2;
    jtbl_0026ECD0[(u16)reg_d0.h[0]]();
    func_001D9BA0();
}

extern Fn jtbl_0026ECD0[];

void func_001D9BA0(void) {
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += 1;
    (*(Fn *)((u8 *)jtbl_0026ECD0 + (reg_d0.h[0] << 2)))();
}

void func_001D9BF0(void) {
    func_001D7C20(0x187);
}


void func_001D9C00(void) {
    func_001D7C90(0xE6, 0xE2, (void *)(&func_001D7900), 0x187);
}

void func_001D9C20(void) {
    func_001D8280(0x187);
}



void func_001D9C30(void) {
    func_001D82E0(0xE6, 0xE2, (void *)func_001D7900, 0x187);
}

void func_001D9C50(void) {
    func_001D8700();
}


void func_001D9C60(void) {
    func_001D8740(0xE6, 0xE2, (void *)func_001D7900);
}

void func_001D9C80(void) {
    func_001D9090();
}

extern s32 D_0028DC64[];

void func_001D9C90(void) {
    func_001D90E0(0xE6, 0xE2, (void *)func_001D7900, (void *)D_0028DC64);
}


void func_001D9CB0(void) {
    func_001D9520(0xE2, 1);
}


void func_001D9CC0(void) {
    func_001D9670(0xE6, 0xE2, (void *)func_001D7900, 0x189);
}

void func_001D9CE0(void) {
    s32 aim256_at_player(s32, s32);
    *(s16 *)(reg_a4 + 4) = 0xC20;
    *(s8 *)(reg_a4 + 7) = 3;
    *(s8 *)(reg_a4 + 9) = 8;
    reg_d0.h[0] = ENTITY(reg_a6)[8].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[8].x.h;
    aim256_at_player(3, 0xC20);
    *(u8 *)(reg_a4 + 6) = (u8) reg_d1.b[0];
}

extern u16 D_00259570[];
extern u16 g_bullets_blocked;

void func_001D9D40(void) {
    s32 aim256_at_player();
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        if (g_bullets_blocked == 0) {
            reg_d0.h[0] = ENTITY(reg_a6)[8].y.h;
            reg_d1.h[0] = ENTITY(reg_a6)[8].x.h;
            aim256_at_player();
            *(u8 *)(reg_a4 + 6) = (u8) reg_d1.b[0];
            reg_a0 = (u8 *)(D_00259570);
            reg_d1.w = 0;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 6);
            reg_d1.b[0] = (u8) ((s8) reg_d1.b[0] >> 2);
            reg_d1.b[0] += 1;
            reg_d1.h[0] &= 0x3E;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 6);
            reg_d0.w = 0xFFFC000B;
            reg_d2.h[1] = ENTITY(reg_a6)[8].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[8].x.h;
            reg_d4.w = 0;
            bullet_fire256();
            reg_d6.w = 2;
            do {
                reg_d1.b[0] += *(u8 *)(reg_a4 + 7);
                bullet_fire256();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_d1.b[0] += *(u8 *)(reg_a4 + 7);
            reg_d1.b[0] += *(u8 *)(reg_a4 + 7);
            reg_d1.b[0] += *(u8 *)(reg_a4 + 7);
            reg_d0.w -= 0x40000;
            reg_d0.h[0] = 0xB;
            reg_d6.w = 5;
            do {
                reg_d1.b[0] += *(u8 *)(reg_a4 + 9);
                bullet_fire256();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_d0.w = 0xFFFC000B;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 6);
            reg_d6.w = 2;
            do {
                reg_d1.b[0] -= *(u8 *)(reg_a4 + 7);
                bullet_fire256();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_d1.b[0] -= *(u8 *)(reg_a4 + 7);
            reg_d1.b[0] -= *(u8 *)(reg_a4 + 7);
            reg_d1.b[0] -= *(u8 *)(reg_a4 + 7);
            reg_d0.w -= 0x40000;
            reg_d0.h[0] = 0xB;
            reg_d6.w = 5;
            do {
                reg_d1.b[0] -= *(u8 *)(reg_a4 + 9);
                bullet_fire256();
            } while ((s16)(--reg_d6.h[0]) >= 0);
        }
    }
}

void func_001DA070(s32 arg0, s32 arg1) {
    reg_d0.h[0] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : ENTITY(reg_a6)->flags.h;
    func_001D7940();
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1F);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (arg1 != 0) ? *(u16 *)(reg_a6 + ((s16) arg1 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d0.h[0] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 8;
    func_001D7940();
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1F);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (arg1 != 0) ? *(u16 *)(reg_a6 + ((s16) arg1 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d0.h[0] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 0x10;
    func_001D7940();
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1F);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (arg1 != 0) ? *(u16 *)(reg_a6 + ((s16) arg1 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
}


void func_001DA370(void) {
    *(s16 *)(reg_a4 + 4) = 0x404;
    *(s16 *)(reg_a4 + 6) = 0x1040;
    *(s16 *)(reg_a4 + 8) = 0x10;
    *(s16 *)(reg_a4 + 0xA) = 0;
    *(s16 *)(reg_a4 + 0xC) = 5;
    *(s8 *)(reg_a4 + 0x1F) = 0;
    func_001DA3C0();
}


void func_001DA3C0(void) {
    s32 aim256_at_player();
    u16 t;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_1;
    *(u8 *)(reg_a4 + 5) = *(u8 *)(reg_a4 + 4);
    func_001D7880();
    func_001D7900();
next_1:
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a4 + 7) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    *(u8 *)(reg_a4 + 7) = *(u8 *)(reg_a4 + 6);
    reg_d0.h[0] = ENTITY(reg_a6)[6].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[6].x.h;
    aim256_at_player();
    *(u8 *)(reg_a4 + 0x1F) = reg_d1.b[0];
    func_001DA070(0xC6, 0xC2);
    *(u8 *)(reg_a4 + 0x1F) += 0x18;
    func_001DA070(0xC6, 0xC2);
    *(u8 *)(reg_a4 + 0x1F) -= 0x30;
    func_001DA070(0xC6, 0xC2);
    reg_d0.h[0] = ENTITY(reg_a6)[7].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[7].x.h;
    aim256_at_player();
    *(u8 *)(reg_a4 + 0x1F) = reg_d1.b[0];
    func_001DA070(0xE6, 0xE2);
    *(u8 *)(reg_a4 + 0x1F) += 0x18;
    func_001DA070(0xE6, 0xE2);
    *(u8 *)(reg_a4 + 0x1F) -= 0x30;
    func_001DA070(0xE6, 0xE2);
    t = *(u16 *)(reg_a4 + 0xA);
    if (t == 3) goto next_2;
    *(u16 *)(reg_a4 + 0xA) = t + 1;
    if ((s16) *(u16 *)(reg_a4 + 0xA) < 3) goto block_rts;
    *(u16 *)(reg_a4 + 6) = 0x5020;
block_rts:
    return;
next_2:
    *(u16 *)(reg_a4 + 0xC) -= 1;
    if ((s16) *(u16 *)(reg_a4 + 0xC) != 0) return;
    *(s16 *)(reg_a4 + 0) = 0;
}


void func_001DA570(void) {
    *(u16 *)(reg_a4 + 6) = 0;
    func_001DA580();
}

s32 func_0014E030();
extern u8 D_0026EBD0[];
extern u8 D_0026EBE0[];

void func_001DA580(arg1)
    u8 arg1;
{
    u16 temp_a0;
    u16 temp_a0_3;
    u32 temp_a0_2;
    u32 temp_a0_4;
    u8 var_a1;

    var_a1 = arg1;
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        if (*(u8 *)(reg_a4 + 3) & 1) {
            reg_a3 = (u8 *)D_0026EBD0;
            temp_a0 = *(u16 *)(reg_a4 + 6);
            reg_a3 += temp_a0;
            reg_d0.w = 0x41;
            func_0014E030();
            reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
            temp_a0_2 = reg_d2.w;
            reg_tmp.h[1] = *(u16 *)reg_a3;
            reg_tmp.h[0] = *(u16 *)(reg_a3 + 2);
            reg_d2.w = temp_a0_2 + reg_tmp.w;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
            rng_next();
            reg_d0.b[0] += 0x20;
            *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
            rng_next();
            reg_d1.b[0] = 0x30;
            reg_d1.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d1.b[0];
        }
        if (*(u8 *)(reg_a4 + 3) & 2) {
            reg_a3 = (u8 *)D_0026EBE0;
            temp_a0_3 = *(u16 *)(reg_a4 + 6);
            reg_a3 += temp_a0_3;
            reg_d0.w = 0x41;
            func_0014E030();
            reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
            temp_a0_4 = reg_d2.w;
            reg_tmp.h[1] = *(u16 *)reg_a3;
            reg_tmp.h[0] = *(u16 *)(reg_a3 + 2);
            reg_d2.w = temp_a0_4 + reg_tmp.w;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
            rng_next();
            reg_d0.b[0] += 0x20;
            *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
            rng_next();
            reg_d1.b[0] = 0x10;
            reg_d1.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d1.b[0];
        }
        *(u16 *)(reg_a4 + 6) += 4;
        *(u16 *)(reg_a4 + 6) &= 0xF;
        *(u16 *)(reg_a4 + 8) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 8) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

void func_001DA7A0(s16 arg0) {
    *(s16 *)(reg_a4 + 4) = arg0;
    reg_a4[5] += 0x40;
    *(s16 *)(reg_a4 + 6) = 0x202;
}

void func_001DA7D0(s32 arg0, s32 arg1) {
    s32 aim256_at_player();
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    *(u8 *)(reg_a4 + 5) = *(u8 *)(reg_a4 + 4);
    reg_d0.h[0] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] = ((arg0 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg0 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 0xF940;
    reg_d1.h[0] += arg1;
    aim256_at_player();
    reg_d2.h[1] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg0 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg0 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d3.w = arg1 + 0xF9400000;
    reg_d4.w = 0;
    reg_d0.w = 4;
    bullet_fire256();
    reg_d1.b[0] += 6;
    bullet_fire256();
    reg_d1.b[0] += 6;
    bullet_fire256();
    reg_d1.b[0] -= 0x12;
    bullet_fire256();
    reg_d1.b[0] -= 6;
    bullet_fire256();
    *(u8 *)(reg_a4 + 7) -= 1;
    if (*(s8 *)(reg_a4 + 7) != 0) goto block_rts;
    *(u8 *)(reg_a4 + 7) = *(u8 *)(reg_a4 + 6);
    *(u8 *)(reg_a4 + 5) = 0x40;
block_rts:
    return;
}


void func_001DA9C0(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x303;
    *(s16 *)(reg_a4 + 6) = 0x606;
    *(s8 *)(reg_a4 + 0x11) = 0;
    *(s8 *)(reg_a4 + 0x10) = 0;
    func_001DAA00();
}

extern u16 g_loop;

void func_001DAA00(void) {
    s32 bullet_fire256_fixed();
    u16 temp_a1;
    u16 temp_a2;
    u8 temp_a0;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
        temp_a1 = ENTITY(reg_a6)[4].x.h;
        reg_d2.h[0] = temp_a1;
        reg_d3.w = 0xF94001C0;
        reg_d4.w = 0;
        reg_d1.w = 0;
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
        reg_d0.w = 0xFFFC0016;
        if (g_loop == 0) {
            bullet_fire256();
            reg_d1.b[0] += 0x55;
            bullet_fire256();
            reg_d1.b[0] += 0x55;
            bullet_fire256();
        } else {
            bullet_fire256_fixed();
            reg_d1.b[0] += 0x40;
            bullet_fire256_fixed();
            reg_d1.b[0] += 0x40;
            bullet_fire256_fixed();
            reg_d1.b[0] += 0x40;
            bullet_fire256_fixed();
        }
        reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
        temp_a2 = ENTITY(reg_a6)[5].x.h;
        reg_d2.h[0] = temp_a2;
        reg_d3.w = 0xF93FFE40;
        reg_d4.w = 0;
        reg_d1.w = 0;
        temp_a0 = *(u8 *)(reg_a4 + 0x10);
        reg_d1.b[0] = temp_a0;
        reg_d0.w = 0xFFFC0016;
        if (g_loop == 0) {
            bullet_fire256();
            reg_d1.b[0] += 0x55;
            bullet_fire256();
            reg_d1.b[0] += 0x55;
            bullet_fire256();
        } else {
            bullet_fire256_fixed();
            reg_d1.b[0] += 0x40;
            bullet_fire256_fixed();
            reg_d1.b[0] += 0x40;
            bullet_fire256_fixed();
            reg_d1.b[0] += 0x40;
            bullet_fire256_fixed();
        }
        *(u8 *)(reg_a4 + 0x11) -= 4;
        *(u8 *)(reg_a4 + 0x10) += 4;
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            *(u8 *)(reg_a4 + 0x11) -= 4;
            *(u8 *)(reg_a4 + 0x10) += 4;
        }
    }
}


void func_001DAC20(void) {
    func_001DA7A0(0x1020);
    func_001DAC50();
}

extern s16 *reg_a4_as_s16_p;

void func_001DAC50(void) {
    if (ENTITY(reg_a6)[4].misc.b.draw_layer != 0) {
        *reg_a4_as_s16_p = 0;
        return;
    }
    func_001DA7D0(0xA2, -0x1C0);
}


void func_001DAC90(void) {
    *(s16 *)(reg_a4 + 2) = 0x40D;
    *(s16 *)(reg_a4 + 4) = 0x40;
    *(s16 *)(reg_a4 + 6) = 1;
    *(s16 *)(reg_a4 + 8) = 0x410;
    *(s16 *)(reg_a4 + 0xA) = 0x10;
    *(s16 *)(reg_a4 + 0xC) = 1;
    *(s8 *)(reg_a4 + 0x11) = 0;
    *(s8 *)(reg_a4 + 0x10) = 0;
    *(s8 *)(reg_a4 + 0x13) = 0;
    *(s8 *)(reg_a4 + 0x12) = 0x18;
    *(s8 *)(reg_a4 + 0x15) = 0;
    *(u8 *)(reg_a4 + 0x14) = 0xEC;
    *(s8 *)(reg_a4 + 0x17) = 0;
    *(s8 *)(reg_a4 + 0x16) = 0;
    func_001DAD20(0x18, 0x10, 0x410, 1);
}


void func_001DAD20() {
    s32 aim256_at_player();
    if (*(u8 *)(reg_a4 + 7) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            goto block_3;
        }
    } else {
block_3:
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0x12);
            *(u8 *)(reg_a4 + 0x13) += reg_d0.b[0];
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x13);
            reg_d1.b[0] = 0x40;
            reg_d3.w = 0xF9400200;
            reg_d0.w = 0;
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 5;
            reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
            reg_d4.w = 0;
            reg_d7.b[0] = *(u8 *)(reg_a4 + 0x17);
            func_001DAF90();
            *(u8 *)(reg_a4 + 7) -= 1;
        }
    }
    if (*(u8 *)(reg_a4 + 0xD) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
        *(u8 *)(reg_a4 + 9) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0x14);
            *(u8 *)(reg_a4 + 0x15) += reg_d0.b[0];
            goto block_8;
        }
    } else {
block_8:
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
        *(u8 *)(reg_a4 + 0xB) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
            reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
            reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
            reg_d0.h[0] += 0xF940;
            reg_d1.h[0] += 0xFE00;
            aim256_at_player();
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x15);
            reg_d1.b[0] = 0xC0;
            reg_d0.w = 0;
            reg_d3.w = 0xF93FFE00;
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0x10);
            reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 5;
            reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
            reg_d4.w = 0;
            reg_d7.b[0] = *(u8 *)(reg_a4 + 0x16);
            func_001DAF90();
            *(u8 *)(reg_a4 + 0xD) -= 1;
        }
    }
}

s32 bullet_fire256();                            /* extern */

void func_001DAF90(void) {
    u32 temp_s0;

    temp_s0 = reg_d1.w;
    reg_d6.b[0] = reg_d1.b[0];
    reg_d1.b[0] += 4;
    bullet_fire256();
    reg_d1.b[0] += 8;
    bullet_fire256();
    reg_d1.b[0] = reg_d6.b[0];
    reg_d1.b[0] -= 4;
    bullet_fire256();
    reg_d1.b[0] -= 8;
    bullet_fire256();
    reg_d1.w = temp_s0;
}

extern s16 g_enemy_signal_e_as_s16;

void func_001DB000(void) {
    *(s16 *)(reg_a4 + 2) = 0x820;
    *(s16 *)(reg_a4 + 4) = 0;
    *(s16 *)(reg_a4 + 6) = 0xC;
    *(s8 *)(reg_a4 + 9) = 3;
    *(s8 *)(reg_a4 + 8) = 0x48;
    g_enemy_signal_e_as_s16 = 0;
    *(s16 *)(reg_a4 + 0x10) = 0x50;
    ENTITY(reg_a6)[12].misc.sh = 0;
    func_001DB060();
}

extern u8 D_0026ED10[];
extern u16 g_enemy_signal_e;

void func_001DB060(void) {
    s8 var_a0;
    u8 temp_v1;

    temp_v1 = *(u8 *)(reg_a4 + 3);
    if (temp_v1 != 0) {
        *(u8 *)(reg_a4 + 3) = (u8) (temp_v1 - 1);
        if ((s8) *(u8 *)(reg_a4 + 3) == 0) {
            rng_next_unsigned();
            reg_a3 = (u8 *)D_0026ED10;
            reg_d0.h[0] &= 7;
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_a3 += reg_d0.h[0];
            reg_tmp.h[1] = *(u16 *)reg_a3;
            reg_tmp.h[0] = *(u16 *)(reg_a3 + 2);
            reg_a3 = (u8 *) reg_tmp.w;
            reg_d6.b[0] = (u8) (s8) *(s8 *)reg_a3;
            reg_a3 += 1;
            reg_d7.w = 0;
            var_a0 = (s8) *(s8 *)reg_a3;
            reg_d7.b[0] = (u8) var_a0;
            reg_a3 += 1;
            *(u16 *)(reg_a4 + 4) = (u16) reg_d7.h[0];
            reg_d7.h[0] -= 1;
            do {
                reg_d0.w = 0x42;
                func_0014E030();
                var_a0 = 0xFF;
                reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
                reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
                *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
                *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
                *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d6.b[0];
                *(s8 *)(reg_a0 + 0x1A) = (s8) *(s8 *)reg_a3;
                reg_a3 += 1;
                reg_tmp.w = (u32) reg_a6;
                *(u16 *)(reg_a0 + 0x1C) = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a0 + 0x1E) = (u16) reg_tmp.h[0];
                *(u8 *)(reg_a0 + 0x21) = (u8) *(u8 *)(reg_a4 + 8);
                *(u8 *)(reg_a0 + 0x20) = 0xFFU;
            } while ((s16)(--reg_d7.h[0]) >= 0);
        }
    }
    reg_d0.h[0] = ENTITY(reg_a6)[12].misc.h;
    if ((*(u16 *)(reg_a4 + 4) == reg_d0.h[0]) && (g_enemy_signal_e == 0)) {
        *(u16 *)(reg_a4 + 0x10) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 0x10) == 0) {
            g_enemy_signal_e = 1;
            *(s16 *)reg_a4 = 0;
        }
    }
}

extern u16 g_enemy_signal_c;

void func_001DB260(void)
{
    ((u16 *)((void *)reg_a4))[1] = 0x820;
    ((u16 *)((void *)reg_a4))[2] = 4;
    ((u16 *)((void *)reg_a4))[3] = 0xC;
    ((u8 *)((void *)reg_a4))[9] = 0x48;
    ((u8 *)((void *)reg_a4))[8] = 0xA0;
    g_enemy_signal_c = 0;
    func_001DB2B0();
}

extern u8 D_0028DC68[];

void func_001DB2B0(arg1)
    u8 *arg1;
{
    u8 *var_a0;
    u8 *var_a1;
    var_a1 = (u8 *)(arg1);
    var_a0 = (u8 *)(reg_a4);
    (*(u8 *)((u8 *)(var_a0) + (3))) -= 1;
    if ((s8) *(u8 *)(reg_a4 + 3) == 0) {
        reg_a3 = (u8 *)D_0028DC68;
        reg_tmp.h[1] = *(u16 *)reg_a3;
        reg_tmp.h[0] = *(u16 *)(reg_a3 + 2);
        reg_a3 = (u8 *) reg_tmp.w;
        reg_d6.b[0] = (u8) (s8) *(s8 *)reg_a3;
        reg_a3 += 1;
        reg_d7.w = 0;
        reg_d7.b[0] = (u8) (s8) *(s8 *)reg_a3;
        reg_a3 += 1;
        reg_d7.h[0] -= 1;
        do {
            reg_d0.w = 0x42;
            func_0014E030();
            reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
            *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d6.b[0];
            *(s8 *)(reg_a0 + 0x1A) = (s8) *(s8 *)reg_a3;
            var_a1 = (u8 *)(reg_a3 + 1);
            reg_a3 = var_a1;
            reg_tmp.w = (u32) reg_a6;
            *(u16 *)(reg_a0 + 0x1C) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x1E) = (u16) reg_tmp.h[0];
            *(u8 *)(reg_a0 + 0x21) = (u8) *(u8 *)(reg_a4 + 9);
            *(s8 *)(reg_a0 + 0x20) = (s8) *(s8 *)reg_a3;
            var_a0 = (u8 *)(reg_a3 + 1);
            reg_a3 = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        *(s16 *)reg_a4 = 0;
    }
}


void func_001DB420(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x4008;
    *(s16 *)(reg_a4 + 6) = 4;
    *(s16 *)(reg_a4 + 8) = 0xA;
    *(s8 *)(reg_a4 + 0xB) = 8;
    *(s8 *)(reg_a4 + 0xA) = 0;
    *(s16 *)(reg_a4 + 0xC) = 0;
    *(s16 *)(reg_a4 + 0xE) = 0;
    func_001DB480();
}

extern u8 D_0026ED90[];
s32 enemy_switch_target_player();
extern u16 D_0026ED98[];
extern u8 D_0026EDA0[];
extern u8 D_0026EDA8[];

void func_001DB480(void) {
    s32 aim256_at_player();
    u16 *t1;
    u16 t2;
    u16 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u16 t7;
    u8 t8;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        if (*(u8 *)(reg_a4 + 9) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
                reg_a0 = (u8 *)D_0026ED90;
                reg_a0 += *(u16 *)(reg_a4 + 0xC);
                reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
                reg_d0.h[0] += *(u16 *)reg_a0;
                reg_a0 += 2;
                reg_d1.h[0] += *(u16 *)reg_a0;
                aim256_at_player();
                *(u8 *)(reg_a4 + 0xA) = (u8) reg_d1.b[0];
                rng_next();
                *(u8 *)(reg_a4 + 0xA) += reg_d0.b[0];
                *(u8 *)(reg_a4 + 0xB) = 0U;
                goto next_1;
            }
        } else {
next_1:
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                reg_d0.w = 0;
                reg_d0.b[0] = *(u8 *)(reg_a4 + 0xB);
                reg_d1.w = 0;
                reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
                t5 = reg_d0.h[0];
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = t5;
                reg_d0.h[0] = 0x13;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xA);
                reg_a0 = (u8 *)D_0026ED90;
                reg_a0 += *(u16 *)(reg_a4 + 0xC);
                reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
                reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
                reg_d3.h[1] = *(u16 *)reg_a0;
                reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
                reg_d4.w = 0;
                reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xC);
                reg_tmp.h[0] += ENTITY(reg_a6)[12].attr.h;
                ((Fn)*(u32 *)((u8 *)D_0026EDA0 + (reg_tmp.h[0] & ~3)))();
                *(u8 *)(reg_a4 + 9) -= 1;
                if ((s8) *(u8 *)(reg_a4 + 9) == 0) {
                    *(u16 *)(reg_a4 + 0xC) += 4;
                    *(u16 *)(reg_a4 + 0xC) &= 0xF;
                    if ((s16) *(u16 *)(reg_a4 + 0xC) == 0) {
                        *(u16 *)(reg_a4 + 4) = 0x3002;
                        *(u16 *)(reg_a4 + 8) = 0xA;
                        *(u8 *)(reg_a4 + 0xB) = 8U;
                        *(u8 *)(reg_a4 + 3) = 1U;
                        reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
                        reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
                        aim256_at_player();
                        *(u8 *)(reg_a4 + 0xA) = (u8) reg_d1.b[0];
                        rng_next();
                        *(u8 *)(reg_a4 + 0xA) += reg_d0.b[0];
                        enemy_switch_target_player();
                    }
                }
            }
        }
    }
    t8 = *(u8 *)(reg_a4 + 3);
    if (t8 == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            if (*(u16 *)(reg_a4 + 0xE) == 0) {
                enemy_switch_target_player();
                *(u16 *)(reg_a4 + 0xE) = 1U;
                reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
                aim256_at_player();
                *(u8 *)(reg_a4 + 0xA) = (u8) reg_d1.b[0];
            }
            reg_a3 = (u8 *)(D_0026ED98);
            reg_a2 = (u8 *)D_0026EDA8;
            reg_a2 += ENTITY(reg_a6)[12].attr.h;
            reg_d7.w = 1;
            do {
                reg_d0.w = 0;
                reg_d0.b[0] = *(u8 *)(reg_a4 + 0xB);
                reg_d1.w = 0;
                reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
                t7 = reg_d0.h[0];
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = t7;
                reg_d0.h[0] = 0x13;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xA);
                reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
                t6 = ENTITY(reg_a6)[1].x.h;
                reg_d2.h[0] = t6;
                t3 = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d3.h[1] = t3;
                t4 = *(u16 *)reg_a3;
                t1 = (u16 *)(reg_a3 + 2);
                reg_d3.h[0] = t4;
                reg_a3 = (u8 *)(t1);
                reg_d4.w = 0;
                reg_a0 = *(u8 **)reg_a2;
                reg_a2 += 4;
                reg_call_target = (Fn)(reg_a0);
                reg_call_target();
            } while ((s16)(--reg_d7.h[0]) >= 0);
            *(u16 *)(reg_a4 + 8) -= 1;
            if (*(s16 *)(reg_a4 + 8) == 0) {
                *(s16 *)reg_a4 = 0;
                t2 = ENTITY(reg_a6)[12].attr.h;
                if (t2 != 0x10) {
                    ENTITY(reg_a6)[12].attr.h = (u16) (t2 + 8);
                }
            }
        }
    }
}

void func_001DB8F0(void) {
    void bullet_fire256_fixed(void);
    bullet_fire256_fixed();
}

void func_001DB900(void) {
    s32 bullet_fire256_fixed();
    reg_d1.b[0] -= 0xA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0x14;
    bullet_fire256_fixed();
}

void func_001DB940(void) {
    s32 bullet_fire256_fixed();
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xE;
    bullet_fire256_fixed();
    reg_d1.b[0] -= 0x1C;
    bullet_fire256_fixed();
}

void func_001DB980(void) {
    s32 bullet_fire256_fixed();
    reg_d1.b[0] -= 9;
    bullet_fire256_fixed();
    reg_d1.b[0] -= 0x12;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0x24;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0x12;
    bullet_fire256_fixed();
}


void func_001DB9E0(void) {
    s32 aim256_at_player(s32);
    *(s16 *)(reg_a4 + 4) = 0xC20;
    *(s8 *)(reg_a4 + 7) = 7;
    reg_d0.h[0] = ENTITY(reg_a6)[8].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[8].x.h;
    aim256_at_player(0xC20);
    *(u8 *)(reg_a4 + 6) = (u8) reg_d1.b[0];
    func_001DBA40();
}

void func_001DBA40(void) {
    s32 aim256_at_player();
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        reg_d0.h[0] = ENTITY(reg_a6)[8].y.h;
        reg_d1.h[0] = ENTITY(reg_a6)[8].x.h;
        aim256_at_player();
        *(u8 *)(reg_a4 + 6) = (u8) reg_d1.b[0];
        reg_d0.w = 0x4000C;
        reg_d2.h[1] = ENTITY(reg_a6)[8].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[8].x.h;
        reg_d3.w = 0;
        reg_d4.w = 0;
        bullet_fire256();
        reg_d0.w = 0x4000C;
        reg_d1.b[0] = *(u8 *)(reg_a4 + 6);
        reg_d6.w = 7;
        do {
            reg_d1.b[0] += *(u8 *)(reg_a4 + 7);
            bullet_fire256();
        } while ((s16)(--reg_d6.h[0]) >= 0);
        reg_d0.w = 0x4000C;
        reg_d1.b[0] = *(u8 *)(reg_a4 + 6);
        reg_d6.w = 7;
        do {
            reg_d1.b[0] -= *(u8 *)(reg_a4 + 7);
            bullet_fire256();
        } while ((s16)(--reg_d6.h[0]) >= 0);
    }
}


void func_001DBB90(void)
{
    reg_a4[0x3] = 0;
    *(u16 *)(reg_a4 + 0x4) = 0x20;
    *(u16 *)(reg_a4 + 0x6) = 0x808;
    *(u16 *)(reg_a4 + 0x8) = 1;
    *(u16 *)(reg_a4 + 0xA) = 0;
    reg_a4[0x8] = reg_a4[0x10];
    func_001DBBE0();
}

extern u8 D_0028DC78[];

void func_001DBBE0(void) {
    u16 temp_a3;

    if (*(u8 *)(reg_a4 + 9) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            goto block_3;
        }
    } else {
block_3:
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            reg_d0.h[0] = 8;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 0xB;
            reg_d1.w = 0x80;
            reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
            temp_a3 = ENTITY(reg_a6)[1].x.h;
            reg_d2.h[0] = temp_a3;
            reg_d3.w = 0x08000000;
            reg_d7.h[0] = reg_d1.h[0];
            reg_d4.w = 0;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xA);
            ((Fn)*(u32 *)((u8 *)D_0028DC78 + (reg_tmp.h[0] & ~3)))();
            *(u16 *)(reg_a4 + 0xA) += 4;
            *(u16 *)(reg_a4 + 0xA) &= 7;
            *(u8 *)(reg_a4 + 9) -= 1;
            if ((s8) *(u8 *)(reg_a4 + 9) == 0) {
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

void func_001DBD30(void) {
    s32 bullet_fire256_fixed();
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
}

void func_001DBE00(void) {
    s32 bullet_fire256_fixed();
    reg_d1.b[0] += 3;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0xFD;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
}


void func_001DBEC0(void)
{
    ((u8 *)((void *)reg_a4))[3] = 0;
    ((u16 *)((void *)reg_a4))[2] = 0x404;
    ((u16 *)((void *)reg_a4))[3] = 0x303;
    ((u16 *)((void *)reg_a4))[4] = 5;
    ((u16 *)((void *)reg_a4))[5] = 0;
    ((u16 *)((void *)reg_a4))[6] = 0x8000;
    ((u16 *)((void *)reg_a4))[7] = 0;
    func_001DBF10();
}


extern u8 D_0026EDC0[];

void func_001DBF10(void) {
    s32 aim256_at_player();
    if (*(u8 *)(reg_a4 + 9) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            *(u8 *)(reg_a4 + 8) += 1;
            rng_next_unsigned();
            reg_d0.h[0] &= 3;
            *(u16 *)(reg_a4 + 0xA) = (u16) reg_d0.h[0];
            *(u16 *)(reg_a4 + 0xE) = 0U;
            reg_a0 = D_0026EDC0;
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 += reg_d0.h[0];
            reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
            reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
            reg_d0.h[0] += *(u16 *)reg_a0;
            reg_d1.h[0] += *(u16 *)(reg_a0 + 2);
            aim256_at_player();
            if (cond_flag == 0) {
                *(u8 *)(reg_a4 + 0xD) = (u8) reg_d1.b[0];
            }
            goto block_4;
        }
    } else {
block_4:
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            reg_a0 = D_0026EDC0;
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 += reg_d0.h[0];
            reg_d3.h[1] = *(u16 *)reg_a0;
            reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_d1.w = 0;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 0x13;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0xD);
            reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
            reg_d4.w = 0;
            bullet_fire256_fast();
            *(u16 *)(reg_a4 + 0xE) += 2;
            *(u8 *)(reg_a4 + 9) -= 1;
            if ((s8) *(u8 *)(reg_a4 + 9) == 0) {
                enemy_switch_target_player();
                *(u16 *)(reg_a4 + 0x10) -= 1;
                if ((s16) *(u16 *)(reg_a4 + 0x10) == 0) {
                    *(s16 *)reg_a4 = 0;
                }
            }
        }
    }
}
