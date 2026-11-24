#include "common.h"

extern void func_001AAB90(void);
extern void *reg_a1_as_void_p;
extern void *reg_a0_as_void_p;
extern u8 D_0028E728_as_u8;
extern u8 D_0028E730_as_u8;

void func_001AAB70(void) {
    reg_a0_as_void_p = &D_0028E730_as_u8;
    reg_a1_as_void_p = &D_0028E728_as_u8;
    func_001AAB90();
}
