#include "common.h"

s32 func_0018DEE0();
void func_00215FF0(void *destination, s32 byteCount, s32 startSector);
s32 memcpy();
s32 printf();
extern u8 D_00289F10[];
extern u8 D_00289F30[];
extern s8 D_0028E9B8;
extern s8 D_0028E9BC;
extern u8 *D_0028EAAC;
extern u8 D_0028EAB0;
extern u8 D_0028EAB4;
extern s32 D_0029CA60[];
extern s32 D_0029CA64[];
extern u8 D_0050D780[];
extern u8 D_006A4800[];
s32 func_0022BE60(u8 arg0) {
    u32 state;

    state = D_0028EAB4;
    switch (state) {
    case 0:
        D_0028EAB0 = arg0;
        D_0028EAB4 = state + 1;
        D_0028EAAC = D_0050D780;
        func_0018DEE0();
        printf(D_00289F10);
        break;
    case 1:
        if (D_0028E9BC != 0) {
            D_0028E9BC = 1;
            D_0028EAB4 = state + 1;
            D_0028E9B8 = 0;
        }
        break;
    case 2:
        func_00215FF0(D_0028EAAC, D_0029CA60[D_0028EAB0 * 2], D_0029CA64[D_0028EAB0 * 2]);
        if (D_0028E9BC == 0) {
            D_0028E9BC = 1;
            D_0028E9B8 = 0;
            D_0028EAB4 = 0;
            memcpy(D_006A4800, D_0028EAAC, 0x202E8);
            printf(D_00289F30);
            return 1;
        }
        break;
    }
    return 0;
}
