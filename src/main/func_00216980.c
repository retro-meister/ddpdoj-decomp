#include "gallery/gallery.h"

typedef struct {
    u8 raw[0x20];
    u32 buttons;
    u32 trigger;
    u32 prevButtons;
    u32 rawButtons;
    u16 extraButtons;
    s8 analogX;
    s8 analogY;
    u16 unk34;
    u8 state;
    u8 padId;
    u8 prevPadId;
    u8 padTypeFlag;
    u8 pad3A[2];
} PadState;

extern u16 D_0028E228;
extern s8 D_0028E248[];
extern u8 D_0028E270;
extern u8 D_0028E271;
extern u8 D_0028E272;
extern u8 D_0028E274;
extern u8 D_0028E275;
extern u8 D_0028E276;
extern u8 *reg_a0;
extern u32 D_0057CC50[];
extern u32 D_0057CC20[];
extern u32 D_0057CC80[];
extern u32 D_0057CC40[];
extern u32 D_0057CC60[];
extern u32 D_0057CC30[];
extern u8 D_0028E2F8;
extern u32 D_0057CC70[];
extern u32 D_0057CC10[];
extern PadState D_0057CC90[];
void func_00216FD0(void);
void func_002172D0(void);

void func_00216980(void)
{
    s32 padIndex;
    u32 buttons;

    func_002172D0();

    for (padIndex = 0; padIndex < 3; padIndex++) {
        D_0057CC10[padIndex] = 0;

        if (D_0057CC90[padIndex].analogX > -64 && D_0057CC90[padIndex].analogX < 64) {
            D_0057CC90[padIndex].analogX = 0;
        }
        if (D_0057CC90[padIndex].analogY > -64 && D_0057CC90[padIndex].analogY < 64) {
            D_0057CC90[padIndex].analogY = 0;
        }

        D_0057CC80[padIndex] = D_0057CC90[padIndex].rawButtons;
        if (D_0057CC90[padIndex].analogX < 0) {
            D_0057CC80[padIndex] |= SCE_PADLleft;
        }
        if (D_0057CC90[padIndex].analogX > 0) {
            D_0057CC80[padIndex] |= SCE_PADLright;
        }
        if (D_0057CC90[padIndex].analogY < 0) {
            D_0057CC80[padIndex] |= SCE_PADLup;
        }
        if (D_0057CC90[padIndex].analogY > 0) {
            D_0057CC80[padIndex] |= SCE_PADLdown;
        }

        if (D_0028E2F8 != 0) {
            buttons = D_0057CC80[padIndex];
            D_0057CC80[padIndex] = buttons & 0xFFF;
            if (buttons & SCE_PADLup) {
                D_0057CC80[padIndex] |= SCE_PADLleft;
            }
            if (buttons & SCE_PADLdown) {
                D_0057CC80[padIndex] |= SCE_PADLright;
            }
            if (buttons & SCE_PADLright) {
                D_0057CC80[padIndex] |= SCE_PADLup;
            }
            if (buttons & SCE_PADLleft) {
                D_0057CC80[padIndex] |= SCE_PADLdown;
            }
        }

        if (D_0057CC80[padIndex] == 0) {
            D_0057CC30[padIndex] = 0;
            D_0057CC60[padIndex] = 0;
            D_0057CC20[padIndex] = 0;
            D_0057CC50[padIndex] = 0;
        }

        if (D_0057CC80[padIndex] == D_0057CC40[padIndex]) {
            D_0057CC30[padIndex]++;
            if (D_0057CC30[padIndex] > 10) {
                D_0057CC60[padIndex] = D_0057CC80[padIndex];
                D_0057CC30[padIndex] = 0;
            } else {
                D_0057CC60[padIndex] = 0;
            }

            D_0057CC20[padIndex]++;
            if (D_0057CC20[padIndex] > 10) {
                D_0057CC50[padIndex] = D_0057CC80[padIndex];
                if (D_0057CC20[padIndex] > 14) {
                    D_0057CC20[padIndex] = 10;
                }
            } else {
                D_0057CC50[padIndex] = 0;
            }
        } else if (D_0057CC40[padIndex] == 0) {
            D_0057CC60[padIndex] = D_0057CC80[padIndex];
            D_0057CC30[padIndex] = 0;
            D_0057CC50[padIndex] = D_0057CC80[padIndex];
            D_0057CC20[padIndex] = 0;
        } else {
            D_0057CC30[padIndex]++;
            if (D_0057CC30[padIndex] > 10) {
                D_0057CC60[padIndex] = D_0057CC80[padIndex];
                D_0057CC30[padIndex] = 0;
            } else {
                D_0057CC60[padIndex] = 0;
            }

            D_0057CC20[padIndex]++;
            if (D_0057CC20[padIndex] > 10) {
                D_0057CC50[padIndex] = D_0057CC80[padIndex];
                D_0057CC20[padIndex] = 10;
            } else {
                D_0057CC50[padIndex] = 0;
            }
        }

        D_0057CC70[padIndex] = D_0057CC40[padIndex] ^ D_0057CC80[padIndex];
        D_0057CC70[padIndex] &= D_0057CC80[padIndex];
        D_0057CC40[padIndex] = D_0057CC80[padIndex];

        if (D_0057CC50[padIndex] & 0x5000) {
            D_0057CC50[padIndex] = 0;
            D_0057CC20[padIndex] = 0;
        }
    }

    reg_a0 = (u8 *)D_0028E248;
    reg_d0.w = 0;
    buttons = D_0057CC80[0];
    if (buttons & SCE_PADstart) {
        *(u8 *)&reg_d0 |= 0x01;
    }
    if (buttons & SCE_PADLup) {
        *(u8 *)&reg_d0 |= 0x02;
    }
    if (buttons & SCE_PADLdown) {
        *(u8 *)&reg_d0 |= 0x04;
    }
    if (buttons & SCE_PADLleft) {
        *(u8 *)&reg_d0 |= 0x08;
    }
    if (buttons & SCE_PADLright) {
        *(u8 *)&reg_d0 |= 0x10;
    }
    if (buttons & (1 << D_0028E270)) {
        *(u8 *)&reg_d0 |= 0x20;
    }
    if (buttons & (1 << D_0028E271)) {
        *(u8 *)&reg_d0 |= 0x40;
    }
    if (buttons & (1 << D_0028E272)) {
        *(u8 *)&reg_d0 |= 0x80;
    }
    *reg_a0 = ~*(u8 *)&reg_d0;
    reg_a0++;

    reg_d0.w = 0;
    buttons = D_0057CC80[1];
    if (buttons & SCE_PADstart) {
        *(u8 *)&reg_d0 |= 0x01;
    }
    if (buttons & SCE_PADLup) {
        *(u8 *)&reg_d0 |= 0x02;
    }
    if (buttons & SCE_PADLdown) {
        *(u8 *)&reg_d0 |= 0x04;
    }
    if (buttons & SCE_PADLleft) {
        *(u8 *)&reg_d0 |= 0x08;
    }
    if (buttons & SCE_PADLright) {
        *(u8 *)&reg_d0 |= 0x10;
    }
    if (buttons & (1 << D_0028E274)) {
        *(u8 *)&reg_d0 |= 0x20;
    }
    if (buttons & (1 << D_0028E275)) {
        *(u8 *)&reg_d0 |= 0x40;
    }
    if (buttons & (1 << D_0028E276)) {
        *(u8 *)&reg_d0 |= 0x80;
    }
    *reg_a0 = ~*(u8 *)&reg_d0;

    reg_a0 = (u8 *)&D_0028E228;
    reg_d0.w = 0;
    if (D_0057CC80[0] & SCE_PADselect) {
        *(u8 *)&reg_d0 |= 0x01;
    }
    if (D_0057CC80[1] & SCE_PADselect) {
        *(u8 *)&reg_d0 |= 0x02;
    }
    *(u16 *)reg_a0 = ~*(u16 *)&reg_d0;

    func_00216FD0();
}
