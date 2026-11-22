#include "common.h"

s32 func_00124F50();
s32 func_00125120();
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001BC2E0(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x7E))) == 0) {
        reg_tmp.w = -1U;
        (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x20))) = (u16) reg_tmp.h[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x7E))) = 1U;
        (*(u16 *)((u8 *)(reg_a6) + (0x60))) = 0x8000;
        (*(s8 *)((u8 *)(reg_a6) + (0x7C))) = 0x15;
        reg_d0.w = 1;
        func_00125120();
        reg_d0.w = 3;
        func_00125120();
        reg_d0.w = 9;
        func_00125120();
        reg_d0.w = 0xB;
        func_00125120();
        reg_d0.w = 0xD;
        func_00125120();
        reg_d0.w = 5;
        func_00124F50();
        return;
    }
}
