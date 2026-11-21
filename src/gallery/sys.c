#include "gallery/gallery.h"

extern u16 gallery_slot_0_state;
extern u16 gallery_slot_1_state;
extern u16 gallery_slot_2_state;
extern u16 gallery_slot_3_state;
extern u16 gallery_state_0;
extern u16 gallery_state_1;

/* Printable ASCII (' '..0x7F) 8x16 glyph top-tile lookup table (bottom tile is +16) */
u16 g_ascii_glyph_table[96] = {
    0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
    0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
    0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7,
    0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
    0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7,
    0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
    0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7,
    0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
    0x0100, 0x0101, 0x0102, 0x0103, 0x0104, 0x0105, 0x0106, 0x0107,
    0x0108, 0x0109, 0x010A, 0x010B, 0x010C, 0x010D, 0x010E, 0x010F,
    0x0120, 0x0121, 0x0122, 0x0123, 0x0124, 0x0125, 0x0126, 0x0127,
    0x0128, 0x0129, 0x012A, 0x012B, 0x012C, 0x012D, 0x012E, 0x012F,
};

/* 32-color all-white RGB555 CLUT (padded to 48 entries in .data) */
s16 g_tex_clut_palette_32[48] = {
    RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31),
    RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31),
    RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31),
    RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31),
    RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31),
    RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31),
    RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31),
    RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31), RGB555(31, 31, 31),
};

static const char g_elf_path_main[0x40] __attribute__((section(".data"))) = "cdrom0:\\SLPS_252.33";
static const char g_elf_path_don2[0x40] __attribute__((section(".data"))) = "cdrom0:\\DON2.ELF";
static const char g_elf_path_gallery[0x20] __attribute__((section(".data"))) = "cdrom0:\\GALLERY.ELF";

/* 16-color orange-to-gold gradient RGB555 CLUT */
s16 g_tex_clut_palette_16[16] = {
    RGB555(10,  6,  5), RGB555(13,  8,  5), RGB555(16,  8,  4), RGB555(19,  8,  2),
    RGB555(22,  8,  1), RGB555(25,  8,  0), RGB555(28,  9,  0), RGB555(31, 10,  0),
    RGB555(31, 14,  2), RGB555(31, 18,  3), RGB555(31, 22,  4), RGB555(31, 25,  5),
    RGB555(31, 26, 11), RGB555(31, 27, 17), RGB555(31, 28, 22), RGB555( 0,  0,  0),
};

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
