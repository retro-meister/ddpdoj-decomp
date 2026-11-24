#include "common.h"

s32 func_0013B190();                            /* extern */
s32 func_0018DE90();                            /* extern */
s32 func_0018DEE0();                            /* extern */
s32 func_00206D70();                            /* extern */
s32 func_002071C0();                            /* extern */
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern s8 D_0028ED64_as_s8;

void func_00134BD0(void) {
    func_0018DEE0();
    func_0018DE90();
    func_0013B190();
    func_00206D70();
    reg_d0.h[0] = 0xE;
    func_002071C0();
    if (D_0028E910 != 1) {
        if ((s32) 0 < D_0028E91C) {
            goto block_3;
        }
    } else {
block_3:
        D_0028ED64_as_s8 = 1;
    }
}
