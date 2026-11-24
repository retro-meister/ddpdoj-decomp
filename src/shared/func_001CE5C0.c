#include "common.h"

typedef struct WorkReg {
    u8 pad0[2];
    s16 unk2;
    s16 unk4;
    s16 unk6;
} WorkReg;

typedef struct WorkRegBC {
    u8 pad0[0xBC];
    s16 unkBC;
} WorkRegBC;

extern WorkReg *reg_a4_as_WorkReg_p;
extern WorkRegBC *reg_a6_as_WorkRegBC_p;

void func_001CE5F0(s32, s32);

void func_001CE5C0(void) {
    reg_a4_as_WorkReg_p->unk2 = 1;
    reg_a4_as_WorkReg_p->unk4 = 0x202;
    reg_a4_as_WorkReg_p->unk6 = 0xC0;
    reg_a6_as_WorkRegBC_p->unkBC = 0;
    func_001CE5F0(0x202, 1);
}
