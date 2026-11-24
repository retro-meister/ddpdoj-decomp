#include "common.h"

extern void func_0021B840(s32, s32);
extern u8 D_00271C60[];
extern u8 D_00271C64[];
extern s8 D_0028E270;
extern s8 D_0028E271;
extern s8 D_0028E272;
extern s8 D_0028E273;
extern s8 D_0028E274;
extern s8 D_0028E275;
extern s8 D_0028E276;
extern s8 D_0028E277;
extern s8 D_0028E28C;
extern u8 D_0028E2DC;
extern s8 D_0028E2E0;
extern u16 D_0028E32C;
extern u8 D_0028E354;
extern u8 D_0028E358;
extern s8 D_0028E9EC;
extern s8 D_0068DD01[];
extern s8 D_0068DD02[];
extern s8 D_0068DD03[];
extern s8 D_0068DD04[];
extern s8 D_0068DD05[];
extern s8 D_0068DD06[];
extern s8 D_0068DD09[];
extern s8 D_0068DD0A[];
extern s8 D_0068DD0B[];
extern s8 D_0068DD0C[];
extern s8 D_0068DD0D[];
extern s8 D_0068DD0E[];
extern s8 D_0068DD0F[];
extern s8 D_0068DD10[];
void func_0021F2C0(void) {
    s32 temp_a0;

    if (D_0028E358 != D_0068DD01[0]) {
        D_0028E354 = 0;
        D_0028E9EC = 1;
        D_0068DD02[0] = 0;
    }
    if (D_0028E354 != D_0068DD02[0]) {
        D_0028E354 = (u8) D_0068DD02[0];
        if (D_0028E358 == 0) {
            D_0028E354 &= 3;
        } else {
            D_0028E354 &= 1;
        }
        D_0068DD02[0] = D_0028E354;
        D_0028E9EC = 1;
    }
    if (D_0028E2DC != D_0068DD03[0]) {
        D_0028E9EC = 1;
    }
    D_0028E2DC = (u8) D_0068DD03[0];
    D_0028E2E0 = D_0068DD06[0];
    D_0028E28C = D_0068DD05[0];
    if (D_0028E32C != D_0068DD04[0]) {
        D_0028E32C = (u16) (s8)(D_0068DD04[0]);
        if (D_0028E32C != 5) {
            temp_a0 = (D_0028E32C & 0xFFFF) * 8;
            func_0021B840(*(s32 *)(D_00271C60 + temp_a0), *(s32 *)(D_00271C64 + temp_a0));
        }
    }
    D_0028E270 = D_0068DD09[0];
    D_0028E271 = D_0068DD0A[0];
    D_0028E272 = D_0068DD0B[0];
    D_0028E273 = D_0068DD0C[0];
    D_0028E274 = D_0068DD0D[0];
    D_0028E275 = D_0068DD0E[0];
    D_0028E276 = D_0068DD0F[0];
    D_0028E277 = D_0068DD10[0];
}
