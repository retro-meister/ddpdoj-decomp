#include "common.h"

extern u16 D_0028E3DC;
extern u16 D_0028E3E0;
extern u16 D_0028E3E4;
extern u16 D_0028E3E8;
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;

void func_00131500(void) {
    D_0028E3F0 += 1;
    if (D_0028E3EC & 1) {
        D_0028E3EC &= 0xFFFE;
    } else {
        D_0028E3EC |= 1;
    }
    D_0028E3E8 += 1;
    if (D_0028E3E8 == 3) {
        D_0028E3E8 = 0;
    }
    D_0028E3E4 = D_0028E3F0;
    D_0028E3E0 = D_0028E3F0;
    D_0028E3DC = D_0028E3F0;
    D_0028E3E4 &= 3;
    D_0028E3E0 &= 7;
    D_0028E3DC &= 0xF;
}
