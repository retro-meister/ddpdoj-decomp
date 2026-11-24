#include "common.h"

extern void func_0023D4E0(void *, void *, s32);
extern u8 D_002B4D50[];

void func_0023DB80(u8 *base)
{
    s32 offset = 0;

    do {
        func_0023D4E0((u8 *)offset + (s32)base + 0x1EE, D_002B4D50, 0x82);
        func_0023D4E0((u8 *)(offset + (s32)base) + 0x248, D_002B4D50, 0x82);
        offset += 0xA;
    } while (offset < 0x5A);
}
