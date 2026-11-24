#include "common.h"

s32 func_001EAF20();
s32 func_001EB060();
extern u8 D_00262A50_as_u8_a[];
extern u16 D_0028E89C;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001EB0E0(void) {
    u32 temp_a0;
    u8 temp_v1;
    u8 temp_v1_2;

    if (D_0028E89C != 0) {
        func_001EB060();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
        if ((u32) reg_tmp.w < 0x15000U) {
            reg_d0.b[0] -= 4;
        }
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) reg_d0.b[0];
        reg_a1 = (u8 *)D_00262A50_as_u8_a;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x12)));
        func_001EAF20();
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x12)));
        reg_d1.b[0] += 0x80;
        func_001EAF20();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x13)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
        if ((u32) reg_tmp.w < 0x15000U) {
            reg_d0.b[0] = (s8) reg_d0.b[0] * 4;
        }
        (*(u8 *)((u8 *)(reg_a4) + (0x12))) += reg_d0.b[0];
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            (*(u8 *)((u8 *)(reg_a4) + (0x13))) *= -1;
            temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            if ((s16)(temp_a0) < 8) {
                (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) (temp_a0 + 2);
            }
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
                temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (9)));
                if ((s32) temp_v1 > 5) {
                    (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (temp_v1 - 2);
                }
                temp_v1_2 = (*(u8 *)((u8 *)(reg_a4) + (4)));
                if ((s32) temp_v1_2 < 0xC7) {
                    (*(u8 *)((u8 *)(reg_a4) + (4))) = (u8) (temp_v1_2 + 0x14);
                }
                (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            }
        }
    }
}
