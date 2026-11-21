#ifndef DDPDOJ_SDK_LIBCDVD_H
#define DDPDOJ_SDK_LIBCDVD_H

#include "types.h"

typedef struct {
    u8 trycount;
    u8 spindlctrl;
    u8 datapattern;
    u8 pad;
} sceCdRMode;

s32 sceCdSearchFile(void *fp, const char *name);
s32 sceCdSync(s32 mode);
s32 sceCdInit(s32 init_mode);
s32 sceCdDiskReady(s32 mode);
s32 sceCdMmode(s32 media);
s32 sceCdRead(u32 lbn, u32 sectors, void *buf, sceCdRMode *mode);
s32 sceCdGetError(void);
void sceCdBreak(void);

#endif
