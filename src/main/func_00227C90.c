#include "common.h"

s32 func_00222260(s32);                     /* extern */
s32 func_002263D0(s32, s8, s32);        /* extern */
s32 func_00227310(s32 *);                   /* extern */
extern s32 D_0028EBE0;
extern s8 D_0028EC20;
extern s8 D_0028EC24;
extern s8 D_0028ED7C;

void func_00227C90(void) {
    func_00227310(&D_0028EBE0);
    func_00222260(0xB);
    D_0028EC20 = 0;
    D_0028ED7C = 0;
    func_002263D0(0, D_0028EC24, 0);
}
