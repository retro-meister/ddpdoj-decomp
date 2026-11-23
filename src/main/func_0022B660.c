#include "common.h"

extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 func_00226260(void);
extern void func_002263C0(void);
extern void func_002263D0(s32 a, s32 b, s32 c);
extern void func_0022B7A0(void *data);
extern void func_0023D4A0(void *data);
extern u8 D_0028E2B8[8];
extern u8 D_0028E368;
extern u8 D_0028E378;
extern s8 D_0028EB04;
extern s32 D_0028EB8C;
extern s32 D_0028EB90;
extern u8 D_0028EC4C;
extern s32 D_0028EC50;
extern u8 D_006A4800[];
extern u8 D_006A4C00[];
extern u8 D_006C58A0[];

s32 func_0022B660(void) {
    u8 *save = D_006C58A0;
    s32 state;

    switch (state = D_0028EC50) {
    default:
        D_0028EC50 = state + 1;
        break;
    case 0:
        save[0x38] = D_0028E2B8[0];
        save[0x39] = D_0028E2B8[1];
        save[0x3A] = D_0028E2B8[2];
        save[0x3B] = D_0028E2B8[3];
        save[0x3C] = D_0028E2B8[4];
        save[0x3D] = D_0028E2B8[5];
        save[0x3E] = D_0028E2B8[6];
        save[0x3F] = D_0028E2B8[7];
        D_0028E378 = 0xFF;
        D_0028EC4C = 1;
        D_0028E368 = 0;
        memcpy(D_006A4800, save, 0x202E8);
        func_0023D4A0(D_006A4800);
        func_0022B7A0(D_006A4C00);
        func_002263C0();
        func_002263D0(1, 2, 0);
        D_0028EB90 = 0;
        D_0028EB04 = 1;
        D_0028EB8C = 0;
        D_0028EC50++;
        break;
    case 1:
        if (func_00226260() == 0) {
            D_0028EC50++;
            D_0028EB04 = 2;
        }
        break;
    case 0x11:
        D_0028EC50 = 0;
        D_0028E368 = 1;
        D_0028EC4C = 0;
        return 1;
    }
    return 0;
}
