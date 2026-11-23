#include "common.h"

extern s8 D_0028E408;

s32 func_0012FBD0();
s32 func_00135120();
s32 func_001ACBA0();
s32 func_001ACC60();
s32 func_002071C0();
extern u16 D_0028E3C0;
extern u8 D_0028E8B4;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00135640(void) {
    u8 temp_a0;

    func_0012FBD0();
    func_00135120();
    if (D_0028E3C0 == 0) {
        if ((*(u8 *)((u8 *)(reg_a6) + (0x16))) == 0) {
            func_001ACBA0();
            if (D_0028E408 == 0) {
                D_0028E8B4 |= 1;
            }
        } else {
            func_001ACC60();
            if (D_0028E408 == 0) {
                D_0028E8B4 |= 2;
            }
        }
        reg_d0.h[0] = 0xD;
        func_002071C0();
        (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_d0.h[0];
        temp_a0 = (*(u8 *)((u8 *)(reg_a6) + (0x16)));
        (*(u8 *)((u8 *)(reg_a0) + (6))) = temp_a0;
        reg_d0.h[0] = 0xB;
        func_002071C0();
        (*(u16 *)((u8 *)(reg_a6) + (0x1C))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) reg_d0.h[0];
        (*(u8 *)((u8 *)(reg_a0) + (6))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x16)));
    }
    (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (2))) = 0;
}
