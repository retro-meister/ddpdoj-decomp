#include "common.h"

extern void func_002150C0(s16 x, s16 y, s32 tile, u16 alpha, s32 z);

void func_00214F50(s32 alpha) {
    s32 pos;
    s32 i;

    func_002150C0(-6, 0, 0x2289, alpha, 300);
    for (pos = 16, i = 0; i < 12; i++, pos += 16) {
        func_002150C0(-6, pos, 0x228A, alpha, 300);
    }
    func_002150C0(-6, pos, 0x228B, alpha, 300);
    for (pos = 10, i = 0; i < 6; i++, pos += 16) {
        func_002150C0(pos, 0, 0x2287, alpha, 300);
    }
    for (pos = 10, i = 0; i < 6; i++, pos += 16) {
        func_002150C0(pos, 0xD0, 0x2288, alpha, 300);
    }
    func_002150C0(0x6A, 0, 0x2284, alpha, 300);
    for (pos = 16, i = 0; i < 12; i++, pos += 16) {
        func_002150C0(0x6A, pos, 0x2285, alpha, 300);
    }
    func_002150C0(0x6A, pos, 0x2286, alpha, 300);
}
