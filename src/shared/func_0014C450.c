#include "common.h"

s32 memset();
extern u8 D_002526B0[];
extern u16 D_0028E914;
extern u8 D_0029BF50[];
extern s32 D_0029C050_as_s32_a[];
extern u8 *reg_a0;

void func_0014C450(void) {
    memset(D_0029BF50, 0, 0x104);
    reg_a0 = D_002526B0;
    reg_a0 += D_0028E914;
    D_0029C050_as_s32_a[0] = *(s32 *)reg_a0;
}
