#include "common.h"

typedef struct WorkRegA4 {
    u8 pad0[4];
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
} WorkRegA4;

extern WorkRegA4 *work_reg_a4;

void func_001B7700(s32 arg0, s32 arg1);

void func_001B76D0(void) {
    work_reg_a4->unk4 = 0x9050;
    work_reg_a4->unk6 = 0;
    work_reg_a4->unk8 = 1;
    work_reg_a4->unkA = 0xC;
    func_001B7700(1, 0x9050);
}
