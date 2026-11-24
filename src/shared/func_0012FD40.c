#include "common.h"

s32 func_00130250();
s32 func_00130260();
s32 func_00130720();
extern u8 D_0024F340[];
extern u8 D_0024F360[];
extern s8 D_0028E1D0_as_s8;
extern s8 D_0028E1D4_as_s8;
extern s8 D_0028E1D8_as_s8_a[];
extern s8 D_0028E1DA_as_s8_a[];
extern s8 D_0028E1DC_as_s8;
extern s8 D_0028E1E0_as_s8;
extern s8 D_0028E1E4_as_s8_a[];
extern s8 D_0028E1E6_as_s8_a[];
extern s8 D_0028E1E8_as_s8;
extern s8 D_0028E1EC_as_s8;
extern s16 D_0028E1F0_as_s16;
extern s16 D_0028E1F4_as_s16;
extern s16 D_0028E1F8_as_s16;
extern s8 D_0028E1FC;
extern s8 D_0028E200;
extern s8 D_0028E204_as_s8;
extern s8 D_0028E208_as_s8;
extern s8 D_0028E20C_as_s8;
extern s8 D_0028E210_as_s8;
extern s16 D_0028E214;
extern u8 D_0028E39C;
extern u8 *reg_a0;

void func_0012FD40(void) {
    s8 temp_v1;

    reg_a0 = D_0024F340;
    reg_d0.w = 0;
    D_0028E1E4_as_s8_a[0] = 0;
    D_0028E1E6_as_s8_a[0] = 0;
    reg_d0.b[0] = D_0028E39C;
    D_0028E1D8_as_s8_a[0] = 0;
    D_0028E214 = 0;
    D_0028E210_as_s8 = 0;
    D_0028E20C_as_s8 = 0;
    D_0028E208_as_s8 = 0;
    D_0028E204_as_s8 = 0;
    D_0028E200 = 0;
    D_0028E1FC = 0;
    D_0028E1F8_as_s16 = 0;
    D_0028E1F4_as_s16 = 0;
    D_0028E1F0_as_s16 = 0;
    D_0028E1E0_as_s8 = 0;
    D_0028E1DC_as_s8 = 0;
    D_0028E1DA_as_s8_a[0] = 0;
    D_0028E1D4_as_s8 = 0;
    D_0028E1D0_as_s8 = 0;
    temp_v1 = *(s8 *)(reg_a0 + reg_d0.h[0]);
    reg_a0 = D_0024F360;
    D_0028E1EC_as_s8 = temp_v1;
    D_0028E1E8_as_s8 = *(s8 *)(reg_a0 + reg_d0.h[0]);
    func_00130250();
    func_00130260();
    func_00130720();
}
