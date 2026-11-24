#include "common.h"

typedef struct {
    s16 x;
    s16 y;
} Point;

extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern void func_0021C0F0(void);
extern void func_0021C100(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern void func_0021C2F0(void);
extern void func_00223D70(void);
extern void func_00223E80(void);
extern void func_00224BA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags);
extern void func_00225450(void);
extern u8 *D_002716B0[];
extern u8 *D_00271710[];
extern u8 *D_00271740[];
extern Point D_00271C90[];
extern u8 *D_0028DD18[2];
extern u8 *D_0028DD48[2];
extern u8 D_0028E27C;
extern u8 D_0028E28C;
extern u16 D_0028E32C;
extern u8 D_0028E354;
extern u8 D_0028E358;
extern u8 D_0028E36C;
extern s8 D_0028EBD0;
extern u8 D_0028ED80;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_002244E0(void) {
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
    s32 n;

    if (D_0028E36C != 0 && D_0028E36C != 0x63) {
        if (D_0028E36C == 0xB) {
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
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x60, 1, 1, 1);
        func_00223D70();
        func_00223E80();
        func_0021C0F0();
        x = D_00271C90[0].x;
        y = D_00271C90[0].y;
        reg_a0 = D_00271710[0];
        func_0021C100(x, y, 300, 0, 0x80, 0x80, 1);
        x = D_00271C90[1].x;
        y = D_00271C90[1].y;
        reg_a0 = D_00271710[1];
        func_0021C100(x, y, 300, 0, 0x80, 0x80, 1);
        if (D_0028E358 == 0) {
            reg_a0 = D_002716B0[D_0028E354];
        } else {
            reg_a0 = D_0028DD48[D_0028E354];
        }
        func_0021C100(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (D_0028EBD0 == 1) {
            func_00224BA0(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        x = D_00271C90[2].x;
        y = D_00271C90[2].y;
        reg_a0 = D_00271710[2];
        func_0021C100(x, y, 300, 0, 0x80, 0x80, 1);
        reg_a0 = D_0028DD18[D_0028E27C];
        func_0021C100(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (D_0028EBD0 == 2) {
            func_00224BA0(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        x = D_00271C90[3].x;
        y = D_00271C90[3].y;
        reg_a0 = D_00271710[3];
        func_0021C100(x, y, 300, 0, 0x80, 0x80, 1);
        reg_a0 = D_00271740[D_0028E32C];
        func_0021C100(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (D_0028EBD0 == 3) {
            func_00224BA0(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        x = D_00271C90[4].x;
        y = D_00271C90[4].y;
        reg_a0 = D_00271710[4];
        func_0021C100(x, y, 300, 0, 0x80, 0x80, 1);
        reg_a0 = D_0028DD18[D_0028E28C];
        func_0021C100(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (D_0028EBD0 == 4) {
            func_00224BA0(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        reg_a0 = D_00271710[5];
        func_0021C100(D_00271C90[5].x, D_00271C90[5].y, 300, 0, 0x80, 0x80, 1);
        n = 6;
        if (D_0028ED80 != 0) {
            n++;
            reg_a0 = D_00271710[6];
            func_0021C100(D_00271C90[6].x, D_00271C90[6].y, 300, 0, 0x80, 0x80, 1);
        }
        x = D_00271C90[n].x;
        reg_a0 = D_00271710[7];
        func_0021C100(x, D_00271C90[n].y, 300, 0, 0x80, 0x80, 1);
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
