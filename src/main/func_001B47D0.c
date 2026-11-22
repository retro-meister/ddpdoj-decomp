#include "common.h"

struct WorkRegA4 {
    u8 unk0[2];
    s16 unk2;
    u8 unk4[3];
    u8 unk7;
};

extern struct WorkRegA4 *work_reg_a4;

void func_001B47D0(void) {
    work_reg_a4->unk2 = 0;
    work_reg_a4->unk7 = 0;
}
