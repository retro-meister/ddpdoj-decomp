#include "common.h"

s32 func_00124F50();
s32 func_00125120();
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001BC230(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
        reg_tmp.w = -1U;
        (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = (u16) reg_tmp.h[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x3E))) = 1U;
        (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0x8000;
        (*(s8 *)((u8 *)(reg_a6) + (0x3C))) = 0x15;
        reg_d0.w = 0;
        func_00125120();
        reg_d0.w = 2;
        func_00125120();
        reg_d0.w = 8;
        func_00125120();
        reg_d0.w = 0xA;
        func_00125120();
        reg_d0.w = 0xC;
        func_00125120();
        reg_d0.w = 4;
        func_00124F50();
        return;
    }
}
