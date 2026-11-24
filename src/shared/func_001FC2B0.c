#include "common.h"

s32 func_0014D220();
s32 func_0014E290();
s32 func_0018DAF0();
s32 func_001FC670();
s32 func_001FC710();
s32 func_001FC7F0();
s32 func_001FC8E0();
extern u8 D_00266160[];
extern u8 D_0028E2E4;
extern u16 D_0028E890;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FC2B0(void) {
    if (D_0028E2E4 != 0) return;
    *(s16 *)(reg_a6 + 0x18) = 0x7FFF;
    if (D_0028E890 == 0) goto block_end1;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[1] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a0 + 4);
    if (*(u16 *)(reg_a5 + 0x1A) != 0) {
        reg_d0.w += 0xF1FFF880;
    } else {
        reg_d0.w += 0xF2000780;
    }
    *(u16 *)(reg_a6 + 2) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 4) = (u16) reg_d0.h[0];
    if (!(*(u8 *)(reg_a5 + 0x1D) & 1)) goto skip_1;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
    *(u8 *)(reg_a5 + 0x21) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto skip_1;
    *(u8 *)(reg_a5 + 0x21) = *(u8 *)(reg_a5 + 0x20);
    *(u16 *)(reg_a5 + 0x1E) += 4;
    if ((s16) *(u16 *)(reg_a5 + 0x1E) < 0x60) goto skip_1;
    *(u16 *)(reg_a5 + 0x1E) = 0;
    *(u8 *)(reg_a5 + 0x1D) &= 0xFE;
    *(u8 *)(reg_a5 + 0x1D) |= 0xE;
    func_001FC8E0();
    func_0018DAF0();
    *(u16 *)reg_a6 = 0x8001;
skip_1:
    if (!(*(u8 *)(reg_a5 + 0x1D) & 2)) goto skip_2;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto skip_2;
    *(u8 *)(reg_a5 + 0x25) = *(u8 *)(reg_a5 + 0x24);
    *(u16 *)(reg_a5 + 0x22) += 0x10;
    if ((s16) *(u16 *)(reg_a5 + 0x22) < 0x90) goto skip_2;
    *(u16 *)(reg_a5 + 0x22) = 0;
    *(u8 *)(reg_a5 + 0x1D) &= 0xFD;
skip_2:
    if (!(*(u8 *)(reg_a5 + 0x1D) & 4)) goto skip_4;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x29);
    *(u8 *)(reg_a5 + 0x29) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto skip_3;
    *(u8 *)(reg_a5 + 0x29) = *(u8 *)(reg_a5 + 0x28);
    *(u16 *)(reg_a5 + 0x26) += 0x10;
    if ((s16) *(u16 *)(reg_a5 + 0x26) < 0xD0) goto skip_3;
    *(u16 *)(reg_a5 + 0x26) = 0;
block_end1:
    func_0014E290();
    return;
skip_3:
    reg_a0 = (u8 *)D_00266160;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x26);
    reg_d0.h[0] >>= 1;
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x10) = *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x12) = *(u16 *)(reg_a0 + 2);
    *(u16 *)(reg_a6 + 0x14) = *(u16 *)(reg_a0 + 4);
    *(u16 *)(reg_a6 + 0x16) = *(u16 *)(reg_a0 + 6);
    if (*(u16 *)(reg_a5 + 0x1A) != 0) {
        *(u16 *)(reg_a6 + 0x14) = *(u16 *)(reg_a0 + 6);
        *(u16 *)(reg_a6 + 0x16) = *(u16 *)(reg_a0 + 4);
    }
skip_4:
    if (!(*(u8 *)(reg_a5 + 0x1D) & 8)) goto skip_5;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_a0 = (u8 *)reg_tmp.w;
    if (*(u16 *)(reg_a5 + 0x1A) != 0) {
        reg_a0 = reg_a0 + 0x26;
    } else {
        reg_a0 = reg_a0 + 0x46;
    }
    if (*(u16 *)reg_a0 == 0x280) goto skip_5;
    *(u16 *)reg_a0 += 0x100;
    if ((s16) *(u16 *)reg_a0 < 0x280) goto skip_5;
    *(u16 *)reg_a0 = 0x280;
    *(u8 *)(reg_a5 + 0x1D) &= 0xF7;
skip_5:
    func_001FC670();
    func_001FC710();
    func_001FC7F0();
    reg_a0 = (u8 *)reg_a6;
    func_0014D220();
}
