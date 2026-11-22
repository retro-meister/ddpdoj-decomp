#include "common.h"

s32 func_00222340(s32);                     /* extern */
s32 func_00227310(s32 *);                   /* extern */
extern s8 D_0028EB04;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s32 D_0028EB90;
extern s32 D_0028EBD8;
extern s8 D_0028EBDA;

void func_0022A260(void) {
    func_00227310(&D_0028EBD8);
    func_00222340(0xD);
    D_0028EBDA = 0;
    D_0028EB58 = 1;
    D_0028EB54 = 0;
    D_0028EB90 = 0x40;
    D_0028EB04 = 2;
}
