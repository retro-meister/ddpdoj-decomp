#include "common.h"

extern Obj38 D_00685010[][16];
extern s8 D_002714F0[];
extern s16 D_00271760[][2];
extern s16 D_002717A0[][2];

void func_00222260(s32 group) {
    s32 i;
    s32 count;
    s32 x;
    s32 y;
    s32 id;

    id = group + 100;
    count = D_002714F0[group];
    for (i = 0; i < count; i++) {
        if (group == 15) {
            x = D_002717A0[i][0];
            D_00685010[group][i].x = x;
            y = D_002717A0[i][1];
            D_00685010[group][i].y = y;
            D_00685010[group][i].x2 = x;
            D_00685010[group][i].y2 = y;
        } else {
            x = D_00271760[i][0];
            D_00685010[group][i].x = x;
            y = D_00271760[i][1];
            D_00685010[group][i].y = y;
            D_00685010[group][i].x2 = x;
            D_00685010[group][i].y2 = y;
        }
        D_00685010[group][i].unk2C = 0;
        D_00685010[group][i].timer = 0x3C;
        D_00685010[group][i].id = id;
        D_00685010[group][i].active = 1;
    }
}
