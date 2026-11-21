#ifndef DDPDOJ_SDK_LIBDMA_H
#define DDPDOJ_SDK_LIBDMA_H

#include "types.h"

void *sceDmaGetChan(s32 id);
void sceDmaReset(s32 mode);
void sceDmaSend(void *chan, void *tag);
void sceDmaSendN(void *chan, void *addr, s32 size);

#endif
