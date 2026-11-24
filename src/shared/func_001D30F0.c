#include "common.h"

s32 func_00124D90();                            /* extern */
s32 func_00124F50();                            /* extern */
s32 func_001D3170(u8);                          /* extern */
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001D30F0(void) {
    u8 temp_a0;
    u8 temp_v0;

    reg_d0.w = 2;
    func_00124D90();
    reg_d0.w = 4;
    func_00124F50();
    temp_a0 = (*(u8 *)((u8 *)(reg_a6) + (0x115)));
    (*(u8 *)((u8 *)(reg_a0) + (3))) = temp_a0;
    (*(s8 *)((u8 *)(reg_a0) + (2))) = 1;
    temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x115)));
    if ((s32) temp_v0 < 0x11) {
        func_001D3170(temp_a0);
        return;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x115))) = (u8) (temp_v0 - 0x30);
    func_001D3170(temp_a0);
}
