#include "common.h"

typedef void (*Fn)();

extern u8 D_00261770[];
extern u8 D_00263C10[];
extern u8 D_00263C30[];
extern u8 D_00263C70[];
extern u8 D_00263C80[];
extern u8 D_00263C90[];
extern u8 D_00263CF0[];
s32 func_001368E0();
s32 func_00139EB0();
s32 func_0013A780();
s32 func_0013B2E0();
s32 func_0013B920();
s32 func_0013C300();
s32 func_0014D220();
s32 func_0014E030();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0018D500();
s32 func_0018D520();
s32 func_0018D5C0();
s32 func_0018DB30();
s32 func_0018DB50();
s32 func_0018DB70();
s32 func_0018DBC0();
s32 func_0018DDA0();
s32 func_0018DDB0();
s32 func_0019BEC0();
s32 func_0019C470();
s32 func_001A3020();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001E1F30();
s32 func_002011A0();
s32 func_00201270();
s32 func_002012F0();
s32 func_00201710();
s32 func_00217BB0();
s32 func_00217C20();
extern u8 D_0028E2E4;
extern Reg32 D_0028E484;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern s8 enemy_move_end_requested;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E1390(void) {
    s16 x_save;

    func_0014EA50();
    if (enemy_move_end_requested != 0) goto block_rts;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x2000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x3800;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0x2000;
    if (reg_tmp.h[1] == 0) goto next_1;
    if ((*(s8 *)((u8 *)(reg_a5) + (0x17))) == 0) goto next_2;
    func_0014E290();
    return;
next_1:
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 1;
next_2:
    if ((*(s8 *)((u8 *)(reg_a6) + (0))) < 0) goto block_c;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u16 *)((u8 *)(reg_a6) + (0x42))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x44))) = (u16) reg_d0.h[0];
    reg_d0.h[1] += 0xDC00;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_d0.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0x38))) = 0x7FFF;
    (*(u8 *)((u8 *)(reg_a6) + (0x21))) &= 0xA3;
    switch (*(u16 *)((u8 *)(reg_a5) + (0x32))) { case 0: goto next_3; }
    (*(u16 *)((u8 *)(reg_a5) + (0x32))) -= 1;
    (*(u16 *)((u8 *)(reg_a6) + (0x18))) = 0x7800;
    (*(u16 *)((u8 *)(reg_a6) + (0x58))) = 0x7800;
next_3:
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
    reg_d1.b[0] |= (*(u8 *)((u8 *)(reg_a6) + (0x41)));
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_4;
    reg_d0.b[0] = 0x13;
    if (!((s32) (*(u16 *)((u8 *)(reg_a6) + (0x18))) < 0x1E00)) goto next_7;
    if (D_0028E8B8 != 0) goto next_7;
    reg_d0.w = 0x19;
    goto next_7;
next_4:
    reg_d0.h[0] = 0xA3;
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x41))) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    if (reg_d0.b[0] != 0x19) goto next_5;
    reg_d0.b[0] = 0x13;
next_5:
    reg_d0.b[0] ^= 0xC;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x18)));
    if (!((s16) (*(u16 *)((u8 *)(reg_a6) + (0x58))) < (s16) reg_d4.h[0])) goto next_6;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x58)));
next_6:
    (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d4.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x58))) = (u16) reg_d4.h[0];
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x18))) < 0) goto block_b;
next_7:
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
    func_001368E0();
    if (D_0028E8A0 != 0) goto next_15;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x18))) != 0) goto next_8;
    if (!((s32) (*(u16 *)((u8 *)(reg_a6) + (2))) < 0x7001)) goto next_15;
    (*(u16 *)((u8 *)(reg_a5) + (0x1E))) -= 0x40;
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 1;
    goto next_15;
next_8:
    if (!((s16) (*(u16 *)((u8 *)(reg_a5) + (0x1E))) < 0x2400)) goto next_9;
    (*(u16 *)((u8 *)(reg_a5) + (0x1E))) += 0x40;
next_9:
    if ((*(u16 *)((u8 *)(reg_a5) + (0x18))) != 1) goto next_10;
    if (!((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) < 0x5001)) goto next_15;
    reg_a0 = (u8 *)D_00263C70;
    func_0013B920();
    func_0018DB30();
    (*(u16 *)((u8 *)(reg_a5) + (0x38))) = 0x20;
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 2;
    goto next_15;
next_10:
    if ((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x20) goto next_11;
    reg_d0.h[0] = 0x40;
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x2A))) += reg_d0.h[0];
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2A))) != 0x1040) goto next_11;
    (*(u16 *)((u8 *)(reg_a6) + (2))) -= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x2A))) -= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0))) = 0xA000;
    (*(u16 *)((u8 *)(reg_a6) + (0x40))) = 0xA000;
next_11:
    if ((*(u16 *)((u8 *)(reg_a5) + (0x18))) != 2) goto next_13;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x38))) == 0) goto next_12;
    (*(u16 *)((u8 *)(reg_a5) + (0x38))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x38))) != 0) goto next_12;
    func_0018DB50();
next_12:
    reg_d0.h[0] = 0xA4;
    func_0014E030();
    reg_a1 = reg_a6 + 0x20;
    reg_tmp.w = (u32) reg_a1;
    (*(u16 *)((u8 *)(reg_a0) + (0x24))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_tmp.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0x800;
    if (!((s32) (*(u16 *)((u8 *)(reg_a6) + (2))) < 0x4601)) goto next_15;
    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 0x20;
    (*(u16 *)((u8 *)(reg_a5) + (0x28))) = 0x18;
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 3;
    goto next_15;
next_13:
    if ((*(u16 *)((u8 *)(reg_a5) + (0x18))) != 3) goto next_14;
    if (!((s32) (*(u16 *)((u8 *)(reg_a6) + (2))) < 0x4001)) goto next_15;
    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 0x3C;
    (*(u16 *)((u8 *)(reg_a5) + (0x28))) = 0x34;
    reg_a0 = (u8 *)D_00263CF0;
    func_0013B2E0();
    func_0018DDB0();
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 4;
    goto next_15;
next_14:
    if ((*(u16 *)((u8 *)(reg_a5) + (0x18))) != 4) goto next_15;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
    if (reg_tmp.w != 0x1DE6) goto next_15;
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0xA001;
    func_0018DB70();
    (*(u16 *)((u8 *)(reg_a5) + (0x38))) = 0x40;
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 5;
next_15:
    if (D_0028E2E4 != 0) goto next_17;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x18))) != 5) goto next_16;
    if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x38))) == -1) goto next_16;
    (*(u16 *)((u8 *)(reg_a5) + (0x38))) -= 1;
    if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x38))) != -1) goto next_16;
    func_0018DBC0();
next_16:
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
    (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_17;
    (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
    reg_a0 = (u8 *)D_00263C30;
    (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x24))) += 4;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
    if ((*(u16 *)((u8 *)(reg_a5) + (0x24))) != reg_d0.h[0]) goto next_17;
    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x28)));
next_17:
    func_0019BEC0();
    if (!((s16) (*(u16 *)((u8 *)(reg_a6) + (0x22))) > -0x800)) goto next_18;
    reg_a6 += 0x20;
    func_0019BEC0();
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (6)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
    reg_a6 = (u8 *) reg_tmp.w;
    goto next_19;
next_18:
    if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x38))) != -1) goto next_19;
    func_0018DDA0();
    (*(u16 *)((u8 *)(reg_a5) + (0x38))) = 0xFFFE;
next_19:
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = reg_a6 + 0x20;
    func_0014D220();
    reg_a0 = reg_a6 + 0x40;
    func_0014D220();
    if (!((s16) (*(u16 *)((u8 *)(reg_a5) + (0x1E))) < 0x2400)) goto block_rts;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0xF400;
    reg_d1.h[1] -= (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
    reg_d2.w = 0x1DD4;
    reg_d3.h[0] = 0x1860;
    reg_d4.h[0] = 0x14;
    reg_d1.h[1] += 0xB800;
    func_0019C470();
    goto block_rts;
block_b:
    (*(u16 *)((u8 *)(reg_a5) + (0x3A))) = (u16) reg_d1.h[0];
    reg_d0.w = 0x788;
    func_001A91A0();
    func_0018DDB0();
    func_0018DDA0();
    func_0018D5C0();
    (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8080;
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0x8000;
    (*(u16 *)((u8 *)(reg_a6) + (0x40))) = 0x8000;
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = 0x13;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x3A)));
    func_00201710();
    reg_a0 = (u8 *)D_00263C80;
    func_0013B920();
    (*(u16 *)((u8 *)(reg_a5) + (0x34))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x36))) = (u16) reg_d0.h[0];
    func_0019BEC0();
    goto block_rts;
block_c:
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2C))) != 0) goto next_22;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x30))) == 0) goto next_26;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x3A)));
    func_00201710();
    (*(u16 *)((u8 *)(reg_a5) + (0x30))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x30))) != 0) goto next_26;
    reg_tmp.w = 0x1DD3;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)D_00261770;
    reg_d0.h[0] = 0x13;
    func_001A3020();
    goto next_26;
next_22:
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x3A)));
    func_00201710();
    (*(u16 *)((u8 *)(reg_a5) + (0x2C))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2C))) == 0) goto next_23;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2C))) != 1) goto next_24;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x34)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x36)));
    func_0013C300();
    reg_a0 = (u8 *)D_00263C90;
    func_0013B2E0();
    goto next_24;
next_23:
    func_00139EB0();
    x_save = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) += 0xF280;
    func_001E1F30();
    (*(u16 *)((u8 *)(reg_a6) + (4))) += 0x1B00;
    func_001E1F30();
    (*(u16 *)((u8 *)(reg_a6) + (4))) = x_save;
    func_0018D5C0();
    func_00217BB0(0xB4, 0x64);
    func_00217C20(0xB4, 0x64);
    goto next_26;
next_24:
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2F)));
    (*(u8 *)((u8 *)(reg_a5) + (0x2F))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_26;
    (*(u8 *)((u8 *)(reg_a5) + (0x2F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2E)));
    reg_a0 = (u8 *)func_0018D500;
    func_002011A0();
    if (reg_d0.sb[0] >= 0) goto next_25;
    reg_a0 = (u8 *)func_0018D520;
next_25:
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
    func_002011A0();
    reg_d0.h[0] &= 7;
    reg_a0 = (u8 *)D_00263C10;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x800;
    func_00201270();
    reg_d0.b[0] += 3;
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d0.b[0];
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
    func_002012F0();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] += reg_d1.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] += 0xF800;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_d0.h[0];
    func_002012F0();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] += reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) reg_d0.h[0];
next_26:
    func_0019BEC0();
block_rts:
    return;
}
