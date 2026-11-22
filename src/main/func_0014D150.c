#include "common.h"

extern u16 *D_0028E460;
extern void func_0018DED0(void);

void func_0014D150(void) {
    work_reg_1.h[0] = *D_0028E460;
    D_0028E460++;
    func_0018DED0();
}
