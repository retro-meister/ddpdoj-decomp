#include "common.h"

extern s16 reg_d4;
extern s16 reg_d3;

void func_001A53E0(void);

void func_001A8A40(void) {
    reg_d3 = 0x430;
    reg_d4 = 0x9;
    func_001A53E0();
}
