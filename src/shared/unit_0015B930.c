#include "common.h"
#include "pad.h"

void func_0015BFD0(void);
void func_0015C090(void);
void func_0015C0E0(void);
void func_0015C170(void);
void func_0015C1F0(void);
void func_0015C250(void);
void func_0015C280(void);
void func_0015C2B0(void);
void func_0015C2E0(void);
void func_0015C310(void);
void func_0015C340(void);
void func_0015C3A0(void);
void func_0015C430(void);
void func_0015C460(void);

void func_0011BEA0(void);
void func_0012FA50(void);
void func_0012FB00(void);
extern u32 D_00268FB0[];
extern u32 g_bg_layer_as_u32_a[];
extern u8 *reg_a1;
extern u8 *reg_a2;

void func_0015B930(void) {
    u32 t1;

    func_0012FA50();
    func_0012FB00();
    func_0011BEA0();
    reg_tmp.w = 0;
    reg_a1 = (u8 *)D_00268FB0;
    reg_d6.w = 0xD;
    do {
        reg_a2 = (u8 *)g_bg_layer_as_u32_a;
        reg_a2 += reg_tmp.w;
        reg_d7.w = 6;
    loop_1:
        reg_d4.w = *(u32 *)reg_a1;
        reg_a1 += 4;
        reg_d4.h[1] += 0xC00;
        *(u32 *)reg_a2 = reg_d4.w;
        reg_a2 += 0x100;
        t1 = reg_d7.h[0] - 1;
        reg_d7.h[0] = t1;
        if (((s64)((s64)(u16)t1 << 0x30) >> 0x30) >= 0) goto loop_1;
        reg_tmp.w += 4;
        reg_tmp.h[0] = reg_tmp.b[0];
    } while ((s16)(--reg_d6.h[0]) >= 0);
}

extern s32 D_0028E7C0_as_s32;
extern s16 D_0028E7C4;
extern s16 D_0028E7C8_as_s16;
extern s16 D_0028E7CC_as_s16;
extern s16 D_0028E7D0;
extern u8 *reg_a0;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015BA20(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;

    D_0028E7C4 = 0xF0;
    save_d0 = reg_d0.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    D_0028E7C0_as_s32 = 0;
    save_d1 = reg_d1.w;
    D_0028E7C8_as_s16 = 0;
    D_0028E7CC_as_s16 = 0;
    D_0028E7D0 = 0;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    func_0015B930();
    func_0015C340();
    func_0015C3A0();
    func_0015C430();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

s32 func_0019C5B0();
extern u8 D_0026A400[];
extern u8 D_0026A440[];

void func_0015BB60() {
    u8 *var_s0;
    u32 temp_a0;
    u32 temp_a0_2;

    reg_a4 = D_0026A400;
    var_s0 = D_0026A440;
loop_1:
    temp_a0 = (*(u32 *)((u8 *)(var_s0) + (0)));
    if (temp_a0 != -1U) {
        reg_d1.w = temp_a0;
        temp_a0_2 = (*(u32 *)((u8 *)(var_s0) + (4)));
        reg_d2.w = temp_a0_2;
        reg_d3.h[0] = 0x208;
        reg_d4.h[0] = 2;
        func_0019C5B0();
        var_s0 += 8;
        goto loop_1;
    }
}

extern s8 D_0028E408;

s32 func_0013B350();
s32 func_0013C300();
s32 func_0013C350();
extern u8 D_0026A620[];
extern u8 *D_0028DF48;
extern u8 *D_0028DF4C;
extern u8 *D_0028DF50;
extern u8 *D_0028DF54;
extern u8 *D_0028DF58;
extern u8 *D_0028DF5C;
extern u8 *D_0028DF60;
extern u32 D_0028DF64;
extern u32 D_0028DF68;
extern u32 D_0028DF6C;
extern u32 D_0028DF70;
extern u32 D_0028DF74;
extern u32 D_0028DF78;
extern u32 D_0028DF7C;
extern u32 D_0028DF80;
extern u32 D_0028E7C0;
extern u16 D_0028E7CC;
extern u8 D_0028E7D1;

void func_0015BBD0(void) {
    D_0028DF80 = reg_d0.w;
    D_0028DF7C = reg_d1.w;
    D_0028DF78 = reg_d2.w;
    D_0028DF74 = reg_d3.w;
    D_0028DF70 = reg_d4.w;
    D_0028DF6C = reg_d5.w;
    D_0028DF68 = reg_d6.w;
    D_0028DF64 = reg_d7.w;
    D_0028DF60 = (u8 *)(reg_a0);
    D_0028DF5C = reg_a1;
    D_0028DF58 = reg_a2;
    D_0028DF54 = reg_a3;
    D_0028DF50 = reg_a4;
    D_0028DF4C = reg_a5;
    D_0028DF48 = reg_a6;
    if (!(D_0028E7D1 & 1)) {
        D_0028E7D1 |= 1;
        reg_a0 = (u8 *)D_0026A620;
        func_0013B350();
        D_0028E7C0 = reg_d0.w;
    }
    if (!(D_0028E7D1 & 2)) {
        reg_d0.w = D_0028E7C0;
        func_0013C350();
        if (D_0028E408 == 0) {
            func_0013C300();
            reg_d0.w = 0;
            D_0028E7CC = 1;
            D_0028E7C0 = reg_d0.w;
            D_0028E7D1 |= 2;
        }
    }
    if (D_0028E7CC == 0) {
        func_0015C090();
        return;
    }
    func_0015BFD0();
}

s32 func_001A31D0();
extern u8 D_002687B0[];
extern u16 D_0028E7C8;

void func_0015BD00(void) {
    D_0028DF80 = reg_d0.w;
    D_0028DF7C = reg_d1.w;
    D_0028DF78 = reg_d2.w;
    D_0028DF74 = reg_d3.w;
    D_0028DF70 = reg_d4.w;
    D_0028DF6C = reg_d5.w;
    D_0028DF68 = reg_d6.w;
    D_0028DF64 = reg_d7.w;
    D_0028DF60 = (u8 *)(reg_a0);
    D_0028DF5C = reg_a1;
    D_0028DF58 = reg_a2;
    D_0028DF54 = reg_a3;
    D_0028DF50 = reg_a4;
    D_0028DF4C = reg_a5;
    D_0028DF48 = reg_a6;
    if (D_0028E7C8 != 0) {
        func_0015C090();
        return;
    }
    reg_d0.h[0] = 0;
    D_0028E7C8 = 1;
    reg_a0 = (u8 *)D_002687B0;
    func_001A31D0();
    func_0015C1F0();
    func_0015C090();
}

void func_0015BDD0(void) {
    D_0028DF80 = reg_d0.w;
    D_0028DF7C = reg_d1.w;
    D_0028DF78 = reg_d2.w;
    D_0028DF74 = reg_d3.w;
    D_0028DF70 = reg_d4.w;
    D_0028DF6C = reg_d5.w;
    D_0028DF68 = reg_d6.w;
    D_0028DF64 = reg_d7.w;
    D_0028DF60 = reg_a0;
    D_0028DF5C = reg_a1;
    D_0028DF58 = reg_a2;
    D_0028DF54 = reg_a3;
    D_0028DF50 = reg_a4;
    D_0028DF4C = reg_a5;
    D_0028DF48 = reg_a6;
    reg_a0 = (u8 *)D_002687B0;
    reg_d0.h[0] = 0;
    func_001A31D0();
    func_0015C1F0();
    reg_d0.w = D_0028DF80;
    reg_d1.w = D_0028DF7C;
    reg_d2.w = D_0028DF78;
    reg_d3.w = D_0028DF74;
    reg_d4.w = D_0028DF70;
    reg_d5.w = D_0028DF6C;
    reg_d6.w = D_0028DF68;
    reg_d7.w = D_0028DF64;
    reg_a0 = (u8 *)D_0028DF60;
    reg_a1 = (u8 *)D_0028DF5C;
    reg_a2 = (u8 *)D_0028DF58;
    reg_a3 = (u8 *)D_0028DF54;
    reg_a4 = (u8 *)D_0028DF50;
    reg_a5 = (u8 *)D_0028DF4C;
    reg_a6 = (u8 *)D_0028DF48;
}

#ifndef DEATH_LABEL
void func_0015BEF0(void) {
    D_0028DF80 = reg_d0.w;
    D_0028DF7C = reg_d1.w;
    D_0028DF78 = reg_d2.w;
    D_0028DF74 = reg_d3.w;
    D_0028DF70 = reg_d4.w;
    D_0028DF6C = reg_d5.w;
    D_0028DF68 = reg_d6.w;
    D_0028DF64 = reg_d7.w;
    D_0028DF60 = (u8 *)(reg_a0);
    D_0028DF5C = reg_a1;
    D_0028DF58 = reg_a2;
    D_0028DF54 = reg_a3;
    D_0028DF50 = reg_a4;
    D_0028DF4C = reg_a5;
    D_0028DF48 = reg_a6;
    if (D_0028E7C8 != 0) {
        func_0015BFD0();
        return;
    }
    reg_d0.h[0] = 0;
    D_0028E7C8 = 1;
    D_0028E7C4 = 0x258;
    reg_a0 = (u8 *)D_002687B0;
    func_001A31D0();
    func_0015C1F0();
    func_0015C090();
}
#endif

s32 func_0013BE50();                            /* extern */
s32 func_0013C300();                            /* extern */
s32 func_0013C350();                            /* extern */
extern s32 D_0026A660[];
extern u8 g_stage_load_state;
extern u16 D_0028E7C4_as_u16;
extern s32 *reg_a0_as_s32_p;

void func_0015BFD0(void) {
    if (D_0028E7C4_as_u16 != 0) {
        if (g_stage_load_state == 0) {
            D_0028E7C4_as_u16 -= 1;
        }
        if (g_pad_held[2] != 0) {
            D_0028E7C4_as_u16 = 0x258;
        }
        if (D_0028E7C4_as_u16 != 0) {
            func_0015C090();
            return;
        }
        reg_a0_as_s32_p = D_0026A660;
        func_0013BE50();
        D_0028E7C0 = reg_d0.w;
        func_0015C090();
        return;
    }
    reg_d0.w = D_0028E7C0;
    func_0013C350();
    if (D_0028E408 != 0) {
        func_0015C090();
        return;
    }
    func_0013C300();
    func_0015C170();
}


void func_0015C090(void) {
    func_0015C280();
    func_0015C250();
    func_0015C2B0();
    func_0015C2E0();
    func_0015C310();
    func_0015BB60();
    func_0015C0E0();
}

void func_0015C0E0(void) {
    reg_d0.w = D_0028DF80;
    reg_d1.w = D_0028DF7C;
    reg_d2.w = D_0028DF78;
    reg_d3.w = D_0028DF74;
    reg_d4.w = D_0028DF70;
    reg_d5.w = D_0028DF6C;
    reg_d6.w = D_0028DF68;
    reg_d7.w = D_0028DF64;
    reg_a0 = (u8 *)D_0028DF60;
    reg_a1 = (u8 *)D_0028DF5C;
    reg_a2 = (u8 *)D_0028DF58;
    reg_a3 = (u8 *)D_0028DF54;
    reg_a4 = (u8 *)D_0028DF50;
    reg_a5 = (u8 *)D_0028DF4C;
    reg_a6 = (u8 *)D_0028DF48;
    D_0028E408 = 1;
}

extern s32 D_0028DF48_as_s32;

extern s32 D_0028DF4C_as_s32;

extern s32 D_0028DF50_as_s32;

extern s32 D_0028DF54_as_s32;

extern s32 D_0028DF58_as_s32;

extern s32 D_0028DF5C_as_s32;

extern s32 D_0028DF60_as_s32;
extern s32 reg_a0_as_s32;
extern s32 reg_a1_as_s32;
extern s32 reg_a2_as_s32;
extern s32 reg_a3_as_s32;
extern s32 reg_a4_as_s32;
extern s32 reg_a5_as_s32;
extern s32 reg_a6_as_s32;

void func_0015C170(void) {
    reg_d0.w = D_0028DF80;
    reg_d1.w = D_0028DF7C;
    reg_d2.w = D_0028DF78;
    reg_d3.w = D_0028DF74;
    reg_d4.w = D_0028DF70;
    reg_d5.w = D_0028DF6C;
    reg_d6.w = D_0028DF68;
    reg_d7.w = D_0028DF64;
    reg_a0_as_s32 = D_0028DF60_as_s32;
    reg_a1_as_s32 = D_0028DF5C_as_s32;
    reg_a2_as_s32 = D_0028DF58_as_s32;
    reg_a3_as_s32 = D_0028DF54_as_s32;
    reg_a4_as_s32 = D_0028DF50_as_s32;
    reg_a5_as_s32 = D_0028DF4C_as_s32;
    reg_a6_as_s32 = D_0028DF48_as_s32;
    D_0028E408 = 0;
}

extern u8 D_0025F770[];
extern u8 D_002623F0[];
extern u8 D_00262430[];

extern void func_001A3020(void);

void func_0015C1F0(void)
{
    reg_a0 = D_00262430;
    reg_d0.h[0] = 0;
    func_001A3020();

    reg_a0 = D_002623F0;
    reg_d0.h[0] = 1;
    func_001A3020();

    reg_a0 = D_0025F770;
    reg_d0.h[0] = 2;
    func_001A3020();
}

extern void func_0019C430(void);
void func_0015C250(void) {
    reg_d1.w = 0x0E000200;
    reg_d2.sw = 0x155C;
    reg_d4.sh[0] = 0;
    reg_d3.sh[0] = 0x30C0;
    func_0019C430();
}

extern Reg32 reg_d1;
void func_0019C430(void);

void func_0015C280(void) {
    reg_d1.w = 0x1A000800;
    reg_d2.sw = 0x155A;
    reg_d3.sh[0] = 0x20A0;
    reg_d4.sh[0] = 1;
    func_0019C430();
}

void func_0015C2B0(void) {
    reg_d1.w = 0x4A001C00;
    reg_d2.sw = 0x1559;
    reg_d4.sh[0] = 0;
    reg_d3.sh[0] = 0x260;
    func_0019C430();
}

void func_0015C2E0(void) {
    reg_d1.w = 0x64003000;
    reg_d2.sw = 0x1558;
    reg_d4.sh[0] = 0;
    reg_d3.sh[0] = 0x410;
    func_0019C430();
}

void func_0015C310(void) {
    reg_d1.w = 0x04000400;
    reg_d2.sw = 0x155B;
    reg_d4.sh[0] = 0;
    reg_d3.sh[0] = 0x620;
    func_0019C430();
}

extern u8 D_0028E38C;
extern u8 *D_0026A690[];


void func_0015C340(void)
{
    extern void func_00137AD0(void);
    reg_d0.w = 0;
    reg_a0 = (u8 *)D_0026A690;
    reg_d0.b[0] = D_0028E38C;
    reg_d0.w += reg_d0.w;
    reg_d0.w += reg_d0.w;
    reg_a0 = *(u8 **)(reg_a0 + reg_d0.h[0]);
    reg_d1.h[0] = 0xD;
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    func_00137AD0();
}

extern u8 D_0026A720[];
extern u8 D_0028E388;

void func_0015C3A0(void) {
    s32 func_00137AD0();
    u16 temp_a0;

    reg_a0 = D_0026A720;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E388;
    reg_d0.w += reg_d0.w;
    reg_d0.w += reg_d0.w;
    temp_a0 = reg_d0.h[0];
    reg_a0 = *(u8 **)((u8 *)reg_a0 + temp_a0);
    reg_d1.h[0] = 0xF;
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    func_00137AD0();
}

#ifdef DEATH_LABEL
void func_00137AD0(void);
extern u8 D_0028E380;
extern u8 death_D_002901F0[];
extern u8 *reg_a0;
#endif

void func_0015C430(void) {
#ifdef DEATH_LABEL
    reg_d0.w = 0;
    reg_a0 = death_D_002901F0;
    reg_d0.b[0] = D_0028E380;
    reg_d0.w += reg_d0.w;
    reg_d0.w += reg_d0.w;
    reg_a0 = *(u8 **)(reg_a0 + reg_d0.h[0]);
    reg_d1.h[0] = 0xC;
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    func_00137AD0();
#endif
}


extern void func_001713F0(s32);

void func_0015C440(void) {
    func_001713F0(0);
}


void func_0015C450(void) {
    func_0015C460();
}

extern void func_0014E290(void);

void func_0015C460(void) {
    func_0014E290();
}
