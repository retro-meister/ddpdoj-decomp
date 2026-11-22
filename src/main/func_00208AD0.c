#include "common.h"

void func_00208A60(void);
extern u8 D_00269160[];
extern u8 D_00269180[];
extern u8 D_002691A0[];
extern u8 D_002691C0[];
extern u8 D_002691E0[];
extern u8 *reg_a0;

void func_00208AD0(void) {
    reg_a0 = D_00269160;
    reg_d0.w = 0;
    func_00208A60();
    reg_a0 = D_00269180;
    reg_d0.w = 1;
    func_00208A60();
    reg_a0 = D_002691A0;
    reg_d0.w = 2;
    func_00208A60();
    reg_a0 = D_002691C0;
    reg_d0.w = 3;
    func_00208A60();
    reg_a0 = D_002691E0;
    reg_d0.w = 4;
    func_00208A60();
}
