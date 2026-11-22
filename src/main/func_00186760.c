#include "common.h"

extern u16 D_00253250[];
extern u16 D_00253280[];

extern u16 D_0028C190[];
extern u16 D_0028C192[];
extern u16 D_0028C194[];
extern u16 D_0028C196[];

void func_00186760(void) {
    work_reg_tmp.w = (u32)D_00253250;
    D_0028C190[0] = work_reg_tmp.h[1];
    D_0028C192[0] = work_reg_tmp.h[0];
    work_reg_tmp.w = (u32)D_00253280;
    D_0028C194[0] = work_reg_tmp.h[1];
    D_0028C196[0] = work_reg_tmp.h[0];
}
