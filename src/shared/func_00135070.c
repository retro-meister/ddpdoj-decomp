#include "common.h"

s32 func_00128660();                            /* extern */
s32 func_00135010();                            /* extern */
s32 func_001368C0();                            /* extern */
s32 func_00139EB0();                            /* extern */
s32 func_0014D260();                            /* extern */
s32 func_0016AAB0();                            /* extern */
s32 func_001B82D0();                            /* extern */
s32 func_002071C0();                            /* extern */
s32 func_00209E60();                            /* extern */
s32 func_002114A0();                            /* extern */
extern u16 D_0028E4AA;
extern u32 D_0028E84C_as_u32;
extern u8 *reg_a0;

void func_00135070(void) {
    func_00135010();
    func_0014D260();
    func_00139EB0();
    func_001B82D0();
    func_002114A0();
    func_001368C0();
    func_00209E60();
    func_0016AAB0();
    func_00128660();
    reg_d0.h[0] = 1;
    func_002071C0();
    reg_tmp.h[0] = D_0028E4AA;
    D_0028E4AA = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    D_0028E84C_as_u32 = reg_d0.w;
    (*(s16 *)((u8 *)(reg_a0) + (6))) = 0;
}
