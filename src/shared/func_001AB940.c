#include "common.h"


s32 func_001AB8D0();
extern u8 D_0028E57C_as_u8;
extern u8 D_0028E57D;
extern u16 D_0028E584;
extern u32 D_0028E594_as_u32;
extern s16 D_0029F260[];
extern u16 D_0029F262[];
extern u16 D_0029F264[];
void func_001AB940(void) {
    if (D_0028E584 != 0) {
        if (D_0029F260[0] < 0) {
            reg_d1.h[1] = D_0029F262[0];
            reg_d1.h[0] = D_0029F264[0];
            reg_d2.w = D_0028E594_as_u32;
            func_001AB8D0();
        }
        D_0028E57D -= 1;
        if ((s8) D_0028E57D < 0) {
            D_0028E57D = D_0028E57C_as_u8;
            D_0028E594_as_u32 += 1;
            if (D_0028E594_as_u32 == 0xA04) {
                D_0028E584 = 0;
            }
        }
    }
}
