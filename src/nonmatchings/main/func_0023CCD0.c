#include "common.h"

/* NONMATCHING: 94.6%; regalloc only (count*4 coalesces into a3, retail keeps it in v1) */

extern s32 D_0028ED88;

s32 func_0023CCD0(Reg32 *entry, Reg32 *table, s32 *lengths, s32 count) {
    s32 length;
    s32 *lp;
    u32 code;
    s32 step;
    s32 offset;
    Reg32 cur;
    Reg32 key;
    u8 *mark = &entry->b[2];

    key.h[1] = entry->h[0];
    key.h[0] = entry->h[1];
    if (key.w == 0) {
        return -1;
    }
    for (offset = 0; offset < count * 4; offset += 4) {
        cur.h[1] = table->h[1];
        cur.h[0] = table->h[0];
        code = cur.w;
        if (code <= key.w && key.w < code + (length = *(s32 *)((u8 *)lengths + offset))) {
            for (step = 0; step < length; step += 2) {
                if (code == key.w) {
                    entry->b[1] = offset;
                    entry->b[0] = step;
                    entry->b[3] = 0x81;
                    *mark = 0x99;
                    return 1;
                }
                code += 2;
            }
        }
        table++;
    }
    D_0028ED88 = 1;
    return 0;
}
