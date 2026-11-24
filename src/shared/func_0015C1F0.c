#include "common.h"

extern u8 *reg_a0;
extern u8 D_0025F770[];
extern u8 D_002623F0[];
extern u8 D_00262430[];

extern void func_001A3020(void);

void func_0015C1F0(void)
{
    reg_a0 = D_00262430;
    reg_d0.h[0] = 0;
    func_001A3020();

    reg_a0 = D_002623F0;
    reg_d0.h[0] = 1;
    func_001A3020();

    reg_a0 = D_0025F770;
    reg_d0.h[0] = 2;
    func_001A3020();
}
