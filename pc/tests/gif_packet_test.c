#include "gif_stream.h"
#include "sdk/eestruct.h"
#include "sdk/libpkt.h"

#include <stdio.h>
#include <string.h>

typedef struct {
    u8 address[12];
    u64 value[12];
    unsigned count;
    bool received_packed;
    bool received_image;
} TestSink;

static void capture_register(void *context, u8 address, u64 value)
{
    TestSink *test = context;
    if (test->count < sizeof(test->address)) {
        test->address[test->count] = address;
        test->value[test->count] = value;
    }
    test->count++;
}

static void capture_packed(void *context, u8 descriptor, u64 low, u64 high)
{
    TestSink *test = context;
    test->received_packed = descriptor == SCE_GS_UV && low == 0x3000000020ULL && high == 0;
}

static void capture_image(void *context, const void *data, size_t size)
{
    TestSink *test = context;
    const u64 expected[] = { 0x03020100, 0x07060504 };
    test->received_image = size == sizeof(expected) && memcmp(data, expected, size) == 0;
}

static bool verify_decode(const u64 *packet, size_t size)
{
    const PcGifSink sink = { capture_register, capture_packed, capture_image };
    const u8 addresses[] = { SCE_GS_TEX0_1, SCE_GS_ALPHA_1, SCE_GS_PRIM,
                             SCE_GS_RGBAQ, SCE_GS_XYZ2, SCE_GS_PRIM };
    const u64 values[] = { 0x0123456789ABCDEFULL, 128, 6, 0x80808080, 0x79006C00, 6 };
    TestSink test = {0};

    if (!pc_gif_decode(packet, size, &sink, &test) || test.count != sizeof(addresses) ||
        memcmp(test.address, addresses, sizeof(addresses)) != 0 ||
        memcmp(test.value, values, sizeof(values)) != 0 ||
        !test.received_packed || !test.received_image) {
        return false;
    }

    test = (TestSink){0};
    return !pc_gif_decode(packet, 31, &sink, &test) &&
           !pc_gif_decode(packet, 32, &sink, &test) && test.count == 0;
}

int main(void)
{
    sceGifPacket packet;
    u64 buffer[24];
    const u64 packed = SCE_GIF_SET_TAG(0, 1, 0, 0, SCE_GIF_PACKED, 1);
    const u64 reglist = SCE_GIF_SET_TAG(0, 1, 0, 0, SCE_GIF_REGLIST, 3);
    const u64 expected[] = {
        packed + 2, SCE_GIF_PACKED_AD,
        0x0123456789ABCDEFULL, SCE_GS_TEX0_1,
        128, SCE_GS_ALPHA_1,
        reglist + 1, 0x510,
        6, 0x80808080, 0x79006C00, 0,
    };

    memset(buffer, 0xFF, sizeof(buffer));
    sceGifPkInit(&packet, buffer);
    sceGifPkOpenGifTag(&packet, (unsigned __int128)SCE_GIF_PACKED_AD << 64 | packed);
    sceGifPkAddGsAD(&packet, SCE_GS_TEX0_1, 0x0123456789ABCDEFULL);
    sceGifPkAddGsAD(&packet, SCE_GS_ALPHA_1, 128);
    sceGifPkCloseGifTag(&packet);
    sceGifPkOpenGifTag(&packet, (unsigned __int128)0x510 << 64 | reglist);
    sceGifPkAddGsData(&packet, 6);
    sceGifPkAddGsData(&packet, 0x80808080);
    sceGifPkAddGsData(&packet, 0x79006C00);
    sceGifPkCloseGifTag(&packet);
    sceGifPkTerminate(&packet);
    if (sceGifPkSize(&packet) != 6 || memcmp(expected, buffer, sizeof(expected)) != 0 ||
        buffer[12] != ~0ULL) {
        fputs("Generated GIF packet differs from the expected quadwords\n", stderr);
        return 1;
    }

    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 1, 6, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GS_UV);
    sceGifPkAddGsData(&packet, 0x3000000020ULL);
    sceGifPkAddGsData(&packet, 0);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_IMAGE, 0));
    sceGifPkAddGsData(&packet, 0);
    sceGifPkAddGsData(&packet, 0x03020100);
    sceGifPkAddGsData(&packet, 0x07060504);
    if (!verify_decode(buffer, (size_t)sceGifPkSize(&packet) * 16)) {
        fputs("GIF stream decoding or bounds checking is incorrect\n", stderr);
        return 1;
    }

    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, reglist + 1);
    sceGifPkAddGsData(&packet, 0x510);
    sceGifPkAddGsData(&packet, 6);
    sceGifPkAddGsData(&packet, 0x80808080);
    sceGifPkAddGsData(&packet, 0x79006C00);
    sceGifPkTerminate(&packet);
    if (sceGifPkSize(&packet) != 3 || memcmp(expected + 6, buffer, 6 * sizeof(u64)) != 0) {
        fputs("Gallery GIF packet padding or reset is incorrect\n", stderr);
        return 1;
    }
    return 0;
}
