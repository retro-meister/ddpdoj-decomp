#include "common.h"

extern void func_0018D4D0(void);
extern s8 D_002714F0[];
extern s8 D_0028EB58;
extern s8 D_0028EB84;
extern s8 D_0028EC24;
extern u32 D_0057CC60_as_u32_a[];
extern s16 D_0068DEFA[];

s32 func_00221120(s32 page) {
    s32 port;
    s32 count;
    u32 pad;

    port = 2;
    switch (page) {
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
    case 17:
    case 18:
        port = D_0028EC24;
        break;
    }
    count = D_002714F0[page];
    pad = D_0057CC60_as_u32_a[port];
    if (pad & 0x1000) {
        func_0018D4D0();
        D_0028EB58--;
        if (D_0028EB84 == 15 && D_0028EB58 == 8) {
            D_0028EB58--;
        }
        if (page == 18 && D_0068DEFA[0] == 0 && D_0028EB58 == 7) {
            D_0028EB58 = 6;
        }
        if (D_0028EB58 <= 0) {
            D_0028EB58 = count - 1;
        }
        return 1;
    }
    if (pad & 0x4000) {
        func_0018D4D0();
        D_0028EB58++;
        if (D_0028EB84 == 15 && D_0028EB58 == 8) {
            D_0028EB58++;
        }
        if (page == 18 && D_0068DEFA[0] == 0 && D_0028EB58 == 7) {
            D_0028EB58 = 8;
        }
        if (D_0028EB58 >= count) {
            D_0028EB58 = 1;
        }
        return 1;
    }
    return 0;
}
