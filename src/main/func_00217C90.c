#include "common.h"

extern s16 D_0028E340;
extern s16 D_0028E344;
extern s16 D_0028E348;
extern s16 D_0028E34C;
extern s8 D_0028E35C;
extern s8 D_0028E360;
extern s8 D_0028EC24;

void func_00217C90(s16 arg0, s16 arg1) {
    if (D_0028EC24 == 0) {
        D_0028E344 = arg0;
        D_0028E360 = 1;
        D_0028E34C = arg1;
        return;
    }
    D_0028E340 = arg0;
    D_0028E35C = 1;
    D_0028E348 = arg1;
}
