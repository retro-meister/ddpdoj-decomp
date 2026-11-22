#include "common.h"

typedef struct WorkRegA4 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} WorkRegA4;

extern WorkRegA4 *work_reg_a4;
extern s16 D_0028E88C;

void func_001F2640(s32 flag);

void func_001F2620(void) {
    work_reg_a4->unk2 = 1;
    work_reg_a4->unk4 = 0x80;
    D_0028E88C = 0;
    func_001F2640(1);
}
