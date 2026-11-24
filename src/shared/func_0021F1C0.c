#include "common.h"

extern void func_0018D4C0(void);
extern s8 D_00271690[];
extern s8 D_002716A0[];
extern u8 D_0028E358;
extern s8 D_0028EB58;
extern s32 D_0057CC68[];
extern s8 D_0068DD00[];

void func_0021F1C0(void) {
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = D_0028EB58;
    if (sel != 7 && !(sel > 7)) {
        max = D_00271690[sel];
        if (sel == 2 && D_0028E358 != 0) {
            max = D_002716A0[sel];
        }
        cur = D_0068DD00[sel];
        pad = D_0057CC68[0];
        if (pad & 0x2000) {
            func_0018D4C0();
            cur++;
            if (cur >= max) {
                cur = 0;
            }
            D_0068DD00[D_0028EB58] = cur;
        } else if (pad & 0x8000) {
            func_0018D4C0();
            cur--;
            if (cur < 0) {
                cur = max - 1;
            }
            D_0068DD00[D_0028EB58] = cur;
        }
    }
}
