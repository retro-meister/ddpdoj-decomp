#include "common.h"

extern s16 D_0028E234;
extern s16 D_0028E238;
extern s16 *D_0028E468;

void func_0012FA50(void) {
    D_0028E468 = &D_0028E234;
    *D_0028E468 = 0;
    D_0028E468 = &D_0028E238;
    *D_0028E468 = 0;
}
