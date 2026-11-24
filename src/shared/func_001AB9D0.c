#include "common.h"

s32 func_001AB8D0();
extern u8 D_0026B8D0[];
extern u16 D_0028E58C;
extern u32 D_0028E594_as_u32;
extern s16 D_0029F260[];
extern u16 D_0029F262[];
extern u16 D_0029F264[];
extern u8 *reg_a0;

void func_001AB9D0(void) {
    if (D_0028E58C != 0) {
        reg_d0.h[0] = D_0028E58C;
        reg_a0 = D_0026B8D0;
        D_0028E594_as_u32 = *(u32 *)(reg_a0 + reg_d0.h[0]);
        if (D_0029F260[0] < 0) {
            reg_d1.h[1] = D_0029F262[0];
            reg_d1.h[0] = D_0029F264[0];
            reg_d2.w = D_0028E594_as_u32;
            func_001AB8D0();
        }
        D_0028E58C -= 4;
    }
}
