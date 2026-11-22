#include "common.h"

extern s8 D_0028E408;

s32 func_00124B20();
s32 func_00124D80();
s32 func_00124F50();
s32 func_00125120();
s32 func_001251C0();
s32 func_00125250();
s32 func_002010A0();
s32 func_002011D0();
s32 func_00202140();
s32 func_00202500();
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BA4D0(void) {
    u8 temp_a0;
    u8 temp_a0_2;

    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        func_00124D80();
        if (reg_d0.h[0] == 7) {
            reg_d0.w = 7;
            func_00125120();
            reg_d0.w = 0x14;
            func_00124F50();
            (*(u16 *)((u8 *)(reg_a4) + (6))) = 1U;
            reg_d1.w = 0x25;
            func_002011D0();
            if (reg_d0.b[0] != 0) {
                reg_d1.w = 0x1C;
                (*(u16 *)((u8 *)(reg_a4) + (6))) *= 0xFFFF;
            }
            func_002010A0();
            reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
            reg_d1.b[0] += reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a4) + (2))) = (u8) reg_d1.b[0];
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
        }
    }
    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0 == 2) {
        if ((*(u8 *)((u8 *)(reg_a4) + (0x11))) != 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
            (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
                func_00202140();
                if (D_0028E408 == 0) {
                    if ((s8) reg_d1.b[0] > 0x27) {
                        reg_d1.w = 0x27;
                    }
                    if ((s8) reg_d1.b[0] < 0x19) {
                        reg_d1.w = 0x19;
                    }
                    reg_d0.w = 0;
                    reg_d1.h[0] = (u16) reg_d1.b[0];
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xAC)));
                    reg_d0.h[0] += 0x20;
                    func_00202500();
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d0.h[0] = (u16) reg_d0.b[0];
                    reg_d0.h[0] -= 0x20;
                    (*(u16 *)((u8 *)(reg_a6) + (0xAC))) = (u16) reg_d0.h[0];
                }
            }
        }
        reg_d0.w = 0xD;
        func_00125250();
        if (D_0028E408 == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
            (*(u8 *)((u8 *)(reg_a4) + (0xB))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (0xA))) -= 8;
                (*(u8 *)((u8 *)(reg_a4) + (0xB))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xA)));
                reg_d0.w = 0xD;
                func_001251C0();
                (*(u8 *)((u8 *)(reg_a0) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (9)));
                (*(u8 *)((u8 *)(reg_a0) + (4))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x10)));
                (*(u16 *)((u8 *)(reg_a0) + (6))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0xE)));
                (*(u8 *)((u8 *)(reg_a4) + (9))) += 4;
                (*(u8 *)((u8 *)(reg_a4) + (0x10))) += 1;
                (*(u16 *)((u8 *)(reg_a4) + (0xE))) += 2;
                (*(u8 *)((u8 *)(reg_a4) + (0x11))) = 1U;
                (*(u16 *)((u8 *)(reg_a4) + (6))) *= 0xFFFF;
                (*(u16 *)((u8 *)(reg_a4) + (0xC))) -= 1;
                if ((s16) (*(u16 *)((u8 *)(reg_a4) + (0xC))) == 0) {
                    (*(u16 *)((u8 *)(reg_a4) + (0x12))) = 0x50U;
                    (*(u8 *)((u8 *)(reg_a4) + (3))) = 3U;
                }
            }
        }
    }
    temp_a0_2 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_2 == 3) {
        reg_d0.w = 0xD;
        func_00125250();
        if (D_0028E408 == 0) {
            (*(u16 *)((u8 *)(reg_a4) + (0x12))) -= 1;
            if ((s16) (*(u16 *)((u8 *)(reg_a4) + (0x12))) == 0) {
                reg_d0.w = 0xF;
                func_00124F50();
                reg_d0.w = 0x14;
                func_00125120();
                reg_d0.w = 7;
                func_00124F50();
                reg_d0.w = 2;
                func_00124B20();
                (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
            }
        }
    }
}
