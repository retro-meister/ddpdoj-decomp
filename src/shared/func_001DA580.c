#include "common.h"

s32 func_0014E030();
s32 func_002010A0();
extern u8 D_0026EBD0[];
extern u8 D_0026EBE0[];
extern u8 *reg_a0;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DA580(u8 arg1) {
    u16 temp_a0;
    u16 temp_a0_3;
    u32 temp_a0_2;
    u32 temp_a0_4;
    u8 var_a1;

    var_a1 = arg1;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
        if ((*(u8 *)((u8 *)(reg_a4) + (3))) & 1) {
            reg_a3 = (u8 *)D_0026EBD0;
            temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (6)));
            reg_a3 += temp_a0;
            reg_d0.w = 0x41;
            func_0014E030();
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
            temp_a0_2 = reg_d2.w;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a3) + (0)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a3) + (2)));
            reg_d2.w = temp_a0_2 + reg_tmp.w;
            (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d2.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d2.h[0];
            func_002010A0();
            reg_d0.b[0] += 0x20;
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d0.b[0];
            func_002010A0();
            reg_d1.b[0] = 0x30;
            reg_d1.b[0] += reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d1.b[0];
        }
        if ((*(u8 *)((u8 *)(reg_a4) + (3))) & 2) {
            reg_a3 = (u8 *)D_0026EBE0;
            temp_a0_3 = (*(u16 *)((u8 *)(reg_a4) + (6)));
            reg_a3 += temp_a0_3;
            reg_d0.w = 0x41;
            func_0014E030();
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
            temp_a0_4 = reg_d2.w;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a3) + (0)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a3) + (2)));
            reg_d2.w = temp_a0_4 + reg_tmp.w;
            (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d2.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d2.h[0];
            func_002010A0();
            reg_d0.b[0] += 0x20;
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d0.b[0];
            func_002010A0();
            reg_d1.b[0] = 0x10;
            reg_d1.b[0] += reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d1.b[0];
        }
        (*(u16 *)((u8 *)(reg_a4) + (6))) += 4;
        (*(u16 *)((u8 *)(reg_a4) + (6))) &= 0xF;
        (*(u16 *)((u8 *)(reg_a4) + (8))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (8))) == 0) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
