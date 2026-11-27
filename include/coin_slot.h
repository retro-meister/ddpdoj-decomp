#ifndef DDPDOJ_COIN_SLOT_H
#define DDPDOJ_COIN_SLOT_H

#include "types.h"

typedef struct {
    struct {
        /* 0x00 */ u8 unread_00;
        u8 phase;
        u16 held_frames;
    } pulse;
    struct {
        u16 status;
        /* 0x06 */ u16 unused_06;
    } result;
} CoinSlot;

extern CoinSlot g_coin_slot_1[];
extern CoinSlot g_coin_slot_2[];

#endif
