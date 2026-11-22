#include "common.h"

s32 func_00201450();
extern s8 D_0028E408;
extern u16 D_00299764[];
extern u16 D_00299766[];
void func_00201690(void) {
    func_00201450();
    if (D_0028E408 == 0) {
        D_00299764[0] = 1;
        D_00299766[0] = 0xFFFF;
    }
}
