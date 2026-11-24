#include "common.h"

s32 func_0019C6D0();
extern u16 D_0026E540[];
extern u8 *reg_a6;

void func_001B7EA0(void) {
    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0xC7);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)D_0026E540;
    reg_d2.h[0] = ((((u16)reg_d2.h[0]) + 2) != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)(((u16)reg_d2.h[0]) + 2) & ~1)) : *(u16 *)D_0026E540;
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = 0x17;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xFC00FD00;
    reg_d0.w = reg_d1.w;
    reg_d1.w += 0x09C00400;
    func_0019C6D0();
    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0xC6);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)D_0026E540;
    reg_d2.h[0] = ((((u16)reg_d2.h[0]) + 2) != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)(((u16)reg_d2.h[0]) + 2) & ~1)) : *(u16 *)D_0026E540;
    reg_d1.w = reg_d0.w;
    reg_d1.w += 0x09BFFC40;
    func_0019C6D0();
    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0xC9);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)D_0026E540;
    reg_d2.h[0] = ((((u16)reg_d2.h[0]) + 2) != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)(((u16)reg_d2.h[0]) + 2) & ~1)) : *(u16 *)D_0026E540;
    reg_d1.w = reg_d0.w;
    reg_d1.w += 0x0F400600;
    func_0019C6D0();
    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0xC8);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)D_0026E540;
    reg_d2.h[0] = ((((u16)reg_d2.h[0]) + 2) != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)(((u16)reg_d2.h[0]) + 2) & ~1)) : *(u16 *)D_0026E540;
    reg_d1.w = reg_d0.w;
    reg_d1.w += 0x0F3FF9C0;
    func_0019C6D0();
}
