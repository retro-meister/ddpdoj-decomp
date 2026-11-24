#include "common.h"

typedef struct {
    u8 trycount;
    u8 spindlctrl;
    u8 datapattern;
    u8 pad;
} CdReadMode;

s32 sceCdSync(s32 mode);
s32 sceCdDiskReady(s32 mode);
s32 sceCdRead(u32 sector, u32 count, void *destination, CdReadMode *mode);
s32 sceCdGetError(void);
s32 sceCdBreak(void);
s32 printf(const char *format, ...);
extern char D_00286ED8[];
extern u32 D_0028E9CC;
typedef struct {
    u32 lsn;
    u32 size;
    char name[16];
    u8 date[8];
} CdFile;

extern CdFile D_002C0100;
s32 sceCdSearchFile(CdFile *file, const char *path);

void func_00215F20(void *destination, const char *path)
{
    CdReadMode readMode;
    s32 error;

    do {
        sceCdDiskReady(0);
    } while (!sceCdSearchFile(&D_002C0100, path));

    for (;;) {
        do {
            sceCdDiskReady(0);
            D_0028E9CC = D_002C0100.size;
            readMode.trycount = 0;
            readMode.spindlctrl = 1;
            readMode.datapattern = 0;
        } while (!sceCdRead(D_002C0100.lsn, (D_002C0100.size + 0x7FF) >> 11, destination, &readMode));

        sceCdSync(0);
        error = sceCdGetError();
        if (error == 0) {
            break;
        }

        printf(D_00286ED8, error);
        sceCdBreak();
    }
}
