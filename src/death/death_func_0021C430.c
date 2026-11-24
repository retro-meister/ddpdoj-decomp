#include "common.h"


s32 func_002011A0();
extern u16 D_00264590[];
extern u32 D_0028DA00;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void death_func_0021C430(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264590);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DA00 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x17))) = (u8) reg_d0.b[0];
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x19))) = (u8) reg_d0.b[0];
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1B))) = (u8) reg_d0.b[0];
    (*(s16 *)((u8 *)(reg_a6) + (0x1e))) = 5;
    (*(s8 *)((u8 *)(reg_a6) + (0x1c))) = 8;
}
