#include "common.h"

extern u16 D_0028E82C;
extern u16 D_0028E830;
extern u16 D_0028E834;
extern u16 D_0028E838;

void func_00137BF0(void) {
    reg_d0.w = 0;
    D_0028E838 = reg_d0.h[0];
    D_0028E834 = reg_d0.h[0];
    D_0028E830 = reg_d0.h[0];
    D_0028E82C = reg_d0.h[0];
}

extern u16 D_002BF372[];

void func_00137C10(void) {
    *(u16 *)&reg_d0 = D_002BF372[0];
}

extern s32 D_0028DE80_as_s32;
extern s16 *reg_a0_as_s16_p;
extern s16 D_002BF350[];
extern s16 D_002BF370[];

void func_00137C20(void) {
    *(s16 *)((u8 *)&D_0028DE80_as_s32 + 8) = 0;
    reg_a0_as_s16_p = D_002BF370;
    *reg_a0_as_s16_p = 0;
    reg_a0_as_s16_p = D_002BF350;
    *reg_a0_as_s16_p = 0;
    func_00137BF0();
}

extern s32 D_0028E7F8_as_s32;
extern s32 D_0028E7FC_as_s32;
extern s16 D_0028E800_as_s16;
extern s16 D_0028E804_as_s16;
extern s16 D_0028E808;
extern s16 D_0028E80C_as_s16;
extern s16 D_0028E810_as_s16;
extern s16 D_0028E814_as_s16;
extern s16 D_0028E818_as_s16;
extern s16 D_0028E81C_as_s16;
extern s16 D_0028E820_as_s16;
extern s16 D_0028E824_as_s16;
extern s16 D_0028E828_as_s16;

void func_00137C50(void) {
    D_0028E7F8_as_s32 = 0;
    D_0028E7FC_as_s32 = 0;
    D_0028E800_as_s16 = 0;
    D_0028E804_as_s16 = 0;
    D_0028E808 = 0;
    D_0028E80C_as_s16 = 0;
    D_0028E810_as_s16 = 0;
    D_0028E814_as_s16 = 0;
    D_0028E818_as_s16 = 0;
    D_0028E81C_as_s16 = 0;
    D_0028E820_as_s16 = 0;
    D_0028E824_as_s16 = 0;
    D_0028E828_as_s16 = 0;
}

#ifdef DEATH_LABEL
s32 func_00171910();
s32 func_001A2FA0();
s32 func_002071C0();
extern u8 death_D_0026EE20[];
extern u32 death_D_0026FD90[];
extern u16 D_0028E3BC;
extern u16 D_0028E3C0;
extern u32 D_0028E7F8;
extern u8 *D_0028E7FC;
extern u16 D_0028E810;
extern u16 D_0028E814;
extern u16 D_0028E818;
extern u16 D_0028E820;
extern u16 D_0028E824;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00137C90(void) {
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

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    D_0028E3C0 = 1;
    func_00137C50();
    D_0028E824 = 0x10;
    D_0028E820 = 0x960;
    reg_a0 = (u8 *) death_D_0026FD90;
    reg_d2.h[0] = D_0028E3BC;
    reg_tmp.w = death_D_0026FD90[reg_d2.h[0]];
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d7.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E818 = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E814 = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E810 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E7FC = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E7F8 = reg_tmp.w;
    reg_d0.h[0] = 0xA;
    func_002071C0();
    *(u16 *)(reg_a0 + 4) = reg_d7.h[0];
    func_00171910();
    reg_a0 = death_D_0026EE20;
    reg_d0.h[0] = 0xC;
    func_001A2FA0();
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
#else
extern s8 D_0028DEF8_as_s8;
extern s16 D_0028DEFC_as_s16;
extern s16 D_0028DF00_as_s16;
extern s8 D_0028DF08_as_s8;
extern s16 D_0028E3C0_as_s16;
extern s8 D_0028EC24;

void func_00137C90(void) {
    D_0028DF08_as_s8 = 0;
    D_0028DF00_as_s16 = 0x960;
    D_0028DEFC_as_s16 = 0;
    D_0028E3C0_as_s16 = 1;
    D_0028DEF8_as_s8 = 1;
    D_0028EC24 = 0;
}
#endif

#ifndef DEATH_LABEL
s32 func_0011C4A0();
extern u32 D_0026A290[];
extern u16 D_0028DEFC;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_00137CC0(void) {
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
    u32 temp_a1;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    reg_a0 = (u8 *)(D_0026A290);
    reg_a0 += D_0028DEFC;
    temp_a1 = *(u32 *)reg_a0;
    reg_d4.w = temp_a1;
    reg_d0.h[0] = 0x88;
    reg_d2.w = 5;
    reg_d3.w = 0x1B;
    reg_d1.h[0] = 0;
    func_0011C4A0();
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
}
#endif
