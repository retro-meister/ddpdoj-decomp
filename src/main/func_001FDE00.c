#include "common.h"

#pragma mpwc_relax on

s32 func_001FDED0();
s32 func_001FDFC0();
s32 func_001FE6D0();
s32 func_001FE990();
s32 func_001FEA90();
s32 func_001FEE40();
s32 func_001FEF40();
s32 func_001FEF70();
s32 func_00201C60();
extern u8 *reg_a6;

void func_001FDE00(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
    switch (reg_d0.h[0]) {
    case 0:
        func_001FDED0();
        break;
    case 1:
        func_001FDFC0();
        break;
    case 2:
        func_001FE6D0();
        break;
    case 3:
        func_001FE990();
        break;
    case 4:
        func_001FEA90();
        break;
    case 5:
        func_001FEE40();
        break;
    case 6:
        func_001FEF40();
        break;
    case 7:
        func_001FEF70();
        break;
    }
    func_00201C60();
}
