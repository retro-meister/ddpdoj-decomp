#include "common.h"

typedef struct {
    u8 pad_00[0x2C];
    u32 buttons;
    u8 pad_30[2];
    s8 analog_x;
    s8 analog_y;
    u8 pad_34[4];
} PadRawData;

extern void func_0011DAC0(void);
extern void reset_gallery_slot_states(void);

extern u16 D_0012B298;
extern s8 D_0012B2A0[];
extern u8 D_0012B2A8;
extern u8 D_0012B2A9;
extern u8 D_0012B2AA;
extern u8 D_0012B2AC;
extern u8 D_0012B2AD;
extern u8 D_0012B2AE;
extern u8 D_0012B2B0;
extern u8 D_0012B2B4;
extern u8 *D_0012B2D4;
extern u32 D_0012B2D8;

extern u32 D_001A4F10[4];
extern u32 D_001A4F20[4];
extern u32 D_001A4F30[4];
extern u32 D_001A4F40[4];
extern u32 D_001A4F50[4];
extern u32 D_001A4F60[4];
extern u32 D_001A4F70[4];
extern u32 D_001A4F80[4];
extern PadRawData D_001A4F90[4];

void func_0011E210(void) {
    s32 padIndex;
    u32 buttons;

    func_0011DAC0();

    for (padIndex = 0; padIndex < 3; padIndex++) {
        D_001A4F10[padIndex] = 0;

        if (D_001A4F90[padIndex].analog_x > -64 && D_001A4F90[padIndex].analog_x < 64) {
            D_001A4F90[padIndex].analog_x = 0;
        }
        if (D_001A4F90[padIndex].analog_y > -64 && D_001A4F90[padIndex].analog_y < 64) {
            D_001A4F90[padIndex].analog_y = 0;
        }

        D_001A4F80[padIndex] = D_001A4F90[padIndex].buttons;
        if (D_001A4F90[padIndex].analog_x < 0) {
            D_001A4F80[padIndex] |= 0x8000;
        }
        if (D_001A4F90[padIndex].analog_x > 0) {
            D_001A4F80[padIndex] |= 0x2000;
        }
        if (D_001A4F90[padIndex].analog_y < 0) {
            D_001A4F80[padIndex] |= 0x1000;
        }
        if (D_001A4F90[padIndex].analog_y > 0) {
            D_001A4F80[padIndex] |= 0x4000;
        }

        if (D_0012B2B4 != 0) {
            buttons = D_001A4F80[padIndex];
            D_001A4F80[padIndex] = buttons & 0xFFF;
            if (buttons & 0x1000) {
                D_001A4F80[padIndex] |= 0x8000;
            }
            if (buttons & 0x4000) {
                D_001A4F80[padIndex] |= 0x2000;
            }
            if (buttons & 0x2000) {
                D_001A4F80[padIndex] |= 0x1000;
            }
            if (buttons & 0x8000) {
                D_001A4F80[padIndex] |= 0x4000;
            }
        }

        if (D_001A4F80[padIndex] == 0) {
            D_001A4F30[padIndex] = 0;
            D_001A4F60[padIndex] = 0;
            D_001A4F20[padIndex] = 0;
            D_001A4F50[padIndex] = 0;
        }

        if (D_001A4F80[padIndex] == D_001A4F40[padIndex]) {
            D_001A4F30[padIndex]++;
            if (D_001A4F30[padIndex] > 10) {
                D_001A4F60[padIndex] = D_001A4F80[padIndex];
                D_001A4F30[padIndex] = 0;
            } else {
                D_001A4F60[padIndex] = 0;
            }

            D_001A4F20[padIndex]++;
            if (D_001A4F20[padIndex] > 10) {
                D_001A4F50[padIndex] = D_001A4F80[padIndex];
                if (D_001A4F20[padIndex] > 14) {
                    D_001A4F20[padIndex] = 10;
                }
            } else {
                D_001A4F50[padIndex] = 0;
            }
        } else if (D_001A4F40[padIndex] == 0) {
            D_001A4F60[padIndex] = D_001A4F80[padIndex];
            D_001A4F30[padIndex] = 0;
            D_001A4F50[padIndex] = D_001A4F80[padIndex];
            D_001A4F20[padIndex] = 0;
        } else {
            D_001A4F30[padIndex]++;
            if (D_001A4F30[padIndex] > 10) {
                D_001A4F60[padIndex] = D_001A4F80[padIndex];
                D_001A4F30[padIndex] = 0;
            } else {
                D_001A4F60[padIndex] = 0;
            }

            D_001A4F20[padIndex]++;
            if (D_001A4F20[padIndex] > 10) {
                D_001A4F50[padIndex] = D_001A4F80[padIndex];
                D_001A4F20[padIndex] = 10;
            } else {
                D_001A4F50[padIndex] = 0;
            }
        }

        D_001A4F70[padIndex] = D_001A4F40[padIndex] ^ D_001A4F80[padIndex];
        D_001A4F70[padIndex] &= D_001A4F80[padIndex];
        D_001A4F40[padIndex] = D_001A4F80[padIndex];

        if (D_001A4F50[padIndex] & 0x5000) {
            D_001A4F50[padIndex] = 0;
            D_001A4F20[padIndex] = 0;
        }
    }

    D_0012B2D4 = (u8 *)D_0012B2A0;
    D_0012B2D8 = 0;
    buttons = D_001A4F80[0];
    if (buttons & 0x800) {
        *(u8 *)&D_0012B2D8 |= 0x01;
    }
    if (buttons & 0x1000) {
        *(u8 *)&D_0012B2D8 |= 0x02;
    }
    if (buttons & 0x4000) {
        *(u8 *)&D_0012B2D8 |= 0x04;
    }
    if (buttons & 0x8000) {
        *(u8 *)&D_0012B2D8 |= 0x08;
    }
    if (buttons & 0x2000) {
        *(u8 *)&D_0012B2D8 |= 0x10;
    }
    if (buttons & (1 << D_0012B2A8)) {
        *(u8 *)&D_0012B2D8 |= 0x20;
    }
    if (buttons & (1 << D_0012B2A9)) {
        *(u8 *)&D_0012B2D8 |= 0x40;
    }
    if (buttons & (1 << D_0012B2AA)) {
        *(u8 *)&D_0012B2D8 |= 0x80;
    }
    *D_0012B2D4 = ~*(u8 *)&D_0012B2D8;
    D_0012B2D4++;

    D_0012B2D8 = 0;
    buttons = D_001A4F80[1];
    if (buttons & 0x800) {
        *(u8 *)&D_0012B2D8 |= 0x01;
    }
    if (buttons & 0x1000) {
        *(u8 *)&D_0012B2D8 |= 0x02;
    }
    if (buttons & 0x4000) {
        *(u8 *)&D_0012B2D8 |= 0x04;
    }
    if (buttons & 0x8000) {
        *(u8 *)&D_0012B2D8 |= 0x08;
    }
    if (buttons & 0x2000) {
        *(u8 *)&D_0012B2D8 |= 0x10;
    }
    if (buttons & (1 << D_0012B2AC)) {
        *(u8 *)&D_0012B2D8 |= 0x20;
    }
    if (buttons & (1 << D_0012B2AD)) {
        *(u8 *)&D_0012B2D8 |= 0x40;
    }
    if (buttons & (1 << D_0012B2AE)) {
        *(u8 *)&D_0012B2D8 |= 0x80;
    }
    *D_0012B2D4 = ~*(u8 *)&D_0012B2D8;

    D_0012B2D4 = (u8 *)&D_0012B298;
    D_0012B2D8 = 0;
    if (D_001A4F80[0] & 0x100) {
        *(u8 *)&D_0012B2D8 |= 0x01;
    }
    if (D_001A4F80[1] & 0x100) {
        *(u8 *)&D_0012B2D8 |= 0x02;
    }
    *(u16 *)D_0012B2D4 = ~*(u16 *)&D_0012B2D8;

    if (D_0012B2B0 != 0) {
        D_0012B2A0[0] = D_0012B2A0[1] = D_0012B2A0[2] = D_0012B2A0[3] =
            D_0012B2A0[4] = D_0012B2A0[5] = D_0012B2A0[6] = D_0012B2A0[7] = -1;
        reset_gallery_slot_states();
    }
}
