#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern GlyphCacheEntry D_0057EF98[];
extern s16 D_0057CF80[];

s32 func_002180A0(u16 key)
{
    s16 *table = D_0057CF80;
    s32 slot = table[key];
    s32 previous;
    s32 next;
    s32 tail;
    s32 newSlot;
    GlyphCacheEntry *entries = D_0057EF98;
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
