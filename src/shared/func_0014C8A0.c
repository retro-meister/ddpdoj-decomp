#include "common.h"

s32 func_0014C3B0();
s32 func_0014CAE0();
s32 memset();
extern u16 D_0028E8A8;
extern s16 D_0029C080_as_s16_a[];
extern u8 D_0029C082[];
extern s16 D_0029C08E[];
extern s16 D_0029C090[];
extern u8 D_0029C09E[];
extern s16 D_0029C0AA[];
extern s16 D_0029C0AC[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_0014C8A0(void) {
    u8 *var_a0;
    u32 temp_s0;
    u32 temp_s1;

    func_0014C3B0();
    memset(D_0029C080_as_s16_a, 0, 0x40);
    reg_a1 = (u8 *)D_0029C082;
    reg_d1.w = 1;
    var_a0 = (u8 *)(D_0029C09E);
    do {
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_tmp.h[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 = (u8 *)(reg_tmp.w);
        (*(u16 *)((u8 *)(reg_a1) + (4))) = *(u16 *)reg_a2;
        reg_a2 += 2;
        (*(u16 *)((u8 *)(reg_a1) + (6))) = *(u16 *)reg_a2;
        reg_a2 += 2;
        (*(u16 *)((u8 *)(reg_a1) + (8))) = *(u16 *)reg_a2;
        reg_a2 += 2;
        (*(u16 *)((u8 *)(reg_a1) + (0xA))) = *(u16 *)reg_a2;
        reg_a2 += 2;
        reg_tmp.w = (u32)reg_a2;
        (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
        reg_a1 = (u8 *)D_0029C09E;
    } while ((s16)(--reg_d1.h[0]) >= 0);
    if (D_0028E8A8 != 0) {
        D_0029C080_as_s16_a[0] = 1;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x10)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x12)));
        reg_a3 = (u8 *)reg_tmp.w;
        temp_s0 = (u32)reg_a3;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0xA)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0xC)));
        reg_d7.w = 0;
        reg_a4 = (u8 *)reg_tmp.w;
        temp_s1 = (u32)reg_a4;
        do {
            func_0014CAE0();
            var_a0 = (u8 *) D_0028E8A8;
            reg_d7.h[0] += 1;
        } while ((u32)var_a0 != reg_d7.h[0]);
        reg_tmp.w = temp_s0;
        reg_a4 = (u8 *)temp_s1;
        reg_a3 = (u8 *)temp_s0;
        (*(u16 *)((u8 *)(reg_a5) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x12))) = (u16) reg_tmp.h[0];
        reg_tmp.w = (u32)reg_a4;
        (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0xC))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0;
        (*(s16 *)((u8 *)(reg_a5) + (8))) = 0;
        D_0029C08E[0] = 0;
        D_0029C090[0] = 0;
        D_0029C0AA[0] = 0;
        D_0029C0AC[0] = 0;
    }
    D_0029C080_as_s16_a[0] = 0;
}
