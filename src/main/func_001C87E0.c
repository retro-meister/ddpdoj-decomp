#include "common.h"

extern s8 D_0028E408;

s32 func_00125120();
s32 func_001251C0();
s32 func_00125250();
s32 func_001CBBE0();
s32 func_00201160();
extern u16 D_0026C800[];
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;

void func_001C87E0(void) {
    u16 temp_v1;
    u16 temp_v1_2;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_v1_3;
    u8 *temp_a1;

    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        temp_v1 = (*(u16 *)((u8 *)(reg_a4) + (4)));
        temp_a1 = (u8 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            (*(u16 *)((u8 *)(reg_a4) + (4))) = (u16) (temp_v1 - 1);
            if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
                func_001CBBE0();
                if (D_0028E910 != 0) {
                    reg_d0.w = 0xD;
                    func_00125120();
                }
                reg_d0.w = 6;
                func_001251C0();
                (*(u16 *)((u8 *)(reg_a0) + (4))) = 0xA0U;
            }
        } else {
            reg_d0.w = 6;
            func_00125250();
            if (D_0028E408 == 0) {
                (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
            }
        }
    }
    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0 == 2) {
        reg_d0.w = 6;
        func_00125250();
        if (D_0028E408 == 0) {
            reg_d0.w = 7;
            func_00125250();
            if (D_0028E408 == 0) {
                reg_d0.w = 8;
                func_00125250();
                if (D_0028E408 == 0) {
                    reg_d0.w = 9;
                    func_00125250();
                    if (D_0028E408 == 0) {
                        do {
                            func_00201160();
                            reg_d0.h[0] &= 3;
                        } while ((*(u16 *)((u8 *)(reg_a4) + (6))) == reg_d0.h[0]);
                        (*(u16 *)((u8 *)(reg_a4) + (6))) = (u16) reg_d0.h[0];
                        reg_a1 = (u8 *)(D_0026C800);
                        reg_d0.h[0] += reg_d0.h[0];
                        reg_d0.h[0] += reg_d0.h[0];
                        reg_a1 += reg_d0.h[0];
                        reg_d0.h[0] = *(u16 *)reg_a1;
                        reg_a1 += 2;
                        func_001251C0();
                        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) *(u16 *)reg_a1;
                        reg_a1 += 2;
                        (*(u16 *)((u8 *)(reg_a4) + (8))) += 1;
                        if ((*(u16 *)((u8 *)(reg_a4) + (8))) == 3) {
                            (*(u16 *)((u8 *)(reg_a4) + (8))) = 0U;
                            (*(u8 *)((u8 *)(reg_a4) + (3))) = 3U;
                            (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x40U;
                        }
                    }
                }
            }
        }
    }
    temp_a0_2 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_2 == 3) {
        reg_d0.w = 6;
        func_00125250();
        if (D_0028E408 == 0) {
            reg_d0.w = 7;
            func_00125250();
            if (D_0028E408 == 0) {
                reg_d0.w = 8;
                func_00125250();
                if (D_0028E408 == 0) {
                    reg_d0.w = 9;
                    func_00125250();
                    if (D_0028E408 == 0) {
                        temp_v1_2 = (*(u16 *)((u8 *)(reg_a4) + (4)));
                        if (temp_v1_2 != 0) {
                            (*(u16 *)((u8 *)(reg_a4) + (4))) = (u16) (temp_v1_2 - 1);
                            if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
                                (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0x20;
                                (*(u16 *)((u8 *)(reg_a4) + (0xE))) = 0x4040U;
                                (*(u16 *)((u8 *)(reg_a4) + (0x10))) = 4U;
                            }
                        } else {
                            reg_d0.w = 0xB;
                            func_00125250();
                            if (D_0028E408 == 0) {
                                reg_d0.w = 0xB;
                                func_001251C0();
                                (*(u16 *)((u8 *)(reg_a0) + (0xC))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0xE)));
                                temp_v1_3 = (*(u8 *)((u8 *)(reg_a4) + (0xF)));
                                if (temp_v1_3 != 0x10) {
                                    (*(u8 *)((u8 *)(reg_a4) + (0xF))) = (u8) (temp_v1_3 - 8);
                                    if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0xF))) < 0x11) {
                                        (*(u8 *)((u8 *)(reg_a4) + (0xF))) = 0x10U;
                                    }
                                }
                                (*(u16 *)((u8 *)(reg_a4) + (0x10))) -= 1;
                                if ((*(u16 *)((u8 *)(reg_a4) + (0x10))) == 0) {
                                    (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
                                } else {
                                    goto block_31;
                                }
                            } else {
block_31:
                                reg_d0.w = 0xA;
                                func_00125250();
                                if (D_0028E408 == 0) {
                                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
                                    (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (*(u8 *)((u8 *)(reg_a4) + (0xC)));
                                        reg_d0.w = 0xA;
                                        func_001251C0();
                                        func_00201160();
                                        reg_d0.h[0] &= 3;
                                        reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                                        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) reg_d0.h[0];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    temp_a0_3 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_3 == 4) {
        reg_d0.w = 0xA;
        func_00125250();
        if (D_0028E408 == 0) {
            reg_d0.w = 0xB;
            func_00125250();
            if (D_0028E408 == 0) {
                (*(u8 *)((u8 *)(reg_a4) + (3))) = 0U;
                (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x40U;
            }
        }
    }
}
