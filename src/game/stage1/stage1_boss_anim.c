#include "common.h"
#include "black_label.h"
#include "entity.h"
#include "explosion.h"
#include "stage1_boss.h"

void stage1_boss_right_hover_start(void);
void stage1_boss_right_hover(void);
void stage1_boss_left_hover_start(void);
void stage1_boss_left_hover(void);
void stage1_boss_right_rotor_start(void);
void stage1_boss_right_rotor(void);
void stage1_boss_left_rotor_start(void);
void stage1_boss_left_rotor(void);
void stage1_boss_right_wreck_start(void);
void stage1_boss_right_wreck(void);
void stage1_boss_left_wreck_start(void);
void stage1_boss_left_wreck(void);
void stage1_boss_body_explode_start(void);
void stage1_boss_body_explode(void);
void stage1_boss_gatling_spin_start(void);
void stage1_boss_right_open_start(void);
void stage1_boss_right_open(void);
void stage1_boss_left_open_start(void);
void stage1_boss_left_open(void);
void stage1_boss_right_rotor_opened_start(void);
void stage1_boss_right_rotor_opened(void);
void stage1_boss_left_rotor_opened_start(void);
void stage1_boss_left_rotor_opened(void);
void stage1_boss_right_close_start(void);
void stage1_boss_right_close(void);
void stage1_boss_left_close_start(void);
void stage1_boss_left_close(void);
void stage1_boss_spin_start(void);
void stage1_boss_spin(void);
void stage1_boss_gatling_recenter_start(void);
void stage1_boss_gatling_recenter(void);
void stage1_boss_right_open_wide_start(void);
void stage1_boss_right_open_wide(void);
void stage1_boss_left_open_wide_start(void);
void stage1_boss_left_open_wide(void);
void stage1_boss_right_close_wide_start(void);
void stage1_boss_right_close_wide(void);
void stage1_boss_left_close_wide_start(void);
void stage1_boss_left_close_wide(void);
void stage1_boss_gatling_fast_spin_start(void);
void stage1_boss_gatling_fast_spin(void);

void stage1_boss_gatling_spin(void);
/*
 * The animation part of the boss slot (reg_a4), one record per kind of animation. `running` is cleared when
 * the animation is over.
 */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 unused_02;
    /* 0x04 */ u8 x_phase;        /* a side part sways around its place */
    /* 0x05 */ u8 y_phase;
} SideHover;

/* A rotor turning, or the gatling gun turning back to the middle: one step every few frames. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer frame;
} FrameStep;

/* A side part opening or closing. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer frame;
    /* 0x04 */ u16 delay;         /* closing: frames to wait first */
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 moving;
} SideDoor;

/* A destroyed side part shrinks, falls and blows up. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 blasts;         /* one bit per series of small explosions that is running */
    /* 0x03 */ u8 step;
    /* 0x04 */ SlotTimer blast[3];
    /* 0x0A */ SlotTimer shrink;  /* frames between two steps of shrinking; gets shorter */
    /* 0x0C */ u16 fall_speed;
} SideWreck;

/* The body blows up: chains of explosions with their sounds, then the big ones. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 blasts;         /* bit 0: the series of small explosions is running */
    /* 0x03 */ u8 step;
    /* 0x04 */ SlotTimer blast;
    /* 0x06 */ SlotTimer blast_b;
    /* 0x08 */ u16 unused_08;
    /* 0x0A */ u16 delay;
    /* 0x0C */ SlotTimer chain;   /* wait between two explosions of the list */
    /* 0x0E */ u16 chain_position;
    /* 0x10 */ u16 toggle;        /* every other explosion of the list comes with a flash */
    /* 0x12 */ SlotTimer sound;  /* wait between two explosion sounds */
    /* 0x14 */ u16 sound_position;
} BodyExplode;

/* The body turns to one side, holds while it fires, and turns back. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 angle;
    /* 0x03 */ u8 direction;      /* 1 or -1 */
    /* 0x04 */ SlotTimer turn;
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 step;
    /* 0x08 */ u16 delay;
    /* 0x0A */ u16 saved_a[2];    /* two 32-bit values kept while it turns, high word first */
    /* 0x0E */ u16 saved_b[2];
    /* 0x12 */ u16 hold;
} BodySpin;

#define HOVER(pointer) ((SideHover *)(pointer))
#define ROTOR(pointer) ((FrameStep *)(pointer))
#define DOOR(pointer) ((SideDoor *)(pointer))
#define WRECK(pointer) ((SideWreck *)(pointer))
#define EXPLODE(pointer) ((BodyExplode *)(pointer))
#define SPIN(pointer) ((BodySpin *)(pointer))

/* The set-up routine and the per-frame routine of every animation, by animation number. */
void (*stage1_boss_anim_routines[])(void) = {
    stage1_boss_right_hover_start,
    stage1_boss_right_hover,
    stage1_boss_left_hover_start,
    stage1_boss_left_hover,
    stage1_boss_right_rotor_start,
    stage1_boss_right_rotor,
    stage1_boss_left_rotor_start,
    stage1_boss_left_rotor,
    stage1_boss_right_wreck_start,
    stage1_boss_right_wreck,
    stage1_boss_left_wreck_start,
    stage1_boss_left_wreck,
    stage1_boss_body_explode_start,
    stage1_boss_body_explode,
    stage1_boss_gatling_spin_start,
    stage1_boss_gatling_spin,
    stage1_boss_right_open_start,
    stage1_boss_right_open,
    stage1_boss_left_open_start,
    stage1_boss_left_open,
    stage1_boss_right_rotor_opened_start,
    stage1_boss_right_rotor_opened,
    stage1_boss_left_rotor_opened_start,
    stage1_boss_left_rotor_opened,
    stage1_boss_right_close_start,
    stage1_boss_right_close,
    stage1_boss_left_close_start,
    stage1_boss_left_close,
    stage1_boss_spin_start,
    stage1_boss_spin,
    stage1_boss_gatling_recenter_start,
    stage1_boss_gatling_recenter,
    stage1_boss_right_open_wide_start,
    stage1_boss_right_open_wide,
    stage1_boss_left_open_wide_start,
    stage1_boss_left_open_wide,
    stage1_boss_right_close_wide_start,
    stage1_boss_right_close_wide,
    stage1_boss_left_close_wide_start,
    stage1_boss_left_close_wide,
    stage1_boss_gatling_fast_spin_start,
    stage1_boss_gatling_fast_spin,
};

s32 sfx_explosion_air_small();
s32 sfx_explosion_air_medium();
s32 sfx_explosion_ground_small();
s32 sfx_explosion_ground_medium();

u16 stage1_boss_right_wreck_debris[] = {
    0x0000, 0x000D, 0x0000, 0x0200, 0x0000, 0x0000, 0x0007, 0x0005,
    0x0000, 0xF800, 0x0400, 0x0001, 0x0006, 0x0003, 0x0000, 0xFE00,
    0x0000, 0x0000, 0x0009, 0x0003, 0x0000, 0xF600, 0xFC00, 0x0000,
    0x0004, 0x0087, 0x0040, 0xF600, 0xFC00, 0x0002, 0x0009, 0x0003,
    0x0000, 0xF000, 0x0000, 0x0000, 0x000C, 0x0004, 0x0000, 0x0200,
    0x0000, 0x0003, 0x0008, 0x0085, 0x0000, 0xF600, 0x0600, 0x0000,
    0xFFFF,
};

u16 stage1_boss_right_wreck_blasts[] = {
    0x0000, 0x000D, 0x0000, 0x0200, 0x0000, 0x0800, 0x0001, 0x0005,
    0x0000, 0xF800, 0x0400, 0x0400, 0x0002, 0x0003, 0x0000, 0xFE00,
    0x0000, 0x0000, 0x0003, 0x0003, 0x0000, 0xF600, 0xFC00, 0x0000,
    0xFFFF,
};

u16 stage1_boss_left_wreck_debris[] = {
    0x0000, 0x000D, 0x0000, 0x0200, 0x0000, 0x0000, 0x0007, 0x0005,
    0x0000, 0xF800, 0xFC00, 0x0001, 0x0006, 0x0003, 0x0000, 0xFE00,
    0x0000, 0x0000, 0x0009, 0x0003, 0x0000, 0xF600, 0x0400, 0x0000,
    0x0004, 0x0087, 0x0040, 0xF600, 0x0400, 0x0002, 0x0009, 0x0003,
    0x0000, 0xF000, 0x0000, 0x0000, 0x000C, 0x0004, 0x0000, 0x0200,
    0x0000, 0x0003, 0x0008, 0x0085, 0x0000, 0xF600, 0xFA00, 0x0000,
    0xFFFF,
};

u16 stage1_boss_left_wreck_blasts[] = {
    0x0000, 0x000D, 0x0000, 0x0200, 0x0000, 0x0800, 0x0001, 0x0005,
    0x0000, 0xF800, 0xFC00, 0x0400, 0x0002, 0x0003, 0x0000, 0xFE00,
    0x0000, 0x0000, 0x0003, 0x0003, 0x0000, 0xF600, 0x0400, 0x0000,
    0xFFFF,
};

/* The explosion sounds played in turn while the body blows up. */
s32 (*stage1_boss_blast_sounds[])() = {
    sfx_explosion_air_small,
    sfx_explosion_air_medium,
    sfx_explosion_air_small,
    sfx_explosion_air_medium,
    sfx_explosion_ground_small,
    sfx_explosion_air_small,
    sfx_explosion_ground_medium,
    sfx_explosion_ground_small,
};

u16 stage1_boss_body_debris[] = {
    0x0000, 0x0085, 0x0000, 0xE800, 0xFE00, 0x0000, 0x0002, 0x0087,
    0x0000, 0xF400, 0x0400, 0x0000, 0x0004, 0x000D, 0x0000, 0xFE00,
    0x0000, 0x0000, 0x0005, 0x0087, 0x0040, 0xF600, 0xFC00, 0x0000,
    0x0006, 0x0087, 0x0040, 0x0400, 0xFA00, 0x0000, 0x0005, 0x0007,
    0x0000, 0xE800, 0x0400, 0x0000, 0x0008, 0x0005, 0x0040, 0x0C00,
    0x0200, 0x0000, 0x0009, 0x000D, 0x0040, 0xF600, 0x0000, 0x0001,
    0xFFFF,
};

u16 stage1_boss_body_debris_b[] = {
    0x0000, 0x0085, 0x0000, 0xE400, 0xFE00, 0x0000, 0x0002, 0x0087,
    0x0000, 0xE000, 0x0400, 0x0000, 0x0004, 0x000D, 0x0000, 0xDC00,
    0x0000, 0x0000, 0x0005, 0x0087, 0x0040, 0xD800, 0xFC00, 0x0000,
    0xFFFF,
};

u16 stage1_boss_blast_chain[] = {
    0x0085, 0x0000, 0xE800, 0xFC00, 0x04C0, 0x0000, 0x0000, 0x0000,
    0x0087, 0x0000, 0xF400, 0x0800, 0x0440, 0x0000, 0x0000, 0x0000,
    0x000D, 0x0000, 0xFE00, 0x0000, 0x0400, 0x0000, 0x0000, 0x0000,
    0x0087, 0x0040, 0xF600, 0xF800, 0x04C0, 0x0000, 0x0000, 0x0000,
    0x0087, 0x0040, 0x0400, 0xF400, 0x04C0, 0x0000, 0x0000, 0x0000,
    0x0007, 0x0000, 0xE800, 0x0800, 0x0440, 0x0000, 0x0000, 0x0000,
    0x0005, 0x0040, 0x0C00, 0x0400, 0x0440, 0x0000, 0x0000, 0x0000,
    0x000D, 0x0040, 0xF600, 0x0000, 0x0480, 0x0000, 0x0000, 0x0000,
    0x0085, 0x0000, 0xE800, 0xFC00, 0x04C0, 0x0000, 0x0000, 0x0000,
    0x0087, 0x0000, 0xF400, 0x0800, 0x0440, 0x0000, 0x0000, 0x0000,
    0x000D, 0x0000, 0xFE00, 0x0000, 0x0400, 0x0000, 0x0000, 0x0000,
    0x0087, 0x0040, 0xF600, 0xF800, 0x04C0, 0x0000, 0x0000, 0x0000,
    0x0087, 0x0040, 0x0400, 0xF400, 0x04C0, 0x0000, 0x0000, 0x0000,
    0x0007, 0x0000, 0xE800, 0x0800, 0x0440, 0x0000, 0x0000, 0x0000,
    0x0005, 0x0040, 0x0C00, 0x0400, 0x0440, 0x0000, 0x0000, 0x0000,
    0x000D, 0x0040, 0xF600, 0x0000, 0x0480,
};

u16 stage1_boss_final_blasts[] = {
    0x0000, 0x000D, 0x0000, 0xE800, 0xFE00, 0x0800, 0x0001, 0x000D,
    0x0000, 0xF400, 0x0400, 0x0820, 0x0002, 0x000D, 0x0000, 0xFE00,
    0x0000, 0x0840, 0x0003, 0x000D, 0x0040, 0xF600, 0xFC00, 0x0860,
    0x0004, 0x000D, 0x0040, 0x0400, 0xFA00, 0x0880, 0x0005, 0x000D,
    0x0000, 0xE800, 0x0400, 0x08A0, 0x0006, 0x000D, 0x0040, 0x0C00,
    0x0200, 0x08C0, 0x0007, 0x000D, 0x0040, 0xF600, 0x0000, 0x08E0,
    0xFFFF,
};

u16 stage1_boss_blast_flash[] = {
    0x0005, 0x7FFF, 0x0000, 0x04C0, 0x0004, 0x0005, 0x001F, 0x0002,
    0x7FFF, 0x0000, 0x0540, 0x000B, 0x000C, 0x001F, 0x0002, 0x7FFF,
    0x0000, 0x0580, 0x0012, 0x0013, 0x001F, 0x0002, 0x7FFF, 0x0000,
    0x05C0, 0x0019, 0x001A, 0x001F, 0x0002, 0x7FFF, 0x0008, 0x0500,
    0x0020, 0x0021, 0x001F, 0x0002,
};

u16 stage1_boss_final_flash[] = {
    0x0002, 0x7FFF, 0x0000, 0x0780, 0x0004, 0x0005, 0x001F, 0x0004,
    0x7FFF, 0x0008, 0x0500, 0x000B, 0x000C, 0x001F, 0x0004,
};

u16 stage1_boss_spin_levels[] = {
    0x0030, 0x0020, 0x0018, 0x0014, 0x0010, 0x000E, 0x000C, 0x000A,
};

void stage1_boss_gatling_spin(void);


void stage1_boss_anim_clear(void) {
    ROTOR(reg_a4)->running = 0;
}

s32 rng_next_unsigned();                            /* extern */

void stage1_boss_right_hover_start(void) {
    rng_next_unsigned();
    HOVER(reg_a4)->y_phase = (u8) reg_d0.b[0];
    rng_next_unsigned();
    HOVER(reg_a4)->x_phase = (u8) reg_d0.b[0];
}

s32 velocity_from_dir256();

void stage1_boss_right_hover(void) {
    u32 temp_a0;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    reg_d1.w = 0;
    reg_d0.w = 2;
    reg_d1.b[0] = HOVER(reg_a4)->y_phase;
    velocity_from_dir256();
    temp_a0 = ENTITY(reg_a6)[1].offset_y.h;
    ENTITY(reg_a6)[1].offset_y.h = (u16) (temp_a0 + reg_d2.h[0]);
    reg_d0.w = 1;
    reg_d1.w = 0;
    reg_d1.b[0] = HOVER(reg_a4)->x_phase;
    velocity_from_dir256();
    ENTITY(reg_a6)[1].offset_x.h += reg_d3.h[0];
    HOVER(reg_a4)->y_phase += 2;
    HOVER(reg_a4)->x_phase += 1;
}

s32 rng_next_unsigned();                            /* extern */

void stage1_boss_left_hover_start(void) {
    rng_next_unsigned();
    HOVER(reg_a4)->y_phase = (u8) reg_d0.b[0];
    rng_next_unsigned();
    HOVER(reg_a4)->x_phase = (u8) reg_d0.b[0];
}

void stage1_boss_left_hover(void) {
    u32 temp_a0;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    reg_d1.w = 0;
    reg_d0.w = 2;
    reg_d1.b[0] = HOVER(reg_a4)->y_phase;
    velocity_from_dir256();
    temp_a0 = ENTITY(reg_a6)[3].offset_y.h;
    ENTITY(reg_a6)[3].offset_y.h = (u16) (temp_a0 + reg_d2.h[0]);
    reg_d0.w = 1;
    reg_d1.w = 0;
    reg_d1.b[0] = HOVER(reg_a4)->x_phase;
    velocity_from_dir256();
    ENTITY(reg_a6)[3].offset_x.h += reg_d3.h[0];
    HOVER(reg_a4)->y_phase += 2;
    HOVER(reg_a4)->x_phase += 1;
}

void stage1_boss_right_rotor_start(void) {
    ROTOR(reg_a4)->frame.h = 0;
}

void stage1_boss_right_rotor(void) {
    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    reg_tmp.b[0] = ROTOR(reg_a4)->frame.t.count;
    ROTOR(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ROTOR(reg_a4)->frame.t.count = (u8) ROTOR(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[1].draw.h += 4;
        if (ENTITY(reg_a6)[1].draw.sh > 0xc) {
            ENTITY(reg_a6)[1].draw.h = 0U;
        }
    }
}

void stage1_boss_left_rotor_start(void) {
    ROTOR(reg_a4)->frame.h = 0;
}

void stage1_boss_left_rotor(void) {
    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    reg_tmp.b[0] = ROTOR(reg_a4)->frame.t.count;
    ROTOR(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ROTOR(reg_a4)->frame.t.count = (u8) ROTOR(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[3].draw.h += 4;
        if (ENTITY(reg_a6)[3].draw.sh > 0xc) {
            ENTITY(reg_a6)[3].draw.h = 0U;
        }
    }
}

s32 explosion_spawn();

void stage1_boss_explode_by_table(arg2)
    u16 *arg2;
{
    u16 *var_a2;
    u16 temp_a1;

    var_a2 = (u16 *)(arg2);
loop_1:
    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        explosion_spawn();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
        EXPLOSION(reg_a0)->delay = (u16) reg_d1.h[0];
        EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
        var_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(var_a2);
        EXPLOSION(reg_a0)->y = (u16) reg_d2.h[1];
        EXPLOSION(reg_a0)->x = (u16) reg_d2.h[0];
        EXPLOSION(reg_a0)->draw_layer = 0xC;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0;
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        if (reg_d0.h[0] != 0) {
            reg_d0.h[0] -= 1;
            ROTOR(reg_a4)->frame.t.reload |= ((1 << (s8) reg_d0.b[0]) & 0xFF);
        }
        goto loop_1;
    }
}

s32 rng_next();

void stage1_boss_explosions_spawn(void) {
    u16 *temp_a2;
    u16 temp_a1;

    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        explosion_spawn();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
        EXPLOSION(reg_a0)->delay = (u16) reg_d1.h[0];
        EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
        temp_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(temp_a2);
        EXPLOSION(reg_a0)->y = (u16) reg_d2.h[1];
        EXPLOSION(reg_a0)->x = (u16) reg_d2.h[0];
        EXPLOSION(reg_a0)->draw_layer = 4;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->move.h = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        rng_next();
        EXPLOSION(reg_a0)->move.b.dir += reg_d0.b[0];
        stage1_boss_explosions_spawn();
    }
}

void stage1_boss_right_wreck_start(void) {
    WRECK(reg_a4)->step = 0;
    WRECK(reg_a4)->blasts = 0;
    WRECK(reg_a4)->blast[0].sh = 8;
    WRECK(reg_a4)->blast[1].sh = 5;
    WRECK(reg_a4)->blast[2].sh = 7;
    WRECK(reg_a4)->shrink.sh = 0x1008;
    WRECK(reg_a4)->fall_speed = 0;
}

s32 boss_part_hide();
s32 sfx_explosion_ground_small();
s32 sfx_explosion_ground_medium();
extern u16 g_side_scroll_step[];

void stage1_boss_right_wreck(void) {
    u32 temp_a1;
    u8 temp_a0;
    u8 temp_v1;

    reg_d0.h[0] = g_side_scroll_step[0];
    temp_a1 = ENTITY(reg_a6)[1].x.h;
    ENTITY(reg_a6)[1].x.h = (u16) (temp_a1 - reg_d0.h[0]);
    temp_a0 = WRECK(reg_a4)->step;
    if (temp_a0 == 2) {
        sfx_explosion_ground_small();
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
        reg_a1 = (u8 *)stage1_boss_right_wreck_blasts;
        stage1_boss_explosions_spawn();
        WRECK(reg_a4)->running = 0;
    }
    if (WRECK(reg_a4)->step == 1) {
        reg_tmp.b[0] = WRECK(reg_a4)->shrink.t.count;
        WRECK(reg_a4)->shrink.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            WRECK(reg_a4)->shrink.t.count = (u8) WRECK(reg_a4)->shrink.t.reload;
            temp_v1 = WRECK(reg_a4)->shrink.t.reload;
            if (temp_v1 != 0) {
                WRECK(reg_a4)->shrink.t.reload = (u8) (temp_v1 - 1);
            }
            WRECK(reg_a4)->fall_speed += 0x10;
            ENTITY(reg_a6)[2].offset_y.h -= 0x800;
            ENTITY(reg_a6)[2].offset_x.h -= 0x800;
            if (0 > (s16) ENTITY(reg_a6)[2].offset_x.h) {
                reg_tmp.w = 0;
                ENTITY(reg_a6)[2].offset_y.h = (u16) reg_tmp.h[1];
                ENTITY(reg_a6)[2].offset_x.h = (u16) reg_tmp.h[0];
                WRECK(reg_a4)->fall_speed = 0U;
                WRECK(reg_a4)->step = 2U;
                reg_d0.w = 0;
                boss_part_hide();
            }
        }
    }
    if (WRECK(reg_a4)->step == 0) {
        WRECK(reg_a4)->step = 1U;
        sfx_explosion_ground_medium();
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
        reg_a1 = (u8 *)stage1_boss_right_wreck_debris;
        stage1_boss_explode_by_table();
    }
    reg_d0.h[0] = WRECK(reg_a4)->fall_speed;
    ENTITY(reg_a6)[1].y.h -= reg_d0.h[0];
}

void stage1_boss_left_wreck_start(void) {
    WRECK(reg_a4)->step = 0;
    WRECK(reg_a4)->blasts = 0;
    WRECK(reg_a4)->blast[0].sh = 8;
    WRECK(reg_a4)->blast[1].sh = 5;
    WRECK(reg_a4)->blast[2].sh = 7;
    WRECK(reg_a4)->shrink.sh = 0x1008;
    WRECK(reg_a4)->fall_speed = 0;
}

void stage1_boss_left_wreck(void) {
    u8 temp_a0;
    u8 temp_v1;
    u8 *var_a1;

    var_a1 = (u8 *)(reg_a6);
    reg_d0.h[0] = g_side_scroll_step[0];
    (*(u16 *)((u8 *)(var_a1) + (0x64))) -= reg_d0.h[0];
    if (WRECK(reg_a4)->blasts & 4) {
        reg_tmp.b[0] = WRECK(reg_a4)->blast[2].t.count;
        WRECK(reg_a4)->blast[2].t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            WRECK(reg_a4)->blast[2].t.count = (u8) WRECK(reg_a4)->blast[2].t.reload;
            reg_d0.w = 0x10;
            explosion_spawn();
            EXPLOSION(reg_a0)->draw_layer = 4;
            EXPLOSION(reg_a0)->move.b.speed = 0x10;
            rng_next();
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[3].y.h;
            var_a1 = (u8 *)((void *) ENTITY(reg_a6)[3].x.h);
            EXPLOSION(reg_a0)->x = (s16) var_a1;
            reg_tmp.w = 0xFDFFFC00;
            EXPLOSION(reg_a0)->start_y = (u16) reg_tmp.h[1];
            EXPLOSION(reg_a0)->start_x = (u16) reg_tmp.h[0];
        }
    }
    if (WRECK(reg_a4)->blasts & 1) {
        reg_tmp.b[0] = WRECK(reg_a4)->blast[0].t.count;
        WRECK(reg_a4)->blast[0].t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            WRECK(reg_a4)->blast[0].t.count = (u8) WRECK(reg_a4)->blast[0].t.reload;
            reg_d0.w = 0x10;
            explosion_spawn();
            EXPLOSION(reg_a0)->draw_layer = 4;
            EXPLOSION(reg_a0)->move.b.speed = 0x10;
            rng_next();
            reg_d0.b[0] += reg_d0.b[0];
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[3].y.h;
            var_a1 = (u8 *)((void *) ENTITY(reg_a6)[3].x.h);
            EXPLOSION(reg_a0)->x = (s16) var_a1;
            reg_tmp.w = 0xF2000200;
            EXPLOSION(reg_a0)->start_y = (u16) reg_tmp.h[1];
            EXPLOSION(reg_a0)->start_x = (u16) reg_tmp.h[0];
        }
    }
    if (WRECK(reg_a4)->blasts & 2) {
        reg_tmp.b[0] = WRECK(reg_a4)->blast[1].t.count;
        WRECK(reg_a4)->blast[1].t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            WRECK(reg_a4)->blast[1].t.count = (u8) WRECK(reg_a4)->blast[1].t.reload;
            reg_d0.w = 6;
            explosion_spawn();
            EXPLOSION(reg_a0)->draw_layer = 8;
            EXPLOSION(reg_a0)->move.b.speed = 0xC;
            rng_next();
            reg_d0.b[0] += reg_d0.b[0];
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[3].y.h;
            var_a1 = (u8 *)((void *) ENTITY(reg_a6)[3].x.h);
            EXPLOSION(reg_a0)->x = (s16) var_a1;
            reg_tmp.w = 0xF5FFFC00;
            EXPLOSION(reg_a0)->start_y = (u16) reg_tmp.h[1];
            EXPLOSION(reg_a0)->start_x = (u16) reg_tmp.h[0];
        }
    }
    temp_a0 = WRECK(reg_a4)->step;
    if (temp_a0 == 2) {
        sfx_explosion_ground_small();
        reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
        reg_a1 = ((u8 *)stage1_boss_left_wreck_blasts);
        stage1_boss_explosions_spawn();
        WRECK(reg_a4)->running = 0;
    }
    if (WRECK(reg_a4)->step == 1) {
        reg_tmp.b[0] = WRECK(reg_a4)->shrink.t.count;
        WRECK(reg_a4)->shrink.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            WRECK(reg_a4)->shrink.t.count = (u8) WRECK(reg_a4)->shrink.t.reload;
            temp_v1 = WRECK(reg_a4)->shrink.t.reload;
            if (temp_v1 != 0) {
                WRECK(reg_a4)->shrink.t.reload = (u8) (temp_v1 - 1);
            }
            WRECK(reg_a4)->fall_speed += 0x10;
            ENTITY(reg_a6)[4].offset_y.h -= 0x800;
            ENTITY(reg_a6)[4].offset_x.h -= 0x800;
            if (0 > (s16) ENTITY(reg_a6)[4].offset_x.h) {
                reg_tmp.w = 0;
                ENTITY(reg_a6)[4].offset_y.h = (u16) reg_tmp.h[1];
                ENTITY(reg_a6)[4].offset_x.h = (u16) reg_tmp.h[0];
                WRECK(reg_a4)->fall_speed = 0U;
                WRECK(reg_a4)->step = 2U;
                reg_d0.w = 1;
                boss_part_hide();
            }
        }
    }
    if (WRECK(reg_a4)->step == 0) {
        WRECK(reg_a4)->step = 1U;
        sfx_explosion_ground_medium();
        reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
        reg_a1 = ((u8 *)stage1_boss_left_wreck_debris);
        stage1_boss_explode_by_table();
    }
    reg_d0.h[0] = WRECK(reg_a4)->fall_speed;
    ENTITY(reg_a6)[3].y.h -= reg_d0.h[0];
}

void stage1_boss_body_explode_start(void) {
    EXPLODE(reg_a4)->step = 0;
    EXPLODE(reg_a4)->blasts = 0;
    EXPLODE(reg_a4)->blast.sh = 8;
    EXPLODE(reg_a4)->blast_b.sh = 0x1209;
    EXPLODE(reg_a4)->delay = 0x20;
    EXPLODE(reg_a4)->chain.sh = 0xC;
    EXPLODE(reg_a4)->chain_position = 0;
    EXPLODE(reg_a4)->toggle = 0;
    EXPLODE(reg_a4)->sound.sh = 0x1010;
    EXPLODE(reg_a4)->sound_position = 0;
}

typedef void (*Fn)();

s32 boss_slots_end();
s32 boss_flash_start();
s32 boss_flash_running();
s32 explosion_burst_large();
s32 explosion_burst_small();
s32 fade_in_and_release();
s32 sfx_explosion_boss();
s32 rng_next_unsigned();
extern u8 g_slowdown_timer;

void stage1_boss_body_explode(void) {
    u16 *temp_a3_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_6;
    u16 temp_a0_7;
    u16 temp_a1;
    u16 temp_a2;
    u16 temp_a3;
    u16 temp_v1;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_5;
    u8 *var_a1;

    var_a1 = (u8 *)(reg_a4);
    temp_a0 = (*(u8 *)((u8 *)(var_a1) + (3)));
    if (temp_a0 == 6) {
        (*(u16 *)((u8 *)(var_a1) + (0xA))) -= 1;
        if (EXPLODE(reg_a4)->delay == 0) {
            boss_slots_end();
            EXPLODE(reg_a4)->running = 0;
        }
        return;
    }
    if ((*(u8 *)((u8 *)(var_a1) + (2))) & 2) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a1) + (7)));
        (*(u8 *)((u8 *)(var_a1) + (7))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            EXPLODE(reg_a4)->blast_b.t.count = (u8) EXPLODE(reg_a4)->blast_b.t.reload;
            reg_d0.w = 5;
            explosion_spawn();
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->move.b.speed = 0x14;
            rng_next();
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            var_a1 = (u8 *)((void *) ENTITY(reg_a6)->x.h);
            EXPLOSION(reg_a0)->x = (u16) var_a1;
            reg_tmp.w = 0xF8000000;
            EXPLOSION(reg_a0)->start_y = (u16) reg_tmp.h[1];
            EXPLOSION(reg_a0)->start_x = (u16) reg_tmp.h[0];
        }
    }
    if (EXPLODE(reg_a4)->blasts & 1) {
        reg_tmp.b[0] = EXPLODE(reg_a4)->blast.t.count;
        EXPLODE(reg_a4)->blast.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            EXPLODE(reg_a4)->blast.t.count = (u8) EXPLODE(reg_a4)->blast.t.reload;
            reg_d0.w = 0x10;
            explosion_spawn();
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->move.b.speed = 0x18;
            rng_next();
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a1;
            reg_tmp.w = 0xE8000400;
            EXPLOSION(reg_a0)->start_y = (u16) reg_tmp.h[1];
            EXPLOSION(reg_a0)->start_x = (u16) reg_tmp.h[0];
            reg_d0.w = 0x10;
            explosion_spawn();
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->move.b.speed = 0x14;
            rng_next();
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            var_a1 = (u8 *)((void *) ENTITY(reg_a6)->x.h);
            EXPLOSION(reg_a0)->x = (u16) var_a1;
            reg_tmp.w = 0xF3FFF800;
            EXPLOSION(reg_a0)->start_y = (u16) reg_tmp.h[1];
            EXPLOSION(reg_a0)->start_x = (u16) reg_tmp.h[0];
        }
    }
    temp_a0_2 = EXPLODE(reg_a4)->step;
    if (temp_a0_2 == 5) {
#ifdef DDPDOJ_BONUS_FEATURES
        if (g_black_label_active) {
            if (--EXPLODE(reg_a4)->delay) return;
            sfx_explosion_boss();
            black_label_boss_burst(ENTITY(reg_a6)->y.h, ENTITY(reg_a6)->x.h);
            goto finish_boss_burst;
        }
#endif

        sfx_explosion_boss();
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_a1 = (u8 *)(stage1_boss_final_blasts);
        stage1_boss_explosions_spawn();
        rng_next();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x40;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d2.w += 0xF8000A00;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        explosion_burst_large();
        rng_next();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0xB0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        reg_d2.w -= 0x800;
        explosion_burst_large();
        rng_next();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x80;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d2.w += 0xF4000000;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        explosion_burst_large();
#ifdef DDPDOJ_BONUS_FEATURES
finish_boss_burst:
#endif
        var_a1 = (u8 *)((void *)0x80);
        EXPLODE(reg_a4)->delay = 0x80U;
        EXPLODE(reg_a4)->step = 6U;
    }
    temp_a0_5 = EXPLODE(reg_a4)->step;
    if (temp_a0_5 == 4) {
        boss_flash_running();
        if (cond_flag == 0) {
            g_slowdown_timer = 0xA;
            if (GAME_RULE(0, 1)) stage1_boss_final_flash[7] = 3;
            reg_a0 = ((u8 *)stage1_boss_final_flash);
            fade_in_and_release();
            reg_d0.w = 2;
            boss_part_hide();
            reg_d0.w = 4;
            boss_part_hide();
            reg_d0.w = 5;
            boss_part_hide();
            EXPLODE(reg_a4)->step = 5U;
            if (GAME_RULE(0, 1)) EXPLODE(reg_a4)->delay = 8;
        }
    }
    if (EXPLODE(reg_a4)->step == 3) {
        reg_tmp.b[0] = EXPLODE(reg_a4)->sound.t.count;
        EXPLODE(reg_a4)->sound.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            EXPLODE(reg_a4)->sound.t.count = (u8) EXPLODE(reg_a4)->sound.t.reload;
            reg_a0 = (u8 *)stage1_boss_blast_sounds;
            temp_a0_6 = EXPLODE(reg_a4)->sound_position;
            reg_a0 += temp_a0_6;
            reg_tmp.h[0] = EXPLODE(reg_a4)->sound_position;
#ifdef DDPDOJ_PC
            stage1_boss_blast_sounds[reg_tmp.h[0] / 4]();
#else
            ((Fn)*(u32 *)((u8 *)stage1_boss_blast_sounds + (reg_tmp.h[0] & ~3)))();
#endif
            EXPLODE(reg_a4)->sound_position += 4;
            EXPLODE(reg_a4)->sound_position &= 0x1F;
        }
        reg_tmp.b[0] = EXPLODE(reg_a4)->chain.t.count;
        EXPLODE(reg_a4)->chain.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            EXPLODE(reg_a4)->chain.t.count = (u8) EXPLODE(reg_a4)->chain.t.reload;
            reg_a1 = (u8 *)(stage1_boss_blast_chain);
            reg_a1 += EXPLODE(reg_a4)->chain_position;
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            explosion_spawn();
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            temp_a3 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a3;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0x800;
            EXPLOSION(reg_a0)->move.h = *(u16 *)reg_a1;
            reg_a1 += 2;
            EXPLODE(reg_a4)->chain_position += 0x10;
            if (EXPLODE(reg_a4)->chain_position == 0x100) {
                EXPLODE(reg_a4)->chain_position = 0U;
                EXPLODE(reg_a4)->step = 4U;
                reg_d0.h[0] = 0x12;
                boss_flash_start();
                sfx_explosion_ground_medium();
            }
        }
    }
    if (EXPLODE(reg_a4)->step == 2) {
        temp_v1 = EXPLODE(reg_a4)->delay;
        if (temp_v1 != 0) {
            EXPLODE(reg_a4)->delay = (u16) (temp_v1 - 1);
        } else {
            reg_tmp.b[0] = EXPLODE(reg_a4)->sound.t.count;
            EXPLODE(reg_a4)->sound.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                EXPLODE(reg_a4)->sound.t.count = (u8) EXPLODE(reg_a4)->sound.t.reload;
                reg_a0 = (u8 *)stage1_boss_blast_sounds;
                temp_a0_7 = EXPLODE(reg_a4)->sound_position;
                reg_a0 += temp_a0_7;
                reg_tmp.h[0] = EXPLODE(reg_a4)->sound_position;
#ifdef DDPDOJ_PC
                stage1_boss_blast_sounds[reg_tmp.h[0] / 4]();
#else
                ((Fn)*(u32 *)((u8 *)stage1_boss_blast_sounds + (reg_tmp.h[0] & ~3)))();
#endif
                EXPLODE(reg_a4)->sound_position += 4;
                EXPLODE(reg_a4)->sound_position &= 0x1F;
            }
            reg_tmp.b[0] = EXPLODE(reg_a4)->chain.t.count;
            EXPLODE(reg_a4)->chain.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                EXPLODE(reg_a4)->chain.t.count = (u8) EXPLODE(reg_a4)->chain.t.reload;
                reg_a1 = (u8 *)(stage1_boss_blast_chain);
                reg_a1 += EXPLODE(reg_a4)->chain_position;
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                explosion_spawn();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
                EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
                temp_a3_2 = (u16 *)(reg_a1 + 2);
                reg_a1 = (u8 *)(temp_a3_2);
                EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
                temp_a2 = ENTITY(reg_a6)->x.h;
                EXPLOSION(reg_a0)->x = temp_a2;
                EXPLOSION(reg_a0)->draw_layer = 0xC;
                EXPLOSION(reg_a0)->debris = 0;
                EXPLOSION(reg_a0)->debris_arg = 0x800;
                EXPLOSION(reg_a0)->move.h = *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLODE(reg_a4)->toggle += 1;
                EXPLODE(reg_a4)->toggle &= 1;
                if (EXPLODE(reg_a4)->toggle == 0) {
                    g_slowdown_timer = 0xA;
                    reg_a0 = ((u8 *)stage1_boss_blast_flash);
                    fade_in_and_release();
                    rng_next_unsigned();
                    reg_d1.b[0] = reg_d0.b[0];
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d3.h[0] = 0xC;
                    reg_d0.h[0] = 0;
                    explosion_burst_small();
                    sfx_explosion_ground_small();
                }
                EXPLODE(reg_a4)->chain_position += 0x10;
                if (EXPLODE(reg_a4)->chain_position == 0x80) {
                    EXPLODE(reg_a4)->chain_position = 0U;
                    EXPLODE(reg_a4)->step = 3U;
                    EXPLODE(reg_a4)->chain.h = 4;
                    EXPLODE(reg_a4)->blasts = 0U;
                    EXPLODE(reg_a4)->sound.h = 0x808;
                }
            }
        }
    }
    if (EXPLODE(reg_a4)->step == 1) {
        EXPLODE(reg_a4)->delay -= 1;
        if (EXPLODE(reg_a4)->delay == 0) {
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)(stage1_boss_body_debris_b);
            stage1_boss_explode_by_table();
            EXPLODE(reg_a4)->step = 2U;
            EXPLODE(reg_a4)->delay = 0x80U;
            EXPLODE(reg_a4)->blasts |= 2;
            reg_d0.w = 3;
            boss_part_hide();
        }
    }
    if (EXPLODE(reg_a4)->step == 0) {
        EXPLODE(reg_a4)->step = 1U;
        sfx_explosion_ground_medium();
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_a1 = (u8 *)(stage1_boss_body_debris);
        stage1_boss_explode_by_table();
    }
}


void stage1_boss_gatling_spin_start(void) {
    stage1_boss_gatling_spin();
}

void stage1_boss_gatling_spin(void) {
    u8 temp_a0;

    reg_tmp.b[0] = (ENTITY(reg_a6)[5].look.b.size);
    (ENTITY(reg_a6)[5].look.b.size) -= 1;
    if ((s32)reg_tmp.b[0] <= 0) {
        (ENTITY(reg_a6)[5].look.b.size) = (ENTITY(reg_a6)[5].look.b.palette);
        temp_a0 = (ENTITY(reg_a6)[5].look.b.palette);
        if (temp_a0 != 2) {
            if ((s8)temp_a0 >= 2) {
                (ENTITY(reg_a6)[5].look.b.palette) = temp_a0 - 1;
            } else {
                (ENTITY(reg_a6)[5].look.b.palette) = temp_a0 + 1;
            }
        }
        (ENTITY(reg_a6)[5].draw.h) += 4;
        if ((s16)(ENTITY(reg_a6)[5].draw.h) >= 0x1C) {
            (ENTITY(reg_a6)[5].draw.h) = 0;
        }
    }
}

void stage1_boss_right_open_start(void) {
    DOOR(reg_a4)->frame.h = 0;
    DOOR(reg_a4)->moving = 0;
}

s32 boss_animation_start();
s32 boss_animation_stop();

void stage1_boss_right_open() {
    u16 temp_a0;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if ((DOOR(reg_a4)->moving == 0) && (ENTITY(reg_a6)[1].draw.h == 0)) {
        reg_d0.w = 2;
        boss_animation_stop();
        ENTITY(reg_a6)[1].draw.h = 0x10U;
        DOOR(reg_a4)->moving = 1U;
    }
    if (DOOR(reg_a4)->moving == 1) {
        reg_tmp.b[0] = DOOR(reg_a4)->frame.t.count;
        DOOR(reg_a4)->frame.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            DOOR(reg_a4)->frame.t.count = (u8) DOOR(reg_a4)->frame.t.reload;
            ENTITY(reg_a6)[2].sprite.h += 0xC0;
            ENTITY(reg_a6)[2].draw.b.priority += 2;
            ENTITY(reg_a6)[1].draw.h += 4;
            temp_a0 = ENTITY(reg_a6)[1].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                boss_animation_start();
                DOOR(reg_a4)->running = 0;
            }
        }
    }
}



void stage1_boss_left_open_start(void) {
    DOOR(reg_a4)->frame.h = 0;
    DOOR(reg_a4)->moving = 0;
}

void stage1_boss_left_open() {
    u16 temp_a0;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if ((DOOR(reg_a4)->moving == 0) && (ENTITY(reg_a6)[3].draw.h == 0)) {
        reg_d0.w = 3;
        boss_animation_stop();
        ENTITY(reg_a6)[3].draw.h = 0x10U;
        DOOR(reg_a4)->moving = 1U;
    }
    if (DOOR(reg_a4)->moving == 1) {
        reg_tmp.b[0] = DOOR(reg_a4)->frame.t.count;
        DOOR(reg_a4)->frame.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            DOOR(reg_a4)->frame.t.count = (u8) DOOR(reg_a4)->frame.t.reload;
            ENTITY(reg_a6)[4].sprite.h += 0xC0;
            ENTITY(reg_a6)[4].draw.b.priority += 2;
            ENTITY(reg_a6)[3].draw.h += 4;
            temp_a0 = ENTITY(reg_a6)[3].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xB;
                boss_animation_start();
                DOOR(reg_a4)->running = 0;
            }
        }
    }
}


void stage1_boss_right_rotor_opened_start(void) {
    ROTOR(reg_a4)->frame.h = 0;
}

void stage1_boss_right_rotor_opened(void) {
    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    reg_tmp.b[0] = ROTOR(reg_a4)->frame.t.count;
    ROTOR(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ROTOR(reg_a4)->frame.t.count = (u8) ROTOR(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[1].draw.h += 4;
        if (ENTITY(reg_a6)[1].draw.sh > 0x74) {
            ENTITY(reg_a6)[1].draw.h = 0x68U;
        }
    }
}

void stage1_boss_left_rotor_opened_start(void) {
    ROTOR(reg_a4)->frame.h = 0;
}

void stage1_boss_left_rotor_opened(void) {
    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    reg_tmp.b[0] = ROTOR(reg_a4)->frame.t.count;
    ROTOR(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ROTOR(reg_a4)->frame.t.count = (u8) ROTOR(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[3].draw.h += 4;
        if (ENTITY(reg_a6)[3].draw.sh > 0x74) {
            ENTITY(reg_a6)[3].draw.h = 0x68U;
        }
    }
}

s32 boss_attack_start();
s32 boss_level_get_from_58();
s32 rng_next_bit();
extern u8 stage1_boss_spin_start_table[];
extern u8 stage1_boss_spin_start_table_2[];

void stage1_boss_spin_start(void) {
    STAGE1_EXTRA(reg_a6)->spinning = 0;
    SPIN(reg_a4)->direction = 1U;
    rng_next_bit();
    if (reg_d0.h[0] == 0) {
        SPIN(reg_a4)->direction = 0xFFU;
    }
    SPIN(reg_a4)->angle = (u8) SPIN(reg_a4)->direction;
    SPIN(reg_a4)->turn.sh = 0x4040;
    SPIN(reg_a4)->step = 0;
    SPIN(reg_a4)->delay = 0x60;
    reg_tmp.w = 0;
    SPIN(reg_a4)->saved_a[0] = (u16) reg_tmp.h[1];
    SPIN(reg_a4)->saved_a[1] = (u16) reg_tmp.h[0];
    reg_tmp.w = 0;
    SPIN(reg_a4)->saved_b[0] = (u16) reg_tmp.h[1];
    SPIN(reg_a4)->saved_b[1] = (u16) reg_tmp.h[0];
    SPIN(reg_a4)->hold = 0;
    boss_level_get_from_58();
    reg_d2.w = 0;
    reg_d2.b[0] = *(stage1_boss_spin_start_table + reg_d0.h[0]);
    reg_d2.b[0] -= STAGE1_EXTRA(reg_a6)->spin_interval_sub;
    if ((s8) reg_d2.b[0] < 5) {
        reg_d2.b[0] = 4;
    }
    STAGE1_EXTRA(reg_a6)->spin_interval_sub += 1;
    if ((s8) STAGE1_EXTRA(reg_a6)->spin_interval_sub > 4) {
        STAGE1_EXTRA(reg_a6)->spin_interval_sub = 4U;
    }
    reg_d3.w = 0;
    reg_d3.b[0] = *(stage1_boss_spin_start_table_2 + reg_d0.h[0]);
    reg_d3.b[0] -= STAGE1_EXTRA(reg_a6)->spin_width_sub;
    if ((s8) reg_d3.b[0] < 0x10) {
        reg_d3.b[0] = 0xF;
    }
    STAGE1_EXTRA(reg_a6)->spin_width_sub += 1;
    if ((s8) STAGE1_EXTRA(reg_a6)->spin_width_sub > 0x10) {
        STAGE1_EXTRA(reg_a6)->spin_width_sub = 0x10U;
    }
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)stage1_boss_spin_levels;
    reg_d4.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d0.w = 5;
    boss_attack_start();
    *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
    *(u8 *)(reg_a0 + 0xA) = (u8) reg_d3.b[0];
    *(u16 *)(reg_a0 + 0xC) = (u16) reg_d4.h[0];
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    SPIN(reg_a4)->saved_a[0] = (u16) reg_tmp.h[1];
    SPIN(reg_a4)->saved_a[1] = (u16) reg_tmp.h[0];
    reg_d0.w = 6;
    boss_attack_start();
    *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
    *(u8 *)(reg_a0 + 0xA) = (u8) reg_d3.b[0];
    *(u16 *)(reg_a0 + 0xC) = (u16) reg_d4.h[0];
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    SPIN(reg_a4)->saved_b[0] = (u16) reg_tmp.h[1];
    SPIN(reg_a4)->saved_b[1] = (u16) reg_tmp.h[0];
    reg_d0.w = 0xE;
    boss_attack_start();
}

s32 boss_attack_stop();

void stage1_boss_spin(void) {
    u16 temp_v1;

    if (SPIN(reg_a4)->step == 0) {
        SPIN(reg_a4)->delay -= 1;
        if (SPIN(reg_a4)->delay == 0) {
            SPIN(reg_a4)->step = 1U;
            STAGE1_EXTRA(reg_a6)->spinning = 1;
            goto block_3;
        }
    } else {
block_3:
        reg_d0.b[0] = SPIN(reg_a4)->angle;
        ENTITY(reg_a6)[2].draw.b.flip += reg_d0.b[0];
        ENTITY(reg_a6)[4].draw.b.flip += reg_d0.b[0];
        if (SPIN(reg_a4)->step == 1) {
            reg_tmp.b[0] = SPIN(reg_a4)->turn.t.count;
            SPIN(reg_a4)->turn.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                SPIN(reg_a4)->turn.t.count = (u8) SPIN(reg_a4)->turn.t.reload;
                reg_d0.b[0] = SPIN(reg_a4)->direction;
                SPIN(reg_a4)->angle += reg_d0.b[0];
                reg_d0.b[0] = SPIN(reg_a4)->angle;
                if ((s8)(reg_d0.b[0]) < 0) {
                    reg_d0.b[0] *= -1;
                }
                if (reg_d0.b[0] == 2) {
                    SPIN(reg_a4)->step = 2U;
                    SPIN(reg_a4)->turn.h = 0x6020;
                    SPIN(reg_a4)->hold = 0x100U;
                }
            }
        }
        if (SPIN(reg_a4)->step == 2) {
            temp_v1 = SPIN(reg_a4)->hold;
            if (temp_v1 != 0) {
                SPIN(reg_a4)->hold = (u16) (temp_v1 - 1);
            } else {
                reg_d0.b[0] = SPIN(reg_a4)->direction;
                reg_d0.b[0] += reg_d0.b[0];
                reg_d1.b[0] = SPIN(reg_a4)->angle;
                if (reg_d0.b[0] != reg_d1.b[0]) {
                    reg_tmp.b[0] = SPIN(reg_a4)->turn.t.count;
                    SPIN(reg_a4)->turn.t.count -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        SPIN(reg_a4)->turn.t.count = (u8) SPIN(reg_a4)->turn.t.reload;
                        reg_tmp.h[1] = SPIN(reg_a4)->saved_a[0];
                        reg_tmp.h[0] = SPIN(reg_a4)->saved_a[1];
                        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
                        reg_tmp.h[1] = SPIN(reg_a4)->saved_b[0];
                        reg_tmp.h[0] = SPIN(reg_a4)->saved_b[1];
                        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
                        reg_d0.b[0] = SPIN(reg_a4)->direction;
                        SPIN(reg_a4)->angle -= reg_d0.b[0];
                    }
                } else {
                    reg_d0.b[0] = ENTITY(reg_a6)[2].draw.b.flip;
                    reg_d0.b[0] &= 0xFE;
                    if (reg_d0.b[0] == 0x40) {
                        ENTITY(reg_a6)[2].draw.b.flip = 0x40U;
                        ENTITY(reg_a6)[4].draw.b.flip = 0xC0U;
                        SPIN(reg_a4)->step = 3U;
                        reg_d0.w = 5;
                        boss_attack_stop();
                        reg_d0.w = 6;
                        boss_attack_stop();
                        reg_d0.w = 0xE;
                        boss_attack_stop();
                    }
                }
            }
        }
        if (SPIN(reg_a4)->step == 3) {
            SPIN(reg_a4)->running = 0;
            STAGE1_EXTRA(reg_a6)->spinning = 0;
        }
    }
}



void stage1_boss_right_close_start(void) {
    DOOR(reg_a4)->frame.h = 0;
    DOOR(reg_a4)->delay = 0x20;
    DOOR(reg_a4)->moving = 0;
}

void stage1_boss_right_close() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if (DOOR(reg_a4)->moving == 0) {
        temp_v1 = DOOR(reg_a4)->delay;
        if (temp_v1 != 0) {
            DOOR(reg_a4)->delay = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = ENTITY(reg_a6)[1].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                boss_animation_stop();
                DOOR(reg_a4)->moving = 1U;
            }
        }
    }
    if (DOOR(reg_a4)->moving == 1) {
        reg_tmp.b[0] = DOOR(reg_a4)->frame.t.count;
        DOOR(reg_a4)->frame.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            DOOR(reg_a4)->frame.t.count = (u8) DOOR(reg_a4)->frame.t.reload;
            ENTITY(reg_a6)[2].sprite.h -= 0xC0;
            ENTITY(reg_a6)[2].draw.b.priority -= 2;
            ENTITY(reg_a6)[1].draw.h -= 4;
            temp_a0_2 = ENTITY(reg_a6)[1].draw.h;
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 2;
                boss_animation_start();
                DOOR(reg_a4)->running = 0;
            }
        }
    }
}

void stage1_boss_left_close_start(void) {
    DOOR(reg_a4)->frame.h = 0;
    DOOR(reg_a4)->delay = 0x20;
    DOOR(reg_a4)->moving = 0;
}

void stage1_boss_left_close() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if (DOOR(reg_a4)->moving == 0) {
        temp_v1 = DOOR(reg_a4)->delay;
        if (temp_v1 != 0) {
            DOOR(reg_a4)->delay = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = ENTITY(reg_a6)[3].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xB;
                boss_animation_stop();
                DOOR(reg_a4)->moving = 1U;
            }
        }
    }
    if (DOOR(reg_a4)->moving == 1) {
        reg_tmp.b[0] = DOOR(reg_a4)->frame.t.count;
        DOOR(reg_a4)->frame.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            DOOR(reg_a4)->frame.t.count = (u8) DOOR(reg_a4)->frame.t.reload;
            ENTITY(reg_a6)[4].sprite.h -= 0xC0;
            ENTITY(reg_a6)[4].draw.b.priority -= 2;
            ENTITY(reg_a6)[3].draw.h -= 4;
            temp_a0_2 = ENTITY(reg_a6)[3].draw.h;
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 3;
                boss_animation_start();
                DOOR(reg_a4)->running = 0;
            }
        }
    }
}

void stage1_boss_gatling_recenter_start(void) {
    ROTOR(reg_a4)->frame.h = 0x101;
}

s32 direction_turn_toward();

void stage1_boss_gatling_recenter() {
    reg_tmp.b[0] = ROTOR(reg_a4)->frame.t.count;
    ROTOR(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ROTOR(reg_a4)->frame.t.count = (u8) ROTOR(reg_a4)->frame.t.reload;
        reg_d1.w = 0;
        reg_d1.b[0] = 0x20;
        reg_d0.w = 0;
        reg_d0.h[0] = ENTITY(reg_a6)[5].sprite.h;
        reg_d0.h[0] += 0x20;
        direction_turn_toward();
        reg_d0.h[0] = reg_d1.h[0];
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] -= 0x20;
        ENTITY(reg_a6)[5].sprite.h = (u16) reg_d0.h[0];
        if (reg_d1.b[0] == 0x20) {
            ROTOR(reg_a4)->running = 0;
        }
    }
}

void stage1_boss_right_open_wide_start(void) {
    DOOR(reg_a4)->frame.h = 0;
    DOOR(reg_a4)->moving = 0;
}

void stage1_boss_right_open_wide() {
    u16 temp_a0;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if ((DOOR(reg_a4)->moving == 0) && (ENTITY(reg_a6)[1].draw.h == 0)) {
        reg_d0.w = 2;
        boss_animation_stop();
        ENTITY(reg_a6)[1].draw.h = 0x10U;
        DOOR(reg_a4)->moving = 1U;
    }
    if (DOOR(reg_a4)->moving == 1) {
        reg_tmp.b[0] = DOOR(reg_a4)->frame.t.count;
        DOOR(reg_a4)->frame.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            DOOR(reg_a4)->frame.t.count = (u8) DOOR(reg_a4)->frame.t.reload;
            ENTITY(reg_a6)[2].sprite.h += 0xC0;
            ENTITY(reg_a6)[2].draw.b.priority -= 2;
            ENTITY(reg_a6)[1].draw.h += 4;
            temp_a0 = ENTITY(reg_a6)[1].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                boss_animation_start();
                DOOR(reg_a4)->running = 0;
            }
        }
    }
}



void stage1_boss_left_open_wide_start(void) {
    DOOR(reg_a4)->frame.h = 0;
    DOOR(reg_a4)->moving = 0;
}

void stage1_boss_left_open_wide() {
    u16 temp_a0;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if ((DOOR(reg_a4)->moving == 0) && (ENTITY(reg_a6)[3].draw.h == 0)) {
        reg_d0.w = 3;
        boss_animation_stop();
        ENTITY(reg_a6)[3].draw.h = 0x10U;
        DOOR(reg_a4)->moving = 1U;
    }
    if (DOOR(reg_a4)->moving == 1) {
        reg_tmp.b[0] = DOOR(reg_a4)->frame.t.count;
        DOOR(reg_a4)->frame.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            DOOR(reg_a4)->frame.t.count = (u8) DOOR(reg_a4)->frame.t.reload;
            ENTITY(reg_a6)[4].sprite.h += 0xC0;
            ENTITY(reg_a6)[4].draw.b.priority -= 2;
            ENTITY(reg_a6)[3].draw.h += 4;
            temp_a0 = ENTITY(reg_a6)[3].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xB;
                boss_animation_start();
                DOOR(reg_a4)->running = 0;
            }
        }
    }
}



void stage1_boss_right_close_wide_start(void) {
    DOOR(reg_a4)->frame.h = 0;
    DOOR(reg_a4)->delay = 0x20;
    DOOR(reg_a4)->moving = 0;
}

void stage1_boss_right_close_wide() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if (DOOR(reg_a4)->moving == 0) {
        temp_v1 = DOOR(reg_a4)->delay;
        if (temp_v1 != 0) {
            DOOR(reg_a4)->delay = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = ENTITY(reg_a6)[1].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                boss_animation_stop();
                DOOR(reg_a4)->moving = 1U;
            }
        }
    }
    if (DOOR(reg_a4)->moving == 1) {
        reg_tmp.b[0] = DOOR(reg_a4)->frame.t.count;
        DOOR(reg_a4)->frame.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            DOOR(reg_a4)->frame.t.count = (u8) DOOR(reg_a4)->frame.t.reload;
            ENTITY(reg_a6)[2].sprite.h -= 0xC0;
            ENTITY(reg_a6)[2].draw.b.priority += 2;
            ENTITY(reg_a6)[1].draw.h -= 4;
            temp_a0_2 = ENTITY(reg_a6)[1].draw.h;
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 2;
                boss_animation_start();
                DOOR(reg_a4)->running = 0;
            }
        }
    }
}

void stage1_boss_left_close_wide_start(void) {
    DOOR(reg_a4)->frame.h = 0;
    DOOR(reg_a4)->delay = 0x20;
    DOOR(reg_a4)->moving = 0;
}

void stage1_boss_left_close_wide() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if (DOOR(reg_a4)->moving == 0) {
        temp_v1 = DOOR(reg_a4)->delay;
        if (temp_v1 != 0) {
            DOOR(reg_a4)->delay = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = ENTITY(reg_a6)[3].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xB;
                boss_animation_stop();
                DOOR(reg_a4)->moving = 1U;
            }
        }
    }
    if (DOOR(reg_a4)->moving == 1) {
        reg_tmp.b[0] = DOOR(reg_a4)->frame.t.count;
        DOOR(reg_a4)->frame.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            DOOR(reg_a4)->frame.t.count = (u8) DOOR(reg_a4)->frame.t.reload;
            ENTITY(reg_a6)[4].sprite.h -= 0xC0;
            ENTITY(reg_a6)[4].draw.b.priority += 2;
            ENTITY(reg_a6)[3].draw.h -= 4;
            temp_a0_2 = ENTITY(reg_a6)[3].draw.h;
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 3;
                boss_animation_start();
                DOOR(reg_a4)->running = 0;
            }
        }
    }
}

void stage1_boss_gatling_fast_spin_start(void) {
    ENTITY(reg_a6)[5].look.sh = 0;
}

void stage1_boss_gatling_fast_spin(void) {
    ENTITY(reg_a6)[5].draw.h += 4;
    if ((s16) ENTITY(reg_a6)[5].draw.h >= 0x1C) {
        ENTITY(reg_a6)[5].draw.h = 0U;
    }
}

u8 stage1_boss_spin_start_table[8] = {
    0x07, 0x06, 0x05, 0x04, 0x04, 0x04, 0x04, 0x04,
};

u8 stage1_boss_spin_start_table_2[8] = {
    0x16, 0x14, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D,
};
