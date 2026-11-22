#include "common.h"

extern u8 D_0028E290;
extern u8 D_0028E2D8;
extern u8 D_0028E304;
extern u16 D_0028E748;
extern u16 D_0028E750;
extern u16 D_0028E920;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;

s32 func_00133070(void) {
    if ((D_0028E290 != 2) && (D_0028ED80 == 0) && (D_0028E2D8 != 0) && (D_0028ED7C == 1) && (D_0028E304 == 0) && (D_0028E920 != 3) && (D_0028E750 == 0) && (D_0028E748 == 0)) {
        return 1;
    }
    return 0;
}
