#include "common.h"

typedef struct WorkRegA4 {
    u8 pad0[2];
    s16 unk2;
    s16 unk4;
    u8 pad6;
    u8 unk7;
} WorkRegA4;

extern WorkRegA4 *reg_a4_as_WorkRegA4_p;

void func_001B4360(void) {
    reg_a4_as_WorkRegA4_p->unk2 = 0;
    reg_a4_as_WorkRegA4_p->unk4 = 0x20;
    reg_a4_as_WorkRegA4_p->unk7 = 0;
}
