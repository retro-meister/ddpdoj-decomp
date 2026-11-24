#include "common.h"

void func_0011BEA0(void);
void func_0011C4A0(void);
void func_0012FA50(void);
void func_0012FB00(void);
void func_00131440(void);
void func_00136600(void);
void func_001719A0(void);
void func_001719D0(void);
extern u8 death_D_0026FDA0[];
extern u8 D_0028E370;
extern u16 D_0028E3BC;
extern u16 D_0028E3C0;
extern u16 D_0028E3F0;
extern s8 D_0028E408;
extern u8 *D_0028E7FC;
extern u16 D_0028E800;
extern u16 D_0028E804;
extern u16 D_0028E80C;
extern u16 D_0028E814;
extern u16 D_0028E818;
extern u16 D_0028E81C;
extern u16 D_0028E820;
extern u16 D_0028E824;
extern u16 D_0028E828;
extern u8 death_D_00291191;
extern s8 death_D_00291195_as_s8;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00137E00(void) {
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
    func_001719D0();
    reg_a0 = death_D_0026FDA0;
    reg_a0 += D_0028E81C;
    reg_d4.w = *(u32 *)reg_a0;
    reg_d0.h[0] = 0x88;
    reg_d1.h[0] = 0;
    reg_d2.w = 5;
    reg_d3.w = 0x1B;
    func_0011C4A0();
    reg_d0.h[0] = D_0028E3F0;
    if ((reg_d0.h[0] &= 1) == 0) {
        D_0028E81C += 4;
        D_0028E81C &= 0xF;
    }
    if (D_0028E828 == 0) {
        D_0028E824 -= 1;
        if (D_0028E824 != 0) {
            goto check_end;
        }
        D_0028E828 = 2;
        death_D_00291191 = 1;
        reg_d0.w = 0;
        reg_a0 = D_0028E7FC;
        reg_a0 += D_0028E800;
        reg_d0.b[0] = *(s8 *)reg_a0;
        D_0028E804 = reg_d0.h[0];
        death_D_00291195_as_s8 = *(s8 *)(reg_a0 + 1);
        D_0028E800 += 2;
        func_00131440();
        D_0028E370 = 0;
        func_001719A0();
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d0.h[0] = D_0028E818;
        reg_d1.h[0] = D_0028E814;
        reg_d2.h[0] = 0xFF;
        reg_d3.h[0] = 0xFF;
        reg_d4.w = 1;
        func_00136600();
    }
    if ((D_0028E828 == 2) && (D_0028E370 != 0)) {
        D_0028E80C = 1;
        D_0028E828 = 1;
    }
check_end:
    if (D_0028E828 == 1) {
        D_0028E820 -= 1;
        if (D_0028E820 == 0) {
            func_0012FA50();
            func_0012FB00();
            func_0011BEA0();
            goto finished;
        }
    }
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
    D_0028E408 = 1;
    return;
finished:
    D_0028E3BC += 1;
    D_0028E80C = 0;
    if ((s16) D_0028E3BC >= 3) {
        D_0028E3BC = 0;
    }
    D_0028E3C0 = 0;
    D_0028E408 = 0;
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
