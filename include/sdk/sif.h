#ifndef DDPDOJ_SDK_SIF_H
#define DDPDOJ_SDK_SIF_H

#include "types.h"

typedef struct _sif_rpc_data {
    void *paddr;
    u32 pid;
    s32 tid;
    u32 mode;
} sceSifRpcData;

typedef void (*sceSifEndFunc)(void *);

typedef struct _sif_client_data {
    sceSifRpcData rpcd;
    u32 command;
    void *buff;
    void *gp;
    sceSifEndFunc func;
    void *para;
    void *serve;
} sceSifClientData;

void sceSifExitCmd(void);
void sceSifInitRpc(s32 mode);
s32 sceSifBindRpc(sceSifClientData *cd, u32 sid, u32 mode);
s32 sceSifCallRpc(sceSifClientData *cd, u32 fno, u32 mode, void *send, s32 ssize, void *recv, s32 rsize, sceSifEndFunc end_func, void *end_param);
s32 sceFsReset(void);
s32 sceSifLoadModule(const char *filename, s32 args, const char *argp);
s32 sceSifSyncIop(void);
s32 sceSifRebootIop(const char *img);

#endif
