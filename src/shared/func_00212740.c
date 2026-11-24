#include "common.h"

s32 memalign(s32, s32);                /* extern */
s32 func_002127B0();                            /* extern */
s32 func_00212C30();                            /* extern */
s32 func_002182F0();                            /* extern */
s32 func_00218D90();                            /* extern */
s32 printf(s32 *, s32, s32);            /* extern */
extern s32 D_00286EC0[];
extern s32 D_0028E9C8;
extern s32 D_0028E9D8;

void func_00212740(void) {
    *(s32 *)0x10000000 = 0;
    D_0028E9C8 = memalign(0x40, 0x300000);
    printf(D_00286EC0, D_0028E9C8, 0x2D9248);
    D_0028E9D8 = D_0028E9C8;
    func_00212C30();
    func_002127B0();
    func_002182F0();
    func_00218D90();
}
