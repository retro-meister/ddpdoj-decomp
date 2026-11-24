#include "common.h"

extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];
extern s16 D_0029976E_as_s16_a[];
extern u16 *reg_a1_as_u16_p;

void func_0014D170(void) {
    reg_d0.h[0] = *reg_a1_as_u16_p;
    reg_a1_as_u16_p += 1;
    if (reg_d0.h[0] == 1) {
        D_00299768[0] = 1;
    }
    if (reg_d0.h[0] == 2) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
    }
    if (reg_d0.h[0] == 3) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C_as_s16_a[0] = 1;
    }
    if (reg_d0.h[0] == 4) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C_as_s16_a[0] = 1;
        D_0029976E_as_s16_a[0] = 1;
    }
}
