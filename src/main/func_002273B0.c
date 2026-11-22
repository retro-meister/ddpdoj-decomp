#include "common.h"

extern s8 D_0028EB04;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s32 D_0028EB90;

s32 func_002273B0(u8 *counter) {
    *counter += 1;
    D_0028EB58 = 1;
    D_0028EB90 = 0x40;
    D_0028EB54 = 1;
    D_0028EB04 = 1;
    return 1;
}
