#include "common.h"

typedef struct WorkRegA4 {
    u8 unk0[3];
    u8 unk3;
    u16 unk4;
    u16 unk6;
    u16 unk8;
} WorkRegA4;

extern WorkRegA4 *work_reg_a4;

void func_001BEE50(void);

void func_001BEE20(void) {
    work_reg_a4->unk3 = 0;
    work_reg_a4->unk4 = 0;
    work_reg_a4->unk6 = 0;
    work_reg_a4->unk8 = 0x808;
    func_001BEE50();
}
