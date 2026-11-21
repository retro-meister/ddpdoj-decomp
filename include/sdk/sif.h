#ifndef DDPDOJ_SDK_SIF_H
#define DDPDOJ_SDK_SIF_H

#include "types.h"

void sceSifExitCmd(void);
void sceSifInitRpc(s32 mode);
s32 sceSifBindRpc(void *cd, u32 sid, u32 mode);
s32 sceSifCallRpc(void *cd, u32 fno, u32 mode, void *send, s32 ssize, void *recv, s32 rsize, void *end_func, void *end_param);
s32 sceFsReset(void);
s32 sceSifLoadModule(const char *filename, s32 args, const char *argp);
s32 sceSifSyncIop(void);
s32 sceSifRebootIop(const char *img);

#endif
