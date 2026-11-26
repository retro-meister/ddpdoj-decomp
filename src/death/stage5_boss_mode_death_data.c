/* Data of the Death Label stage 5 boss modes. */
#include "common.h"

void twin_boss_mode_attack_b_start();
void twin_boss_mode_attack_b();
void twin_boss_mode_attack_c_start();
void twin_boss_mode_attack_c();
void twin_boss_mode_spiral_start();
void twin_boss_mode_spiral();
void twin_boss_mode_rage_start();
void twin_boss_mode_rage();
void twin_boss_mode_jet_start();
void twin_boss_mode_jet();

struct TwinBossModes { void *routines[10]; u16 words[4]; };
extern struct TwinBossModes g_twin_boss_modes;

struct TwinBossModes g_twin_boss_modes = {
    {
        twin_boss_mode_attack_b_start,
        twin_boss_mode_attack_b,
        twin_boss_mode_attack_c_start,
        twin_boss_mode_attack_c,
        twin_boss_mode_spiral_start,
        twin_boss_mode_spiral,
        twin_boss_mode_rage_start,
        twin_boss_mode_rage,
        twin_boss_mode_jet_start,
        twin_boss_mode_jet,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};
