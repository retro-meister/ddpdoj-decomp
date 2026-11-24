#include "common.h"

s32 func_00123870();
s32 func_002071C0();
s32 func_002075F0();
s32 stage_load_step();
s32 func_00225630();
s32 func_002256B0();
extern s8 D_0028E350_as_s8;
extern s16 D_0028E3FC;
extern s16 D_0028E910_as_s16;
extern u16 D_0028E91C;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern u16 D_00295E38[];
extern u16 D_00295E3C[];
extern u8 *reg_a6;

void func_00122EB0(void) {
    u16 temp_a0;

    temp_a0 = D_00295E3C[0];
    if (temp_a0 != 0) {
        if (temp_a0 == 1) {
            switch (D_00295E38[0]) { case 0: break; default:
                D_00295E3C[0] = 0;
                func_00123870();
                return;
            }
            g_cd_async_busy = 1;
            D_00295E3C[0] = 2;
            D_0028E350_as_s8 = 0;
            g_cd_async_state = 0;
            func_00225630(temp_a0);
            goto block_6;
        }
block_6:
        if (D_00295E3C[0] == 2) {
            D_0028E91C = 0;
            stage_load_step(D_00295E3C[0]);
            if (D_0028E3FC == D_0028E91C) {
                D_0028E910_as_s16 = 1;
                D_00295E3C[0] = 0;
                func_002256B0(D_0028E3FC);
                reg_d0.h[0] = 0x11;
                func_002071C0();
                func_002075F0();
            }
        }
    } else {
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) += 1;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
        if ((*(u16 *)((u8 *)(reg_a6) + (0x10))) != reg_d0.h[0]) {
            func_00123870();
            return;
        }
        reg_d0.h[0] = 0xF;
        func_002071C0();
        func_002075F0();
    }
}
