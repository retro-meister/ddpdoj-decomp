#include "common.h"

extern Reg32 work_reg_0;
extern u16 D_0028E750;
extern u16 D_0028E490;
extern u32 D_0028E768;
extern u32 *D_0028E468;
extern u32 D_0028E498;
extern u8 D_002BAF50[];

void func_001AED90(void);

void func_001AED30(void) {
    D_0028E468 = (u32 *)D_002BAF50;
    work_reg_0.w = D_0028E768;
    D_0028E490 = D_0028E750;
    D_0028E498 = work_reg_0.w;
    func_001AED90();
}
