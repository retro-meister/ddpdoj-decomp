#include "common.h"

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
