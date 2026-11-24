#include "common.h"

typedef void (*Fn)();

extern u8 D_0024F3C0[];
extern u8 D_0024F3F0[];
extern u8 D_0024F410[];
extern u8 D_0024F430[];
extern u8 D_0024F460[];
extern u8 D_0024F480[];
extern u8 D_0024F4A0[];
extern u8 D_002BC7C0[];
s32 func_00137820();
extern u16 D_0028E3EC;
extern s8 D_0028E855;
extern u8 D_0029BC00[];
extern u16 D_0029BD7C[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00136F30(void) {
    u32 count;
    u8 bits;

    reg_d0.h[0] = 0x95;
    reg_d1.w = 0;
    reg_a0 = (u8 *)D_002BC7C0;
loop_10:
    bits = (*(u8 *)((u8 *)(reg_a0) + (1)));
    if (bits == 0) goto next_20;
    if (0 > (s8)bits) goto next_20;
    (*(u16 *)((u8 *)(reg_a0) + (0))) = reg_d1.h[0];
next_20:
    reg_a0 += 0x20;
    count = reg_d0.h[0] - 1;
    reg_d0.h[0] = count;
    if (((s64)((s64)(u16)count << 0x30) >> 0x30) >= 0) goto loop_10;
    reg_d7.h[0] = D_0029BD7C[0];
    if (reg_d7.h[0] == 0) return;
    reg_d7.h[0] -= 1;
    reg_a6 = (u8 *)D_0029BC00;
    goto loop_40;
loop_30:
    reg_a6 += 0x26;
loop_40:
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0)));
    if (reg_d2.h[0] == 0) goto loop_30;
    if (reg_d2.w & 0x200) goto next_50;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    if (!(0 > (s16)reg_d1.h[0])) goto block_clr;
    if (0 > (s8)reg_d1.b[0]) goto block_clr;
    if (0 > D_0028E855) goto block_clr;
next_50:
    if (D_0028E3EC == 0) goto next_90;
    if (0 > (s8)reg_d2.b[0]) goto next_60;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x22))) != 0) goto next_60;
    func_00137820();
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0)));
next_60:
    reg_d0.w = 0x7C;
    reg_d0.h[0] &= reg_d2.h[0];
    switch (reg_d0.h[0]) {
    case 0x00: goto block_a0;
    case 0x04: goto block_a1;
    case 0x08: goto block_a2;
    case 0x0C: goto block_a3;
    case 0x10: goto block_a4;
    case 0x14: goto block_a5;
    case 0x18: goto block_objset;
    case 0x1C: goto block_objset;
    case 0x20: goto block_objset;
    case 0x24: goto block_objset;
    case 0x28: goto block_a0;
    case 0x2C: goto block_a1;
    case 0x30: goto block_a2;
    case 0x34: goto block_a3;
    case 0x38: goto block_a4;
    case 0x3C: goto block_a5;
    case 0x40: goto block_objset;
    case 0x44: goto block_objset;
    case 0x48: goto block_objset;
    case 0x4C: goto block_objset;
    }
next_90:
    reg_a6 += 0x26;
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_40;
    return;
block_clr:
    (*(u16 *)((u8 *)(reg_a6) + (0))) = 0;
    D_0029BD7C[0] -= 1;
    reg_a6 += 0x26;
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_40;
    return;
block_a0:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_a0 = (u8 *)D_0024F3F0;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) -= 4;
    if (!(0 > (*(s16 *)((u8 *)(reg_a6) + (0x24))))) goto block_objset;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = 0xC;
    goto block_objset;
block_a1:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_a0 = (u8 *)D_0024F410;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) -= 4;
    if (!(0 > (*(s16 *)((u8 *)(reg_a6) + (0x24))))) goto block_objset;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = 0xC;
    goto block_objset;
block_a2:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_a0 = (u8 *)D_0024F430;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) -= 4;
    if (!(0 > (*(s16 *)((u8 *)(reg_a6) + (0x24))))) goto block_objset;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = 0x1C;
    goto block_objset;
block_a3:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_a0 = (u8 *)D_0024F460;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) -= 4;
    if (!(0 > (*(s16 *)((u8 *)(reg_a6) + (0x24))))) goto block_objset;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = 0xC;
    goto block_objset;
block_a4:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_a0 = (u8 *)D_0024F480;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) -= 4;
    if (!(0 > (*(s16 *)((u8 *)(reg_a6) + (0x24))))) goto block_objset;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = 0xC;
    goto block_objset;
block_a5:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_a0 = (u8 *)D_0024F4A0;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) -= 4;
    if (!(0 > (*(s16 *)((u8 *)(reg_a6) + (0x24))))) goto block_objset;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = 0x1C;
block_objset:
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x16)));
    reg_d0.w += reg_tmp.w;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = reg_d0.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x18)));
    if (!((*(u8 *)((u8 *)(reg_a6) + (1))) & 1)) goto next_obj10;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a0) + (0x1F)));
    reg_d0.h[0] <<= 2;
next_obj10:
    reg_a0 = (u8 *)D_0024F3C0;
    reg_a0 += reg_d0.h[0];
    reg_a0 = *(u8 **)reg_a0;
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
    reg_a6 += 0x26;
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_40;
}
