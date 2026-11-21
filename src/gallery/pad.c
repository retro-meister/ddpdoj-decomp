#include "gallery/gallery.h"

typedef struct
{
    u8 raw[0x20];
    u32 buttons;
    u32 trigger;
    u32 prevButtons;
    u32 rawButtons;
    u16 unk30;
    s8 analogX;
    s8 analogY;
    u8 state;
    u8 padId;
    u8 prevPadId;
    u8 padTypeFlag;
} PadInfo;

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
extern u8 D_0012B340[6];
extern u8 D_0012B380[6];

extern u32 D_001A4F10[4];
extern u32 D_001A4F14[];
extern u32 D_001A4F18[];
extern u32 D_001A4F20[4];
extern u32 D_001A4F30[4];
extern u32 D_001A4F34[];
extern u32 D_001A4F38[];
extern u32 D_001A4F40[4];
extern u32 D_001A4F44[];
extern u32 D_001A4F48[];
extern u32 D_001A4F50[4];
extern u32 D_001A4F60[4];
extern u32 D_001A4F64[];
extern u32 D_001A4F68[];
extern u32 D_001A4F70[4];
extern u32 D_001A4F74[];
extern u32 D_001A4F78[];
extern u32 D_001A4F80[4];
extern u32 D_001A4F84[];
extern u32 D_001A4F88[];
extern PadInfo g_pads[3];
extern u8 D_001A5040[0x100];
extern u8 D_001A5140[0x100];

void pad_poll_hardware(void)
{
    s32 port;
    PadInfo *pad;
    for (port = 0, pad = g_pads; port < 2; port++, pad++) {
        s32 padState;
        pad->rawButtons = 0;
        pad->analogX = 0;
        pad->analogY = 0;
        padState = scePadGetState(port, 0);
        if (padState == 0) {
            pad->state = 0;
        }
        switch (pad->state) {
            case 0x00:
                if ((padState == 6) || (padState == 2)) {
                    s32 mode = scePadInfoMode(port, 0, 1, 0);
                    if (mode != 0) {
                        s32 exMode = scePadInfoMode(port, 0, 2, 0);
                        if (exMode > 0) {
                            mode = exMode;
                        }
                        if (mode == 4) {
                            pad->state = 0x28;
                        } else if (mode == 7) {
                            pad->state = 0x46;
                        } else {
                            pad->state = 0x80;
                        }
                    }
                }
                break;

            case 0x28:
                if (scePadInfoMode(port, 0, 4, -1) == 0) {
                    pad->state = 0x80;
                    pad->padTypeFlag = 1;
                    break;
                }
                pad->state++;

            case 0x29:
                if (scePadSetMainMode(port, 0, 1, 3) == 1) {
                    pad->state++;
                }
                break;

            case 0x2A:
                if (scePadGetReqState(port, 0) == 1) {
                    pad->state--;
                }
                if (scePadGetReqState(port, 0) == 0) {
                    pad->state = 0;
                }
                break;

            case 0x46:
                if (scePadInfoAct(port, 0, -1, 0) == 0) {
                    pad->state = 0x80;
                    pad->padTypeFlag = 2;
                    break;
                }
                D_0012B340[0] = (D_0012B380[0] = (D_0012B380[1] = (D_0012B380[2] = (D_0012B380[3] = (D_0012B380[4] = (D_0012B380[5] = 0))))));
                D_0012B340[2] = D_0012B340[3] = D_0012B340[4] = D_0012B340[5] = 0xFF;
                D_0012B340[1] = 1;
                if (scePadSetActAlign(port, 0, D_0012B340) != 0) {
                    pad->state++;
                }
                break;

            case 0x47:
                if (scePadGetReqState(port, 0) == 1) {
                    pad->state--;
                }
                if (scePadGetReqState(port, 0) == 0) {
                    pad->state++;
                }
                break;

            case 0x48:
                if (scePadInfoPressMode(port, 0) == 0) {
                    pad->prevPadId = 0;
                    pad->state = 0x80;
                    pad->padTypeFlag = 4;
                    break;
                }
                pad->state = 0x4C;

            case 0x4C:
                if (scePadEnterPressMode(port, 0) == 0) {
                    pad->state = 0x48;
                } else {
                    pad->state++;
                }
                break;

            case 0x4D:
                if (scePadGetReqState(port, 0) == 1) {
                    pad->state--;
                }
                if (scePadGetReqState(port, 0) == 0) {
                    pad->state = 0x80;
                    pad->padTypeFlag = 8;
                }
                break;

            case 0x80:
                if ((padState == 6) || (padState == 2)) {
                    u32 rawBtns;
                    pad->prevButtons = pad->buttons;
                    if (scePadRead(port, 0, pad->raw) > 0) {
                        if (pad->padTypeFlag & 0xE) {
                            s8 rx = pad->raw[4] - 0x80;
                            s8 ry = pad->raw[5] - 0x80;
                            s8 lx = pad->raw[6] - 0x80;
                            s8 ly = pad->raw[7] - 0x80;
                            pad->analogX = (((rx >= 0) ? (rx) : (-rx)) > ((lx >= 0) ? (lx) : (-lx))) ? (rx) : (lx);
                            pad->analogY = (((ry >= 0) ? (ry) : (-ry)) > ((ly >= 0) ? (ly) : (-ly))) ? (ry) : (ly);
                        }
                        rawBtns = ((pad->raw[2] << 8) | pad->raw[3]) ^ 0xFFFF;
                        pad->rawButtons = rawBtns;
                    } else {
                        pad->rawButtons = 0;
                        pad->analogX = 0;
                        pad->analogY = 0;
                        break;
                    }
                    pad->buttons = rawBtns;
                    pad->trigger = (~pad->prevButtons) & rawBtns;
                    pad->padId = pad->raw[1];
                    if ((pad->prevPadId != 0) && (pad->padId != pad->prevPadId)) {
                        pad->prevPadId = 0;
                        pad->state = 0;
                    }
                    pad->prevPadId = pad->padId;
                }
                break;
        }
    }

    g_pads[2].rawButtons = g_pads[0].rawButtons | g_pads[1].rawButtons;
    g_pads[2].buttons = g_pads[0].buttons | g_pads[1].buttons;
    g_pads[2].trigger = g_pads[0].trigger | g_pads[1].trigger;
    g_pads[2].analogX = (((g_pads[0].analogX >= 0) ? (g_pads[0].analogX) : (-g_pads[0].analogX)) > ((g_pads[1].analogX >= 0) ? (g_pads[1].analogX) : (-g_pads[1].analogX))) ? (g_pads[0].analogX) : (g_pads[1].analogX);
    g_pads[2].analogY = (((g_pads[0].analogY >= 0) ? (g_pads[0].analogY) : (-g_pads[0].analogY)) > ((g_pads[1].analogY >= 0) ? (g_pads[1].analogY) : (-g_pads[1].analogY))) ? (g_pads[0].analogY) : (g_pads[1].analogY);
    g_pads[2].unk30 = g_pads[0].unk30 | g_pads[1].unk30;
}

void pad_init_system(void)
{
    memset(g_pads, 0, sizeof(g_pads));

    D_001A4F88[0] = 0;
    D_001A4F78[0] = 0;
    D_001A4F68[0] = 0;
    D_001A4F48[0] = 0;
    D_001A4F38[0] = 0;
    D_001A4F18[0] = 0;

    D_001A4F84[0] = 0;
    D_001A4F74[0] = 0;
    D_001A4F64[0] = 0;
    D_001A4F44[0] = 0;
    D_001A4F34[0] = 0;
    D_001A4F14[0] = 0;

    D_001A4F80[0] = 0;
    D_001A4F70[0] = 0;
    D_001A4F60[0] = 0;
    D_001A4F40[0] = 0;
    D_001A4F30[0] = 0;
    D_001A4F10[0] = 0;

    scePadInit(0);
    scePadPortOpen(0, 0, D_001A5040);
    scePadPortOpen(1, 0, D_001A5140);
}

void pad_update(void)
{
    s32 padIndex;
    u32 buttons;

    pad_poll_hardware();

    for (padIndex = 0; padIndex < 3; padIndex++) {
        D_001A4F10[padIndex] = 0;

        if (g_pads[padIndex].analogX > -64 && g_pads[padIndex].analogX < 64) {
            g_pads[padIndex].analogX = 0;
        }
        if (g_pads[padIndex].analogY > -64 && g_pads[padIndex].analogY < 64) {
            g_pads[padIndex].analogY = 0;
        }

        D_001A4F80[padIndex] = g_pads[padIndex].rawButtons;
        if (g_pads[padIndex].analogX < 0) {
            D_001A4F80[padIndex] |= 0x8000;
        }
        if (g_pads[padIndex].analogX > 0) {
            D_001A4F80[padIndex] |= 0x2000;
        }
        if (g_pads[padIndex].analogY < 0) {
            D_001A4F80[padIndex] |= 0x1000;
        }
        if (g_pads[padIndex].analogY > 0) {
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
        gallery_reset_slot_states();
    }
}

void pad_open_ports(void)
{
    sceDevVif0Reset();
    sceDevVu0Reset();
    sceGsResetPath();
    sceDmaReset(1);
}
