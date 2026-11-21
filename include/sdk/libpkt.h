#ifndef DDPDOJ_SDK_LIBPKT_H
#define DDPDOJ_SDK_LIBPKT_H

#include "types.h"

typedef struct {
    u32 words[4];
} sceGifPacket;

void sceGifPkInit(sceGifPacket *packet, void *base);
void sceGifPkReset(sceGifPacket *packet);
void sceGifPkTerminate(sceGifPacket *packet);
s32 sceGifPkSize(sceGifPacket *packet);
void sceGifPkAddGsData(sceGifPacket *packet, u64 data, ...);

#endif
