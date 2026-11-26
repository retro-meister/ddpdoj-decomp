#include "common.h"
#include "task.h"
#include "sdk/ps2sdk.h"
#include "pad.h"
#include "gfx_types.h"
#include "cd.h"

/* One line of a menu screen: where it is drawn, and the slide that brings it there. Positions of the
   slide are in 1/10000. */
typedef struct {
    s32 x;
    s32 y;
    s32 target_x;
    s32 target_y;
    s32 pos_x;
    s32 pos_y;
    s32 speed_x;
    s32 speed_y;
    s32 accel_x;
    s32 accel_y;
    s32 delay;
    s32 alpha;
    s32 z;
    s32 active;
} MenuItem;

#define MENU_ITEMS_PER_PAGE 16

typedef struct {
    s16 x;
    s16 y;
} Point16;

typedef struct {
    s32 a;
    s32 b;
} Pair;

typedef struct {
    u16 status;
    u16 f02;
    u16 f04;
    u16 f06;
    u16 f08;
    u16 f0A;
    u16 f0C;
    u16 f0E;
    u8 pad10[0x28];
    u8 f38;
    u8 f39;
    u8 f3A;
    u8 f3B;
} SaveInfo;

typedef struct {
    u8 step;
    s8 state;
    s8 cursor;
    s8 pad3;
    s16 alpha;
    s16 pad6;
} MenuPage;

typedef struct {
    u8 pad0000[0x327C];
    s32 score1;
    s32 score2;
    u8 pad3284[4];
    u16 stage1;
    u16 stage2;
    u16 pad328C;
    u16 count1;
    u16 pad3290;
    u16 count2;
} SaveBody;

typedef struct {
    u8 stat;
    u8 second;
    u8 minute;
    u8 hour;
    u8 pad;
    u8 day;
    u8 month;
    u8 year;
} CdClock;

typedef struct {
    s16 h[33];
} Row;

extern MenuItem g_menu_items[40][MENU_ITEMS_PER_PAGE];

typedef struct {
    s32 image;
    u16 *palette;
} Wallpaper;

/* The screens of the menu (`g_menu_page`). */
enum {
    MENU_PAGE_MAIN = 0,
    MENU_PAGE_GAME_OPTION = 1,
    MENU_PAGE_SAVE_LOAD = 2,
    MENU_PAGE_DEBUG_OPTION = 3,
    MENU_PAGE_CARD_SAVE = 5,
    MENU_PAGE_CARD_LOAD = 6,
    MENU_PAGE_SIMULATION = 7,
    MENU_PAGE_SIM_SETTING = 8,
    MENU_PAGE_STAGE_DIFFICULTY = 9,
    MENU_PAGE_STAGE_SELECT = 10,
    MENU_PAGE_REPLAY = 11,
    MENU_PAGE_PRACTICE_RANKING = 13,
    MENU_PAGE_ARCADE = 14,
    MENU_PAGE_SYSTEM_OPTION = 15,
    MENU_PAGE_SCREEN_ADJUST = 16,
    MENU_PAGE_SIM_PLAYER = 17,
    MENU_PAGE_SIM_RULES = 18,
    MENU_PAGE_SIM_PARAM = 19,
    MENU_PAGE_SETTINGS_LOAD = 20,
    MENU_PAGE_LAUNCH = 21,
    MENU_PAGE_SUPER_REPLAY = 22,
    MENU_PAGE_23 = 23,
    MENU_PAGE_RANKING = 24,
};


/* Tables. */
extern u8 g_menu_wallpapers_1[];
extern u8 g_menu_wallpapers_3[];
extern u8 g_menu_wallpapers_5[];
extern u8 g_menu_wallpapers_7[];
extern u8 g_menu_wallpapers_9[];
extern s32 D_00270810[6];
extern s16 D_00270828[5];
extern s16 D_00270838[6];
extern char *g_menu_simulation_items[6];
extern char *g_menu_simulation_help[6];
extern char *g_menu_sim_setting_items[6];
extern char *g_menu_sim_setting_help[6];
extern char *g_menu_sim_player_items[8];
extern char *g_menu_sim_player_help[8];
extern char *g_menu_sim_difficulty_names[4];
extern char *g_menu_ship_type_names[2];
extern u8 g_menu_sim_player_value_counts[8];
extern s8 g_menu_sim_player_value_tables[8];
extern char *g_menu_doll_names[3];
extern char *g_menu_numbers_0_to_20[21];
extern char *g_menu_sim_extend_names[8];
extern char **g_menu_sim_player_values[5];
extern char *g_menu_sim_rules_items[12];
extern char *g_menu_sim_rules_help[12];
extern char *g_menu_numbers_1_to_7[7];
extern char *g_menu_start_point_names[2];
extern char *g_menu_sim_death_off_on[2];
extern char *g_menu_default_text;
extern char *g_menu_blank_text_a;
extern char *g_menu_sim_off_on[2];
extern char *g_menu_blank_text_b;
extern char *g_menu_blank_text_c;
extern char *g_menu_sim_level_names_a[9];
extern char *g_menu_sim_level_names_b[9];
extern char *g_menu_numbers_0_to_500[501];
extern char **g_menu_sim_rules_values[9];
extern u16 g_menu_sim_rules_value_counts[12];
extern s8 g_menu_sim_rules_value_tables[14];
extern char *g_menu_percent_text;
extern char *g_menu_sim_param_items[9];
extern char *g_menu_sim_param_help[9];
extern char *g_menu_sim_param_values_0[3];
extern char *g_menu_sim_param_values_1[10];
extern char *g_menu_sim_param_values_2[16];
extern char *g_menu_sim_param_values_3[5];
extern char *g_menu_sim_param_values_4[5];
#ifdef DEATH_LABEL
extern char *g_menu_sim_param_values_5[10];
#else
extern char *g_menu_sim_param_values_5[9];
#endif
extern char **g_menu_sim_param_values[6];
extern u16 g_menu_sim_param_value_counts[7];
extern s8 g_menu_sim_param_value_tables[14];
extern char *g_menu_stage_select_difficulty_help[2];
extern char *g_menu_stage_select_start_help[2];
extern char *g_menu_stage_select_items[12];
extern char *g_menu_dashes_text;
extern char *g_menu_replay_help;
#ifndef DEATH_LABEL
extern char *g_menu_super_replay_help;
#endif
extern char *g_menu_load_file_help;
extern char *g_menu_practice_ranking_text[15];
extern s8 g_menu_page_item_counts[32];
extern char *g_menu_ranking_title;
extern s8 menu_game_option_adjust_table[8];
extern char *D_0028DD18[2];
extern s8 menu_debug_option_adjust_table[8];
extern char *menu_debug_option_draw_table[2];
extern char *menu_debug_option_draw_table_2[2];
extern char *menu_debug_option_draw_table_3[2];
extern char *menu_debug_option_draw_table_4[2];
#ifdef DEATH_LABEL
extern char *g_menu_main_items[7];
#else
extern char *g_menu_main_items[10];
#endif
extern char *g_menu_game_option_items[7];
extern char *g_menu_save_load_items[7];
#ifdef DEATH_LABEL
extern char *g_menu_debug_option_items[8];
#else
extern char *g_menu_debug_option_items[6];
#endif
extern char *g_menu_locked_item_text[3];
extern char *g_menu_arcade_items[6];
extern char *g_menu_system_option_items[14];
extern char *g_menu_ranking_page_text[12];
#ifdef DEATH_LABEL
extern char *menu_death_option_draw_table[4];
#endif
extern char *g_menu_difficulty_names[4];
extern char *g_menu_ship_stock_names[5];
extern char *g_menu_extend_names[4][2];
extern s8 menu_system_option_adjust_table[16];
extern s8 menu_system_option_adjust_table_2[16];
extern char *g_menu_monitor_mode_names[4];
extern char *menu_system_option_draw_table[6];
extern char *g_menu_monitor_mode_tate_names[2];
extern char *g_menu_lever_set_names[2];
extern char *g_menu_monitor_type_names[2];
extern char *D_0028DD60[2];
extern char *g_menu_original_arrange_names[2];
#ifdef DEATH_LABEL
extern s8 menu_death_option_adjust_table[8];
#endif
#ifdef DEATH_LABEL
extern char *menu_death_option_draw_table_3[2];
#endif
extern char *g_menu_round_names[10];
#ifdef DEATH_LABEL
extern char *menu_death_option_draw_table_2[3];
#endif
extern char *g_menu_pause_items[10];
extern char *pause_menu_draw_table[6];
extern Point16 g_menu_item_positions_a[16];
extern Point16 g_menu_item_positions_b[16];
extern Point16 g_menu_item_positions_c[8];
extern s16 D_00271800[136];
extern s32 menu_items_slide_in_table[64];
extern u16 menu_system_option_draw_table_2[8];
extern char *g_menu_now_loading_text;
extern char *g_menu_dot_text;
#ifdef DEATH_LABEL
extern char *g_menu_main_help[7];
#else
extern char *g_menu_main_help[10];
#endif
extern char *g_menu_game_option_help[7];
extern char *g_menu_lever_set_help[2];
extern char *g_menu_save_load_help[7];
#ifdef DEATH_LABEL
extern char *g_menu_debug_option_help[8];
#else
extern char *g_menu_debug_option_help[6];
#endif
extern char *g_menu_unlock_condition_help[2];
extern char *g_menu_empty_help;
extern char *g_menu_arcade_help[6];
extern char *g_menu_system_option_help[14];
#ifdef DEATH_LABEL
extern char *menu_help_draw_table[4];
#endif
extern char *g_menu_ranking_help;
#ifndef DEATH_LABEL
extern char *g_menu_launch_ask[3];
#endif
#ifndef DEATH_LABEL
extern char *g_menu_launch_warning[3];
#endif
#ifdef DEATH_LABEL
extern char *menu_help_draw_table_2[2];
#endif
#ifdef DEATH_LABEL
extern char *menu_help_draw_table_3[2];
#endif
extern char *g_menu_password_title;
extern char *g_menu_pause_help_a[10];
#ifndef DEATH_LABEL
extern char *g_menu_pause_help_b[10];
#endif
#ifdef DEATH_LABEL
extern char *g_menu_pause_help_c[17];
#else
extern char *g_menu_pause_help_c[18];
#endif
extern char g_menu_screen_adjust_help[128];
extern Wallpaper g_menu_wallpapers[5];
#ifdef DEATH_LABEL
extern Point16 g_pause_menu_positions[4];
#else
extern Point16 g_pause_menu_positions[12];
#endif
#ifdef DEATH_LABEL
extern u16 death_D_00263620[16];
#endif
extern char *g_menu_confirm_cancel_text;
extern char *g_menu_cancel_text;
extern s8 screen_setting_apply_table[4];
extern s8 screen_setting_apply_table_2[2];
extern char g_menu_arrow_text[2][2];
extern char *g_menu_result_items[3];
extern char *g_menu_result_help[3];
extern Point16 g_menu_result_positions[8];
extern char *g_menu_save_file_help;
extern char *g_replay_slot_ship_names[2];
extern char *g_replay_slot_shot_names[4];
extern char *g_replay_slot_difficulty_names[4];

s32 D_00270810[6] = {
    0, 0x60000, 8, 0x64, 0, 0,
};

s16 D_00270828[5] = {
    1, 0, 0, 0x14, 0,
};

s16 D_00270838[6] = {
    0, 0, 0, 0, 0, 0,
};

char *g_menu_simulation_items[6] = {
    "SIMULATION MODE",
    "SETTING",
    "STAGE SELECT",
    "REPLAY",
    "SUPER REPLAY",
    "EXIT",
};

char *g_menu_simulation_help[6] = {
    SJIS("￥"),
    SJIS("プレイヤーの設定を／変更します。￥"),
    SJIS("ステージを選択して／ゲームを開始します。￥"),
    SJIS("リプレイを再生します。￥"),
    SJIS("スーパーリプレイを／再生します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};

char *g_menu_sim_setting_items[6] = {
    "SETTING",
    "PLAYER     SETTING",
    "SIMULATION SETTING",
    "PARAMETER  SETTING",
    "SETTING LOAD",
    "EXIT",
};

#ifdef DEATH_LABEL
char *g_menu_sim_setting_help[6] = {
    SJIS("￥"),
    SJIS("使用する自機等の設定を変更／します。￥"),
    SJIS("各種シミュレーション設定を／変更します。￥"),
    SJIS("各種シミュレーション設定に／関係するパラメーターを変更／します。￥"),
    SJIS("リプレイデータから各種設定／をロードします￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#else
char *g_menu_sim_setting_help[6] = {
    SJIS("￥"),
    SJIS("機体関係の設定を／変更します。￥"),
    SJIS("シミュレーション設定を／変更します。￥"),
    SJIS("シミュレーション設定に／関係するパラメーターを／変更します。￥"),
    SJIS("リプレイデータから／各種設定をロードします。￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#endif

char *g_menu_sim_player_items[8] = {
    "PLAYER SETTING",
    "DIFFICULTY ",
    "PLAYERTYPE ",
    "DOLL TYPE  ",
    "SHIP STOCK ",
    "EXTEND     ",
    "DEFAULT",
    "EXIT",
};

char *g_menu_sim_player_help[8] = {
    SJIS("￥"),
    SJIS("難易度を設定します。￥"),
    SJIS("機体タイプを設定します。￥"),
    SJIS("強化タイプを設定します。￥"),
    SJIS("残機数を設定します。￥"),
    SJIS("エクステンドを設定します。￥"),
    SJIS("デフォルト設定に戻します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};

char *g_menu_sim_difficulty_names[4] = {
    "EASY",
    "NORMAL",
    "HARD",
    "VERY HARD",
};

char *g_menu_ship_type_names[2] = {
    "TYPE-A",
    "TYPE-B",
};

u8 g_menu_sim_player_value_counts[8] = {
    4, 2, 3, 0x15, 4, 0, 0, 0,
};

s8 g_menu_sim_player_value_tables[8] = {
    -1, 0, 1, 2, 3, 4, -1, -1,
};

char *g_menu_doll_names[3] = {
    "SHOTIA",
    "LEINYAN",
    "EXY",
};

char *g_menu_numbers_0_to_20[21] = {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "FREE",
};

char *g_menu_sim_extend_names[8] = {
    "1ST 10000000PTS",
    "2ND 30000000PTS",
    "1ST 50000000PTS",
    "2ND100000000PTS",
    "1ST  5000000PTS",
    "2ND 20000000PTS",
    "NO EXTEND",
    "NO EXTEND",
};

char **g_menu_sim_player_values[5] = {
    g_menu_sim_difficulty_names,
    g_menu_ship_type_names,
    g_menu_doll_names,
    g_menu_numbers_0_to_20,
    g_menu_sim_extend_names,
};

char *g_menu_sim_rules_items[12] = {
    "SIMULATION SETTING",
    "START POINT   ",
    "DEATH         ",
    "RANK          ",
    "MAX   BOM     ",
    "STOCK BOM     ",
    "HYPER         ",
    "HYPER TIME    ",
    "HYPER STOCK   ",
    "HYPER GAGE    ",
    "DEFAULT",
    "EXIT",
};

#ifdef DEATH_LABEL
char *g_menu_sim_rules_help[12] = {
    SJIS("￥"),
    SJIS("ゲーム開始位置を設定します￥"),
    SJIS("ミス時の復活状況の設定。／ON  設定の状況で復活／OFF POWER-UPを失って復活￥"),
    SJIS("初期ランクを設定します。／○ボタン押下で、DEFAULT／初期ランク指定切り替え￥"),
    SJIS("ボム数の上限を設定します。￥"),
    SJIS("取得しているボム数を設定／します。￥"),
    SJIS("スタート時のハイパー状態の／ON/OFFを設定します。￥"),
    SJIS("HYPER ON時のハイパー継続／時間を設定します。￥"),
    SJIS("ハイパー数を設定します。／HYPER ON: ハイパー使用数／HYPER OFF:ハイパー取得数￥"),
    SJIS("HYPER ON時のハイパーゲージ／の数量を設定します。￥"),
    SJIS("デフォルト設定に戻します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#else
char *g_menu_sim_rules_help[12] = {
    SJIS("￥"),
    SJIS("ゲーム開始位置を／設定します。￥"),
    SJIS("ミス時の復活状況の設定。／ON  設定の状況で復活／OFF POWER-UPを失って復活￥"),
    SJIS("初期ランクを設定します。／○ボタン押下後、／左右で変更します。￥"),
    SJIS("持てるボムの上限数を／設定します。￥"),
    SJIS("取得しているボム数を／設定します。￥"),
    SJIS("スタート時のハイパー状態の／ON/OFFを設定します。￥"),
    SJIS("HYPER ON時のハイパー／継続時間を設定します。￥"),
    SJIS("ハイパー数を設定します。／HYPER ON: ハイパー使用数／HYPER OFF:ハイパー取得数￥"),
    SJIS("ハイパーゲージの数量を／設定します。￥"),
    SJIS("デフォルト設定に戻します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#endif

char *g_menu_numbers_1_to_7[7] = {
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "DEFAULT",
};

char *g_menu_start_point_names[2] = {
    "STAGE FIRST",
    "BOSS",
};

char *g_menu_sim_death_off_on[2] = {
    "OFF",
    "ON",
};

char *g_menu_default_text = "DEFAULT ";

char *g_menu_blank_text_a = "            ";

char *g_menu_sim_off_on[2] = {
    "OFF",
    "ON",
};

char *g_menu_blank_text_b = "            ";

char *g_menu_blank_text_c = "            ";

char *g_menu_sim_level_names_a[9] = {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "MAXIMUM",
    "DEFAULT",
};

char *g_menu_sim_level_names_b[9] = {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "MAXIMUM",
    "DEFAULT",
};

/* A table nothing uses was defined here: the retail link left it out, and the text it was
   the first to mention kept its place. */
#pragma define_section unused ".unused"
#pragma section unused begin
char *unused_text_0 = "";
#pragma section unused end

char *g_menu_numbers_0_to_500[501] = {
    "  0",
    "  1",
    "  2",
    "  3",
    "  4",
    "  5",
    "  6",
    "  7",
    "  8",
    "  9",
    " 10",
    " 11",
    " 12",
    " 13",
    " 14",
    " 15",
    " 16",
    " 17",
    " 18",
    " 19",
    " 20",
    " 21",
    " 22",
    " 23",
    " 24",
    " 25",
    " 26",
    " 27",
    " 28",
    " 29",
    " 30",
    " 31",
    " 32",
    " 33",
    " 34",
    " 35",
    " 36",
    " 37",
    " 38",
    " 39",
    " 40",
    " 41",
    " 42",
    " 43",
    " 44",
    " 45",
    " 46",
    " 47",
    " 48",
    " 49",
    " 50",
    " 51",
    " 52",
    " 53",
    " 54",
    " 55",
    " 56",
    " 57",
    " 58",
    " 59",
    " 60",
    " 61",
    " 62",
    " 63",
    " 64",
    " 65",
    " 66",
    " 67",
    " 68",
    " 69",
    " 70",
    " 71",
    " 72",
    " 73",
    " 74",
    " 75",
    " 76",
    " 77",
    " 78",
    " 79",
    " 80",
    " 81",
    " 82",
    " 83",
    " 84",
    " 85",
    " 86",
    " 87",
    " 88",
    " 89",
    " 90",
    " 91",
    " 92",
    " 93",
    " 94",
    " 95",
    " 96",
    " 97",
    " 98",
    " 99",
    "100",
    "101",
    "102",
    "103",
    "104",
    "105",
    "106",
    "107",
    "108",
    "109",
    "110",
    "111",
    "112",
    "113",
    "114",
    "115",
    "116",
    "117",
    "118",
    "119",
    "120",
    "121",
    "122",
    "123",
    "124",
    "125",
    "126",
    "127",
    "128",
    "129",
    "130",
    "131",
    "132",
    "133",
    "134",
    "135",
    "136",
    "137",
    "138",
    "139",
    "140",
    "141",
    "142",
    "143",
    "144",
    "145",
    "146",
    "147",
    "148",
    "149",
    "150",
    "151",
    "152",
    "153",
    "154",
    "155",
    "156",
    "157",
    "158",
    "159",
    "160",
    "161",
    "162",
    "163",
    "164",
    "165",
    "166",
    "167",
    "168",
    "169",
    "170",
    "171",
    "172",
    "173",
    "174",
    "175",
    "176",
    "177",
    "178",
    "179",
    "180",
    "181",
    "182",
    "183",
    "184",
    "185",
    "186",
    "187",
    "188",
    "189",
    "190",
    "191",
    "192",
    "193",
    "194",
    "195",
    "196",
    "197",
    "198",
    "199",
    "200",
    "201",
    "202",
    "203",
    "204",
    "205",
    "206",
    "207",
    "208",
    "209",
    "210",
    "211",
    "212",
    "213",
    "214",
    "215",
    "216",
    "217",
    "218",
    "219",
    "220",
    "221",
    "222",
    "223",
    "224",
    "225",
    "226",
    "227",
    "228",
    "229",
    "230",
    "231",
    "232",
    "233",
    "234",
    "235",
    "236",
    "237",
    "238",
    "239",
    "240",
    "241",
    "242",
    "243",
    "244",
    "245",
    "246",
    "247",
    "248",
    "249",
    "250",
    "251",
    "252",
    "253",
    "254",
    "255",
    "256",
    "257",
    "258",
    "259",
    "260",
    "261",
    "262",
    "263",
    "264",
    "265",
    "266",
    "267",
    "268",
    "269",
    "270",
    "271",
    "272",
    "273",
    "274",
    "275",
    "276",
    "277",
    "278",
    "279",
    "280",
    "281",
    "282",
    "283",
    "284",
    "285",
    "286",
    "287",
    "288",
    "289",
    "290",
    "291",
    "292",
    "293",
    "294",
    "295",
    "296",
    "297",
    "298",
    "299",
    "300",
    "301",
    "302",
    "303",
    "304",
    "305",
    "306",
    "307",
    "308",
    "309",
    "310",
    "311",
    "312",
    "313",
    "314",
    "315",
    "316",
    "317",
    "318",
    "319",
    "320",
    "321",
    "322",
    "323",
    "324",
    "325",
    "326",
    "327",
    "328",
    "329",
    "330",
    "331",
    "332",
    "333",
    "334",
    "335",
    "336",
    "337",
    "338",
    "339",
    "340",
    "341",
    "342",
    "343",
    "344",
    "345",
    "346",
    "347",
    "348",
    "349",
    "350",
    "351",
    "352",
    "353",
    "354",
    "355",
    "356",
    "357",
    "358",
    "359",
    "360",
    "361",
    "362",
    "363",
    "364",
    "365",
    "366",
    "367",
    "368",
    "369",
    "370",
    "371",
    "372",
    "373",
    "374",
    "375",
    "376",
    "377",
    "378",
    "379",
    "380",
    "381",
    "382",
    "383",
    "384",
    "385",
    "386",
    "387",
    "388",
    "389",
    "390",
    "391",
    "392",
    "393",
    "394",
    "395",
    "396",
    "397",
    "398",
    "399",
    "400",
    "401",
    "402",
    "403",
    "404",
    "405",
    "406",
    "407",
    "408",
    "409",
    "410",
    "411",
    "412",
    "413",
    "414",
    "415",
    "416",
    "417",
    "418",
    "419",
    "420",
    "421",
    "422",
    "423",
    "424",
    "425",
    "426",
    "427",
    "428",
    "429",
    "430",
    "431",
    "432",
    "433",
    "434",
    "435",
    "436",
    "437",
    "438",
    "439",
    "440",
    "441",
    "442",
    "443",
    "444",
    "445",
    "446",
    "447",
    "448",
    "449",
    "450",
    "451",
    "452",
    "453",
    "454",
    "455",
    "456",
    "457",
    "458",
    "459",
    "460",
    "461",
    "462",
    "463",
    "464",
    "465",
    "466",
    "467",
    "468",
    "469",
    "470",
    "471",
    "472",
    "473",
    "474",
    "475",
    "476",
    "477",
    "478",
    "479",
    "480",
    "481",
    "482",
    "483",
    "484",
    "485",
    "486",
    "487",
    "488",
    "489",
    "490",
    "491",
    "492",
    "493",
    "494",
    "495",
    "496",
    "497",
    "498",
    "499",
    "500",
};

char **g_menu_sim_rules_values[9] = {
    g_menu_start_point_names,
    g_menu_sim_death_off_on,
    &g_menu_default_text,
    g_menu_numbers_1_to_7,
    g_menu_sim_level_names_a,
    g_menu_sim_off_on,
    &g_menu_blank_text_c,
    g_menu_sim_level_names_b,
    &g_menu_blank_text_b,
};

u16 g_menu_sim_rules_value_counts[12] = {
    2, 2, 0x100, 7, 9, 2, 0x65, 6,
    0x1f5, 0, 0, 0,
};

s8 g_menu_sim_rules_value_tables[14] = {
    -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, -1, -1, 0, 0,
};

char *g_menu_percent_text = "%";

char *g_menu_sim_param_items[9] = {
    "PARAMETER SETTING",
    "MAXI LEVEL     ",
    "MAXI BOM_CNT   ",
    "HYPER CNT      ",
    "LASER LEVEL    ",
    "SHOT  LEVEL    ",
    "POWERUP ITEM   ",
    "DEFAULT",
    "EXIT",
};

#ifdef DEATH_LABEL
char *g_menu_sim_param_help[9] = {
    SJIS("￥"),
    SJIS("MAXIMUMのレベルを設定／します。￥"),
    SJIS("MAXIMUMの倍率を設定します￥"),
    SJIS("ハイパー累積使用回数を設定／します。￥"),
    SJIS("レーザーレベルを設定します￥"),
    SJIS("ショットレベルを設定します￥"),
    SJIS("ミス時に出現するパワーアッ／プアイテム数を設定します。￥"),
    SJIS("デフォルト設定に戻します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#else
char *g_menu_sim_param_help[9] = {
    SJIS("￥"),
    SJIS("MAXIMUMのレベルを／設定します。￥"),
    SJIS("MAXIMUMの倍率を設定します。￥"),
    SJIS("ハイパー累積使用回数を／設定します。￥"),
    SJIS("レーザーレベルを設定します￥"),
    SJIS("ショットレベルを設定します￥"),
    SJIS("ミス時に出現する／パワーアップアイテム数の／初期値を設定します。￥"),
    SJIS("デフォルト設定に戻します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#endif

char *g_menu_sim_param_values_0[3] = {
    "1",
    "2",
    "3",
};

char *g_menu_sim_param_values_1[10] = {
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
};

char *g_menu_sim_param_values_2[16] = {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
};

char *g_menu_sim_param_values_3[5] = {
    "0",
    "1",
    "2",
    "3",
    "4",
};

char *g_menu_sim_param_values_4[5] = {
    "0",
    "1",
    "2",
    "3",
    "4",
};

#ifdef DEATH_LABEL
char *g_menu_sim_param_values_5[10] = {
    "DEFAULT",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
};
#else
char *g_menu_sim_param_values_5[9] = {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
};
#endif

char **g_menu_sim_param_values[6] = {
    g_menu_sim_param_values_0,
    g_menu_sim_param_values_1,
    g_menu_sim_param_values_2,
    g_menu_sim_param_values_3,
    g_menu_sim_param_values_4,
    g_menu_sim_param_values_5,
};

#ifdef DEATH_LABEL
u16 g_menu_sim_param_value_counts[7] = {
    3, 0xa, 0x10, 5, 5, 0xa, 0,
};
#else
u16 g_menu_sim_param_value_counts[7] = {
    3, 0xa, 0x10, 5, 5, 9, 0,
};
#endif

s8 g_menu_sim_param_value_tables[14] = {
    -1, 0, 1, 2, 3, 4, 5, -1, -1, 0, 0, 0, 0, 0,
};

char *g_menu_stage_select_difficulty_help[2] = {
    SJIS("難易度を選択します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};

char *g_menu_stage_select_start_help[2] = {
    SJIS("ステージを選択して／ゲームを開始します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};

char *g_menu_stage_select_items[12] = {
    "STAGE SELECT",
    "1-1 START",
    "1-2 START",
    "1-3 START",
    "1-4 START",
    "1-5 START",
    "2-1 START",
    "2-2 START",
    "2-3 START",
    "2-4 START",
    "2-5 START",
    "EXIT",
};

char *g_menu_dashes_text = "---";

#ifdef DEATH_LABEL
char *g_menu_replay_help = SJIS("ロードするファイルを選択／して下さい。／      ○決定  ×戻る￥");
#else
char *g_menu_replay_help = SJIS("リプレイを再生します。￥");
#endif

#ifndef DEATH_LABEL
char *g_menu_super_replay_help = SJIS("スーパーリプレイを／再生します。￥");
#endif

char *g_menu_load_file_help = SJIS("設定をロードするファイルを／選択して下さい。／      ○決定  ×戻る￥");

char *g_menu_practice_ranking_text[15] = {
    "PRACTICE STAGE RANKING",
    "1   STAGE                 ",
    "1   EASY         NORMAL",
    "1.            1.",
    "2.            2.",
    "3.            3.",
    "4.            4.",
    "5.            5.",
    "    HARD        VERY HARD",
    "1.            1.",
    "2.            2.",
    "3.            3.",
    "4.            4.",
    "5.            5.",
    "              EXIT",
};

#ifdef DEATH_LABEL
s8 g_menu_page_item_counts[32] = {
    6, 7, 5, 8, 0, 0, 0, 6, 6, 6, 0xc, 1, 0xc, 0xf, 6, 0xe,
    0, 8, 0xc, 9, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,
};
#else
s8 g_menu_page_item_counts[32] = {
    9, 7, 5, 6, 0, 0, 0, 6, 6, 6, 0xc, 1, 0xc, 0xf, 6, 0xe,
    0, 8, 0xc, 9, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,
};
#endif

char *g_menu_ranking_title = SJIS("ランキング￥");

s8 menu_game_option_adjust_table[8] = {
    0, 4, 5, 4, 2, 0, 0, 0,
};

char *D_0028DD18[2] = {
    "OFF",
    "ON",
};

#ifdef DEATH_LABEL
s8 menu_debug_option_adjust_table[8] = {
    0, 2, 2, 2, 2, 100, 2, 0,
};
#else
s8 menu_debug_option_adjust_table[8] = {
    0, 2, 2, 2, 2, 2, 0, 0,
};
#endif

char *menu_debug_option_draw_table[2] = {
    "1",
    "2",
};

char *menu_debug_option_draw_table_2[2] = {
    "OFF",
    "ON",
};

char *menu_debug_option_draw_table_3[2] = {
    "ON",
    "OFF",
};

char *menu_debug_option_draw_table_4[2] = {
    "2",
    "1",
};

#ifdef DEATH_LABEL
char *g_menu_main_items[7] = {
    "DEATH LABEL",
    "GAME START",
    "RANKING",
    "SYSTEM OPTION",
    "SAVE/LOAD",
    "EXIT",
    "DEBUG OPTION",
};
#else
char *g_menu_main_items[10] = {
    " ",
    "ARCADE MODE",
    "SIMULATION MODE",
    "DEATH LABEL",
    "GALLERY",
    "RANKING",
    "SYSTEM OPTION",
    "SAVE/LOAD",
    "EXIT",
    "DEBUG OPTION",
};
#endif

char *g_menu_game_option_items[7] = {
    "GAME OPTION",
    "DIFFICULTY",
    "SHIP STOCK",
    "EXTEND",
    "VIBRATION",
    "DEFAULT",
    "EXIT",
};

char *g_menu_save_load_items[7] = {
    "SAVE/LOAD",
    "LOAD",
    "SAVE",
    "AUTO SAVE",
    "EXIT",
    "SE TEST",
    "MUSIC TEST",
};

#ifdef DEATH_LABEL
char *g_menu_debug_option_items[8] = {
    "DEBUG OPTION",
    "START ROUND",
    "HIT DISP",
    "HIT DISP T",
    "ROUND SET",
    "TAMA LIMIT",
    "TAMA MABIKI",
    "EXIT",
};
#else
char *g_menu_debug_option_items[6] = {
    "DEBUG OPTION",
    "START ROUND",
    "HIT DISP",
    "HIT DISP T",
    "ROUND SET",
    "EXIT",
};
#endif

char *g_menu_locked_item_text[3] = {
    "?????????",
    "?????????",
    "-----------",
};

char *g_menu_arcade_items[6] = {
    "ARCADE MODE",
    "GAME START",
    "NO BULLET MODE",
    "GAME OPTION",
    "REPLAY SAVE",
    "EXIT",
};

char *g_menu_system_option_items[14] = {
    "SYSTEM OPTION",
    "LEVER SET",
    "MONITOR MODE",
    "MONITOR TYPE",
    "WALL PAPER",
    "MAP DISPLAY",
    "BGM SELECT",
    "SCREEN ADJUST",
    "    BUTTON CONFIG ",
    " 1P-SHOT      2P-SHOT",
    " 1P-BOMBER    2P-BOMBER",
    " 1P-RAPID     2P-RAPID",
    "DEFAULT",
    "EXIT",
};

char *g_menu_ranking_page_text[12] = {
    "PRACTICE STAGE RANKING",
    "STAGE ",
    " ",
    "  1ST             PTS",
    "  2ND             PTS",
    "  3RD             PTS",
    "  4TH             PTS",
    "  5TH             PTS",
    " ",
    "SCORE             PTS",
    " ",
    "            EXIT",
};

#ifdef DEATH_LABEL
char *menu_death_option_draw_table[4] = {
    "GAME OPTION",
    "PLAYER TYPE ",
    "DOLL TYPE  ",
    "EXIT",
};
#endif

char *g_menu_difficulty_names[4] = {
    "EASY",
    "NORMAL",
    "HARD",
    "VERY HARD",
};

char *g_menu_ship_stock_names[5] = {
    "3",
    "4",
    "5",
    "1",
    "2",
};

char *g_menu_extend_names[4][2] = {
    "1ST 10000000PTS",
    "2ND 30000000PTS",
    "1ST 50000000PTS",
    "2ND100000000PTS",
    "1ST  5000000PTS",
    "2ND 20000000PTS",
    "NO EXTEND",
    "NO EXTEND",
};

s8 menu_system_option_adjust_table[16] = {
    0, 2, 4, 2, 6, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

s8 menu_system_option_adjust_table_2[16] = {
    0, 2, 2, 2, 6, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

/* A table nothing uses was defined here: the retail link left it out, and the text it was
   the first to mention kept its place. */
#pragma define_section unused ".unused"
#pragma section unused begin
char *unused_text_1[2] = {
    "YOKO",
    "TATE",
};
#pragma section unused end

char *g_menu_monitor_mode_names[4] = {
    "YOKO ANTI",
    "YOKO",
    "TATE HOSEI",
    "TATE",
};

char *menu_system_option_draw_table[6] = {
    "1",
    "2",
    "3",
    "4",
    "5",
    "OFF",
};

char *g_menu_monitor_mode_tate_names[2] = {
    "TATE HOSEI",
    "TATE",
};

char *g_menu_lever_set_names[2] = {
    "YOKO",
    "TATE",
};

char *g_menu_monitor_type_names[2] = {
    "4:3",
    "16:9",
};

char *D_0028DD60[2] = {
    "OFF",
    "ON",
};

char *g_menu_original_arrange_names[2] = {
    "ORIGINAL",
    "ARRANGE",
};

#ifdef DEATH_LABEL
s8 menu_death_option_adjust_table[8] = {
    0, 2, 3, 0, 0, 0, 0, 0,
};

char *menu_death_option_draw_table_3[2] = {
    "TYPE-A",
    "TYPE-B",
};
#endif

char *g_menu_round_names[10] = {
    "1-1",
    "1-2",
    "1-3",
    "1-4",
    "1-5",
    "2-1",
    "2-2",
    "2-3",
    "2-4",
    "2-5",
};

#ifdef DEATH_LABEL
char *menu_death_option_draw_table_2[3] = {
    "SHOTIA",
    "LEINYAN",
    "EXY",
};
#endif

char *g_menu_pause_items[10] = {
    "PAUSE",
    "MONITOR MODE",
    "VIBRATION",
    "WALL PAPER",
    "MAP DISPLAY",
    "SCREEN ADJUST",
    "RETRY",
    "QUIT",
    "ROUND SEL",
    "STAGE SEL",
};

char *pause_menu_draw_table[6] = {
    "1",
    "2",
    "3",
    "4",
    "5",
    "OFF",
};

Point16 g_menu_item_positions_a[16] = {
    { 0x18c, 8 },
    { 0x164, 8 },
    { 0x14c, 8 },
    { 0x134, 8 },
    { 0x11c, 8 },
    { 0x104, 8 },
    { 0xec, 8 },
    { 0xd4, 8 },
    { 0xbc, 8 },
    { 0xa4, 8 },
    { 0x8c, 8 },
    { 0x74, 8 },
    { 0x5c, 8 },
    { 0x44, 8 },
    { 0x14, 8 },
    { -4, 8 },
};

Point16 g_menu_item_positions_b[16] = {
    { 0x1a4, 8 },
    { 0x17c, 8 },
    { 0x164, 8 },
    { 0x14c, 8 },
    { 0x134, 8 },
    { 0x11c, 8 },
    { 0x104, 8 },
    { 0xec, 8 },
    { 0xd4, 8 },
    { 0xbc, 8 },
    { 0xa4, 8 },
    { 0x8c, 8 },
    { 0x74, 8 },
    { 0x5c, 8 },
    { 0x2c, 8 },
    { 0x14, 8 },
};

Point16 g_menu_item_positions_c[8] = {
    { 0x17e, 8 },
    { 0x137, 8 },
    { 0xf0, 8 },
    { 0xa9, 8 },
    { 0x62, 8 },
    { 0x62, 8 },
    { 0, 0 },
    { 0, 0 },
};

s16 D_00271800[136] = {
    0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
    0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0, 0,
    0, 0, 1, 0, 3, 0, 6, 0,
    0xa, 0, 0xf, 0, 0x15, 0, 0x1c, 0,
    0x24, 0, 0x2d, 0, 0x37, 0, 0x42, 0,
    0x4e, 0, 0x5b, 0, 0x69, 0, 0x78, 0,
    0x88, 0, 0x99, 0, 0xab, 0, 0xbe, 0,
    0xd2, 0, 0xe7, 0, 0xfd, 0, 0x114, 0,
    0x12c, 0, 0x145, 0, 0x15f, 0, 0x17a, 0,
    0x196, 0, 0x1b3, 0, 0x1d1, 0, 0x1f0, 0,
    0x210, 0, 0x231, 0, 0x253, 0, 0x276, 0,
    0x29a, 0, 0x2bf, 0, 0x2e5, 0, 0x30c, 0,
    0x334, 0, 0x35d, 0, 0x387, 0, 0x3b2, 0,
    0x3de, 0, 0x40b, 0, 0x439, 0, 0x468, 0,
    0x498, 0, 0x4c9, 0, 0x4fb, 0, 0x52e, 0,
    0x562, 0, 0x597, 0, 0x5cd, 0, 0x604, 0,
    0x63c, 0, 0x675, 0, 0x6af, 0, 0x6ea, 0,
};

s32 menu_items_slide_in_table[64] = {
    0x726, 0x763, 0x7a1, 0x7e0, 0x820, 0x861, 0x8a3, 0x8e6,
    0x92a, 0x96f, 0x9b5, 0x9fc, 0xa44, 0xa8d, 0xad7, 0xb22,
    0xb6e, 0xbbb, 0xc09, 0xc58, 0xca8, 0xcf9, 0xd4b, 0xd9e,
    0xdf2, 0xe47, 0xe9d, 0xef4, 0xf4c, 0xfa5, 0xfff, 0x105a,
    0x10b6, 0x1113, 0x1171, 0x11d0, 0x1230, 0x1291, 0x12f3, 0x1356,
    0x13ba, 0x141f, 0x1485, 0x14ec, 0x1554, 0x15bd, 0x1627, 0x1692,
    0x16fe, 0x176b, 0x17d9, 0x1848, 0x18b8, 0x1929, 0x199b, 0x1a0e,
    0x1a82, 0x1af7, 0x1b6d, 0x1be4, 0x1c5c, 0, 0, 0,
};

u16 menu_system_option_draw_table_2[8] = {
    0x2281, 0x2283, 0x2280, 0x2282, 0x227e, 0x227c, 0x227d, 0x227f,
};

char *g_menu_now_loading_text = "NOW LOADING";

char *g_menu_dot_text = ".";

#ifdef DEATH_LABEL
char *g_menu_main_help[7] = {
    SJIS("￥"),
    SJIS("ゲームを開始します。￥"),
    SJIS("デスレーベルのランキングを／表示します。￥"),
    SJIS("システムオプションの設定を／変更します。￥"),
    SJIS("ゲームデータの／セーブ・ロードを行います。￥"),
    SJIS("怒首領蜂大往生を／起動します。￥"),
    SJIS("デバックオプションの設定を／変更します。￥"),
};
#else
char *g_menu_main_help[10] = {
    SJIS("￥"),
    SJIS("アーケードモードで／遊びます。￥"),
    SJIS("シミュレーションモードで／遊びます。￥"),
    SJIS("デスレーベルを起動します。￥"),
    SJIS("ギャラリーを起動します。￥"),
    SJIS("ランキングを表示します。￥"),
    SJIS("システムオプションの設定を／変更します。￥"),
    SJIS("ゲームデータのセーブ、／ロードを行います。￥"),
    SJIS("タイトル画面に戻ります。￥"),
    SJIS("デバックオプションの設定を／変更します。￥"),
};
#endif

char *g_menu_game_option_help[7] = {
    SJIS("￥"),
    SJIS("難易度を設定します。￥"),
    SJIS("残機数を設定します。￥"),
    SJIS("エクステンドを設定します。￥"),
    SJIS("振動のON/OFFを設定します。￥"),
    SJIS("設定を初期値に戻します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};

char *g_menu_lever_set_help[2] = {
    SJIS("横配置用方向キー入力に／設定します。￥"),
    SJIS("縦配置用方向キー入力に／設定します。￥"),
};

#ifdef DEATH_LABEL
char *g_menu_save_load_help[7] = {
    SJIS("￥"),
    SJIS("ゲームデータを／ロードします。￥"),
    SJIS("ゲームデータを／セーブします。￥"),
    SJIS("オートセーブのON/OFFを／設定します。￥"),
    SJIS("前のメニューに戻ります。￥"),
    SJIS("デバック項目SE TEST￥"),
    SJIS("デバック項目MUSIC TEST￥"),
};
#else
char *g_menu_save_load_help[7] = {
    SJIS("￥"),
    SJIS("ゲームデータを／ロードします。￥"),
    SJIS("ゲームデータを／セーブします。￥"),
    SJIS("オートセーブの／ON/OFFを設定します。￥"),
    SJIS("前のメニューに戻ります。￥"),
    SJIS("デバック項目SE TEST￥"),
    SJIS("デバック項目MUSIC TEST￥"),
};
#endif

#ifdef DEATH_LABEL
char *g_menu_debug_option_help[8] = {
    SJIS("￥"),
    SJIS("ゲーム開始ラウンドを設定／します。￥"),
    SJIS("敵の当たり判定領域表示の／ON/OFFを設定します。￥"),
    SJIS("HIT DISP ON時、敵弾表示の／ON/OFFを設定します。￥"),
    SJIS("周回数を設定します。￥"),
    SJIS("敵弾スピードのリミット／を設定します。￥"),
    SJIS("敵弾発射奇数偶数。￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#else
char *g_menu_debug_option_help[6] = {
    SJIS("￥"),
    SJIS("ゲーム開始ラウンドを設定／します。￥"),
    SJIS("敵の当たり判定領域表示の／ON/OFFを設定します。￥"),
    SJIS("HIT DISP ON時、敵弾表示の／ON/OFFを設定します。￥"),
    SJIS("周回数を設定します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#endif

char *g_menu_unlock_condition_help[2] = {
    SJIS("なんらかの項目出現条件表示￥"),
    NULL,
};

char *g_menu_empty_help = SJIS("￥");

#ifdef DEATH_LABEL
char *g_menu_arcade_help[6] = {
    SJIS("￥"),
    SJIS("ゲームを開始します。￥"),
    SJIS("敵弾無しでゲームを開始／します。￥"),
    SJIS("ゲームオプションの設定を／変更します。￥"),
    SJIS("リプレイセーブのON/OFFを／設定します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#else
char *g_menu_arcade_help[6] = {
    SJIS("￥"),
    SJIS("ゲームを開始します。￥"),
    SJIS("敵弾無しで／ゲームを開始します。￥"),
    SJIS("ゲームオプションの設定を／変更します。￥"),
    SJIS("リプレイセーブのON/OFFを／設定します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#endif

#ifdef DEATH_LABEL
char *g_menu_system_option_help[14] = {
    SJIS("￥"),
    SJIS("モニター設置方向を設定。￥"),
    SJIS("画像の表示方向・内容を／設定します。￥"),
    SJIS("モニターのタイプを／変更します。￥"),
    SJIS("横画面での背景の壁紙を／設定します。￥"),
    SJIS("横画面でのマップ表示の／ON/OFFを設定します。￥"),
    SJIS("BGMを変更します。￥"),
    SJIS("画面表示位置を調整します。／○ボタンを押下すると／調整モードに移行します。￥"),
    SJIS("￥"),
    SJIS("ショットボタンを／設定します。￥"),
    SJIS("ボンバーボタンを／設定します。￥"),
    SJIS("連射ボタンを設定します。￥"),
    SJIS("設定を初期値に戻します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#else
char *g_menu_system_option_help[14] = {
    SJIS("￥"),
    SJIS("モニター設置方向を設定。￥"),
    SJIS("画像の表示方向・内容を／設定します。￥"),
    SJIS("モニターのタイプを／変更します。￥"),
    SJIS("横画面での背景の壁紙を／設定します。￥"),
    SJIS("横画面で、マップ表示の／ON/OFFを設定します。￥"),
    SJIS("BGMを変更します。￥"),
    SJIS("画面表示位置を調整します。／○ボタンを押下すると／調整モードに移行します。￥"),
    SJIS("￥"),
    SJIS("ショットボタンを／設定します。￥"),
    SJIS("ボンバーボタンを／設定します。￥"),
    SJIS("連射ボタンを設定します。￥"),
    SJIS("設定を初期値に戻します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#endif

#ifdef DEATH_LABEL
char *menu_help_draw_table[4] = {
    SJIS("￥"),
    SJIS("機体タイプを設定します。￥"),
    SJIS("強化タイプを設定します。￥"),
    SJIS("前のメニューに戻ります。￥"),
};
#endif

char *g_menu_ranking_help = SJIS("○インターネットランキング／　パスワードを表示。／×前のメニューに戻る。￥");

#ifndef DEATH_LABEL
char *g_menu_launch_ask[3] = {
    SJIS("￥"),
    SJIS("ギャラリーを起動しますか？￥"),
    SJIS("デスレーベルを／起動しますか？￥"),
};

char *g_menu_launch_warning[3] = {
    SJIS("￥"),
    SJIS("　　　　　注意　　　　　／ギャラリーを起動すると、／現在のゲームデータは／失われます。セーブを／行ってから起動して下さい。￥"),
    SJIS("　　　　　注意　　　　　／デスレーベルを起動すると、／現在のゲームデータは／失われます。セーブを／行ってから起動して下さい。￥"),
};
#endif

#ifdef DEATH_LABEL
char *menu_help_draw_table_2[2] = {
    SJIS("￥"),
    SJIS("怒首領蜂大往生を／起動しますか？￥"),
};

char *menu_help_draw_table_3[2] = {
    SJIS("￥"),
    SJIS("　　　　　注意　　　　　／怒首領蜂大往生を起動すると／現在のゲームデータは／失われます。セーブを／行ってから起動して下さい。￥"),
};
#endif

char *g_menu_password_title = SJIS("　　　　パスワード￥");

char *g_menu_pause_help_a[10] = {
    SJIS("￥"),
    SJIS("画像の表示方向・内容を／設定します。￥"),
    SJIS("振動のON/OFFを設定します。￥"),
    SJIS("横画面での背景の壁紙を／設定します。￥"),
    SJIS("横画面でのマップ表示の／ON/OFFを設定します。￥"),
    SJIS("画面表示位置を調整します。／○ボタンを押下すると／調整モードに移行します。￥"),
    SJIS("最初からやり直します。￥"),
    SJIS("ゲームを終了します。￥"),
    SJIS("デバック項目ROUND SELECT￥"),
    SJIS("デバック項目STAGE SELECT／○ボタンを押下すると選択／したステージに行けます。￥"),
};

#ifndef DEATH_LABEL
char *g_menu_pause_help_b[10] = {
    SJIS("￥"),
    SJIS("画像の表示方向・内容を／設定します。￥"),
    SJIS("振動のON/OFFを設定します。￥"),
    SJIS("横画面での背景の壁紙を／設定します。￥"),
    SJIS("横画面でのマップ表示の／ON/OFFを設定します。￥"),
    SJIS("画面表示位置を調整します。／○ボタンを押下すると／調整モードに移行します。￥"),
    SJIS("最初からやり直します。￥"),
    SJIS("このステージを終了します。￥"),
    SJIS("デバック項目ROUND SELECT￥"),
    SJIS("デバック項目STAGE SELECT／○ボタンを押下すると選択／したステージに行けます。￥"),
};
#endif

#ifdef DEATH_LABEL
char *g_menu_pause_help_c[17] = {
    SJIS("￥"),
    SJIS("画像の表示方向・内容を／設定します。￥"),
    SJIS("振動のON/OFFを設定します。￥"),
    SJIS("横画面での背景の壁紙を／設定します。￥"),
    SJIS("横画面でのマップ表示の／ON/OFFを設定します。￥"),
    SJIS("画面表示位置を調整します。／○ボタンを押下すると／調整モードに移行します。￥"),
    SJIS("最初からやり直します。￥"),
    SJIS("リプレイを終了します。￥"),
    SJIS("デバック項目ROUND SELECT￥"),
    SJIS("デバック項目STAGE SELECT／○ボタンを押下すると選択／したステージに行けます。￥"),
    NULL,
    NULL,
    SJIS("はい￥"),
    SJIS("いいえ￥"),
    SJIS("ゲームを終了しますか？￥"),
    SJIS("リプレイを終了しますか？￥"),
    SJIS("リトライしますか？￥"),
};
#else
char *g_menu_pause_help_c[18] = {
    SJIS("￥"),
    SJIS("画像の表示方向・内容を／設定します。￥"),
    SJIS("振動のON/OFFを設定します。￥"),
    SJIS("横画面での背景の壁紙を／設定します。￥"),
    SJIS("横画面でのマップ表示の／ON/OFFを設定します。￥"),
    SJIS("画面表示位置を調整します。／○ボタンを押下すると／調整モードに移行します。￥"),
    SJIS("最初からやり直します。￥"),
    SJIS("リプレイを終了します。￥"),
    SJIS("デバック項目ROUND SELECT￥"),
    SJIS("デバック項目STAGE SELECT／○ボタンを押下すると選択／したステージに行けます。￥"),
    NULL,
    NULL,
    SJIS("はい￥"),
    SJIS("いいえ￥"),
    SJIS("ゲームを終了しますか？￥"),
    SJIS("リプレイを終了しますか？￥"),
    SJIS("リトライしますか？￥"),
    SJIS("本当に終了しますか？￥"),
};
#endif

char g_menu_screen_adjust_help[128] = SJIS("方向キーの↑↓←→で／画面位置を調整します。／○ボタンで決定、×ボタンで／キャンセルできます。／SELECTで初期値に戻ります。￥");

Wallpaper g_menu_wallpapers[5] = {
    { 0x14b5, (void *)g_menu_wallpapers_1 },
    { 0x14b6, (void *)g_menu_wallpapers_3 },
    { 0x14b7, (void *)g_menu_wallpapers_5 },
    { 0x14b8, (void *)g_menu_wallpapers_7 },
    { 0x14b9, (void *)g_menu_wallpapers_9 },
};

#ifdef DEATH_LABEL
Point16 g_pause_menu_positions[4] = {
    { 0x160, 0x5c },
    { 0x140, 0xc },
    { 0x120, 0xc },
    { 0x100, 0xc },
};
#else
Point16 g_pause_menu_positions[12] = {
    { 0x160, 0x5c },
    { 0x140, 0xc },
    { 0x120, 0xc },
    { 0x100, 0xc },
    { 0xe0, 0xc },
    { 0xc0, 0xc },
    { 0xa0, 0xc },
    { 0x80, 0xc },
    { 0x60, 0xc },
    { 0x40, 0xc },
    { 0x20, 0xc },
    { 0, 0xc },
};
#endif

#ifdef DEATH_LABEL
u16 death_D_00263620[16] = {
    0xe0, 0xc, 0xc0, 0xc, 0xa0, 0xc, 0x80, 0xc,
    0x60, 0xc, 0x40, 0xc, 0x20, 0xc, 0, 0xc,
};
#endif

char *g_menu_confirm_cancel_text = SJIS("○×￥");

char *g_menu_cancel_text = SJIS("×￥");

s8 screen_setting_apply_table[4] = {
    3, 2, 5, 0,
};

s8 screen_setting_apply_table_2[2] = {
    5, 0,
};

char g_menu_arrow_text[2][2] = {
    "<",
    ">",
};

extern MenuPage g_menu_practice_ranking;
extern MenuPage g_menu_sim_rules;
extern MenuPage g_menu_sim_player;
extern MenuPage g_menu_sim_setting;
extern MenuPage g_menu_simulation;
extern MenuPage g_menu_file_select;
extern MenuPage g_menu_stage_select;
extern MenuPage g_menu_stage_difficulty;
extern MenuPage g_menu_sim_param;

void delta_encode(u8 *buf);
void menu_item_values_clear(void);
void menu_task_update(void);
void menu_page_dispatch(void);
void menu_exit_when_faded();
void sim_rules_set_defaults(void);
void menu_main_page(void);
void menu_main_step0(void);
void menu_main_step1(void);
void menu_main_step2(void);
void menu_main_step3(void);
void menu_main_step4(void);
void menu_game_option_page(void);
void menu_game_option_step0();
void menu_game_option_step1();
void menu_game_option_step2();
void screen_setting_apply(void);
void menu_game_option_adjust(void);
void menu_game_option_commit(void);
void menu_values_from_settings(void);
void menu_game_option_defaults(void);
void menu_save_load_page(void);
void menu_save_load_step0();
void menu_save_load_step1();
void menu_save_load_step2();
void menu_save_load_adjust(void);
void menu_debug_option_page(void);
void menu_debug_option_step0();
void menu_debug_option_step1();
void menu_debug_option_step2();
void menu_debug_option_adjust(void);
void menu_debug_option_commit(void);
void menu_arcade_page(void);
void menu_arcade_step0(void);
void menu_arcade_step1(void);
void menu_arcade_step2(void);
void menu_arcade_step3(void);
void menu_arcade_step4(void);
void menu_arcade_adjust(void);
void menu_system_option_page(void);
void menu_system_option_step0();
void menu_system_option_step1();
void menu_system_option_step2();
void menu_system_option_step3();
void menu_system_option_adjust(void);
void menu_system_option_commit(void);
void menu_system_option_defaults(void);
void menu_launch_page(void);
void menu_launch_step0();
void menu_launch_step1();
void menu_launch_step2();
void menu_launch_when_faded();
void menu_death_option_page(void);
void menu_death_option_step0(void);
void menu_death_option_step1(void);
void menu_death_option_step2(void);
void menu_death_option_adjust(void);
void menu_ranking_page(void);
void menu_ranking_step0();
void menu_ranking_step1();
void menu_ranking_step2();
void menu_draw(void);
void menu_main_draw(void);
void menu_game_option_draw(void);
void menu_save_load_draw(void);
void menu_debug_option_draw(void);
void menu_arcade_draw(void);
void menu_system_option_draw(void);
void menu_alpha_a_update(void);
void menu_death_option_draw(void);
void menu_alpha_b_update(void);
s32 menu_cursor_input(s32 page);
s32 menu_ranking_cursor_move();
void menu_box_draw(void);
void menu_box_draw_wide(void);
void menu_help_draw(void);
s32 menu_notice_update(void);
void menu_overlay_draw(void);
void menu_notice_draw(void);
void menu_reset();
void menu_items_clear(void);
void menu_items_place(s32 group);
void menu_items_slide_in(s32 group);
s32 menu_items_slide_update(s32 group);
void menu_button_assign_input(void);
void menu_message_draw(s32 x, s32 y);
void menu_text_queue(s32 x, s32 y, s32 attr);
void menu_text_queue_plain(s32 x, s32 y, s32 attr);
void pause_update(void);
void pause_begin(void);
void pause_menu_update(void);
void pause_end(void);
void pause_menu_confirm(void);
s32 pause_menu_cursor_move(void);
void pause_menu_box_draw(void);
void pause_menu_items_draw(void);
void pause_menu_item_draw(s32 x, s32 y);
void menu_help_item_draw(s32 x, s32 y);
void pause_menu_draw(void);
void pause_menu_quit_confirm(void);
void game_screen_teardown(void);
void menu_settings_restore(void);
void menu_arrows_draw(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags);
void pause_screen_adjust_update(void);
void menu_screen_adjust_page(void);
void screen_adjust_frame_draw(void *buffer);
void menu_screen_adjust_draw(void);
void disc_notice_begin(void);
void disc_notice_begin_for_stage(void);
void disc_notice_end(void);
void disc_notice_draw(void);
void menu_card_save_page(void);
void menu_card_load_page(void);
void result_menu_reset(void);
void result_menu_input(void);
void result_menu_wait_faded(void);
s8 result_menu_update(void);
void result_menu_box_draw(void);
void result_menu_items_draw(void);
void result_menu_draw(void);
s32 replay_slots_update(void);
void replay_slots_reset(void);
void replay_slots_open(s8 arg0, s8 arg1, s8 arg2);
void replay_slots_close(void);
void replay_slots_card_scan_begin(void);
void replay_slots_start(void);
void replay_slots_card_scan_wait(void);
void replay_slots_card_ready(void);
void replay_slots_card_select(void);
s32 replay_slots_card_save(void);
s32 replay_slots_card_load(void);
void replay_slots_closing(void);
void replay_slots_disc_scan(void);
void replay_slots_disc_ready(void);
void replay_slots_disc_select(void);
s32 replay_slots_disc_load(void);
void replay_slot_draw(s32 slot, s32 x, s32 y, s32 alpha, s32 selected, SaveInfo *info);
s32 replay_slots_draw(void);
void menu_reset_keep_sim_rules(void);
void menu_reset_keep_sim_rules_and_page(void);
void menu_close_begin(void);
static void menu_page_enter(MenuPage *fade);
s32 menu_simulation_slide_in_step(MenuPage *fade, s32 command);
static s32 menu_page_advance(MenuPage *fade, s32 command);
void menu_idle_cancel(void);
static void menu_page_fade(MenuPage *fade);
void menu_simulation_items_draw(MenuPage *arg0, u8 **arg1, s32 arg2);
void menu_simulation_step0(void);
void menu_simulation_step1(void);
void menu_simulation_step10(void);
void menu_simulation_step11(void);
void menu_simulation_step2(void);
void menu_simulation_page(void);
void menu_simulation_draw(void);
void menu_stage_select_step0(void);
void menu_stage_select_step1(void);
void menu_stage_select_step2(void);
void menu_stage_select_step3(void);
void menu_stage_select_page(void);
void menu_stage_select_draw(void);
void menu_file_select_step0(void);
void menu_file_select_step1(void);
void menu_replay_step2(void);
void menu_replay_page(void);
void menu_file_select_draw(void);
void menu_super_replay_step0(void);
void menu_super_replay_step2(void);
void menu_super_replay_page(void);
void menu_settings_load_page(void);
void menu_settings_load_step2(void);
void menu_settings_load_apply(void);
void menu_sim_setting_step0(void);
void menu_sim_setting_step1(void);
void menu_sim_setting_step2(void);
void menu_sim_setting_page(void);
void menu_sim_setting_draw(void);
void menu_sim_player_step0(void);
void menu_sim_player_step1(void);
void menu_sim_player_step2(void);
void menu_sim_player_page(void);
void menu_sim_player_draw(void);
void menu_sim_rules_step0(void);
void menu_sim_rules_step1(void);
void menu_sim_rules_step2(void);
void menu_sim_rules_page(void);
void menu_sim_rules_draw(void);
void menu_sim_rule_gauge_draw(s32 x, s32 y, s32 alpha, s32 mode, s32 kind);
void menu_sim_param_step0(void);
void menu_sim_param_step1(void);
void menu_sim_param_step2(void);
void menu_sim_param_page(void);
void menu_sim_param_draw(void);
void menu_practice_ranking_step0(void);
void menu_practice_ranking_step1(void);
void menu_practice_ranking_step2(void);
void menu_practice_ranking_page(void);
void menu_practice_ranking_draw(void);
void result_notice_update(void);
void result_notice_begin();
void result_notice_slide();
void result_notice_wait_button();
void result_notice_finish();
void menu_ranking_draw(void);
void menu_ranking_scores_format(s32 arg0, s32 arg1);
void menu_ranking_box_draw(void);
void replay_save_prompt_update(void);
void replay_loaded_file_adopt(void);
s32 replay_save_prompt_update_card(void);
s32 replay_save_prompt_update_disc(void);
void replay_scores_snapshot(void);
s32 replay_file_finalize(void);
void delta_decode(s32 arg0);
void replay_save_prompt_draw(void);
void replay_save_prompt_text_draw(void);
s32 replay_snapshot_checksum(const u8 *data);
s32 clock_read(u8 *out);
s32 replay_disc_headers_load(void);
s32 replay_disc_file_load(u8 arg0);
void simulation_task(void);
void simulation_task_begin();
void task_stop_self_entry();
void simulation_task_run();
void simulation_ships_start();

#ifndef DEATH_LABEL
void delta_encode(u8 *buf) {
    u8 prev;
    u8 cur;
    s32 i;

    prev = buf[0];
    for (i = 1; i < 0x5533; i++) {
        cur = buf[i];
        buf[i] = (s8)cur - (s8)prev;
        prev = cur;
    }
}
#endif


extern s32 D_00684CF0[10][4][5];

void menu_item_values_clear(void) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                D_00684CF0[i][j][k] = 0;
            }
        }
    }
}

extern s8 g_menu_task_phase;

void menu_task_update(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    switch (g_menu_task_phase) {                           /* irregular */
    case 0:
        menu_reset(2, g_menu_task_phase);
        /* fallthrough */
    case 1:
        menu_page_dispatch();
        break;
    case 2:
        menu_exit_when_faded(2, g_menu_task_phase);
        break;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

extern s8 g_menu_page;

#ifdef DEATH_LABEL
#endif

void menu_page_dispatch(void) {
    switch (g_menu_page) {
    case MENU_PAGE_MAIN:
        menu_main_page();
        break;
    case MENU_PAGE_GAME_OPTION:
        menu_game_option_page();
        break;
    case MENU_PAGE_SAVE_LOAD:
        menu_save_load_page();
        break;
    case MENU_PAGE_DEBUG_OPTION:
        menu_debug_option_page();
        break;
    case MENU_PAGE_CARD_SAVE:
        menu_card_save_page();
        break;
    case MENU_PAGE_CARD_LOAD:
        menu_card_load_page();
        break;
    case MENU_PAGE_SIMULATION:
        menu_simulation_page();
        break;
    case MENU_PAGE_STAGE_SELECT:
        menu_stage_select_page();
        break;
    case MENU_PAGE_REPLAY:
        menu_replay_page();
        break;
    case MENU_PAGE_SIM_SETTING:
        menu_sim_setting_page();
        break;
    case MENU_PAGE_PRACTICE_RANKING:
        menu_practice_ranking_page();
        break;
    case MENU_PAGE_ARCADE:
        menu_arcade_page();
        break;
    case MENU_PAGE_SYSTEM_OPTION:
        menu_system_option_page();
        break;
    case MENU_PAGE_SCREEN_ADJUST:
        menu_screen_adjust_page();
        break;
    case MENU_PAGE_LAUNCH:
        menu_launch_page();
        break;
#ifdef DEATH_LABEL
    case MENU_PAGE_23:
        menu_death_option_page();
        break;
#endif
    case MENU_PAGE_RANKING:
        menu_ranking_page();
        break;
    case MENU_PAGE_SIM_PLAYER:
        menu_sim_player_page();
        break;
    case MENU_PAGE_SIM_RULES:
        menu_sim_rules_page();
        break;
    case MENU_PAGE_SIM_PARAM:
        menu_sim_param_page();
        break;
    case MENU_PAGE_SETTINGS_LOAD:
        menu_settings_load_page();
        break;
    case MENU_PAGE_SUPER_REPLAY:
        menu_super_replay_page();
        break;
    }
}

extern s8 g_fade_state;
extern s8 g_menu_exit_code;

void menu_exit_when_faded() {
    if (g_fade_state == 0) {
        g_menu_task_phase = 0;
        if (g_menu_exit_code == 2) {
            g_menu_exit_code = 0x14;
        } else if (g_menu_exit_code == 3) {
            g_menu_exit_code = 0x1E;
        } else if (g_menu_exit_code == 4) {
            g_menu_exit_code = 0x28;
        } else {
            g_menu_exit_code = 0xA;
        }
    }
}

extern s32 D_0068DE90[];
extern s32 D_0068DEA0[];
extern s32 D_0068DEB0[];
extern u8 D_0068DEC8[];
extern u8 D_0068DED8[];
extern u8 D_0068DEF0[];

void sim_rules_set_defaults(void) {
    memcpy(((s32 *)D_0068DEF0), D_00270810, 0x16);
    memcpy(((s32 *)D_0068DED8), D_00270828, 0xA);
    memcpy(((s32 *)D_0068DEC8), D_00270838, 0xC);
    memcpy(D_0068DEB0, D_00270810, 0x16);
    memcpy(D_0068DE90, D_00270828, 0xA);
    memcpy(D_0068DEA0, D_00270838, 0xC);
}

extern s8 g_menu_main_step;

void menu_main_page(void) {
    switch (g_menu_main_step) {
    case 0:
        menu_main_step0();
        break;
    case 1:
        menu_main_step1();
        break;
    case 2:
        menu_main_step2();
        break;
    case 3:
        menu_main_step3();
        break;
    case 4:
        menu_main_step4();
        break;
    }
}

extern s16 g_menu_idle_timer;
extern u8 g_replay_file_finalized;
extern s8 g_menu_main_fade_state;
extern s8 g_menu_main_unread_flag;
extern s32 g_menu_main_alpha;

void menu_main_step0(void) {
    g_replay_file_finalized = 0;
    g_menu_main_alpha = 0;
    g_menu_main_unread_flag = 0;
    g_menu_main_step += 1;
    menu_items_slide_in(0);
    g_menu_main_fade_state = 1;
    g_menu_idle_timer = 0xE10;
}

extern s8 g_menu_fade_state;
extern s8 g_menu_main_cursor;
extern s8 g_menu_box_fade_state;
extern s8 g_menu_cursor;

void menu_main_step1(void) {
    if (menu_items_slide_update(0) != 0) {
        g_menu_box_fade_state = 1;
        g_menu_fade_state = 1;
        g_menu_main_step += 1;
        g_menu_cursor = g_menu_main_cursor;
    }
}

extern s8 g_menu_launch_kind;
extern s8 g_menu_ranking_cursor;
extern s8 g_menu_launch_cursor;
extern s8 g_menu_system_option_cursor;
extern s8 g_menu_arcade_cursor;
extern s8 g_menu_debug_option_cursor;
extern s8 g_menu_save_load_cursor;
extern s8 g_menu_box_alpha;
extern s8 g_menu_ranking_step;
extern s8 g_menu_launch_step;
extern s8 g_menu_system_option_step;
extern s8 g_menu_arcade_step;
extern s8 g_menu_debug_option_step;
extern s8 g_menu_save_load_step;
extern s8 g_menu_pad;
#ifdef DEATH_LABEL
extern u8 g_game_mode;
extern u8 g_no_enemy_bullets;
extern u8 g_setting_start_round;
extern s32 g_ranking_entry_index;
extern s8 g_menu_exit_code;
s32 start_buttons_take_credits();
#endif

void menu_main_step2(void) {
    s32 sfx_menu_confirm();
    s32 fade_start_out();
    s32 var_a1;

    menu_cursor_input(0);
    var_a1 = 0;
    g_menu_idle_timer = 0xE10;
    if (g_pad_held[2] == 0) {
        (*(u16 *)&g_menu_idle_timer) -= 1;
        if ((s32) (u16)g_menu_idle_timer <= 0) {
            var_a1 = 1;
            g_menu_cursor = MAIN_OR_DEATH_LABEL(8, 5);
        }
    } else {
        g_menu_idle_timer = 0xE10;
    }
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        g_menu_cursor = MAIN_OR_DEATH_LABEL(8, 5);
    } else if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    g_menu_main_cursor = g_menu_cursor;
    if (var_a1 != 0) {
        g_menu_main_fade_state = 2;
        g_menu_box_fade_state = 2;
        sfx_menu_confirm();
        g_menu_box_alpha = 0;
        g_menu_box_fade_state = 0;
#ifdef DEATH_LABEL
        switch (g_menu_cursor) {
        case 0:
            break;
        case 1:
            g_no_enemy_bullets = 0;
            g_game_mode = 2;
            g_setting_start_round = 1;
            g_ranking_entry_index = 0xFF;
            start_buttons_take_credits();
            fade_start_out();
            g_menu_task_phase = 2;
            g_menu_exit_code = 4;
            break;
        case 2:
            g_menu_ranking_step = 0;
            g_menu_page = MENU_PAGE_RANKING;
            g_menu_ranking_cursor = 0;
            break;
        case 3:
            g_menu_system_option_step = 0;
            g_menu_page = MENU_PAGE_SYSTEM_OPTION;
            g_menu_system_option_cursor = 0;
            break;
        case 4:
            g_menu_save_load_step = 0;
            g_menu_page = MENU_PAGE_SAVE_LOAD;
            g_menu_save_load_cursor = 0;
            break;
        case 6:
            g_menu_debug_option_step = 0;
            g_menu_page = MENU_PAGE_DEBUG_OPTION;
            g_menu_debug_option_cursor = 0;
            break;
        case 5:
            g_menu_launch_step = 0;
            g_menu_page = MENU_PAGE_LAUNCH;
            g_menu_launch_cursor = 0;
            g_menu_launch_kind = 1;
            break;
        }
#else
        switch (g_menu_cursor) {
        case 0:
            break;
        case 1:
            g_menu_arcade_step = 0;
            g_menu_page = MENU_PAGE_ARCADE;
            g_menu_arcade_cursor = 0;
            break;
        case 3:
            g_menu_launch_step = 0;
            g_menu_page = MENU_PAGE_LAUNCH;
            g_menu_launch_cursor = 0;
            g_menu_launch_kind = 2;
            break;
        case 4:
            g_menu_launch_step = 0;
            g_menu_page = MENU_PAGE_LAUNCH;
            g_menu_launch_cursor = 0;
            g_menu_launch_kind = 1;
            break;
        case 5:
            g_menu_ranking_step = 0;
            g_menu_page = MENU_PAGE_RANKING;
            g_menu_ranking_cursor = 0;
            break;
        case 6:
            g_menu_system_option_step = 0;
            g_menu_page = MENU_PAGE_SYSTEM_OPTION;
            g_menu_system_option_cursor = 0;
            break;
        case 7:
            g_menu_save_load_step = 0;
            g_menu_page = MENU_PAGE_SAVE_LOAD;
            g_menu_save_load_cursor = 0;
            break;
        case 2:
            g_menu_page = MENU_PAGE_SIMULATION;
            g_menu_simulation.step = 0xA;
            g_menu_simulation.cursor = 0;
            if (g_pad_trigger[0] & 0x20) {
                g_menu_pad = 0;
            } else {
                g_menu_pad = 1;
            }
            break;
        case 9:
            g_menu_debug_option_step = 0;
            g_menu_page = MENU_PAGE_DEBUG_OPTION;
            g_menu_debug_option_cursor = 0;
            break;
        case 8:
            fade_start_out();
            g_menu_task_phase = 2;
            break;
        }
#endif
    }
}

void menu_main_step3(void) {
    if (g_menu_main_fade_state == 0) {
        g_replay_file_finalized = 0;
        g_menu_main_step = 4;
    }
}

#pragma push
#pragma opt_propagation off
extern s32 autosave_update(void);

void menu_main_step4(void) {
    if (autosave_update() != 0) {
        s8 val = g_menu_main_cursor;
        g_menu_main_step = 2;
        g_menu_box_fade_state = 1;
        g_menu_idle_timer = 0xE10;
        g_menu_cursor = val;
    }
}
#pragma pop

extern s8 g_menu_game_option_step;

void menu_game_option_page(void) {
    switch (g_menu_game_option_step) {                           /* irregular */
    case 0:
        menu_game_option_step0(g_menu_game_option_step);
        break;
    case 1:
        menu_game_option_step1(g_menu_game_option_step);
        break;
    case 2:
        menu_game_option_step2(g_menu_game_option_step);
        /* fallthrough */
    case 3:
        break;
    }
}

extern s8 g_menu_game_option_cursor;
extern s8 g_menu_game_option_fade_state;
extern s32 g_menu_alpha;
extern s32 g_menu_game_option_alpha;

void menu_game_option_step0() {
    g_menu_game_option_alpha = 0;
    g_menu_game_option_step += 1;
    menu_items_slide_in(1);
    g_menu_alpha = 0x40;
    g_menu_game_option_cursor = 0;
    g_menu_game_option_fade_state = 1;
    g_menu_fade_state = 1;
    g_menu_idle_timer = 0xE10;
}

#pragma push
#pragma opt_propagation off

void menu_game_option_step1()
{
    if (menu_items_slide_update(1) != 0) {
        s32 previousCount = g_menu_game_option_step;

        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        g_menu_box_fade_state = 1;
        g_menu_fade_state = 1;
        g_menu_game_option_step = previousCount + 1;
        return;
    }
}
#pragma pop

extern s8 g_menu_arcade_fade_state;
void menu_game_option_step2() {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (menu_cursor_input(1) == 0) {
        menu_game_option_adjust();
    }
    menu_game_option_commit();
    var_a1 = 0;
    g_menu_idle_timer = 0xE10;
    if (g_pad_held[2] == 0) {
        (*(u16 *)&g_menu_idle_timer) -= 1;
        if ((s32) (u16)g_menu_idle_timer <= 0) {
            var_a1 = 1;
            g_menu_cursor = 6;
        }
    } else {
        g_menu_idle_timer = 0xE10;
    }
    if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    g_menu_game_option_cursor = g_menu_cursor;
    if ((g_menu_game_option_cursor >= 7) && (g_menu_game_option_cursor < 0xB)) {
        if (g_pad_trigger[2] != 0) {
            var_a1 = 1;
        }
    } else if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        g_menu_cursor = 6;
    }
    if (var_a1 != 0) {
        switch (g_menu_cursor) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            break;
        case 5:
            sfx_menu_confirm();
            menu_game_option_defaults();
            menu_game_option_commit();
            break;
        case 6:
            sfx_menu_confirm();
            menu_items_place(0xE);
            g_menu_arcade_step = 3;
            g_menu_page = MENU_PAGE_ARCADE;
            g_menu_alpha = 0x40;
            g_menu_arcade_fade_state = 1;
            g_menu_box_fade_state = 2;
            g_menu_game_option_fade_state = 2;
            g_menu_fade_state = 1;
            g_menu_game_option_step += 1;
            break;
        }
    }
}

extern s32 g_screen_mode;
extern u8 g_pad_tate_rotate;
extern u8 g_setting_screen_variant;
extern u8 g_setting_screen_mode;
extern s8 g_menu_value_screen_mode[];

void screen_setting_apply(void) {
    s32 value;

    g_setting_screen_mode = g_menu_value_screen_mode[0];
    if (g_setting_screen_mode == 0) {
        if (g_setting_screen_variant > 3) {
            g_setting_screen_variant = 0;
        }
        value = screen_setting_apply_table[g_setting_screen_variant];
    } else {
        if (g_setting_screen_variant > 1) {
            g_setting_screen_variant = 0;
        }
        value = screen_setting_apply_table_2[g_setting_screen_variant];
    }
    g_screen_mode = value;
    if (g_setting_screen_mode == 0 && g_setting_screen_variant >= 2) {
        g_pad_tate_rotate = 1;
    } else {
        g_pad_tate_rotate = 0;
    }
}

extern u16 g_pad_vib_power_p2;
extern u16 g_pad_vib_power_p1;
extern u16 g_pad_vib_timer_p2;
extern u16 g_pad_vib_timer_p1;
extern u8 g_pad_vib_state_p2;
extern u8 g_pad_vib_state_p1;
extern s8 menu_game_option_adjust_buffer[];

void menu_game_option_adjust(void) {
    extern void sfx_menu_tick(void);
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = g_menu_cursor;
    if (sel < 5) {
        max = menu_game_option_adjust_table[sel];
        cur = menu_game_option_adjust_buffer[sel];
        pad = g_pad_repeat[2];
        if (pad & 0x2000) {
            sfx_menu_tick();
            cur++;
            if (cur >= max) {
                cur = 0;
            }
            menu_game_option_adjust_buffer[g_menu_cursor] = cur;
            if (g_menu_cursor == 4 && cur == 1) {
                if (g_pad_repeat[0] != 0) {
                    g_pad_vib_state_p1 = 1;
                    g_pad_vib_power_p1 = 0x78;
                    g_pad_vib_timer_p1 = 0x14;
                } else {
                    g_pad_vib_state_p2 = 1;
                    g_pad_vib_power_p2 = 0x78;
                    g_pad_vib_timer_p2 = 0x14;
                }
            }
        } else if (pad & 0x8000) {
            sfx_menu_tick();
            cur--;
            if (cur < 0) {
                cur = max - 1;
            }
            menu_game_option_adjust_buffer[g_menu_cursor] = cur;
            if (g_menu_cursor == 4 && cur == 1) {
                if (g_pad_repeat[0] != 0) {
                    g_pad_vib_state_p1 = 1;
                    g_pad_vib_power_p1 = 0x78;
                    g_pad_vib_timer_p1 = 0x14;
                } else {
                    g_pad_vib_state_p2 = 1;
                    g_pad_vib_power_p2 = 0x78;
                    g_pad_vib_timer_p2 = 0x14;
                }
            }
        }
    }
}

extern u8 g_pad_vib_enabled;
extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u8 g_setting_difficulty;
extern s8 g_menu_value_difficulty[];
extern s8 g_menu_value_ship_stock[];
extern s8 g_menu_value_extend[];
extern s8 g_menu_value_vibration[];

void menu_game_option_commit(void) {
    g_setting_difficulty = g_menu_value_difficulty[0];
    g_setting_ship_stock = g_menu_value_ship_stock[0];
    g_setting_extend = g_menu_value_extend[0];
    g_pad_vib_enabled = g_menu_value_vibration[0];
}

extern u8 g_p1_btn_map_a;
extern u8 g_p1_btn_map_b;
extern u8 g_p1_btn_map_c;
extern u8 g_p1_btn_map_d;
extern u8 g_p2_btn_map_a;
extern u8 g_p2_btn_map_b;
extern u8 g_p2_btn_map_c;
extern u8 g_p2_btn_map_d;
extern u8 g_setting_autosave;
extern u8 g_pad_vib_enabled;
extern u8 g_stage_map_enabled;
extern u8 g_setting_replay_save;
extern u8 g_screen_wide;
extern u8 g_bgm_alternate_set;
extern u8 g_no_enemy_bullets;
extern u8 g_setting_loop_count;
extern u8 g_setting_start_round;
extern u8 g_setting_hitbox_bullets_shown;
extern u8 g_setting_hitbox_display;
extern u16 g_setting_wallpaper;
extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u8 g_setting_difficulty;
extern u8 g_menu_value_autosave[];
extern s8 g_menu_value_start_round[];
extern u8 g_menu_value_hitbox_display[];
extern u8 g_menu_value_hitbox_bullets[];
extern s8 g_menu_value_loop_count[];
extern u8 g_menu_value_debug_5[];
extern u8 g_menu_value_replay_save[];
extern s8 g_menu_value_screen_variant[];
extern u8 g_menu_value_screen_wide[];
extern u8 g_menu_value_wallpaper[];
extern u8 g_menu_value_stage_map[];
extern u8 g_menu_value_bgm_set[];
extern s8 g_menu_value_p1_btn_a[];
extern s8 g_menu_value_p1_btn_b[];
extern s8 g_menu_value_p1_btn_c[];
extern u8 g_menu_value_p1_btn_d[];
extern s8 g_menu_value_p2_btn_a[];
extern s8 g_menu_value_p2_btn_b[];
extern s8 g_menu_value_p2_btn_c[];
extern u8 g_menu_value_p2_btn_d[];

#ifdef DEATH_LABEL
extern u8 g_twin_boss_bullets_halved;
extern u8 g_twin_boss_bullet_speed_limit;
extern u8 death_D_00628DC6[];
#endif

void menu_values_from_settings(void) {
    ((u8 *)g_menu_value_difficulty)[0] = g_setting_difficulty;
    ((u8 *)g_menu_value_ship_stock)[0] = g_setting_ship_stock;
    ((u8 *)g_menu_value_extend)[0] = g_setting_extend;
    ((u8 *)g_menu_value_vibration)[0] = g_pad_vib_enabled;
    g_menu_value_autosave[0] = g_setting_autosave;
    g_menu_value_replay_save[0] = g_setting_replay_save;
    ((u8 *)g_menu_value_start_round)[0] = g_setting_start_round;
    g_menu_value_hitbox_display[0] = g_setting_hitbox_display;
    g_menu_value_hitbox_bullets[0] = g_setting_hitbox_bullets_shown;
    ((u8 *)g_menu_value_loop_count)[0] = g_setting_loop_count;
#ifdef DEATH_LABEL
    g_menu_value_debug_5[0] = g_twin_boss_bullet_speed_limit;
    death_D_00628DC6[0] = g_twin_boss_bullets_halved;
#else
    g_menu_value_debug_5[0] = g_no_enemy_bullets;
#endif
    ((u8 *)g_menu_value_screen_mode)[0] = g_setting_screen_mode;
    ((u8 *)g_menu_value_screen_variant)[0] = g_setting_screen_variant;
    g_menu_value_screen_wide[0] = g_screen_wide;
    g_menu_value_wallpaper[0] = (*(u8 *)&g_setting_wallpaper);
    g_menu_value_stage_map[0] = g_stage_map_enabled;
    g_menu_value_bgm_set[0] = g_bgm_alternate_set;
    ((u8 *)g_menu_value_p1_btn_a)[0] = (u8)g_p1_btn_map_a;
    ((u8 *)g_menu_value_p1_btn_b)[0] = g_p1_btn_map_b;
    ((u8 *)g_menu_value_p1_btn_c)[0] = g_p1_btn_map_c;
    g_menu_value_p1_btn_d[0] = g_p1_btn_map_d;
    ((u8 *)g_menu_value_p2_btn_a)[0] = g_p2_btn_map_a;
    ((u8 *)g_menu_value_p2_btn_b)[0] = g_p2_btn_map_b;
    ((u8 *)g_menu_value_p2_btn_c)[0] = g_p2_btn_map_c;
    g_menu_value_p2_btn_d[0] = g_p2_btn_map_d;
}

void menu_game_option_defaults(void) {
    g_menu_value_ship_stock[0] = 0;
    g_menu_value_extend[0] = 0;
    g_menu_value_difficulty[0] = 1;
    g_menu_value_vibration[0] = 0;
}


void menu_save_load_page(void) {
    switch (g_menu_save_load_step) {                           /* irregular */
    case 0:
        menu_save_load_step0(g_menu_save_load_step);
        break;
    case 1:
        menu_save_load_step1(g_menu_save_load_step);
        break;
    case 2:
        menu_save_load_step2(g_menu_save_load_step);
        /* fallthrough */
    case 3:
        break;
    }
}

extern s8 g_menu_save_load_fade_state;
extern s32 g_menu_save_load_alpha;

void menu_save_load_step0() {
    g_menu_save_load_alpha = 0;
    g_menu_save_load_step += 1;
    menu_items_slide_in(2);
    g_menu_alpha = 0x40;
    g_menu_save_load_cursor = 0;
    g_menu_save_load_fade_state = 1;
    g_menu_fade_state = 1;
    g_menu_idle_timer = 0xE10;
}

#pragma push
#pragma opt_propagation off
void menu_save_load_step1()
{
    if (menu_items_slide_update(2) != 0) {
        s32 count = g_menu_save_load_step;

        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        g_menu_box_fade_state = 1;
        g_menu_fade_state = 1;
        g_menu_save_load_step = count + 1;
    }
}
#pragma pop

s32 streams_stop();
s32 sfx_play_on_channel();
s32 music_play();
extern s32 g_se_priority;
extern s32 g_se_volume;
extern s32 g_se_last_result;
extern s32 g_menu_card_load_step;
extern s32 g_menu_card_save_step;
extern s8 D_0068DC35[];
extern s8 D_0068DC36[];
void menu_save_load_step2() {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (menu_cursor_input(2) == 0) {
        menu_save_load_adjust();
    }
    var_a1 = 0;
    g_menu_idle_timer = 0xE10;
    if (g_pad_held[2] == 0) {
        (*(u16 *)&g_menu_idle_timer) -= 1;
        if ((s32) (u16)g_menu_idle_timer <= 0) {
            var_a1 = 1;
            g_menu_cursor = 4;
        }
    } else {
        g_menu_idle_timer = 0xE10;
    }
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        g_menu_cursor = 4;
    } else if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    g_menu_save_load_cursor = g_menu_cursor;
    if (var_a1 != 0) {
        switch (g_menu_cursor) {
        case 0:
        case 3:
            break;
        case 1:
            sfx_menu_confirm();
            g_menu_card_load_step = 0;
            g_menu_page = 6;
            break;
        case 2:
            sfx_menu_confirm();
            g_menu_card_save_step = 0;
            g_menu_page = 5;
            break;
        case 4:
            streams_stop();
            menu_items_place(0);
            g_menu_main_step = 3;
            g_menu_main_fade_state = 1;
            g_menu_alpha = 0x40;
            g_menu_fade_state = 1;
            g_menu_box_fade_state = 2;
            g_menu_save_load_fade_state = 2;
            g_menu_page = 0;
            g_menu_save_load_step += 1;
            sfx_menu_confirm();
            break;
        case 5:
            g_se_volume = 0xFF;
            g_se_priority = 0xA;
            g_se_last_result = D_0068DC35[0] + 1;
            sfx_play_on_channel(g_se_last_result);
            break;
        case 6:
            g_se_last_result = (s32) D_0068DC36[0];
            music_play(g_se_last_result, 1);
            break;
        }
    }
}

extern s8 menu_save_load_adjust_buffer[];

void menu_save_load_adjust(void) {
    void sfx_menu_tick(void);
    s32 value;

    if (g_menu_cursor == 3) {
        value = menu_save_load_adjust_buffer[g_menu_cursor];
        if (g_pad_repeat[2] & 0x2000) {
            sfx_menu_tick();
            value++;
            if (value >= 2) {
                value = 0;
            }
            menu_save_load_adjust_buffer[g_menu_cursor] = value;
            g_setting_autosave = value;
        } else if (g_pad_repeat[2] & 0x8000) {
            sfx_menu_tick();
            value--;
            if (value < 0) {
                value = 1;
            }
            menu_save_load_adjust_buffer[g_menu_cursor] = value;
            g_setting_autosave = value;
        }
    }
}


void menu_debug_option_page(void) {
    switch (g_menu_debug_option_step) {                           /* irregular */
    case 0:
        menu_debug_option_step0(g_menu_debug_option_step);
        break;
    case 1:
        menu_debug_option_step1(g_menu_debug_option_step);
        break;
    case 2:
        menu_debug_option_step2(g_menu_debug_option_step);
        /* fallthrough */
    case 3:
        break;
    }
}

extern s8 g_menu_debug_option_fade_state;
extern s32 g_menu_debug_option_alpha;

void menu_debug_option_step0() {
    g_menu_debug_option_alpha = 0;
    g_menu_debug_option_step += 1;
    menu_items_slide_in(3);
    g_menu_alpha = 0x40;
    g_menu_debug_option_cursor = 0;
    g_menu_debug_option_fade_state = 1;
    g_menu_fade_state = 1;
    g_menu_idle_timer = 0xE10;
}

#pragma push
#pragma opt_propagation off
void menu_debug_option_step1()
{
    if (menu_items_slide_update(3) != 0) {
        s32 previousCount = g_menu_debug_option_step;

        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        g_menu_box_fade_state = 1;
        g_menu_fade_state = 1;
        g_menu_debug_option_step = previousCount + 1;
        return;
    }
}
#pragma pop

void menu_debug_option_step2() {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (menu_cursor_input(3) == 0) {
        menu_debug_option_adjust();
    }
    menu_debug_option_commit();
    var_a1 = 0;
    g_menu_idle_timer = 0xE10;
    if (g_pad_held[2] == 0) {
        (*(u16 *)&g_menu_idle_timer) -= 1;
        if ((s32) (u16)g_menu_idle_timer <= 0) {
            var_a1 = 1;
            g_menu_cursor = MAIN_OR_DEATH_LABEL(5, 7);
        }
    } else {
        g_menu_idle_timer = 0xE10;
    }
    if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    g_menu_debug_option_cursor = g_menu_cursor;
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        g_menu_cursor = MAIN_OR_DEATH_LABEL(5, 7);
    }
    if (var_a1 != 0) {
        switch (g_menu_cursor) {
        case 1:
        case 2:
        case 3:
        case 4:
#ifdef DEATH_LABEL
        case 5:
        case 6:
#endif
            break;
        case MAIN_OR_DEATH_LABEL(5, 7):
            sfx_menu_confirm();
            menu_items_place(0);
            g_menu_main_step = 3;
            g_menu_page = MENU_PAGE_MAIN;
            g_menu_alpha = 0x40;
            g_menu_main_fade_state = 1;
            g_menu_box_fade_state = 2;
            g_menu_debug_option_fade_state = 2;
            g_menu_fade_state = 1;
            g_menu_debug_option_step += 1;
            break;
        }
    }
}

extern u16 g_unlocked_options;
extern s8 menu_debug_option_adjust_buffer[];

void menu_debug_option_adjust(void) {
    extern void sfx_menu_tick(void);
    s32 count;
    s32 value;

    if (g_menu_cursor >= MAIN_OR_DEATH_LABEL(5, 7)) {
        return;
    }
    if (g_menu_cursor == 1 && !(g_unlocked_options & 1)) {
        return;
    }
    if (g_menu_cursor == 2 && !(g_unlocked_options & 2)) {
        return;
    }
    if (g_menu_cursor == 3 && !(g_unlocked_options & 4)) {
        return;
    }
    if (g_menu_cursor == 4 && !(g_unlocked_options & 8)) {
        return;
    }
    count = menu_debug_option_adjust_table[g_menu_cursor];
    value = menu_debug_option_adjust_buffer[g_menu_cursor];
    if (g_pad_repeat[2] & 0x2000) {
        sfx_menu_tick();
        value++;
        if (value >= count) {
            value = 0;
        }
        menu_debug_option_adjust_buffer[g_menu_cursor] = value;
    } else if (g_pad_repeat[2] & 0x8000) {
        sfx_menu_tick();
        value--;
        if (value < 0) {
            value = count - 1;
        }
        menu_debug_option_adjust_buffer[g_menu_cursor] = value;
    }
}

extern s8 g_menu_value_start_round[];
extern s8 g_menu_value_loop_count[];

#ifdef DEATH_LABEL
extern u8 g_twin_boss_bullets_halved;
extern u8 g_twin_boss_bullet_speed_limit;
extern u8 death_D_00628DC6[];
#endif

void menu_debug_option_commit(void) {
    g_setting_start_round = g_menu_value_start_round[0];
    g_setting_hitbox_display = ((s8 *)g_menu_value_hitbox_display)[0];
    g_setting_hitbox_bullets_shown = ((s8 *)g_menu_value_hitbox_bullets)[0];
    g_setting_loop_count = g_menu_value_loop_count[0];
#ifdef DEATH_LABEL
    g_twin_boss_bullet_speed_limit = ((s8 *)g_menu_value_debug_5)[0];
    g_twin_boss_bullets_halved = ((s8 *)death_D_00628DC6)[0];
#endif
}


void menu_arcade_page(void) {
    switch (g_menu_arcade_step) {
    case 0:
        menu_arcade_step0();
        break;
    case 1:
        menu_arcade_step1();
        break;
    case 2:
        menu_arcade_step2();
        break;
    case 3:
        menu_arcade_step3();
        break;
    case 4:
        menu_arcade_step4();
        break;
    case 5:
        break;
    }
}

extern s32 g_menu_arcade_alpha;

void menu_arcade_step0(void) {
    g_menu_arcade_alpha = 0;
    g_menu_arcade_step += 1;
    menu_items_slide_in(0xE);
    g_menu_alpha = 0x40;
    g_menu_arcade_cursor = 0;
    g_menu_arcade_fade_state = 1;
    g_menu_fade_state = 1;
    g_menu_idle_timer = 0xE10;
}

#pragma push
#pragma opt_propagation off
void menu_arcade_step1(void)
{
    if (menu_items_slide_update(0xE) != 0) {
        s32 previousCount = g_menu_arcade_step;

        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        g_menu_box_fade_state = 1;
        g_menu_fade_state = 1;
        g_menu_arcade_step = previousCount + 1;
        return;
    }
}
#pragma pop

extern u8 g_game_mode;
extern s32 g_ranking_entry_index;

void menu_arcade_step2(void) {
    extern void sfx_menu_confirm(void);
    extern void start_buttons_take_credits(void);
    extern void fade_start_out(void);
    s32 var_a1;

    if (menu_cursor_input(0xE) == 0) {
        menu_arcade_adjust();
    }
    var_a1 = 0;
    g_menu_idle_timer = 0xE10;
    if (g_pad_held[2] == 0) {
        (*(u16 *)&g_menu_idle_timer) -= 1;
        if ((s32) (u16)g_menu_idle_timer <= 0) {
            var_a1 = 1;
            g_menu_cursor = 5;
        }
    } else {
        g_menu_idle_timer = 0xE10;
    }
    if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    g_menu_arcade_cursor = g_menu_cursor;
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        g_menu_cursor = 5;
    }
    if (var_a1 != 0) {
        switch (g_menu_cursor) {
        case 1:
            g_menu_arcade_fade_state = 2;
#ifndef DEATH_LABEL
            g_ranking_entry_index = 0xFF;
#endif
            g_menu_box_fade_state = 2;
            g_game_mode = 0;
            g_no_enemy_bullets = 0;
            sfx_menu_confirm();
            start_buttons_take_credits();
            fade_start_out();
            g_menu_task_phase = 2;
            g_menu_exit_code = 2;
            break;
        case 2:
            g_game_mode = 1;
            g_no_enemy_bullets = 1;
#ifndef DEATH_LABEL
            g_ranking_entry_index = 0xFF;
#endif
            g_menu_arcade_fade_state = 2;
            g_menu_box_fade_state = 2;
            sfx_menu_confirm();
            start_buttons_take_credits();
            fade_start_out();
            g_menu_task_phase = 2;
            g_menu_exit_code = 2;
            break;
        case 3:
            g_menu_arcade_fade_state = 2;
            g_menu_box_fade_state = 2;
            sfx_menu_confirm();
            g_menu_game_option_step = 0;
            g_menu_page = MENU_PAGE_GAME_OPTION;
            g_menu_game_option_cursor = 0;
            break;
        case 4:
            break;
        case 5:
            sfx_menu_confirm();
            menu_items_place(0);
            g_menu_main_step = 3;
            g_menu_page = MENU_PAGE_MAIN;
            g_menu_alpha = 0x40;
            g_menu_main_fade_state = 1;
            g_menu_box_fade_state = 2;
            g_menu_arcade_fade_state = 2;
            g_menu_fade_state = 1;
            g_menu_arcade_step += 1;
            break;
        }
    }
}

void menu_arcade_step3(void) {
    if (g_menu_arcade_fade_state == 0) {
        g_menu_arcade_step = 4;
    }
}

#pragma push
#pragma opt_propagation off
void menu_arcade_step4(void) {
    if (autosave_update() != 0) {
        s8 val = g_menu_arcade_cursor;
        g_menu_arcade_step = 2;
        g_menu_box_fade_state = 1;
        g_menu_idle_timer = 0xE10;
        g_menu_cursor = val;
    }
}
#pragma pop

extern s8 menu_arcade_adjust_buffer[];

void menu_arcade_adjust(void) {
    void sfx_menu_tick(void);
    s32 value;

    if (g_menu_cursor == 4) {
        value = menu_arcade_adjust_buffer[g_menu_cursor];
        if (g_pad_repeat[2] & 0x2000) {
            sfx_menu_tick();
            value++;
            if (value >= 2) {
                value = 0;
            }
            menu_arcade_adjust_buffer[g_menu_cursor] = value;
            g_setting_replay_save = value;
        } else if (g_pad_repeat[2] & 0x8000) {
            sfx_menu_tick();
            value--;
            if (value < 0) {
                value = 1;
            }
            menu_arcade_adjust_buffer[g_menu_cursor] = value;
            g_setting_replay_save = value;
        }
    }
}


void menu_system_option_page(void) {
    switch (g_menu_system_option_step) {                           /* irregular */
    case 0:
        menu_system_option_step0(g_menu_system_option_step);
        break;
    case 1:
        menu_system_option_step1(g_menu_system_option_step);
        break;
    case 2:
        menu_system_option_step2(g_menu_system_option_step);
        break;
    case 3:
        menu_system_option_step3(g_menu_system_option_step);
        /* fallthrough */
    case 4:
        break;
    }
}

extern s8 g_menu_system_option_fade_state;
extern s32 g_menu_system_option_alpha;

void menu_system_option_step0() {
    g_menu_system_option_alpha = 0;
    g_menu_system_option_step += 1;
    menu_items_slide_in(0xF);
    g_menu_alpha = 0x40;
    g_menu_system_option_cursor = 0;
    g_menu_system_option_fade_state = 1;
    g_menu_fade_state = 1;
    g_menu_idle_timer = 0xE10;
}

#pragma push
#pragma opt_propagation off
void menu_system_option_step1()
{
    if (menu_items_slide_update(0xF) != 0) {
        s32 count = g_menu_system_option_step;

        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        g_menu_box_fade_state = 1;
        g_menu_fade_state = 1;
        g_menu_system_option_step = count + 1;
        return;
    }
}
#pragma pop

#pragma push
extern s8 g_display_offset_y;
extern s8 g_display_offset_x;
extern s8 g_menu_display_offset_y;
extern s8 g_menu_display_offset_x;
void menu_system_option_step2() {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (menu_cursor_input(0xF) == 0) {
        menu_system_option_adjust();
    }
    menu_system_option_commit();
    var_a1 = 0;
    g_menu_idle_timer = 0xE10;
    if (g_pad_held[2] == 0) {
        (*(u16 *)&g_menu_idle_timer) -= 1;
        if ((s32) (u16)g_menu_idle_timer <= 0) {
            var_a1 = 1;
            g_menu_cursor = 0xD;
        }
    } else {
        g_menu_idle_timer = 0xE10;
    }
    g_menu_system_option_cursor = g_menu_cursor;
    if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    if ((g_menu_system_option_cursor >= 9) && (g_menu_system_option_cursor < 0xC)) {
        if (g_pad_trigger[2] != 0) {
            var_a1 = 1;
        }
    } else if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        g_menu_cursor = 0xD;
    }
    if (var_a1 != 0) {
        switch (g_menu_cursor) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
            break;
        case 7:
            sfx_menu_confirm();
            g_menu_alpha = 0x80;
            g_menu_display_offset_x = g_display_offset_x;
            g_menu_page = MENU_PAGE_SCREEN_ADJUST;
            g_menu_display_offset_y = g_display_offset_y;
            break;
        case 9:
            menu_button_assign_input();
            break;
        case 10:
            menu_button_assign_input();
            break;
        case 11:
            menu_button_assign_input();
            break;
        case 12:
            sfx_menu_confirm();
            menu_system_option_defaults();
            menu_system_option_commit();
            break;
        case 13:
            sfx_menu_confirm();
            menu_items_place(0);
            g_menu_main_step = 3;
            g_menu_page = MENU_PAGE_MAIN;
            g_menu_alpha = 0x40;
            g_menu_main_fade_state = 1;
            g_menu_box_fade_state = 2;
            g_menu_system_option_fade_state = 2;
            g_menu_fade_state = 1;
            g_menu_system_option_step += 1;
            break;
        }
    }
}

#pragma opt_propagation off


void menu_system_option_step3()
{
    if (g_menu_system_option_fade_state == 0) {
        s8 savedState = g_menu_system_option_cursor;

        g_menu_system_option_step = 2;
        g_menu_box_fade_state = 1;
        g_menu_idle_timer = 0xE10;
        g_menu_cursor = savedState;
        return;
    }
}

extern s8 D_0068DD00[];

void menu_system_option_adjust(void) {
    extern void sfx_menu_tick(void);
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = g_menu_cursor;
    if (sel != 7 && !(sel > 7)) {
        max = menu_system_option_adjust_table[sel];
        if (sel == 2 && g_setting_screen_mode != 0) {
            max = menu_system_option_adjust_table_2[sel];
        }
        cur = D_0068DD00[sel];
        pad = g_pad_repeat[2];
        if (pad & 0x2000) {
            sfx_menu_tick();
            cur++;
            if (cur >= max) {
                cur = 0;
            }
            D_0068DD00[g_menu_cursor] = cur;
        } else if (pad & 0x8000) {
            sfx_menu_tick();
            cur--;
            if (cur < 0) {
                cur = max - 1;
            }
            D_0068DD00[g_menu_cursor] = cur;
        }
    }
}

extern u8 D_00271C64[];
extern u8 g_p1_btn_map_a;
extern u16 g_setting_wallpaper;
extern s8 g_display_reset_pending;
extern s8 g_menu_value_screen_variant[];
extern s8 g_menu_value_screen_wide_as_s8_a[];
extern s8 g_menu_value_p1_btn_a[];
extern s8 g_menu_value_p1_btn_b[];
extern s8 g_menu_value_p1_btn_c[];
extern s8 g_menu_value_p2_btn_a[];
extern s8 g_menu_value_p2_btn_b[];
extern s8 g_menu_value_p2_btn_c[];
void menu_system_option_commit(void) {
    extern void wallpaper_load(s32, s32);
    s32 temp_a0;

    if (g_setting_screen_mode != g_menu_value_screen_mode[0]) {
        g_setting_screen_variant = 0;
        g_display_reset_pending = 1;
        g_menu_value_screen_variant[0] = 0;
    }
    if (g_setting_screen_variant != g_menu_value_screen_variant[0]) {
        g_setting_screen_variant = (u8) g_menu_value_screen_variant[0];
        if (g_setting_screen_mode == 0) {
            g_setting_screen_variant &= 3;
        } else {
            g_setting_screen_variant &= 1;
        }
        g_menu_value_screen_variant[0] = g_setting_screen_variant;
        g_display_reset_pending = 1;
    }
    if (g_screen_wide != g_menu_value_screen_wide_as_s8_a[0]) {
        g_display_reset_pending = 1;
    }
    g_screen_wide = (u8) g_menu_value_screen_wide_as_s8_a[0];
    g_bgm_alternate_set = ((s8 *)g_menu_value_bgm_set)[0];
    g_stage_map_enabled = ((s8 *)g_menu_value_stage_map)[0];
    if (g_setting_wallpaper != ((s8 *)g_menu_value_wallpaper)[0]) {
        g_setting_wallpaper = (u16) (s8)(((s8 *)g_menu_value_wallpaper)[0]);
        if (g_setting_wallpaper != 5) {
            temp_a0 = (g_setting_wallpaper & 0xFFFF) * 8;
            wallpaper_load(*(s32 *)((u8 *)g_menu_wallpapers + temp_a0), *(s32 *)(D_00271C64 + temp_a0));
        }
    }
    g_p1_btn_map_a = g_menu_value_p1_btn_a[0];
    g_p1_btn_map_b = g_menu_value_p1_btn_b[0];
    g_p1_btn_map_c = g_menu_value_p1_btn_c[0];
    g_p1_btn_map_d = ((s8 *)g_menu_value_p1_btn_d)[0];
    g_p2_btn_map_a = g_menu_value_p2_btn_a[0];
    g_p2_btn_map_b = g_menu_value_p2_btn_b[0];
    g_p2_btn_map_c = g_menu_value_p2_btn_c[0];
    g_p2_btn_map_d = ((s8 *)g_menu_value_p2_btn_d)[0];
}

#ifdef DEATH_LABEL
extern u8 death_D_00628F01[];
extern u8 death_D_00628F02[];
#endif

void menu_system_option_defaults(void) {
    if (g_setting_screen_variant != 0) {
        g_display_reset_pending = 1;
    }
    g_menu_value_screen_mode[0] = 0;
    g_menu_value_screen_variant[0] = 0;
    g_setting_screen_variant = 0;
    g_menu_value_screen_wide_as_s8_a[0] = 0;
    ((s8 *)g_menu_value_wallpaper)[0] = 5;
    ((s8 *)g_menu_value_stage_map)[0] = 1;
    ((s8 *)g_menu_value_bgm_set)[0] = 0;
    g_menu_value_p1_btn_a[0] = 7;
    g_menu_value_p2_btn_a[0] = 7;
    g_menu_value_p1_btn_b[0] = 6;
    g_menu_value_p2_btn_b[0] = 6;
    g_menu_value_p1_btn_c[0] = 5;
    g_menu_value_p2_btn_c[0] = 5;
    ((s8 *)g_menu_value_p1_btn_d)[0] = 1;
    ((s8 *)g_menu_value_p2_btn_d)[0] = 1;
#ifdef DEATH_LABEL
    death_D_00628F01[0] = 0;
    death_D_00628F02[0] = 0;
#endif
}

s32 executable_launch();

void menu_launch_page(void) {
    switch (g_menu_launch_step) {                           /* irregular */
    case 0:
        menu_launch_step0(g_menu_launch_step);
        break;
    case 1:
        menu_launch_step1(g_menu_launch_step);
        break;
    case 2:
        menu_launch_step2(g_menu_launch_step);
        break;
    case 3:
#ifndef DEATH_LABEL
        menu_launch_when_faded(g_menu_launch_step);
#endif
        break;
    }
#ifdef DEATH_LABEL
    if (g_menu_launch_step >= 0x40) {
        g_menu_launch_step++;
        if (g_menu_launch_step >= 0x60) {
            executable_launch(2);
            printf("kidou\n");
        }
    }
#endif
}
#pragma pop

extern s8 g_menu_alpha_a_fade_state;
extern s32 g_menu_alpha_a;

void menu_launch_step0() {
    g_menu_alpha_a = 0;
    g_menu_launch_step += 1;
    menu_items_slide_in(0x15);
    g_menu_alpha = 0x40;
    g_menu_launch_cursor = 0;
    g_menu_alpha_a_fade_state = 1;
    g_menu_fade_state = 1;
    g_menu_idle_timer = 0xE10;
}

void menu_launch_step1() {
    if (menu_items_slide_update(0x15) != 0) {
        g_menu_cursor = 0;
        g_menu_box_fade_state = 1;
        g_menu_fade_state = 1;
        g_menu_alpha = 0x40;
        g_menu_launch_step++;
    }
}

extern s8 g_menu_launch_choice;
extern s8 g_pause_item_shrink;
void menu_launch_step2() {
    s32 sfx_menu_confirm();
    s32 sfx_menu_move();
    s32 fade_start_out();
    s32 selected;
    s32 choice;
    u32 buttons;

    buttons = g_pad_trigger[2];
    choice = g_menu_launch_kind;
    selected = 0;
    if ((buttons & 0x8000) && g_menu_launch_cursor == 0) {
        g_pause_item_shrink = 0;
        g_menu_launch_cursor = 1;
        sfx_menu_move();
    } else if ((buttons & 0x2000) && g_menu_launch_cursor == 1) {
        g_pause_item_shrink = 0;
        g_menu_launch_cursor = 0;
        sfx_menu_move();
    } else if (buttons & 0x20) {
        selected = 1;
        if (g_menu_launch_cursor == 0) {
            choice = 3;
        }
    }
    if (selected != 0) {
        switch (choice) {
#ifdef DEATH_LABEL
        case 1:
            streams_stop();
            sfx_menu_confirm();
            g_menu_launch_step = 0x40;
            fade_start_out();
            break;
#else
        case 1:
        case 2:
            g_menu_launch_choice = choice;
            fade_start_out();
            sfx_menu_confirm();
            g_menu_launch_step += 1;
            break;
#endif
        case 3:
            streams_stop();
            menu_items_place(0);
            g_menu_main_step = 3;
            g_menu_main_fade_state = 1;
            g_menu_alpha = 0x40;
            g_menu_fade_state = 1;
            g_menu_box_fade_state = 2;
            g_menu_alpha_a_fade_state = 2;
            g_menu_page = MENU_PAGE_MAIN;
            g_menu_launch_step += 1;
            sfx_menu_confirm();
            break;
        }
    }
}

#ifndef DEATH_LABEL
s32 executable_launch(s32);                     /* extern */

void menu_launch_when_faded() {
    if (g_fade_state == 0) {
        switch (g_menu_launch_choice) {                       /* irregular */
        case 1:
            executable_launch(0);
            return;
        case 2:
            executable_launch(1);
            break;
        }
    }
}
#endif

#ifdef DEATH_LABEL
extern s8 death_D_00290C4C;
extern s8 death_D_00290C74;
extern s8 death_D_00290CA8;
extern s32 death_D_00290CE4;
extern s8 menu_death_option_adjust_buffer[];

void menu_death_option_page(void) {
    switch (death_D_00290CA8) {
    case 0:
        menu_death_option_step0();
        break;
    case 1:
        menu_death_option_step1();
        break;
    case 2:
        menu_death_option_step2();
        break;
    case 3:
        break;
    }
}

void menu_death_option_step0(void) {
    death_D_00290CE4 = 0;
    death_D_00290CA8++;
    menu_items_slide_in(0x17);
    g_menu_alpha = 0x40;
    death_D_00290C4C = 0;
    death_D_00290C74 = 1;
    g_menu_fade_state = 1;
    g_menu_idle_timer = 0xE10;
}

void menu_death_option_step1(void) {
    if (menu_items_slide_update(0x17) != 0) {
        death_D_00290CA8++;
        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        g_menu_box_fade_state = 1;
        g_menu_fade_state = 1;
    }
}

void menu_death_option_step2(void) {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (menu_cursor_input(0x17) == 0) {
        menu_death_option_adjust();
    }
    var_a1 = 0;
    g_menu_idle_timer = 0xE10;
    if (g_pad_held[2] == 0) {
        (*(u16 *)&g_menu_idle_timer) -= 1;
        if ((s32) (u16)g_menu_idle_timer <= 0) {
            var_a1 = 1;
            g_menu_cursor = 3;
        }
    } else {
        g_menu_idle_timer = 0xE10;
    }
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        g_menu_cursor = 3;
    } else if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    death_D_00290C4C = g_menu_cursor;
    if (var_a1 != 0) {
        switch (g_menu_cursor) {
        case 1:
        case 2:
            break;
        case 3:
            streams_stop();
            menu_items_place(0);
            g_menu_main_step = 3;
            g_menu_main_fade_state = 1;
            g_menu_alpha = 0x40;
            g_menu_fade_state = 1;
            g_menu_box_fade_state = 2;
            death_D_00290C74 = 2;
            g_menu_page = MENU_PAGE_MAIN;
            death_D_00290CA8++;
            sfx_menu_confirm();
            break;
        }
    }
}

void menu_death_option_adjust(void) {
    void sfx_menu_tick(void);
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = g_menu_cursor;
    if (sel < 3) {
        max = menu_death_option_adjust_table[sel];
        cur = menu_death_option_adjust_buffer[sel];
        pad = g_pad_repeat[2];
        if (pad & 0x2000) {
            sfx_menu_tick();
            cur++;
            if (cur >= max) {
                cur = 0;
            }
            menu_death_option_adjust_buffer[g_menu_cursor] = cur;
        } else if (pad & 0x8000) {
            sfx_menu_tick();
            cur--;
            if (cur < 0) {
                cur = max - 1;
            }
            menu_death_option_adjust_buffer[g_menu_cursor] = cur;
        }
    }
}
#endif


void menu_ranking_page(void) {
    switch (g_menu_ranking_step) {                           /* irregular */
    case 0:
        menu_ranking_step0(g_menu_ranking_step);
        break;
    case 1:
        menu_ranking_step1(g_menu_ranking_step);
        break;
    case 2:
        menu_ranking_step2(g_menu_ranking_step);
        /* fallthrough */
    case 3:
        break;
    }
}

s32 ranking_screen_begin();                            /* extern */
extern s32 g_menu_notice_alpha;
extern s32 g_menu_ranking_state_a;
extern s32 g_menu_ranking_state_b;
extern s8 g_menu_alpha_b_fade_state;
extern s32 g_menu_alpha_b;

void menu_ranking_step0() {
    g_menu_alpha_b = 0;
    g_menu_ranking_step += 1;
    menu_items_slide_in(0x18);
    g_menu_alpha = 0x40;
    g_menu_alpha_b_fade_state = 1;
    g_menu_fade_state = 1;
    g_menu_idle_timer = 0xE10;
    g_menu_ranking_cursor = 0;
    g_menu_ranking_state_a = 0;
    g_menu_notice_alpha = 0;
    g_menu_ranking_state_b = 0;
    ranking_screen_begin();
}

void menu_ranking_step1() {
    if (menu_items_slide_update(0x18) != 0) {
        g_menu_cursor = 0;
        g_menu_box_fade_state = 1;
        g_menu_fade_state = 1;
        g_menu_alpha = 0x40;
        g_menu_ranking_step++;
    }
}

s32 settings_notice_graphics_load();
s32 ranking_screen_update();
extern u8 g_ranking_opened_from_menu;
void menu_ranking_step2() {
    s32 sfx_menu_confirm();
    s32 var_s0;

    if (g_menu_ranking_state_a == 0) {
        menu_ranking_cursor_move(0x18);
    }
    var_s0 = 0;
    g_ranking_opened_from_menu = 1;
    ranking_screen_update();
    g_menu_idle_timer = 0xE10;
    if (g_pad_held[2] == 0) {
        (*(u16 *)&g_menu_idle_timer) -= 1;
        if ((s32) (u16)g_menu_idle_timer <= 0) {
            var_s0 = 1;
            g_menu_cursor = 5;
        }
    } else {
        g_menu_idle_timer = 0xE10;
    }
    if (g_pad_trigger[2] & 0x40) {
        var_s0 = 1;
        g_menu_cursor = 5;
    } else if (g_pad_trigger[2] & 0x20) {
        var_s0 = 1;
    }
    g_menu_ranking_cursor = g_menu_cursor;
    if (var_s0 != 0) {
        switch (g_menu_cursor) {
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            sfx_menu_confirm();
            if (g_menu_ranking_state_b == 0) {
                g_menu_notice_alpha = 0;
                g_menu_ranking_state_a = 1;
                g_menu_ranking_state_b = 1;
                break;
            }
            g_menu_ranking_state_b = 0;
            g_menu_ranking_state_a = 2;
            break;
        case 5:
            streams_stop();
            menu_items_place(0);
            g_menu_main_step = 3;
            g_menu_main_fade_state = 1;
            g_menu_alpha = 0x40;
            g_menu_fade_state = 1;
            g_menu_box_fade_state = 2;
            g_menu_page = MENU_PAGE_MAIN;
            g_menu_alpha_b_fade_state = 0;
            g_menu_alpha_b = 0;
            g_menu_ranking_state_a = 0;
            g_menu_notice_alpha = 0;
            g_menu_ranking_state_b = 0;
            g_menu_ranking_step += 1;
            settings_notice_graphics_load();
            sfx_menu_confirm();
            break;
        }
    }
}

#ifdef DEATH_LABEL
#endif

void menu_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern void glyph_queue_clear(void);
    extern void glyph_queue_flush(void);
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    if (g_menu_exit_code != 0) {
        if (g_menu_page == MENU_PAGE_SCREEN_ADJUST) {
            menu_screen_adjust_draw();
            return;
        }
        save_d0 = reg_d0.w;
        save_d1 = reg_d1.w;
        save_d2 = reg_d2.w;
        save_d3 = reg_d3.w;
        save_d4 = reg_d4.w;
        save_d5 = reg_d5.w;
        save_d6 = reg_d6.w;
        save_d7 = reg_d7.w;
        save_a0 = reg_a0;
        save_a1 = reg_a1;
        save_a2 = reg_a2;
        save_a3 = reg_a3;
        save_a4 = reg_a4;
        save_a5 = reg_a5;
        save_a6 = reg_a6;
        if (g_menu_alpha_b == 0) {
            gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x60, 1, 1, 1);
            menu_box_draw_wide();
        } else {
            menu_box_draw();
        }
        glyph_queue_clear();
        menu_main_draw();
        menu_game_option_draw();
        menu_save_load_draw();
        menu_debug_option_draw();
        menu_arcade_draw();
        menu_system_option_draw();
        menu_alpha_a_update();
#ifdef DEATH_LABEL
        menu_death_option_draw();
#endif
        menu_alpha_b_update();
        menu_simulation_draw();
        menu_stage_select_draw();
        menu_sim_setting_draw();
        menu_sim_player_draw();
        menu_sim_rules_draw();
        menu_sim_param_draw();
        menu_practice_ranking_draw();
        menu_notice_draw();
        glyph_queue_flush();
        menu_file_select_draw();
        menu_help_draw();
        reg_d0.w = save_d0;
        reg_d1.w = save_d1;
        reg_d2.w = save_d2;
        reg_d3.w = save_d3;
        reg_d4.w = save_d4;
        reg_d5.w = save_d5;
        reg_d6.w = save_d6;
        reg_d7.w = save_d7;
        reg_a0 = save_a0;
        reg_a1 = save_a1;
        reg_a2 = save_a2;
        reg_a3 = save_a3;
        reg_a4 = save_a4;
        reg_a5 = save_a5;
        reg_a6 = save_a6;
    }
}

void menu_main_draw(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 wide);
    s32 i;
    s32 count;
    MenuItem *label;
    s32 x;
    s32 y;
    s32 z;

    count = g_menu_page_item_counts[0];
    switch (g_menu_main_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_main_alpha += 4;
        if (g_menu_main_alpha >= 0x80) {
            g_menu_main_fade_state = 0;
            g_menu_main_alpha = 0x80;
        }
        break;
    case 2:
        g_menu_main_alpha -= 4;
        if (g_menu_main_alpha <= 0) {
            g_menu_main_alpha = 0;
            g_menu_main_fade_state = 0;
        }
        break;
    }
    for (i = 0; i < count; i++) {
        label = &g_menu_items[0][i];
        if (label->active != 0) {
            label->alpha = g_menu_main_alpha;
            reg_a0 = (u8 *)g_menu_main_items[i];
            x = label->x;
            y = label->y;
            z = label->z;
            if (label->alpha != 0) {
                glyph_queue_add(x, y, z, 0, 0x80, label->alpha, 1);
            }
        }
    }
}

extern void text_queue_clear(void);
extern void text_flush(void);
extern s8 D_002714F1[];
extern s8 D_0068DC10[];

void menu_game_option_draw(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 count;
    s32 index;
    s32 top;
    MenuItem *item;
    u8 **pair;

    count = D_002714F1[0];
    switch (g_menu_game_option_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_game_option_alpha += 4;
        if (g_menu_game_option_alpha >= 0x80) {
            g_menu_game_option_fade_state = 0;
            g_menu_game_option_alpha = 0x80;
        }
        break;
    case 2:
        g_menu_game_option_alpha -= 4;
        if (g_menu_game_option_alpha <= 0) {
            g_menu_game_option_alpha = 0;
            g_menu_game_option_fade_state = 0;
        }
        break;
    }
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_GAME_OPTION * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_GAME_OPTION * MENU_ITEMS_PER_PAGE].alpha = g_menu_game_option_alpha;
        reg_a0 = (u8 *)g_menu_game_option_items[i];
        x = item[MENU_PAGE_GAME_OPTION * MENU_ITEMS_PER_PAGE].x;
        alpha = item[MENU_PAGE_GAME_OPTION * MENU_ITEMS_PER_PAGE].alpha;
        top = item[MENU_PAGE_GAME_OPTION * MENU_ITEMS_PER_PAGE].y;
        z = item[MENU_PAGE_GAME_OPTION * MENU_ITEMS_PER_PAGE].z;
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x10 + i];
        if (i == 1) {
            reg_a0 = (u8 *)g_menu_difficulty_names[index];
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
            if (g_menu_game_option_cursor == 1) {
                menu_arrows_draw(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2) {
            reg_a0 = (u8 *)g_menu_ship_stock_names[index];
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
            if (g_menu_game_option_cursor == 2) {
                menu_arrows_draw(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 3) {
            if (index == 3) {
                reg_a0 = (u8 *)g_menu_extend_names[index][0];
                glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
            } else {
                pair = (u8 **)g_menu_extend_names[index];
                reg_a0 = pair[0];
                glyph_queue_add(x, y, z, 0, 0x80, alpha, 0);
                reg_a0 = pair[1];
                glyph_queue_add(x - 8, y, z, 0, 0x80, alpha, 0);
            }
            if (g_menu_game_option_cursor == 3) {
                menu_arrows_draw(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 4) {
            reg_a0 = (u8 *)D_0028DD18[index];
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
            if (g_menu_game_option_cursor == 4) {
                menu_arrows_draw(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
    text_flush();
}

extern s8 D_002714F2[];

void menu_save_load_draw(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    MenuItem *item;

    count = D_002714F2[0];
    switch (g_menu_save_load_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_save_load_alpha += 4;
        if (g_menu_save_load_alpha >= 0x80) {
            g_menu_save_load_fade_state = 0;
            g_menu_save_load_alpha = 0x80;
        }
        break;
    case 2:
        g_menu_save_load_alpha -= 4;
        if (g_menu_save_load_alpha <= 0) {
            g_menu_save_load_alpha = 0;
            g_menu_save_load_fade_state = 0;
        }
        break;
    }
    for (i = 0; i < count; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_SAVE_LOAD * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_SAVE_LOAD * MENU_ITEMS_PER_PAGE].alpha = g_menu_save_load_alpha;
        reg_a0 = (u8 *)g_menu_save_load_items[i];
        x = item[MENU_PAGE_SAVE_LOAD * MENU_ITEMS_PER_PAGE].x;
        alpha = item[MENU_PAGE_SAVE_LOAD * MENU_ITEMS_PER_PAGE].alpha;
        top = item[MENU_PAGE_SAVE_LOAD * MENU_ITEMS_PER_PAGE].y;
        z = item[MENU_PAGE_SAVE_LOAD * MENU_ITEMS_PER_PAGE].z;
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x20 + i];
        if (i == 3) {
            reg_a0 = (u8 *)D_0028DD18[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_save_load_cursor == 3) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
}

extern s8 D_002714F3[];
#ifdef DEATH_LABEL
#endif

void menu_debug_option_draw(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 count;
    s32 index;
    s32 top;
    MenuItem *item;

    count = D_002714F3[0];
    switch (g_menu_debug_option_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_debug_option_alpha += 4;
        if (g_menu_debug_option_alpha >= 0x80) {
            g_menu_debug_option_fade_state = 0;
            g_menu_debug_option_alpha = 0x80;
        }
        break;
    case 2:
        g_menu_debug_option_alpha -= 4;
        if (g_menu_debug_option_alpha <= 0) {
            g_menu_debug_option_alpha = 0;
            g_menu_debug_option_fade_state = 0;
        }
        break;
    }
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_DEBUG_OPTION * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_DEBUG_OPTION * MENU_ITEMS_PER_PAGE].alpha = g_menu_debug_option_alpha;
        reg_a0 = (u8 *)g_menu_debug_option_items[i];
        x = item[MENU_PAGE_DEBUG_OPTION * MENU_ITEMS_PER_PAGE].x;
        alpha = item[MENU_PAGE_DEBUG_OPTION * MENU_ITEMS_PER_PAGE].alpha;
        top = item[MENU_PAGE_DEBUG_OPTION * MENU_ITEMS_PER_PAGE].y;
        z = item[MENU_PAGE_DEBUG_OPTION * MENU_ITEMS_PER_PAGE].z;
        if (alpha == 0) {
            continue;
        }
        if (i == 1 && !(g_unlocked_options & 1)) {
            reg_a0 = (u8 *)g_menu_locked_item_text[0];
        }
        if (i == 2 && !(g_unlocked_options & 2)) {
            reg_a0 = (u8 *)g_menu_locked_item_text[0];
        }
        if (i == 3 && !(g_unlocked_options & 4)) {
            reg_a0 = (u8 *)g_menu_locked_item_text[0];
        }
        if (i == 4 && !(g_unlocked_options & 8)) {
            reg_a0 = (u8 *)g_menu_locked_item_text[0];
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x30 + i];
        if (i == 1 && (g_unlocked_options & 1)) {
            reg_a0 = (u8 *)menu_debug_option_draw_table[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_debug_option_cursor == 1) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2 && (g_unlocked_options & 2)) {
            reg_a0 = (u8 *)menu_debug_option_draw_table_2[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_debug_option_cursor == 2) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 3 && (g_unlocked_options & 4)) {
            reg_a0 = (u8 *)menu_debug_option_draw_table_3[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_debug_option_cursor == 3) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 4 && (g_unlocked_options & 8)) {
            reg_a0 = (u8 *)menu_debug_option_draw_table_4[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_debug_option_cursor == 4) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
#ifdef DEATH_LABEL
        if (i == 5) {
            reg_a0 = (u8 *)g_menu_numbers_0_to_500[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_debug_option_cursor == 5) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 6) {
            reg_a0 = (u8 *)D_0028DD60[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_debug_option_cursor == 6) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
#endif
    }
    text_flush();
}

extern s8 D_002714FE[];

void menu_arcade_draw(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    MenuItem *item;

    count = D_002714FE[0];
    switch (g_menu_arcade_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_arcade_alpha += 4;
        if (g_menu_arcade_alpha >= 0x80) {
            g_menu_arcade_fade_state = 0;
            g_menu_arcade_alpha = 0x80;
        }
        break;
    case 2:
        g_menu_arcade_alpha -= 4;
        if (g_menu_arcade_alpha <= 0) {
            g_menu_arcade_alpha = 0;
            g_menu_arcade_fade_state = 0;
        }
        break;
    }
    for (i = 0; i < count; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_ARCADE * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_ARCADE * MENU_ITEMS_PER_PAGE].alpha = g_menu_arcade_alpha;
        reg_a0 = (u8 *)g_menu_arcade_items[i];
        x = item[MENU_PAGE_ARCADE * MENU_ITEMS_PER_PAGE].x;
        alpha = item[MENU_PAGE_ARCADE * MENU_ITEMS_PER_PAGE].alpha;
        top = item[MENU_PAGE_ARCADE * MENU_ITEMS_PER_PAGE].y;
        z = item[MENU_PAGE_ARCADE * MENU_ITEMS_PER_PAGE].z;
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0xE0 + i];
        if (i == 4) {
            reg_a0 = (u8 *)D_0028DD18[index];
            glyph_queue_add(x, y + 32, z, 0, 0x80, alpha, 1);
            if (g_menu_arcade_cursor == 4) {
                menu_arrows_draw(x, y + 32, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
}

#pragma push
#pragma opt_dead_assignments off
void text_queue_clear(void);
void text_flush(void);
extern s8 D_002714FF[];

void menu_system_option_draw(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    void text_queue_glyph(s16 x, s16 y, u16 glyph, s32 w, s32 a4, s32 h, u16 attr, u16 z);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    MenuItem *item;
    u16 glyph;

    count = D_002714FF[0];
    switch (g_menu_system_option_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_system_option_alpha += 4;
        if (g_menu_system_option_alpha >= 0x80) {
            g_menu_system_option_fade_state = 0;
            g_menu_system_option_alpha = 0x80;
        }
        break;
    case 2:
        g_menu_system_option_alpha -= 4;
        if (g_menu_system_option_alpha <= 0) {
            g_menu_system_option_alpha = 0;
            g_menu_system_option_fade_state = 0;
        }
        break;
    }
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_SYSTEM_OPTION * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_SYSTEM_OPTION * MENU_ITEMS_PER_PAGE].alpha = g_menu_system_option_alpha;
        reg_a0 = (u8 *)g_menu_system_option_items[i];
        x = item[MENU_PAGE_SYSTEM_OPTION * MENU_ITEMS_PER_PAGE].x;
        alpha = item[MENU_PAGE_SYSTEM_OPTION * MENU_ITEMS_PER_PAGE].alpha;
        top = item[MENU_PAGE_SYSTEM_OPTION * MENU_ITEMS_PER_PAGE].y;
        z = item[MENU_PAGE_SYSTEM_OPTION * MENU_ITEMS_PER_PAGE].z;
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0xF0 + i];
        if (i == 1) {
            reg_a0 = (u8 *)g_menu_lever_set_names[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_system_option_cursor == 1) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2) {
            if (g_setting_screen_mode == 0) {
                reg_a0 = (u8 *)g_menu_monitor_mode_names[index];
            } else {
                reg_a0 = (u8 *)g_menu_monitor_mode_tate_names[index];
            }
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_system_option_cursor == 2) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 3) {
            reg_a0 = (u8 *)g_menu_monitor_type_names[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_system_option_cursor == 3) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 4) {
            reg_a0 = (u8 *)menu_system_option_draw_table[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_system_option_cursor == 4) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 5) {
            reg_a0 = (u8 *)D_0028DD60[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_system_option_cursor == 5) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 6) {
            reg_a0 = (u8 *)g_menu_original_arrange_names[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (g_menu_system_option_cursor == 6) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 9) {
            glyph = menu_system_option_draw_table_2[g_menu_value_p1_btn_a[0]];
            text_queue_glyph(x - 22, y - 4, glyph, 20, 32, 32, alpha, z);
            glyph = menu_system_option_draw_table_2[g_menu_value_p2_btn_a[0]];
            text_queue_glyph(x - 22, y + 100, glyph, 20, 32, 32, alpha, z);
        }
        if (i == 10) {
            glyph = menu_system_option_draw_table_2[g_menu_value_p1_btn_b[0]];
            text_queue_glyph(x - 22, y - 4, glyph, 20, 32, 32, alpha, z);
            glyph = menu_system_option_draw_table_2[g_menu_value_p2_btn_b[0]];
            text_queue_glyph(x - 22, y + 100, glyph, 20, 32, 32, alpha, z);
        }
        if (i == 11) {
            glyph = menu_system_option_draw_table_2[g_menu_value_p1_btn_c[0]];
            text_queue_glyph(x - 22, y - 4, glyph, 20, 32, 32, alpha, z);
            glyph = menu_system_option_draw_table_2[g_menu_value_p2_btn_c[0]];
            text_queue_glyph(x - 22, y + 100, glyph, 20, 32, 32, alpha, z);
        }
    }
    text_flush();
}
#pragma pop

void menu_alpha_a_update(void) {
    switch (g_menu_alpha_a_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_alpha_a += 4;
        if (g_menu_alpha_a >= 0x80) {
            g_menu_alpha_a_fade_state = 0;
            g_menu_alpha_a = 0x80;
        }
        break;
    case 2:
        g_menu_alpha_a -= 4;
        if (g_menu_alpha_a <= 0) {
            g_menu_alpha_a = 0;
            g_menu_alpha_a_fade_state = 0;
        }
        break;
    }
}

#ifdef DEATH_LABEL
extern s8 death_D_00262EC7[];

void menu_death_option_draw(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    MenuItem *item;

    count = death_D_00262EC7[0];
    switch (death_D_00290C74) {
    case 0:
        break;
    case 1:
        death_D_00290CE4 += 4;
        if (death_D_00290CE4 >= 0x80) {
            death_D_00290C74 = 0;
            death_D_00290CE4 = 0x80;
        }
        break;
    case 2:
        death_D_00290CE4 -= 4;
        if (death_D_00290CE4 <= 0) {
            death_D_00290CE4 = 0;
            death_D_00290C74 = 0;
        }
        break;
    }
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_23 * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_23 * MENU_ITEMS_PER_PAGE].alpha = death_D_00290CE4;
        reg_a0 = (u8 *)menu_death_option_draw_table[i];
        x = item[MENU_PAGE_23 * MENU_ITEMS_PER_PAGE].x;
        alpha = item[MENU_PAGE_23 * MENU_ITEMS_PER_PAGE].alpha;
        top = item[MENU_PAGE_23 * MENU_ITEMS_PER_PAGE].y;
        z = item[MENU_PAGE_23 * MENU_ITEMS_PER_PAGE].z;
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x170 + i];
        if (i == 1) {
            reg_a0 = (u8 *)menu_death_option_draw_table_3[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (death_D_00290C4C == 1) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2) {
            reg_a0 = (u8 *)menu_death_option_draw_table_2[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (death_D_00290C4C == 2) {
                menu_arrows_draw(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
    text_flush();
}
#endif

s32 ranking_screen_draw();
extern u8 g_ranking_opened_from_menu;

void menu_alpha_b_update(void) {
    switch (g_menu_alpha_b_fade_state) {                           /* irregular */
    case 0:
        break;
    case 1:
        g_menu_alpha_b += 4;
        if (g_menu_alpha_b >= 0x80) {
            g_menu_alpha_b_fade_state = 0;
            g_menu_alpha_b = 0x80;
        }
        break;
    case 2:
        g_menu_alpha_b -= 4;
        if (g_menu_alpha_b <= 0) {
            g_menu_alpha_b = 0;
            g_menu_alpha_b_fade_state = 0;
        }
        break;
    }
    if (g_menu_alpha_b != 0) {
        g_ranking_opened_from_menu = 1;
        ranking_screen_draw();
    }
}

extern s16 D_0068DEFA[];

s32 menu_cursor_input(s32 page) {
    extern void sfx_menu_move(void);
    s32 port;
    s32 count;
    u32 pad;

    port = 2;
    switch (page) {
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
    case 17:
    case 18:
        port = g_menu_pad;
        break;
    }
    count = g_menu_page_item_counts[page];
    pad = g_pad_repeat[port];
    if (pad & 0x1000) {
        sfx_menu_move();
        g_menu_cursor--;
        if (g_menu_page == MENU_PAGE_SYSTEM_OPTION && g_menu_cursor == 8) {
            g_menu_cursor--;
        }
        if (page == 18 && D_0068DEFA[0] == 0 && g_menu_cursor == 7) {
            g_menu_cursor = 6;
        }
        if (g_menu_cursor <= 0) {
            g_menu_cursor = count - 1;
        }
        return 1;
    }
    if (pad & 0x4000) {
        sfx_menu_move();
        g_menu_cursor++;
        if (g_menu_page == MENU_PAGE_SYSTEM_OPTION && g_menu_cursor == 8) {
            g_menu_cursor++;
        }
        if (page == 18 && D_0068DEFA[0] == 0 && g_menu_cursor == 7) {
            g_menu_cursor = 8;
        }
        if (g_menu_cursor >= count) {
            g_menu_cursor = 1;
        }
        return 1;
    }
    return 0;
}

s32 sfx_menu_move();                            /* extern */

s32 menu_ranking_cursor_move() {
    if (g_pad_repeat[2] & 0x1000) {
        sfx_menu_move();
        g_menu_cursor -= 1;
        if (g_menu_cursor < 0) {
            g_menu_cursor = 4;
        }
        return 1;
    }
    if (g_pad_repeat[2] & 0x4000) {
        sfx_menu_move();
        g_menu_cursor += 1;
        if (g_menu_cursor >= 5) {
            g_menu_cursor = 0;
        }
        return 1;
    }
    return 0;
}


void menu_box_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s32 x;

    switch (g_menu_box_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_box_alpha += 4;
        if (g_menu_box_alpha >= 0x20) {
            g_menu_box_fade_state = 0;
            g_menu_box_alpha = 0x20;
        }
        break;
    case 2:
        g_menu_box_alpha -= 4;
        if (g_menu_box_alpha <= 0) {
            g_menu_box_alpha = 0;
            g_menu_box_fade_state = 0;
        }
        break;
    }
    if (g_menu_cursor != -1) {
        x = g_menu_item_positions_c[g_menu_cursor].x;
        if (g_menu_box_alpha != 0) {
            gfx_draw_color_box(x - 8, 0, 0x48, 0xE0, 0x5A, g_menu_box_alpha, 0xB4, 1, 1);
        }
    }
}

void menu_box_draw_wide(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s32 sel;
    s32 x;

    switch (g_menu_box_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_box_alpha += 4;
        if (g_menu_box_alpha >= 0x40) {
            g_menu_box_fade_state = 0;
            g_menu_box_alpha = 0x40;
        }
        break;
    case 2:
        g_menu_box_alpha -= 4;
        if (g_menu_box_alpha <= 0) {
            g_menu_box_alpha = 0;
            g_menu_box_fade_state = 0;
        }
        break;
    }
    sel = g_menu_cursor;
    if (sel != -1) {
        if (g_menu_page == MENU_PAGE_SYSTEM_OPTION) {
            x = g_menu_item_positions_b[sel].x;
        } else {
            x = g_menu_item_positions_a[sel].x;
        }
        if (g_menu_box_alpha != 0 && sel != 0) {
            gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, g_menu_box_alpha, 0xB4, 1, 1);
        }
    }
}

extern void frame_draw_left_panel(s32 level);
extern s8 D_002714F9[];
extern s8 D_002714FA[];
extern s32 g_menu_left_panel_alpha;
extern s8 g_replay_slots_state;
extern s32 g_autosave_step;
#ifdef DEATH_LABEL
extern s8 death_D_00290C4C;
#endif

void menu_help_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s64 alpha;
    s32 item;
    u8 state;

    switch (g_menu_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_alpha += 4;
        g_menu_left_panel_alpha += 4;
        if (g_menu_alpha >= 0x80) {
            g_menu_fade_state = 0;
            g_menu_alpha = 0x80;
#ifndef DEATH_LABEL
            g_menu_left_panel_alpha = 0x80;
#endif
        }
        if (g_menu_left_panel_alpha >= 0x80) {
            g_menu_left_panel_alpha = 0x80;
        }
        break;
    case 2:
        g_menu_alpha -= 4;
        if (g_menu_alpha <= 0) {
            g_menu_alpha = 0;
            g_menu_fade_state = 0;
        }
        break;
    }
    if (g_menu_page == MENU_PAGE_PRACTICE_RANKING) {
        return;
    }
    if (g_menu_alpha != 0) {
        text_queue_clear();
        alpha = g_menu_alpha;
        if (alpha >= 0x40) {
            alpha = 0x40;
        }
        if (alpha != 0) {
            frame_draw_left_panel(g_menu_left_panel_alpha);
            gfx_draw_color_box(0xC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        if (g_menu_page == MENU_PAGE_MAIN) {
            reg_a0 = (u8 *)g_menu_main_help[g_menu_main_cursor];
            if (g_menu_exit_code != 3) {
                if (g_menu_main_step != 4 || g_autosave_step == 0) {
                    menu_message_draw(0x36, 8);
                }
            }
        }
        if (g_menu_page == MENU_PAGE_GAME_OPTION) {
            reg_a0 = (u8 *)g_menu_game_option_help[g_menu_game_option_cursor];
            menu_message_draw(0x36, 8);
        }
        if (g_menu_page == MENU_PAGE_SAVE_LOAD) {
            reg_a0 = (u8 *)g_menu_save_load_help[g_menu_save_load_cursor];
            menu_message_draw(0x36, 8);
        }
        if (g_menu_page == MENU_PAGE_DEBUG_OPTION) {
            item = g_menu_debug_option_cursor;
            reg_a0 = (u8 *)g_menu_debug_option_help[item];
            if (item == 1 && !(g_unlocked_options & 1)) {
                reg_a0 = (u8 *)g_menu_unlock_condition_help[0];
            }
            if (item == 2 && !(g_unlocked_options & 2)) {
                reg_a0 = (u8 *)g_menu_unlock_condition_help[0];
            }
            if (item == 4 && !(g_unlocked_options & 8)) {
                reg_a0 = (u8 *)g_menu_unlock_condition_help[0];
            }
            if (item == 5 && !(g_unlocked_options & 0x10)) {
                reg_a0 = (u8 *)g_menu_unlock_condition_help[0];
            }
            menu_message_draw(0x36, 8);
        }
        if (g_menu_page == MENU_PAGE_ARCADE) {
            reg_a0 = (u8 *)g_menu_arcade_help[g_menu_arcade_cursor];
            if (g_menu_arcade_step != 4 || g_autosave_step == 0) {
                menu_message_draw(0x36, 8);
            }
        }
        if (g_menu_page == MENU_PAGE_LAUNCH) {
            if (g_menu_box_alpha != 0) {
                gfx_draw_color_box(0xE0, 0, 0x6E, 0xE0, 0x5A, g_menu_box_alpha, 0xB4, 1, 1);
            }
            reg_a0 = (u8 *)MAIN_OR_DEATH_LABEL(g_menu_launch_ask, menu_help_draw_table_2)[g_menu_launch_kind];
            menu_message_draw(0x36, 8);
            reg_a0 = (u8 *)MAIN_OR_DEATH_LABEL(g_menu_launch_warning, menu_help_draw_table_3)[g_menu_launch_kind];
            menu_message_draw(0x136, 8);
            menu_help_item_draw(0xC, 4);
        }
#ifdef DEATH_LABEL
        if (g_menu_page == MENU_PAGE_23) {
            reg_a0 = (u8 *)menu_help_draw_table[death_D_00290C4C];
            menu_message_draw(0x36, 8);
        }
#endif
        if (g_menu_page == MENU_PAGE_RANKING) {
            reg_a0 = (u8 *)g_menu_ranking_help;
            menu_message_draw(0x36, 8);
        }
        if (g_menu_page == MENU_PAGE_SYSTEM_OPTION) {
            reg_a0 = (u8 *)g_menu_system_option_help[g_menu_system_option_cursor];
            menu_message_draw(0x36, 8);
            if (g_menu_system_option_cursor == 1) {
                reg_a0 = (u8 *)g_menu_lever_set_help[g_menu_value_screen_mode[0]];
                menu_message_draw(0x22, 8);
            }
        }
    }
    if (g_menu_page == MENU_PAGE_SIMULATION) {
        reg_a0 = (u8 *)g_menu_simulation_help[g_menu_simulation.cursor];
        menu_message_draw(0x36, 8);
    }
    if (g_menu_page == MENU_PAGE_SIM_SETTING) {
        reg_a0 = (u8 *)g_menu_sim_setting_help[g_menu_sim_setting.cursor];
        menu_message_draw(0x36, 8);
    }
    if (g_menu_page == MENU_PAGE_SIM_PLAYER) {
        reg_a0 = (u8 *)g_menu_sim_player_help[g_menu_sim_player.cursor];
        menu_message_draw(0x36, 8);
    }
    if (g_menu_page == MENU_PAGE_SIM_RULES) {
        reg_a0 = (u8 *)g_menu_sim_rules_help[g_menu_sim_rules.cursor];
        menu_message_draw(0x36, 8);
    }
    if (g_menu_page == MENU_PAGE_SIM_PARAM) {
        reg_a0 = (u8 *)g_menu_sim_param_help[g_menu_sim_param.cursor];
        menu_message_draw(0x36, 8);
    }
    if (g_menu_page == MENU_PAGE_STAGE_DIFFICULTY) {
        reg_a0 = (u8 *)g_menu_stage_select_difficulty_help[(g_menu_stage_difficulty.cursor == D_002714F9[0] - 1) ? 1 : 0];
        menu_message_draw(0x36, 8);
    }
    if (g_menu_page == MENU_PAGE_STAGE_SELECT) {
        reg_a0 = (u8 *)g_menu_stage_select_start_help[(g_menu_stage_select.cursor == D_002714FA[0] - 1) ? 1 : 0];
        if (g_menu_stage_select.step >= 3) {
            menu_message_draw(0x36, 8);
        }
    }
    if (g_menu_page == MENU_PAGE_REPLAY) {
        state = (u8)g_replay_slots_state;
        if (state != 0 && (u32)(state - 1) > 1 && (u32)(state - 5) > 1) {
            reg_a0 = (u8 *)MAIN_OR_DEATH_LABEL(g_menu_replay_help, g_menu_replay_help);
            menu_message_draw(0x36, 8);
        }
    }
    if (g_menu_page == MENU_PAGE_SUPER_REPLAY) {
        reg_a0 = (u8 *)MAIN_OR_DEATH_LABEL(g_menu_super_replay_help, g_menu_replay_help);
        menu_message_draw(0x36, 8);
    }
    if (g_menu_page == MENU_PAGE_SETTINGS_LOAD) {
        state = (u8)g_replay_slots_state;
        if (state != 0 && (u32)(state - 1) > 1 && (u32)(state - 5) > 1) {
            reg_a0 = (u8 *)g_menu_load_file_help;
            menu_message_draw(0x36, 8);
        }
    }
    if (g_menu_page == MENU_PAGE_PRACTICE_RANKING) {
        reg_a0 = (u8 *)g_menu_ranking_title;
        menu_message_draw(0x36, 8);
    }
    text_flush();
}

s32 sfx_menu_confirm(s32);                         /* extern */
extern s32 g_menu_notice_step;

s32 menu_notice_update(void) {
    s32 var_s0;

    var_s0 = 0;
    if (g_ranking_entry_index == 0xFF) {
        return 1;
    }
    switch (g_menu_notice_step) {                           /* irregular */
    case 0:
        g_menu_ranking_state_a = 1;
        g_menu_cursor = (s8) g_ranking_entry_index;
        g_menu_notice_step += 1;
        g_menu_notice_alpha = 0;
        break;
    case 1:
        if ((g_menu_ranking_state_a == 3) && (g_pad_trigger[2] & 0x20)) {
            sfx_menu_confirm(g_ranking_entry_index);
            g_menu_ranking_state_a = 2;
            g_menu_notice_step += 1;
        }
        break;
    case 2:
        if (g_menu_ranking_state_a == 0) {
            g_menu_notice_step = 0;
            var_s0 = 1;
        }
        break;
    }
    return var_s0;
}


void menu_overlay_draw(void) {
    s32 glyph_queue_clear();
    s32 glyph_queue_flush();
    u8 * spA0;
    u8 * spB0;
    u8 * spC0;
    u8 * spD0;
    u8 * spE0;
    u8 * spF0;
    u8 * temp_fp;
    u32 temp_s7;
    u32 temp_s6;
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;
    u32 temp_s4;
    u32 temp_s5;

    if (g_menu_notice_step != 0) {
        temp_s7 = reg_d0.w;
        temp_s6 = reg_d1.w;
        temp_s0 = reg_d2.w;
        temp_s1 = reg_d3.w;
        temp_s2 = reg_d4.w;
        temp_s3 = reg_d5.w;
        temp_s4 = reg_d6.w;
        temp_s5 = reg_d7.w;
        spA0 = reg_a0;
        spB0 = reg_a1;
        spC0 = reg_a2;
        spD0 = reg_a3;
        spE0 = reg_a4;
        spF0 = reg_a5;
        temp_fp = reg_a6;
        glyph_queue_clear();
        menu_notice_draw();
        glyph_queue_flush();
        reg_d0.w = temp_s7;
        reg_d1.w = temp_s6;
        reg_d2.w = temp_s0;
        reg_d3.w = temp_s1;
        reg_d4.w = temp_s2;
        reg_d5.w = temp_s3;
        reg_d6.w = temp_s4;
        reg_d7.w = temp_s5;
        reg_a0 = spA0;
        reg_a1 = spB0;
        reg_a2 = spC0;
        reg_a3 = spD0;
        reg_a4 = spE0;
        reg_a5 = spF0;
        reg_a6 = temp_fp;
    }
}

extern void frame_draw_right_panel(s32 level);
extern u8 g_stored_ranking_texts[160];
extern u8 g_death_label_ranking_texts[272];

void menu_notice_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern s32 glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 alpha, s32 attr, s32 wide);
    char buf[2];
    s32 alpha;
    s32 i;
    char *p;
    s32 y;

    switch (g_menu_ranking_state_a) {
    case 0:
    case 3:
        break;
    case 1:
        g_menu_notice_alpha += 4;
        if (g_menu_notice_alpha >= 0x80) {
            g_menu_notice_alpha = 0x80;
            g_menu_ranking_state_a = 3;
        }
        break;
    case 2:
        g_menu_notice_alpha -= 4;
        if (g_menu_notice_alpha <= 0) {
            g_menu_notice_alpha = 0;
            g_menu_ranking_state_a = 0;
        }
        break;
    }
    if (g_menu_notice_alpha != 0) {
        text_queue_clear();
        alpha = g_menu_notice_alpha;
        if (g_menu_notice_alpha >= 0x60) {
            alpha = 0x60;
        }
        if (alpha != 0) {
            frame_draw_right_panel(g_menu_notice_alpha);
            gfx_draw_color_box(0xEC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        (*(char **)&reg_a0) = (char *)g_menu_password_title;
        menu_text_queue(0x116, 8, g_menu_notice_alpha);
        buf[1] = 0;
        i = 0;
        y = 0;
        p = MAIN_OR_DEATH_LABEL(((char *)g_death_label_ranking_texts), ((char *)g_stored_ranking_texts)) + g_menu_cursor * 0x1E;
        do {
            (*(char **)&reg_a0) = buf;
            *(*(char **)&reg_a0) = *p++;
            glyph_queue_add(0x106, y + 0xE + (i / 5) * 5, 0x136, 0, 0x80, g_menu_notice_alpha, 1);
            i++;
            y += 9;
        } while (i < 0x14);
    }
    text_flush();
}

extern s8 g_result_notice_unread_flag;
extern s8 g_result_notice_state;
extern s8 g_result_notice_step;
extern s32 g_menu_ranking_alpha;
extern s32 menu_reset_state;
extern s8 g_menu_replay_chosen;

#ifdef DEATH_LABEL
extern s32 death_D_00290CE4;
extern s8 death_D_00290CA8;
extern s8 death_D_00290C74;
extern s8 death_D_00290C4C;
#endif

void menu_reset() {
    menu_reset_state = 0;
    g_menu_main_alpha = 0;
    g_menu_game_option_alpha = 0;
    g_menu_save_load_alpha = 0;
    g_menu_debug_option_alpha = 0;
    g_menu_arcade_alpha = 0;
    g_menu_system_option_alpha = 0;
    g_menu_ranking_alpha = 0;
    g_menu_alpha_a = 0;
#ifdef DEATH_LABEL
    death_D_00290CE4 = 0;
#endif
    g_menu_alpha_b = 0;
    g_menu_alpha = 0;
    g_menu_left_panel_alpha = 0;
    g_menu_page = MENU_PAGE_MAIN;
    g_menu_main_unread_flag = 0;
    g_menu_main_step = 0;
    g_menu_game_option_step = 0;
    g_menu_save_load_step = 0;
    g_menu_debug_option_step = 0;
    g_menu_arcade_step = 0;
    g_menu_system_option_step = 0;
    g_result_notice_step = 0;
    g_menu_launch_step = 0;
#ifdef DEATH_LABEL
    death_D_00290CA8 = 0;
#endif
    g_menu_ranking_step = 0;
    g_menu_fade_state = 0;
    g_menu_cursor = 0;
    g_menu_box_fade_state = 0;
    g_menu_box_alpha = 0;
    g_menu_main_fade_state = 0;
    g_menu_game_option_fade_state = 0;
    g_menu_save_load_fade_state = 0;
    g_menu_debug_option_fade_state = 0;
    g_menu_arcade_fade_state = 0;
    g_menu_system_option_fade_state = 0;
    g_result_notice_state = 0;
    g_menu_alpha_a_fade_state = 0;
#ifdef DEATH_LABEL
    death_D_00290C74 = 0;
#endif
    g_menu_alpha_b_fade_state = 0;
    g_menu_game_option_cursor = 0;
    g_menu_save_load_cursor = 0;
    g_menu_debug_option_cursor = 0;
    g_menu_arcade_cursor = 0;
    g_menu_system_option_cursor = 0;
    g_result_notice_unread_flag = 0;
    g_menu_launch_cursor = 0;
#ifdef DEATH_LABEL
    death_D_00290C4C = 0;
#endif
    g_menu_ranking_cursor = 0;
    g_menu_ranking_state_b = 0;
    g_menu_ranking_state_a = 0;
    g_menu_notice_alpha = 0;
    g_menu_replay_chosen = 0;
    g_menu_task_phase = 1;
    g_menu_main_cursor = 1;
    memset(&g_menu_simulation, 0, 6);
    memset(&g_menu_sim_setting, 0, 6);
    memset(&g_menu_sim_player, 0, 6);
    memset(&g_menu_sim_rules, 0, 6);
    memset(&g_menu_stage_difficulty, 0, 6);
    memset(&g_menu_stage_select, 0, 6);
    memset(&g_menu_file_select, 0, 6);
    memset(&g_menu_practice_ranking, 0, 6);
    replay_slots_reset();
    g_replay_file_finalized = 0;
    g_menu_exit_code = 1;
    menu_items_clear();
    menu_values_from_settings();
}

void menu_items_clear(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 16; j++) {
            g_menu_items[i][j].active = 0;
            ((u8 (*)[16])D_0068DC10)[i][j] = 0;
        }
    }
    for (j = 0; j < 16; j++) {
        g_menu_items[12][j].active = 0;
    }
}

void menu_items_place(s32 group) {
    s32 i;
    s32 count;
    s32 x;
    s32 y;
    s32 id;

    id = group + 100;
    count = g_menu_page_item_counts[group];
    for (i = 0; i < count; i++) {
        if (group == 15) {
            x = g_menu_item_positions_b[i].x;
            g_menu_items[group][i].x = x;
            y = g_menu_item_positions_b[i].y;
            g_menu_items[group][i].y = y;
            g_menu_items[group][i].target_x = x;
            g_menu_items[group][i].target_y = y;
        } else {
            x = g_menu_item_positions_a[i].x;
            g_menu_items[group][i].x = x;
            y = g_menu_item_positions_a[i].y;
            g_menu_items[group][i].y = y;
            g_menu_items[group][i].target_x = x;
            g_menu_items[group][i].target_y = y;
        }
        g_menu_items[group][i].alpha = 0;
        g_menu_items[group][i].delay = 0x3C;
        g_menu_items[group][i].z = id;
        g_menu_items[group][i].active = 1;
    }
}

#pragma push
#pragma divbyzerocheck on

void menu_items_slide_in(s32 group) {
    s32 i;
    s32 count;
    s32 dx;
    s32 dy;
    s32 tag;

    tag = group + 100;
    count = g_menu_page_item_counts[group];
    for (i = 0; i < count; i++) {
        if (group == 15) {
            g_menu_items[group][i].x = -g_menu_item_positions_b[i].x;
            g_menu_items[group][i].y = g_menu_item_positions_b[i].y;
            g_menu_items[group][i].target_x = g_menu_item_positions_b[i].x;
            g_menu_items[group][i].target_y = g_menu_item_positions_b[i].y;
        } else {
            g_menu_items[group][i].x = -g_menu_item_positions_a[i].x;
            g_menu_items[group][i].y = g_menu_item_positions_a[i].y;
            g_menu_items[group][i].target_x = g_menu_item_positions_a[i].x;
            g_menu_items[group][i].target_y = g_menu_item_positions_a[i].y;
        }
        g_menu_items[group][i].alpha = 0;
        g_menu_items[group][i].delay = 60;
        g_menu_items[group][i].z = tag;
        g_menu_items[group][i].active = 1;
        dx = g_menu_items[group][i].target_x - g_menu_items[group][i].x;
        dy = g_menu_items[group][i].target_y - g_menu_items[group][i].y;
        if (dx < 0) {
            dx = -dx;
        }
        if (dy < 0) {
            dy = -dy;
        }
        g_menu_items[group][i].accel_x = 0;
        g_menu_items[group][i].accel_y = 0;
        if (dx != 0) {
            g_menu_items[group][i].accel_x = dx * 10000 / menu_items_slide_in_table[0];
        }
        if (dy != 0) {
            g_menu_items[group][i].accel_y = dy * 10000 / menu_items_slide_in_table[0];
        }
        g_menu_items[group][i].speed_x = g_menu_items[group][i].accel_x * 60;
        g_menu_items[group][i].speed_y = g_menu_items[group][i].accel_y * 60;
        g_menu_items[group][i].pos_x = g_menu_items[group][i].x * 10000;
        g_menu_items[group][i].pos_y = g_menu_items[group][i].y * 10000;
    }
}
#pragma pop



s32 menu_items_slide_update(s32 group) {
    s32 i;
    s32 count;
    s32 done;
    MenuItem *m;
    s32 *delay;
    s32 off;
    s32 *target;
    s32 *cur;

    done = 0;
    count = g_menu_page_item_counts[group];
    i = 0;
    if (i < count) {
        off = 0;
        do {
            m = (MenuItem *)((u8 *)g_menu_items + group * 0x380 + off);
            delay = &m->delay;
            if (*delay != 0) {
                (*delay)--;
            }
            if (*delay <= 0) {
                done++;
                m->x = m->target_x;
                m->y = m->target_y;
            }
            cur = &m->x;
            target = &m->target_x;
            if (m->x != m->target_x) {
                if (m->x < m->target_x) {
                    *cur = m->pos_x / 10000;
                    m->pos_x += m->speed_x;
                    m->speed_x -= m->accel_x;
                    if (*cur > *target) {
                        *cur = *target;
                    }
                } else {
                    *cur = m->pos_x / 10000;
                    m->pos_x -= m->speed_x;
                    m->speed_x -= m->accel_x;
                    if (*cur < *target) {
                        *cur = *target;
                    }
                }
            }
            cur = &m->y;
            target = &m->target_y;
            if (m->y != m->target_y) {
                if (m->y < m->target_y) {
                    *cur = m->pos_y / 10000;
                    m->pos_y += m->speed_y;
                    m->speed_y -= m->accel_y;
                    if (*cur > *target) {
                        *cur = *target;
                    }
                } else {
                    *cur = m->pos_y / 10000;
                    m->pos_y -= m->speed_y;
                    m->speed_y -= m->accel_y;
                    if (*cur < *target) {
                        *cur = *target;
                    }
                }
            }
            i++;
            off += 0x38;
        } while (i < count);
    }
    return done == count;
}


void menu_button_assign_input(void) {
    extern void sfx_menu_confirm(void);
    s32 button;
    s32 slot;
    s32 sel;

    if (g_pad_trigger[0] != 0) {
        for (button = 0; button < 8; button++) {
            if (g_pad_trigger[0] & (1 << button)) {
                goto found1;
            }
        }
        goto next;
found1:
        sfx_menu_confirm();
        sel = g_menu_system_option_cursor;
        for (slot = 9; slot < MAIN_OR_DEATH_LABEL(12, 13); slot++) {
            if (sel != slot && button == D_0068DC10[slot + 0xF0]) {
                D_0068DC10[slot + 0xF0] = D_0068DC10[sel + 0xF0];
            }
        }
        D_0068DD00[sel] = button;
    }
next:
    if (g_pad_trigger[1] != 0) {
        for (button = 0; button < 8; button++) {
            if (g_pad_trigger[1] & (1 << button)) {
                goto found2;
            }
        }
        return;
found2:
        sfx_menu_confirm();
        sel = g_menu_system_option_cursor + 4;
        for (slot = 13; slot < MAIN_OR_DEATH_LABEL(16, 17); slot++) {
            if (sel != slot && button == D_0068DC10[slot + 0xF0]) {
                D_0068DC10[slot + 0xF0] = D_0068DC10[sel + 0xF0];
            }
        }
        D_0068DD00[sel] = button;
    }
}

void text_queue_sjis(s16 x, s16 y, u8 *text, s32 a3, s32 w, s32 h, u16 attr, s32 z);
void text_queue_ascii(s16 x, s16 y, u8 *text, s32 a3, s32 w, s32 h, u16 attr, s32 z);
extern u16 g_game_frame;

void menu_message_draw(s32 x, s32 y) {
    void text_queue_glyph(s16 x, s16 y, s32 glyph, s32 w, s32 a4, s32 h, u16 attr, s32 z);
    u8 buf[4];
    s32 n;
    s32 single;
    s32 i;
    s32 cx;
    s32 cy;

    cy = y;
    cx = x;
    for (i = 0; i < 0x100; i++) {
        buf[0] = *(s8 *)reg_a0;
        reg_a0 += 1;
        if (buf[0] < 0x81) {
            buf[1] = 0;
            single = 1;
        } else {
            single = 0;
            buf[1] = *(s8 *)reg_a0;
            reg_a0 += 1;
        }
        *(u16 *)&buf[2] = 0;
        switch (*(u16 *)buf) {
        case 0x5E81:
            cx -= 0x14;
            cy = y;
            break;
        case 0x8F81:
            return;
        case 0x6781:
            text_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, g_menu_alpha, 0x12C);
            cy += 0xC;
            break;
        case 0x6881:
            text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, g_menu_alpha, 0x12C);
            cy += 0xC;
            break;
        case 0x6981:
            text_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, g_menu_alpha, 0x12C);
            cy += 0xC;
            break;
        case 0x6A81:
            text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, g_menu_alpha, 0x12C);
            cy += 0xC;
            break;
        case 0x9B81:
            text_queue_glyph(cx - 0x10, cy + 2, 0x227C, 0x14, 0x26, 0x14, g_menu_alpha, 0x12C);
            cy += 0x10;
            break;
        case 0x7E81:
            text_queue_glyph(cx - 0x10, cy + 2, 0x227D, 0x14, 0x26, 0x14, g_menu_alpha, 0x12C);
            cy += 0x10;
            break;
        case 0x9781:
            buf[0] = 0x81;
            buf[1] = 0x44;
            for (n = (g_game_frame >> 5) & 3; n > 0; n--) {
                text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, g_menu_alpha, 0x12C);
                cy += 5;
            }
            return;
        default:
            if (single != 0) {
                text_queue_ascii(cx, cy, buf, 0, 0x14, 0x10, g_menu_alpha, 0x12C);
                cy += 8;
            } else {
                text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, g_menu_alpha, 0x12C);
                cy += 0x10;
            }
            break;
        }
    }
}

void menu_text_queue(s32 x, s32 y, s32 attr) {
    void text_queue_glyph(s16 x, s16 y, s32 glyph, s32 w, s32 a4, s32 h, u16 attr, s32 z);
    u8 buf[4];
    s32 n;
    s32 single;
    s32 i;
    s32 cx;
    s32 cy;

    cy = y;
    cx = x;
    for (i = 0; i < 0x100; i++) {
        buf[0] = *(s8 *)reg_a0;
        reg_a0 += 1;
        if (buf[0] < 0x81) {
            buf[1] = 0;
            single = 1;
        } else {
            single = 0;
            buf[1] = *(s8 *)reg_a0;
            reg_a0 += 1;
        }
        *(u16 *)&buf[2] = 0;
        switch (*(u16 *)buf) {
        case 0x5E81:
            cx -= 0x14;
            cy = y;
            break;
        case 0x8F81:
            return;
        case 0x6781:
            text_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x6881:
            text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x6981:
            text_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x6A81:
            text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x9B81:
            text_queue_glyph(cx - 0x10, cy + 2, 0x227C, 0x14, 0x26, 0x14, attr, 0x12C);
            cy += 0x10;
            break;
        case 0x7E81:
            text_queue_glyph(cx - 0x10, cy + 2, 0x227D, 0x14, 0x26, 0x14, attr, 0x12C);
            cy += 0x10;
            break;
        case 0x9781:
            buf[0] = 0x81;
            buf[1] = 0x44;
            for (n = (g_game_frame >> 5) & 3; n > 0; n--) {
                text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
                cy += 5;
            }
            return;
        default:
            if (single != 0) {
                text_queue_ascii(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
                cy += 8;
            } else {
                text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
                cy += 0x10;
            }
            break;
        }
    }
}

void overlay_queue_sjis(s16 x, s16 y, u8 *text, s32 a3, s32 w, s32 h, u16 attr, s32 z);
void overlay_queue_glyph(s16 x, s16 y, s32 glyph, s32 w, s32 a4, s32 h, u16 attr, s32 z);
void overlay_queue_ascii(s16 x, s16 y, u8 *text, s32 a3, s32 w, s32 h, u16 attr, s32 z);

void menu_text_queue_plain(s32 x, s32 y, s32 attr) {
    u8 buf[4];
    s32 n;
    s32 single;
    s32 i;
    s32 cx;
    s32 cy;

    cy = y;
    cx = x;
    for (i = 0; i < 0x100; i++) {
        buf[0] = *(s8 *)reg_a0;
        reg_a0 += 1;
        if (buf[0] < 0x81) {
            buf[1] = 0;
            single = 1;
        } else {
            single = 0;
            buf[1] = *(s8 *)reg_a0;
            reg_a0 += 1;
        }
        *(u16 *)&buf[2] = 0;
        switch (*(u16 *)buf) {
        case 0x5E81:
            cx -= 0x14;
            cy = y;
            break;
        case 0:
        case 0x8F81:
            return;
        case 0x6781:
            overlay_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x6881:
            overlay_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x6981:
            overlay_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x6A81:
            overlay_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x9B81:
            overlay_queue_glyph(cx - 0x10, cy + 2, 0x227C, 0x14, 0x26, 0x14, attr, 0x12C);
            cy += 0x10;
            break;
        case 0x7E81:
            overlay_queue_glyph(cx - 0x10, cy + 2, 0x227D, 0x14, 0x26, 0x14, attr, 0x12C);
            cy += 0x10;
            break;
        case 0x9781:
            buf[0] = 0x81;
            buf[1] = 0x44;
            for (n = (g_game_frame >> 5) & 3; n > 0; n--) {
                overlay_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
                cy += 5;
            }
            return;
        default:
            if (single != 0) {
                overlay_queue_ascii(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
                cy += 8;
            } else {
                overlay_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
                cy += 0x10;
            }
            break;
        }
    }
}

extern u8 g_paused;

void pause_update(void) {
    extern void sfx_menu_confirm(void);
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    if (g_paused != 0 && g_paused != 0x63) {
        save_d0 = reg_d0.w;
        save_d1 = reg_d1.w;
        save_d2 = reg_d2.w;
        save_d3 = reg_d3.w;
        save_d4 = reg_d4.w;
        save_d5 = reg_d5.w;
        save_d6 = reg_d6.w;
        save_d7 = reg_d7.w;
        save_a0 = reg_a0;
        save_a1 = reg_a1;
        save_a2 = reg_a2;
        save_a3 = reg_a3;
        save_a4 = reg_a4;
        save_a5 = reg_a5;
        save_a6 = reg_a6;
        switch (g_paused) {
        case 0:
            break;
        case 1:
            pause_begin();
            break;
        case 2:
            sfx_menu_confirm();
            g_paused++;
            break;
        case 3:
            pause_menu_update();
            break;
        case 4:
            pause_end();
            break;
        case 5:
            pause_menu_confirm();
            break;
        case 0xB:
            pause_screen_adjust_update();
            break;
        case 0x63:
            break;
        }
        reg_d0.w = save_d0;
        reg_d1.w = save_d1;
        reg_d2.w = save_d2;
        reg_d3.w = save_d3;
        reg_d4.w = save_d4;
        reg_d5.w = save_d5;
        reg_d6.w = save_d6;
        reg_d7.w = save_d7;
        reg_a0 = save_a0;
        reg_a1 = save_a1;
        reg_a2 = save_a2;
        reg_a3 = save_a3;
        reg_a4 = save_a4;
        reg_a5 = save_a5;
        reg_a6 = save_a6;
    }
}

extern void streams_pause(void);
extern void vibration_stop_all(void);
extern void vibration_suspend(void);
extern u16 g_pause_loop_choice;
extern u16 g_pause_stage_choice;
extern u16 g_loop;
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
#endif
extern u16 g_stage;
extern u8 g_pause_input_delay;
extern s16 g_pause_box_alpha;
extern u8 g_pause_box_fade_state;
extern s8 g_pause_menu_cursor;
extern u8 g_replay_buffer_state;

void pause_begin(void) {
    g_paused++;
    g_pause_box_alpha = 0;
    g_menu_alpha = 0;
    g_pause_menu_cursor = 1;
    g_pause_box_fade_state = 1;
    g_menu_fade_state = 1;
    g_menu_left_panel_alpha = 0;
    g_pause_loop_choice = MAIN_OR_DEATH_LABEL(g_loop, death_D_00290DC0);
    g_pause_stage_choice = g_stage;
    if (g_pause_stage_choice == 0) {
        g_pause_stage_choice = 1;
    }
    g_pause_input_delay = 0x28;
    vibration_suspend();
    vibration_stop_all();
    streams_pause();
    if (g_replay_buffer_state == 1) {
        g_replay_buffer_state = 3;
    }
}

extern s8 g_pause_confirm_cursor;


extern void stage_clear_from_menu(void);
extern void vibration_start_pad1(s32 a, s32 b);
extern void vibration_start_pad2(s32 a, s32 b);
extern Pair g_menu_wallpapers_as_Pair_a[];
extern u16 g_pause_player;
extern u8 g_stage_jump_state;
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
#endif
extern s8 g_pause_menu_cursor;
s32 streams_resume();
s32 vibration_resume();
extern u8 g_pause_lock_timer;
s32 replay_start_run();
s32 replay_start_result();
extern u8 g_replay_mode;
extern u8 g_simulation_active;
extern s16 D_00271C8C[];
extern s32 sprintf(char *buf, const char *format, ...);
extern void text_queue_sjis_vertical(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth);
extern char *g_pad_dma_buf;
extern u8 *D_00271BC8[];
extern u8 *D_00271BCC[];
extern u8 *D_00271BD0[];
extern u8 *D_00271BD4[];

void pause_menu_update(void) {
    extern void sfx_menu_confirm(void);
    extern void sfx_menu_tick(void);
    extern void wallpaper_load(s32 a, s32 b);
    u32 pad;

    if ((s8)g_pause_input_delay != 0) {
        (*(s8 *)&g_pause_input_delay)--;
    }
    if ((s8)g_pause_input_delay == 0 && (g_pad_trigger[g_pause_player] & 0x800)) {
        sfx_menu_confirm();
        g_paused++;
        return;
    }
    if (pause_menu_cursor_move() != 0) {
        return;
    }
    switch (g_pause_menu_cursor) {
    case 1:
        pad = g_pad_repeat[g_pause_player];
        if (pad & 0x8000) {
            sfx_menu_tick();
            g_menu_value_screen_variant[0]--;
            g_setting_screen_variant = g_menu_value_screen_variant[0];
            if (g_setting_screen_mode == 0) {
                g_setting_screen_variant &= 3;
            } else {
                g_setting_screen_variant &= 1;
            }
            g_menu_value_screen_variant[0] = g_setting_screen_variant;
            g_display_reset_pending = 1;
        } else if (pad & 0x2000) {
            sfx_menu_tick();
            g_menu_value_screen_variant[0]++;
            g_setting_screen_variant = g_menu_value_screen_variant[0];
            if (g_setting_screen_mode == 0) {
                g_setting_screen_variant &= 3;
            } else {
                g_setting_screen_variant &= 1;
            }
            g_menu_value_screen_variant[0] = g_setting_screen_variant;
            g_display_reset_pending = 1;
        }
        break;
    case 2:
        if (g_pad_repeat[g_pause_player] & 0xA000) {
            sfx_menu_tick();
            g_pad_vib_enabled++;
            g_pad_vib_enabled &= 1;
            if (g_pad_vib_enabled != 0) {
                vibration_start_pad1(0x78, 0x14);
                vibration_start_pad2(0x78, 0x14);
            }
        }
        break;
    case 3:
        pad = g_pad_repeat[g_pause_player];
        if (pad & 0x8000) {
            sfx_menu_tick();
            g_setting_wallpaper--;
            if ((s16)g_setting_wallpaper < 0) {
                g_setting_wallpaper = 5;
            }
            if (g_setting_wallpaper != 5) {
                wallpaper_load(g_menu_wallpapers_as_Pair_a[g_setting_wallpaper].a, g_menu_wallpapers_as_Pair_a[g_setting_wallpaper].b);
            }
        } else if (pad & 0x2000) {
            sfx_menu_tick();
            g_setting_wallpaper++;
            if (g_setting_wallpaper > 5) {
                g_setting_wallpaper = 0;
            }
            if (g_setting_wallpaper != 5) {
                wallpaper_load(g_menu_wallpapers_as_Pair_a[g_setting_wallpaper].a, g_menu_wallpapers_as_Pair_a[g_setting_wallpaper].b);
            }
        }
        break;
    case 4:
        if (g_pad_repeat[g_pause_player] & 0xA000) {
            sfx_menu_tick();
            g_stage_map_enabled++;
            g_stage_map_enabled &= 1;
        }
        break;
    case 5:
        if (g_pad_trigger[g_pause_player] & 0x20) {
            sfx_menu_confirm();
            g_menu_alpha = 0x80;
            g_menu_display_offset_x = g_display_offset_x;
            g_paused = 0xB;
            g_menu_display_offset_y = g_display_offset_y;
        }
        break;
    case 6:
    case 7:
        if (g_pad_trigger[g_pause_player] & 0x20) {
            sfx_menu_confirm();
            g_pause_confirm_cursor = 1;
            g_paused = 5;
        }
        break;
    case 8:
        if (g_pad_repeat[g_pause_player] & 0xA000) {
            sfx_menu_tick();
            g_pause_loop_choice++;
            g_pause_loop_choice &= 1;
        }
        break;
    case 9:
        pad = g_pad_repeat[g_pause_player];
        if (pad & 0x8000) {
            sfx_menu_tick();
            g_pause_stage_choice--;
            if ((s32)g_pause_stage_choice <= 0) {
                g_pause_stage_choice = 5;
            }
        } else if (pad & 0x2000) {
            sfx_menu_tick();
            g_pause_stage_choice++;
            if (g_pause_stage_choice > 5) {
                g_pause_stage_choice = 1;
            }
        }
        if (g_stage_jump_state != 0xFF && (g_pad_trigger[g_pause_player] & 0x20)) {
            reg_d6.h[0] = 1;
            reg_d7.h[0] = g_pause_stage_choice;
            if (reg_d7.h[0] == 5) {
                reg_d7.h[0] = 0;
            }
            stage_clear_from_menu();
            g_paused = 0;
        }
        break;
    }
    MAIN_OR_DEATH_LABEL(g_loop, death_D_00290DC0) = g_pause_loop_choice;
}

void pause_end(void) {
    g_paused = 0;
    streams_resume();
    g_pause_lock_timer = 0x3C;
    vibration_resume();
    if (g_replay_buffer_state == 3) {
        g_replay_buffer_state = 1;
    }
}

void pause_menu_confirm(void) {
    extern void sfx_menu_confirm(void);
    extern void sfx_menu_tick(void);
    u32 buttons;

    buttons = g_pad_trigger[g_pause_player];
    if (buttons & 0x20) {
        if (g_pause_confirm_cursor == 0) {
            if (g_simulation_active == 0 && g_replay_mode != 2) {
                pause_menu_quit_confirm();
            } else {
                sfx_menu_confirm();
                if (g_pause_menu_cursor == 7) {
                    replay_start_result();
                } else {
                    game_screen_teardown();
                    replay_start_run();
                }
            }
        } else {
            sfx_menu_confirm();
            g_paused = 3;
        }
        return;
    }
    if (buttons & 0x40) {
        sfx_menu_confirm();
        g_paused = 3;
        return;
    }
    if ((buttons & 0x8000) && g_pause_confirm_cursor == 1) {
        sfx_menu_tick();
        g_pause_item_shrink = 0;
        g_pause_confirm_cursor = 0;
        return;
    }
    if ((buttons & 0x2000) && g_pause_confirm_cursor == 0) {
        sfx_menu_tick();
        g_pause_item_shrink = 0;
        g_pause_confirm_cursor = 1;
    }
}

s32 pause_menu_cursor_move(void) {
    s32 sfx_menu_move();
    s32 temp_s0;
    s32 temp_v1;
    s32 temp_v1_2;

    if (g_simulation_active == 0) { temp_s0 = 8; } else { temp_s0 = 8; }
    if (g_simulation_active == 0) {
        temp_v1 = g_pad_repeat[g_pause_player];
        if (temp_v1 & 0x1000) {
            sfx_menu_move();
            g_pause_menu_cursor -= 1;
            if (g_pause_menu_cursor == 6) {
                g_pause_menu_cursor -= 1;
            }
            if (g_pause_menu_cursor <= 0) {
                g_pause_menu_cursor = temp_s0 - 1;
            }
            return 1;
        }
        if (temp_v1 & 0x4000) {
            sfx_menu_move();
            g_pause_menu_cursor += 1;
            if (g_pause_menu_cursor == 6) {
                g_pause_menu_cursor += 1;
            }
            if (g_pause_menu_cursor >= temp_s0) {
                g_pause_menu_cursor = 1;
            }
            return 1;
        }
        goto block_21;
    }
    temp_v1_2 = g_pad_repeat[g_pause_player];
    if (temp_v1_2 & 0x1000) {
        sfx_menu_move();
        g_pause_menu_cursor -= 1;
        if (g_pause_menu_cursor <= 0) {
            g_pause_menu_cursor = temp_s0 - 1;
        }
        return 1;
    }
    if (temp_v1_2 & 0x4000) {
        sfx_menu_move();
        g_pause_menu_cursor += 1;
        if (g_pause_menu_cursor >= temp_s0) {
            g_pause_menu_cursor = 1;
        }
        return 1;
    }
block_21:
    return 0;
}

void pause_menu_box_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s32 x;

    switch ((s8)g_pause_box_fade_state) {
    case 0:
        break;
    case 1:
        g_pause_box_alpha += 4;
        if (g_pause_box_alpha >= 0x40) {
            g_pause_box_fade_state = 0;
            g_pause_box_alpha = 0x40;
        }
        break;
    case 2:
        g_pause_box_alpha -= 4;
        if (g_pause_box_alpha <= 0) {
            g_pause_box_alpha = 0;
            g_pause_box_fade_state = 0;
        }
        break;
    }
    if (g_simulation_active == 0 && g_pause_menu_cursor > 6) {
        x = D_00271C8C[g_pause_menu_cursor * 2];
    } else {
        x = g_pause_menu_positions[g_pause_menu_cursor].x;
    }
    if (g_pause_box_alpha != 0) {
        gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, g_pause_box_alpha, 0xB4, 1, 1);
    }
}

void pause_menu_items_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s64 alpha;

    switch (g_menu_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_alpha += 4;
        if (g_menu_alpha >= 0x80) {
            g_menu_fade_state = 0;
            g_menu_alpha = 0x80;
        }
        break;
    case 2:
        g_menu_alpha -= 4;
        if (g_menu_alpha <= 0) {
            g_menu_alpha = 0;
            g_menu_fade_state = 0;
        }
        break;
    }
    if (g_menu_alpha != 0) {
        text_queue_clear();
        alpha = g_menu_alpha;
        if (g_menu_alpha >= 0x40) {
            alpha = 0x40;
        }
        if (alpha != 0) {
            frame_draw_left_panel(g_menu_alpha);
            gfx_draw_color_box(0xC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        if (g_paused != 5) {
            if (g_replay_mode == 2) {
                reg_a0 = (u8 *)g_menu_pause_help_c[g_pause_menu_cursor];
#ifndef DEATH_LABEL
            } else if (g_simulation_active != 0) {
                reg_a0 = (u8 *)g_menu_pause_help_b[g_pause_menu_cursor];
#endif
            } else {
                reg_a0 = (u8 *)g_menu_pause_help_a[g_pause_menu_cursor];
            }
            menu_message_draw(0x36, 8);
        } else {
            pause_menu_item_draw(0xC, 8);
        }
        text_flush();
    }
}

void pause_menu_item_draw(s32 x, s32 y) {
    s32 shrink;
    s32 w;
    s32 h;
    s32 px;
    s32 py;

    if (g_pause_item_shrink < 4) {
        g_pause_item_shrink += 2;
    }
    px = x + 40;
    py = y + 10;
    shrink = 0;
    if (g_pause_item_shrink != 0) {
        shrink = (s32)(s8)g_pause_item_shrink / 2;
    }
    w = (s32)(s8)g_pause_item_shrink + 20;
    h = (s32)(s8)g_pause_item_shrink + 16;
    if (g_pause_menu_cursor == 6) {
        reg_a0 = D_00271BD0[0];
    } else if (g_replay_mode == 2) {
        reg_a0 = D_00271BCC[0];
#ifndef DEATH_LABEL
    } else if (g_simulation_active != 0) {
        reg_a0 = D_00271BD4[0];
#endif
    } else {
        reg_a0 = D_00271BC8[0];
    }
    menu_message_draw(x + 42, y);
    if (g_pause_confirm_cursor == 0) {
        sprintf(g_pad_dma_buf, "\x82\xCD\x82\xA2");
        text_queue_sjis_vertical(py - shrink, px - shrink, g_pad_dma_buf, 4, w, h, 128, 300);
        sprintf(g_pad_dma_buf, "\x81\x5E");
        text_queue_sjis_vertical(py, px + 50, g_pad_dma_buf, 0, 20, 16, 128, 300);
        sprintf(g_pad_dma_buf, "\x82\xA2\x82\xA2\x82\xA6");
        text_queue_sjis_vertical(py, px + 75, g_pad_dma_buf, 0, 20, 16, 128, 300);
    } else {
        sprintf(g_pad_dma_buf, "\x82\xCD\x82\xA2");
        text_queue_sjis_vertical(py, px, g_pad_dma_buf, 0, 20, 16, 128, 300);
        sprintf(g_pad_dma_buf, "\x81\x5E");
        text_queue_sjis_vertical(py, px + 50, g_pad_dma_buf, 0, 20, 16, 128, 300);
        sprintf(g_pad_dma_buf, "\x82\xA2\x82\xA2\x82\xA6");
        text_queue_sjis_vertical(py - shrink, px + 75 - shrink, g_pad_dma_buf, 4, w, h, 128, 300);
    }
}

void menu_help_item_draw(s32 x, s32 y) {
    s32 shrink;
    s32 w;
    s32 h;
    s32 px;
    s32 py;

    if (g_pause_item_shrink < 4) {
        g_pause_item_shrink += 2;
    }
    px = x + 40;
    py = y + 10;
    shrink = 0;
    if (g_pause_item_shrink != 0) {
        shrink = (s32)(s8)g_pause_item_shrink / 2;
    }
    w = (s32)(s8)g_pause_item_shrink + 20;
    h = (s32)(s8)g_pause_item_shrink + 16;
    if (g_menu_launch_cursor == 1) {
        sprintf(g_pad_dma_buf, "\x82\xCD\x82\xA2");
        text_queue_sjis_vertical(py - shrink, px - shrink, g_pad_dma_buf, 4, w, h, 128, 300);
        sprintf(g_pad_dma_buf, "\x81\x5E");
        text_queue_sjis_vertical(py, px + 50, g_pad_dma_buf, 0, 20, 16, 128, 300);
        sprintf(g_pad_dma_buf, "\x82\xA2\x82\xA2\x82\xA6");
        text_queue_sjis_vertical(py, px + 75, g_pad_dma_buf, 0, 20, 16, 128, 300);
    } else {
        sprintf(g_pad_dma_buf, "\x82\xCD\x82\xA2");
        text_queue_sjis_vertical(py, px, g_pad_dma_buf, 0, 20, 16, 128, 300);
        sprintf(g_pad_dma_buf, "\x81\x5E");
        text_queue_sjis_vertical(py, px + 50, g_pad_dma_buf, 0, 20, 16, 128, 300);
        sprintf(g_pad_dma_buf, "\x82\xA2\x82\xA2\x82\xA6");
        text_queue_sjis_vertical(py - shrink, px + 75 - shrink, g_pad_dma_buf, 4, w, h, 128, 300);
    }
}

void pause_menu_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern void glyph_queue_clear(void);
    extern void glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    extern void glyph_queue_flush(void);
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    s32 x;
    s32 y;
    s32 n;

    if (g_paused != 0 && g_paused != 0x63) {
        if (g_paused == 0xB) {
            menu_screen_adjust_draw();
            return;
        }
        save_d0 = reg_d0.w;
        save_d1 = reg_d1.w;
        save_d2 = reg_d2.w;
        save_d3 = reg_d3.w;
        save_d4 = reg_d4.w;
        save_d5 = reg_d5.w;
        save_d6 = reg_d6.w;
        save_d7 = reg_d7.w;
        save_a0 = reg_a0;
        save_a1 = reg_a1;
        save_a2 = reg_a2;
        save_a3 = reg_a3;
        save_a4 = reg_a4;
        save_a5 = reg_a5;
        save_a6 = reg_a6;
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x60, 1, 1, 1);
        pause_menu_box_draw();
        pause_menu_items_draw();
        glyph_queue_clear();
        x = g_pause_menu_positions[0].x;
        y = g_pause_menu_positions[0].y;
        reg_a0 = (u8 *)g_menu_pause_items[0];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        x = g_pause_menu_positions[1].x;
        y = g_pause_menu_positions[1].y;
        reg_a0 = (u8 *)g_menu_pause_items[1];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        if (g_setting_screen_mode == 0) {
            reg_a0 = (u8 *)g_menu_monitor_mode_names[g_setting_screen_variant];
        } else {
            reg_a0 = (u8 *)g_menu_monitor_mode_tate_names[g_setting_screen_variant];
        }
        glyph_queue_add(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (g_pause_menu_cursor == 1) {
            menu_arrows_draw(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        x = g_pause_menu_positions[2].x;
        y = g_pause_menu_positions[2].y;
        reg_a0 = (u8 *)g_menu_pause_items[2];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        reg_a0 = (u8 *)D_0028DD18[g_pad_vib_enabled];
        glyph_queue_add(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (g_pause_menu_cursor == 2) {
            menu_arrows_draw(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        x = g_pause_menu_positions[3].x;
        y = g_pause_menu_positions[3].y;
        reg_a0 = (u8 *)g_menu_pause_items[3];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        reg_a0 = (u8 *)pause_menu_draw_table[g_setting_wallpaper];
        glyph_queue_add(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (g_pause_menu_cursor == 3) {
            menu_arrows_draw(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        x = g_pause_menu_positions[4].x;
        y = g_pause_menu_positions[4].y;
        reg_a0 = (u8 *)g_menu_pause_items[4];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        reg_a0 = (u8 *)D_0028DD18[g_stage_map_enabled];
        glyph_queue_add(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (g_pause_menu_cursor == 4) {
            menu_arrows_draw(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        reg_a0 = (u8 *)g_menu_pause_items[5];
        glyph_queue_add(g_pause_menu_positions[5].x, g_pause_menu_positions[5].y, 300, 0, 0x80, 0x80, 1);
        n = 6;
        if (g_simulation_active != 0) {
            n++;
            reg_a0 = (u8 *)g_menu_pause_items[6];
            glyph_queue_add(g_pause_menu_positions[6].x, g_pause_menu_positions[6].y, 300, 0, 0x80, 0x80, 1);
        }
        x = g_pause_menu_positions[n].x;
        reg_a0 = (u8 *)g_menu_pause_items[7];
        glyph_queue_add(x, g_pause_menu_positions[n].y, 300, 0, 0x80, 0x80, 1);
        glyph_queue_flush();
        reg_d0.w = save_d0;
        reg_d1.w = save_d1;
        reg_d2.w = save_d2;
        reg_d3.w = save_d3;
        reg_d4.w = save_d4;
        reg_d5.w = save_d5;
        reg_d6.w = save_d6;
        reg_d7.w = save_d7;
        reg_a0 = save_a0;
        reg_a1 = save_a1;
        reg_a2 = save_a2;
        reg_a3 = save_a3;
        reg_a4 = save_a4;
        reg_a5 = save_a5;
        reg_a6 = save_a6;
    }
}

extern u16 g_attract_step;

void pause_menu_quit_confirm(void) {
    extern void sfx_menu_confirm(void);
    if (g_attract_step == 1 || g_attract_step == 0xF) {
        return;
    }
    game_screen_teardown();
    sfx_menu_confirm();
    reg_d0.h[0] = TASK_ATTRACT;
    task_start();
    *(u16 *)(reg_a0 + 4) = 0x12;
}

s32 layers_reset();
s32 bg_scroll_reset();
s32 bg_layer_clear();
s32 layers_clear_all();
s32 fades_reset();
s32 sound_stop_effects();
s32 music_stop();
s32 stage_map_reset();
s32 replay_header_clear();
extern u8 D_0028E1DA[];
extern u8 D_0028E1E6[];
extern u8 g_replay_save_asked;
extern u8 g_replay_file_finalized;
extern s16 g_slowdown_loop2_allowed;
extern u16 g_select_screen_active;
extern u16 g_attract_demo;
extern u8 g_replay_save_prompt_active;
extern u8 g_game_over_after_continue;
extern u8 g_replay_begin_pending;
extern s32 g_replay_position;

void game_screen_teardown(void) {
    sound_stop_effects();
    music_stop();
    bg_scroll_reset();
    bg_layer_clear();
    layers_reset();
    g_attract_demo = 0;
    g_ranking_entry_index = 0xFF;
    g_stage_jump_state = 0xFF;
    g_paused = 0;
    g_replay_save_asked = 0;
    g_replay_file_finalized = 0;
    menu_settings_restore();
    g_simulation_active = 0;
    replay_header_clear();
    g_replay_mode = 0;
    g_replay_buffer_state = 0;
    g_replay_save_prompt_active = 0;
    g_replay_begin_pending = 0;
    g_game_over_after_continue = 0;
    g_replay_position = 0;
#ifndef DEATH_LABEL
    g_select_screen_active = 0;
#endif
    layers_clear_all();
    task_reset_all();
    fades_reset();
    stage_map_reset();
    g_loop = 0;
    D_0028E1DA[0] = 0;
    g_pause_loop_choice = 0;
    D_0028E1E6[0] = 0;
    g_slowdown_loop2_allowed = 0;
}

void menu_settings_restore(void) {
    g_setting_difficulty = g_menu_value_difficulty[0];
    g_setting_ship_stock = g_menu_value_ship_stock[0];
    g_setting_extend = g_menu_value_extend[0];
    g_setting_loop_count = g_menu_value_loop_count[0];
    g_setting_start_round = g_menu_value_start_round[0];
#ifndef DEATH_LABEL
    printf("restore com setting\n", g_menu_value_extend[0], g_menu_value_ship_stock[0], g_menu_value_difficulty[0]);
#endif
}

extern s32 g_frame_counter;

void menu_arrows_draw(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags) {
    extern s32 glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    u8 *text;
    s32 level;
    s32 alpha;

    text = reg_a0;
    level = (g_frame_counter & 0x3F) * 2;
    if (level < 0x3F) {
        level = 0x80 - level;
    }
    alpha = (arg5 * level) >> 7;
    if (flags & 1) {
        reg_a0 = (u8 *)g_menu_arrow_text[0];
        glyph_queue_add(arg0, arg1 - 8, arg2, arg3, arg4, alpha, arg6);
    }
    if (flags & 2) {
        reg_a0 = (u8 *)g_menu_arrow_text[1];
        glyph_queue_add(arg0, arg1 + strlen((const char *)text) * 8, arg2, arg3, arg4, alpha, arg6);
    }
    reg_a0 = text;
}

s32 display_set_offset();
void pause_screen_adjust_update(void) {
    s32 sfx_menu_confirm();
    s32 sfx_menu_tick();
    s32 temp_v1;

    temp_v1 = g_pad_trigger[g_pause_player];
    if (temp_v1 & 0x20) {
        sfx_menu_confirm();
        g_display_offset_x = g_menu_display_offset_x;
        g_display_offset_y = g_menu_display_offset_y;
        display_set_offset(g_display_offset_x, g_display_offset_y);
        g_menu_alpha = 0;
        g_paused = 3;
        g_menu_fade_state = 1;
        return;
    }
    if (temp_v1 & 0x40) {
        sfx_menu_confirm();
        display_set_offset(g_display_offset_x, g_display_offset_y);
        g_menu_alpha = 0;
        g_paused = 3;
        g_menu_fade_state = 1;
        return;
    }
    if (temp_v1 & 0x100) {
        sfx_menu_confirm();
        g_menu_display_offset_x = g_menu_display_offset_y = 0;
        display_set_offset(g_menu_display_offset_x, g_menu_display_offset_y);
    }
    if ((g_screen_mode != 2) && (g_screen_mode != 3)) {
        if ((g_pad_repeat[g_pause_player] & 0x4000) && (g_menu_display_offset_x > -8)) {
            sfx_menu_tick();
            g_menu_display_offset_x -= 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x1000) && (g_menu_display_offset_x < 8)) {
            sfx_menu_tick();
            g_menu_display_offset_x += 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x2000) && (g_menu_display_offset_y < 8)) {
            sfx_menu_tick();
            g_menu_display_offset_y += 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x8000) && (g_menu_display_offset_y > -8)) {
            sfx_menu_tick();
            g_menu_display_offset_y -= 1;
        }
    } else {
        if ((g_pad_repeat[g_pause_player] & 0x4000) && (g_menu_display_offset_y < 8)) {
            sfx_menu_tick();
            g_menu_display_offset_y += 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x1000) && (g_menu_display_offset_y > -8)) {
            sfx_menu_tick();
            g_menu_display_offset_y -= 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x2000) && (g_menu_display_offset_x < 8)) {
            sfx_menu_tick();
            g_menu_display_offset_x += 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x8000) && (g_menu_display_offset_x > -8)) {
            sfx_menu_tick();
            g_menu_display_offset_x -= 1;
        }
    }
    display_set_offset(g_menu_display_offset_x, g_menu_display_offset_y);
}

void menu_screen_adjust_page(void) {
    s32 sfx_menu_confirm();
    s32 sfx_menu_tick();
    if (g_pad_trigger[2] & 0x20) {
        sfx_menu_confirm();
        g_display_offset_x = g_menu_display_offset_x;
        g_display_offset_y = g_menu_display_offset_y;
        display_set_offset(g_display_offset_x, g_display_offset_y);
        g_menu_fade_state = 1;
        g_menu_alpha = 0;
        menu_items_place(0xF);
        g_menu_page = MENU_PAGE_SYSTEM_OPTION;
        g_menu_system_option_step = 3;
        g_menu_system_option_fade_state = 1;
        return;
    }
    if (g_pad_trigger[2] & 0x40) {
        sfx_menu_confirm();
        display_set_offset(g_display_offset_x, g_display_offset_y);
        g_menu_fade_state = 1;
        g_menu_alpha = 0;
        menu_items_place(0xF);
        g_menu_page = MENU_PAGE_SYSTEM_OPTION;
        g_menu_system_option_step = 3;
        g_menu_system_option_fade_state = 1;
        return;
    }
    if (g_pad_trigger[2] & 0x100) {
        sfx_menu_confirm();
        g_menu_display_offset_x = g_menu_display_offset_y = 0;
        display_set_offset(g_menu_display_offset_x, g_menu_display_offset_y);
    }
    if ((g_screen_mode != 2) && (g_screen_mode != 3)) {
        if ((g_pad_repeat[2] & 0x4000) && (g_menu_display_offset_x > -8)) {
            sfx_menu_tick();
            g_menu_display_offset_x -= 1;
        }
        if ((g_pad_repeat[2] & 0x1000) && (g_menu_display_offset_x < 8)) {
            sfx_menu_tick();
            g_menu_display_offset_x += 1;
        }
        if ((g_pad_repeat[2] & 0x2000) && (g_menu_display_offset_y < 8)) {
            sfx_menu_tick();
            g_menu_display_offset_y += 1;
        }
        if ((g_pad_repeat[2] & 0x8000) && (g_menu_display_offset_y > -8)) {
            sfx_menu_tick();
            g_menu_display_offset_y -= 1;
        }
    } else {
        if ((g_pad_repeat[2] & 0x4000) && (g_menu_display_offset_y < 8)) {
            sfx_menu_tick();
            g_menu_display_offset_y += 1;
        }
        if ((g_pad_repeat[2] & 0x1000) && (g_menu_display_offset_y > -8)) {
            sfx_menu_tick();
            g_menu_display_offset_y -= 1;
        }
        if ((g_pad_repeat[2] & 0x2000) && (g_menu_display_offset_x < 8)) {
            sfx_menu_tick();
            g_menu_display_offset_x += 1;
        }
        if ((g_pad_repeat[2] & 0x8000) && (g_menu_display_offset_x > -8)) {
            sfx_menu_tick();
            g_menu_display_offset_x -= 1;
        }
    }
    display_set_offset(g_menu_display_offset_x, g_menu_display_offset_y);
}

extern void *g_dma_gif;

void screen_adjust_frame_draw(void *buffer) {
    sceGifPacket packet;
    s32 i;
    u64 x;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 0, 1, 0x101, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, 0x80808080ULL | ((u64)0x3F800000 << 32));
    sceGifPkAddGsData(&packet, 1);
    sceGifPkAddGsData(&packet, 0x801CULL | ((u64)0x24000000 << 32));
    sceGifPkAddGsData(&packet, 0x55);
    for (i = 0; i < 0x1C0; i += 0x20) {
        x = (i + 0x700) << 4;
        sceGifPkAddGsData(&packet, x | 0x79000000);
        sceGifPkAddGsData(&packet, x | 0x87000000ULL);
    }
    for (i = 0; i < 0xE0; i += 0x10) {
        x = (u64)((i + 0x790) << 4) << 16;
        sceGifPkAddGsData(&packet, x | 0x7000);
        sceGifPkAddGsData(&packet, x | 0x8C00);
    }
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

extern void frame_draw_wide_left_panel(s32 alpha);
extern u8 g_gif_buf[2][0x10000];

void menu_screen_adjust_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern void glyph_queue_clear(void);
    extern void glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    extern void glyph_queue_flush(void);
    char buf[16];

    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x60, 1, 1, 1);
    screen_adjust_frame_draw(((u8 (*)[0x10000])g_gif_buf)[0]);
    text_queue_clear();
    frame_draw_wide_left_panel(0x80);
    gfx_draw_color_box(0xC, 8, 0x70, 0xD0, 0x12C, 0x40, 1, 1, 0x40);
    reg_a0 = (u8 *)g_menu_screen_adjust_help;
    menu_message_draw(0x62, 8);
    text_flush();
    sprintf(buf, "%3d,%d", g_menu_display_offset_x, g_menu_display_offset_y);
    reg_a0 = (u8 *)buf;
    glyph_queue_clear();
    glyph_queue_add(0xD8, 0x54, 0x12C, 0, 0x80, 0x80, 1);
    glyph_queue_flush();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

extern u8 g_disc_notice_kind;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern s8 g_disc_notice_step;

void disc_notice_begin(void) {
    g_disc_notice_step = 0;
    if (g_cd_async_state != 0) {
        sceCdBreak();
    }
    g_cd_async_state = 0;
    g_disc_notice_kind = 1;
    g_cd_async_busy = 1;
}


void disc_notice_begin_for_stage(void) {
    g_disc_notice_step = 0;
    if (g_cd_async_state != 0) {
        sceCdBreak();
    }
    g_cd_async_state = 0;
    g_disc_notice_kind = 2;
    g_cd_async_busy = 1;
}


void disc_notice_end(void) {
    g_disc_notice_step = 3;
}

extern u8 g_disc_notice_kind;
extern s16 disc_notice_draw_state;
extern s8 disc_notice_draw_state_2;

void disc_notice_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern void glyph_queue_clear(void);
    extern void glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    extern void glyph_queue_flush(void);
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    s32 x;
    s32 y;
    s32 alpha;

    if (g_disc_notice_kind != 0) {
        save_d0 = reg_d0.w;
        save_d1 = reg_d1.w;
        save_d2 = reg_d2.w;
        save_d3 = reg_d3.w;
        save_d4 = reg_d4.w;
        save_d5 = reg_d5.w;
        save_d6 = reg_d6.w;
        save_d7 = reg_d7.w;
        save_a0 = reg_a0;
        save_a1 = reg_a1;
        save_a2 = reg_a2;
        save_a3 = reg_a3;
        save_a4 = reg_a4;
        save_a5 = reg_a5;
        save_a6 = reg_a6;
        switch (g_disc_notice_step) {
        case 0:
            disc_notice_draw_state = 0;
            g_disc_notice_step++;
            disc_notice_draw_state_2 = 0;
        case 1:
            disc_notice_draw_state += 8;
            if (disc_notice_draw_state >= 0x80) {
                disc_notice_draw_state = 0x80;
                g_disc_notice_step++;
            }
            break;
        case 2:
            disc_notice_draw_state_2++;
            if (disc_notice_draw_state_2 >= 120) {
                disc_notice_draw_state_2 = 0;
            }
            break;
        case 3:
            disc_notice_draw_state -= 8;
            if (disc_notice_draw_state <= 0) {
                disc_notice_draw_state = 0;
                g_disc_notice_step++;
            }
            break;
        case 4:
            g_disc_notice_kind = 0;
            break;
        }
        alpha = disc_notice_draw_state;
        if (g_disc_notice_step < 3 && g_disc_notice_kind == 1) {
            gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x18F, 0x60, 1, 1, 1);
        }
        glyph_queue_clear();
        if (g_disc_notice_kind == 1) {
            x = 32;
            y = 104;
        } else {
            x = 96;
            y = 72;
        }
        reg_a0 = (u8 *)g_menu_now_loading_text;
        glyph_queue_add(x, y, 400, 0, 0x80, alpha, 1);
        if (disc_notice_draw_state_2 >= 30) {
            reg_a0 = (u8 *)g_menu_dot_text;
            y += 88;
            glyph_queue_add(x, y, 400, 0, 0x80, alpha, 1);
        }
        if (disc_notice_draw_state_2 >= 60) {
            reg_a0 = (u8 *)g_menu_dot_text;
            y += 8;
            glyph_queue_add(x, y, 400, 0, 0x80, alpha, 1);
        }
        if (disc_notice_draw_state_2 >= 90) {
            reg_a0 = (u8 *)g_menu_dot_text;
            glyph_queue_add(x, y + 8, 400, 0, 0x80, alpha, 1);
        }
        glyph_queue_flush();
        reg_d0.w = save_d0;
        reg_d1.w = save_d1;
        reg_d2.w = save_d2;
        reg_d3.w = save_d3;
        reg_d4.w = save_d4;
        reg_d5.w = save_d5;
        reg_d6.w = save_d6;
        reg_d7.w = save_d7;
        reg_a0 = save_a0;
        reg_a1 = save_a1;
        reg_a2 = save_a2;
        reg_a3 = save_a3;
        reg_a4 = save_a4;
        reg_a5 = save_a5;
        reg_a6 = save_a6;
    }
}

s32 mc_save_update();
s32 save_snapshot_take();
extern s32 menu_card_save_page_state;
extern s32 g_mc_operation_done;

void menu_card_save_page(void) {
    switch (g_menu_card_save_step) {                           /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        menu_card_save_page_state = 0;
        g_menu_card_save_step += 1;
        g_mc_operation_done = 0;
        /* fallthrough */
    case 1:                                         /* switch 1 */
        switch (menu_card_save_page_state) {                       /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            mc_save_update(0);
            if (g_mc_operation_done != 0) {
                save_snapshot_take();
                menu_card_save_page_state += 1;
                break;
            }
            break;
        case 1:                                     /* switch 2 */
            g_mc_operation_done = 0;
            g_menu_card_save_step += 1;
            break;
        }
        break;
    default:                                        /* switch 1 */
        g_menu_page = MENU_PAGE_SAVE_LOAD;
        break;
    }
}

s32 mc_load_update();
s32 save_block_to_settings();
extern s32 menu_card_load_page_state;
extern s32 g_mc_load_succeeded;

void menu_card_load_page(void) {
    switch (g_menu_card_load_step) {                           /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        menu_card_load_page_state = 0;
        g_menu_card_load_step += 1;
        g_mc_operation_done = 0;
        /* fallthrough */
    case 1:                                         /* switch 1 */
        switch (menu_card_load_page_state) {                       /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            mc_load_update(0);
            if (g_mc_operation_done != 0) {
                menu_card_load_page_state += 1;
                break;
            }
            break;
        case 1:                                     /* switch 2 */
            g_mc_operation_done = 0;
            if (g_mc_load_succeeded != 0) {
                save_block_to_settings(menu_card_load_page_state);
                save_snapshot_take();
            }
            g_menu_card_load_step += 1;
            break;
        }
        break;
    default:                                        /* switch 1 */
        g_menu_page = MENU_PAGE_SAVE_LOAD;
        break;
    }
}

extern s32 g_result_menu_box_fade_state;
extern s32 g_result_menu_box_alpha;
extern s8 g_result_menu_step;


void result_menu_reset(void) {
    g_result_menu_box_alpha = 0;
    g_result_menu_step = 1;
    g_result_menu_box_fade_state = 1;
    g_menu_fade_state = 1;
    g_menu_alpha = 0;
    g_menu_left_panel_alpha = 0;
    replay_slots_reset();
}

extern s8 g_result_menu_cursor;
void result_menu_input(void) {
    s32 sfx_menu_confirm();
    s32 sfx_menu_move();
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;

    temp_a1 = g_menu_pad * 4;
    temp_a0 = *(u32 *)((u8 *)g_pad_trigger + temp_a1);
    if (temp_a0 & 0x40) {
        g_result_menu_box_fade_state = 2;
        g_menu_fade_state = 2;
        g_result_menu_cursor = 2;
        g_result_menu_step += 1;
        sfx_menu_confirm();
        return;
    }
    if (temp_a0 & 0x20) {
        g_result_menu_box_fade_state = 2;
        sfx_menu_confirm();
        if (g_result_menu_cursor == 3) {
            g_result_menu_step = 0x40;
            return;
        }
        g_menu_fade_state = 2;
        g_result_menu_step += 1;
        return;
    }
    temp_a0_2 = *(u32 *)((u8 *)g_pad_repeat + temp_a1);
    if (temp_a0_2 & 0x1000) {
        sfx_menu_move();
        g_result_menu_cursor -= 1;
        if (0 >= g_result_menu_cursor) {
            g_result_menu_cursor = 2;
        }
    } else if (temp_a0_2 & 0x4000) {
        sfx_menu_move();
        g_result_menu_cursor += 1;
        if (g_result_menu_cursor >= 3) {
            g_result_menu_cursor = 1;
        }
    }
}

void result_menu_wait_faded(void) {
    if (g_result_menu_box_alpha == 0) {
        g_result_menu_step += 1;
    }
}


s8 result_menu_update(void) {
    s8 var_s0;

    var_s0 = 0;
    switch (g_result_menu_step) {
    default:
        if (g_result_menu_step != 0) {
            g_result_menu_step += 1;
        }
        break;
    case 0x1:
        result_menu_input();
        break;
    case 0x2:
        var_s0 = g_result_menu_cursor;
        g_result_menu_step += 1;
        break;
    case 0x3:
        result_menu_wait_faded();
        break;
    case 0x20:
        g_result_menu_step = 0;
        break;
    case 0x40:
        replay_slots_open(1, g_menu_pad, 0);
        g_result_menu_step += 1;
        break;
    case 0x41:
        switch (replay_slots_update()) {
        case 0:
            g_result_menu_step = 1;
            g_result_menu_box_fade_state = 1;
            break;
        }
        break;
    case 0x50:
        result_notice_update();
        break;
    case 0x51:
        g_result_menu_box_alpha = 0;
        g_result_menu_step = 1;
        g_result_menu_box_fade_state = 1;
        g_menu_fade_state = 1;
        g_menu_alpha = 0;
        g_menu_left_panel_alpha = 0;
        replay_slots_reset();
        break;
    }
    return var_s0;
}


void result_menu_box_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    s32 x;

    switch (g_result_menu_box_fade_state) {
    case 0:
        break;
    case 1:
        g_result_menu_box_alpha += 4;
        if (g_result_menu_box_alpha >= 0x40) {
            g_result_menu_box_fade_state = 0;
            g_result_menu_box_alpha = 0x3C;
        }
        break;
    case 2:
        g_result_menu_box_alpha -= 4;
        if (0 >= g_result_menu_box_alpha) {
            g_result_menu_box_alpha = 0;
            g_result_menu_box_fade_state = 0;
        }
        break;
    }
    x = g_menu_result_positions[g_result_menu_cursor].x;
    if (g_result_menu_box_alpha != 0) {
        gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, g_result_menu_box_alpha, 0xB4, 1, 1);
    }
}

void result_menu_items_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern void glyph_queue_clear(void);
    extern void glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    extern void glyph_queue_flush(void);
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    s32 alpha;
    s32 i;

    if (g_result_menu_step != 0) {
        save_d0 = reg_d0.w;
        save_d1 = reg_d1.w;
        save_d2 = reg_d2.w;
        save_d3 = reg_d3.w;
        save_d4 = reg_d4.w;
        save_d5 = reg_d5.w;
        save_d6 = reg_d6.w;
        save_d7 = reg_d7.w;
        save_a0 = reg_a0;
        save_a1 = reg_a1;
        save_a2 = reg_a2;
        save_a3 = reg_a3;
        save_a4 = reg_a4;
        save_a5 = reg_a5;
        save_a6 = reg_a6;
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x20, 1, 1, 1);
        if (g_result_menu_step == 0x50 || g_result_menu_step == 0x51) {
            menu_ranking_draw();
        } else {
            result_menu_box_draw();
            result_menu_draw();
            replay_slots_draw();
            glyph_queue_clear();
            alpha = g_result_menu_box_alpha * 2;
            for (i = 0; i < 3; i++) {
                reg_a0 = (u8 *)g_menu_result_items[i];
                glyph_queue_add(g_menu_result_positions[i].x, g_menu_result_positions[i].y, 0x12C, 0, 0x80, alpha, 1);
            }
            glyph_queue_flush();
        }
        reg_d0.w = save_d0;
        reg_d1.w = save_d1;
        reg_d2.w = save_d2;
        reg_d3.w = save_d3;
        reg_d4.w = save_d4;
        reg_d5.w = save_d5;
        reg_d6.w = save_d6;
        reg_d7.w = save_d7;
        reg_a0 = save_a0;
        reg_a1 = save_a1;
        reg_a2 = save_a2;
        reg_a3 = save_a3;
        reg_a4 = save_a4;
        reg_a5 = save_a5;
        reg_a6 = save_a6;
    }
}


void result_menu_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    s32 alpha;

    switch (g_menu_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_alpha += 4;
        if (g_menu_alpha >= 0x80) {
            g_menu_fade_state = 0;
            g_menu_alpha = 0x80;
        }
        break;
    case 2:
        g_menu_alpha -= 4;
        if (g_menu_alpha <= 0) {
            g_menu_alpha = 0;
            g_menu_fade_state = 0;
        }
        break;
    }
    if (g_menu_alpha != 0) {
        text_queue_clear();
        alpha = g_menu_alpha;
        if (g_menu_alpha >= 0x40) {
            alpha = 0x40;
        }
        if (alpha != 0) {
            frame_draw_left_panel(g_menu_alpha);
            gfx_draw_color_box(0xC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        if (g_result_menu_step >= 0x40) {
            if ((u8)g_replay_slots_state != 0 && (u32)((u8)g_replay_slots_state - 1) > 1 && (u32)((u8)g_replay_slots_state - 5) > 1) {
                reg_a0 = (u8 *)g_menu_save_file_help;
                menu_message_draw(0x36, 8);
            }
        } else {
            reg_a0 = (u8 *)g_menu_result_help[g_result_menu_cursor];
            menu_message_draw(0x36, 8);
        }
        text_flush();
    }
}

/* .sbss (the compiler lays these out in reverse) */
s32 g_menu_card_save_step;
s32 g_menu_card_load_step;
#ifdef DEATH_LABEL
u8 death_D_00290DC0 __attribute__((aligned(4)));
u8 death_D_00290DBC;
u32 death_D_00290DB8;
u32 death_D_00290DB4;
#endif
s8 g_disc_notice_step __attribute__((aligned(4)));
s8 disc_notice_draw_state_2 __attribute__((aligned(4)));
s16 disc_notice_draw_state __attribute__((aligned(4)));
s8 g_stage_load_finished __attribute__((aligned(4)));
#ifndef DEATH_LABEL
u8 settings_reset_state_5;
#endif
s32 g_replay_save_prompt_step;
u8 g_replay_save_prompt_active;
s32 g_replay_slots_alpha;
s8 g_replay_slots_fade __attribute__((aligned(4)));
s8 g_replay_slots_cursor __attribute__((aligned(4)));
s8 g_replay_slots_state __attribute__((aligned(4)));
u8 g_replay_slots_step __attribute__((aligned(4)));
u8 g_replay_slots_pad __attribute__((aligned(4)));
u8 g_replay_slots_from_disc __attribute__((aligned(4)));
s8 g_replay_slots_saving __attribute__((aligned(4)));
s8 g_replay_slot_loaded __attribute__((aligned(4)));
s8 g_menu_pad __attribute__((aligned(4)));
s8 g_menu_replay_chosen;
MenuPage g_menu_simulation;
MenuPage g_menu_sim_setting;
MenuPage g_menu_sim_player;
MenuPage g_menu_sim_rules;
MenuPage g_menu_sim_param;
MenuPage g_menu_stage_difficulty;
MenuPage g_menu_stage_select;
MenuPage g_menu_file_select;
MenuPage g_menu_practice_ranking;
s8 g_pause_menu_cursor __attribute__((aligned(4)));
u8 g_pause_box_fade_state __attribute__((aligned(4)));
s16 g_pause_box_alpha __attribute__((aligned(4)));
s8 g_pause_confirm_cursor __attribute__((aligned(4)));
s8 g_pause_item_shrink __attribute__((aligned(4)));
u8 g_pause_input_delay;
s32 menu_reset_state;
s32 g_menu_main_alpha;
s32 g_menu_game_option_alpha;
s32 g_menu_save_load_alpha;
s32 g_menu_debug_option_alpha;
s32 g_menu_arcade_alpha;
s32 g_menu_system_option_alpha;
s32 g_menu_ranking_alpha;
s32 g_menu_alpha_a;
#ifdef DEATH_LABEL
s32 death_D_00290CE4;
#endif
s32 g_menu_alpha_b;
s32 g_menu_alpha;
s32 g_menu_left_panel_alpha;
s8 g_menu_task_phase __attribute__((aligned(4)));
s8 g_menu_page __attribute__((aligned(4)));
s8 g_menu_main_unread_flag __attribute__((aligned(4)));
s8 g_menu_main_step __attribute__((aligned(4)));
s8 g_menu_game_option_step __attribute__((aligned(4)));
s8 g_menu_save_load_step __attribute__((aligned(4)));
s8 g_menu_debug_option_step __attribute__((aligned(4)));
s8 g_menu_arcade_step __attribute__((aligned(4)));
s8 g_menu_system_option_step __attribute__((aligned(4)));
s8 g_result_notice_step __attribute__((aligned(4)));
s8 g_menu_launch_step __attribute__((aligned(4)));
#ifdef DEATH_LABEL
s8 death_D_00290CA8 __attribute__((aligned(4)));
#endif
s8 g_menu_ranking_step __attribute__((aligned(4)));
s8 g_menu_cursor __attribute__((aligned(4)));
s8 g_menu_box_fade_state __attribute__((aligned(4)));
s8 g_menu_box_alpha __attribute__((aligned(4)));
s8 g_menu_main_fade_state __attribute__((aligned(4)));
s8 g_menu_game_option_fade_state __attribute__((aligned(4)));
s8 g_menu_save_load_fade_state __attribute__((aligned(4)));
s8 g_menu_debug_option_fade_state __attribute__((aligned(4)));
s8 g_menu_arcade_fade_state __attribute__((aligned(4)));
s8 g_menu_system_option_fade_state __attribute__((aligned(4)));
s8 g_result_notice_state __attribute__((aligned(4)));
s8 g_menu_alpha_a_fade_state __attribute__((aligned(4)));
#ifdef DEATH_LABEL
s8 death_D_00290C74 __attribute__((aligned(4)));
#endif
s8 g_menu_alpha_b_fade_state __attribute__((aligned(4)));
s8 g_menu_main_cursor __attribute__((aligned(4)));
s8 g_menu_game_option_cursor __attribute__((aligned(4)));
s8 g_menu_save_load_cursor __attribute__((aligned(4)));
s8 g_menu_debug_option_cursor __attribute__((aligned(4)));
s8 g_menu_arcade_cursor __attribute__((aligned(4)));
s8 g_menu_system_option_cursor __attribute__((aligned(4)));
s8 g_result_notice_unread_flag __attribute__((aligned(4)));
s8 g_menu_launch_cursor __attribute__((aligned(4)));
#ifdef DEATH_LABEL
s8 death_D_00290C4C __attribute__((aligned(4)));
#endif
s8 g_menu_ranking_cursor __attribute__((aligned(4)));
s8 g_menu_fade_state __attribute__((aligned(4)));
s8 g_menu_exit_code;
s32 g_ranking_entry_index;
s32 g_menu_notice_step;
s32 g_menu_ranking_state_b;
s32 g_menu_ranking_state_a;
s32 g_menu_notice_alpha;
s8 g_menu_launch_kind __attribute__((aligned(4)));
s8 g_menu_display_offset_x __attribute__((aligned(4)));
s8 g_menu_display_offset_y __attribute__((aligned(4)));
s8 result_notice_slide_state;
s32 menu_ranking_scores_format_state;
s32 menu_card_save_page_state;
s32 menu_card_load_page_state;
s8 g_result_menu_step __attribute__((aligned(4)));
s8 g_result_menu_cursor;
s32 g_result_menu_box_alpha;
s32 g_result_menu_box_fade_state;
s32 replay_slots_card_save_state;
u8 replay_save_prompt_update_disc_state __attribute__((aligned(4)));
u8 g_replay_disc_load_step __attribute__((aligned(4)));
u8 g_replay_disc_load_slot;
u8 *g_replay_disc_load_buf;
#ifndef DEATH_LABEL
s8 g_menu_launch_choice __attribute__((aligned(4)));
#endif

char *g_menu_result_items[3] = {
    "RESULT MENU",
    "RETRY",
    "QUIT",
};

#ifdef DEATH_LABEL
char *g_menu_result_help[3] = {
    SJIS("￥"),
    SJIS("最初からやり直します。￥"),
    SJIS("ゲームを終了して／ステージセレクト画面へ／戻ります。￥"),
};
#else
char *g_menu_result_help[3] = {
    SJIS("￥"),
    SJIS("ステージの最初から／やり直します。￥"),
    SJIS("ゲームを終了して／ステージセレクト画面へ／戻ります。￥"),
};
#endif

Point16 g_menu_result_positions[8] = {
    { 0x18c, 8 },
    { 0x164, 8 },
    { 0x14c, 8 },
    { 0x134, 8 },
    { 0x11c, 8 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
};

#ifdef DEATH_LABEL
char *g_menu_save_file_help = SJIS("セーブするファイルを選択／して下さい。／      ○決定  ×戻る￥");
#else
char *g_menu_save_file_help = SJIS("セーブするファイルを／選択して下さい。／      ○決定  ×戻る￥");
#endif

/* The replay slot screens. */

extern u8 g_replay_slots_from_disc;

s32 replay_slots_update(void) {
    if (g_replay_slots_from_disc == 0) {
        switch ((u8)g_replay_slots_state) {
        case 0:
            return 0;
        case 1:
            replay_slots_start();
            break;
        case 2:
            replay_slots_card_scan_wait();
            break;
        case 3:
            replay_slots_card_ready();
            break;
        case 4:
            replay_slots_card_select();
            break;
        case 5:
            return replay_slots_card_save();
        case 6:
            return replay_slots_card_load();
        case 7:
            replay_slots_closing();
            break;
        }
    } else {
        switch ((u8)g_replay_slots_state) {
        case 0:
            return 0;
        case 1:
            replay_slots_start();
            break;
        case 2:
            replay_slots_disc_scan();
            break;
        case 3:
            replay_slots_disc_ready();
            break;
        case 4:
            replay_slots_disc_select();
            break;
        case 5:
            printf("program error\n");
            break;
        case 6:
            return replay_slots_disc_load();
        case 7:
            replay_slots_closing();
            break;
        }
    }
    return 1;
}

extern s8 g_replay_slots_state;
extern s8 g_replay_slots_fade;
extern s32 g_replay_slots_alpha;

void replay_slots_reset(void) {
    g_replay_slots_alpha = 0;
    g_replay_slots_fade = 0;
    g_replay_slots_state = 0;
}

extern s8 g_replay_slots_saving;

void replay_slots_open(s8 arg0, s8 arg1, s8 arg2) {
    g_replay_slots_pad = arg1;
    g_replay_slots_saving = arg0;
    g_replay_slots_state = 1;
    g_replay_slots_from_disc = arg2;
}

void replay_slots_close(void) {
    g_replay_slots_state = 7;
    g_replay_slots_fade = 2;
}

s32 replay_slot_infos_clear();                            /* extern */
extern s32 g_memcard_watch_step;

void replay_slots_card_scan_begin(void) {
    g_memcard_watch_step = 0;
    replay_slot_infos_clear();
    g_replay_slots_state = 2;
}

extern s8 g_replay_slots_cursor;


void replay_slots_start(void) {
    g_replay_slots_alpha = 0;
    g_replay_slots_fade = 0;
    g_replay_slots_cursor = 0;
    replay_slots_card_scan_begin();
}

s32 memcard_watch_update();                                /* extern */
extern s8 g_menu_fade_state;
extern s32 g_menu_alpha;

void replay_slots_card_scan_wait(void) {
    if (memcard_watch_update() != 0) {
        g_replay_slots_state = 3;
        g_replay_slots_fade = 1;
        g_menu_alpha = 0x40;
        g_menu_fade_state = 1;
    }
}

s32 memcard_watch_update();                                /* extern */

void replay_slots_card_ready(void) {
    if (memcard_watch_update() == 0) {
        replay_slots_card_scan_begin();
        return;
    }
    g_replay_slots_state = 4;
}

s32 sfx_menu_confirm();
s32 sfx_menu_move();
s32 memcard_watch_update();
extern u8 g_replay_slots_pad;
extern u8 g_replay_slot_infos[];
void replay_slots_card_select(void) {
    s32 temp_a0;
    s32 temp_a0_3;
    u16 temp_a0_2;

    if (memcard_watch_update() == 0) {
        replay_slots_card_scan_begin();
        return;
    }
    temp_a0 = g_pad_trigger[g_replay_slots_pad];
    if (temp_a0 & 0x40) {
        sfx_menu_confirm();
        replay_slots_close();
    } else if (temp_a0 & 0x20) {
        g_replay_slots_step = 0;
        if (g_replay_slots_saving == 1) {
            g_replay_slots_state = 5;
            sfx_menu_confirm();
        } else {
            temp_a0_2 = *(u16 *)(g_replay_slot_infos + (g_replay_slots_cursor << 0xA));
            if ((temp_a0_2 != 0) && (temp_a0_2 != 3)) {
                g_replay_slots_state = 6;
                sfx_menu_confirm();
            }
        }
    }
    temp_a0_3 = g_pad_repeat[g_replay_slots_pad];
    if (temp_a0_3 & 0x1000) {
        sfx_menu_move();
        g_replay_slots_cursor -= 1;
        if (0 > g_replay_slots_cursor) {
            g_replay_slots_cursor = 9;
        }
    } else if (temp_a0_3 & 0x4000) {
        sfx_menu_move();
        g_replay_slots_cursor += 1;
        if (g_replay_slots_cursor >= 0xA) {
            g_replay_slots_cursor = 0;
        }
    }
}

s32 mc_replay_save_begin();
s32 memcard_watch_recheck();
s32 replay_slot_info_fill();
extern s32 replay_slots_card_save_state;
extern u8 g_replay_slots_step;
extern s32 g_mc_save_succeeded;
extern s32 g_mc_operation_done;

s32 replay_slots_card_save(void) {
    switch (g_replay_slots_step) {
    case 0:
        g_mc_operation_done = 0;
        g_replay_slots_step += 1;
    case 1:
        mc_replay_save_begin(g_replay_slots_cursor + 1);
        if (g_mc_operation_done != 0) {
            memcard_watch_recheck();
            g_mc_operation_done = 0;
            g_memcard_watch_step = 0;
            g_replay_slots_step += 1;
            replay_slots_card_save_state = g_mc_save_succeeded;
            if (g_mc_save_succeeded != 0) {
                replay_slot_info_fill(g_replay_slots_cursor);
            }
        }
        break;
    case 2:
        if (memcard_watch_update() != 0) {
            g_menu_fade_state = 1;
            g_menu_alpha = 0x40;
            g_replay_slots_state = 4;
            g_replay_slots_step = 0;
            if (replay_slots_card_save_state != 0) {
                return 2;
            }
        }
        break;
    }
    return 1;
}

s32 mc_replay_load_begin(s32);                         /* extern */
s32 memcard_watch_recheck();                            /* extern */
s32 replay_file_pointers_decode(s32 *);                   /* extern */
extern s8 g_replay_slot_loaded;
extern s32 g_mc_load_succeeded;
extern u8 g_loaded_replay_id_0;
extern u8 g_loaded_replay_id_1;
extern u8 g_loaded_replay_id_2;
extern u8 g_loaded_replay_id_3;
extern u8 g_loaded_replay_id_4;
extern u8 g_loaded_replay_id_5;
extern u8 g_loaded_replay_id_6;
extern u8 g_loaded_replay_id_7;
extern u8 g_replay_file_loaded[];
extern u8 g_replay_file[];
extern u8 g_replay_file_id_0[];
extern u8 g_replay_file_id_1[];
extern u8 g_replay_file_id_2[];
extern u8 g_replay_file_id_3[];
extern u8 g_replay_file_id_4[];
extern u8 g_replay_file_id_5[];
extern u8 g_replay_file_id_6[];
extern u8 g_replay_file_id_7[];
extern u8 g_replay_snapshot[];

s32 replay_slots_card_load(void) {
    switch (g_replay_slots_step) {                           /* irregular */
    case 0:
        g_mc_operation_done = 0;
        g_replay_slots_step += 1;
        /* fallthrough */
    case 1:
        mc_replay_load_begin(g_replay_slots_cursor + 1);
        if (g_mc_operation_done != 0) {
            memcard_watch_recheck();
            g_replay_slots_state = 4;
            g_mc_operation_done = 0;
            g_menu_fade_state = 1;
            g_replay_slots_step = 0;
            g_menu_alpha = 0x40;
            g_replay_slot_loaded = g_replay_slots_cursor;
            if (g_mc_load_succeeded != 0) {
                memcpy(((s32 *)g_replay_file), ((s32 *)g_replay_file_loaded), 0x202E8);
                delta_encode((u8 *)((s32 *)g_replay_snapshot));
                replay_file_pointers_decode(((s32 *)g_replay_file));
                g_loaded_replay_id_0 = g_replay_file_id_0[0];
                g_loaded_replay_id_1 = g_replay_file_id_1[0];
                g_loaded_replay_id_2 = g_replay_file_id_2[0];
                g_loaded_replay_id_3 = g_replay_file_id_3[0];
                g_loaded_replay_id_4 = g_replay_file_id_4[0];
                g_loaded_replay_id_5 = g_replay_file_id_5[0];
                g_loaded_replay_id_6 = g_replay_file_id_6[0];
                g_loaded_replay_id_7 = g_replay_file_id_7[0];
                return 3;
            }
        }
    default:
        return 1;
    }
}

#ifdef DEATH_LABEL
void delta_encode(u8 *buf) {
    u8 prev;
    u8 cur;
    s32 i;

    prev = buf[0];
    for (i = 1; i < 0x5533; i++) {
        cur = buf[i];
        buf[i] = (s8)cur - (s8)prev;
        prev = cur;
    }
}
#endif

const s32 g_replay_slot_layout[14] = {
    17, 12, 17, 58, 9, 58, 17, 120, 17, 168, 9, 120, 9, 168,
};

char *g_replay_slot_ship_names[2] = {
    "ATYPE",
    "BTYPE",
};

char *g_replay_slot_shot_names[4] = {
    "",
    "SHOT",
    "LASER",
    "EXPERT",
};

char *g_replay_slot_difficulty_names[4] = {
    "EASY",
    "NORMAL",
    "HARD",
    "V-HARD",
};

/* Save data. */

extern s8 g_replay_slots_state;
extern s32 g_replay_slots_alpha;

void replay_slots_closing(void) {
    if (g_replay_slots_alpha == 0) {
        g_replay_slots_state = 0;
    }
}

extern s8 g_menu_fade_state;
extern s32 g_menu_alpha;
extern s8 g_replay_slots_fade;

void replay_slots_disc_scan(void) {
    if (replay_disc_headers_load() != 0) {
        g_replay_slots_state = 3;
        g_replay_slots_fade = 1;
        g_menu_alpha = 0x40;
        g_menu_fade_state = 1;
    }
}


void replay_slots_disc_ready(void) {
    g_replay_slots_state = 4;
}

s32 sfx_menu_move();
extern u8 g_replay_slots_pad;
extern s8 g_replay_slots_cursor;
extern u8 g_replay_slot_infos[];
void replay_slots_disc_select(void) {
    s32 sfx_menu_confirm();
    s32 temp_a0;
    s32 temp_a0_3;
    u16 temp_a0_2;

    temp_a0 = g_pad_trigger[g_replay_slots_pad];
    if (temp_a0 & 0x40) {
        sfx_menu_confirm();
        replay_slots_close();
    } else if (temp_a0 & 0x20) {
        temp_a0_2 = *(u16 *)(g_replay_slot_infos + (g_replay_slots_cursor << 0xA));
        if ((temp_a0_2 != 0) && (temp_a0_2 != 3)) {
            g_replay_slots_state = 6;
            sfx_menu_confirm();
        }
    }
    temp_a0_3 = g_pad_repeat[g_replay_slots_pad];
    if (temp_a0_3 & 0x1000) {
        sfx_menu_move();
        g_replay_slots_cursor -= 1;
        if (0 > g_replay_slots_cursor) {
            g_replay_slots_cursor = 9;
        }
    } else if (temp_a0_3 & 0x4000) {
        sfx_menu_move();
        g_replay_slots_cursor += 1;
        if (g_replay_slots_cursor >= 0xA) {
            g_replay_slots_cursor = 0;
        }
    }
}

extern s8 g_replay_slot_loaded;
extern u8 g_loaded_replay_id_0;
extern u8 g_loaded_replay_id_1;
extern u8 g_loaded_replay_id_2;
extern u8 g_loaded_replay_id_3;
extern u8 g_loaded_replay_id_4;
extern u8 g_loaded_replay_id_5;
extern u8 g_loaded_replay_id_6;
extern u8 g_loaded_replay_id_7;
extern u8 g_replay_file_loaded[];
extern u8 g_replay_file[];
extern u8 g_replay_file_id_0[];
extern u8 g_replay_file_id_1[];
extern u8 g_replay_file_id_2[];
extern u8 g_replay_file_id_3[];
extern u8 g_replay_file_id_4[];
extern u8 g_replay_file_id_5[];
extern u8 g_replay_file_id_6[];
extern u8 g_replay_file_id_7[];
extern u8 g_replay_snapshot[];
s32 replay_slots_disc_load(void) {
    s32 replay_file_pointers_decode();
    if (replay_disc_file_load((u8)g_replay_slots_cursor) != 0) {
        g_replay_slot_loaded = *(s8 *)&(*(u8 *)&g_replay_slots_cursor);
        g_menu_fade_state = 1;
        g_menu_alpha = 0x40;
        memcpy(g_replay_file, g_replay_file_loaded, 0x202E8);
        delta_encode(g_replay_snapshot);
        replay_file_pointers_decode(g_replay_file);
        g_loaded_replay_id_0 = g_replay_file_id_0[0];
        g_loaded_replay_id_1 = g_replay_file_id_1[0];
        g_loaded_replay_id_2 = g_replay_file_id_2[0];
        g_loaded_replay_id_3 = g_replay_file_id_3[0];
        g_loaded_replay_id_4 = g_replay_file_id_4[0];
        g_loaded_replay_id_5 = g_replay_file_id_5[0];
        g_loaded_replay_id_6 = g_replay_file_id_6[0];
        g_loaded_replay_id_7 = g_replay_file_id_7[0];
        return 3;
    }
    return 1;
}


extern s32 sprintf(char *buf, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern void frame_draw_column(s32 x, s32 y, s32 alpha);
extern void glyph_queue_clear(void);
extern void glyph_queue_flush(void);

void replay_slot_draw(s32 slot, s32 x, s32 y, s32 alpha, s32 selected, SaveInfo *info) {
    extern void text_queue_clear(void);
    extern void text_flush(void);
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 alpha, s32 attr, s32 wide);
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    char buf[16];
    u32 save_d6;
    u32 save_d7;
    s32 a;
    s32 b;
    s32 fade;

    if (alpha == 0) {
        return;
    }
    save_d0 = reg_d0.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    text_queue_clear();
    frame_draw_column(x, y, alpha);
    if (selected != 0) {
        gfx_draw_color_box(x + 8, y + 8, 0x1A, 0xD0, 0x12C, alpha, 0xFF, 1, 1);
    } else {
        fade = alpha >= 0x40 ? 0x40 : alpha;
        gfx_draw_color_box(x + 8, y + 8, 0x1A, 0xD0, 0x12C, fade, 1, 1, 0x40);
    }
    text_flush();
    glyph_queue_clear();
    reg_a0 = (u8 *)buf;
    a = info->f04;
    if (a != 0xFF) {
        b = info->f02;
    } else {
        b = info->f06;
        a = info->f08;
    }
    sprintf(buf, "NO.%02d", slot + 1);
    glyph_queue_add(x + g_replay_slot_layout[0], y + g_replay_slot_layout[1], 0x12C, 0, 0x80, alpha, 1);
    switch (info->status) {
    case 0:
        strcpy(buf, (char *)"NO DATA");
        glyph_queue_add(x + g_replay_slot_layout[0], y + g_replay_slot_layout[1] + 0x60, 0x12C, 0, 0x80, alpha, 1);
        break;
    case 2:
        strcpy(buf, (char *)"BROKEN DATA");
        glyph_queue_add(x + g_replay_slot_layout[0], y + g_replay_slot_layout[1] + 0x60, 0x12C, 0, 0x80, alpha, 1);
        break;
    case 3:
        strcpy(buf, (char *)"VERSION ERR");
        glyph_queue_add(x + g_replay_slot_layout[0], y + g_replay_slot_layout[1] + 0x60, 0x12C, 0, 0x80, alpha, 1);
        break;
    default:
        sprintf(buf, "STG %d-%d", info->f0C + 1, info->f0E + 1);
        glyph_queue_add(x + g_replay_slot_layout[2], y + g_replay_slot_layout[3], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, "%s", g_replay_slot_difficulty_names[info->f0A]);
        glyph_queue_add(x + g_replay_slot_layout[4], y + g_replay_slot_layout[5], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, "%s", g_replay_slot_ship_names[b / 2]);
        glyph_queue_add(x + g_replay_slot_layout[6], y + g_replay_slot_layout[7], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, "%s", g_replay_slot_shot_names[a / 2]);
        glyph_queue_add(x + g_replay_slot_layout[8], y + g_replay_slot_layout[9], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, "%2d/%d", info->f38, info->f39);
        glyph_queue_add(x + g_replay_slot_layout[10], y + g_replay_slot_layout[11], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, "%2d:%02d", info->f3A, info->f3B);
        glyph_queue_add(x + g_replay_slot_layout[12], y + g_replay_slot_layout[13], 0x12C, 0, 0x80, alpha, 0);
        break;
    }
    glyph_queue_flush();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}


s32 replay_slots_draw(void) {
    s32 i;
    s32 y;

    if ((u8)g_replay_slots_state == 0) {
        return 0;
    }
    switch ((u8)g_replay_slots_fade) {
    case 0:
        break;
    case 1:
        g_replay_slots_alpha += 4;
        if (g_replay_slots_alpha >= 0x80) {
            g_replay_slots_fade = 0;
            g_replay_slots_alpha = 0x80;
        }
        break;
    case 2:
        g_replay_slots_alpha -= 4;
        if (0 >= g_replay_slots_alpha) {
            g_replay_slots_alpha = 0;
            g_replay_slots_fade = 0;
        }
        break;
    }
    if (0 < g_replay_slots_alpha) {
        y = 0x18A;
        for (i = 0; i < 10; i++) {
            replay_slot_draw(i, y, 0, g_replay_slots_alpha, (i == g_replay_slots_cursor) ? 1 : 0, (SaveInfo *)((u8 (*)[0x400])g_replay_slot_infos)[i]);
            y -= 0x22;
        }
    }
    return 1;
}

s32 fade_start_in();
extern s8 g_menu_page;
extern u8 D_0068DEC8[];
extern u8 D_0068DED8[];
extern u8 D_0068DEF0[];
void menu_reset_keep_sim_rules(void) {
    u8 sp10[0x16];
    u8 sp30[0xA];
    u8 sp40[0xC];

    memcpy(sp10, D_0068DEF0, 0x16);
    memcpy(sp30, D_0068DED8, 0xA);
    memcpy(sp40, D_0068DEC8, 0xC);
    menu_reset();
    menu_settings_restore();
    memcpy(D_0068DEF0, sp10, 0x16);
    memcpy(D_0068DED8, sp30, 0xA);
    memcpy(D_0068DEC8, sp40, 0xC);
    g_menu_stage_select.step = 0;
    g_menu_page = MENU_PAGE_STAGE_SELECT;
    fade_start_in();
}
extern u8 g_replay_slots_from_disc;
void menu_reset_keep_sim_rules_and_page(void) {
    u8 sp10[0x16];
    u8 sp30[0xA];
    u8 sp40[0xC];

    memcpy(sp10, D_0068DEF0, 0x16);
    memcpy(sp30, D_0068DED8, 0xA);
    memcpy(sp40, D_0068DEC8, 0xC);
    menu_reset();
    menu_settings_restore();
    memcpy(D_0068DEF0, sp10, 0x16);
    memcpy(D_0068DED8, sp30, 0xA);
    memcpy(D_0068DEC8, sp40, 0xC);
    if (g_replay_slots_from_disc == 0) {
        g_menu_file_select.step = 0;
        g_menu_page = MENU_PAGE_REPLAY;
        menu_file_select_step0();
    } else {
        g_menu_file_select.step = 0;
        g_menu_page = MENU_PAGE_SUPER_REPLAY;
        menu_super_replay_step0();
    }
    while (g_menu_file_select.step != 2) {
        menu_file_select_step1();
    }
    fade_start_in();
}

s32 fade_start_out();                            /* extern */
extern s8 g_result_menu_cursor;
extern s8 g_menu_exit_code;
extern s8 g_menu_box_fade_state;
extern s8 g_menu_task_phase;

void menu_close_begin(void) {
    g_menu_box_fade_state = 2;
    g_menu_exit_code = 3;
    g_menu_task_phase = 2;
    g_menu_page = MENU_PAGE_MAIN;
    fade_start_out();
    g_result_menu_cursor = 1;
}


extern s8 g_menu_cursor;
extern s8 g_menu_box_alpha;
extern s8 D_002714F7[];
extern s8 g_menu_main_fade_state;
extern s8 g_menu_main_step;
extern s8 g_menu_pad;
extern s32 g_autosave_step;
s32 autosave_update();
extern s16 D_0068DF02[];
extern s16 D_00270822[];
extern s8 D_002714FA[];
extern u8 g_stage_select_unlocked;
extern u8 g_stage_select_choice;
extern s8 g_menu_replay_chosen;
extern s16 D_00270828[];
extern s16 D_00270838[];
extern s16 D_0068DECA[];
extern s16 D_0068DECC[];
extern s16 D_0068DECE[];
extern s16 D_0068DED0[];
extern s16 D_0068DED2[];
extern s16 D_0068DEDA[];
extern s16 D_0068DEDC[];
extern s16 D_0068DEDE[];
extern s16 D_0068DEE0[];
extern s16 D_0068DEF0_as_s16_a[];
extern s16 D_0068DEF2[];
extern s16 D_0068DEF4[];
extern s16 D_0068DEF6[];
extern s16 D_0068DEF8[];
extern s16 D_0068DEFA[];
extern s16 D_0068DEFC[];
extern s16 D_0068DEFE[];
extern s16 D_0068DF00[];
extern s16 D_0068DF04[];
extern u16 D_006C58A2[];
extern u16 D_006C58A4[];
extern u16 D_006C58A6[];
extern u16 D_006C58A8[];
extern u16 D_006C58AA[];
extern u16 D_006C58B0[];
extern u16 D_006C58B2[];
extern u16 D_006C58B4[];
extern u16 D_006C58B6[];
extern u16 D_006C58B8[];
extern u16 D_006C58BA[];
extern u16 D_006C58BC[];
extern u16 D_006C58BE[];
extern u16 D_006C58C0[];
extern u16 D_006C58C2[];
extern u16 D_006C58C6[];
extern u16 D_006C58C8[];
extern u16 D_006C58CA[];
extern u16 D_006C58CC[];
extern u16 D_006C58CE[];
extern u16 D_006C58D0[];
extern u16 D_006C58D2[];
extern u16 D_006C58D4[];
extern s8 D_002714F8[];
extern s8 D_00271501[];
extern s8 D_00271502[];
extern s8 D_00271503[];
extern s8 D_002714FD[];
extern u8 D_00684CA0[];

static void menu_page_enter(MenuPage *fade) {
    g_menu_idle_timer = 0xE10;
    fade->alpha = 0x40;
    fade->state = 1;
    fade->step += 1;
    fade->cursor = 1;
    g_menu_alpha = 0x40;
    g_menu_fade_state = 1;
    g_menu_box_fade_state = 0;
    g_menu_box_alpha = 0;
}

s32 menu_simulation_slide_in_step(MenuPage *fade, s32 command) {
    if (menu_items_slide_update(command) != 0) {
        fade->step += 1;
        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        g_menu_box_fade_state = 1;
        g_menu_fade_state = 1;
        return 1;
    }
    return 0;
}

static s32 menu_page_advance(MenuPage *fade, s32 command) {
    fade->step += 1;
    g_menu_cursor = 1;
    g_menu_alpha = 0x40;
    g_menu_box_fade_state = 1;
    g_menu_fade_state = 1;
    return 1;
}

void menu_idle_cancel(void) {
    g_menu_idle_timer = 0xE10;
    if (g_pad_trigger[2] == 0) {
        (*(u16 *)&g_menu_idle_timer) -= 1;
        if ((u16)g_menu_idle_timer == 0) {
            g_pad_trigger[1] = 0x40;
            g_pad_trigger[0] = 0x40;
            g_pad_trigger[2] = 0x40;
        }
    } else {
        g_menu_idle_timer = 0xE10;
    }
}

static void menu_page_fade(MenuPage *fade) {
    switch (fade->state) {
    case 0:
        break;
    case 1:
        fade->alpha += 4;
        if (fade->alpha >= 0x80) {
            fade->alpha = 0x80;
            fade->state = 0;
        }
        break;
    case 2:
        fade->alpha -= 4;
        if (0 >= fade->alpha) {
            fade->alpha = 0;
            fade->state = 0;
        }
        break;
    }
}

void menu_simulation_items_draw(MenuPage *arg0, u8 **arg1, s32 arg2) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 count;
    s32 i;
    s32 offset;
    s32 index;
    MenuItem *entry;

    count = g_menu_page_item_counts[arg2];
    if (arg0->alpha == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        index = 0;
        do {
            entry = (MenuItem *)(offset + ((u8 *)g_menu_items + arg2 * 0x380));
            if (entry->active != 0) {
                entry->alpha = arg0->alpha;
                reg_a0 = *(u8 **)((u8 *)arg1 + index);
                glyph_queue_add(entry->x, entry->y, entry->z, 0, 128, arg0->alpha, 1);
            }
            i++;
            offset += 0x38;
            index += 4;
        } while (i < count);
    }
}

void menu_simulation_step0(void)
{
    s8 saved;

    saved = g_menu_simulation.cursor;
    menu_page_enter(&g_menu_simulation);
    g_menu_simulation.cursor = saved;
    menu_items_place(7);
}

void menu_simulation_step1(void) {
    s8 value = g_menu_simulation.cursor;
    if (menu_page_advance(&g_menu_simulation, 7) != 0) {
        g_menu_cursor = value;
        if (value == 0) {
            g_menu_cursor++;
        }
    }
}

void menu_simulation_step10(void) {
    menu_page_enter(&g_menu_simulation);
    g_menu_simulation.cursor = 0;
    g_menu_simulation.alpha = 0;
    g_menu_box_alpha = 0;
    g_menu_cursor = 0;
    menu_items_slide_in(7);
}

void menu_simulation_step11(void) {
    if (menu_simulation_slide_in_step(&g_menu_simulation, 7) != 0) {
        g_menu_cursor = 1;
        g_menu_simulation.step = 2;
    }
}

void menu_simulation_step2(void) {
    s32 confirm;
    s32 last;
    u32 buttons;

    confirm = 0;
    last = D_002714F7[0] - 1;
    menu_idle_cancel();
    if ((s8)menu_cursor_input(7) == 0) {
        buttons = g_pad_trigger[g_menu_pad];
        if (buttons & 0x40) {
            g_menu_cursor = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    g_menu_simulation.cursor = g_menu_cursor;
    if (confirm != 0) {
        sfx_menu_confirm();
        g_menu_simulation.step += 1;
        if (last == g_menu_simulation.cursor) {
            menu_items_place(0);
            g_menu_main_step = 3;
            g_menu_page = MENU_PAGE_MAIN;
            g_menu_alpha = 0x40;
            g_menu_main_fade_state = 1;
            g_menu_fade_state = 1;
            g_menu_box_fade_state = 2;
            g_menu_simulation.state = 2;
        } else {
            g_menu_simulation.state = 0;
            g_menu_simulation.alpha = 0;
            g_menu_box_fade_state = 0;
            g_menu_box_alpha = 0;
            switch (g_menu_simulation.cursor) {
            case 1:
                g_menu_sim_setting.cursor = 1;
                g_menu_sim_setting.step = 0;
                g_menu_page = MENU_PAGE_SIM_SETTING;
                break;
            case 2:
                g_menu_stage_select.step = 0;
                g_menu_page = MENU_PAGE_STAGE_SELECT;
                break;
            case 3:
                g_menu_file_select.step = 0;
                g_menu_page = MENU_PAGE_REPLAY;
                break;
            case 4:
                g_menu_file_select.step = 0;
                g_menu_page = MENU_PAGE_SUPER_REPLAY;
                break;
            }
        }
    }
}

void menu_simulation_page(void) {
    switch (g_menu_simulation.step) {
    case 10:
        menu_simulation_step10();
        break;
    case 0:
        menu_simulation_step0();
        break;
    case 11:
        menu_simulation_step11();
        break;
    case 1:
        menu_simulation_step1();
        break;
    case 2:
        menu_simulation_step2();
        break;
    case 3:
        break;
    }
}

void menu_simulation_draw(void) {
    menu_page_fade(&g_menu_simulation);
    menu_simulation_items_draw(&g_menu_simulation, (u8 **)g_menu_simulation_items, 7);
}

void menu_stage_select_step0(void) {
    menu_page_enter(&g_menu_stage_select);
    menu_items_place(0xA);
    g_autosave_step = 0;
}

void menu_stage_select_step1(void) {
    if (autosave_update() != 0) {
        g_menu_stage_select.step += 1;
    }
}

void menu_stage_select_step2(void) {
    if (menu_page_advance(&g_menu_stage_select, 0xA) != 0) {
        g_menu_cursor = D_0068DF02[0] + 1;
    }
}

void menu_stage_select_step3(void) {
    s32 confirm;
    s32 last;
    u32 buttons;
    s32 selected;

    confirm = 0;
    last = D_002714FA[0] - 1;
    menu_idle_cancel();
    if ((s8)menu_cursor_input(10) == 0) {
        buttons = g_pad_trigger[g_menu_pad];
        if (buttons & 0x40) {
            g_menu_cursor = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    g_menu_stage_select.cursor = g_menu_cursor;
    if (confirm != 0) {
        if (last != g_menu_stage_select.cursor) {
            selected = g_menu_stage_select.cursor - 1;
            if (g_stage_select_unlocked < selected) {
                sfx_menu_denied();
                return;
            }
#ifndef DEATH_LABEL
            g_stage_select_choice = selected;
            printf("----stage[%d]\n", g_stage_select_choice);
#endif
            sfx_menu_confirm();
            g_menu_stage_select.step += 1;
            D_0068DF02[0] = g_menu_stage_select.cursor - 1;
            menu_close_begin();
        } else {
            sfx_menu_confirm();
            g_menu_simulation.cursor = 2;
            g_menu_stage_select.state = 0;
            g_menu_page = MENU_PAGE_SIMULATION;
            g_menu_stage_select.alpha = 0;
            g_menu_simulation.step = 0;
            D_0068DF02[0] = D_00270822[0];
        }
    }
}

void menu_stage_select_page(void) {
    switch (g_menu_stage_select.step) {
    case 0:
        menu_stage_select_step0();
        break;
    case 1:
        menu_stage_select_step1();
        break;
    case 2:
        menu_stage_select_step2();
        break;
    case 3:
        menu_stage_select_step3();
        /* fallthrough */
    case 4:
        break;
    }
}

void menu_stage_select_draw(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 count;
    s32 last;
    s32 i;
    s32 offset;
    s32 index;
    s32 alpha;
    MenuItem *entry;
    s32 x;
    s32 y;
    s32 sprite;
    s16 value;

    count = D_002714FA[0];
    last = count - 1;
    if (g_menu_stage_select.step < 3) {
        return;
    }
    menu_page_fade(&g_menu_stage_select);
    if (g_menu_stage_select.alpha == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        index = 0;
        do {
            entry = (MenuItem *)((u8 *)g_menu_items + offset);
            if (entry[MENU_PAGE_STAGE_SELECT * MENU_ITEMS_PER_PAGE].active != 0) {
                value = g_menu_stage_select.alpha;
                alpha = 128;
                entry[MENU_PAGE_STAGE_SELECT * MENU_ITEMS_PER_PAGE].alpha = value;
                x = entry[MENU_PAGE_STAGE_SELECT * MENU_ITEMS_PER_PAGE].x;
                y = entry[MENU_PAGE_STAGE_SELECT * MENU_ITEMS_PER_PAGE].y;
                sprite = entry[MENU_PAGE_STAGE_SELECT * MENU_ITEMS_PER_PAGE].z;
                reg_a0 = *(u8 **)((u8 *)g_menu_stage_select_items + index);
                if ((i > 0) && (i < last) && (g_stage_select_unlocked < i - 1)) {
                    alpha = 64;
                    reg_a0 = (u8 *)g_menu_dashes_text;
                }
                glyph_queue_add(x, y, sprite, 0, alpha, value, 1);
            }
            i++;
            offset += 0x38;
            index += 4;
        } while (i < count);
    }
}

void menu_file_select_step0(void) {
    menu_page_enter(&g_menu_file_select);
    menu_items_place(0xB);
    g_menu_replay_chosen = 0;
    g_replay_mode = 0;
    replay_slots_open(0, g_menu_pad, 0);
}

void menu_file_select_step1(void) {
    if (menu_page_advance(&g_menu_file_select, 0xB) != 0) {
        g_menu_box_fade_state = 0;
    }
}

void menu_replay_step2(void) {
    s32 temp_v0;

    menu_idle_cancel();
    temp_v0 = replay_slots_update();
    switch (temp_v0) {
    case 0:
        g_menu_simulation.cursor = 3;
        g_menu_box_fade_state = 0;
        g_menu_page = MENU_PAGE_SIMULATION;
        g_menu_box_alpha = 0;
        g_menu_file_select.state = 0;
        g_menu_file_select.alpha = 0;
        g_menu_simulation.step = 0;
        return;
    case 3:
        g_replay_mode = 2;
        g_menu_replay_chosen = 1;
        g_menu_file_select.step += 1;
        menu_close_begin();
        return;
    }
}

void menu_replay_page(void) {
    switch (g_menu_file_select.step) {
    case 0:
        menu_file_select_step0();
        break;
    case 1:
        menu_file_select_step1();
        break;
    case 2:
        menu_replay_step2();
        /* fallthrough */
    case 3:
        break;
    }
}

void menu_file_select_draw(void) {
    menu_page_fade(&g_menu_file_select);
    replay_slots_draw();
}

void menu_super_replay_step0(void) {
    menu_page_enter(&g_menu_file_select);
    menu_items_place(0xB);
    g_menu_replay_chosen = 0;
    g_replay_mode = 0;
    replay_slots_open(0, g_menu_pad, 1);
}

void menu_super_replay_step2(void) {
    s32 temp_v0;

    menu_idle_cancel();
    temp_v0 = replay_slots_update();
    switch (temp_v0) {
    case 0:
        g_menu_simulation.cursor = 4;
        g_menu_box_fade_state = 0;
        g_menu_page = MENU_PAGE_SIMULATION;
        g_menu_box_alpha = 0;
        g_menu_file_select.state = 0;
        g_menu_file_select.alpha = 0;
        g_menu_simulation.step = 0;
        break;
    case 3:
        g_replay_mode = 2;
        g_menu_replay_chosen = 1;
        g_menu_file_select.step += 1;
        menu_close_begin();
        break;
    }
}

void menu_super_replay_page(void) {
    switch (g_menu_file_select.step) {
    case 0:
        menu_super_replay_step0();
        break;
    case 1:
        menu_file_select_step1();
        break;
    case 2:
        menu_super_replay_step2();
        /* fallthrough */
    case 3:
        break;
    }
}

void menu_settings_load_page(void) {
    switch (g_menu_file_select.step) {
    case 0:
        menu_file_select_step0();
        break;
    case 1:
        menu_file_select_step1();
        break;
    case 2:
        menu_settings_load_step2();
        /* fallthrough */
    case 3:
        break;
    }
}

void menu_settings_load_step2(void) {
    s32 temp_v0;

    menu_idle_cancel();
    temp_v0 = replay_slots_update();
    switch (temp_v0) {
    case 0:
        g_menu_box_fade_state = 0;
        g_menu_sim_setting.cursor = 4;
        g_menu_box_alpha = 0;
        g_menu_page = MENU_PAGE_SIM_SETTING;
        g_menu_file_select.state = 0;
        g_menu_file_select.alpha = 0;
        g_menu_sim_setting.step = 0;
        break;
    case 3:
        menu_settings_load_apply();
        replay_slots_close();
        break;
    }
}

void menu_settings_load_apply(void) {
    memcpy(D_0068DEF0_as_s16_a, ((s16 *)D_00270810), 0x16);
    memcpy(((s16 *)D_0068DED8), D_00270828, 0xA);
    memcpy(((s16 *)D_0068DEC8), D_00270838, 0xC);
    ((s16 *)D_0068DED8)[0] = D_006C58AA[0];
    D_0068DEDE[0] = D_006C58C6[0];
    D_0068DEE0[0] = D_006C58C8[0];
    if (D_006C58A2[0] == 0xFF) {
        if (D_006C58A6[0] == 0) {
            D_0068DEDA[0] = 0;
        } else {
            D_0068DEDA[0] = 1;
        }
        if (D_006C58A8[0] == 2) {
            D_0068DEDC[0] = 0;
        } else if (D_006C58A8[0] == 4) {
            D_0068DEDC[0] = 1;
        } else {
            D_0068DEDC[0] = 2;
        }
    } else {
        if (D_006C58A2[0] == 0) {
            D_0068DEDA[0] = 0;
        } else {
            D_0068DEDA[0] = 1;
        }
        if (D_006C58A4[0] == 2) {
            D_0068DEDC[0] = 0;
        } else if (D_006C58A4[0] == 4) {
            D_0068DEDC[0] = 1;
        } else {
            D_0068DEDC[0] = 2;
        }
    }
    D_0068DEF0_as_s16_a[0] = D_006C58B8[0];
    D_0068DEF2[0] = D_006C58BA[0];
    D_0068DEF4[0] = D_006C58C0[0];
    D_0068DF04[0] = D_006C58C2[0];
    D_0068DEF6[0] = D_006C58B4[0];
    D_0068DEF8[0] = D_006C58B6[0];
    D_0068DEFA[0] = D_006C58CA[0];
    D_0068DEFE[0] = D_006C58BC[0];
    D_0068DF00[0] = D_006C58BE[0];
    D_0068DEFC[0] = D_006C58CC[0];
    ((s16 *)D_0068DEC8)[0] = D_006C58CE[0];
    D_0068DECA[0] = D_006C58D0[0];
    D_0068DECC[0] = D_006C58D2[0];
    D_0068DECE[0] = D_006C58B0[0];
    D_0068DED0[0] = D_006C58B2[0];
    D_0068DED2[0] = D_006C58D4[0];
    if (((s16 *)D_0068DED8)[0] > 3) {
        ((s16 *)D_0068DED8)[0] = 1;
    }
    if (D_0068DEDE[0] > 19) {
        D_0068DEDE[0] = 20;
    }
    if (D_0068DEE0[0] > 3) {
        D_0068DEE0[0] = 0;
    }
    if (D_0068DEF0_as_s16_a[0] > 1) {
        D_0068DEF0_as_s16_a[0] = 0;
    }
    if (D_0068DEF2[0] > 1) {
        D_0068DEF2[0] = 0;
    }
    if (D_0068DEF4[0] > 255) {
        D_0068DEF4[0] = 0;
    }
    if (D_0068DF04[0] > 1) {
        D_0068DF04[0] = 0;
    }
    if (D_0068DEF6[0] > 5) {
        D_0068DEF6[0] = 6;
    }
    if (D_0068DEF8[0] > 7) {
        D_0068DEF8[0] = 8;
    }
    if (D_0068DEFA[0] > 1) {
        D_0068DEFA[0] = 0;
    }
    if (D_0068DEFE[0] > 5) {
        D_0068DEFE[0] = 0;
    }
    if (D_0068DF00[0] > 500) {
        D_0068DF00[0] = 0;
    }
    if (D_0068DEFC[0] > 100) {
        D_0068DEFC[0] = 0;
    }
    if (((s16 *)D_0068DEC8)[0] > 2) {
        ((s16 *)D_0068DEC8)[0] = 0;
    }
    if (D_0068DECA[0] > 9) {
        D_0068DECA[0] = 0;
    }
    if (D_0068DECC[0] > 15) {
        D_0068DECC[0] = 0;
    }
    if (D_0068DECE[0] > 4) {
        D_0068DECE[0] = 0;
    }
    if (D_0068DED0[0] > 4) {
        D_0068DED0[0] = 0;
    }
    if (D_0068DED2[0] > 10) {
        D_0068DED2[0] = 0;
    }
    memcpy(((s16 *)D_0068DEB0), D_0068DEF0_as_s16_a, 0x16);
    memcpy(((s16 *)D_0068DE90), ((s16 *)D_0068DED8), 0xA);
    memcpy(((s16 *)D_0068DEA0), ((s16 *)D_0068DEC8), 0xC);
}

void menu_sim_setting_step0(void)
{
    s8 saved;

    saved = g_menu_sim_setting.cursor;
    menu_page_enter(&g_menu_sim_setting);
    g_menu_sim_setting.cursor = saved;
    menu_items_place(8);
}

void menu_sim_setting_step1(void) {
    if (menu_page_advance(&g_menu_sim_setting, 8) != 0) {
        g_menu_cursor = g_menu_sim_setting.cursor;
    }
}

void menu_sim_setting_step2(void) {
    s32 confirm;
    s32 last;
    u32 buttons;

    confirm = 0;
    last = D_002714F8[0] - 1;
    menu_idle_cancel();
    if ((s8)menu_cursor_input(8) == 0) {
        buttons = g_pad_trigger[g_menu_pad];
        if (buttons & 0x40) {
            g_menu_cursor = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    g_menu_sim_setting.cursor = g_menu_cursor;
    if (confirm != 0) {
        switch (g_menu_cursor) {
        case 1:
            sfx_menu_confirm();
            g_menu_sim_setting.state = 0;
            g_menu_page = MENU_PAGE_SIM_PLAYER;
            g_menu_sim_setting.alpha = 0;
            g_menu_box_fade_state = 0;
            g_menu_box_alpha = 0;
            g_menu_sim_player.step = 0;
            g_menu_sim_setting.step += 1;
            break;
        case 2:
            sfx_menu_confirm();
            g_menu_sim_setting.state = 0;
            g_menu_page = MENU_PAGE_SIM_RULES;
            g_menu_sim_setting.alpha = 0;
            g_menu_box_fade_state = 0;
            g_menu_box_alpha = 0;
            g_menu_sim_rules.step = 0;
            g_menu_sim_setting.step += 1;
            break;
        case 3:
            sfx_menu_confirm();
            g_menu_sim_setting.state = 0;
            g_menu_page = MENU_PAGE_SIM_PARAM;
            g_menu_sim_setting.alpha = 0;
            g_menu_box_fade_state = 0;
            g_menu_box_alpha = 0;
            g_menu_sim_param.step = 0;
            g_menu_sim_setting.step += 1;
            break;
        case 4:
            sfx_menu_confirm();
            g_menu_sim_setting.state = 0;
            g_menu_page = MENU_PAGE_SETTINGS_LOAD;
            g_menu_sim_setting.alpha = 0;
            g_menu_box_fade_state = 0;
            g_menu_box_alpha = 0;
            g_menu_file_select.step = 0;
            g_menu_sim_setting.step += 1;
            break;
        case 5:
            sfx_menu_confirm();
            g_menu_sim_setting.state = 0;
            g_menu_simulation.cursor = 1;
            g_menu_sim_setting.alpha = 0;
            g_menu_page = MENU_PAGE_SIMULATION;
            g_menu_box_fade_state = 0;
            g_menu_box_alpha = 0;
            g_menu_simulation.step = 0;
            g_menu_sim_setting.step += 1;
            break;
        }
    }
}

void menu_sim_setting_page(void) {
    switch (g_menu_sim_setting.step) {
    case 0:
        menu_sim_setting_step0();
        break;
    case 1:
        menu_sim_setting_step1();
        break;
    case 2:
        menu_sim_setting_step2();
        /* fallthrough */
    case 3:
        break;
    }
}

void menu_sim_setting_draw(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 count;
    s32 i;
    s32 offset;
    s32 tableOffset;
    MenuItem *entry;

    count = D_002714F8[0];
    menu_page_fade(&g_menu_sim_setting);
    if (g_menu_sim_setting.alpha == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        tableOffset = 0;
        do {
            entry = (MenuItem *)((u8 *)g_menu_items + offset);
            if (entry[MENU_PAGE_SIM_SETTING * MENU_ITEMS_PER_PAGE].active != 0) {
                s32 value = g_menu_sim_setting.alpha;

                entry[MENU_PAGE_SIM_SETTING * MENU_ITEMS_PER_PAGE].alpha = value;
                reg_a0 = *(u8 **)((u8 *)g_menu_sim_setting_items + tableOffset);
                glyph_queue_add(entry[MENU_PAGE_SIM_SETTING * MENU_ITEMS_PER_PAGE].x, entry[MENU_PAGE_SIM_SETTING * MENU_ITEMS_PER_PAGE].y, entry[MENU_PAGE_SIM_SETTING * MENU_ITEMS_PER_PAGE].z, 0, 0x80, value, 1);
            }
            i++;
            offset += 0x38;
            tableOffset += 4;
        } while (i < count);
    }
}

void menu_sim_player_step0(void) {
    menu_page_enter(&g_menu_sim_player);
    menu_items_place(0x11);
}

void menu_sim_player_step1(void) {
    if (menu_page_advance(&g_menu_sim_player, 0x11) != 0) {
        g_menu_cursor = 1;
    }
}

void menu_sim_player_step2(void) {
    s32 confirm;
    s32 last;
    s32 dir;
    s32 skip;
    u32 buttons;
    s32 count;
    s32 item;
    s16 *value;

    dir = 0;
    confirm = 0;
    last = D_00271501[0] - 1;
    menu_idle_cancel();
    skip = (s8)menu_cursor_input(17);
    if (skip == 0) {
        buttons = g_pad_repeat[g_menu_pad];
        if (buttons & 0x8000) {
            dir = -1;
            skip = 1;
        } else if (buttons & 0x2000) {
            dir = 1;
            skip = 1;
        }
    }
    if (skip == 0) {
        buttons = g_pad_trigger[g_menu_pad];
        if (buttons & 0x40) {
            g_menu_cursor = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    g_menu_sim_player.cursor = g_menu_cursor;
    if (confirm != 0) {
        switch (g_menu_cursor) {
        case 6:
            sfx_menu_confirm();
            memcpy(((s16 *)D_0068DED8), D_00270828, 10);
            break;
        case 7:
            sfx_menu_confirm();
            g_menu_sim_player.state = 0;
            g_menu_sim_setting.cursor = 1;
            g_menu_sim_player.alpha = 0;
            g_menu_page = MENU_PAGE_SIM_SETTING;
            g_menu_box_fade_state = 0;
            g_menu_box_alpha = 0;
            g_menu_sim_setting.step = 0;
            g_menu_sim_player.step += 1;
            break;
        }
    } else if (dir != 0) {
        item = g_menu_sim_player_value_tables[g_menu_cursor];
        if (!(0 > item)) {
            value = &((s16 *)D_0068DED8)[item];
            count = g_menu_sim_player_value_counts[item];
            sfx_menu_tick();
            if (item == 2) {
                D_0068DEF6[0] = 6;
                D_0068DEF8[0] = 8;
            }
            if (dir == -1) {
                (*value)--;
                if (0 > *value) {
                    *value = count - 1;
                }
            } else {
                (*value)++;
                if (count <= *value) {
                    *value = 0;
                }
            }
        }
    }
}

void menu_sim_player_page(void) {
    switch (g_menu_sim_player.step) {
    case 0:
        menu_sim_player_step0();
        break;
    case 1:
        menu_sim_player_step1();
        break;
    case 2:
        menu_sim_player_step2();
        /* fallthrough */
    case 3:
        break;
    }
}

void menu_sim_player_draw(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 dbl;
    s32 x;
    s32 y;
    s32 z;
    s32 i;
    s32 count;
    s32 value;
    s32 alpha;
    u8 **entries;
    s8 index;
    MenuItem *item;

    count = D_00271501[0];
    menu_page_fade(&g_menu_sim_player);
    if (g_menu_sim_player.alpha == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_SIM_PLAYER * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_SIM_PLAYER * MENU_ITEMS_PER_PAGE].alpha = alpha = g_menu_sim_player.alpha;
        x = item[MENU_PAGE_SIM_PLAYER * MENU_ITEMS_PER_PAGE].x;
        y = item[MENU_PAGE_SIM_PLAYER * MENU_ITEMS_PER_PAGE].y;
        z = item[MENU_PAGE_SIM_PLAYER * MENU_ITEMS_PER_PAGE].z;
        reg_a0 = (u8 *)g_menu_sim_player_items[i];
        glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        y += strlen((const char *)reg_a0) * 8;
        reg_a0 = 0;
        index = g_menu_sim_player_value_tables[i];
        if (index == -1) {
            continue;
        }
        entries = (u8 **)g_menu_sim_player_values[index];
        value = ((s16 *)D_0068DED8)[index];
        reg_a0 = entries[value];
        if (reg_a0 == 0) {
            continue;
        }
        if (index == 4) {
            dbl = value * 2;
            reg_a0 = entries[dbl];
            if (dbl == 6) {
                glyph_queue_add(x, y, z, 0, 0x80, g_menu_sim_player.alpha, 1);
            } else {
                glyph_queue_add(x, y, z, 0, 0x80, g_menu_sim_player.alpha, 0);
                reg_a0 = (u8 *)g_menu_sim_player_values[index][dbl + 1];
                glyph_queue_add(x - 8, y, z, 0, 0x80, g_menu_sim_player.alpha, 0);
            }
        } else {
            glyph_queue_add(x, y, z, 0, 0x80, g_menu_sim_player.alpha, 1);
        }
        if (i == g_menu_sim_player.cursor) {
            menu_arrows_draw(x, y, z, 0, 0x80, g_menu_sim_player.alpha, 1, 3);
        }
    }
}

void menu_sim_rules_step0(void) {
    menu_page_enter(&g_menu_sim_rules);
    menu_items_place(0x12);
}

void menu_sim_rules_step1(void) {
    if (menu_page_advance(&g_menu_sim_rules, 0x12) != 0) {
        g_menu_cursor = 1;
    }
}

void menu_sim_rules_step2(void) {
    s32 confirm;
    s32 last;
    s32 dir;
    s32 moved;
    s32 count;
    s32 idx;
    s32 pad;
    s8 sel;
    s32 limit;
    s16 *value;
    s32 base;
    s32 total;
    s32 extra;

    last = D_00271502[0] - 1;
    dir = 0;
    confirm = 0;
    menu_idle_cancel();
    moved = (s8)menu_cursor_input(0x12);
    if (moved == 0) {
        if (g_menu_cursor == 3 || g_menu_cursor == 9 || g_menu_cursor == 7) {
            pad = g_pad_fast_repeat[g_menu_pad];
            if (pad & 0x8000) {
                dir = -1;
                moved = 1;
            } else if (pad & 0x2000) {
                dir = 1;
                moved = dir;
            }
        } else {
            pad = g_pad_repeat[g_menu_pad];
            if (pad & 0x8000) {
                dir = -1;
                moved = 1;
            } else if (pad & 0x2000) {
                dir = 1;
                moved = dir;
            }
        }
    }
    if (moved == 0) {
        pad = g_pad_trigger[g_menu_pad];
        if (pad & 0x40) {
            g_menu_cursor = last;
            confirm = 1;
        } else if (pad & 0x20) {
            confirm = 1;
        }
    }
    sel = g_menu_cursor;
    g_menu_sim_rules.cursor = sel;
    if (confirm != 0) {
        switch (sel) {
        case 3:
            sfx_menu_confirm();
            D_0068DEF0_as_s16_a[10] += 1;
            D_0068DEF0_as_s16_a[10] &= 1;
            break;
        case 10:
            sfx_menu_confirm();
            memcpy(D_0068DEF0_as_s16_a, ((s16 *)D_00270810), 0x16);
            break;
        case 11:
            sfx_menu_confirm();
            g_menu_sim_rules.state = 0;
            g_menu_sim_setting.cursor = 2;
            g_menu_sim_rules.alpha = 0;
            g_menu_page = MENU_PAGE_SIM_SETTING;
            g_menu_box_fade_state = 0;
            g_menu_box_alpha = 0;
            g_menu_sim_setting.step = 0;
            g_menu_sim_rules.step++;
            break;
        }
    } else if (dir != 0) {
        idx = g_menu_sim_rules_value_tables[sel];
        if (sel == 3 && D_0068DEF0_as_s16_a[10] == 0) {
            idx = -1;
        }
        if (!(0 > idx)) {
        value = &D_0068DEF0_as_s16_a[idx];
        count = g_menu_sim_rules_value_counts[idx];
        if (sel == 3 || sel == 9 || sel == 7) {
            pad = g_pad_fast_repeat_timer[g_menu_pad];
            if (pad == 0 || pad == 0xE) {
                if (!(*value == 0 && dir == -1) && !(*value == count - 1 && dir == 1)) {
                    sfx_menu_tick();
                }
            }
        } else {
            sfx_menu_tick();
        }
        if (idx == 5) {
            if (D_0068DEF0_as_s16_a[5] == 0 && D_0068DEF0_as_s16_a[7] == 0) {
                D_0068DEF0_as_s16_a[7] = 1;
            }
            if (D_0068DEF0_as_s16_a[5] != 0) {
                D_0068DEF0_as_s16_a[7] = 0;
                D_0068DEF0_as_s16_a[8] = 0;
            }
        }
        if (idx == 3) {
            D_0068DEF0_as_s16_a[4] = 8;
        }
        limit = D_0068DEF0_as_s16_a[3] + 1;
        if (limit == 7) {
            if (D_0068DEDC[0] == 0) {
                limit = 3;
            }
            if (D_0068DEDC[0] == 1) {
                limit = 2;
            }
            if (D_0068DEDC[0] == 2) {
                limit = 1;
            }
        }
        if (dir == -1) {
            (*value)--;
            if (idx == 3) {
                if (D_0068DEDC[0] == 0 && *value == 1) {
                    *value = 6;
                }
                if (D_0068DEDC[0] == 1 && *value == 5) {
                    *value = 3;
                }
                if (D_0068DEDC[0] == 1 && *value == 0) {
                    *value = 6;
                }
                if (D_0068DEDC[0] == 2 && *value == 5) {
                    *value = 1;
                }
            }
            if (idx == 4 && *value == 6) {
                *value = limit;
            }
            if (idx == 7 && D_0068DEF0_as_s16_a[5] == 1 && *value == 0) {
                *value = 5;
            }
            if (g_menu_cursor == 3 || g_menu_cursor == 9 || g_menu_cursor == 7) {
                if (0 > *value) {
                    *value = 0;
                }
            } else {
                if (0 > *value) {
                    *value = count - 1;
                }
            }
        } else {
            (*value)++;
            if (idx == 3) {
                if (D_0068DEDC[0] == 0 && *value == 7) {
                    *value = 2;
                }
                if (D_0068DEDC[0] == 1 && *value == 4) {
                    *value = 6;
                }
                if (D_0068DEDC[0] == 1 && *value == 7) {
                    *value = 1;
                }
                if (D_0068DEDC[0] == 2 && *value == 2) {
                    *value = 6;
                }
            }
            if (idx == 4 && *value < 7 && limit < *value) {
                *value = 7;
            }
            if (idx == 7 && D_0068DEF0_as_s16_a[5] == 1 && *value == 6) {
                *value = 1;
            }
            if (g_menu_cursor == 3 || g_menu_cursor == 9 || g_menu_cursor == 7) {
                if (count <= *value) {
                    *value = count - 1;
                }
            } else {
                if (count <= *value) {
                    *value = 0;
                }
            }
#ifdef DEATH_LABEL
            if (D_0068DEF0_as_s16_a[5] == 0) {
                base = D_0068DEF0_as_s16_a[8];
                total = 0;
                if (base != 0) {
                    total = (s16)base / 100;
                }
                extra = D_0068DEF0_as_s16_a[7];
                total += extra;
                if (total > 5) {
                    if (idx == 7) {
                        if ((s16)base >= 100) {
                            D_0068DEF0_as_s16_a[8] -= 100;
                        }
                    } else if (idx == 8) {
                        if (extra > 0) {
                            D_0068DEF0_as_s16_a[7] = extra - 1;
                        }
                    }
                }
            }
#endif
        }
#ifndef DEATH_LABEL
        if (D_0068DEF0_as_s16_a[5] == 0) {
            base = D_0068DEF0_as_s16_a[8];
            total = 0;
            if (base != 0) {
                total = (s16)base / 100;
            }
            extra = D_0068DEF0_as_s16_a[7];
            total += extra;
            if (total > 5) {
                if (idx == 7) {
                    D_0068DEF0_as_s16_a[8] = (5 - extra) * 100 + 99;
                } else if (idx == 8) {
                    D_0068DEF0_as_s16_a[7] = (500 - (s16)base) / 100;
                }
            }
        }
#endif
    }
    }
}

void menu_sim_rules_page(void) {
    switch (g_menu_sim_rules.step) {
    case 0:
        menu_sim_rules_step0();
        break;
    case 1:
        menu_sim_rules_step1();
        break;
    case 2:
        menu_sim_rules_step2();
        /* fallthrough */
    case 3:
        break;
    }
}

void menu_sim_rules_draw(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 x;
    s32 y;
    s32 z;
    s32 bright;
    s32 i;
    s32 count;
    s32 flag;
    s32 alpha;
    s8 index;
    MenuItem *item;

    count = D_00271502[0];
    menu_page_fade(&g_menu_sim_rules);
    if (g_menu_sim_rules.alpha == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_SIM_RULES * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_SIM_RULES * MENU_ITEMS_PER_PAGE].alpha = alpha = g_menu_sim_rules.alpha;
        x = item[MENU_PAGE_SIM_RULES * MENU_ITEMS_PER_PAGE].x;
        y = item[MENU_PAGE_SIM_RULES * MENU_ITEMS_PER_PAGE].y;
        z = item[MENU_PAGE_SIM_RULES * MENU_ITEMS_PER_PAGE].z;
        bright = 0x80;
        if (D_0068DEFA[0] == 0 && i == 7) {
            bright = 0x40;
        }
        reg_a0 = (u8 *)g_menu_sim_rules_items[i];
        glyph_queue_add(x, y, z, 0, bright, alpha, 1);
        y += strlen((const char *)reg_a0) * 8;
        reg_a0 = 0;
        index = g_menu_sim_rules_value_tables[i];
        if (index == -1) {
            continue;
        }
        if (i == 3) {
            reg_a0 = (u8 *)g_menu_default_text;
        } else if (i == 9 || i == 7) {
            reg_a0 = (u8 *)g_menu_blank_text_a;
        } else {
            reg_a0 = (u8 *)g_menu_sim_rules_values[index][D_0068DEF0_as_s16_a[index]];
        }
        if (reg_a0 == 0) {
            continue;
        }
        flag = 1;
        if (i == 3) {
            if (D_0068DF04[0] == 1) {
                menu_sim_rule_gauge_draw(x, y, g_menu_sim_rules.alpha, bright, 2);
            } else {
                glyph_queue_add(x, y, z, 0, bright, g_menu_sim_rules.alpha, flag);
                flag = 0;
            }
        } else if (i == 9) {
            menu_sim_rule_gauge_draw(x, y, g_menu_sim_rules.alpha, bright, 8);
        } else if (i == 7) {
            menu_sim_rule_gauge_draw(x, y, g_menu_sim_rules.alpha, bright, 6);
        } else {
            glyph_queue_add(x, y, z, 0, bright, g_menu_sim_rules.alpha, flag);
        }
        if (i == g_menu_sim_rules.cursor && flag != 0) {
            menu_arrows_draw(x, y, z, 0, bright, g_menu_sim_rules.alpha, 1, 3);
        }
    }
}

void menu_sim_rule_gauge_draw(s32 x, s32 y, s32 alpha, s32 mode, s32 kind) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    u8 *saved;
    s32 c;
    s32 level;
    s32 h;

    saved = reg_a0;
    level = D_0068DEF0_as_s16_a[kind];
    if (kind == 2) {
        h = level * 60000 / 255000;
    } else if (kind == 8) {
        h = level * 60000 / 500000;
    } else if (kind == 6) {
        h = level * 60000 / 100000;
    }
    c = 0xC8;
    if (mode != 0x80) {
        c = 0x40;
    }
    gfx_draw_color_box(x - 8, y, 0x10, 0x40, 0xC8, alpha, 0x14, 0x14, 0x14);
    if (h != 0) {
        if (h == 0x3C) {
            gfx_draw_color_box(x - 6, y + 2, 0xE, h + 1, 0xC8, alpha, c, 0, 0);
        } else {
            gfx_draw_color_box(x - 6, y + 2, 0xE, h + 1, 0xC8, alpha, 0, 0, c);
        }
        if (kind == 8 && level >= 100) {
            if (level >= 100 && level < 200) {
                h = 12;
            }
            if (level >= 200 && level < 300) {
                h = 24;
            }
            if (level >= 300 && level < 400) {
                h = 36;
            }
            if (level >= 400 && level < 500) {
                h = 48;
            }
            gfx_draw_color_box(x - 6, y + 2, 0xE, h + 1, 0xC8, alpha, c, 0, 0);
        }
    }
    gfx_draw_color_box(x - 7, y, 0xE, 1, 0xC8, alpha, c, c, c);
    gfx_draw_color_box(x - 8, y + 1, 0x10, 1, 0xC8, alpha, c, c, c);
    gfx_draw_color_box(x - 8, y + 0x3E, 0x10, 1, 0xC8, alpha, c, c, c);
    gfx_draw_color_box(x - 7, y + 0x3F, 0xE, 1, 0xC8, alpha, c, c, c);
    if (kind == 8) {
        gfx_draw_color_box(x - 8, y + 0xE, 0x10, 1, 0xC8, alpha, c, c, c);
        gfx_draw_color_box(x - 8, y + 0x1A, 0x10, 1, 0xC8, alpha, c, c, c);
        gfx_draw_color_box(x - 8, y + 0x26, 0x10, 1, 0xC8, alpha, c, c, c);
        gfx_draw_color_box(x - 8, y + 0x32, 0x10, 1, 0xC8, alpha, c, c, c);
    }
    gfx_draw_color_box(x - 8, y + 1, 2, 0x3E, 0xC8, alpha, c, c, c);
    gfx_draw_color_box(x + 6, y + 1, 2, 0x3E, 0xC8, alpha, c, c, c);
    if (kind != 2) {
        reg_a0 = (u8 *)g_menu_numbers_0_to_500[level];
        glyph_queue_add(x - 4, y + 0x42, 0xC8, 0, c, alpha, 0);
        reg_a0 = (u8 *)g_menu_percent_text;
        glyph_queue_add(x - 4, y + 0x5A, 0xC8, 0, c, alpha, 0);
    }
    reg_a0 = saved;
}

void menu_sim_param_step0(void) {
    menu_page_enter(&g_menu_sim_param);
    menu_items_place(0x13);
}

void menu_sim_param_step1(void) {
    if (menu_page_advance(&g_menu_sim_param, 0x13) != 0) {
        g_menu_cursor = 1;
    }
}

void menu_sim_param_step2(void) {
    s32 confirm;
    s32 last;
    s32 dir;
    s32 skip;
    u32 buttons;
    s32 count;
    s32 item;
    s16 *value;

    dir = 0;
    confirm = 0;
    last = D_00271503[0] - 1;
    menu_idle_cancel();
    skip = (s8)menu_cursor_input(19);
    if (skip == 0) {
        buttons = g_pad_repeat[g_menu_pad];
        if (buttons & 0x8000) {
            dir = -1;
            skip = 1;
        } else if (buttons & 0x2000) {
            dir = 1;
            skip = 1;
        }
    }
    if (skip == 0) {
        buttons = g_pad_trigger[g_menu_pad];
        if (buttons & 0x40) {
            g_menu_cursor = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    g_menu_sim_param.cursor = g_menu_cursor;
    if (confirm != 0) {
        switch (g_menu_cursor) {
        case 7:
            sfx_menu_confirm();
            memcpy(((s16 *)D_0068DEC8), D_00270838, 12);
            break;
        case 8:
            sfx_menu_confirm();
            g_menu_sim_param.state = 0;
            g_menu_sim_setting.cursor = 3;
            g_menu_sim_param.alpha = 0;
            g_menu_page = MENU_PAGE_SIM_SETTING;
            g_menu_box_fade_state = 0;
            g_menu_box_alpha = 0;
            g_menu_sim_setting.step = 0;
            g_menu_sim_param.step += 1;
            break;
        }
    } else if (dir != 0) {
        item = g_menu_sim_param_value_tables[g_menu_cursor];
        if (!(0 > item)) {
            value = &((s16 *)D_0068DEC8)[item];
            count = g_menu_sim_param_value_counts[item];
            sfx_menu_tick();
            if (dir == -1) {
                (*value)--;
                if (0 > *value) {
                    *value = count - 1;
                }
            } else {
                (*value)++;
                if (count <= *value) {
                    *value = 0;
                }
            }
        }
    }
}

void menu_sim_param_page(void) {
    switch (g_menu_sim_param.step) {
    case 0:
        menu_sim_param_step0();
        break;
    case 1:
        menu_sim_param_step1();
        break;
    case 2:
        menu_sim_param_step2();
        /* fallthrough */
    case 3:
        break;
    }
}

void menu_sim_param_draw(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 x;
    s32 y;
    s32 z;
    s32 i;
    s32 count;
    s8 index;
    s32 alpha;
    MenuItem *item;

    count = D_00271503[0];
    menu_page_fade(&g_menu_sim_param);
    if (g_menu_sim_param.alpha == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_SIM_PARAM * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_SIM_PARAM * MENU_ITEMS_PER_PAGE].alpha = alpha = g_menu_sim_param.alpha;
        y = item[MENU_PAGE_SIM_PARAM * MENU_ITEMS_PER_PAGE].y;
        z = item[MENU_PAGE_SIM_PARAM * MENU_ITEMS_PER_PAGE].z;
        x = item[MENU_PAGE_SIM_PARAM * MENU_ITEMS_PER_PAGE].x;
        reg_a0 = (u8 *)g_menu_sim_param_items[i];
        glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        y += strlen((const char *)reg_a0) * 8;
        reg_a0 = 0;
        index = g_menu_sim_param_value_tables[i];
        if (index == -1) {
            continue;
        }
        reg_a0 = (u8 *)g_menu_sim_param_values[index][((s16 *)D_0068DEC8)[index]];
        if (reg_a0 == 0) {
            continue;
        }
        glyph_queue_add(x, y, z, 0, 0x80, g_menu_sim_param.alpha, 1);
        if (i == g_menu_sim_param.cursor) {
            menu_arrows_draw(x, y, z, 0, 0x80, g_menu_sim_param.alpha, 1, 3);
        }
    }
}

void menu_practice_ranking_step0(void) {
    menu_page_enter(&g_menu_practice_ranking);
    menu_items_slide_in(0xD);
    g_menu_practice_ranking.cursor = 0;
    g_menu_cursor = 1;
    g_menu_box_fade_state = 0;
    g_menu_alpha = 0x40;
    g_menu_fade_state = 2;
}

void menu_practice_ranking_step1(void) {
    if (menu_items_slide_update(0xD) != 0) {
        g_menu_practice_ranking.step += 1;
    }
}

void menu_practice_ranking_step2(void) {
    s32 temp_a0;
    s32 var_a1;
    s32 var_s0;

    var_s0 = 0;
    menu_idle_cancel();
    temp_a0 = g_pad_repeat[g_menu_pad];
    var_a1 = 0;
    if (temp_a0 & 0x8000) {
        sfx_menu_tick();
        g_menu_practice_ranking.cursor -= 1;
        if (g_menu_practice_ranking.cursor < 0) {
            g_menu_practice_ranking.cursor = 9;
        }
        var_a1 = 1;
    } else if (temp_a0 & 0x2000) {
        sfx_menu_tick();
        g_menu_practice_ranking.cursor += 1;
        if (g_menu_practice_ranking.cursor > 9) {
            g_menu_practice_ranking.cursor = 0;
        }
        var_a1 = 1;
    }
    if ((var_a1 == 0) && (g_pad_trigger[g_menu_pad] & 0x40)) {
        var_s0 = 1;
    }
    if (var_s0 != 0) {
        sfx_menu_confirm();
        g_menu_practice_ranking.state = 0;
        g_menu_fade_state = 1;
        g_menu_practice_ranking.alpha = 0;
        g_menu_simulation.cursor = 4;
        g_menu_box_fade_state = 0;
        g_menu_page = MENU_PAGE_SIMULATION;
        g_menu_box_alpha = 0;
        g_menu_alpha = 0;
        g_menu_simulation.step = 0;
        g_menu_practice_ranking.step += 1;
    }
}

void menu_practice_ranking_page(void) {
    switch (g_menu_practice_ranking.step) {
    case 0:
        menu_practice_ranking_step0();
        break;
    case 1:
        menu_practice_ranking_step1();
        break;
    case 2:
        menu_practice_ranking_step2();
        /* fallthrough */
    case 3:
        break;
    }
}

void menu_practice_ranking_draw(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    extern void text_queue_clear(void);
    extern void text_flush(void);
    s32 i;
    s32 x;
    s32 y;
    s32 z;
    s32 alpha;
    s32 count;
    MenuItem *item;

    menu_page_fade(&g_menu_practice_ranking);
    if (g_menu_practice_ranking.alpha == 0) {
        return;
    }
    count = D_002714FD[0];
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].alpha = g_menu_practice_ranking.alpha;
        reg_a0 = (u8 *)g_menu_practice_ranking_text[i];
        x = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].x;
        alpha = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].alpha;
        y = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].y;
        z = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].z;
        if (alpha == 0) {
            continue;
        }
        if (i == 1) {
            menu_arrows_draw(x, y, z, 0, 0x80, alpha, 1, 3);
        }
        glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        if (i == 1) {
            reg_a0 = (u8 *)g_menu_round_names[g_menu_practice_ranking.cursor];
            glyph_queue_add(x, y + 0x70, z, 0, 0x80, alpha, 1);
        }
    }
    menu_ranking_scores_format(g_menu_practice_ranking.cursor, 0);
    for (i = 3; i < 8; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].alpha = g_menu_practice_ranking.alpha;
        reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
        y = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].y + 16;
        x = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].x;
        z = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].z;
        alpha = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].alpha;
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    menu_ranking_scores_format(g_menu_practice_ranking.cursor, 1);
    for (i = 3; i < 8; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].alpha = g_menu_practice_ranking.alpha;
        reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
        y = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].y + 0x80;
        x = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].x;
        z = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].z;
        alpha = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].alpha;
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    menu_ranking_scores_format(g_menu_practice_ranking.cursor, 2);
    for (i = 9; i < 14; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].alpha = g_menu_practice_ranking.alpha;
        reg_a0 = (u8 *)D_00684CA0 + (i - 9) * 11;
        y = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].y + 16;
        x = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].x;
        z = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].z;
        alpha = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].alpha;
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    menu_ranking_scores_format(g_menu_practice_ranking.cursor, 3);
    for (i = 9; i < 14; i++) {
        item = &g_menu_items[0][i];
        if (item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].alpha = g_menu_practice_ranking.alpha;
        reg_a0 = (u8 *)D_00684CA0 + (i - 9) * 11;
        y = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].y + 0x80;
        x = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].x;
        z = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].z;
        alpha = item[MENU_PAGE_PRACTICE_RANKING * MENU_ITEMS_PER_PAGE].alpha;
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    g_menu_alpha = g_menu_practice_ranking.alpha;
    reg_a0 = (u8 *)g_menu_cancel_text;
    menu_message_draw(g_menu_items[13][14].x - 10, g_menu_items[13][14].y + 0x58);
    text_flush();
}

extern s8 g_result_notice_step;

void result_notice_update(void) {
    switch (g_result_notice_step) {                           /* irregular */
    case 0:
        result_notice_begin(g_result_notice_step);
        break;
    case 1:
        result_notice_slide(g_result_notice_step);
        break;
    case 2:
        result_notice_wait_button(g_result_notice_step);
        break;
    case 3:
        result_notice_finish(g_result_notice_step);
        break;
    }
}

extern s8 g_result_notice_unread_flag;
extern s8 g_result_notice_state;
extern s32 g_menu_ranking_alpha;

void result_notice_begin() {
    g_menu_ranking_alpha = 0;
    g_result_notice_step += 1;
    menu_items_slide_in(0xC);
    g_result_notice_unread_flag = 0;
    g_result_notice_state = 1;
}

extern s8 result_notice_slide_state;

void result_notice_slide() {
    if (menu_items_slide_update(0xC) != 0) {
        g_result_notice_step += 1;
        if ((0 <= result_notice_slide_state) && (result_notice_slide_state < 5)) {
            g_menu_cursor = result_notice_slide_state + 3;
            g_menu_box_fade_state = 1;
        } else {
            g_menu_cursor = -1;
            g_menu_box_fade_state = 1;
        }
    }
}

void result_notice_wait_button()
{
    extern void sfx_menu_confirm(void);
    if (g_pad_trigger[g_menu_pad] & 0x60) {
        sfx_menu_confirm();
        g_menu_box_fade_state = 2;
        g_result_notice_state = 2;
        g_result_notice_step = g_result_notice_step + 1;
    }
}

extern s8 g_result_menu_step;

void result_notice_finish() {
    if (g_result_notice_state == 0) {
        g_result_menu_step = 0x51;
    }
}

extern s8 D_002714FC[];
extern u8 D_00684CD7[];
extern u16 D_006C58AC[];
extern u16 D_006C58AE[];

void menu_ranking_draw(void) {
    extern void text_queue_clear(void);
    extern void text_flush(void);
    extern void glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    s32 count;
    u8 *save;
    s32 page;
    s32 sel;
    s32 i;
    s32 x;
    s32 y;
    s32 z;
    s32 alpha;
    MenuItem *item;

    save = reg_a0;
    count = D_002714FC[0];
    switch (g_result_notice_state) {
    case 0:
        break;
    case 1:
        g_menu_ranking_alpha += 4;
        if (g_menu_ranking_alpha >= 0x80) {
            g_result_notice_state = 0;
            g_menu_ranking_alpha = 0x80;
        }
        break;
    case 2:
        g_menu_ranking_alpha -= 4;
        if (g_menu_ranking_alpha <= 0) {
            g_menu_ranking_alpha = 0;
            g_result_notice_state = 0;
        }
        break;
    }
    page = D_006C58AE[0] + D_006C58AC[0] * 5;
    sel = D_006C58AA[0];
    menu_ranking_scores_format(page, sel);
    menu_ranking_box_draw();
    glyph_queue_clear();
    for (i = 0; i < count; i++) {
        item = &g_menu_items[0][i];
        if (item[12 * MENU_ITEMS_PER_PAGE].active == 0) {
            continue;
        }
        item[12 * MENU_ITEMS_PER_PAGE].alpha = g_menu_ranking_alpha;
        reg_a0 = (u8 *)g_menu_ranking_page_text[i];
        alpha = item[12 * MENU_ITEMS_PER_PAGE].alpha;
        x = item[12 * MENU_ITEMS_PER_PAGE].x;
        y = item[12 * MENU_ITEMS_PER_PAGE].y;
        z = item[12 * MENU_ITEMS_PER_PAGE].z;
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        if (i == 1) {
            reg_a0 = (u8 *)g_menu_round_names[page];
            glyph_queue_add(x, y + 0x38, z, 0, 0x80, alpha, 1);
            reg_a0 = (u8 *)g_menu_difficulty_names[sel];
            glyph_queue_add(x, y + 0x78, z, 0, 0x80, alpha, 1);
        }
        if (i >= 3 && i < 8) {
            reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
            glyph_queue_add(x, y + 0x38, z, 0, 0x80, alpha, 1);
        }
        if (i == 9) {
            reg_a0 = (u8 *)D_00684CD7;
            glyph_queue_add(x, y + 0x38, z, 0, 0x80, alpha, 1);
        }
    }
    glyph_queue_flush();
    text_queue_clear();
    g_menu_alpha = g_menu_ranking_alpha;
    reg_a0 = (u8 *)g_menu_confirm_cancel_text;
    menu_message_draw(x - 10, 0x40);
    text_flush();
    reg_a0 = save;
}

extern s32 menu_ranking_scores_format_state;

void menu_ranking_scores_format(s32 arg0, s32 arg1) {
    s32 i;
    s32 j;
    s32 v;
    s32 lead;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 11; j++) {
            ((char (*)[11])D_00684CA0)[i][j] = ' ';
        }
        ((char (*)[11])D_00684CA0)[i][10] = 0;
    }
    for (i = 0; i < 6; i++) {
        if (i == 5) {
            v = menu_ranking_scores_format_state;
        } else {
            v = ((s32 (*)[4][5])D_00684CF0)[arg0][arg1][i];
        }
        lead = 0;
        if (v >= 100000000) {
            ((char (*)[11])D_00684CA0)[i][0] = v / 100000000 + '0';
            v %= 100000000;
            lead = 1;
        }
        if (v >= 10000000) {
            ((char (*)[11])D_00684CA0)[i][1] = v / 10000000 + '0';
            v %= 10000000;
            lead = 1;
        } else if (lead) {
            ((char (*)[11])D_00684CA0)[i][1] = '0';
        }
        if (v >= 1000000) {
            ((char (*)[11])D_00684CA0)[i][2] = v / 1000000 + '0';
            v %= 1000000;
            lead = 1;
        } else if (lead) {
            ((char (*)[11])D_00684CA0)[i][2] = '0';
        }
        if (v >= 100000) {
            ((char (*)[11])D_00684CA0)[i][3] = v / 100000 + '0';
            v %= 100000;
            lead = 1;
        } else if (lead) {
            ((char (*)[11])D_00684CA0)[i][3] = '0';
        }
        if (v >= 10000) {
            ((char (*)[11])D_00684CA0)[i][4] = v / 10000 + '0';
            v %= 10000;
            lead = 1;
        } else if (lead) {
            ((char (*)[11])D_00684CA0)[i][4] = '0';
        }
        if (v >= 1000) {
            ((char (*)[11])D_00684CA0)[i][5] = v / 1000 + '0';
            v %= 1000;
            lead = 1;
        } else if (lead) {
            ((char (*)[11])D_00684CA0)[i][5] = '0';
        }
        if (v >= 100) {
            ((char (*)[11])D_00684CA0)[i][6] = v / 100 + '0';
            v %= 100;
            lead = 1;
        } else if (lead) {
            ((char (*)[11])D_00684CA0)[i][6] = '0';
        }
        if (v >= 10) {
            ((char (*)[11])D_00684CA0)[i][7] = v / 10 + '0';
            v %= 10;
            lead = 1;
        } else if (lead) {
            ((char (*)[11])D_00684CA0)[i][7] = '0';
        }
        if (v > 0) {
            ((char (*)[11])D_00684CA0)[i][8] = v + '0';
        } else if (lead) {
            ((char (*)[11])D_00684CA0)[i][8] = '0';
        }
        ((char (*)[11])D_00684CA0)[i][9] = '0';
    }
}


void menu_ranking_box_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s32 x;

    switch (g_menu_box_fade_state) {
    case 0:
        break;
    case 1:
        g_menu_box_alpha += 4;
        if (g_menu_box_alpha >= 0x40) {
            g_menu_box_fade_state = 0;
            g_menu_box_alpha = 0x40;
        }
        break;
    case 2:
        g_menu_box_alpha -= 4;
        if (g_menu_box_alpha <= 0) {
            g_menu_box_alpha = 0;
            g_menu_box_fade_state = 0;
        }
        break;
    }
    if (g_menu_cursor != -1) {
        x = g_menu_item_positions_a[g_menu_cursor].x;
        if (g_menu_box_alpha != 0) {
            gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, g_menu_box_alpha, 0xB4, 1, 1);
        }
    }
    if (g_menu_box_alpha != 0) {
        gfx_draw_color_box(g_menu_item_positions_a[9].x - 8, 0, 0x12, 0xE0, 0x5A, g_menu_box_alpha, 0xB4, 1, 1);
    }
}


void replay_save_prompt_update(void) {
    if (g_replay_slots_from_disc == 0) {
        replay_save_prompt_update_card();
        return;
    }
    replay_save_prompt_update_disc();
}

extern u8 g_loaded_replay_id_0_as_u8_a8[8];
extern u16 g_replay_start_p2_score_billions;
extern s32 g_replay_start_p2_score;
extern u16 g_replay_start_p2_score_digits;
extern u16 g_replay_start_p1_score_billions;
extern s32 g_replay_start_p1_score;
extern u16 g_replay_start_p1_score_digits;
extern u8 g_replay_watch_after_run;
extern u8 D_006A4C00[];


void replay_loaded_file_adopt(void) {
    extern void replay_file_pointers_decode(void *data);
    s32 count;
    s32 i;
    SaveBody *data;

    count = 0;
    for (i = 0; i < 6; i++) {
        if (g_loaded_replay_id_0_as_u8_a8[i] == g_replay_file_loaded[0x38 + i]) {
            count++;
        }
    }
    if (count == 6) {
        data = (SaveBody *)D_006A4C00;
        delta_encode((u8 *)data);
        replay_file_pointers_decode(g_replay_file_loaded);
        printf("sco1up  [%x] -> [%x]\n", g_replay_start_p1_score, data->score1);
        printf("sco1cnt [%x] -> [%x]\n", g_replay_start_p1_score_digits, data->count1);
        printf("sco1oku [%x] -> [%x]\n", g_replay_start_p1_score_billions, data->stage1);
        printf("sco2up  [%x] -> [%x]\n", g_replay_start_p2_score, data->score2);
        printf("sco2cnt [%x] -> [%x]\n", g_replay_start_p2_score_digits, data->count2);
        printf("sco2oku [%x] -> [%x]\n", g_replay_start_p2_score_billions, data->stage2);
        if (g_replay_start_p1_score_digits == data->count1 && g_replay_start_p1_score == data->score1 &&
            g_replay_start_p1_score_billions == data->stage1 && g_replay_start_p2_score_digits == data->count2 &&
            g_replay_start_p2_score == data->score2 && g_replay_start_p2_score_billions == data->stage2) {
            memcpy(g_replay_file, g_replay_file_loaded, 0x202E8);
            g_replay_watch_after_run = 1;
        }
    }
}

s32 mc_replay_autosave_begin();
extern u8 g_stage_jump_state;
extern u8 g_replay_save_prompt_active;
extern s32 g_replay_save_prompt_step;
extern s32 g_mc_load_succeeded;
extern s32 g_mc_operation_done;

s32 replay_save_prompt_update_card(void) {
    switch (g_replay_save_prompt_step) {                           /* irregular */
    case 0:
        g_replay_save_prompt_active = 1;
        g_mc_operation_done = 0;
        g_replay_save_prompt_step += 1;
        g_replay_watch_after_run = 0;
        g_stage_jump_state = 0xFF;
        /* fallthrough */
    case 1:
        mc_replay_autosave_begin();
        if (g_mc_operation_done != 0) {
            g_mc_operation_done = 0;
            g_replay_save_prompt_step = 0;
            g_replay_save_prompt_active = 0;
            if (g_mc_load_succeeded != 0) {
                replay_loaded_file_adopt();
            }
            return 1;
        }
    default:
        return 0;
    }
}

u8 replay_slot_infos_next();
extern u8 replay_save_prompt_update_disc_state;

s32 replay_save_prompt_update_disc(void) {
    switch (g_replay_save_prompt_step) {
    case 0:
        g_replay_save_prompt_active = 1;
        g_replay_watch_after_run = 0;
        g_replay_save_prompt_step += 1;
        g_stage_jump_state = 0xFF;
        /* fallthrough */
    case 1:
        replay_save_prompt_update_disc_state = replay_slot_infos_next();
        if (replay_save_prompt_update_disc_state == 0xFF) {
            g_replay_save_prompt_step = 3;
        } else {
            replay_save_prompt_update_disc_state -= 1;
            g_replay_save_prompt_step += 1;
        }
        break;
    case 2:
        if (replay_disc_file_load(replay_save_prompt_update_disc_state) != 0) {
            g_replay_save_prompt_step += 1;
            replay_loaded_file_adopt();
        }
        break;
    case 3:
        g_replay_save_prompt_step = 0;
        g_replay_save_prompt_active = 0;
        return 1;
    }
    return 0;
}

extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_p2_score_billions;
extern u16 g_p1_score_billions;
extern u32 g_p2_score;
extern u32 g_p1_score;

void replay_scores_snapshot(void) {
    g_replay_start_p1_score_digits = g_p1_score_digits;
    g_replay_start_p1_score = (s32)g_p1_score;
    g_replay_start_p1_score_billions = g_p1_score_billions;
    g_replay_start_p2_score_digits = g_p2_score_digits;
    g_replay_start_p2_score = (s32)g_p2_score;
    g_replay_start_p2_score_billions = g_p2_score_billions;
}

extern void replay_file_pointers_encode(void *data);
extern u8 g_session_date[8];
extern u8 g_replay_file_finalized;
extern s32 g_menu_left_panel_alpha;

s32 replay_file_finalize(void) {
    u8 *save = g_replay_file;
    s32 state;

    switch (state = g_replay_save_prompt_step) {
    default:
        g_replay_save_prompt_step = state + 1;
        break;
    case 0:
        save[0x38] = g_session_date[0];
        save[0x39] = g_session_date[1];
        save[0x3A] = g_session_date[2];
        save[0x3B] = g_session_date[3];
        save[0x3C] = g_session_date[4];
        save[0x3D] = g_session_date[5];
        save[0x3E] = g_session_date[6];
        save[0x3F] = g_session_date[7];
        g_stage_jump_state = 0xFF;
        g_replay_save_prompt_active = 1;
        g_replay_file_finalized = 0;
        memcpy(g_replay_file_loaded, save, 0x202E8);
        replay_file_pointers_encode(g_replay_file_loaded);
        delta_decode((s32)D_006A4C00);
        replay_slots_reset();
        replay_slots_open(1, 2, 0);
        g_menu_alpha = 0;
        g_menu_fade_state = 1;
        g_menu_left_panel_alpha = 0;
        g_replay_save_prompt_step++;
        break;
    case 1:
        if (replay_slots_update() == 0) {
            g_replay_save_prompt_step++;
            g_menu_fade_state = 2;
        }
        break;
    case 0x11:
        g_replay_save_prompt_step = 0;
        g_replay_file_finalized = 1;
        g_replay_save_prompt_active = 0;
        return 1;
    }
    return 0;
}

void delta_decode(s32 arg0) {
    s32 var_v1;
    s8 *temp_a1;
    s8 *temp_t0_2;
    u8 temp_a3;
    u8 temp_t0;

    var_v1 = 1;
    do {
        temp_a1 = (s8 *)(arg0 + var_v1);
        temp_t0 = (*(s8 *)((u8 *)(temp_a1) + (0)));
        var_v1 += 8;
        (*(s8 *)((u8 *)(temp_a1) + (0))) = temp_t0 + (*(s8 *)((u8 *)(temp_a1) + (-1)));
        (*(s8 *)((u8 *)(temp_a1) + (1))) += (*(s8 *)((u8 *)(temp_a1) + (0)));
        (*(s8 *)((u8 *)(temp_a1) + (2))) += (*(s8 *)((u8 *)(temp_a1) + (1)));
        (*(s8 *)((u8 *)(temp_a1) + (3))) += (*(s8 *)((u8 *)(temp_a1) + (2)));
        (*(s8 *)((u8 *)(temp_a1) + (4))) += (*(s8 *)((u8 *)(temp_a1) + (3)));
        (*(s8 *)((u8 *)(temp_a1) + (5))) += (*(s8 *)((u8 *)(temp_a1) + (4)));
        (*(s8 *)((u8 *)(temp_a1) + (6))) += (*(s8 *)((u8 *)(temp_a1) + (5)));
        (*(s8 *)((u8 *)(temp_a1) + (7))) += (*(s8 *)((u8 *)(temp_a1) + (6)));
    } while (var_v1 < 0x552B);
    if (var_v1 < 0x5533) {
        do {
            temp_t0_2 = (s8 *)(arg0 + var_v1);
            temp_a3 = (*(s8 *)((u8 *)(temp_t0_2) + (0)));
            var_v1 += 1;
            (*(s8 *)((u8 *)(temp_t0_2) + (0))) = temp_a3 + (*(s8 *)((u8 *)(temp_t0_2) + (-1)));
        } while (var_v1 < 0x5533);
    }
}

extern u8 g_replay_mode;

void replay_save_prompt_draw(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    if (g_replay_save_prompt_step != 0) {
        save_d0 = reg_d0.w;
        save_d1 = reg_d1.w;
        save_d2 = reg_d2.w;
        save_d3 = reg_d3.w;
        save_d4 = reg_d4.w;
        save_d5 = reg_d5.w;
        save_d6 = reg_d6.w;
        save_d7 = reg_d7.w;
        save_a0 = reg_a0;
        save_a1 = reg_a1;
        save_a2 = reg_a2;
        save_a3 = reg_a3;
        save_a4 = reg_a4;
        save_a5 = reg_a5;
        save_a6 = reg_a6;
        glyph_queue_clear();
        switch (g_menu_fade_state) {
        case 0:
            break;
        case 1:
            g_menu_alpha += 8;
            if (g_menu_alpha >= 0x80) {
                g_menu_fade_state = 0;
                g_menu_alpha = 0x80;
            }
            break;
        case 2:
            g_menu_alpha -= 8;
            if (g_menu_alpha <= 0) {
                g_menu_alpha = 0;
                g_menu_fade_state = 0;
            }
            break;
        }
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, g_menu_alpha / 2, 1, 1, 1);
        if (g_replay_mode == 1) {
            replay_save_prompt_text_draw();
            replay_slots_draw();
        }
        glyph_queue_flush();
        reg_d0.w = save_d0;
        reg_d1.w = save_d1;
        reg_d2.w = save_d2;
        reg_d3.w = save_d3;
        reg_d4.w = save_d4;
        reg_d5.w = save_d5;
        reg_d6.w = save_d6;
        reg_d7.w = save_d7;
        reg_a0 = save_a0;
        reg_a1 = save_a1;
        reg_a2 = save_a2;
        reg_a3 = save_a3;
        reg_a4 = save_a4;
        reg_a5 = save_a5;
        reg_a6 = save_a6;
    }
}


void replay_save_prompt_text_draw(void) {
    s32 text_queue_clear();
    s32 text_flush();
    void gfx_draw_color_box(s32 a, s32 b, s32 c, s32 d, s32 e, s32 alpha, s32 g, s32 h, s32 i);
    s32 var_s0;

    if (g_menu_alpha != 0) {
        text_queue_clear();
        var_s0 = g_menu_alpha;
        if (g_menu_alpha >= 0x40) {
            var_s0 = 0x40;
        }
        if (var_s0 != 0) {
            frame_draw_left_panel(g_menu_alpha);
            gfx_draw_color_box(0xC, 8, 0x40, 0xD0, 0x12C, var_s0, 1, 1, 0x40);
        }
        if (((u8)g_replay_slots_state != 0) && ((u32) ((u8)g_replay_slots_state - 1) > 1U) && ((u32) ((u8)g_replay_slots_state - 5) > 1U)) {
            reg_a0 = (u8 *)(*(s32 *)&g_menu_save_file_help);
            menu_message_draw(0x36, 8);
        }
        text_flush();
    }
}

s32 replay_snapshot_checksum(const u8 *data)
{
    s32 checksum = 0;
    s32 offset = 0;
    const u8 *block;

    do {
        block = data + offset;
        offset += 8;
        checksum += block[0] + block[1] + block[2] + block[3]
                  + block[4] + block[5] + block[6] + block[7];
    } while (offset < 0x5530);

    return checksum;
}


s32 sceCdReadClock(CdClock *clock);

#define FROM_BCD(x) (((x) & 0xF) + ((x) >> 4) * 10)

s32 clock_read(u8 *out)
{
    CdClock clock;

    if (sceCdReadClock(&clock) != 0) {
        out[0] = FROM_BCD(clock.month);
        out[1] = FROM_BCD(clock.day);
        out[2] = FROM_BCD(clock.hour);
        out[3] = FROM_BCD(clock.minute);
        out[4] = FROM_BCD(clock.second);
        return 0;
    }
    return clock.stat;
}


extern u8 g_replay_file_headers[672];

s32 replay_disc_headers_load(void) {
    s32 i;

    replay_slot_infos_clear();
    for (i = 0; i < 10; i++) {
        *(Row *)((s16 (*)[512])g_replay_slot_infos)[i] = ((Row *)g_replay_file_headers)[i];
    }
    return 1;
}

s32 music_stop();
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern u8 *g_replay_disc_load_buf;
extern u8 g_replay_disc_load_slot;
extern u8 g_replay_disc_load_step;
extern u8 g_load_buf[];
s32 replay_disc_file_load(u8 arg0) {
    u32 state;

    state = g_replay_disc_load_step;
    switch (state) {
    case 0:
        g_replay_disc_load_slot = arg0;
        g_replay_disc_load_step = state + 1;
        g_replay_disc_load_buf = g_load_buf;
        music_stop();
        printf("repdat load start\n");
        break;
    case 1:
        if (g_cd_async_busy != 0) {
            g_cd_async_busy = 1;
            g_replay_disc_load_step = state + 1;
            g_cd_async_state = 0;
        }
        break;
    case 2:
        cd_read_async(g_replay_disc_load_buf, g_replay_files[g_replay_disc_load_slot].size, g_replay_files[g_replay_disc_load_slot].lba);
        if (g_cd_async_busy == 0) {
#ifndef DEATH_LABEL
            g_cd_async_busy = 1;
            g_cd_async_state = 0;
#endif
            g_replay_disc_load_step = 0;
            memcpy(g_replay_file_loaded, g_replay_disc_load_buf, 0x202E8);
            printf("repdat load end\n");
            return 1;
        }
        break;
    }
    return 0;
}


void simulation_task(void) {
    u8 temp_a0;

    temp_a0 = *(u8 *)(reg_a5 + 3);
    switch (temp_a0) {                              /* irregular */
    case 0:
        simulation_task_begin(temp_a0);
        break;
    case 1:
        simulation_task_run(temp_a0);
        break;
    case 2:
        task_stop_self_entry(temp_a0);
        break;
    }
}

extern void text_layer_clear(void);
extern void stage_doors_clear(void);
extern void text_palette_load(void);
extern void task_start(void);
extern u8 g_default_text_palette[];
extern u8 D_0028DE40[];
extern u8 D_0028DE44[];
extern u8 g_game_mode;
extern u8 g_game_frame_ran;
extern s8 g_bomb_panel_seen;
extern u8 D_0028E7B4;
extern u16 D_00684C80[];
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
extern u8 death_D_00290DBC;
extern u8 g_death_boss_form;
extern u8 death_D_00290850;
extern u32 death_D_00290DB8;
extern u32 death_D_00290DB4;
extern u16 g_p1_max_hits;
extern u16 g_p2_max_hits;
extern u16 g_loop;
#endif

void simulation_task_begin() {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
#ifdef DEATH_LABEL
    g_game_mode = 2;
    g_loop = 0;
    D_00684C80[6] = 0;
    D_00684C80[4] = 3;
    D_00684C80[5] = 1;
    D_00684C80[7] = 0;
    D_00684C80[8] = 3;
    if (death_D_00290DC0 == 0) {
        if (D_00684C80[9] == 2) {
            D_00684C80[7] = 3;
        }
        if (D_00684C80[9] == 4) {
            D_00684C80[7] = 0;
        }
        if (D_00684C80[9] == 6) {
            D_00684C80[7] = 1;
        }
    } else {
        D_00684C80[7] = 3;
    }
    D_00684C80[10] = 0;
    g_death_boss_form = 0;
    death_D_00290850 = 0;
    death_D_00290DBC = 0;
    g_game_frame_ran = 0;
    g_bomb_panel_seen = 0;
    g_replay_file_finalized = 0;
    if (death_D_00290DC0 != 0) {
        replay_scores_snapshot();
        reg_d0.h[0] = 10;
        death_D_00290DB8 = g_p1_max_hits;
        death_D_00290DB4 = g_p2_max_hits;
        task_start();
        *(u16 *)(reg_a0 + 4) = D_00684C80[6];
    }
    stage_doors_clear();
    printf("death round[%d]\n", death_D_00290DC0);
#else
    g_game_mode = 2;
    D_00684C80[0] = 0xFF;
    D_00684C80[1] = 0xFF;
    D_00684C80[2] = 0xFF;
    D_00684C80[3] = 0xFF;
    if (D_0028E7B4 & 1) {
        D_00684C80[0] = D_0028DE40[0];
        D_00684C80[1] = D_0028DE44[0];
    } else {
        D_00684C80[2] = D_0028DE40[0];
        D_00684C80[3] = D_0028DE44[0];
    }
    D_00684C80[6] = 0;
    D_00684C80[4] = 3;
    g_game_frame_ran = 0;
    g_bomb_panel_seen = 0;
    D_00684C80[5] = 1;
    D_00684C80[8] = 3;
    reg_d0.h[0] = 10;
    D_00684C80[7] = 0;
    g_replay_file_finalized = 0;
    D_00684C80[10] = 0;
    task_start();
    *(u16 *)(reg_a0 + 4) = D_00684C80[6];
    stage_doors_clear();
#endif
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)g_default_text_palette;
    text_palette_load();
    *(u8 *)(reg_a5 + 3) = 1;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

extern void task_stop_self(void);

void task_stop_self_entry() {
    task_stop_self();
}


s32 frame_counters_reset();
s32 enemies_resume();
s32 stage_doors_open_request();
s32 stage_doors_open_requested_check();
s32 stage_doors_update();
s32 music_play_bgm2();
extern u8 g_pad_input_locked;
extern u8 g_start_rule_death;
extern u8 g_simulation_boss_start;
extern u8 g_start_rule_rank;
extern u8 g_no_enemy_bullets;
extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u8 g_setting_difficulty;
extern u16 g_score_panel_intro;
extern u16 g_loop;
extern u8 D_00684C88[];
extern u16 D_00684C8A[];
extern u16 D_00684C8C[];
extern u8 D_00684C8E[];
extern u8 simulation_task_run_buffer[];
extern u16 D_00684C94[];
#ifdef DEATH_LABEL
s32 fade_reset();
extern u8 death_D_00290DC0;
extern u8 death_D_00290DBC;
extern u32 death_D_00290DB8;
extern u32 death_D_00290DB4;
extern u16 g_p1_max_hits;
extern u16 g_p2_max_hits;
#endif

void simulation_task_run() {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    stage_doors_update();
    switch (D_00684C94[0]) {                           /* irregular */
    default:
        D_00684C94[0] += 1;
        break;
    case 0:
        stage_doors_open_request();
        D_00684C94[0] += 1;
        break;
#ifdef DEATH_LABEL
    case 2:
        fade_reset();
        D_00684C94[0] += 1;
        break;
#endif
    case 16:
        g_simulation_boss_start = 1;
        g_no_enemy_bullets = 0;
        g_start_rule_rank = 0xFF;
        g_start_rule_death = 0;
        g_setting_difficulty = D_00684C88[0];
        g_setting_extend = simulation_task_run_buffer[0];
        g_setting_ship_stock = D_00684C8E[0];
        simulation_ships_start(D_00684C88[0]);
        g_pad_input_locked = 1;
#ifdef DEATH_LABEL
        if (death_D_00290DC0 != 0) {
            death_D_00290DBC = 1;
            g_p1_max_hits = (*(u16 *)&death_D_00290DB8);
            g_p2_max_hits = (*(u16 *)&death_D_00290DB4);
        }
#endif
        D_00684C94[0] += 1;
        break;
#ifdef DEATH_LABEL
    case 17:
        death_D_00290DBC = 0;
        D_00684C94[0] += 1;
        break;
#endif
    case MAIN_OR_DEATH_LABEL(17, 18):
        if (g_score_panel_intro == 0) {
            D_00684C94[0] += 1;
        }
        break;
    case MAIN_OR_DEATH_LABEL(18, 19):
        frame_counters_reset();
        if (g_game_frame_ran != 0) {
            g_pad_input_locked = 0;
            D_00684C94[0] += 1;
            g_loop = D_00684C8A[0];
            enemies_resume();
#ifdef DEATH_LABEL
            fade_reset();
#endif
            if (D_00684C8C[0] == 0) {
                music_play_bgm2();
            }
        }
        break;
    case MAIN_OR_DEATH_LABEL(19, 20):
        stage_doors_open_requested_check();
        if (cond_flag == 0) {
            *(s8 *)(reg_a5 + 3) = 2;
        }
        break;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
}

extern void ship_select_apply(void);

void simulation_ships_start() {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;

    save_d0 = reg_d0.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_d1 = reg_d1.w;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_d2 = reg_d2.w;
    save_a4 = reg_a4;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_a5 = reg_a5;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.h[0] = D_00684C80[0];
    reg_d1.h[0] = D_00684C80[1];
    reg_d2.w = 0;
    g_game_frame_ran = 0;
    reg_d3.w = 0;
    reg_d4.w = 1;
    reg_d2.h[0] = D_00684C80[2];
    reg_d3.h[0] = D_00684C80[3];
    ship_select_apply();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
}

/* .bss (the compiler lays these out in reverse) */
u8 g_replay_file_headers[672];
s16 D_0068DF00[8];
s16 D_0068DEE0[16];
s32 D_0068DEB0[12];
s32 D_0068DEA0[4];
s32 D_0068DE90[4];
#ifdef DEATH_LABEL
s8 menu_death_option_adjust_buffer[272];
#endif
#ifdef DEATH_LABEL
u8 g_menu_value_p2_btn_d[112];
#else
u8 g_menu_value_p2_btn_d[384];
#endif
s8 D_0068DD00[16];
s8 menu_arcade_adjust_buffer[16];
s8 menu_debug_option_adjust_buffer[176];
s8 menu_save_load_adjust_buffer[16];
s8 menu_game_option_adjust_buffer[16];
s8 D_0068DC10[16];
MenuItem g_menu_items[40][MENU_ITEMS_PER_PAGE];
s32 D_00684CF0[10][4][5];
u8 D_00684CA0[80];
u8 simulation_task_run_buffer[16];
u16 D_00684C80[8];
