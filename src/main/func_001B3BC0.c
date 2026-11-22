#include "common.h"

typedef struct WorkRegA4 {
    u8 pad0[2];
    u16 unk2;
    u8 pad4[3];
    u8 unk7;
} WorkRegA4;

extern WorkRegA4 *work_reg_a4;

void func_001B3BC0(void) {
    work_reg_a4->unk2 = 0;
    work_reg_a4->unk7 = 0;
}
