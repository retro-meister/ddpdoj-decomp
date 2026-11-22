#include "common.h"

extern s8 D_0028E408;
extern u8 *D_0028E450;

void func_001D66B0(void) {
    if (D_0028E450[0x69] == 0) {
        D_0028E408 = 0;
        return;
    }
    D_0028E408 = 1;
}
