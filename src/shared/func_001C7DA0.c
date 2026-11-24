#include "common.h"


typedef void (*Fn)();

extern u8 D_0026C6C0[];
s32 func_00124B20();
s32 func_00124F00();
s32 func_001CBA00();
extern u8 D_0026C680[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C7DA0(void) {
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        reg_a1 = D_0026C680;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        func_001CBA00();
        (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
        (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
            reg_a0 = D_0026C6C0;
            reg_a0 += (*(u16 *)((u8 *)(reg_a4) + (0x14)));
            reg_a0 = *(u8 **)reg_a0;
            jtbl_0028E3F4 = (Fn)(reg_a0);
            jtbl_0028E3F4();
            (*(u16 *)((u8 *)(reg_a4) + (0x14))) += 4;
            (*(u16 *)((u8 *)(reg_a4) + (8))) &= 0x1F;
        }
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            reg_d0.w = 2;
            func_00124F00();
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
            reg_d0.w = 4;
            func_00124B20();
        }
    }
}
