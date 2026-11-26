#include "common.h"
#include "pc_replay_storage.h"
#include "pc_enemy_animation.h"

#include <stdio.h>

extern u16 D_00242020[];
extern u16 D_00242058[];
extern u16 bullet_move_routines[];
extern u16 D_0024EBC0[];
extern s32 D_006C4AE8[];
extern u8 D_00257C10[];
extern u8 D_00257D20[];
extern u16 D_0024F3D8[];
extern u16 D_0024F400[];
extern u16 D_0028C0E0[];

static unsigned selected_draw;
void entity_draw_layer1(void) { selected_draw = 1; }
void entity_draw_layer2(void) { selected_draw = 2; }
void entity_draw_layer3(void) { selected_draw = 3; }
void entity_draw_layer4(void) { selected_draw = 4; }
void entity_draw_layer5(void) { selected_draw = 5; }

static int same_address(const void *volatile actual, const void *expected, const char *name)
{
    if (actual == expected) {
        return 1;
    }
    fprintf(stderr, "%s points to %p, expected %p\n", name, actual, expected);
    return 0;
}

static int check_enemy_animation(void)
{
    pc_enemy_animation_draw(0x14)();
    return selected_draw == 5 && D_0024F3D8[0] == 0x8000 &&
           same_address(pc_enemy_animation_definition(0), D_0024F3D8, "first enemy animation") &&
           same_address(pc_enemy_animation_definition(4), D_0024F400, "second enemy animation") &&
           same_address(pc_enemy_animation_definition(24), D_0028C0E0, "last enemy animation pair");
}

int main(void)
{
    return !(same_address(D_00242058, D_00242020 + 0x38 / sizeof(u16), "mounted tank table") &&
             same_address(D_0024EBC0,
                          bullet_move_routines + MAIN_OR_DEATH_LABEL(0x90, 0xa0) / sizeof(u16),
                          "bullet move table") &&
             same_address(D_006C4AE8, g_replay_file_loaded + 0x202e8, "loaded replay checksum") &&
             same_address(D_00257D20, D_00257C10 + 0x110, "ground enemy record") &&
             check_enemy_animation());
}
