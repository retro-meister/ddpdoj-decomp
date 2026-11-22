#include "common.h"

extern u8 D_0028E30C;
extern u16 D_0028E3C0;
extern volatile u8 D_0028ED7C;
extern u8 D_0028ED80;

void func_0014D220(void) {
    if (D_0028E3C0 == 0 && D_0028E30C != 0 && D_0028ED80 != 0) {
        if (D_0028ED7C == 2) {
            return;
        }
    }
}
