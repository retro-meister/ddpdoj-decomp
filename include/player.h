#ifndef DDPDOJ_PLAYER_H
#define DDPDOJ_PLAYER_H

#include "entity.h"

/*
 * A player's ship. It starts with the fields every game object has (see Entity), with the pad state where other
 * objects keep their hit points, and goes on with the ship's own state. The ship routines get it in reg_a6.
 */
typedef struct {
    /* 0x00 */ Field16 flags;
    /* 0x02 */ Field16 y;
    /* 0x04 */ Field16 x;
    /* 0x06 */ Field16 offset_y;
    /* 0x08 */ Field16 offset_x;
    /* 0x0A */ Field16 sprite_hi;            /* sprite number, 32 bits, high word first */
    /* 0x0C */ Field16 sprite_lo;
    /* 0x0E */ Field16 size;
    /* 0x10 */ Field16 hit_y_plus;
    /* 0x12 */ Field16 hit_y_minus;
    /* 0x14 */ Field16 hit_x_plus;
    /* 0x16 */ Field16 hit_x_minus;
    /* 0x18 */ union { u16 h; s16 sh; struct { u8 filtered; u8 raw; } b; struct { s8 filtered; s8 raw; } sb; } input;
    /* 0x1A */ union { u16 h; s16 sh; struct { u8 dir; u8 speed; } b; struct { s8 dir; s8 speed; } sb; } move;
    /* 0x1C */ union { u16 h; s16 sh; struct { u8 palette; u8 flip; } b; struct { s8 palette; s8 flip; } sb; } attr;
    /* 0x1E */ Field16 unk_1E;
    /* 0x20 */ Field16 shot_power;           /* 0..4 */
    /* 0x22 */ Field16 laser_power;          /* 0..4 */
    /* 0x24 */ union { u16 h; s16 sh; struct { u8 capacity; u8 count; } b; struct { s8 capacity; s8 count; } sb; } bombs;
    /* 0x26 */ Field16 shield_anim_delay;
    /* 0x28 */ Field16 shield_anim_frame;
    /* 0x2A */ union { u16 h; s16 sh; struct { u8 shots; u8 wait; } b; struct { s8 shots; s8 wait; } sb; } burst;
    /* 0x2C */ union { u16 h; s16 sh; struct { u8 shots; u8 wait; } b; struct { s8 shots; s8 wait; } sb; } burst_reset;
    /* 0x2E */ Field16 gun_flash_count;
    /* 0x30 */ Field16 moved_y;              /* distance moved this frame */
    /* 0x32 */ Field16 moved_x;
    /* 0x34 */ union { u16 h; s16 sh; struct { u8 shots; u8 wait; } b; struct { s8 shots; s8 wait; } sb; } option_burst;
    /* 0x36 */ union { u16 h; s16 sh; struct { u8 shots; u8 wait; } b; struct { s8 shots; s8 wait; } sb; } option_burst_reset;
    /* 0x38 */ union { u16 h; s16 sh; struct { u8 normal; u8 laser_min; } b; struct { s8 normal; s8 laser_min; } sb; } speed;
    /* 0x3A */ union { u16 h; s16 sh; struct { u8 default_palette; u8 shot_sound_wait; } b; struct { s8 default_palette; s8 shot_sound_wait; } sb; } aux;
    /* 0x3C */ Field16 fire_lockout;
    /* 0x3E */ union { u16 h; s16 sh; struct { u8 laser_mode; u8 invincible; } b; struct { s8 laser_mode; s8 invincible; } sb; } state;   /* invincible: frames left, 0xFF: until cleared */
    /* 0x40 */ Field16 bomb_recoil;
    /* 0x42 */ Field16 gun_index;
    /* 0x44 */ Field16 shot_counter;
    /* 0x46 */ Field16 laser_bomb_recoil;
    /* 0x48 */ Field16 exhaust_frame;
    /* 0x4A */ union { u16 h; s16 sh; struct { u8 reset; u8 wait; } b; struct { s8 reset; s8 wait; } sb; } brake;
    /* 0x4C */ Field16 roll_delay;
    /* 0x4E */ Field16 roll_frame;
    /* 0x50 */ Field16 max_text_sprite_hi;
    /* 0x52 */ Field16 max_text_sprite_lo;
    /* 0x54 */ union { u16 h; s16 sh; struct { u8 hyper_palette; u8 shot_palette; } b; struct { s8 hyper_palette; s8 shot_palette; } sb; } weapon;
    /* 0x56 */ union { u16 h; s16 sh; struct { u8 side; u8 palette; } b; struct { s8 side; s8 palette; } sb; } who;   /* side: 0 player 1, 1 player 2 */
    /* 0x58 */ Field16 ship_type;            /* 0: type A, 2: type B */
    /* 0x5A */ Field16 power_style;          /* 2: shot, 4: laser, 6: expert */
    /* 0x5C */ Field16 scroll_offset;
    /* 0x5E */ Field16 laser_recoil;
    /* 0x60 */ Field16 zoom;
} Player;

#define PLAYER(pointer) ((Player *)(pointer))

#endif
