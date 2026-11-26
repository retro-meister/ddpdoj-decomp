#include "gallery/gallery.h"

extern u8 g_pad_act_align[6];
extern u32 g_pad_unk_state[4];
extern u32 g_pad_fast_repeat_timer[4];
extern u32 g_pad_repeat_timer[4];
extern u32 g_pad_prev_held[4];
extern u32 g_pad_fast_repeat[4];
extern u32 g_pad_repeat[4];
extern u32 g_pad_trigger[4];
extern u32 g_pad_held[4];
extern u8 g_pad_dma_buf_0[0x100];
extern u8 g_pad_dma_buf_1[0x100];

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
                g_pad_act_align[0] = (g_pad_act_direct[0] = (g_pad_act_direct[1] = (g_pad_act_direct[2] = (g_pad_act_direct[3] = (g_pad_act_direct[4] = (g_pad_act_direct[5] = 0))))));
                g_pad_act_align[2] = g_pad_act_align[3] = g_pad_act_align[4] = g_pad_act_align[5] = 0xFF;
                g_pad_act_align[1] = 1;
                if (scePadSetActAlign(port, 0, g_pad_act_align) != 0) {
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
    g_pads[2].extraButtons = g_pads[0].extraButtons | g_pads[1].extraButtons;
}

void pad_init_system(void)
{
    memset(g_pads, 0, sizeof(g_pads));

    g_pad_held[2] = 0;
    g_pad_trigger[2] = 0;
    g_pad_repeat[2] = 0;
    g_pad_prev_held[2] = 0;
    g_pad_repeat_timer[2] = 0;
    g_pad_unk_state[2] = 0;

    g_pad_held[1] = 0;
    g_pad_trigger[1] = 0;
    g_pad_repeat[1] = 0;
    g_pad_prev_held[1] = 0;
    g_pad_repeat_timer[1] = 0;
    g_pad_unk_state[1] = 0;

    g_pad_held[0] = 0;
    g_pad_trigger[0] = 0;
    g_pad_repeat[0] = 0;
    g_pad_prev_held[0] = 0;
    g_pad_repeat_timer[0] = 0;
    g_pad_unk_state[0] = 0;

    scePadInit(0);
    scePadPortOpen(0, 0, g_pad_dma_buf_0);
    scePadPortOpen(1, 0, g_pad_dma_buf_1);
}

void pad_update(void)
{
    s32 padIndex;
    u32 buttons;

    pad_poll_hardware();

    for (padIndex = 0; padIndex < 3; padIndex++) {
        g_pad_unk_state[padIndex] = 0;

        if (g_pads[padIndex].analogX > -64 && g_pads[padIndex].analogX < 64) {
            g_pads[padIndex].analogX = 0;
        }
        if (g_pads[padIndex].analogY > -64 && g_pads[padIndex].analogY < 64) {
            g_pads[padIndex].analogY = 0;
        }

        g_pad_held[padIndex] = g_pads[padIndex].rawButtons;
        if (g_pads[padIndex].analogX < 0) {
            g_pad_held[padIndex] |= SCE_PADLleft;
        }
        if (g_pads[padIndex].analogX > 0) {
            g_pad_held[padIndex] |= SCE_PADLright;
        }
        if (g_pads[padIndex].analogY < 0) {
            g_pad_held[padIndex] |= SCE_PADLup;
        }
        if (g_pads[padIndex].analogY > 0) {
            g_pad_held[padIndex] |= SCE_PADLdown;
        }

        if (g_pad_tate_rotate != 0) {
            buttons = g_pad_held[padIndex];
            g_pad_held[padIndex] = buttons & 0xFFF;
            if (buttons & SCE_PADLup) {
                g_pad_held[padIndex] |= SCE_PADLleft;
            }
            if (buttons & SCE_PADLdown) {
                g_pad_held[padIndex] |= SCE_PADLright;
            }
            if (buttons & SCE_PADLright) {
                g_pad_held[padIndex] |= SCE_PADLup;
            }
            if (buttons & SCE_PADLleft) {
                g_pad_held[padIndex] |= SCE_PADLdown;
            }
        }

        if (g_pad_held[padIndex] == 0) {
            g_pad_repeat_timer[padIndex] = 0;
            g_pad_repeat[padIndex] = 0;
            g_pad_fast_repeat_timer[padIndex] = 0;
            g_pad_fast_repeat[padIndex] = 0;
        }

        if (g_pad_held[padIndex] == g_pad_prev_held[padIndex]) {
            g_pad_repeat_timer[padIndex]++;
            if (g_pad_repeat_timer[padIndex] > 10) {
                g_pad_repeat[padIndex] = g_pad_held[padIndex];
                g_pad_repeat_timer[padIndex] = 0;
            } else {
                g_pad_repeat[padIndex] = 0;
            }

            g_pad_fast_repeat_timer[padIndex]++;
            if (g_pad_fast_repeat_timer[padIndex] > 10) {
                g_pad_fast_repeat[padIndex] = g_pad_held[padIndex];
                if (g_pad_fast_repeat_timer[padIndex] > 14) {
                    g_pad_fast_repeat_timer[padIndex] = 10;
                }
            } else {
                g_pad_fast_repeat[padIndex] = 0;
            }
        } else if (g_pad_prev_held[padIndex] == 0) {
            g_pad_repeat[padIndex] = g_pad_held[padIndex];
            g_pad_repeat_timer[padIndex] = 0;
            g_pad_fast_repeat[padIndex] = g_pad_held[padIndex];
            g_pad_fast_repeat_timer[padIndex] = 0;
        } else {
            g_pad_repeat_timer[padIndex]++;
            if (g_pad_repeat_timer[padIndex] > 10) {
                g_pad_repeat[padIndex] = g_pad_held[padIndex];
                g_pad_repeat_timer[padIndex] = 0;
            } else {
                g_pad_repeat[padIndex] = 0;
            }

            g_pad_fast_repeat_timer[padIndex]++;
            if (g_pad_fast_repeat_timer[padIndex] > 10) {
                g_pad_fast_repeat[padIndex] = g_pad_held[padIndex];
                g_pad_fast_repeat_timer[padIndex] = 10;
            } else {
                g_pad_fast_repeat[padIndex] = 0;
            }
        }

        g_pad_trigger[padIndex] = g_pad_prev_held[padIndex] ^ g_pad_held[padIndex];
        g_pad_trigger[padIndex] &= g_pad_held[padIndex];
        g_pad_prev_held[padIndex] = g_pad_held[padIndex];

        if (g_pad_fast_repeat[padIndex] & 0x5000) {
            g_pad_fast_repeat[padIndex] = 0;
            g_pad_fast_repeat_timer[padIndex] = 0;
        }
    }

    g_pad_port_dst = (u8 *)g_arcade_input_port;
    g_pad_port_bits = 0;
    buttons = g_pad_held[0];
    if (buttons & SCE_PADstart) {
        *(u8 *)&g_pad_port_bits |= 0x01;
    }
    if (buttons & SCE_PADLup) {
        *(u8 *)&g_pad_port_bits |= 0x02;
    }
    if (buttons & SCE_PADLdown) {
        *(u8 *)&g_pad_port_bits |= 0x04;
    }
    if (buttons & SCE_PADLleft) {
        *(u8 *)&g_pad_port_bits |= 0x08;
    }
    if (buttons & SCE_PADLright) {
        *(u8 *)&g_pad_port_bits |= 0x10;
    }
    if (buttons & (1 << g_p1_btn_map_a)) {
        *(u8 *)&g_pad_port_bits |= 0x20;
    }
    if (buttons & (1 << g_p1_btn_map_b)) {
        *(u8 *)&g_pad_port_bits |= 0x40;
    }
    if (buttons & (1 << g_p1_btn_map_c)) {
        *(u8 *)&g_pad_port_bits |= 0x80;
    }
    *g_pad_port_dst = ~*(u8 *)&g_pad_port_bits;
    g_pad_port_dst++;

    g_pad_port_bits = 0;
    buttons = g_pad_held[1];
    if (buttons & SCE_PADstart) {
        *(u8 *)&g_pad_port_bits |= 0x01;
    }
    if (buttons & SCE_PADLup) {
        *(u8 *)&g_pad_port_bits |= 0x02;
    }
    if (buttons & SCE_PADLdown) {
        *(u8 *)&g_pad_port_bits |= 0x04;
    }
    if (buttons & SCE_PADLleft) {
        *(u8 *)&g_pad_port_bits |= 0x08;
    }
    if (buttons & SCE_PADLright) {
        *(u8 *)&g_pad_port_bits |= 0x10;
    }
    if (buttons & (1 << g_p2_btn_map_a)) {
        *(u8 *)&g_pad_port_bits |= 0x20;
    }
    if (buttons & (1 << g_p2_btn_map_b)) {
        *(u8 *)&g_pad_port_bits |= 0x40;
    }
    if (buttons & (1 << g_p2_btn_map_c)) {
        *(u8 *)&g_pad_port_bits |= 0x80;
    }
    *g_pad_port_dst = ~*(u8 *)&g_pad_port_bits;

    g_pad_port_dst = (u8 *)&g_arcade_coin_port;
    g_pad_port_bits = 0;
    if (g_pad_held[0] & SCE_PADselect) {
        *(u8 *)&g_pad_port_bits |= 0x01;
    }
    if (g_pad_held[1] & SCE_PADselect) {
        *(u8 *)&g_pad_port_bits |= 0x02;
    }
    *(u16 *)g_pad_port_dst = ~*(u16 *)&g_pad_port_bits;

    if (g_pad_input_locked != 0) {
        g_arcade_input_port[0] = g_arcade_input_port[1] = g_arcade_input_port[2] = g_arcade_input_port[3] =
            g_arcade_input_port[4] = g_arcade_input_port[5] = g_arcade_input_port[6] = g_arcade_input_port[7] = -1;
        gallery_reset_slot_states();
    }
}

void pad_open_ports(void)
{
#ifndef DDPDOJ_PC
    sceDevVif0Reset();
    sceDevVu0Reset();
    sceGsResetPath();
    sceDmaReset(1);
#endif
}

u8 g_pad_act_direct[6] __attribute__((aligned(64)));
u8 g_pad_act_align[6] __attribute__((aligned(64)));
void *g_pad_dma_buf;
void *g_dma_gif;

u8 g_pad_dma_buf_1[0x100] __attribute__((aligned(64)));
u8 g_pad_dma_buf_0[0x100] __attribute__((aligned(64)));
PadInfo g_pads[3];
u32 g_pad_held[4];
u32 g_pad_trigger[4];
u32 g_pad_repeat[4];
u32 g_pad_fast_repeat[4];
u32 g_pad_prev_held[4];
u32 g_pad_repeat_timer[4];
u32 g_pad_fast_repeat_timer[4];
u32 g_pad_unk_state[4];
u8 g_pad_dma_area[0x100];
