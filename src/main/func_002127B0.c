#include "gallery/gallery.h"

extern sceGsLoadImage D_0057C780;
extern u8 D_002C0180[];
extern u8 D_002C0200[];

void func_002127B0(void) {
    s32 entryIndex;
    s32 offset;
    s16 cbp;

    for (entryIndex = 0, offset = 0; entryIndex < 17; entryIndex++, offset += 0x40) {
        cbp = (s64)(entryIndex + 0x37E8);
        sceGsSetDefLoadImage(&D_0057C780, cbp, 1, SCE_GS_PSMCT32, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(&D_0057C780, D_002C0200 + offset);
        sceGsSyncPath(0, 0);
    }

    sceGsSetDefLoadImage(&D_0057C780, 0x37FA, 1, SCE_GS_PSMCT32, 0, 0, 8, 2);
    FlushCache(0);
    sceGsExecLoadImage(&D_0057C780, D_002C0180);
    sceGsSyncPath(0, 0);
}
