#include "common.h"

void func_0021C100(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s32 arg6);
void func_00227440(u8 *arg0);
extern u8 *D_00271480[];
extern s8 D_002714FA[];
extern s32 D_0028DCF8;
extern u8 D_0028E258;
extern u8 D_0028EBE8;
extern s16 D_0028EBEC;
extern u8 D_00685010[];
extern u8 *reg_a0;

void func_00227B70(void) {
    s32 count;
    s32 last;
    s32 i;
    s32 offset;
    s32 index;
    s32 alpha;
    u8 *entry;
    s32 x;
    s32 y;
    s32 sprite;
    s16 value;

    count = D_002714FA[0];
    last = count - 1;
    if (D_0028EBE8 < 3) {
        return;
    }
    func_00227440(&D_0028EBE8);
    if (D_0028EBEC == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        index = 0;
        do {
            entry = D_00685010 + offset;
            if (*(s32 *)(entry + 0x2334) != 0) {
                value = D_0028EBEC;
                alpha = 128;
                *(s32 *)(entry + 0x232C) = value;
                x = *(s32 *)(entry + 0x2300);
                y = *(s32 *)(entry + 0x2304);
                sprite = *(s32 *)(entry + 0x2330);
                reg_a0 = *(u8 **)((u8 *)D_00271480 + index);
                if ((i > 0) && (i < last) && (D_0028E258 < i - 1)) {
                    alpha = 64;
                    reg_a0 = (u8 *)D_0028DCF8;
                }
                func_0021C100(x, y, sprite, 0, alpha, value, 1);
            }
            i++;
            offset += 0x38;
            index += 4;
        } while (i < count);
    }
}
