#include "common.h"

s32 func_00129410();
s32 func_002026F0();
extern u16 D_0026E090[];
extern u16 D_0026E092[];
extern u16 D_0026E094[];
extern u16 D_0026E096[];
extern u16 D_0026E098[];
extern u16 D_0026E09A[];
extern u16 D_0026E09C[];
extern u16 D_0026E09E[];
extern s8 D_0028E408;
extern u16 D_0028E49E;
extern u16 D_0028E4A2;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B69E0() {
    u16 temp_a2;
    u8 temp_a0;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
    (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        func_002026F0();
        if (D_0028E408 == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) reg_d1.b[0];
        }
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x20009;
        reg_d4.w = 0;
        reg_d1.w = 0;
        temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
        reg_d1.b[0] = temp_a0;
        D_0028E49E = D_0026E094[0];
        reg_d3.h[0] = D_0026E096[0];
        func_00129410();
        D_0028E49E = D_0026E09C[0];
        reg_d3.h[0] = D_0026E09E[0];
        func_00129410();
        D_0028E49E = D_0026E090[0];
        reg_d3.h[0] = D_0026E092[0];
        func_00129410();
        D_0028E49E = D_0026E098[0];
        reg_d3.h[0] = D_0026E09A[0];
        func_00129410();
        (*(u16 *)((u8 *)(reg_a4) + (0xA))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (0xA))) == 0) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
