#include "common.h"

extern u16 D_0028E140;
extern u8 *D_0028E468;
extern u8 D_002A3EF0[];

void func_0019DA50(void) {
    u32 offset;
    u8 *cursor;

    D_0028E468 = D_002A3EF0;
    offset = D_0028E140;
    cursor = D_0028E468;
    D_0028E468 = cursor + offset;
    D_0028E140 = offset + 0xC;
}
