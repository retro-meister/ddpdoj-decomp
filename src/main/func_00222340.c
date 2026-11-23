#include "common.h"

#pragma divbyzerocheck on

typedef struct {
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 fx;
    s32 fy;
    s32 vx;
    s32 vy;
    s32 dx;
    s32 dy;
    s32 timer;
    s32 step;
    s32 id;
    s32 active;
} MoveItem;

typedef struct {
    s16 x;
    s16 y;
} Point16;

extern s8 D_002714F0[];
extern Point16 D_00271760[];
extern Point16 D_002717A0[];
extern s32 D_00271910[];
extern MoveItem D_00685010[][16];

void func_00222340(s32 group) {
    s32 i;
    s32 count;
    s32 dx;
    s32 dy;
    s32 tag;

    tag = group + 100;
    count = D_002714F0[group];
    for (i = 0; i < count; i++) {
        if (group == 15) {
            D_00685010[group][i].x0 = -D_002717A0[i].x;
            D_00685010[group][i].y0 = D_002717A0[i].y;
            D_00685010[group][i].x1 = D_002717A0[i].x;
            D_00685010[group][i].y1 = D_002717A0[i].y;
        } else {
            D_00685010[group][i].x0 = -D_00271760[i].x;
            D_00685010[group][i].y0 = D_00271760[i].y;
            D_00685010[group][i].x1 = D_00271760[i].x;
            D_00685010[group][i].y1 = D_00271760[i].y;
        }
        D_00685010[group][i].step = 0;
        D_00685010[group][i].timer = 60;
        D_00685010[group][i].id = tag;
        D_00685010[group][i].active = 1;
        dx = D_00685010[group][i].x1 - D_00685010[group][i].x0;
        dy = D_00685010[group][i].y1 - D_00685010[group][i].y0;
        if (dx < 0) {
            dx = -dx;
        }
        if (dy < 0) {
            dy = -dy;
        }
        D_00685010[group][i].dx = 0;
        D_00685010[group][i].dy = 0;
        if (dx != 0) {
            D_00685010[group][i].dx = dx * 10000 / D_00271910[0];
        }
        if (dy != 0) {
            D_00685010[group][i].dy = dy * 10000 / D_00271910[0];
        }
        D_00685010[group][i].vx = D_00685010[group][i].dx * 60;
        D_00685010[group][i].vy = D_00685010[group][i].dy * 60;
        D_00685010[group][i].fx = D_00685010[group][i].x0 * 10000;
        D_00685010[group][i].fy = D_00685010[group][i].y0 * 10000;
    }
}
