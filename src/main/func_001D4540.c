#include "common.h"

struct UnkDataD28E450 {
    u8 pad_00[0x88];
    s16 unk88;
};

extern struct UnkDataD28E450 *D_0028E450;

void func_001D4540(void) {
    D_0028E450->unk88 = 1;
}
