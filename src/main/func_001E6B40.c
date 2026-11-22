#include "common.h"


typedef void (*Fn)();

extern u8 D_0026F240[];
extern u8 *reg_a4;

void func_001E6B40(void) {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x11)));
    (*(u8 *)((u8 *)(reg_a4) + (0x11))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0x11))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x10)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
        ((Fn)*(u32 *)((u8 *)D_0026F240 + (reg_tmp.h[0] & ~3)))();
        (*(u16 *)((u8 *)(reg_a4) + (0x12))) += 4;
        (*(u16 *)((u8 *)(reg_a4) + (0x12))) &= 0x1F;
    }
}
