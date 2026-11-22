#include "common.h"

s32 func_00124D90();                            /* extern */
s32 func_00124F50();                            /* extern */
s32 func_001C7D10();                            /* extern */

void func_001C7CB0(void) {
    reg_d0.w = 0;
    func_00124D90();
    reg_d0.w = 0;
    func_00124F50();
    reg_d0.w = 2;
    func_00124F50();
    reg_d0.w = 0xB;
    func_00124F50();
    reg_d0.w = 0xC;
    func_00124F50();
    reg_d0.w = 0xD;
    func_00124F50();
    func_001C7D10();
}
