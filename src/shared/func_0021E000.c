#include "common.h"

extern void func_0018D4C0(void);
extern s8 D_0028DD10[8];
extern s16 D_0028E340_as_s16;
extern s16 D_0028E344_as_s16;
extern s16 D_0028E348_as_s16;
extern s16 D_0028E34C_as_s16;
extern u8 D_0028E35C;
extern u8 D_0028E360;
extern s8 D_0028EB58;
extern s32 D_0057CC60_as_s32_a[];
extern s32 D_0057CC68[];
extern s8 D_0068DC20[];

void func_0021E000(void) {
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = D_0028EB58;
    if (sel < 5) {
        max = D_0028DD10[sel];
        cur = D_0068DC20[sel];
        pad = D_0057CC68[0];
        if (pad & 0x2000) {
            func_0018D4C0();
            cur++;
            if (cur >= max) {
                cur = 0;
            }
            D_0068DC20[D_0028EB58] = cur;
            if (D_0028EB58 == 4 && cur == 1) {
                if (D_0057CC60_as_s32_a[0] != 0) {
                    D_0028E360 = 1;
                    D_0028E344_as_s16 = 0x78;
                    D_0028E34C_as_s16 = 0x14;
                } else {
                    D_0028E35C = 1;
                    D_0028E340_as_s16 = 0x78;
                    D_0028E348_as_s16 = 0x14;
                }
            }
        } else if (pad & 0x8000) {
            func_0018D4C0();
            cur--;
            if (cur < 0) {
                cur = max - 1;
            }
            D_0068DC20[D_0028EB58] = cur;
            if (D_0028EB58 == 4 && cur == 1) {
                if (D_0057CC60_as_s32_a[0] != 0) {
                    D_0028E360 = 1;
                    D_0028E344_as_s16 = 0x78;
                    D_0028E34C_as_s16 = 0x14;
                } else {
                    D_0028E35C = 1;
                    D_0028E340_as_s16 = 0x78;
                    D_0028E348_as_s16 = 0x14;
                }
            }
        }
    }
}
