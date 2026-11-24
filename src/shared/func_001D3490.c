#include "common.h"

typedef struct WorkRegA4 {
    u8 pad0[2];
    u16 unk2;
    u16 unk4;
    u16 unk6;
} WorkRegA4;

extern WorkRegA4 *reg_a4_as_WorkRegA4_p;
void func_001D34C0(s32 param0, s32 param1);

void func_001D3490(void) {
    reg_a4_as_WorkRegA4_p->unk2 = 0x40;
    reg_a4_as_WorkRegA4_p->unk4 = 0x404;
    reg_a4_as_WorkRegA4_p->unk6 = 0x17;
    func_001D34C0(0x404, 0x40);
}
