#include "common.h"

s32 func_00222260(s32);                     /* extern */
s32 func_00227310(s32 *);                   /* extern */
extern s32 D_0028EBE8;
extern s32 D_0028EC7C;

void func_00227900(void) {
    func_00227310(&D_0028EBE8);
    func_00222260(0xA);
    D_0028EC7C = 0;
}
