#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    u8 pad08[0x24];
    s32 alpha;
    s32 z;
    s32 active;
} Label;

extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 wide);
extern s8 D_002714F0[];
extern u8 *D_00271510[];
extern s8 D_0028EB4C;
extern s32 D_0028EBB4;
extern Label D_00685010[];
extern u8 *reg_a0;

void func_0021FC70(void) {
    s32 i;
    s32 count;
    Label *label;
    s32 x;
    s32 y;
    s32 z;

    count = D_002714F0[0];
    switch (D_0028EB4C) {
    case 0:
        break;
    case 1:
        D_0028EBB4 += 4;
        if (D_0028EBB4 >= 0x80) {
            D_0028EB4C = 0;
            D_0028EBB4 = 0x80;
        }
        break;
    case 2:
        D_0028EBB4 -= 4;
        if (D_0028EBB4 <= 0) {
            D_0028EBB4 = 0;
            D_0028EB4C = 0;
        }
        break;
    }
    for (i = 0; i < count; i++) {
        label = &D_00685010[i];
        if (label->active != 0) {
            label->alpha = D_0028EBB4;
            reg_a0 = D_00271510[i];
            x = label->x;
            y = label->y;
            z = label->z;
            if (label->alpha != 0) {
                glyph_queue_add(x, y, z, 0, 0x80, label->alpha, 1);
            }
        }
    }
}
