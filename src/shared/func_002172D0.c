#include "common.h"

typedef struct {
    u8 raw[0x20];
    u32 buttons;
    u32 trigger;
    u32 prevButtons;
    u32 rawButtons;
    u16 extraButtons;
    s8 analogX;
    s8 analogY;
#ifdef DEATH_LABEL
    s8 rightX;
    s8 rightY;
#else
    u16 unk34;
#endif
    u8 state;
    u8 padId;
    u8 prevPadId;
    u8 padTypeFlag;
    u8 pad3A[2];
} PadInfo;

s32 scePadRead(s32 port, s32 slot, u8 *data);
s32 scePadGetState(s32 port, s32 slot);
s32 scePadGetReqState(s32 port, s32 slot);
s32 scePadInfoAct(s32 port, s32 slot, s32 actno, s32 term);
s32 scePadInfoMode(s32 port, s32 slot, s32 term, s32 offs);
s32 scePadSetMainMode(s32 port, s32 slot, s32 offs, s32 lock);
s32 scePadSetActAlign(s32 port, s32 slot, u8 *data);
s32 scePadInfoPressMode(s32 port, s32 slot);
s32 scePadEnterPressMode(s32 port, s32 slot);
extern PadInfo D_0057CC90[3];
extern u8 D_0028EA00[6];
extern u8 D_0028EA40[6];

void func_002172D0(void)
{
    s32 port;
    PadInfo *pad;
    for (pad = D_0057CC90, port = 0; port < 2; port++, pad++) {
        s32 padState;
        pad->rawButtons = 0;
        pad->analogX = 0;
        pad->analogY = 0;
#ifdef DEATH_LABEL
        pad->rightX = 0;
        pad->rightY = 0;
#endif
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
                D_0028EA00[0] = D_0028EA40[5] = D_0028EA40[4] = D_0028EA40[3] = D_0028EA40[2] = D_0028EA40[1] = D_0028EA40[0] = 0;
                D_0028EA00[5] = D_0028EA00[4] = D_0028EA00[3] = D_0028EA00[2] = 0xFF;
                D_0028EA00[1] = 1;
                if (scePadSetActAlign(port, 0, D_0028EA00) != 0) {
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

    D_0057CC90[2].rawButtons = D_0057CC90[0].rawButtons | D_0057CC90[1].rawButtons;
    D_0057CC90[2].buttons = D_0057CC90[0].buttons | D_0057CC90[1].buttons;
    D_0057CC90[2].trigger = D_0057CC90[0].trigger | D_0057CC90[1].trigger;
    D_0057CC90[2].analogX = (((D_0057CC90[0].analogX >= 0) ? (D_0057CC90[0].analogX) : (-D_0057CC90[0].analogX)) > ((D_0057CC90[1].analogX >= 0) ? (D_0057CC90[1].analogX) : (-D_0057CC90[1].analogX))) ? (D_0057CC90[0].analogX) : (D_0057CC90[1].analogX);
    D_0057CC90[2].analogY = (((D_0057CC90[0].analogY >= 0) ? (D_0057CC90[0].analogY) : (-D_0057CC90[0].analogY)) > ((D_0057CC90[1].analogY >= 0) ? (D_0057CC90[1].analogY) : (-D_0057CC90[1].analogY))) ? (D_0057CC90[0].analogY) : (D_0057CC90[1].analogY);
    D_0057CC90[2].extraButtons = D_0057CC90[0].extraButtons | D_0057CC90[1].extraButtons;
}
