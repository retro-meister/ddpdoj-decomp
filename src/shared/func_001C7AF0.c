#include "common.h"

s32 func_0014E290();
s32 func_0014EA50();
s32 func_0019BF80();
s32 func_0019C530();
extern u16 D_00262F00[];
extern u16 D_0028E484;
extern u16 D_0028E8A8;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C7AF0(void) {
    u32 temp_a1;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        if ((s32) D_0028E8A8 >= 0x22F) {
            func_0014E290();
            return;
        }
        if (((s32) D_0028E8A8 >= 0x1F8) && ((*(s16 *)((u8 *)(reg_a5) + (0x1C))) >= 0)) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
                reg_a0 = (u8 *)(D_00262F00);
                reg_a0 += reg_d0.h[0];
                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                (*(u16 *)((u8 *)(reg_a5) + (0x20))) = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                (*(u16 *)((u8 *)(reg_a5) + (0x1C))) -= 8;
            }
        }
        if ((s32) D_0028E8A8 < 0x21A) {
            func_0019BF80();
        }
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] += 0x4C00;
        temp_a1 = reg_d1.h[0];
        D_0028E484 = temp_a1;
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484;
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.w += 0xFE00DC00;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
        reg_d3.h[0] = 0x2320;
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
        func_0019C530();
    }
}
