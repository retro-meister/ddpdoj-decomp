#include "gallery/gallery.h"

extern u16 gallery_slot_0_state;
extern u16 gallery_slot_1_state;
extern u16 gallery_slot_2_state;
extern u16 gallery_slot_3_state;
extern u16 gallery_state_0;
extern u16 gallery_state_1;

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

u32 g_pad_port_bits;
u8 *g_pad_port_dst;
u16 g_system_mute __attribute__((aligned(4)));
u8 g_pad_vib_state_p1 __attribute__((aligned(4)));
u8 g_pad_vib_state_p2 __attribute__((aligned(4)));
u16 g_pad_vib_timer_p1 __attribute__((aligned(4)));
u16 g_pad_vib_timer_p2 __attribute__((aligned(4)));
u16 g_pad_vib_power_p1 __attribute__((aligned(4)));
u16 g_pad_vib_power_p2 __attribute__((aligned(4)));
u8 g_pad_tate_rotate __attribute__((aligned(4)));
u8 g_pad_input_locked __attribute__((aligned(4)));
u8 g_p2_btn_map_c;
u8 g_p2_btn_map_b;
u8 g_p2_btn_map_a __attribute__((aligned(4)));
u8 g_p1_btn_map_c;
u8 g_p1_btn_map_b;
u8 g_p1_btn_map_a;
s8 g_arcade_input_port[8] __attribute__((aligned(8)));
u16 g_arcade_coin_port __attribute__((aligned(4)));
u16 gallery_state_1 __attribute__((aligned(4)));
u16 gallery_state_0 __attribute__((aligned(4)));
u16 gallery_slot_3_state __attribute__((aligned(4)));
u16 gallery_slot_2_state __attribute__((aligned(4)));
u16 gallery_slot_1_state __attribute__((aligned(4)));
u16 gallery_slot_0_state __attribute__((aligned(4)));
