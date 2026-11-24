#pragma opt_propagation off
#include "common.h"

extern void scePadSetActDirect(s32 port, s32 slot, u8 *info);
extern u8 D_0028E340;
extern u8 D_0028E344;
extern u16 D_0028E348;
extern u16 D_0028E34C;
extern u8 D_0028E35C;
extern u8 D_0028E360;
extern u16 D_0028E3C0;
extern u8 D_0028EA40;
extern u8 D_0028EA41;

void func_00217D80(void) {
    s32 slot;

    if (D_0028E3C0 != 0) {
        return;
    }
    slot = 0;
    switch (D_0028E360) {
    case 0:
        break;
    case 1:
        D_0028EA41 = D_0028E344;
        scePadSetActDirect(0, slot, &D_0028EA40);
        D_0028E360 += 1;
        break;
    case 2:
        D_0028E34C -= 1;
        if ((s32)D_0028E34C <= 0) {
            D_0028E360 += 1;
        }
        break;
    case 3:
        D_0028EA41 = 0;
        scePadSetActDirect(0, slot, &D_0028EA40);
        D_0028E360 = 0;
        break;
    }
    switch (D_0028E35C) {
    case 0:
        break;
    case 1:
        D_0028EA41 = D_0028E340;
        scePadSetActDirect(1, 0, &D_0028EA40);
        D_0028E35C += 1;
        break;
    case 2:
        D_0028E348 -= 1;
        if ((s32)D_0028E348 <= 0) {
            D_0028E35C += 1;
        }
        break;
    case 3:
        D_0028EA41 = 0;
        scePadSetActDirect(1, 0, &D_0028EA40);
        D_0028E35C = 0;
        break;
    }
}
