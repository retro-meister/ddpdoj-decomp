#include "common.h"

s32 func_00216160(s32 *, s32, s32);         /* extern */
s32 func_00218650(s32);                     /* extern */
s32 printf(s32 *);                          /* extern */
extern s32 D_00287058[];
extern s32 D_0028EA74;
extern s32 D_0029CB00[];
extern s32 D_0029CB04[];
extern s32 D_0050D780[];

void func_00218B00(void) {
    D_0028EA74 = 0x1E40;
    func_00216160(D_0050D780, D_0029CB00[0], D_0029CB04[0]);
    func_00218650(2);
    printf(D_00287058);
}
