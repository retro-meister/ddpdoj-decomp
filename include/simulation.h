#ifndef DDPDOJ_SIMULATION_H
#define DDPDOJ_SIMULATION_H

#include "entity.h"

typedef struct {
    /* 0x00 */ u16 p1_ship_type;
    /* 0x02 */ u16 p1_power_style;
    /* 0x04 */ u16 p2_ship_type;
    /* 0x06 */ u16 p2_power_style;
    /* 0x08 */ Field16 difficulty;
    /* 0x0A */ u16 loop;
    /* 0x0C */ u16 stage;
    /* 0x0E */ Field16 ship_stock;
    /* 0x10 */ Field16 extend;
    /* 0x12 */ u16 death_power_style;
    /* 0x14 */ u16 task_step;
    /* 0x16 */ u16 unused_16[5];
} SimulationRules;

extern SimulationRules g_sim_rules;

#endif
