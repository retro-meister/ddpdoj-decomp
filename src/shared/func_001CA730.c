#include "common.h"

s32 func_00124B20();
s32 func_00124D10();
s32 func_001253B0();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001CB6B0();
s32 func_001CB7E0();
s32 func_001CB890();
s32 func_001CB940();
s32 func_001CBB10();
s32 func_001CBCE0();
s32 func_002016D0();
s32 func_00203400();
extern u8 D_0028E290;
extern Reg32 D_0028E480;
extern s32 D_0028E638;
extern u16 D_0028E8B8;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001CA730(void) {
    s32 m;
    u32 cnt;
    s32 h1;
    s32 h2;
    s32 h3;

    if (*(u16 *)(reg_a6 + 0x146) != 0) return;
    if (*(u8 *)(reg_a6 + 0x14D) == 0) goto next_110;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 1);
    reg_d1.b[0] |= *(u8 *)(reg_a6 + 0x21);
    reg_d1.b[0] |= *(u8 *)(reg_a6 + 0xC1);
    reg_d1.b[0] |= *(u8 *)(reg_a6 + 0xE1);
    cnt = reg_d1.h[0] & 0x5C;
    reg_d1.h[0] = cnt;
    if (!(cnt & 0xFFFF)) goto next_100;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 1) &= reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x21) &= reg_d0.b[0];
    *(u8 *)(reg_a6 + 0xC1) &= reg_d0.b[0];
    *(u8 *)(reg_a6 + 0xE1) &= reg_d0.b[0];
    *(u16 *)(reg_a6 + 0x14A) = reg_d1.h[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x126);
    if (reg_d0.b[0] != 0x19) goto next_101;
    *(u8 *)(reg_a6 + 0x126) = 0x10;
    *(u8 *)(reg_a6 + 0x127) = 0x12;
    *(u8 *)(reg_a6 + 0x129) = 0x17;
    *(u8 *)(reg_a6 + 0x12E) = 0x11;
    *(u8 *)(reg_a6 + 0x131) = 0x13;
    *(u8 *)(reg_a6 + 0x12C) = 0x13;
    *(u8 *)(reg_a6 + 0x12F) = 0xD;
next_101:
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x126);
    reg_d0.b[0] ^= 0xF;
    *(u8 *)(reg_a6 + 0x126) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x127);
    reg_d0.b[0] ^= 0xD;
    *(u8 *)(reg_a6 + 0x127) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x129);
    reg_d0.b[0] ^= 0x8;
    *(u8 *)(reg_a6 + 0x129) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12E);
    reg_d0.b[0] ^= 0xE;
    *(u8 *)(reg_a6 + 0x12E) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x131);
    reg_d0.b[0] ^= 0xC;
    *(u8 *)(reg_a6 + 0x131) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12C);
    reg_d0.b[0] ^= 0xC;
    *(u8 *)(reg_a6 + 0x12C) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12F);
    reg_d0.b[0] ^= 0x12;
    *(u8 *)(reg_a6 + 0x12F) = reg_d0.b[0];
    if (D_0028E290 == 2) {
        m = *(u16 *)(reg_a6 + 0x18);
        h1 = *(u16 *)(reg_a6 + 0x38);
        h2 = *(u16 *)(reg_a6 + 0xD8);
        h3 = *(u16 *)(reg_a6 + 0xF8);
        if (m > h1) goto skip_m1;
        m = h1;
skip_m1:
        if (h2 > h3) goto skip_m2;
        h2 = h3;
skip_m2:
        if (m > h2) goto skip_m3;
        m = h2;
skip_m3:;
    }
    reg_d2.w = 0x7FFF;
    reg_d2.h[0] -= *(u16 *)(reg_a6 + 0x18);
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= *(u16 *)(reg_a6 + 0x38);
    if (!((s32) reg_d2.w < (s32) reg_d3.w)) goto skip_d180;
    reg_d2.w = reg_d3.w;
skip_d180:
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= *(u16 *)(reg_a6 + 0xD8);
    if (!((s32) reg_d2.w < (s32) reg_d3.w)) goto skip_d181;
    reg_d2.w = reg_d3.w;
skip_d181:
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= *(u16 *)(reg_a6 + 0xF8);
    if (!((s32) reg_d2.w < (s32) reg_d3.w)) goto skip_d182;
    reg_d2.w = reg_d3.w;
skip_d182:
    if (*(u16 *)(reg_a6 + 0x148) != 0) goto next_108;
    D_0028E480.h[1] = *(u16 *)(reg_a5 + 0x16);
    D_0028E480.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (D_0028E290 != 2) goto next_106;
    if (m <= 0x7FFF) goto next_105;
    m -= 0x7FFF;
    D_0028E480.w += m;
    if ((u32) D_0028E480.w < 0x2BDC0U) goto next_107;
    D_0028E480.w = 0x2BDC0;
    goto next_107;
next_105:
    D_0028E480.w -= reg_d2.w;
    goto next_107;
next_106:
    D_0028E480.w -= reg_d2.w;
next_107:
    *(u16 *)(reg_a5 + 0x16) = D_0028E480.h[1];
    *(u16 *)(reg_a5 + 0x18) = D_0028E480.h[0];
next_108:
    reg_d0.h[0] = 0x7FFF;
    *(u16 *)(reg_a6 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x38) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xD8) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xF8) = reg_d0.h[0];
    goto next_110;
next_100:
    *(u8 *)(reg_a6 + 0x126) = 0x10;
    *(u8 *)(reg_a6 + 0x127) = 0x12;
    *(u8 *)(reg_a6 + 0x129) = 0x17;
    *(u8 *)(reg_a6 + 0x12E) = 0x11;
    *(u8 *)(reg_a6 + 0x131) = 0x13;
    *(u8 *)(reg_a6 + 0x12C) = 0x13;
    *(u8 *)(reg_a6 + 0x12F) = 0xD;
    reg_d2.w = 0x7700;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (reg_tmp.w > reg_d2.w) goto next_110;
    if (D_0028E8B8 != 0) goto next_110;
    *(u8 *)(reg_a6 + 0x126) = 0x19;
    *(u8 *)(reg_a6 + 0x127) = 0x19;
    *(u8 *)(reg_a6 + 0x129) = 0x19;
    *(u8 *)(reg_a6 + 0x12E) = 0x19;
    *(u8 *)(reg_a6 + 0x131) = 0x19;
    *(u8 *)(reg_a6 + 0x12C) = 0x19;
    *(u8 *)(reg_a6 + 0x12F) = 0x19;
next_110:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if ((s32) reg_tmp.w >= 0) goto next_130;
    func_00203400();
    if (reg_d0.h[0] != 0) goto next_120;
    reg_tmp.w = 0x200;
    *(u16 *)(reg_a5 + 0x16) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x18) = reg_tmp.h[0];
    goto next_130;
next_120:
    D_0028E638 = 0x40000;
    func_001CB6B0();
    return;
next_130:
    if (*(u16 *)(reg_a6 + 0x40) == 0x8000) goto next_29;
    reg_d1.w = 0x5C;
    cnt = reg_d1.b[0];
    cnt &= *(u8 *)(reg_a6 + 0x41);
    reg_d1.b[0] = cnt;
    if (!(cnt & 0xFF)) goto next_25;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 0x41) &= reg_d0.b[0];
    *(u16 *)(reg_a6 + 0x14A) = reg_d1.h[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x128);
    if (reg_d0.b[0] != 0x19) goto next_21;
    *(u8 *)(reg_a6 + 0x128) = 0x11;
next_21:
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x128);
    reg_d0.b[0] ^= 0xE;
    *(u8 *)(reg_a6 + 0x128) = reg_d0.b[0];
    if (*(u16 *)(reg_a6 + 0x148) == 0) goto next_22;
    *(u16 *)(reg_a6 + 0x58) = 0x5000;
next_22:
    if (*(s16 *)(reg_a6 + 0x58) >= 0) goto next_29;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x14A);
    reg_d0.w = 0x800;
    func_001A91A0();
    func_001CB7E0();
    goto next_29;
next_25:
    *(u8 *)(reg_a6 + 0x128) = 0x11;
    reg_d2.h[0] = 0x1800;
    if ((s32) *(u16 *)(reg_a6 + 0x58) > (s32) reg_d2.h[0]) goto next_29;
    if (D_0028E8B8 != 0) goto next_29;
    *(u8 *)(reg_a6 + 0x128) = 0x19;
next_29:
    if (*(u16 *)(reg_a6 + 0x60) == 0x8000) goto next_39;
    reg_d1.w = 0x5C;
    cnt = reg_d1.b[0];
    cnt &= *(u8 *)(reg_a6 + 0x61);
    reg_d1.b[0] = cnt;
    if (!(cnt & 0xFF)) goto next_35;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 0x61) &= reg_d0.b[0];
    *(u16 *)(reg_a6 + 0x14A) = reg_d1.h[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12B);
    if (reg_d0.b[0] != 0x19) goto next_31;
    *(u8 *)(reg_a6 + 0x12B) = 0x11;
next_31:
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12B);
    reg_d0.b[0] ^= 0xE;
    *(u8 *)(reg_a6 + 0x12B) = reg_d0.b[0];
    if (*(u16 *)(reg_a6 + 0x148) == 0) goto next_32;
    *(u16 *)(reg_a6 + 0x78) = 0x5000;
next_32:
    if (*(s16 *)(reg_a6 + 0x78) >= 0) goto next_39;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x14A);
    reg_d0.w = 0x800;
    func_001A91A0();
    func_001CB890();
    goto next_39;
next_35:
    *(u8 *)(reg_a6 + 0x12B) = 0x11;
    reg_d2.h[0] = 0x1800;
    if ((s32) *(u16 *)(reg_a6 + 0x78) > (s32) reg_d2.h[0]) goto next_39;
    if (D_0028E8B8 != 0) goto next_39;
    *(u8 *)(reg_a6 + 0x12B) = 0x19;
next_39:
    if (*(u16 *)(reg_a6 + 0x80) == 0x8000) goto next_49;
    reg_d1.w = 0x5C;
    cnt = reg_d1.b[0];
    cnt &= *(u8 *)(reg_a6 + 0x81);
    reg_d1.b[0] = cnt;
    if (!(cnt & 0xFF)) goto next_45;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 0x81) &= reg_d0.b[0];
    *(u16 *)(reg_a6 + 0x14A) = reg_d1.h[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12A);
    if (reg_d0.b[0] != 0x19) goto next_41;
    *(u8 *)(reg_a6 + 0x12A) = 0x12;
next_41:
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12A);
    reg_d0.b[0] ^= 0xD;
    *(u8 *)(reg_a6 + 0x12A) = reg_d0.b[0];
    if (*(u16 *)(reg_a6 + 0x148) == 0) goto next_42;
    *(u16 *)(reg_a6 + 0x98) = 0x5000;
next_42:
    if (*(s16 *)(reg_a6 + 0x98) >= 0) goto next_49;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x14A);
    reg_d0.w = 0x800;
    func_001A91A0();
    func_001CB940();
    goto next_49;
next_45:
    *(u8 *)(reg_a6 + 0x12A) = 0x12;
    reg_d2.h[0] = 0x1800;
    if ((s32) *(u16 *)(reg_a6 + 0x98) > (s32) reg_d2.h[0]) goto next_49;
    if (D_0028E8B8 != 0) goto next_49;
    *(u8 *)(reg_a6 + 0x12A) = 0x19;
next_49:
    if (*(u16 *)(reg_a6 + 0xA0) == 0x8000) goto next_59;
    reg_d1.w = 0x5C;
    cnt = reg_d1.b[0];
    cnt &= *(u8 *)(reg_a6 + 0xA1);
    reg_d1.b[0] = cnt;
    if (!(cnt & 0xFF)) goto next_55;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 0xA1) &= reg_d0.b[0];
    *(u16 *)(reg_a6 + 0x14A) = reg_d1.h[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12D);
    if (reg_d0.b[0] != 0x19) goto next_51;
    *(u8 *)(reg_a6 + 0x12D) = 0x12;
next_51:
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12D);
    reg_d0.b[0] ^= 0xD;
    *(u8 *)(reg_a6 + 0x12D) = reg_d0.b[0];
    if (*(u16 *)(reg_a6 + 0x148) == 0) goto next_52;
    *(u16 *)(reg_a6 + 0xB8) = 0x5000;
next_52:
    if (*(s16 *)(reg_a6 + 0xB8) >= 0) goto next_59;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x14A);
    reg_d0.w = 0x800;
    func_001A91A0();
    func_001CBB10();
    goto next_59;
next_55:
    *(u8 *)(reg_a6 + 0x12D) = 0x12;
    reg_d2.h[0] = 0x1800;
    if ((s32) *(u16 *)(reg_a6 + 0xB8) > (s32) reg_d2.h[0]) goto next_59;
    if (D_0028E8B8 != 0) goto next_59;
    *(u8 *)(reg_a6 + 0x12D) = 0x19;
next_59:
    if (*(u16 *)(reg_a6 + 0x100) == 0x8000) goto next_610;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x101);
    reg_d1.b[0] |= *(u8 *)(reg_a6 + 0xC1);
    reg_d1.b[0] |= *(u8 *)(reg_a6 + 0xE1);
    cnt = reg_d1.h[0] & 0x5C;
    reg_d1.h[0] = cnt;
    if (!(cnt & 0xFFFF)) goto next_600;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 0x101) &= reg_d0.b[0];
    *(u8 *)(reg_a6 + 0xC1) &= reg_d0.b[0];
    *(u8 *)(reg_a6 + 0xE1) &= reg_d0.b[0];
    *(u16 *)(reg_a6 + 0x14A) = reg_d1.h[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12E);
    if (reg_d0.b[0] != 0x19) goto next_601;
    *(u8 *)(reg_a6 + 0x126) = 0x10;
    *(u8 *)(reg_a6 + 0x127) = 0x12;
    *(u8 *)(reg_a6 + 0x129) = 0x17;
    *(u8 *)(reg_a6 + 0x12E) = 0x11;
    *(u8 *)(reg_a6 + 0x131) = 0x13;
    *(u8 *)(reg_a6 + 0x12C) = 0x13;
    *(u8 *)(reg_a6 + 0x12F) = 0xD;
    *(u8 *)(reg_a6 + 0x128) = 0x11;
    *(u8 *)(reg_a6 + 0x12B) = 0x11;
    *(u8 *)(reg_a6 + 0x12A) = 0x12;
    *(u8 *)(reg_a6 + 0x12D) = 0x12;
next_601:
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x126);
    reg_d0.b[0] ^= 0xF;
    *(u8 *)(reg_a6 + 0x126) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x127);
    reg_d0.b[0] ^= 0xD;
    *(u8 *)(reg_a6 + 0x127) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x129);
    reg_d0.b[0] ^= 0x8;
    *(u8 *)(reg_a6 + 0x129) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12E);
    reg_d0.b[0] ^= 0xE;
    *(u8 *)(reg_a6 + 0x12E) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x131);
    reg_d0.b[0] ^= 0xC;
    *(u8 *)(reg_a6 + 0x131) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12C);
    reg_d0.b[0] ^= 0xC;
    *(u8 *)(reg_a6 + 0x12C) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12F);
    reg_d0.b[0] ^= 0x12;
    *(u8 *)(reg_a6 + 0x12F) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x128);
    reg_d0.b[0] ^= 0xE;
    *(u8 *)(reg_a6 + 0x128) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12B);
    reg_d0.b[0] ^= 0xE;
    *(u8 *)(reg_a6 + 0x12B) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12A);
    reg_d0.b[0] ^= 0xD;
    *(u8 *)(reg_a6 + 0x12A) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12D);
    reg_d0.b[0] ^= 0xD;
    *(u8 *)(reg_a6 + 0x12D) = reg_d0.b[0];
    if (D_0028E290 == 2) {
        m = *(u16 *)(reg_a6 + 0x118);
        h1 = *(u16 *)(reg_a6 + 0xD8);
        h2 = *(u16 *)(reg_a6 + 0xF8);
        if (m > h1) goto skip_m4;
        m = h1;
skip_m4:
        if (m > h2) goto skip_m5;
        m = h2;
skip_m5:;
    }
    reg_d2.w = 0x7FFF;
    reg_d2.h[0] -= *(u16 *)(reg_a6 + 0x118);
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= *(u16 *)(reg_a6 + 0xD8);
    if (!((s32) reg_d2.w < (s32) reg_d3.w)) goto skip_d1180;
    reg_d2.w = reg_d3.w;
skip_d1180:
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= *(u16 *)(reg_a6 + 0xF8);
    if (!((s32) reg_d2.w < (s32) reg_d3.w)) goto skip_d1181;
    reg_d2.w = reg_d3.w;
skip_d1181:
    if (*(u16 *)(reg_a6 + 0x148) != 0) goto next_608;
    D_0028E480.h[1] = *(u16 *)(reg_a5 + 0x16);
    D_0028E480.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (D_0028E290 != 2) goto next_606;
    if (m <= 0x7FFF) goto next_605;
    m -= 0x7FFF;
    D_0028E480.w += m;
    if ((u32) D_0028E480.w < 0x2BDC0U) goto next_607;
    D_0028E480.w = 0x2BDC0;
    goto next_607;
next_605:
    D_0028E480.w -= reg_d2.w;
    goto next_607;
next_606:
    D_0028E480.w -= reg_d2.w;
next_607:
    *(u16 *)(reg_a5 + 0x16) = D_0028E480.h[1];
    *(u16 *)(reg_a5 + 0x18) = D_0028E480.h[0];
next_608:
    reg_d0.h[0] = 0x7FFF;
    *(u16 *)(reg_a6 + 0x118) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xD8) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xF8) = reg_d0.h[0];
    goto next_610;
next_600:
    *(u8 *)(reg_a6 + 0x126) = 0x10;
    *(u8 *)(reg_a6 + 0x127) = 0x12;
    *(u8 *)(reg_a6 + 0x129) = 0x17;
    *(u8 *)(reg_a6 + 0x12E) = 0x11;
    *(u8 *)(reg_a6 + 0x131) = 0x13;
    *(u8 *)(reg_a6 + 0x12C) = 0x13;
    *(u8 *)(reg_a6 + 0x12F) = 0xD;
    *(u8 *)(reg_a6 + 0x128) = 0x11;
    *(u8 *)(reg_a6 + 0x12B) = 0x11;
    *(u8 *)(reg_a6 + 0x12A) = 0x12;
    *(u8 *)(reg_a6 + 0x12D) = 0x12;
next_610:
    if (*(u8 *)(reg_a6 + 0x14D) != 0) goto next_720;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x5E);
    reg_d0.b[0] += *(u8 *)(reg_a6 + 0x7E);
    reg_d0.b[0] += *(u8 *)(reg_a6 + 0x9E);
    reg_d0.b[0] += *(u8 *)(reg_a6 + 0xBE);
    if (reg_d0.b[0] == 4) goto next_710;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_d0.w -= 0xEFC0;
    if ((s32) reg_d0.w >= 0) goto next_720;
next_710:
    func_001253B0();
    func_00124D10();
    reg_d0.w = 1;
    func_00124B20();
    func_001CB7E0();
    func_001CB890();
    func_001CB940();
    func_001CBB10();
    *(u8 *)(reg_a6 + 0x12C) = 0x13;
    *(u8 *)(reg_a6 + 0x12F) = 0xD;
    *(u8 *)(reg_a6 + 0x14D) = 1;
    func_002016D0();
next_720:
    if (*(u8 *)(reg_a6 + 0x14C) != 0) goto next_730;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (!((s32) reg_tmp.w < 0x7701)) goto next_730;
    *(u8 *)(reg_a6 + 0x14C) = 1;
    func_001253B0();
    func_00124D10();
    reg_d0.w = 8;
    func_00124B20();
next_730:
    func_001CBCE0();
}
