#include "common.h"

extern volatile s8 D_0028EB58;
extern s16 D_0028EC18;
extern s8 D_0028EC1A;

extern s32 func_002273B0(s16 *state, s32 limit, s8 value);

void func_002275F0(void)
{
    if (func_002273B0(&D_0028EC18, 7, D_0028EC1A) != 0) {
        s8 value = D_0028EC1A;

        D_0028EB58 = value;
        if (value == 0) {
            D_0028EB58 = D_0028EB58 + 1;
        }
    }
}
