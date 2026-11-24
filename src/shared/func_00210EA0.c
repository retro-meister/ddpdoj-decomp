#include "common.h"

s32 func_0013EAF0();
s32 func_0018D950();
s32 func_0018D990();
s32 func_0018D9B0();
s32 func_001A9180();
s32 func_001AC3A0();
extern s32 D_0028E734;
extern u16 D_0028E750;
extern u16 D_0028E8C4;
extern u16 D_0028E910;
extern u16 D_0029CD90[];
extern s16 D_0029F260[];
extern u8 D_0029F261[];
extern u8 D_0029F285[];
extern u8 *reg_a6;
#ifdef DEATH_LABEL
extern u16 D_00684C80[];
#endif

void func_00210EA0(void) {
    u8 *p;

    if (*(u8 *)(reg_a6 + 5) & 1) {
        goto block_3;
    }
    *(u8 *)(reg_a6 + 5) |= 1;
    if (D_0029F260[0] >= 0) {
        goto block_2;
    }
    D_0028E734 = -1;
    if (D_0028E750 != 0) {
        goto block_2;
    }
    *(u16 *)(reg_a6 + 0xE) += 1;
    if (D_0028E910 == 0) {
        *(u16 *)(reg_a6 + 6) = 1;
        return;
    }
    *(u16 *)(reg_a6 + 6) = 2;
    return;
block_1:
    *(u16 *)(reg_a6 + 0xE) -= 1;
block_2:
    *(u8 *)(reg_a6 + 5) |= 0x80;
block_rts:
    return;
block_3:
    if (*(u8 *)(reg_a6 + 5) & 0x80) {
        goto block_rts;
    }
    if (*(u16 *)(reg_a6 + 6) == 1) {
        switch (D_0028E8C4) {
        case 0:
            goto block_1;
        }
        reg_d0.w = 0x01000000;
        func_001A9180();
        D_0028E8C4 -= 1;
        func_001AC3A0();
        *(s16 *)(reg_a6 + 0xA) = 0x30;
        *(u8 *)(reg_a6 + 0x11) |= 1;
        func_0018D9B0();
        func_0018D990();
        func_0018D950();
    } else if (*(u16 *)(reg_a6 + 6) == 2) {
        if (D_0028E8C4 != 0) {
            reg_d0.w = MAIN_OR_DEATH_LABEL(0x05000000, 0x07000000);
            func_001A9180();
            D_0028E8C4 -= 1;
            func_001AC3A0();
            *(s16 *)(reg_a6 + 0xA) = 0x30;
            *(u8 *)(reg_a6 + 0x11) |= 1;
            func_0018D9B0();
            func_0018D990();
            func_0018D950();
        } else {
            *(u16 *)(reg_a6 + 6) = 3;
        }
    } else if (*(u16 *)(reg_a6 + 6) == 3) {
        if (!(D_0029F261[0] & 0x40) && D_0029CD90[0] != 0) {
            reg_d0.w = 0x10000000;
            func_001A9180();
            D_0029CD90[0] = 0;
            func_0013EAF0();
            *(s16 *)(reg_a6 + 0xA) = 0x30;
            *(u8 *)(reg_a6 + 0x11) |= 1;
            func_0018D9B0();
            func_0018D990();
            func_0018D950();
        } else {
            *(u16 *)(reg_a6 + 6) = 4;
        }
    } else {
        p = (u8 *)(u32)D_0029F285;
        if (*p == 0) {
            goto block_1;
        }
        reg_d0.w = 0x01000000;
#ifdef DEATH_LABEL
        if (D_00684C80[1] == 2) {
            *(s32 *)&reg_d0 = 0x01000000;
        } else if (D_00684C80[1] == 4) {
            reg_d0.w = 0x01500000;
        } else {
            reg_d0.w = 0x03000000;
        }
#endif
        func_001A9180();
        *p -= 1;
        func_0013EAF0();
        *(s16 *)(reg_a6 + 0xA) = 0x30;
        *(u8 *)(reg_a6 + 0x11) |= 1;
        func_0018D9B0();
        func_0018D990();
        func_0018D950();
    }
}
