#include "common.h"

s32 func_00129450();                            /* extern */
s32 func_00129460();                            /* extern */
extern u16 D_0028E910;

void func_00129280(void) {
    if (D_0028E910 == 0) {
        func_00129460();
        return;
    }
    func_00129450();
}
