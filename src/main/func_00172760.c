#include "common.h"

extern u16 D_00261070[];
extern u16 D_00261BF0[];
extern u16 D_00261CB0[];

extern u16 D_0025F5F4[];
extern u16 D_0025F5F6[];
extern u16 D_0025F5FC[];
extern u16 D_0025F5FE[];
extern u16 D_0025F604[];
extern u16 D_0025F606[];
extern u16 D_0025F60C[];
extern u16 D_0025F60E[];

void func_00172760(void) {
    work_reg_tmp.w = (u32)D_00261070;
    D_0025F5F4[0] = work_reg_tmp.h[1];
    D_0025F5F6[0] = work_reg_tmp.h[0];
    work_reg_tmp.w = (u32)D_00261CB0;
    D_0025F5FC[0] = work_reg_tmp.h[1];
    D_0025F5FE[0] = work_reg_tmp.h[0];
    work_reg_tmp.w = (u32)D_00261CB0;
    D_0025F604[0] = work_reg_tmp.h[1];
    D_0025F606[0] = work_reg_tmp.h[0];
    work_reg_tmp.w = (u32)D_00261BF0;
    D_0025F60C[0] = work_reg_tmp.h[1];
    D_0025F60E[0] = work_reg_tmp.h[0];
}
