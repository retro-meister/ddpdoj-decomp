#include "common.h"

s32 func_00129370();
extern u16 D_0026E090[];
extern u16 D_0026E092[];
extern u16 D_0026E094[];
extern u16 D_0026E096[];
extern u16 D_0026E098[];
extern u16 D_0026E09A[];
extern u16 D_0026E09C[];
extern u16 D_0026E09E[];
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B4D00(void) {
    u16 temp_a1;
    u16 temp_a2;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        reg_d1.w = 0;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
        temp_a2 = reg_d0.h[0];
        reg_tmp.w = reg_d0.w;
        reg_d0.h[1] = temp_a2;
        reg_d0.h[0] = 3;
        temp_a1 = (*(u16 *)((u8 *)(reg_a4) + (8)));
        reg_d6.h[0] = temp_a1;
        reg_d3.h[1] = D_0026E098[0];
        reg_d3.h[0] = D_0026E09A[0];
        reg_d4.w = 0;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.h[0] += 2;
        func_00129370();
        reg_d3.h[1] = D_0026E09C[0];
        reg_d3.h[0] = D_0026E09E[0];
        reg_d1.h[0] -= 4;
        func_00129370();
        reg_d1.h[0] += 2;
        reg_d1.b[0] += reg_d6.b[0];
        reg_d3.h[1] = D_0026E090[0];
        reg_d3.h[0] = D_0026E092[0];
        func_00129370();
        reg_d1.b[0] -= reg_d6.b[0];
        reg_d3.h[1] = D_0026E094[0];
        reg_d3.h[0] = D_0026E096[0];
        reg_d1.b[0] -= reg_d6.b[0];
        func_00129370();
        (*(u16 *)((u8 *)(reg_a4) + (4))) += 4;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
        (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a4) + (6))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (6))) == 0) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
