#include "gallery/gallery.h"

extern s8 g_glyph_cache_sub_map[0x2000];
extern GlyphCacheEntry g_glyph_cache_sub[0xE3];
extern s16 g_glyph_cache_map[0x22C4];

void glyph_cache_init(void)
{
    GlyphCacheEntry *table;
    s32 index;
    s32 i;
    s32 j;
    s32 previousTail;
    {
        s8 *destination = (s8 *)g_glyph_cache_map;
        s32 remaining = sizeof(g_glyph_cache_map);
        while (remaining--) {
            *(destination++) = -1;
        }
    }
    {
        s8 *destination = g_glyph_cache_sub_map;
        s32 remaining = sizeof(g_glyph_cache_sub_map);
        while (remaining--) {
            *(destination++) = -1;
        }
    }
    {
        GlyphCacheEntry *p;
        for (index = 2, p = g_glyph_cache; index < 0x402; index++, p++) {
            p->previous = index - 2;
            p->next = index - 2;
        }
    }
    g_glyph_cache[-2].next = -1;
    g_glyph_cache[-1].previous = -2;
    table = g_glyph_cache;
    for (i = 0; i <= 0x400; i++) {
        if (i == table[i].next) {
            previousTail = table[-2].next;
            table[previousTail].previous = i;
            table[-2].next = i;
            table[i].previous = -2;
            table[i].next = previousTail;
            table[i].key = -1;
        }
    }
    for (index = 2; index < 0xE3; index++) {
        g_glyph_cache_sub[index].previous = index - 2;
        g_glyph_cache_sub[index].next = index - 2;
    }

    table = &g_glyph_cache_sub[2];
    g_glyph_cache_sub[0].next = -1;
    g_glyph_cache_sub[1].previous = -2;
    for (j = 0; j <= 0xE1; j++) {
        if (j == table[j].next) {
            previousTail = table[-2].next;
            table[previousTail].previous = j;
            table[-2].next = j;
            table[j].previous = -2;
            table[j].next = previousTail;
            table[j].key = -1;
        }
    }
}

s32 glyph_cache_lookup(u16 key)
{
    s16 *table = g_glyph_cache_map;
    s32 slot = table[key];
    s32 previous;
    s32 next;
    s32 tail;
    s32 newSlot;
    GlyphCacheEntry *entries = g_glyph_cache;
    s32 oldKey;
    if (slot >= 0) {
        previous = entries[slot].previous;
        next = entries[slot].next;
        entries[previous].next = next;
        entries[next].previous = previous;
        tail = entries[-1].previous;
        entries[tail].next = slot;
        entries[slot].previous = tail;
        entries[slot].next = -1;
        entries[-1].previous = slot;
        return slot;
    }
    newSlot = entries[-2].next;
    oldKey = entries[newSlot].key;
    if (oldKey >= 0) {
        table[oldKey] = -1;
    }
    entries[newSlot].key = key;
    next = entries[newSlot].next;
    entries[-2].next = next;
    entries[next].previous = -2;
    tail = entries[-1].previous;
    entries[tail].next = newSlot;
    entries[newSlot].previous = tail;
    entries[newSlot].next = -1;
    entries[-1].previous = newSlot;
    table[key] = newSlot;
    entries[newSlot].x = (newSlot % 32) * 32;
    entries[newSlot].y = (newSlot / 32) * 32;
    entries[newSlot].flags = 0;
    return newSlot | 0x8000;
}
