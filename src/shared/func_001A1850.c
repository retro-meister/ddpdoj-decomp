#include "common.h"

extern u16 D_0029CEA0[];
extern u8 *reg_a4;

void func_001A1850(void) {
    if ((D_0029CEA0[0] == 0) || !((*(u8 *)((u8 *)(reg_a4) + (0))) & 0x40)) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1B)));
        if ((*(u8 *)((u8 *)(reg_a4) + (0x38))) != reg_d0.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0x1B))) += 1;
        }
    }
}
