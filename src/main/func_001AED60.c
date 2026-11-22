#include "common.h"

extern void func_001AED90(void);
extern u8 *D_0028E468;
extern u16 D_0028E490;
extern u32 D_0028E498;
extern u16 D_0028E748;
extern u32 D_0028E764;
extern u8 D_002BAFAA[];

void func_001AED60(void) {
    D_0028E468 = D_002BAFAA;
    work_reg_0.w = D_0028E764;
    D_0028E490 = D_0028E748;
    D_0028E498 = work_reg_0.w;
    func_001AED90();
}
