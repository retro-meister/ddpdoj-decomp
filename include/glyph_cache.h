#ifndef DDPDOJ_GLYPH_CACHE_H
#define DDPDOJ_GLYPH_CACHE_H

#include "gfx_types.h"

/*
 * Two least-recently-used caches of 32x32 cells in the font textures: the main one (32 cells per row,
 * 0x401 cells) and a smaller one (15 cells per row, 0xE1 cells). The two entries in front of each list
 * are its head (-2) and tail (-1).
 */
extern GlyphCacheEntry g_glyph_cache_storage[0x403];
extern GlyphCacheEntry g_glyph_cache_sub_storage[0xE3];
#define g_glyph_cache (&g_glyph_cache_storage[2])
#define g_glyph_cache_sub (&g_glyph_cache_sub_storage[2])

void glyph_cache_init(void);
s32 glyph_cache_lookup(u16 key);
s32 glyph_cache_sub_lookup(u16 key);

#endif
