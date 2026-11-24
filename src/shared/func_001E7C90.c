#include "common.h"

s32 func_00124B20();
s32 func_00124C70();
s32 func_00124D10();
s32 func_001253B0();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001E8480();
s32 func_001E8580();
s32 func_001E8640();
s32 func_001E87A0();
s32 func_002016D0();
s32 func_00203400();
extern u8 D_0028E290;
extern s32 D_0028E638;
extern u16 D_0028E864;
extern u16 D_0028E870;
extern u16 D_0028E874;
extern u16 D_0028E878;
extern u16 D_0028E8B8;
extern s16 D_0029CEA0_as_s16_a[];
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
extern u16 D_00684C80[];
#endif
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E7C90(void) {
    s32 hp;
    s32 mid;
    s32 low;

    D_0028E878 = 0;
    if (D_0028E874 == 0) goto next_100_chk;
    reg_d1.h[0] = D_0028E870;
    (*(u16 *)((u8 *)(reg_a6) + (0x16A))) = reg_d1.h[0];
    goto next_100_set;
next_100_chk:
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x21)));
    reg_d1.b[0] |= (*(u8 *)((u8 *)(reg_a6) + (0x41)));
    reg_d1.b[0] |= (*(u8 *)((u8 *)(reg_a6) + (0x61)));
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] == 0) goto next_100;
    (*(u16 *)((u8 *)(reg_a6) + (0x16A))) = reg_d1.h[0];
next_100_set:
    reg_d0.b[0] = 0xA3;
    (*(u8 *)((u8 *)(reg_a6) + (0x21))) &= reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x41))) &= reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x61))) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x147)));
    if (reg_d0.b[0] != 0x19) goto next_r_pal;
    (*(u8 *)((u8 *)(reg_a6) + (0x147))) = 0x13;
    (*(u8 *)((u8 *)(reg_a6) + (0x146))) = 0x14;
    (*(u8 *)((u8 *)(reg_a6) + (0x149))) = 0x15;
    (*(u8 *)((u8 *)(reg_a6) + (0x148))) = 0x15;
    (*(u8 *)((u8 *)(reg_a6) + (0x14B))) = 0x15;
    (*(u8 *)((u8 *)(reg_a6) + (0x14A))) = 0x14;
next_r_pal:
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x147)));
    reg_d0.b[0] ^= 0xC;
    (*(u8 *)((u8 *)(reg_a6) + (0x147))) = reg_d0.b[0];
    if ((*(u8 *)((u8 *)(reg_a6) + (0x5E))) != 0) goto next_dm_skip;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x146)));
    reg_d0.b[0] ^= 0xB;
    (*(u8 *)((u8 *)(reg_a6) + (0x146))) = reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x149)));
    reg_d0.b[0] ^= 0xA;
    (*(u8 *)((u8 *)(reg_a6) + (0x149))) = reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x148)));
    reg_d0.b[0] ^= 0xA;
    (*(u8 *)((u8 *)(reg_a6) + (0x148))) = reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14B)));
    reg_d0.b[0] ^= 0xA;
    (*(u8 *)((u8 *)(reg_a6) + (0x14B))) = reg_d0.b[0];
next_dm_skip:
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14A)));
    reg_d0.b[0] ^= 0xB;
    (*(u8 *)((u8 *)(reg_a6) + (0x14A))) = reg_d0.b[0];
    if (D_0028E290 != 2) goto next_max_end;
    hp = (*(u16 *)((u8 *)(reg_a6) + (0x38)));
    mid = (*(u16 *)((u8 *)(reg_a6) + (0x58)));
    low = (*(u16 *)((u8 *)(reg_a6) + (0x78)));
    if (hp > (s32)mid) goto next_max1;
    hp = mid;
next_max1:
    if (hp > (s32)low) goto next_max_end;
    hp = low;
next_max_end:
    reg_d2.w = 0x7FFF;
    reg_d2.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x38)));
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x58)));
    if (!((s32)reg_d2.w < (s32)reg_d3.w)) goto next_dmg0;
    reg_d2.w = reg_d3.w;
next_dmg0:
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x78)));
    if (!((s32)reg_d2.w < (s32)reg_d3.w)) goto next_dmg1;
    reg_d2.w = reg_d3.w;
next_dmg1:
    reg_d0.w = 0;
    reg_d0.h[0] = D_0028E874;
    if (reg_d0.h[0] == 0) goto next_dec_cut;
    reg_d0.h[0] = (s32)(reg_d0.h[0] & 0xFFFF) >> 1;
    D_0028E874 = 0;
    reg_d2.w = reg_d0.w;
    if (D_0029CEA0_as_s16_a[0] >= 0) goto next_flag7;
#ifdef DEATH_LABEL
    hp = reg_d2.w;
    if (hp != 0) {
        if (death_D_00290DC0 == 0) {
            if (D_00684C80[9] == 2) {
                hp = 0;
            }
            if (D_00684C80[9] == 4) {
                hp /= 5;
            }
            if (D_00684C80[9] == 6) {
                hp /= 10;
            }
        } else {
            if (D_00684C80[9] == 2) {
                hp *= 2;
            }
            if (D_00684C80[9] == 4) {
                hp *= 2;
            }
            if (D_00684C80[9] == 6) {
                hp *= 2;
            }
        }
    }
    if (hp != 0) {
        hp += 0x7FFF;
    }
#else
    hp = 0;
    if (reg_d2.w == 0) goto next_div;
    hp = reg_d2.w / 6;
next_div:
    hp += 0x7FFF;
#endif
next_flag7:
    D_0028E878 = 1;
next_dec_cut:
    if ((*(u16 *)((u8 *)(reg_a6) + (0x168))) != 0) goto next_nodec;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    if (D_0028E290 != 2) goto next_sub2;
    if (hp <= 0x7FFF) goto next_sub1;
    reg_tmp.w += hp - 0x7FFF;
    if (reg_tmp.w < 0x46000) goto next_store;
    reg_tmp.w = 0x46000;
    goto next_store;
next_sub1:
    reg_tmp.w -= reg_d2.w;
    goto next_store;
next_sub2:
    reg_tmp.w -= reg_d2.w;
next_store:
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = reg_tmp.h[0];
next_nodec:
    reg_d0.h[0] = 0x7FFF;
    (*(u16 *)((u8 *)(reg_a6) + (0x38))) = reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x58))) = reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x78))) = reg_d0.h[0];
    goto next_110;
next_100:
    (*(u8 *)((u8 *)(reg_a6) + (0x147))) = 0x13;
    (*(u8 *)((u8 *)(reg_a6) + (0x146))) = 0x14;
    (*(u8 *)((u8 *)(reg_a6) + (0x149))) = 0x15;
    (*(u8 *)((u8 *)(reg_a6) + (0x148))) = 0x15;
    (*(u8 *)((u8 *)(reg_a6) + (0x14B))) = 0x15;
    (*(u8 *)((u8 *)(reg_a6) + (0x14A))) = 0x14;
    reg_d2.w = 0xC400;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    if (reg_tmp.w > reg_d2.w) goto next_110;
    if (D_0028E8B8 != 0) goto next_110;
    reg_d0.w = 0x19;
    (*(u8 *)((u8 *)(reg_a6) + (0x147))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x146))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x149))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x148))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x14B))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x14A))) = reg_d0.b[0];
next_110:
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x81)));
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] == 0) goto next_hr_100;
    reg_d0.b[0] = 0xA3;
    (*(u8 *)((u8 *)(reg_a6) + (0x81))) &= reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14D)));
    if (reg_d0.b[0] != 0x19) goto next_hr_r_pal;
    (*(u8 *)((u8 *)(reg_a6) + (0x14D))) = 0x13;
next_hr_r_pal:
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14D)));
    reg_d0.b[0] ^= 0xC;
    (*(u8 *)((u8 *)(reg_a6) + (0x14D))) = reg_d0.b[0];
    reg_d0.h[0] = 0x7FFF;
    reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x98)));
    if (!((s16)D_0028E874 < (s16)reg_d0.h[0])) goto next_hr_kangen;
    D_0028E874 = reg_d0.h[0];
    D_0028E870 = reg_d1.h[0];
next_hr_kangen:
    (*(u16 *)((u8 *)(reg_a6) + (0x98))) = 0x7FFF;
    goto next_hr_110;
next_hr_100:
    (*(u8 *)((u8 *)(reg_a6) + (0x14D))) = 0x13;
next_hr_110:
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xA1)));
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] == 0) goto next_hl_100;
    reg_d0.b[0] = 0xA3;
    (*(u8 *)((u8 *)(reg_a6) + (0xA1))) &= reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14C)));
    if (reg_d0.b[0] != 0x19) goto next_hl_r_pal;
    (*(u8 *)((u8 *)(reg_a6) + (0x14C))) = 0x13;
next_hl_r_pal:
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14C)));
    reg_d0.b[0] ^= 0xC;
    (*(u8 *)((u8 *)(reg_a6) + (0x14C))) = reg_d0.b[0];
    reg_d0.h[0] = 0x7FFF;
    reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0xB8)));
    if (!((s16)D_0028E874 < (s16)reg_d0.h[0])) goto next_hl_kangen;
    D_0028E874 = reg_d0.h[0];
    D_0028E870 = reg_d1.h[0];
next_hl_kangen:
    (*(u16 *)((u8 *)(reg_a6) + (0xB8))) = 0x7FFF;
    goto next_hl_110;
next_hl_100:
    (*(u8 *)((u8 *)(reg_a6) + (0x14C))) = 0x13;
next_hl_110:
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    if ((s32)reg_tmp.w >= 0) goto next_death_chk;
    func_00203400();
    if (reg_d0.h[0] != 0) goto next_elix;
    reg_tmp.w = 0x200;
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = reg_tmp.h[0];
    goto next_death_chk;
next_elix:
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x16A)));
    reg_d0.w = 0x60000;
    func_001A91A0();
    D_0028E638 = 0x60000;
    func_001E8480();
    return;
next_death_chk:
    if ((*(u8 *)((u8 *)(reg_a6) + (0x16D))) != 0) goto next_mode2_chk;
#ifndef DEATH_LABEL
    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) -= 1;
#endif
    if ((*(u16 *)((u8 *)(reg_a5) + (0x1A))) == 0) goto next_mode2_set;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    if (!((s32)reg_tmp.w < 0x23000)) goto next_mode2_chk;
next_mode2_set:
    (*(u8 *)((u8 *)(reg_a6) + (0x16D))) = 1;
    func_001253B0();
    func_00124D10();
    func_002016D0();
    reg_d0.w = 1;
    func_00124B20();
    (*(u8 *)((u8 *)(reg_a6) + (0x5E))) = 1;
next_mode2_chk:
    if ((*(u8 *)((u8 *)(reg_a6) + (0x16C))) != 0) goto next_hakyo_chk;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    if (!((s32)reg_tmp.w < 0xC400)) goto next_hakyo_chk;
    (*(u8 *)((u8 *)(reg_a6) + (0x16C))) = 1;
    D_0028E864 = 1;
    reg_d0.w = 5;
    func_00124C70();
    reg_d0.w = 6;
    func_00124B20();
    func_001E8580();
    func_001E8640();
    func_002016D0();
next_hakyo_chk:
    func_001E87A0();
}
