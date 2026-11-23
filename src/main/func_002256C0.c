#include "common.h"

extern void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern void func_0021C0F0(void);
extern void func_0021C100(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern void func_0021C2F0(void);
extern u8 *D_0028DD70;
extern u8 *D_0028DD74;
extern u8 D_0028E374;
extern s16 D_0028EC5C;
extern s8 D_0028EC60;
extern s8 D_0028EC64;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_002256C0(void) {
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
    s32 x;
    s32 y;
    s32 alpha;

    if (D_0028E374 != 0) {
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
        switch (D_0028EC64) {
        case 0:
            D_0028EC5C = 0;
            D_0028EC64++;
            D_0028EC60 = 0;
        case 1:
            D_0028EC5C += 8;
            if (D_0028EC5C >= 0x80) {
                D_0028EC5C = 0x80;
                D_0028EC64++;
            }
            break;
        case 2:
            D_0028EC60++;
            if (D_0028EC60 >= 120) {
                D_0028EC60 = 0;
            }
            break;
        case 3:
            D_0028EC5C -= 8;
            if (D_0028EC5C <= 0) {
                D_0028EC5C = 0;
                D_0028EC64++;
            }
            break;
        case 4:
            D_0028E374 = 0;
            break;
        }
        alpha = D_0028EC5C;
        if (D_0028EC64 < 3 && D_0028E374 == 1) {
            func_00215DB0(0, 0, 0x1C2, 0xE0, 0x18F, 0x60, 1, 1, 1);
        }
        func_0021C0F0();
        if (D_0028E374 == 1) {
            x = 32;
            y = 104;
        } else {
            x = 96;
            y = 72;
        }
        reg_a0 = (u8 *)D_0028DD70;
        func_0021C100(x, y, 400, 0, 0x80, alpha, 1);
        if (D_0028EC60 >= 30) {
            reg_a0 = (u8 *)D_0028DD74;
            y += 88;
            func_0021C100(x, y, 400, 0, 0x80, alpha, 1);
        }
        if (D_0028EC60 >= 60) {
            reg_a0 = (u8 *)D_0028DD74;
            y += 8;
            func_0021C100(x, y, 400, 0, 0x80, alpha, 1);
        }
        if (D_0028EC60 >= 90) {
            reg_a0 = (u8 *)D_0028DD74;
            func_0021C100(x, y + 8, 400, 0, 0x80, alpha, 1);
        }
        func_0021C2F0();
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
