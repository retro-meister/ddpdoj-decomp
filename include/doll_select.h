#ifndef DDPDOJ_DOLL_SELECT_H
#define DDPDOJ_DOLL_SELECT_H

#include "types.h"

/* What the doll selection needs to know about one player. */
typedef struct {
    /* 0x00 */ u16 other_00;
    /* 0x02 */ u16 held[2];          /* input routines; the start-up fill puts their addresses here */
    /* 0x06 */ u16 pressed[2];
    /* 0x0A */ u16 text_x;
    /* 0x0C */ u16 text_y;
    /* 0x0E */ u16 unused_0E;
} DollSelectPlayer;

extern DollSelectPlayer doll_select_p1;
extern DollSelectPlayer doll_select_p2;
extern char doll_select_blank[16];
extern u16 doll_select_values[4];
extern u16 doll_select_order_p1[4];
extern u16 doll_select_order_p2[4];

#endif
