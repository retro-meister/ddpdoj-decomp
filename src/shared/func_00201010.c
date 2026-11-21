#include "common.h"

union DecimalResult {
    unsigned int word;
    unsigned short halfwords[2];
};

extern union DecimalResult bcd_result;

void func_00201010(void)
{
    unsigned char low = work_reg_0.b[0];
    unsigned char high = work_reg_0.b[1];

    bcd_result.word = 0;
    bcd_digits[0] = low & 15;
    bcd_digits[1] = low >> 4;
    bcd_digits[2] = high & 15;
    bcd_digits[3] = high >> 4;
    bcd_result.halfwords[0] = bcd_digits[0] + (bcd_digits[1] * 10 +
        (bcd_digits[3] * 1000 + bcd_digits[2] * 100));
}
