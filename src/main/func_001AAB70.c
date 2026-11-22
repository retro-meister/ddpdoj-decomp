#include "common.h"

extern void func_001AAB90(void);
extern void *D_0028E464;
extern void *D_0028E468;
extern u8 D_0028E728;
extern u8 D_0028E730;

void func_001AAB70(void) {
    D_0028E468 = &D_0028E730;
    D_0028E464 = &D_0028E728;
    func_001AAB90();
}
