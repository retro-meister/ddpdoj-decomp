#include "common.h"

extern u16 D_002420C0[];
extern u16 D_002420D0[];
extern u16 D_002420E0[];
extern void func_0019BEC0(void);
extern void func_0019C470(void);

extern u16 D_00242048[];
extern u16 D_0024204A[];
extern u16 D_0024204C[];
extern u16 D_0024204E[];
extern u16 D_00242098[];
extern u16 D_0024209A[];
extern u16 D_0024209C[];
extern u16 D_0024209E[];
extern u16 D_002420A8[];
extern u16 D_002420AA[];
extern u16 D_002420AC[];
extern u16 D_002420AE[];
extern u16 D_002420B0[];
extern u16 D_002420B2[];

void func_001881E0(void) {
    work_reg_tmp.w = (u32)func_0019BEC0;
    D_00242048[0] = work_reg_tmp.h[1];
    D_0024204A[0] = work_reg_tmp.h[0];
    work_reg_tmp.w = (u32)func_0019C470;
    D_0024204C[0] = work_reg_tmp.h[1];
    D_0024204E[0] = work_reg_tmp.h[0];
    work_reg_tmp.w = (u32)func_0019BEC0;
    D_00242098[0] = work_reg_tmp.h[1];
    D_0024209A[0] = work_reg_tmp.h[0];
    work_reg_tmp.w = (u32)func_0019C470;
    D_0024209C[0] = work_reg_tmp.h[1];
    D_0024209E[0] = work_reg_tmp.h[0];
    work_reg_tmp.w = (u32)D_002420C0;
    D_002420A8[0] = work_reg_tmp.h[1];
    D_002420AA[0] = work_reg_tmp.h[0];
    work_reg_tmp.w = (u32)D_002420D0;
    D_002420AC[0] = work_reg_tmp.h[1];
    D_002420AE[0] = work_reg_tmp.h[0];
    work_reg_tmp.w = (u32)D_002420E0;
    D_002420B0[0] = work_reg_tmp.h[1];
    D_002420B2[0] = work_reg_tmp.h[0];
}
