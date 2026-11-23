#include "common.h"

s32 func_0018D4B0();
s32 func_0018D4C0();
s32 func_002273E0();
extern s8 D_0028EB04;
extern s8 D_0028EB50;
extern s8 D_0028EB54;
extern s8 D_0028EB84;
extern s32 D_0028EB90;
extern u8 D_0028EBD8;
extern s8 D_0028EBD9;
extern s8 D_0028EBDA;
extern s16 D_0028EBDC;
extern s8 D_0028EC18;
extern s8 D_0028EC1A;
extern s8 D_0028EC24;
extern u8 D_0057CC60[];
extern u8 D_0057CC70[];
void func_0022A2E0(void) {
    s32 temp_a0;
    s32 var_a1;
    s32 var_s0;

    var_s0 = 0;
    func_002273E0();
    temp_a0 = *(u32 *)(D_0057CC60 + (D_0028EC24 * 4));
    var_a1 = 0;
    if (temp_a0 & 0x8000) {
        func_0018D4C0();
        D_0028EBDA -= 1;
        if (D_0028EBDA < 0) {
            D_0028EBDA = 9;
        }
        var_a1 = 1;
    } else if (temp_a0 & 0x2000) {
        func_0018D4C0();
        D_0028EBDA += 1;
        if (D_0028EBDA > 9) {
            D_0028EBDA = 0;
        }
        var_a1 = 1;
    }
    if ((var_a1 == 0) && (*(u32 *)(D_0057CC70 + (D_0028EC24 * 4)) & 0x40)) {
        var_s0 = 1;
    }
    if (var_s0 != 0) {
        func_0018D4B0();
        D_0028EBD9 = 0;
        D_0028EB04 = 1;
        D_0028EBDC = 0;
        D_0028EC1A = 4;
        D_0028EB54 = 0;
        D_0028EB84 = 7;
        D_0028EB50 = 0;
        D_0028EB90 = 0;
        D_0028EC18 = 0;
        D_0028EBD8 += 1;
    }
}
