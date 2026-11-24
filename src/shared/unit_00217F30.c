#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern GlyphCacheEntry D_00583FD8[];
extern s16 D_0057FA30_as_s16_a[];

s32 func_00217F30(u16 key)
{
    s16 *table = D_0057FA30_as_s16_a;
    s32 slot = table[key];
    s32 previous;
    s32 next;
    s32 tail;
    s32 newSlot;
    GlyphCacheEntry *entries = D_00583FD8;
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

extern GlyphCacheEntry D_0057EF98[];
extern s16 D_0057CF80_as_s16_a[];

s32 func_002180A0(u16 key)
{
    s16 *table = D_0057CF80_as_s16_a;
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

typedef struct {
    s16 next;
    s16 previous;
    s16 link;
    u8 data[6];
} ListEntry;

void func_00218210(s32 index, s32 lastIndex, ListEntry *entries)
{
    if (index <= lastIndex) {
        s32 entryOffset = index * sizeof(ListEntry);

        do {
            ListEntry *entry = (ListEntry *)((u8 *)entries + entryOffset);
            s16 *previousLink = &entry->previous;

            if (index == *previousLink) {
                s16 *head = (s16 *)((u8 *)entries - 0x16);
                s16 oldHead = *head;

                entries[oldHead].next = index;
                *head = index;
                entry->next = -2;
                *previousLink = oldHead;
                entry->link = -1;
            }

            index++;
            entryOffset += sizeof(ListEntry);
        } while (index <= lastIndex);
    }
}

void func_00218280(s8 *dst, s8 value, s32 count) {
    while (count-- != 0) {
        *dst++ = value;
    }
}

extern s32 D_0057CF80[];
extern s32 D_0057FA30[];

void func_002182B0(void) {
    func_00218280((void *)D_0057FA30, -1, 0x4588);
    func_00218280((void *)D_0057CF80, -1, 0x2000);
}

extern ListEntry D_0057EF80[];
extern ListEntry D_00583FC0[];

void func_002182F0(void) {
    s32 i;

    func_002182B0();
    for (i = 2; i < 0x402; i++) {
        D_00583FC0[i].previous = D_00583FC0[i].next = i - 2;
    }
    D_00583FC0[0].previous = -1;
    D_00583FC0[1].next = -2;
    func_00218210(0, 0x400, &D_00583FC0[2]);
    for (i = 2; i < 0xE3; i++) {
        D_0057EF80[i].previous = D_0057EF80[i].next = i - 2;
    }
    D_0057EF80[0].previous = -1;
    D_0057EF80[1].next = -2;
    func_00218210(0, 0xE1, &D_0057EF80[2]);
}
