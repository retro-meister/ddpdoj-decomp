#include "common.h"

s32 func_00134380();
s32 func_00135420();
s32 func_00135ED0();
s32 func_00136450();
s32 func_00138170();
s32 func_002075F0();
extern u8 D_0028E350;
extern u16 D_0028E3F0;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern s32 D_0028E8BC;
extern u16 D_0028E910;
extern u16 D_0028E93C;
extern u8 D_0028EC4C;
extern s16 D_00299768[];
extern u8 *reg_a5;

void func_001367C0(void) {
    u8 t;

    t = *(u8 *)(reg_a5 + 3);
    if (t == 0) {
        func_00136450();
        return;
    }
    if (t == 2) goto block_end1;
    func_00135420();
    if (D_0028E93C == 0) {
        if (D_0028E8A0 == 0) {
            if (D_0028E89C != 0) {
                D_0028E89C -= 1;
            }
        }
        reg_d0.w = 0xE;
        reg_d0.h[0] &= D_0028E3F0;
        D_0028E8B8 = reg_d0.h[0];
        if ((D_0028E8A0 == 0) && (D_0028E350 == 0) && (D_0028EC4C == 0)) {
            D_0028E8BC += 1;
        }
        func_00138170();
        func_00134380();
        if (D_0028E910 != 0) {
            D_00299768[0] = 1;
        }
    }
    return;
block_end1:
    func_00135ED0();
    func_002075F0();
}
