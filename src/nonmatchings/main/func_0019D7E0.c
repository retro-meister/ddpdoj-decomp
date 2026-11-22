#include "common.h"

extern u16 D_0028E150;
extern u8 *D_0028E468;
extern u8 D_002A4430[];

void func_0019D7E0(void) {
    u32 counter;

    counter = D_0028E150;
    D_0028E468 = D_002A4430;
    D_0028E468 += counter;
    D_0028E150 = counter + 0xC;
}
