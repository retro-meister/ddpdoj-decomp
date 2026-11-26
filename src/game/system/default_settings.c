/* The default values of the game settings. */
#include "common.h"

u16 D_0028C0F8[2] = {
    0x0100, 0x0201,
};

u16 g_default_setting_difficulty[2] = {
    0x0001, 0x0100,
};

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(g_default_setting_continue, D_0028C0F8, 0x1);
PC_DATA_ALIAS(g_default_setting_demo_sound, D_0028C0F8, 0x2);
PC_DATA_ALIAS(g_default_setting_chute_type, D_0028C0F8, 0x3);

PC_DATA_ALIAS(g_default_setting_extend, g_default_setting_difficulty, 0x1);
PC_DATA_ALIAS(g_default_setting_ship_stock, g_default_setting_difficulty, 0x2);
PC_DATA_ALIAS(g_default_setting_rapid_fire, g_default_setting_difficulty, 0x3);
#endif
