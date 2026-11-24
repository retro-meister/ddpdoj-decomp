#include "common.h"

s32 func_00217C90();
extern u8 D_0028E27C;
extern s16 D_0028E344;
extern s16 D_0028E34C;
extern s8 D_0028E360;
extern u16 D_0028E3C0;
extern u8 D_0028ED58;
extern u8 D_0028ED7C;
extern s16 D_0029F260[];
void func_00217BB0(s16 arg0, s16 arg1) {
    if ((D_0028E3C0 == 0) && (D_0028E27C != 0)) {
        if (D_0028ED7C == 2) {
            if (D_0028ED58 != 0) {
                func_00217C90();
            }
        } else if (D_0029F260[0] < 0) {
            D_0028E344 = arg0;
            D_0028E360 = 1;
            D_0028E34C = arg1;
        }
    }
}
