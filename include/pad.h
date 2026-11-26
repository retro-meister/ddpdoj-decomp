#ifndef DDPDOJ_PAD_H
#define DDPDOJ_PAD_H

#include "common.h"

/* State of one controller port; g_pads[2] is both ports merged. */
typedef struct {
    /* 0x00 */ u8 raw[0x20];
    /* 0x20 */ u32 buttons;
    /* 0x24 */ u32 trigger;
    /* 0x28 */ u32 prevButtons;
    /* 0x2C */ u32 rawButtons;
    /* 0x30 */ u16 extraButtons;
    /* 0x32 */ s8 analogX;
    /* 0x33 */ s8 analogY;
#ifdef DEATH_LABEL
    /* 0x34 */ s8 rightX;
    /* 0x35 */ s8 rightY;
#else
    /* 0x34 */ u16 unk34;
#endif
    /* 0x36 */ u8 state;
    /* 0x37 */ u8 padId;
    /* 0x38 */ u8 prevPadId;
    /* 0x39 */ u8 padTypeFlag;
    /* 0x3A */ u8 pad3A[2];
} PadInfo;

extern PadInfo g_pads[3];

/* Button state per port (index 2: both ports), with the left stick folded into the direction buttons. */
extern u32 g_pad_held[4];
extern u32 g_pad_trigger[4];           /* pressed this frame */
extern u32 g_pad_repeat[4];            /* pressed, then again every 11 frames while held */
extern u32 g_pad_fast_repeat[4];       /* pressed, then after 11 frames again every 4 frames while held */
extern u32 g_pad_prev_held[4];
extern u32 g_pad_repeat_timer[4];
extern u32 g_pad_fast_repeat_timer[4];
extern u32 g_pad_unused[4];

#ifdef DDPDOJ_PC
extern u16 g_pad_vib_power_p1, g_pad_vib_power_p2;
extern u16 g_pad_vib_timer_p1, g_pad_vib_timer_p2;
extern u8 g_pad_vib_state_p1, g_pad_vib_state_p2;
#endif

void pad_init_system(void);
void pad_poll_hardware(void);
void pad_update(void);
void pad_mask_game_inputs(void);

#endif
