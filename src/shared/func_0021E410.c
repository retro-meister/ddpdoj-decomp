#include "common.h"

s32 func_0018CBB0();
s32 func_0018D0A0();
s32 func_0018D4B0();
s32 func_0018DEF0();
s32 func_0021E5C0();
s32 func_00221120();
s32 func_00222260();
extern s32 D_0028DF88;
extern s32 D_0028DF8C;
extern s32 D_0028DF90;
extern u16 D_0028E320_as_u16;
extern u8 D_0028EB04_as_u8;
extern u8 D_0028EB20_as_u8;
extern u8 D_0028EB44_as_u8;
extern u8 D_0028EB4C_as_u8;
extern u8 D_0028EB54_as_u8;
extern s8 D_0028EB58;
extern s8 D_0028EB74;
extern u8 D_0028EB7C_as_u8;
extern u8 D_0028EB84_as_u8;
extern s32 D_0028EB90;
extern s32 D_0028EC68;
extern s32 D_0028EC6C;
extern s32 D_0057CC78[];
extern s32 D_0057CC88[];
extern s8 D_0068DC35[];
extern s8 D_0068DC36[];
void func_0021E410(void) {
    s32 var_a1;

    if (func_00221120(2) == 0) {
        func_0021E5C0();
    }
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (D_0057CC88[0] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = 4;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (D_0057CC78[0] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = 4;
    } else if (D_0057CC78[0] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB20_as_u8 = D_0028EB58;
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 0:
        case 3:
            break;
        case 1:
            func_0018D4B0();
            D_0028EC68 = 0;
            D_0028EB84_as_u8 = 6;
            break;
        case 2:
            func_0018D4B0();
            D_0028EC6C = 0;
            D_0028EB84_as_u8 = 5;
            break;
        case 4:
            func_0018CBB0();
            func_00222260(0);
            D_0028EB7C_as_u8 = 3;
            D_0028EB4C_as_u8 = 1;
            D_0028EB90 = 0x40;
            D_0028EB04_as_u8 = 1;
            D_0028EB54_as_u8 = 2;
            D_0028EB44_as_u8 = 2;
            D_0028EB84_as_u8 = 0;
            D_0028EB74 += 1;
            func_0018D4B0();
            break;
        case 5:
            D_0028DF8C = 0xFF;
            D_0028DF88 = 0xA;
            D_0028DF90 = D_0068DC35[0] + 1;
            func_0018D0A0(D_0028DF90);
            break;
        case 6:
            D_0028DF90 = (s32) D_0068DC36[0];
            func_0018DEF0(D_0028DF90, 1);
            break;
        }
    }
}
