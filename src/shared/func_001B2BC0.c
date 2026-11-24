#include "common.h"

s32 func_00124F00();
s32 func_0013A780();
s32 func_0018D540();
s32 func_0018D560();
s32 func_001B26F0();
s32 func_001B2830();
s32 func_002010A0();
extern u8 D_0026DC80[];
extern u8 D_0026DCF0[];
extern u16 D_0029C06C[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B2BC0(void) {
    u8 temp_a0;
    u8 temp_v1;
    u8 *var_a1;

    var_a1 = (u8 *)(reg_a6);
    reg_d0.h[0] = D_0029C06C[0];
    (*(u16 *)((u8 *)(var_a1) + (0x64))) -= reg_d0.h[0];
    if ((*(u8 *)((u8 *)(reg_a4) + (2))) & 4) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
        (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            reg_d0.w = 0x10;
            func_0013A780();
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 4;
            (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x10;
            func_002010A0();
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x62)));
            var_a1 = (u8 *)((void *) (*(u16 *)((u8 *)(reg_a6) + (0x64))));
            (*(s16 *)((u8 *)(reg_a0) + (4))) = (s16) var_a1;
            reg_tmp.w = 0xFDFFFC00;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) reg_tmp.h[0];
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (2))) & 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            reg_d0.w = 0x10;
            func_0013A780();
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 4;
            (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x10;
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x62)));
            var_a1 = (u8 *)((void *) (*(u16 *)((u8 *)(reg_a6) + (0x64))));
            (*(s16 *)((u8 *)(reg_a0) + (4))) = (s16) var_a1;
            reg_tmp.w = 0xF2000200;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) reg_tmp.h[0];
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (2))) & 2) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
        (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
            reg_d0.w = 6;
            func_0013A780();
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 8;
            (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0xC;
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x62)));
            var_a1 = (u8 *)((void *) (*(u16 *)((u8 *)(reg_a6) + (0x64))));
            (*(s16 *)((u8 *)(reg_a0) + (4))) = (s16) var_a1;
            reg_tmp.w = 0xF5FFFC00;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) reg_tmp.h[0];
        }
    }
    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0 == 2) {
        func_0018D540();
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
        reg_a1 = D_0026DCF0;
        func_001B2830();
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
        (*(u8 *)((u8 *)(reg_a4) + (0xB))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0xB))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xA)));
            temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (0xA)));
            if (temp_v1 != 0) {
                (*(u8 *)((u8 *)(reg_a4) + (0xA))) = (u8) (temp_v1 - 1);
            }
            (*(u16 *)((u8 *)(reg_a4) + (0xC))) += 0x10;
            (*(u16 *)((u8 *)(reg_a6) + (0x86))) -= 0x800;
            (*(u16 *)((u8 *)(reg_a6) + (0x88))) -= 0x800;
            if (0 > (s16) (*(u16 *)((u8 *)(reg_a6) + (0x88)))) {
                reg_tmp.w = 0;
                (*(u16 *)((u8 *)(reg_a6) + (0x86))) = (u16) reg_tmp.h[1];
                (*(u16 *)((u8 *)(reg_a6) + (0x88))) = (u16) reg_tmp.h[0];
                (*(u16 *)((u8 *)(reg_a4) + (0xC))) = 0U;
                (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
                reg_d0.w = 1;
                func_00124F00();
            }
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        func_0018D560();
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
        reg_a1 = D_0026DC80;
        func_001B26F0();
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    (*(u16 *)((u8 *)(reg_a6) + (0x62))) -= reg_d0.h[0];
}
