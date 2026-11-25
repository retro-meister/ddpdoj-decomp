#ifndef DDPDOJ_ENEMY_TABLES_H
#define DDPDOJ_ENEMY_TABLES_H

#include "types.h"

/*
 * One enemy of a stage. A stage's table is in the order of `line`; the enemy unit starts every enemy whose
 * line the scroll has reached and stops at the first later one.
 */
typedef struct {
    /* 0x00 */ u16 line;         /* scroll line (g_scroll_line) at which the enemy starts */
    /* 0x02 */ s16 line_step;    /* position within the line (g_scroll_line_step): moves the start along x */
    /* 0x04 */ u8 start_flags;   /* EnemyState.start_flags */
    /* 0x05 */ u8 kind;          /* EnemyState.kind: which enemy */
    /* 0x06 */ u16 path;         /* low 12 bits: number of its path; the top four bits are not read */
} EnemyPlacement;

#define ENEMY_PLACEMENT_END { 0xFFFF, -1, 0xFF, 0xFF, 0xFFFF }

/* The three tables of a stage's enemies. */
typedef struct {
    /* 0x00 */ const EnemyPlacement *placements;
    /* 0x04 */ const u16 *path_offsets;   /* by path number: where the path starts in `paths` */
    /* 0x08 */ const u8 *paths;
    /* 0x0C */ u16 unused[2];
} StageEnemies;

/* By stage: the enemies of a whole stage, and of a game that starts at the boss. */
extern StageEnemies g_stage_enemies[5];
extern StageEnemies g_stage_boss_start_enemies[5];

extern const EnemyPlacement g_stage1_enemy_placements[];
extern const EnemyPlacement g_stage1_boss_start_placements[];
extern const u16 g_stage1_enemy_path_offsets[];
extern const u8 g_stage1_enemy_paths[];
extern const EnemyPlacement g_stage2_enemy_placements[];
extern const EnemyPlacement g_stage2_boss_start_placements[];
extern const u16 g_stage2_enemy_path_offsets[];
extern const u8 g_stage2_enemy_paths[];
extern const EnemyPlacement g_stage3_enemy_placements[];
extern const EnemyPlacement g_stage3_boss_start_placements[];
extern const u16 g_stage3_enemy_path_offsets[];
extern const u8 g_stage3_enemy_paths[];
extern const EnemyPlacement g_stage4_enemy_placements[];
extern const EnemyPlacement g_stage4_boss_start_placements[];
extern const u16 g_stage4_enemy_path_offsets[];
extern const u8 g_stage4_enemy_paths[];
extern const EnemyPlacement g_stage5_enemy_placements[];
extern const EnemyPlacement g_stage5_boss_start_placements[];
extern const u16 g_stage5_enemy_path_offsets[];
extern const u8 g_stage5_enemy_paths[];

/*
 * A path is a run of bytes: the start position, then steps. An enemy placed by a spawner starts where the
 * spawner says and its path has no start position. Positions are in 1/64 pixel.
 */
#define PATH_START(y, x) (u8)((y) >> 8), (u8)(y), (u8)((x) >> 8), (u8)(x)
/* Move in a direction (0x00..0x3F; from 0x40 up the enemy stays where it is) for a number of frames; 0 frames: for good. */
#define PATH_MOVE(dir, frames) dir, frames
#define PATH_SPEED(speed) 0xC0, speed
/* Go back by a number of two-byte steps. */
#define PATH_LOOP(steps) 0x80, steps
/* Set Entity.misc.draw_layer. */
#define PATH_DRAW_LAYER(layer) 0x81, layer
/* 1: clear bit 5 of the entity's high flags byte; other values set it. */
#define PATH_GROUND_HITS(mode) 0x82, mode
/* 1: clear bits 13 and 0 of the entity's flags; other values set them. */
#define PATH_AIR_HITS(mode) 0x83, mode
/* Set Entity.misc.user. */
#define PATH_USER(value) 0x88, value
/* Take the sideways scroll position off x; the number is not read. */
#define PATH_SIDE_SCROLL(unused) 0x89, unused
/* Remove the enemy. */
#define PATH_END 0x8A

#endif
