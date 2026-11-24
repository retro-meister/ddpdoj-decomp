#include "common.h"
#include "sdk/ps2sdk.h"

u64 func_00212E50(u64 sjis) {
    u64 hi = (sjis >> 8) & 0xFF;
    u64 lo = sjis & 0xFF;

    if (hi >= 0x81 && hi < 0xA0) {
        hi -= 0x81;
    } else if (hi >= 0xE0 && hi < 0xF0) {
        hi += -0xC1LL;
    }
    hi *= 2;
    if (lo >= 0x40 && lo < 0x7F) {
        lo -= 0x40;
    } else if (lo >= 0x80 && lo < 0x9F) {
        lo += -0x41LL;
    } else if (lo >= 0x9F && lo < 0xFD) {
        lo -= 0x9F;
        hi += 1;
    }
    return ((hi + 1) << 8) + lo + 0x2021;
}
