#include "common.h"

extern u16 D_00261D30[];

extern u16 D_00265C16[];
extern u16 D_00265C18[];
extern u16 D_00265F66[];
extern u16 D_00265F68[];
extern u16 D_00266336[];
extern u16 D_00266338[];

void func_00187300(void) {
    work_reg_tmp.w = (u32)D_00261D30;
    D_00265C16[0] = work_reg_tmp.h[1];
    D_00265C18[0] = work_reg_tmp.h[0];
    work_reg_tmp.w = (u32)D_00261D30;
    D_00265F66[0] = work_reg_tmp.h[1];
    D_00265F68[0] = work_reg_tmp.h[0];
    work_reg_tmp.w = (u32)D_00261D30;
    D_00266336[0] = work_reg_tmp.h[1];
    D_00266338[0] = work_reg_tmp.h[0];
}
