#ifndef DDPDOJ_SDK_LIBPKT_H
#define DDPDOJ_SDK_LIBPKT_H

#include "types.h"

typedef struct {
#ifdef DDPDOJ_PC
    u8 *base;
    u8 *cursor;
    u8 *open_tag;
#else
    u32 words[4];
#endif
} sceGifPacket;

void sceGifPkInit(sceGifPacket *packet, void *base);
void sceGifPkReset(sceGifPacket *packet);
void sceGifPkTerminate(sceGifPacket *packet);
s32 sceGifPkSize(sceGifPacket *packet);
void sceGifPkAddGsData(sceGifPacket *packet, u64 data, ...);
#ifdef DDPDOJ_PC
void sceGifPkOpenGifTag(sceGifPacket *packet, unsigned __int128 tag);
void sceGifPkCloseGifTag(sceGifPacket *packet);
void sceGifPkAddGsAD(sceGifPacket *packet, s32 addr, u64 data);
#endif

#endif
