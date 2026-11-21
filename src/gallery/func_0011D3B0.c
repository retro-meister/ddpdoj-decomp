#include "common.h"

extern s32 D_0012B314;
extern u8 D_001A4A80[];

extern s32 func_00100E08(s32 mode, s32 count);
extern void func_00101120(void *packet, s16 sourceBase, s16 sourceWidth,
                          s16 pixelFormat, s16 x, s16 y, s16 width, s16 height);
extern s32 func_00101308(void *packet, void *destination);
extern s32 func_00103220(s32 mode);

void func_0011D3B0(u8 *destination, s32 mode, s32 blockCount)
{
    s32 blockIndex;

    func_00100E08(0, 0);

    switch (mode) {
    case 0:
        for (blockIndex = 0; blockIndex < blockCount; blockIndex++) {
            func_00101120(D_001A4A80, (s16)D_0012B314, 1, 2, 0, 0, 8, 2);
            func_00103220(0);
            func_00101308(D_001A4A80, destination);
            func_00100E08(0, 0);
            D_0012B314 += 1;
            destination += 0x80;
        }
        break;
    case 1:
        for (blockIndex = 0; blockIndex < blockCount; blockIndex++) {
            func_00101120(D_001A4A80, (s16)D_0012B314, 1, 2, 0, 0, 16, 16);
            func_00103220(0);
            func_00101308(D_001A4A80, destination);
            func_00100E08(0, 0);
            D_0012B314 += 4;
            destination += 0x80;
        }
        break;
    case 2:
        break;
    }
}
