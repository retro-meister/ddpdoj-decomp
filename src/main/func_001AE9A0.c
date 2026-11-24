#include "common.h"

s32 func_001AE9A0(u32 *arg0, u32 *arg1) {
    u32 b;
    u32 a;
    u32 tmp;
    u32 res;
    u32 digit;
    s32 carry;
    s32 i;

    a = *arg0;
    b = *arg1;
    tmp = 0;
    carry = 0;
    for (i = 0; i < 8; i++) {
        digit = carry + ((b & 0xF) + (a & 0xF));
        carry = 0;
        if (digit >= 0xAU) {
            carry = 1;
            digit -= 0xA;
        }
        tmp <<= 4;
        tmp |= digit;
        b >>= 4;
        a >>= 4;
    }
    res = 0;
    for (i = 0; i < 8; i++) {
        res <<= 4;
        res |= tmp & 0xF;
        tmp >>= 4;
    }
    *arg1 = res;
    return carry;
}
