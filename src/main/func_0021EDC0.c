#include "common.h"

void func_0018D4C0(void);
extern s8 D_0028E2D8;
extern s8 D_0028EB58;
extern s32 D_0057CC68[];
extern s8 D_0068DCF0[];

void func_0021EDC0(void) {
    s32 value;

    if (D_0028EB58 == 4) {
        value = D_0068DCF0[D_0028EB58];
        if (D_0057CC68[0] & 0x2000) {
            func_0018D4C0();
            value++;
            if (value >= 2) {
                value = 0;
            }
            D_0068DCF0[D_0028EB58] = value;
            D_0028E2D8 = value;
        } else if (D_0057CC68[0] & 0x8000) {
            func_0018D4C0();
            value--;
            if (value < 0) {
                value = 1;
            }
            D_0068DCF0[D_0028EB58] = value;
            D_0028E2D8 = value;
        }
    }
}
