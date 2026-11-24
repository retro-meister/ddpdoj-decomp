#include "common.h"

struct Unk0028E450 {
    u8 pad_00[0x66];
    u16 unk66;
    u16 unk68;
};

extern struct Unk0028E450 *reg_a6_as_Unk0028E450_p;

void func_001FAD00(void) {
    if (reg_a6_as_Unk0028E450_p->unk66 != reg_d0.h[0]) {
        reg_a6_as_Unk0028E450_p->unk66 = (u16) reg_d0.h[0];
        reg_a6_as_Unk0028E450_p->unk68 = 0;
    }
}
