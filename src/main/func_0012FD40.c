#include "common.h"

s32 func_00130250();
s32 func_00130260();
s32 func_00130720();
extern u8 D_0024F340[];
extern u8 D_0024F360[];
extern s8 D_0028E1D0;
extern s8 D_0028E1D4;
extern s8 D_0028E1D8[];
extern s8 D_0028E1DA[];
extern s8 D_0028E1DC;
extern s8 D_0028E1E0;
extern s8 D_0028E1E4[];
extern s8 D_0028E1E6[];
extern s8 D_0028E1E8;
extern s8 D_0028E1EC;
extern s16 D_0028E1F0;
extern s16 D_0028E1F4;
extern s16 D_0028E1F8;
extern s8 D_0028E1FC;
extern s8 D_0028E200;
extern s8 D_0028E204;
extern s8 D_0028E208;
extern s8 D_0028E20C;
extern s8 D_0028E210;
extern s16 D_0028E214;
extern u8 D_0028E39C;
extern u8 *reg_a0;

void func_0012FD40(void) {
    s8 temp_v1;

    reg_a0 = D_0024F340;
    reg_d0.w = 0;
    D_0028E1E4[0] = 0;
    D_0028E1E6[0] = 0;
    reg_d0.b[0] = D_0028E39C;
    D_0028E1D8[0] = 0;
    D_0028E214 = 0;
    D_0028E210 = 0;
    D_0028E20C = 0;
    D_0028E208 = 0;
    D_0028E204 = 0;
    D_0028E200 = 0;
    D_0028E1FC = 0;
    D_0028E1F8 = 0;
    D_0028E1F4 = 0;
    D_0028E1F0 = 0;
    D_0028E1E0 = 0;
    D_0028E1DC = 0;
    D_0028E1DA[0] = 0;
    D_0028E1D4 = 0;
    D_0028E1D0 = 0;
    temp_v1 = *(s8 *)(reg_a0 + reg_d0.h[0]);
    reg_a0 = D_0024F360;
    D_0028E1EC = temp_v1;
    D_0028E1E8 = *(s8 *)(reg_a0 + reg_d0.h[0]);
    func_00130250();
    func_00130260();
    func_00130720();
}
