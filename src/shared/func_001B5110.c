#include "common.h"

s32 func_001B4EB0();
extern u16 D_0026E0A0[];
extern u16 D_0026E0A2[];
extern u16 D_0026E0A4[];
extern u16 D_0026E0A6[];
extern u16 D_0026E0A8[];
extern u16 D_0026E0AA[];
extern u16 D_0026E0AC[];
extern u16 D_0026E0AE[];
extern u16 D_0028E89C;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B5110(void) {
    u16 temp_a0;
    u16 temp_a1;

    if (D_0028E89C == 0) {
        if (!((*(u8 *)((u8 *)(reg_a4) + (4))) & 1)) {
            (*(u8 *)((u8 *)(reg_a6) + (0xC7))) += 1;
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0xC7))) >= 0x30) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) |= 1;
            }
        } else {
            (*(u8 *)((u8 *)(reg_a6) + (0xC7))) -= 1;
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0xC7))) < 0x11) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) &= 0xE;
            }
        }
        if (!((*(u8 *)((u8 *)(reg_a4) + (4))) & 2)) {
            (*(u8 *)((u8 *)(reg_a6) + (0xC6))) += 1;
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0xC6))) >= 0x30) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) |= 2;
            }
        } else {
            (*(u8 *)((u8 *)(reg_a6) + (0xC6))) -= 1;
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0xC6))) < 0x11) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) &= 0xD;
            }
        }
        if (!((*(u8 *)((u8 *)(reg_a4) + (4))) & 4)) {
            (*(u8 *)((u8 *)(reg_a6) + (0xC9))) += 1;
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0xC9))) >= 0x30) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) |= 4;
            }
        } else {
            (*(u8 *)((u8 *)(reg_a6) + (0xC9))) -= 1;
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0xC9))) < 0x11) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) &= 0xB;
            }
        }
        if (!((*(u8 *)((u8 *)(reg_a4) + (4))) & 8)) {
            (*(u8 *)((u8 *)(reg_a6) + (0xC8))) += 1;
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0xC8))) >= 0x30) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) |= 8;
            }
        } else {
            (*(u8 *)((u8 *)(reg_a6) + (0xC8))) -= 1;
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0xC8))) < 0x11) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) &= 7;
            }
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
        (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
            temp_a1 = reg_d0.h[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = temp_a1;
            reg_d0.h[0] = 0xC;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d2.h[0] = temp_a0;
            reg_d3.h[1] = D_0026E0A0[0];
            reg_d3.h[0] = D_0026E0A2[0];
            reg_d1.w = 0;
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xC7)));
            func_001B4EB0();
            reg_d3.h[1] = D_0026E0A4[0];
            reg_d3.h[0] = D_0026E0A6[0];
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xC6)));
            func_001B4EB0();
            reg_d3.h[1] = D_0026E0A8[0];
            reg_d3.h[0] = D_0026E0AA[0];
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xC9)));
            func_001B4EB0();
            reg_d3.h[1] = D_0026E0AC[0];
            reg_d3.h[0] = D_0026E0AE[0];
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xC8)));
            func_001B4EB0();
            (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
            if ((s8) (*(u8 *)((u8 *)(reg_a4) + (5))) == 0) {
                (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
            }
        }
    }
}
