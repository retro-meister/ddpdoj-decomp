#include "common.h"


s32 func_00129370();
extern u16 D_0026E170[];
extern u16 D_0026E172[];
extern u16 D_0026E174[];
extern u16 D_0026E176[];
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B6D30(void) {
    u16 temp_a2;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.w = 0;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x13;
        reg_d1.b[0] = 0x80;
        reg_d3.h[1] = D_0026E170[0];
        reg_d3.h[0] = D_0026E172[0];
        reg_d4.w = 0;
        func_00129370();
        reg_d1.b[0] += 0xC;
        func_00129370();
        reg_d1.b[0] += 0xC;
        func_00129370();
        reg_d1.b[0] -= 0x24;
        func_00129370();
        reg_d1.b[0] -= 0xC;
        func_00129370();
        reg_d1.b[0] = 0x80;
        reg_d3.h[1] = D_0026E174[0];
        reg_d3.h[0] = D_0026E176[0];
        func_00129370();
        reg_d1.b[0] += 0xC;
        func_00129370();
        reg_d1.b[0] += 0xC;
        func_00129370();
        reg_d1.b[0] -= 0x24;
        func_00129370();
        reg_d1.b[0] -= 0xC;
        func_00129370();
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
