#include "common.h"

s32 func_002164A0();                            /* extern */
s32 printf(s32 *);                          /* extern */
extern s32 D_00287030[];
extern s32 D_0028E9DC;

void func_00216470(void) {
    printf(D_00287030);
    D_0028E9DC = 0;
    func_002164A0();
}
