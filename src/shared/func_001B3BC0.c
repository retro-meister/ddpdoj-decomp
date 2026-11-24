#include "common.h"

typedef struct WorkRegA4 {
    u8 pad0[2];
    u16 unk2;
    u8 pad4[3];
    u8 unk7;
} WorkRegA4;

extern WorkRegA4 *reg_a4_as_WorkRegA4_p;

void func_001B3BC0(void) {
    reg_a4_as_WorkRegA4_p->unk2 = 0;
    reg_a4_as_WorkRegA4_p->unk7 = 0;
}
