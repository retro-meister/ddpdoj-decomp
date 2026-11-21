#ifndef DDPDOJ_SDK_LIBPAD_H
#define DDPDOJ_SDK_LIBPAD_H

#include "types.h"

#define SCE_PADL2     0x0001
#define SCE_PADR2     0x0002
#define SCE_PADL1     0x0004
#define SCE_PADR1     0x0008
#define SCE_PADRup    0x0010
#define SCE_PADRright 0x0020
#define SCE_PADRdown  0x0040
#define SCE_PADRleft  0x0080
#define SCE_PADselect 0x0100
#define SCE_PADstart  0x0800
#define SCE_PADLup    0x1000
#define SCE_PADLright 0x2000
#define SCE_PADLdown  0x4000
#define SCE_PADLleft  0x8000

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
