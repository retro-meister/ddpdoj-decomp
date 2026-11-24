#include "common.h"
#include "sdk/ps2sdk.h"

extern s32 D_0028DC98;
extern s8 D_0028DD9C[4];
extern s8 D_0028DDA0[2];
extern s8 D_0028E2F8_as_s8;
extern u8 D_0028E354;
extern u8 D_0028E358;
extern s8 D_0068DD01[];

void func_0021DF60(void) {
    s32 value;

    D_0028E358 = D_0068DD01[0];
    if (D_0028E358 == 0) {
        if (D_0028E354 > 3) {
            D_0028E354 = 0;
        }
        value = D_0028DD9C[D_0028E354];
    } else {
        if (D_0028E354 > 1) {
            D_0028E354 = 0;
        }
        value = D_0028DDA0[D_0028E354];
    }
    D_0028DC98 = value;
    if (D_0028E358 == 0 && D_0028E354 >= 2) {
        D_0028E2F8_as_s8 = 1;
    } else {
        D_0028E2F8_as_s8 = 0;
    }
}
