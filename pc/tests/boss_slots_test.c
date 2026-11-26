#include "common.h"

#include <stdio.h>

void boss_slots_init(void);
void boss_slots_run(void);
void boss_slots_end(void);
void boss_movement_start(void);
void boss_attack_start(void);
void boss_animation_start(void);
void boss_phase_start(void);
void boss_part_show(void);

typedef void (*BossRoutine)(void);

static unsigned inits;
static unsigned updates;
static unsigned draws;

static void initialize_slot(void) {
    ++inits;
}

static void update_slot(void) {
    ++updates;
}

static void draw_part(void) {
    ++draws;
}

s32 sprite_draw_with_warning_keep(void) {
    return 0;
}

int main(void) {
    BossRoutine callbacks[] = {NULL, NULL, initialize_slot, update_slot};
    BossRoutine parts[] = {draw_part, (BossRoutine)-1};
    pc_arcade_address_init();

    reg_a0 = (u8 *)callbacks;
    reg_a1 = (u8 *)callbacks;
    reg_a2 = (u8 *)parts;
    reg_a3 = (u8 *)callbacks;
    reg_a4 = (u8 *)callbacks;
    boss_slots_init();

    reg_d0.w = 1;
    boss_movement_start();
    boss_attack_start();
    boss_animation_start();
    boss_phase_start();
    reg_d0.w = 0;
    boss_part_show();
    boss_slots_run();
    boss_slots_run();
    if (inits != 4 || updates != 4 || draws != 2) {
        fprintf(stderr, "Expected four initializers, four updates and two draws, got %u, %u and %u\n",
                inits, updates, draws);
        return 1;
    }

    boss_slots_end();
    boss_slots_run();
    if (!cond_flag || updates != 4 || draws != 2) {
        fputs("Finished boss slots still dispatch callbacks\n", stderr);
        return 1;
    }

    reg_a0 = reg_a1 = reg_a2 = reg_a3 = reg_a4 = NULL;
    boss_slots_init();
    boss_slots_run();
    if (cond_flag || inits != 4 || updates != 4 || draws != 2) {
        fputs("Reset boss slots retain callbacks or the end flag\n", stderr);
        return 1;
    }
    return 0;
}
