#include "common.h"

typedef struct WorkRegA4 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u8 unk6;
    u8 unk7;
} WorkRegA4;

extern WorkRegA4 *work_reg_a4;

void func_001B4900(void) {
    work_reg_a4->unk2 = 0;
    work_reg_a4->unk4 = 0x20;
    work_reg_a4->unk7 = 0;
}
