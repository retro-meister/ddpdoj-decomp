#include "common.h"

s32 func_00135100(s16);                         /* extern */
s32 func_00135110();                            /* extern */
extern u16 D_0028E4AA;
extern u16 D_0028E924;
extern u16 D_0028E928;
extern s32 D_002BF390_as_s32_a[];
extern s32 D_002BF3B4_as_s32_a[];
extern s32 *reg_a2_as_s32_p;
extern s32 *reg_a3_as_s32_p;

void func_00135120(void) {
    reg_a2_as_s32_p = D_002BF390_as_s32_a;
    D_0028E928 = 0;
    reg_a3_as_s32_p = D_002BF3B4_as_s32_a;
    D_0028E4AA = (*(u16 *)((u8 *)(reg_a2_as_s32_p) + (0x18)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a2_as_s32_p) + (0x1A)));
    if (reg_d0.w != 0) {
        D_0028E928 += 1;
    }
    D_0028E4AA = (*(u16 *)((u8 *)(reg_a3_as_s32_p) + (0x18)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a3_as_s32_p) + (0x1A)));
    if (reg_d0.w != 0) {
        D_0028E928 += 1;
    }
    D_0028E928 -= 1;
    D_0028E924 = D_0028E928;
    func_00135110();
    if ((s16) D_0028E924 == -1) {
        func_00135100((s16) D_0028E924);
    }
    if (D_0028E928 == 0) {
        D_0028E928 = 1;
        return;
    }
    D_0028E928 = 0;
}
