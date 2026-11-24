#include "common.h"
#include "sdk/ps2sdk.h"

extern s8 g_fade_state;
extern s8 D_0028EB00;
extern s8 D_0028EB88;

void func_0021D850(void) {
    if (g_fade_state == 0) {
        D_0028EB88 = 0;
        if (D_0028EB00 == 2) {
            D_0028EB00 = 0x14;
        } else if (D_0028EB00 == 3) {
            D_0028EB00 = 0x1E;
        } else if (D_0028EB00 == 4) {
            D_0028EB00 = 0x28;
        } else {
            D_0028EB00 = 0xA;
        }
    }
}
