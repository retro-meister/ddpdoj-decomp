#include "common.h"

s32 func_0013BE50();                            /* extern */
s32 func_0013C300();                            /* extern */
s32 func_0013C350();                            /* extern */
s32 func_0015C090();                            /* extern */
s32 func_0015C170();                            /* extern */
extern s32 D_0026A660[];
extern u8 D_0028E350;
extern s8 D_0028E408;
extern u32 D_0028E7C0;
extern u16 D_0028E7C4;
extern s32 D_0057CC88[];
extern s32 *reg_a0;

void func_0015BFD0(void) {
    if (D_0028E7C4 != 0) {
        if (D_0028E350 == 0) {
            D_0028E7C4 -= 1;
        }
        if (D_0057CC88[0] != 0) {
            D_0028E7C4 = 0x258;
        }
        if (D_0028E7C4 != 0) {
            func_0015C090();
            return;
        }
        reg_a0 = D_0026A660;
        func_0013BE50();
        D_0028E7C0 = reg_d0.w;
        func_0015C090();
        return;
    }
    reg_d0.w = D_0028E7C0;
    func_0013C350();
    if (D_0028E408 != 0) {
        func_0015C090();
        return;
    }
    func_0013C300();
    func_0015C170();
}
