#include "common.h"
#include "sdk/ps2sdk.h"

void func_00139EB0(void);
void func_0013A020(void);

s32 func_00128660();                            /* extern */
s32 func_001368C0();                            /* extern */
s32 func_0014D260();                            /* extern */
s32 func_0016AAB0();                            /* extern */
s32 func_001B82D0();                            /* extern */
s32 func_00209E60();                            /* extern */
s32 func_002114A0();                            /* extern */

void func_00139B20(void) {
    func_0016AAB0();
    func_00128660();
    func_00139EB0();
    func_001B82D0();
    func_002114A0();
    func_001368C0();
    func_00209E60();
    func_0014D260();
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
}

s32 func_0011F980();
s32 func_00125FA0();
s32 func_00129DB0();
s32 func_00136F30();
s32 func_0013CC60();
s32 func_0013D090();
s32 func_0013D560();
s32 func_0013D660();
s32 func_0013F380();
s32 func_00144D00();
s32 func_00144DA0();
s32 func_00144E40();
s32 func_00144EA0();
s32 func_00146760();
s32 func_001482C0();
s32 func_001488C0();
s32 func_0014DA50();
s32 func_0016AC30();
void func_00170A50(s32, s32, s32);
s32 func_0019FC70();
s32 func_001B8410();
s32 func_0020A540();
s32 func_0020BD10();
s32 func_0020BD60();
s32 func_00211670();
extern u16 D_0028E3EC;
extern u16 D_0028E5CC;
extern u16 D_0028E5D0;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u16 D_0028E910;
extern u16 D_0028E928;
extern u8 D_0029D750[];
extern u8 D_0029D770[];
extern u8 D_0029DCA0[];
extern u8 D_0029DD30[];
extern u8 D_0029E2A0[];
extern u8 D_0029E330[];
extern u8 D_0029E390[];
extern u8 D_0029EA50[];
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];

void func_00139B80(void) {
    u16 t1;
    u16 t2;

    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_00139B20();
        return;
    }
    func_00211670();
    func_00170A50(0x1F, 0x1F, 0x1F);
    func_0014DA50();
    func_00170A50(0, 0, 0);
    func_00136F30();
    func_00125FA0();
    func_0013A020();
    func_001B8410();
    func_00170A50(0x1F, 0, 0);
    func_0011F980();
    func_001488C0();
    func_0019FC70();
    func_00146760();
    func_001482C0();
    func_0020A540();
    func_0013CC60();
    func_00144E40();
    func_00144EA0();
    func_00144D00();
    func_00144DA0();
    func_00170A50(0x1F, 0, 0x1F);
    func_0016AC30();
    func_00170A50(0x1F, 0x1F, 0);
    func_0013D660();
    func_00129DB0();
    func_0013F380();
    func_0013D090();
    func_0013D560();
    func_00170A50(0, 0x1F, 0);
    if (D_0028E928 != 0) {
        reg_d4.h[0] = D_0029F260_as_u16_a[0];
        if (D_0029F260_as_u16_a[0] != 0) {
            reg_a0 = (u8 *)D_0029E390;
            reg_a1 = (u8 *)D_0029D770;
            reg_a2 = (u8 *)D_0029E2A0;
            reg_a3 = (u8 *)D_0029E330;
            reg_a4 = (u8 *)(D_0029F260_as_u16_a);
            reg_d0.h[0] = 0x1000;
            t2 = D_0028E5FC;
            t1 = D_0028E5D0;
            reg_d1.h[0] = t2;
            reg_d2.h[0] = t1;
            if (D_0028E3EC == 0) {
                func_0020BD60();
                return;
            }
            goto next_1;
        }
        reg_d4.h[0] = D_0029F1F0_as_u16_a[0];
        if (D_0029F1F0_as_u16_a[0] != 0) {
            reg_a0 = (u8 *)D_0029EA50;
            reg_a1 = (u8 *)D_0029D750;
            reg_a2 = (u8 *)D_0029DCA0;
            reg_a3 = (u8 *)D_0029DD30;
            reg_a4 = (u8 *)(D_0029F1F0_as_u16_a);
            reg_d0.h[0] = 0x800;
            t2 = D_0028E5F8;
            t1 = D_0028E5CC;
            reg_d1.h[0] = t2;
            reg_d2.h[0] = t1;
            if (D_0028E3EC != 0) {
                func_0020BD60();
                return;
            }
next_1:
            switch (D_0028E910) {
            case 0:
                break;
            default:
                func_0020BD10();
            }
        }
    } else {
        if (D_0028E3EC == 0) {
            reg_a0 = (u8 *)D_0029E390;
            reg_a1 = (u8 *)D_0029D770;
            reg_a2 = (u8 *)D_0029E2A0;
            reg_a3 = (u8 *)D_0029E330;
            reg_a4 = (u8 *)(D_0029F260_as_u16_a);
            reg_d0.h[0] = 0x1000;
            reg_d1.h[0] = D_0028E5FC;
            reg_d2.h[0] = D_0028E5D0;
            func_0020BD60();
            return;
        }
        reg_a0 = (u8 *)D_0029EA50;
        reg_a1 = (u8 *)D_0029D750;
        reg_a2 = (u8 *)D_0029DCA0;
        reg_a3 = (u8 *)D_0029DD30;
        reg_a4 = (u8 *)(D_0029F1F0_as_u16_a);
        reg_d0.h[0] = 0x800;
        reg_d1.h[0] = D_0028E5F8;
        reg_d2.h[0] = D_0028E5CC;
        func_0020BD60();
    }
}

extern s32 D_0029AA40_as_s32_a[];


void func_00139EB0(void) {
    memset(D_0029AA40_as_s32_a, 0, 0x11BA);
}


void func_00139ED0(void) {
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
    reg_a1 = (u8 *)reg_tmp.w;
loop_1:
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
    if (0 > (s32) reg_d0.w) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0)));
        reg_a1 += 2;
        if ((s16) reg_d0.h[0] == -1) {
            (*(u16 *)((u8 *)(reg_a6) + (0xE))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_a1 += 2;
        } else {
            reg_a1 += 2;
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_a1 += 2;
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_a1 += 2;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_tmp.w += reg_d1.w;
            (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
        }
        goto loop_1;
    }
    reg_tmp.w = (u32)reg_a1;
    (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = (u16) reg_tmp.h[0];
}

typedef void (*Fn)();

s32 func_001B82F0();
s32 func_00201B80();
s32 func_00201E20();
extern u16 D_0024F570[];
extern u16 D_0024F680[];
extern u8 D_00250760[];
extern u16 D_0028E3F0;
extern u8 D_0029AA40[];
extern u16 D_0029BBF8[];
extern u16 D_0029C06C[];
extern u8 D_0029CEA0_as_u8_a[];

void func_0013A020(void) {
    u16 x_save;
    u16 hi_save;

    D_0029BBF8[0] = 0;
    reg_d7.h[0] = 0x4F;
    reg_a6 = (u8 *)D_0029AA40;
loop_1:
    if (*(u16 *)(reg_a6 + 0) == 0) goto next_1;
    if (*(u16 *)(reg_a6 + 0x18) == 0) goto block_main;
    *(u16 *)(reg_a6 + 0x18) -= 1;
    goto next_1;
block_main:
    D_0029BBF8[0] += 1;
    if (!(*(u8 *)(reg_a6 + 1) & 0x40)) goto block_first;
    *(u8 *)(reg_a6 + 1) |= 0x40;
    goto block_fire;
block_first:
    *(u8 *)(reg_a6 + 1) |= 0x40;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0);
    reg_a1 = (u8 *)D_0024F570;
    reg_d1.h[0] = reg_d1.b[0];
    reg_tmp.w = reg_d1.w;
    if (!(reg_tmp.w & 0x80)) goto skip_1;
    reg_d1.w &= ~0x80;
    reg_a1 = (u8 *)D_0024F680;
skip_1:
    reg_d1.h[0] *= 8;
    reg_tmp.h[1] = ((reg_d1.h[0] + 4) != 0) ? *(u16 *)(reg_a1 + ((s16)(reg_d1.h[0] + 4) & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = ((reg_d1.h[0] + 6) != 0) ? *(u16 *)(reg_a1 + ((s16)(reg_d1.h[0] + 6) & ~1)) : *(u16 *)reg_a1;
    reg_a2 = (u8 *)reg_tmp.w;
    *(u16 *)(reg_a6 + 0x32) = *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a6 + 0x32) += 1;
    reg_tmp.w = (u32)reg_a2;
    *(u16 *)(reg_a6 + 0x2E) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x30) = reg_tmp.h[0];
    *(u16 *)(reg_a6 + 0x2A) = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
    *(u16 *)(reg_a6 + 0x2C) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a1 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    func_00139ED0();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2A);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_a2 = (u8 *)reg_tmp.w;
    *(u16 *)(reg_a6 + 0xA) = *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a6 + 0xC) = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_tmp.w = (u32)reg_a2;
    *(u16 *)(reg_a6 + 0x2A) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x2C) = reg_tmp.h[0];
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x26);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d1.w += reg_tmp.w;
    *(u16 *)(reg_a6 + 2) = reg_d1.h[1];
    *(u16 *)(reg_a6 + 4) = reg_d1.h[0];
block_fire:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x12);
    if (0 > (s16)reg_d0.h[0]) goto block_debris;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x1E);
    reg_d1.h[0] <<= 8;
    reg_d0.h[0] |= reg_d1.h[0];
    x_save = *(u16 *)(reg_a6 + 0x1C);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x14);
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a6 + 0x17);
    func_001B82F0();
    *(u16 *)(reg_a6 + 0x1C) = x_save;
    *(u16 *)(reg_a6 + 0x12) = 0xFFFF;
block_debris:
    reg_d0.h[0] = D_0029C06C[0];
    *(u16 *)(reg_a6 + 4) -= reg_d0.h[0];
    if (*(u16 *)(reg_a6 + 0x10) == 0) goto block_shift;
    func_00201B80();
block_shift:
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
    if (reg_d0.b[0] == 0) goto block_speed;
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
    func_00201E20();
    *(u16 *)(reg_a6 + 0x34) = reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x36) = reg_d3.h[0];
    *(u8 *)(reg_a6 + 0x1B) = 0;
block_speed:
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x22);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    if (reg_d0.w == 0) goto block_move;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x21);
    *(u8 *)(reg_a6 + 0x21) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_move;
    *(u8 *)(reg_a6 + 0x21) = *(u8 *)(reg_a6 + 0x20);
    *(u16 *)(reg_a6 + 0x36) -= reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x34) -= reg_d0.h[0];
block_move:
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x34);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x36);
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0xA800;
    reg_tmp1.w = 0;
    reg_d1.h[0] += 0x1000;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] += 0xA800;
    reg_tmp1.w += reg_tmp.w;
    if (reg_tmp1.h[1] != 0) goto block_end;
    reg_tmp1.w = 0;
    reg_tmp.w = reg_d1.w;
    hi_save = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x1000;
    reg_d1.h[0] += 0x1000;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] += 0x7000;
    reg_tmp1.w += reg_tmp.w;
    reg_d1.h[1] = hi_save;
    if (reg_tmp1.h[1] != 0) goto block_end;
    *(u16 *)(reg_a6 + 0x32) -= 1;
    if (!(0 > *(s16 *)(reg_a6 + 0x32))) goto block_disp;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2E);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x30);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    if ((s16)reg_d0.h[0] != -1) goto block_anim;
block_end:
    *(u16 *)(reg_a6 + 0) = 0;
    goto next_1;
block_anim:
    *(u16 *)(reg_a6 + 0x32) = reg_d0.h[0];
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a6 + 0x2E) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x30) = reg_tmp.h[0];
    func_00139ED0();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2A);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0xA) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_d0.h[0];
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a6 + 0x2A) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x2C) = reg_tmp.h[0];
block_disp:
    reg_a0 = (u8 *)D_0029CEA0_as_u8_a;
    if (!(0 > *(s16 *)reg_a0)) goto block_draw;
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] &= 1;
    if ((s16)reg_d0.h[0] == 0) goto next_1;
block_draw:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1E);
    reg_d0.h[0] >>= 2;
    ((Fn)*(u32 *)(D_00250760 + reg_d0.h[0] * 4))();
next_1:
    reg_a6 += 0x38;
    if ((s16)(--reg_d7.h[0]) >= 0) goto loop_1;
}

extern u8 D_0029BBC0[];

void func_0013A780(void) {
    u8 *sa1;
    u8 *sa2;
    u8 *sa3;
    u8 *sa4;
    u8 *sa5;
    u8 *sa6;
    u32 s0;
    u32 s1;
    u32 t1;

    s0 = reg_d0.w;
    s1 = reg_d1.w;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa3 = reg_a3;
    sa4 = reg_a4;
    sa5 = reg_a5;
    sa6 = reg_a6;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] &= 0x7F;
    if (0 > (s16) reg_d1.h[0]) goto block_2;
    if ((s16) reg_d1.h[0] > 0x21) goto block_2;
    reg_d1.h[0] = 0x4F;
    reg_a0 = (u8 *)D_0029AA40;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    reg_d0.h[0] |= 0x8000;
    *(u16 *) reg_a0 = reg_d0.h[0];
    reg_d0.w = 0;
    *(u16 *) (reg_a0 + 0x10) = reg_d0.h[0];
    *(u16 *) (reg_a0 + 0x12) = 0xFFFF;
    *(u8 *) (reg_a0 + 0x17) = 0x1E;
    *(u16 *) (reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *) (reg_a0 + 0x1A) = reg_d0.h[0];
    *(u8 *) (reg_a0 + 0x1D) = reg_d0.b[0];
    *(u8 *) (reg_a0 + 0x1C) = 0x1E;
    *(u16 *) (reg_a0 + 0x1E) = 0;
    *(u16 *) (reg_a0 + 0x22) = reg_d0.h[1];
    *(u16 *) (reg_a0 + 0x24) = reg_d0.h[0];
    *(u16 *) (reg_a0 + 0x26) = reg_d0.h[1];
    *(u16 *) (reg_a0 + 0x28) = reg_d0.h[0];
    *(u16 *) (reg_a0 + 0x34) = reg_d0.h[1];
    *(u16 *) (reg_a0 + 0x36) = reg_d0.h[0];
    reg_d0.w = s0;
    reg_d1.w = s1;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    return;
next_1:
    reg_a0 += 0x38;
    t1 = reg_d1.h[0] - 1;
    reg_d1.h[0] = t1;
    if (((s64) ((s64) (u16) t1 << 0x30) >> 0x30) >= 0) goto loop_1;
block_2:
    reg_d0.w = s0;
    reg_d1.w = s1;
    reg_a1 = sa1;
    reg_a0 = (u8 *)D_0029BBC0;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
}
