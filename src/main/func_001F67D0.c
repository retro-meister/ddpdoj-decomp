#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern u8 D_00265170[];
extern u8 D_00265180[];
extern u16 D_0028E8A8;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_001F67D0(void) {
    reg_a0 = D_00265180;
    func_0014E370();
    reg_a0 = D_00265170;
    reg_d0.w = 6;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        (*(u16 *)((u8 *)(reg_a5) + (0x22))) = (u16) D_0028E8A8;
        if (D_0028E8A8 == 0xE6) {
            (*(s8 *)((u8 *)(reg_a5) + (0x19))) = 0x60;
        }
        if (D_0028E8A8 == 0xE4) {
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = 0xF0;
        }
        if (D_0028E8A8 == 0x108) {
            (*(s8 *)((u8 *)(reg_a5) + (0x19))) = 0x40;
        }
        if (D_0028E8A8 == 0x106) {
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = 0xF0;
        }
        if (D_0028E8A8 == 0x116) {
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = 0x80;
        }
    }
}
