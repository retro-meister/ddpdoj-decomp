#include "common.h"

s32 func_00124B20(s32, s32, s32, s32); /* extern */
s32 func_00124D10();                            /* extern */
s32 func_00125120();                            /* extern */
s32 func_001253B0();                            /* extern */
s32 func_0013F3C0();                            /* extern */
s32 func_0018DEE0();                            /* extern */
s32 func_001F5750();                            /* extern */
s32 func_001F57D0();                            /* extern */
s32 func_002016D0();                            /* extern */
s32 func_00203460();                            /* extern */
s32 func_0020ED10();                            /* extern */
extern u16 D_0028E2E8;
extern u8 D_0028E855;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F5520(void) {
    func_0018DEE0();
    func_0020ED10();
    if (D_0028E2E8 == 0) {
        D_0028E855 |= 0x40;
        D_0028E855 |= 0x80;
        func_00203460();
        (*(s8 *)((u8 *)(reg_a6) + (0x1E))) = 1;
    } else {
        (*(s16 *)((u8 *)(reg_a5) + (0x1A))) = 0x6270;
    }
    func_0013F3C0();
    func_002016D0();
    func_001253B0();
    func_00124D10();
    func_001F57D0();
    func_001F5750();
    reg_d0.w = 2;
    func_00125120();
    reg_tmp.w = -1U;
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_tmp.h[0];
    (*(s8 *)((u8 *)(reg_a6) + (0xE7))) = 0x10;
    (*(s8 *)((u8 *)(reg_a6) + (0xE6))) = 0x11;
    (*(s8 *)((u8 *)(reg_a6) + (0xE9))) = 0x12;
    (*(s8 *)((u8 *)(reg_a6) + (0xE8))) = 0x16;
    reg_d0.w = 1;
    func_00124B20(0x16, 0x12, 0x11, 0x10);
}
