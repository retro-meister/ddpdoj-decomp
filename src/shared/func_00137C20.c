#include "common.h"

extern s32 D_0028DE80;
extern s16 *reg_a0;
extern s16 D_002BF350[];
extern s16 D_002BF370[];
extern void func_00137BF0(void);

void func_00137C20(void) {
    *(s16 *)((u8 *)&D_0028DE80 + 8) = 0;
    reg_a0 = D_002BF370;
    *reg_a0 = 0;
    reg_a0 = D_002BF350;
    *reg_a0 = 0;
    func_00137BF0();
}
