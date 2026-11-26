/* Data of the Death Label stage 5 boss movement. */
#include "common.h"

void twin_boss_move_wander_a_start();
void twin_boss_move_wander_a();
void twin_boss_move_wander_b_start();
void twin_boss_move_wander_b();
void twin_boss_move_wander_c_start();
void twin_boss_move_wander_c();
void twin_boss_move_wander_d_start();
void twin_boss_move_wander_d();
void twin_boss_move_wander_e_start();
void twin_boss_move_wander_e();

extern void *g_twin_boss_move_routines[10];

void *g_twin_boss_move_routines[10] = {
    twin_boss_move_wander_a_start,
    twin_boss_move_wander_a,
    twin_boss_move_wander_b_start,
    twin_boss_move_wander_b,
    twin_boss_move_wander_c_start,
    twin_boss_move_wander_c,
    twin_boss_move_wander_d_start,
    twin_boss_move_wander_d,
    twin_boss_move_wander_e_start,
    twin_boss_move_wander_e,
};
