#include "common.h"

extern u8 D_002BAE90[];
extern u8 *reg_a5;
extern u8 *reg_a6;

#ifdef DEATH_LABEL
extern s8 D_0028E2A4_as_s8;
#endif

void func_00210C90(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    do {
        temp_a2 = D_002BAE90 + var_a1;
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0x20);
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
    (*(s16 *)((u8 *)(reg_a6) + (0xA))) = 0x60;
    (*(s16 *)((u8 *)(reg_a6) + (0xC))) = 0x10;
#ifdef DEATH_LABEL
    D_0028E2A4_as_s8 = 0x78;
#endif
}
