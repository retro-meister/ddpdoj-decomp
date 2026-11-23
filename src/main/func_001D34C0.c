#include "common.h"

typedef void (*Fn)();

s32 func_00124B20();
s32 func_00124F00();
s32 func_0013A780();
s32 func_0018D500();
s32 func_0018D520();
s32 func_00201160();
s32 func_002011A0();
s32 func_002013F0();
extern u8 D_0026D9C0[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D34C0(void) {
    u16 temp_a2;
    u16 temp_v1;

    temp_v1 = (*(u16 *)((u8 *)(reg_a4) + (2)));
    if (temp_v1 != 0) {
        (*(u16 *)((u8 *)(reg_a4) + (2))) = (u16) (temp_v1 - 1);
        if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
            reg_d0.w = 8;
            func_00124F00();
        }
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
        reg_a0 = (u8 *)func_0018D500;
        func_002011A0();
        if ((s8) reg_d0.b[0] >= 0) {
            reg_a0 = (u8 *)func_0018D520;
        }
        jtbl_0028E3F4 = (Fn)(reg_a0);
        jtbl_0028E3F4();
        func_002011A0();
        reg_d0.h[0] &= 7;
        reg_d0.h[0] = *(u16 *)(D_0026D9C0 + (reg_d0.h[0] * 2));
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a2;
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x800;
        (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 2;
        func_00201160();
        reg_d0.b[0] += 0x60;
        (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
        (*(s16 *)((u8 *)(reg_a0) + (0x20))) = 0;
        (*(u16 *)((u8 *)(reg_a0) + (0x22))) = 0xFFF9;
        func_002013F0();
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += 0x7FFF + 0x6641;
        (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_d1.h[0];
        func_002013F0();
        reg_d0.h[0] = reg_d1.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a4) + (6))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (6))) < 0) {
            reg_d0.w = 8;
            func_00124B20();
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
