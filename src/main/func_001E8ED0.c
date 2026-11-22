#include "common.h"

typedef struct WorkReg {
    s16 unk0;
    s16 unk2;
} WorkReg;

extern WorkReg *work_reg_a4;
extern void *D_0028E450;
extern void func_001E8EF0(void);

void func_001E8ED0(void) {
    work_reg_a4->unk2 = 1;
    *(s16 *)((u8 *)D_0028E450 + 0x132) = 0;
    func_001E8EF0();
}
