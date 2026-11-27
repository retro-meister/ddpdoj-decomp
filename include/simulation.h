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

typedef union {
    s16 values[6];
    struct {
        s16 maximum_level;
        s16 maximum_multiplier;
        s16 hyper_uses;
        s16 laser_level;
        s16 shot_level;
        s16 dropped_powerups;
    };
} SimPowerOptions;

enum { SIM_SHIP_STOCK_FREE = 20 };

typedef union {
    s16 values[5];
    struct {
        s16 difficulty;
        s16 ship_type;
        s16 doll_type;
        s16 ship_stock;
        s16 extend;
    };
} SimShipOptions;

typedef union {
    s16 values[11];
    struct {
        s16 start_point;
        s16 keep_power_on_death;
        s16 rank;
        s16 bomb_capacity;
        s16 bomb_stock;
        s16 hyper_active;
        s16 hyper_time;
        s16 hyper_stock;
        s16 hyper_gauge;
        s16 stage_selection;
        s16 custom_rank;
    };
} SimStartOptions;

typedef struct {
    SimShipOptions ship;
    /* 0x0A */ u8 unused_0A[6];
    SimPowerOptions power;
    /* 0x1C */ u8 unused_1C[4];
    SimStartOptions start;
    /* 0x36 */ u8 unused_36[2];
} SimStoredOptions;

typedef struct {
    SimPowerOptions power;
    /* 0x0C */ u8 unused_0C[4];
    SimShipOptions ship;
    /* 0x1A */ u8 unused_1A[14];
    SimStartOptions start;
    /* 0x3E */ u8 unused_3E[10];
} SimEditingOptions;

typedef struct {
    SimStoredOptions stored;
    SimEditingOptions editing;
} SimulationMenuOptions;

extern SimulationMenuOptions g_sim_menu_options;

#endif
