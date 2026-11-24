#include "common.h"

extern u8 D_002962E0[];

void func_0013F380(void) {
    if (*(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3484, 0x10684)) != 0) {
        *(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3484, 0x10684)) -= 1;
        if (*(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3484, 0x10684)) == 0) {
            *(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3486, 0x10686)) = 0;
        }
    }
}
