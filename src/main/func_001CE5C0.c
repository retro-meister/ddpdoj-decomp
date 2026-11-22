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

extern WorkReg *work_reg_a4;
extern WorkRegBC *D_0028E450;

void func_001CE5F0(s32, s32);

void func_001CE5C0(void) {
    work_reg_a4->unk2 = 1;
    work_reg_a4->unk4 = 0x202;
    work_reg_a4->unk6 = 0xC0;
    D_0028E450->unkBC = 0;
    func_001CE5F0(0x202, 1);
}
