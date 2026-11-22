#include "common.h"

s32 func_00124F50(s32, s32, s32);   /* extern */
s32 func_001251C0();                            /* extern */
s32 func_001C9740();                            /* extern */
extern u8 *reg_a4;

void func_001C96E0(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x10;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x200A;
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0x101;
    reg_d0.w = 0xA;
    func_00124F50(0x101, 0x200A, 0x10);
    reg_d0.w = 0xF;
    func_001251C0();
    func_001C9740();
}
