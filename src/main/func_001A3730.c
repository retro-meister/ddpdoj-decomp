#include "common.h"

typedef void (*Fn)();

s32 func_001A34C0();
s32 func_001A36E0();
extern u8 D_0026B2A0[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001A3730(void) {
    if ((*(u8 *)((u8 *)(reg_a5) + (3))) == 0) {
        func_001A36E0();
        return;
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
    func_001A34C0();
    if ((*(u16 *)((u8 *)(reg_a4) + (0))) != 0) {
        (*(u16 *)((u8 *)(reg_a4) + (0))) = 0U;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
        if ((*(u16 *)((u8 *)(reg_a5) + (4))) != reg_d0.h[0]) {
            (*(s8 *)((u8 *)(reg_a5) + (2))) = 0;
            (*(u16 *)((u8 *)(reg_a5) + (4))) = (u16) reg_d0.h[0];
        }
    }
    reg_a0 = (u8 *)D_0026B2A0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (4)));
    jtbl_0028E3F4 = *(Fn *)reg_a0;
    jtbl_0028E3F4();
}
