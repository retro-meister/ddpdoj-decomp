#include "common.h"

extern s32 D_0026BA70[];
extern s32 D_0028E6FC;
extern u16 D_0028E700;
extern u8 D_0028E704;
extern u8 D_0028E705;
extern u8 *reg_a0;

void func_001A8970(void)
{
    s32 tableEntry;

    D_0028E705 -= 1;
    if ((s8)D_0028E705 < 0) {
        reg_a0 = (u8 *)D_0026BA70;
        D_0028E705 = D_0028E704;
        reg_d0.h[0] = D_0028E700;
        tableEntry = *(s32 *)(reg_a0 + reg_d0.h[0]);
        D_0028E700 -= 4;
        D_0028E6FC = tableEntry;
        if ((s16)D_0028E700 < 0) {
            D_0028E700 = 0x38;
        }
    }
}
