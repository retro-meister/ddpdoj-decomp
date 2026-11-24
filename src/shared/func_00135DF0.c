#include "common.h"

s32 func_00207600();                            /* extern */
extern u16 D_0028E4AA;
extern s32 D_002BF390_as_s32_a[];
extern s32 D_002BF3B4_as_s32_a[];
extern u8 *reg_a0;
extern s32 *reg_a2_as_s32_p;
extern s32 *reg_a3_as_s32_p;
extern u8 *reg_a6;

void func_00135DF0(void) {
    reg_a2_as_s32_p = D_002BF390_as_s32_a;
    reg_a3_as_s32_p = D_002BF3B4_as_s32_a;
    D_0028E4AA = (*(u16 *)((u8 *)(reg_a2_as_s32_p) + (0x20)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a2_as_s32_p) + (0x22)));
    func_00207600();
    (*(s8 *)((u8 *)(reg_a0) + (4))) = 0;
    D_0028E4AA = (*(u16 *)((u8 *)(reg_a3_as_s32_p) + (0x20)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a3_as_s32_p) + (0x22)));
    func_00207600();
    (*(s8 *)((u8 *)(reg_a0) + (4))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (2))) = 0;
}
