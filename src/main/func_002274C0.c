#include "common.h"

void func_0021C100(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s32 arg6);
extern s8 D_002714F0[];
extern u8 D_00685010[];
extern u8 *reg_a0;

void func_002274C0(u8 *arg0, u8 **arg1, s32 arg2) {
    s32 count;
    s32 i;
    s32 offset;
    s32 index;
    u8 *entry;

    count = D_002714F0[arg2];
    if (*(s16 *)(arg0 + 4) == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        index = 0;
        do {
            entry = offset + (D_00685010 + arg2 * 0x380);
            if (*(s32 *)(entry + 0x34) != 0) {
                *(s32 *)(entry + 0x2C) = *(s16 *)(arg0 + 4);
                reg_a0 = *(u8 **)((u8 *)arg1 + index);
                func_0021C100(*(s32 *)entry, *(s32 *)(entry + 4), *(s32 *)(entry + 0x30), 0, 128, *(s16 *)(arg0 + 4), 1);
            }
            i++;
            offset += 0x38;
            index += 4;
        } while (i < count);
    }
}
