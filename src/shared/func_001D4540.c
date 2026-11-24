#include "common.h"

struct UnkDataD28E450 {
    u8 pad_00[0x88];
    s16 unk88;
};

extern struct UnkDataD28E450 *reg_a6_as_UnkDataD28E450_p;

void func_001D4540(void) {
    reg_a6_as_UnkDataD28E450_p->unk88 = 1;
}
