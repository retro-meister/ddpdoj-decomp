#include "common.h"

void func_0018D4C0(void);
extern s8 D_0028E278_as_s8;
extern s8 D_0028EB58;
extern s32 D_0057CC68[];
extern s8 D_0068DC30[];

void func_0021E5C0(void) {
    s32 value;

    if (D_0028EB58 == 3) {
        value = D_0068DC30[D_0028EB58];
        if (D_0057CC68[0] & 0x2000) {
            func_0018D4C0();
            value++;
            if (value >= 2) {
                value = 0;
            }
            D_0068DC30[D_0028EB58] = value;
            D_0028E278_as_s8 = value;
        } else if (D_0057CC68[0] & 0x8000) {
            func_0018D4C0();
            value--;
            if (value < 0) {
                value = 1;
            }
            D_0068DC30[D_0028EB58] = value;
            D_0028E278_as_s8 = value;
        }
    }
}
