#include "common.h"

extern s16 D_0028E970;
extern s16 D_0028E974;
extern s16 D_0028E978;
extern s16 D_0028E97C;
extern s16 D_0028E980;
extern s16 D_0028E984;
extern s16 D_0028E988;
extern u8 D_002BF4F0[];
void func_00125DE0(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    do {
        temp_a2 = D_002BF4F0 + var_a1;
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0xC08);
    D_0028E970 = 0;
    D_0028E974 = 0;
    D_0028E978 = 0;
    D_0028E97C = 0;
    D_0028E980 = 0;
    D_0028E984 = 0;
    D_0028E988 = 0;
}
