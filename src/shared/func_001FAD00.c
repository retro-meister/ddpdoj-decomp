#include "common.h"

struct Unk0028E450 {
    u8 pad_00[0x66];
    u16 unk66;
    u16 unk68;
};

extern struct Unk0028E450 *reg_a6;

void func_001FAD00(void) {
    if (reg_a6->unk66 != reg_d0.h[0]) {
        reg_a6->unk66 = (u16) reg_d0.h[0];
        reg_a6->unk68 = 0;
    }
}
