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
    work_reg_tmp.b[0] = low & 15;
    work_reg_tmp.b[1] = low >> 4;
    work_reg_tmp.b[2] = high & 15;
    work_reg_tmp.b[3] = high >> 4;
    bcd_result.halfwords[0] = work_reg_tmp.b[0] + (work_reg_tmp.b[1] * 10 +
        (work_reg_tmp.b[3] * 1000 + work_reg_tmp.b[2] * 100));
}
