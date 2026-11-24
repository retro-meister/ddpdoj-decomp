#include "common.h"

extern s8 D_0028EB04;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s32 D_0028EB90;
extern u8 D_0028EC18;
extern s8 D_0028EC1A;

static s32 func_002273B0(u8 *counter, s32 limit, s32 value) {
    *counter += 1;
    D_0028EB58 = 1;
    D_0028EB90 = 0x40;
    D_0028EB54 = 1;
    D_0028EB04 = 1;
    return 1;
}

void func_002275F0(void) {
    s8 value = D_0028EC1A;
    if (func_002273B0(&D_0028EC18, 7, value) != 0) {
        D_0028EB58 = value;
        if (value == 0) {
            D_0028EB58++;
        }
    }
}
