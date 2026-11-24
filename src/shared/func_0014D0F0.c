#include "common.h"

extern u16 D_0029C0BA[];
extern u16 D_0029C0BC[];
extern u16 D_0029C0BE[];
extern u16 *reg_a2_as_u16_p;

void func_0014D0F0(void) {
    D_0029C0BA[0] = *reg_a2_as_u16_p;
    reg_a2_as_u16_p += 1;
    D_0029C0BC[0] = *reg_a2_as_u16_p;
    reg_a2_as_u16_p += 1;
    D_0029C0BE[0] = *reg_a2_as_u16_p;
    reg_a2_as_u16_p += 1;
}
