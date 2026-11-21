#include "common.h"

typedef struct {
    s16 next;
    s16 previous;
    s16 value;
    s16 reserved[3];
} LinkEntry;

extern s8 D_001A5240[0x2000];
extern s16 D_001A7240[][6];
extern s16 D_001A7242[][6];
extern s16 D_001A724C[];
extern LinkEntry D_001A7258[0xE2];
extern s8 D_001A7CF0[0x4588];
extern s16 D_001AC282[];
extern s16 D_001AC28C[];
extern LinkEntry D_001AC298[0x401];

#define SET_LINKS(entry, index) \
    (entry).next = (index); \
    (entry).previous = (index)

void func_0011E9E0(void)
{
    s32 index;
    s32 previousTail;
    LinkEntry *entry;
    LinkEntry *table;

    {
        s32 remaining = sizeof(D_001A7CF0);
        s8 *destination = D_001A7CF0;

        while (remaining--) {
            *destination++ = -1;
        }
    }

    {
        s32 remaining = sizeof(D_001A5240);
        s8 *destination = D_001A5240;

        while (remaining--) {
            *destination++ = -1;
        }
    }

    index = 2;
    entry = D_001AC298;
    do {
        SET_LINKS(entry[0], index - 2);
        SET_LINKS(entry[1], index - 1);
        SET_LINKS(entry[2], index);
        SET_LINKS(entry[3], index + 1);
        SET_LINKS(entry[4], index + 2);
        SET_LINKS(entry[5], index + 3);
        SET_LINKS(entry[6], index + 4);
        SET_LINKS(entry[7], index + 5);
        index += 8;
        entry += 8;
    } while (index < 0x402);

    D_001AC282[0] = -1;
    table = D_001AC298;
    D_001AC28C[0] = -2;
    for (index = 0; index < 0x401; index++) {
        if (index == table[index].previous) {
            previousTail = table[-2].previous;
            table[previousTail].next = index;
            table[-2].previous = index;
            table[index].next = -2;
            table[index].previous = previousTail;
            table[index].value = -1;
        }
    }

    entry = D_001A7258;
    index = 2;
    do {
        SET_LINKS(entry[0], index - 2);
        SET_LINKS(entry[1], index - 1);
        SET_LINKS(entry[2], index);
        SET_LINKS(entry[3], index + 1);
        SET_LINKS(entry[4], index + 2);
        SET_LINKS(entry[5], index + 3);
        SET_LINKS(entry[6], index + 4);
        SET_LINKS(entry[7], index + 5);
        index += 8;
        entry += 8;
    } while (index < 0xDB);

    D_001A7240[index][0] = index - 2;
    D_001A7242[index][0] = index - 2;

    D_001A7242[0][0] = -1;
    table = D_001A7258;
    D_001A724C[0] = -2;
    for (index = 0; index < 0xE2; index++) {
        if (index == table[index].previous) {
            previousTail = table[-2].previous;
            table[previousTail].next = index;
            table[-2].previous = index;
            table[index].next = -2;
            table[index].previous = previousTail;
            table[index].value = -1;
        }
    }
}

#undef SET_LINKS
