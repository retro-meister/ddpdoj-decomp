#include "common.h"

extern s8 D_0028E408;
extern u16 D_002962D4[];

void func_00125440(void) {
    if (D_002962D4[0] == 0) {
        D_0028E408 = 0;
        return;
    }
    D_0028E408 = 1;
}
