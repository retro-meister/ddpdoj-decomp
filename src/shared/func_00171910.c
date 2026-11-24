#include "common.h"

extern s16 D_0028E798;
extern s16 D_0028E79C;
extern s16 D_0028E7A0;
extern s16 D_002BB458_as_s16_a[];
extern s16 D_002BB45A[];
extern s16 D_002BB45C[];
extern s16 D_002BB45E[];
extern s16 D_002BB460[];
extern u8 D_002BB470[];
void func_00171910(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    do {
        temp_a2 = D_002BB470 + var_a1;
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0x40);
    D_0028E798 = 0;
    D_002BB458_as_s16_a[0] = 0;
    D_0028E79C = 0;
    D_002BB45A[0] = 0;
    D_0028E7A0 = 0;
    D_002BB45C[0] = 0;
    D_002BB45E[0] = 0;
    D_002BB460[0] = 0;
}
