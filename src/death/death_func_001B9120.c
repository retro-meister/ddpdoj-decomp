#include "common.h"
#pragma opt_dead_assignments off

extern void func_0021C100(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
extern void func_00224BA0(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag, s32 kind);
void func_00213060(void);
void func_00215350(void);
extern s8 death_D_00262EC7[];
extern u8 *death_D_00262FF0[];
extern u8 *death_D_002630C8[];
extern s16 D_00271800[];
extern u8 *death_D_00290050[2];
extern s8 death_D_00290C4C;
extern s8 death_D_00290C74;
extern s32 death_D_00290CE4;
extern u8 D_00685010[];
extern s8 D_0068DC10[];
extern u8 *reg_a0;

void death_func_001B9120(void) {
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    u8 *item;

    count = death_D_00262EC7[0];
    switch (death_D_00290C74) {
    case 0:
        break;
    case 1:
        death_D_00290CE4 += 4;
        if (death_D_00290CE4 >= 0x80) {
            death_D_00290C74 = 0;
            death_D_00290CE4 = 0x80;
        }
        break;
    case 2:
        death_D_00290CE4 -= 4;
        if (death_D_00290CE4 <= 0) {
            death_D_00290CE4 = 0;
            death_D_00290C74 = 0;
        }
        break;
    }
    func_00213060();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x50B4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x50AC) = death_D_00290CE4;
        reg_a0 = death_D_00262FF0[i];
        x = *(s32 *)(item + 0x5080);
        alpha = *(s32 *)(item + 0x50AC);
        top = *(s32 *)(item + 0x5084);
        z = *(s32 *)(item + 0x50B0);
        if (alpha == 0) {
            continue;
        }
        func_0021C100(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x170 + i];
        if (i == 1) {
            reg_a0 = death_D_00290050[index];
            func_0021C100(x, y + 16, z, 0, 0x80, alpha, 1);
            if (death_D_00290C4C == 1) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2) {
            reg_a0 = death_D_002630C8[index];
            func_0021C100(x, y + 16, z, 0, 0x80, alpha, 1);
            if (death_D_00290C4C == 2) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
    func_00215350();
}
