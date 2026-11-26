#ifndef DDPDOJ_EFFECT_TABLES_H
#define DDPDOJ_EFFECT_TABLES_H

#include "types.h"

typedef void (*EffectRoutine)(void);

struct ExplosionLifetimeTable {
    u16 timings[16];
    EffectRoutine draw[5];
    u16 padding[6];
};

extern struct ExplosionLifetimeTable explosion_scripts_33;

struct DebrisTables {
    EffectRoutine draw[5];
    u16 directions[294];
    EffectRoutine initialize[5];
    u16 padding[6];
};

extern struct DebrisTables debris_update_loop_value;

struct DebrisPatterns {
    u16 frame_addresses[8];
    u8 *parameters[5];
    u16 padding[6];
};

extern struct DebrisPatterns debris_random_patterns;

#endif
