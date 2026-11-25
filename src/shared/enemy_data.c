/* Data of the enemy unit, still to be merged into it. */
#include "common.h"

extern u8 D_0027D960[];
extern u8 D_0027E400[];
extern u8 D_0027E420[];
extern u8 D_0027E570[];
extern u8 D_0027F300[];
extern u8 D_0027FD70[];
extern u8 D_0027FD90[];
extern u8 D_0027FEF0[];
extern u8 D_00281020[];
extern u8 D_00281D20[];
extern u8 D_00281D40[];
extern u8 D_00281E40[];
extern u8 D_00282650[];
extern u8 D_00283250[];
extern u8 D_00283270[];
extern u8 D_002833B0[];
extern u8 D_00284750[];
extern u8 D_00285F70[];
extern u8 D_00285FA0[];
extern u8 D_002861B0[];
void enemy_script_air_collision();
void enemy_script_air_scroll_check();
void enemy_script_end();
void enemy_script_ground_collision();
void enemy_script_loop();
void enemy_script_poke_entity();
void enemy_script_poke_task();
void enemy_script_set_entity_1e();
void enemy_script_set_entity_1f();
void enemy_script_set_work_22();
void enemy_script_set_work_24();
void enemy_script_unused();

struct D0026a2b0Record { void *p0[3]; u16 w1[2]; void *p2[3]; u16 w3[2]; void *p4[3]; u16 w5[2]; void *p6[3]; u16 w7[2]; void *p8[3]; u16 w9[2]; void *p10[3]; u16 w11[2]; void *p12[3]; u16 w13[2]; void *p14[3]; u16 w15[2]; void *p16[3]; u16 w17[2]; void *p18[3]; u16 w19[2]; void *p20[12]; };
extern struct D0026a2b0Record D_0026A2B0;

struct D0026a2b0Record D_0026A2B0 = {
    {
        D_0027D960,
        D_0027E420,
        D_0027E570,
    },
    { 0x0000, 0x0000 },
    {
        D_0027F300,
        D_0027FD90,
        D_0027FEF0,
    },
    { 0x0000, 0x0000 },
    {
        D_00281020,
        D_00281D40,
        D_00281E40,
    },
    { 0x0000, 0x0000 },
    {
        D_00282650,
        D_00283270,
        D_002833B0,
    },
    { 0x0000, 0x0000 },
    {
        D_00284750,
        D_00285FA0,
        D_002861B0,
    },
    { 0x0000, 0x0000 },
    {
        D_0027E400,
        D_0027E420,
        D_0027E570,
    },
    { 0x0000, 0x0000 },
    {
        D_0027FD70,
        D_0027FD90,
        D_0027FEF0,
    },
    { 0x0000, 0x0000 },
    {
        D_00281D20,
        D_00281D40,
        D_00281E40,
    },
    { 0x0000, 0x0000 },
    {
        D_00283250,
        D_00283270,
        D_002833B0,
    },
    { 0x0000, 0x0000 },
    {
        D_00285F70,
        D_00285FA0,
        D_002861B0,
    },
    { 0x0000, 0x0000 },
    {
        enemy_script_loop,
        enemy_script_set_entity_1f,
        enemy_script_ground_collision,
        enemy_script_air_collision,
        enemy_script_set_work_22,
        enemy_script_poke_task,
        enemy_script_poke_entity,
        enemy_script_set_work_24,
        enemy_script_set_entity_1e,
        enemy_script_air_scroll_check,
        enemy_script_end,
        enemy_script_unused,
    },
};
