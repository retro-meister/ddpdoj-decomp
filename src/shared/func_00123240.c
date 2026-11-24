#include "common.h"

s32 func_001A3020();
extern u8 D_0024D030[];
extern s16 D_00295E1C_as_s16_a[];
extern s16 D_00295E1E_as_s16_a[];
extern s16 D_00295E20_as_s16_a[];
extern s32 D_00295E24_as_s32_a[];
extern s32 D_00295E28_as_s32_a[];
extern u8 D_002BDA80[];
extern u8 *reg_a0;
extern u8 *reg_a3;

void func_00123240(void) {
    reg_a3 = D_002BDA80;
    reg_d7.h[0] = 0xC7;
    do {
        (*(s16 *)((u8 *)(reg_a3) + (0))) = 0;
        (*(s16 *)((u8 *)(reg_a3) + (2))) = 0;
        (*(s16 *)((u8 *)(reg_a3) + (4))) = 0;
        (*(s16 *)((u8 *)(reg_a3) + (6))) = 0;
        reg_a3 += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    D_00295E1C_as_s16_a[0] = 0;
    reg_a0 = D_0024D030;
    D_00295E1E_as_s16_a[0] = 0;
    reg_d0.h[0] = 0;
    D_00295E20_as_s16_a[0] = 0;
    D_00295E24_as_s32_a[0] = 0;
    D_00295E28_as_s32_a[0] = 0;
    func_001A3020();
}
