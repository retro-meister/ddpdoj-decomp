#include "common.h"

extern s8 D_0028E360;
extern s8 D_0028EA41;
extern s64 D_0028EA40;
void scePadSetActDirect(s64, s64, void *);

void func_00217B70(void) {
    s64 zero;

    D_0028E360 = 0;
    D_0028EA41 = 0;
    scePadSetActDirect(zero = 0, zero, &D_0028EA40);
}
