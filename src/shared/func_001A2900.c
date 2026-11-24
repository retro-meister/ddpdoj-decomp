#include "common.h"

extern s16 D_0028E0AC_as_s16;
extern s16 D_0028E0B0_as_s16;
extern s16 D_0028E0B4_as_s16;
extern s16 D_0028E0B8;
extern s16 D_0028E0BC;
extern s16 D_0028E0C0;
extern u8 D_0029F2D0[];
extern u8 D_0029F4B0[];
extern u8 D_0029FCB0[];
void func_001A2900(void) {
    s32 var_a1;
    u8 *temp_a2;
    s32 var_a2;
    s32 var_a3;
    s32 var_a3_2;
    u8 *temp_t0;
    u8 *temp_t1;

    var_a2 = 0;
    var_a3 = 0;
    do {
        temp_t0 = (u8 *)(D_0029FCB0 + var_a3);
        temp_t1 = (u8 *)(D_0029F4B0 + var_a3);
        (*(s16 *)((u8 *)(temp_t0) + (0))) = 0;
        var_a2 += 8;
        (*(s16 *)((u8 *)(temp_t1) + (0))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (2))) = 0;
        var_a3 += 0x10;
        (*(s16 *)((u8 *)(temp_t1) + (2))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (4))) = 0;
        (*(s16 *)((u8 *)(temp_t1) + (4))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (6))) = 0;
        (*(s16 *)((u8 *)(temp_t1) + (6))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (8))) = 0;
        (*(s16 *)((u8 *)(temp_t1) + (8))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (0xA))) = 0;
        (*(s16 *)((u8 *)(temp_t1) + (0xA))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (0xC))) = 0;
        (*(s16 *)((u8 *)(temp_t1) + (0xC))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (0xE))) = 0;
        (*(s16 *)((u8 *)(temp_t1) + (0xE))) = 0;
    } while (var_a2 < 0x400);
    var_a3_2 = 0;
    var_a1 = 0;
    do {
        temp_a2 = (u8 *)(D_0029F2D0 + var_a1);
        var_a3_2 += 8;
        (*(s16 *)((u8 *)(temp_a2) + (0))) = 0;
        (*(s16 *)((u8 *)(temp_a2) + (2))) = 0;
        var_a1 += 0x10;
        (*(s16 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s16 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s16 *)((u8 *)(temp_a2) + (8))) = 0;
        (*(s16 *)((u8 *)(temp_a2) + (0xA))) = 0;
        (*(s16 *)((u8 *)(temp_a2) + (0xC))) = 0;
        (*(s16 *)((u8 *)(temp_a2) + (0xE))) = 0;
    } while (var_a3_2 < 0xF0);
    D_0028E0C0 = 0;
    D_0028E0AC_as_s16 = 0x101;
    D_0028E0BC = 0;
    D_0028E0B0_as_s16 = 1;
    D_0028E0B8 = 0;
    D_0028E0B4_as_s16 = 0x20;
}
