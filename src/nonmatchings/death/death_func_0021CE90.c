#include "common.h"

s32 func_001EFF10();
s32 func_0020ED00();
extern u8 D_00262A50[];
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;

void death_func_0021CE90(void) {
    u32 temp_a0;
    u8 temp_v1;
    u8 temp_v1_2;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
        if ((u32) reg_tmp.w < 0x15000U) {
            reg_d0.b[0] -= 2;
            func_0020ED00();
        }
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) reg_d0.b[0];
        reg_a1 = (u8 *)D_00262A50;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x12)));
        func_001EFF10();
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x12)));
        reg_d1.b[0] += 0x40;
        func_001EFF10();
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x12)));
        reg_d1.b[0] += 0x80;
        func_001EFF10();
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x12)));
        reg_d1.b[0] += 0xC0;
        func_001EFF10();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x13)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
        if ((u32) reg_tmp.w < 0x15000U) {
            reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
        }
        (*(u8 *)((u8 *)(reg_a4) + (0x12))) += reg_d0.b[0];
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            (*(u8 *)((u8 *)(reg_a4) + (0x13))) *= -1;
            temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            if ((s16)(temp_a0) < 6) {
                (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) (temp_a0 + 2);
            }
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
                temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (9)));
                if ((s32) temp_v1 > 7) {
                    (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (temp_v1 - 2);
                    if ((s32) (*(u8 *)((u8 *)(reg_a4) + (9))) < 8) {
                        func_0020ED00();
                    }
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
