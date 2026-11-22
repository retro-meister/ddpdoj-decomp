#include "common.h"

s32 func_00125E80();                            /* extern */
s32 func_00131630();                            /* extern */
s32 func_0013B190();                            /* extern */
s32 func_0013E7C0();                            /* extern */
s32 func_0013E850();                            /* extern */
s32 func_001AD720();                            /* extern */
s32 func_00206D70();                            /* extern */
s32 func_002071C0();                            /* extern */
extern s16 D_0028E59C;
extern s16 D_0028E854;

void func_001317E0(void) {
    func_0013B190();
    func_00206D70();
    func_00131630();
    func_00125E80();
    func_001AD720();
    D_0028E854 = 0;
    func_0013E7C0();
    func_0013E850();
    D_0028E59C = 0;
    reg_d0.h[0] = 7;
    func_002071C0();
}
