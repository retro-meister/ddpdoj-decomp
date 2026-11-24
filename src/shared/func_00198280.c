#include "common.h"

s32 rand(void);
void *memset(void *, s32, s32);
void printf(const char *, ...);
extern s8 D_0025C4A0[];
extern const char D_0027D7E0[];
extern s32 D_0028E4AC;
extern u8 D_002BAD50[];
extern u8 D_002BAD63[];
extern u8 D_002BAD70[];
extern s8 D_002BADD0[];
extern u8 D_002BADF0[];

s32 func_00198280(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 val;
    u8 ch;

    memset(D_002BAD70, 0, 0x60);
    k = 0;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 8; j++) {
            if (D_002BADF0[i] & (1 << j)) {
                D_002BAD70[k] = 1;
            }
            k++;
        }
    }
    memset(D_002BAD50, 0, 20);
    k = 0;
    for (i = 0; i < 20; i++) {
        val = 0;
        for (j = 0; j < 5; j++) {
            if (D_002BAD70[k] != 0) {
                val |= 1 << j;
            }
            k++;
        }
        D_002BAD50[i] = val;
    }
    for (i = 0; i < 4; i++) {
        if ((rand() % 2) != 0) {
            D_002BAD63[0] |= 1 << (i + 1);
        }
    }
    D_0028E4AC = 0;
    for (i = 0; D_0025C4A0[i] != -1; i++) {
        D_0028E4AC++;
    }
    memset(D_002BADD0, 0, 30);
    for (i = 0; i < 20; i++) {
        ch = D_002BAD50[i];
        if ((((s32) ch < 0) || ((s32) ch >= D_0028E4AC)) ? 1 : 0) {
            printf(D_0027D7E0);
            return 0;
        }
        D_002BADD0[i] = D_0025C4A0[ch];
    }
    return 1;
}
