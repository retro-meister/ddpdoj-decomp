#include "common.h"

typedef struct WorkRegA4 {
    u8 pad0[3];
    u8 unk3;
    u16 unk4;
    u16 unk6;
} WorkRegA4;

extern WorkRegA4 *reg_a4;

void func_001BA2E0(void) {
    reg_a4->unk3 = 0;
    reg_a4->unk4 = 0x40;
    reg_a4->unk6 = 0x404;
}
