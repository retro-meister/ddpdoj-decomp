#include "common.h"

extern u16 D_0028E490;
extern void *D_0028E450;

void func_002037B0(void) {
    u32 scaled = (u32)D_0028E490 << 16;
    D_0028E490 = (u16)(scaled - D_0028E490);
    D_0028E490 += 0x1C00;
    *(u16 *)((u8 *)D_0028E450 + 4) = D_0028E490;
}
