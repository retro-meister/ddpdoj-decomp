#include "common.h"

extern u16 D_0028E330;
extern u16 D_0028E334;
extern u16 D_0028E338;
extern u16 D_0028E33C;
extern u16 D_0028E340;
extern u16 D_0028E344;
extern u16 D_0028E348;
extern u16 D_0028E34C;
extern u8 D_0028E35C;
extern u8 D_0028E360;

void func_00217CD0(void) {
    D_0028E334 = 0;
    D_0028E33C = 0;
    D_0028E330 = 0;
    D_0028E338 = 0;
    if (D_0028E360 != 0) {
        D_0028E334 = D_0028E344;
        D_0028E33C = D_0028E34C;
    }
    if (D_0028E35C != 0) {
        D_0028E330 = D_0028E340;
        D_0028E338 = D_0028E348;
    }
}
