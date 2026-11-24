#include "common.h"


void func_0022B7A0(s32 arg0) {
    s32 var_v1;
    s8 *temp_a1;
    s8 *temp_t0_2;
    u8 temp_a3;
    u8 temp_t0;

    var_v1 = 1;
    do {
        temp_a1 = (s8 *)(arg0 + var_v1);
        temp_t0 = (*(s8 *)((u8 *)(temp_a1) + (0)));
        var_v1 += 8;
        (*(s8 *)((u8 *)(temp_a1) + (0))) = temp_t0 + (*(s8 *)((u8 *)(temp_a1) + (-1)));
        (*(s8 *)((u8 *)(temp_a1) + (1))) += (*(s8 *)((u8 *)(temp_a1) + (0)));
        (*(s8 *)((u8 *)(temp_a1) + (2))) += (*(s8 *)((u8 *)(temp_a1) + (1)));
        (*(s8 *)((u8 *)(temp_a1) + (3))) += (*(s8 *)((u8 *)(temp_a1) + (2)));
        (*(s8 *)((u8 *)(temp_a1) + (4))) += (*(s8 *)((u8 *)(temp_a1) + (3)));
        (*(s8 *)((u8 *)(temp_a1) + (5))) += (*(s8 *)((u8 *)(temp_a1) + (4)));
        (*(s8 *)((u8 *)(temp_a1) + (6))) += (*(s8 *)((u8 *)(temp_a1) + (5)));
        (*(s8 *)((u8 *)(temp_a1) + (7))) += (*(s8 *)((u8 *)(temp_a1) + (6)));
    } while (var_v1 < 0x552B);
    if (var_v1 < 0x5533) {
        do {
            temp_t0_2 = (s8 *)(arg0 + var_v1);
            temp_a3 = (*(s8 *)((u8 *)(temp_t0_2) + (0)));
            var_v1 += 1;
            (*(s8 *)((u8 *)(temp_t0_2) + (0))) = temp_a3 + (*(s8 *)((u8 *)(temp_t0_2) + (-1)));
        } while (var_v1 < 0x5533);
    }
}
