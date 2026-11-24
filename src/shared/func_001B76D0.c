#include "common.h"

typedef struct WorkRegA4 {
    u8 pad0[4];
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
} WorkRegA4;

extern WorkRegA4 *reg_a4_as_WorkRegA4_p;

void func_001B7700(s32 arg0, s32 arg1);

void func_001B76D0(void) {
    reg_a4_as_WorkRegA4_p->unk4 = 0x9050;
    reg_a4_as_WorkRegA4_p->unk6 = 0;
    reg_a4_as_WorkRegA4_p->unk8 = 1;
    reg_a4_as_WorkRegA4_p->unkA = 0xC;
    func_001B7700(1, 0x9050);
}
