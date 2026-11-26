/* Data of the Death Label stage 5 boss attacks. */
#include "common.h"

void twin_boss_first_fire_attack_b_start();
void twin_boss_first_fire_attack_b();
void twin_boss_first_fire_attack_c_start();
void twin_boss_first_fire_attack_c();
void twin_boss_first_fire_spiral_start();
void twin_boss_first_fire_spiral();
void twin_boss_first_fire_rage_start();
void twin_boss_first_fire_rage();
void twin_boss_first_fire_stinger_start();
void twin_boss_first_fire_stinger();
void twin_boss_first_fire_form1_rage_start();
void twin_boss_first_fire_form1_rage();
void twin_boss_first_fire_jet_start();
void twin_boss_first_fire_jet();
void twin_boss_second_fire_attack_b_start();
void twin_boss_second_fire_attack_b();
void twin_boss_second_fire_attack_c_start();
void twin_boss_second_fire_attack_c();
void twin_boss_second_fire_spiral_start();
void twin_boss_second_fire_spiral();
void twin_boss_second_fire_rage_start();
void twin_boss_second_fire_rage();
void twin_boss_second_fire_stinger_start();
void twin_boss_second_fire_stinger();
void twin_boss_second_fire_form1_rage_start();
void twin_boss_second_fire_form1_rage();
void twin_boss_second_fire_jet_start();
void twin_boss_second_fire_jet();

extern void *g_twin_boss_attack_routines[32];

void *g_twin_boss_attack_routines[32] = {
    twin_boss_first_fire_stinger_start,
    twin_boss_first_fire_stinger,
    twin_boss_second_fire_stinger_start,
    twin_boss_second_fire_stinger,
    twin_boss_first_fire_attack_b_start,
    twin_boss_first_fire_attack_b,
    twin_boss_second_fire_attack_b_start,
    twin_boss_second_fire_attack_b,
    twin_boss_first_fire_attack_c_start,
    twin_boss_first_fire_attack_c,
    twin_boss_second_fire_attack_c_start,
    twin_boss_second_fire_attack_c,
    twin_boss_first_fire_spiral_start,
    twin_boss_first_fire_spiral,
    twin_boss_second_fire_spiral_start,
    twin_boss_second_fire_spiral,
    twin_boss_first_fire_rage_start,
    twin_boss_first_fire_rage,
    twin_boss_second_fire_rage_start,
    twin_boss_second_fire_rage,
    twin_boss_first_fire_stinger_start,
    twin_boss_first_fire_stinger,
    twin_boss_second_fire_stinger_start,
    twin_boss_second_fire_stinger,
    twin_boss_first_fire_form1_rage_start,
    twin_boss_first_fire_form1_rage,
    twin_boss_second_fire_form1_rage_start,
    twin_boss_second_fire_form1_rage,
    twin_boss_first_fire_jet_start,
    twin_boss_first_fire_jet,
    twin_boss_second_fire_jet_start,
    twin_boss_second_fire_jet,
};
