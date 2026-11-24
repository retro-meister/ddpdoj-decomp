#include "common.h"

extern u32 D_0028DEA4;
extern u32 D_0028DEA8;
extern s32 D_0028DEB0;
extern void *D_0028DEB4;
extern s8 D_0028E408;
extern u16 D_0028E496;
extern u16 D_0028E49A;
extern u16 D_0028E49E;
extern u8 *reg_a0;
extern s32 reg_a1;

void func_00129B70(void) {
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) D_0028E49E;
    (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) reg_d3.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) D_0028E49A;
    (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) reg_d4.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x24))) = (u16) D_0028E496;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_d5.h[0];
    D_0028E408 = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1 = D_0028DEB0;
}
