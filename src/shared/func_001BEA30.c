#include "common.h"

s32 func_00124F50(s32);                     /* extern */
s32 func_001BEA80();                            /* extern */
extern u8 *reg_a4;

void func_001BEA30(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 4;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x202;
    (*(s8 *)((u8 *)(reg_a4) + (7))) = 0;
    reg_d0.w = 0;
    func_00124F50(4);
    func_001BEA80();
}
