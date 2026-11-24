#include "common.h"

typedef struct WorkReg {
    s16 unk0;
    s16 unk2;
} WorkReg;

extern WorkReg *reg_a4_as_WorkReg_p;
extern void *reg_a6_as_void_p;
extern void func_001E8EF0(void);

void func_001E8ED0(void) {
    reg_a4_as_WorkReg_p->unk2 = 1;
    *(s16 *)((u8 *)reg_a6_as_void_p + 0x132) = 0;
    func_001E8EF0();
}
