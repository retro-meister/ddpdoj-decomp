#include "common.h"

extern u16 D_0028E0E4[];
extern u16 D_0028E0E6[];
extern u16 D_0028E4AA;
extern u16 D_0028E8A0;
extern u8 *reg_a6;

void func_00201B80(void) {
    if (D_0028E8A0 == 0) {
        D_0028E4AA = D_0028E0E4[0];
        reg_d0.h[0] = D_0028E0E6[0];
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] = D_0028E4AA;
        D_0028E4AA = reg_tmp.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
    }
}
