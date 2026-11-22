#include "common.h"
#include "sdk/ps2sdk.h"

extern s8 D_0028EB30;
extern s32 D_0028EB98;

void func_00221000(void) {
    switch (D_0028EB30) {
    case 0:
        break;
    case 1:
        D_0028EB98 += 4;
        if (D_0028EB98 >= 0x80) {
            D_0028EB30 = 0;
            D_0028EB98 = 0x80;
        }
        break;
    case 2:
        D_0028EB98 -= 4;
        if (D_0028EB98 <= 0) {
            D_0028EB98 = 0;
            D_0028EB30 = 0;
        }
        break;
    }
}
