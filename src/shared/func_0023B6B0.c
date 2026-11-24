#include "common.h"

typedef struct {
    u8 pad[0x3511];
    s8 data[0x2000];
} Src;
extern s8 D_002B4D50_as_s8_a0x2000[0x2000];

void func_0023B6B0(const Src *src) {
    s32 i;
    for (i = 0; i < 0x2000; i++) {
        D_002B4D50_as_s8_a0x2000[i] = src->data[i];
    }
}
