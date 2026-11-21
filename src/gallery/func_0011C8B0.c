#include "common.h"

u64 func_0011C8B0(u64 shiftJis)
{
    u64 leadByte = (shiftJis >> 8) & 0xFF;
    u64 trailByte = shiftJis & 0xFF;

    if (leadByte >= 0x81 && leadByte < 0xA0) {
        leadByte -= 0x81;
    } else if (leadByte >= 0xE0 && leadByte < 0xF0) {
        leadByte += 0xFFFFFFFFFFFFFF3FULL;
    }

    leadByte <<= 1;
    if (trailByte >= 0x40 && trailByte < 0x7F) {
        trailByte -= 0x40;
    } else if (trailByte >= 0x80 && trailByte < 0x9F) {
        trailByte += 0xFFFFFFFFFFFFFFBFULL;
    } else if (trailByte >= 0x9F && trailByte < 0xFD) {
        trailByte -= 0x9F;
        leadByte++;
    }

    return ((leadByte + 1) << 8) + trailByte + 0x2021;
}
