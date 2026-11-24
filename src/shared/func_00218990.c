#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern sceGsLoadImage D_0057C780;
extern s32 D_0028EA78;

void func_00218990(u8 *src, s32 mode, s32 count) {
    s32 i;
    s32 offset;
    s32 off2;

    sceGsSyncPath(0, 0);
    switch (mode) {
    case 0:
        if (0 < count) {
            i = 0;
            offset = 0;
            do {
                sceGsSetDefLoadImage(&D_0057C780, D_0028EA78, 1, SCE_GS_PSMCT16, 0, 0, 8, 2);
                FlushCache(0);
                sceGsExecLoadImage(&D_0057C780, src + offset);
                sceGsSyncPath(0, 0);
                D_0028EA78 += 1;
                i++;
                offset += 0x80;
            } while (i < count);
        }
        break;
    case 1:
        if (0 < count) {
            i = 0;
            off2 = 0;
            do {
                sceGsSetDefLoadImage(&D_0057C780, D_0028EA78, 1, SCE_GS_PSMCT16, 0, 0, 16, 16);
                FlushCache(0);
                sceGsExecLoadImage(&D_0057C780, src + off2);
                sceGsSyncPath(0, 0);
                D_0028EA78 += 4;
                i++;
                off2 += 0x80;
            } while (i < count);
        }
        break;
    case 2:
        break;
    }
}
