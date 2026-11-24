#include "common.h"

s32 func_0013CCE0(s16 *);                       /* extern */
s32 func_0013CCF0(s16 *);                       /* extern */
extern u16 D_0028E5BC;
extern u16 D_0028E5C0;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern s16 *reg_a1;

void func_0013CC60(void) {
    if (D_0029F260[0] < 0) {
        reg_d0.h[0] = D_0028E5C0;
        reg_a1 = D_0029F260;
        if (reg_d0.h[0] != 0) {
            func_0013CCF0(D_0029F260);
        }
    }
    if (D_0029F1F0[0] < 0) {
        reg_d0.h[0] = D_0028E5BC;
        reg_a1 = D_0029F1F0;
        if (reg_d0.h[0] != 0) {
            func_0013CCE0(D_0029F1F0);
        }
    }
}
