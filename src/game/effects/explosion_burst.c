#include "common.h"
#include "explosion.h"

s32 explosion_spawn();
s32 rng_next();

/*
 * One piece of a burst: an explosion of the given kind at the position in reg_d2, thrown in the direction in
 * reg_d1 (spread a little at random) at `speed` scaled down by reg_d6, starting after `delay` frames.
 */
void explosion_piece_spawn(u32 kind, u32 speed, s16 delay) {
    u32 scaled;

    reg_d0.w = kind;
    explosion_spawn();
    EXPLOSION(reg_a0)->draw_layer = (u16) reg_d3.h[0];
    EXPLOSION(reg_a0)->y = (u16) reg_d2.h[1];
    EXPLOSION(reg_a0)->x = (u16) reg_d2.h[0];
    reg_d0.w = speed;
    scaled = reg_d0.h[0];
    reg_d0.h[0] = (u16) (scaled >> reg_d6.h[0]);
    EXPLOSION(reg_a0)->move.b.speed = (u8) reg_d0.b[0];
    EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d1.b[0];
    rng_next();
    reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
    EXPLOSION(reg_a0)->move.b.dir += reg_d0.b[0];
    EXPLOSION(reg_a0)->delay = delay;
}


void explosion_burst_large(void) {
    reg_d6.h[0] = reg_d0.h[0];
    explosion_piece_spawn(7, 5, 0);
    explosion_piece_spawn(4, 7, 1);
    explosion_piece_spawn(7, 0xA, 2);
    explosion_piece_spawn(4, 0xE, 3);
    explosion_piece_spawn(7, 0x12, 6);
    explosion_piece_spawn(4, 0x16, 8);
    explosion_piece_spawn(7, 0x1C, 0xA);
    explosion_piece_spawn(5, 0x22, 0xC);
    explosion_piece_spawn(4, 0x28, 0xE);
    explosion_piece_spawn(5, 0x2E, 0x10);
    explosion_piece_spawn(5, 0x34, 0x12);
}

void explosion_burst_medium(void) {
    reg_d6.h[0] = reg_d0.h[0];
    explosion_piece_spawn(7, 5, 0);
    explosion_piece_spawn(4, 7, 1);
    explosion_piece_spawn(7, 0xA, 2);
    explosion_piece_spawn(4, 0xE, 3);
    explosion_piece_spawn(5, 0x12, 6);
    explosion_piece_spawn(4, 0x16, 8);
    explosion_piece_spawn(5, 0x1C, 0xA);
    explosion_piece_spawn(5, 0x22, 0xC);
}

void explosion_burst_small(void) {
    reg_d6.h[0] = reg_d0.h[0];
    explosion_piece_spawn(4, 5, 0);
    explosion_piece_spawn(7, 7, 1);
    explosion_piece_spawn(4, 0xA, 2);
    explosion_piece_spawn(5, 0xE, 3);
    explosion_piece_spawn(5, 0x12, 6);
}
