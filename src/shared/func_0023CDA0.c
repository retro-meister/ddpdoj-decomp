#include "common.h"

extern s32 D_0028ED88;

s32 func_0023CDA0(Reg32 *entry, u32 code, u32 count, u32 stride) {
    Reg32 key;
    u32 offset;
    u8 *mark = &entry->b[2];

    key.h[1] = entry->h[0];
    key.h[0] = entry->h[1];
    if (key.w == 0) {
        return -1;
    }
    for (offset = 0; offset < count * stride; offset += stride) {
        if (code == key.w) {
            entry->h[0] = offset;
            entry->b[3] = 0x82;
            *mark = 0x99;
            return 1;
        }
        code += stride;
    }
    D_0028ED88 = 1;
    return 0;
}
