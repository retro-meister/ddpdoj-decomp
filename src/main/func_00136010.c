#include "common.h"

s32 func_001353E0();
s32 func_001AAEE0();
s32 func_001AB070();
s32 func_001AC840();
s32 func_002071C0();
extern u16 D_0028E910;
extern u16 D_0028E934;
extern u16 D_0028E938;
extern u8 D_002BF390[];
extern u8 D_002BF3B4[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00136010(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a2 = (u8 *)D_002BF390;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    reg_a3 = (u8 *)D_002BF3B4;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    if ((s32) save_d0 >= 0) {
        (*(u16 *)((u8 *)(reg_a2) + (0x10))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a2) + (0x12))) = (u16) reg_d0.h[0];
    }
    if ((s32) reg_d1.w >= 0) {
        (*(u16 *)((u8 *)(reg_a3) + (0x10))) = (u16) reg_d1.h[1];
        (*(u16 *)((u8 *)(reg_a3) + (0x12))) = (u16) reg_d1.h[0];
    }
    reg_d0.h[0] = D_0028E938;
    if (reg_d0.h[0] != 0xFF) {
        reg_d0.w = 0;
        reg_d1.h[0] = 4;
        func_001353E0();
        if (D_0028E910 == 0) {
            func_001AAEE0();
        }
    } else {
        reg_d0.h[0] = 0xB;
        func_002071C0();
        (*(u16 *)((u8 *)(reg_a2) + (0x1C))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a2) + (0x1E))) = (u16) reg_d0.h[0];
        (*(s8 *)((u8 *)(reg_a0) + (6))) = 0;
    }
    reg_d0.h[0] = D_0028E934;
    if (reg_d0.h[0] != 0xFF) {
        reg_d0.w = 1;
        reg_d1.h[0] = 4;
        func_001353E0();
        if (D_0028E910 == 0) {
            func_001AB070();
        }
    } else {
        reg_d0.h[0] = 0xB;
        func_002071C0();
        (*(u16 *)((u8 *)(reg_a3) + (0x1C))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a3) + (0x1E))) = (u16) reg_d0.h[0];
        (*(s8 *)((u8 *)(reg_a0) + (6))) = 1;
    }
    func_001AC840();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}
