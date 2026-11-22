#include "common.h"

extern u32 D_002B4D50[];
extern s32 D_0028EA80;
extern void func_00219A80(s32 x, s32 y);
extern void func_0021A170(void);

void func_002199F0(void) {
    s32 y;
    u32 *p = D_002B4D50;
    s32 x;

    D_0028EA80 = 0;
    for (y = 0; y < 32; y++) {
        for (x = 0; x < 64; x++) {
            reg_d0.w = *p++;
            if (reg_d0.w != 0xC0000000 && reg_d0.w != 0) {
                func_00219A80(x, y);
            }
        }
    }
    func_0021A170();
}
