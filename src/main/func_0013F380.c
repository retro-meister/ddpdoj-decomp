#include "common.h"

extern u16 D_00299764[];
extern s16 D_00299766[];

void func_0013F380(void) {
    if (D_00299764[0] != 0) {
        D_00299764[0] -= 1;
        if (D_00299764[0] == 0) {
            D_00299766[0] = 0;
        }
    }
}
