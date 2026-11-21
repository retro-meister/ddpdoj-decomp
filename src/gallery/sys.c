#include "gallery/gallery.h"

extern unsigned short gallery_slot_0_state;
extern unsigned short gallery_slot_1_state;
extern unsigned short gallery_slot_2_state;
extern unsigned short gallery_slot_3_state;
extern unsigned short gallery_state_0;
extern unsigned short gallery_state_1;

extern const char D_00128C40[];
extern const char D_00128C80[];
extern const char D_00128CC0[];

void gallery_reset_slot_states(void)
{
    gallery_state_1 = 0;
    gallery_state_0 = 0;
    gallery_slot_3_state = 0;
    gallery_slot_2_state = 0;
    gallery_slot_1_state = 0;
    gallery_slot_0_state = 0;
}

void gallery_exit_to_elf(s32 destination)
{
    sceSifInitRpc(0);
    sceCdInit(0);
    sceSifExitCmd();

    if (destination == 0) {
        LoadExecPS2(D_00128C40, 0, 0);
    } else if (destination == 1) {
        LoadExecPS2(D_00128C80, 0, 0);
    } else {
        LoadExecPS2(D_00128CC0, 0, 0);
    }
}
