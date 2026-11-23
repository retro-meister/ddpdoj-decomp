#include "common.h"

extern void func_00136600(void);
extern u8 D_0028E370;
extern u16 D_00684C80[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_0022C450(void) {
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

    save_d0 = reg_d0.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_d1 = reg_d1.w;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_d2 = reg_d2.w;
    save_a4 = reg_a4;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_a5 = reg_a5;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.h[0] = D_00684C80[0];
    reg_d1.h[0] = D_00684C80[1];
    reg_d2.w = 0;
    D_0028E370 = 0;
    reg_d3.w = 0;
    reg_d4.w = 1;
    reg_d2.h[0] = D_00684C80[2];
    reg_d3.h[0] = D_00684C80[3];
    func_00136600();
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
}
