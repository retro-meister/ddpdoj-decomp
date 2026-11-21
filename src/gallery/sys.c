#include "gallery/gallery.h"

extern unsigned short gallery_slot_0_state;
extern unsigned short gallery_slot_1_state;
extern unsigned short gallery_slot_2_state;
extern unsigned short gallery_slot_3_state;
extern unsigned short gallery_state_0;
extern unsigned short gallery_state_1;

static const char g_elf_path_main[0x40] __attribute__((section(".data"))) = "cdrom0:\\SLPS_252.33";
static const char g_elf_path_don2[0x40] __attribute__((section(".data"))) = "cdrom0:\\DON2.ELF";
static const char g_elf_path_gallery[0x20] __attribute__((section(".data"))) = "cdrom0:\\GALLERY.ELF";

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
        LoadExecPS2(g_elf_path_main, 0, 0);
    } else if (destination == 1) {
        LoadExecPS2(g_elf_path_don2, 0, 0);
    } else {
        LoadExecPS2(g_elf_path_gallery, 0, 0);
    }
}
