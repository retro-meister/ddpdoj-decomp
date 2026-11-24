#include "common.h"

s32 func_00124F50();
s32 func_00125310();
s32 func_00129280();
s32 func_001293C0();
s32 func_00171400();
s32 func_002027A0();
extern u16 D_0026D1A0[];
extern u16 D_0026D1B8[];
extern s16 *D_0028E448;
extern u16 D_0028E910;
extern u16 D_0029F1F0[];
extern u16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D0E60(void) {
    s16 *temp_a0_2;
    s16 *var_a1;
    u32 temp_a0_10;
    u32 temp_a0_3;
    u32 temp_a0_6;
    u32 temp_a0_7;
    u32 temp_a0_8;
    u32 temp_a1;
    u8 temp_a0;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (7)));
        temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (0x1B)));
        if (!(temp_a0 & 1)) {
            (*(u8 *)((u8 *)(reg_a4) + (0x1B))) = (u8) (temp_a0 | 1);
            reg_a0 = (u8 *)(D_0029F260);
            reg_a1 = (u8 *)(D_0029F1F0);
            if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
                D_0028E448 = (s16 *)(reg_a1);
                reg_a1 = (u8 *)(reg_a0);
                reg_a0 = (u8 *)(D_0028E448);
            }
            var_a1 = (s16 *)(reg_a0);
            if ((*(s16 *)((u8 *)(var_a1) + (0))) >= 0) {
                temp_a0_2 = (s16 *)(reg_a1);
                if (*temp_a0_2 < 0) {
                    reg_a1 = (u8 *)(var_a1);
                    D_0028E448 = (s16 *)(temp_a0_2);
                    reg_a0 = (u8 *)(temp_a0_2);
                    goto block_7;
                }
            } else {
block_7:
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d0.h[0] += 0x7FFF + 0x7541;
                func_002027A0();
                (*(u8 *)((u8 *)(reg_a4) + (0x1A))) = (u8) reg_d1.b[0];
                goto block_8;
            }
        } else {
block_8:
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1A)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d2.h[0] = temp_a1;
            reg_d6.h[0] = 8;
            reg_d7.h[0] = 0xFFFE;
            reg_d4.w = 0;
            if (D_0028E910 != 0) {
                reg_d6.h[0] = 0xA;
                reg_d7.h[0] = 0xFFFF;
            }
            reg_a3 = (u8 *)(D_0026D1A0);
            if ((*(s8 *)((u8 *)(reg_a4) + (8))) >= 0) {
                reg_a3 = (u8 *)(D_0026D1B8);
            }
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            temp_a0_3 = *(u16 *)reg_a3;
            reg_d3.h[0] = temp_a0_3;
            reg_a3 += 2;
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
            reg_d1.h[0] += 0x14;
            func_00129280();
            if (D_0028E910 != 0) {
                reg_d0.h[0] = 5;
                reg_d0.h[1] -= reg_d7.h[0];
                reg_d1.h[0] += reg_d6.h[0];
                func_00129280();
                reg_d1.h[0] -= reg_d6.h[0];
            }
            reg_d0.h[0] = 5;
            reg_d0.h[1] -= reg_d7.h[0];
            reg_d1.h[0] -= reg_d6.h[0];
            func_00129280();
            reg_d1.h[0] += reg_d6.h[0];
            temp_a0_6 = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[1] = temp_a0_6;
            temp_a0_7 = *(u16 *)reg_a3;
            reg_d3.h[0] = temp_a0_7;
            reg_a3 += 2;
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
            reg_d1.h[0] -= 0x14;
            func_001293C0();
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            temp_a0_8 = *(u16 *)reg_a3;
            reg_d3.h[0] = temp_a0_8;
            reg_a3 += 2;
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
            reg_d1.h[0] -= 0x14;
            func_00129280();
            reg_d0.h[0] = 5;
            reg_d0.h[1] -= reg_d7.h[0];
            reg_d1.h[0] += reg_d6.h[0];
            func_00129280();
            reg_d1.h[0] -= reg_d6.h[0];
            switch (D_0028E910) { case 0: break; default:
                temp_a0_10 = reg_d0.h[1];
                reg_d0.h[0] = 5;
                reg_d0.h[1] = temp_a0_10 - reg_d7.h[0];
                reg_d1.h[0] -= reg_d6.h[0];
                func_00129280();
            }
            var_a1 = (s16 *)(reg_a4);
            reg_d0.b[0] = (u8) (*(u8 *)((u8 *)(var_a1) + (8)));
            (*(u8 *)((u8 *)(var_a1) + (0x1A))) += reg_d0.b[0];
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        switch (reg_tmp.b[0]) {
        case 0:
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xD)));
            (*(u8 *)((u8 *)(reg_a4) + (8))) *= -1;
            (*(u8 *)((u8 *)(reg_a4) + (0x1B))) &= 0xFE;
            func_00171400();
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
            (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
            if ((s32) (*(u8 *)((u8 *)(reg_a4) + (4))) > 0xE) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) = 0xEU;
            }
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x16)));
            (*(u16 *)((u8 *)(reg_a4) + (0xE))) += reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a4) + (0x12))) += reg_d0.h[0];
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
            (*(u8 *)((u8 *)(reg_a4) + (0xB))) -= 1;
            if (reg_tmp.b[0] == 0) {
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
                (*(u8 *)((u8 *)(reg_a6) + (0x117))) += reg_d0.b[0];
                if ((s32) (*(u8 *)((u8 *)(reg_a6) + (0x117))) > 0xE) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x117))) = 0xEU;
                }
                (*(u8 *)((u8 *)(reg_a6) + (0x116))) += 1;
                if ((s32) (*(u8 *)((u8 *)(reg_a6) + (0x116))) > 4) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x116))) = 4U;
                }
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x18)));
                (*(u16 *)((u8 *)(reg_a6) + (0x118))) += reg_d0.b[0];
                if ((s32) (*(u16 *)((u8 *)(reg_a6) + (0x118))) > 0xC) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x118))) = 0xCU;
                }
                reg_d0.w = 8;
                func_00125310();
                reg_d0.w = 5;
                func_00124F50();
            }
            break;
        }
    }
}
