#ifndef DDPDOJ_SDK_LIBPAD_H
#define DDPDOJ_SDK_LIBPAD_H

#include "types.h"

s32 scePadInit(s32 mode);
s32 scePadPortOpen(s32 port, s32 slot, void *addr);
s32 scePadRead(s32 port, s32 slot, u8 *rdata);
s32 scePadGetState(s32 port, s32 slot);
s32 scePadGetReqState(s32 port, s32 slot);
s32 scePadInfoAct(s32 port, s32 slot, s32 actno, s32 term);
s32 scePadInfoMode(s32 port, s32 slot, s32 term, s32 offs);
s32 scePadSetMainMode(s32 port, s32 slot, s32 offs, s32 lock);
void scePadSetActDirect(s32 port, s32 slot, u8 *data);
s32 scePadSetActAlign(s32 port, s32 slot, u8 *data);
s32 scePadInfoPressMode(s32 port, s32 slot);
s32 scePadEnterPressMode(s32 port, s32 slot);

#endif
