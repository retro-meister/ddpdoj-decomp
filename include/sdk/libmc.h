#ifndef DDPDOJ_SDK_LIBMC_H
#define DDPDOJ_SDK_LIBMC_H

#include "types.h"

s32 sceMcInit(void);
#ifdef DDPDOJ_PC
s32 sceMcGetInfo(s32 port, s32 slot, s32 *type, s32 *free_blocks, s32 *formatted);
#endif

#endif
