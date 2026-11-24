#include "common.h"

typedef union {
    u32 w;
    u16 h[2];
} Pair;

static inline void func_0023D4E0_read(u16 *dst, u16 *mem, s32 addr) {
    u16 value;

    if (addr != 0) {
        value = *(u16 *)((u8 *)mem + ((s16)addr & ~1));
    } else {
        value = *mem;
    }
    *dst = value;
}

s32 func_0023D4E0(u8 *entry, u16 *mem, s32 op) {
    Pair r;
    u8 *tag;
    u16 addr;
    u8 lo;
    s32 base;

    tag = entry + 2;
    if (*tag != 0x99) {
        return -1;
    }
    if (entry[3] != op) {
        return 0;
    }
    switch (op) {
    case 0x80:
        addr = *(u16 *)entry;
        func_0023D4E0_read(&r.h[0], mem, addr);
        func_0023D4E0_read(&r.h[1], mem, addr + 2);
        *(u16 *)entry = r.h[1];
        *(u16 *)tag = r.h[0];
        break;
    case 0x81:
        lo = entry[1];
        base = entry[0];
        func_0023D4E0_read(&r.h[0], mem, lo);
        func_0023D4E0_read(&r.h[1], mem, lo + 2);
        r.w += base;
        *(u16 *)entry = r.h[1];
        *(u16 *)tag = r.h[0];
        break;
    case 0x82:
        r.w = (u32)mem + *(u16 *)entry;
        *(u16 *)entry = r.h[1];
        *(u16 *)tag = r.h[0];
        break;
    case 0x83:
        r.w = (u32)mem + *(u16 *)entry;
        *(u16 *)entry = r.h[0];
        *(u16 *)tag = r.h[1];
        break;
    default:
        return 0;
    }
    return 1;
}
