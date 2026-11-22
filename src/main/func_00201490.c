#include "common.h"

s32 func_00201450();
s32 func_002018E0();
extern s8 D_0028E408;
extern u16 D_00299764[];
extern u16 D_00299766[];
void func_00201490(void) {
    func_00201450();
    if (D_0028E408 == 0) {
        D_00299764[0] = 1;
        D_00299766[0] = 0xFFFF;
        func_002018E0();
    }
}
