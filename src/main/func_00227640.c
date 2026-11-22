#include "common.h"

s32 func_00222340(s32);                     /* extern */
s32 func_00227310(s32 *);                   /* extern */
extern s8 D_0028EB50;
extern s8 D_0028EB58;
extern s32 D_0028EC18;
extern s8 D_0028EC1A;
extern s16 D_0028EC1C;

void func_00227640(void) {
    func_00227310(&D_0028EC18);
    D_0028EC1A = 0;
    D_0028EC1C = 0;
    D_0028EB50 = 0;
    D_0028EB58 = 0;
    func_00222340(7);
}
