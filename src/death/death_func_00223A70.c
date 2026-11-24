#include "common.h"

s32 func_00124B20();
s32 func_00124D90();
s32 func_001251C0();
s32 func_00125250();
extern s8 D_0028E408;
extern u16 D_0028E89C;
extern u8 *reg_a4;
extern u8 *reg_a6;

void death_func_00223A70(void) {
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
        reg_d0.w = 0x12;
        func_001251C0();
        reg_d0.w = 0x13;
        func_001251C0();
        *(u8 *)(reg_a6 + 0x1B) = 4;
        *(u8 *)(reg_a6 + 0x21B) = 4;
    }
    reg_d0.w = 0x12;
    func_00125250();
    first_busy = D_0028E408;
    reg_d0.w = 0x12;
    func_00125250();
    second_busy = D_0028E408;
    if ((first_busy == 0) && (second_busy == 0)) {
        reg_d0.w = 0x16;
        func_00124B20();
        reg_d0.w = 0xd;
        func_00124D90();
        *(u16 *)reg_a4 = 0;
    }
}
