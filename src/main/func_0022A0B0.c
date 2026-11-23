#include "common.h"

extern void func_0021C100(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern void func_00224BA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags);
extern void func_00227440(u8 *state);
extern s32 strlen(u8 *s);
extern u8 *D_002712F0[];
extern u8 **D_00271440[];
extern s8 D_00271468[];
extern s8 D_00271503[];
extern u8 D_0028EBF8;
extern s8 D_0028EBFA;
extern s16 D_0028EBFC;
extern u8 D_00685010[];
extern s16 D_0068DEC8[];
extern u8 *reg_a0;

void func_0022A0B0(void) {
    s32 x;
    s32 y;
    s32 z;
    s32 i;
    s32 count;
    s8 index;
    s32 alpha;
    u8 *item;

    count = D_00271503[0];
    func_00227440(&D_0028EBF8);
    if (D_0028EBFC == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x42B4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x42AC) = alpha = D_0028EBFC;
        y = *(s32 *)(item + 0x4284);
        z = *(s32 *)(item + 0x42B0);
        x = *(s32 *)(item + 0x4280);
        reg_a0 = D_002712F0[i];
        func_0021C100(x, y, z, 0, 0x80, alpha, 1);
        y += strlen(reg_a0) * 8;
        reg_a0 = 0;
        index = D_00271468[i];
        if (index == -1) {
            continue;
        }
        reg_a0 = D_00271440[index][D_0068DEC8[index]];
        if (reg_a0 == 0) {
            continue;
        }
        func_0021C100(x, y, z, 0, 0x80, D_0028EBFC, 1);
        if (i == D_0028EBFA) {
            func_00224BA0(x, y, z, 0, 0x80, D_0028EBFC, 1, 3);
        }
    }
}
