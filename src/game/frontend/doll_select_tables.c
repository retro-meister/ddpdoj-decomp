/* Tables of the doll selection. */
#include "common.h"
#include "doll_select.h"

DollSelectPlayer doll_select_p1 = { 0, { 1, 2 }, { 3, 4 }, 0x5000, 0xE00, 0 };
DollSelectPlayer doll_select_p2 = { 0x200, { 1, 2 }, { 3, 4 }, 0x1C00, 0xE00, 0 };

char doll_select_blank[16] = "           ";

/* What a player's choice 0..2 is stored as. */
u16 doll_select_values[4] = { 2, 4, 6 };

/* The order in which each player is offered a doll the other has not taken. */
u16 doll_select_order_p1[4] = { 0, 1, 2 };
u16 doll_select_order_p2[4] = { 2, 1, 0 };
