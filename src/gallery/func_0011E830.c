#include "common.h"

extern void func_00100380(void);
extern void func_00101C40(s32 enabled);
extern void func_00102320(void);
extern void func_00102798(void);

void func_0011E830(void) {
    func_00102798();
    func_00102320();
    func_00100380();
    func_00101C40(1);
}
