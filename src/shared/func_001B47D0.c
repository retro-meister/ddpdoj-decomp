#include "common.h"

struct WorkRegA4 {
    u8 unk0[2];
    s16 unk2;
    u8 unk4[3];
    u8 unk7;
};

extern struct WorkRegA4 *reg_a4_as_WorkRegA4_p;

void func_001B47D0(void) {
    reg_a4_as_WorkRegA4_p->unk2 = 0;
    reg_a4_as_WorkRegA4_p->unk7 = 0;
}
