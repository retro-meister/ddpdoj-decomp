#include "common.h"

s32 func_0013EB60();
s32 func_0018D950();
s32 func_0018D990();
s32 func_0018D9B0();
s32 func_001A9190();
s32 func_001AC5F0();
extern s32 D_0028E730;
extern u16 D_0028E748;
extern u16 D_0028E8C0;
extern u16 D_0028E910;
extern u16 D_0029CD80[];
extern s16 D_0029F1F0[];
extern u8 D_0029F1F1[];
extern u8 D_0029F215[];
extern u8 *reg_a6;
#ifdef DEATH_LABEL
extern u16 D_00684C80[];
#endif

void func_00211140(void) {
    u8 *p;

    if (*(u8 *)(reg_a6 + 4) & 1) {
        goto block_3;
    }
    *(u8 *)(reg_a6 + 4) |= 1;
    if (D_0029F1F0[0] >= 0) {
        goto block_2;
    }
    D_0028E730 = -1;
    if (D_0028E748 != 0) {
        goto block_2;
    }
    *(u16 *)(reg_a6 + 0xE) += 1;
    if (D_0028E910 == 0) {
        *(u16 *)(reg_a6 + 8) = 1;
        return;
    }
    *(u16 *)(reg_a6 + 8) = 2;
    return;
block_1:
    *(u16 *)(reg_a6 + 0xE) -= 1;
block_2:
    *(u8 *)(reg_a6 + 4) |= 0x80;
block_rts:
    return;
block_3:
    if (*(u8 *)(reg_a6 + 4) & 0x80) {
        goto block_rts;
    }
    if (*(u16 *)(reg_a6 + 8) == 1) {
        switch (D_0028E8C0) {
        case 0:
            goto block_1;
        }
        reg_d0.w = 0x01000000;
        func_001A9190();
        D_0028E8C0 -= 1;
        func_001AC5F0();
        *(s16 *)(reg_a6 + 0xA) = 0x30;
        if (*(u16 *)(reg_a6 + 0x10) & 1) {
            *(u8 *)(reg_a6 + 0x11) &= 0xFE;
        } else {
            func_0018D9B0();
            func_0018D990();
            func_0018D950();
        }
        return;
    }
    if (*(u16 *)(reg_a6 + 8) == 2) {
        if (D_0028E8C0 != 0) {
            reg_d0.w = MAIN_OR_DEATH_LABEL(0x05000000, 0x07000000);
            func_001A9190();
            D_0028E8C0 -= 1;
            func_001AC5F0();
            if (*(u16 *)(reg_a6 + 0x10) & 1) {
                *(u8 *)(reg_a6 + 0x11) &= 0xFE;
            } else {
                *(s16 *)(reg_a6 + 0xA) = 0x30;
                func_0018D9B0();
                func_0018D990();
                func_0018D950();
            }
            return;
        }
        *(u16 *)(reg_a6 + 8) = 3;
        return;
    }
    if (*(u16 *)(reg_a6 + 8) == 3) {
        if (!(D_0029F1F1[0] & 0x40) && D_0029CD80[0] != 0) {
            reg_d0.w = 0x10000000;
            func_001A9190();
            D_0029CD80[0] = 0;
            func_0013EB60();
            if (*(u16 *)(reg_a6 + 0x10) & 1) {
                *(u8 *)(reg_a6 + 0x11) &= 0xFE;
            } else {
                *(s16 *)(reg_a6 + 0xA) = 0x30;
                func_0018D9B0();
                func_0018D990();
                func_0018D950();
            }
            return;
        }
        *(u16 *)(reg_a6 + 8) = 4;
        return;
    }
    p = (u8 *)(u32)D_0029F215;
    if (*p == 0) {
        goto block_1;
    }
    reg_d0.w = 0x01000000;
#ifdef DEATH_LABEL
    if (D_00684C80[3] == 2) {
        *(s32 *)&reg_d0 = 0x01000000;
    } else if (D_00684C80[3] == 4) {
        reg_d0.w = 0x01500000;
    } else {
        reg_d0.w = 0x03000000;
    }
#endif
    func_001A9190();
    *p -= 1;
    func_0013EB60();
    if (*(u16 *)(reg_a6 + 0x10) & 1) {
        *(u8 *)(reg_a6 + 0x11) &= 0xFE;
    } else {
        *(s16 *)(reg_a6 + 0xA) = 0x30;
        func_0018D9B0();
        func_0018D990();
        func_0018D950();
    }
}
