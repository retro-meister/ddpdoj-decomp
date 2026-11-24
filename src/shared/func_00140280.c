#include "common.h"

extern u32 D_0028E484;

void func_00140280(s32 *arg0, u32 *arg1) {
    s32 carry;
    s32 n;
    s32 digit;
    s32 i;

    carry = 0;
    n = 0;
    reg_tmp.w = *arg1;
    D_0028E484 = *arg0;
    reg_d2.w = 0;
    do {
        digit = carry + ((reg_tmp.w & 0xF) + (D_0028E484 & 0xF));
        carry = 0;
        if (digit >= 0xA) {
            carry = 1;
            digit -= 0xA;
        }
        n += 1;
        reg_tmp.w = (u32) reg_tmp.w >> 4;
        D_0028E484 = (u32) D_0028E484 >> 4;
        reg_d2.w *= 0x10;
        reg_d2.w |= digit;
    } while (n < 8);
    *arg0 = 0;
    for (i = 0; i < 8; i++) {
        *arg0 *= 0x10;
        *arg0 = *arg0 | (reg_d2.w & 0xF);
        reg_d2.w = (u32) ((s64) (((u64) reg_d2.w >> 4) << 0x20) >> 0x20);
    }
}
