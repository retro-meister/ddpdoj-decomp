#include "common.h"

extern void func_0012FAB0(void);
extern void func_00171910(void);
extern void func_001A2FA0(void);
extern void func_002071C0(void);
extern u8 D_00269140[];
extern u8 D_0028DE40[];
extern u8 D_0028DE44[];
extern u8 D_0028E290;
extern u8 D_0028E368;
extern u8 D_0028E370;
extern u8 D_0028E3F8_as_u8;
extern u8 D_0028E7B4;
extern u16 D_00684C80[];
#ifdef DEATH_LABEL
extern void func_0022B620(void);
extern void printf(const char *, ...);
extern u8 death_D_00290DC0;
extern u8 death_D_00290DBC;
extern u8 death_D_0029085C;
extern u8 death_D_00290850;
extern u32 death_D_00290DB8;
extern u32 death_D_00290DB4;
extern u16 D_0028E614;
extern u16 D_0028E610;
extern u16 D_0028E910;
#endif
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0022BFD0(void) {
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
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
#ifdef DEATH_LABEL
    D_0028E290 = 2;
    D_0028E910 = 0;
    D_00684C80[6] = 0;
    D_00684C80[4] = 3;
    D_00684C80[5] = 1;
    D_00684C80[7] = 0;
    D_00684C80[8] = 3;
    if (death_D_00290DC0 == 0) {
        if (D_00684C80[9] == 2) {
            D_00684C80[7] = 3;
        }
        if (D_00684C80[9] == 4) {
            D_00684C80[7] = 0;
        }
        if (D_00684C80[9] == 6) {
            D_00684C80[7] = 1;
        }
    } else {
        D_00684C80[7] = 3;
    }
    D_00684C80[10] = 0;
    death_D_0029085C = 0;
    death_D_00290850 = 0;
    death_D_00290DBC = 0;
    D_0028E370 = 0;
    D_0028E3F8_as_u8 = 0;
    D_0028E368 = 0;
    if (death_D_00290DC0 != 0) {
        func_0022B620();
        reg_d0.h[0] = 10;
        death_D_00290DB8 = D_0028E614;
        death_D_00290DB4 = D_0028E610;
        func_002071C0();
        *(u16 *)(reg_a0 + 4) = D_00684C80[6];
    }
    func_00171910();
    printf("death round[%d]\n", death_D_00290DC0);
#else
    D_0028E290 = 2;
    D_00684C80[0] = 0xFF;
    D_00684C80[1] = 0xFF;
    D_00684C80[2] = 0xFF;
    D_00684C80[3] = 0xFF;
    if (D_0028E7B4 & 1) {
        D_00684C80[0] = D_0028DE40[0];
        D_00684C80[1] = D_0028DE44[0];
    } else {
        D_00684C80[2] = D_0028DE40[0];
        D_00684C80[3] = D_0028DE44[0];
    }
    D_00684C80[6] = 0;
    D_00684C80[4] = 3;
    D_0028E370 = 0;
    D_0028E3F8_as_u8 = 0;
    D_00684C80[5] = 1;
    D_00684C80[8] = 3;
    reg_d0.h[0] = 10;
    D_00684C80[7] = 0;
    D_0028E368 = 0;
    D_00684C80[10] = 0;
    func_002071C0();
    *(u16 *)(reg_a0 + 4) = D_00684C80[6];
    func_00171910();
#endif
    func_0012FAB0();
    reg_d0.w = 0;
    reg_a0 = (u8 *)D_00269140;
    func_001A2FA0();
    *(u8 *)(reg_a5 + 3) = 1;
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
