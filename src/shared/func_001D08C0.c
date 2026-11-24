#include "common.h"

s32 func_00124F50();
s32 func_00125310();
s32 func_00129280();
s32 func_00129370();
s32 func_001293C0();
s32 func_002011A0();
extern u16 D_0026D1A0[];
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D08C0(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_a1_4;
    u16 temp_a1_5;
    u16 temp_v1_2;
    u8 temp_v1;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (7)));
        temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (0x1E)));
        if (!(temp_v1 & 1)) {
            (*(u8 *)((u8 *)(reg_a4) + (0x1E))) = (u8) (temp_v1 | 1);
            func_002011A0();
            if ((s8)(reg_d0.b[0]) >= 0) {
                reg_d0.b[0] *= -1;
            }
            (*(u8 *)((u8 *)(reg_a4) + (0x1F))) = (u8) reg_d0.b[0];
        }
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1F)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d4.w = 0;
        reg_d6.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
        reg_a3 = (u8 *)(D_0026D1A0);
        temp_a1 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1;
        reg_a3 += 2;
        temp_a0 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0;
        reg_a3 += 2;
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
        reg_d1.b[0] += reg_d6.b[0];
        func_00129280();
        temp_a1_2 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1_2;
        reg_a3 += 2;
        temp_a0_2 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0_2;
        reg_a3 += 2;
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
        reg_d1.b[0] -= reg_d6.b[0];
        func_001293C0();
        temp_a1_3 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1_3;
        reg_a3 += 2;
        temp_a0_3 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0_3;
        reg_a3 += 2;
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
        reg_d1.b[0] -= reg_d6.b[0];
        func_00129370();
        reg_d1.b[0] += 0x80;
        temp_v1_2 = *(u16 *)reg_a3;
        reg_a3 += 2;
        reg_d3.h[1] = temp_v1_2;
        reg_d3.h[0] = *(u16 *)reg_a3;
        reg_a3 += 2;
        func_00129280();
        temp_a1_4 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1_4;
        reg_a3 += 2;
        temp_a0_4 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0_4;
        reg_a3 += 2;
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
        reg_d1.b[0] += reg_d6.b[0];
        func_001293C0();
        temp_a1_5 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1_5;
        reg_a3 += 2;
        temp_a0_5 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0_5;
        reg_a3 += 2;
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
        reg_d1.b[0] += reg_d6.b[0];
        func_00129370();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (8)));
        (*(u8 *)((u8 *)(reg_a4) + (0x1F))) += reg_d0.b[0];
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if (reg_tmp.b[0] == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xD)));
            (*(u8 *)((u8 *)(reg_a4) + (8))) *= -1;
            (*(u8 *)((u8 *)(reg_a4) + (0x1E))) &= 0xFE;
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x1A)));
            (*(u16 *)((u8 *)(reg_a4) + (0xE))) += reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a4) + (0x12))) += reg_d0.h[0];
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
            (*(u8 *)((u8 *)(reg_a4) + (0xB))) -= 1;
            if (reg_tmp.b[0] == 0) {
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x1C)));
                (*(u16 *)((u8 *)(reg_a6) + (0x112))) += reg_d0.h[0];
                if ((s32) (*(u16 *)((u8 *)(reg_a6) + (0x112))) > 12) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x112))) = 0xCU;
                }
                reg_d0.w = 5;
                func_00125310();
                reg_d0.w = 5;
                func_00124F50();
            }
        }
    }
}
