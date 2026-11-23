#include "common.h"

s32 func_0022BFD0();
s32 func_0022C1E0();
s32 func_0022C1F0();
extern u8 *reg_a5;

void func_0022BF60(void) {
    u8 temp_a0;

    temp_a0 = (*(u8 *)((u8 *)(reg_a5) + (3)));
    switch (temp_a0) {                              /* irregular */
    case 0:
        func_0022BFD0(temp_a0);
        break;
    case 1:
        func_0022C1F0(temp_a0);
        break;
    case 2:
        func_0022C1E0(temp_a0);
        break;
    }
}
