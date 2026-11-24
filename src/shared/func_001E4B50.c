#include "common.h"

typedef struct WorkRegA4 {
    u8 pad0[3];
    u8 flag3;
    s16 field4;
    s16 field6;
} WorkRegA4;

extern WorkRegA4 *reg_a4_as_WorkRegA4_p;

void func_001E4B70(void);

void func_001E4B50(void) {
    reg_a4_as_WorkRegA4_p->flag3 = 0;
    reg_a4_as_WorkRegA4_p->field4 = 0x20;
    reg_a4_as_WorkRegA4_p->field6 = 0;
    func_001E4B70();
}
