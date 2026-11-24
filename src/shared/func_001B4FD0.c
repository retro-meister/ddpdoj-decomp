#include "common.h"

s32 func_001B5110();                            /* extern */
s32 func_00202500();                            /* extern */
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B4FD0(void) {
    if ((*(u8 *)((u8 *)(reg_a4) + (7))) != 0) {
        func_001B5110();
        return;
    }
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xC7)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0xC7))) = (u8) reg_d1.b[0];
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (8)));
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xC6)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0xC6))) = (u8) reg_d1.b[0];
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xC9)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0xC9))) = (u8) reg_d1.b[0];
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xC8)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0xC8))) = (u8) reg_d1.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
    if ((*(u8 *)((u8 *)(reg_a6) + (0xC7))) == reg_d0.b[0]) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (8)));
        if ((*(u8 *)((u8 *)(reg_a6) + (0xC6))) == reg_d0.b[0]) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
            if ((*(u8 *)((u8 *)(reg_a6) + (0xC9))) == reg_d0.b[0]) {
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xA)));
                if ((*(u8 *)((u8 *)(reg_a6) + (0xC8))) == reg_d0.b[0]) {
                    (*(u8 *)((u8 *)(reg_a4) + (7))) = 1U;
                }
            }
        }
    }
}
