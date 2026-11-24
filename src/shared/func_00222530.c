#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 targetX;
    s32 targetY;
    s32 posX;
    s32 posY;
    s32 speedX;
    s32 speedY;
    s32 accelX;
    s32 accelY;
    s32 delay;
    u8 pad[0xC];
} Mover;

extern s8 D_002714F0[];
extern u8 D_00685010[];

s32 func_00222530(s32 group) {
    s32 i;
    s32 count;
    s32 done;
    Mover *m;
    s32 *delay;
    s32 off;
    s32 *target;
    s32 *cur;

    done = 0;
    count = D_002714F0[group];
    i = 0;
    if (i < count) {
        off = 0;
        do {
            m = (Mover *)(D_00685010 + group * 0x380 + off);
            delay = &m->delay;
            if (*delay != 0) {
                (*delay)--;
            }
            if (*delay <= 0) {
                done++;
                m->x = m->targetX;
                m->y = m->targetY;
            }
            cur = &m->x;
            target = &m->targetX;
            if (m->x != m->targetX) {
                if (m->x < m->targetX) {
                    *cur = m->posX / 10000;
                    m->posX += m->speedX;
                    m->speedX -= m->accelX;
                    if (*cur > *target) {
                        *cur = *target;
                    }
                } else {
                    *cur = m->posX / 10000;
                    m->posX -= m->speedX;
                    m->speedX -= m->accelX;
                    if (*cur < *target) {
                        *cur = *target;
                    }
                }
            }
            cur = &m->y;
            target = &m->targetY;
            if (m->y != m->targetY) {
                if (m->y < m->targetY) {
                    *cur = m->posY / 10000;
                    m->posY += m->speedY;
                    m->speedY -= m->accelY;
                    if (*cur > *target) {
                        *cur = *target;
                    }
                } else {
                    *cur = m->posY / 10000;
                    m->posY -= m->speedY;
                    m->speedY -= m->accelY;
                    if (*cur < *target) {
                        *cur = *target;
                    }
                }
            }
            i++;
            off += 0x38;
        } while (i < count);
    }
    return done == count;
}
