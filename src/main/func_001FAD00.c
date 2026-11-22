#include "common.h"

struct Unk0028E450 {
    u8 pad_00[0x66];
    u16 unk66;
    u16 unk68;
};

extern struct Unk0028E450 *D_0028E450;

void func_001FAD00(void) {
    if (D_0028E450->unk66 != work_reg_0.h[0]) {
        D_0028E450->unk66 = (u16) work_reg_0.h[0];
        D_0028E450->unk68 = 0;
    }
}
