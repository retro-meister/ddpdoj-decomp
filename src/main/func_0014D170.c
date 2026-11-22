#include "common.h"

extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C[];
extern s16 D_0029976E[];
extern u16 *reg_a1;

void func_0014D170(void) {
    reg_d0.h[0] = *reg_a1;
    reg_a1 += 1;
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
        D_0029976C[0] = 1;
    }
    if (reg_d0.h[0] == 4) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C[0] = 1;
        D_0029976E[0] = 1;
    }
}
