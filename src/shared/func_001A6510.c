#include "common.h"

s32 func_001A7080();
s32 func_001A7840();
s32 func_001AC320();
extern s16 D_0028E644;
extern u16 D_0028E648;
extern u16 D_0028E64C;
extern u16 D_0028E650;
extern u8 D_0028E855;
extern s16 D_0028E924_as_s16;
extern u16 D_0028E928;

void func_001A6510(void) {
    u32 flags;
    u32 hit;

    flags = D_0028E855;
    if (!(flags & 4)) goto next_7;
    hit = D_0028E648;
    if ((s16)hit >= 0) goto next_0;
    D_0028E64C -= 1;
    goto next_1;
next_0:
    D_0028E64C += 1;
next_1:
    if (flags & 0x40) goto next_4;
    if (D_0028E924_as_s16 < 0) goto next_6;
    if (D_0028E650 == 0) goto next_7;
    D_0028E650 -= 1;
    if (D_0028E650 != 0) goto next_5;
    D_0028E644 = 8;
    D_0028E650 = 0xA;
    if (D_0028E928 != 0) goto next_3;
    D_0028E650 = 0x12;
next_3:
    D_0028E648 -= 1;
    if ((s16)D_0028E648 < 0) goto next_6;
    if (D_0028E648 != 0) goto next_5;
    func_001AC320();
    goto next_7;
next_4:
    switch (hit & 0xFFFF) {
    case 0:
        goto next_7;
    }
    if ((s16)D_0028E64C < 0) goto next_7;
    D_0028E644 = 7;
    D_0028E650 = 0;
next_5:
    func_001A7840();
    goto next_7;
next_6:
    D_0028E648 = 0;
    D_0028E650 = 0;
next_7:
    if (D_0028E855 & 8) {
        func_001A7080();
    }
}
