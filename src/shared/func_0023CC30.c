#include "common.h"

extern s32 D_0028ED88;

s32 func_0023CC30(Reg32 *entry, Reg32 *table, s32 count) {
    Reg32 key;
    Reg32 cur;
    s32 offset;
    u8 *mark = &entry->b[2];

    key.h[1] = entry->h[0];
    key.h[0] = entry->h[1];
    if (key.w == 0) {
        return -1;
    }
    for (offset = 0; offset < count * 4; offset += 4) {
        cur.h[1] = table->h[1];
        cur.h[0] = table->h[0];
        if (cur.w == key.w) {
            entry->h[0] = offset;
            entry->b[3] = 0x80;
            *mark = 0x99;
            return 1;
        }
        table++;
    }
    D_0028ED88 = 1;
    return 0;
}
