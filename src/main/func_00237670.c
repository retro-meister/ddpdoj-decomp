#include "common.h"

typedef struct {
    u8 data[0x42];
} Struct66;

s32 func_002071C0();
extern Struct66 D_006E5B90;
extern Struct66 D_006E5BE0;
extern u8 *reg_a0;

void func_00237670(void) {
    u32 temp_s0 = reg_d0.w;
    u8 *temp_s1 = reg_a0;

    D_006E5BE0 = D_006E5B90;
    reg_d0.h[0] = 0x14;
    func_002071C0();
    *(s8 *)(reg_a0 + 5) = 0;
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
}
