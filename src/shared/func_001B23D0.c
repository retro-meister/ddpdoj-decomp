#include "common.h"

s32 func_002011A0();                            /* extern */
extern u8 *reg_a4;

void func_001B23D0(void) {
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) reg_d0.b[0];
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a4) + (4))) = (u8) reg_d0.b[0];
}
