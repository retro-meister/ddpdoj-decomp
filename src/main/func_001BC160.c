#include "common.h"

s32 func_00124D10();
s32 func_00124D90();
s32 func_00124F50();
s32 func_001253B0();
s32 func_0013F3C0();
s32 func_001BC230();
s32 func_001BC2E0();
s32 func_001BC430();
s32 func_00203460();
s32 func_0020ED10();
extern u8 D_0028E855;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001BC160() {
    D_0028E855 |= 0x40;
    D_0028E855 |= 0x80;
    func_0020ED10();
    func_0013F3C0();
    func_00203460();
    func_001BC430();
    func_001BC230();
    func_001BC2E0();
    func_001253B0();
    func_00124D10();
    reg_tmp.w = -1U;
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_tmp.h[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1E))) = 1;
    (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = 0x13;
    (*(s8 *)((u8 *)(reg_a6) + (0xBC))) = 0x16;
    reg_d0.w = 1;
    func_00124D90();
    reg_d0.w = 6;
    func_00124F50();
}
