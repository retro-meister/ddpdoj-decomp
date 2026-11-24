#include "common.h"

s32 func_0014E030();
extern u8 D_0028DC68[];
extern u8 *reg_a0;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DB2B0(u8 *arg1) {
    u8 *var_a0;
    u8 *var_a1;
    var_a1 = (u8 *)(arg1);
    var_a0 = (u8 *)(reg_a4);
    (*(u8 *)((u8 *)(var_a0) + (3))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        reg_a3 = (u8 *)D_0028DC68;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a3) + (0)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a3) + (2)));
        reg_a3 = (u8 *) reg_tmp.w;
        reg_d6.b[0] = (u8) (s8) (*(s8 *)((u8 *)(reg_a3) + (0)));
        reg_a3 += 1;
        reg_d7.w = 0;
        reg_d7.b[0] = (u8) (s8) (*(s8 *)((u8 *)(reg_a3) + (0)));
        reg_a3 += 1;
        reg_d7.h[0] -= 1;
        do {
            reg_d0.w = 0x42;
            func_0014E030();
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
            (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d2.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d2.h[0];
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d6.b[0];
            (*(s8 *)((u8 *)(reg_a0) + (0x1A))) = (s8) (*(s8 *)((u8 *)(reg_a3) + (0)));
            var_a1 = (u8 *)(reg_a3 + 1);
            reg_a3 = var_a1;
            reg_tmp.w = (u32) reg_a6;
            (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) reg_tmp.h[0];
            (*(u8 *)((u8 *)(reg_a0) + (0x21))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (9)));
            (*(s8 *)((u8 *)(reg_a0) + (0x20))) = (s8) (*(s8 *)((u8 *)(reg_a3) + (0)));
            var_a0 = (u8 *)(reg_a3 + 1);
            reg_a3 = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
    }
}
