#ifndef DDPDOJ_DEBUG_VIEWS_H
#define DDPDOJ_DEBUG_VIEWS_H

#include "types.h"

/* One list of records for a viewer that this build does not have. The start-up fill puts the address in. */
typedef struct {
    /* 0x00 */ u16 last_word;       /* entry_size / 2 - 1 */
    /* 0x02 */ u16 last_entry;
    /* 0x04 */ u16 entry_size;
    /* 0x06 */ u16 entries[2];
    /* 0x0A */ u16 other_0A;
    /* 0x0C */ u16 other_0C;
    /* 0x0E */ char title[18];
} DebugListView;

typedef struct {
    /* 0x00 */ u16 other_00[4];
    /* 0x08 */ u16 table[2];
    /* 0x0C */ u16 other_0C;
    /* 0x0E */ u16 other_0E;
} DebugTableView;

extern DebugListView debug_list_views[34];
extern DebugTableView debug_table_views[3];

#endif
