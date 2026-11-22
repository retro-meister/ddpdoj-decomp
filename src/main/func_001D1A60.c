#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_001713C0();
s32 func_001D1C00();
extern u8 D_0026D5C0[];
extern u8 D_0026D5E0[];
extern u8 D_0026D600[];
extern u32 D_0028DC10;
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D1A60(void) {
    s32 temp_a0_2;
    u16 temp_a0;

    reg_a0 = D_0026D600;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1C))) = temp_a0;
    reg_a0 = D_0026D5E0;
    reg_d0.w = ((u32) D_0028DC10 >> 1) - 1;
    func_0014E300();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x37)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) += reg_d0.b[0];
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a0_2 = reg_d0.h[0] & ~3;
    reg_a0 = *(u8 **)((u8 *)D_0026D5C0 + temp_a0_2);
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a0) + (1)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1E))) = (u8) (*(u8 *)((u8 *)(reg_a0) + (0)));
    reg_a0 += 2;
    (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a0) + (1)));
    (*(u8 *)((u8 *)(reg_a5) + (0x24))) = (u8) (*(u8 *)((u8 *)(reg_a0) + (0)));
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a5) + (0x30))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a6) + (0x38))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0)));
    if (D_0028E910 == 0) {
        func_001D1C00();
        return;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x23))) = 0xDU;
    (*(u16 *)((u8 *)(reg_a5) + (0x30))) = 1U;
    func_001D1C00();
}
