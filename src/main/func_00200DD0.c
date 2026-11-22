#include "common.h"

s32 func_0013BE50();
s32 func_0013C300();
s32 func_0013C350();
s32 func_0018DED0();
s32 func_00200A70();
s32 func_00200D30();
s32 func_00200D60();
extern u8 D_0024E090[];
extern u8 D_0028DE80;
extern s8 D_0028E408;
extern u16 D_0028E4AA;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_00200DD0() {
    u16 temp_a0;
    u8 temp_v1;

    temp_v1 = (*(u8 *)((u8 *)(reg_a5) + (3)));
    if (temp_v1 == 0) {
        func_00200D60();
        return;
    }
    if (temp_v1 == 2) {
        func_00200D30();
        return;
    }
    func_00200A70();
    if (((*(u16 *)((u8 *)(reg_a5) + (4))) == 0) && ((*(u16 *)((u8 *)(&D_0028DE80) + (4))) == 0)) {
        (*(u16 *)((u8 *)(reg_a5) + (6))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a5) + (6))) == 0) {
            (*(u16 *)((u8 *)(reg_a5) + (4))) = 1U;
            reg_a0 = D_0024E090;
            func_0013BE50();
            (*(u16 *)((u8 *)(reg_a5) + (8))) = (u16) D_0028E4AA;
            (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_d0.h[0];
            reg_d1.w = 0;
            func_0018DED0();
        }
    }
    temp_a0 = (*(u16 *)((u8 *)(reg_a5) + (4)));
    if (temp_a0 == 1) {
        D_0028E4AA = (*(u16 *)((u8 *)(reg_a5) + (8)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0xA)));
        func_0013C350();
        if (D_0028E408 == 0) {
            func_0013C300();
            (*(u8 *)((u8 *)(reg_a5) + (3))) = 2U;
        }
    }
}
