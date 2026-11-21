#include "common.h"

extern u16 D_00128AE0[];
extern void func_00102B58(void *packet, u64 word, ...);

void func_00123480(void *packet, s32 x, s32 y, u8 glyphIndex)
{
    u16 glyphs[2];
    u16 firstGlyph;
    u16 *glyph;
    s32 row;
    s32 screenTop;
    s64 screenLeft;
    s64 screenRight;

    firstGlyph = D_00128AE0[glyphIndex];
    glyphs[0] = firstGlyph;
    glyphs[1] = firstGlyph + 16;

    func_00102B58(packet, 0xA400000000008002ULL);
    func_00102B58(packet, 0x0000005353535310ULL);

    glyph = glyphs;
    row = 0;
    screenTop = y * 8 + 0x7900;
    screenLeft = x * 16 + 0x6C00;
    screenRight = (x + 16) * 16 + 0x6C00;

    for (; row < 2; row++, screenTop += 64, glyph++, y += 8) {
        s32 tile = *glyph;
        s32 textureLeft = (tile % 126 + 1) * 8;
        s32 textureTop = (tile / 126 + 1) * 8;

        func_00102B58(packet, 0x115, tile);
        func_00102B58(packet, 0x3F80000080808080ULL);
        func_00102B58(packet, (u64)(s64)((textureLeft + 7) * 16) |
                              ((u64)(s64)(textureTop * 16) << 16));
        func_00102B58(packet, (u64)screenLeft |
                              ((u64)(s64)screenTop << 16));
        func_00102B58(packet, (u64)(s64)((textureLeft + 7) * 16) |
                              ((u64)(s64)((textureTop + 7) * 16) << 16));
        func_00102B58(packet, (u64)screenRight |
                              ((u64)(s64)screenTop << 16));
        func_00102B58(packet, (u64)(s64)(textureLeft * 16) |
                              ((u64)(s64)((textureTop + 7) * 16) << 16));
        func_00102B58(packet, (u64)screenRight |
                              ((u64)(s64)((y + 8) * 8 + 0x7900) << 16));
        func_00102B58(packet, (u64)(s64)(textureLeft * 16) |
                              ((u64)(s64)(textureTop * 16) << 16));
        func_00102B58(packet, (u64)screenLeft |
                              ((u64)(s64)((y + 8) * 8 + 0x7900) << 16));
    }
}
