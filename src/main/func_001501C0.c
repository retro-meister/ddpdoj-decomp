#include "common.h"

s32 func_0014E290();
s32 func_0019C470();
s32 func_00201B80();
s32 func_00201C60();
extern u8 D_0026E820[];
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001501C0(void) {
    u16 temp_a0;
    u16 temp_a1;

    if (D_0028E8A0 == 0) {
        func_00201B80();
        func_00201C60();
        if ((*(u16 *)((u8 *)(reg_a5) + (0x1E))) == 0) {
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) -= 1;
            if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) == 0) {
                (*(s16 *)((u8 *)(reg_a6) + (0x1A))) = 0x537;
                (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = 1U;
                (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 0x808U;
            }
        }
        if ((*(u16 *)((u8 *)(reg_a5) + (0x1E))) == 1) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 1;
            }
        }
        if ((*(s16 *)((u8 *)(reg_a6) + (4))) < -0x21FF) {
            func_0014E290();
            return;
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
            (*(u16 *)((u8 *)(reg_a5) + (0x18))) += 4;
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x1B))) >= 0x10) {
                (*(u16 *)((u8 *)(reg_a5) + (0x18))) += 4;
                (*(u16 *)((u8 *)(reg_a5) + (0x18))) += 4;
            }
            (*(u16 *)((u8 *)(reg_a5) + (0x18))) &= 0x3F;
        }
        goto block_13;
    }
block_13:
    reg_d2.w = 0x1A3A;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0;
    reg_d3.h[0] = 0x1488;
    reg_d4.w = 0x13;
    func_0019C470();
    reg_a0 = (u8 *)D_0026E820;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFDC00080;
    reg_d3.h[0] = 0x1488;
    reg_d4.w = 0x13;
    func_0019C470();
}
