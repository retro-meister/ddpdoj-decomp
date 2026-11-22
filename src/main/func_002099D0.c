#include "common.h"

extern s32 D_00268770[];
extern s32 *D_0028E468;
extern u16 D_0028E48C;
extern u16 bcd_result;
void func_002092F0(void);

void func_002099D0(void) {
    D_0028E468 = D_00268770;
    work_reg_0.h[0] = 7;
    work_reg_1.h[0] = 0x29;
    bcd_result = D_0028E48C;
    func_002092F0();
}
