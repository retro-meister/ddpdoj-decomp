#include "common.h"

extern void func_0018D4B0(void);
extern s8 D_0028EB14;
extern u32 D_0057CC70[];
extern u32 D_0057CC74[];
extern s8 D_0068DC10[];
extern s8 D_0068DD00[];

void func_00222780(void) {
    s32 button;
    s32 slot;
    s32 sel;

    if (D_0057CC70[0] != 0) {
        for (button = 0; button < 8; button++) {
            if (D_0057CC70[0] & (1 << button)) {
                goto found1;
            }
        }
        goto next;
found1:
        func_0018D4B0();
        sel = D_0028EB14;
        for (slot = 9; slot < MAIN_OR_DEATH_LABEL(12, 13); slot++) {
            if (sel != slot && button == D_0068DC10[slot + 0xF0]) {
                D_0068DC10[slot + 0xF0] = D_0068DC10[sel + 0xF0];
            }
        }
        D_0068DD00[sel] = button;
    }
next:
    if (D_0057CC74[0] != 0) {
        for (button = 0; button < 8; button++) {
            if (D_0057CC74[0] & (1 << button)) {
                goto found2;
            }
        }
        return;
found2:
        func_0018D4B0();
        sel = D_0028EB14 + 4;
        for (slot = 13; slot < MAIN_OR_DEATH_LABEL(16, 17); slot++) {
            if (sel != slot && button == D_0068DC10[slot + 0xF0]) {
                D_0068DC10[slot + 0xF0] = D_0068DC10[sel + 0xF0];
            }
        }
        D_0068DD00[sel] = button;
    }
}
