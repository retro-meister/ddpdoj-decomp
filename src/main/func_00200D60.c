#include "common.h"

s32 func_001A3020();
s32 func_00200A10();
extern u8 D_0025F770[];
extern s16 D_0028E90C;
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_00200D60(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    func_00200A10();
    reg_a0 = D_0025F770;
    reg_d0.h[0] = 2;
    func_001A3020();
    *(s16 *)(reg_a5 + 4) = 0;
    *(s16 *)(reg_a5 + 6) = 0x80;
    if (D_0028E910 == 0) {
        *(s8 *)(reg_a5 + 3) = 2;
        return;
    }
    D_0028E90C = 1;
}
