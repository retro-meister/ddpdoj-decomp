#include "common.h"

typedef struct WorkRegA4 {
    u8 pad0[2];
    s16 unk2;
    s16 unk4;
    u8 pad6;
    u8 unk7;
} WorkRegA4;

extern WorkRegA4 *reg_a4;

void func_001B4360(void) {
    reg_a4->unk2 = 0;
    reg_a4->unk4 = 0x20;
    reg_a4->unk7 = 0;
}
