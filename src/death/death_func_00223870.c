#include "common.h"

s32 func_00124B20();
s32 func_00124D90();
s32 func_001251C0();
s32 func_00125250();
extern s8 D_0028E408;
extern u16 D_0028E89C;
extern u8 *reg_a4;
extern u8 *reg_a6;

void death_func_00223870(void) {
    s8 first_busy;
    s8 second_busy;

    if (*(u16 *)(reg_a4 + 2) != 0) {
        if (D_0028E89C != 0) {
            return;
        }
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) != 0) {
            return;
        }
        reg_d0.w = 0x18;
        func_001251C0();
        reg_d0.w = 0x19;
        func_001251C0();
    }
    reg_d0.w = 0x18;
    func_00125250();
    first_busy = D_0028E408;
    reg_d0.w = 0x19;
    func_00125250();
    second_busy = D_0028E408;
    if ((first_busy == 0) && (second_busy == 0)) {
        reg_d0.w = 0x17;
        func_00124B20();
        reg_d0.w = 0xe;
        func_00124D90();
        *(u8 *)(reg_a6 + 0x1B) = 0xC;
        *(u8 *)(reg_a6 + 0x21B) = 0xC;
        *(u16 *)reg_a4 = 0;
    }
}
