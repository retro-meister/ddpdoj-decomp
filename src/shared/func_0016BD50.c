#include "common.h"

extern s8 D_0028E408;

s32 func_0016C260();
extern u16 D_00269490[];
extern Reg32 D_0028E484;
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0016BD50(void) {
    u32 temp_a1;
    u8 temp_v1;

    if (D_0028E8A0 == 0) {
        temp_v1 = (*(u8 *)((u8 *)(reg_a6) + (0x18)));
        reg_d1.b[0] = temp_v1;
        if (temp_v1 != 0) {
            (*(u16 *)((u8 *)(reg_a6) + (2))) -= 0x40;
            if (((s8) reg_d1.b[0] >= 0) && ((s32) (*(u16 *)((u8 *)(reg_a6) + (2))) < 0x800)) {
                (*(u8 *)((u8 *)(reg_a6) + (0x18))) = 0U;
            }
            goto block_7;
        }
        (*(u16 *)((u8 *)(reg_a6) + (2))) += 0x18;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x8800;
        reg_tmp.w = 0;
        reg_tmp.h[0] = reg_d0.h[0];
        temp_a1 = reg_tmp.w;
        reg_tmp.w = temp_a1 + D_0028E484.w;
        reg_d0.h[0] += 0x7FFF + 0x801;
        if (reg_tmp.h[1] != 0) {
            func_0016C260();
            return;
        }
block_7:
        (*(u8 *)((u8 *)(reg_a6) + (0x1E))) -= 1;
        if ((*(u8 *)((u8 *)(reg_a6) + (0x1E))) == 0) {
            reg_d0.w = 0;
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1F)));
            reg_a0 = (u8 *)(D_00269490);
            reg_a0 += reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = *(u16 *)reg_a0;
            reg_a0 += 2;
            (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            (*(u16 *)((u8 *)(reg_a6) + (0x1C))) = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
        (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d1.h[0];
        goto block_10;
    }
block_10:
    reg_d0.w = 0;
    D_0028E408 = 0;
}
