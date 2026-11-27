#ifndef DDPDOJ_GFX_TYPES_H
#define DDPDOJ_GFX_TYPES_H

#include "types.h"

/* Types the graphics layer of all three executables shares. */

/* Some PS2 callers extend the color box alpha to a doubleword. */
#ifdef DDPDOJ_PC
typedef s32 GfxBoxAlphaArg;
#else
typedef s64 GfxBoxAlphaArg;
#endif

/* One 128-bit DMA/GIF quadword. */
typedef union {
    unsigned __int128 q;
    u64 d[2];
    u32 w[4];
} Qword;

/* Node of the glyph cache's doubly linked list: which character occupies which cell of the font texture. */
typedef struct {
    s16 previous;
    s16 next;
    s16 key;
    s16 x;
    s16 y;
    s16 flags;
} GlyphCacheEntry;

#endif
