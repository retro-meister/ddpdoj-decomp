#include "common.h"

typedef struct WorkRegA4 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u8 unk6;
    u8 unk7;
} WorkRegA4;

extern WorkRegA4 *reg_a4;

void func_001B4900(void) {
    reg_a4->unk2 = 0;
    reg_a4->unk4 = 0x20;
    reg_a4->unk7 = 0;
}
