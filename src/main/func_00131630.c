#include "common.h"

extern s16 D_0028E948;
extern s16 D_0028E94C;
extern s16 D_0028E950;
extern s16 D_0028E954;
extern s16 D_0028E958;
extern s16 D_0028E95C;
extern s16 D_0028E960;
extern u8 D_002BF410[];
extern u8 D_002BF450[];
extern u8 D_002BF490[];
void func_00131630(void) {
    s32 var_a1;
    u8 *temp_a2;
    s32 var_a2;
    u8 *temp_a3;
    u8 *temp_t0;
    s32 var_t1;

    var_a1 = 0;
    do {
        temp_a2 = (u8 *)(D_002BF490 + var_a1);
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0x60);
    D_0028E948 = 0;
    var_t1 = 0;
    D_0028E94C = 0;
    var_a2 = 0;
    D_0028E950 = 0;
    D_0028E954 = 0;
    D_0028E958 = 0;
    D_0028E95C = 0;
    D_0028E960 = 0;
    do {
        temp_a3 = (u8 *)(D_002BF450 + var_a2);
        temp_t0 = (u8 *)(D_002BF410 + var_a2);
        (*(s16 *)((u8 *)(temp_a3) + (0))) = 0;
        var_t1 += 8;
        (*(s16 *)((u8 *)(temp_t0) + (0))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (2))) = 0;
        var_a2 += 0x10;
        (*(s16 *)((u8 *)(temp_t0) + (2))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (4))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (4))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (6))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (6))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (8))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (8))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (0xA))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (0xA))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (0xC))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (0xC))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (0xE))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (0xE))) = 0;
    } while (var_t1 < 0x20);
}
