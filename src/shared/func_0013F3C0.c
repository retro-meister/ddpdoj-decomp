#include "common.h"

extern u16 D_0029CEBA[];

void func_0013F3C0(void) {
    u16 *counter = (u16 *) &D_0029CEBA[0];

    if (*counter >= 0x14) {
        *counter = 0x14;
    }
}
