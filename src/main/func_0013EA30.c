#include "common.h"

extern u8 D_0028E855;
extern u8 D_0029F22F[];

void func_0013EA30(void)
{
    u32 destinationAddress;

    reg_d0.b[0] = 0x50;
    if (D_0028E855 & 4) {
        reg_d0.b[0] = 0x78;
    }

    destinationAddress = (u32)D_0029F22F;
    *(volatile u8 *)destinationAddress = reg_d0.b[0];
    *(volatile u8 *)destinationAddress = 0x50;
}
