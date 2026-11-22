#include "common.h"

extern u8 *D_0028E454;

void func_00171400(void) {
    u8 *flags_ptr;
    u8 flags;

    flags_ptr = D_0028E454 + 2;
    flags = flags_ptr[0];
    if (flags & 1) {
        flags_ptr[0] = flags & 0xFE;
        return;
    }
    flags_ptr[0] = flags | 1;
}
