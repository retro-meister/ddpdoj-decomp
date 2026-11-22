#include "common.h"

s32 func_001A2FA0();
extern u8 D_00269340[];
extern u8 D_002BF3E0[];
extern u8 *reg_a0;

void func_001340F0(void) {
    s32 var_a0;
    u8 *temp_a1;

    var_a0 = 0;
    do {
        temp_a1 = D_002BF3E0 + var_a0;
        (*(s8 *)((u8 *)(temp_a1) + (0))) = 0;
        var_a0 += 8;
        (*(s8 *)((u8 *)(temp_a1) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (7))) = 0;
    } while (var_a0 < 0x24);
    if (var_a0 < 0x2C) {
        do {
            *(D_002BF3E0 + var_a0) = 0;
            var_a0 += 1;
        } while (var_a0 < 0x2C);
    }
    reg_a0 = D_00269340;
    reg_d0.h[0] = 0xD;
    func_001A2FA0();
}
