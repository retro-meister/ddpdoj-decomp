#include "common.h"
#include "task.h"
#include "sdk/ps2sdk.h"

extern u16 D_00241C30[];
extern u16 D_002420A8[];
extern u16 D_00255580[];
extern u16 D_002555A0[];
extern u16 player_weapon_tables[];
extern u16 ship0_shot_lists_1[];
extern u16 ship0_shot_lists_2[];
extern u16 ship0_shot_lists_3[];
extern u16 D_00255EE0[];
extern u16 D_0025B100[];
extern u16 D_0025ECF0[];
extern u16 D_0025ED80[];
extern u16 D_0025EE10[];
extern u16 D_0025EEA0[];
extern u16 D_0025F3B0[];
extern u16 D_0025F400[];
extern u16 D_0025F430[];
extern u16 player_ship_sprite_tables[];
extern u16 D_0028C9D8[];

extern u16 D_00263390[];
extern u16 D_00263590[];
extern u16 D_002635E0[];

extern u16 ship0_shot_list_1_00_00[];
extern u16 ship0_shot_list_2_00_00[];
extern u16 ship0_shot_list_1_00_01[];
extern u16 ship0_shot_list_2_00_01[];
extern u16 ship0_shot_list_1_00_02[];
extern u16 ship0_shot_list_2_00_02[];
extern u16 ship0_shot_list_1_00_03[];
extern u16 ship0_shot_list_2_00_03[];
extern u16 ship0_shot_list_1_00_04[];
extern u16 ship0_shot_list_2_00_04[];
extern u16 ship0_shot_list_1_02_00[];
extern u16 ship0_shot_list_1_02_01[];
extern u16 ship0_shot_list_1_02_02[];
extern u16 ship0_shot_list_1_02_03[];
extern u16 ship0_shot_list_1_02_04[];
extern u16 ship0_shot_list_1_04_00[];
extern u16 ship0_shot_list_2_04_00[];
extern u16 ship0_shot_list_1_04_01[];
extern u16 ship0_shot_list_2_04_01[];
extern u16 ship0_shot_list_1_04_02[];
extern u16 ship0_shot_list_2_04_02[];
extern u16 ship0_shot_list_1_04_03[];
extern u16 ship0_shot_list_2_04_03[];
extern u16 ship0_shot_list_1_04_04[];
extern u16 ship0_shot_list_2_04_04[];
extern u16 ship0_shot_list_3_00_00[];
extern u16 ship0_shot_list_3_00_01[];
extern u16 ship0_shot_list_3_00_02[];
extern u16 ship0_shot_list_3_00_03[];
extern u16 ship0_shot_list_3_00_04[];
extern u16 ship0_shot_list_3_02_00[];
extern u16 ship0_shot_list_3_02_01[];
extern u16 ship0_shot_list_3_02_02[];
extern u16 ship0_shot_list_3_02_03[];
extern u16 ship0_shot_list_3_02_04[];
extern u16 ship0_shot_list_3_04_00[];
extern u16 ship0_shot_list_3_04_01[];
extern u16 ship0_shot_list_3_04_02[];
extern u16 ship0_shot_list_3_04_03[];
extern u16 ship0_shot_list_3_04_04[];
extern u16 ship0_shot_list_1_01_00[];
extern u16 ship0_shot_list_2_01_00[];
extern u16 ship0_shot_list_1_01_01[];
extern u16 ship0_shot_list_2_01_01[];
extern u16 ship0_shot_list_1_01_02[];
extern u16 ship0_shot_list_2_01_02[];
extern u16 ship0_shot_list_1_01_03[];
extern u16 ship0_shot_list_2_01_03[];
extern u16 ship0_shot_list_1_01_04[];
extern u16 ship0_shot_list_2_01_04[];
extern u16 ship0_shot_list_1_03_00[];
extern u16 ship0_shot_list_1_03_01[];
extern u16 ship0_shot_list_1_03_02[];
extern u16 ship0_shot_list_1_03_03[];
extern u16 ship0_shot_list_1_03_04[];
extern u16 ship0_shot_list_1_05_00[];
extern u16 ship0_shot_list_2_05_00[];
extern u16 ship0_shot_list_1_05_01[];
extern u16 ship0_shot_list_2_05_01[];
extern u16 ship0_shot_list_1_05_02[];
extern u16 ship0_shot_list_2_05_02[];
extern u16 ship0_shot_list_1_05_03[];
extern u16 ship0_shot_list_2_05_03[];
extern u16 ship0_shot_list_1_05_04[];
extern u16 ship0_shot_list_2_05_04[];
extern u16 ship0_shot_list_3_01_00[];
extern u16 ship0_shot_list_3_01_01[];
extern u16 ship0_shot_list_3_01_02[];
extern u16 ship0_shot_list_3_01_03[];
extern u16 ship0_shot_list_3_01_04[];
extern u16 ship0_shot_list_3_03_00[];
extern u16 ship0_shot_list_3_03_01[];
extern u16 ship0_shot_list_3_03_02[];
extern u16 ship0_shot_list_3_03_03[];
extern u16 ship0_shot_list_3_03_04[];
extern u16 ship0_shot_list_3_05_00[];
extern u16 ship0_shot_list_3_05_01[];
extern u16 ship0_shot_list_3_05_02[];
extern u16 ship0_shot_list_3_05_03[];
extern u16 ship0_shot_list_3_05_04[];
extern u16 D_00256280[];
extern u16 D_002562B0[];
extern u16 D_002562E0[];
extern u16 D_00256310[];
extern u16 D_00256340[];
extern u16 D_00256370[];
extern u16 D_002563A0[];
extern u16 D_002563D0[];
extern u16 D_00256400[];
extern u16 D_00256430[];
extern u16 D_00256460[];
extern u16 D_00256490[];
extern u16 D_002564C0[];
extern u16 D_002564F0[];
extern u16 D_00256520[];
extern u16 D_00256550[];
extern u16 D_00256580[];
extern u16 D_002565B0[];
extern u16 D_002565E0[];
extern u16 D_00256610[];
extern u16 D_00256640[];
extern u16 D_00256670[];
extern u16 D_002566A0[];
extern u16 D_002566D0[];
extern u16 D_00256700[];
extern u16 D_00256A28[];
extern u16 D_00256A38[];
extern u16 D_00256A48[];
extern u16 D_00256A58[];
extern u16 D_00256A68[];
extern u16 D_00256A78[];
extern u16 D_00256A88[];
extern u16 D_00256A98[];
extern u16 D_00256AA8[];
extern u16 D_00256AB8[];
extern u16 D_00256AC8[];
extern u16 D_00256AD8[];
extern u16 D_00256AE8[];
extern u16 D_00256AF8[];
extern u16 D_00256B08[];
extern u16 D_00256B18[];
extern u16 D_00256B30[];
extern u16 D_00256B50[];
extern u16 D_00256B70[];
extern u16 D_00256B90[];
extern u16 D_00256BB0[];
extern u16 D_00256BD0[];
extern u16 D_00256BF0[];
extern u16 D_00256C10[];
extern u16 D_00256C30[];
extern u16 D_00256C50[];
extern u16 D_00256C70[];
extern u16 D_00256C90[];
extern u16 D_00256CB0[];
extern u16 D_00256CD0[];
extern u16 D_00256CF0[];
extern u16 D_00256D10[];
extern u16 D_00256D30[];
extern u16 D_00256D50[];
extern u16 D_00256D70[];
extern u16 D_00256D90[];
extern u16 D_00256DB0[];
extern u16 D_00256DD0[];
extern u16 D_00256DF0[];
extern u16 D_00256E10[];
extern u16 D_00256E30[];
extern u16 D_0025C680[];
extern u16 D_0025C6B0[];
extern u16 D_0025C6E0[];
extern u16 D_0025C710[];
extern u16 D_0025C740[];
extern u16 D_0025C770[];
extern u16 D_0025C7A0[];
extern u16 D_0025C7D0[];
extern u16 D_0025C800[];
extern u16 D_0025C830[];
extern u16 D_0025C860[];
extern u16 D_0025C890[];
extern u16 D_0025C8C0[];
extern u16 D_0025C8F0[];
extern u16 D_0025C920[];
extern u16 D_0025C950[];
extern u16 D_0025C9A0[];
extern u16 D_0025C9F0[];
extern u16 D_0025CA40[];
extern u16 D_0025CA90[];
extern u16 D_0025D010[];
extern u16 D_0025D040[];
extern u16 D_0025D070[];
extern u16 D_0025D0A0[];
extern u16 D_0025D0D0[];
extern u16 D_0025D100[];
extern u16 D_0025D130[];
extern u16 D_0025D160[];
extern u16 D_0025D190[];
extern u16 D_0025D1C0[];
extern u16 D_0025D1F0[];
extern u16 D_0025D220[];
extern u16 D_0025D250[];
extern u16 D_0025D280[];
extern u16 D_0025D2B0[];
extern u16 D_0025D2E0[];
extern u16 D_0025D330[];
extern u16 D_0025D380[];
extern u16 D_0025D3D0[];
extern u16 D_0025D420[];
extern u16 D_0025E330[];
extern u16 D_0025E360[];
extern u16 D_0025E390[];
extern u16 D_0025E3C0[];
extern u16 D_0025E3F0[];
extern u16 D_0025E420[];
extern u16 D_0025E450[];
extern u16 D_0025E480[];
extern u16 D_0025E4B0[];
extern u16 D_0025E4E0[];
extern u16 D_0025E510[];
extern u16 D_0025E540[];
extern u16 D_0025E570[];
extern u16 D_0025E5A0[];
extern u16 D_0025E5D0[];
extern u16 D_0025E600[];
extern u16 D_0025E650[];
extern u16 D_0025E6A0[];
extern u16 D_0025E6F0[];
extern u16 D_0025E740[];

extern u16 D_00241720[];
extern u16 D_002417C0[];
extern u16 D_00241830[];
extern u16 D_00241CD0[];
extern u16 D_00241F50[];
extern u16 D_00242020[];
extern u16 D_00242070[];
extern u16 D_002576C0[];
extern u16 D_00257C10[];
extern u16 D_002589B0[];
extern u16 D_0025A0B0[];
extern u16 D_0025A160[];
extern u16 D_0025A230[];
extern u16 D_0025A2C0[];
extern u16 D_0025A3B0[];
extern u16 D_0025A4B0[];
extern u16 D_0025A5A0[];
extern u16 D_0025AD90[];
extern u16 D_0025B180[];
extern u16 D_0025B450[];
extern u16 D_0025B6C0[];
extern u16 D_0025B780[];
extern u16 D_0025F5C0[];
extern u16 D_00262720[];
extern u16 D_00262B50[];
extern u16 D_00263030[];
extern u16 D_002630D0[];
extern u16 D_00263290[];
extern u16 D_002638B0[];
extern u16 D_002639B0[];
extern u16 D_00263A50[];
extern u16 D_00263B80[];
extern u16 D_00263C70[];
extern u16 D_00263C80[];
extern u16 D_00263C90[];
extern u16 D_00263CF0[];
extern u16 D_00265B60[];
extern u16 D_00265F60[];
extern u16 D_00266330[];
extern u16 D_0028C5E0[];
extern u16 D_0028C9B0[];

void task_table_init(void);
void func_00172760(void);
void func_001727F0(void);
void player_shot_1_tables_init(void);
void player_shot_2_tables_init(void);
void player_shot_5_tables_init(void);
void player_shot_6_tables_init(void);
void player_shot_3_tables_init(void);
void player_shot_4_tables_init(void);
void player_shot_8_tables_init(void);
void func_0017FCB0(void);
void func_001828A0(void);
void func_001829B0(void);
void func_00184410(void);
void func_00185320(void);
void func_00186310(void);
void func_00186760(void);
void func_001867B0(void);
void func_00186A80(void);
void func_00186CA0(void);
void func_00187300(void);
void func_00187360(void);
void func_00187AE0(void);
void func_00187E00(void);
void func_001881E0(void);
void func_001882D0(void);
void player_shot_7_tables_init(void);


void pointer_tables_init(void) {
    task_table_init();
    func_00172760();
    func_001727F0();
    player_shot_1_tables_init();
    player_shot_2_tables_init();
    player_shot_5_tables_init();
    player_shot_6_tables_init();
    player_shot_3_tables_init();
    player_shot_4_tables_init();
    player_shot_8_tables_init();
    func_0017FCB0();
    func_001828A0();
    func_001829B0();
    func_00184410();
    func_00185320();
    func_00186310();
    func_00186760();
    func_001867B0();
    func_00186A80();
    func_00186CA0();
    func_00187300();
    func_00187360();
    func_00187AE0();
    func_00187E00();
    func_001881E0();
    func_001882D0();
    player_shot_7_tables_init();
}

extern u16 g_task_table[];
void ending_task();
void func_00131880();
void func_00134C40();
void game_task();
void func_00138DA0();
void func_00139B80();
void player1_task();
void player2_task();
void score_task();
void game_over_task();
void attract_task();
void func_00198B70();
void func_001A3730();
void func_001AF560();
void ship_select_task();
void func_001B2200();
void credits_task();
void test_mode_task();
void func_00210D00();
void func_0022BF60();
void replay_task();

void task_table_init(void) {
    STORE_POINTER(g_task_table + 4 * TASK_SCORE, score_task);
    STORE_POINTER(g_task_table + 4 * 1, func_00138DA0);
    STORE_POINTER(g_task_table + 4 * TASK_PLAYER1, player1_task);
    STORE_POINTER(g_task_table + 4 * TASK_PLAYER2, player2_task);
    STORE_POINTER(g_task_table + 4 * 4, func_001A3730);
    STORE_POINTER(g_task_table + 4 * 5, func_00139B80);
    STORE_POINTER(g_task_table + 4 * 6, func_00131880);
    STORE_POINTER(g_task_table + 4 * TASK_ENDING, ending_task);
    STORE_POINTER(g_task_table + 4 * TASK_ATTRACT, attract_task);
    STORE_POINTER(g_task_table + 4 * TASK_SHIP_SELECT, ship_select_task);
    STORE_POINTER(g_task_table + 4 * TASK_GAME, game_task);
    STORE_POINTER(g_task_table + 4 * 11, func_001AF560);
    STORE_POINTER(g_task_table + 4 * 12, func_00198B70);
    STORE_POINTER(g_task_table + 4 * 13, func_00134C40);
    STORE_POINTER(g_task_table + 4 * TASK_GAME_OVER, game_over_task);
    STORE_POINTER(g_task_table + 4 * TASK_CREDITS, credits_task);
    STORE_POINTER(g_task_table + 4 * TASK_TEST_MODE, test_mode_task);
    STORE_POINTER(g_task_table + 4 * 17, func_001B2200);
    STORE_POINTER(g_task_table + 4 * 18, 0);
    STORE_POINTER(g_task_table + 4 * 19, func_00210D00);
    STORE_POINTER(g_task_table + 4 * TASK_REPLAY, replay_task);
    STORE_POINTER(g_task_table + 4 * 21, func_0022BF60);
}

extern u16 D_00261070[];
extern u16 D_00261BF0[];
extern u16 D_00261CB0[];


void func_00172760(void) {
    STORE_POINTER(D_0025F5C0 + 26, D_00261070);
    STORE_POINTER(D_0025F5C0 + 30, D_00261CB0);
    STORE_POINTER(D_0025F5C0 + 34, D_00261CB0);
    STORE_POINTER(D_0025F5C0 + 38, D_00261BF0);
}

extern u16 D_00241740[];
extern u16 D_002417F0[];
extern u16 D_00241850[];
extern u16 D_00241888[];
extern u16 D_00241898[];
extern u16 D_002418A8[];
extern u16 D_002418B8[];
extern u16 D_002418D0[];
extern u16 D_002418F0[];
extern u16 D_00241900[];
extern u16 D_00241910[];
extern u16 D_00241920[];
extern u16 D_00241930[];
extern u16 D_00241940[];
extern u16 D_00241950[];
extern u16 D_00241960[];
extern u16 D_00241970[];
extern u16 D_00241A70[];
extern u16 D_00241A90[];
extern u16 D_00241AB0[];
extern u16 D_00241AD0[];
extern u16 D_00241AF0[];
extern u16 D_00241B10[];
extern u16 D_00241B30[];
extern u16 D_00241B50[];
extern u16 D_00241B70[];
extern u16 D_00241B90[];
extern u16 D_00241BB0[];
extern u16 D_00241BD0[];
extern u16 D_00241C50[];
extern u16 D_00241C60[];
extern u16 D_00241C70[];
extern u16 D_00241C80[];
extern u16 D_00241C90[];
extern u16 D_00241CA0[];
extern u16 D_00241CB0[];
extern u16 D_00241CC0[];
extern u16 D_00241DD0[];
extern u16 D_00241DF0[];
extern u16 D_00241E10[];
extern u16 D_00241E30[];
extern u16 D_00241E50[];
extern u16 D_00241E70[];
extern u16 D_00241E90[];
extern u16 D_00241EB0[];
extern u16 D_00241ED0[];
extern u16 D_00241EF0[];
extern u16 D_00241F10[];
extern u16 D_00241F30[];

extern u16 D_00241C30_as_u16_a[];

void func_001727F0(void) {
    STORE_POINTER(D_00241720 + 8, D_00241740);
    STORE_POINTER(D_002417C0 + 10, D_002417F0);
    STORE_POINTER(D_00241830 + 10, D_00241850);
    STORE_POINTER(D_002418D0, D_00241960);
    STORE_POINTER(D_002418D0 + 2, D_00241950);
    STORE_POINTER(D_002418D0 + 4, D_00241940);
    STORE_POINTER(D_002418D0 + 6, D_00241930);
    STORE_POINTER(D_002418D0 + 8, D_00241920);
    STORE_POINTER(D_002418D0 + 10, D_00241910);
    STORE_POINTER(D_002418D0 + 12, D_00241900);
    STORE_POINTER(D_002418D0 + 14, D_002418F0);
    STORE_POINTER(D_00241970 + 8, D_00241A70);
    STORE_POINTER(D_00241970 + 18, D_00241A90);
    STORE_POINTER(D_00241970 + 28, D_00241AB0);
    STORE_POINTER(D_00241970 + 38, D_00241AD0);
    STORE_POINTER(D_00241970 + 48, D_00241AF0);
    STORE_POINTER(D_00241970 + 58, D_00241B10);
    STORE_POINTER(D_00241970 + 68, D_00241B30);
    STORE_POINTER(D_00241970 + 78, D_00241B50);
    STORE_POINTER(D_00241970 + 88, D_00241B70);
    STORE_POINTER(D_00241970 + 98, D_00241B90);
    STORE_POINTER(D_00241970 + 108, D_00241BB0);
    STORE_POINTER(D_00241970 + 118, D_00241BD0);
    STORE_POINTER(D_00241C30_as_u16_a, D_00241CC0);
    STORE_POINTER(D_00241C30 + 2, D_00241CB0);
    STORE_POINTER(D_00241C30 + 4, D_00241CA0);
    STORE_POINTER(D_00241C30 + 6, D_00241C90);
    STORE_POINTER(D_00241C30 + 8, D_00241C80);
    STORE_POINTER(D_00241C30 + 10, D_00241C70);
    STORE_POINTER(D_00241C30 + 12, D_00241C60);
    STORE_POINTER(D_00241C30 + 14, D_00241C50);
    STORE_POINTER(D_00241CD0 + 8, D_00241DD0);
    STORE_POINTER(D_00241CD0 + 18, D_00241DF0);
    STORE_POINTER(D_00241CD0 + 28, D_00241E10);
    STORE_POINTER(D_00241CD0 + 38, D_00241E30);
    STORE_POINTER(D_00241CD0 + 48, D_00241E50);
    STORE_POINTER(D_00241CD0 + 58, D_00241E70);
    STORE_POINTER(D_00241CD0 + 68, D_00241E90);
    STORE_POINTER(D_00241CD0 + 78, D_00241EB0);
    STORE_POINTER(D_00241CD0 + 88, D_00241ED0);
    STORE_POINTER(D_00241CD0 + 98, D_00241EF0);
    STORE_POINTER(D_00241CD0 + 108, D_00241F10);
    STORE_POINTER(D_00241CD0 + 118, D_00241F30);
    STORE_POINTER(D_00241F50 + 10, D_00241888);
    STORE_POINTER(D_00241F50 + 15, D_00241970);
    STORE_POINTER(D_00241F50 + 17, D_002418D0);
    STORE_POINTER(D_00241F50 + 30, D_002418A8);
    STORE_POINTER(D_00241F50 + 50, D_00241898);
    STORE_POINTER(D_00241F50 + 70, D_002418B8);
}

extern u16 D_002532A8[];
extern u16 D_002532B8[];
extern u16 D_002532C8[];
extern u16 D_002532D8[];
extern u16 D_002532E8[];
extern u16 ship0_shot_list_1_02_00_02[];
extern u16 ship0_shot_list_1_02_01_02[];
extern u16 ship0_shot_list_1_02_02_02[];
extern u16 ship0_shot_list_1_02_03_02[];
extern u16 ship0_shot_list_1_02_04_02[];
extern u16 D_00253348[];
extern u16 D_00253358[];
extern u16 D_00253368[];
extern u16 D_00253378[];
extern u16 D_00253388[];
extern u16 player_shot_1_impact_frames_00[];
extern u16 player_shot_1_impact_frames_02[];
extern u16 player_shot_1_impact_frames_04[];
extern u16 player_shot_1_impact_frames_06[];
extern u16 player_shot_1_impact_frames_08[];
extern u16 player_shot_1_impact_frames_10[];
extern u16 player_shot_1_impact_frames_11[];
extern u16 player_shot_1_impact_frames_12[];
extern u16 player_shot_1_impact_frames_13[];
extern u16 player_shot_1_impact_frames_14[];
extern u16 player_shot_1_impact_frames_15[];
extern u16 player_shot_1_impact_frames_17[];
extern u16 player_shot_1_impact_frames_19[];
extern u16 player_shot_1_impact_frames_21[];
extern u16 player_shot_1_impact_frames_23[];
extern u16 player_shot_1_impact_00[];
extern u16 player_shot_1_impact_01[];
extern u16 player_shot_1_impact_02[];
extern u16 player_shot_1_impact_03[];
extern u16 player_shot_1_impact_04[];
extern u16 player_shot_1_impact_05[];
extern u16 player_shot_1_impact_06[];
extern u16 player_shot_1_impact_07[];
extern u16 player_shot_1_impact_08[];
extern u16 player_shot_1_impact_09[];
extern u16 player_shot_1_impact_10[];
extern u16 player_shot_1_impact_11[];
extern u16 player_shot_1_impact_12[];
extern u16 player_shot_1_impact_13[];
extern u16 player_shot_1_impact_14[];
extern u16 player_shot_1_impact_15[];
extern u16 player_shot_1_impact_16[];
extern u16 player_shot_1_impact_17[];
extern u16 player_shot_1_impact_18[];
extern u16 player_shot_1_impact_19[];
extern u16 player_shot_1_impact_20[];
extern u16 player_shot_1_impact_21[];
extern u16 player_shot_1_impact_22[];
extern u16 player_shot_1_impact_23[];
extern u16 player_shot_1_impact_24[];
extern u16 D_0028C198[];
extern u16 D_0028C1A0[];
extern u16 D_0028C1A8[];
extern u16 D_0028C1B0[];
extern u16 D_0028C1B8[];
extern u16 ship0_shot_list_1_02_00_07[];
extern u16 ship0_shot_list_1_02_01_07[];
extern u16 ship0_shot_list_1_02_02_07[];
extern u16 ship0_shot_list_1_02_03_07[];
extern u16 ship0_shot_list_1_02_04_07[];
extern u16 D_0028C1E8[];
extern u16 D_0028C1F0[];
extern u16 D_0028C1F8[];
extern u16 D_0028C200[];
extern u16 D_0028C208[];
extern u16 player_shot_1_flight_00[];
extern u16 player_shot_1_flight_01[];
extern u16 player_shot_1_flight_02[];
extern u16 player_shot_1_flight_03[];
extern u16 player_shot_1_flight_04[];
extern u16 player_shot_1_flight_05[];
extern u16 player_shot_1_flight_06[];
extern u16 player_shot_1_flight_07[];
extern u16 player_shot_1_flight_08[];
extern u16 player_shot_1_flight_09[];
extern u16 player_shot_1_flight_10[];
extern u16 player_shot_1_flight_11[];
extern u16 player_shot_1_flight_12[];
extern u16 player_shot_1_flight_13[];
extern u16 player_shot_1_flight_14[];
extern u16 player_shot_1_flight_15[];
extern u16 player_shot_1_flight_16[];
extern u16 player_shot_1_flight_17[];
extern u16 player_shot_1_flight_18[];
extern u16 player_shot_1_flight_19[];
extern u16 player_shot_1_flight_20[];
extern u16 player_shot_1_flight_21[];
extern u16 player_shot_1_flight_22[];
extern u16 player_shot_1_flight_23[];
extern u16 player_shot_1_flight_24[];

extern u16 player_shot_1_flight_table[];
extern u16 player_shot_1_impact_table[];

void player_shot_1_tables_init(void) {
    STORE_POINTER(ship0_shot_list_1_00_00 + 5, D_002532A8);
    STORE_POINTER(ship0_shot_list_1_00_00 + 15, D_0028C198);
    STORE_POINTER(ship0_shot_list_2_00_00 + 5, D_002532A8);
    STORE_POINTER(ship0_shot_list_2_00_00 + 15, D_0028C198);
    STORE_POINTER(ship0_shot_list_1_00_01 + 5, D_002532B8);
    STORE_POINTER(ship0_shot_list_1_00_01 + 15, D_0028C1A0);
    STORE_POINTER(ship0_shot_list_2_00_01 + 5, D_002532B8);
    STORE_POINTER(ship0_shot_list_2_00_01 + 15, D_0028C1A0);
    STORE_POINTER(ship0_shot_list_1_00_02 + 5, D_002532C8);
    STORE_POINTER(ship0_shot_list_1_00_02 + 15, D_0028C1A8);
    STORE_POINTER(ship0_shot_list_2_00_02 + 5, D_002532C8);
    STORE_POINTER(ship0_shot_list_2_00_02 + 15, D_0028C1A8);
    STORE_POINTER(ship0_shot_list_1_00_03 + 5, D_002532D8);
    STORE_POINTER(ship0_shot_list_1_00_03 + 15, D_0028C1B0);
    STORE_POINTER(ship0_shot_list_2_00_03 + 5, D_002532D8);
    STORE_POINTER(ship0_shot_list_2_00_03 + 15, D_0028C1B0);
    STORE_POINTER(ship0_shot_list_1_00_04 + 5, D_002532E8);
    STORE_POINTER(ship0_shot_list_1_00_04 + 15, D_0028C1B8);
    STORE_POINTER(ship0_shot_list_2_00_04 + 5, D_002532E8);
    STORE_POINTER(ship0_shot_list_2_00_04 + 15, D_0028C1B8);
    STORE_POINTER(ship0_shot_list_1_02_00 + 5, ship0_shot_list_1_02_00_02);
    STORE_POINTER(ship0_shot_list_1_02_00 + 15, ship0_shot_list_1_02_00_07);
    STORE_POINTER(ship0_shot_list_1_02_01 + 5, ship0_shot_list_1_02_01_02);
    STORE_POINTER(ship0_shot_list_1_02_01 + 15, ship0_shot_list_1_02_01_07);
    STORE_POINTER(ship0_shot_list_1_02_02 + 5, ship0_shot_list_1_02_02_02);
    STORE_POINTER(ship0_shot_list_1_02_02 + 15, ship0_shot_list_1_02_02_07);
    STORE_POINTER(ship0_shot_list_1_02_03 + 5, ship0_shot_list_1_02_03_02);
    STORE_POINTER(ship0_shot_list_1_02_03 + 15, ship0_shot_list_1_02_03_07);
    STORE_POINTER(ship0_shot_list_1_02_04 + 5, ship0_shot_list_1_02_04_02);
    STORE_POINTER(ship0_shot_list_1_02_04 + 15, ship0_shot_list_1_02_04_07);
    STORE_POINTER(ship0_shot_list_1_04_00 + 5, D_00253348);
    STORE_POINTER(ship0_shot_list_1_04_00 + 15, D_0028C1E8);
    STORE_POINTER(ship0_shot_list_2_04_00 + 5, D_00253348);
    STORE_POINTER(ship0_shot_list_2_04_00 + 15, D_0028C1E8);
    STORE_POINTER(ship0_shot_list_1_04_01 + 5, D_00253358);
    STORE_POINTER(ship0_shot_list_1_04_01 + 15, D_0028C1F0);
    STORE_POINTER(ship0_shot_list_2_04_01 + 5, D_00253358);
    STORE_POINTER(ship0_shot_list_2_04_01 + 15, D_0028C1F0);
    STORE_POINTER(ship0_shot_list_1_04_02 + 5, D_00253368);
    STORE_POINTER(ship0_shot_list_1_04_02 + 15, D_0028C1F8);
    STORE_POINTER(ship0_shot_list_2_04_02 + 5, D_00253368);
    STORE_POINTER(ship0_shot_list_2_04_02 + 15, D_0028C1F8);
    STORE_POINTER(ship0_shot_list_1_04_03 + 5, D_00253378);
    STORE_POINTER(ship0_shot_list_1_04_03 + 15, D_0028C200);
    STORE_POINTER(ship0_shot_list_2_04_03 + 5, D_00253378);
    STORE_POINTER(ship0_shot_list_2_04_03 + 15, D_0028C200);
    STORE_POINTER(ship0_shot_list_1_04_04 + 5, D_00253388);
    STORE_POINTER(ship0_shot_list_1_04_04 + 15, D_0028C208);
    STORE_POINTER(ship0_shot_list_2_04_04 + 5, D_00253388);
    STORE_POINTER(ship0_shot_list_2_04_04 + 15, D_0028C208);
    STORE_POINTER(player_shot_1_flight_table, player_shot_1_flight_00);
    STORE_POINTER(player_shot_1_flight_table + 2, player_shot_1_flight_01);
    STORE_POINTER(player_shot_1_flight_table + 4, player_shot_1_flight_02);
    STORE_POINTER(player_shot_1_flight_table + 6, player_shot_1_flight_03);
    STORE_POINTER(player_shot_1_flight_table + 8, player_shot_1_flight_04);
    STORE_POINTER(player_shot_1_flight_table + 10, player_shot_1_flight_05);
    STORE_POINTER(player_shot_1_flight_table + 12, player_shot_1_flight_06);
    STORE_POINTER(player_shot_1_flight_table + 14, player_shot_1_flight_07);
    STORE_POINTER(player_shot_1_flight_table + 16, player_shot_1_flight_08);
    STORE_POINTER(player_shot_1_flight_table + 18, player_shot_1_flight_09);
    STORE_POINTER(player_shot_1_flight_table + 20, player_shot_1_flight_10);
    STORE_POINTER(player_shot_1_flight_table + 22, player_shot_1_flight_11);
    STORE_POINTER(player_shot_1_flight_table + 24, player_shot_1_flight_12);
    STORE_POINTER(player_shot_1_flight_table + 26, player_shot_1_flight_13);
    STORE_POINTER(player_shot_1_flight_table + 28, player_shot_1_flight_14);
    STORE_POINTER(player_shot_1_flight_table + 30, player_shot_1_flight_15);
    STORE_POINTER(player_shot_1_flight_table + 32, player_shot_1_flight_16);
    STORE_POINTER(player_shot_1_flight_table + 34, player_shot_1_flight_17);
    STORE_POINTER(player_shot_1_flight_table + 36, player_shot_1_flight_18);
    STORE_POINTER(player_shot_1_flight_table + 38, player_shot_1_flight_19);
    STORE_POINTER(player_shot_1_flight_table + 40, player_shot_1_flight_20);
    STORE_POINTER(player_shot_1_flight_table + 42, player_shot_1_flight_21);
    STORE_POINTER(player_shot_1_flight_table + 44, player_shot_1_flight_22);
    STORE_POINTER(player_shot_1_flight_table + 46, player_shot_1_flight_23);
    STORE_POINTER(player_shot_1_flight_table + 48, player_shot_1_flight_24);
    STORE_POINTER(player_shot_1_impact_table, player_shot_1_impact_00);
    STORE_POINTER(player_shot_1_impact_table + 2, player_shot_1_impact_01);
    STORE_POINTER(player_shot_1_impact_table + 4, player_shot_1_impact_02);
    STORE_POINTER(player_shot_1_impact_table + 6, player_shot_1_impact_03);
    STORE_POINTER(player_shot_1_impact_table + 8, player_shot_1_impact_04);
    STORE_POINTER(player_shot_1_impact_table + 10, player_shot_1_impact_05);
    STORE_POINTER(player_shot_1_impact_table + 12, player_shot_1_impact_06);
    STORE_POINTER(player_shot_1_impact_table + 14, player_shot_1_impact_07);
    STORE_POINTER(player_shot_1_impact_table + 16, player_shot_1_impact_08);
    STORE_POINTER(player_shot_1_impact_table + 18, player_shot_1_impact_09);
    STORE_POINTER(player_shot_1_impact_table + 20, player_shot_1_impact_10);
    STORE_POINTER(player_shot_1_impact_table + 22, player_shot_1_impact_11);
    STORE_POINTER(player_shot_1_impact_table + 24, player_shot_1_impact_12);
    STORE_POINTER(player_shot_1_impact_table + 26, player_shot_1_impact_13);
    STORE_POINTER(player_shot_1_impact_table + 28, player_shot_1_impact_14);
    STORE_POINTER(player_shot_1_impact_table + 30, player_shot_1_impact_15);
    STORE_POINTER(player_shot_1_impact_table + 32, player_shot_1_impact_16);
    STORE_POINTER(player_shot_1_impact_table + 34, player_shot_1_impact_17);
    STORE_POINTER(player_shot_1_impact_table + 36, player_shot_1_impact_18);
    STORE_POINTER(player_shot_1_impact_table + 38, player_shot_1_impact_19);
    STORE_POINTER(player_shot_1_impact_table + 40, player_shot_1_impact_20);
    STORE_POINTER(player_shot_1_impact_table + 42, player_shot_1_impact_21);
    STORE_POINTER(player_shot_1_impact_table + 44, player_shot_1_impact_22);
    STORE_POINTER(player_shot_1_impact_table + 46, player_shot_1_impact_23);
    STORE_POINTER(player_shot_1_impact_table + 48, player_shot_1_impact_24);
    STORE_POINTER(player_shot_1_impact_00 + 3, player_shot_1_impact_frames_00);
    STORE_POINTER(player_shot_1_impact_01 + 3, player_shot_1_impact_frames_00);
    STORE_POINTER(player_shot_1_impact_02 + 3, player_shot_1_impact_frames_02);
    STORE_POINTER(player_shot_1_impact_03 + 3, player_shot_1_impact_frames_02);
    STORE_POINTER(player_shot_1_impact_04 + 3, player_shot_1_impact_frames_04);
    STORE_POINTER(player_shot_1_impact_05 + 3, player_shot_1_impact_frames_04);
    STORE_POINTER(player_shot_1_impact_06 + 3, player_shot_1_impact_frames_06);
    STORE_POINTER(player_shot_1_impact_07 + 3, player_shot_1_impact_frames_06);
    STORE_POINTER(player_shot_1_impact_08 + 3, player_shot_1_impact_frames_08);
    STORE_POINTER(player_shot_1_impact_09 + 3, player_shot_1_impact_frames_08);
    STORE_POINTER(player_shot_1_impact_10 + 3, player_shot_1_impact_frames_10);
    STORE_POINTER(player_shot_1_impact_11 + 3, player_shot_1_impact_frames_11);
    STORE_POINTER(player_shot_1_impact_12 + 3, player_shot_1_impact_frames_12);
    STORE_POINTER(player_shot_1_impact_13 + 3, player_shot_1_impact_frames_13);
    STORE_POINTER(player_shot_1_impact_14 + 3, player_shot_1_impact_frames_14);
    STORE_POINTER(player_shot_1_impact_15 + 3, player_shot_1_impact_frames_15);
    STORE_POINTER(player_shot_1_impact_16 + 3, player_shot_1_impact_frames_15);
    STORE_POINTER(player_shot_1_impact_17 + 3, player_shot_1_impact_frames_17);
    STORE_POINTER(player_shot_1_impact_18 + 3, player_shot_1_impact_frames_17);
    STORE_POINTER(player_shot_1_impact_19 + 3, player_shot_1_impact_frames_19);
    STORE_POINTER(player_shot_1_impact_20 + 3, player_shot_1_impact_frames_19);
    STORE_POINTER(player_shot_1_impact_21 + 3, player_shot_1_impact_frames_21);
    STORE_POINTER(player_shot_1_impact_22 + 3, player_shot_1_impact_frames_21);
    STORE_POINTER(player_shot_1_impact_23 + 3, player_shot_1_impact_frames_23);
    STORE_POINTER(player_shot_1_impact_24 + 3, player_shot_1_impact_frames_23);
}

extern u16 ship0_shot_list_3_00_00_02[];
extern u16 ship0_shot_list_3_00_01_02[];
extern u16 ship0_shot_list_3_00_02_02[];
extern u16 ship0_shot_list_3_00_03_02[];
extern u16 ship0_shot_list_3_00_04_02[];
extern u16 ship0_shot_list_3_02_00_02[];
extern u16 ship0_shot_list_3_02_01_02[];
extern u16 ship0_shot_list_3_02_02_02[];
extern u16 ship0_shot_list_3_02_03_02[];
extern u16 ship0_shot_list_3_02_04_02[];
extern u16 ship0_shot_list_3_04_00_02[];
extern u16 ship0_shot_list_3_04_01_02[];
extern u16 ship0_shot_list_3_04_02_02[];
extern u16 ship0_shot_list_3_04_03_02[];
extern u16 ship0_shot_list_3_04_04_02[];
extern u16 player_shot_2_impact_frames_00[];
extern u16 player_shot_2_impact_frames_02[];
extern u16 player_shot_2_impact_frames_04[];
extern u16 player_shot_2_impact_frames_06[];
extern u16 player_shot_2_impact_frames_08[];
extern u16 player_shot_2_impact_frames_10[];
extern u16 player_shot_2_impact_frames_11[];
extern u16 player_shot_2_impact_frames_12[];
extern u16 player_shot_2_impact_frames_13[];
extern u16 player_shot_2_impact_frames_14[];
extern u16 player_shot_2_impact_frames_15[];
extern u16 player_shot_2_impact_frames_17[];
extern u16 player_shot_2_impact_frames_19[];
extern u16 player_shot_2_impact_frames_21[];
extern u16 player_shot_2_impact_frames_23[];
extern u16 player_shot_2_impact_00[];
extern u16 player_shot_2_impact_01[];
extern u16 player_shot_2_impact_02[];
extern u16 player_shot_2_impact_03[];
extern u16 player_shot_2_impact_04[];
extern u16 player_shot_2_impact_05[];
extern u16 player_shot_2_impact_06[];
extern u16 player_shot_2_impact_07[];
extern u16 player_shot_2_impact_08[];
extern u16 player_shot_2_impact_09[];
extern u16 player_shot_2_impact_10[];
extern u16 player_shot_2_impact_11[];
extern u16 player_shot_2_impact_12[];
extern u16 player_shot_2_impact_13[];
extern u16 player_shot_2_impact_14[];
extern u16 player_shot_2_impact_15[];
extern u16 player_shot_2_impact_16[];
extern u16 player_shot_2_impact_17[];
extern u16 player_shot_2_impact_18[];
extern u16 player_shot_2_impact_19[];
extern u16 player_shot_2_impact_20[];
extern u16 player_shot_2_impact_21[];
extern u16 player_shot_2_impact_22[];
extern u16 player_shot_2_impact_23[];
extern u16 player_shot_2_impact_24[];
extern u16 ship0_shot_list_3_00_00_07[];
extern u16 ship0_shot_list_3_00_01_07[];
extern u16 ship0_shot_list_3_00_02_07[];
extern u16 ship0_shot_list_3_00_03_07[];
extern u16 ship0_shot_list_3_00_04_07[];
extern u16 ship0_shot_list_3_02_00_07[];
extern u16 ship0_shot_list_3_02_01_07[];
extern u16 ship0_shot_list_3_02_02_07[];
extern u16 ship0_shot_list_3_02_03_07[];
extern u16 ship0_shot_list_3_02_04_07[];
extern u16 ship0_shot_list_3_04_00_07[];
extern u16 ship0_shot_list_3_04_01_07[];
extern u16 ship0_shot_list_3_04_02_07[];
extern u16 ship0_shot_list_3_04_03_07[];
extern u16 ship0_shot_list_3_04_04_07[];
extern u16 player_shot_2_flight_00[];
extern u16 player_shot_2_flight_01[];
extern u16 player_shot_2_flight_02[];
extern u16 player_shot_2_flight_03[];
extern u16 player_shot_2_flight_04[];
extern u16 player_shot_2_flight_05[];
extern u16 player_shot_2_flight_06[];
extern u16 player_shot_2_flight_07[];
extern u16 player_shot_2_flight_08[];
extern u16 player_shot_2_flight_09[];
extern u16 player_shot_2_flight_10[];
extern u16 player_shot_2_flight_11[];
extern u16 player_shot_2_flight_12[];
extern u16 player_shot_2_flight_13[];
extern u16 player_shot_2_flight_14[];
extern u16 player_shot_2_flight_15[];
extern u16 player_shot_2_flight_16[];
extern u16 player_shot_2_flight_17[];
extern u16 player_shot_2_flight_18[];
extern u16 player_shot_2_flight_19[];
extern u16 player_shot_2_flight_20[];
extern u16 player_shot_2_flight_21[];
extern u16 player_shot_2_flight_22[];
extern u16 player_shot_2_flight_23[];
extern u16 player_shot_2_flight_24[];

extern u16 player_shot_2_flight_table[];
extern u16 player_shot_2_impact_table[];

void player_shot_2_tables_init(void) {
    STORE_POINTER(ship0_shot_list_3_00_00 + 5, ship0_shot_list_3_00_00_02);
    STORE_POINTER(ship0_shot_list_3_00_00 + 15, ship0_shot_list_3_00_00_07);
    STORE_POINTER(ship0_shot_list_3_00_00 + 24, ship0_shot_list_3_00_00_02);
    STORE_POINTER(ship0_shot_list_3_00_00 + 34, ship0_shot_list_3_00_00_07);
    STORE_POINTER(ship0_shot_list_3_00_01 + 5, ship0_shot_list_3_00_01_02);
    STORE_POINTER(ship0_shot_list_3_00_01 + 15, ship0_shot_list_3_00_01_07);
    STORE_POINTER(ship0_shot_list_3_00_01 + 24, ship0_shot_list_3_00_01_02);
    STORE_POINTER(ship0_shot_list_3_00_01 + 34, ship0_shot_list_3_00_01_07);
    STORE_POINTER(ship0_shot_list_3_00_02 + 5, ship0_shot_list_3_00_02_02);
    STORE_POINTER(ship0_shot_list_3_00_02 + 15, ship0_shot_list_3_00_02_07);
    STORE_POINTER(ship0_shot_list_3_00_02 + 24, ship0_shot_list_3_00_02_02);
    STORE_POINTER(ship0_shot_list_3_00_02 + 34, ship0_shot_list_3_00_02_07);
    STORE_POINTER(ship0_shot_list_3_00_03 + 5, ship0_shot_list_3_00_03_02);
    STORE_POINTER(ship0_shot_list_3_00_03 + 15, ship0_shot_list_3_00_03_07);
    STORE_POINTER(ship0_shot_list_3_00_03 + 24, ship0_shot_list_3_00_03_02);
    STORE_POINTER(ship0_shot_list_3_00_03 + 34, ship0_shot_list_3_00_03_07);
    STORE_POINTER(ship0_shot_list_3_00_04 + 5, ship0_shot_list_3_00_04_02);
    STORE_POINTER(ship0_shot_list_3_00_04 + 15, ship0_shot_list_3_00_04_07);
    STORE_POINTER(ship0_shot_list_3_00_04 + 24, ship0_shot_list_3_00_04_02);
    STORE_POINTER(ship0_shot_list_3_00_04 + 34, ship0_shot_list_3_00_04_07);
    STORE_POINTER(ship0_shot_list_3_02_00 + 5, ship0_shot_list_3_02_00_02);
    STORE_POINTER(ship0_shot_list_3_02_00 + 15, ship0_shot_list_3_02_00_07);
    STORE_POINTER(ship0_shot_list_3_02_01 + 5, ship0_shot_list_3_02_01_02);
    STORE_POINTER(ship0_shot_list_3_02_01 + 15, ship0_shot_list_3_02_01_07);
    STORE_POINTER(ship0_shot_list_3_02_02 + 5, ship0_shot_list_3_02_02_02);
    STORE_POINTER(ship0_shot_list_3_02_02 + 15, ship0_shot_list_3_02_02_07);
    STORE_POINTER(ship0_shot_list_3_02_03 + 5, ship0_shot_list_3_02_03_02);
    STORE_POINTER(ship0_shot_list_3_02_03 + 15, ship0_shot_list_3_02_03_07);
    STORE_POINTER(ship0_shot_list_3_02_04 + 5, ship0_shot_list_3_02_04_02);
    STORE_POINTER(ship0_shot_list_3_02_04 + 15, ship0_shot_list_3_02_04_07);
    STORE_POINTER(ship0_shot_list_3_04_00 + 5, ship0_shot_list_3_04_00_02);
    STORE_POINTER(ship0_shot_list_3_04_00 + 15, ship0_shot_list_3_04_00_07);
    STORE_POINTER(ship0_shot_list_3_04_00 + 24, ship0_shot_list_3_04_00_02);
    STORE_POINTER(ship0_shot_list_3_04_00 + 34, ship0_shot_list_3_04_00_07);
    STORE_POINTER(ship0_shot_list_3_04_01 + 5, ship0_shot_list_3_04_01_02);
    STORE_POINTER(ship0_shot_list_3_04_01 + 15, ship0_shot_list_3_04_01_07);
    STORE_POINTER(ship0_shot_list_3_04_01 + 24, ship0_shot_list_3_04_01_02);
    STORE_POINTER(ship0_shot_list_3_04_01 + 34, ship0_shot_list_3_04_01_07);
    STORE_POINTER(ship0_shot_list_3_04_02 + 5, ship0_shot_list_3_04_02_02);
    STORE_POINTER(ship0_shot_list_3_04_02 + 15, ship0_shot_list_3_04_02_07);
    STORE_POINTER(ship0_shot_list_3_04_02 + 24, ship0_shot_list_3_04_02_02);
    STORE_POINTER(ship0_shot_list_3_04_02 + 34, ship0_shot_list_3_04_02_07);
    STORE_POINTER(ship0_shot_list_3_04_03 + 5, ship0_shot_list_3_04_03_02);
    STORE_POINTER(ship0_shot_list_3_04_03 + 15, ship0_shot_list_3_04_03_07);
    STORE_POINTER(ship0_shot_list_3_04_03 + 24, ship0_shot_list_3_04_03_02);
    STORE_POINTER(ship0_shot_list_3_04_03 + 34, ship0_shot_list_3_04_03_07);
    STORE_POINTER(ship0_shot_list_3_04_04 + 5, ship0_shot_list_3_04_04_02);
    STORE_POINTER(ship0_shot_list_3_04_04 + 15, ship0_shot_list_3_04_04_07);
    STORE_POINTER(ship0_shot_list_3_04_04 + 24, ship0_shot_list_3_04_04_02);
    STORE_POINTER(ship0_shot_list_3_04_04 + 34, ship0_shot_list_3_04_04_07);
    STORE_POINTER(player_shot_2_flight_table, player_shot_2_flight_00);
    STORE_POINTER(player_shot_2_flight_table + 2, player_shot_2_flight_01);
    STORE_POINTER(player_shot_2_flight_table + 4, player_shot_2_flight_02);
    STORE_POINTER(player_shot_2_flight_table + 6, player_shot_2_flight_03);
    STORE_POINTER(player_shot_2_flight_table + 8, player_shot_2_flight_04);
    STORE_POINTER(player_shot_2_flight_table + 10, player_shot_2_flight_05);
    STORE_POINTER(player_shot_2_flight_table + 12, player_shot_2_flight_06);
    STORE_POINTER(player_shot_2_flight_table + 14, player_shot_2_flight_07);
    STORE_POINTER(player_shot_2_flight_table + 16, player_shot_2_flight_08);
    STORE_POINTER(player_shot_2_flight_table + 18, player_shot_2_flight_09);
    STORE_POINTER(player_shot_2_flight_table + 20, player_shot_2_flight_10);
    STORE_POINTER(player_shot_2_flight_table + 22, player_shot_2_flight_11);
    STORE_POINTER(player_shot_2_flight_table + 24, player_shot_2_flight_12);
    STORE_POINTER(player_shot_2_flight_table + 26, player_shot_2_flight_13);
    STORE_POINTER(player_shot_2_flight_table + 28, player_shot_2_flight_14);
    STORE_POINTER(player_shot_2_flight_table + 30, player_shot_2_flight_15);
    STORE_POINTER(player_shot_2_flight_table + 32, player_shot_2_flight_16);
    STORE_POINTER(player_shot_2_flight_table + 34, player_shot_2_flight_17);
    STORE_POINTER(player_shot_2_flight_table + 36, player_shot_2_flight_18);
    STORE_POINTER(player_shot_2_flight_table + 38, player_shot_2_flight_19);
    STORE_POINTER(player_shot_2_flight_table + 40, player_shot_2_flight_20);
    STORE_POINTER(player_shot_2_flight_table + 42, player_shot_2_flight_21);
    STORE_POINTER(player_shot_2_flight_table + 44, player_shot_2_flight_22);
    STORE_POINTER(player_shot_2_flight_table + 46, player_shot_2_flight_23);
    STORE_POINTER(player_shot_2_flight_table + 48, player_shot_2_flight_24);
    STORE_POINTER(player_shot_2_impact_table, player_shot_2_impact_00);
    STORE_POINTER(player_shot_2_impact_table + 2, player_shot_2_impact_01);
    STORE_POINTER(player_shot_2_impact_table + 4, player_shot_2_impact_02);
    STORE_POINTER(player_shot_2_impact_table + 6, player_shot_2_impact_03);
    STORE_POINTER(player_shot_2_impact_table + 8, player_shot_2_impact_04);
    STORE_POINTER(player_shot_2_impact_table + 10, player_shot_2_impact_05);
    STORE_POINTER(player_shot_2_impact_table + 12, player_shot_2_impact_06);
    STORE_POINTER(player_shot_2_impact_table + 14, player_shot_2_impact_07);
    STORE_POINTER(player_shot_2_impact_table + 16, player_shot_2_impact_08);
    STORE_POINTER(player_shot_2_impact_table + 18, player_shot_2_impact_09);
    STORE_POINTER(player_shot_2_impact_table + 20, player_shot_2_impact_10);
    STORE_POINTER(player_shot_2_impact_table + 22, player_shot_2_impact_11);
    STORE_POINTER(player_shot_2_impact_table + 24, player_shot_2_impact_12);
    STORE_POINTER(player_shot_2_impact_table + 26, player_shot_2_impact_13);
    STORE_POINTER(player_shot_2_impact_table + 28, player_shot_2_impact_14);
    STORE_POINTER(player_shot_2_impact_table + 30, player_shot_2_impact_15);
    STORE_POINTER(player_shot_2_impact_table + 32, player_shot_2_impact_16);
    STORE_POINTER(player_shot_2_impact_table + 34, player_shot_2_impact_17);
    STORE_POINTER(player_shot_2_impact_table + 36, player_shot_2_impact_18);
    STORE_POINTER(player_shot_2_impact_table + 38, player_shot_2_impact_19);
    STORE_POINTER(player_shot_2_impact_table + 40, player_shot_2_impact_20);
    STORE_POINTER(player_shot_2_impact_table + 42, player_shot_2_impact_21);
    STORE_POINTER(player_shot_2_impact_table + 44, player_shot_2_impact_22);
    STORE_POINTER(player_shot_2_impact_table + 46, player_shot_2_impact_23);
    STORE_POINTER(player_shot_2_impact_table + 48, player_shot_2_impact_24);
    STORE_POINTER(player_shot_2_impact_00 + 3, player_shot_2_impact_frames_00);
    STORE_POINTER(player_shot_2_impact_01 + 3, player_shot_2_impact_frames_00);
    STORE_POINTER(player_shot_2_impact_02 + 3, player_shot_2_impact_frames_02);
    STORE_POINTER(player_shot_2_impact_03 + 3, player_shot_2_impact_frames_02);
    STORE_POINTER(player_shot_2_impact_04 + 3, player_shot_2_impact_frames_04);
    STORE_POINTER(player_shot_2_impact_05 + 3, player_shot_2_impact_frames_04);
    STORE_POINTER(player_shot_2_impact_06 + 3, player_shot_2_impact_frames_06);
    STORE_POINTER(player_shot_2_impact_07 + 3, player_shot_2_impact_frames_06);
    STORE_POINTER(player_shot_2_impact_08 + 3, player_shot_2_impact_frames_08);
    STORE_POINTER(player_shot_2_impact_09 + 3, player_shot_2_impact_frames_08);
    STORE_POINTER(player_shot_2_impact_10 + 3, player_shot_2_impact_frames_10);
    STORE_POINTER(player_shot_2_impact_11 + 3, player_shot_2_impact_frames_11);
    STORE_POINTER(player_shot_2_impact_12 + 3, player_shot_2_impact_frames_12);
    STORE_POINTER(player_shot_2_impact_13 + 3, player_shot_2_impact_frames_13);
    STORE_POINTER(player_shot_2_impact_14 + 3, player_shot_2_impact_frames_14);
    STORE_POINTER(player_shot_2_impact_15 + 3, player_shot_2_impact_frames_15);
    STORE_POINTER(player_shot_2_impact_16 + 3, player_shot_2_impact_frames_15);
    STORE_POINTER(player_shot_2_impact_17 + 3, player_shot_2_impact_frames_17);
    STORE_POINTER(player_shot_2_impact_18 + 3, player_shot_2_impact_frames_17);
    STORE_POINTER(player_shot_2_impact_19 + 3, player_shot_2_impact_frames_19);
    STORE_POINTER(player_shot_2_impact_20 + 3, player_shot_2_impact_frames_19);
    STORE_POINTER(player_shot_2_impact_21 + 3, player_shot_2_impact_frames_21);
    STORE_POINTER(player_shot_2_impact_22 + 3, player_shot_2_impact_frames_21);
    STORE_POINTER(player_shot_2_impact_23 + 3, player_shot_2_impact_frames_23);
    STORE_POINTER(player_shot_2_impact_24 + 3, player_shot_2_impact_frames_23);
}

extern u16 D_00254410[];
extern u16 D_00254420[];
extern u16 D_00254430[];
extern u16 player_shot_5_impact_frames_00[];
extern u16 player_shot_5_impact_frames_02[];
extern u16 player_shot_5_impact_frames_04[];
extern u16 player_shot_5_impact_frames_06[];
extern u16 player_shot_5_impact_frames_08[];
extern u16 player_shot_5_impact_frames_10[];
extern u16 player_shot_5_impact_frames_11[];
extern u16 player_shot_5_impact_frames_12[];
extern u16 player_shot_5_impact_frames_13[];
extern u16 player_shot_5_impact_frames_14[];
extern u16 player_shot_5_impact_frames_15[];
extern u16 player_shot_5_impact_frames_17[];
extern u16 player_shot_5_impact_frames_19[];
extern u16 player_shot_5_impact_frames_21[];
extern u16 player_shot_5_impact_frames_23[];
extern u16 player_shot_5_impact_00[];
extern u16 player_shot_5_impact_01[];
extern u16 player_shot_5_impact_02[];
extern u16 player_shot_5_impact_03[];
extern u16 player_shot_5_impact_04[];
extern u16 player_shot_5_impact_05[];
extern u16 player_shot_5_impact_06[];
extern u16 player_shot_5_impact_07[];
extern u16 player_shot_5_impact_08[];
extern u16 player_shot_5_impact_09[];
extern u16 player_shot_5_impact_10[];
extern u16 player_shot_5_impact_11[];
extern u16 player_shot_5_impact_12[];
extern u16 player_shot_5_impact_13[];
extern u16 player_shot_5_impact_14[];
extern u16 player_shot_5_impact_15[];
extern u16 player_shot_5_impact_16[];
extern u16 player_shot_5_impact_17[];
extern u16 player_shot_5_impact_18[];
extern u16 player_shot_5_impact_19[];
extern u16 player_shot_5_impact_20[];
extern u16 player_shot_5_impact_21[];
extern u16 player_shot_5_impact_22[];
extern u16 player_shot_5_impact_23[];
extern u16 player_shot_5_impact_24[];
extern u16 D_0028C418[];
extern u16 D_0028C420[];
extern u16 D_0028C428[];
extern u16 player_shot_5_flight_00[];
extern u16 player_shot_5_flight_01[];
extern u16 player_shot_5_flight_02[];
extern u16 player_shot_5_flight_03[];
extern u16 player_shot_5_flight_04[];
extern u16 player_shot_5_flight_05[];
extern u16 player_shot_5_flight_06[];
extern u16 player_shot_5_flight_07[];
extern u16 player_shot_5_flight_08[];
extern u16 player_shot_5_flight_09[];
extern u16 player_shot_5_flight_10[];
extern u16 player_shot_5_flight_11[];
extern u16 player_shot_5_flight_12[];
extern u16 player_shot_5_flight_13[];
extern u16 player_shot_5_flight_14[];
extern u16 player_shot_5_flight_15[];
extern u16 player_shot_5_flight_16[];
extern u16 player_shot_5_flight_17[];
extern u16 player_shot_5_flight_18[];
extern u16 player_shot_5_flight_19[];
extern u16 player_shot_5_flight_20[];
extern u16 player_shot_5_flight_21[];
extern u16 player_shot_5_flight_22[];
extern u16 player_shot_5_flight_23[];
extern u16 player_shot_5_flight_24[];

extern u16 player_shot_5_flight_table[];
extern u16 player_shot_5_impact_table[];

void player_shot_5_tables_init(void) {
    STORE_POINTER(ship0_shot_list_1_01_00 + 5, D_00254410);
    STORE_POINTER(ship0_shot_list_1_01_00 + 15, D_0028C418);
    STORE_POINTER(ship0_shot_list_2_01_00 + 5, D_00254410);
    STORE_POINTER(ship0_shot_list_2_01_00 + 15, D_0028C418);
    STORE_POINTER(ship0_shot_list_1_01_01 + 5, D_00254410);
    STORE_POINTER(ship0_shot_list_1_01_01 + 15, D_0028C418);
    STORE_POINTER(ship0_shot_list_2_01_01 + 5, D_00254410);
    STORE_POINTER(ship0_shot_list_2_01_01 + 15, D_0028C418);
    STORE_POINTER(ship0_shot_list_1_01_02 + 5, D_00254410);
    STORE_POINTER(ship0_shot_list_1_01_02 + 15, D_0028C418);
    STORE_POINTER(ship0_shot_list_2_01_02 + 5, D_00254410);
    STORE_POINTER(ship0_shot_list_2_01_02 + 15, D_0028C418);
    STORE_POINTER(ship0_shot_list_1_01_03 + 5, D_00254410);
    STORE_POINTER(ship0_shot_list_1_01_03 + 15, D_0028C418);
    STORE_POINTER(ship0_shot_list_2_01_03 + 5, D_00254410);
    STORE_POINTER(ship0_shot_list_2_01_03 + 15, D_0028C418);
    STORE_POINTER(ship0_shot_list_1_01_04 + 5, D_00254410);
    STORE_POINTER(ship0_shot_list_1_01_04 + 15, D_0028C418);
    STORE_POINTER(ship0_shot_list_2_01_04 + 5, D_00254410);
    STORE_POINTER(ship0_shot_list_2_01_04 + 15, D_0028C418);
    STORE_POINTER(ship0_shot_list_1_03_00 + 5, D_00254420);
    STORE_POINTER(ship0_shot_list_1_03_00 + 15, D_0028C420);
    STORE_POINTER(ship0_shot_list_1_03_01 + 5, D_00254420);
    STORE_POINTER(ship0_shot_list_1_03_01 + 15, D_0028C420);
    STORE_POINTER(ship0_shot_list_1_03_02 + 5, D_00254420);
    STORE_POINTER(ship0_shot_list_1_03_02 + 15, D_0028C420);
    STORE_POINTER(ship0_shot_list_1_03_03 + 5, D_00254420);
    STORE_POINTER(ship0_shot_list_1_03_03 + 15, D_0028C420);
    STORE_POINTER(ship0_shot_list_1_03_04 + 5, D_00254420);
    STORE_POINTER(ship0_shot_list_1_03_04 + 15, D_0028C420);
    STORE_POINTER(ship0_shot_list_1_05_00 + 5, D_00254430);
    STORE_POINTER(ship0_shot_list_1_05_00 + 15, D_0028C428);
    STORE_POINTER(ship0_shot_list_2_05_00 + 5, D_00254430);
    STORE_POINTER(ship0_shot_list_2_05_00 + 15, D_0028C428);
    STORE_POINTER(ship0_shot_list_1_05_01 + 5, D_00254430);
    STORE_POINTER(ship0_shot_list_1_05_01 + 15, D_0028C428);
    STORE_POINTER(ship0_shot_list_2_05_01 + 5, D_00254430);
    STORE_POINTER(ship0_shot_list_2_05_01 + 15, D_0028C428);
    STORE_POINTER(ship0_shot_list_1_05_02 + 5, D_00254430);
    STORE_POINTER(ship0_shot_list_1_05_02 + 15, D_0028C428);
    STORE_POINTER(ship0_shot_list_2_05_02 + 5, D_00254430);
    STORE_POINTER(ship0_shot_list_2_05_02 + 15, D_0028C428);
    STORE_POINTER(ship0_shot_list_1_05_03 + 5, D_00254430);
    STORE_POINTER(ship0_shot_list_1_05_03 + 15, D_0028C428);
    STORE_POINTER(ship0_shot_list_2_05_03 + 5, D_00254430);
    STORE_POINTER(ship0_shot_list_2_05_03 + 15, D_0028C428);
    STORE_POINTER(ship0_shot_list_1_05_04 + 5, D_00254430);
    STORE_POINTER(ship0_shot_list_1_05_04 + 15, D_0028C428);
    STORE_POINTER(ship0_shot_list_2_05_04 + 5, D_00254430);
    STORE_POINTER(ship0_shot_list_2_05_04 + 15, D_0028C428);
    STORE_POINTER(player_shot_5_flight_table, player_shot_5_flight_00);
    STORE_POINTER(player_shot_5_flight_table + 2, player_shot_5_flight_01);
    STORE_POINTER(player_shot_5_flight_table + 4, player_shot_5_flight_02);
    STORE_POINTER(player_shot_5_flight_table + 6, player_shot_5_flight_03);
    STORE_POINTER(player_shot_5_flight_table + 8, player_shot_5_flight_04);
    STORE_POINTER(player_shot_5_flight_table + 10, player_shot_5_flight_05);
    STORE_POINTER(player_shot_5_flight_table + 12, player_shot_5_flight_06);
    STORE_POINTER(player_shot_5_flight_table + 14, player_shot_5_flight_07);
    STORE_POINTER(player_shot_5_flight_table + 16, player_shot_5_flight_08);
    STORE_POINTER(player_shot_5_flight_table + 18, player_shot_5_flight_09);
    STORE_POINTER(player_shot_5_flight_table + 20, player_shot_5_flight_10);
    STORE_POINTER(player_shot_5_flight_table + 22, player_shot_5_flight_11);
    STORE_POINTER(player_shot_5_flight_table + 24, player_shot_5_flight_12);
    STORE_POINTER(player_shot_5_flight_table + 26, player_shot_5_flight_13);
    STORE_POINTER(player_shot_5_flight_table + 28, player_shot_5_flight_14);
    STORE_POINTER(player_shot_5_flight_table + 30, player_shot_5_flight_15);
    STORE_POINTER(player_shot_5_flight_table + 32, player_shot_5_flight_16);
    STORE_POINTER(player_shot_5_flight_table + 34, player_shot_5_flight_17);
    STORE_POINTER(player_shot_5_flight_table + 36, player_shot_5_flight_18);
    STORE_POINTER(player_shot_5_flight_table + 38, player_shot_5_flight_19);
    STORE_POINTER(player_shot_5_flight_table + 40, player_shot_5_flight_20);
    STORE_POINTER(player_shot_5_flight_table + 42, player_shot_5_flight_21);
    STORE_POINTER(player_shot_5_flight_table + 44, player_shot_5_flight_22);
    STORE_POINTER(player_shot_5_flight_table + 46, player_shot_5_flight_23);
    STORE_POINTER(player_shot_5_flight_table + 48, player_shot_5_flight_24);
    STORE_POINTER(player_shot_5_impact_table, player_shot_5_impact_00);
    STORE_POINTER(player_shot_5_impact_table + 2, player_shot_5_impact_01);
    STORE_POINTER(player_shot_5_impact_table + 4, player_shot_5_impact_02);
    STORE_POINTER(player_shot_5_impact_table + 6, player_shot_5_impact_03);
    STORE_POINTER(player_shot_5_impact_table + 8, player_shot_5_impact_04);
    STORE_POINTER(player_shot_5_impact_table + 10, player_shot_5_impact_05);
    STORE_POINTER(player_shot_5_impact_table + 12, player_shot_5_impact_06);
    STORE_POINTER(player_shot_5_impact_table + 14, player_shot_5_impact_07);
    STORE_POINTER(player_shot_5_impact_table + 16, player_shot_5_impact_08);
    STORE_POINTER(player_shot_5_impact_table + 18, player_shot_5_impact_09);
    STORE_POINTER(player_shot_5_impact_table + 20, player_shot_5_impact_10);
    STORE_POINTER(player_shot_5_impact_table + 22, player_shot_5_impact_11);
    STORE_POINTER(player_shot_5_impact_table + 24, player_shot_5_impact_12);
    STORE_POINTER(player_shot_5_impact_table + 26, player_shot_5_impact_13);
    STORE_POINTER(player_shot_5_impact_table + 28, player_shot_5_impact_14);
    STORE_POINTER(player_shot_5_impact_table + 30, player_shot_5_impact_15);
    STORE_POINTER(player_shot_5_impact_table + 32, player_shot_5_impact_16);
    STORE_POINTER(player_shot_5_impact_table + 34, player_shot_5_impact_17);
    STORE_POINTER(player_shot_5_impact_table + 36, player_shot_5_impact_18);
    STORE_POINTER(player_shot_5_impact_table + 38, player_shot_5_impact_19);
    STORE_POINTER(player_shot_5_impact_table + 40, player_shot_5_impact_20);
    STORE_POINTER(player_shot_5_impact_table + 42, player_shot_5_impact_21);
    STORE_POINTER(player_shot_5_impact_table + 44, player_shot_5_impact_22);
    STORE_POINTER(player_shot_5_impact_table + 46, player_shot_5_impact_23);
    STORE_POINTER(player_shot_5_impact_table + 48, player_shot_5_impact_24);
    STORE_POINTER(player_shot_5_impact_00 + 3, player_shot_5_impact_frames_00);
    STORE_POINTER(player_shot_5_impact_01 + 3, player_shot_5_impact_frames_00);
    STORE_POINTER(player_shot_5_impact_02 + 3, player_shot_5_impact_frames_02);
    STORE_POINTER(player_shot_5_impact_03 + 3, player_shot_5_impact_frames_02);
    STORE_POINTER(player_shot_5_impact_04 + 3, player_shot_5_impact_frames_04);
    STORE_POINTER(player_shot_5_impact_05 + 3, player_shot_5_impact_frames_04);
    STORE_POINTER(player_shot_5_impact_06 + 3, player_shot_5_impact_frames_06);
    STORE_POINTER(player_shot_5_impact_07 + 3, player_shot_5_impact_frames_06);
    STORE_POINTER(player_shot_5_impact_08 + 3, player_shot_5_impact_frames_08);
    STORE_POINTER(player_shot_5_impact_09 + 3, player_shot_5_impact_frames_08);
    STORE_POINTER(player_shot_5_impact_10 + 3, player_shot_5_impact_frames_10);
    STORE_POINTER(player_shot_5_impact_11 + 3, player_shot_5_impact_frames_11);
    STORE_POINTER(player_shot_5_impact_12 + 3, player_shot_5_impact_frames_12);
    STORE_POINTER(player_shot_5_impact_13 + 3, player_shot_5_impact_frames_13);
    STORE_POINTER(player_shot_5_impact_14 + 3, player_shot_5_impact_frames_14);
    STORE_POINTER(player_shot_5_impact_15 + 3, player_shot_5_impact_frames_15);
    STORE_POINTER(player_shot_5_impact_16 + 3, player_shot_5_impact_frames_15);
    STORE_POINTER(player_shot_5_impact_17 + 3, player_shot_5_impact_frames_17);
    STORE_POINTER(player_shot_5_impact_18 + 3, player_shot_5_impact_frames_17);
    STORE_POINTER(player_shot_5_impact_19 + 3, player_shot_5_impact_frames_19);
    STORE_POINTER(player_shot_5_impact_20 + 3, player_shot_5_impact_frames_19);
    STORE_POINTER(player_shot_5_impact_21 + 3, player_shot_5_impact_frames_21);
    STORE_POINTER(player_shot_5_impact_22 + 3, player_shot_5_impact_frames_21);
    STORE_POINTER(player_shot_5_impact_23 + 3, player_shot_5_impact_frames_23);
    STORE_POINTER(player_shot_5_impact_24 + 3, player_shot_5_impact_frames_23);
}

extern u16 D_00254C50[];
extern u16 D_00254C60[];
extern u16 D_00254C70[];
extern u16 player_shot_6_impact_frames_00[];
extern u16 player_shot_6_impact_frames_02[];
extern u16 player_shot_6_impact_frames_04[];
extern u16 player_shot_6_impact_frames_06[];
extern u16 player_shot_6_impact_frames_08[];
extern u16 player_shot_6_impact_frames_10[];
extern u16 player_shot_6_impact_frames_11[];
extern u16 player_shot_6_impact_frames_12[];
extern u16 player_shot_6_impact_frames_13[];
extern u16 player_shot_6_impact_frames_14[];
extern u16 player_shot_6_impact_frames_15[];
extern u16 player_shot_6_impact_frames_17[];
extern u16 player_shot_6_impact_frames_19[];
extern u16 player_shot_6_impact_frames_21[];
extern u16 player_shot_6_impact_frames_23[];
extern u16 player_shot_6_impact_00[];
extern u16 player_shot_6_impact_01[];
extern u16 player_shot_6_impact_02[];
extern u16 player_shot_6_impact_03[];
extern u16 player_shot_6_impact_04[];
extern u16 player_shot_6_impact_05[];
extern u16 player_shot_6_impact_06[];
extern u16 player_shot_6_impact_07[];
extern u16 player_shot_6_impact_08[];
extern u16 player_shot_6_impact_09[];
extern u16 player_shot_6_impact_10[];
extern u16 player_shot_6_impact_11[];
extern u16 player_shot_6_impact_12[];
extern u16 player_shot_6_impact_13[];
extern u16 player_shot_6_impact_14[];
extern u16 player_shot_6_impact_15[];
extern u16 player_shot_6_impact_16[];
extern u16 player_shot_6_impact_17[];
extern u16 player_shot_6_impact_18[];
extern u16 player_shot_6_impact_19[];
extern u16 player_shot_6_impact_20[];
extern u16 player_shot_6_impact_21[];
extern u16 player_shot_6_impact_22[];
extern u16 player_shot_6_impact_23[];
extern u16 player_shot_6_impact_24[];
extern u16 D_0028C4F8[];
extern u16 D_0028C500[];
extern u16 D_0028C508[];
extern u16 player_shot_6_flight_00[];
extern u16 player_shot_6_flight_01[];
extern u16 player_shot_6_flight_02[];
extern u16 player_shot_6_flight_03[];
extern u16 player_shot_6_flight_04[];
extern u16 player_shot_6_flight_05[];
extern u16 player_shot_6_flight_06[];
extern u16 player_shot_6_flight_07[];
extern u16 player_shot_6_flight_08[];
extern u16 player_shot_6_flight_09[];
extern u16 player_shot_6_flight_10[];
extern u16 player_shot_6_flight_11[];
extern u16 player_shot_6_flight_12[];
extern u16 player_shot_6_flight_13[];
extern u16 player_shot_6_flight_14[];
extern u16 player_shot_6_flight_15[];
extern u16 player_shot_6_flight_16[];
extern u16 player_shot_6_flight_17[];
extern u16 player_shot_6_flight_18[];
extern u16 player_shot_6_flight_19[];
extern u16 player_shot_6_flight_20[];
extern u16 player_shot_6_flight_21[];
extern u16 player_shot_6_flight_22[];
extern u16 player_shot_6_flight_23[];
extern u16 player_shot_6_flight_24[];

extern u16 player_shot_6_flight_table[];
extern u16 player_shot_6_impact_table[];

void player_shot_6_tables_init(void) {
    STORE_POINTER(ship0_shot_list_3_01_00 + 5, D_00254C50);
    STORE_POINTER(ship0_shot_list_3_01_00 + 15, D_0028C4F8);
    STORE_POINTER(ship0_shot_list_3_01_00 + 24, D_00254C50);
    STORE_POINTER(ship0_shot_list_3_01_00 + 34, D_0028C4F8);
    STORE_POINTER(ship0_shot_list_3_01_01 + 5, D_00254C50);
    STORE_POINTER(ship0_shot_list_3_01_01 + 15, D_0028C4F8);
    STORE_POINTER(ship0_shot_list_3_01_01 + 24, D_00254C50);
    STORE_POINTER(ship0_shot_list_3_01_01 + 34, D_0028C4F8);
    STORE_POINTER(ship0_shot_list_3_01_02 + 5, D_00254C50);
    STORE_POINTER(ship0_shot_list_3_01_02 + 15, D_0028C4F8);
    STORE_POINTER(ship0_shot_list_3_01_02 + 24, D_00254C50);
    STORE_POINTER(ship0_shot_list_3_01_02 + 34, D_0028C4F8);
    STORE_POINTER(ship0_shot_list_3_01_03 + 5, D_00254C50);
    STORE_POINTER(ship0_shot_list_3_01_03 + 15, D_0028C4F8);
    STORE_POINTER(ship0_shot_list_3_01_03 + 24, D_00254C50);
    STORE_POINTER(ship0_shot_list_3_01_03 + 34, D_0028C4F8);
    STORE_POINTER(ship0_shot_list_3_01_04 + 5, D_00254C50);
    STORE_POINTER(ship0_shot_list_3_01_04 + 15, D_0028C4F8);
    STORE_POINTER(ship0_shot_list_3_01_04 + 24, D_00254C50);
    STORE_POINTER(ship0_shot_list_3_01_04 + 34, D_0028C4F8);
    STORE_POINTER(ship0_shot_list_3_03_00 + 5, D_00254C60);
    STORE_POINTER(ship0_shot_list_3_03_00 + 15, D_0028C500);
    STORE_POINTER(ship0_shot_list_3_03_01 + 5, D_00254C60);
    STORE_POINTER(ship0_shot_list_3_03_01 + 15, D_0028C500);
    STORE_POINTER(ship0_shot_list_3_03_02 + 5, D_00254C60);
    STORE_POINTER(ship0_shot_list_3_03_02 + 15, D_0028C500);
    STORE_POINTER(ship0_shot_list_3_03_03 + 5, D_00254C60);
    STORE_POINTER(ship0_shot_list_3_03_03 + 15, D_0028C500);
    STORE_POINTER(ship0_shot_list_3_03_04 + 5, D_00254C60);
    STORE_POINTER(ship0_shot_list_3_03_04 + 15, D_0028C500);
    STORE_POINTER(ship0_shot_list_3_05_00 + 5, D_00254C70);
    STORE_POINTER(ship0_shot_list_3_05_00 + 15, D_0028C508);
    STORE_POINTER(ship0_shot_list_3_05_00 + 24, D_00254C70);
    STORE_POINTER(ship0_shot_list_3_05_00 + 34, D_0028C508);
    STORE_POINTER(ship0_shot_list_3_05_01 + 5, D_00254C70);
    STORE_POINTER(ship0_shot_list_3_05_01 + 15, D_0028C508);
    STORE_POINTER(ship0_shot_list_3_05_01 + 24, D_00254C70);
    STORE_POINTER(ship0_shot_list_3_05_01 + 34, D_0028C508);
    STORE_POINTER(ship0_shot_list_3_05_02 + 5, D_00254C70);
    STORE_POINTER(ship0_shot_list_3_05_02 + 15, D_0028C508);
    STORE_POINTER(ship0_shot_list_3_05_02 + 24, D_00254C70);
    STORE_POINTER(ship0_shot_list_3_05_02 + 34, D_0028C508);
    STORE_POINTER(ship0_shot_list_3_05_03 + 5, D_00254C70);
    STORE_POINTER(ship0_shot_list_3_05_03 + 15, D_0028C508);
    STORE_POINTER(ship0_shot_list_3_05_03 + 24, D_00254C70);
    STORE_POINTER(ship0_shot_list_3_05_03 + 34, D_0028C508);
    STORE_POINTER(ship0_shot_list_3_05_04 + 5, D_00254C70);
    STORE_POINTER(ship0_shot_list_3_05_04 + 15, D_0028C508);
    STORE_POINTER(ship0_shot_list_3_05_04 + 24, D_00254C70);
    STORE_POINTER(ship0_shot_list_3_05_04 + 34, D_0028C508);
    STORE_POINTER(player_shot_6_flight_table, player_shot_6_flight_00);
    STORE_POINTER(player_shot_6_flight_table + 2, player_shot_6_flight_01);
    STORE_POINTER(player_shot_6_flight_table + 4, player_shot_6_flight_02);
    STORE_POINTER(player_shot_6_flight_table + 6, player_shot_6_flight_03);
    STORE_POINTER(player_shot_6_flight_table + 8, player_shot_6_flight_04);
    STORE_POINTER(player_shot_6_flight_table + 10, player_shot_6_flight_05);
    STORE_POINTER(player_shot_6_flight_table + 12, player_shot_6_flight_06);
    STORE_POINTER(player_shot_6_flight_table + 14, player_shot_6_flight_07);
    STORE_POINTER(player_shot_6_flight_table + 16, player_shot_6_flight_08);
    STORE_POINTER(player_shot_6_flight_table + 18, player_shot_6_flight_09);
    STORE_POINTER(player_shot_6_flight_table + 20, player_shot_6_flight_10);
    STORE_POINTER(player_shot_6_flight_table + 22, player_shot_6_flight_11);
    STORE_POINTER(player_shot_6_flight_table + 24, player_shot_6_flight_12);
    STORE_POINTER(player_shot_6_flight_table + 26, player_shot_6_flight_13);
    STORE_POINTER(player_shot_6_flight_table + 28, player_shot_6_flight_14);
    STORE_POINTER(player_shot_6_flight_table + 30, player_shot_6_flight_15);
    STORE_POINTER(player_shot_6_flight_table + 32, player_shot_6_flight_16);
    STORE_POINTER(player_shot_6_flight_table + 34, player_shot_6_flight_17);
    STORE_POINTER(player_shot_6_flight_table + 36, player_shot_6_flight_18);
    STORE_POINTER(player_shot_6_flight_table + 38, player_shot_6_flight_19);
    STORE_POINTER(player_shot_6_flight_table + 40, player_shot_6_flight_20);
    STORE_POINTER(player_shot_6_flight_table + 42, player_shot_6_flight_21);
    STORE_POINTER(player_shot_6_flight_table + 44, player_shot_6_flight_22);
    STORE_POINTER(player_shot_6_flight_table + 46, player_shot_6_flight_23);
    STORE_POINTER(player_shot_6_flight_table + 48, player_shot_6_flight_24);
    STORE_POINTER(player_shot_6_impact_table, player_shot_6_impact_00);
    STORE_POINTER(player_shot_6_impact_table + 2, player_shot_6_impact_01);
    STORE_POINTER(player_shot_6_impact_table + 4, player_shot_6_impact_02);
    STORE_POINTER(player_shot_6_impact_table + 6, player_shot_6_impact_03);
    STORE_POINTER(player_shot_6_impact_table + 8, player_shot_6_impact_04);
    STORE_POINTER(player_shot_6_impact_table + 10, player_shot_6_impact_05);
    STORE_POINTER(player_shot_6_impact_table + 12, player_shot_6_impact_06);
    STORE_POINTER(player_shot_6_impact_table + 14, player_shot_6_impact_07);
    STORE_POINTER(player_shot_6_impact_table + 16, player_shot_6_impact_08);
    STORE_POINTER(player_shot_6_impact_table + 18, player_shot_6_impact_09);
    STORE_POINTER(player_shot_6_impact_table + 20, player_shot_6_impact_10);
    STORE_POINTER(player_shot_6_impact_table + 22, player_shot_6_impact_11);
    STORE_POINTER(player_shot_6_impact_table + 24, player_shot_6_impact_12);
    STORE_POINTER(player_shot_6_impact_table + 26, player_shot_6_impact_13);
    STORE_POINTER(player_shot_6_impact_table + 28, player_shot_6_impact_14);
    STORE_POINTER(player_shot_6_impact_table + 30, player_shot_6_impact_15);
    STORE_POINTER(player_shot_6_impact_table + 32, player_shot_6_impact_16);
    STORE_POINTER(player_shot_6_impact_table + 34, player_shot_6_impact_17);
    STORE_POINTER(player_shot_6_impact_table + 36, player_shot_6_impact_18);
    STORE_POINTER(player_shot_6_impact_table + 38, player_shot_6_impact_19);
    STORE_POINTER(player_shot_6_impact_table + 40, player_shot_6_impact_20);
    STORE_POINTER(player_shot_6_impact_table + 42, player_shot_6_impact_21);
    STORE_POINTER(player_shot_6_impact_table + 44, player_shot_6_impact_22);
    STORE_POINTER(player_shot_6_impact_table + 46, player_shot_6_impact_23);
    STORE_POINTER(player_shot_6_impact_table + 48, player_shot_6_impact_24);
    STORE_POINTER(player_shot_6_impact_00 + 3, player_shot_6_impact_frames_00);
    STORE_POINTER(player_shot_6_impact_01 + 3, player_shot_6_impact_frames_00);
    STORE_POINTER(player_shot_6_impact_02 + 3, player_shot_6_impact_frames_02);
    STORE_POINTER(player_shot_6_impact_03 + 3, player_shot_6_impact_frames_02);
    STORE_POINTER(player_shot_6_impact_04 + 3, player_shot_6_impact_frames_04);
    STORE_POINTER(player_shot_6_impact_05 + 3, player_shot_6_impact_frames_04);
    STORE_POINTER(player_shot_6_impact_06 + 3, player_shot_6_impact_frames_06);
    STORE_POINTER(player_shot_6_impact_07 + 3, player_shot_6_impact_frames_06);
    STORE_POINTER(player_shot_6_impact_08 + 3, player_shot_6_impact_frames_08);
    STORE_POINTER(player_shot_6_impact_09 + 3, player_shot_6_impact_frames_08);
    STORE_POINTER(player_shot_6_impact_10 + 3, player_shot_6_impact_frames_10);
    STORE_POINTER(player_shot_6_impact_11 + 3, player_shot_6_impact_frames_11);
    STORE_POINTER(player_shot_6_impact_12 + 3, player_shot_6_impact_frames_12);
    STORE_POINTER(player_shot_6_impact_13 + 3, player_shot_6_impact_frames_13);
    STORE_POINTER(player_shot_6_impact_14 + 3, player_shot_6_impact_frames_14);
    STORE_POINTER(player_shot_6_impact_15 + 3, player_shot_6_impact_frames_15);
    STORE_POINTER(player_shot_6_impact_16 + 3, player_shot_6_impact_frames_15);
    STORE_POINTER(player_shot_6_impact_17 + 3, player_shot_6_impact_frames_17);
    STORE_POINTER(player_shot_6_impact_18 + 3, player_shot_6_impact_frames_17);
    STORE_POINTER(player_shot_6_impact_19 + 3, player_shot_6_impact_frames_19);
    STORE_POINTER(player_shot_6_impact_20 + 3, player_shot_6_impact_frames_19);
    STORE_POINTER(player_shot_6_impact_21 + 3, player_shot_6_impact_frames_21);
    STORE_POINTER(player_shot_6_impact_22 + 3, player_shot_6_impact_frames_21);
    STORE_POINTER(player_shot_6_impact_23 + 3, player_shot_6_impact_frames_23);
    STORE_POINTER(player_shot_6_impact_24 + 3, player_shot_6_impact_frames_23);
}

extern u16 D_0025C4C8[];
extern u16 D_0025C4D8[];
extern u16 D_0025C4E8[];
extern u16 D_0025C4F8[];
extern u16 D_0025C508[];
extern u16 D_0025C518[];
extern u16 D_0025C528[];
extern u16 D_0025C538[];
extern u16 D_0025C548[];
extern u16 player_shot_3_impact_frames_00[];
extern u16 player_shot_3_impact_frames_04[];
extern u16 player_shot_3_impact_frames_08[];
extern u16 player_shot_3_impact_frames_10[];
extern u16 player_shot_3_impact_frames_12[];
extern u16 player_shot_3_impact_frames_14[];
extern u16 player_shot_3_impact_frames_15[];
extern u16 player_shot_3_impact_frames_19[];
extern u16 player_shot_3_impact_frames_23[];
extern u16 D_0025CB50[];
extern u16 D_0025CB98[];
extern u16 D_0025CBA8[];
extern u16 D_0025CBC0[];
extern u16 D_0025CC10[];
extern u16 D_0025CC60[];
extern u16 D_0025CCB0[];
extern u16 player_shot_3_impact_00[];
extern u16 player_shot_3_impact_02[];
extern u16 player_shot_3_impact_04[];
extern u16 player_shot_3_impact_06[];
extern u16 player_shot_3_impact_08[];
extern u16 player_shot_3_impact_10[];
extern u16 player_shot_3_impact_11[];
extern u16 player_shot_3_impact_12[];
extern u16 player_shot_3_impact_13[];
extern u16 player_shot_3_impact_14[];
extern u16 player_shot_3_impact_15[];
extern u16 player_shot_3_impact_17[];
extern u16 player_shot_3_impact_19[];
extern u16 player_shot_3_impact_21[];
extern u16 player_shot_3_impact_23[];
extern u16 D_0028CA04[];
extern u16 D_0028CA08[];
extern u16 D_0028CA0C[];
extern u16 D_0028CA10[];
extern u16 D_0028CA14[];
extern u16 D_0028CA18[];
extern u16 D_0028CA1C[];
extern u16 D_0028CA20[];
extern u16 D_0028CA24[];
extern u16 D_0028CA28[];
extern u16 D_0028CA2C[];
extern u16 D_0028CA30[];
extern u16 D_0028CA34[];
extern u16 D_0028CA38[];
extern u16 D_0028CA3C[];
extern u16 D_0028CA40[];
extern u16 D_0028CA44[];
extern u16 D_0028CA48[];
extern u16 D_0028CA4C[];
extern u16 D_0028CA50[];
extern u16 D_0028CA54[];
extern u16 D_0028CA58[];
extern u16 D_0028CA5C[];
extern u16 D_0028CA60[];
extern u16 D_0028CA64[];
extern u16 D_0028CA68[];
extern u16 D_0028CA6C[];
extern u16 D_0028CA70[];
extern u16 D_0028CA74[];
extern u16 D_0028CA78[];
extern u16 D_0028CA7C[];
extern u16 D_0028CA80[];
extern u16 D_0028CA84[];
extern u16 D_0028CA88[];
extern u16 D_0028CA8C[];
extern u16 D_0028CA90[];
extern u16 D_0028CA94[];
extern u16 D_0028CA98[];
extern u16 D_0028CA9C[];
extern u16 D_0028CAA0[];
extern u16 D_0028CAA4[];
extern u16 D_0028CAA8[];
extern u16 D_0028CAAC[];
extern u16 D_0028CAB0[];
extern u16 D_0028CAB4[];
extern u16 D_0028CAB8[];
extern u16 D_0028CABC[];
extern u16 D_0028CAC0[];
extern u16 D_0028CAC4[];
extern u16 D_0028CAC8[];
extern u16 D_0028CACC[];
extern u16 D_0028CAD0[];
extern u16 D_0028CAD4[];
extern u16 D_0028CAD8[];
extern u16 D_0028CADC[];
extern u16 D_0028CAE0[];
extern u16 D_0028CAE4[];
extern u16 D_0028CAE8[];
extern u16 D_0028CAEC[];
extern u16 D_0028CAF0[];
extern u16 D_0028CAF4[];
extern u16 D_0028CAF8[];
extern u16 D_0028CAFC[];
extern u16 D_0028CB00[];
extern u16 D_0028CB04[];
extern u16 D_0028CB08[];
extern u16 D_0028CB0C[];
extern u16 D_0028CB10[];
extern u16 D_0028CB14[];
extern u16 D_0028CB18[];
extern u16 D_0028CB1C[];
extern u16 D_0028CB20[];
extern u16 D_0028CB24[];
extern u16 D_0028CB28[];
extern u16 D_0028CB2C[];
extern u16 D_0028CB30[];
extern u16 D_0028CB34[];
extern u16 D_0028CB38[];
extern u16 D_0028CB3C[];
extern u16 D_0028CB40[];
extern u16 D_0028CB44[];
extern u16 D_0028CB48[];
extern u16 D_0028CB4C[];
extern u16 D_0028CB50[];
extern u16 D_0028CB54[];
extern u16 D_0028CB58[];
extern u16 D_0028CB5C[];
extern u16 D_0028CB60[];
extern u16 D_0028CB64[];
extern u16 D_0028CB68[];
extern u16 D_0028CB6C[];
extern u16 D_0028CB70[];
extern u16 D_0028CB74[];
extern u16 D_0028CB78[];
extern u16 D_0028CB7C[];
extern u16 player_shot_3_flight_00[];
extern u16 player_shot_3_flight_02[];
extern u16 player_shot_3_flight_04[];
extern u16 player_shot_3_flight_06[];
extern u16 player_shot_3_flight_08[];
extern u16 player_shot_3_flight_10[];
extern u16 player_shot_3_flight_11[];
extern u16 player_shot_3_flight_12[];
extern u16 player_shot_3_flight_13[];
extern u16 player_shot_3_flight_14[];
extern u16 player_shot_3_flight_15[];
extern u16 player_shot_3_flight_17[];
extern u16 player_shot_3_flight_19[];
extern u16 player_shot_3_flight_21[];
extern u16 player_shot_3_flight_23[];
extern u16 D_0028CBF8[];
extern u16 D_0028CC00[];
extern u16 D_0028CC08[];
extern u16 D_0028CC10[];
extern u16 D_0028CC18[];
extern u16 D_0028CC20[];
extern u16 D_0028CC28[];
extern u16 D_0028CC30[];
extern u16 D_0028CC38[];
extern u16 D_0028CC40[];
extern u16 D_0028CC48[];
extern u16 D_0028CC50[];
extern u16 D_0028CC58[];
extern u16 D_0028CC60[];
extern u16 D_0028CC68[];
extern u16 D_0028CC70[];
extern u16 D_0028CC78[];
extern u16 D_0028CC80[];
extern u16 D_0028CC88[];
extern u16 D_0028CC90[];
extern u16 D_0028CC98[];
extern u16 D_0028CCA0[];
extern u16 D_0028CCA8[];
extern u16 D_0028CCB0[];
extern u16 D_0028CCB8[];
extern u16 D_0028CCC0[];
extern u16 D_0028CCC8[];
extern u16 D_0028CCD0[];
extern u16 D_0028CCD8[];
extern u16 D_0028CCE0[];
extern u16 D_0028CCE8[];
extern u16 D_0028CCF0[];
extern u16 D_0028CCF8[];
extern u16 D_0028CD00[];
extern u16 D_0028CD08[];
extern u16 D_0028CD10[];
extern u16 D_0028CD18[];
extern u16 D_0028CD20[];
extern u16 D_0028CD28[];
extern u16 D_0028CD30[];
extern u16 D_0028CD38[];
extern u16 D_0028CD40[];
extern u16 D_0028CD48[];
extern u16 D_0028CD50[];
extern u16 D_0028CD58[];
extern u16 D_0028CD60[];
extern u16 D_0028CD68[];
extern u16 D_0028CD70[];
extern u16 D_0028CD78[];
extern u16 D_0028CD80[];
extern u16 D_0028CD88[];
extern u16 D_0028CD90[];
extern u16 D_0028CD98[];
extern u16 D_0028CDA0[];
extern u16 D_0028CDA8[];
extern u16 D_0028CDB0[];
extern u16 D_0028CDB8[];
extern u16 D_0028CDC0[];
extern u16 D_0028CDC8[];
extern u16 D_0028CDD0[];
extern u16 D_0028CDD8[];
extern u16 D_0028CDE0[];
extern u16 D_0028CDE8[];
extern u16 D_0028CDF0[];
extern u16 D_0028CDF8[];
extern u16 D_0028CE00[];
extern u16 D_0028CE08[];
extern u16 D_0028CE10[];
extern u16 D_0028CE18[];
extern u16 D_0028CE20[];
extern u16 D_0028CE28[];
extern u16 D_0028CE30[];
extern u16 D_0028CE38[];
extern u16 D_0028CE40[];
extern u16 D_0028CE48[];
extern u16 D_0028CE50[];
extern u16 D_0028CE58[];
extern u16 D_0028CE60[];
extern u16 D_0028CE68[];
extern u16 D_0028CE70[];
extern u16 D_0028CE78[];
extern u16 D_0028CE80[];
extern u16 D_0028CE88[];

extern u16 player_shot_3_flight_table[];
extern u16 player_shot_3_impact_table[];

void player_shot_3_tables_init(void) {
    STORE_POINTER(D_0025C680 + 5, D_0025C4C8);
    STORE_POINTER(D_0025C680 + 15, D_0028CA04);
    STORE_POINTER(D_0025C6B0 + 5, D_0025C4C8);
    STORE_POINTER(D_0025C6B0 + 15, D_0028CA04);
    STORE_POINTER(D_0025C6E0 + 5, D_0025C4C8);
    STORE_POINTER(D_0025C6E0 + 15, D_0028CA08);
    STORE_POINTER(D_0025C710 + 5, D_0025C4C8);
    STORE_POINTER(D_0025C710 + 15, D_0028CA08);
    STORE_POINTER(D_0025C740 + 5, D_0025C4D8);
    STORE_POINTER(D_0025C740 + 15, D_0028CA0C);
    STORE_POINTER(D_0025C770 + 5, D_0025C4D8);
    STORE_POINTER(D_0025C770 + 15, D_0028CA0C);
    STORE_POINTER(D_0025C7A0 + 5, D_0025C4D8);
    STORE_POINTER(D_0025C7A0 + 15, D_0028CA10);
    STORE_POINTER(D_0025C7D0 + 5, D_0025C4D8);
    STORE_POINTER(D_0025C7D0 + 15, D_0028CA10);
    STORE_POINTER(D_0025C800 + 5, D_0025C4E8);
    STORE_POINTER(D_0025C800 + 15, D_0028CA14);
    STORE_POINTER(D_0025C830 + 5, D_0025C4E8);
    STORE_POINTER(D_0025C830 + 15, D_0028CA14);
    STORE_POINTER(D_0025C860 + 1, D_0025CB50);
    STORE_POINTER(D_0025C860 + 5, D_0025C4F8);
    STORE_POINTER(D_0025C890 + 1, D_0025CBC0);
    STORE_POINTER(D_0025C890 + 5, D_0025C4F8);
    STORE_POINTER(D_0025C8C0 + 1, D_0025CC10);
    STORE_POINTER(D_0025C8C0 + 5, D_0025C508);
    STORE_POINTER(D_0025C8F0 + 1, D_0025CC60);
    STORE_POINTER(D_0025C8F0 + 5, D_0025C508);
    STORE_POINTER(D_0025C920 + 1, D_0025CCB0);
    STORE_POINTER(D_0025C920 + 5, D_0025C518);
    STORE_POINTER(D_0025C950 + 5, D_0025C528);
    STORE_POINTER(D_0025C950 + 15, D_0028CB6C);
    STORE_POINTER(D_0025C950 + 24, D_0025C528);
    STORE_POINTER(D_0025C950 + 34, D_0028CB6C);
    STORE_POINTER(D_0025C9A0 + 5, D_0025C528);
    STORE_POINTER(D_0025C9A0 + 15, D_0028CB70);
    STORE_POINTER(D_0025C9A0 + 24, D_0025C528);
    STORE_POINTER(D_0025C9A0 + 34, D_0028CB70);
    STORE_POINTER(D_0025C9F0 + 5, D_0025C538);
    STORE_POINTER(D_0025C9F0 + 15, D_0028CB74);
    STORE_POINTER(D_0025C9F0 + 24, D_0025C538);
    STORE_POINTER(D_0025C9F0 + 34, D_0028CB74);
    STORE_POINTER(D_0025CA40 + 5, D_0025C538);
    STORE_POINTER(D_0025CA40 + 15, D_0028CB78);
    STORE_POINTER(D_0025CA40 + 24, D_0025C538);
    STORE_POINTER(D_0025CA40 + 34, D_0028CB78);
    STORE_POINTER(D_0025CA90 + 5, D_0025C548);
    STORE_POINTER(D_0025CA90 + 15, D_0028CB7C);
    STORE_POINTER(D_0025CA90 + 24, D_0025C548);
    STORE_POINTER(D_0025CA90 + 34, D_0028CB7C);
    STORE_POINTER(player_shot_3_flight_table, player_shot_3_flight_00);
    STORE_POINTER(player_shot_3_flight_table + 2, player_shot_3_flight_00);
    STORE_POINTER(player_shot_3_flight_table + 4, player_shot_3_flight_02);
    STORE_POINTER(player_shot_3_flight_table + 6, player_shot_3_flight_02);
    STORE_POINTER(player_shot_3_flight_table + 8, player_shot_3_flight_04);
    STORE_POINTER(player_shot_3_flight_table + 10, player_shot_3_flight_04);
    STORE_POINTER(player_shot_3_flight_table + 12, player_shot_3_flight_06);
    STORE_POINTER(player_shot_3_flight_table + 14, player_shot_3_flight_06);
    STORE_POINTER(player_shot_3_flight_table + 16, player_shot_3_flight_08);
    STORE_POINTER(player_shot_3_flight_table + 18, player_shot_3_flight_08);
    STORE_POINTER(player_shot_3_flight_table + 20, player_shot_3_flight_10);
    STORE_POINTER(player_shot_3_flight_table + 22, player_shot_3_flight_11);
    STORE_POINTER(player_shot_3_flight_table + 24, player_shot_3_flight_12);
    STORE_POINTER(player_shot_3_flight_table + 26, player_shot_3_flight_13);
    STORE_POINTER(player_shot_3_flight_table + 28, player_shot_3_flight_14);
    STORE_POINTER(player_shot_3_flight_table + 30, player_shot_3_flight_15);
    STORE_POINTER(player_shot_3_flight_table + 32, player_shot_3_flight_15);
    STORE_POINTER(player_shot_3_flight_table + 34, player_shot_3_flight_17);
    STORE_POINTER(player_shot_3_flight_table + 36, player_shot_3_flight_17);
    STORE_POINTER(player_shot_3_flight_table + 38, player_shot_3_flight_19);
    STORE_POINTER(player_shot_3_flight_table + 40, player_shot_3_flight_19);
    STORE_POINTER(player_shot_3_flight_table + 42, player_shot_3_flight_21);
    STORE_POINTER(player_shot_3_flight_table + 44, player_shot_3_flight_21);
    STORE_POINTER(player_shot_3_flight_table + 46, player_shot_3_flight_23);
    STORE_POINTER(player_shot_3_flight_table + 48, player_shot_3_flight_23);
    STORE_POINTER(D_0025CB50, D_0025CB98);
    STORE_POINTER(D_0025CB50 + 2, D_0028CBF8);
    STORE_POINTER(D_0025CB50 + 4, D_0028CC00);
    STORE_POINTER(D_0025CB50 + 6, D_0028CC08);
    STORE_POINTER(D_0025CB50 + 8, D_0028CC10);
    STORE_POINTER(D_0025CB50 + 10, D_0028CC18);
    STORE_POINTER(D_0025CB50 + 12, D_0028CC20);
    STORE_POINTER(D_0025CB50 + 14, D_0028CC28);
    STORE_POINTER(D_0025CB50 + 16, D_0028CC30);
    STORE_POINTER(D_0025CB50 + 18, D_0028CC38);
    STORE_POINTER(D_0025CB50 + 20, D_0028CC40);
    STORE_POINTER(D_0025CB50 + 22, D_0028CC48);
    STORE_POINTER(D_0025CB50 + 24, D_0028CC50);
    STORE_POINTER(D_0025CB50 + 26, D_0025CBA8);
    STORE_POINTER(D_0025CB50 + 28, D_0028CC58);
    STORE_POINTER(D_0025CB50 + 30, D_0028CC60);
    STORE_POINTER(D_0025CB50 + 32, D_0028CC68);
    STORE_POINTER(D_0025CB98 + 2, D_0028CA18);
    STORE_POINTER(D_0028CBF8 + 2, D_0028CA1C);
    STORE_POINTER(D_0028CC00 + 2, D_0028CA20);
    STORE_POINTER(D_0028CC08 + 2, D_0028CA24);
    STORE_POINTER(D_0028CC10 + 2, D_0028CA28);
    STORE_POINTER(D_0028CC18 + 2, D_0028CA2C);
    STORE_POINTER(D_0028CC20 + 2, D_0028CA30);
    STORE_POINTER(D_0028CC28 + 2, D_0028CA34);
    STORE_POINTER(D_0028CC30 + 2, D_0028CA38);
    STORE_POINTER(D_0028CC38 + 2, D_0028CA3C);
    STORE_POINTER(D_0028CC40 + 2, D_0028CA40);
    STORE_POINTER(D_0028CC48 + 2, D_0028CA44);
    STORE_POINTER(D_0028CC50 + 2, D_0028CA48);
    STORE_POINTER(D_0025CBA8 + 2, D_0028CA4C);
    STORE_POINTER(D_0028CC58 + 2, D_0028CA50);
    STORE_POINTER(D_0028CC60 + 2, D_0028CA54);
    STORE_POINTER(D_0028CC68 + 2, D_0028CA58);
    STORE_POINTER(D_0025CBC0, D_0028CC70);
    STORE_POINTER(D_0025CBC0 + 2, D_0028CC78);
    STORE_POINTER(D_0025CBC0 + 4, D_0028CC80);
    STORE_POINTER(D_0025CBC0 + 6, D_0028CC88);
    STORE_POINTER(D_0025CBC0 + 8, D_0028CC90);
    STORE_POINTER(D_0025CBC0 + 10, D_0028CC98);
    STORE_POINTER(D_0025CBC0 + 12, D_0028CCA0);
    STORE_POINTER(D_0025CBC0 + 14, D_0028CCA8);
    STORE_POINTER(D_0025CBC0 + 16, D_0028CCB0);
    STORE_POINTER(D_0025CBC0 + 18, D_0028CCB8);
    STORE_POINTER(D_0025CBC0 + 20, D_0028CCC0);
    STORE_POINTER(D_0025CBC0 + 22, D_0028CCC8);
    STORE_POINTER(D_0025CBC0 + 24, D_0028CCD0);
    STORE_POINTER(D_0025CBC0 + 26, D_0028CCD8);
    STORE_POINTER(D_0025CBC0 + 28, D_0028CCE0);
    STORE_POINTER(D_0025CBC0 + 30, D_0028CCE8);
    STORE_POINTER(D_0025CBC0 + 32, D_0028CCF0);
    STORE_POINTER(D_0028CC70 + 2, D_0028CA5C);
    STORE_POINTER(D_0028CC78 + 2, D_0028CA60);
    STORE_POINTER(D_0028CC80 + 2, D_0028CA64);
    STORE_POINTER(D_0028CC88 + 2, D_0028CA68);
    STORE_POINTER(D_0028CC90 + 2, D_0028CA6C);
    STORE_POINTER(D_0028CC98 + 2, D_0028CA70);
    STORE_POINTER(D_0028CCA0 + 2, D_0028CA74);
    STORE_POINTER(D_0028CCA8 + 2, D_0028CA78);
    STORE_POINTER(D_0028CCB0 + 2, D_0028CA7C);
    STORE_POINTER(D_0028CCB8 + 2, D_0028CA80);
    STORE_POINTER(D_0028CCC0 + 2, D_0028CA84);
    STORE_POINTER(D_0028CCC8 + 2, D_0028CA88);
    STORE_POINTER(D_0028CCD0 + 2, D_0028CA8C);
    STORE_POINTER(D_0028CCD8 + 2, D_0028CA90);
    STORE_POINTER(D_0028CCE0 + 2, D_0028CA94);
    STORE_POINTER(D_0028CCE8 + 2, D_0028CA98);
    STORE_POINTER(D_0028CCF0 + 2, D_0028CA9C);
    STORE_POINTER(D_0025CC10, D_0028CCF8);
    STORE_POINTER(D_0025CC10 + 2, D_0028CD00);
    STORE_POINTER(D_0025CC10 + 4, D_0028CD08);
    STORE_POINTER(D_0025CC10 + 6, D_0028CD10);
    STORE_POINTER(D_0025CC10 + 8, D_0028CD18);
    STORE_POINTER(D_0025CC10 + 10, D_0028CD20);
    STORE_POINTER(D_0025CC10 + 12, D_0028CD28);
    STORE_POINTER(D_0025CC10 + 14, D_0028CD30);
    STORE_POINTER(D_0025CC10 + 16, D_0028CD38);
    STORE_POINTER(D_0025CC10 + 18, D_0028CD40);
    STORE_POINTER(D_0025CC10 + 20, D_0028CD48);
    STORE_POINTER(D_0025CC10 + 22, D_0028CD50);
    STORE_POINTER(D_0025CC10 + 24, D_0028CD58);
    STORE_POINTER(D_0025CC10 + 26, D_0028CD60);
    STORE_POINTER(D_0025CC10 + 28, D_0028CD68);
    STORE_POINTER(D_0025CC10 + 30, D_0028CD70);
    STORE_POINTER(D_0025CC10 + 32, D_0028CD78);
    STORE_POINTER(D_0028CCF8 + 2, D_0028CAA0);
    STORE_POINTER(D_0028CD00 + 2, D_0028CAA4);
    STORE_POINTER(D_0028CD08 + 2, D_0028CAA8);
    STORE_POINTER(D_0028CD10 + 2, D_0028CAAC);
    STORE_POINTER(D_0028CD18 + 2, D_0028CAB0);
    STORE_POINTER(D_0028CD20 + 2, D_0028CAB4);
    STORE_POINTER(D_0028CD28 + 2, D_0028CAB8);
    STORE_POINTER(D_0028CD30 + 2, D_0028CABC);
    STORE_POINTER(D_0028CD38 + 2, D_0028CAC0);
    STORE_POINTER(D_0028CD40 + 2, D_0028CAC4);
    STORE_POINTER(D_0028CD48 + 2, D_0028CAC8);
    STORE_POINTER(D_0028CD50 + 2, D_0028CACC);
    STORE_POINTER(D_0028CD58 + 2, D_0028CAD0);
    STORE_POINTER(D_0028CD60 + 2, D_0028CAD4);
    STORE_POINTER(D_0028CD68 + 2, D_0028CAD8);
    STORE_POINTER(D_0028CD70 + 2, D_0028CADC);
    STORE_POINTER(D_0028CD78 + 2, D_0028CAE0);
    STORE_POINTER(D_0025CC60, D_0028CD80);
    STORE_POINTER(D_0025CC60 + 2, D_0028CD88);
    STORE_POINTER(D_0025CC60 + 4, D_0028CD90);
    STORE_POINTER(D_0025CC60 + 6, D_0028CD98);
    STORE_POINTER(D_0025CC60 + 8, D_0028CDA0);
    STORE_POINTER(D_0025CC60 + 10, D_0028CDA8);
    STORE_POINTER(D_0025CC60 + 12, D_0028CDB0);
    STORE_POINTER(D_0025CC60 + 14, D_0028CDB8);
    STORE_POINTER(D_0025CC60 + 16, D_0028CDC0);
    STORE_POINTER(D_0025CC60 + 18, D_0028CDC8);
    STORE_POINTER(D_0025CC60 + 20, D_0028CDD0);
    STORE_POINTER(D_0025CC60 + 22, D_0028CDD8);
    STORE_POINTER(D_0025CC60 + 24, D_0028CDE0);
    STORE_POINTER(D_0025CC60 + 26, D_0028CDE8);
    STORE_POINTER(D_0025CC60 + 28, D_0028CDF0);
    STORE_POINTER(D_0025CC60 + 30, D_0028CDF8);
    STORE_POINTER(D_0025CC60 + 32, D_0028CE00);
    STORE_POINTER(D_0028CD80 + 2, D_0028CAE4);
    STORE_POINTER(D_0028CD88 + 2, D_0028CAE8);
    STORE_POINTER(D_0028CD90 + 2, D_0028CAEC);
    STORE_POINTER(D_0028CD98 + 2, D_0028CAF0);
    STORE_POINTER(D_0028CDA0 + 2, D_0028CAF4);
    STORE_POINTER(D_0028CDA8 + 2, D_0028CAF8);
    STORE_POINTER(D_0028CDB0 + 2, D_0028CAFC);
    STORE_POINTER(D_0028CDB8 + 2, D_0028CB00);
    STORE_POINTER(D_0028CDC0 + 2, D_0028CB04);
    STORE_POINTER(D_0028CDC8 + 2, D_0028CB08);
    STORE_POINTER(D_0028CDD0 + 2, D_0028CB0C);
    STORE_POINTER(D_0028CDD8 + 2, D_0028CB10);
    STORE_POINTER(D_0028CDE0 + 2, D_0028CB14);
    STORE_POINTER(D_0028CDE8 + 2, D_0028CB18);
    STORE_POINTER(D_0028CDF0 + 2, D_0028CB1C);
    STORE_POINTER(D_0028CDF8 + 2, D_0028CB20);
    STORE_POINTER(D_0028CE00 + 2, D_0028CB24);
    STORE_POINTER(D_0025CCB0, D_0028CE08);
    STORE_POINTER(D_0025CCB0 + 2, D_0028CE10);
    STORE_POINTER(D_0025CCB0 + 4, D_0028CE18);
    STORE_POINTER(D_0025CCB0 + 6, D_0028CE20);
    STORE_POINTER(D_0025CCB0 + 8, D_0028CE28);
    STORE_POINTER(D_0025CCB0 + 10, D_0028CE30);
    STORE_POINTER(D_0025CCB0 + 12, D_0028CE38);
    STORE_POINTER(D_0025CCB0 + 14, D_0028CE40);
    STORE_POINTER(D_0025CCB0 + 16, D_0028CE48);
    STORE_POINTER(D_0025CCB0 + 18, D_0028CE50);
    STORE_POINTER(D_0025CCB0 + 20, D_0028CE58);
    STORE_POINTER(D_0025CCB0 + 22, D_0028CE60);
    STORE_POINTER(D_0025CCB0 + 24, D_0028CE68);
    STORE_POINTER(D_0025CCB0 + 26, D_0028CE70);
    STORE_POINTER(D_0025CCB0 + 28, D_0028CE78);
    STORE_POINTER(D_0025CCB0 + 30, D_0028CE80);
    STORE_POINTER(D_0025CCB0 + 32, D_0028CE88);
    STORE_POINTER(D_0028CE08 + 2, D_0028CB28);
    STORE_POINTER(D_0028CE10 + 2, D_0028CB2C);
    STORE_POINTER(D_0028CE18 + 2, D_0028CB30);
    STORE_POINTER(D_0028CE20 + 2, D_0028CB34);
    STORE_POINTER(D_0028CE28 + 2, D_0028CB38);
    STORE_POINTER(D_0028CE30 + 2, D_0028CB3C);
    STORE_POINTER(D_0028CE38 + 2, D_0028CB40);
    STORE_POINTER(D_0028CE40 + 2, D_0028CB44);
    STORE_POINTER(D_0028CE48 + 2, D_0028CB48);
    STORE_POINTER(D_0028CE50 + 2, D_0028CB4C);
    STORE_POINTER(D_0028CE58 + 2, D_0028CB50);
    STORE_POINTER(D_0028CE60 + 2, D_0028CB54);
    STORE_POINTER(D_0028CE68 + 2, D_0028CB58);
    STORE_POINTER(D_0028CE70 + 2, D_0028CB5C);
    STORE_POINTER(D_0028CE78 + 2, D_0028CB60);
    STORE_POINTER(D_0028CE80 + 2, D_0028CB64);
    STORE_POINTER(D_0028CE88 + 2, D_0028CB68);
    STORE_POINTER(player_shot_3_impact_table, player_shot_3_impact_00);
    STORE_POINTER(player_shot_3_impact_table + 2, player_shot_3_impact_00);
    STORE_POINTER(player_shot_3_impact_table + 4, player_shot_3_impact_02);
    STORE_POINTER(player_shot_3_impact_table + 6, player_shot_3_impact_02);
    STORE_POINTER(player_shot_3_impact_table + 8, player_shot_3_impact_04);
    STORE_POINTER(player_shot_3_impact_table + 10, player_shot_3_impact_04);
    STORE_POINTER(player_shot_3_impact_table + 12, player_shot_3_impact_06);
    STORE_POINTER(player_shot_3_impact_table + 14, player_shot_3_impact_06);
    STORE_POINTER(player_shot_3_impact_table + 16, player_shot_3_impact_08);
    STORE_POINTER(player_shot_3_impact_table + 18, player_shot_3_impact_08);
    STORE_POINTER(player_shot_3_impact_table + 20, player_shot_3_impact_10);
    STORE_POINTER(player_shot_3_impact_table + 22, player_shot_3_impact_11);
    STORE_POINTER(player_shot_3_impact_table + 24, player_shot_3_impact_12);
    STORE_POINTER(player_shot_3_impact_table + 26, player_shot_3_impact_13);
    STORE_POINTER(player_shot_3_impact_table + 28, player_shot_3_impact_14);
    STORE_POINTER(player_shot_3_impact_table + 30, player_shot_3_impact_15);
    STORE_POINTER(player_shot_3_impact_table + 32, player_shot_3_impact_15);
    STORE_POINTER(player_shot_3_impact_table + 34, player_shot_3_impact_17);
    STORE_POINTER(player_shot_3_impact_table + 36, player_shot_3_impact_17);
    STORE_POINTER(player_shot_3_impact_table + 38, player_shot_3_impact_19);
    STORE_POINTER(player_shot_3_impact_table + 40, player_shot_3_impact_19);
    STORE_POINTER(player_shot_3_impact_table + 42, player_shot_3_impact_21);
    STORE_POINTER(player_shot_3_impact_table + 44, player_shot_3_impact_21);
    STORE_POINTER(player_shot_3_impact_table + 46, player_shot_3_impact_23);
    STORE_POINTER(player_shot_3_impact_table + 48, player_shot_3_impact_23);
    STORE_POINTER(player_shot_3_impact_00 + 3, player_shot_3_impact_frames_00);
    STORE_POINTER(player_shot_3_impact_02 + 3, player_shot_3_impact_frames_00);
    STORE_POINTER(player_shot_3_impact_04 + 3, player_shot_3_impact_frames_04);
    STORE_POINTER(player_shot_3_impact_06 + 3, player_shot_3_impact_frames_04);
    STORE_POINTER(player_shot_3_impact_08 + 3, player_shot_3_impact_frames_08);
    STORE_POINTER(player_shot_3_impact_10 + 3, player_shot_3_impact_frames_10);
    STORE_POINTER(player_shot_3_impact_11 + 3, player_shot_3_impact_frames_10);
    STORE_POINTER(player_shot_3_impact_12 + 3, player_shot_3_impact_frames_12);
    STORE_POINTER(player_shot_3_impact_13 + 3, player_shot_3_impact_frames_12);
    STORE_POINTER(player_shot_3_impact_14 + 3, player_shot_3_impact_frames_14);
    STORE_POINTER(player_shot_3_impact_15 + 3, player_shot_3_impact_frames_15);
    STORE_POINTER(player_shot_3_impact_17 + 3, player_shot_3_impact_frames_15);
    STORE_POINTER(player_shot_3_impact_19 + 3, player_shot_3_impact_frames_19);
    STORE_POINTER(player_shot_3_impact_21 + 3, player_shot_3_impact_frames_19);
    STORE_POINTER(player_shot_3_impact_23 + 3, player_shot_3_impact_frames_23);
}

extern u16 D_0025CE58[];
extern u16 D_0025CE68[];
extern u16 D_0025CE78[];
extern u16 D_0025CE88[];
extern u16 D_0025CE98[];
extern u16 D_0025CEA8[];
extern u16 D_0025CEB8[];
extern u16 D_0025CEC8[];
extern u16 D_0025CED8[];
extern u16 player_shot_4_impact_frames_00[];
extern u16 player_shot_4_impact_frames_04[];
extern u16 player_shot_4_impact_frames_08[];
extern u16 player_shot_4_impact_frames_10[];
extern u16 player_shot_4_impact_frames_12[];
extern u16 player_shot_4_impact_frames_14[];
extern u16 player_shot_4_impact_frames_15[];
extern u16 player_shot_4_impact_frames_19[];
extern u16 player_shot_4_impact_frames_23[];
extern u16 D_0025D4E0[];
extern u16 D_0025D528[];
extern u16 D_0025D538[];
extern u16 D_0025D550[];
extern u16 D_0025D5A0[];
extern u16 D_0025D5F0[];
extern u16 D_0025D640[];
extern u16 player_shot_4_impact_00[];
extern u16 player_shot_4_impact_02[];
extern u16 player_shot_4_impact_04[];
extern u16 player_shot_4_impact_06[];
extern u16 player_shot_4_impact_08[];
extern u16 player_shot_4_impact_10[];
extern u16 player_shot_4_impact_11[];
extern u16 player_shot_4_impact_12[];
extern u16 player_shot_4_impact_13[];
extern u16 player_shot_4_impact_14[];
extern u16 player_shot_4_impact_15[];
extern u16 player_shot_4_impact_17[];
extern u16 player_shot_4_impact_19[];
extern u16 player_shot_4_impact_21[];
extern u16 player_shot_4_impact_23[];
extern u16 D_0028CE90[];
extern u16 D_0028CE94[];
extern u16 D_0028CE98[];
extern u16 D_0028CE9C[];
extern u16 D_0028CEA0[];
extern u16 D_0028CEA4[];
extern u16 D_0028CEA8[];
extern u16 D_0028CEAC[];
extern u16 D_0028CEB0[];
extern u16 D_0028CEB4[];
extern u16 D_0028CEB8[];
extern u16 D_0028CEBC[];
extern u16 D_0028CEC0[];
extern u16 D_0028CEC4[];
extern u16 D_0028CEC8[];
extern u16 D_0028CECC[];
extern u16 D_0028CED0[];
extern u16 D_0028CED4[];
extern u16 D_0028CED8[];
extern u16 D_0028CEDC[];
extern u16 D_0028CEE0[];
extern u16 D_0028CEE4[];
extern u16 D_0028CEE8[];
extern u16 D_0028CEEC[];
extern u16 D_0028CEF0[];
extern u16 D_0028CEF4[];
extern u16 D_0028CEF8[];
extern u16 D_0028CEFC[];
extern u16 D_0028CF00[];
extern u16 D_0028CF04[];
extern u16 D_0028CF08[];
extern u16 D_0028CF0C[];
extern u16 D_0028CF10[];
extern u16 D_0028CF14[];
extern u16 D_0028CF18[];
extern u16 D_0028CF1C[];
extern u16 D_0028CF20[];
extern u16 D_0028CF24[];
extern u16 D_0028CF28[];
extern u16 D_0028CF2C[];
extern u16 D_0028CF30[];
extern u16 D_0028CF34[];
extern u16 D_0028CF38[];
extern u16 D_0028CF3C[];
extern u16 D_0028CF40[];
extern u16 D_0028CF44[];
extern u16 D_0028CF48[];
extern u16 D_0028CF4C[];
extern u16 D_0028CF50[];
extern u16 D_0028CF54[];
extern u16 D_0028CF58[];
extern u16 D_0028CF5C[];
extern u16 D_0028CF60[];
extern u16 D_0028CF64[];
extern u16 D_0028CF68[];
extern u16 D_0028CF6C[];
extern u16 D_0028CF70[];
extern u16 D_0028CF74[];
extern u16 D_0028CF78[];
extern u16 D_0028CF7C[];
extern u16 D_0028CF80[];
extern u16 D_0028CF84[];
extern u16 D_0028CF88[];
extern u16 D_0028CF8C[];
extern u16 D_0028CF90[];
extern u16 D_0028CF94[];
extern u16 D_0028CF98[];
extern u16 D_0028CF9C[];
extern u16 D_0028CFA0[];
extern u16 D_0028CFA4[];
extern u16 D_0028CFA8[];
extern u16 D_0028CFAC[];
extern u16 D_0028CFB0[];
extern u16 D_0028CFB4[];
extern u16 D_0028CFB8[];
extern u16 D_0028CFBC[];
extern u16 D_0028CFC0[];
extern u16 D_0028CFC4[];
extern u16 D_0028CFC8[];
extern u16 D_0028CFCC[];
extern u16 D_0028CFD0[];
extern u16 D_0028CFD4[];
extern u16 D_0028CFD8[];
extern u16 D_0028CFDC[];
extern u16 D_0028CFE0[];
extern u16 D_0028CFE4[];
extern u16 D_0028CFE8[];
extern u16 D_0028CFEC[];
extern u16 D_0028CFF0[];
extern u16 D_0028CFF4[];
extern u16 D_0028CFF8[];
extern u16 D_0028CFFC[];
extern u16 D_0028D000[];
extern u16 D_0028D004[];
extern u16 D_0028D008[];
extern u16 player_shot_4_flight_00[];
extern u16 player_shot_4_flight_02[];
extern u16 player_shot_4_flight_04[];
extern u16 player_shot_4_flight_06[];
extern u16 player_shot_4_flight_08[];
extern u16 player_shot_4_flight_10[];
extern u16 player_shot_4_flight_11[];
extern u16 player_shot_4_flight_12[];
extern u16 player_shot_4_flight_13[];
extern u16 player_shot_4_flight_14[];
extern u16 player_shot_4_flight_15[];
extern u16 player_shot_4_flight_17[];
extern u16 player_shot_4_flight_19[];
extern u16 player_shot_4_flight_21[];
extern u16 player_shot_4_flight_23[];
extern u16 D_0028D088[];
extern u16 D_0028D090[];
extern u16 D_0028D098[];
extern u16 D_0028D0A0[];
extern u16 D_0028D0A8[];
extern u16 D_0028D0B0[];
extern u16 D_0028D0B8[];
extern u16 D_0028D0C0[];
extern u16 D_0028D0C8[];
extern u16 D_0028D0D0[];
extern u16 D_0028D0D8[];
extern u16 D_0028D0E0[];
extern u16 D_0028D0E8[];
extern u16 D_0028D0F0[];
extern u16 D_0028D0F8[];
extern u16 D_0028D100[];
extern u16 D_0028D108[];
extern u16 D_0028D110[];
extern u16 D_0028D118[];
extern u16 D_0028D120[];
extern u16 D_0028D128[];
extern u16 D_0028D130[];
extern u16 D_0028D138[];
extern u16 D_0028D140[];
extern u16 D_0028D148[];
extern u16 D_0028D150[];
extern u16 D_0028D158[];
extern u16 D_0028D160[];
extern u16 D_0028D168[];
extern u16 D_0028D170[];
extern u16 D_0028D178[];
extern u16 D_0028D180[];
extern u16 D_0028D188[];
extern u16 D_0028D190[];
extern u16 D_0028D198[];
extern u16 D_0028D1A0[];
extern u16 D_0028D1A8[];
extern u16 D_0028D1B0[];
extern u16 D_0028D1B8[];
extern u16 D_0028D1C0[];
extern u16 D_0028D1C8[];
extern u16 D_0028D1D0[];
extern u16 D_0028D1D8[];
extern u16 D_0028D1E0[];
extern u16 D_0028D1E8[];
extern u16 D_0028D1F0[];
extern u16 D_0028D1F8[];
extern u16 D_0028D200[];
extern u16 D_0028D208[];
extern u16 D_0028D210[];
extern u16 D_0028D218[];
extern u16 D_0028D220[];
extern u16 D_0028D228[];
extern u16 D_0028D230[];
extern u16 D_0028D238[];
extern u16 D_0028D240[];
extern u16 D_0028D248[];
extern u16 D_0028D250[];
extern u16 D_0028D258[];
extern u16 D_0028D260[];
extern u16 D_0028D268[];
extern u16 D_0028D270[];
extern u16 D_0028D278[];
extern u16 D_0028D280[];
extern u16 D_0028D288[];
extern u16 D_0028D290[];
extern u16 D_0028D298[];
extern u16 D_0028D2A0[];
extern u16 D_0028D2A8[];
extern u16 D_0028D2B0[];
extern u16 D_0028D2B8[];
extern u16 D_0028D2C0[];
extern u16 D_0028D2C8[];
extern u16 D_0028D2D0[];
extern u16 D_0028D2D8[];
extern u16 D_0028D2E0[];
extern u16 D_0028D2E8[];
extern u16 D_0028D2F0[];
extern u16 D_0028D2F8[];
extern u16 D_0028D300[];
extern u16 D_0028D308[];
extern u16 D_0028D310[];
extern u16 D_0028D318[];

extern u16 player_shot_4_flight_table[];
extern u16 player_shot_4_impact_table[];

void player_shot_4_tables_init(void) {
    STORE_POINTER(D_0025D010 + 5, D_0025CE58);
    STORE_POINTER(D_0025D010 + 15, D_0028CE90);
    STORE_POINTER(D_0025D040 + 5, D_0025CE58);
    STORE_POINTER(D_0025D040 + 15, D_0028CE90);
    STORE_POINTER(D_0025D070 + 5, D_0025CE58);
    STORE_POINTER(D_0025D070 + 15, D_0028CE94);
    STORE_POINTER(D_0025D0A0 + 5, D_0025CE58);
    STORE_POINTER(D_0025D0A0 + 15, D_0028CE94);
    STORE_POINTER(D_0025D0D0 + 5, D_0025CE68);
    STORE_POINTER(D_0025D0D0 + 15, D_0028CE98);
    STORE_POINTER(D_0025D100 + 5, D_0025CE68);
    STORE_POINTER(D_0025D100 + 15, D_0028CE98);
    STORE_POINTER(D_0025D130 + 5, D_0025CE68);
    STORE_POINTER(D_0025D130 + 15, D_0028CE9C);
    STORE_POINTER(D_0025D160 + 5, D_0025CE68);
    STORE_POINTER(D_0025D160 + 15, D_0028CE9C);
    STORE_POINTER(D_0025D190 + 5, D_0025CE78);
    STORE_POINTER(D_0025D190 + 15, D_0028CEA0);
    STORE_POINTER(D_0025D1C0 + 5, D_0025CE78);
    STORE_POINTER(D_0025D1C0 + 15, D_0028CEA0);
    STORE_POINTER(D_0025D1F0 + 1, D_0025D4E0);
    STORE_POINTER(D_0025D1F0 + 5, D_0025CE88);
    STORE_POINTER(D_0025D220 + 1, D_0025D550);
    STORE_POINTER(D_0025D220 + 5, D_0025CE88);
    STORE_POINTER(D_0025D250 + 1, D_0025D5A0);
    STORE_POINTER(D_0025D250 + 5, D_0025CE98);
    STORE_POINTER(D_0025D280 + 1, D_0025D5F0);
    STORE_POINTER(D_0025D280 + 5, D_0025CE98);
    STORE_POINTER(D_0025D2B0 + 1, D_0025D640);
    STORE_POINTER(D_0025D2B0 + 5, D_0025CEA8);
    STORE_POINTER(D_0025D2E0 + 5, D_0025CEB8);
    STORE_POINTER(D_0025D2E0 + 15, D_0028CFF8);
    STORE_POINTER(D_0025D2E0 + 24, D_0025CEB8);
    STORE_POINTER(D_0025D2E0 + 34, D_0028CFF8);
    STORE_POINTER(D_0025D330 + 5, D_0025CEB8);
    STORE_POINTER(D_0025D330 + 15, D_0028CFFC);
    STORE_POINTER(D_0025D330 + 24, D_0025CEB8);
    STORE_POINTER(D_0025D330 + 34, D_0028CFFC);
    STORE_POINTER(D_0025D380 + 5, D_0025CEC8);
    STORE_POINTER(D_0025D380 + 15, D_0028D000);
    STORE_POINTER(D_0025D380 + 24, D_0025CEC8);
    STORE_POINTER(D_0025D380 + 34, D_0028D000);
    STORE_POINTER(D_0025D3D0 + 5, D_0025CEC8);
    STORE_POINTER(D_0025D3D0 + 15, D_0028D004);
    STORE_POINTER(D_0025D3D0 + 24, D_0025CEC8);
    STORE_POINTER(D_0025D3D0 + 34, D_0028D004);
    STORE_POINTER(D_0025D420 + 5, D_0025CED8);
    STORE_POINTER(D_0025D420 + 15, D_0028D008);
    STORE_POINTER(D_0025D420 + 24, D_0025CED8);
    STORE_POINTER(D_0025D420 + 34, D_0028D008);
    STORE_POINTER(player_shot_4_flight_table, player_shot_4_flight_00);
    STORE_POINTER(player_shot_4_flight_table + 2, player_shot_4_flight_00);
    STORE_POINTER(player_shot_4_flight_table + 4, player_shot_4_flight_02);
    STORE_POINTER(player_shot_4_flight_table + 6, player_shot_4_flight_02);
    STORE_POINTER(player_shot_4_flight_table + 8, player_shot_4_flight_04);
    STORE_POINTER(player_shot_4_flight_table + 10, player_shot_4_flight_04);
    STORE_POINTER(player_shot_4_flight_table + 12, player_shot_4_flight_06);
    STORE_POINTER(player_shot_4_flight_table + 14, player_shot_4_flight_06);
    STORE_POINTER(player_shot_4_flight_table + 16, player_shot_4_flight_08);
    STORE_POINTER(player_shot_4_flight_table + 18, player_shot_4_flight_08);
    STORE_POINTER(player_shot_4_flight_table + 20, player_shot_4_flight_10);
    STORE_POINTER(player_shot_4_flight_table + 22, player_shot_4_flight_11);
    STORE_POINTER(player_shot_4_flight_table + 24, player_shot_4_flight_12);
    STORE_POINTER(player_shot_4_flight_table + 26, player_shot_4_flight_13);
    STORE_POINTER(player_shot_4_flight_table + 28, player_shot_4_flight_14);
    STORE_POINTER(player_shot_4_flight_table + 30, player_shot_4_flight_15);
    STORE_POINTER(player_shot_4_flight_table + 32, player_shot_4_flight_15);
    STORE_POINTER(player_shot_4_flight_table + 34, player_shot_4_flight_17);
    STORE_POINTER(player_shot_4_flight_table + 36, player_shot_4_flight_17);
    STORE_POINTER(player_shot_4_flight_table + 38, player_shot_4_flight_19);
    STORE_POINTER(player_shot_4_flight_table + 40, player_shot_4_flight_19);
    STORE_POINTER(player_shot_4_flight_table + 42, player_shot_4_flight_21);
    STORE_POINTER(player_shot_4_flight_table + 44, player_shot_4_flight_21);
    STORE_POINTER(player_shot_4_flight_table + 46, player_shot_4_flight_23);
    STORE_POINTER(player_shot_4_flight_table + 48, player_shot_4_flight_23);
    STORE_POINTER(D_0025D4E0, D_0025D528);
    STORE_POINTER(D_0025D4E0 + 2, D_0028D088);
    STORE_POINTER(D_0025D4E0 + 4, D_0028D090);
    STORE_POINTER(D_0025D4E0 + 6, D_0028D098);
    STORE_POINTER(D_0025D4E0 + 8, D_0028D0A0);
    STORE_POINTER(D_0025D4E0 + 10, D_0028D0A8);
    STORE_POINTER(D_0025D4E0 + 12, D_0028D0B0);
    STORE_POINTER(D_0025D4E0 + 14, D_0028D0B8);
    STORE_POINTER(D_0025D4E0 + 16, D_0028D0C0);
    STORE_POINTER(D_0025D4E0 + 18, D_0028D0C8);
    STORE_POINTER(D_0025D4E0 + 20, D_0028D0D0);
    STORE_POINTER(D_0025D4E0 + 22, D_0028D0D8);
    STORE_POINTER(D_0025D4E0 + 24, D_0028D0E0);
    STORE_POINTER(D_0025D4E0 + 26, D_0025D538);
    STORE_POINTER(D_0025D4E0 + 28, D_0028D0E8);
    STORE_POINTER(D_0025D4E0 + 30, D_0028D0F0);
    STORE_POINTER(D_0025D4E0 + 32, D_0028D0F8);
    STORE_POINTER(D_0025D528 + 2, D_0028CEA4);
    STORE_POINTER(D_0028D088 + 2, D_0028CEA8);
    STORE_POINTER(D_0028D090 + 2, D_0028CEAC);
    STORE_POINTER(D_0028D098 + 2, D_0028CEB0);
    STORE_POINTER(D_0028D0A0 + 2, D_0028CEB4);
    STORE_POINTER(D_0028D0A8 + 2, D_0028CEB8);
    STORE_POINTER(D_0028D0B0 + 2, D_0028CEBC);
    STORE_POINTER(D_0028D0B8 + 2, D_0028CEC0);
    STORE_POINTER(D_0028D0C0 + 2, D_0028CEC4);
    STORE_POINTER(D_0028D0C8 + 2, D_0028CEC8);
    STORE_POINTER(D_0028D0D0 + 2, D_0028CECC);
    STORE_POINTER(D_0028D0D8 + 2, D_0028CED0);
    STORE_POINTER(D_0028D0E0 + 2, D_0028CED4);
    STORE_POINTER(D_0025D538 + 2, D_0028CED8);
    STORE_POINTER(D_0028D0E8 + 2, D_0028CEDC);
    STORE_POINTER(D_0028D0F0 + 2, D_0028CEE0);
    STORE_POINTER(D_0028D0F8 + 2, D_0028CEE4);
    STORE_POINTER(D_0025D550, D_0028D100);
    STORE_POINTER(D_0025D550 + 2, D_0028D108);
    STORE_POINTER(D_0025D550 + 4, D_0028D110);
    STORE_POINTER(D_0025D550 + 6, D_0028D118);
    STORE_POINTER(D_0025D550 + 8, D_0028D120);
    STORE_POINTER(D_0025D550 + 10, D_0028D128);
    STORE_POINTER(D_0025D550 + 12, D_0028D130);
    STORE_POINTER(D_0025D550 + 14, D_0028D138);
    STORE_POINTER(D_0025D550 + 16, D_0028D140);
    STORE_POINTER(D_0025D550 + 18, D_0028D148);
    STORE_POINTER(D_0025D550 + 20, D_0028D150);
    STORE_POINTER(D_0025D550 + 22, D_0028D158);
    STORE_POINTER(D_0025D550 + 24, D_0028D160);
    STORE_POINTER(D_0025D550 + 26, D_0028D168);
    STORE_POINTER(D_0025D550 + 28, D_0028D170);
    STORE_POINTER(D_0025D550 + 30, D_0028D178);
    STORE_POINTER(D_0025D550 + 32, D_0028D180);
    STORE_POINTER(D_0028D100 + 2, D_0028CEE8);
    STORE_POINTER(D_0028D108 + 2, D_0028CEEC);
    STORE_POINTER(D_0028D110 + 2, D_0028CEF0);
    STORE_POINTER(D_0028D118 + 2, D_0028CEF4);
    STORE_POINTER(D_0028D120 + 2, D_0028CEF8);
    STORE_POINTER(D_0028D128 + 2, D_0028CEFC);
    STORE_POINTER(D_0028D130 + 2, D_0028CF00);
    STORE_POINTER(D_0028D138 + 2, D_0028CF04);
    STORE_POINTER(D_0028D140 + 2, D_0028CF08);
    STORE_POINTER(D_0028D148 + 2, D_0028CF0C);
    STORE_POINTER(D_0028D150 + 2, D_0028CF10);
    STORE_POINTER(D_0028D158 + 2, D_0028CF14);
    STORE_POINTER(D_0028D160 + 2, D_0028CF18);
    STORE_POINTER(D_0028D168 + 2, D_0028CF1C);
    STORE_POINTER(D_0028D170 + 2, D_0028CF20);
    STORE_POINTER(D_0028D178 + 2, D_0028CF24);
    STORE_POINTER(D_0028D180 + 2, D_0028CF28);
    STORE_POINTER(D_0025D5A0, D_0028D188);
    STORE_POINTER(D_0025D5A0 + 2, D_0028D190);
    STORE_POINTER(D_0025D5A0 + 4, D_0028D198);
    STORE_POINTER(D_0025D5A0 + 6, D_0028D1A0);
    STORE_POINTER(D_0025D5A0 + 8, D_0028D1A8);
    STORE_POINTER(D_0025D5A0 + 10, D_0028D1B0);
    STORE_POINTER(D_0025D5A0 + 12, D_0028D1B8);
    STORE_POINTER(D_0025D5A0 + 14, D_0028D1C0);
    STORE_POINTER(D_0025D5A0 + 16, D_0028D1C8);
    STORE_POINTER(D_0025D5A0 + 18, D_0028D1D0);
    STORE_POINTER(D_0025D5A0 + 20, D_0028D1D8);
    STORE_POINTER(D_0025D5A0 + 22, D_0028D1E0);
    STORE_POINTER(D_0025D5A0 + 24, D_0028D1E8);
    STORE_POINTER(D_0025D5A0 + 26, D_0028D1F0);
    STORE_POINTER(D_0025D5A0 + 28, D_0028D1F8);
    STORE_POINTER(D_0025D5A0 + 30, D_0028D200);
    STORE_POINTER(D_0025D5A0 + 32, D_0028D208);
    STORE_POINTER(D_0028D188 + 2, D_0028CF2C);
    STORE_POINTER(D_0028D190 + 2, D_0028CF30);
    STORE_POINTER(D_0028D198 + 2, D_0028CF34);
    STORE_POINTER(D_0028D1A0 + 2, D_0028CF38);
    STORE_POINTER(D_0028D1A8 + 2, D_0028CF3C);
    STORE_POINTER(D_0028D1B0 + 2, D_0028CF40);
    STORE_POINTER(D_0028D1B8 + 2, D_0028CF44);
    STORE_POINTER(D_0028D1C0 + 2, D_0028CF48);
    STORE_POINTER(D_0028D1C8 + 2, D_0028CF4C);
    STORE_POINTER(D_0028D1D0 + 2, D_0028CF50);
    STORE_POINTER(D_0028D1D8 + 2, D_0028CF54);
    STORE_POINTER(D_0028D1E0 + 2, D_0028CF58);
    STORE_POINTER(D_0028D1E8 + 2, D_0028CF5C);
    STORE_POINTER(D_0028D1F0 + 2, D_0028CF60);
    STORE_POINTER(D_0028D1F8 + 2, D_0028CF64);
    STORE_POINTER(D_0028D200 + 2, D_0028CF68);
    STORE_POINTER(D_0028D208 + 2, D_0028CF6C);
    STORE_POINTER(D_0025D5F0, D_0028D210);
    STORE_POINTER(D_0025D5F0 + 2, D_0028D218);
    STORE_POINTER(D_0025D5F0 + 4, D_0028D220);
    STORE_POINTER(D_0025D5F0 + 6, D_0028D228);
    STORE_POINTER(D_0025D5F0 + 8, D_0028D230);
    STORE_POINTER(D_0025D5F0 + 10, D_0028D238);
    STORE_POINTER(D_0025D5F0 + 12, D_0028D240);
    STORE_POINTER(D_0025D5F0 + 14, D_0028D248);
    STORE_POINTER(D_0025D5F0 + 16, D_0028D250);
    STORE_POINTER(D_0025D5F0 + 18, D_0028D258);
    STORE_POINTER(D_0025D5F0 + 20, D_0028D260);
    STORE_POINTER(D_0025D5F0 + 22, D_0028D268);
    STORE_POINTER(D_0025D5F0 + 24, D_0028D270);
    STORE_POINTER(D_0025D5F0 + 26, D_0028D278);
    STORE_POINTER(D_0025D5F0 + 28, D_0028D280);
    STORE_POINTER(D_0025D5F0 + 30, D_0028D288);
    STORE_POINTER(D_0025D5F0 + 32, D_0028D290);
    STORE_POINTER(D_0028D210 + 2, D_0028CF70);
    STORE_POINTER(D_0028D218 + 2, D_0028CF74);
    STORE_POINTER(D_0028D220 + 2, D_0028CF78);
    STORE_POINTER(D_0028D228 + 2, D_0028CF7C);
    STORE_POINTER(D_0028D230 + 2, D_0028CF80);
    STORE_POINTER(D_0028D238 + 2, D_0028CF84);
    STORE_POINTER(D_0028D240 + 2, D_0028CF88);
    STORE_POINTER(D_0028D248 + 2, D_0028CF8C);
    STORE_POINTER(D_0028D250 + 2, D_0028CF90);
    STORE_POINTER(D_0028D258 + 2, D_0028CF94);
    STORE_POINTER(D_0028D260 + 2, D_0028CF98);
    STORE_POINTER(D_0028D268 + 2, D_0028CF9C);
    STORE_POINTER(D_0028D270 + 2, D_0028CFA0);
    STORE_POINTER(D_0028D278 + 2, D_0028CFA4);
    STORE_POINTER(D_0028D280 + 2, D_0028CFA8);
    STORE_POINTER(D_0028D288 + 2, D_0028CFAC);
    STORE_POINTER(D_0028D290 + 2, D_0028CFB0);
    STORE_POINTER(D_0025D640, D_0028D298);
    STORE_POINTER(D_0025D640 + 2, D_0028D2A0);
    STORE_POINTER(D_0025D640 + 4, D_0028D2A8);
    STORE_POINTER(D_0025D640 + 6, D_0028D2B0);
    STORE_POINTER(D_0025D640 + 8, D_0028D2B8);
    STORE_POINTER(D_0025D640 + 10, D_0028D2C0);
    STORE_POINTER(D_0025D640 + 12, D_0028D2C8);
    STORE_POINTER(D_0025D640 + 14, D_0028D2D0);
    STORE_POINTER(D_0025D640 + 16, D_0028D2D8);
    STORE_POINTER(D_0025D640 + 18, D_0028D2E0);
    STORE_POINTER(D_0025D640 + 20, D_0028D2E8);
    STORE_POINTER(D_0025D640 + 22, D_0028D2F0);
    STORE_POINTER(D_0025D640 + 24, D_0028D2F8);
    STORE_POINTER(D_0025D640 + 26, D_0028D300);
    STORE_POINTER(D_0025D640 + 28, D_0028D308);
    STORE_POINTER(D_0025D640 + 30, D_0028D310);
    STORE_POINTER(D_0025D640 + 32, D_0028D318);
    STORE_POINTER(D_0028D298 + 2, D_0028CFB4);
    STORE_POINTER(D_0028D2A0 + 2, D_0028CFB8);
    STORE_POINTER(D_0028D2A8 + 2, D_0028CFBC);
    STORE_POINTER(D_0028D2B0 + 2, D_0028CFC0);
    STORE_POINTER(D_0028D2B8 + 2, D_0028CFC4);
    STORE_POINTER(D_0028D2C0 + 2, D_0028CFC8);
    STORE_POINTER(D_0028D2C8 + 2, D_0028CFCC);
    STORE_POINTER(D_0028D2D0 + 2, D_0028CFD0);
    STORE_POINTER(D_0028D2D8 + 2, D_0028CFD4);
    STORE_POINTER(D_0028D2E0 + 2, D_0028CFD8);
    STORE_POINTER(D_0028D2E8 + 2, D_0028CFDC);
    STORE_POINTER(D_0028D2F0 + 2, D_0028CFE0);
    STORE_POINTER(D_0028D2F8 + 2, D_0028CFE4);
    STORE_POINTER(D_0028D300 + 2, D_0028CFE8);
    STORE_POINTER(D_0028D308 + 2, D_0028CFEC);
    STORE_POINTER(D_0028D310 + 2, D_0028CFF0);
    STORE_POINTER(D_0028D318 + 2, D_0028CFF4);
    STORE_POINTER(player_shot_4_impact_table, player_shot_4_impact_00);
    STORE_POINTER(player_shot_4_impact_table + 2, player_shot_4_impact_00);
    STORE_POINTER(player_shot_4_impact_table + 4, player_shot_4_impact_02);
    STORE_POINTER(player_shot_4_impact_table + 6, player_shot_4_impact_02);
    STORE_POINTER(player_shot_4_impact_table + 8, player_shot_4_impact_04);
    STORE_POINTER(player_shot_4_impact_table + 10, player_shot_4_impact_04);
    STORE_POINTER(player_shot_4_impact_table + 12, player_shot_4_impact_06);
    STORE_POINTER(player_shot_4_impact_table + 14, player_shot_4_impact_06);
    STORE_POINTER(player_shot_4_impact_table + 16, player_shot_4_impact_08);
    STORE_POINTER(player_shot_4_impact_table + 18, player_shot_4_impact_08);
    STORE_POINTER(player_shot_4_impact_table + 20, player_shot_4_impact_10);
    STORE_POINTER(player_shot_4_impact_table + 22, player_shot_4_impact_11);
    STORE_POINTER(player_shot_4_impact_table + 24, player_shot_4_impact_12);
    STORE_POINTER(player_shot_4_impact_table + 26, player_shot_4_impact_13);
    STORE_POINTER(player_shot_4_impact_table + 28, player_shot_4_impact_14);
    STORE_POINTER(player_shot_4_impact_table + 30, player_shot_4_impact_15);
    STORE_POINTER(player_shot_4_impact_table + 32, player_shot_4_impact_15);
    STORE_POINTER(player_shot_4_impact_table + 34, player_shot_4_impact_17);
    STORE_POINTER(player_shot_4_impact_table + 36, player_shot_4_impact_17);
    STORE_POINTER(player_shot_4_impact_table + 38, player_shot_4_impact_19);
    STORE_POINTER(player_shot_4_impact_table + 40, player_shot_4_impact_19);
    STORE_POINTER(player_shot_4_impact_table + 42, player_shot_4_impact_21);
    STORE_POINTER(player_shot_4_impact_table + 44, player_shot_4_impact_21);
    STORE_POINTER(player_shot_4_impact_table + 46, player_shot_4_impact_23);
    STORE_POINTER(player_shot_4_impact_table + 48, player_shot_4_impact_23);
    STORE_POINTER(player_shot_4_impact_00 + 3, player_shot_4_impact_frames_00);
    STORE_POINTER(player_shot_4_impact_02 + 3, player_shot_4_impact_frames_00);
    STORE_POINTER(player_shot_4_impact_04 + 3, player_shot_4_impact_frames_04);
    STORE_POINTER(player_shot_4_impact_06 + 3, player_shot_4_impact_frames_04);
    STORE_POINTER(player_shot_4_impact_08 + 3, player_shot_4_impact_frames_08);
    STORE_POINTER(player_shot_4_impact_10 + 3, player_shot_4_impact_frames_10);
    STORE_POINTER(player_shot_4_impact_11 + 3, player_shot_4_impact_frames_10);
    STORE_POINTER(player_shot_4_impact_12 + 3, player_shot_4_impact_frames_12);
    STORE_POINTER(player_shot_4_impact_13 + 3, player_shot_4_impact_frames_12);
    STORE_POINTER(player_shot_4_impact_14 + 3, player_shot_4_impact_frames_14);
    STORE_POINTER(player_shot_4_impact_15 + 3, player_shot_4_impact_frames_15);
    STORE_POINTER(player_shot_4_impact_17 + 3, player_shot_4_impact_frames_15);
    STORE_POINTER(player_shot_4_impact_19 + 3, player_shot_4_impact_frames_19);
    STORE_POINTER(player_shot_4_impact_21 + 3, player_shot_4_impact_frames_19);
    STORE_POINTER(player_shot_4_impact_23 + 3, player_shot_4_impact_frames_23);
}

extern u16 D_0025E170[];
extern u16 D_0025E180[];
extern u16 D_0025E190[];
extern u16 D_0025E1A0[];
extern u16 D_0025E1B0[];
extern u16 D_0025E1C0[];
extern u16 D_0025E1D0[];
extern u16 D_0025E1E0[];
extern u16 D_0025E1F0[];
extern u16 D_0025E200[];
extern u16 player_shot_8_impact_frames_00[];
extern u16 player_shot_8_impact_frames_02[];
extern u16 player_shot_8_impact_frames_06[];
extern u16 player_shot_8_impact_frames_10[];
extern u16 player_shot_8_impact_frames_11[];
extern u16 player_shot_8_impact_frames_13[];
extern u16 player_shot_8_impact_frames_15[];
extern u16 player_shot_8_impact_frames_17[];
extern u16 player_shot_8_impact_frames_21[];
extern u16 D_0025E940[];
extern u16 player_shot_8_impact_00[];
extern u16 player_shot_8_impact_02[];
extern u16 player_shot_8_impact_04[];
extern u16 player_shot_8_impact_06[];
extern u16 player_shot_8_impact_08[];
extern u16 player_shot_8_impact_10[];
extern u16 player_shot_8_impact_11[];
extern u16 player_shot_8_impact_12[];
extern u16 player_shot_8_impact_13[];
extern u16 player_shot_8_impact_14[];
extern u16 player_shot_8_impact_15[];
extern u16 player_shot_8_impact_17[];
extern u16 player_shot_8_impact_19[];
extern u16 player_shot_8_impact_21[];
extern u16 player_shot_8_impact_23[];
extern u16 player_shot_8_flight_000[];
extern u16 player_shot_8_flight_002[];
extern u16 player_shot_8_flight_004[];
extern u16 player_shot_8_flight_006[];
extern u16 player_shot_8_flight_008[];
extern u16 player_shot_8_flight_010[];
extern u16 player_shot_8_flight_011[];
extern u16 player_shot_8_flight_012[];
extern u16 player_shot_8_flight_013[];
extern u16 player_shot_8_flight_014[];
extern u16 player_shot_8_flight_015[];
extern u16 player_shot_8_flight_017[];
extern u16 player_shot_8_flight_019[];
extern u16 player_shot_8_flight_021[];
extern u16 player_shot_8_flight_023[];
extern u16 player_shot_8_flight_028[];
extern u16 player_shot_8_flight_029[];
extern u16 player_shot_8_flight_030[];
extern u16 player_shot_8_flight_031[];
extern u16 player_shot_8_flight_032[];
extern u16 player_shot_8_flight_033[];
extern u16 player_shot_8_flight_034[];
extern u16 player_shot_8_flight_035[];
extern u16 player_shot_8_flight_036[];
extern u16 player_shot_8_flight_037[];
extern u16 player_shot_8_flight_038[];
extern u16 player_shot_8_flight_039[];
extern u16 player_shot_8_flight_040[];
extern u16 player_shot_8_flight_041[];
extern u16 player_shot_8_flight_042[];
extern u16 player_shot_8_flight_043[];
extern u16 player_shot_8_flight_044[];
extern u16 player_shot_8_flight_048[];
extern u16 player_shot_8_flight_049[];
extern u16 player_shot_8_flight_050[];
extern u16 player_shot_8_flight_051[];
extern u16 player_shot_8_flight_052[];
extern u16 player_shot_8_flight_053[];
extern u16 player_shot_8_flight_054[];
extern u16 player_shot_8_flight_055[];
extern u16 player_shot_8_flight_056[];
extern u16 player_shot_8_flight_057[];
extern u16 player_shot_8_flight_058[];
extern u16 player_shot_8_flight_059[];
extern u16 player_shot_8_flight_060[];
extern u16 player_shot_8_flight_061[];
extern u16 player_shot_8_flight_062[];
extern u16 player_shot_8_flight_063[];
extern u16 player_shot_8_flight_064[];
extern u16 player_shot_8_flight_068[];
extern u16 player_shot_8_flight_069[];
extern u16 player_shot_8_flight_070[];
extern u16 player_shot_8_flight_071[];
extern u16 player_shot_8_flight_072[];
extern u16 player_shot_8_flight_073[];
extern u16 player_shot_8_flight_074[];
extern u16 player_shot_8_flight_075[];
extern u16 player_shot_8_flight_076[];
extern u16 player_shot_8_flight_077[];
extern u16 player_shot_8_flight_078[];
extern u16 player_shot_8_flight_079[];
extern u16 player_shot_8_flight_080[];
extern u16 player_shot_8_flight_081[];
extern u16 player_shot_8_flight_082[];
extern u16 player_shot_8_flight_083[];
extern u16 player_shot_8_flight_084[];
extern u16 player_shot_8_flight_088[];
extern u16 player_shot_8_flight_089[];
extern u16 player_shot_8_flight_090[];
extern u16 player_shot_8_flight_091[];
extern u16 player_shot_8_flight_092[];
extern u16 player_shot_8_flight_093[];
extern u16 player_shot_8_flight_094[];
extern u16 player_shot_8_flight_095[];
extern u16 player_shot_8_flight_096[];
extern u16 player_shot_8_flight_097[];
extern u16 player_shot_8_flight_098[];
extern u16 player_shot_8_flight_099[];
extern u16 player_shot_8_flight_100[];
extern u16 player_shot_8_flight_101[];
extern u16 player_shot_8_flight_102[];
extern u16 player_shot_8_flight_103[];
extern u16 player_shot_8_flight_104[];
extern u16 D_0028D8D8[];
extern u16 D_0028D8E0[];
extern u16 D_0028D8E8[];
extern u16 D_0028D8F0[];
extern u16 D_0028D8F8[];
extern u16 D_0028D900[];
extern u16 D_0028D908[];
extern u16 D_0028D910[];
extern u16 D_0028D918[];
extern u16 D_0028D920[];
extern u16 D_0028D928[];
extern u16 D_0028D930[];
extern u16 D_0028D938[];
extern u16 D_0028D940[];
extern u16 D_0028D948[];
extern u16 D_0028D950[];
extern u16 D_0028D958[];

extern u16 player_shot_8_flight_table[];
extern u16 player_shot_8_impact_table[];

void player_shot_8_tables_init(void) {
    STORE_POINTER(D_0025E330 + 5, D_0025E170);
    STORE_POINTER(D_0025E330 + 15, D_0025E1A0);
    STORE_POINTER(D_0025E360 + 5, D_0025E170);
    STORE_POINTER(D_0025E360 + 15, D_0025E1A0);
    STORE_POINTER(D_0025E390 + 5, D_0025E170);
    STORE_POINTER(D_0025E390 + 15, D_0025E1A0);
    STORE_POINTER(D_0025E3C0 + 5, D_0025E170);
    STORE_POINTER(D_0025E3C0 + 15, D_0025E1A0);
    STORE_POINTER(D_0025E3F0 + 5, D_0025E170);
    STORE_POINTER(D_0025E3F0 + 15, D_0025E1A0);
    STORE_POINTER(D_0025E420 + 5, D_0025E170);
    STORE_POINTER(D_0025E420 + 15, D_0025E1A0);
    STORE_POINTER(D_0025E450 + 5, D_0025E170);
    STORE_POINTER(D_0025E450 + 15, D_0025E1A0);
    STORE_POINTER(D_0025E480 + 5, D_0025E170);
    STORE_POINTER(D_0025E480 + 15, D_0025E1A0);
    STORE_POINTER(D_0025E4B0 + 5, D_0025E170);
    STORE_POINTER(D_0025E4B0 + 15, D_0025E1A0);
    STORE_POINTER(D_0025E4E0 + 5, D_0025E170);
    STORE_POINTER(D_0025E4E0 + 15, D_0025E1A0);
    STORE_POINTER(D_0025E510 + 1, D_0025E940);
    STORE_POINTER(D_0025E510 + 5, D_0025E180);
    STORE_POINTER(D_0025E540 + 1, D_0025E940);
    STORE_POINTER(D_0025E540 + 5, D_0025E180);
    STORE_POINTER(D_0025E570 + 1, D_0025E940);
    STORE_POINTER(D_0025E570 + 5, D_0025E180);
    STORE_POINTER(D_0025E5A0 + 1, D_0025E940);
    STORE_POINTER(D_0025E5A0 + 5, D_0025E180);
    STORE_POINTER(D_0025E5D0 + 1, D_0025E940);
    STORE_POINTER(D_0025E5D0 + 5, D_0025E180);
    STORE_POINTER(D_0025E600 + 5, D_0025E190);
    STORE_POINTER(D_0025E600 + 15, D_0025E200);
    STORE_POINTER(D_0025E600 + 24, D_0025E190);
    STORE_POINTER(D_0025E600 + 34, D_0025E200);
    STORE_POINTER(D_0025E650 + 5, D_0025E190);
    STORE_POINTER(D_0025E650 + 15, D_0025E200);
    STORE_POINTER(D_0025E650 + 24, D_0025E190);
    STORE_POINTER(D_0025E650 + 34, D_0025E200);
    STORE_POINTER(D_0025E6A0 + 5, D_0025E190);
    STORE_POINTER(D_0025E6A0 + 15, D_0025E200);
    STORE_POINTER(D_0025E6A0 + 24, D_0025E190);
    STORE_POINTER(D_0025E6A0 + 34, D_0025E200);
    STORE_POINTER(D_0025E6F0 + 5, D_0025E190);
    STORE_POINTER(D_0025E6F0 + 15, D_0025E200);
    STORE_POINTER(D_0025E6F0 + 24, D_0025E190);
    STORE_POINTER(D_0025E6F0 + 34, D_0025E200);
    STORE_POINTER(D_0025E740 + 5, D_0025E190);
    STORE_POINTER(D_0025E740 + 15, D_0025E200);
    STORE_POINTER(D_0025E740 + 24, D_0025E190);
    STORE_POINTER(D_0025E740 + 34, D_0025E200);
    STORE_POINTER(player_shot_8_flight_table, player_shot_8_flight_000);
    STORE_POINTER(player_shot_8_flight_table + 2, player_shot_8_flight_000);
    STORE_POINTER(player_shot_8_flight_table + 4, player_shot_8_flight_002);
    STORE_POINTER(player_shot_8_flight_table + 6, player_shot_8_flight_002);
    STORE_POINTER(player_shot_8_flight_table + 8, player_shot_8_flight_004);
    STORE_POINTER(player_shot_8_flight_table + 10, player_shot_8_flight_004);
    STORE_POINTER(player_shot_8_flight_table + 12, player_shot_8_flight_006);
    STORE_POINTER(player_shot_8_flight_table + 14, player_shot_8_flight_006);
    STORE_POINTER(player_shot_8_flight_table + 16, player_shot_8_flight_008);
    STORE_POINTER(player_shot_8_flight_table + 18, player_shot_8_flight_008);
    STORE_POINTER(player_shot_8_flight_table + 20, player_shot_8_flight_010);
    STORE_POINTER(player_shot_8_flight_table + 22, player_shot_8_flight_011);
    STORE_POINTER(player_shot_8_flight_table + 24, player_shot_8_flight_012);
    STORE_POINTER(player_shot_8_flight_table + 26, player_shot_8_flight_013);
    STORE_POINTER(player_shot_8_flight_table + 28, player_shot_8_flight_014);
    STORE_POINTER(player_shot_8_flight_table + 30, player_shot_8_flight_015);
    STORE_POINTER(player_shot_8_flight_table + 32, player_shot_8_flight_015);
    STORE_POINTER(player_shot_8_flight_table + 34, player_shot_8_flight_017);
    STORE_POINTER(player_shot_8_flight_table + 36, player_shot_8_flight_017);
    STORE_POINTER(player_shot_8_flight_table + 38, player_shot_8_flight_019);
    STORE_POINTER(player_shot_8_flight_table + 40, player_shot_8_flight_019);
    STORE_POINTER(player_shot_8_flight_table + 42, player_shot_8_flight_021);
    STORE_POINTER(player_shot_8_flight_table + 44, player_shot_8_flight_021);
    STORE_POINTER(player_shot_8_flight_table + 46, player_shot_8_flight_023);
    STORE_POINTER(player_shot_8_flight_table + 48, player_shot_8_flight_023);
    STORE_POINTER(player_shot_8_flight_table + 56, player_shot_8_flight_028);
    STORE_POINTER(player_shot_8_flight_table + 58, player_shot_8_flight_029);
    STORE_POINTER(player_shot_8_flight_table + 60, player_shot_8_flight_030);
    STORE_POINTER(player_shot_8_flight_table + 62, player_shot_8_flight_031);
    STORE_POINTER(player_shot_8_flight_table + 64, player_shot_8_flight_032);
    STORE_POINTER(player_shot_8_flight_table + 66, player_shot_8_flight_033);
    STORE_POINTER(player_shot_8_flight_table + 68, player_shot_8_flight_034);
    STORE_POINTER(player_shot_8_flight_table + 70, player_shot_8_flight_035);
    STORE_POINTER(player_shot_8_flight_table + 72, player_shot_8_flight_036);
    STORE_POINTER(player_shot_8_flight_table + 74, player_shot_8_flight_037);
    STORE_POINTER(player_shot_8_flight_table + 76, player_shot_8_flight_038);
    STORE_POINTER(player_shot_8_flight_table + 78, player_shot_8_flight_039);
    STORE_POINTER(player_shot_8_flight_table + 80, player_shot_8_flight_040);
    STORE_POINTER(player_shot_8_flight_table + 82, player_shot_8_flight_041);
    STORE_POINTER(player_shot_8_flight_table + 84, player_shot_8_flight_042);
    STORE_POINTER(player_shot_8_flight_table + 86, player_shot_8_flight_043);
    STORE_POINTER(player_shot_8_flight_table + 88, player_shot_8_flight_044);
    STORE_POINTER(player_shot_8_flight_028 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_029 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_030 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_031 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_032 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_033 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_034 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_035 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_036 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_037 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_038 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_039 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_040 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_041 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_042 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_043 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_044 + 2, D_0025E1B0);
    STORE_POINTER(player_shot_8_flight_table + 96, player_shot_8_flight_048);
    STORE_POINTER(player_shot_8_flight_table + 98, player_shot_8_flight_049);
    STORE_POINTER(player_shot_8_flight_table + 100, player_shot_8_flight_050);
    STORE_POINTER(player_shot_8_flight_table + 102, player_shot_8_flight_051);
    STORE_POINTER(player_shot_8_flight_table + 104, player_shot_8_flight_052);
    STORE_POINTER(player_shot_8_flight_table + 106, player_shot_8_flight_053);
    STORE_POINTER(player_shot_8_flight_table + 108, player_shot_8_flight_054);
    STORE_POINTER(player_shot_8_flight_table + 110, player_shot_8_flight_055);
    STORE_POINTER(player_shot_8_flight_table + 112, player_shot_8_flight_056);
    STORE_POINTER(player_shot_8_flight_table + 114, player_shot_8_flight_057);
    STORE_POINTER(player_shot_8_flight_table + 116, player_shot_8_flight_058);
    STORE_POINTER(player_shot_8_flight_table + 118, player_shot_8_flight_059);
    STORE_POINTER(player_shot_8_flight_table + 120, player_shot_8_flight_060);
    STORE_POINTER(player_shot_8_flight_table + 122, player_shot_8_flight_061);
    STORE_POINTER(player_shot_8_flight_table + 124, player_shot_8_flight_062);
    STORE_POINTER(player_shot_8_flight_table + 126, player_shot_8_flight_063);
    STORE_POINTER(player_shot_8_flight_table + 128, player_shot_8_flight_064);
    STORE_POINTER(player_shot_8_flight_048 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_049 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_050 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_051 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_052 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_053 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_054 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_055 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_056 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_057 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_058 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_059 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_060 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_061 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_062 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_063 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_064 + 2, D_0025E1C0);
    STORE_POINTER(player_shot_8_flight_table + 136, player_shot_8_flight_068);
    STORE_POINTER(player_shot_8_flight_table + 138, player_shot_8_flight_069);
    STORE_POINTER(player_shot_8_flight_table + 140, player_shot_8_flight_070);
    STORE_POINTER(player_shot_8_flight_table + 142, player_shot_8_flight_071);
    STORE_POINTER(player_shot_8_flight_table + 144, player_shot_8_flight_072);
    STORE_POINTER(player_shot_8_flight_table + 146, player_shot_8_flight_073);
    STORE_POINTER(player_shot_8_flight_table + 148, player_shot_8_flight_074);
    STORE_POINTER(player_shot_8_flight_table + 150, player_shot_8_flight_075);
    STORE_POINTER(player_shot_8_flight_table + 152, player_shot_8_flight_076);
    STORE_POINTER(player_shot_8_flight_table + 154, player_shot_8_flight_077);
    STORE_POINTER(player_shot_8_flight_table + 156, player_shot_8_flight_078);
    STORE_POINTER(player_shot_8_flight_table + 158, player_shot_8_flight_079);
    STORE_POINTER(player_shot_8_flight_table + 160, player_shot_8_flight_080);
    STORE_POINTER(player_shot_8_flight_table + 162, player_shot_8_flight_081);
    STORE_POINTER(player_shot_8_flight_table + 164, player_shot_8_flight_082);
    STORE_POINTER(player_shot_8_flight_table + 166, player_shot_8_flight_083);
    STORE_POINTER(player_shot_8_flight_table + 168, player_shot_8_flight_084);
    STORE_POINTER(player_shot_8_flight_068 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_069 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_070 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_071 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_072 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_073 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_074 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_075 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_076 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_077 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_078 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_079 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_080 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_081 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_082 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_083 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_084 + 2, D_0025E1D0);
    STORE_POINTER(player_shot_8_flight_table + 176, player_shot_8_flight_088);
    STORE_POINTER(player_shot_8_flight_table + 178, player_shot_8_flight_089);
    STORE_POINTER(player_shot_8_flight_table + 180, player_shot_8_flight_090);
    STORE_POINTER(player_shot_8_flight_table + 182, player_shot_8_flight_091);
    STORE_POINTER(player_shot_8_flight_table + 184, player_shot_8_flight_092);
    STORE_POINTER(player_shot_8_flight_table + 186, player_shot_8_flight_093);
    STORE_POINTER(player_shot_8_flight_table + 188, player_shot_8_flight_094);
    STORE_POINTER(player_shot_8_flight_table + 190, player_shot_8_flight_095);
    STORE_POINTER(player_shot_8_flight_table + 192, player_shot_8_flight_096);
    STORE_POINTER(player_shot_8_flight_table + 194, player_shot_8_flight_097);
    STORE_POINTER(player_shot_8_flight_table + 196, player_shot_8_flight_098);
    STORE_POINTER(player_shot_8_flight_table + 198, player_shot_8_flight_099);
    STORE_POINTER(player_shot_8_flight_table + 200, player_shot_8_flight_100);
    STORE_POINTER(player_shot_8_flight_table + 202, player_shot_8_flight_101);
    STORE_POINTER(player_shot_8_flight_table + 204, player_shot_8_flight_102);
    STORE_POINTER(player_shot_8_flight_table + 206, player_shot_8_flight_103);
    STORE_POINTER(player_shot_8_flight_table + 208, player_shot_8_flight_104);
    STORE_POINTER(player_shot_8_flight_088 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_089 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_090 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_091 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_092 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_093 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_094 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_095 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_096 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_097 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_098 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_099 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_100 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_101 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_102 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_103 + 2, D_0025E1E0);
    STORE_POINTER(player_shot_8_flight_104 + 2, D_0025E1E0);
    STORE_POINTER(D_0025E940, D_0028D8D8);
    STORE_POINTER(D_0025E940 + 2, D_0028D8E0);
    STORE_POINTER(D_0025E940 + 4, D_0028D8E8);
    STORE_POINTER(D_0025E940 + 6, D_0028D8F0);
    STORE_POINTER(D_0025E940 + 8, D_0028D8F8);
    STORE_POINTER(D_0025E940 + 10, D_0028D900);
    STORE_POINTER(D_0025E940 + 12, D_0028D908);
    STORE_POINTER(D_0025E940 + 14, D_0028D910);
    STORE_POINTER(D_0025E940 + 16, D_0028D918);
    STORE_POINTER(D_0025E940 + 18, D_0028D920);
    STORE_POINTER(D_0025E940 + 20, D_0028D928);
    STORE_POINTER(D_0025E940 + 22, D_0028D930);
    STORE_POINTER(D_0025E940 + 24, D_0028D938);
    STORE_POINTER(D_0025E940 + 26, D_0028D940);
    STORE_POINTER(D_0025E940 + 28, D_0028D948);
    STORE_POINTER(D_0025E940 + 30, D_0028D950);
    STORE_POINTER(D_0025E940 + 32, D_0028D958);
    STORE_POINTER(D_0028D8D8 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D8E0 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D8E8 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D8F0 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D8F8 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D900 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D908 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D910 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D918 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D920 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D928 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D930 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D938 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D940 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D948 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D950 + 2, D_0025E1F0);
    STORE_POINTER(D_0028D958 + 2, D_0025E1F0);
    STORE_POINTER(player_shot_8_impact_table, player_shot_8_impact_00);
    STORE_POINTER(player_shot_8_impact_table + 2, player_shot_8_impact_00);
    STORE_POINTER(player_shot_8_impact_table + 4, player_shot_8_impact_02);
    STORE_POINTER(player_shot_8_impact_table + 6, player_shot_8_impact_02);
    STORE_POINTER(player_shot_8_impact_table + 8, player_shot_8_impact_04);
    STORE_POINTER(player_shot_8_impact_table + 10, player_shot_8_impact_04);
    STORE_POINTER(player_shot_8_impact_table + 12, player_shot_8_impact_06);
    STORE_POINTER(player_shot_8_impact_table + 14, player_shot_8_impact_06);
    STORE_POINTER(player_shot_8_impact_table + 16, player_shot_8_impact_08);
    STORE_POINTER(player_shot_8_impact_table + 18, player_shot_8_impact_08);
    STORE_POINTER(player_shot_8_impact_table + 20, player_shot_8_impact_10);
    STORE_POINTER(player_shot_8_impact_table + 22, player_shot_8_impact_11);
    STORE_POINTER(player_shot_8_impact_table + 24, player_shot_8_impact_12);
    STORE_POINTER(player_shot_8_impact_table + 26, player_shot_8_impact_13);
    STORE_POINTER(player_shot_8_impact_table + 28, player_shot_8_impact_14);
    STORE_POINTER(player_shot_8_impact_table + 30, player_shot_8_impact_15);
    STORE_POINTER(player_shot_8_impact_table + 32, player_shot_8_impact_15);
    STORE_POINTER(player_shot_8_impact_table + 34, player_shot_8_impact_17);
    STORE_POINTER(player_shot_8_impact_table + 36, player_shot_8_impact_17);
    STORE_POINTER(player_shot_8_impact_table + 38, player_shot_8_impact_19);
    STORE_POINTER(player_shot_8_impact_table + 40, player_shot_8_impact_19);
    STORE_POINTER(player_shot_8_impact_table + 42, player_shot_8_impact_21);
    STORE_POINTER(player_shot_8_impact_table + 44, player_shot_8_impact_21);
    STORE_POINTER(player_shot_8_impact_table + 46, player_shot_8_impact_23);
    STORE_POINTER(player_shot_8_impact_table + 48, player_shot_8_impact_23);
    STORE_POINTER(player_shot_8_impact_00 + 3, player_shot_8_impact_frames_00);
    STORE_POINTER(player_shot_8_impact_02 + 3, player_shot_8_impact_frames_02);
    STORE_POINTER(player_shot_8_impact_04 + 3, player_shot_8_impact_frames_02);
    STORE_POINTER(player_shot_8_impact_06 + 3, player_shot_8_impact_frames_06);
    STORE_POINTER(player_shot_8_impact_08 + 3, player_shot_8_impact_frames_06);
    STORE_POINTER(player_shot_8_impact_10 + 3, player_shot_8_impact_frames_10);
    STORE_POINTER(player_shot_8_impact_11 + 3, player_shot_8_impact_frames_11);
    STORE_POINTER(player_shot_8_impact_12 + 3, player_shot_8_impact_frames_11);
    STORE_POINTER(player_shot_8_impact_13 + 3, player_shot_8_impact_frames_13);
    STORE_POINTER(player_shot_8_impact_14 + 3, player_shot_8_impact_frames_13);
    STORE_POINTER(player_shot_8_impact_15 + 3, player_shot_8_impact_frames_15);
    STORE_POINTER(player_shot_8_impact_17 + 3, player_shot_8_impact_frames_17);
    STORE_POINTER(player_shot_8_impact_19 + 3, player_shot_8_impact_frames_17);
    STORE_POINTER(player_shot_8_impact_21 + 3, player_shot_8_impact_frames_21);
    STORE_POINTER(player_shot_8_impact_23 + 3, player_shot_8_impact_frames_21);
}

extern u16 ship0_shot_list_1_00_00[];
extern u16 ship0_shot_list_2_00_00[];
extern u16 ship0_shot_list_1_00_01[];
extern u16 ship0_shot_list_2_00_01[];
extern u16 ship0_shot_list_1_00_02[];
extern u16 ship0_shot_list_2_00_02[];
extern u16 ship0_shot_list_1_00_03[];
extern u16 ship0_shot_list_2_00_03[];
extern u16 ship0_shot_list_1_00_04[];
extern u16 ship0_shot_list_2_00_04[];
extern u16 ship0_shot_list_1_02_00[];
extern u16 ship0_shot_list_1_02_01[];
extern u16 ship0_shot_list_1_02_02[];
extern u16 ship0_shot_list_1_02_03[];
extern u16 ship0_shot_list_1_02_04[];
extern u16 ship0_shot_list_1_04_00[];
extern u16 ship0_shot_list_2_04_00[];
extern u16 ship0_shot_list_1_04_01[];
extern u16 ship0_shot_list_2_04_01[];
extern u16 ship0_shot_list_1_04_02[];
extern u16 ship0_shot_list_2_04_02[];
extern u16 ship0_shot_list_1_04_03[];
extern u16 ship0_shot_list_2_04_03[];
extern u16 ship0_shot_list_1_04_04[];
extern u16 ship0_shot_list_2_04_04[];
extern u16 ship0_shot_list_3_00_00[];
extern u16 ship0_shot_list_3_00_01[];
extern u16 ship0_shot_list_3_00_02[];
extern u16 ship0_shot_list_3_00_03[];
extern u16 ship0_shot_list_3_00_04[];
extern u16 ship0_shot_list_3_02_00[];
extern u16 ship0_shot_list_3_02_01[];
extern u16 ship0_shot_list_3_02_02[];
extern u16 ship0_shot_list_3_02_03[];
extern u16 ship0_shot_list_3_02_04[];
extern u16 ship0_shot_list_3_04_00[];
extern u16 ship0_shot_list_3_04_01[];
extern u16 ship0_shot_list_3_04_02[];
extern u16 ship0_shot_list_3_04_03[];
extern u16 ship0_shot_list_3_04_04[];
extern u16 ship0_shot_list_1_01_00[];
extern u16 ship0_shot_list_2_01_00[];
extern u16 ship0_shot_list_1_01_01[];
extern u16 ship0_shot_list_2_01_01[];
extern u16 ship0_shot_list_1_01_02[];
extern u16 ship0_shot_list_2_01_02[];
extern u16 ship0_shot_list_1_01_03[];
extern u16 ship0_shot_list_2_01_03[];
extern u16 ship0_shot_list_1_01_04[];
extern u16 ship0_shot_list_2_01_04[];
extern u16 ship0_shot_list_1_03_00[];
extern u16 ship0_shot_list_1_03_01[];
extern u16 ship0_shot_list_1_03_02[];
extern u16 ship0_shot_list_1_03_03[];
extern u16 ship0_shot_list_1_03_04[];
extern u16 ship0_shot_list_1_05_00[];
extern u16 ship0_shot_list_2_05_00[];
extern u16 ship0_shot_list_1_05_01[];
extern u16 ship0_shot_list_2_05_01[];
extern u16 ship0_shot_list_1_05_02[];
extern u16 ship0_shot_list_2_05_02[];
extern u16 ship0_shot_list_1_05_03[];
extern u16 ship0_shot_list_2_05_03[];
extern u16 ship0_shot_list_1_05_04[];
extern u16 ship0_shot_list_2_05_04[];
extern u16 ship0_shot_list_3_01_00[];
extern u16 ship0_shot_list_3_01_01[];
extern u16 ship0_shot_list_3_01_02[];
extern u16 ship0_shot_list_3_01_03[];
extern u16 ship0_shot_list_3_01_04[];
extern u16 ship0_shot_list_3_03_00[];
extern u16 ship0_shot_list_3_03_01[];
extern u16 ship0_shot_list_3_03_02[];
extern u16 ship0_shot_list_3_03_03[];
extern u16 ship0_shot_list_3_03_04[];
extern u16 ship0_shot_list_3_05_00[];
extern u16 ship0_shot_list_3_05_01[];
extern u16 ship0_shot_list_3_05_02[];
extern u16 ship0_shot_list_3_05_03[];
extern u16 ship0_shot_list_3_05_04[];
extern u16 player_shot_levels_0[];
extern u16 player_shot_levels_1[];
extern u16 player_shot_levels_2[];
extern u16 player_shot_levels_3[];
extern u16 player_shot_levels_4[];
extern u16 player_shot_levels_5[];
extern u16 player_laser_levels_0[];
extern u16 player_laser_levels_1[];
extern u16 player_laser_levels_2[];
extern u16 player_laser_levels_3[];
extern u16 player_laser_levels_4[];
extern u16 player_laser_levels_5[];
extern u16 player_ship_sprites_00[];
extern u16 player_ship_sprites_01[];
extern u16 player_ship_hitboxes_00[];
extern u16 player_ship_hitboxes_01[];
extern u16 player_ship_shadows_00[];
extern u16 player_ship_shadows_01[];
extern u16 ship0_shot_list_1_00[];
extern u16 ship0_shot_list_2_00[];
extern u16 ship0_shot_list_3_00[];
extern u16 ship0_shot_list_1_01[];
extern u16 ship0_shot_list_2_01[];
extern u16 ship0_shot_list_3_01[];
extern u16 ship0_shot_list_1_02[];
extern u16 ship0_shot_list_3_02[];
extern u16 ship0_shot_list_1_03[];
extern u16 ship0_shot_list_3_03[];
extern u16 ship0_shot_list_1_04[];
extern u16 ship0_shot_list_2_04[];
extern u16 ship0_shot_list_3_04[];
extern u16 ship0_shot_list_1_05[];
extern u16 ship0_shot_list_2_05[];
extern u16 ship0_shot_list_3_05[];
extern u16 player_shield_sprites_00[];
extern u16 player_shield_sprites_01[];
extern u16 player_exhaust_sprites_00[];
extern u16 player_exhaust_sprites_01[];
extern u16 player_exhaust_slow_sprites_00[];
extern u16 player_exhaust_slow_sprites_01[];
extern u16 D_00255D48[];
extern u16 D_00255DB8[];
extern u16 D_00255DC8[];
extern u16 D_00255DD8[];
extern u16 D_00255DE8[];
extern u16 D_00255DF8[];
extern u16 D_00255E08[];
extern u16 D_00255E78[];
extern u16 D_00255E88[];
extern u16 D_00255E98[];
extern u16 D_00255EA8[];
extern u16 D_00255EB8[];
extern u16 D_00255EC8[];
extern u16 D_00255F80[];
extern u16 D_00255FA0[];
extern u16 D_00255FC0[];
extern u16 D_00255FE0[];
extern u16 D_00256000[];
extern u16 D_00256010[];
extern u16 D_00256020[];
extern u16 D_00256030[];
extern u16 D_00256040[];
extern u16 D_00256050[];
extern u16 D_00256060[];
extern u16 D_00256070[];
extern u16 D_00256080[];
extern u16 D_00256090[];
extern u16 D_002560A0[];
extern u16 player_shield_sprites_01_04[];
extern u16 player_shield_sprites_01_05[];
extern u16 player_shield_sprites_01_06[];
extern u16 player_shield_sprites_01_07[];
extern u16 player_shield_sprites_01_08[];
extern u16 player_shield_sprites_01_09[];
extern u16 player_shield_sprites_01_10[];
extern u16 player_shield_sprites_01_11[];
extern u16 D_0028C680[];
extern u16 player_exhaust_sprites_00_01[];
extern u16 player_exhaust_sprites_00_02[];
extern u16 player_exhaust_sprites_00_03[];
extern u16 player_exhaust_sprites_00_04[];
extern u16 player_exhaust_sprites_00_05[];
extern u16 player_exhaust_sprites_00_06[];
extern u16 player_exhaust_sprites_00_07[];
extern u16 player_exhaust_sprites_00_08[];
extern u16 player_exhaust_sprites_00_12[];
extern u16 player_exhaust_sprites_00_13[];
extern u16 player_exhaust_sprites_00_14[];
extern u16 player_exhaust_sprites_00_15[];
extern u16 player_exhaust_sprites_00_16[];
extern u16 player_exhaust_sprites_00_17[];
extern u16 player_exhaust_sprites_00_18[];
extern u16 player_exhaust_sprites_00_19[];
extern u16 D_0028C708[];
extern u16 player_exhaust_sprites_01_01[];
extern u16 player_exhaust_sprites_01_02[];
extern u16 player_exhaust_sprites_01_03[];
extern u16 player_exhaust_sprites_01_04[];
extern u16 player_exhaust_sprites_01_05[];
extern u16 player_exhaust_sprites_01_06[];
extern u16 player_exhaust_sprites_01_07[];
extern u16 player_exhaust_sprites_01_08[];
extern u16 player_exhaust_sprites_01_12[];
extern u16 player_exhaust_sprites_01_13[];
extern u16 player_exhaust_sprites_01_14[];
extern u16 player_exhaust_sprites_01_15[];
extern u16 player_exhaust_sprites_01_16[];
extern u16 player_exhaust_sprites_01_17[];
extern u16 player_exhaust_sprites_01_18[];
extern u16 player_exhaust_sprites_01_19[];
extern u16 player_exhaust_slow_sprites_00_00[];
extern u16 player_exhaust_slow_sprites_00_01[];
extern u16 player_exhaust_slow_sprites_00_02[];
extern u16 player_exhaust_slow_sprites_00_03[];
extern u16 player_exhaust_slow_sprites_00_04[];
extern u16 player_exhaust_slow_sprites_00_05[];
extern u16 player_exhaust_slow_sprites_00_06[];
extern u16 player_exhaust_slow_sprites_00_07[];
extern u16 player_exhaust_slow_sprites_00_08[];
extern u16 player_exhaust_slow_sprites_00_12[];
extern u16 player_exhaust_slow_sprites_00_13[];
extern u16 player_exhaust_slow_sprites_00_14[];
extern u16 player_exhaust_slow_sprites_00_15[];
extern u16 player_exhaust_slow_sprites_00_16[];
extern u16 player_exhaust_slow_sprites_00_17[];
extern u16 player_exhaust_slow_sprites_00_18[];
extern u16 player_exhaust_slow_sprites_00_19[];
extern u16 player_exhaust_slow_sprites_01_00[];
extern u16 player_exhaust_slow_sprites_01_01[];
extern u16 player_exhaust_slow_sprites_01_02[];
extern u16 player_exhaust_slow_sprites_01_03[];
extern u16 player_exhaust_slow_sprites_01_04[];
extern u16 player_exhaust_slow_sprites_01_05[];
extern u16 player_exhaust_slow_sprites_01_06[];
extern u16 player_exhaust_slow_sprites_01_07[];
extern u16 player_exhaust_slow_sprites_01_08[];
extern u16 D_0028C870[];
extern u16 D_0028C878[];
extern u16 D_0028C888[];
extern u16 D_0028C890[];
extern u16 D_0028C898[];
extern u16 D_0028C8A0[];
extern u16 D_0028C8A8[];
extern u16 D_0028C8B0[];
extern u16 D_0028C8B8[];
extern u16 D_0028C8C0[];
extern u16 D_0028C8C8[];
extern u16 D_0028C8D0[];
extern u16 D_0028C8D8[];
extern u16 D_0028C8E0[];
extern u16 D_0028C8E8[];
extern u16 D_0028C8F0[];
extern u16 D_0028C8F8[];
extern u16 D_0028C900[];
extern u16 D_0028C908[];
extern u16 D_0028C910[];
extern u16 D_0028C918[];
extern u16 D_0028C920[];
extern u16 D_0028C928[];
extern u16 D_0028C930[];
extern u16 D_0028C938[];
extern u16 D_0028C940[];

extern u16 player_weapon_tables_as_u16_a[];
extern u16 D_002556D2[];
extern u16 D_002556D6[];
extern u16 D_002556DA[];
extern u16 D_002556DE[];
extern u16 ship0_shot_lists_1_as_u16_a[];
extern u16 ship0_shot_lists_2_as_u16_a[];
extern u16 ship0_shot_lists_3_as_u16_a[];
extern u16 D_00255EE0_as_u16_a[];
extern u16 player_ship_sprite_tables_as_u16_a[];
extern u16 player_ship_hitbox_tables[];
extern u16 player_ship_shadow_tables[];
extern u16 player_shield_sprite_tables[];
extern u16 player_exhaust_sprite_tables[];
extern u16 player_exhaust_slow_sprite_tables[];
extern u16 D_0028C868[];
extern u16 D_0028C880[];

void func_0017FCB0(void) {
    STORE_POINTER(player_weapon_tables_as_u16_a, player_shot_levels_0);
    STORE_POINTER(player_weapon_tables + 2, player_laser_levels_0);
    STORE_POINTER(player_weapon_tables + 4, player_shot_levels_1);
    STORE_POINTER(player_weapon_tables + 6, player_laser_levels_1);
    STORE_POINTER(player_weapon_tables + 8, player_shot_levels_2);
    STORE_POINTER(player_weapon_tables + 10, player_laser_levels_2);
    STORE_POINTER(player_weapon_tables + 12, player_shot_levels_3);
    STORE_POINTER(player_weapon_tables + 14, player_laser_levels_3);
    STORE_POINTER(player_weapon_tables + 16, player_shot_levels_4);
    STORE_POINTER(player_weapon_tables + 18, player_laser_levels_4);
    STORE_POINTER(player_weapon_tables + 20, player_shot_levels_5);
    STORE_POINTER(player_weapon_tables + 22, player_laser_levels_5);
    STORE_POINTER(player_laser_levels_5 + 8, (u32)player_shot_levels_2 + 8);
    STORE_POINTER(player_laser_levels_5 + 10, (u32)player_laser_levels_2 + 8);
    STORE_POINTER(player_laser_levels_5 + 12, (u32)player_shot_levels_3 + 8);
    STORE_POINTER(player_laser_levels_5 + 14, (u32)player_laser_levels_3 + 8);
    STORE_POINTER(player_ship_sprite_tables_as_u16_a, player_ship_sprites_00);
    STORE_POINTER(player_ship_sprite_tables + 2, player_ship_sprites_01);
    STORE_POINTER(player_ship_hitbox_tables, player_ship_hitboxes_00);
    STORE_POINTER(player_ship_hitbox_tables + 2, player_ship_hitboxes_01);
    STORE_POINTER(player_ship_shadow_tables, player_ship_shadows_00);
    STORE_POINTER(player_ship_shadow_tables + 2, player_ship_shadows_01);
    STORE_POINTER(ship0_shot_lists_1_as_u16_a, ship0_shot_list_1_00);
    STORE_POINTER(ship0_shot_lists_1 + 2, ship0_shot_list_1_01);
    STORE_POINTER(ship0_shot_lists_1 + 4, ship0_shot_list_1_02);
    STORE_POINTER(ship0_shot_lists_1 + 6, ship0_shot_list_1_03);
    STORE_POINTER(ship0_shot_lists_1 + 8, ship0_shot_list_1_04);
    STORE_POINTER(ship0_shot_lists_1 + 10, ship0_shot_list_1_05);
    STORE_POINTER(ship0_shot_lists_2_as_u16_a, ship0_shot_list_2_00);
    STORE_POINTER(ship0_shot_lists_2 + 2, ship0_shot_list_2_01);
    STORE_POINTER(ship0_shot_lists_2 + 8, ship0_shot_list_2_04);
    STORE_POINTER(ship0_shot_lists_2 + 10, ship0_shot_list_2_05);
    STORE_POINTER(ship0_shot_lists_3_as_u16_a, ship0_shot_list_3_00);
    STORE_POINTER(ship0_shot_lists_3 + 2, ship0_shot_list_3_01);
    STORE_POINTER(ship0_shot_lists_3 + 4, ship0_shot_list_3_02);
    STORE_POINTER(ship0_shot_lists_3 + 6, ship0_shot_list_3_03);
    STORE_POINTER(ship0_shot_lists_3 + 8, ship0_shot_list_3_04);
    STORE_POINTER(ship0_shot_lists_3 + 10, ship0_shot_list_3_05);
    STORE_POINTER(ship0_shot_list_1_00, ship0_shot_list_1_00_00);
    STORE_POINTER(ship0_shot_list_1_00 + 2, ship0_shot_list_1_00_01);
    STORE_POINTER(ship0_shot_list_1_00 + 4, ship0_shot_list_1_00_02);
    STORE_POINTER(ship0_shot_list_1_00 + 6, ship0_shot_list_1_00_03);
    STORE_POINTER(ship0_shot_list_1_00 + 8, ship0_shot_list_1_00_04);
    STORE_POINTER(ship0_shot_list_2_00, ship0_shot_list_2_00_00);
    STORE_POINTER(ship0_shot_list_2_00 + 2, ship0_shot_list_2_00_01);
    STORE_POINTER(ship0_shot_list_2_00 + 4, ship0_shot_list_2_00_02);
    STORE_POINTER(ship0_shot_list_2_00 + 6, ship0_shot_list_2_00_03);
    STORE_POINTER(ship0_shot_list_2_00 + 8, ship0_shot_list_2_00_04);
    STORE_POINTER(ship0_shot_list_3_00, ship0_shot_list_3_00_00);
    STORE_POINTER(ship0_shot_list_3_00 + 2, ship0_shot_list_3_00_01);
    STORE_POINTER(ship0_shot_list_3_00 + 4, ship0_shot_list_3_00_02);
    STORE_POINTER(ship0_shot_list_3_00 + 6, ship0_shot_list_3_00_03);
    STORE_POINTER(ship0_shot_list_3_00 + 8, ship0_shot_list_3_00_04);
    STORE_POINTER(ship0_shot_list_1_01, ship0_shot_list_1_01_00);
    STORE_POINTER(ship0_shot_list_1_01 + 2, ship0_shot_list_1_01_01);
    STORE_POINTER(ship0_shot_list_1_01 + 4, ship0_shot_list_1_01_02);
    STORE_POINTER(ship0_shot_list_1_01 + 6, ship0_shot_list_1_01_03);
    STORE_POINTER(ship0_shot_list_1_01 + 8, ship0_shot_list_1_01_04);
    STORE_POINTER(ship0_shot_list_2_01, ship0_shot_list_2_01_00);
    STORE_POINTER(ship0_shot_list_2_01 + 2, ship0_shot_list_2_01_01);
    STORE_POINTER(ship0_shot_list_2_01 + 4, ship0_shot_list_2_01_02);
    STORE_POINTER(ship0_shot_list_2_01 + 6, ship0_shot_list_2_01_03);
    STORE_POINTER(ship0_shot_list_2_01 + 8, ship0_shot_list_2_01_04);
    STORE_POINTER(ship0_shot_list_3_01, ship0_shot_list_3_01_00);
    STORE_POINTER(ship0_shot_list_3_01 + 2, ship0_shot_list_3_01_01);
    STORE_POINTER(ship0_shot_list_3_01 + 4, ship0_shot_list_3_01_02);
    STORE_POINTER(ship0_shot_list_3_01 + 6, ship0_shot_list_3_01_03);
    STORE_POINTER(ship0_shot_list_3_01 + 8, ship0_shot_list_3_01_04);
    STORE_POINTER(ship0_shot_list_1_02, ship0_shot_list_1_02_00);
    STORE_POINTER(ship0_shot_list_1_02 + 2, ship0_shot_list_1_02_01);
    STORE_POINTER(ship0_shot_list_1_02 + 4, ship0_shot_list_1_02_02);
    STORE_POINTER(ship0_shot_list_1_02 + 6, ship0_shot_list_1_02_03);
    STORE_POINTER(ship0_shot_list_1_02 + 8, ship0_shot_list_1_02_04);
    STORE_POINTER(ship0_shot_list_3_02, ship0_shot_list_3_02_00);
    STORE_POINTER(ship0_shot_list_3_02 + 2, ship0_shot_list_3_02_01);
    STORE_POINTER(ship0_shot_list_3_02 + 4, ship0_shot_list_3_02_02);
    STORE_POINTER(ship0_shot_list_3_02 + 6, ship0_shot_list_3_02_03);
    STORE_POINTER(ship0_shot_list_3_02 + 8, ship0_shot_list_3_02_04);
    STORE_POINTER(ship0_shot_list_1_03, ship0_shot_list_1_03_00);
    STORE_POINTER(ship0_shot_list_1_03 + 2, ship0_shot_list_1_03_01);
    STORE_POINTER(ship0_shot_list_1_03 + 4, ship0_shot_list_1_03_02);
    STORE_POINTER(ship0_shot_list_1_03 + 6, ship0_shot_list_1_03_03);
    STORE_POINTER(ship0_shot_list_1_03 + 8, ship0_shot_list_1_03_04);
    STORE_POINTER(ship0_shot_list_3_03, ship0_shot_list_3_03_00);
    STORE_POINTER(ship0_shot_list_3_03 + 2, ship0_shot_list_3_03_01);
    STORE_POINTER(ship0_shot_list_3_03 + 4, ship0_shot_list_3_03_02);
    STORE_POINTER(ship0_shot_list_3_03 + 6, ship0_shot_list_3_03_03);
    STORE_POINTER(ship0_shot_list_3_03 + 8, ship0_shot_list_3_03_04);
    STORE_POINTER(ship0_shot_list_1_04, ship0_shot_list_1_04_00);
    STORE_POINTER(ship0_shot_list_1_04 + 2, ship0_shot_list_1_04_01);
    STORE_POINTER(ship0_shot_list_1_04 + 4, ship0_shot_list_1_04_02);
    STORE_POINTER(ship0_shot_list_1_04 + 6, ship0_shot_list_1_04_03);
    STORE_POINTER(ship0_shot_list_1_04 + 8, ship0_shot_list_1_04_04);
    STORE_POINTER(ship0_shot_list_2_04, ship0_shot_list_2_04_00);
    STORE_POINTER(ship0_shot_list_2_04 + 2, ship0_shot_list_2_04_01);
    STORE_POINTER(ship0_shot_list_2_04 + 4, ship0_shot_list_2_04_02);
    STORE_POINTER(ship0_shot_list_2_04 + 6, ship0_shot_list_2_04_03);
    STORE_POINTER(ship0_shot_list_2_04 + 8, ship0_shot_list_2_04_04);
    STORE_POINTER(ship0_shot_list_3_04, ship0_shot_list_3_04_00);
    STORE_POINTER(ship0_shot_list_3_04 + 2, ship0_shot_list_3_04_01);
    STORE_POINTER(ship0_shot_list_3_04 + 4, ship0_shot_list_3_04_02);
    STORE_POINTER(ship0_shot_list_3_04 + 6, ship0_shot_list_3_04_03);
    STORE_POINTER(ship0_shot_list_3_04 + 8, ship0_shot_list_3_04_04);
    STORE_POINTER(ship0_shot_list_1_05, ship0_shot_list_1_05_00);
    STORE_POINTER(ship0_shot_list_1_05 + 2, ship0_shot_list_1_05_01);
    STORE_POINTER(ship0_shot_list_1_05 + 4, ship0_shot_list_1_05_02);
    STORE_POINTER(ship0_shot_list_1_05 + 6, ship0_shot_list_1_05_03);
    STORE_POINTER(ship0_shot_list_1_05 + 8, ship0_shot_list_1_05_04);
    STORE_POINTER(ship0_shot_list_2_05, ship0_shot_list_2_05_00);
    STORE_POINTER(ship0_shot_list_2_05 + 2, ship0_shot_list_2_05_01);
    STORE_POINTER(ship0_shot_list_2_05 + 4, ship0_shot_list_2_05_02);
    STORE_POINTER(ship0_shot_list_2_05 + 6, ship0_shot_list_2_05_03);
    STORE_POINTER(ship0_shot_list_2_05 + 8, ship0_shot_list_2_05_04);
    STORE_POINTER(ship0_shot_list_3_05, ship0_shot_list_3_05_00);
    STORE_POINTER(ship0_shot_list_3_05 + 2, ship0_shot_list_3_05_01);
    STORE_POINTER(ship0_shot_list_3_05 + 4, ship0_shot_list_3_05_02);
    STORE_POINTER(ship0_shot_list_3_05 + 6, ship0_shot_list_3_05_03);
    STORE_POINTER(ship0_shot_list_3_05 + 8, ship0_shot_list_3_05_04);
    STORE_POINTER(player_shield_sprite_tables, player_shield_sprites_00);
    STORE_POINTER(player_shield_sprite_tables + 2, player_shield_sprites_01);
    STORE_POINTER(player_exhaust_sprite_tables, player_exhaust_sprites_00);
    STORE_POINTER(player_exhaust_sprite_tables + 2, player_exhaust_sprites_01);
    STORE_POINTER(player_shield_sprites_01 + 8, player_shield_sprites_01_04);
    STORE_POINTER(player_shield_sprites_01 + 10, player_shield_sprites_01_05);
    STORE_POINTER(player_shield_sprites_01 + 12, player_shield_sprites_01_06);
    STORE_POINTER(player_shield_sprites_01 + 14, player_shield_sprites_01_07);
    STORE_POINTER(player_shield_sprites_01 + 16, player_shield_sprites_01_08);
    STORE_POINTER(player_shield_sprites_01 + 18, player_shield_sprites_01_09);
    STORE_POINTER(player_shield_sprites_01 + 20, player_shield_sprites_01_10);
    STORE_POINTER(player_shield_sprites_01 + 22, player_shield_sprites_01_11);
    STORE_POINTER(player_exhaust_sprites_00, D_0028C680);
    STORE_POINTER(player_exhaust_sprites_00 + 2, player_exhaust_sprites_00_01);
    STORE_POINTER(player_exhaust_sprites_00 + 4, player_exhaust_sprites_00_02);
    STORE_POINTER(player_exhaust_sprites_00 + 6, player_exhaust_sprites_00_03);
    STORE_POINTER(player_exhaust_sprites_00 + 8, player_exhaust_sprites_00_04);
    STORE_POINTER(player_exhaust_sprites_00 + 10, player_exhaust_sprites_00_05);
    STORE_POINTER(player_exhaust_sprites_00 + 12, player_exhaust_sprites_00_06);
    STORE_POINTER(player_exhaust_sprites_00 + 14, player_exhaust_sprites_00_07);
    STORE_POINTER(player_exhaust_sprites_00 + 16, player_exhaust_sprites_00_08);
    STORE_POINTER(player_exhaust_sprites_00 + 24, player_exhaust_sprites_00_12);
    STORE_POINTER(player_exhaust_sprites_00 + 26, player_exhaust_sprites_00_13);
    STORE_POINTER(player_exhaust_sprites_00 + 28, player_exhaust_sprites_00_14);
    STORE_POINTER(player_exhaust_sprites_00 + 30, player_exhaust_sprites_00_15);
    STORE_POINTER(player_exhaust_sprites_00 + 32, player_exhaust_sprites_00_16);
    STORE_POINTER(player_exhaust_sprites_00 + 34, player_exhaust_sprites_00_17);
    STORE_POINTER(player_exhaust_sprites_00 + 36, player_exhaust_sprites_00_18);
    STORE_POINTER(player_exhaust_sprites_00 + 38, player_exhaust_sprites_00_19);
    STORE_POINTER(player_exhaust_sprites_01, D_0028C708);
    STORE_POINTER(player_exhaust_sprites_01 + 2, player_exhaust_sprites_01_01);
    STORE_POINTER(player_exhaust_sprites_01 + 4, player_exhaust_sprites_01_02);
    STORE_POINTER(player_exhaust_sprites_01 + 6, player_exhaust_sprites_01_03);
    STORE_POINTER(player_exhaust_sprites_01 + 8, player_exhaust_sprites_01_04);
    STORE_POINTER(player_exhaust_sprites_01 + 10, player_exhaust_sprites_01_05);
    STORE_POINTER(player_exhaust_sprites_01 + 12, player_exhaust_sprites_01_06);
    STORE_POINTER(player_exhaust_sprites_01 + 14, player_exhaust_sprites_01_07);
    STORE_POINTER(player_exhaust_sprites_01 + 16, player_exhaust_sprites_01_08);
    STORE_POINTER(player_exhaust_slow_sprite_tables, player_exhaust_slow_sprites_00);
    STORE_POINTER(player_exhaust_slow_sprite_tables + 2, player_exhaust_slow_sprites_01);
    STORE_POINTER(player_exhaust_sprites_01 + 24, player_exhaust_sprites_01_12);
    STORE_POINTER(player_exhaust_sprites_01 + 26, player_exhaust_sprites_01_13);
    STORE_POINTER(player_exhaust_sprites_01 + 28, player_exhaust_sprites_01_14);
    STORE_POINTER(player_exhaust_sprites_01 + 30, player_exhaust_sprites_01_15);
    STORE_POINTER(player_exhaust_sprites_01 + 32, player_exhaust_sprites_01_16);
    STORE_POINTER(player_exhaust_sprites_01 + 34, player_exhaust_sprites_01_17);
    STORE_POINTER(player_exhaust_sprites_01 + 36, player_exhaust_sprites_01_18);
    STORE_POINTER(player_exhaust_sprites_01 + 38, player_exhaust_sprites_01_19);
    STORE_POINTER(player_exhaust_slow_sprites_00, player_exhaust_slow_sprites_00_00);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 2, player_exhaust_slow_sprites_00_01);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 4, player_exhaust_slow_sprites_00_02);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 6, player_exhaust_slow_sprites_00_03);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 8, player_exhaust_slow_sprites_00_04);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 10, player_exhaust_slow_sprites_00_05);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 12, player_exhaust_slow_sprites_00_06);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 14, player_exhaust_slow_sprites_00_07);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 16, player_exhaust_slow_sprites_00_08);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 24, player_exhaust_slow_sprites_00_12);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 26, player_exhaust_slow_sprites_00_13);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 28, player_exhaust_slow_sprites_00_14);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 30, player_exhaust_slow_sprites_00_15);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 32, player_exhaust_slow_sprites_00_16);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 34, player_exhaust_slow_sprites_00_17);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 36, player_exhaust_slow_sprites_00_18);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 38, player_exhaust_slow_sprites_00_19);
    STORE_POINTER(player_exhaust_slow_sprites_01, player_exhaust_slow_sprites_01_00);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 2, player_exhaust_slow_sprites_01_01);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 4, player_exhaust_slow_sprites_01_02);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 6, player_exhaust_slow_sprites_01_03);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 8, player_exhaust_slow_sprites_01_04);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 10, player_exhaust_slow_sprites_01_05);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 12, player_exhaust_slow_sprites_01_06);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 14, player_exhaust_slow_sprites_01_07);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 16, player_exhaust_slow_sprites_01_08);
    STORE_POINTER(D_0028C868, D_0028C870);
    STORE_POINTER(D_0028C868 + 2, D_0028C878);
    STORE_POINTER(D_0028C880, D_0028C888);
    STORE_POINTER(D_0028C880 + 2, D_00255D48);
    STORE_POINTER(D_00255D48 + 12, D_00255DB8);
    STORE_POINTER(D_00255D48 + 14, D_00255DB8);
    STORE_POINTER(D_00255D48 + 16, D_00255DB8);
    STORE_POINTER(D_00255D48 + 18, D_00255DC8);
    STORE_POINTER(D_00255D48 + 20, D_00255DC8);
    STORE_POINTER(D_00255D48 + 22, D_00255DC8);
    STORE_POINTER(D_00255D48 + 24, D_00255DD8);
    STORE_POINTER(D_00255D48 + 26, D_00255DD8);
    STORE_POINTER(D_00255D48 + 28, D_00255DD8);
    STORE_POINTER(D_00255D48 + 36, D_00255DE8);
    STORE_POINTER(D_00255D48 + 38, D_00255DE8);
    STORE_POINTER(D_00255D48 + 40, D_00255DE8);
    STORE_POINTER(D_00255D48 + 42, D_00255DF8);
    STORE_POINTER(D_00255D48 + 44, D_00255DF8);
    STORE_POINTER(D_00255D48 + 46, D_00255DF8);
    STORE_POINTER(D_00255D48 + 48, D_00255E08);
    STORE_POINTER(D_00255D48 + 50, D_00255E08);
    STORE_POINTER(D_00255D48 + 52, D_00255E08);
    STORE_POINTER(D_00255E08 + 12, D_00255E78);
    STORE_POINTER(D_00255E08 + 14, D_00255E78);
    STORE_POINTER(D_00255E08 + 16, D_00255E78);
    STORE_POINTER(D_00255E08 + 18, D_00255E88);
    STORE_POINTER(D_00255E08 + 20, D_00255E88);
    STORE_POINTER(D_00255E08 + 22, D_00255E88);
    STORE_POINTER(D_00255E08 + 24, D_00255E98);
    STORE_POINTER(D_00255E08 + 26, D_00255E98);
    STORE_POINTER(D_00255E08 + 28, D_00255E98);
    STORE_POINTER(D_00255E08 + 36, D_00255EA8);
    STORE_POINTER(D_00255E08 + 38, D_00255EA8);
    STORE_POINTER(D_00255E08 + 40, D_00255EA8);
    STORE_POINTER(D_00255E08 + 42, D_00255EB8);
    STORE_POINTER(D_00255E08 + 44, D_00255EB8);
    STORE_POINTER(D_00255E08 + 46, D_00255EB8);
    STORE_POINTER(D_00255E08 + 48, D_00255EC8);
    STORE_POINTER(D_00255E08 + 50, D_00255EC8);
    STORE_POINTER(D_00255E08 + 52, D_00255EC8);
    STORE_POINTER(D_00255EE0_as_u16_a, D_00255F80);
    STORE_POINTER(D_00255EE0 + 2, D_0028C890);
    STORE_POINTER(D_00255EE0 + 4, D_0028C898);
    STORE_POINTER(D_00255EE0 + 6, D_0028C8A0);
    STORE_POINTER(D_00255EE0 + 8, D_0028C8A8);
    STORE_POINTER(D_00255EE0 + 10, D_0028C8B0);
    STORE_POINTER(D_00255EE0 + 12, D_00255FA0);
    STORE_POINTER(D_00255EE0 + 14, D_0028C8B8);
    STORE_POINTER(D_00255EE0 + 16, D_0028C8C0);
    STORE_POINTER(D_00255EE0 + 18, D_0028C8C8);
    STORE_POINTER(D_00255EE0 + 20, D_0028C8D0);
    STORE_POINTER(D_00255EE0 + 22, D_0028C8D8);
    STORE_POINTER(D_00255EE0 + 24, D_0028C8E0);
    STORE_POINTER(D_00255EE0 + 26, D_0028C8E8);
    STORE_POINTER(D_00255EE0 + 28, D_0028C8F0);
    STORE_POINTER(D_00255EE0 + 30, D_0028C8F8);
    STORE_POINTER(D_00255EE0 + 32, D_0028C900);
    STORE_POINTER(D_00255EE0 + 34, D_0028C908);
    STORE_POINTER(D_00255EE0 + 36, D_0028C910);
    STORE_POINTER(D_00255EE0 + 38, D_0028C918);
    STORE_POINTER(D_00255EE0 + 40, D_0028C920);
    STORE_POINTER(D_00255EE0 + 42, D_0028C928);
    STORE_POINTER(D_00255EE0 + 44, D_00255FC0);
    STORE_POINTER(D_00255EE0 + 46, D_0028C930);
    STORE_POINTER(D_00255EE0 + 48, D_00255FE0);
    STORE_POINTER(D_00255EE0 + 50, D_00256000);
    STORE_POINTER(D_00255EE0 + 52, D_00256010);
    STORE_POINTER(D_00255EE0 + 54, D_00256020);
    STORE_POINTER(D_00255EE0 + 56, D_00256030);
    STORE_POINTER(D_00255EE0 + 58, D_00256040);
    STORE_POINTER(D_00255EE0 + 60, D_00256050);
    STORE_POINTER(D_00255EE0 + 62, D_00256060);
    STORE_POINTER(D_00255EE0 + 64, D_00256070);
    STORE_POINTER(D_00255EE0 + 66, D_00256080);
    STORE_POINTER(D_00255EE0 + 68, D_00256090);
    STORE_POINTER(D_00255EE0 + 70, D_002560A0);
    STORE_POINTER(D_00255EE0 + 72, D_0028C938);
    STORE_POINTER(D_00255EE0 + 74, D_0028C940);
}

extern u16 D_00261E30[];
extern u16 D_00261E70[];
extern u16 D_00261EB0[];

extern u16 D_00255580_as_u16_a[];
extern u16 D_002555A0_as_u16_a[];

void func_001828A0(void) {
    STORE_POINTER(D_00255580_as_u16_a, D_00261CB0);
    STORE_POINTER(D_00255580 + 4, D_00261E30);
    STORE_POINTER(D_00255580 + 8, D_00261E70);
    STORE_POINTER(D_0028C5E0 + 4, D_00261EB0);
    STORE_POINTER(D_002555A0_as_u16_a, D_00261CB0);
    STORE_POINTER(D_002555A0 + 4, D_00261E30);
    STORE_POINTER(D_002555A0 + 8, D_00261E70);
    STORE_POINTER(D_0028C5E0 + 8, D_00261EB0);
}

extern u16 D_00256180[];
extern u16 D_002561C0[];
extern u16 D_00256200[];
extern u16 D_00256240[];
extern u16 D_00256730[];
extern u16 D_00256760[];
extern u16 D_00256790[];
extern u16 D_002567C0[];
extern u16 D_002567F0[];
extern u16 D_00256820[];
extern u16 D_00256850[];
extern u16 D_00256880[];
extern u16 D_002568B0[];
extern u16 D_002568E0[];
extern u16 D_00256910[];
extern u16 D_00256940[];
extern u16 D_00256970[];
extern u16 D_002569A0[];
extern u16 D_002569D0[];
extern u16 D_00256A00[];
extern u16 D_00256E50[];
extern u16 D_00256E70[];
extern u16 D_00256E90[];
extern u16 D_00256EB0[];
extern u16 D_00256ED0[];
extern u16 D_00256F00[];
extern u16 D_00256F30[];
extern u16 D_00256F60[];
extern u16 D_00256F90[];
extern u16 D_00256FC0[];
extern u16 D_00256FD8[];
extern u16 D_00256FE8[];
extern u16 D_00256FF8[];
extern u16 D_00257008[];
extern u16 D_00257018[];
extern u16 D_00257030[];
extern u16 D_00257048[];
extern u16 D_00257058[];
extern u16 D_00257068[];
extern u16 D_00257078[];
extern u16 D_00257088[];
extern u16 D_002570A0[];
extern u16 D_002570B8[];
extern u16 D_002570C8[];
extern u16 D_002570D8[];
extern u16 D_002570E8[];
extern u16 D_002570F8[];
extern u16 D_00257110[];
extern u16 D_00257128[];
extern u16 D_00257138[];
extern u16 D_00257148[];
extern u16 D_00257158[];
extern u16 D_00257168[];
extern u16 D_00257178[];
extern u16 D_00257188[];
extern u16 D_00257198[];
extern u16 D_002571A8[];
extern u16 D_002571B8[];
extern u16 D_002571C8[];
extern u16 D_002571D8[];
extern u16 D_002571E8[];
extern u16 D_002571F8[];
extern u16 D_00257208[];
extern u16 D_00257218[];
extern u16 D_00257268[];
extern u16 D_00257278[];
extern u16 D_00257288[];
extern u16 D_00257298[];
extern u16 D_002572A8[];
extern u16 D_002572B8[];
extern u16 D_002572C8[];
extern u16 D_002572D8[];
extern u16 D_002572E8[];
extern u16 D_002572F8[];
extern u16 D_00257308[];
extern u16 D_00257318[];
extern u16 D_00257328[];
extern u16 D_00257338[];
extern u16 D_00257348[];
extern u16 D_00257358[];
extern u16 D_002573A8[];
extern u16 D_002573C0[];
extern u16 D_002573F0[];
extern u16 D_00257420[];
extern u16 D_00257450[];
extern u16 D_00257480[];
extern u16 D_002574B0[];
extern u16 D_002574E0[];
extern u16 D_00257510[];
extern u16 D_00257540[];
extern u16 D_00257570[];
extern u16 D_002575A0[];
extern u16 D_002575D0[];
extern u16 D_00257600[];
extern u16 D_00257630[];
extern u16 D_00257660[];
extern u16 D_00257690[];
extern u16 D_0028C950[];
extern u16 D_0028C958[];
extern u16 D_0028C960[];
extern u16 D_0028C968[];
extern u16 D_0028C970[];
extern u16 D_0028C978[];
extern u16 D_0028C980[];
extern u16 D_0028C988[];
extern u16 D_0028C990[];
extern u16 D_0028C998[];
extern u16 D_0028C9A0[];


void func_001829B0(void) {
    STORE_POINTER(D_00256280 + 10, D_00256180);
    STORE_POINTER(D_00256280 + 15, D_00256ED0);
    STORE_POINTER(D_00256280 + 17, D_00257278);
    STORE_POINTER(D_002562B0 + 10, D_00256180);
    STORE_POINTER(D_002562B0 + 15, D_00256ED0);
    STORE_POINTER(D_002562B0 + 17, D_00257288);
    STORE_POINTER(D_002562E0 + 10, D_00256180);
    STORE_POINTER(D_002562E0 + 15, D_00256ED0);
    STORE_POINTER(D_002562E0 + 17, D_00257298);
    STORE_POINTER(D_00256310 + 10, D_00256180);
    STORE_POINTER(D_00256310 + 15, D_00256ED0);
    STORE_POINTER(D_00256310 + 17, D_002572A8);
    STORE_POINTER(D_00256340 + 10, D_00256180);
    STORE_POINTER(D_00256340 + 15, D_00256ED0);
    STORE_POINTER(D_00256340 + 17, D_002572B8);
    STORE_POINTER(D_00256370 + 10, D_002561C0);
    STORE_POINTER(D_00256370 + 15, D_00256F00);
    STORE_POINTER(D_00256370 + 17, D_002572C8);
    STORE_POINTER(D_002563A0 + 10, D_002561C0);
    STORE_POINTER(D_002563A0 + 15, D_00256F00);
    STORE_POINTER(D_002563A0 + 17, D_002572D8);
    STORE_POINTER(D_002563D0 + 10, D_002561C0);
    STORE_POINTER(D_002563D0 + 15, D_00256F00);
    STORE_POINTER(D_002563D0 + 17, D_002572E8);
    STORE_POINTER(D_00256400 + 10, D_002561C0);
    STORE_POINTER(D_00256400 + 15, D_00256F00);
    STORE_POINTER(D_00256400 + 17, D_002572F8);
    STORE_POINTER(D_00256430 + 10, D_002561C0);
    STORE_POINTER(D_00256430 + 15, D_00256F00);
    STORE_POINTER(D_00256430 + 17, D_00257308);
    STORE_POINTER(D_00256460 + 10, D_00256200);
    STORE_POINTER(D_00256460 + 15, D_00256F30);
    STORE_POINTER(D_00256460 + 17, D_00257318);
    STORE_POINTER(D_00256490 + 10, D_00256200);
    STORE_POINTER(D_00256490 + 15, D_00256F30);
    STORE_POINTER(D_00256490 + 17, D_00257328);
    STORE_POINTER(D_002564C0 + 10, D_00256200);
    STORE_POINTER(D_002564C0 + 15, D_00256F30);
    STORE_POINTER(D_002564C0 + 17, D_00257338);
    STORE_POINTER(D_002564F0 + 10, D_00256200);
    STORE_POINTER(D_002564F0 + 15, D_00256F30);
    STORE_POINTER(D_002564F0 + 17, D_00257348);
    STORE_POINTER(D_00256520 + 10, D_00256200);
    STORE_POINTER(D_00256520 + 15, D_00256F30);
    STORE_POINTER(D_00256520 + 17, D_00257358);
    STORE_POINTER(D_00256550 + 10, D_00256200);
    STORE_POINTER(D_00256550 + 15, D_00256F60);
    STORE_POINTER(D_00256550 + 17, D_00257318);
    STORE_POINTER(D_00256580 + 10, D_00256200);
    STORE_POINTER(D_00256580 + 15, D_00256F60);
    STORE_POINTER(D_00256580 + 17, D_00257328);
    STORE_POINTER(D_002565B0 + 10, D_00256200);
    STORE_POINTER(D_002565B0 + 15, D_00256F60);
    STORE_POINTER(D_002565B0 + 17, D_00257338);
    STORE_POINTER(D_002565E0 + 10, D_00256200);
    STORE_POINTER(D_002565E0 + 15, D_00256F60);
    STORE_POINTER(D_002565E0 + 17, D_00257348);
    STORE_POINTER(D_00256610 + 10, D_00256200);
    STORE_POINTER(D_00256610 + 15, D_00256F60);
    STORE_POINTER(D_00256610 + 17, D_00257358);
    STORE_POINTER(D_00256640 + 10, D_00256240);
    STORE_POINTER(D_00256640 + 15, D_00256F90);
    STORE_POINTER(D_00256640 + 17, D_002573A8);
    STORE_POINTER(D_00256670 + 10, D_00256240);
    STORE_POINTER(D_00256670 + 15, D_00256F90);
    STORE_POINTER(D_00256670 + 17, D_002573A8);
    STORE_POINTER(D_002566A0 + 10, D_00256240);
    STORE_POINTER(D_002566A0 + 15, D_00256F90);
    STORE_POINTER(D_002566A0 + 17, D_002573A8);
    STORE_POINTER(D_002566D0 + 10, D_00256240);
    STORE_POINTER(D_002566D0 + 15, D_00256F90);
    STORE_POINTER(D_002566D0 + 17, D_002573A8);
    STORE_POINTER(D_00256700 + 10, D_00256240);
    STORE_POINTER(D_00256700 + 15, D_00256F90);
    STORE_POINTER(D_00256700 + 17, D_002573A8);
    STORE_POINTER(D_00256A28 + 3, D_00256730);
    STORE_POINTER(D_00256A38 + 3, D_00256760);
    STORE_POINTER(D_00256A48 + 3, D_00256790);
    STORE_POINTER(D_00256A58 + 3, D_002567C0);
    STORE_POINTER(D_00256A68 + 3, D_002567F0);
    STORE_POINTER(D_00256A78 + 3, D_00256820);
    STORE_POINTER(D_00256A88 + 3, D_00256850);
    STORE_POINTER(D_00256A98 + 3, D_00256880);
    STORE_POINTER(D_00256AA8 + 3, D_002568B0);
    STORE_POINTER(D_00256AB8 + 3, D_002568E0);
    STORE_POINTER(D_00256AC8 + 3, D_00256910);
    STORE_POINTER(D_00256AD8 + 3, D_00256940);
    STORE_POINTER(D_00256AE8 + 3, D_00256970);
    STORE_POINTER(D_00256AF8 + 3, D_002569A0);
    STORE_POINTER(D_00256B08 + 3, D_002569D0);
    STORE_POINTER(D_00256B18 + 3, D_00256A00);
    STORE_POINTER(D_00256B30 + 10, D_0028C950);
    STORE_POINTER(D_00256B50 + 10, D_0028C958);
    STORE_POINTER(D_00256B70 + 10, D_0028C960);
    STORE_POINTER(D_00256B90 + 10, D_0028C968);
    STORE_POINTER(D_00256BB0 + 10, D_0028C970);
    STORE_POINTER(D_00256BD0 + 10, D_0028C978);
    STORE_POINTER(D_00256BF0 + 10, D_0028C980);
    STORE_POINTER(D_00256C10 + 10, D_0028C988);
    STORE_POINTER(D_00256C30 + 10, D_0028C990);
    STORE_POINTER(D_00256C50 + 10, D_0028C998);
    STORE_POINTER(D_00256C70 + 10, D_0028C950);
    STORE_POINTER(D_00256C90 + 10, D_0028C958);
    STORE_POINTER(D_00256CB0 + 10, D_0028C960);
    STORE_POINTER(D_00256CD0 + 10, D_0028C968);
    STORE_POINTER(D_00256CF0 + 10, D_0028C970);
    STORE_POINTER(D_00256D10 + 10, D_0028C978);
    STORE_POINTER(D_00256D30 + 10, D_0028C980);
    STORE_POINTER(D_00256D50 + 10, D_0028C988);
    STORE_POINTER(D_00256D70 + 10, D_0028C990);
    STORE_POINTER(D_00256D90 + 10, D_0028C998);
    STORE_POINTER(D_00256DB0 + 10, D_0028C9A0);
    STORE_POINTER(D_00256DD0 + 10, D_0028C9A0);
    STORE_POINTER(D_00256DF0 + 10, D_0028C9A0);
    STORE_POINTER(D_00256E10 + 10, D_0028C9A0);
    STORE_POINTER(D_00256E30 + 10, D_0028C9A0);
    STORE_POINTER(D_00256ED0 + 9, D_00256E50);
    STORE_POINTER(D_00256ED0 + 15, D_00256FC0);
    STORE_POINTER(D_00256F00 + 9, D_00256E70);
    STORE_POINTER(D_00256F00 + 15, D_00257030);
    STORE_POINTER(D_00256F30 + 9, D_00256E90);
    STORE_POINTER(D_00256F30 + 15, D_002570A0);
    STORE_POINTER(D_00256F60 + 9, D_00256E90);
    STORE_POINTER(D_00256F60 + 15, D_002570A0);
    STORE_POINTER(D_00256F90 + 9, D_00256EB0);
    STORE_POINTER(D_00256F90 + 15, D_00257110);
    STORE_POINTER(D_00256FC0, D_00256FD8);
    STORE_POINTER(D_00256FC0 + 2, D_00256FE8);
    STORE_POINTER(D_00256FC0 + 4, D_00256FF8);
    STORE_POINTER(D_00256FC0 + 6, D_00257008);
    STORE_POINTER(D_00256FC0 + 8, D_00257018);
    STORE_POINTER(D_00256FD8, D_00257138);
    STORE_POINTER(D_00256FE8, D_00257148);
    STORE_POINTER(D_00256FF8, D_00257158);
    STORE_POINTER(D_00257008, D_00257168);
    STORE_POINTER(D_00257018, D_00257178);
    STORE_POINTER(D_00257030, D_00257048);
    STORE_POINTER(D_00257030 + 2, D_00257058);
    STORE_POINTER(D_00257030 + 4, D_00257068);
    STORE_POINTER(D_00257030 + 6, D_00257078);
    STORE_POINTER(D_00257030 + 8, D_00257088);
    STORE_POINTER(D_00257048, D_00257188);
    STORE_POINTER(D_00257058, D_00257198);
    STORE_POINTER(D_00257068, D_002571A8);
    STORE_POINTER(D_00257078, D_002571B8);
    STORE_POINTER(D_00257088, D_002571C8);
    STORE_POINTER(D_002570A0, D_002570B8);
    STORE_POINTER(D_002570A0 + 2, D_002570C8);
    STORE_POINTER(D_002570A0 + 4, D_002570D8);
    STORE_POINTER(D_002570A0 + 6, D_002570E8);
    STORE_POINTER(D_002570A0 + 8, D_002570F8);
    STORE_POINTER(D_002570B8, D_002571D8);
    STORE_POINTER(D_002570C8, D_002571E8);
    STORE_POINTER(D_002570D8, D_002571F8);
    STORE_POINTER(D_002570E8, D_00257208);
    STORE_POINTER(D_002570F8, D_00257218);
    STORE_POINTER(D_00257110, D_00257128);
    STORE_POINTER(D_00257110 + 2, D_00257128);
    STORE_POINTER(D_00257110 + 4, D_00257128);
    STORE_POINTER(D_00257110 + 6, D_00257128);
    STORE_POINTER(D_00257110 + 8, D_00257128);
    STORE_POINTER(D_00257128, D_00257268);
    STORE_POINTER(D_002576C0 + 2, D_002573C0);
    STORE_POINTER(D_002576C0 + 6, D_002573F0);
    STORE_POINTER(D_002576C0 + 10, D_00257420);
    STORE_POINTER(D_002576C0 + 14, D_00257450);
    STORE_POINTER(D_002576C0 + 18, D_00257480);
    STORE_POINTER(D_002576C0 + 22, D_002574B0);
    STORE_POINTER(D_002576C0 + 26, D_002574E0);
    STORE_POINTER(D_002576C0 + 30, D_00257510);
    STORE_POINTER(D_002576C0 + 34, D_00257540);
    STORE_POINTER(D_002576C0 + 38, D_00257570);
    STORE_POINTER(D_002576C0 + 42, D_002575A0);
    STORE_POINTER(D_002576C0 + 46, D_002575D0);
    STORE_POINTER(D_002576C0 + 50, D_00257600);
    STORE_POINTER(D_002576C0 + 54, D_00257630);
    STORE_POINTER(D_002576C0 + 58, D_00257660);
    STORE_POINTER(D_002576C0 + 62, D_00257690);
    STORE_POINTER(D_002576C0 + 66, D_00257690);
    STORE_POINTER(D_002576C0 + 70, D_00257690);
    STORE_POINTER(D_002576C0 + 74, D_00257690);
    STORE_POINTER(D_002576C0 + 78, D_00257690);
}

extern u16 D_00256280[];
extern u16 D_002562B0[];
extern u16 D_002562E0[];
extern u16 D_00256310[];
extern u16 D_00256340[];
extern u16 D_00256370[];
extern u16 D_002563A0[];
extern u16 D_002563D0[];
extern u16 D_00256400[];
extern u16 D_00256430[];
extern u16 D_00256460[];
extern u16 D_00256490[];
extern u16 D_002564C0[];
extern u16 D_002564F0[];
extern u16 D_00256520[];
extern u16 D_00256550[];
extern u16 D_00256580[];
extern u16 D_002565B0[];
extern u16 D_002565E0[];
extern u16 D_00256610[];
extern u16 D_00256640[];
extern u16 D_00256670[];
extern u16 D_002566A0[];
extern u16 D_002566D0[];
extern u16 D_00256700[];
extern u16 D_00256A28[];
extern u16 D_00256A38[];
extern u16 D_00256A48[];
extern u16 D_00256A58[];
extern u16 D_00256A68[];
extern u16 D_00256A78[];
extern u16 D_00256A88[];
extern u16 D_00256A98[];
extern u16 D_00256AA8[];
extern u16 D_00256AB8[];
extern u16 D_00256AC8[];
extern u16 D_00256AD8[];
extern u16 D_00256AE8[];
extern u16 D_00256AF8[];
extern u16 D_00256B08[];
extern u16 D_00256B18[];
extern u16 D_00256B30[];
extern u16 D_00256B50[];
extern u16 D_00256B70[];
extern u16 D_00256B90[];
extern u16 D_00256BB0[];
extern u16 D_00256BD0[];
extern u16 D_00256BF0[];
extern u16 D_00256C10[];
extern u16 D_00256C30[];
extern u16 D_00256C50[];
extern u16 D_00256C70[];
extern u16 D_00256C90[];
extern u16 D_00256CB0[];
extern u16 D_00256CD0[];
extern u16 D_00256CF0[];
extern u16 D_00256D10[];
extern u16 D_00256D30[];
extern u16 D_00256D50[];
extern u16 D_00256D70[];
extern u16 D_00256D90[];
extern u16 D_00256DB0[];
extern u16 D_00256DD0[];
extern u16 D_00256DF0[];
extern u16 D_00256E10[];
extern u16 D_00256E30[];
extern u16 D_0025EF30[];
extern u16 D_0025EFB0[];
extern u16 D_0025F040[];
extern u16 D_0025F080[];
extern u16 D_0025F100[];
extern u16 D_0025F190[];
extern u16 D_0025F258[];
extern u16 D_0025F268[];
extern u16 D_0025F278[];
extern u16 D_0025F290[];
extern u16 D_0025F2F0[];
extern u16 D_0025F350[];
extern u16 D_0025F450[];
extern u16 D_0025F470[];
extern u16 D_0025F4D0[];
extern u16 D_0025F4F0[];
extern u16 D_0025F510[];
extern u16 D_0025F530[];
extern u16 D_0025F570[];
extern u16 D_0025F590[];

extern u16 D_0025F3B0_as_u16_a[];
extern u16 D_0025F3D0[];
extern u16 D_0025F400_as_u16_a[];
extern u16 D_0025F430_as_u16_a[];
extern u16 D_0025F490[];
extern u16 D_0025F4B0[];
extern u16 D_0025F550[];
extern u16 D_0028D968[];
extern u16 D_0028D970[];
extern u16 D_0028D978[];

void func_00184410(void) {
    STORE_POINTER(D_0025F290 + 8, D_0025F258);
    STORE_POINTER(D_0025F290 + 19, D_0025F258);
    STORE_POINTER(D_0025F290 + 30, D_0025EF30);
    STORE_POINTER(D_0025F290 + 39, D_0025F080);
    STORE_POINTER(D_0025F2F0 + 8, D_0025F268);
    STORE_POINTER(D_0025F2F0 + 19, D_0025F268);
    STORE_POINTER(D_0025F2F0 + 30, D_0025EFB0);
    STORE_POINTER(D_0025F2F0 + 39, D_0025F100);
    STORE_POINTER(D_0025F350 + 8, D_0025F278);
    STORE_POINTER(D_0025F350 + 19, D_0025F278);
    STORE_POINTER(D_0025F350 + 30, D_0025F040);
    STORE_POINTER(D_0025F350 + 39, D_0025F190);
    STORE_POINTER(D_0025F3B0_as_u16_a, D_0025F290);
    STORE_POINTER(D_0025F3B0 + 2, D_0025F2F0);
    STORE_POINTER(D_0025F3B0 + 4, D_0025F350);
    STORE_POINTER(D_0025F3D0, D_00256280);
    STORE_POINTER(D_0025F3D0 + 2, D_002562B0);
    STORE_POINTER(D_0025F3D0 + 4, D_002562E0);
    STORE_POINTER(D_0025F3D0 + 6, D_00256310);
    STORE_POINTER(D_0025F3D0 + 8, D_00256340);
    STORE_POINTER(D_0025F3D0 + 10, D_00256370);
    STORE_POINTER(D_0025F3D0 + 12, D_002563A0);
    STORE_POINTER(D_0025F3D0 + 14, D_002563D0);
    STORE_POINTER(D_0025F3D0 + 16, D_00256400);
    STORE_POINTER(D_0025F3D0 + 18, D_00256430);
    STORE_POINTER(D_0025F400_as_u16_a, D_00256460);
    STORE_POINTER(D_0025F400 + 2, D_00256490);
    STORE_POINTER(D_0025F400 + 4, D_002564C0);
    STORE_POINTER(D_0025F400 + 6, D_002564F0);
    STORE_POINTER(D_0025F400 + 8, D_00256520);
    STORE_POINTER(D_0025F400 + 10, D_00256550);
    STORE_POINTER(D_0025F400 + 12, D_00256580);
    STORE_POINTER(D_0025F400 + 14, D_002565B0);
    STORE_POINTER(D_0025F400 + 16, D_002565E0);
    STORE_POINTER(D_0025F400 + 18, D_00256610);
    STORE_POINTER(D_0025F430_as_u16_a, D_00256640);
    STORE_POINTER(D_0025F430 + 2, D_00256670);
    STORE_POINTER(D_0025F430 + 4, D_002566A0);
    STORE_POINTER(D_0025F430 + 6, D_002566D0);
    STORE_POINTER(D_0025F430 + 8, D_00256700);
    STORE_POINTER(D_0028D968, D_0025F450);
    STORE_POINTER(D_0028D968 + 2, D_0025F470);
    STORE_POINTER(D_0025F450, D_00256A28);
    STORE_POINTER(D_0025F450 + 2, D_00256A38);
    STORE_POINTER(D_0025F450 + 4, D_00256A48);
    STORE_POINTER(D_0025F450 + 6, D_00256A58);
    STORE_POINTER(D_0025F450 + 8, D_00256A68);
    STORE_POINTER(D_0025F470, D_00256A78);
    STORE_POINTER(D_0025F470 + 2, D_00256A88);
    STORE_POINTER(D_0025F470 + 4, D_00256A98);
    STORE_POINTER(D_0025F470 + 6, D_00256AA8);
    STORE_POINTER(D_0025F470 + 8, D_00256AB8);
    STORE_POINTER(D_0025F490, D_00256AC8);
    STORE_POINTER(D_0025F490 + 2, D_00256AD8);
    STORE_POINTER(D_0025F490 + 4, D_00256AE8);
    STORE_POINTER(D_0025F490 + 6, D_00256AF8);
    STORE_POINTER(D_0025F490 + 8, D_00256B08);
    STORE_POINTER(D_0025F4B0, D_00256B18);
    STORE_POINTER(D_0025F4B0 + 2, D_00256B18);
    STORE_POINTER(D_0025F4B0 + 4, D_00256B18);
    STORE_POINTER(D_0025F4B0 + 6, D_00256B18);
    STORE_POINTER(D_0025F4B0 + 8, D_00256B18);
    STORE_POINTER(D_0028D970, D_0025F4D0);
    STORE_POINTER(D_0028D970 + 2, D_0025F4F0);
    STORE_POINTER(D_0025F4D0, D_00256B30);
    STORE_POINTER(D_0025F4D0 + 2, D_00256B50);
    STORE_POINTER(D_0025F4D0 + 4, D_00256B70);
    STORE_POINTER(D_0025F4D0 + 6, D_00256B90);
    STORE_POINTER(D_0025F4D0 + 8, D_00256BB0);
    STORE_POINTER(D_0025F4F0, D_00256BD0);
    STORE_POINTER(D_0025F4F0 + 2, D_00256BF0);
    STORE_POINTER(D_0025F4F0 + 4, D_00256C10);
    STORE_POINTER(D_0025F4F0 + 6, D_00256C30);
    STORE_POINTER(D_0025F4F0 + 8, D_00256C50);
    STORE_POINTER(D_0028D978, D_0025F510);
    STORE_POINTER(D_0028D978 + 2, D_0025F530);
    STORE_POINTER(D_0025F510, D_00256C70);
    STORE_POINTER(D_0025F510 + 2, D_00256C90);
    STORE_POINTER(D_0025F510 + 4, D_00256CB0);
    STORE_POINTER(D_0025F510 + 6, D_00256CD0);
    STORE_POINTER(D_0025F510 + 8, D_00256CF0);
    STORE_POINTER(D_0025F530, D_00256D10);
    STORE_POINTER(D_0025F530 + 2, D_00256D30);
    STORE_POINTER(D_0025F530 + 4, D_00256D50);
    STORE_POINTER(D_0025F530 + 6, D_00256D70);
    STORE_POINTER(D_0025F530 + 8, D_00256D90);
    STORE_POINTER(D_0025F550, D_00256DB0);
    STORE_POINTER(D_0025F550 + 2, D_00256DD0);
    STORE_POINTER(D_0025F550 + 4, D_00256DF0);
    STORE_POINTER(D_0025F550 + 6, D_00256E10);
    STORE_POINTER(D_0025F550 + 8, D_00256E30);
    STORE_POINTER(D_0028D978 + 4, D_0025F570);
    STORE_POINTER(D_0028D978 + 6, D_0025F590);
}

extern u16 D_0025C680[];
extern u16 D_0025C6B0[];
extern u16 D_0025C6E0[];
extern u16 D_0025C710[];
extern u16 D_0025C740[];
extern u16 D_0025C770[];
extern u16 D_0025C7A0[];
extern u16 D_0025C7D0[];
extern u16 D_0025C800[];
extern u16 D_0025C830[];
extern u16 D_0025C860[];
extern u16 D_0025C890[];
extern u16 D_0025C8C0[];
extern u16 D_0025C8F0[];
extern u16 D_0025C920[];
extern u16 D_0025C950[];
extern u16 D_0025C9A0[];
extern u16 D_0025C9F0[];
extern u16 D_0025CA40[];
extern u16 D_0025CA90[];
extern u16 D_0025D010[];
extern u16 D_0025D040[];
extern u16 D_0025D070[];
extern u16 D_0025D0A0[];
extern u16 D_0025D0D0[];
extern u16 D_0025D100[];
extern u16 D_0025D130[];
extern u16 D_0025D160[];
extern u16 D_0025D190[];
extern u16 D_0025D1C0[];
extern u16 D_0025D1F0[];
extern u16 D_0025D220[];
extern u16 D_0025D250[];
extern u16 D_0025D280[];
extern u16 D_0025D2B0[];
extern u16 D_0025D2E0[];
extern u16 D_0025D330[];
extern u16 D_0025D380[];
extern u16 D_0025D3D0[];
extern u16 D_0025D420[];
extern u16 D_0025D9B0[];
extern u16 D_0025D9E0[];
extern u16 D_0025DA10[];
extern u16 D_0025DA40[];
extern u16 D_0025DA70[];
extern u16 D_0025DAA0[];
extern u16 D_0025DAD0[];
extern u16 D_0025DB00[];
extern u16 D_0025DB30[];
extern u16 D_0025DB60[];
extern u16 D_0025DB90[];
extern u16 D_0025DBC0[];
extern u16 D_0025DBF0[];
extern u16 D_0025DC20[];
extern u16 D_0025DC50[];
extern u16 D_0025DC80[];
extern u16 D_0025DCD0[];
extern u16 D_0025DD20[];
extern u16 D_0025DD70[];
extern u16 D_0025DDC0[];
extern u16 D_0025E330[];
extern u16 D_0025E360[];
extern u16 D_0025E390[];
extern u16 D_0025E3C0[];
extern u16 D_0025E3F0[];
extern u16 D_0025E420[];
extern u16 D_0025E450[];
extern u16 D_0025E480[];
extern u16 D_0025E4B0[];
extern u16 D_0025E4E0[];
extern u16 D_0025E510[];
extern u16 D_0025E540[];
extern u16 D_0025E570[];
extern u16 D_0025E5A0[];
extern u16 D_0025E5D0[];
extern u16 D_0025E600[];
extern u16 D_0025E650[];
extern u16 D_0025E6A0[];
extern u16 D_0025E6F0[];
extern u16 D_0025E740[];
extern u16 D_0025ED00[];
extern u16 D_0025ED20[];
extern u16 D_0025ED40[];
extern u16 D_0025ED60[];
extern u16 D_0025ED90[];
extern u16 D_0025EDB0[];
extern u16 D_0025EDD0[];
extern u16 D_0025EDF0[];
extern u16 D_0025EE20[];
extern u16 D_0025EE40[];
extern u16 D_0025EE60[];
extern u16 D_0025EE80[];
extern u16 D_0025EEB0[];
extern u16 D_0025EED0[];
extern u16 D_0025EEF0[];
extern u16 D_0025EF10[];

extern u16 D_0025ECF0_as_u16_a[];
extern u16 D_0025ED80_as_u16_a[];
extern u16 D_0025EE10_as_u16_a[];
extern u16 D_0025EEA0_as_u16_a[];

void func_00185320(void) {
    STORE_POINTER(D_0025ECF0_as_u16_a, D_0025ED00);
    STORE_POINTER(D_0025ECF0 + 2, D_0025ED40);
    STORE_POINTER(D_0025ECF0 + 4, D_0025ED20);
    STORE_POINTER(D_0025ECF0 + 6, D_0025ED60);
    STORE_POINTER(D_0025ED00, D_0025C680);
    STORE_POINTER(D_0025ED00 + 2, D_0025C6E0);
    STORE_POINTER(D_0025ED00 + 4, D_0025C740);
    STORE_POINTER(D_0025ED00 + 6, D_0025C7A0);
    STORE_POINTER(D_0025ED00 + 8, D_0025C800);
    STORE_POINTER(D_0025ED20, D_0025D010);
    STORE_POINTER(D_0025ED20 + 2, D_0025D070);
    STORE_POINTER(D_0025ED20 + 4, D_0025D0D0);
    STORE_POINTER(D_0025ED20 + 6, D_0025D130);
    STORE_POINTER(D_0025ED20 + 8, D_0025D190);
    STORE_POINTER(D_0025ED40, D_0025D9B0);
    STORE_POINTER(D_0025ED40 + 2, D_0025DA10);
    STORE_POINTER(D_0025ED40 + 4, D_0025DA70);
    STORE_POINTER(D_0025ED40 + 6, D_0025DAD0);
    STORE_POINTER(D_0025ED40 + 8, D_0025DB30);
    STORE_POINTER(D_0025ED60, D_0025E330);
    STORE_POINTER(D_0025ED60 + 2, D_0025E390);
    STORE_POINTER(D_0025ED60 + 4, D_0025E3F0);
    STORE_POINTER(D_0025ED60 + 6, D_0025E450);
    STORE_POINTER(D_0025ED60 + 8, D_0025E4B0);
    STORE_POINTER(D_0025ED80_as_u16_a, D_0025ED90);
    STORE_POINTER(D_0025ED80 + 2, D_0025EDD0);
    STORE_POINTER(D_0025ED80 + 4, D_0025EDB0);
    STORE_POINTER(D_0025ED80 + 6, D_0025EDF0);
    STORE_POINTER(D_0025ED90, D_0025C6B0);
    STORE_POINTER(D_0025ED90 + 2, D_0025C710);
    STORE_POINTER(D_0025ED90 + 4, D_0025C770);
    STORE_POINTER(D_0025ED90 + 6, D_0025C7D0);
    STORE_POINTER(D_0025ED90 + 8, D_0025C830);
    STORE_POINTER(D_0025EDB0, D_0025D040);
    STORE_POINTER(D_0025EDB0 + 2, D_0025D0A0);
    STORE_POINTER(D_0025EDB0 + 4, D_0025D100);
    STORE_POINTER(D_0025EDB0 + 6, D_0025D160);
    STORE_POINTER(D_0025EDB0 + 8, D_0025D1C0);
    STORE_POINTER(D_0025EDD0, D_0025D9E0);
    STORE_POINTER(D_0025EDD0 + 2, D_0025DA40);
    STORE_POINTER(D_0025EDD0 + 4, D_0025DAA0);
    STORE_POINTER(D_0025EDD0 + 6, D_0025DB00);
    STORE_POINTER(D_0025EDD0 + 8, D_0025DB60);
    STORE_POINTER(D_0025EDF0, D_0025E360);
    STORE_POINTER(D_0025EDF0 + 2, D_0025E3C0);
    STORE_POINTER(D_0025EDF0 + 4, D_0025E420);
    STORE_POINTER(D_0025EDF0 + 6, D_0025E480);
    STORE_POINTER(D_0025EDF0 + 8, D_0025E4E0);
    STORE_POINTER(D_0025EE10_as_u16_a, D_0025EE20);
    STORE_POINTER(D_0025EE10 + 2, D_0025EE60);
    STORE_POINTER(D_0025EE10 + 4, D_0025EE40);
    STORE_POINTER(D_0025EE10 + 6, D_0025EE80);
    STORE_POINTER(D_0025EE20, D_0025C860);
    STORE_POINTER(D_0025EE20 + 2, D_0025C890);
    STORE_POINTER(D_0025EE20 + 4, D_0025C8C0);
    STORE_POINTER(D_0025EE20 + 6, D_0025C8F0);
    STORE_POINTER(D_0025EE20 + 8, D_0025C920);
    STORE_POINTER(D_0025EE40, D_0025D1F0);
    STORE_POINTER(D_0025EE40 + 2, D_0025D220);
    STORE_POINTER(D_0025EE40 + 4, D_0025D250);
    STORE_POINTER(D_0025EE40 + 6, D_0025D280);
    STORE_POINTER(D_0025EE40 + 8, D_0025D2B0);
    STORE_POINTER(D_0025EE60, D_0025DB90);
    STORE_POINTER(D_0025EE60 + 2, D_0025DBC0);
    STORE_POINTER(D_0025EE60 + 4, D_0025DBF0);
    STORE_POINTER(D_0025EE60 + 6, D_0025DC20);
    STORE_POINTER(D_0025EE60 + 8, D_0025DC50);
    STORE_POINTER(D_0025EE80, D_0025E510);
    STORE_POINTER(D_0025EE80 + 2, D_0025E540);
    STORE_POINTER(D_0025EE80 + 4, D_0025E570);
    STORE_POINTER(D_0025EE80 + 6, D_0025E5A0);
    STORE_POINTER(D_0025EE80 + 8, D_0025E5D0);
    STORE_POINTER(D_0025EEA0_as_u16_a, D_0025EEB0);
    STORE_POINTER(D_0025EEA0 + 2, D_0025EEF0);
    STORE_POINTER(D_0025EEA0 + 4, D_0025EED0);
    STORE_POINTER(D_0025EEA0 + 6, D_0025EF10);
    STORE_POINTER(D_0025EEB0, D_0025C950);
    STORE_POINTER(D_0025EEB0 + 2, D_0025C9A0);
    STORE_POINTER(D_0025EEB0 + 4, D_0025C9F0);
    STORE_POINTER(D_0025EEB0 + 6, D_0025CA40);
    STORE_POINTER(D_0025EEB0 + 8, D_0025CA90);
    STORE_POINTER(D_0025EED0, D_0025D2E0);
    STORE_POINTER(D_0025EED0 + 2, D_0025D330);
    STORE_POINTER(D_0025EED0 + 4, D_0025D380);
    STORE_POINTER(D_0025EED0 + 6, D_0025D3D0);
    STORE_POINTER(D_0025EED0 + 8, D_0025D420);
    STORE_POINTER(D_0025EEF0, D_0025DC80);
    STORE_POINTER(D_0025EEF0 + 2, D_0025DCD0);
    STORE_POINTER(D_0025EEF0 + 4, D_0025DD20);
    STORE_POINTER(D_0025EEF0 + 6, D_0025DD70);
    STORE_POINTER(D_0025EEF0 + 8, D_0025DDC0);
    STORE_POINTER(D_0025EF10, D_0025E600);
    STORE_POINTER(D_0025EF10 + 2, D_0025E650);
    STORE_POINTER(D_0025EF10 + 4, D_0025E6A0);
    STORE_POINTER(D_0025EF10 + 6, D_0025E6F0);
    STORE_POINTER(D_0025EF10 + 8, D_0025E740);
}

extern u16 func_00158C30[];
extern u16 func_00159AC0[];
extern u16 D_00258880[];
extern u16 D_00258900[];
extern u16 D_0028C0D8[];
extern u16 D_0028C0DC[];
extern void func_001570B0(void);
extern void func_00157140(void);
extern void func_00158CF0(void);
extern void func_00158E10(void);
extern void func_00158ED0(void);
extern void func_00159B20(void);
extern void func_0015A290(void);
extern void func_0015A390(void);
extern void entity_draw_layer1(void);
extern void sprite_draw_layer1(void);

extern u16 D_00258560[];
extern u16 D_002586E0[];
extern u16 D_00258760[];
extern u16 D_00258770[];
extern u16 D_0028C9D8_as_u16_a[];

void func_00186310(void) {
    STORE_POINTER(D_0028C9B0 + 4, func_00157140);
    STORE_POINTER(D_0028C9B0 + 6, func_001570B0);
    STORE_POINTER(D_00258560, func_00158C30);
    STORE_POINTER(D_00258560 + 2, func_00158CF0);
    STORE_POINTER(D_00258560 + 4, func_00158E10);
    STORE_POINTER(D_00258560 + 6, func_00158ED0);
    STORE_POINTER(D_00258560 + 8, func_00158C30);
    STORE_POINTER(D_00258560 + 10, func_00158CF0);
    STORE_POINTER(D_00258560 + 12, func_00158E10);
    STORE_POINTER(D_00258560 + 14, func_00158ED0);
    STORE_POINTER(D_002586E0, func_00159AC0);
    STORE_POINTER(D_002586E0 + 2, func_00159B20);
    STORE_POINTER(D_002586E0 + 4, func_00159AC0);
    STORE_POINTER(D_002586E0 + 6, func_00159B20);
    STORE_POINTER(D_00258760, func_0015A390);
    STORE_POINTER(D_00258760 + 2, func_0015A290);
    STORE_POINTER(D_00258760 + 4, func_0015A290);
    STORE_POINTER(D_00258760 + 6, func_0015A290);
    STORE_POINTER(D_00258770, func_0015A290);
    STORE_POINTER(D_00258770 + 2, func_0015A290);
    STORE_POINTER(D_00258770 + 4, func_0015A390);
    STORE_POINTER(D_00258770 + 6, func_0015A390);
    STORE_POINTER(D_00258770 + 8, func_0015A290);
    STORE_POINTER(D_00258770 + 10, func_0015A290);
    STORE_POINTER(D_00258770 + 12, func_0015A290);
    STORE_POINTER(D_00258770 + 14, func_0015A390);
    STORE_POINTER(D_0028C9D8_as_u16_a, D_00258880);
    STORE_POINTER(D_0028C9D8 + 2, D_00258900);
    STORE_POINTER(D_002589B0 + 10, entity_draw_layer1);
    STORE_POINTER(D_002589B0 + 12, sprite_draw_layer1);
    STORE_POINTER(D_00257C10 + 104, D_0028C0DC);
    STORE_POINTER(D_00257C10 + 112, D_0028C0DC);
    STORE_POINTER(D_00257C10 + 120, D_0028C0D8);
    STORE_POINTER(D_00257C10 + 128, D_0028C0D8);
}

extern u16 D_00253250[];
extern u16 D_00253280[];

extern u16 g_explosion_test_labels[];

void func_00186760(void) {
    STORE_POINTER(g_explosion_test_labels, D_00253250);
    STORE_POINTER(g_explosion_test_labels + 2, D_00253280);
}

extern u16 D_0028C0C0[];
extern u16 D_0028C0C8[];
extern void entity_draw_layer2(void);
extern void entity_draw_layer3(void);
extern void entity_draw_layer4(void);
extern void entity_draw_layer5(void);
extern void sprite_draw_layer2(void);
extern void sprite_draw_layer3(void);
extern void sprite_draw_layer4(void);
extern void sprite_draw_layer5(void);

extern u16 D_0025B100_as_u16_a[];

void func_001867B0(void) {
    STORE_POINTER(D_0025B100_as_u16_a, entity_draw_layer1);
    STORE_POINTER(D_0025B100 + 2, sprite_draw_layer1);
    STORE_POINTER(D_0025B100 + 4, entity_draw_layer1);
    STORE_POINTER(D_0025B100 + 6, sprite_draw_layer1);
    STORE_POINTER(D_0025B100 + 8, entity_draw_layer2);
    STORE_POINTER(D_0025B100 + 10, sprite_draw_layer2);
    STORE_POINTER(D_0025B100 + 12, entity_draw_layer3);
    STORE_POINTER(D_0025B100 + 14, sprite_draw_layer3);
    STORE_POINTER(D_0025B100 + 16, entity_draw_layer4);
    STORE_POINTER(D_0025B100 + 18, sprite_draw_layer4);
    STORE_POINTER(D_0025B100 + 20, entity_draw_layer5);
    STORE_POINTER(D_0025B100 + 22, sprite_draw_layer5);
    STORE_POINTER(D_0025B180 + 10, entity_draw_layer1);
    STORE_POINTER(D_0025B180 + 12, sprite_draw_layer1);
    STORE_POINTER(D_0025B450 + 10, entity_draw_layer1);
    STORE_POINTER(D_0025B450 + 12, sprite_draw_layer1);
    STORE_POINTER(D_0025B6C0 + 33, D_0028C0C8);
    STORE_POINTER(D_0025B6C0 + 40, D_0028C0C8);
    STORE_POINTER(D_0025B6C0 + 47, D_0028C0C0);
    STORE_POINTER(D_0025B6C0 + 54, D_0028C0C0);
    STORE_POINTER(D_0025B780 + 33, D_0028C0C8);
    STORE_POINTER(D_0025B780 + 40, D_0028C0C8);
}

extern u16 D_00244870[];
extern u16 D_002448B0[];
extern u16 D_002448F0[];
extern u16 D_00244970[];
extern u16 D_002449B0[];
extern u16 D_002449F0[];
extern u16 D_002601B0_as_u16_a[];
extern u16 D_002601F0_as_u16_a[];
extern u16 D_00260230_as_u16_a[];
extern u16 D_002610F0[];
extern u16 D_00261130[];
extern u16 D_00261170[];
extern u16 D_002611B0[];
extern u16 D_002611F0[];
extern u16 D_0028C0D0[];


void func_00186A80(void) {
    STORE_POINTER(D_00262720 + 243, D_0028C0D0);
    STORE_POINTER(D_00262B50 + 4, D_002610F0);
    STORE_POINTER(D_00262B50 + 11, D_002601B0_as_u16_a);
    STORE_POINTER(D_00262B50 + 18, D_002601F0_as_u16_a);
    STORE_POINTER(D_00262B50 + 25, D_00260230_as_u16_a);
    STORE_POINTER(D_00262B50 + 32, D_00261170);
    STORE_POINTER(D_00262B50 + 39, D_00261130);
    STORE_POINTER(D_00262B50 + 46, D_002611B0);
    STORE_POINTER(D_00262B50 + 53, D_002611F0);
    STORE_POINTER(D_00262B50 + 60, D_00244870);
    STORE_POINTER(D_00262B50 + 67, D_002448B0);
    STORE_POINTER(D_00262B50 + 74, D_002448F0);
    STORE_POINTER(D_00262B50 + 81, D_00244970);
    STORE_POINTER(D_00262B50 + 88, D_002449B0);
    STORE_POINTER(D_00262B50 + 95, D_002449F0);
}


extern const char D_00275880[];
extern const char D_002758A0[];
extern const char D_002758C0[];
extern const char D_002758E0[];
extern const char D_00275900[];
extern const char D_00275920[];
extern const char D_00275940[];
extern const char D_00275960[];
extern const char D_00275980[];
extern const char D_002759A0[];
extern const char D_002759C0[];
extern const char D_002759E0[];
extern const char D_00275A00[];
extern const char D_00275A20[];
extern const char D_00275A40[];
extern const char D_00275A60[];
extern const char D_00275A80[];
extern const char D_00275AA0[];
extern const char D_00275AC0[];
extern const char D_00275AE0[];
extern const char D_00275B00[];
extern const char D_00275B20[];
extern const char D_00275B40[];
extern const char D_00275B60[];
extern const char D_00275B80[];
extern const char D_00275BA0[];
extern const char D_00275BC0[];

extern u16 D_00247080[];
extern u16 D_00261630[];
extern void func_001D5780(void);
extern void func_001D58F0(void);
extern void func_001D5CA0(void);
extern void func_001D60F0(void);
extern void func_001D6160(void);
extern void func_001D6410(void);
extern void func_001D6830(void);

extern u16 D_002635C0_as_u16_a[];
extern u16 D_002635C2[];
extern u16 D_00263610_as_u16_a[];
extern u16 D_00263612[];

void func_00186CA0(void) {
    if (D_00263390[103] != 0x67) {
        printf((const char *)D_00275880);
    }
    STORE_POINTER(D_00263390 + 103, D_0028C0D0);
    if (D_00263590[4] != 0x4) {
        printf((const char *)D_002758A0);
    }
    STORE_POINTER(D_00263590 + 4, D_002610F0);
    if (D_00263590[11] != 0xb) {
        printf((const char *)D_002758C0);
    }
    STORE_POINTER(D_00263590 + 11, D_00261630);
    if (D_00263590[18] != 0x12) {
        printf((const char *)D_002758E0);
    }
    STORE_POINTER(D_00263590 + 18, D_00247080);
    if (D_002635C0_as_u16_a[0] != 0x0) {
        printf((const char *)D_00275900);
    }
    STORE_POINTER(D_002635C0_as_u16_a, func_001D5780);
    if (D_002635C2[1] != 0x2) {
        printf((const char *)D_00275920);
    }
    STORE_POINTER(D_002635C2 + 1, func_001D58F0);
    if (D_002635C2[3] != 0x4) {
        printf((const char *)D_00275940);
    }
    STORE_POINTER(D_002635C2 + 3, func_001D5CA0);
    if (D_002635C2[5] != 0x6) {
        printf((const char *)D_00275960);
    }
    STORE_POINTER(D_002635C2 + 5, func_001D58F0);
    if (D_002635C2[7] != 0x8) {
        printf((const char *)D_00275980);
    }
    STORE_POINTER(D_002635C2 + 7, func_001D5CA0);
    if (D_002635C2[9] != 0xa) {
        printf((const char *)D_002759A0);
    }
    STORE_POINTER(D_002635C2 + 9, func_001D6410);
    if (D_002635C2[11] != 0xc) {
        printf((const char *)D_002759C0);
    }
    STORE_POINTER(D_002635C2 + 11, func_001D6830);
    if (D_002635E0[8] != 0x0) {
        printf((const char *)D_002759E0);
    }
    STORE_POINTER(D_002635E0 + 8, func_001D60F0);
    if (D_002635E0[10] != 0x2) {
        printf((const char *)D_00275A00);
    }
    STORE_POINTER(D_002635E0 + 10, func_001D60F0);
    if (D_002635E0[12] != 0x4) {
        printf((const char *)D_00275A20);
    }
    STORE_POINTER(D_002635E0 + 12, func_001D60F0);
    if (D_002635E0[14] != 0x6) {
        printf((const char *)D_00275A40);
    }
    STORE_POINTER(D_002635E0 + 14, func_001D60F0);
    if (D_002635E0[16] != 0x8) {
        printf((const char *)D_00275A60);
    }
    STORE_POINTER(D_002635E0 + 16, func_001D60F0);
    if (D_002635E0[18] != 0xa) {
        printf((const char *)D_00275A80);
    }
    STORE_POINTER(D_002635E0 + 18, func_001D60F0);
    if (D_002635E0[20] != 0xc) {
        printf((const char *)D_00275AA0);
    }
    STORE_POINTER(D_002635E0 + 20, func_001D60F0);
    if (D_002635E0[22] != 0xe) {
        printf((const char *)D_00275AC0);
    }
    STORE_POINTER(D_002635E0 + 22, func_001D60F0);
    if (D_00263610_as_u16_a[0] != 0x0) {
        printf((const char *)D_00275AE0);
    }
    STORE_POINTER(D_00263610_as_u16_a, func_001D6160);
    if (D_00263612[1] != 0x2) {
        printf((const char *)D_00275B00);
    }
    STORE_POINTER(D_00263612 + 1, func_001D6160);
    if (D_00263612[3] != 0x4) {
        printf((const char *)D_00275B20);
    }
    STORE_POINTER(D_00263612 + 3, func_001D6160);
    if (D_00263612[5] != 0x6) {
        printf((const char *)D_00275B40);
    }
    STORE_POINTER(D_00263612 + 5, func_001D6160);
    if (D_00263612[7] != 0x8) {
        printf((const char *)D_00275B60);
    }
    STORE_POINTER(D_00263612 + 7, func_001D6160);
    if (D_00263612[9] != 0xa) {
        printf((const char *)D_00275B80);
    }
    STORE_POINTER(D_00263612 + 9, func_001D6160);
    if (D_00263612[11] != 0xc) {
        printf((const char *)D_00275BA0);
    }
    STORE_POINTER(D_00263612 + 11, func_001D6160);
    if (D_00263612[13] != 0xe) {
        printf((const char *)D_00275BC0);
    }
    STORE_POINTER(D_00263612 + 13, func_001D6160);
}

extern u16 D_00261D30[];


void func_00187300(void) {
    STORE_POINTER(D_00265B60 + 91, D_00261D30);
    STORE_POINTER(D_00265F60 + 3, D_00261D30);
    STORE_POINTER(D_00266330 + 3, D_00261D30);
}

extern void entity_draw_layer1_keep(void);
extern void entity_draw_layer2_keep(void);
extern void entity_draw_layer3_keep(void);
extern void entity_draw_layer4_keep(void);
extern void entity_draw_layer5_keep(void);
extern void entity_draw_layer1_zoom(void);
extern void entity_draw_layer2_zoom(void);
extern void entity_draw_layer3_zoom(void);
extern void entity_draw_layer4_zoom(void);
extern void entity_draw_layer5_zoom(void);
extern void sprite_draw_layer1_keep(void);
extern void sprite_draw_layer2_keep(void);
extern void sprite_draw_layer3_keep(void);
extern void sprite_draw_layer4_keep(void);
extern void sprite_draw_layer5_keep(void);

extern u16 D_0025AE10[];
extern u16 D_0025AE50[];
extern u16 D_0025AE70[];

void func_00187360(void) {
    STORE_POINTER(D_0025A0B0 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A0B0 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A0B0 + 47, D_0028C0C0);
    STORE_POINTER(D_0025A0B0 + 54, D_0028C0C0);
    STORE_POINTER(D_0025A160 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A160 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A160 + 47, D_0028C0C0);
    STORE_POINTER(D_0025A160 + 54, D_0028C0C0);
    STORE_POINTER(D_0025A230 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A230 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A2C0 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A2C0 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A2C0 + 47, D_0028C0C0);
    STORE_POINTER(D_0025A3B0 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A3B0 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A3B0 + 47, D_0028C0C0);
    STORE_POINTER(D_0025A3B0 + 54, D_0028C0C0);
    STORE_POINTER(D_0025A4B0 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A4B0 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A4B0 + 47, D_0028C0C0);
    STORE_POINTER(D_0025A5A0 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A5A0 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A5A0 + 47, D_0028C0C0);
    STORE_POINTER(D_0025AD90 + 19, D_0028C0C8);
    STORE_POINTER(D_0025AD90 + 26, D_0028C0C8);
    STORE_POINTER(D_0025AD90 + 33, D_0028C0C0);
    STORE_POINTER(D_0025AE10, entity_draw_layer1);
    STORE_POINTER(D_0025AE10 + 2, entity_draw_layer1);
    STORE_POINTER(D_0025AE10 + 4, entity_draw_layer2);
    STORE_POINTER(D_0025AE10 + 6, entity_draw_layer3);
    STORE_POINTER(D_0025AE10 + 8, entity_draw_layer4);
    STORE_POINTER(D_0025AE10 + 10, entity_draw_layer5);
    STORE_POINTER(D_0025AE10 + 16, entity_draw_layer1_keep);
    STORE_POINTER(D_0025AE10 + 18, entity_draw_layer1_keep);
    STORE_POINTER(D_0025AE10 + 20, entity_draw_layer2_keep);
    STORE_POINTER(D_0025AE10 + 22, entity_draw_layer3_keep);
    STORE_POINTER(D_0025AE10 + 24, entity_draw_layer4_keep);
    STORE_POINTER(D_0025AE10 + 26, entity_draw_layer5_keep);
    STORE_POINTER(D_0025AE50, entity_draw_layer1_zoom);
    STORE_POINTER(D_0025AE50 + 2, entity_draw_layer1_zoom);
    STORE_POINTER(D_0025AE50 + 4, entity_draw_layer2_zoom);
    STORE_POINTER(D_0025AE50 + 6, entity_draw_layer3_zoom);
    STORE_POINTER(D_0025AE50 + 8, entity_draw_layer4_zoom);
    STORE_POINTER(D_0025AE50 + 10, entity_draw_layer5_zoom);
    STORE_POINTER(D_0025AE70, sprite_draw_layer1);
    STORE_POINTER(D_0025AE70 + 2, sprite_draw_layer1);
    STORE_POINTER(D_0025AE70 + 4, sprite_draw_layer2);
    STORE_POINTER(D_0025AE70 + 6, sprite_draw_layer3);
    STORE_POINTER(D_0025AE70 + 8, sprite_draw_layer4);
    STORE_POINTER(D_0025AE70 + 10, sprite_draw_layer5);
    STORE_POINTER(D_0025AE70 + 16, sprite_draw_layer1_keep);
    STORE_POINTER(D_0025AE70 + 18, sprite_draw_layer1_keep);
    STORE_POINTER(D_0025AE70 + 20, sprite_draw_layer2_keep);
    STORE_POINTER(D_0025AE70 + 22, sprite_draw_layer3_keep);
    STORE_POINTER(D_0025AE70 + 24, sprite_draw_layer4_keep);
    STORE_POINTER(D_0025AE70 + 26, sprite_draw_layer5_keep);
}

extern u16 D_002461D0[];
extern u16 D_002469D0[];
extern u16 D_00246A10[];
extern u16 D_00246A50[];
extern u16 D_00246A90[];
extern u16 D_00246AD0[];
extern u16 D_00246B10[];
extern u16 D_00246B50[];
extern u16 D_00246B90[];
extern u16 D_00246BD0[];
extern u16 D_00246C10[];
extern u16 D_00260270[];
extern u16 D_002602B0[];
extern u16 D_002602F0[];


void func_00187AE0(void) {
    STORE_POINTER(D_00263030 + 48, D_0028C0C8);
    STORE_POINTER(D_00263030 + 56, D_0028C0C8);
    STORE_POINTER(D_00263030 + 64, D_0028C0C0);
    STORE_POINTER(D_00263030 + 72, D_0028C0C0);
    STORE_POINTER(D_002630D0 + 4, D_00260270);
    STORE_POINTER(D_002630D0 + 11, D_002602B0);
    STORE_POINTER(D_002630D0 + 18, D_002602F0);
    STORE_POINTER(D_00263290 + 4, D_002610F0);
    STORE_POINTER(D_00263290 + 11, D_00260270);
    STORE_POINTER(D_00263290 + 18, D_002602B0);
    STORE_POINTER(D_00263290 + 25, D_002602F0);
    STORE_POINTER(D_00263290 + 32, D_002461D0);
    STORE_POINTER(D_00263290 + 39, D_002469D0);
    STORE_POINTER(D_00263290 + 46, D_00246A10);
    STORE_POINTER(D_00263290 + 53, D_00246A50);
    STORE_POINTER(D_00263290 + 60, D_00246A90);
    STORE_POINTER(D_00263290 + 67, D_00246AD0);
    STORE_POINTER(D_00263290 + 74, D_00246B10);
    STORE_POINTER(D_00263290 + 81, D_00246B50);
    STORE_POINTER(D_00263290 + 88, D_00246B90);
    STORE_POINTER(D_00263290 + 95, D_00246BD0);
    STORE_POINTER(D_00263290 + 102, D_00246C10);
}

extern u16 D_00249E10[];
extern u16 D_00249E50[];
extern u16 D_00249E90[];
extern u16 D_002616F0_as_u16_a[];
extern u16 D_00261770_as_u16_a[];
extern u16 D_002617B0_as_u16_a[];
extern u16 D_002617F0_as_u16_a[];
extern u16 D_00261830_as_u16_a[];
extern u16 D_00261870_as_u16_a[];
extern u16 D_002619B0[];
extern u16 D_002619F0[];
extern u16 D_00263AE0[];
extern u16 D_00263B10[];
extern u16 D_00263B30[];


void func_00187E00(void) {
    STORE_POINTER(D_002638B0 + 47, D_0028C0C8);
    STORE_POINTER(D_002638B0 + 54, D_0028C0C8);
    STORE_POINTER(D_002638B0 + 61, D_0028C0C0);
    STORE_POINTER(D_002638B0 + 68, D_0028C0C0);
    STORE_POINTER(D_002639B0 + 4, D_002610F0);
    STORE_POINTER(D_002639B0 + 11, D_002616F0_as_u16_a);
    STORE_POINTER(D_002639B0 + 18, D_002617B0_as_u16_a);
    STORE_POINTER(D_002639B0 + 25, D_002617F0_as_u16_a);
    STORE_POINTER(D_002639B0 + 32, D_00261870_as_u16_a);
    STORE_POINTER(D_002639B0 + 39, D_002619B0);
    STORE_POINTER(D_002639B0 + 46, D_00249E10);
    STORE_POINTER(D_002639B0 + 53, D_00249E50);
    STORE_POINTER(D_00263A50 + 64, D_00263AE0);
    STORE_POINTER(D_00263A50 + 66, D_00263B10);
    STORE_POINTER(D_00263A50 + 68, D_00263B30);
    STORE_POINTER(D_00263B80 + 47, D_0028C0C8);
    STORE_POINTER(D_00263B80 + 54, D_0028C0C8);
    STORE_POINTER(D_00263B80 + 61, D_0028C0C0);
    STORE_POINTER(D_00263B80 + 68, D_0028C0C0);
    STORE_POINTER(D_00263C70 + 3, D_00261770_as_u16_a);
    STORE_POINTER(D_00263C80 + 3, D_00261D30);
    STORE_POINTER(D_00263C90 + 4, D_002610F0);
    STORE_POINTER(D_00263C90 + 11, D_00261770_as_u16_a);
    STORE_POINTER(D_00263C90 + 18, D_00249E50);
    STORE_POINTER(D_00263C90 + 25, D_00249E90);
    STORE_POINTER(D_00263C90 + 32, D_00261870_as_u16_a);
    STORE_POINTER(D_00263C90 + 39, D_002619F0);
    STORE_POINTER(D_00263CF0 + 4, D_00261830_as_u16_a);
}

extern u16 D_002420C0[];
extern u16 D_002420D0[];
extern u16 D_002420E0[];

extern u16 D_002420A8_as_u16_a[];

void func_001881E0(void) {
    STORE_POINTER(D_00242020 + 20, entity_draw_layer1);
    STORE_POINTER(D_00242020 + 22, sprite_draw_layer1);
    STORE_POINTER(D_00242070 + 20, entity_draw_layer1);
    STORE_POINTER(D_00242070 + 22, sprite_draw_layer1);
    STORE_POINTER(D_002420A8_as_u16_a, D_002420C0);
    STORE_POINTER(D_002420A8 + 2, D_002420D0);
    STORE_POINTER(D_002420A8 + 4, D_002420E0);
}

void func_001882D0(void) {
}

extern const char D_00275BE0[];
extern const char D_00275C00[];
extern const char D_00275C20[];
extern const char D_00275C40[];
extern const char D_00275C60[];
extern const char D_00275C80[];
extern const char D_00275CA0[];
extern const char D_00275CC0[];
extern const char D_00275CE0[];
extern const char D_00275D00[];
extern const char D_00275D20[];
extern const char D_00275D40[];
extern const char D_00275D60[];
extern const char D_00275D80[];
extern const char D_00275DA0[];
extern const char D_00275DC0[];
extern const char D_00275DE0[];
extern const char D_00275E00[];
extern const char D_00275E20[];
extern const char D_00275E40[];
extern const char D_00275E60[];
extern const char D_00275E80[];
extern const char D_00275EA0[];
extern const char D_00275EC0[];
extern const char D_00275EE0[];
extern const char D_00275F00[];
extern const char D_00275F20[];
extern const char D_00275F40[];
extern const char D_00275F60[];
extern const char D_00275F80[];
extern const char D_00275FA0[];
extern const char D_00275FC0[];
extern const char D_00275FE0[];
extern const char D_00276000[];
extern const char D_00276020[];
extern const char D_00276040[];
extern const char D_00276060[];
extern const char D_00276080[];
extern const char D_002760A0[];
extern const char D_002760C0[];
extern const char D_002760E0[];
extern const char D_00276100[];
extern const char D_00276120[];
extern const char D_00276140[];
extern const char D_00276160[];
extern const char D_00276180[];
extern const char D_002761A0[];
extern const char D_002761C0[];
extern const char D_002761E0[];
extern const char D_00276200[];
extern const char D_00276220[];
extern const char D_00276240[];
extern const char D_00276260[];
extern const char D_00276280[];
extern const char D_002762A0[];
extern const char D_002762C0[];
extern const char D_002762E0[];
extern const char D_00276300[];
extern const char D_00276320[];
extern const char D_00276340[];
extern const char D_00276360[];
extern const char D_00276380[];
extern const char D_002763A0[];
extern const char D_002763C0[];
extern const char D_002763E0[];
extern const char D_00276400[];
extern const char D_00276420[];
extern const char D_00276440[];
extern const char D_00276460[];
extern const char D_00276480[];
extern const char D_002764A0[];
extern const char D_002764C0[];
extern const char D_002764E0[];
extern const char D_00276500[];
extern const char D_00276520[];
extern const char D_00276540[];
extern const char D_00276560[];
extern const char D_00276580[];
extern const char D_002765A0[];
extern const char D_002765C0[];
extern const char D_002765E0[];
extern const char D_00276600[];
extern const char D_00276620[];
extern const char D_00276640[];
extern const char D_00276660[];
extern const char D_00276680[];
extern const char D_002766A0[];
extern const char D_002766C0[];
extern const char D_002766E0[];
extern const char D_00276700[];
extern const char D_00276720[];
extern const char D_00276740[];
extern const char D_00276760[];
extern const char D_00276780[];
extern const char D_002767A0[];
extern const char D_002767C0[];
extern const char D_002767E0[];
extern const char D_00276800[];
extern const char D_00276820[];
extern const char D_00276840[];
extern const char D_00276860[];
extern const char D_00276880[];
extern const char D_002768A0[];
extern const char D_002768C0[];
extern const char D_002768E0[];
extern const char D_00276900[];
extern const char D_00276920[];
extern const char D_00276940[];
extern const char D_00276960[];
extern const char D_00276980[];
extern const char D_002769A0[];
extern const char D_002769C0[];
extern const char D_002769E0[];
extern const char D_00276A00[];
extern const char D_00276A20[];
extern const char D_00276A40[];
extern const char D_00276A60[];
extern const char D_00276A80[];
extern const char D_00276AA0[];
extern const char D_00276AC0[];
extern const char D_00276AE0[];
extern const char D_00276B00[];
extern const char D_00276B20[];
extern const char D_00276B40[];
extern const char D_00276B60[];
extern const char D_00276B80[];
extern const char D_00276BA0[];
extern const char D_00276BC0[];
extern const char D_00276BE0[];
extern const char D_00276C00[];
extern const char D_00276C20[];
extern const char D_00276C40[];
extern const char D_00276C60[];
extern const char D_00276C80[];
extern const char D_00276CA0[];
extern const char D_00276CC0[];
extern const char D_00276CE0[];
extern const char D_00276D00[];
extern const char D_00276D20[];
extern const char D_00276D40[];
extern const char D_00276D60[];
extern const char D_00276D80[];
extern const char D_00276DA0[];
extern const char D_00276DC0[];
extern const char D_00276DE0[];
extern const char D_00276E00[];
extern const char D_00276E20[];
extern const char D_00276E40[];
extern const char D_00276E60[];
extern const char D_00276E80[];
extern const char D_00276EA0[];
extern const char D_00276EC0[];
extern const char D_00276EE0[];
extern const char D_00276F00[];
extern const char D_00276F20[];
extern const char D_00276F40[];
extern const char D_00276F60[];
extern const char D_00276F80[];
extern const char D_00276FA0[];
extern const char D_00276FC0[];
extern const char D_00276FE0[];
extern const char D_00277000[];
extern const char D_00277020[];
extern const char D_00277040[];
extern const char D_00277060[];
extern const char D_00277080[];
extern const char D_002770A0[];
extern const char D_002770C0[];
extern const char D_002770E0[];
extern const char D_00277100[];
extern const char D_00277120[];
extern const char D_00277140[];
extern const char D_00277160[];
extern const char D_00277180[];
extern const char D_002771A0[];
extern const char D_002771C0[];
extern const char D_002771E0[];
extern const char D_00277200[];
extern const char D_00277220[];
extern const char D_00277240[];
extern const char D_00277260[];
extern const char D_00277280[];
extern const char D_002772A0[];
extern const char D_002772C0[];
extern const char D_002772E0[];
extern const char D_00277300[];
extern const char D_00277320[];
extern const char D_00277340[];
extern const char D_00277360[];
extern const char D_00277380[];
extern const char D_002773A0[];
extern const char D_002773C0[];
extern const char D_002773E0[];
extern const char D_00277400[];
extern const char D_00277420[];
extern const char D_00277440[];
extern const char D_00277460[];
extern const char D_00277480[];
extern const char D_002774A0[];
extern const char D_002774C0[];
extern const char D_002774E0[];
extern const char D_00277500[];
extern const char D_00277520[];
extern const char D_00277540[];
extern const char D_00277560[];
extern const char D_00277580[];
extern const char D_002775A0[];
extern const char D_002775C0[];
extern const char D_002775E0[];
extern const char D_00277600[];
extern const char D_00277620[];
extern const char D_00277640[];
extern const char D_00277660[];
extern const char D_00277680[];
extern const char D_002776A0[];
extern const char D_002776C0[];
extern const char D_002776E0[];
extern const char D_00277700[];
extern const char D_00277720[];
extern const char D_00277740[];
extern const char D_00277760[];
extern const char D_00277780[];
extern const char D_002777A0[];
extern const char D_002777C0[];
extern const char D_002777E0[];
extern const char D_00277800[];
extern const char D_00277820[];
extern const char D_00277840[];
extern const char D_00277860[];
extern const char D_00277880[];
extern const char D_002778A0[];
extern const char D_002778C0[];
extern const char D_002778E0[];
extern const char D_00277900[];
extern const char D_00277920[];
extern const char D_00277940[];
extern const char D_00277960[];
extern const char D_00277980[];
extern const char D_002779A0[];
extern const char D_002779C0[];
extern const char D_002779E0[];
extern const char D_00277A00[];
extern const char D_00277A20[];
extern const char D_00277A40[];
extern const char D_00277A60[];
extern const char D_00277A80[];
extern const char D_00277AA0[];
extern const char D_00277AC0[];
extern const char D_00277AE0[];
extern const char D_00277B00[];
extern const char D_00277B20[];
extern const char D_00277B40[];
extern const char D_00277B60[];
extern const char D_00277B80[];
extern const char D_00277BA0[];
extern const char D_00277BC0[];
extern const char D_00277BE0[];
extern const char D_00277C00[];
extern const char D_00277C20[];
extern const char D_00277C40[];
extern const char D_00277C60[];
extern const char D_00277C80[];
extern const char D_00277CA0[];
extern const char D_00277CC0[];
extern const char D_00277CE0[];
extern const char D_00277D00[];
extern const char D_00277D20[];
extern const char D_00277D40[];
extern const char D_00277D60[];
extern const char D_00277D80[];
extern const char D_00277DA0[];
extern const char D_00277DC0[];
extern const char D_00277DE0[];
extern const char D_00277E00[];
extern const char D_00277E20[];
extern const char D_00277E40[];
extern const char D_00277E60[];
extern const char D_00277E80[];
extern const char D_00277EA0[];
extern const char D_00277EC0[];
extern const char D_00277EE0[];
extern const char D_00277F00[];
extern const char D_00277F20[];
extern const char D_00277F40[];
extern const char D_00277F60[];

extern u16 D_0025D7F0[];
extern u16 D_0025D800[];
extern u16 D_0025D810[];
extern u16 D_0025D820[];
extern u16 D_0025D830[];
extern u16 D_0025D840[];
extern u16 D_0025D850[];
extern u16 D_0025D860[];
extern u16 D_0025D870[];
extern u16 D_0025D880[];
extern u16 player_shot_7_impact_frames_00[];
extern u16 player_shot_7_impact_frames_02[];
extern u16 player_shot_7_impact_frames_06[];
extern u16 player_shot_7_impact_frames_10[];
extern u16 player_shot_7_impact_frames_11[];
extern u16 player_shot_7_impact_frames_13[];
extern u16 player_shot_7_impact_frames_15[];
extern u16 player_shot_7_impact_frames_17[];
extern u16 player_shot_7_impact_frames_21[];
extern u16 D_0025DFC0[];
extern u16 player_shot_7_impact_00[];
extern u16 player_shot_7_impact_02[];
extern u16 player_shot_7_impact_04[];
extern u16 player_shot_7_impact_06[];
extern u16 player_shot_7_impact_08[];
extern u16 player_shot_7_impact_10[];
extern u16 player_shot_7_impact_11[];
extern u16 player_shot_7_impact_12[];
extern u16 player_shot_7_impact_13[];
extern u16 player_shot_7_impact_14[];
extern u16 player_shot_7_impact_15[];
extern u16 player_shot_7_impact_17[];
extern u16 player_shot_7_impact_19[];
extern u16 player_shot_7_impact_21[];
extern u16 player_shot_7_impact_23[];
extern u16 player_shot_7_flight_000[];
extern u16 player_shot_7_flight_002[];
extern u16 player_shot_7_flight_004[];
extern u16 player_shot_7_flight_006[];
extern u16 player_shot_7_flight_008[];
extern u16 player_shot_7_flight_010[];
extern u16 player_shot_7_flight_011[];
extern u16 player_shot_7_flight_012[];
extern u16 player_shot_7_flight_013[];
extern u16 player_shot_7_flight_014[];
extern u16 player_shot_7_flight_015[];
extern u16 player_shot_7_flight_017[];
extern u16 player_shot_7_flight_019[];
extern u16 player_shot_7_flight_021[];
extern u16 player_shot_7_flight_023[];
extern u16 player_shot_7_flight_028[];
extern u16 player_shot_7_flight_029[];
extern u16 player_shot_7_flight_030[];
extern u16 player_shot_7_flight_031[];
extern u16 player_shot_7_flight_032[];
extern u16 player_shot_7_flight_033[];
extern u16 player_shot_7_flight_034[];
extern u16 player_shot_7_flight_035[];
extern u16 player_shot_7_flight_036[];
extern u16 player_shot_7_flight_037[];
extern u16 player_shot_7_flight_038[];
extern u16 player_shot_7_flight_039[];
extern u16 player_shot_7_flight_040[];
extern u16 player_shot_7_flight_041[];
extern u16 player_shot_7_flight_042[];
extern u16 player_shot_7_flight_043[];
extern u16 player_shot_7_flight_044[];
extern u16 player_shot_7_flight_048[];
extern u16 player_shot_7_flight_049[];
extern u16 player_shot_7_flight_050[];
extern u16 player_shot_7_flight_051[];
extern u16 player_shot_7_flight_052[];
extern u16 player_shot_7_flight_053[];
extern u16 player_shot_7_flight_054[];
extern u16 player_shot_7_flight_055[];
extern u16 player_shot_7_flight_056[];
extern u16 player_shot_7_flight_057[];
extern u16 player_shot_7_flight_058[];
extern u16 player_shot_7_flight_059[];
extern u16 player_shot_7_flight_060[];
extern u16 player_shot_7_flight_061[];
extern u16 player_shot_7_flight_062[];
extern u16 player_shot_7_flight_063[];
extern u16 player_shot_7_flight_064[];
extern u16 player_shot_7_flight_068[];
extern u16 player_shot_7_flight_069[];
extern u16 player_shot_7_flight_070[];
extern u16 player_shot_7_flight_071[];
extern u16 player_shot_7_flight_072[];
extern u16 player_shot_7_flight_073[];
extern u16 player_shot_7_flight_074[];
extern u16 player_shot_7_flight_075[];
extern u16 player_shot_7_flight_076[];
extern u16 player_shot_7_flight_077[];
extern u16 player_shot_7_flight_078[];
extern u16 player_shot_7_flight_079[];
extern u16 player_shot_7_flight_080[];
extern u16 player_shot_7_flight_081[];
extern u16 player_shot_7_flight_082[];
extern u16 player_shot_7_flight_083[];
extern u16 player_shot_7_flight_084[];
extern u16 player_shot_7_flight_088[];
extern u16 player_shot_7_flight_089[];
extern u16 player_shot_7_flight_090[];
extern u16 player_shot_7_flight_091[];
extern u16 player_shot_7_flight_092[];
extern u16 player_shot_7_flight_093[];
extern u16 player_shot_7_flight_094[];
extern u16 player_shot_7_flight_095[];
extern u16 player_shot_7_flight_096[];
extern u16 player_shot_7_flight_097[];
extern u16 player_shot_7_flight_098[];
extern u16 player_shot_7_flight_099[];
extern u16 player_shot_7_flight_100[];
extern u16 player_shot_7_flight_101[];
extern u16 player_shot_7_flight_102[];
extern u16 player_shot_7_flight_103[];
extern u16 player_shot_7_flight_104[];
extern u16 D_0028D5B8[];
extern u16 D_0028D5C0[];
extern u16 D_0028D5C8[];
extern u16 D_0028D5D0[];
extern u16 D_0028D5D8[];
extern u16 D_0028D5E0[];
extern u16 D_0028D5E8[];
extern u16 D_0028D5F0[];
extern u16 D_0028D5F8[];
extern u16 D_0028D600[];
extern u16 D_0028D608[];
extern u16 D_0028D610[];
extern u16 D_0028D618[];
extern u16 D_0028D620[];
extern u16 D_0028D628[];
extern u16 D_0028D630[];
extern u16 D_0028D638[];

extern u16 D_0025DB94[];
extern u16 D_0025DBC4[];
extern u16 D_0025DBF4[];
extern u16 D_0025DC24[];
extern u16 D_0025DC54[];
extern u16 player_shot_7_flight_table[];
extern u16 player_shot_7_impact_table[];

void player_shot_7_tables_init(void) {
    if (D_0025D9B0[5] != 0x5) {
        printf((const char *)D_00275BE0);
    }
    STORE_POINTER(D_0025D9B0 + 5, D_0025D7F0);
    if (D_0025D9B0[15] != 0xf) {
        printf((const char *)D_00275C00);
    }
    STORE_POINTER(D_0025D9B0 + 15, D_0025D820);
    if (D_0025D9E0[5] != 0x5) {
        printf((const char *)D_00275C20);
    }
    STORE_POINTER(D_0025D9E0 + 5, D_0025D7F0);
    if (D_0025D9E0[15] != 0xf) {
        printf((const char *)D_00275C40);
    }
    STORE_POINTER(D_0025D9E0 + 15, D_0025D820);
    if (D_0025DA10[5] != 0x5) {
        printf((const char *)D_00275C60);
    }
    STORE_POINTER(D_0025DA10 + 5, D_0025D7F0);
    if (D_0025DA10[15] != 0xf) {
        printf((const char *)D_00275C80);
    }
    STORE_POINTER(D_0025DA10 + 15, D_0025D820);
    if (D_0025DA40[5] != 0x5) {
        printf((const char *)D_00275CA0);
    }
    STORE_POINTER(D_0025DA40 + 5, D_0025D7F0);
    if (D_0025DA40[15] != 0xf) {
        printf((const char *)D_00275CC0);
    }
    STORE_POINTER(D_0025DA40 + 15, D_0025D820);
    if (D_0025DA70[5] != 0x5) {
        printf((const char *)D_00275CE0);
    }
    STORE_POINTER(D_0025DA70 + 5, D_0025D7F0);
    if (D_0025DA70[15] != 0xf) {
        printf((const char *)D_00275D00);
    }
    STORE_POINTER(D_0025DA70 + 15, D_0025D820);
    if (D_0025DAA0[5] != 0x5) {
        printf((const char *)D_00275D20);
    }
    STORE_POINTER(D_0025DAA0 + 5, D_0025D7F0);
    if (D_0025DAA0[15] != 0xf) {
        printf((const char *)D_00275D40);
    }
    STORE_POINTER(D_0025DAA0 + 15, D_0025D820);
    if (D_0025DAD0[5] != 0x5) {
        printf((const char *)D_00275D60);
    }
    STORE_POINTER(D_0025DAD0 + 5, D_0025D7F0);
    if (D_0025DAD0[15] != 0xf) {
        printf((const char *)D_00275D80);
    }
    STORE_POINTER(D_0025DAD0 + 15, D_0025D820);
    if (D_0025DB00[5] != 0x5) {
        printf((const char *)D_00275DA0);
    }
    STORE_POINTER(D_0025DB00 + 5, D_0025D7F0);
    if (D_0025DB00[15] != 0xf) {
        printf((const char *)D_00275DC0);
    }
    STORE_POINTER(D_0025DB00 + 15, D_0025D820);
    if (D_0025DB30[5] != 0x5) {
        printf((const char *)D_00275DE0);
    }
    STORE_POINTER(D_0025DB30 + 5, D_0025D7F0);
    if (D_0025DB30[15] != 0xf) {
        printf((const char *)D_00275E00);
    }
    STORE_POINTER(D_0025DB30 + 15, D_0025D820);
    if (D_0025DB60[5] != 0x5) {
        printf((const char *)D_00275E20);
    }
    STORE_POINTER(D_0025DB60 + 5, D_0025D7F0);
    if (D_0025DB60[15] != 0xf) {
        printf((const char *)D_00275E40);
    }
    STORE_POINTER(D_0025DB60 + 15, D_0025D820);
    if (D_0025DB90[1] != 0x1) {
        printf((const char *)D_00275E60);
    }
    STORE_POINTER(D_0025DB90 + 1, D_0025DFC0);
    if (D_0025DB94[3] != 0x5) {
        printf((const char *)D_00275E80);
    }
    STORE_POINTER(D_0025DB94 + 3, D_0025D800);
    if (D_0025DBC0[1] != 0x1) {
        printf((const char *)D_00275EA0);
    }
    STORE_POINTER(D_0025DBC0 + 1, D_0025DFC0);
    if (D_0025DBC4[3] != 0x5) {
        printf((const char *)D_00275EC0);
    }
    STORE_POINTER(D_0025DBC4 + 3, D_0025D800);
    if (D_0025DBF0[1] != 0x1) {
        printf((const char *)D_00275EE0);
    }
    STORE_POINTER(D_0025DBF0 + 1, D_0025DFC0);
    if (D_0025DBF4[3] != 0x5) {
        printf((const char *)D_00275F00);
    }
    STORE_POINTER(D_0025DBF4 + 3, D_0025D800);
    if (D_0025DC20[1] != 0x1) {
        printf((const char *)D_00275F20);
    }
    STORE_POINTER(D_0025DC20 + 1, D_0025DFC0);
    if (D_0025DC24[3] != 0x5) {
        printf((const char *)D_00275F40);
    }
    STORE_POINTER(D_0025DC24 + 3, D_0025D800);
    if (D_0025DC50[1] != 0x1) {
        printf((const char *)D_00275F60);
    }
    STORE_POINTER(D_0025DC50 + 1, D_0025DFC0);
    if (D_0025DC54[3] != 0x5) {
        printf((const char *)D_00275F80);
    }
    STORE_POINTER(D_0025DC54 + 3, D_0025D800);
    if (D_0025DC80[5] != 0x5) {
        printf((const char *)D_00275FA0);
    }
    STORE_POINTER(D_0025DC80 + 5, D_0025D810);
    if (D_0025DC80[15] != 0xf) {
        printf((const char *)D_00275FC0);
    }
    STORE_POINTER(D_0025DC80 + 15, D_0025D880);
    if (D_0025DC80[24] != 0x18) {
        printf((const char *)D_00275FE0);
    }
    STORE_POINTER(D_0025DC80 + 24, D_0025D810);
    if (D_0025DC80[34] != 0x22) {
        printf((const char *)D_00276000);
    }
    STORE_POINTER(D_0025DC80 + 34, D_0025D880);
    if (D_0025DCD0[5] != 0x5) {
        printf((const char *)D_00276020);
    }
    STORE_POINTER(D_0025DCD0 + 5, D_0025D810);
    if (D_0025DCD0[15] != 0xf) {
        printf((const char *)D_00276040);
    }
    STORE_POINTER(D_0025DCD0 + 15, D_0025D880);
    if (D_0025DCD0[24] != 0x18) {
        printf((const char *)D_00276060);
    }
    STORE_POINTER(D_0025DCD0 + 24, D_0025D810);
    if (D_0025DCD0[34] != 0x22) {
        printf((const char *)D_00276080);
    }
    STORE_POINTER(D_0025DCD0 + 34, D_0025D880);
    if (D_0025DD20[5] != 0x5) {
        printf((const char *)D_002760A0);
    }
    STORE_POINTER(D_0025DD20 + 5, D_0025D810);
    if (D_0025DD20[15] != 0xf) {
        printf((const char *)D_002760C0);
    }
    STORE_POINTER(D_0025DD20 + 15, D_0025D880);
    if (D_0025DD20[24] != 0x18) {
        printf((const char *)D_002760E0);
    }
    STORE_POINTER(D_0025DD20 + 24, D_0025D810);
    if (D_0025DD20[34] != 0x22) {
        printf((const char *)D_00276100);
    }
    STORE_POINTER(D_0025DD20 + 34, D_0025D880);
    if (D_0025DD70[5] != 0x5) {
        printf((const char *)D_00276120);
    }
    STORE_POINTER(D_0025DD70 + 5, D_0025D810);
    if (D_0025DD70[15] != 0xf) {
        printf((const char *)D_00276140);
    }
    STORE_POINTER(D_0025DD70 + 15, D_0025D880);
    if (D_0025DD70[24] != 0x18) {
        printf((const char *)D_00276160);
    }
    STORE_POINTER(D_0025DD70 + 24, D_0025D810);
    if (D_0025DD70[34] != 0x22) {
        printf((const char *)D_00276180);
    }
    STORE_POINTER(D_0025DD70 + 34, D_0025D880);
    if (D_0025DDC0[5] != 0x5) {
        printf((const char *)D_002761A0);
    }
    STORE_POINTER(D_0025DDC0 + 5, D_0025D810);
    if (D_0025DDC0[15] != 0xf) {
        printf((const char *)D_002761C0);
    }
    STORE_POINTER(D_0025DDC0 + 15, D_0025D880);
    if (D_0025DDC0[24] != 0x18) {
        printf((const char *)D_002761E0);
    }
    STORE_POINTER(D_0025DDC0 + 24, D_0025D810);
    if (D_0025DDC0[34] != 0x22) {
        printf((const char *)D_00276200);
    }
    STORE_POINTER(D_0025DDC0 + 34, D_0025D880);
    if (player_shot_7_flight_table[0] != 0x0) {
        printf((const char *)D_00276220);
    }
    STORE_POINTER(player_shot_7_flight_table, player_shot_7_flight_000);
    if (player_shot_7_flight_table[2] != 0x2) {
        printf((const char *)D_00276240);
    }
    STORE_POINTER(player_shot_7_flight_table + 2, player_shot_7_flight_000);
    if (player_shot_7_flight_table[4] != 0x4) {
        printf((const char *)D_00276260);
    }
    STORE_POINTER(player_shot_7_flight_table + 4, player_shot_7_flight_002);
    if (player_shot_7_flight_table[6] != 0x6) {
        printf((const char *)D_00276280);
    }
    STORE_POINTER(player_shot_7_flight_table + 6, player_shot_7_flight_002);
    if (player_shot_7_flight_table[8] != 0x8) {
        printf((const char *)D_002762A0);
    }
    STORE_POINTER(player_shot_7_flight_table + 8, player_shot_7_flight_004);
    if (player_shot_7_flight_table[10] != 0xa) {
        printf((const char *)D_002762C0);
    }
    STORE_POINTER(player_shot_7_flight_table + 10, player_shot_7_flight_004);
    if (player_shot_7_flight_table[12] != 0xc) {
        printf((const char *)D_002762E0);
    }
    STORE_POINTER(player_shot_7_flight_table + 12, player_shot_7_flight_006);
    if (player_shot_7_flight_table[14] != 0xe) {
        printf((const char *)D_00276300);
    }
    STORE_POINTER(player_shot_7_flight_table + 14, player_shot_7_flight_006);
    if (player_shot_7_flight_table[16] != 0x10) {
        printf((const char *)D_00276320);
    }
    STORE_POINTER(player_shot_7_flight_table + 16, player_shot_7_flight_008);
    if (player_shot_7_flight_table[18] != 0x12) {
        printf((const char *)D_00276340);
    }
    STORE_POINTER(player_shot_7_flight_table + 18, player_shot_7_flight_008);
    if (player_shot_7_flight_table[20] != 0x14) {
        printf((const char *)D_00276360);
    }
    STORE_POINTER(player_shot_7_flight_table + 20, player_shot_7_flight_010);
    if (player_shot_7_flight_table[22] != 0x16) {
        printf((const char *)D_00276380);
    }
    STORE_POINTER(player_shot_7_flight_table + 22, player_shot_7_flight_011);
    if (player_shot_7_flight_table[24] != 0x18) {
        printf((const char *)D_002763A0);
    }
    STORE_POINTER(player_shot_7_flight_table + 24, player_shot_7_flight_012);
    if (player_shot_7_flight_table[26] != 0x1a) {
        printf((const char *)D_002763C0);
    }
    STORE_POINTER(player_shot_7_flight_table + 26, player_shot_7_flight_013);
    if (player_shot_7_flight_table[28] != 0x1c) {
        printf((const char *)D_002763E0);
    }
    STORE_POINTER(player_shot_7_flight_table + 28, player_shot_7_flight_014);
    if (player_shot_7_flight_table[30] != 0x1e) {
        printf((const char *)D_00276400);
    }
    STORE_POINTER(player_shot_7_flight_table + 30, player_shot_7_flight_015);
    if (player_shot_7_flight_table[32] != 0x20) {
        printf((const char *)D_00276420);
    }
    STORE_POINTER(player_shot_7_flight_table + 32, player_shot_7_flight_015);
    if (player_shot_7_flight_table[34] != 0x22) {
        printf((const char *)D_00276440);
    }
    STORE_POINTER(player_shot_7_flight_table + 34, player_shot_7_flight_017);
    if (player_shot_7_flight_table[36] != 0x24) {
        printf((const char *)D_00276460);
    }
    STORE_POINTER(player_shot_7_flight_table + 36, player_shot_7_flight_017);
    if (player_shot_7_flight_table[38] != 0x26) {
        printf((const char *)D_00276480);
    }
    STORE_POINTER(player_shot_7_flight_table + 38, player_shot_7_flight_019);
    if (player_shot_7_flight_table[40] != 0x28) {
        printf((const char *)D_002764A0);
    }
    STORE_POINTER(player_shot_7_flight_table + 40, player_shot_7_flight_019);
    if (player_shot_7_flight_table[42] != 0x2a) {
        printf((const char *)D_002764C0);
    }
    STORE_POINTER(player_shot_7_flight_table + 42, player_shot_7_flight_021);
    if (player_shot_7_flight_table[44] != 0x2c) {
        printf((const char *)D_002764E0);
    }
    STORE_POINTER(player_shot_7_flight_table + 44, player_shot_7_flight_021);
    if (player_shot_7_flight_table[46] != 0x2e) {
        printf((const char *)D_00276500);
    }
    STORE_POINTER(player_shot_7_flight_table + 46, player_shot_7_flight_023);
    if (player_shot_7_flight_table[48] != 0x30) {
        printf((const char *)D_00276520);
    }
    STORE_POINTER(player_shot_7_flight_table + 48, player_shot_7_flight_023);
    if (player_shot_7_flight_table[56] != 0x0) {
        printf((const char *)D_00276540);
    }
    STORE_POINTER(player_shot_7_flight_table + 56, player_shot_7_flight_028);
    if (player_shot_7_flight_table[58] != 0x2) {
        printf((const char *)D_00276560);
    }
    STORE_POINTER(player_shot_7_flight_table + 58, player_shot_7_flight_029);
    if (player_shot_7_flight_table[60] != 0x4) {
        printf((const char *)D_00276580);
    }
    STORE_POINTER(player_shot_7_flight_table + 60, player_shot_7_flight_030);
    if (player_shot_7_flight_table[62] != 0x6) {
        printf((const char *)D_002765A0);
    }
    STORE_POINTER(player_shot_7_flight_table + 62, player_shot_7_flight_031);
    if (player_shot_7_flight_table[64] != 0x8) {
        printf((const char *)D_002765C0);
    }
    STORE_POINTER(player_shot_7_flight_table + 64, player_shot_7_flight_032);
    if (player_shot_7_flight_table[66] != 0xa) {
        printf((const char *)D_002765E0);
    }
    STORE_POINTER(player_shot_7_flight_table + 66, player_shot_7_flight_033);
    if (player_shot_7_flight_table[68] != 0xc) {
        printf((const char *)D_00276600);
    }
    STORE_POINTER(player_shot_7_flight_table + 68, player_shot_7_flight_034);
    if (player_shot_7_flight_table[70] != 0xe) {
        printf((const char *)D_00276620);
    }
    STORE_POINTER(player_shot_7_flight_table + 70, player_shot_7_flight_035);
    if (player_shot_7_flight_table[72] != 0x10) {
        printf((const char *)D_00276640);
    }
    STORE_POINTER(player_shot_7_flight_table + 72, player_shot_7_flight_036);
    if (player_shot_7_flight_table[74] != 0x12) {
        printf((const char *)D_00276660);
    }
    STORE_POINTER(player_shot_7_flight_table + 74, player_shot_7_flight_037);
    if (player_shot_7_flight_table[76] != 0x14) {
        printf((const char *)D_00276680);
    }
    STORE_POINTER(player_shot_7_flight_table + 76, player_shot_7_flight_038);
    if (player_shot_7_flight_table[78] != 0x16) {
        printf((const char *)D_002766A0);
    }
    STORE_POINTER(player_shot_7_flight_table + 78, player_shot_7_flight_039);
    if (player_shot_7_flight_table[80] != 0x18) {
        printf((const char *)D_002766C0);
    }
    STORE_POINTER(player_shot_7_flight_table + 80, player_shot_7_flight_040);
    if (player_shot_7_flight_table[82] != 0x1a) {
        printf((const char *)D_002766E0);
    }
    STORE_POINTER(player_shot_7_flight_table + 82, player_shot_7_flight_041);
    if (player_shot_7_flight_table[84] != 0x1c) {
        printf((const char *)D_00276700);
    }
    STORE_POINTER(player_shot_7_flight_table + 84, player_shot_7_flight_042);
    if (player_shot_7_flight_table[86] != 0x1e) {
        printf((const char *)D_00276720);
    }
    STORE_POINTER(player_shot_7_flight_table + 86, player_shot_7_flight_043);
    if (player_shot_7_flight_table[88] != 0x20) {
        printf((const char *)D_00276740);
    }
    STORE_POINTER(player_shot_7_flight_table + 88, player_shot_7_flight_044);
    if (player_shot_7_flight_028[2] != 0x2) {
        printf((const char *)D_00276760);
    }
    STORE_POINTER(player_shot_7_flight_028 + 2, D_0025D830);
    if (player_shot_7_flight_029[2] != 0x2) {
        printf((const char *)D_00276780);
    }
    STORE_POINTER(player_shot_7_flight_029 + 2, D_0025D830);
    if (player_shot_7_flight_030[2] != 0x2) {
        printf((const char *)D_002767A0);
    }
    STORE_POINTER(player_shot_7_flight_030 + 2, D_0025D830);
    if (player_shot_7_flight_031[2] != 0x2) {
        printf((const char *)D_002767C0);
    }
    STORE_POINTER(player_shot_7_flight_031 + 2, D_0025D830);
    if (player_shot_7_flight_032[2] != 0x2) {
        printf((const char *)D_002767E0);
    }
    STORE_POINTER(player_shot_7_flight_032 + 2, D_0025D830);
    if (player_shot_7_flight_033[2] != 0x2) {
        printf((const char *)D_00276800);
    }
    STORE_POINTER(player_shot_7_flight_033 + 2, D_0025D830);
    if (player_shot_7_flight_034[2] != 0x2) {
        printf((const char *)D_00276820);
    }
    STORE_POINTER(player_shot_7_flight_034 + 2, D_0025D830);
    if (player_shot_7_flight_035[2] != 0x2) {
        printf((const char *)D_00276840);
    }
    STORE_POINTER(player_shot_7_flight_035 + 2, D_0025D830);
    if (player_shot_7_flight_036[2] != 0x2) {
        printf((const char *)D_00276860);
    }
    STORE_POINTER(player_shot_7_flight_036 + 2, D_0025D830);
    if (player_shot_7_flight_037[2] != 0x2) {
        printf((const char *)D_00276880);
    }
    STORE_POINTER(player_shot_7_flight_037 + 2, D_0025D830);
    if (player_shot_7_flight_038[2] != 0x2) {
        printf((const char *)D_002768A0);
    }
    STORE_POINTER(player_shot_7_flight_038 + 2, D_0025D830);
    if (player_shot_7_flight_039[2] != 0x2) {
        printf((const char *)D_002768C0);
    }
    STORE_POINTER(player_shot_7_flight_039 + 2, D_0025D830);
    if (player_shot_7_flight_040[2] != 0x2) {
        printf((const char *)D_002768E0);
    }
    STORE_POINTER(player_shot_7_flight_040 + 2, D_0025D830);
    if (player_shot_7_flight_041[2] != 0x2) {
        printf((const char *)D_00276900);
    }
    STORE_POINTER(player_shot_7_flight_041 + 2, D_0025D830);
    if (player_shot_7_flight_042[2] != 0x2) {
        printf((const char *)D_00276920);
    }
    STORE_POINTER(player_shot_7_flight_042 + 2, D_0025D830);
    if (player_shot_7_flight_043[2] != 0x2) {
        printf((const char *)D_00276940);
    }
    STORE_POINTER(player_shot_7_flight_043 + 2, D_0025D830);
    if (player_shot_7_flight_044[2] != 0x2) {
        printf((const char *)D_00276960);
    }
    STORE_POINTER(player_shot_7_flight_044 + 2, D_0025D830);
    if (player_shot_7_flight_table[96] != 0x0) {
        printf((const char *)D_00276980);
    }
    STORE_POINTER(player_shot_7_flight_table + 96, player_shot_7_flight_048);
    if (player_shot_7_flight_table[98] != 0x2) {
        printf((const char *)D_002769A0);
    }
    STORE_POINTER(player_shot_7_flight_table + 98, player_shot_7_flight_049);
    if (player_shot_7_flight_table[100] != 0x4) {
        printf((const char *)D_002769C0);
    }
    STORE_POINTER(player_shot_7_flight_table + 100, player_shot_7_flight_050);
    if (player_shot_7_flight_table[102] != 0x6) {
        printf((const char *)D_002769E0);
    }
    STORE_POINTER(player_shot_7_flight_table + 102, player_shot_7_flight_051);
    if (player_shot_7_flight_table[104] != 0x8) {
        printf((const char *)D_00276A00);
    }
    STORE_POINTER(player_shot_7_flight_table + 104, player_shot_7_flight_052);
    if (player_shot_7_flight_table[106] != 0xa) {
        printf((const char *)D_00276A20);
    }
    STORE_POINTER(player_shot_7_flight_table + 106, player_shot_7_flight_053);
    if (player_shot_7_flight_table[108] != 0xc) {
        printf((const char *)D_00276A40);
    }
    STORE_POINTER(player_shot_7_flight_table + 108, player_shot_7_flight_054);
    if (player_shot_7_flight_table[110] != 0xe) {
        printf((const char *)D_00276A60);
    }
    STORE_POINTER(player_shot_7_flight_table + 110, player_shot_7_flight_055);
    if (player_shot_7_flight_table[112] != 0x10) {
        printf((const char *)D_00276A80);
    }
    STORE_POINTER(player_shot_7_flight_table + 112, player_shot_7_flight_056);
    if (player_shot_7_flight_table[114] != 0x12) {
        printf((const char *)D_00276AA0);
    }
    STORE_POINTER(player_shot_7_flight_table + 114, player_shot_7_flight_057);
    if (player_shot_7_flight_table[116] != 0x14) {
        printf((const char *)D_00276AC0);
    }
    STORE_POINTER(player_shot_7_flight_table + 116, player_shot_7_flight_058);
    if (player_shot_7_flight_table[118] != 0x16) {
        printf((const char *)D_00276AE0);
    }
    STORE_POINTER(player_shot_7_flight_table + 118, player_shot_7_flight_059);
    if (player_shot_7_flight_table[120] != 0x18) {
        printf((const char *)D_00276B00);
    }
    STORE_POINTER(player_shot_7_flight_table + 120, player_shot_7_flight_060);
    if (player_shot_7_flight_table[122] != 0x1a) {
        printf((const char *)D_00276B20);
    }
    STORE_POINTER(player_shot_7_flight_table + 122, player_shot_7_flight_061);
    if (player_shot_7_flight_table[124] != 0x1c) {
        printf((const char *)D_00276B40);
    }
    STORE_POINTER(player_shot_7_flight_table + 124, player_shot_7_flight_062);
    if (player_shot_7_flight_table[126] != 0x1e) {
        printf((const char *)D_00276B60);
    }
    STORE_POINTER(player_shot_7_flight_table + 126, player_shot_7_flight_063);
    if (player_shot_7_flight_table[128] != 0x20) {
        printf((const char *)D_00276B80);
    }
    STORE_POINTER(player_shot_7_flight_table + 128, player_shot_7_flight_064);
    if (player_shot_7_flight_048[2] != 0x2) {
        printf((const char *)D_00276BA0);
    }
    STORE_POINTER(player_shot_7_flight_048 + 2, D_0025D840);
    if (player_shot_7_flight_049[2] != 0x2) {
        printf((const char *)D_00276BC0);
    }
    STORE_POINTER(player_shot_7_flight_049 + 2, D_0025D840);
    if (player_shot_7_flight_050[2] != 0x2) {
        printf((const char *)D_00276BE0);
    }
    STORE_POINTER(player_shot_7_flight_050 + 2, D_0025D840);
    if (player_shot_7_flight_051[2] != 0x2) {
        printf((const char *)D_00276C00);
    }
    STORE_POINTER(player_shot_7_flight_051 + 2, D_0025D840);
    if (player_shot_7_flight_052[2] != 0x2) {
        printf((const char *)D_00276C20);
    }
    STORE_POINTER(player_shot_7_flight_052 + 2, D_0025D840);
    if (player_shot_7_flight_053[2] != 0x2) {
        printf((const char *)D_00276C40);
    }
    STORE_POINTER(player_shot_7_flight_053 + 2, D_0025D840);
    if (player_shot_7_flight_054[2] != 0x2) {
        printf((const char *)D_00276C60);
    }
    STORE_POINTER(player_shot_7_flight_054 + 2, D_0025D840);
    if (player_shot_7_flight_055[2] != 0x2) {
        printf((const char *)D_00276C80);
    }
    STORE_POINTER(player_shot_7_flight_055 + 2, D_0025D840);
    if (player_shot_7_flight_056[2] != 0x2) {
        printf((const char *)D_00276CA0);
    }
    STORE_POINTER(player_shot_7_flight_056 + 2, D_0025D840);
    if (player_shot_7_flight_057[2] != 0x2) {
        printf((const char *)D_00276CC0);
    }
    STORE_POINTER(player_shot_7_flight_057 + 2, D_0025D840);
    if (player_shot_7_flight_058[2] != 0x2) {
        printf((const char *)D_00276CE0);
    }
    STORE_POINTER(player_shot_7_flight_058 + 2, D_0025D840);
    if (player_shot_7_flight_059[2] != 0x2) {
        printf((const char *)D_00276D00);
    }
    STORE_POINTER(player_shot_7_flight_059 + 2, D_0025D840);
    if (player_shot_7_flight_060[2] != 0x2) {
        printf((const char *)D_00276D20);
    }
    STORE_POINTER(player_shot_7_flight_060 + 2, D_0025D840);
    if (player_shot_7_flight_061[2] != 0x2) {
        printf((const char *)D_00276D40);
    }
    STORE_POINTER(player_shot_7_flight_061 + 2, D_0025D840);
    if (player_shot_7_flight_062[2] != 0x2) {
        printf((const char *)D_00276D60);
    }
    STORE_POINTER(player_shot_7_flight_062 + 2, D_0025D840);
    if (player_shot_7_flight_063[2] != 0x2) {
        printf((const char *)D_00276D80);
    }
    STORE_POINTER(player_shot_7_flight_063 + 2, D_0025D840);
    if (player_shot_7_flight_064[2] != 0x2) {
        printf((const char *)D_00276DA0);
    }
    STORE_POINTER(player_shot_7_flight_064 + 2, D_0025D840);
    if (player_shot_7_flight_table[136] != 0x0) {
        printf((const char *)D_00276DC0);
    }
    STORE_POINTER(player_shot_7_flight_table + 136, player_shot_7_flight_068);
    if (player_shot_7_flight_table[138] != 0x2) {
        printf((const char *)D_00276DE0);
    }
    STORE_POINTER(player_shot_7_flight_table + 138, player_shot_7_flight_069);
    if (player_shot_7_flight_table[140] != 0x4) {
        printf((const char *)D_00276E00);
    }
    STORE_POINTER(player_shot_7_flight_table + 140, player_shot_7_flight_070);
    if (player_shot_7_flight_table[142] != 0x6) {
        printf((const char *)D_00276E20);
    }
    STORE_POINTER(player_shot_7_flight_table + 142, player_shot_7_flight_071);
    if (player_shot_7_flight_table[144] != 0x8) {
        printf((const char *)D_00276E40);
    }
    STORE_POINTER(player_shot_7_flight_table + 144, player_shot_7_flight_072);
    if (player_shot_7_flight_table[146] != 0xa) {
        printf((const char *)D_00276E60);
    }
    STORE_POINTER(player_shot_7_flight_table + 146, player_shot_7_flight_073);
    if (player_shot_7_flight_table[148] != 0xc) {
        printf((const char *)D_00276E80);
    }
    STORE_POINTER(player_shot_7_flight_table + 148, player_shot_7_flight_074);
    if (player_shot_7_flight_table[150] != 0xe) {
        printf((const char *)D_00276EA0);
    }
    STORE_POINTER(player_shot_7_flight_table + 150, player_shot_7_flight_075);
    if (player_shot_7_flight_table[152] != 0x10) {
        printf((const char *)D_00276EC0);
    }
    STORE_POINTER(player_shot_7_flight_table + 152, player_shot_7_flight_076);
    if (player_shot_7_flight_table[154] != 0x12) {
        printf((const char *)D_00276EE0);
    }
    STORE_POINTER(player_shot_7_flight_table + 154, player_shot_7_flight_077);
    if (player_shot_7_flight_table[156] != 0x14) {
        printf((const char *)D_00276F00);
    }
    STORE_POINTER(player_shot_7_flight_table + 156, player_shot_7_flight_078);
    if (player_shot_7_flight_table[158] != 0x16) {
        printf((const char *)D_00276F20);
    }
    STORE_POINTER(player_shot_7_flight_table + 158, player_shot_7_flight_079);
    if (player_shot_7_flight_table[160] != 0x18) {
        printf((const char *)D_00276F40);
    }
    STORE_POINTER(player_shot_7_flight_table + 160, player_shot_7_flight_080);
    if (player_shot_7_flight_table[162] != 0x1a) {
        printf((const char *)D_00276F60);
    }
    STORE_POINTER(player_shot_7_flight_table + 162, player_shot_7_flight_081);
    if (player_shot_7_flight_table[164] != 0x1c) {
        printf((const char *)D_00276F80);
    }
    STORE_POINTER(player_shot_7_flight_table + 164, player_shot_7_flight_082);
    if (player_shot_7_flight_table[166] != 0x1e) {
        printf((const char *)D_00276FA0);
    }
    STORE_POINTER(player_shot_7_flight_table + 166, player_shot_7_flight_083);
    if (player_shot_7_flight_table[168] != 0x20) {
        printf((const char *)D_00276FC0);
    }
    STORE_POINTER(player_shot_7_flight_table + 168, player_shot_7_flight_084);
    if (player_shot_7_flight_068[2] != 0x2) {
        printf((const char *)D_00276FE0);
    }
    STORE_POINTER(player_shot_7_flight_068 + 2, D_0025D850);
    if (player_shot_7_flight_069[2] != 0x2) {
        printf((const char *)D_00277000);
    }
    STORE_POINTER(player_shot_7_flight_069 + 2, D_0025D850);
    if (player_shot_7_flight_070[2] != 0x2) {
        printf((const char *)D_00277020);
    }
    STORE_POINTER(player_shot_7_flight_070 + 2, D_0025D850);
    if (player_shot_7_flight_071[2] != 0x2) {
        printf((const char *)D_00277040);
    }
    STORE_POINTER(player_shot_7_flight_071 + 2, D_0025D850);
    if (player_shot_7_flight_072[2] != 0x2) {
        printf((const char *)D_00277060);
    }
    STORE_POINTER(player_shot_7_flight_072 + 2, D_0025D850);
    if (player_shot_7_flight_073[2] != 0x2) {
        printf((const char *)D_00277080);
    }
    STORE_POINTER(player_shot_7_flight_073 + 2, D_0025D850);
    if (player_shot_7_flight_074[2] != 0x2) {
        printf((const char *)D_002770A0);
    }
    STORE_POINTER(player_shot_7_flight_074 + 2, D_0025D850);
    if (player_shot_7_flight_075[2] != 0x2) {
        printf((const char *)D_002770C0);
    }
    STORE_POINTER(player_shot_7_flight_075 + 2, D_0025D850);
    if (player_shot_7_flight_076[2] != 0x2) {
        printf((const char *)D_002770E0);
    }
    STORE_POINTER(player_shot_7_flight_076 + 2, D_0025D850);
    if (player_shot_7_flight_077[2] != 0x2) {
        printf((const char *)D_00277100);
    }
    STORE_POINTER(player_shot_7_flight_077 + 2, D_0025D850);
    if (player_shot_7_flight_078[2] != 0x2) {
        printf((const char *)D_00277120);
    }
    STORE_POINTER(player_shot_7_flight_078 + 2, D_0025D850);
    if (player_shot_7_flight_079[2] != 0x2) {
        printf((const char *)D_00277140);
    }
    STORE_POINTER(player_shot_7_flight_079 + 2, D_0025D850);
    if (player_shot_7_flight_080[2] != 0x2) {
        printf((const char *)D_00277160);
    }
    STORE_POINTER(player_shot_7_flight_080 + 2, D_0025D850);
    if (player_shot_7_flight_081[2] != 0x2) {
        printf((const char *)D_00277180);
    }
    STORE_POINTER(player_shot_7_flight_081 + 2, D_0025D850);
    if (player_shot_7_flight_082[2] != 0x2) {
        printf((const char *)D_002771A0);
    }
    STORE_POINTER(player_shot_7_flight_082 + 2, D_0025D850);
    if (player_shot_7_flight_083[2] != 0x2) {
        printf((const char *)D_002771C0);
    }
    STORE_POINTER(player_shot_7_flight_083 + 2, D_0025D850);
    if (player_shot_7_flight_084[2] != 0x2) {
        printf((const char *)D_002771E0);
    }
    STORE_POINTER(player_shot_7_flight_084 + 2, D_0025D850);
    if (player_shot_7_flight_table[176] != 0x0) {
        printf((const char *)D_00277200);
    }
    STORE_POINTER(player_shot_7_flight_table + 176, player_shot_7_flight_088);
    if (player_shot_7_flight_table[178] != 0x2) {
        printf((const char *)D_00277220);
    }
    STORE_POINTER(player_shot_7_flight_table + 178, player_shot_7_flight_089);
    if (player_shot_7_flight_table[180] != 0x4) {
        printf((const char *)D_00277240);
    }
    STORE_POINTER(player_shot_7_flight_table + 180, player_shot_7_flight_090);
    if (player_shot_7_flight_table[182] != 0x6) {
        printf((const char *)D_00277260);
    }
    STORE_POINTER(player_shot_7_flight_table + 182, player_shot_7_flight_091);
    if (player_shot_7_flight_table[184] != 0x8) {
        printf((const char *)D_00277280);
    }
    STORE_POINTER(player_shot_7_flight_table + 184, player_shot_7_flight_092);
    if (player_shot_7_flight_table[186] != 0xa) {
        printf((const char *)D_002772A0);
    }
    STORE_POINTER(player_shot_7_flight_table + 186, player_shot_7_flight_093);
    if (player_shot_7_flight_table[188] != 0xc) {
        printf((const char *)D_002772C0);
    }
    STORE_POINTER(player_shot_7_flight_table + 188, player_shot_7_flight_094);
    if (player_shot_7_flight_table[190] != 0xe) {
        printf((const char *)D_002772E0);
    }
    STORE_POINTER(player_shot_7_flight_table + 190, player_shot_7_flight_095);
    if (player_shot_7_flight_table[192] != 0x10) {
        printf((const char *)D_00277300);
    }
    STORE_POINTER(player_shot_7_flight_table + 192, player_shot_7_flight_096);
    if (player_shot_7_flight_table[194] != 0x12) {
        printf((const char *)D_00277320);
    }
    STORE_POINTER(player_shot_7_flight_table + 194, player_shot_7_flight_097);
    if (player_shot_7_flight_table[196] != 0x14) {
        printf((const char *)D_00277340);
    }
    STORE_POINTER(player_shot_7_flight_table + 196, player_shot_7_flight_098);
    if (player_shot_7_flight_table[198] != 0x16) {
        printf((const char *)D_00277360);
    }
    STORE_POINTER(player_shot_7_flight_table + 198, player_shot_7_flight_099);
    if (player_shot_7_flight_table[200] != 0x18) {
        printf((const char *)D_00277380);
    }
    STORE_POINTER(player_shot_7_flight_table + 200, player_shot_7_flight_100);
    if (player_shot_7_flight_table[202] != 0x1a) {
        printf((const char *)D_002773A0);
    }
    STORE_POINTER(player_shot_7_flight_table + 202, player_shot_7_flight_101);
    if (player_shot_7_flight_table[204] != 0x1c) {
        printf((const char *)D_002773C0);
    }
    STORE_POINTER(player_shot_7_flight_table + 204, player_shot_7_flight_102);
    if (player_shot_7_flight_table[206] != 0x1e) {
        printf((const char *)D_002773E0);
    }
    STORE_POINTER(player_shot_7_flight_table + 206, player_shot_7_flight_103);
    if (player_shot_7_flight_table[208] != 0x20) {
        printf((const char *)D_00277400);
    }
    STORE_POINTER(player_shot_7_flight_table + 208, player_shot_7_flight_104);
    if (player_shot_7_flight_088[2] != 0x2) {
        printf((const char *)D_00277420);
    }
    STORE_POINTER(player_shot_7_flight_088 + 2, D_0025D860);
    if (player_shot_7_flight_089[2] != 0x2) {
        printf((const char *)D_00277440);
    }
    STORE_POINTER(player_shot_7_flight_089 + 2, D_0025D860);
    if (player_shot_7_flight_090[2] != 0x2) {
        printf((const char *)D_00277460);
    }
    STORE_POINTER(player_shot_7_flight_090 + 2, D_0025D860);
    if (player_shot_7_flight_091[2] != 0x2) {
        printf((const char *)D_00277480);
    }
    STORE_POINTER(player_shot_7_flight_091 + 2, D_0025D860);
    if (player_shot_7_flight_092[2] != 0x2) {
        printf((const char *)D_002774A0);
    }
    STORE_POINTER(player_shot_7_flight_092 + 2, D_0025D860);
    if (player_shot_7_flight_093[2] != 0x2) {
        printf((const char *)D_002774C0);
    }
    STORE_POINTER(player_shot_7_flight_093 + 2, D_0025D860);
    if (player_shot_7_flight_094[2] != 0x2) {
        printf((const char *)D_002774E0);
    }
    STORE_POINTER(player_shot_7_flight_094 + 2, D_0025D860);
    if (player_shot_7_flight_095[2] != 0x2) {
        printf((const char *)D_00277500);
    }
    STORE_POINTER(player_shot_7_flight_095 + 2, D_0025D860);
    if (player_shot_7_flight_096[2] != 0x2) {
        printf((const char *)D_00277520);
    }
    STORE_POINTER(player_shot_7_flight_096 + 2, D_0025D860);
    if (player_shot_7_flight_097[2] != 0x2) {
        printf((const char *)D_00277540);
    }
    STORE_POINTER(player_shot_7_flight_097 + 2, D_0025D860);
    if (player_shot_7_flight_098[2] != 0x2) {
        printf((const char *)D_00277560);
    }
    STORE_POINTER(player_shot_7_flight_098 + 2, D_0025D860);
    if (player_shot_7_flight_099[2] != 0x2) {
        printf((const char *)D_00277580);
    }
    STORE_POINTER(player_shot_7_flight_099 + 2, D_0025D860);
    if (player_shot_7_flight_100[2] != 0x2) {
        printf((const char *)D_002775A0);
    }
    STORE_POINTER(player_shot_7_flight_100 + 2, D_0025D860);
    if (player_shot_7_flight_101[2] != 0x2) {
        printf((const char *)D_002775C0);
    }
    STORE_POINTER(player_shot_7_flight_101 + 2, D_0025D860);
    if (player_shot_7_flight_102[2] != 0x2) {
        printf((const char *)D_002775E0);
    }
    STORE_POINTER(player_shot_7_flight_102 + 2, D_0025D860);
    if (player_shot_7_flight_103[2] != 0x2) {
        printf((const char *)D_00277600);
    }
    STORE_POINTER(player_shot_7_flight_103 + 2, D_0025D860);
    if (player_shot_7_flight_104[2] != 0x2) {
        printf((const char *)D_00277620);
    }
    STORE_POINTER(player_shot_7_flight_104 + 2, D_0025D860);
    if (D_0025DFC0[0] != 0x0) {
        printf((const char *)D_00277640);
    }
    STORE_POINTER(D_0025DFC0, D_0028D5B8);
    if (D_0025DFC0[2] != 0x2) {
        printf((const char *)D_00277660);
    }
    STORE_POINTER(D_0025DFC0 + 2, D_0028D5C0);
    if (D_0025DFC0[4] != 0x4) {
        printf((const char *)D_00277680);
    }
    STORE_POINTER(D_0025DFC0 + 4, D_0028D5C8);
    if (D_0025DFC0[6] != 0x6) {
        printf((const char *)D_002776A0);
    }
    STORE_POINTER(D_0025DFC0 + 6, D_0028D5D0);
    if (D_0025DFC0[8] != 0x8) {
        printf((const char *)D_002776C0);
    }
    STORE_POINTER(D_0025DFC0 + 8, D_0028D5D8);
    if (D_0025DFC0[10] != 0xa) {
        printf((const char *)D_002776E0);
    }
    STORE_POINTER(D_0025DFC0 + 10, D_0028D5E0);
    if (D_0025DFC0[12] != 0xc) {
        printf((const char *)D_00277700);
    }
    STORE_POINTER(D_0025DFC0 + 12, D_0028D5E8);
    if (D_0025DFC0[14] != 0xe) {
        printf((const char *)D_00277720);
    }
    STORE_POINTER(D_0025DFC0 + 14, D_0028D5F0);
    if (D_0025DFC0[16] != 0x10) {
        printf((const char *)D_00277740);
    }
    STORE_POINTER(D_0025DFC0 + 16, D_0028D5F8);
    if (D_0025DFC0[18] != 0x12) {
        printf((const char *)D_00277760);
    }
    STORE_POINTER(D_0025DFC0 + 18, D_0028D600);
    if (D_0025DFC0[20] != 0x14) {
        printf((const char *)D_00277780);
    }
    STORE_POINTER(D_0025DFC0 + 20, D_0028D608);
    if (D_0025DFC0[22] != 0x16) {
        printf((const char *)D_002777A0);
    }
    STORE_POINTER(D_0025DFC0 + 22, D_0028D610);
    if (D_0025DFC0[24] != 0x18) {
        printf((const char *)D_002777C0);
    }
    STORE_POINTER(D_0025DFC0 + 24, D_0028D618);
    if (D_0025DFC0[26] != 0x1a) {
        printf((const char *)D_002777E0);
    }
    STORE_POINTER(D_0025DFC0 + 26, D_0028D620);
    if (D_0025DFC0[28] != 0x1c) {
        printf((const char *)D_00277800);
    }
    STORE_POINTER(D_0025DFC0 + 28, D_0028D628);
    if (D_0025DFC0[30] != 0x1e) {
        printf((const char *)D_00277820);
    }
    STORE_POINTER(D_0025DFC0 + 30, D_0028D630);
    if (D_0025DFC0[32] != 0x20) {
        printf((const char *)D_00277840);
    }
    STORE_POINTER(D_0025DFC0 + 32, D_0028D638);
    if (D_0028D5B8[2] != 0x2) {
        printf((const char *)D_00277860);
    }
    STORE_POINTER(D_0028D5B8 + 2, D_0025D870);
    if (D_0028D5C0[2] != 0x2) {
        printf((const char *)D_00277880);
    }
    STORE_POINTER(D_0028D5C0 + 2, D_0025D870);
    if (D_0028D5C8[2] != 0x2) {
        printf((const char *)D_002778A0);
    }
    STORE_POINTER(D_0028D5C8 + 2, D_0025D870);
    if (D_0028D5D0[2] != 0x2) {
        printf((const char *)D_002778C0);
    }
    STORE_POINTER(D_0028D5D0 + 2, D_0025D870);
    if (D_0028D5D8[2] != 0x2) {
        printf((const char *)D_002778E0);
    }
    STORE_POINTER(D_0028D5D8 + 2, D_0025D870);
    if (D_0028D5E0[2] != 0x2) {
        printf((const char *)D_00277900);
    }
    STORE_POINTER(D_0028D5E0 + 2, D_0025D870);
    if (D_0028D5E8[2] != 0x2) {
        printf((const char *)D_00277920);
    }
    STORE_POINTER(D_0028D5E8 + 2, D_0025D870);
    if (D_0028D5F0[2] != 0x2) {
        printf((const char *)D_00277940);
    }
    STORE_POINTER(D_0028D5F0 + 2, D_0025D870);
    if (D_0028D5F8[2] != 0x2) {
        printf((const char *)D_00277960);
    }
    STORE_POINTER(D_0028D5F8 + 2, D_0025D870);
    if (D_0028D600[2] != 0x2) {
        printf((const char *)D_00277980);
    }
    STORE_POINTER(D_0028D600 + 2, D_0025D870);
    if (D_0028D608[2] != 0x2) {
        printf((const char *)D_002779A0);
    }
    STORE_POINTER(D_0028D608 + 2, D_0025D870);
    if (D_0028D610[2] != 0x2) {
        printf((const char *)D_002779C0);
    }
    STORE_POINTER(D_0028D610 + 2, D_0025D870);
    if (D_0028D618[2] != 0x2) {
        printf((const char *)D_002779E0);
    }
    STORE_POINTER(D_0028D618 + 2, D_0025D870);
    if (D_0028D620[2] != 0x2) {
        printf((const char *)D_00277A00);
    }
    STORE_POINTER(D_0028D620 + 2, D_0025D870);
    if (D_0028D628[2] != 0x2) {
        printf((const char *)D_00277A20);
    }
    STORE_POINTER(D_0028D628 + 2, D_0025D870);
    if (D_0028D630[2] != 0x2) {
        printf((const char *)D_00277A40);
    }
    STORE_POINTER(D_0028D630 + 2, D_0025D870);
    if (D_0028D638[2] != 0x2) {
        printf((const char *)D_00277A60);
    }
    STORE_POINTER(D_0028D638 + 2, D_0025D870);
    if (player_shot_7_impact_table[0] != 0x0) {
        printf((const char *)D_00277A80);
    }
    STORE_POINTER(player_shot_7_impact_table, player_shot_7_impact_00);
    if (player_shot_7_impact_table[2] != 0x2) {
        printf((const char *)D_00277AA0);
    }
    STORE_POINTER(player_shot_7_impact_table + 2, player_shot_7_impact_00);
    if (player_shot_7_impact_table[4] != 0x4) {
        printf((const char *)D_00277AC0);
    }
    STORE_POINTER(player_shot_7_impact_table + 4, player_shot_7_impact_02);
    if (player_shot_7_impact_table[6] != 0x6) {
        printf((const char *)D_00277AE0);
    }
    STORE_POINTER(player_shot_7_impact_table + 6, player_shot_7_impact_02);
    if (player_shot_7_impact_table[8] != 0x8) {
        printf((const char *)D_00277B00);
    }
    STORE_POINTER(player_shot_7_impact_table + 8, player_shot_7_impact_04);
    if (player_shot_7_impact_table[10] != 0xa) {
        printf((const char *)D_00277B20);
    }
    STORE_POINTER(player_shot_7_impact_table + 10, player_shot_7_impact_04);
    if (player_shot_7_impact_table[12] != 0xc) {
        printf((const char *)D_00277B40);
    }
    STORE_POINTER(player_shot_7_impact_table + 12, player_shot_7_impact_06);
    if (player_shot_7_impact_table[14] != 0xe) {
        printf((const char *)D_00277B60);
    }
    STORE_POINTER(player_shot_7_impact_table + 14, player_shot_7_impact_06);
    if (player_shot_7_impact_table[16] != 0x10) {
        printf((const char *)D_00277B80);
    }
    STORE_POINTER(player_shot_7_impact_table + 16, player_shot_7_impact_08);
    if (player_shot_7_impact_table[18] != 0x12) {
        printf((const char *)D_00277BA0);
    }
    STORE_POINTER(player_shot_7_impact_table + 18, player_shot_7_impact_08);
    if (player_shot_7_impact_table[20] != 0x14) {
        printf((const char *)D_00277BC0);
    }
    STORE_POINTER(player_shot_7_impact_table + 20, player_shot_7_impact_10);
    if (player_shot_7_impact_table[22] != 0x16) {
        printf((const char *)D_00277BE0);
    }
    STORE_POINTER(player_shot_7_impact_table + 22, player_shot_7_impact_11);
    if (player_shot_7_impact_table[24] != 0x18) {
        printf((const char *)D_00277C00);
    }
    STORE_POINTER(player_shot_7_impact_table + 24, player_shot_7_impact_12);
    if (player_shot_7_impact_table[26] != 0x1a) {
        printf((const char *)D_00277C20);
    }
    STORE_POINTER(player_shot_7_impact_table + 26, player_shot_7_impact_13);
    if (player_shot_7_impact_table[28] != 0x1c) {
        printf((const char *)D_00277C40);
    }
    STORE_POINTER(player_shot_7_impact_table + 28, player_shot_7_impact_14);
    if (player_shot_7_impact_table[30] != 0x1e) {
        printf((const char *)D_00277C60);
    }
    STORE_POINTER(player_shot_7_impact_table + 30, player_shot_7_impact_15);
    if (player_shot_7_impact_table[32] != 0x20) {
        printf((const char *)D_00277C80);
    }
    STORE_POINTER(player_shot_7_impact_table + 32, player_shot_7_impact_15);
    if (player_shot_7_impact_table[34] != 0x22) {
        printf((const char *)D_00277CA0);
    }
    STORE_POINTER(player_shot_7_impact_table + 34, player_shot_7_impact_17);
    if (player_shot_7_impact_table[36] != 0x24) {
        printf((const char *)D_00277CC0);
    }
    STORE_POINTER(player_shot_7_impact_table + 36, player_shot_7_impact_17);
    if (player_shot_7_impact_table[38] != 0x26) {
        printf((const char *)D_00277CE0);
    }
    STORE_POINTER(player_shot_7_impact_table + 38, player_shot_7_impact_19);
    if (player_shot_7_impact_table[40] != 0x28) {
        printf((const char *)D_00277D00);
    }
    STORE_POINTER(player_shot_7_impact_table + 40, player_shot_7_impact_19);
    if (player_shot_7_impact_table[42] != 0x2a) {
        printf((const char *)D_00277D20);
    }
    STORE_POINTER(player_shot_7_impact_table + 42, player_shot_7_impact_21);
    if (player_shot_7_impact_table[44] != 0x2c) {
        printf((const char *)D_00277D40);
    }
    STORE_POINTER(player_shot_7_impact_table + 44, player_shot_7_impact_21);
    if (player_shot_7_impact_table[46] != 0x2e) {
        printf((const char *)D_00277D60);
    }
    STORE_POINTER(player_shot_7_impact_table + 46, player_shot_7_impact_23);
    if (player_shot_7_impact_table[48] != 0x30) {
        printf((const char *)D_00277D80);
    }
    STORE_POINTER(player_shot_7_impact_table + 48, player_shot_7_impact_23);
    if (player_shot_7_impact_00[3] != 0x3) {
        printf((const char *)D_00277DA0);
    }
    STORE_POINTER(player_shot_7_impact_00 + 3, player_shot_7_impact_frames_00);
    if (player_shot_7_impact_02[3] != 0x3) {
        printf((const char *)D_00277DC0);
    }
    STORE_POINTER(player_shot_7_impact_02 + 3, player_shot_7_impact_frames_02);
    if (player_shot_7_impact_04[3] != 0x3) {
        printf((const char *)D_00277DE0);
    }
    STORE_POINTER(player_shot_7_impact_04 + 3, player_shot_7_impact_frames_02);
    if (player_shot_7_impact_06[3] != 0x3) {
        printf((const char *)D_00277E00);
    }
    STORE_POINTER(player_shot_7_impact_06 + 3, player_shot_7_impact_frames_06);
    if (player_shot_7_impact_08[3] != 0x3) {
        printf((const char *)D_00277E20);
    }
    STORE_POINTER(player_shot_7_impact_08 + 3, player_shot_7_impact_frames_06);
    if (player_shot_7_impact_10[3] != 0x3) {
        printf((const char *)D_00277E40);
    }
    STORE_POINTER(player_shot_7_impact_10 + 3, player_shot_7_impact_frames_10);
    if (player_shot_7_impact_11[3] != 0x3) {
        printf((const char *)D_00277E60);
    }
    STORE_POINTER(player_shot_7_impact_11 + 3, player_shot_7_impact_frames_11);
    if (player_shot_7_impact_12[3] != 0x3) {
        printf((const char *)D_00277E80);
    }
    STORE_POINTER(player_shot_7_impact_12 + 3, player_shot_7_impact_frames_11);
    if (player_shot_7_impact_13[3] != 0x3) {
        printf((const char *)D_00277EA0);
    }
    STORE_POINTER(player_shot_7_impact_13 + 3, player_shot_7_impact_frames_13);
    if (player_shot_7_impact_14[3] != 0x3) {
        printf((const char *)D_00277EC0);
    }
    STORE_POINTER(player_shot_7_impact_14 + 3, player_shot_7_impact_frames_13);
    if (player_shot_7_impact_15[3] != 0x3) {
        printf((const char *)D_00277EE0);
    }
    STORE_POINTER(player_shot_7_impact_15 + 3, player_shot_7_impact_frames_15);
    if (player_shot_7_impact_17[3] != 0x3) {
        printf((const char *)D_00277F00);
    }
    STORE_POINTER(player_shot_7_impact_17 + 3, player_shot_7_impact_frames_17);
    if (player_shot_7_impact_19[3] != 0x3) {
        printf((const char *)D_00277F20);
    }
    STORE_POINTER(player_shot_7_impact_19 + 3, player_shot_7_impact_frames_17);
    if (player_shot_7_impact_21[3] != 0x3) {
        printf((const char *)D_00277F40);
    }
    STORE_POINTER(player_shot_7_impact_21 + 3, player_shot_7_impact_frames_21);
    if (player_shot_7_impact_23[3] != 0x3) {
        printf((const char *)D_00277F60);
    }
    STORE_POINTER(player_shot_7_impact_23 + 3, player_shot_7_impact_frames_21);
}
