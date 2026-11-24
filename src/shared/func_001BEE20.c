#include "common.h"

typedef struct WorkRegA4 {
    u8 unk0[3];
    u8 unk3;
    u16 unk4;
    u16 unk6;
    u16 unk8;
} WorkRegA4;

extern WorkRegA4 *reg_a4_as_WorkRegA4_p;

void func_001BEE50(void);

void func_001BEE20(void) {
    reg_a4_as_WorkRegA4_p->unk3 = 0;
    reg_a4_as_WorkRegA4_p->unk4 = 0;
    reg_a4_as_WorkRegA4_p->unk6 = 0;
    reg_a4_as_WorkRegA4_p->unk8 = 0x808;
    func_001BEE50();
}
