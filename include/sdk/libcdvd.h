#ifndef DDPDOJ_SDK_LIBCDVD_H
#define DDPDOJ_SDK_LIBCDVD_H

#include "types.h"

#define SCECdINIT         0x00
#define SCECdSecS2048     0
#define SCECdSpinNom      1
#define SCECdComplete     0x02

typedef struct {
    u8 trycount;
    u8 spindlctrl;
    u8 datapattern;
    u8 pad;
} sceCdRMode;

typedef struct {
    u32 lsn;
    u32 size;
    char name[16];
    u8 date[8];
    u32 flag;
} sceCdlFILE;

typedef struct {
    u8 stat;
    u8 second;
    u8 minute;
    u8 hour;
    u8 pad;
    u8 day;
    u8 month;
    u8 year;
} sceCdCLOCK;

s32 sceCdReadClock(sceCdCLOCK *clock);
s32 sceCdSearchFile(sceCdlFILE *fp, const char *name);
s32 sceCdSync(s32 mode);
s32 sceCdInit(s32 init_mode);
s32 sceCdDiskReady(s32 mode);
s32 sceCdMmode(s32 media);
s32 sceCdRead(u32 lbn, u32 sectors, void *buf, sceCdRMode *mode);
s32 sceCdGetError(void);
void sceCdBreak(void);

#endif
