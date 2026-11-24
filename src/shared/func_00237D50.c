#include "common.h"

s32 func_002376F0(s32);                         /* extern */
s32 func_0023A490(s32 *);                   /* extern */
extern u16 D_0028E1A4;
extern u16 D_0028E1A8;
extern u16 D_0028E1AC;
extern u16 D_0028E1B0;
extern u16 D_0028E1B4;
extern u16 D_0028E1B8;
extern s32 D_0028ED3C;
extern s32 D_0028ED70;
extern s8 D_0028ED74_as_s8;
extern s8 D_0028ED78_as_s8;
extern s32 D_006C5CA0_as_s32_a[];
extern u16 D_006CB578[];
extern u16 D_006CB57A[];
extern u16 D_006CB57C[];
extern u16 D_006CB57E[];
extern u16 D_006CB580[];
extern u16 D_006CB582[];
extern s32 D_006CB584[];

void func_00237D50(void) {
    D_0028ED78_as_s8 = 2;
    func_0023A490(D_006C5CA0_as_s32_a);
    if (D_006CB584[0] == D_0028ED3C) {
        D_0028ED74_as_s8 = 1;
        D_0028ED70 = 0;
        D_0028E1B4 = D_006CB57A[0];
        D_0028E1B8 = D_006CB578[0];
        D_0028E1B0 = D_006CB57C[0];
        D_0028E1A8 = D_006CB580[0];
        D_0028E1AC = D_006CB57E[0];
        D_0028E1A4 = D_006CB582[0];
        return;
    }
    func_002376F0(D_006CB584[0]);
}
