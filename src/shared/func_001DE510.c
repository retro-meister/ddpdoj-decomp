#include "common.h"

typedef void (*Fn)();

extern u8 D_00261730[];
extern u8 D_00263840[];
extern u8 D_00263860[];
s32 func_00119B10();
s32 func_0011AD50();
s32 func_0014E300();
s32 func_0014E380();
s32 func_0014E7E0();
s32 func_001A3020();
s32 func_002011A0();
extern u8 D_002637F0[];
extern u8 D_00263810[];
extern s8 enemy_move_end_requested;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a3;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001DE510(void) {
    reg_a0 = (u8 *)D_00263860;
    reg_d7.w = 0;
    func_0014E380();
    reg_a0 = (u8 *)D_00263840;
    reg_d0.w = 0xB;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested != 0) {
        return;
    }
    (*(u16 *)((u8 *)(reg_a6) + (2))) -= 0x1440;
    (*(u16 *)((u8 *)(reg_a6) + (4))) -= 0x1D40;
    reg_a0 = (u8 *)D_00261730;
    reg_d0.h[0] = 0x17;
    func_001A3020();
    func_002011A0();
    if ((s8) reg_d0.b[0] < 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0))) |= 0x40;
    }
    reg_d7.w = 4;
    reg_a0 = (u8 *)func_0011AD50;
    reg_a3 = (u8 *)D_002637F0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1E)));
    if ((s8) reg_d0.b[0] < 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x1E))) = (u8) ~(s8) (*(u8 *)((u8 *)(reg_a6) + (0x1E)));
        (*(s8 *)((u8 *)(reg_a6) + (0x1D))) = 0x40;
        (*(u16 *)((u8 *)(reg_a5) + (0x1A))) *= (0xFFFF & 0xFFFF);
        (*(u16 *)((u8 *)(reg_a5) + (0x2C))) *= 0xFFFF;
        (*(u8 *)((u8 *)(reg_a5) + (0x2A))) *= -1;
        (*(u16 *)((u8 *)(reg_a6) + (4))) += 0x3A80;
        (*(u16 *)((u8 *)(reg_a5) + (4))) -= 6;
        (*(s16 *)((u8 *)(reg_a6) + (0xA0))) = 0;
        (*(s16 *)((u8 *)(reg_a6) + (0xC0))) = 0;
        (*(s16 *)((u8 *)(reg_a6) + (0xE0))) = 0;
        (*(s16 *)((u8 *)(reg_a6) + (0x100))) = 0;
        (*(s16 *)((u8 *)(reg_a6) + (0x120))) = 0;
        (*(s16 *)((u8 *)(reg_a6) + (0x140))) = 0;
        reg_d7.w = 1;
        reg_a0 = (u8 *)func_00119B10;
        reg_a3 = (u8 *)D_00263810;
    }
    reg_a6 += 0x20;
    do {
        jtbl_0028E3F4 = (Fn)(reg_a0);
        jtbl_0028E3F4();
        reg_a6 += 0x40;
        reg_a3 += 6;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
