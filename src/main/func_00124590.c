#include "common.h"

typedef void (*Fn)();

extern s8 D_0028E408;

s32 func_00124700();
s32 func_00125470();
extern u16 D_0028E3EC;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u8 D_0028E855;
extern u16 D_0028E8A0;
extern s16 D_0028E908;
extern s32 D_00295E9C[];
extern u8 D_00295EA0[];
extern u16 D_002962DE[];
extern u8 *jtbl_0028E3F4;
extern u8 *reg_a3;
extern u8 *reg_a4;

void func_00124590(void) {
    u32 temp_s0;
    u8 *temp_s1;
    u32 temp_v0;

    D_0028E408 = 0;
    if (D_002962DE[0] != 0) {
        D_0028E408 = 1;
        return;
    }
    if (D_0028E8A0 == 0) {
        func_00124700();
        if (!(D_0028E855 & 0x40) && (D_0028E855 & 0x10)) {
            reg_d0.h[0] = D_0028E5FC;
            temp_v0 = reg_d0.h[0] | D_0028E5F8;
            reg_d0.h[0] = temp_v0;
            if ((temp_v0 & 0xFFFF) && (0 <= D_0028E908) && (D_0028E3EC != 0)) {
                func_00124700();
            }
        }
    }
    if (D_00295E9C[0] != 0) {
        reg_a4 = (u8 *)D_00295EA0;
        reg_d7.h[0] = 0x13;
        do {
            temp_s1 = (u8 *)(reg_a4);
            if ((0 > (s64)*(s16 *)((u8 *)(temp_s1) + (0))) && ((*(u8 *)((u8 *)(temp_s1) + (0))) & 1)) {
                reg_tmp.h[1] = (*(u16 *)((u8 *)(temp_s1) + (2)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(temp_s1) + (4)));
                reg_a3 = (u8 *)reg_tmp.w;
                jtbl_0028E3F4 = reg_a3;
                temp_s0 = reg_d7.w;
                ((Fn)jtbl_0028E3F4)();
                reg_a4 = temp_s1;
                reg_d7.w = temp_s0;
            }
            reg_a4 += 8;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    func_00125470();
    D_0028E408 = 0;
}
