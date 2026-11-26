#ifndef DDPDOJ_SDK_LIBMC_H
#define DDPDOJ_SDK_LIBMC_H

#include "types.h"

s32 sceMcInit(void);
#ifdef DDPDOJ_PC
s32 sceMcGetInfo(s32 port, s32 slot, s32 *type, s32 *free_blocks, s32 *formatted);
s32 sceMcGetDir(s32 port, s32 slot, char *path, s32 mode, s32 count, void *entries);
s32 sceMcMkdir(s32 port, s32 slot, char *path);
s32 sceMcOpen(s32 port, s32 slot, char *path, s32 flags);
s32 sceMcClose(s32 fd);
s32 sceMcRead(s32 fd, void *buffer, s32 size);
s32 sceMcWrite(s32 fd, void *buffer, s32 size);
s32 sceMcFormat(s32 port, s32 slot);
s32 sceMcUnformat(s32 port, s32 slot);
s32 sceMcSync(s32 mode, s32 reserved, s32 *result);
#endif

#endif
