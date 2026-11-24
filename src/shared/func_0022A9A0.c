#include "common.h"

extern void func_0018D4B0(void);
extern s8 D_0028EB34;
extern s8 D_0028EB54;
extern s8 D_0028EB64;
extern s8 D_0028EC24;
extern u32 D_0057CC70_as_u32_a[];

void func_0022A9A0(void)
{
    if (D_0057CC70_as_u32_a[D_0028EC24] & 0x60) {
        func_0018D4B0();
        D_0028EB54 = 2;
        D_0028EB34 = 2;
        D_0028EB64 = D_0028EB64 + 1;
    }
}
