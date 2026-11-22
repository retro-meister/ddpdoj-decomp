#include "common.h"

s32 func_00207600();                            /* extern */
extern u16 D_0028E4AA;
extern s32 D_002BF390[];
extern s32 D_002BF3B4[];
extern u8 *reg_a0;
extern s32 *reg_a2;
extern s32 *reg_a3;
extern u8 *reg_a6;

void func_00135DF0(void) {
    reg_a2 = D_002BF390;
    reg_a3 = D_002BF3B4;
    D_0028E4AA = (*(u16 *)((u8 *)(reg_a2) + (0x20)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a2) + (0x22)));
    func_00207600();
    (*(s8 *)((u8 *)(reg_a0) + (4))) = 0;
    D_0028E4AA = (*(u16 *)((u8 *)(reg_a3) + (0x20)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a3) + (0x22)));
    func_00207600();
    (*(s8 *)((u8 *)(reg_a0) + (4))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (2))) = 0;
}
