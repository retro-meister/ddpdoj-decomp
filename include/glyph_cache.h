#ifndef DDPDOJ_GLYPH_CACHE_H
#define DDPDOJ_GLYPH_CACHE_H

#include "gfx_types.h"

/*
 * Two least-recently-used caches of 32x32 cells in the font textures: the main one (32 cells per row,
 * 0x401 cells) and a smaller one (15 cells per row, 0xE1 cells). The two entries in front of each list
 * are its head (-2) and tail (-1).
 */
typedef union {
    struct {
        GlyphCacheEntry head;
        GlyphCacheEntry tail;
        GlyphCacheEntry cells[0x400];
        /* free_range also examines the entry immediately following the linked cells. */
        GlyphCacheEntry end_probe;
    } list;
    GlyphCacheEntry nodes[0x403];
} GlyphCacheStorage;

typedef union {
    struct {
        GlyphCacheEntry head;
        GlyphCacheEntry tail;
        GlyphCacheEntry cells[0xe1];
        /* free_range also examines the entry immediately following the linked cells. */
        GlyphCacheEntry end_probe;
    } list;
    GlyphCacheEntry nodes[0xe4];
} SmallGlyphCacheStorage;

extern GlyphCacheStorage g_glyph_cache_storage;
extern SmallGlyphCacheStorage g_glyph_cache_sub_storage;

/* Link indices include -2 (head) and -1 (tail). */
#define g_glyph_cache (&g_glyph_cache_storage.nodes[2])
#define g_glyph_cache_sub (&g_glyph_cache_sub_storage.nodes[2])

void glyph_cache_init(void);
s32 glyph_cache_lookup(u16 key);
s32 glyph_cache_sub_lookup(u16 key);

#endif
