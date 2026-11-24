#include "common.h"

extern s8 D_0028E35C;
extern s8 D_0028EA40;
extern s8 D_0028EA41;

extern void scePadSetActDirect(s32, s32, void *);

void func_00217B90(void) {
    D_0028E35C = 0;
    D_0028EA41 = 0;
    scePadSetActDirect(1, 0, &D_0028EA40);
}
