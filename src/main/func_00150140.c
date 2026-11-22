#include "common.h"

s32 func_0014E370();
s32 func_0014E7E0();
s32 func_001A3020();
extern u8 D_0025FB30[];
extern u8 D_0026E800[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00150140(void) {
    reg_a0 = D_0026E800;
    func_0014E370();
    reg_d0.h[0] = 0x13;
    reg_a0 = D_0025FB30;
    func_001A3020();
    (*(s16 *)((u8 *)(reg_a5) + (0x18))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x1A))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x1C))) = 0x120;
    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 0;
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (2))) += 0x200;
    }
}
