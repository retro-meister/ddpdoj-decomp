#include "common.h"

s32 func_0016C260();
s32 func_00201C60();
s32 func_002021D0();
s32 func_00202B50();
s32 func_00203060();
extern u16 D_0028E3E0;
extern s8 D_0028E408;
extern u8 D_0028E855;
extern u16 D_0028E8A0;
extern u8 *reg_a6;

void func_0016B7F0(void) {
    if (!(D_0028E855 & 0x40)) {
        if (!((*(u8 *)((u8 *)(reg_a6) + (1))) & 1)) {
            if (D_0028E3E0 == 0) {
                reg_d2.h[0] = 0x4600;
                reg_d3.h[0] = 0x1C00;
                func_002021D0();
                (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
            }
            reg_d2.h[0] = 0x4600;
            reg_d3.h[0] = 0x1C00;
            func_00202B50();
            if ((s32) reg_d0.h[0] < 0x201) {
                (*(u8 *)((u8 *)(reg_a6) + (1))) |= 1;
                (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 0xA;
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                reg_d0.b[0] -= 8;
                (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = 0x40U;
                if (reg_d0.w & 0x10) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) -= 0x10;
                }
                if (reg_d0.w & 0x20) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) -= 0x20;
                } else {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = 0U;
                }
            }
        } else if (D_0028E8A0 == 0) {
            (*(u16 *)((u8 *)(reg_a6) + (0x18))) -= 1;
            if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x18))) >= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x1F))) -= 1;
                if ((*(u8 *)((u8 *)(reg_a6) + (0x1F))) == 0) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) += 0x10;
                    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) &= 0x3F;
                    if (D_0028E8A0 == 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (0x1E))) += 8;
                    }
                    (*(u8 *)((u8 *)(reg_a6) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1E)));
                }
            }
        }
    }
    func_00201C60();
    D_0028E408 = 0;
    func_00203060();
    if (D_0028E408 != 0) {
        func_0016C260();
    }
}
