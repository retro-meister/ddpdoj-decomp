#include "common.h"

typedef struct WorkRegA4 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} WorkRegA4;

extern WorkRegA4 *reg_a4_as_WorkRegA4_p;
extern s16 D_0028E88C_as_s16;

void func_001F2640(s32 flag);

#ifdef DEATH_LABEL
extern s8 death_D_0029085C_as_s8;
#endif

void func_001F2620(void) {
#ifdef DEATH_LABEL
    death_D_0029085C_as_s8 = 2;
#endif
    reg_a4_as_WorkRegA4_p->unk2 = 1;
    reg_a4_as_WorkRegA4_p->unk4 = 0x80;
    D_0028E88C_as_s16 = 0;
    func_001F2640(1);
}
