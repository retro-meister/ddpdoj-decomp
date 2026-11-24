#include "common.h"

extern s32 D_0028DE80_as_s32;
extern s16 *reg_a0_as_s16_p;
extern s16 D_002BF350[];
extern s16 D_002BF370[];
extern void func_00137BF0(void);

void func_00137C20(void) {
    *(s16 *)((u8 *)&D_0028DE80_as_s32 + 8) = 0;
    reg_a0_as_s16_p = D_002BF370;
    *reg_a0_as_s16_p = 0;
    reg_a0_as_s16_p = D_002BF350;
    *reg_a0_as_s16_p = 0;
    func_00137BF0();
}
