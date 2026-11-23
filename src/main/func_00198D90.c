#include "common.h"

extern s8 D_0028E408;

s32 func_0016A8C0();
s32 func_0016A8E0();
s32 func_00198EF0();
s32 func_00198F30();
s32 func_001994F0();
s32 func_00199550();
s32 func_00199710();
extern u8 D_002BAE40[];
extern u16 D_002BAE80[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00198D90(void) {
    s32 temp_s6;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;

    reg_a4 = (u8 *)D_002BAE40;
    func_0016A8C0();
    (*(u16 *)((u8 *)(reg_a4) + (0x34))) = (u16) reg_d0.h[0];
    func_0016A8E0();
    (*(u16 *)((u8 *)(reg_a4) + (0x36))) = (u16) reg_d0.h[0];
    reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
    if (reg_d7.h[0] != 0) {
        func_00198F30();
        return;
    }
    (*(s16 *)((u8 *)(reg_a4) + (0x12))) = 2;
    (*(s16 *)((u8 *)(reg_a4) + (0x2C))) = 1;
    (*(s16 *)((u8 *)(reg_a4) + (0x2E))) = 0;
    temp_s6 = (s32)reg_a0;
    temp_s0 = (s32)reg_a1;
    temp_s1 = (s32)reg_a2;
    temp_s2 = (s32)reg_a3;
    temp_s3 = (s32)reg_a4;
    temp_s4 = (s32)reg_a5;
    temp_s5 = (s32)reg_a6;
    func_00199550();
    if (D_0028E408 != 0) {
        reg_a0 = (u8 *)temp_s6;
        reg_a1 = (u8 *)temp_s0;
        reg_a2 = (u8 *)temp_s1;
        reg_a3 = (u8 *)temp_s2;
        reg_a4 = (u8 *)temp_s3;
        reg_a5 = (u8 *)temp_s4;
        reg_a6 = (u8 *)temp_s5;
        func_001994F0();
        return;
    }
    func_00199710();
    reg_a0 = (u8 *)temp_s6;
    reg_a1 = (u8 *)temp_s0;
    reg_a2 = (u8 *)temp_s1;
    reg_a3 = (u8 *)temp_s2;
    reg_a4 = (u8 *)temp_s3;
    reg_a5 = (u8 *)temp_s4;
    reg_a6 = (u8 *)temp_s5;
    if (D_002BAE80[0] != 0) {
        func_00198F30();
        return;
    }
    func_00198EF0();
}
