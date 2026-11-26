#include "common.h"
#include "pc_replay_storage.h"

#include <stdio.h>

extern u16 D_00242020[];
extern u16 D_00242058[];
extern u16 bullet_move_routines[];
extern u16 D_0024EBC0[];
extern s32 D_006C4AE8[];
extern u8 D_00257C10[];
extern u8 D_00257D20[];

static int same_address(const void *volatile actual, const void *expected, const char *name)
{
    if (actual == expected) {
        return 1;
    }
    fprintf(stderr, "%s points to %p, expected %p\n", name, actual, expected);
    return 0;
}

int main(void)
{
    return !(same_address(D_00242058, D_00242020 + 0x38 / sizeof(u16), "mounted tank table") &&
             same_address(D_0024EBC0,
                          bullet_move_routines + MAIN_OR_DEATH_LABEL(0x90, 0xa0) / sizeof(u16),
                          "bullet move table") &&
             same_address(D_006C4AE8, g_replay_file_loaded + 0x202e8, "loaded replay checksum") &&
             same_address(D_00257D20, D_00257C10 + 0x110, "ground enemy record"));
}
