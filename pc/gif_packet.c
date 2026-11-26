#include "sdk/eestruct.h"
#include "sdk/libpkt.h"

#include <stddef.h>
#include <string.h>

static void align_packet(sceGifPacket *packet)
{
    size_t offset = (size_t)(packet->cursor - packet->base);
    size_t padding = (16 - offset % 16) % 16;
    memset(packet->cursor, 0, padding);
    packet->cursor += padding;
}

void sceGifPkInit(sceGifPacket *packet, void *base)
{
    packet->base = base;
    sceGifPkReset(packet);
}

void sceGifPkReset(sceGifPacket *packet)
{
    packet->cursor = packet->base;
    packet->open_tag = NULL;
}

void sceGifPkTerminate(sceGifPacket *packet)
{
    align_packet(packet);
}

s32 sceGifPkSize(sceGifPacket *packet)
{
    return (s32)((packet->cursor - packet->base) / 16);
}

void sceGifPkAddGsData(sceGifPacket *packet, u64 data, ...)
{
    memcpy(packet->cursor, &data, sizeof(data));
    packet->cursor += sizeof(data);
}

void sceGifPkOpenGifTag(sceGifPacket *packet, unsigned __int128 tag)
{
    packet->open_tag = packet->cursor;
    sceGifPkAddGsData(packet, (u64)tag);
    sceGifPkAddGsData(packet, (u64)(tag >> 64));
}

void sceGifPkCloseGifTag(sceGifPacket *packet)
{
    u64 tag;
    memcpy(&tag, packet->open_tag, sizeof(tag));
    size_t words = (size_t)(packet->cursor - packet->open_tag - 16) / sizeof(u64);
    unsigned format = (tag >> 58) & 3;
    size_t loops = words / 2;
    if (format != SCE_GIF_IMAGE) {
        unsigned registers = tag >> 60;
        if (registers == 0) {
            registers = 16;
        }
        size_t entries = format == SCE_GIF_REGLIST ? words : words / 2;
        loops = (entries + registers - 1) / registers;
    }
    tag += loops;
    memcpy(packet->open_tag, &tag, sizeof(tag));
    packet->open_tag = NULL;
    align_packet(packet);
}

void sceGifPkAddGsAD(sceGifPacket *packet, s32 addr, u64 data)
{
    sceGifPkAddGsData(packet, data);
    sceGifPkAddGsData(packet, (u32)addr);
}
