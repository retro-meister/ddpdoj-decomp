#include "common.h"

extern void memset(void *dst, s32 value, u32 size);
extern u8 D_00299D30[];

void func_00209E60(void) {
    memset(&D_00299D30[0], 0, 0x7FC);
}
