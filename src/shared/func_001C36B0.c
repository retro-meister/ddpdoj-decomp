#include "common.h"

s32 func_00171400();                            /* extern */
s32 func_001C3730();                            /* extern */
s32 func_00202730(s32, s32);            /* extern */
extern s8 D_0028E408;
extern u8 *reg_a4;

void func_001C36B0(void) {
    func_00171400();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0x10))) = 8;
    (*(s16 *)((u8 *)(reg_a4) + (0x14))) = 2;
    (*(u8 *)((u8 *)(reg_a4) + (0x13))) = 0x80U;
    func_00202730(2, 8);
    if (D_0028E408 != 0) {
        func_001C3730();
        return;
    }
    (*(u8 *)((u8 *)(reg_a4) + (0x13))) = (u8) reg_d1.b[0];
    func_001C3730();
}
