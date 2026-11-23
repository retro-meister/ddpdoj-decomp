#include "common.h"

typedef struct {
    s16 h[0x21];
} SaveHeader;

extern void func_0012FAB0(void);
extern void func_00171910(void);
extern void func_001A2FA0(void);
extern void func_002071C0(void);
extern void func_0021BEA0(s32 a, s32 b, s32 c, s32 d);
extern void func_00236DB0(void);
extern void func_0023B720(u8 *arg);
extern u8 D_00269140[];
extern u16 D_0028E314;
extern u16 D_0028E318;
extern u8 D_0028E368;
extern u8 D_0028E370;
extern u16 D_0028E3C0;
extern u8 D_0028E3F8;
extern u8 D_0028ED58;
extern u8 D_0028ED5C;
extern s32 D_0028ED70;
extern u8 D_0028ED74;
extern SaveHeader D_006C58A0;
extern u16 D_006C58A4[];
extern u16 D_006C8E56[];
extern u16 D_006C8E5C[];
extern u8 D_006CB1D4[];
extern SaveHeader D_006E5BE0;
extern u16 D_006E5BEE[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00237DF0(void) {
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

    D_0028E370 = 0;
    D_0028E3F8 = 0;
    D_0028ED74 = 0;
    D_0028ED70 = 0;
    D_0028E368 = 0;
    D_0028ED5C = 1;
    D_0028ED58 = 0;
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
    D_006E5BE0 = D_006C58A0;
    *(u8 *)(reg_a5 + 3) = 1;
    *(u16 *)(reg_a5 + 10) = 0;
    if (D_006C8E56[0] == 0 && D_006C8E5C[0] != 0) {
        func_0023B720(D_006CB1D4);
    }
    if (D_0028E3C0 == 0) {
        if (D_006C58A4[0] != 0xFF) {
            D_0028E314 = 0;
            D_0028E318 = 9;
        } else {
            D_0028E318 = 0;
            D_0028E314 = 9;
        }
    }
    reg_d0.h[0] = 10;
    func_002071C0();
    *(u16 *)(reg_a0 + 4) = D_006E5BEE[0];
    func_00171910();
    func_0012FAB0();
    reg_d0.w = 0;
    reg_a0 = (u8 *)D_00269140;
    func_001A2FA0();
    func_0021BEA0(0, 0, 0, 0);
    func_00236DB0();
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
