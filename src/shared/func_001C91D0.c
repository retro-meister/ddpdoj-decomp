#include "common.h"

extern s8 D_0028E408;

s32 func_00124B20();
s32 func_00124F50();
s32 func_00125060();
s32 func_001251C0();
s32 func_00202140();
s32 func_00202500();
extern u16 D_0026C250[];
extern u16 D_0026C252[];
extern u16 D_0026C260[];
extern u16 D_0026C262[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C91D0(void) {
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_a1_4;
    u8 temp_a0_3;

    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d1.h[0] = temp_a1;
            reg_d0.h[0] += D_0026C250[0];
            reg_d1.h[0] += D_0026C252[0];
            func_00202140();
            (*(u8 *)((u8 *)(reg_a4) + (0xB))) = (u8) reg_d1.b[0];
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a1_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d1.h[0] = temp_a1_2;
            reg_d0.h[0] += D_0026C260[0];
            reg_d1.h[0] += D_0026C262[0];
            func_00202140();
            (*(u8 *)((u8 *)(reg_a4) + (0xA))) = (u8) reg_d1.b[0];
        }
    }
    temp_a0_3 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_3 == 1) {
        reg_d0.w = 8;
        func_00125060();
        if (D_0028E408 == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
                reg_d0.w = 8;
                func_00124F50();
                reg_d7.w = 1;
                do {
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    temp_a1_3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_d1.h[0] = temp_a1_3;
                    reg_d0.h[0] += D_0026C250[0];
                    reg_d1.h[0] += D_0026C252[0];
                    func_00202140();
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
                    func_00202500();
                    (*(u8 *)((u8 *)(reg_a4) + (0xB))) = (u8) reg_d1.b[0];
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    temp_a1_4 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_d1.h[0] = temp_a1_4;
                    reg_d0.h[0] += D_0026C260[0];
                    reg_d1.h[0] += D_0026C262[0];
                    func_00202140();
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xA)));
                    func_00202500();
                    (*(u8 *)((u8 *)(reg_a4) + (0xA))) = (u8) reg_d1.b[0];
                } while ((s16)(--reg_d7.h[0]) >= 0);
                reg_d0.w = 0xD;
                func_001251C0();
                (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                (*(u16 *)((u8 *)(reg_a4) + (8))) -= 1;
                if ((*(u16 *)((u8 *)(reg_a4) + (8))) == 0) {
                    (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
                    reg_d0.w = 4;
                    func_00124B20();
                }
            }
        }
    }
}
