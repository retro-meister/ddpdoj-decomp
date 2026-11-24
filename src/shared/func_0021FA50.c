#include "common.h"

extern void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern void func_0021C0F0(void);
extern void func_0021C2F0(void);
extern void func_0021FC70(void);
extern void func_0021FDB0(void);
extern void func_002201A0(void);
extern void func_00220390(void);
extern void func_002207C0(void);
extern void func_002209C0(void);
extern void func_00221000(void);
extern void func_00221080(void);
extern void func_00221360(void);
extern void func_00221440(void);
extern void func_00221550(void);
extern void func_00221E20(void);
extern void func_00225450(void);
extern void func_002278D0(void);
extern void func_00227B70(void);
extern void func_00227E00(void);
extern void func_002287E0(void);
extern void func_00228BC0(void);
extern void func_00229660(void);
extern void func_0022A0B0(void);
extern void func_0022A480(void);
#ifdef DEATH_LABEL
extern void death_func_001B9120(void);
#endif
extern s8 D_0028EB00;
extern s8 D_0028EB84;
extern s32 D_0028EB94;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0021FA50(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    if (D_0028EB00 != 0) {
        if (D_0028EB84 == 0x10) {
            func_00225450();
            return;
        }
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
        if (D_0028EB94 == 0) {
            func_00215DB0(0, 0, 0x1C2, 0xE0, 0x50, 0x60, 1, 1, 1);
            func_00221440();
        } else {
            func_00221360();
        }
        func_0021C0F0();
        func_0021FC70();
        func_0021FDB0();
        func_002201A0();
        func_00220390();
        func_002207C0();
        func_002209C0();
        func_00221000();
#ifdef DEATH_LABEL
        death_func_001B9120();
#endif
        func_00221080();
        func_002278D0();
        func_00227B70();
        func_002287E0();
        func_00228BC0();
        func_00229660();
        func_0022A0B0();
        func_0022A480();
        func_00221E20();
        func_0021C2F0();
        func_00227E00();
        func_00221550();
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
}
