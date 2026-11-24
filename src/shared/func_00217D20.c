#include "common.h"

extern u8 D_0028E27C;
extern u16 D_0028E330;
extern u16 D_0028E334;
extern u16 D_0028E338;
extern u16 D_0028E33C;
extern u16 D_0028E340;
extern u16 D_0028E344;
extern u16 D_0028E348;
extern u16 D_0028E34C;
extern s8 D_0028E35C;
extern s8 D_0028E360;

void func_00217D20(void)
{
    if (D_0028E27C != 0) {
        if (D_0028E33C > 0x3C) {
            D_0028E34C = D_0028E33C;
            D_0028E360 = 1;
            D_0028E344 = D_0028E334;
        }

        if (D_0028E338 > 0x3C) {
            D_0028E348 = D_0028E338;
            D_0028E35C = 1;
            D_0028E340 = D_0028E330;
        }
    }
}
