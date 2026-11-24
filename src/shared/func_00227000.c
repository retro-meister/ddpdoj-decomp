#include "common.h"

extern void func_00226A90(s32 slot, s32 x, s32 y, s32 alpha, s32 selected, void *info);
extern u8 D_0028EC3C;
extern s8 D_0028EC40;
extern u8 D_0028EC44;
extern s32 D_0028EC48;
extern u8 D_006A0E50[][0x400];

s32 func_00227000(void) {
    s32 i;
    s32 y;

    if (D_0028EC3C == 0) {
        return 0;
    }
    switch (D_0028EC44) {
    case 0:
        break;
    case 1:
        D_0028EC48 += 4;
        if (D_0028EC48 >= 0x80) {
            D_0028EC44 = 0;
            D_0028EC48 = 0x80;
        }
        break;
    case 2:
        D_0028EC48 -= 4;
        if (0 >= D_0028EC48) {
            D_0028EC48 = 0;
            D_0028EC44 = 0;
        }
        break;
    }
    if (0 < D_0028EC48) {
        y = 0x18A;
        for (i = 0; i < 10; i++) {
            func_00226A90(i, y, 0, D_0028EC48, (i == D_0028EC40) ? 1 : 0, D_006A0E50[i]);
            y -= 0x22;
        }
    }
    return 1;
}
