#include "common.h"

s32 func_001A5A80();
s32 func_001AEA80();
s32 func_002075F0();
extern u8 D_0028E370;
extern s16 D_0028E598;
extern u16 D_0028E91C;
extern u8 D_0028ED7C;
extern u8 *reg_a5;

void func_0014BE30(void) {
    switch (reg_a5[3]) {
    case 0:
        goto block_1;
    }
    if (reg_a5[3] == 2) goto block_2;
    func_001AEA80();
    if (D_0028ED7C != 2) goto next_1;
    if (D_0028E91C != 0) goto next_1;
    if (D_0028E370 == 0) return;
next_1:
    func_001A5A80();
    return;
block_1:
    reg_a5[3] = 1;
    D_0028E598 = 1;
    return;
block_2:
    D_0028E598 = 0;
    func_002075F0();
}
