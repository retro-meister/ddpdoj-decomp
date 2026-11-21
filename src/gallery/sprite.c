#include "common.h"

typedef union {
    unsigned __int128 q;
    u64 d[2];
    u32 w[4];
} Qword;

typedef struct {
    s16 previous;
    s16 next;
    s16 key;
    s16 x;
    s16 y;
    s16 flags;
} GlyphCacheEntry;

typedef struct {
    s16 x;
    s16 y;
    u16 depth;
    u16 u;
    u16 v;
    u16 tex;
    u16 w;
    u16 h;
    u16 alpha;
} SpriteEntry;

extern s32 D_0012B308;
extern s8 *D_0012B30C;
extern void *D_0012B318;
extern SpriteEntry D_00132E80[];
extern u8 D_00180A80[2][0x10000];
extern s8 D_001A0A80[];
extern u64 D_001A4A80[12];
extern GlyphCacheEntry D_001AC298[];

extern s32 func_00100E08(s32 mode, s32 timeout);
extern s32 func_00101120(void *packet, s32 base, s32 bufferWidth, s32 format,
                         s32 x, s32 y, s32 width, s32 height);
extern s32 func_00101308(void *packet, const void *pixels);
extern void func_00101F48(void *dmaChannel, void *packet);
extern void func_00103220(s32 mode);
extern void func_0011C7E0(void *packet);
extern u64 func_0011C8B0(u64 shiftJis);
extern s32 func_0011EC80(u16 key);

void func_0011B930(Qword *pkt, s32 startIndex, s32 count)
{
    s32 x[4];
    s32 y[4];
    s32 u[4];
    s32 v[4];
    s32 uOffset[4] = { 9, -9, 9, -9 };
    s32 qwc;
    s32 i;
    s32 j;

    qwc = 1;
    pkt[0].q = 0;
    pkt[0].w[0] = (count << 4) | 0x10000000;

    for (i = 0; i < count; i++) {
        s32 z;
        s32 tex;
        s32 width;
        s32 height;
        s32 alpha;
        s32 cbp;

        x[0] = D_00132E80[startIndex].x;
        y[0] = D_00132E80[startIndex].y;
        z = D_00132E80[startIndex].depth;
        u[0] = D_00132E80[startIndex].u;
        v[0] = D_00132E80[startIndex].v;
        tex = D_00132E80[startIndex].tex;
        width = D_00132E80[startIndex].w;
        height = D_00132E80[startIndex].h;
        alpha = D_00132E80[startIndex].alpha;

        if (tex == 0x14) {
            cbp = 0x37FA;
        } else if (tex == 0x3832) {
            cbp = 0x3832;
        } else {
            cbp = tex + 0x37E8;
        }

        startIndex++;

        x[1] = x[0];
        x[2] = x[0];
        x[3] = x[0];
        y[1] = y[0];
        y[2] = y[0];
        y[3] = y[0];
        x[0] += width;
        x[1] += width;
        y[1] += height;
        y[3] += height;

        u[1] = u[0] + 0x1A;
        u[2] = u[0];
        u[3] = u[0] + 0x1A;
        v[1] = v[0];
        v[2] = v[0] + 0x1A;
        v[3] = v[0] + 0x1A;

        pkt[qwc].d[0] = 0x1000000000000002ULL;
        pkt[qwc].d[1] = 0xE;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = 0x3F;
        qwc++;

        if (cbp == 0x3832) {
            pkt[qwc].d[0] = ((u64)cbp << 37) | 0x20100006A9443800ULL;
        } else {
            pkt[qwc].d[0] = ((u64)cbp << 37) | 0x20000006A9443800ULL;
        }
        pkt[qwc].d[1] = 0x6;
        qwc++;

        pkt[qwc].d[0] = 0xC0AA400000008001ULL;
        pkt[qwc].d[1] = 0x0000431431431431ULL;
        qwc++;

        for (j = 0; j < 4; j++) {
            pkt[qwc].w[0] = 0x7F;
            pkt[qwc].w[1] = 0x7F;
            pkt[qwc].w[2] = 0x7F;
            pkt[qwc].w[3] = alpha;
            qwc++;

            pkt[qwc].w[0] = u[j] << 4;
            pkt[qwc].w[1] = v[j] << 4;
            pkt[qwc].w[2] = 0;
            pkt[qwc].w[3] = 0;
            if (cbp == 0x3832) {
                pkt[qwc].w[0] += uOffset[j];
            }
            qwc++;

            pkt[qwc].w[0] = (x[j] + 0x700) << 4;
            pkt[qwc].w[1] = (y[j] << 4) + 0x7900;
            pkt[qwc].w[2] = z << 4;
            pkt[qwc].w[3] = 0;
            qwc++;
        }
    }

    pkt[qwc].q = 0;
    pkt[qwc].w[0] = 0x70000000;
}

void func_0011BD30(void)
{
    s32 firstEntry;
    s32 remainingEntries;
    s32 batchCount;
    s32 bufferIndex;
    u8 *packet;

    if (D_0012B308 != 0) {
        func_0011C7E0(D_00180A80[0]);
        func_00103220(0);
        func_00101F48(D_0012B318, D_00180A80[0]);
        func_00100E08(0, 0);

        bufferIndex = 0;
        firstEntry = 0;
        while ((remainingEntries = D_0012B308) != 0) {
            if (remainingEntries >= 6) {
                batchCount = 6;
            } else {
                batchCount = remainingEntries;
            }

            packet = D_00180A80[bufferIndex];
            func_0011B930((Qword *)packet, firstEntry, batchCount);
            func_00100E08(0, 0);
            func_00103220(0);
            func_00101F48(D_0012B318, packet);

            D_0012B308 -= batchCount;
            firstEntry += batchCount;
            bufferIndex ^= 1;
        }
    }
}

void func_0011BE30(s16 x, s16 y, u16 textureId, u16 attributes, u16 scale)
{
    s32 id = textureId;
    s32 textureIndex;
    s32 uploaded = 0;
    GlyphCacheEntry *textures = D_001AC298;

    if (D_0012B308 < 0x200) {
        s32 queueIndex;
        s16 width;
        s16 height;

        textureIndex = func_0011EC80((u16)id);
        if (textureIndex & 0x8000) {
            s32 byteIndex;

            for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                D_001A0A80[byteIndex] = (D_0012B30C + id * 0x152)[byteIndex];
            }

            textureIndex &= 0x7FFF;
            func_00101120(D_001A4A80, 0x3800, 0x10, 0x14,
                          textures[textureIndex].x,
                          textures[textureIndex].y, 0x1A, 0x1A);
            func_00103220(0);
            func_00101308(D_001A4A80, D_001A0A80);
            uploaded++;
        }

        width = textures[textureIndex & 0x7FFF].x;
        height = textures[textureIndex & 0x7FFF].y;
        if (scale == 0) {
            scale = 1;
        }

        queueIndex = D_0012B308;
        D_00132E80[queueIndex].x = x;
        D_00132E80[queueIndex].y = y;
        D_00132E80[queueIndex].depth = scale;
        D_00132E80[queueIndex].u = width;
        D_00132E80[queueIndex].v = height;
        D_00132E80[queueIndex].tex = 0x3832;
        D_00132E80[queueIndex].w = 0x1B;
        D_00132E80[queueIndex].h = 0x1B;
        D_00132E80[queueIndex].alpha = attributes;
        D_0012B308++;
    }

    if (uploaded != 0) {
        func_00100E08(0, 0);
    }
}

void func_0011C0C0(Qword *packet, s32 firstEntry, s32 entryCount)
{
    s32 packetIndex;
    s32 entryIndex;

    packetIndex = 1;
    packet[0].q = 0;
    packet[0].w[0] = (entryCount * 10) | 0x10000000;

    for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
        s32 x = D_00132E80[firstEntry].x;
        s32 y = D_00132E80[firstEntry].y;
        s32 depth = D_00132E80[firstEntry].depth;
        s32 textureU = D_00132E80[firstEntry].u;
        s32 textureV = D_00132E80[firstEntry].v;
        s32 texturePage = D_00132E80[firstEntry].tex;
        s32 width = D_00132E80[firstEntry].w;
        s32 height = D_00132E80[firstEntry].h;
        s32 alpha = D_00132E80[firstEntry].alpha;
        s32 textureBase;
        s32 left;
        s32 right;

        if (texturePage == 0x14) {
            textureBase = 0x37FA;
        } else {
            textureBase = texturePage + 0x37E8;
        }

        firstEntry++;
        left = x + 0x700;
        right = left + width;
        depth <<= 4;
        height >>= 1;

        packet[packetIndex].d[0] = 0x1000000000000002ULL;
        packet[packetIndex].d[1] = 0x0E;
        packetIndex++;

        packet[packetIndex].d[0] = 0;
        packet[packetIndex].d[1] = 0x3F;
        packetIndex++;

        packet[packetIndex].d[0] =
            ((u64)textureBase << 37) | 0x20000006A9443800ULL;
        packet[packetIndex].d[1] = 0x06;
        packetIndex++;

        packet[packetIndex].d[0] = 0x60EB400000008001ULL;
        packet[packetIndex].d[1] = 0x431431;
        packetIndex++;

        packet[packetIndex].w[0] = 0x7F;
        packet[packetIndex].w[1] = 0x7F;
        packet[packetIndex].w[2] = 0x7F;
        packet[packetIndex].w[3] = alpha;
        packetIndex++;

        packet[packetIndex].w[0] = textureU << 4;
        packet[packetIndex].w[1] = textureV << 4;
        packet[packetIndex].w[2] = 0;
        packet[packetIndex].w[3] = 0;
        packetIndex++;

        packet[packetIndex].w[0] = (u32)left << 4;
        packet[packetIndex].w[1] = ((u32)y << 3) + 0x7900;
        packet[packetIndex].w[2] = depth;
        packet[packetIndex].w[3] = 0;
        packetIndex++;

        packet[packetIndex].w[0] = 0x7F;
        packet[packetIndex].w[1] = 0x7F;
        packet[packetIndex].w[2] = 0x7F;
        packet[packetIndex].w[3] = alpha;
        packetIndex++;

        packet[packetIndex].w[0] = (textureU + 0x1A) << 4;
        packet[packetIndex].w[1] = (textureV + 0x1A) << 4;
        packet[packetIndex].w[2] = 0;
        packet[packetIndex].w[3] = 0;
        packetIndex++;

        packet[packetIndex].w[0] = (u32)right << 4;
        packet[packetIndex].w[1] = ((height + 0x790) << 4) + ((u32)y << 3);
        packet[packetIndex].w[2] = depth;
        packet[packetIndex].w[3] = 0;
        packetIndex++;
    }

    packet[packetIndex].q = 0;
    packet[packetIndex].w[0] = 0x70000000;
}

void func_0011C360(void)
{
    s32 entryOffset;
    s32 batchSize;
    s32 remainingEntries;
    s32 bufferIndex;
    u8 *buffer;

    if (D_0012B308 != 0) {
        func_0011C7E0(D_00180A80[0]);
        func_00103220(0);
        func_00101F48(D_0012B318, D_00180A80[0]);
        func_00100E08(0, 0);

        bufferIndex = 0;
        entryOffset = 0;
        while ((remainingEntries = D_0012B308) != 0) {
            if (remainingEntries >= 6) {
                batchSize = 6;
            } else {
                batchSize = remainingEntries;
            }

            buffer = D_00180A80[bufferIndex];
            func_0011C0C0((Qword *)buffer, entryOffset, batchSize);
            func_00100E08(0, 0);
            func_00103220(0);
            func_00101F48(D_0012B318, buffer);

            entryOffset += batchSize;
            D_0012B308 -= batchSize;
            bufferIndex ^= 1;
        }
    }
}

void func_0011C460(s32 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth)
{
    s32 uploadCount = 0;
    s8 *uploadBuffer = D_001A0A80;
    GlyphCacheEntry *cache = D_001AC298;
    s8 leadByte;
    s32 shiftJis;
    u64 jis;
    u64 row;
    u64 col;
    s32 glyphIndex;
    s32 cacheIndex;
    s32 byteIndex;
    s32 bitmapOffset;
    s16 textureX;
    s16 textureY;
    SpriteEntry *drawEntry;

    while (((leadByte = *text) != 0) && (uploadCount < 30)) {
        shiftJis = (s8)leadByte;
        shiftJis &= 0xFF;
        shiftJis <<= 8;
        shiftJis |= (u8)text[1];
        text += 2;
        if (shiftJis == 0x818F) {
            break;
        }
        if ((D_0012B308 < 512) || (shiftJis != 0x8140)) {
            jis = func_0011C8B0((s64)shiftJis);
            row = ((jis >> 8) - 0x21) * 94;
            col = (jis & 0xFF) - 0x21;
            glyphIndex = (s32)(row + col);
            cacheIndex = func_0011EC80((u16)glyphIndex);
            if (cacheIndex & 0x8000) {
                bitmapOffset = glyphIndex * 0x152;
                for (byteIndex = 0; byteIndex < 0x14A; byteIndex += 8) {
                    uploadBuffer[byteIndex + 0] = ((D_0012B30C + bitmapOffset) + byteIndex)[0];
                    uploadBuffer[byteIndex + 1] = ((D_0012B30C + bitmapOffset) + byteIndex)[1];
                    uploadBuffer[byteIndex + 2] = ((D_0012B30C + bitmapOffset) + byteIndex)[2];
                    uploadBuffer[byteIndex + 3] = ((D_0012B30C + bitmapOffset) + byteIndex)[3];
                    uploadBuffer[byteIndex + 4] = ((D_0012B30C + bitmapOffset) + byteIndex)[4];
                    uploadBuffer[byteIndex + 5] = ((D_0012B30C + bitmapOffset) + byteIndex)[5];
                    uploadBuffer[byteIndex + 6] = ((D_0012B30C + bitmapOffset) + byteIndex)[6];
                    uploadBuffer[byteIndex + 7] = ((D_0012B30C + bitmapOffset) + byteIndex)[7];
                }

                uploadBuffer[byteIndex + 0] = ((D_0012B30C + bitmapOffset) + byteIndex)[0];
                uploadBuffer[byteIndex + 1] = ((D_0012B30C + bitmapOffset) + byteIndex)[1];
                cacheIndex &= 0x7FFF;
                func_00101120(D_001A4A80, 0x3800, 16, 20, cache[cacheIndex].x, cache[cacheIndex].y, 26, 26);
                func_00103220(0);
                func_00101308(D_001A4A80, uploadBuffer);
                uploadBuffer += 0x200;
                uploadCount++;
            }
            textureX = cache[cacheIndex & 0x7FFF].x;
            textureY = cache[cacheIndex & 0x7FFF].y;
            if (glyphWidth == 0) {
                glyphWidth = 26;
                glyphHeight = glyphWidth;
            }
            if (depth == 0) {
                depth = 1;
            }
            drawEntry = &D_00132E80[D_0012B308];
            drawEntry->x = x;
            drawEntry->y = y;
            drawEntry->depth = depth;
            drawEntry->u = textureX;
            drawEntry->v = textureY;
            drawEntry->tex = texturePage;
            drawEntry->w = glyphWidth;
            drawEntry->h = glyphHeight;
            drawEntry->alpha = alpha;
            D_0012B308++;
        }
        x = (s16)(x + ((s16)glyphWidth));
    }

    if (uploadCount != 0) {
        func_00100E08(0, 0);
    }
}

void func_0011C7D0(void)
{
    D_0012B308 = 0;
}
