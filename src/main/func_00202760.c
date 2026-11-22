#include "common.h"

extern u16 *reg_a0;
extern u16 reg_d3;
extern u16 reg_d2;

void func_00202780(void);

void func_00202760(void) {
    reg_d2 = reg_a0[1];
    reg_d3 = reg_a0[2];
    func_00202780();
}
