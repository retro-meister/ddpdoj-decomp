#include "common.h"

extern s8 D_0028E408;

s32 func_00130270();
s32 func_001303A0();
s32 func_001384E0();
s32 func_00138650();
s32 func_00138750();
s32 func_001460A0();
s32 func_00146350();
s32 func_00146470();
s32 func_0016A8B0();
s32 func_0016A8C0();
s32 func_001B0E60();
s32 func_001B1080();
s32 func_001B1920();
s32 func_00204800();
s32 func_0020ED40();
s32 func_0020EE20();
#ifdef DEATH_LABEL
s32 func_0012FAB0();
s32 func_0018DD40();
s32 func_0018DEE0();
s32 func_001A2FA0();
s32 death_func_001B1220();
s32 func_002071C0();
s32 func_002075F0();
s32 fade_reset();
extern u8 D_00269140[];
extern u8 D_0028E290;
extern u8 D_0028E7B4;
extern u16 D_00684C80[];
#endif
extern u8 D_0028E304;
extern u8 D_0029BE00[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001B1960(void) {
    u8 t1;

    t1 = *(u8 *)(reg_a5 + 3);
    if (t1 == 0) {
        func_001B1080();
        return;
    }
    if (t1 == 2) {
        func_001B1920();
        return;
    }
    *(s8 *)(reg_a5 + 2) = 0;
    reg_a6 = (u8 *)D_0029BE00;
    reg_d7.w = 1;
    do {
        if (*(u8 *)(reg_a6 + 1) != 0) {
            if (*(u8 *)reg_a6 == 3) {
                func_001384E0();
            }
            if (*(u8 *)reg_a6 == 4) {
                func_00138750();
            }
#ifdef DEATH_LABEL
            if (*(u8 *)reg_a6 == 5) {
                func_00138650();
                fade_reset();
                death_func_001B1220();
                D_0028E290 = 2;
                func_0012FAB0();
                reg_d0.w = 0;
                reg_a0 = (u8 *)D_00269140;
                func_001A2FA0();
                D_00684C80[0] = 0xFF;
                D_00684C80[1] = 0xFF;
                D_00684C80[2] = 0xFF;
                D_00684C80[3] = 0xFF;
                D_00684C80[9] = 0xFF;
                if (D_0028E7B4 & 1) {
                    D_00684C80[0] = *(u8 *)(reg_a5 + 9);
                    D_00684C80[1] = *(u8 *)(reg_a5 + 5);
                    D_00684C80[9] = D_00684C80[1];
                } else {
                    D_00684C80[2] = *(u8 *)(reg_a5 + 8);
                    D_00684C80[3] = *(u8 *)(reg_a5 + 4);
                    D_00684C80[9] = D_00684C80[3];
                }
                func_002075F0();
                func_0018DD40();
                func_0018DEE0();
                reg_d0.h[0] = 0x15;
                func_002071C0();
                return;
            }
#else
            if (*(u8 *)reg_a6 == 5) {
                func_00138650();
            }
            if (*(u8 *)reg_a6 == 6) {
                func_0020ED40();
            }
            if (*(u8 *)reg_a6 == 7) {
                func_0020EE20();
            }
#endif
            if (*(u8 *)reg_a6 == 0) {
                func_001460A0();
            }
            if (*(u8 *)reg_a6 == 1) {
                func_00146470();
            }
            if (*(u8 *)reg_a6 == 2) {
                func_00146350();
            }
            if ((s32) *(u8 *)reg_a6 < 7) {
                *(u8 *)(reg_a6 + 0x30) -= 1;
                if (*(u8 *)(reg_a6 + 0x30) == 0) {
                    *(u8 *)(reg_a6 + 0x30) = 2U;
                    if (*(u16 *)(reg_a6 + 0x2E) == 0) {
                        *(s8 *)(reg_a6 + 0x31) = 1;
                    } else {
                        reg_d0.w = 1;
                        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x2E);
                        if (reg_d1.b[0] == 0) {
                            reg_d1.b[0] = 0x99;
                        } else if (reg_d1.b[0] & 0xF) {
                            reg_d1.b[0] = reg_d1.b[0] - 1;
                        } else {
                            reg_d1.b[0] = (reg_d1.b[0] - 0x10) & 0xF0;
                            reg_d1.b[0] |= 9;
                        }
                        if (reg_d1.b[0] == 0x99) {
                            *(u8 *)(reg_a6 + 0x2F) -= 1;
                        }
                        *(u8 *)(reg_a6 + 0x2E) = (u8) reg_d1.b[0];
                    }
                }
            }
        } else if ((reg_d7.h[0] != 0) && (D_0028E304 == 0)) {
            func_0016A8B0();
            if ((reg_d0.w & 0x8000) && ((reg_a0 = (u8 *)D_0029BE00, (*(u8 *)(reg_a0 + 0x71) == 0)) || ((s32) *(u8 *)(reg_a0 + 0x70) < 6))) {
                func_00130270();
                if (D_0028E408 == 0) {
                    *(s8 *)(reg_a6 + 1) = 1;
                }
            }
        } else if (D_0028E304 == 0) {
            func_0016A8C0();
            if ((reg_d0.w & 0x8000) && ((reg_a0 = (u8 *)D_0029BE00, (*(u8 *)(reg_a0 + 1) == 0)) || ((s32) *(u8 *)reg_a0 < 6))) {
                func_001303A0();
                if (D_0028E408 == 0) {
                    *(s8 *)(reg_a6 + 1) = 1;
                }
            }
        }
        func_00204800();
        reg_a6 += 0x70;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = 3;
    reg_a6 = (u8 *)D_0029BE00;
    if (*(u8 *)(reg_a6 + 1) != 0) {
        reg_d0.h[0] &= 0xFFFE;
        if (*(u8 *)reg_a6 == 8) {
            reg_d0.h[0] |= 1;
        }
    }
    if (*(u8 *)(reg_a6 + 0x71) != 0) {
        reg_d0.h[0] &= 0xFFFD;
        if (*(u8 *)(reg_a6 + 0x70) == 8) {
            reg_d0.h[0] |= 2;
        }
    }
    if (reg_d0.h[0] == 3) {
        *(u8 *)(reg_a5 + 3) = 2U;
    }
    func_001B0E60();
}
