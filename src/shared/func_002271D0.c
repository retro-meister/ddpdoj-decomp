#include "common.h"

s32 fade_start_in();
s32 func_00221FF0();
s32 func_00224B50();
s32 func_00227C90();
s32 func_00227CD0();
s32 func_00227E30();
s32 memcpy();
extern s8 D_0028EB84;
extern u8 D_0028EBE0;
extern u8 D_0028EC30;
extern u8 D_0068DEC8[];
extern u8 D_0068DED8[];
extern u8 D_0068DEF0[];
void func_002271D0(void) {
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
    if (D_0028EC30 == 0) {
        D_0028EBE0 = 0;
        D_0028EB84 = 0xB;
        func_00227C90();
    } else {
        D_0028EBE0 = 0;
        D_0028EB84 = 0x16;
        func_00227E30();
    }
    while (D_0028EBE0 != 2) {
        func_00227CD0();
    }
    fade_start_in();
}
