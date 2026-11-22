#include "common.h"

extern s16 D_0028E23C;
extern s16 D_0028E240;
extern s16 *D_0028E468;

void func_0012FA20(void) {
    D_0028E468 = &D_0028E23C;
    *D_0028E468 = 0;
    D_0028E468 = &D_0028E240;
    *D_0028E468 = 1;
}
