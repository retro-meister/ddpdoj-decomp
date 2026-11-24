#include "common.h"

extern s16 D_0028E59C_as_s16;
extern u16 D_0028E630;
extern u8 D_0028E854;
extern u16 D_0028E91C;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u16 D_006C8E5C[];

void func_001AC840(void) {
    if (!(D_0028E854 & 1)) {
        D_0028E630 = 0x53;
        if (D_0028E91C == 0 && D_0028ED7C == 2) {
            if (D_006C8E5C[0] == 0) {
                D_0028E630 += 0x42;
            } else {
                D_0028E630 += 0x6B;
            }
        }
        if (D_0028ED80 != 0) {
            D_0028E630 = 1;
        }
    }
    D_0028E59C_as_s16 = 1;
}
