#include "common.h"

s32 fade_start_in();
s32 func_00221FF0();
s32 func_00224B50();
s32 memcpy();
extern s8 D_0028EB84;
extern s8 D_0028EBE8;
extern u8 D_0068DEC8[];
extern u8 D_0068DED8[];
extern u8 D_0068DEF0[];
void func_00227120(void) {
    u8 sp10[0x16];
    u8 sp30[0xA];
    u8 sp40[0xC];

    memcpy(sp10, D_0068DEF0, 0x16);
    memcpy(sp30, D_0068DED8, 0xA);
    memcpy(sp40, D_0068DEC8, 0xC);
    func_00221FF0();
    func_00224B50();
    memcpy(D_0068DEF0, sp10, 0x16);
    memcpy(D_0068DED8, sp30, 0xA);
    memcpy(D_0068DEC8, sp40, 0xC);
    D_0028EBE8 = 0;
    D_0028EB84 = 0xA;
    fade_start_in();
}
