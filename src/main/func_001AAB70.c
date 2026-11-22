#include "common.h"

extern void func_001AAB90(void);
extern void *reg_a1;
extern void *reg_a0;
extern u8 D_0028E728;
extern u8 D_0028E730;

void func_001AAB70(void) {
    reg_a0 = &D_0028E730;
    reg_a1 = &D_0028E728;
    func_001AAB90();
}
