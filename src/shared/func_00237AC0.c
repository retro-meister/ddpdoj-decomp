#include "common.h"

extern s32 printf(const char *format, ...);
extern void *memset(void *dst, s32 c, u32 n);
extern void func_00117390(u32 seed);
extern s32 func_001173A8(void);
extern void func_00238B90(u8 *data);
extern char D_0028BEE0[];
extern char D_0028BF00[];
extern u16 D_0028E1A4;
extern u16 D_0028E1A8;
extern u16 D_0028E1AC;
extern u16 D_0028E1B0;
extern u16 D_0028E1B4;
extern u16 D_0028E1B8;
extern u8 D_0028E2BB;
extern u8 D_0028E2BC;
extern u8 D_0028E2E4;
extern u8 D_0028E38C;
extern u16 D_0028E8A8;
extern u16 D_0028E8AC;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u8 D_0028ED64;
extern s32 D_0028ED70;
extern u8 D_0028ED74;
extern u8 D_0028ED78;
extern u8 D_0028ED80;
extern u16 D_006C58A0[];
extern u16 D_006C58A2[];
extern u16 D_006C58A4[];
extern u16 D_006C58A6[];
extern u16 D_006C58A8[];
extern u16 D_006C5CA0[];
extern u8 D_006CB1D4[];
extern u16 D_006CB578[];
extern u16 D_006CB57A[];
extern u16 D_006CB57C[];
extern u16 D_006CB57E[];
extern u16 D_006CB580[];
extern u16 D_006CB582[];
extern u8 D_006CB5A8[];

void func_00237AC0(void) {
    s32 i;
    u16 *data;
    u16 *save;

    if (D_0028ED80 == 0 && D_0028ED74 == 2) {
        data = D_006C5CA0;
        save = D_006C58A0;
    D_0028ED78 = 1;
    D_0028ED74 = 1;
    D_0028ED64 = 0;
    D_0028ED70 = 0;
    printf(D_0028BEE0);
    memset(save, 0, 0x400);
    memset(D_006CB5A8, 0, 0x1A5E0);
    memset(data, 0, 0x5534);
    func_00238B90((u8 *)data);
    if (D_0028E91C != 0 || D_0028E910 == 0) {
        memset(D_006CB1D4, 0, 0x3A4);
    }
    func_00117390(D_0028E2BC * D_0028E2BB);
    for (i = 0; i < 0x20; i++) {
        ((u8 *)D_006C58A0)[0x5CE8 + i] = func_001173A8();
    }
    D_006CB57A[0] = D_0028E1B4;
    D_006CB578[0] = D_0028E1B8;
    D_006CB57C[0] = D_0028E1B0;
    D_006CB580[0] = D_0028E1A8;
    D_006CB57E[0] = D_0028E1AC;
    D_006C58A2[0] = 0xFF;
    D_006C58A4[0] = 0xFF;
    D_006C58A6[0] = 0xFF;
    D_006C58A8[0] = 0xFF;
    D_006CB582[0] = D_0028E1A4;
    save[6] = data[0x31BC / 2];
    save[7] = data[0x31B6 / 2];
    save[1] = data[0xC6E / 2];
    save[2] = data[0xC70 / 2];
    if (save[2] == 0) {
        save[2] = 0xFF;
        save[1] = 0xFF;
    }
    save[3] = data[0xCD0 / 2];
    save[4] = data[0xCD2 / 2];
    if (save[4] == 0) {
        save[4] = 0xFF;
        save[3] = 0xFF;
    }
    save[5] = D_0028E38C;
    save[18] = D_0028E2E4;
    printf(D_0028BF00, D_0028E8A8, D_0028E8AC);
    }
}
