#include "common.h"

s32 func_0012FAB0();                            /* extern */
s32 func_00137C50();                            /* extern */
s32 func_00137C90();                            /* extern */
s32 func_00137E00();                            /* extern */
s32 func_0013B190();                            /* extern */
s32 func_0018DE90();                            /* extern */
s32 func_001A2FA0();                            /* extern */
s32 func_00206D70();                            /* extern */
s32 func_002071C0();                            /* extern */
s32 func_00219570();                            /* extern */
s32 printf(s32 *);                          /* extern */
extern s32 D_00269140_as_s32_a[];
extern s32 D_00275860[];
extern s8 D_0028E408;
extern s32 *reg_a0_as_s32_p;
extern u8 *reg_a5;

void func_00169320(void) {
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) == 0) {
        (*(u8 *)((u8 *)(reg_a5) + (2))) = 1U;
        func_00137C90();
        func_0012FAB0();
        (*(s16 *)((u8 *)(reg_a5) + (4))) = 0;
        reg_a0_as_s32_p = D_00269140_as_s32_a;
        reg_d0.w = 0;
        func_001A2FA0();
    }
    func_00137E00();
    if (D_0028E408 == 0) {
        printf(D_00275860);
        func_00206D70();
        func_0013B190();
        func_00137C50();
        func_00219570();
        func_0012FAB0();
        reg_d0.h[0] = 8;
        func_002071C0();
        (*(s16 *)((u8 *)(reg_a0_as_s32_p) + (4))) = 2;
        func_0018DE90();
    }
}
