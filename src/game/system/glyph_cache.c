#include "common.h"
#include "sdk/ps2sdk.h"
#include "glyph_cache.h"

extern s16 g_glyph_cache_map[0x22C4];
extern s16 g_glyph_cache_sub_map[0x1000];

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

s32 glyph_cache_sub_lookup(u16 key)
{
    s16 *table = g_glyph_cache_sub_map;
    s32 slot = table[key];
    s32 previous;
    s32 next;
    s32 tail;
    s32 newSlot;
    GlyphCacheEntry *entries = g_glyph_cache_sub;
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
    entries[newSlot].x = (newSlot % 15) * 32 + 0x10;
    entries[newSlot].y = (newSlot / 15) * 32 + 0x10;
    entries[newSlot].flags = 0;
    return newSlot | 0x8000;
}

/* Puts the cells index..lastIndex that are not linked yet at the head of the list, marked unused. */
void glyph_cache_free_range(s32 index, s32 lastIndex, GlyphCacheEntry *entries)
{
    if (index <= lastIndex) {
        s32 entryOffset = index * sizeof(GlyphCacheEntry);

        do {
            GlyphCacheEntry *entry = (GlyphCacheEntry *)((u8 *)entries + entryOffset);
            s16 *next = &entry->next;

            if (index == *next) {
                s16 *head = &entries[-2].next;
                s16 oldHead = *head;

                entries[oldHead].previous = index;
                *head = index;
                entry->previous = -2;
                *next = oldHead;
                entry->key = -1;
            }

            index++;
            entryOffset += sizeof(GlyphCacheEntry);
        } while (index <= lastIndex);
    }
}

void glyph_cache_fill(s8 *dst, s8 value, s32 count) {
    while (count-- != 0) {
        *dst++ = value;
    }
}

void glyph_cache_clear_maps(void) {
    glyph_cache_fill((s8 *)g_glyph_cache_map, -1, sizeof(g_glyph_cache_map));
    glyph_cache_fill((s8 *)g_glyph_cache_sub_map, -1, sizeof(g_glyph_cache_sub_map));
}

void glyph_cache_init(void) {
    s32 i;

    glyph_cache_clear_maps();
    for (i = 2; i < 0x402; i++) {
        g_glyph_cache_storage.nodes[i].next = g_glyph_cache_storage.nodes[i].previous = i - 2;
    }
    g_glyph_cache_storage.list.head.next = -1;
    g_glyph_cache_storage.list.tail.previous = -2;
    glyph_cache_free_range(0, 0x400, g_glyph_cache);
    for (i = 2; i < 0xE3; i++) {
        g_glyph_cache_sub_storage.nodes[i].next = g_glyph_cache_sub_storage.nodes[i].previous = i - 2;
    }
    g_glyph_cache_sub_storage.list.head.next = -1;
    g_glyph_cache_sub_storage.list.tail.previous = -2;
    glyph_cache_free_range(0, 0xE1, g_glyph_cache_sub);
}

GlyphCacheStorage g_glyph_cache_storage __attribute__((aligned(16)));
s16 g_glyph_cache_map[0x22C4] __attribute__((aligned(16)));
SmallGlyphCacheStorage g_glyph_cache_sub_storage __attribute__((aligned(16)));
s16 g_glyph_cache_sub_map[0x1000] __attribute__((aligned(16)));

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

_Static_assert(sizeof(GlyphCacheEntry) == 12, "glyph cache entry stride");
_Static_assert(offsetof(GlyphCacheStorage, list.cells) == 24, "links before main cells");
_Static_assert(offsetof(SmallGlyphCacheStorage, list.cells) == 24, "links before small cells");
_Static_assert(offsetof(GlyphCacheStorage, list.end_probe) == 0x402 * 12, "main free range end");
_Static_assert(offsetof(SmallGlyphCacheStorage, list.end_probe) == 0xe3 * 12, "small free range end");
_Static_assert(sizeof(GlyphCacheStorage) == 0x403 * 12, "main cache save size");
_Static_assert(sizeof(SmallGlyphCacheStorage) == 0xe4 * 12, "small cache save size");

const PcFrameRegion pc_glyph_cache_regions[] = {
    PC_FRAME_REGION(g_glyph_cache_storage),
    PC_FRAME_REGION(g_glyph_cache_map),
    PC_FRAME_REGION(g_glyph_cache_sub_storage),
    PC_FRAME_REGION(g_glyph_cache_sub_map),
    { NULL, 0 },
};
#endif
