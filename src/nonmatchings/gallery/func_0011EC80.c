#include "common.h"

typedef struct {
    s16 previous;
    s16 next;
    s16 key;
    s16 x;
    s16 y;
    s16 flags;
} GalleryCacheEntry;

extern s16 D_001A7CF0[];
extern GalleryCacheEntry D_001AC298[];

s32 func_0011EC80(u16 key)
{
    s16 *table = D_001A7CF0;
    GalleryCacheEntry *entries = D_001AC298;
    s32 slot = table[key];
    s32 previous;
    s32 next;
    s32 tail;
    s32 newSlot;
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
