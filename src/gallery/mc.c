#include "gallery/gallery.h"

static char g_icon_1_path[0x20] = "\\DATA\\DDON3_1.ICO;1";
static char g_icon_2_path[0x18] = "\\DATA\\DDON3_2.ICO;1";

extern u32 g_mc_state_0;
extern u32 g_mc_state_1;
extern u32 g_mc_state_2;
extern u8 g_mc_flag_0;
extern u8 g_mc_flag_1;
extern u8 g_mc_flag_2;
extern u8 g_mc_flag_3;
extern u8 g_mc_flag_4;
extern u8 g_mc_enabled;
extern u8 g_mc_flag_5;
extern u8 g_mc_flag_6;
extern u32 g_mc_param_0;
extern u32 g_mc_param_1;
extern u32 g_mc_param_2;
extern u32 g_mc_param_3;
extern u32 g_mc_param_4;
extern u32 g_mc_param_5;
extern u32 g_mc_icon_2_size;
extern u32 g_mc_icon_1_size;
extern u8 g_mc_busy;
extern u8 g_mc_icon_2_buf[0x8800];
extern u8 g_mc_icon_1_buf[0x8800];

void gallery_load_font_files(void)
{
    cd_load_file(g_mc_icon_1_buf, g_icon_1_path);
    g_mc_icon_1_size = g_cd_last_read_size;
    cd_load_file(g_mc_icon_2_buf, g_icon_2_path);

    g_mc_busy = 0;
    g_mc_enabled = 1;
    g_mc_flag_4 = 0;
    g_mc_flag_5 = 0;
    g_mc_flag_2 = 0;
    g_mc_flag_3 = 0;
    g_mc_flag_6 = 0;
    g_mc_flag_1 = 0;
    g_mc_state_2 = 0;
    g_mc_state_1 = 0;
    g_mc_state_0 = 0;
    g_mc_param_2 = 0;
    g_mc_param_5 = 0;
    g_mc_param_4 = 0;
    g_mc_param_3 = 0;
    g_mc_param_1 = 0;
    g_mc_param_0 = 0;
    g_mc_flag_0 = 0;
    g_mc_icon_2_size = g_cd_last_read_size;
}

u8 g_mc_busy __attribute__((aligned(4)));
u32 g_mc_icon_1_size;
u32 g_mc_icon_2_size;
u32 g_mc_param_5;
u32 g_mc_param_4;
u32 g_mc_param_3;
u32 g_mc_param_2;
u32 g_mc_param_1;
u32 g_mc_param_0;
u8 g_mc_flag_6 __attribute__((aligned(4)));
u8 g_mc_flag_5 __attribute__((aligned(4)));
u8 g_mc_enabled __attribute__((aligned(4)));
u8 g_mc_flag_4 __attribute__((aligned(4)));
u8 g_mc_flag_3 __attribute__((aligned(4)));
u8 g_mc_flag_2 __attribute__((aligned(4)));
u8 g_mc_flag_1 __attribute__((aligned(4)));
u8 g_mc_flag_0 __attribute__((aligned(4)));
u32 g_mc_state_2;
u32 g_mc_state_1;
u32 g_mc_state_0;

u8 g_mc_icon_1_buf[0x8800];
u8 g_mc_icon_2_buf[0x8800];
