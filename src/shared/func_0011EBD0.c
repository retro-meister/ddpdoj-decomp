#include "common.h"

extern void func_0011EB40(void);
extern u8 *reg_a6;

void func_0011EBD0(void) {
    reg_tmp.w = 0x1D84;
    (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0x14))) = 0x3520;
    reg_tmp.w = (u32) (u32)func_0011EB40;
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xC))) = 0x56;
}
