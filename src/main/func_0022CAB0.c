#include "common.h"

extern s32 printf(const char *format, ...);
extern char D_0028B360[];
extern u32 D_0028ED1C;
extern s8 D_006A4800[];
extern s32 D_006C4AE8[];
extern s8 D_006C4EF0[];
extern s32 D_006C5494[];

s32 func_0022CAB0(void) {
    s32 size;
    s32 i;
    s8 *data;
    s32 sum;
    s32 result;

    switch (D_0028ED1C) {
    case 0:
        data = D_006C4EF0;
        size = 0x5A4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        size = 0x202E8;
        data = D_006A4800;
        break;
    }
    sum = 0;
    for (i = 0; i < size; i++) {
        sum ^= *data++;
    }
    printf(D_0028B360, D_0028ED1C, size, sum);
    result = 0;
    switch (D_0028ED1C) {
    case 0:
        if (D_006C5494[0] != sum) {
            result = 1;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        if (D_006C4AE8[0] != sum) {
            result = 1;
        }
        break;
    }
    return result;
}
