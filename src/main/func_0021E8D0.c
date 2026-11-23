#include "common.h"

extern void func_0018D4C0(void);
extern s8 D_0028DD20;
extern u16 D_0028E300;
extern s8 D_0028EB58;
extern s32 D_0057CC68[];
extern s8 D_0068DC40[];

void func_0021E8D0(void) {
    s32 count;
    s32 value;

    if (D_0028EB58 >= 5) {
        return;
    }
    if (D_0028EB58 == 1 && !(D_0028E300 & 1)) {
        return;
    }
    if (D_0028EB58 == 2 && !(D_0028E300 & 2)) {
        return;
    }
    if (D_0028EB58 == 3 && !(D_0028E300 & 4)) {
        return;
    }
    if (D_0028EB58 == 4 && !(D_0028E300 & 8)) {
        return;
    }
    count = (&D_0028DD20)[D_0028EB58];
    value = D_0068DC40[D_0028EB58];
    if (D_0057CC68[0] & 0x2000) {
        func_0018D4C0();
        value++;
        if (value >= count) {
            value = 0;
        }
        D_0068DC40[D_0028EB58] = value;
    } else if (D_0057CC68[0] & 0x8000) {
        func_0018D4C0();
        value--;
        if (value < 0) {
            value = count - 1;
        }
        D_0068DC40[D_0028EB58] = value;
    }
}
