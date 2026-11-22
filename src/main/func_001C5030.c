#include "common.h"


extern s8 D_0028E408;

s32 func_0014E290();
s32 func_0019C470();
s32 func_00201B80();
s32 func_00201C60();
s32 func_00203060();
extern u32 D_0026C610[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C5030(void) {
    u16 temp_a1;
    u16 temp_a2;

    func_00203060();
    if (D_0028E408 != 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_4:
    func_00201C60();
    func_00201B80();
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
        (*(u16 *)((u8 *)(reg_a5) + (0x20))) += 4;
        if ((*(u16 *)((u8 *)(reg_a5) + (0x20))) == 0x20) {
            func_0014E290();
            return;
        }
    }
    reg_a0 = (u8 *)(D_0026C610);
    temp_a2 = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
    reg_a0 += temp_a2;
    reg_d2.w = *(u32 *)reg_a0;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FC00;
    reg_d3.h[0] = 0x620;
    reg_d4.w = 0x17;
    func_0019C470();
}
