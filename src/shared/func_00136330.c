#include "common.h"

s32 func_00136010();
s32 func_00138110();
s32 func_001A2FA0();
s32 func_001A3300();
s32 func_002071C0();
extern u8 D_00269140[];
extern u16 D_0028E4AA;
extern u32 D_0028E848_as_u32;
extern u32 D_0028E84C_as_u32;
extern u16 D_0028E940;
extern u16 D_0028E944;
extern u8 *reg_a0;

void func_00136330() {
    u16 temp_a0;
    u16 temp_a1;
    u32 temp_a0_2;

    reg_d0.h[0] = 5;
    func_002071C0();
    temp_a0 = D_0028E4AA;
    reg_tmp.h[0] = temp_a0;
    D_0028E4AA = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    D_0028E848_as_u32 = reg_d0.w;
    reg_d0.h[0] = 1;
    func_002071C0();
    temp_a1 = D_0028E4AA;
    reg_tmp.h[0] = temp_a1;
    D_0028E4AA = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    temp_a0_2 = reg_d0.w;
    D_0028E84C_as_u32 = temp_a0_2;
    (*(u16 *)((u8 *)(reg_a0) + (6))) = (u16) D_0028E944;
    if (D_0028E940 != 0) {
        reg_d0.w = 0x10000E00;
        reg_d1.w = 0x10002A00;
        func_00136010();
        D_0028E940 = 0;
    }
    reg_d0.w = 0;
    reg_a0 = D_00269140;
    func_001A2FA0();
    func_001A3300();
    func_00138110();
}
