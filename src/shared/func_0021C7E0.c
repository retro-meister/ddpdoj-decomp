#include "common.h"

extern s32 D_0026FBA0[];
extern u16 D_0028E91C;
extern u8 *D_0028EA84;
extern u8 *D_0028EA88;
extern u8 *D_0028EA8C;
extern s32 D_0028EA90;
extern s32 D_0028EA94;
extern u8 *D_0028EA9C;

s32 func_0021C7E0(void) {
    u8 *src;
    s32 count;
    u8 code;

    D_0028EA90++;
    while (D_0028EA84 - D_0028EA8C < D_0026FBA0[D_0028E91C]) {
        code = *D_0028EA84;
        D_0028EA84++;
        if (code & 0x80) {
            count = *D_0028EA84;
            D_0028EA84++;
            src = D_0028EA88 - (code & 0x7F);
            for (; count >= 0; count--) {
                *D_0028EA88 = *src;
                D_0028EA88++;
                src++;
            }
        } else if (code & 0x40) {
            src = D_0028EA88 - (code & 0x3F);
            *D_0028EA88 = src[0];
            D_0028EA88++;
            *D_0028EA88 = src[1];
            D_0028EA88++;
        } else {
            *D_0028EA88 = code;
            D_0028EA88++;
        }
        if (D_0028EA88 - D_0028EA9C > D_0028EA90 * D_0028EA94) {
            return 0;
        }
    }
    return 1;
}
