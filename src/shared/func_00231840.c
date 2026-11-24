#include "common.h"

s32 printf(const char *format, ...);
extern char D_0028BBF0[];
extern char D_0028BC00[];
extern u8 D_0028ED30;
extern u8 D_0028ED35;
extern u8 D_006A0E50[];
extern u8 D_006A0E88[];
extern u8 D_006A0E89[];
extern u8 D_006A0E8A[];
extern u8 D_006A0E8B[];
extern u8 D_006A0E8C[];
extern u8 D_006A0E8D[];

s32 func_00231840(void) {
    s32 i;
    s32 offset;
    u8 *save;
    s32 j;
    s32 count;
    s32 k;

    D_0028ED35 += 1;
    if (D_0028ED35 < 11) {
        printf(D_0028BBF0, D_0028ED35);
        for (i = 0, offset = 0; i < 10; i++, offset += 0x400) {
            save = D_006A0E50 + offset;
            printf(D_0028BC00, save[0x38], save[0x39], save[0x3A], save[0x3B], save[0x3C], save[0x3D], i);
            count = 0;
            if (*(u16 *)save == 1) {
                for (j = 0; j < 6; j++) {
                    if ((&D_0028ED30)[j] == save[j + 0x38]) {
                        count++;
                    }
                }
                if (count == 6) {
                    goto found;
                }
            }
        }
    }
    return 0xFF;
found:
    k = i << 10;
    printf(D_0028BC00, D_006A0E88[k], D_006A0E89[k], D_006A0E8A[k], D_006A0E8B[k], D_006A0E8C[k], D_006A0E8D[k], i + 1);
    return i + 1;
}
