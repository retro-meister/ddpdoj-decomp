#include "common.h"

s32 func_0012FBD0();
s32 func_00138A00();
s32 func_001AC3A0();
s32 func_001AC5F0();
s32 func_002071C0();
extern s16 D_0028E028_as_s16;
extern s16 D_0028E02C_as_s16;
extern s16 D_0028E030_as_s16;
extern s16 D_0028E034_as_s16;
extern s16 D_0028E038_as_s16;
extern s16 D_0028E03C_as_s16;
extern s16 D_0028E89C_as_s16;
extern u8 D_0028ED80;
extern u16 D_006E5C06[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001354C0(void) {
    u16 var_a0;

    func_0012FBD0();
    (*(u16 *)((u8 *)(reg_a6) + (0x18))) = 0U;
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = 0U;
    D_0028E89C_as_s16 = 0x78;
    func_00138A00();
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (8)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    reg_a0 = (u8 *)reg_tmp.w;
    (*(u16 *)((u8 *)(reg_a0) + (0))) -= 1;
    var_a0 = D_0028ED80;
    if ((var_a0 == 1) && ((s16) (*(u16 *)((u8 *)(reg_a0) + (0))) < 0)) {
        var_a0 = D_006E5C06[0];
        if (var_a0 == 0x14) {
            (*(u16 *)((u8 *)(reg_a0) + (0))) = 0U;
        }
    }
    if ((s16) (*(u16 *)((u8 *)(reg_a0) + (0))) < 0) {
        if ((*(u8 *)((u8 *)(reg_a6) + (0x16))) == 0) {
            D_0028E03C_as_s16 = 0;
            D_0028E034_as_s16 = 1;
            D_0028E02C_as_s16 = 0;
        } else {
            D_0028E038_as_s16 = 0;
            D_0028E030_as_s16 = 1;
            D_0028E028_as_s16 = 0;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0))) = 2;
    } else {
        if ((*(u8 *)((u8 *)(reg_a6) + (0x16))) == 0) {
            func_001AC3A0();
        } else {
            func_001AC5F0();
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
        func_002071C0();
        (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) reg_d0.h[0];
        (*(s8 *)((u8 *)(reg_a0) + (7))) = 0;
        (*(u8 *)((u8 *)(reg_a0) + (6))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x16)));
        (*(u16 *)((u8 *)(reg_a0) + (8))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0xC)));
        (*(u16 *)((u8 *)(reg_a0) + (0xA))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0xE)));
        (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
    }
    (*(s16 *)((u8 *)(reg_a6) + (2))) = 0;
}
