#include "common.h"

typedef struct {
    s32 first;
    s32 second;
} GalleryEntry;

extern const char *D_00128E90[];
extern const char *D_00128ED0[];
extern const char *D_00128F00[];
extern GalleryEntry D_00132620[];
extern GalleryEntry D_001326C0[];
extern GalleryEntry D_00132760[];
extern s32 D_001328C0[3];
extern s32 D_001328C4[3];

extern void func_0011B580(const char *source);

void func_0011B0B0(void)
{
    s32 index;
    const char **source;
    GalleryEntry *entry;

    index = 0;
    source = D_00128E90;
    entry = D_00132760;
    for (; index < 13; index++, source++, entry++) {
        func_0011B580(*source);
        entry->first = D_001328C4[0];
        entry->second = D_001328C0[0];
    }

    index = 0;
    source = D_00128ED0;
    entry = D_001326C0;
    for (; index < 10; index++, source++, entry++) {
        func_0011B580(*source);
        entry->first = D_001328C4[0];
        entry->second = D_001328C0[0];
    }

    index = 0;
    source = D_00128F00;
    entry = D_00132620;
    for (; index < 14; index++, source++, entry++) {
        func_0011B580(*source);
        entry->first = D_001328C4[0];
        entry->second = D_001328C0[0];
    }
}
