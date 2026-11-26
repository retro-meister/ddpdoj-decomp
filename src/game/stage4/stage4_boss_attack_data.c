/* Data of the stage4 boss attack unit, still to be merged into it. */
#include "common.h"

void stage4_boss_right_spinner_volleys_start();
void stage4_boss_right_spinner_volleys();
void stage4_boss_right_spinner_volleys_b_start();
void stage4_boss_right_spinner_volleys_b();
void stage4_boss_right_spinner_arms_start();
void stage4_boss_right_spinner_arms();
void stage4_boss_fire_doubles();
void stage4_boss_fire_doubles_3way();
void stage4_boss_fire_2ways_3way();
void stage4_boss_right_spinner_rounds_start();
void stage4_boss_right_spinner_rounds();
void stage4_boss_right_spinner_sweep_start();
void stage4_boss_right_spinner_sweep();
void stage4_boss_left_spinner_volleys_start();
void stage4_boss_left_spinner_volleys();
void stage4_boss_left_spinner_volleys_b_start();
void stage4_boss_left_spinner_volleys_b();
void stage4_boss_left_spinner_arms_start();
void stage4_boss_left_spinner_arms();
void stage4_boss_left_spinner_rounds_start();
void stage4_boss_left_spinner_rounds();
void stage4_boss_left_spinner_sweep_start();
void stage4_boss_left_spinner_sweep();
void stage4_boss_fire_fixed_1();
void stage4_boss_fire_fixed_2way();
void stage4_boss_fire_fixed_3way();
void stage4_boss_fire_fixed_4way();
void stage4_boss_fire_fixed_fan_a();
void stage4_boss_fire_fixed_fan_b();

extern u8 D_0026EBD0[176];
extern void *stage4_boss_right_spinner_routines[20];
struct Stage4BossLeftSpinnerRoutinesRecord { void *p0; void *p1; void *p2; void *p3; void *p4; void *p5; void *p6; void *p7; void *p8; void *p9; void *p10; void *p11; void *p12; void *p13; void *p14; void *p15; u16 w16[72]; void *p17; void *p18; void *p19; void *p20; void *p21; void *p22; void *p23; void *p24; u16 w25[8]; };
extern struct Stage4BossLeftSpinnerRoutinesRecord stage4_boss_left_spinner_routines;
extern s32 D_0028DC60[1];
extern s32 D_0028DC64[1];
extern u16 D_0028DC68[2];
extern u16 D_0028DC6C[2];
extern u16 D_0028DC70[4];
extern void *D_0028DC78[2];

u8 D_0026EBD0[176] = {
    0x80, 0x07, 0x40, 0xFE, 0x80, 0x03, 0x40, 0xFE, 0xC0, 0xFF, 0x40, 0xFE, 0xC0, 0xFB, 0x40, 0xFE,
    0x80, 0x07, 0xC0, 0x01, 0x80, 0x03, 0xC0, 0x01, 0xC0, 0xFF, 0xC0, 0x01, 0xC0, 0xFB, 0xC0, 0x01,
    0x40, 0x07, 0x00, 0x00, 0x40, 0x07, 0x40, 0x01, 0x00, 0x07, 0x80, 0x02, 0x00, 0x06, 0x80, 0x03,
    0x00, 0x05, 0x40, 0x04, 0xC0, 0x03, 0xC0, 0x04, 0x00, 0x02, 0x00, 0x05, 0x80, 0x00, 0xC0, 0x04,
    0x40, 0xFF, 0xC0, 0x04, 0x00, 0xFE, 0x00, 0x04, 0xC0, 0xFC, 0xC0, 0x02, 0x40, 0xFC, 0x40, 0x01,
    0x00, 0xFC, 0x00, 0x00, 0x00, 0xFC, 0x40, 0xFE, 0xC0, 0xFC, 0xC0, 0xFC, 0x00, 0xFE, 0x00, 0xFC,
    0x40, 0xFF, 0x40, 0xFB, 0x80, 0x00, 0x40, 0xFB, 0x00, 0x02, 0x00, 0xFB, 0x00, 0x02, 0xC0, 0xFA,
    0x80, 0x03, 0x40, 0xFB, 0x00, 0x05, 0x80, 0xFB, 0x40, 0x06, 0x40, 0xFC, 0x00, 0x07, 0x80, 0xFD,
    0x40, 0x07, 0x80, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x14, 0x20, 0x28, 0x30, 0x34, 0x40, 0x48, 0x50, 0x62, 0x72, 0x80, 0x8E, 0x9E, 0xB0,
    0xB8, 0xC0, 0xCC, 0xD0, 0xD8, 0xE0, 0xEC, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

void *stage4_boss_right_spinner_routines[20] = {
    stage4_boss_right_spinner_volleys_start,
    stage4_boss_right_spinner_volleys,
    stage4_boss_right_spinner_volleys_b_start,
    stage4_boss_right_spinner_volleys_b,
    stage4_boss_right_spinner_arms_start,
    stage4_boss_right_spinner_arms,
    stage4_boss_right_spinner_sweep_start,
    stage4_boss_right_spinner_sweep,
    stage4_boss_right_spinner_volleys_start,
    stage4_boss_right_spinner_volleys,
    stage4_boss_right_spinner_arms_start,
    stage4_boss_right_spinner_arms,
    stage4_boss_right_spinner_rounds_start,
    stage4_boss_right_spinner_rounds,
    stage4_boss_right_spinner_sweep_start,
    stage4_boss_right_spinner_sweep,
    stage4_boss_fire_doubles,
    stage4_boss_fire_doubles_3way,
    stage4_boss_fire_2ways_3way,
    stage4_boss_fire_doubles,
};

struct Stage4BossLeftSpinnerRoutinesRecord stage4_boss_left_spinner_routines = {
    stage4_boss_left_spinner_volleys_start,
    stage4_boss_left_spinner_volleys,
    stage4_boss_left_spinner_volleys_b_start,
    stage4_boss_left_spinner_volleys_b,
    stage4_boss_left_spinner_arms_start,
    stage4_boss_left_spinner_arms,
    stage4_boss_left_spinner_sweep_start,
    stage4_boss_left_spinner_sweep,
    stage4_boss_left_spinner_volleys_start,
    stage4_boss_left_spinner_volleys,
    stage4_boss_left_spinner_arms_start,
    stage4_boss_left_spinner_arms,
    stage4_boss_left_spinner_rounds_start,
    stage4_boss_left_spinner_rounds,
    stage4_boss_left_spinner_sweep_start,
    stage4_boss_left_spinner_sweep,
    { 0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F, 0x090E, 0xF000, 0x55E0, 0x3545, 0x9BAB, 0x008B, 0x0000, 0x0000, 0x09F2, 0x1000, 0x5520, 0x7565, 0xBBAB, 0x00CB, 0x0000, 0x0000, 0x080E, 0x2000, 0x6040, 0xA080, 0xE0C0, 0x0000, 0x0000, 0x0000, 0x08F2, 0x2000, 0x6040, 0xA080, 0xE0C0, 0x0000, 0x0000, 0x0000, 0x0A0E, 0x0000, 0x01F0, 0x02E0, 0x03D0, 0x0480, 0x0570, 0x0660, 0x0750, 0x70E8, 0x7168, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xF640, 0xF980, 0xF640, 0x0680, 0xFE00, 0xF980, 0xFE00, 0x0680 },
    stage4_boss_fire_fixed_1,
    stage4_boss_fire_fixed_1,
    stage4_boss_fire_fixed_2way,
    stage4_boss_fire_fixed_2way,
    stage4_boss_fire_fixed_3way,
    stage4_boss_fire_fixed_3way,
    stage4_boss_fire_fixed_4way,
    stage4_boss_fire_fixed_4way,
    { 0x0800, 0x0E00, 0x0800, 0x1400, 0x0800, 0xF200, 0x0800, 0xEC00 },
};

s32 D_0028DC60[1] = {
    9988224,
};

s32 D_0028DC64[1] = {
    6854784,
};

u16 D_0028DC68[2] = {
    0x0000, 0x0001,
};

u16 D_0028DC6C[2] = {
    0x0000, 0x0001,
};

u16 D_0028DC70[4] = {
    0x03F6, 0x0400, 0x0455, 0x04AB,
};

void *D_0028DC78[2] = {
    stage4_boss_fire_fixed_fan_a,
    stage4_boss_fire_fixed_fan_b,
};
