#include "common.h"
#include "task.h"
#include "sdk/ps2sdk.h"
#include "pad.h"
#include "gfx_types.h"
#include "cd.h"

typedef struct {
    s32 x;
    s32 y;
    u8 pad08[0x24];
    s32 alpha;
    s32 z;
    s32 active;
} Label;

typedef struct {
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 fx;
    s32 fy;
    s32 vx;
    s32 vy;
    s32 dx;
    s32 dy;
    s32 timer;
    s32 step;
    s32 id;
    s32 active;
} MoveItem;

typedef struct {
    s16 x;
    s16 y;
} Point16;

typedef struct {
    s32 x;
    s32 y;
    s32 targetX;
    s32 targetY;
    s32 posX;
    s32 posY;
    s32 speedX;
    s32 speedY;
    s32 accelX;
    s32 accelY;
    s32 delay;
    u8 pad[0xC];
} Mover;

typedef struct {
    s32 a;
    s32 b;
} Pair;

typedef struct {
    s16 x;
    s16 y;
} Point;

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
    s8 flag;
    s8 pad3;
    s16 value;
    s16 pad6;
} Fade;

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

typedef struct {
    s32 image;
    u16 *palette;
} Wallpaper;

/* Tables. */
extern u8 D_002620F0[];
extern u8 D_00262130[];
extern u8 D_00262170[];
extern u8 D_002621B0[];
extern u8 D_002621F0[];
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
extern char *D_00271348[3];
extern char *D_00271360[10];
extern char *D_00271390[16];
extern char *D_002713D0[5];
extern char *D_002713F0[5];
#ifdef DEATH_LABEL
extern char *D_00271410[10];
#else
extern char *D_00271410[9];
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
extern s8 D_0028DD10[8];
extern char *D_0028DD18[2];
extern s8 D_0028DD20[8];
extern char *D_0028DD28[2];
extern char *D_0028DD30[2];
extern char *D_0028DD38[2];
extern char *D_0028DD40[2];
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
extern char *death_D_00262FF0[4];
#endif
extern char *g_menu_difficulty_names[4];
extern char *g_menu_ship_stock_names[5];
extern char *g_menu_extend_names[4][2];
extern s8 D_00271690[16];
extern s8 D_002716A0[16];
extern char *g_menu_monitor_mode_names[4];
extern char *D_002716C0[6];
extern char *g_menu_monitor_mode_tate_names[2];
extern char *g_menu_lever_set_names[2];
extern char *g_menu_monitor_type_names[2];
extern char *D_0028DD60[2];
extern char *g_menu_original_arrange_names[2];
#ifdef DEATH_LABEL
extern s8 death_D_00290048[8];
#endif
#ifdef DEATH_LABEL
extern char *death_D_00290050[2];
#endif
extern char *g_menu_round_names[10];
#ifdef DEATH_LABEL
extern char *death_D_002630C8[3];
#endif
extern char *g_menu_pause_items[10];
extern char *D_00271740[6];
extern s16 g_menu_item_positions_a[32];
extern s16 g_menu_item_positions_b[16][2];
extern s16 g_menu_item_positions_c[16];
extern s16 D_00271800[136];
extern s32 D_00271910[64];
extern u16 D_00271A10[8];
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
extern char *death_D_002634D0[4];
#endif
extern char *g_menu_ranking_help;
#ifndef DEATH_LABEL
extern char *g_menu_launch_ask[3];
#endif
#ifndef DEATH_LABEL
extern char *g_menu_launch_warning[3];
#endif
#ifdef DEATH_LABEL
extern char *death_D_00290078[2];
#endif
#ifdef DEATH_LABEL
extern char *death_D_00290080[2];
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
extern s16 D_00271C90[8];
#else
extern s16 D_00271C90[24];
#endif
#ifdef DEATH_LABEL
extern u16 death_D_00263620[16];
#endif
extern char *g_menu_confirm_cancel_text;
extern char *g_menu_cancel_text;
extern s8 D_0028DD9C[4];
extern s8 D_0028DDA0[2];
extern char g_menu_arrow_text[2][2];
extern char *g_menu_result_items[3];
extern char *g_menu_result_help[3];
extern s16 g_menu_result_positions[16];
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

char *D_00271348[3] = {
    "1",
    "2",
    "3",
};

char *D_00271360[10] = {
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

char *D_00271390[16] = {
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

char *D_002713D0[5] = {
    "0",
    "1",
    "2",
    "3",
    "4",
};

char *D_002713F0[5] = {
    "0",
    "1",
    "2",
    "3",
    "4",
};

#ifdef DEATH_LABEL
char *D_00271410[10] = {
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
char *D_00271410[9] = {
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
    D_00271348,
    D_00271360,
    D_00271390,
    D_002713D0,
    D_002713F0,
    D_00271410,
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

s8 D_0028DD10[8] = {
    0, 4, 5, 4, 2, 0, 0, 0,
};

char *D_0028DD18[2] = {
    "OFF",
    "ON",
};

#ifdef DEATH_LABEL
s8 D_0028DD20[8] = {
    0, 2, 2, 2, 2, 100, 2, 0,
};
#else
s8 D_0028DD20[8] = {
    0, 2, 2, 2, 2, 2, 0, 0,
};
#endif

char *D_0028DD28[2] = {
    "1",
    "2",
};

char *D_0028DD30[2] = {
    "OFF",
    "ON",
};

char *D_0028DD38[2] = {
    "ON",
    "OFF",
};

char *D_0028DD40[2] = {
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
char *death_D_00262FF0[4] = {
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

s8 D_00271690[16] = {
    0, 2, 4, 2, 6, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

s8 D_002716A0[16] = {
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

char *D_002716C0[6] = {
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
s8 death_D_00290048[8] = {
    0, 2, 3, 0, 0, 0, 0, 0,
};

char *death_D_00290050[2] = {
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
char *death_D_002630C8[3] = {
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

char *D_00271740[6] = {
    "1",
    "2",
    "3",
    "4",
    "5",
    "OFF",
};

s16 g_menu_item_positions_a[32] = {
    0x18c, 8, 0x164, 8, 0x14c, 8, 0x134, 8,
    0x11c, 8, 0x104, 8, 0xec, 8, 0xd4, 8,
    0xbc, 8, 0xa4, 8, 0x8c, 8, 0x74, 8,
    0x5c, 8, 0x44, 8, 0x14, 8, -4, 8,
};

s16 g_menu_item_positions_b[16][2] = {
    0x1a4, 8, 0x17c, 8, 0x164, 8, 0x14c, 8,
    0x134, 8, 0x11c, 8, 0x104, 8, 0xec, 8,
    0xd4, 8, 0xbc, 8, 0xa4, 8, 0x8c, 8,
    0x74, 8, 0x5c, 8, 0x2c, 8, 0x14, 8,
};

s16 g_menu_item_positions_c[16] = {
    0x17e, 8, 0x137, 8, 0xf0, 8, 0xa9, 8,
    0x62, 8, 0x62, 8, 0, 0, 0, 0,
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

s32 D_00271910[64] = {
    0x726, 0x763, 0x7a1, 0x7e0, 0x820, 0x861, 0x8a3, 0x8e6,
    0x92a, 0x96f, 0x9b5, 0x9fc, 0xa44, 0xa8d, 0xad7, 0xb22,
    0xb6e, 0xbbb, 0xc09, 0xc58, 0xca8, 0xcf9, 0xd4b, 0xd9e,
    0xdf2, 0xe47, 0xe9d, 0xef4, 0xf4c, 0xfa5, 0xfff, 0x105a,
    0x10b6, 0x1113, 0x1171, 0x11d0, 0x1230, 0x1291, 0x12f3, 0x1356,
    0x13ba, 0x141f, 0x1485, 0x14ec, 0x1554, 0x15bd, 0x1627, 0x1692,
    0x16fe, 0x176b, 0x17d9, 0x1848, 0x18b8, 0x1929, 0x199b, 0x1a0e,
    0x1a82, 0x1af7, 0x1b6d, 0x1be4, 0x1c5c, 0, 0, 0,
};

u16 D_00271A10[8] = {
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
char *death_D_002634D0[4] = {
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
char *death_D_00290078[2] = {
    SJIS("￥"),
    SJIS("怒首領蜂大往生を／起動しますか？￥"),
};

char *death_D_00290080[2] = {
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
    { 0x14b5, (void *)D_002620F0 },
    { 0x14b6, (void *)D_00262130 },
    { 0x14b7, (void *)D_00262170 },
    { 0x14b8, (void *)D_002621B0 },
    { 0x14b9, (void *)D_002621F0 },
};

#ifdef DEATH_LABEL
s16 D_00271C90[8] = {
    0x160, 0x5c, 0x140, 0xc, 0x120, 0xc, 0x100, 0xc,
};
#else
s16 D_00271C90[24] = {
    0x160, 0x5c, 0x140, 0xc, 0x120, 0xc, 0x100, 0xc,
    0xe0, 0xc, 0xc0, 0xc, 0xa0, 0xc, 0x80, 0xc,
    0x60, 0xc, 0x40, 0xc, 0x20, 0xc, 0, 0xc,
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

s8 D_0028DD9C[4] = {
    3, 2, 5, 0,
};

s8 D_0028DDA0[2] = {
    5, 0,
};

char g_menu_arrow_text[2][2] = {
    "<",
    ">",
};

extern Fade D_0028EBE0;
extern Fade D_0028EBE8;
extern Fade D_0028EBF0;
extern Fade D_0028EBF8;

void delta_encode(u8 *buf);
void func_0021D500(void);
void func_0021D570(void);
void func_0021D6C0(void);
void func_0021D850();
void func_0021D8C0(void);
void func_0021D970(void);
void func_0021DA10(void);
void func_0021DA60(void);
void func_0021DAA0(void);
void func_0021DC60(void);
void func_0021DC80(void);
void func_0021DCD0(void);
void func_0021DD40();
void func_0021DD90();
void func_0021DDE0();
void func_0021DF60(void);
void func_0021E000(void);
void func_0021E160(void);
void func_0021E1A0(void);
void func_0021E2D0(void);
void func_0021E300(void);
void func_0021E370();
void func_0021E3C0();
void func_0021E410();
void func_0021E5C0(void);
void func_0021E680(void);
void func_0021E6F0();
void func_0021E740();
void func_0021E790();
void func_0021E8D0(void);
void func_0021EA10(void);
void func_0021EA50(void);
void func_0021EAE0(void);
void func_0021EB30(void);
void func_0021EB80(void);
void func_0021ED50(void);
void func_0021ED70(void);
void func_0021EDC0(void);
void func_0021EE80(void);
void func_0021EF10();
void func_0021EF60();
void func_0021EFB0();
void func_0021F180();
void func_0021F1C0(void);
void func_0021F2C0(void);
void func_0021F440(void);
void func_0021F4E0(void);
void func_0021F560();
void func_0021F5B0();
void func_0021F600();
void func_0021F750();
void death_func_001B7460(void);
void death_func_001B74D0(void);
void death_func_001B7520(void);
void death_func_001B7570(void);
void death_func_001B76A0(void);
void func_0021F7B0(void);
void func_0021F820();
void func_0021F880();
void func_0021F8D0();
void func_0021FA50(void);
void func_0021FC70(void);
void func_0021FDB0(void);
void func_002201A0(void);
void func_00220390(void);
void func_002207C0(void);
void func_002209C0(void);
void func_00221000(void);
void death_func_001B9120(void);
void func_00221080(void);
s32 func_00221120(s32 page);
s32 func_002212C0();
void func_00221360(void);
void func_00221440(void);
void func_00221550(void);
s32 func_00221C20(void);
void func_00221CF0(void);
void func_00221E20(void);
void func_00221FF0();
void func_00222170(void);
void func_00222260(s32 group);
void func_00222340(s32 group);
s32 func_00222530(s32 group);
void func_00222780(void);
void func_002228D0(s32 x, s32 y);
void func_00222C30(s32 x, s32 y, s32 attr);
void func_00222F90(s32 x, s32 y, s32 attr);
void func_002232F0(void);
void func_002234C0(void);
void func_00223550(void);
void func_00223A60(void);
void func_00223AA0(void);
s32 func_00223BE0(void);
void func_00223D70(void);
void func_00223E80(void);
void func_00224020(s32 x, s32 y);
void func_002242B0(s32 x, s32 y);
void func_002244E0(void);
void func_00224A30(void);
void func_00224A90(void);
void func_00224B50(void);
void func_00224BA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags);
void func_00224CC0(void);
void func_00225000(void);
void func_002252E0(void *buffer);
void func_00225450(void);
void func_00225630(void);
void func_00225670(void);
void func_002256B0(void);
void func_002256C0(void);
void func_00225A00(void);
void func_00225AB0(void);
void func_00225B70(void);
void func_00225B90(void);
void func_00225CB0(void);
s8 func_00225CD0(void);
void func_00225E20(void);
void func_00225EF0(void);
void func_002260F0(void);
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
void func_00227120(void);
void func_002271D0(void);
void func_002272D0(void);
static void func_00227310(Fade *fade);
s32 func_00227350(Fade *fade, s32 command);
static s32 func_002273B0(Fade *fade, s32 command);
void func_002273E0(void);
static void func_00227440(Fade *fade);
void func_002274C0(Fade *arg0, u8 **arg1, s32 arg2);
void func_002275C0(void);
void func_002275F0(void);
void func_00227640(void);
void func_00227680(void);
void func_002276C0(void);
void func_00227830(void);
void func_002278D0(void);
void func_00227900(void);
void func_00227930(void);
void func_00227960(void);
void func_002279A0(void);
void func_00227AE0(void);
void func_00227B70(void);
void func_00227C90(void);
void func_00227CD0(void);
void func_00227D00(void);
void func_00227D90(void);
void func_00227E00(void);
void func_00227E30(void);
void func_00227E70(void);
void func_00227F00(void);
void func_00227F70(void);
void func_00227FE0(void);
void func_00228060(void);
void func_00228520(void);
void func_00228550(void);
void func_00228580(void);
void func_00228770(void);
void func_002287E0(void);
void func_002288B0(void);
void func_002288E0(void);
void func_00228910(void);
void func_00228B50(void);
void func_00228BC0(void);
void func_00228E20(void);
void func_00228E50(void);
void func_00228E80(void);
void func_002295F0(void);
void func_00229660(void);
void func_00229950(s32 x, s32 y, s32 alpha, s32 mode, s32 kind);
void func_00229DC0(void);
void func_00229DF0(void);
void func_00229E20(void);
void func_0022A040(void);
void func_0022A0B0(void);
void func_0022A260(void);
void func_0022A2B0(void);
void func_0022A2E0(void);
void func_0022A410(void);
void func_0022A480(void);
void func_0022A870(void);
void func_0022A8F0();
void func_0022A930();
void func_0022A9A0();
void func_0022AA00();
void func_0022AA20(void);
void func_0022AD20(s32 arg0, s32 arg1);
void func_0022B1D0(void);
void func_0022B2F0(void);
void func_0022B330(void);
s32 func_0022B4B0(void);
s32 func_0022B540(void);
void func_0022B620(void);
s32 func_0022B660(void);
void func_0022B7A0(s32 arg0);
void func_0022B870(void);
void func_0022BA60(void);
s32 replay_snapshot_checksum(const u8 *data);
s32 func_0022BB80(u8 *out);
s32 replay_disc_headers_load(void);
s32 replay_disc_file_load(u8 arg0);
void func_0022BF60(void);
void func_0022BFD0();
void task_stop_self_entry();
void func_0022C1F0();
void func_0022C450();

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

void func_0021D500(void) {
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

extern s8 D_0028EB88;

void func_0021D570(void) {
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
    switch (D_0028EB88) {                           /* irregular */
    case 0:
        func_00221FF0(2, D_0028EB88);
        /* fallthrough */
    case 1:
        func_0021D6C0();
        break;
    case 2:
        func_0021D850(2, D_0028EB88);
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

void func_0021D6C0(void) {
    switch (g_menu_page) {
    case 0:
        func_0021D970();
        break;
    case 1:
        func_0021DCD0();
        break;
    case 2:
        func_0021E300();
        break;
    case 3:
        func_0021E680();
        break;
    case 5:
        func_00225A00();
        break;
    case 6:
        func_00225AB0();
        break;
    case 7:
        func_00227830();
        break;
    case 10:
        func_00227AE0();
        break;
    case 11:
        func_00227D90();
        break;
    case 8:
        func_00228770();
        break;
    case 13:
        func_0022A410();
        break;
    case 14:
        func_0021EA50();
        break;
    case 15:
        func_0021EE80();
        break;
    case 16:
        func_00225000();
        break;
    case 21:
        func_0021F4E0();
        break;
#ifdef DEATH_LABEL
    case 23:
        death_func_001B7460();
        break;
#endif
    case 24:
        func_0021F7B0();
        break;
    case 17:
        func_00228B50();
        break;
    case 18:
        func_002295F0();
        break;
    case 19:
        func_0022A040();
        break;
    case 20:
        func_00227F70();
        break;
    case 22:
        func_00227F00();
        break;
    }
}

extern s8 g_fade_state;
extern s8 D_0028EB00;

void func_0021D850() {
    if (g_fade_state == 0) {
        D_0028EB88 = 0;
        if (D_0028EB00 == 2) {
            D_0028EB00 = 0x14;
        } else if (D_0028EB00 == 3) {
            D_0028EB00 = 0x1E;
        } else if (D_0028EB00 == 4) {
            D_0028EB00 = 0x28;
        } else {
            D_0028EB00 = 0xA;
        }
    }
}

extern s32 D_0068DE90[];
extern s32 D_0068DEA0[];
extern s32 D_0068DEB0[];
extern s32 D_0068DEC8_as_s32_a[];
extern s32 D_0068DED8_as_s32_a[];
extern s32 D_0068DEF0_as_s32_a[];

void func_0021D8C0(void) {
    memcpy(D_0068DEF0_as_s32_a, D_00270810, 0x16);
    memcpy(D_0068DED8_as_s32_a, D_00270828, 0xA);
    memcpy(D_0068DEC8_as_s32_a, D_00270838, 0xC);
    memcpy(D_0068DEB0, D_00270810, 0x16);
    memcpy(D_0068DE90, D_00270828, 0xA);
    memcpy(D_0068DEA0, D_00270838, 0xC);
}

extern s8 g_menu_step;

void func_0021D970(void) {
    switch (g_menu_step) {
    case 0:
        func_0021DA10();
        break;
    case 1:
        func_0021DA60();
        break;
    case 2:
        func_0021DAA0();
        break;
    case 3:
        func_0021DC60();
        break;
    case 4:
        func_0021DC80();
        break;
    }
}

extern s16 D_0028E320;
extern s8 D_0028E368_as_s8;
extern s8 D_0028EB4C;
extern s8 D_0028EB80;
extern s32 D_0028EBB4;

void func_0021DA10(void) {
    D_0028E368_as_s8 = 0;
    D_0028EBB4 = 0;
    D_0028EB80 = 0;
    g_menu_step += 1;
    func_00222340(0);
    D_0028EB4C = 1;
    D_0028E320 = 0xE10;
}

extern s8 D_0028EB04;
extern s8 D_0028EB28;
extern s8 D_0028EB54;
extern s8 g_menu_cursor;

void func_0021DA60(void) {
    if (func_00222530(0) != 0) {
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        g_menu_step += 1;
        g_menu_cursor = D_0028EB28;
    }
}

extern u16 D_0028E320_as_u16;
extern s8 D_0028EAE8;
extern s8 D_0028EB08;
extern s8 D_0028EB0C;
extern s8 D_0028EB14;
extern s8 D_0028EB18;
extern s8 D_0028EB1C;
extern s8 D_0028EB20;
extern s8 g_menu_box_alpha;
extern s8 D_0028EB5C;
extern s8 D_0028EB60;
extern s8 D_0028EB68;
extern s8 D_0028EB6C;
extern s8 D_0028EB70;
extern s8 D_0028EB74;
extern s8 D_0028EC18_as_s8;
extern s8 D_0028EC1A;
extern s8 g_menu_pad;
#ifdef DEATH_LABEL
extern s8 g_game_mode_as_s8;
extern s8 D_0028E2E4_as_s8;
extern s8 D_0028E304_as_s8;
extern s32 D_0028EAFC;
extern s8 D_0028EB00;
s32 func_00169BC0();
#endif

void func_0021DAA0(void) {
    s32 sfx_menu_confirm();
    s32 fade_start_out();
    s32 var_a1;

    func_00221120(0);
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            g_menu_cursor = MAIN_OR_DEATH_LABEL(8, 5);
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        g_menu_cursor = MAIN_OR_DEATH_LABEL(8, 5);
    } else if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB28 = g_menu_cursor;
    if (var_a1 != 0) {
        D_0028EB4C = 2;
        D_0028EB54 = 2;
        sfx_menu_confirm();
        g_menu_box_alpha = 0;
        D_0028EB54 = 0;
#ifdef DEATH_LABEL
        switch (g_menu_cursor) {
        case 0:
            break;
        case 1:
            D_0028E2E4_as_s8 = 0;
            g_game_mode_as_s8 = 2;
            D_0028E304_as_s8 = 1;
            D_0028EAFC = 0xFF;
            func_00169BC0();
            fade_start_out();
            D_0028EB88 = 2;
            D_0028EB00 = 4;
            break;
        case 2:
            D_0028EB5C = 0;
            g_menu_page = 0x18;
            D_0028EB08 = 0;
            break;
        case 3:
            D_0028EB68 = 0;
            g_menu_page = 0xF;
            D_0028EB14 = 0;
            break;
        case 4:
            D_0028EB74 = 0;
            g_menu_page = 2;
            D_0028EB20 = 0;
            break;
        case 6:
            D_0028EB70 = 0;
            g_menu_page = 3;
            D_0028EB1C = 0;
            break;
        case 5:
            D_0028EB60 = 0;
            g_menu_page = 0x15;
            D_0028EB0C = 0;
            D_0028EAE8 = 1;
            break;
        }
#else
        switch (g_menu_cursor) {
        case 0:
            break;
        case 1:
            D_0028EB6C = 0;
            g_menu_page = 0xE;
            D_0028EB18 = 0;
            break;
        case 3:
            D_0028EB60 = 0;
            g_menu_page = 0x15;
            D_0028EB0C = 0;
            D_0028EAE8 = 2;
            break;
        case 4:
            D_0028EB60 = 0;
            g_menu_page = 0x15;
            D_0028EB0C = 0;
            D_0028EAE8 = 1;
            break;
        case 5:
            D_0028EB5C = 0;
            g_menu_page = 0x18;
            D_0028EB08 = 0;
            break;
        case 6:
            D_0028EB68 = 0;
            g_menu_page = 0xF;
            D_0028EB14 = 0;
            break;
        case 7:
            D_0028EB74 = 0;
            g_menu_page = 2;
            D_0028EB20 = 0;
            break;
        case 2:
            g_menu_page = 7;
            D_0028EC18_as_s8 = 0xA;
            D_0028EC1A = 0;
            if (g_pad_trigger[0] & 0x20) {
                g_menu_pad = 0;
            } else {
                g_menu_pad = 1;
            }
            break;
        case 9:
            D_0028EB70 = 0;
            g_menu_page = 3;
            D_0028EB1C = 0;
            break;
        case 8:
            fade_start_out();
            D_0028EB88 = 2;
            break;
        }
#endif
    }
}

void func_0021DC60(void) {
    if (D_0028EB4C == 0) {
        D_0028E368_as_s8 = 0;
        g_menu_step = 4;
    }
}

#pragma push
#pragma opt_propagation off
extern s32 func_002365A0(void);

void func_0021DC80(void) {
    if (func_002365A0() != 0) {
        s8 val = D_0028EB28;
        g_menu_step = 2;
        D_0028EB54 = 1;
        D_0028E320 = 0xE10;
        g_menu_cursor = val;
    }
}
#pragma pop

extern s8 D_0028EB78;

void func_0021DCD0(void) {
    switch (D_0028EB78) {                           /* irregular */
    case 0:
        func_0021DD40(D_0028EB78);
        break;
    case 1:
        func_0021DD90(D_0028EB78);
        break;
    case 2:
        func_0021DDE0(D_0028EB78);
        /* fallthrough */
    case 3:
        break;
    }
}

extern s8 D_0028EB24;
extern s8 D_0028EB48;
extern s32 g_menu_alpha;
extern s32 D_0028EBB0;

void func_0021DD40() {
    D_0028EBB0 = 0;
    D_0028EB78 += 1;
    func_00222340(1);
    g_menu_alpha = 0x40;
    D_0028EB24 = 0;
    D_0028EB48 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}

#pragma push
#pragma opt_propagation off

void func_0021DD90()
{
    if (func_00222530(1) != 0) {
        s32 previousCount = D_0028EB78;

        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB78 = previousCount + 1;
        return;
    }
}
#pragma pop

extern s8 D_0028EB3C;
void func_0021DDE0() {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (func_00221120(1) == 0) {
        func_0021E000();
    }
    func_0021E160();
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            g_menu_cursor = 6;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB24 = g_menu_cursor;
    if ((D_0028EB24 >= 7) && (D_0028EB24 < 0xB)) {
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
            func_0021E2D0();
            func_0021E160();
            break;
        case 6:
            sfx_menu_confirm();
            func_00222260(0xE);
            D_0028EB6C = 3;
            g_menu_page = 0xE;
            g_menu_alpha = 0x40;
            D_0028EB3C = 1;
            D_0028EB54 = 2;
            D_0028EB48 = 2;
            D_0028EB04 = 1;
            D_0028EB78 += 1;
            break;
        }
    }
}

extern s32 g_screen_mode;
extern s8 g_pad_tate_rotate_as_s8;
extern u8 D_0028E354;
extern u8 D_0028E358;
extern s8 D_0068DD01[];

void func_0021DF60(void) {
    s32 value;

    D_0028E358 = D_0068DD01[0];
    if (D_0028E358 == 0) {
        if (D_0028E354 > 3) {
            D_0028E354 = 0;
        }
        value = D_0028DD9C[D_0028E354];
    } else {
        if (D_0028E354 > 1) {
            D_0028E354 = 0;
        }
        value = D_0028DDA0[D_0028E354];
    }
    g_screen_mode = value;
    if (D_0028E358 == 0 && D_0028E354 >= 2) {
        g_pad_tate_rotate_as_s8 = 1;
    } else {
        g_pad_tate_rotate_as_s8 = 0;
    }
}

extern s16 g_pad_vib_power_p2_as_s16;
extern s16 g_pad_vib_power_p1_as_s16;
extern s16 g_pad_vib_timer_p2_as_s16;
extern s16 g_pad_vib_timer_p1_as_s16;
extern u8 g_pad_vib_state_p2;
extern u8 g_pad_vib_state_p1;
extern s8 D_0068DC20[];

void func_0021E000(void) {
    extern void sfx_menu_tick(void);
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = g_menu_cursor;
    if (sel < 5) {
        max = D_0028DD10[sel];
        cur = D_0068DC20[sel];
        pad = g_pad_repeat[2];
        if (pad & 0x2000) {
            sfx_menu_tick();
            cur++;
            if (cur >= max) {
                cur = 0;
            }
            D_0068DC20[g_menu_cursor] = cur;
            if (g_menu_cursor == 4 && cur == 1) {
                if (g_pad_repeat[0] != 0) {
                    g_pad_vib_state_p1 = 1;
                    g_pad_vib_power_p1_as_s16 = 0x78;
                    g_pad_vib_timer_p1_as_s16 = 0x14;
                } else {
                    g_pad_vib_state_p2 = 1;
                    g_pad_vib_power_p2_as_s16 = 0x78;
                    g_pad_vib_timer_p2_as_s16 = 0x14;
                }
            }
        } else if (pad & 0x8000) {
            sfx_menu_tick();
            cur--;
            if (cur < 0) {
                cur = max - 1;
            }
            D_0068DC20[g_menu_cursor] = cur;
            if (g_menu_cursor == 4 && cur == 1) {
                if (g_pad_repeat[0] != 0) {
                    g_pad_vib_state_p1 = 1;
                    g_pad_vib_power_p1_as_s16 = 0x78;
                    g_pad_vib_timer_p1_as_s16 = 0x14;
                } else {
                    g_pad_vib_state_p2 = 1;
                    g_pad_vib_power_p2_as_s16 = 0x78;
                    g_pad_vib_timer_p2_as_s16 = 0x14;
                }
            }
        }
    }
}

extern s8 g_pad_vib_enabled_as_s8;
extern s8 g_setting_ship_stock_as_s8;
extern s8 g_setting_extend_as_s8;
extern s8 g_setting_difficulty_as_s8;
extern s8 D_0068DC21[];
extern s8 D_0068DC22[];
extern s8 D_0068DC23[];
extern s8 D_0068DC24[];

void func_0021E160(void) {
    g_setting_difficulty_as_s8 = D_0068DC21[0];
    g_setting_ship_stock_as_s8 = D_0068DC22[0];
    g_setting_extend_as_s8 = D_0068DC23[0];
    g_pad_vib_enabled_as_s8 = D_0068DC24[0];
}

extern u8 g_p1_btn_map_a_as_u8;
extern u8 g_p1_btn_map_b;
extern u8 g_p1_btn_map_c;
extern u8 D_0028E273;
extern u8 g_p2_btn_map_a;
extern u8 g_p2_btn_map_b;
extern u8 g_p2_btn_map_c;
extern u8 D_0028E277;
extern u8 D_0028E278;
extern u8 g_pad_vib_enabled;
extern u8 g_stage_map_enabled;
extern u8 D_0028E2D8;
extern u8 g_screen_wide;
extern u8 g_bgm_alternate_set;
extern u8 D_0028E2E4;
extern u8 D_0028E2EC;
extern u8 D_0028E304;
extern u8 D_0028E308;
extern u8 D_0028E30C;
extern u8 D_0028E32C_as_u8;
extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u8 g_setting_difficulty;
extern u8 D_0068DC21_as_u8_a[];
extern u8 D_0068DC22_as_u8_a[];
extern u8 D_0068DC23_as_u8_a[];
extern u8 D_0068DC24_as_u8_a[];
extern u8 D_0068DC33[];
extern u8 D_0068DC41_as_u8_a[];
extern u8 D_0068DC42[];
extern u8 D_0068DC43[];
extern u8 D_0068DC44_as_u8_a[];
extern u8 D_0068DC45[];
extern u8 D_0068DCF4[];
extern u8 D_0068DD01_as_u8_a[];
extern u8 D_0068DD02_as_u8_a[];
extern u8 D_0068DD03[];
extern u8 D_0068DD04[];
extern u8 D_0068DD05[];
extern u8 D_0068DD06[];
extern u8 D_0068DD09_as_u8_a[];
extern u8 D_0068DD0A_as_u8_a[];
extern u8 D_0068DD0B_as_u8_a[];
extern u8 D_0068DD0C[];
extern u8 D_0068DD0D_as_u8_a[];
extern u8 D_0068DD0E_as_u8_a[];
extern u8 D_0068DD0F_as_u8_a[];
extern u8 D_0068DD10[];

#ifdef DEATH_LABEL
extern u8 death_D_00290854;
extern u8 death_D_00290858;
extern u8 death_D_00628DC6[];
#endif

void func_0021E1A0(void) {
    D_0068DC21_as_u8_a[0] = g_setting_difficulty;
    D_0068DC22_as_u8_a[0] = g_setting_ship_stock;
    D_0068DC23_as_u8_a[0] = g_setting_extend;
    D_0068DC24_as_u8_a[0] = g_pad_vib_enabled;
    D_0068DC33[0] = D_0028E278;
    D_0068DCF4[0] = D_0028E2D8;
    D_0068DC41_as_u8_a[0] = D_0028E304;
    D_0068DC42[0] = D_0028E30C;
    D_0068DC43[0] = D_0028E308;
    D_0068DC44_as_u8_a[0] = D_0028E2EC;
#ifdef DEATH_LABEL
    D_0068DC45[0] = death_D_00290858;
    death_D_00628DC6[0] = death_D_00290854;
#else
    D_0068DC45[0] = D_0028E2E4;
#endif
    D_0068DD01_as_u8_a[0] = D_0028E358;
    D_0068DD02_as_u8_a[0] = D_0028E354;
    D_0068DD03[0] = g_screen_wide;
    D_0068DD04[0] = D_0028E32C_as_u8;
    D_0068DD05[0] = g_stage_map_enabled;
    D_0068DD06[0] = g_bgm_alternate_set;
    D_0068DD09_as_u8_a[0] = g_p1_btn_map_a_as_u8;
    D_0068DD0A_as_u8_a[0] = g_p1_btn_map_b;
    D_0068DD0B_as_u8_a[0] = g_p1_btn_map_c;
    D_0068DD0C[0] = D_0028E273;
    D_0068DD0D_as_u8_a[0] = g_p2_btn_map_a;
    D_0068DD0E_as_u8_a[0] = g_p2_btn_map_b;
    D_0068DD0F_as_u8_a[0] = g_p2_btn_map_c;
    D_0068DD10[0] = D_0028E277;
}

void func_0021E2D0(void) {
    D_0068DC22[0] = 0;
    D_0068DC23[0] = 0;
    D_0068DC21[0] = 1;
    D_0068DC24[0] = 0;
}


void func_0021E300(void) {
    switch (D_0028EB74) {                           /* irregular */
    case 0:
        func_0021E370(D_0028EB74);
        break;
    case 1:
        func_0021E3C0(D_0028EB74);
        break;
    case 2:
        func_0021E410(D_0028EB74);
        /* fallthrough */
    case 3:
        break;
    }
}

extern s8 D_0028EB44;
extern s32 D_0028EBAC;

void func_0021E370() {
    D_0028EBAC = 0;
    D_0028EB74 += 1;
    func_00222340(2);
    g_menu_alpha = 0x40;
    D_0028EB20 = 0;
    D_0028EB44 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}

#pragma push
#pragma opt_propagation off
void func_0021E3C0()
{
    if (func_00222530(2) != 0) {
        s32 count = D_0028EB74;

        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB74 = count + 1;
    }
}
#pragma pop

s32 streams_stop();
s32 sfx_play_on_channel();
s32 music_play();
extern s32 g_se_priority;
extern s32 g_se_volume;
extern s32 g_se_last_result;
extern u8 D_0028EB04_as_u8;
extern u8 D_0028EB20_as_u8;
extern u8 D_0028EB44_as_u8;
extern u8 D_0028EB4C_as_u8;
extern u8 D_0028EB54_as_u8;
extern u8 g_menu_step_as_u8;
extern u8 g_menu_page_as_u8;
extern s32 D_0028EC68;
extern s32 D_0028EC6C;
extern s8 D_0068DC35[];
extern s8 D_0068DC36[];
void func_0021E410() {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (func_00221120(2) == 0) {
        func_0021E5C0();
    }
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            g_menu_cursor = 4;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        g_menu_cursor = 4;
    } else if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB20_as_u8 = g_menu_cursor;
    if (var_a1 != 0) {
        switch (g_menu_cursor) {
        case 0:
        case 3:
            break;
        case 1:
            sfx_menu_confirm();
            D_0028EC68 = 0;
            g_menu_page_as_u8 = 6;
            break;
        case 2:
            sfx_menu_confirm();
            D_0028EC6C = 0;
            g_menu_page_as_u8 = 5;
            break;
        case 4:
            streams_stop();
            func_00222260(0);
            g_menu_step_as_u8 = 3;
            D_0028EB4C_as_u8 = 1;
            g_menu_alpha = 0x40;
            D_0028EB04_as_u8 = 1;
            D_0028EB54_as_u8 = 2;
            D_0028EB44_as_u8 = 2;
            g_menu_page_as_u8 = 0;
            D_0028EB74 += 1;
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

extern s8 D_0028E278_as_s8;
extern s8 D_0068DC30[];

void func_0021E5C0(void) {
    void sfx_menu_tick(void);
    s32 value;

    if (g_menu_cursor == 3) {
        value = D_0068DC30[g_menu_cursor];
        if (g_pad_repeat[2] & 0x2000) {
            sfx_menu_tick();
            value++;
            if (value >= 2) {
                value = 0;
            }
            D_0068DC30[g_menu_cursor] = value;
            D_0028E278_as_s8 = value;
        } else if (g_pad_repeat[2] & 0x8000) {
            sfx_menu_tick();
            value--;
            if (value < 0) {
                value = 1;
            }
            D_0068DC30[g_menu_cursor] = value;
            D_0028E278_as_s8 = value;
        }
    }
}


void func_0021E680(void) {
    switch (D_0028EB70) {                           /* irregular */
    case 0:
        func_0021E6F0(D_0028EB70);
        break;
    case 1:
        func_0021E740(D_0028EB70);
        break;
    case 2:
        func_0021E790(D_0028EB70);
        /* fallthrough */
    case 3:
        break;
    }
}

extern s8 D_0028EB40;
extern s32 D_0028EBA8;

void func_0021E6F0() {
    D_0028EBA8 = 0;
    D_0028EB70 += 1;
    func_00222340(3);
    g_menu_alpha = 0x40;
    D_0028EB1C = 0;
    D_0028EB40 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}

#pragma push
#pragma opt_propagation off
void func_0021E740()
{
    if (func_00222530(3) != 0) {
        s32 previousCount = D_0028EB70;

        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB70 = previousCount + 1;
        return;
    }
}
#pragma pop

void func_0021E790() {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (func_00221120(3) == 0) {
        func_0021E8D0();
    }
    func_0021EA10();
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            g_menu_cursor = MAIN_OR_DEATH_LABEL(5, 7);
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB1C = g_menu_cursor;
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
            func_00222260(0);
            g_menu_step = 3;
            g_menu_page = 0;
            g_menu_alpha = 0x40;
            D_0028EB4C = 1;
            D_0028EB54 = 2;
            D_0028EB40 = 2;
            D_0028EB04 = 1;
            D_0028EB70 += 1;
            break;
        }
    }
}

extern u16 D_0028E300;
extern s8 D_0068DC40[];

void func_0021E8D0(void) {
    extern void sfx_menu_tick(void);
    s32 count;
    s32 value;

    if (g_menu_cursor >= MAIN_OR_DEATH_LABEL(5, 7)) {
        return;
    }
    if (g_menu_cursor == 1 && !(D_0028E300 & 1)) {
        return;
    }
    if (g_menu_cursor == 2 && !(D_0028E300 & 2)) {
        return;
    }
    if (g_menu_cursor == 3 && !(D_0028E300 & 4)) {
        return;
    }
    if (g_menu_cursor == 4 && !(D_0028E300 & 8)) {
        return;
    }
    count = D_0028DD20[g_menu_cursor];
    value = D_0068DC40[g_menu_cursor];
    if (g_pad_repeat[2] & 0x2000) {
        sfx_menu_tick();
        value++;
        if (value >= count) {
            value = 0;
        }
        D_0068DC40[g_menu_cursor] = value;
    } else if (g_pad_repeat[2] & 0x8000) {
        sfx_menu_tick();
        value--;
        if (value < 0) {
            value = count - 1;
        }
        D_0068DC40[g_menu_cursor] = value;
    }
}

extern s8 D_0028E2EC_as_s8;
extern s8 D_0028E304_as_s8;
extern s8 D_0028E308_as_s8;
extern s8 D_0028E30C_as_s8;
extern s8 D_0068DC41[];
extern s8 D_0068DC42_as_s8_a[];
extern s8 D_0068DC43_as_s8_a[];
extern s8 D_0068DC44[];

#ifdef DEATH_LABEL
extern s8 D_0068DC45_as_s8_a[];
extern s8 death_D_00290854_as_s8;
extern s8 death_D_00290858_as_s8;
extern s8 death_D_00628DC6_as_s8_a[];
#endif

void func_0021EA10(void) {
    D_0028E304_as_s8 = D_0068DC41[0];
    D_0028E30C_as_s8 = D_0068DC42_as_s8_a[0];
    D_0028E308_as_s8 = D_0068DC43_as_s8_a[0];
    D_0028E2EC_as_s8 = D_0068DC44[0];
#ifdef DEATH_LABEL
    death_D_00290858_as_s8 = D_0068DC45_as_s8_a[0];
    death_D_00290854_as_s8 = death_D_00628DC6_as_s8_a[0];
#endif
}


void func_0021EA50(void) {
    switch (D_0028EB6C) {
    case 0:
        func_0021EAE0();
        break;
    case 1:
        func_0021EB30();
        break;
    case 2:
        func_0021EB80();
        break;
    case 3:
        func_0021ED50();
        break;
    case 4:
        func_0021ED70();
        break;
    case 5:
        break;
    }
}

extern s32 D_0028EBA4;

void func_0021EAE0(void) {
    D_0028EBA4 = 0;
    D_0028EB6C += 1;
    func_00222340(0xE);
    g_menu_alpha = 0x40;
    D_0028EB18 = 0;
    D_0028EB3C = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}

#pragma push
#pragma opt_propagation off
void func_0021EB30(void)
{
    if (func_00222530(0xE) != 0) {
        s32 previousCount = D_0028EB6C;

        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB6C = previousCount + 1;
        return;
    }
}
#pragma pop

extern u8 g_game_mode;
extern s32 D_0028EAFC;

void func_0021EB80(void) {
    extern void sfx_menu_confirm(void);
    extern void func_00169BC0(void);
    extern void fade_start_out(void);
    s32 var_a1;

    if (func_00221120(0xE) == 0) {
        func_0021EDC0();
    }
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            g_menu_cursor = 5;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB18 = g_menu_cursor;
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        g_menu_cursor = 5;
    }
    if (var_a1 != 0) {
        switch (g_menu_cursor) {
        case 1:
            D_0028EB3C = 2;
#ifndef DEATH_LABEL
            D_0028EAFC = 0xFF;
#endif
            D_0028EB54 = 2;
            g_game_mode = 0;
            D_0028E2E4 = 0;
            sfx_menu_confirm();
            func_00169BC0();
            fade_start_out();
            D_0028EB88 = 2;
            D_0028EB00 = 2;
            break;
        case 2:
            g_game_mode = 1;
            D_0028E2E4 = 1;
#ifndef DEATH_LABEL
            D_0028EAFC = 0xFF;
#endif
            D_0028EB3C = 2;
            D_0028EB54 = 2;
            sfx_menu_confirm();
            func_00169BC0();
            fade_start_out();
            D_0028EB88 = 2;
            D_0028EB00 = 2;
            break;
        case 3:
            D_0028EB3C = 2;
            D_0028EB54 = 2;
            sfx_menu_confirm();
            D_0028EB78 = 0;
            g_menu_page = 1;
            D_0028EB24 = 0;
            break;
        case 4:
            break;
        case 5:
            sfx_menu_confirm();
            func_00222260(0);
            g_menu_step = 3;
            g_menu_page = 0;
            g_menu_alpha = 0x40;
            D_0028EB4C = 1;
            D_0028EB54 = 2;
            D_0028EB3C = 2;
            D_0028EB04 = 1;
            D_0028EB6C += 1;
            break;
        }
    }
}

void func_0021ED50(void) {
    if (D_0028EB3C == 0) {
        D_0028EB6C = 4;
    }
}

#pragma push
#pragma opt_propagation off
void func_0021ED70(void) {
    if (func_002365A0() != 0) {
        s8 val = D_0028EB18;
        D_0028EB6C = 2;
        D_0028EB54 = 1;
        D_0028E320 = 0xE10;
        g_menu_cursor = val;
    }
}
#pragma pop

extern s8 D_0028E2D8_as_s8;
extern s8 D_0068DCF0[];

void func_0021EDC0(void) {
    void sfx_menu_tick(void);
    s32 value;

    if (g_menu_cursor == 4) {
        value = D_0068DCF0[g_menu_cursor];
        if (g_pad_repeat[2] & 0x2000) {
            sfx_menu_tick();
            value++;
            if (value >= 2) {
                value = 0;
            }
            D_0068DCF0[g_menu_cursor] = value;
            D_0028E2D8_as_s8 = value;
        } else if (g_pad_repeat[2] & 0x8000) {
            sfx_menu_tick();
            value--;
            if (value < 0) {
                value = 1;
            }
            D_0068DCF0[g_menu_cursor] = value;
            D_0028E2D8_as_s8 = value;
        }
    }
}


void func_0021EE80(void) {
    switch (D_0028EB68) {                           /* irregular */
    case 0:
        func_0021EF10(D_0028EB68);
        break;
    case 1:
        func_0021EF60(D_0028EB68);
        break;
    case 2:
        func_0021EFB0(D_0028EB68);
        break;
    case 3:
        func_0021F180(D_0028EB68);
        /* fallthrough */
    case 4:
        break;
    }
}

extern s8 D_0028EB38;
extern s32 D_0028EBA0;

void func_0021EF10() {
    D_0028EBA0 = 0;
    D_0028EB68 += 1;
    func_00222340(0xF);
    g_menu_alpha = 0x40;
    D_0028EB14 = 0;
    D_0028EB38 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}

#pragma push
#pragma opt_propagation off
void func_0021EF60()
{
    if (func_00222530(0xF) != 0) {
        s32 count = D_0028EB68;

        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB68 = count + 1;
        return;
    }
}
#pragma pop

#pragma push
extern s8 g_display_offset_y;
extern s8 g_display_offset_x;
extern s8 D_0028EAE0;
extern s8 D_0028EAE4;
void func_0021EFB0() {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (func_00221120(0xF) == 0) {
        func_0021F1C0();
    }
    func_0021F2C0();
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            g_menu_cursor = 0xD;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    D_0028EB14 = g_menu_cursor;
    if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    if ((D_0028EB14 >= 9) && (D_0028EB14 < 0xC)) {
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
            D_0028EAE4 = g_display_offset_x;
            g_menu_page = 0x10;
            D_0028EAE0 = g_display_offset_y;
            break;
        case 9:
            func_00222780();
            break;
        case 10:
            func_00222780();
            break;
        case 11:
            func_00222780();
            break;
        case 12:
            sfx_menu_confirm();
            func_0021F440();
            func_0021F2C0();
            break;
        case 13:
            sfx_menu_confirm();
            func_00222260(0);
            g_menu_step = 3;
            g_menu_page = 0;
            g_menu_alpha = 0x40;
            D_0028EB4C = 1;
            D_0028EB54 = 2;
            D_0028EB38 = 2;
            D_0028EB04 = 1;
            D_0028EB68 += 1;
            break;
        }
    }
}

#pragma opt_propagation off


void func_0021F180()
{
    if (D_0028EB38 == 0) {
        s8 savedState = D_0028EB14;

        D_0028EB68 = 2;
        D_0028EB54 = 1;
        D_0028E320_as_u16 = 0xE10;
        g_menu_cursor = savedState;
        return;
    }
}

extern s8 D_0068DD00[];

void func_0021F1C0(void) {
    extern void sfx_menu_tick(void);
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = g_menu_cursor;
    if (sel != 7 && !(sel > 7)) {
        max = D_00271690[sel];
        if (sel == 2 && D_0028E358 != 0) {
            max = D_002716A0[sel];
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
extern s8 g_p1_btn_map_a_as_s8;
extern s8 g_p1_btn_map_b_as_s8;
extern s8 g_p1_btn_map_c_as_s8;
extern s8 D_0028E273_as_s8;
extern s8 g_p2_btn_map_a_as_s8;
extern s8 g_p2_btn_map_b_as_s8;
extern s8 g_p2_btn_map_c_as_s8;
extern s8 D_0028E277_as_s8;
extern s8 g_stage_map_enabled_as_s8;
extern s8 g_bgm_alternate_set_as_s8;
extern u16 D_0028E32C;
extern s8 g_display_reset_pending;
extern s8 D_0068DD02[];
extern s8 D_0068DD03_as_s8_a[];
extern s8 D_0068DD04_as_s8_a[];
extern s8 D_0068DD05_as_s8_a[];
extern s8 D_0068DD06_as_s8_a[];
extern s8 D_0068DD09[];
extern s8 D_0068DD0A[];
extern s8 D_0068DD0B[];
extern s8 D_0068DD0C_as_s8_a[];
extern s8 D_0068DD0D[];
extern s8 D_0068DD0E[];
extern s8 D_0068DD0F[];
extern s8 D_0068DD10_as_s8_a[];
void func_0021F2C0(void) {
    extern void wallpaper_load(s32, s32);
    s32 temp_a0;

    if (D_0028E358 != D_0068DD01[0]) {
        D_0028E354 = 0;
        g_display_reset_pending = 1;
        D_0068DD02[0] = 0;
    }
    if (D_0028E354 != D_0068DD02[0]) {
        D_0028E354 = (u8) D_0068DD02[0];
        if (D_0028E358 == 0) {
            D_0028E354 &= 3;
        } else {
            D_0028E354 &= 1;
        }
        D_0068DD02[0] = D_0028E354;
        g_display_reset_pending = 1;
    }
    if (g_screen_wide != D_0068DD03_as_s8_a[0]) {
        g_display_reset_pending = 1;
    }
    g_screen_wide = (u8) D_0068DD03_as_s8_a[0];
    g_bgm_alternate_set_as_s8 = D_0068DD06_as_s8_a[0];
    g_stage_map_enabled_as_s8 = D_0068DD05_as_s8_a[0];
    if (D_0028E32C != D_0068DD04_as_s8_a[0]) {
        D_0028E32C = (u16) (s8)(D_0068DD04_as_s8_a[0]);
        if (D_0028E32C != 5) {
            temp_a0 = (D_0028E32C & 0xFFFF) * 8;
            wallpaper_load(*(s32 *)((u8 *)g_menu_wallpapers + temp_a0), *(s32 *)(D_00271C64 + temp_a0));
        }
    }
    g_p1_btn_map_a_as_s8 = D_0068DD09[0];
    g_p1_btn_map_b_as_s8 = D_0068DD0A[0];
    g_p1_btn_map_c_as_s8 = D_0068DD0B[0];
    D_0028E273_as_s8 = D_0068DD0C_as_s8_a[0];
    g_p2_btn_map_a_as_s8 = D_0068DD0D[0];
    g_p2_btn_map_b_as_s8 = D_0068DD0E[0];
    g_p2_btn_map_c_as_s8 = D_0068DD0F[0];
    D_0028E277_as_s8 = D_0068DD10_as_s8_a[0];
}

#ifdef DEATH_LABEL
extern u8 death_D_00628F01[];
extern u8 death_D_00628F02[];
#endif

void func_0021F440(void) {
    if (D_0028E354 != 0) {
        g_display_reset_pending = 1;
    }
    D_0068DD01[0] = 0;
    D_0068DD02[0] = 0;
    D_0028E354 = 0;
    D_0068DD03_as_s8_a[0] = 0;
    D_0068DD04_as_s8_a[0] = 5;
    D_0068DD05_as_s8_a[0] = 1;
    D_0068DD06_as_s8_a[0] = 0;
    D_0068DD09[0] = 7;
    D_0068DD0D[0] = 7;
    D_0068DD0A[0] = 6;
    D_0068DD0E[0] = 6;
    D_0068DD0B[0] = 5;
    D_0068DD0F[0] = 5;
    D_0068DD0C_as_s8_a[0] = 1;
    D_0068DD10_as_s8_a[0] = 1;
#ifdef DEATH_LABEL
    death_D_00628F01[0] = 0;
    death_D_00628F02[0] = 0;
#endif
}

s32 func_00212580();

void func_0021F4E0(void) {
    switch (D_0028EB60) {                           /* irregular */
    case 0:
        func_0021F560(D_0028EB60);
        break;
    case 1:
        func_0021F5B0(D_0028EB60);
        break;
    case 2:
        func_0021F600(D_0028EB60);
        break;
    case 3:
#ifndef DEATH_LABEL
        func_0021F750(D_0028EB60);
#endif
        break;
    }
#ifdef DEATH_LABEL
    if (D_0028EB60 >= 0x40) {
        D_0028EB60++;
        if (D_0028EB60 >= 0x60) {
            func_00212580(2);
            printf("kidou\n");
        }
    }
#endif
}
#pragma pop

extern s8 D_0028EB30;
extern s32 D_0028EB98;

void func_0021F560() {
    D_0028EB98 = 0;
    D_0028EB60 += 1;
    func_00222340(0x15);
    g_menu_alpha = 0x40;
    D_0028EB0C = 0;
    D_0028EB30 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}

void func_0021F5B0() {
    if (func_00222530(0x15) != 0) {
        g_menu_cursor = 0;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        g_menu_alpha = 0x40;
        D_0028EB60++;
    }
}

extern s8 D_0028EAA8;
extern s8 D_0028EBC0;
void func_0021F600() {
    s32 sfx_menu_confirm();
    s32 sfx_menu_move();
    s32 fade_start_out();
    s32 selected;
    s32 choice;
    u32 buttons;

    buttons = g_pad_trigger[2];
    choice = D_0028EAE8;
    selected = 0;
    if ((buttons & 0x8000) && D_0028EB0C == 0) {
        D_0028EBC0 = 0;
        D_0028EB0C = 1;
        sfx_menu_move();
    } else if ((buttons & 0x2000) && D_0028EB0C == 1) {
        D_0028EBC0 = 0;
        D_0028EB0C = 0;
        sfx_menu_move();
    } else if (buttons & 0x20) {
        selected = 1;
        if (D_0028EB0C == 0) {
            choice = 3;
        }
    }
    if (selected != 0) {
        switch (choice) {
#ifdef DEATH_LABEL
        case 1:
            streams_stop();
            sfx_menu_confirm();
            D_0028EB60 = 0x40;
            fade_start_out();
            break;
#else
        case 1:
        case 2:
            D_0028EAA8 = choice;
            fade_start_out();
            sfx_menu_confirm();
            D_0028EB60 += 1;
            break;
#endif
        case 3:
            streams_stop();
            func_00222260(0);
            g_menu_step = 3;
            D_0028EB4C = 1;
            g_menu_alpha = 0x40;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            D_0028EB30 = 2;
            g_menu_page = 0;
            D_0028EB60 += 1;
            sfx_menu_confirm();
            break;
        }
    }
}

#ifndef DEATH_LABEL
s32 func_00212580(s32);                     /* extern */

void func_0021F750() {
    if (g_fade_state == 0) {
        switch (D_0028EAA8) {                       /* irregular */
        case 1:
            func_00212580(0);
            return;
        case 2:
            func_00212580(1);
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
extern s8 death_D_00628F00[];

void death_func_001B7460(void) {
    switch (death_D_00290CA8) {
    case 0:
        death_func_001B74D0();
        break;
    case 1:
        death_func_001B7520();
        break;
    case 2:
        death_func_001B7570();
        break;
    case 3:
        break;
    }
}

void death_func_001B74D0(void) {
    death_D_00290CE4 = 0;
    death_D_00290CA8++;
    func_00222340(0x17);
    g_menu_alpha = 0x40;
    death_D_00290C4C = 0;
    death_D_00290C74 = 1;
    D_0028EB04 = 1;
    D_0028E320_as_u16 = 0xE10;
}

void death_func_001B7520(void) {
    if (func_00222530(0x17) != 0) {
        death_D_00290CA8++;
        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
    }
}

void death_func_001B7570(void) {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (func_00221120(0x17) == 0) {
        death_func_001B76A0();
    }
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            g_menu_cursor = 3;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
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
            func_00222260(0);
            g_menu_step = 3;
            D_0028EB4C = 1;
            g_menu_alpha = 0x40;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            death_D_00290C74 = 2;
            g_menu_page = 0;
            death_D_00290CA8++;
            sfx_menu_confirm();
            break;
        }
    }
}

void death_func_001B76A0(void) {
    void sfx_menu_tick(void);
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = g_menu_cursor;
    if (sel < 3) {
        max = death_D_00290048[sel];
        cur = death_D_00628F00[sel];
        pad = g_pad_repeat[2];
        if (pad & 0x2000) {
            sfx_menu_tick();
            cur++;
            if (cur >= max) {
                cur = 0;
            }
            death_D_00628F00[g_menu_cursor] = cur;
        } else if (pad & 0x8000) {
            sfx_menu_tick();
            cur--;
            if (cur < 0) {
                cur = max - 1;
            }
            death_D_00628F00[g_menu_cursor] = cur;
        }
    }
}
#endif


void func_0021F7B0(void) {
    switch (D_0028EB5C) {                           /* irregular */
    case 0:
        func_0021F820(D_0028EB5C);
        break;
    case 1:
        func_0021F880(D_0028EB5C);
        break;
    case 2:
        func_0021F8D0(D_0028EB5C);
        /* fallthrough */
    case 3:
        break;
    }
}

s32 func_001A3D30();                            /* extern */
extern s32 D_0028EAEC;
extern s32 D_0028EAF0;
extern s32 D_0028EAF4;
extern s8 D_0028EB2C;
extern s32 D_0028EB94;

void func_0021F820() {
    D_0028EB94 = 0;
    D_0028EB5C += 1;
    func_00222340(0x18);
    g_menu_alpha = 0x40;
    D_0028EB2C = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
    D_0028EB08 = 0;
    D_0028EAF0 = 0;
    D_0028EAEC = 0;
    D_0028EAF4 = 0;
    func_001A3D30();
}

void func_0021F880() {
    if (func_00222530(0x18) != 0) {
        g_menu_cursor = 0;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        g_menu_alpha = 0x40;
        D_0028EB5C++;
    }
}

s32 func_0015BDD0();
s32 func_001A3E70();
extern s8 D_0028E294_as_s8;
void func_0021F8D0() {
    s32 sfx_menu_confirm();
    s32 var_s0;

    if (D_0028EAF0 == 0) {
        func_002212C0(0x18);
    }
    var_s0 = 0;
    D_0028E294_as_s8 = 1;
    func_001A3E70();
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_s0 = 1;
            g_menu_cursor = 5;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x40) {
        var_s0 = 1;
        g_menu_cursor = 5;
    } else if (g_pad_trigger[2] & 0x20) {
        var_s0 = 1;
    }
    D_0028EB08 = g_menu_cursor;
    if (var_s0 != 0) {
        switch (g_menu_cursor) {
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            sfx_menu_confirm();
            if (D_0028EAF4 == 0) {
                D_0028EAEC = 0;
                D_0028EAF0 = 1;
                D_0028EAF4 = 1;
                break;
            }
            D_0028EAF4 = 0;
            D_0028EAF0 = 2;
            break;
        case 5:
            streams_stop();
            func_00222260(0);
            g_menu_step = 3;
            D_0028EB4C = 1;
            g_menu_alpha = 0x40;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            g_menu_page = 0;
            D_0028EB2C = 0;
            D_0028EB94 = 0;
            D_0028EAF0 = 0;
            D_0028EAEC = 0;
            D_0028EAF4 = 0;
            D_0028EB5C += 1;
            func_0015BDD0();
            sfx_menu_confirm();
            break;
        }
    }
}

#ifdef DEATH_LABEL
#endif

void func_0021FA50(void) {
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

    if (D_0028EB00 != 0) {
        if (g_menu_page == 0x10) {
            func_00225450();
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
        if (D_0028EB94 == 0) {
            gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x60, 1, 1, 1);
            func_00221440();
        } else {
            func_00221360();
        }
        glyph_queue_clear();
        func_0021FC70();
        func_0021FDB0();
        func_002201A0();
        func_00220390();
        func_002207C0();
        func_002209C0();
        func_00221000();
#ifdef DEATH_LABEL
        death_func_001B9120();
#endif
        func_00221080();
        func_002278D0();
        func_00227B70();
        func_002287E0();
        func_00228BC0();
        func_00229660();
        func_0022A0B0();
        func_0022A480();
        func_00221E20();
        glyph_queue_flush();
        func_00227E00();
        func_00221550();
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


extern Label D_00685010_as_Label_a[];

void func_0021FC70(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 wide);
    s32 i;
    s32 count;
    Label *label;
    s32 x;
    s32 y;
    s32 z;

    count = g_menu_page_item_counts[0];
    switch (D_0028EB4C) {
    case 0:
        break;
    case 1:
        D_0028EBB4 += 4;
        if (D_0028EBB4 >= 0x80) {
            D_0028EB4C = 0;
            D_0028EBB4 = 0x80;
        }
        break;
    case 2:
        D_0028EBB4 -= 4;
        if (D_0028EBB4 <= 0) {
            D_0028EBB4 = 0;
            D_0028EB4C = 0;
        }
        break;
    }
    for (i = 0; i < count; i++) {
        label = &D_00685010_as_Label_a[i];
        if (label->active != 0) {
            label->alpha = D_0028EBB4;
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
extern u8 D_00685010[];
extern s8 D_0068DC10[];

void func_0021FDB0(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 count;
    s32 index;
    s32 top;
    u8 *item;
    u8 **pair;

    count = D_002714F1[0];
    switch (D_0028EB48) {
    case 0:
        break;
    case 1:
        D_0028EBB0 += 4;
        if (D_0028EBB0 >= 0x80) {
            D_0028EB48 = 0;
            D_0028EBB0 = 0x80;
        }
        break;
    case 2:
        D_0028EBB0 -= 4;
        if (D_0028EBB0 <= 0) {
            D_0028EBB0 = 0;
            D_0028EB48 = 0;
        }
        break;
    }
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3B4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x3AC) = D_0028EBB0;
        reg_a0 = (u8 *)g_menu_game_option_items[i];
        x = *(s32 *)(item + 0x380);
        alpha = *(s32 *)(item + 0x3AC);
        top = *(s32 *)(item + 0x384);
        z = *(s32 *)(item + 0x3B0);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x10 + i];
        if (i == 1) {
            reg_a0 = (u8 *)g_menu_difficulty_names[index];
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
            if (D_0028EB24 == 1) {
                func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2) {
            reg_a0 = (u8 *)g_menu_ship_stock_names[index];
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
            if (D_0028EB24 == 2) {
                func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
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
            if (D_0028EB24 == 3) {
                func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 4) {
            reg_a0 = (u8 *)D_0028DD18[index];
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
            if (D_0028EB24 == 4) {
                func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
    text_flush();
}

extern s8 D_002714F2[];

void func_002201A0(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    u8 *item;

    count = D_002714F2[0];
    switch (D_0028EB44) {
    case 0:
        break;
    case 1:
        D_0028EBAC += 4;
        if (D_0028EBAC >= 0x80) {
            D_0028EB44 = 0;
            D_0028EBAC = 0x80;
        }
        break;
    case 2:
        D_0028EBAC -= 4;
        if (D_0028EBAC <= 0) {
            D_0028EBAC = 0;
            D_0028EB44 = 0;
        }
        break;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x734) == 0) {
            continue;
        }
        *(s32 *)(item + 0x72C) = D_0028EBAC;
        reg_a0 = (u8 *)g_menu_save_load_items[i];
        x = *(s32 *)(item + 0x700);
        alpha = *(s32 *)(item + 0x72C);
        top = *(s32 *)(item + 0x704);
        z = *(s32 *)(item + 0x730);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x20 + i];
        if (i == 3) {
            reg_a0 = (u8 *)D_0028DD18[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB20 == 3) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
}

extern s8 D_002714F3[];
#ifdef DEATH_LABEL
#endif

void func_00220390(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 count;
    s32 index;
    s32 top;
    u8 *item;

    count = D_002714F3[0];
    switch (D_0028EB40) {
    case 0:
        break;
    case 1:
        D_0028EBA8 += 4;
        if (D_0028EBA8 >= 0x80) {
            D_0028EB40 = 0;
            D_0028EBA8 = 0x80;
        }
        break;
    case 2:
        D_0028EBA8 -= 4;
        if (D_0028EBA8 <= 0) {
            D_0028EBA8 = 0;
            D_0028EB40 = 0;
        }
        break;
    }
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0xAB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0xAAC) = D_0028EBA8;
        reg_a0 = (u8 *)g_menu_debug_option_items[i];
        x = *(s32 *)(item + 0xA80);
        alpha = *(s32 *)(item + 0xAAC);
        top = *(s32 *)(item + 0xA84);
        z = *(s32 *)(item + 0xAB0);
        if (alpha == 0) {
            continue;
        }
        if (i == 1 && !(D_0028E300 & 1)) {
            reg_a0 = (u8 *)g_menu_locked_item_text[0];
        }
        if (i == 2 && !(D_0028E300 & 2)) {
            reg_a0 = (u8 *)g_menu_locked_item_text[0];
        }
        if (i == 3 && !(D_0028E300 & 4)) {
            reg_a0 = (u8 *)g_menu_locked_item_text[0];
        }
        if (i == 4 && !(D_0028E300 & 8)) {
            reg_a0 = (u8 *)g_menu_locked_item_text[0];
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x30 + i];
        if (i == 1 && (D_0028E300 & 1)) {
            reg_a0 = (u8 *)D_0028DD28[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 1) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2 && (D_0028E300 & 2)) {
            reg_a0 = (u8 *)D_0028DD30[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 2) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 3 && (D_0028E300 & 4)) {
            reg_a0 = (u8 *)D_0028DD38[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 3) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 4 && (D_0028E300 & 8)) {
            reg_a0 = (u8 *)D_0028DD40[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 4) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
#ifdef DEATH_LABEL
        if (i == 5) {
            reg_a0 = (u8 *)g_menu_numbers_0_to_500[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 5) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 6) {
            reg_a0 = (u8 *)D_0028DD60[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 6) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
#endif
    }
    text_flush();
}

extern s8 D_002714FE[];

void func_002207C0(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    u8 *item;

    count = D_002714FE[0];
    switch (D_0028EB3C) {
    case 0:
        break;
    case 1:
        D_0028EBA4 += 4;
        if (D_0028EBA4 >= 0x80) {
            D_0028EB3C = 0;
            D_0028EBA4 = 0x80;
        }
        break;
    case 2:
        D_0028EBA4 -= 4;
        if (D_0028EBA4 <= 0) {
            D_0028EBA4 = 0;
            D_0028EB3C = 0;
        }
        break;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3134) == 0) {
            continue;
        }
        *(s32 *)(item + 0x312C) = D_0028EBA4;
        reg_a0 = (u8 *)g_menu_arcade_items[i];
        x = *(s32 *)(item + 0x3100);
        alpha = *(s32 *)(item + 0x312C);
        top = *(s32 *)(item + 0x3104);
        z = *(s32 *)(item + 0x3130);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0xE0 + i];
        if (i == 4) {
            reg_a0 = (u8 *)D_0028DD18[index];
            glyph_queue_add(x, y + 32, z, 0, 0x80, alpha, 1);
            if (D_0028EB18 == 4) {
                func_00224BA0(x, y + 32, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
}

#pragma push
#pragma opt_dead_assignments off
void text_queue_clear(void);
void text_flush(void);
extern s8 D_002714FF[];

void func_002209C0(void) {
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
    u8 *item;
    u16 glyph;

    count = D_002714FF[0];
    switch (D_0028EB38) {
    case 0:
        break;
    case 1:
        D_0028EBA0 += 4;
        if (D_0028EBA0 >= 0x80) {
            D_0028EB38 = 0;
            D_0028EBA0 = 0x80;
        }
        break;
    case 2:
        D_0028EBA0 -= 4;
        if (D_0028EBA0 <= 0) {
            D_0028EBA0 = 0;
            D_0028EB38 = 0;
        }
        break;
    }
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x34B4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x34AC) = D_0028EBA0;
        reg_a0 = (u8 *)g_menu_system_option_items[i];
        x = *(s32 *)(item + 0x3480);
        alpha = *(s32 *)(item + 0x34AC);
        top = *(s32 *)(item + 0x3484);
        z = *(s32 *)(item + 0x34B0);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0xF0 + i];
        if (i == 1) {
            reg_a0 = (u8 *)g_menu_lever_set_names[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 1) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2) {
            if (D_0028E358 == 0) {
                reg_a0 = (u8 *)g_menu_monitor_mode_names[index];
            } else {
                reg_a0 = (u8 *)g_menu_monitor_mode_tate_names[index];
            }
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 2) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 3) {
            reg_a0 = (u8 *)g_menu_monitor_type_names[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 3) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 4) {
            reg_a0 = (u8 *)D_002716C0[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 4) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 5) {
            reg_a0 = (u8 *)D_0028DD60[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 5) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 6) {
            reg_a0 = (u8 *)g_menu_original_arrange_names[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 6) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 9) {
            glyph = D_00271A10[D_0068DD09[0]];
            text_queue_glyph(x - 22, y - 4, glyph, 20, 32, 32, alpha, z);
            glyph = D_00271A10[D_0068DD0D[0]];
            text_queue_glyph(x - 22, y + 100, glyph, 20, 32, 32, alpha, z);
        }
        if (i == 10) {
            glyph = D_00271A10[D_0068DD0A[0]];
            text_queue_glyph(x - 22, y - 4, glyph, 20, 32, 32, alpha, z);
            glyph = D_00271A10[D_0068DD0E[0]];
            text_queue_glyph(x - 22, y + 100, glyph, 20, 32, 32, alpha, z);
        }
        if (i == 11) {
            glyph = D_00271A10[D_0068DD0B[0]];
            text_queue_glyph(x - 22, y - 4, glyph, 20, 32, 32, alpha, z);
            glyph = D_00271A10[D_0068DD0F[0]];
            text_queue_glyph(x - 22, y + 100, glyph, 20, 32, 32, alpha, z);
        }
    }
    text_flush();
}
#pragma pop

void func_00221000(void) {
    switch (D_0028EB30) {
    case 0:
        break;
    case 1:
        D_0028EB98 += 4;
        if (D_0028EB98 >= 0x80) {
            D_0028EB30 = 0;
            D_0028EB98 = 0x80;
        }
        break;
    case 2:
        D_0028EB98 -= 4;
        if (D_0028EB98 <= 0) {
            D_0028EB98 = 0;
            D_0028EB30 = 0;
        }
        break;
    }
}

#ifdef DEATH_LABEL
extern s8 death_D_00262EC7[];

void death_func_001B9120(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    u8 *item;

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
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x50B4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x50AC) = death_D_00290CE4;
        reg_a0 = (u8 *)death_D_00262FF0[i];
        x = *(s32 *)(item + 0x5080);
        alpha = *(s32 *)(item + 0x50AC);
        top = *(s32 *)(item + 0x5084);
        z = *(s32 *)(item + 0x50B0);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x170 + i];
        if (i == 1) {
            reg_a0 = (u8 *)death_D_00290050[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (death_D_00290C4C == 1) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2) {
            reg_a0 = (u8 *)death_D_002630C8[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (death_D_00290C4C == 2) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
    text_flush();
}
#endif

s32 func_001A4140();
extern u8 D_0028E294;

void func_00221080(void) {
    switch (D_0028EB2C) {                           /* irregular */
    case 0:
        break;
    case 1:
        D_0028EB94 += 4;
        if (D_0028EB94 >= 0x80) {
            D_0028EB2C = 0;
            D_0028EB94 = 0x80;
        }
        break;
    case 2:
        D_0028EB94 -= 4;
        if (D_0028EB94 <= 0) {
            D_0028EB94 = 0;
            D_0028EB2C = 0;
        }
        break;
    }
    if (D_0028EB94 != 0) {
        D_0028E294 = 1;
        func_001A4140();
    }
}

extern s16 D_0068DEFA[];

s32 func_00221120(s32 page) {
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
        if (g_menu_page == 15 && g_menu_cursor == 8) {
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
        if (g_menu_page == 15 && g_menu_cursor == 8) {
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

s32 func_002212C0() {
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


void func_00221360(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s32 x;

    switch (D_0028EB54) {
    case 0:
        break;
    case 1:
        g_menu_box_alpha += 4;
        if (g_menu_box_alpha >= 0x20) {
            D_0028EB54 = 0;
            g_menu_box_alpha = 0x20;
        }
        break;
    case 2:
        g_menu_box_alpha -= 4;
        if (g_menu_box_alpha <= 0) {
            g_menu_box_alpha = 0;
            D_0028EB54 = 0;
        }
        break;
    }
    if (g_menu_cursor != -1) {
        x = g_menu_item_positions_c[g_menu_cursor * 2];
        if (g_menu_box_alpha != 0) {
            gfx_draw_color_box(x - 8, 0, 0x48, 0xE0, 0x5A, g_menu_box_alpha, 0xB4, 1, 1);
        }
    }
}

extern s16 g_menu_item_positions_b_as_s16_a[];

void func_00221440(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s32 sel;
    s32 x;

    switch (D_0028EB54) {
    case 0:
        break;
    case 1:
        g_menu_box_alpha += 4;
        if (g_menu_box_alpha >= 0x40) {
            D_0028EB54 = 0;
            g_menu_box_alpha = 0x40;
        }
        break;
    case 2:
        g_menu_box_alpha -= 4;
        if (g_menu_box_alpha <= 0) {
            g_menu_box_alpha = 0;
            D_0028EB54 = 0;
        }
        break;
    }
    sel = g_menu_cursor;
    if (sel != -1) {
        if (g_menu_page == 0xF) {
            x = g_menu_item_positions_b_as_s16_a[sel * 2];
        } else {
            x = g_menu_item_positions_a[sel * 2];
        }
        if (g_menu_box_alpha != 0 && sel != 0) {
            gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, g_menu_box_alpha, 0xB4, 1, 1);
        }
    }
}

extern void frame_draw_left_panel(s32 level);
extern s8 D_002714F9[];
extern s8 D_002714FA[];
extern s32 D_0028EB8C;
extern s8 D_0028EC02;
extern s8 D_0028EC0A;
extern s8 D_0028EC12;
extern u8 g_replay_slots_state_as_u8;
extern s32 D_0028EC7C;
#ifdef DEATH_LABEL
extern s8 death_D_00290C4C;
#endif

void func_00221550(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s64 alpha;
    s32 item;
    u8 state;

    switch (D_0028EB04) {
    case 0:
        break;
    case 1:
        g_menu_alpha += 4;
        D_0028EB8C += 4;
        if (g_menu_alpha >= 0x80) {
            D_0028EB04 = 0;
            g_menu_alpha = 0x80;
#ifndef DEATH_LABEL
            D_0028EB8C = 0x80;
#endif
        }
        if (D_0028EB8C >= 0x80) {
            D_0028EB8C = 0x80;
        }
        break;
    case 2:
        g_menu_alpha -= 4;
        if (g_menu_alpha <= 0) {
            g_menu_alpha = 0;
            D_0028EB04 = 0;
        }
        break;
    }
    if (g_menu_page == 0xD) {
        return;
    }
    if (g_menu_alpha != 0) {
        text_queue_clear();
        alpha = g_menu_alpha;
        if (alpha >= 0x40) {
            alpha = 0x40;
        }
        if (alpha != 0) {
            frame_draw_left_panel(D_0028EB8C);
            gfx_draw_color_box(0xC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        if (g_menu_page == 0) {
            reg_a0 = (u8 *)g_menu_main_help[D_0028EB28];
            if (D_0028EB00 != 3) {
                if (g_menu_step != 4 || D_0028EC7C == 0) {
                    func_002228D0(0x36, 8);
                }
            }
        }
        if (g_menu_page == 1) {
            reg_a0 = (u8 *)g_menu_game_option_help[D_0028EB24];
            func_002228D0(0x36, 8);
        }
        if (g_menu_page == 2) {
            reg_a0 = (u8 *)g_menu_save_load_help[D_0028EB20];
            func_002228D0(0x36, 8);
        }
        if (g_menu_page == 3) {
            item = D_0028EB1C;
            reg_a0 = (u8 *)g_menu_debug_option_help[item];
            if (item == 1 && !(D_0028E300 & 1)) {
                reg_a0 = (u8 *)g_menu_unlock_condition_help[0];
            }
            if (item == 2 && !(D_0028E300 & 2)) {
                reg_a0 = (u8 *)g_menu_unlock_condition_help[0];
            }
            if (item == 4 && !(D_0028E300 & 8)) {
                reg_a0 = (u8 *)g_menu_unlock_condition_help[0];
            }
            if (item == 5 && !(D_0028E300 & 0x10)) {
                reg_a0 = (u8 *)g_menu_unlock_condition_help[0];
            }
            func_002228D0(0x36, 8);
        }
        if (g_menu_page == 0xE) {
            reg_a0 = (u8 *)g_menu_arcade_help[D_0028EB18];
            if (D_0028EB6C != 4 || D_0028EC7C == 0) {
                func_002228D0(0x36, 8);
            }
        }
        if (g_menu_page == 0x15) {
            if (g_menu_box_alpha != 0) {
                gfx_draw_color_box(0xE0, 0, 0x6E, 0xE0, 0x5A, g_menu_box_alpha, 0xB4, 1, 1);
            }
            reg_a0 = (u8 *)MAIN_OR_DEATH_LABEL(g_menu_launch_ask, death_D_00290078)[D_0028EAE8];
            func_002228D0(0x36, 8);
            reg_a0 = (u8 *)MAIN_OR_DEATH_LABEL(g_menu_launch_warning, death_D_00290080)[D_0028EAE8];
            func_002228D0(0x136, 8);
            func_002242B0(0xC, 4);
        }
#ifdef DEATH_LABEL
        if (g_menu_page == 0x17) {
            reg_a0 = (u8 *)death_D_002634D0[death_D_00290C4C];
            func_002228D0(0x36, 8);
        }
#endif
        if (g_menu_page == 0x18) {
            reg_a0 = (u8 *)g_menu_ranking_help;
            func_002228D0(0x36, 8);
        }
        if (g_menu_page == 0xF) {
            reg_a0 = (u8 *)g_menu_system_option_help[D_0028EB14];
            func_002228D0(0x36, 8);
            if (D_0028EB14 == 1) {
                reg_a0 = (u8 *)g_menu_lever_set_help[D_0068DD01[0]];
                func_002228D0(0x22, 8);
            }
        }
    }
    if (g_menu_page == 7) {
        reg_a0 = (u8 *)g_menu_simulation_help[D_0028EC1A];
        func_002228D0(0x36, 8);
    }
    if (g_menu_page == 8) {
        reg_a0 = (u8 *)g_menu_sim_setting_help[D_0028EC12];
        func_002228D0(0x36, 8);
    }
    if (g_menu_page == 0x11) {
        reg_a0 = (u8 *)g_menu_sim_player_help[D_0028EC0A];
        func_002228D0(0x36, 8);
    }
    if (g_menu_page == 0x12) {
        reg_a0 = (u8 *)g_menu_sim_rules_help[D_0028EC02];
        func_002228D0(0x36, 8);
    }
    if (g_menu_page == 0x13) {
        reg_a0 = (u8 *)g_menu_sim_param_help[D_0028EBF8.flag];
        func_002228D0(0x36, 8);
    }
    if (g_menu_page == 9) {
        reg_a0 = (u8 *)g_menu_stage_select_difficulty_help[(D_0028EBF0.flag == D_002714F9[0] - 1) ? 1 : 0];
        func_002228D0(0x36, 8);
    }
    if (g_menu_page == 0xA) {
        reg_a0 = (u8 *)g_menu_stage_select_start_help[(D_0028EBE8.flag == D_002714FA[0] - 1) ? 1 : 0];
        if (D_0028EBE8.step >= 3) {
            func_002228D0(0x36, 8);
        }
    }
    if (g_menu_page == 0xB) {
        state = g_replay_slots_state_as_u8;
        if (state != 0 && (u32)(state - 1) > 1 && (u32)(state - 5) > 1) {
            reg_a0 = (u8 *)MAIN_OR_DEATH_LABEL(g_menu_replay_help, g_menu_replay_help);
            func_002228D0(0x36, 8);
        }
    }
    if (g_menu_page == 0x16) {
        reg_a0 = (u8 *)MAIN_OR_DEATH_LABEL(g_menu_super_replay_help, g_menu_replay_help);
        func_002228D0(0x36, 8);
    }
    if (g_menu_page == 0x14) {
        state = g_replay_slots_state_as_u8;
        if (state != 0 && (u32)(state - 1) > 1 && (u32)(state - 5) > 1) {
            reg_a0 = (u8 *)g_menu_load_file_help;
            func_002228D0(0x36, 8);
        }
    }
    if (g_menu_page == 0xD) {
        reg_a0 = (u8 *)g_menu_ranking_title;
        func_002228D0(0x36, 8);
    }
    text_flush();
}

s32 sfx_menu_confirm(s32);                         /* extern */
extern s32 D_0028EAF8;

s32 func_00221C20(void) {
    s32 var_s0;

    var_s0 = 0;
    if (D_0028EAFC == 0xFF) {
        return 1;
    }
    switch (D_0028EAF8) {                           /* irregular */
    case 0:
        D_0028EAF0 = 1;
        g_menu_cursor = (s8) D_0028EAFC;
        D_0028EAF8 += 1;
        D_0028EAEC = 0;
        break;
    case 1:
        if ((D_0028EAF0 == 3) && (g_pad_trigger[2] & 0x20)) {
            sfx_menu_confirm(D_0028EAFC);
            D_0028EAF0 = 2;
            D_0028EAF8 += 1;
        }
        break;
    case 2:
        if (D_0028EAF0 == 0) {
            D_0028EAF8 = 0;
            var_s0 = 1;
        }
        break;
    }
    return var_s0;
}


void func_00221CF0(void) {
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

    if (D_0028EAF8 != 0) {
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
        func_00221E20();
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
extern char D_002BB060_as_char_a[];
extern char D_002BB100_as_char_a[];
extern char *reg_a0_as_char_p;

void func_00221E20(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern s32 glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 alpha, s32 attr, s32 wide);
    char buf[2];
    s32 alpha;
    s32 i;
    char *p;
    s32 y;

    switch (D_0028EAF0) {
    case 0:
    case 3:
        break;
    case 1:
        D_0028EAEC += 4;
        if (D_0028EAEC >= 0x80) {
            D_0028EAEC = 0x80;
            D_0028EAF0 = 3;
        }
        break;
    case 2:
        D_0028EAEC -= 4;
        if (D_0028EAEC <= 0) {
            D_0028EAEC = 0;
            D_0028EAF0 = 0;
        }
        break;
    }
    if (D_0028EAEC != 0) {
        text_queue_clear();
        alpha = D_0028EAEC;
        if (D_0028EAEC >= 0x60) {
            alpha = 0x60;
        }
        if (alpha != 0) {
            frame_draw_right_panel(D_0028EAEC);
            gfx_draw_color_box(0xEC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        reg_a0_as_char_p = (char *)g_menu_password_title;
        func_00222C30(0x116, 8, D_0028EAEC);
        buf[1] = 0;
        i = 0;
        y = 0;
        p = MAIN_OR_DEATH_LABEL(D_002BB100_as_char_a, D_002BB060_as_char_a) + g_menu_cursor * 0x1E;
        do {
            reg_a0_as_char_p = buf;
            *reg_a0_as_char_p = *p++;
            glyph_queue_add(0x106, y + 0xE + (i / 5) * 5, 0x136, 0, 0x80, D_0028EAEC, 1);
            i++;
            y += 9;
        } while (i < 0x14);
    }
    text_flush();
}

extern s8 D_0028EB10;
extern s8 D_0028EB34;
extern s8 D_0028EB64;
extern s32 D_0028EB9C;
extern s32 D_0028EBB8;
extern u8 D_0028EBD8;
extern u8 D_0028EC00;
extern u8 D_0028EC08;
extern u8 D_0028EC10;
extern u8 D_0028EC18;
extern s8 D_0028EC20;

#ifdef DEATH_LABEL
extern s32 death_D_00290CE4;
extern s8 death_D_00290CA8;
extern s8 death_D_00290C74;
extern s8 death_D_00290C4C;
#endif

void func_00221FF0() {
    D_0028EBB8 = 0;
    D_0028EBB4 = 0;
    D_0028EBB0 = 0;
    D_0028EBAC = 0;
    D_0028EBA8 = 0;
    D_0028EBA4 = 0;
    D_0028EBA0 = 0;
    D_0028EB9C = 0;
    D_0028EB98 = 0;
#ifdef DEATH_LABEL
    death_D_00290CE4 = 0;
#endif
    D_0028EB94 = 0;
    g_menu_alpha = 0;
    D_0028EB8C = 0;
    g_menu_page = 0;
    D_0028EB80 = 0;
    g_menu_step = 0;
    D_0028EB78 = 0;
    D_0028EB74 = 0;
    D_0028EB70 = 0;
    D_0028EB6C = 0;
    D_0028EB68 = 0;
    D_0028EB64 = 0;
    D_0028EB60 = 0;
#ifdef DEATH_LABEL
    death_D_00290CA8 = 0;
#endif
    D_0028EB5C = 0;
    D_0028EB04 = 0;
    g_menu_cursor = 0;
    D_0028EB54 = 0;
    g_menu_box_alpha = 0;
    D_0028EB4C = 0;
    D_0028EB48 = 0;
    D_0028EB44 = 0;
    D_0028EB40 = 0;
    D_0028EB3C = 0;
    D_0028EB38 = 0;
    D_0028EB34 = 0;
    D_0028EB30 = 0;
#ifdef DEATH_LABEL
    death_D_00290C74 = 0;
#endif
    D_0028EB2C = 0;
    D_0028EB24 = 0;
    D_0028EB20 = 0;
    D_0028EB1C = 0;
    D_0028EB18 = 0;
    D_0028EB14 = 0;
    D_0028EB10 = 0;
    D_0028EB0C = 0;
#ifdef DEATH_LABEL
    death_D_00290C4C = 0;
#endif
    D_0028EB08 = 0;
    D_0028EAF4 = 0;
    D_0028EAF0 = 0;
    D_0028EAEC = 0;
    D_0028EC20 = 0;
    D_0028EB88 = 1;
    D_0028EB28 = 1;
    memset(&D_0028EC18, 0, 6);
    memset(&D_0028EC10, 0, 6);
    memset(&D_0028EC08, 0, 6);
    memset(&D_0028EC00, 0, 6);
    memset(&D_0028EBF0, 0, 6);
    memset(&D_0028EBE8, 0, 6);
    memset(&D_0028EBE0, 0, 6);
    memset(&D_0028EBD8, 0, 6);
    replay_slots_reset();
    D_0028E368_as_s8 = 0;
    D_0028EB00 = 1;
    func_00222170();
    func_0021E1A0();
}

extern Obj38 D_00685010_as_Obj38_a_a16[][16];
extern u8 D_0068DC10_as_u8_a_a16[][16];

void func_00222170(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 16; j++) {
            D_00685010_as_Obj38_a_a16[i][j].active = 0;
            D_0068DC10_as_u8_a_a16[i][j] = 0;
        }
    }
    for (j = 0; j < 16; j++) {
        D_00685010_as_Obj38_a_a16[12][j].active = 0;
    }
}

extern s16 g_menu_item_positions_a_as_s16_a_a2[][2];

void func_00222260(s32 group) {
    s32 i;
    s32 count;
    s32 x;
    s32 y;
    s32 id;

    id = group + 100;
    count = g_menu_page_item_counts[group];
    for (i = 0; i < count; i++) {
        if (group == 15) {
            x = g_menu_item_positions_b[i][0];
            D_00685010_as_Obj38_a_a16[group][i].x = x;
            y = g_menu_item_positions_b[i][1];
            D_00685010_as_Obj38_a_a16[group][i].y = y;
            D_00685010_as_Obj38_a_a16[group][i].x2 = x;
            D_00685010_as_Obj38_a_a16[group][i].y2 = y;
        } else {
            x = g_menu_item_positions_a_as_s16_a_a2[i][0];
            D_00685010_as_Obj38_a_a16[group][i].x = x;
            y = g_menu_item_positions_a_as_s16_a_a2[i][1];
            D_00685010_as_Obj38_a_a16[group][i].y = y;
            D_00685010_as_Obj38_a_a16[group][i].x2 = x;
            D_00685010_as_Obj38_a_a16[group][i].y2 = y;
        }
        D_00685010_as_Obj38_a_a16[group][i].unk2C = 0;
        D_00685010_as_Obj38_a_a16[group][i].timer = 0x3C;
        D_00685010_as_Obj38_a_a16[group][i].id = id;
        D_00685010_as_Obj38_a_a16[group][i].active = 1;
    }
}

#pragma push
#pragma divbyzerocheck on


extern Point16 g_menu_item_positions_a_as_Point16_a[];
extern Point16 g_menu_item_positions_b_as_Point16_a[];
extern MoveItem D_00685010_as_MoveItem_a_a16[][16];

void func_00222340(s32 group) {
    s32 i;
    s32 count;
    s32 dx;
    s32 dy;
    s32 tag;

    tag = group + 100;
    count = g_menu_page_item_counts[group];
    for (i = 0; i < count; i++) {
        if (group == 15) {
            D_00685010_as_MoveItem_a_a16[group][i].x0 = -g_menu_item_positions_b_as_Point16_a[i].x;
            D_00685010_as_MoveItem_a_a16[group][i].y0 = g_menu_item_positions_b_as_Point16_a[i].y;
            D_00685010_as_MoveItem_a_a16[group][i].x1 = g_menu_item_positions_b_as_Point16_a[i].x;
            D_00685010_as_MoveItem_a_a16[group][i].y1 = g_menu_item_positions_b_as_Point16_a[i].y;
        } else {
            D_00685010_as_MoveItem_a_a16[group][i].x0 = -g_menu_item_positions_a_as_Point16_a[i].x;
            D_00685010_as_MoveItem_a_a16[group][i].y0 = g_menu_item_positions_a_as_Point16_a[i].y;
            D_00685010_as_MoveItem_a_a16[group][i].x1 = g_menu_item_positions_a_as_Point16_a[i].x;
            D_00685010_as_MoveItem_a_a16[group][i].y1 = g_menu_item_positions_a_as_Point16_a[i].y;
        }
        D_00685010_as_MoveItem_a_a16[group][i].step = 0;
        D_00685010_as_MoveItem_a_a16[group][i].timer = 60;
        D_00685010_as_MoveItem_a_a16[group][i].id = tag;
        D_00685010_as_MoveItem_a_a16[group][i].active = 1;
        dx = D_00685010_as_MoveItem_a_a16[group][i].x1 - D_00685010_as_MoveItem_a_a16[group][i].x0;
        dy = D_00685010_as_MoveItem_a_a16[group][i].y1 - D_00685010_as_MoveItem_a_a16[group][i].y0;
        if (dx < 0) {
            dx = -dx;
        }
        if (dy < 0) {
            dy = -dy;
        }
        D_00685010_as_MoveItem_a_a16[group][i].dx = 0;
        D_00685010_as_MoveItem_a_a16[group][i].dy = 0;
        if (dx != 0) {
            D_00685010_as_MoveItem_a_a16[group][i].dx = dx * 10000 / D_00271910[0];
        }
        if (dy != 0) {
            D_00685010_as_MoveItem_a_a16[group][i].dy = dy * 10000 / D_00271910[0];
        }
        D_00685010_as_MoveItem_a_a16[group][i].vx = D_00685010_as_MoveItem_a_a16[group][i].dx * 60;
        D_00685010_as_MoveItem_a_a16[group][i].vy = D_00685010_as_MoveItem_a_a16[group][i].dy * 60;
        D_00685010_as_MoveItem_a_a16[group][i].fx = D_00685010_as_MoveItem_a_a16[group][i].x0 * 10000;
        D_00685010_as_MoveItem_a_a16[group][i].fy = D_00685010_as_MoveItem_a_a16[group][i].y0 * 10000;
    }
}
#pragma pop



s32 func_00222530(s32 group) {
    s32 i;
    s32 count;
    s32 done;
    Mover *m;
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
            m = (Mover *)(D_00685010 + group * 0x380 + off);
            delay = &m->delay;
            if (*delay != 0) {
                (*delay)--;
            }
            if (*delay <= 0) {
                done++;
                m->x = m->targetX;
                m->y = m->targetY;
            }
            cur = &m->x;
            target = &m->targetX;
            if (m->x != m->targetX) {
                if (m->x < m->targetX) {
                    *cur = m->posX / 10000;
                    m->posX += m->speedX;
                    m->speedX -= m->accelX;
                    if (*cur > *target) {
                        *cur = *target;
                    }
                } else {
                    *cur = m->posX / 10000;
                    m->posX -= m->speedX;
                    m->speedX -= m->accelX;
                    if (*cur < *target) {
                        *cur = *target;
                    }
                }
            }
            cur = &m->y;
            target = &m->targetY;
            if (m->y != m->targetY) {
                if (m->y < m->targetY) {
                    *cur = m->posY / 10000;
                    m->posY += m->speedY;
                    m->speedY -= m->accelY;
                    if (*cur > *target) {
                        *cur = *target;
                    }
                } else {
                    *cur = m->posY / 10000;
                    m->posY -= m->speedY;
                    m->speedY -= m->accelY;
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


void func_00222780(void) {
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
        sel = D_0028EB14;
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
        sel = D_0028EB14 + 4;
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

void func_002228D0(s32 x, s32 y) {
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

void func_00222C30(s32 x, s32 y, s32 attr) {
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

void func_00222F90(s32 x, s32 y, s32 attr) {
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

void func_002232F0(void) {
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
            func_002234C0();
            break;
        case 2:
            sfx_menu_confirm();
            g_paused++;
            break;
        case 3:
            func_00223550();
            break;
        case 4:
            func_00223A60();
            break;
        case 5:
            func_00223AA0();
            break;
        case 0xB:
            func_00224CC0();
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
extern u16 D_0028E324;
extern u16 D_0028E328;
extern u16 g_loop;
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
#endif
extern u16 g_stage;
extern u8 D_0028EBBC;
extern s16 D_0028EBC8;
extern u8 D_0028EBCC;
extern u8 g_pause_menu_cursor_as_u8;
extern u8 g_replay_buffer_state;

void func_002234C0(void) {
    g_paused++;
    D_0028EBC8 = 0;
    g_menu_alpha = 0;
    g_pause_menu_cursor_as_u8 = 1;
    D_0028EBCC = 1;
    D_0028EB04 = 1;
    D_0028EB8C = 0;
    D_0028E324 = MAIN_OR_DEATH_LABEL(g_loop, death_D_00290DC0);
    D_0028E328 = g_stage;
    if (D_0028E328 == 0) {
        D_0028E328 = 1;
    }
    D_0028EBBC = 0x28;
    vibration_suspend();
    vibration_stop_all();
    streams_pause();
    if (g_replay_buffer_state == 1) {
        g_replay_buffer_state = 3;
    }
}

extern s8 D_0028EBC4;


extern void func_002035F0(void);
extern void vibration_start_pad1(s32 a, s32 b);
extern void vibration_start_pad2(s32 a, s32 b);
extern Pair g_menu_wallpapers_as_Pair_a[];
extern u16 g_pause_player;
extern u8 D_0028E378;
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
#endif
extern u8 g_display_reset_pending_as_u8;
extern s8 D_0028EBBC_as_s8;
extern s8 g_pause_menu_cursor;
s32 streams_resume();
s32 vibration_resume();
extern s8 g_pause_lock_timer_as_s8;
s32 replay_start_run();
s32 replay_start_result();
extern u8 g_replay_mode;
extern u8 g_simulation_active;
extern s16 D_00271C8C[];
extern s8 D_0028EBCC_as_s8;
extern s32 sprintf(char *buf, const char *format, ...);
extern void text_queue_sjis_vertical(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth);
extern char *g_pad_dma_buf;
extern u8 *D_00271BC8[];
extern u8 *D_00271BCC[];
extern u8 *D_00271BD0[];
extern u8 *D_00271BD4[];

void func_00223550(void) {
    extern void sfx_menu_confirm(void);
    extern void sfx_menu_tick(void);
    extern void wallpaper_load(s32 a, s32 b);
    u32 pad;

    if (D_0028EBBC_as_s8 != 0) {
        D_0028EBBC_as_s8--;
    }
    if (D_0028EBBC_as_s8 == 0 && (g_pad_trigger[g_pause_player] & 0x800)) {
        sfx_menu_confirm();
        g_paused++;
        return;
    }
    if (func_00223BE0() != 0) {
        return;
    }
    switch (g_pause_menu_cursor) {
    case 1:
        pad = g_pad_repeat[g_pause_player];
        if (pad & 0x8000) {
            sfx_menu_tick();
            D_0068DD02[0]--;
            D_0028E354 = D_0068DD02[0];
            if (D_0028E358 == 0) {
                D_0028E354 &= 3;
            } else {
                D_0028E354 &= 1;
            }
            D_0068DD02[0] = D_0028E354;
            g_display_reset_pending_as_u8 = 1;
        } else if (pad & 0x2000) {
            sfx_menu_tick();
            D_0068DD02[0]++;
            D_0028E354 = D_0068DD02[0];
            if (D_0028E358 == 0) {
                D_0028E354 &= 3;
            } else {
                D_0028E354 &= 1;
            }
            D_0068DD02[0] = D_0028E354;
            g_display_reset_pending_as_u8 = 1;
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
            D_0028E32C--;
            if ((s16)D_0028E32C < 0) {
                D_0028E32C = 5;
            }
            if (D_0028E32C != 5) {
                wallpaper_load(g_menu_wallpapers_as_Pair_a[D_0028E32C].a, g_menu_wallpapers_as_Pair_a[D_0028E32C].b);
            }
        } else if (pad & 0x2000) {
            sfx_menu_tick();
            D_0028E32C++;
            if (D_0028E32C > 5) {
                D_0028E32C = 0;
            }
            if (D_0028E32C != 5) {
                wallpaper_load(g_menu_wallpapers_as_Pair_a[D_0028E32C].a, g_menu_wallpapers_as_Pair_a[D_0028E32C].b);
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
            D_0028EAE4 = g_display_offset_x;
            g_paused = 0xB;
            D_0028EAE0 = g_display_offset_y;
        }
        break;
    case 6:
    case 7:
        if (g_pad_trigger[g_pause_player] & 0x20) {
            sfx_menu_confirm();
            D_0028EBC4 = 1;
            g_paused = 5;
        }
        break;
    case 8:
        if (g_pad_repeat[g_pause_player] & 0xA000) {
            sfx_menu_tick();
            D_0028E324++;
            D_0028E324 &= 1;
        }
        break;
    case 9:
        pad = g_pad_repeat[g_pause_player];
        if (pad & 0x8000) {
            sfx_menu_tick();
            D_0028E328--;
            if ((s32)D_0028E328 <= 0) {
                D_0028E328 = 5;
            }
        } else if (pad & 0x2000) {
            sfx_menu_tick();
            D_0028E328++;
            if (D_0028E328 > 5) {
                D_0028E328 = 1;
            }
        }
        if (D_0028E378 != 0xFF && (g_pad_trigger[g_pause_player] & 0x20)) {
            reg_d6.h[0] = 1;
            reg_d7.h[0] = D_0028E328;
            if (reg_d7.h[0] == 5) {
                reg_d7.h[0] = 0;
            }
            func_002035F0();
            g_paused = 0;
        }
        break;
    }
    MAIN_OR_DEATH_LABEL(g_loop, death_D_00290DC0) = D_0028E324;
}

void func_00223A60(void) {
    g_paused = 0;
    streams_resume();
    g_pause_lock_timer_as_s8 = 0x3C;
    vibration_resume();
    if (g_replay_buffer_state == 3) {
        g_replay_buffer_state = 1;
    }
}

void func_00223AA0(void) {
    extern void sfx_menu_confirm(void);
    extern void sfx_menu_tick(void);
    u32 buttons;

    buttons = g_pad_trigger[g_pause_player];
    if (buttons & 0x20) {
        if (D_0028EBC4 == 0) {
            if (g_simulation_active == 0 && g_replay_mode != 2) {
                func_00224A30();
            } else {
                sfx_menu_confirm();
                if (g_pause_menu_cursor == 7) {
                    replay_start_result();
                } else {
                    func_00224A90();
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
    if ((buttons & 0x8000) && D_0028EBC4 == 1) {
        sfx_menu_tick();
        D_0028EBC0 = 0;
        D_0028EBC4 = 0;
        return;
    }
    if ((buttons & 0x2000) && D_0028EBC4 == 0) {
        sfx_menu_tick();
        D_0028EBC0 = 0;
        D_0028EBC4 = 1;
    }
}

s32 func_00223BE0(void) {
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

void func_00223D70(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s32 x;

    switch (D_0028EBCC_as_s8) {
    case 0:
        break;
    case 1:
        D_0028EBC8 += 4;
        if (D_0028EBC8 >= 0x40) {
            D_0028EBCC_as_s8 = 0;
            D_0028EBC8 = 0x40;
        }
        break;
    case 2:
        D_0028EBC8 -= 4;
        if (D_0028EBC8 <= 0) {
            D_0028EBC8 = 0;
            D_0028EBCC_as_s8 = 0;
        }
        break;
    }
    if (g_simulation_active == 0 && g_pause_menu_cursor > 6) {
        x = D_00271C8C[g_pause_menu_cursor * 2];
    } else {
        x = D_00271C90[g_pause_menu_cursor * 2];
    }
    if (D_0028EBC8 != 0) {
        gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, D_0028EBC8, 0xB4, 1, 1);
    }
}

void func_00223E80(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s64 alpha;

    switch (D_0028EB04) {
    case 0:
        break;
    case 1:
        g_menu_alpha += 4;
        if (g_menu_alpha >= 0x80) {
            D_0028EB04 = 0;
            g_menu_alpha = 0x80;
        }
        break;
    case 2:
        g_menu_alpha -= 4;
        if (g_menu_alpha <= 0) {
            g_menu_alpha = 0;
            D_0028EB04 = 0;
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
            func_002228D0(0x36, 8);
        } else {
            func_00224020(0xC, 8);
        }
        text_flush();
    }
}

void func_00224020(s32 x, s32 y) {
    s32 shrink;
    s32 w;
    s32 h;
    s32 px;
    s32 py;

    if (D_0028EBC0 < 4) {
        D_0028EBC0 += 2;
    }
    px = x + 40;
    py = y + 10;
    shrink = 0;
    if (D_0028EBC0 != 0) {
        shrink = (s32)(s8)D_0028EBC0 / 2;
    }
    w = (s32)(s8)D_0028EBC0 + 20;
    h = (s32)(s8)D_0028EBC0 + 16;
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
    func_002228D0(x + 42, y);
    if (D_0028EBC4 == 0) {
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

void func_002242B0(s32 x, s32 y) {
    s32 shrink;
    s32 w;
    s32 h;
    s32 px;
    s32 py;

    if (D_0028EBC0 < 4) {
        D_0028EBC0 += 2;
    }
    px = x + 40;
    py = y + 10;
    shrink = 0;
    if (D_0028EBC0 != 0) {
        shrink = (s32)(s8)D_0028EBC0 / 2;
    }
    w = (s32)(s8)D_0028EBC0 + 20;
    h = (s32)(s8)D_0028EBC0 + 16;
    if (D_0028EB0C == 1) {
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


extern Point D_00271C90_as_Point_a[];

void func_002244E0(void) {
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
            func_00225450();
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
        func_00223D70();
        func_00223E80();
        glyph_queue_clear();
        x = D_00271C90_as_Point_a[0].x;
        y = D_00271C90_as_Point_a[0].y;
        reg_a0 = (u8 *)g_menu_pause_items[0];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        x = D_00271C90_as_Point_a[1].x;
        y = D_00271C90_as_Point_a[1].y;
        reg_a0 = (u8 *)g_menu_pause_items[1];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        if (D_0028E358 == 0) {
            reg_a0 = (u8 *)g_menu_monitor_mode_names[D_0028E354];
        } else {
            reg_a0 = (u8 *)g_menu_monitor_mode_tate_names[D_0028E354];
        }
        glyph_queue_add(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (g_pause_menu_cursor == 1) {
            func_00224BA0(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        x = D_00271C90_as_Point_a[2].x;
        y = D_00271C90_as_Point_a[2].y;
        reg_a0 = (u8 *)g_menu_pause_items[2];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        reg_a0 = (u8 *)D_0028DD18[g_pad_vib_enabled];
        glyph_queue_add(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (g_pause_menu_cursor == 2) {
            func_00224BA0(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        x = D_00271C90_as_Point_a[3].x;
        y = D_00271C90_as_Point_a[3].y;
        reg_a0 = (u8 *)g_menu_pause_items[3];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        reg_a0 = (u8 *)D_00271740[D_0028E32C];
        glyph_queue_add(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (g_pause_menu_cursor == 3) {
            func_00224BA0(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        x = D_00271C90_as_Point_a[4].x;
        y = D_00271C90_as_Point_a[4].y;
        reg_a0 = (u8 *)g_menu_pause_items[4];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        reg_a0 = (u8 *)D_0028DD18[g_stage_map_enabled];
        glyph_queue_add(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (g_pause_menu_cursor == 4) {
            func_00224BA0(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        reg_a0 = (u8 *)g_menu_pause_items[5];
        glyph_queue_add(D_00271C90_as_Point_a[5].x, D_00271C90_as_Point_a[5].y, 300, 0, 0x80, 0x80, 1);
        n = 6;
        if (g_simulation_active != 0) {
            n++;
            reg_a0 = (u8 *)g_menu_pause_items[6];
            glyph_queue_add(D_00271C90_as_Point_a[6].x, D_00271C90_as_Point_a[6].y, 300, 0, 0x80, 0x80, 1);
        }
        x = D_00271C90_as_Point_a[n].x;
        reg_a0 = (u8 *)g_menu_pause_items[7];
        glyph_queue_add(x, D_00271C90_as_Point_a[n].y, 300, 0, 0x80, 0x80, 1);
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

extern u16 D_0028E7BC;

void func_00224A30(void) {
    extern void sfx_menu_confirm(void);
    if (D_0028E7BC == 1 || D_0028E7BC == 0xF) {
        return;
    }
    func_00224A90();
    sfx_menu_confirm();
    reg_d0.h[0] = TASK_ATTRACT;
    task_start();
    *(u16 *)(reg_a0 + 4) = 0x12;
}

s32 layers_reset();
s32 func_0012FA50();
s32 func_0012FB00();
s32 layers_clear_all();
s32 func_0013B190();
s32 sound_stop_effects();
s32 music_stop();
s32 stage_map_reset();
s32 replay_header_clear();
extern u8 D_0028E1DA[];
extern u8 D_0028E1E6[];
extern u8 D_0028E2A0;
extern s16 D_0028E324_as_s16;
extern u8 D_0028E368;
extern s16 g_slowdown_loop2_allowed;
extern s16 g_select_screen_active_as_s16;
extern s16 g_attract_demo_as_s16;
extern s16 g_loop_as_s16;
extern u8 D_0028EC4C;
extern u8 D_0028ED64;
extern u8 g_replay_begin_pending;
extern s32 g_replay_position;

void func_00224A90(void) {
    sound_stop_effects();
    music_stop();
    func_0012FA50();
    func_0012FB00();
    layers_reset();
    g_attract_demo_as_s16 = 0;
    D_0028EAFC = 0xFF;
    D_0028E378 = 0xFF;
    g_paused = 0;
    D_0028E2A0 = 0;
    D_0028E368 = 0;
    func_00224B50();
    g_simulation_active = 0;
    replay_header_clear();
    g_replay_mode = 0;
    g_replay_buffer_state = 0;
    D_0028EC4C = 0;
    g_replay_begin_pending = 0;
    D_0028ED64 = 0;
    g_replay_position = 0;
#ifndef DEATH_LABEL
    g_select_screen_active_as_s16 = 0;
#endif
    layers_clear_all();
    task_reset_all();
    func_0013B190();
    stage_map_reset();
    g_loop_as_s16 = 0;
    D_0028E1DA[0] = 0;
    D_0028E324_as_s16 = 0;
    D_0028E1E6[0] = 0;
    g_slowdown_loop2_allowed = 0;
}

void func_00224B50(void) {
    g_setting_difficulty_as_s8 = D_0068DC21[0];
    g_setting_ship_stock_as_s8 = D_0068DC22[0];
    g_setting_extend_as_s8 = D_0068DC23[0];
    D_0028E2EC_as_s8 = D_0068DC44[0];
    D_0028E304_as_s8 = D_0068DC41[0];
#ifndef DEATH_LABEL
    printf("restore com setting\n", D_0068DC23[0], D_0068DC22[0], D_0068DC21[0]);
#endif
}

extern s32 g_frame_counter;

void func_00224BA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags) {
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
extern s8 g_paused_as_s8;
void func_00224CC0(void) {
    s32 sfx_menu_confirm();
    s32 sfx_menu_tick();
    s32 temp_v1;

    temp_v1 = g_pad_trigger[g_pause_player];
    if (temp_v1 & 0x20) {
        sfx_menu_confirm();
        g_display_offset_x = D_0028EAE4;
        g_display_offset_y = D_0028EAE0;
        display_set_offset(g_display_offset_x, g_display_offset_y);
        g_menu_alpha = 0;
        g_paused_as_s8 = 3;
        D_0028EB04 = 1;
        return;
    }
    if (temp_v1 & 0x40) {
        sfx_menu_confirm();
        display_set_offset(g_display_offset_x, g_display_offset_y);
        g_menu_alpha = 0;
        g_paused_as_s8 = 3;
        D_0028EB04 = 1;
        return;
    }
    if (temp_v1 & 0x100) {
        sfx_menu_confirm();
        D_0028EAE4 = D_0028EAE0 = 0;
        display_set_offset(D_0028EAE4, D_0028EAE0);
    }
    if ((g_screen_mode != 2) && (g_screen_mode != 3)) {
        if ((g_pad_repeat[g_pause_player] & 0x4000) && (D_0028EAE4 > -8)) {
            sfx_menu_tick();
            D_0028EAE4 -= 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x1000) && (D_0028EAE4 < 8)) {
            sfx_menu_tick();
            D_0028EAE4 += 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x2000) && (D_0028EAE0 < 8)) {
            sfx_menu_tick();
            D_0028EAE0 += 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x8000) && (D_0028EAE0 > -8)) {
            sfx_menu_tick();
            D_0028EAE0 -= 1;
        }
    } else {
        if ((g_pad_repeat[g_pause_player] & 0x4000) && (D_0028EAE0 < 8)) {
            sfx_menu_tick();
            D_0028EAE0 += 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x1000) && (D_0028EAE0 > -8)) {
            sfx_menu_tick();
            D_0028EAE0 -= 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x2000) && (D_0028EAE4 < 8)) {
            sfx_menu_tick();
            D_0028EAE4 += 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x8000) && (D_0028EAE4 > -8)) {
            sfx_menu_tick();
            D_0028EAE4 -= 1;
        }
    }
    display_set_offset(D_0028EAE4, D_0028EAE0);
}

void func_00225000(void) {
    s32 sfx_menu_confirm();
    s32 sfx_menu_tick();
    if (g_pad_trigger[2] & 0x20) {
        sfx_menu_confirm();
        g_display_offset_x = D_0028EAE4;
        g_display_offset_y = D_0028EAE0;
        display_set_offset(g_display_offset_x, g_display_offset_y);
        D_0028EB04 = 1;
        g_menu_alpha = 0;
        func_00222260(0xF);
        g_menu_page = 0xF;
        D_0028EB68 = 3;
        D_0028EB38 = 1;
        return;
    }
    if (g_pad_trigger[2] & 0x40) {
        sfx_menu_confirm();
        display_set_offset(g_display_offset_x, g_display_offset_y);
        D_0028EB04 = 1;
        g_menu_alpha = 0;
        func_00222260(0xF);
        g_menu_page = 0xF;
        D_0028EB68 = 3;
        D_0028EB38 = 1;
        return;
    }
    if (g_pad_trigger[2] & 0x100) {
        sfx_menu_confirm();
        D_0028EAE4 = D_0028EAE0 = 0;
        display_set_offset(D_0028EAE4, D_0028EAE0);
    }
    if ((g_screen_mode != 2) && (g_screen_mode != 3)) {
        if ((g_pad_repeat[2] & 0x4000) && (D_0028EAE4 > -8)) {
            sfx_menu_tick();
            D_0028EAE4 -= 1;
        }
        if ((g_pad_repeat[2] & 0x1000) && (D_0028EAE4 < 8)) {
            sfx_menu_tick();
            D_0028EAE4 += 1;
        }
        if ((g_pad_repeat[2] & 0x2000) && (D_0028EAE0 < 8)) {
            sfx_menu_tick();
            D_0028EAE0 += 1;
        }
        if ((g_pad_repeat[2] & 0x8000) && (D_0028EAE0 > -8)) {
            sfx_menu_tick();
            D_0028EAE0 -= 1;
        }
    } else {
        if ((g_pad_repeat[2] & 0x4000) && (D_0028EAE0 < 8)) {
            sfx_menu_tick();
            D_0028EAE0 += 1;
        }
        if ((g_pad_repeat[2] & 0x1000) && (D_0028EAE0 > -8)) {
            sfx_menu_tick();
            D_0028EAE0 -= 1;
        }
        if ((g_pad_repeat[2] & 0x2000) && (D_0028EAE4 < 8)) {
            sfx_menu_tick();
            D_0028EAE4 += 1;
        }
        if ((g_pad_repeat[2] & 0x8000) && (D_0028EAE4 > -8)) {
            sfx_menu_tick();
            D_0028EAE4 -= 1;
        }
    }
    display_set_offset(D_0028EAE4, D_0028EAE0);
}

extern void *g_dma_gif;

void func_002252E0(void *buffer) {
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
extern u8 g_gif_buf_as_u8_a2_a0x10000[2][0x10000];

void func_00225450(void) {
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
    func_002252E0(g_gif_buf_as_u8_a2_a0x10000[0]);
    text_queue_clear();
    frame_draw_wide_left_panel(0x80);
    gfx_draw_color_box(0xC, 8, 0x70, 0xD0, 0x12C, 0x40, 1, 1, 0x40);
    reg_a0 = (u8 *)g_menu_screen_adjust_help;
    func_002228D0(0x62, 8);
    text_flush();
    sprintf(buf, "%3d,%d", D_0028EAE4, D_0028EAE0);
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

extern s8 D_0028E374_as_s8;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern s8 D_0028EC64;

void func_00225630(void) {
    D_0028EC64 = 0;
    if (g_cd_async_state != 0) {
        sceCdBreak();
    }
    g_cd_async_state = 0;
    D_0028E374_as_s8 = 1;
    g_cd_async_busy = 1;
}


void func_00225670(void) {
    D_0028EC64 = 0;
    if (g_cd_async_state != 0) {
        sceCdBreak();
    }
    g_cd_async_state = 0;
    D_0028E374_as_s8 = 2;
    g_cd_async_busy = 1;
}

extern u8 D_0028EC64_as_u8;

void func_002256B0(void) {
    D_0028EC64_as_u8 = 3;
}

extern u8 D_0028E374;
extern s16 D_0028EC5C;
extern s8 D_0028EC60;

void func_002256C0(void) {
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

    if (D_0028E374 != 0) {
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
        switch (D_0028EC64) {
        case 0:
            D_0028EC5C = 0;
            D_0028EC64++;
            D_0028EC60 = 0;
        case 1:
            D_0028EC5C += 8;
            if (D_0028EC5C >= 0x80) {
                D_0028EC5C = 0x80;
                D_0028EC64++;
            }
            break;
        case 2:
            D_0028EC60++;
            if (D_0028EC60 >= 120) {
                D_0028EC60 = 0;
            }
            break;
        case 3:
            D_0028EC5C -= 8;
            if (D_0028EC5C <= 0) {
                D_0028EC5C = 0;
                D_0028EC64++;
            }
            break;
        case 4:
            D_0028E374 = 0;
            break;
        }
        alpha = D_0028EC5C;
        if (D_0028EC64 < 3 && D_0028E374 == 1) {
            gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x18F, 0x60, 1, 1, 1);
        }
        glyph_queue_clear();
        if (D_0028E374 == 1) {
            x = 32;
            y = 104;
        } else {
            x = 96;
            y = 72;
        }
        reg_a0 = (u8 *)g_menu_now_loading_text;
        glyph_queue_add(x, y, 400, 0, 0x80, alpha, 1);
        if (D_0028EC60 >= 30) {
            reg_a0 = (u8 *)g_menu_dot_text;
            y += 88;
            glyph_queue_add(x, y, 400, 0, 0x80, alpha, 1);
        }
        if (D_0028EC60 >= 60) {
            reg_a0 = (u8 *)g_menu_dot_text;
            y += 8;
            glyph_queue_add(x, y, 400, 0, 0x80, alpha, 1);
        }
        if (D_0028EC60 >= 90) {
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

s32 func_0022C6A0();
s32 func_00235890();
extern s32 D_0028EAD4;
extern s32 D_0028ED0C;

void func_00225A00(void) {
    switch (D_0028EC6C) {                           /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        D_0028EAD4 = 0;
        D_0028EC6C += 1;
        D_0028ED0C = 0;
        /* fallthrough */
    case 1:                                         /* switch 1 */
        switch (D_0028EAD4) {                       /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            func_0022C6A0(0);
            if (D_0028ED0C != 0) {
                func_00235890();
                D_0028EAD4 += 1;
                break;
            }
            break;
        case 1:                                     /* switch 2 */
            D_0028ED0C = 0;
            D_0028EC6C += 1;
            break;
        }
        break;
    default:                                        /* switch 1 */
        g_menu_page = 2;
        break;
    }
}

s32 func_0022C6D0();
s32 func_00234EF0();
extern s32 D_0028EAD0;
extern s32 D_0028ECC4;

void func_00225AB0(void) {
    switch (D_0028EC68) {                           /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        D_0028EAD0 = 0;
        D_0028EC68 += 1;
        D_0028ED0C = 0;
        /* fallthrough */
    case 1:                                         /* switch 1 */
        switch (D_0028EAD0) {                       /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            func_0022C6D0(0);
            if (D_0028ED0C != 0) {
                D_0028EAD0 += 1;
                break;
            }
            break;
        case 1:                                     /* switch 2 */
            D_0028ED0C = 0;
            if (D_0028ECC4 != 0) {
                func_00234EF0(D_0028EAD0);
                func_00235890();
            }
            D_0028EC68 += 1;
            break;
        }
        break;
    default:                                        /* switch 1 */
        g_menu_page = 2;
        break;
    }
}

extern s32 D_0028EAC0;
extern s32 D_0028EAC4;
extern s8 D_0028EACC;


void func_00225B70(void) {
    D_0028EAC4 = 0;
    D_0028EACC = 1;
    D_0028EAC0 = 1;
    D_0028EB04 = 1;
    g_menu_alpha = 0;
    D_0028EB8C = 0;
    replay_slots_reset();
}

extern s8 D_0028EAC8;
void func_00225B90(void) {
    s32 sfx_menu_confirm();
    s32 sfx_menu_move();
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;

    temp_a1 = g_menu_pad * 4;
    temp_a0 = *(u32 *)((u8 *)g_pad_trigger + temp_a1);
    if (temp_a0 & 0x40) {
        D_0028EAC0 = 2;
        D_0028EB04 = 2;
        D_0028EAC8 = 2;
        D_0028EACC += 1;
        sfx_menu_confirm();
        return;
    }
    if (temp_a0 & 0x20) {
        D_0028EAC0 = 2;
        sfx_menu_confirm();
        if (D_0028EAC8 == 3) {
            D_0028EACC = 0x40;
            return;
        }
        D_0028EB04 = 2;
        D_0028EACC += 1;
        return;
    }
    temp_a0_2 = *(u32 *)((u8 *)g_pad_repeat + temp_a1);
    if (temp_a0_2 & 0x1000) {
        sfx_menu_move();
        D_0028EAC8 -= 1;
        if (0 >= D_0028EAC8) {
            D_0028EAC8 = 2;
        }
    } else if (temp_a0_2 & 0x4000) {
        sfx_menu_move();
        D_0028EAC8 += 1;
        if (D_0028EAC8 >= 3) {
            D_0028EAC8 = 1;
        }
    }
}

void func_00225CB0(void) {
    if (D_0028EAC4 == 0) {
        D_0028EACC += 1;
    }
}


s8 func_00225CD0(void) {
    s8 var_s0;

    var_s0 = 0;
    switch (D_0028EACC) {
    default:
        if (D_0028EACC != 0) {
            D_0028EACC += 1;
        }
        break;
    case 0x1:
        func_00225B90();
        break;
    case 0x2:
        var_s0 = D_0028EAC8;
        D_0028EACC += 1;
        break;
    case 0x3:
        func_00225CB0();
        break;
    case 0x20:
        D_0028EACC = 0;
        break;
    case 0x40:
        replay_slots_open(1, g_menu_pad, 0);
        D_0028EACC += 1;
        break;
    case 0x41:
        switch (replay_slots_update()) {
        case 0:
            D_0028EACC = 1;
            D_0028EAC0 = 1;
            break;
        }
        break;
    case 0x50:
        func_0022A870();
        break;
    case 0x51:
        D_0028EAC4 = 0;
        D_0028EACC = 1;
        D_0028EAC0 = 1;
        D_0028EB04 = 1;
        g_menu_alpha = 0;
        D_0028EB8C = 0;
        replay_slots_reset();
        break;
    }
    return var_s0;
}


void func_00225E20(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    s32 x;

    switch (D_0028EAC0) {
    case 0:
        break;
    case 1:
        D_0028EAC4 += 4;
        if (D_0028EAC4 >= 0x40) {
            D_0028EAC0 = 0;
            D_0028EAC4 = 0x3C;
        }
        break;
    case 2:
        D_0028EAC4 -= 4;
        if (0 >= D_0028EAC4) {
            D_0028EAC4 = 0;
            D_0028EAC0 = 0;
        }
        break;
    }
    x = g_menu_result_positions[D_0028EAC8 * 2];
    if (D_0028EAC4 != 0) {
        gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, D_0028EAC4, 0xB4, 1, 1);
    }
}

extern Point g_menu_result_positions_as_Point_a[];

void func_00225EF0(void) {
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

    if (D_0028EACC != 0) {
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
        if (D_0028EACC == 0x50 || D_0028EACC == 0x51) {
            func_0022AA20();
        } else {
            func_00225E20();
            func_002260F0();
            replay_slots_draw();
            glyph_queue_clear();
            alpha = D_0028EAC4 * 2;
            for (i = 0; i < 3; i++) {
                reg_a0 = (u8 *)g_menu_result_items[i];
                glyph_queue_add(g_menu_result_positions_as_Point_a[i].x, g_menu_result_positions_as_Point_a[i].y, 0x12C, 0, 0x80, alpha, 1);
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


void func_002260F0(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    s32 alpha;

    switch (D_0028EB04) {
    case 0:
        break;
    case 1:
        g_menu_alpha += 4;
        if (g_menu_alpha >= 0x80) {
            D_0028EB04 = 0;
            g_menu_alpha = 0x80;
        }
        break;
    case 2:
        g_menu_alpha -= 4;
        if (g_menu_alpha <= 0) {
            g_menu_alpha = 0;
            D_0028EB04 = 0;
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
        if (D_0028EACC >= 0x40) {
            if (g_replay_slots_state_as_u8 != 0 && (u32)(g_replay_slots_state_as_u8 - 1) > 1 && (u32)(g_replay_slots_state_as_u8 - 5) > 1) {
                reg_a0 = (u8 *)g_menu_save_file_help;
                func_002228D0(0x36, 8);
            }
        } else {
            reg_a0 = (u8 *)g_menu_result_help[D_0028EAC8];
            func_002228D0(0x36, 8);
        }
        text_flush();
    }
}

/* .sbss (the compiler lays these out in reverse) */
s32 D_0028EC6C;
s32 D_0028EC68;
#ifdef DEATH_LABEL
u8 death_D_00290DC0 __attribute__((aligned(4)));
u8 death_D_00290DBC;
u32 death_D_00290DB8;
u32 death_D_00290DB4;
#endif
s8 D_0028EC64 __attribute__((aligned(4)));
s8 D_0028EC60 __attribute__((aligned(4)));
s16 D_0028EC5C __attribute__((aligned(4)));
s8 D_0028EC58 __attribute__((aligned(4)));
#ifndef DEATH_LABEL
u8 D_0028EC54;
#endif
s32 D_0028EC50;
u8 D_0028EC4C;
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
s8 D_0028EC20;
s32 D_0028EC1C;
s8 D_0028EC1A;
u8 D_0028EC19;
u8 D_0028EC18;
s32 D_0028EC14;
s8 D_0028EC12;
u8 D_0028EC11;
u8 D_0028EC10;
s32 D_0028EC0C;
s8 D_0028EC0A;
u8 D_0028EC09;
u8 D_0028EC08;
s32 D_0028EC04;
s8 D_0028EC02;
u8 D_0028EC01;
u8 D_0028EC00;
Fade D_0028EBF8;
Fade D_0028EBF0;
Fade D_0028EBE8;
Fade D_0028EBE0;
s32 D_0028EBDC;
u8 D_0028EBD8 __attribute__((aligned(8)));
s8 g_pause_menu_cursor __attribute__((aligned(4)));
u8 D_0028EBCC __attribute__((aligned(4)));
s16 D_0028EBC8 __attribute__((aligned(4)));
s8 D_0028EBC4 __attribute__((aligned(4)));
s8 D_0028EBC0 __attribute__((aligned(4)));
u8 D_0028EBBC;
s32 D_0028EBB8;
s32 D_0028EBB4;
s32 D_0028EBB0;
s32 D_0028EBAC;
s32 D_0028EBA8;
s32 D_0028EBA4;
s32 D_0028EBA0;
s32 D_0028EB9C;
s32 D_0028EB98;
#ifdef DEATH_LABEL
s32 death_D_00290CE4;
#endif
s32 D_0028EB94;
s32 g_menu_alpha;
s32 D_0028EB8C;
s8 D_0028EB88 __attribute__((aligned(4)));
s8 g_menu_page __attribute__((aligned(4)));
s8 D_0028EB80 __attribute__((aligned(4)));
s8 g_menu_step __attribute__((aligned(4)));
s8 D_0028EB78 __attribute__((aligned(4)));
s8 D_0028EB74 __attribute__((aligned(4)));
s8 D_0028EB70 __attribute__((aligned(4)));
s8 D_0028EB6C __attribute__((aligned(4)));
s8 D_0028EB68 __attribute__((aligned(4)));
s8 D_0028EB64 __attribute__((aligned(4)));
s8 D_0028EB60 __attribute__((aligned(4)));
#ifdef DEATH_LABEL
s8 death_D_00290CA8 __attribute__((aligned(4)));
#endif
s8 D_0028EB5C __attribute__((aligned(4)));
s8 g_menu_cursor __attribute__((aligned(4)));
s8 D_0028EB54 __attribute__((aligned(4)));
s8 g_menu_box_alpha __attribute__((aligned(4)));
s8 D_0028EB4C __attribute__((aligned(4)));
s8 D_0028EB48 __attribute__((aligned(4)));
s8 D_0028EB44 __attribute__((aligned(4)));
s8 D_0028EB40 __attribute__((aligned(4)));
s8 D_0028EB3C __attribute__((aligned(4)));
s8 D_0028EB38 __attribute__((aligned(4)));
s8 D_0028EB34 __attribute__((aligned(4)));
s8 D_0028EB30 __attribute__((aligned(4)));
#ifdef DEATH_LABEL
s8 death_D_00290C74 __attribute__((aligned(4)));
#endif
s8 D_0028EB2C __attribute__((aligned(4)));
s8 D_0028EB28 __attribute__((aligned(4)));
s8 D_0028EB24 __attribute__((aligned(4)));
s8 D_0028EB20 __attribute__((aligned(4)));
s8 D_0028EB1C __attribute__((aligned(4)));
s8 D_0028EB18 __attribute__((aligned(4)));
s8 D_0028EB14 __attribute__((aligned(4)));
s8 D_0028EB10 __attribute__((aligned(4)));
s8 D_0028EB0C __attribute__((aligned(4)));
#ifdef DEATH_LABEL
s8 death_D_00290C4C __attribute__((aligned(4)));
#endif
s8 D_0028EB08 __attribute__((aligned(4)));
s8 D_0028EB04 __attribute__((aligned(4)));
s8 D_0028EB00;
s32 D_0028EAFC;
s32 D_0028EAF8;
s32 D_0028EAF4;
s32 D_0028EAF0;
s32 D_0028EAEC;
s8 D_0028EAE8 __attribute__((aligned(4)));
s8 D_0028EAE4 __attribute__((aligned(4)));
s8 D_0028EAE0 __attribute__((aligned(4)));
s8 D_0028EADC;
s32 D_0028EAD8;
s32 D_0028EAD4;
s32 D_0028EAD0;
s8 D_0028EACC __attribute__((aligned(4)));
s8 D_0028EAC8;
s32 D_0028EAC4;
s32 D_0028EAC0;
s32 D_0028EABC;
u8 D_0028EAB8 __attribute__((aligned(4)));
u8 g_replay_disc_load_step __attribute__((aligned(4)));
u8 g_replay_disc_load_slot;
u8 *g_replay_disc_load_buf;
#ifndef DEATH_LABEL
s8 D_0028EAA8 __attribute__((aligned(4)));
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

s16 g_menu_result_positions[16] = {
    0x18c, 8, 0x164, 8, 0x14c, 8, 0x134, 8,
    0x11c, 8, 0, 0, 0, 0, 0, 0,
};

#ifdef DEATH_LABEL
char *g_menu_save_file_help = SJIS("セーブするファイルを選択／して下さい。／      ○決定  ×戻る￥");
#else
char *g_menu_save_file_help = SJIS("セーブするファイルを／選択して下さい。／      ○決定  ×戻る￥");
#endif

/* The replay slot screens. */

extern u8 g_replay_slots_from_disc;
extern u8 g_replay_slots_state_as_u8;

s32 replay_slots_update(void) {
    if (g_replay_slots_from_disc == 0) {
        switch (g_replay_slots_state_as_u8) {
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
        switch (g_replay_slots_state_as_u8) {
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
extern s8 g_replay_slots_from_disc_as_s8;
extern s8 g_replay_slots_pad_as_s8;

void replay_slots_open(s8 arg0, s8 arg1, s8 arg2) {
    g_replay_slots_pad_as_s8 = arg1;
    g_replay_slots_saving = arg0;
    g_replay_slots_state = 1;
    g_replay_slots_from_disc_as_s8 = arg2;
}

void replay_slots_close(void) {
    g_replay_slots_state = 7;
    g_replay_slots_fade = 2;
}

s32 func_00236900();                            /* extern */
extern s32 g_memcard_watch_step;

void replay_slots_card_scan_begin(void) {
    g_memcard_watch_step = 0;
    func_00236900();
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
extern s8 D_0028EB04;
extern s32 g_menu_alpha;

void replay_slots_card_scan_wait(void) {
    if (memcard_watch_update() != 0) {
        g_replay_slots_state = 3;
        g_replay_slots_fade = 1;
        g_menu_alpha = 0x40;
        D_0028EB04 = 1;
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
extern s8 g_replay_slots_step_as_s8;
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
        g_replay_slots_step_as_s8 = 0;
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

s32 func_0022C750();
s32 memcard_watch_recheck();
s32 func_00236960();
extern s32 D_0028EABC;
extern u8 g_replay_slots_step;
extern s32 D_0028ECC0;
extern s32 D_0028ED0C;

s32 replay_slots_card_save(void) {
    switch (g_replay_slots_step) {
    case 0:
        D_0028ED0C = 0;
        g_replay_slots_step += 1;
    case 1:
        func_0022C750(g_replay_slots_cursor + 1);
        if (D_0028ED0C != 0) {
            memcard_watch_recheck();
            D_0028ED0C = 0;
            g_memcard_watch_step = 0;
            g_replay_slots_step += 1;
            D_0028EABC = D_0028ECC0;
            if (D_0028ECC0 != 0) {
                func_00236960(g_replay_slots_cursor);
            }
        }
        break;
    case 2:
        if (memcard_watch_update() != 0) {
            D_0028EB04 = 1;
            g_menu_alpha = 0x40;
            g_replay_slots_state = 4;
            g_replay_slots_step = 0;
            if (D_0028EABC != 0) {
                return 2;
            }
        }
        break;
    }
    return 1;
}

s32 func_0022C760(s32);                         /* extern */
s32 memcard_watch_recheck();                            /* extern */
s32 replay_file_pointers_decode(s32 *);                   /* extern */
extern s8 g_replay_slot_loaded;
extern s32 D_0028ECC4;
extern u8 D_0028ED30;
extern u8 D_0028ED31;
extern u8 D_0028ED32;
extern u8 D_0028ED33;
extern u8 D_0028ED34;
extern u8 D_0028ED35;
extern u8 D_0028ED36;
extern u8 D_0028ED37;
extern s32 g_replay_file_loaded_as_s32_a[];
extern s32 g_replay_file_as_s32_a[];
extern u8 D_006C58D8[];
extern u8 D_006C58D9[];
extern u8 D_006C58DA[];
extern u8 D_006C58DB[];
extern u8 D_006C58DC[];
extern u8 D_006C58DD[];
extern u8 D_006C58DE[];
extern u8 D_006C58DF[];
extern s32 g_replay_snapshot_as_s32_a[];

s32 replay_slots_card_load(void) {
    switch (g_replay_slots_step) {                           /* irregular */
    case 0:
        D_0028ED0C = 0;
        g_replay_slots_step += 1;
        /* fallthrough */
    case 1:
        func_0022C760(g_replay_slots_cursor + 1);
        if (D_0028ED0C != 0) {
            memcard_watch_recheck();
            g_replay_slots_state = 4;
            D_0028ED0C = 0;
            D_0028EB04 = 1;
            g_replay_slots_step = 0;
            g_menu_alpha = 0x40;
            g_replay_slot_loaded = g_replay_slots_cursor;
            if (D_0028ECC4 != 0) {
                memcpy(g_replay_file_as_s32_a, g_replay_file_loaded_as_s32_a, 0x202E8);
                delta_encode((u8 *)g_replay_snapshot_as_s32_a);
                replay_file_pointers_decode(g_replay_file_as_s32_a);
                D_0028ED30 = D_006C58D8[0];
                D_0028ED31 = D_006C58D9[0];
                D_0028ED32 = D_006C58DA[0];
                D_0028ED33 = D_006C58DB[0];
                D_0028ED34 = D_006C58DC[0];
                D_0028ED35 = D_006C58DD[0];
                D_0028ED36 = D_006C58DE[0];
                D_0028ED37 = D_006C58DF[0];
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

extern s8 D_0028EB04;
extern s32 g_menu_alpha;
extern s8 g_replay_slots_fade;

void replay_slots_disc_scan(void) {
    if (replay_disc_headers_load() != 0) {
        g_replay_slots_state = 3;
        g_replay_slots_fade = 1;
        g_menu_alpha = 0x40;
        D_0028EB04 = 1;
    }
}

extern u8 g_replay_slots_state_as_u8;

void replay_slots_disc_ready(void) {
    g_replay_slots_state_as_u8 = 4;
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
extern u8 g_replay_slots_cursor_as_u8;
extern u8 D_0028ED30;
extern u8 D_0028ED31;
extern u8 D_0028ED32;
extern u8 D_0028ED33;
extern u8 D_0028ED34;
extern u8 D_0028ED35;
extern u8 D_0028ED36;
extern u8 D_0028ED37;
extern u8 g_replay_file_loaded[];
extern u8 g_replay_file[];
extern u8 D_006C58D8[];
extern u8 D_006C58D9[];
extern u8 D_006C58DA[];
extern u8 D_006C58DB[];
extern u8 D_006C58DC[];
extern u8 D_006C58DD[];
extern u8 D_006C58DE[];
extern u8 D_006C58DF[];
extern u8 g_replay_snapshot[];
s32 replay_slots_disc_load(void) {
    s32 replay_file_pointers_decode();
    if (replay_disc_file_load(g_replay_slots_cursor_as_u8) != 0) {
        g_replay_slot_loaded = *(s8 *)&g_replay_slots_cursor_as_u8;
        D_0028EB04 = 1;
        g_menu_alpha = 0x40;
        memcpy(g_replay_file, g_replay_file_loaded, 0x202E8);
        delta_encode(g_replay_snapshot);
        replay_file_pointers_decode(g_replay_file);
        D_0028ED30 = D_006C58D8[0];
        D_0028ED31 = D_006C58D9[0];
        D_0028ED32 = D_006C58DA[0];
        D_0028ED33 = D_006C58DB[0];
        D_0028ED34 = D_006C58DC[0];
        D_0028ED35 = D_006C58DD[0];
        D_0028ED36 = D_006C58DE[0];
        D_0028ED37 = D_006C58DF[0];
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

extern u8 g_replay_slots_fade_as_u8;
extern u8 g_replay_slot_infos_as_u8_a_a0x400[][0x400];

s32 replay_slots_draw(void) {
    s32 i;
    s32 y;

    if (g_replay_slots_state_as_u8 == 0) {
        return 0;
    }
    switch (g_replay_slots_fade_as_u8) {
    case 0:
        break;
    case 1:
        g_replay_slots_alpha += 4;
        if (g_replay_slots_alpha >= 0x80) {
            g_replay_slots_fade_as_u8 = 0;
            g_replay_slots_alpha = 0x80;
        }
        break;
    case 2:
        g_replay_slots_alpha -= 4;
        if (0 >= g_replay_slots_alpha) {
            g_replay_slots_alpha = 0;
            g_replay_slots_fade_as_u8 = 0;
        }
        break;
    }
    if (0 < g_replay_slots_alpha) {
        y = 0x18A;
        for (i = 0; i < 10; i++) {
            replay_slot_draw(i, y, 0, g_replay_slots_alpha, (i == g_replay_slots_cursor) ? 1 : 0, (SaveInfo *)g_replay_slot_infos_as_u8_a_a0x400[i]);
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
void func_00227120(void) {
    u8 sp10[0x16];
    u8 sp30[0xA];
    u8 sp40[0xC];

    memcpy(sp10, D_0068DEF0, 0x16);
    memcpy(sp30, D_0068DED8, 0xA);
    memcpy(sp40, D_0068DEC8, 0xC);
    func_00221FF0();
    func_00224B50();
    memcpy(D_0068DEF0, sp10, 0x16);
    memcpy(D_0068DED8, sp30, 0xA);
    memcpy(D_0068DEC8, sp40, 0xC);
    D_0028EBE8.step = 0;
    g_menu_page = 0xA;
    fade_start_in();
}
extern u8 g_replay_slots_from_disc;
void func_002271D0(void) {
    u8 sp10[0x16];
    u8 sp30[0xA];
    u8 sp40[0xC];

    memcpy(sp10, D_0068DEF0, 0x16);
    memcpy(sp30, D_0068DED8, 0xA);
    memcpy(sp40, D_0068DEC8, 0xC);
    func_00221FF0();
    func_00224B50();
    memcpy(D_0068DEF0, sp10, 0x16);
    memcpy(D_0068DED8, sp30, 0xA);
    memcpy(D_0068DEC8, sp40, 0xC);
    if (g_replay_slots_from_disc == 0) {
        D_0028EBE0.step = 0;
        g_menu_page = 0xB;
        func_00227C90();
    } else {
        D_0028EBE0.step = 0;
        g_menu_page = 0x16;
        func_00227E30();
    }
    while (D_0028EBE0.step != 2) {
        func_00227CD0();
    }
    fade_start_in();
}

s32 fade_start_out();                            /* extern */
extern s8 D_0028EAC8;
extern s8 D_0028EB00;
extern s8 D_0028EB54;
extern s8 D_0028EB88;

void func_002272D0(void) {
    D_0028EB54 = 2;
    D_0028EB00 = 3;
    D_0028EB88 = 2;
    g_menu_page = 0;
    fade_start_out();
    D_0028EAC8 = 1;
}


extern Fade D_0028EBD8_as_Fade;
extern Fade D_0028EC00_as_Fade;
extern Fade D_0028EC08_as_Fade;
extern Fade D_0028EC10_as_Fade;
extern Fade D_0028EC18_as_Fade;


extern s8 g_menu_cursor;
extern u16 D_0028E320_as_u16;
extern u8 D_00685010[];
extern s8 g_menu_box_alpha;
extern s8 D_002714F7[];
extern s8 D_0028EB4C;
extern s8 g_menu_step;
extern s8 g_menu_pad;
extern s32 D_0028EC7C;
s32 func_002365A0();
extern s16 D_0068DF02[];
extern s16 D_00270822[];
extern s8 D_002714FA[];
extern u8 D_0028E258;
extern u8 D_0028E280;
extern s8 D_0028EC20;
extern s8 g_replay_mode_as_s8;
extern s16 D_00270810_as_s16_a[];
extern s16 D_00270828[];
extern s16 D_00270838[];
extern s16 D_0068DE90_as_s16_a[];
extern s16 D_0068DEA0_as_s16_a[];
extern s16 D_0068DEB0_as_s16_a[];
extern s16 D_0068DEC8_as_s16_a[];
extern s16 D_0068DECA[];
extern s16 D_0068DECC[];
extern s16 D_0068DECE[];
extern s16 D_0068DED0[];
extern s16 D_0068DED2[];
extern s16 D_0068DED8_as_s16_a[];
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
extern s32 D_006880A0[];
extern s32 D_006880A4[];

static void func_00227310(Fade *fade) {
    D_0028E320_as_u16 = 0xE10;
    fade->value = 0x40;
    fade->state = 1;
    fade->step += 1;
    fade->flag = 1;
    g_menu_alpha = 0x40;
    D_0028EB04 = 1;
    D_0028EB54 = 0;
    g_menu_box_alpha = 0;
}

s32 func_00227350(Fade *fade, s32 command) {
    if (func_00222530(command) != 0) {
        fade->step += 1;
        g_menu_cursor = 1;
        g_menu_alpha = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        return 1;
    }
    return 0;
}

static s32 func_002273B0(Fade *fade, s32 command) {
    fade->step += 1;
    g_menu_cursor = 1;
    g_menu_alpha = 0x40;
    D_0028EB54 = 1;
    D_0028EB04 = 1;
    return 1;
}

void func_002273E0(void) {
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_trigger[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if (D_0028E320_as_u16 == 0) {
            g_pad_trigger[1] = 0x40;
            g_pad_trigger[0] = 0x40;
            g_pad_trigger[2] = 0x40;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
}

static void func_00227440(Fade *fade) {
    switch (fade->state) {
    case 0:
        break;
    case 1:
        fade->value += 4;
        if (fade->value >= 0x80) {
            fade->value = 0x80;
            fade->state = 0;
        }
        break;
    case 2:
        fade->value -= 4;
        if (0 >= fade->value) {
            fade->value = 0;
            fade->state = 0;
        }
        break;
    }
}

void func_002274C0(Fade *arg0, u8 **arg1, s32 arg2) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 count;
    s32 i;
    s32 offset;
    s32 index;
    u8 *entry;

    count = g_menu_page_item_counts[arg2];
    if (arg0->value == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        index = 0;
        do {
            entry = offset + (D_00685010 + arg2 * 0x380);
            if (*(s32 *)(entry + 0x34) != 0) {
                *(s32 *)(entry + 0x2C) = arg0->value;
                reg_a0 = *(u8 **)((u8 *)arg1 + index);
                glyph_queue_add(*(s32 *)entry, *(s32 *)(entry + 4), *(s32 *)(entry + 0x30), 0, 128, arg0->value, 1);
            }
            i++;
            offset += 0x38;
            index += 4;
        } while (i < count);
    }
}

void func_002275C0(void)
{
    s8 saved;

    saved = D_0028EC18_as_Fade.flag;
    func_00227310(&D_0028EC18_as_Fade);
    D_0028EC18_as_Fade.flag = saved;
    func_00222260(7);
}

void func_002275F0(void) {
    s8 value = D_0028EC18_as_Fade.flag;
    if (func_002273B0(&D_0028EC18_as_Fade, 7) != 0) {
        g_menu_cursor = value;
        if (value == 0) {
            g_menu_cursor++;
        }
    }
}

void func_00227640(void) {
    func_00227310(&D_0028EC18_as_Fade);
    D_0028EC18_as_Fade.flag = 0;
    D_0028EC18_as_Fade.value = 0;
    g_menu_box_alpha = 0;
    g_menu_cursor = 0;
    func_00222340(7);
}

void func_00227680(void) {
    if (func_00227350(&D_0028EC18_as_Fade, 7) != 0) {
        g_menu_cursor = 1;
        D_0028EC18_as_Fade.step = 2;
    }
}

void func_002276C0(void) {
    s32 confirm;
    s32 last;
    u32 buttons;

    confirm = 0;
    last = D_002714F7[0] - 1;
    func_002273E0();
    if ((s8)func_00221120(7) == 0) {
        buttons = g_pad_trigger[g_menu_pad];
        if (buttons & 0x40) {
            g_menu_cursor = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EC18_as_Fade.flag = g_menu_cursor;
    if (confirm != 0) {
        sfx_menu_confirm();
        D_0028EC18_as_Fade.step += 1;
        if (last == D_0028EC18_as_Fade.flag) {
            func_00222260(0);
            g_menu_step = 3;
            g_menu_page = 0;
            g_menu_alpha = 0x40;
            D_0028EB4C = 1;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            D_0028EC18_as_Fade.state = 2;
        } else {
            D_0028EC18_as_Fade.state = 0;
            D_0028EC18_as_Fade.value = 0;
            D_0028EB54 = 0;
            g_menu_box_alpha = 0;
            switch (D_0028EC18_as_Fade.flag) {
            case 1:
                D_0028EC10_as_Fade.flag = 1;
                D_0028EC10_as_Fade.step = 0;
                g_menu_page = 8;
                break;
            case 2:
                D_0028EBE8.step = 0;
                g_menu_page = 10;
                break;
            case 3:
                D_0028EBE0.step = 0;
                g_menu_page = 11;
                break;
            case 4:
                D_0028EBE0.step = 0;
                g_menu_page = 22;
                break;
            }
        }
    }
}

void func_00227830(void) {
    switch (D_0028EC18_as_Fade.step) {
    case 10:
        func_00227640();
        break;
    case 0:
        func_002275C0();
        break;
    case 11:
        func_00227680();
        break;
    case 1:
        func_002275F0();
        break;
    case 2:
        func_002276C0();
        break;
    case 3:
        break;
    }
}

void func_002278D0(void) {
    func_00227440(&D_0028EC18_as_Fade);
    func_002274C0(&D_0028EC18_as_Fade, (u8 **)g_menu_simulation_items, 7);
}

void func_00227900(void) {
    func_00227310(&D_0028EBE8);
    func_00222260(0xA);
    D_0028EC7C = 0;
}

void func_00227930(void) {
    if (func_002365A0() != 0) {
        D_0028EBE8.step += 1;
    }
}

void func_00227960(void) {
    if (func_002273B0(&D_0028EBE8, 0xA) != 0) {
        g_menu_cursor = D_0068DF02[0] + 1;
    }
}

void func_002279A0(void) {
    s32 confirm;
    s32 last;
    u32 buttons;
    s32 selected;

    confirm = 0;
    last = D_002714FA[0] - 1;
    func_002273E0();
    if ((s8)func_00221120(10) == 0) {
        buttons = g_pad_trigger[g_menu_pad];
        if (buttons & 0x40) {
            g_menu_cursor = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EBE8.flag = g_menu_cursor;
    if (confirm != 0) {
        if (last != D_0028EBE8.flag) {
            selected = D_0028EBE8.flag - 1;
            if (D_0028E258 < selected) {
                sfx_menu_denied();
                return;
            }
#ifndef DEATH_LABEL
            D_0028E280 = selected;
            printf("----stage[%d]\n", D_0028E280);
#endif
            sfx_menu_confirm();
            D_0028EBE8.step += 1;
            D_0068DF02[0] = D_0028EBE8.flag - 1;
            func_002272D0();
        } else {
            sfx_menu_confirm();
            D_0028EC18_as_Fade.flag = 2;
            D_0028EBE8.state = 0;
            g_menu_page = 7;
            D_0028EBE8.value = 0;
            D_0028EC18_as_Fade.step = 0;
            D_0068DF02[0] = D_00270822[0];
        }
    }
}

void func_00227AE0(void) {
    switch (D_0028EBE8.step) {
    case 0:
        func_00227900();
        break;
    case 1:
        func_00227930();
        break;
    case 2:
        func_00227960();
        break;
    case 3:
        func_002279A0();
        /* fallthrough */
    case 4:
        break;
    }
}

void func_00227B70(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 count;
    s32 last;
    s32 i;
    s32 offset;
    s32 index;
    s32 alpha;
    u8 *entry;
    s32 x;
    s32 y;
    s32 sprite;
    s16 value;

    count = D_002714FA[0];
    last = count - 1;
    if (D_0028EBE8.step < 3) {
        return;
    }
    func_00227440(&D_0028EBE8);
    if (D_0028EBE8.value == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        index = 0;
        do {
            entry = D_00685010 + offset;
            if (*(s32 *)(entry + 0x2334) != 0) {
                value = D_0028EBE8.value;
                alpha = 128;
                *(s32 *)(entry + 0x232C) = value;
                x = *(s32 *)(entry + 0x2300);
                y = *(s32 *)(entry + 0x2304);
                sprite = *(s32 *)(entry + 0x2330);
                reg_a0 = *(u8 **)((u8 *)g_menu_stage_select_items + index);
                if ((i > 0) && (i < last) && (D_0028E258 < i - 1)) {
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

void func_00227C90(void) {
    func_00227310(&D_0028EBE0);
    func_00222260(0xB);
    D_0028EC20 = 0;
    g_replay_mode_as_s8 = 0;
    replay_slots_open(0, g_menu_pad, 0);
}

void func_00227CD0(void) {
    if (func_002273B0(&D_0028EBE0, 0xB) != 0) {
        D_0028EB54 = 0;
    }
}

void func_00227D00(void) {
    s32 temp_v0;

    func_002273E0();
    temp_v0 = replay_slots_update();
    switch (temp_v0) {
    case 0:
        D_0028EC18_as_Fade.flag = 3;
        D_0028EB54 = 0;
        g_menu_page = 7;
        g_menu_box_alpha = 0;
        D_0028EBE0.state = 0;
        D_0028EBE0.value = 0;
        D_0028EC18_as_Fade.step = 0;
        return;
    case 3:
        g_replay_mode_as_s8 = 2;
        D_0028EC20 = 1;
        D_0028EBE0.step += 1;
        func_002272D0();
        return;
    }
}

void func_00227D90(void) {
    switch (D_0028EBE0.step) {
    case 0:
        func_00227C90();
        break;
    case 1:
        func_00227CD0();
        break;
    case 2:
        func_00227D00();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_00227E00(void) {
    func_00227440(&D_0028EBE0);
    replay_slots_draw();
}

void func_00227E30(void) {
    func_00227310(&D_0028EBE0);
    func_00222260(0xB);
    D_0028EC20 = 0;
    g_replay_mode_as_s8 = 0;
    replay_slots_open(0, g_menu_pad, 1);
}

void func_00227E70(void) {
    s32 temp_v0;

    func_002273E0();
    temp_v0 = replay_slots_update();
    switch (temp_v0) {
    case 0:
        D_0028EC18_as_Fade.flag = 4;
        D_0028EB54 = 0;
        g_menu_page = 7;
        g_menu_box_alpha = 0;
        D_0028EBE0.state = 0;
        D_0028EBE0.value = 0;
        D_0028EC18_as_Fade.step = 0;
        break;
    case 3:
        g_replay_mode_as_s8 = 2;
        D_0028EC20 = 1;
        D_0028EBE0.step += 1;
        func_002272D0();
        break;
    }
}

void func_00227F00(void) {
    switch (D_0028EBE0.step) {
    case 0:
        func_00227E30();
        break;
    case 1:
        func_00227CD0();
        break;
    case 2:
        func_00227E70();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_00227F70(void) {
    switch (D_0028EBE0.step) {
    case 0:
        func_00227C90();
        break;
    case 1:
        func_00227CD0();
        break;
    case 2:
        func_00227FE0();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_00227FE0(void) {
    s32 temp_v0;

    func_002273E0();
    temp_v0 = replay_slots_update();
    switch (temp_v0) {
    case 0:
        D_0028EB54 = 0;
        D_0028EC10_as_Fade.flag = 4;
        g_menu_box_alpha = 0;
        g_menu_page = 8;
        D_0028EBE0.state = 0;
        D_0028EBE0.value = 0;
        D_0028EC10_as_Fade.step = 0;
        break;
    case 3:
        func_00228060();
        replay_slots_close();
        break;
    }
}

void func_00228060(void) {
    memcpy(D_0068DEF0_as_s16_a, D_00270810_as_s16_a, 0x16);
    memcpy(D_0068DED8_as_s16_a, D_00270828, 0xA);
    memcpy(D_0068DEC8_as_s16_a, D_00270838, 0xC);
    D_0068DED8_as_s16_a[0] = D_006C58AA[0];
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
    D_0068DEC8_as_s16_a[0] = D_006C58CE[0];
    D_0068DECA[0] = D_006C58D0[0];
    D_0068DECC[0] = D_006C58D2[0];
    D_0068DECE[0] = D_006C58B0[0];
    D_0068DED0[0] = D_006C58B2[0];
    D_0068DED2[0] = D_006C58D4[0];
    if (D_0068DED8_as_s16_a[0] > 3) {
        D_0068DED8_as_s16_a[0] = 1;
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
    if (D_0068DEC8_as_s16_a[0] > 2) {
        D_0068DEC8_as_s16_a[0] = 0;
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
    memcpy(D_0068DEB0_as_s16_a, D_0068DEF0_as_s16_a, 0x16);
    memcpy(D_0068DE90_as_s16_a, D_0068DED8_as_s16_a, 0xA);
    memcpy(D_0068DEA0_as_s16_a, D_0068DEC8_as_s16_a, 0xC);
}

void func_00228520(void)
{
    s8 saved;

    saved = D_0028EC10_as_Fade.flag;
    func_00227310(&D_0028EC10_as_Fade);
    D_0028EC10_as_Fade.flag = saved;
    func_00222260(8);
}

void func_00228550(void) {
    if (func_002273B0(&D_0028EC10_as_Fade, 8) != 0) {
        g_menu_cursor = D_0028EC10_as_Fade.flag;
    }
}

void func_00228580(void) {
    s32 confirm;
    s32 last;
    u32 buttons;

    confirm = 0;
    last = D_002714F8[0] - 1;
    func_002273E0();
    if ((s8)func_00221120(8) == 0) {
        buttons = g_pad_trigger[g_menu_pad];
        if (buttons & 0x40) {
            g_menu_cursor = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EC10_as_Fade.flag = g_menu_cursor;
    if (confirm != 0) {
        switch (g_menu_cursor) {
        case 1:
            sfx_menu_confirm();
            D_0028EC10_as_Fade.state = 0;
            g_menu_page = 0x11;
            D_0028EC10_as_Fade.value = 0;
            D_0028EB54 = 0;
            g_menu_box_alpha = 0;
            D_0028EC08_as_Fade.step = 0;
            D_0028EC10_as_Fade.step += 1;
            break;
        case 2:
            sfx_menu_confirm();
            D_0028EC10_as_Fade.state = 0;
            g_menu_page = 0x12;
            D_0028EC10_as_Fade.value = 0;
            D_0028EB54 = 0;
            g_menu_box_alpha = 0;
            D_0028EC00_as_Fade.step = 0;
            D_0028EC10_as_Fade.step += 1;
            break;
        case 3:
            sfx_menu_confirm();
            D_0028EC10_as_Fade.state = 0;
            g_menu_page = 0x13;
            D_0028EC10_as_Fade.value = 0;
            D_0028EB54 = 0;
            g_menu_box_alpha = 0;
            D_0028EBF8.step = 0;
            D_0028EC10_as_Fade.step += 1;
            break;
        case 4:
            sfx_menu_confirm();
            D_0028EC10_as_Fade.state = 0;
            g_menu_page = 0x14;
            D_0028EC10_as_Fade.value = 0;
            D_0028EB54 = 0;
            g_menu_box_alpha = 0;
            D_0028EBE0.step = 0;
            D_0028EC10_as_Fade.step += 1;
            break;
        case 5:
            sfx_menu_confirm();
            D_0028EC10_as_Fade.state = 0;
            D_0028EC18_as_Fade.flag = 1;
            D_0028EC10_as_Fade.value = 0;
            g_menu_page = 7;
            D_0028EB54 = 0;
            g_menu_box_alpha = 0;
            D_0028EC18_as_Fade.step = 0;
            D_0028EC10_as_Fade.step += 1;
            break;
        }
    }
}

void func_00228770(void) {
    switch (D_0028EC10_as_Fade.step) {
    case 0:
        func_00228520();
        break;
    case 1:
        func_00228550();
        break;
    case 2:
        func_00228580();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_002287E0(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 count;
    s32 i;
    s32 offset;
    s32 tableOffset;
    u8 *entry;

    count = D_002714F8[0];
    func_00227440(&D_0028EC10_as_Fade);
    if (D_0028EC10_as_Fade.value == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        tableOffset = 0;
        do {
            entry = D_00685010 + offset;
            if (*(s32 *)(entry + 0x1C34) != 0) {
                s32 value = D_0028EC10_as_Fade.value;

                *(s32 *)(entry + 0x1C2C) = value;
                reg_a0 = *(u8 **)((u8 *)g_menu_sim_setting_items + tableOffset);
                glyph_queue_add(*(s32 *)(entry + 0x1C00), *(s32 *)(entry + 0x1C04), *(s32 *)(entry + 0x1C30), 0, 0x80, value, 1);
            }
            i++;
            offset += 0x38;
            tableOffset += 4;
        } while (i < count);
    }
}

void func_002288B0(void) {
    func_00227310(&D_0028EC08_as_Fade);
    func_00222260(0x11);
}

void func_002288E0(void) {
    if (func_002273B0(&D_0028EC08_as_Fade, 0x11) != 0) {
        g_menu_cursor = 1;
    }
}

void func_00228910(void) {
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
    func_002273E0();
    skip = (s8)func_00221120(17);
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
    D_0028EC08_as_Fade.flag = g_menu_cursor;
    if (confirm != 0) {
        switch (g_menu_cursor) {
        case 6:
            sfx_menu_confirm();
            memcpy(D_0068DED8_as_s16_a, D_00270828, 10);
            break;
        case 7:
            sfx_menu_confirm();
            D_0028EC08_as_Fade.state = 0;
            D_0028EC10_as_Fade.flag = 1;
            D_0028EC08_as_Fade.value = 0;
            g_menu_page = 8;
            D_0028EB54 = 0;
            g_menu_box_alpha = 0;
            D_0028EC10_as_Fade.step = 0;
            D_0028EC08_as_Fade.step += 1;
            break;
        }
    } else if (dir != 0) {
        item = g_menu_sim_player_value_tables[g_menu_cursor];
        if (!(0 > item)) {
            value = &D_0068DED8_as_s16_a[item];
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

void func_00228B50(void) {
    switch (D_0028EC08_as_Fade.step) {
    case 0:
        func_002288B0();
        break;
    case 1:
        func_002288E0();
        break;
    case 2:
        func_00228910();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_00228BC0(void) {
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
    u8 *item;

    count = D_00271501[0];
    func_00227440(&D_0028EC08_as_Fade);
    if (D_0028EC08_as_Fade.value == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3BB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x3BAC) = alpha = D_0028EC08_as_Fade.value;
        x = *(s32 *)(item + 0x3B80);
        y = *(s32 *)(item + 0x3B84);
        z = *(s32 *)(item + 0x3BB0);
        reg_a0 = (u8 *)g_menu_sim_player_items[i];
        glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        y += strlen((const char *)reg_a0) * 8;
        reg_a0 = 0;
        index = g_menu_sim_player_value_tables[i];
        if (index == -1) {
            continue;
        }
        entries = (u8 **)g_menu_sim_player_values[index];
        value = D_0068DED8_as_s16_a[index];
        reg_a0 = entries[value];
        if (reg_a0 == 0) {
            continue;
        }
        if (index == 4) {
            dbl = value * 2;
            reg_a0 = entries[dbl];
            if (dbl == 6) {
                glyph_queue_add(x, y, z, 0, 0x80, D_0028EC08_as_Fade.value, 1);
            } else {
                glyph_queue_add(x, y, z, 0, 0x80, D_0028EC08_as_Fade.value, 0);
                reg_a0 = (u8 *)g_menu_sim_player_values[index][dbl + 1];
                glyph_queue_add(x - 8, y, z, 0, 0x80, D_0028EC08_as_Fade.value, 0);
            }
        } else {
            glyph_queue_add(x, y, z, 0, 0x80, D_0028EC08_as_Fade.value, 1);
        }
        if (i == D_0028EC08_as_Fade.flag) {
            func_00224BA0(x, y, z, 0, 0x80, D_0028EC08_as_Fade.value, 1, 3);
        }
    }
}

void func_00228E20(void) {
    func_00227310(&D_0028EC00_as_Fade);
    func_00222260(0x12);
}

void func_00228E50(void) {
    if (func_002273B0(&D_0028EC00_as_Fade, 0x12) != 0) {
        g_menu_cursor = 1;
    }
}

void func_00228E80(void) {
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
    func_002273E0();
    moved = (s8)func_00221120(0x12);
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
    D_0028EC00_as_Fade.flag = sel;
    if (confirm != 0) {
        switch (sel) {
        case 3:
            sfx_menu_confirm();
            D_0068DEF0_as_s16_a[10] += 1;
            D_0068DEF0_as_s16_a[10] &= 1;
            break;
        case 10:
            sfx_menu_confirm();
            memcpy(D_0068DEF0_as_s16_a, D_00270810_as_s16_a, 0x16);
            break;
        case 11:
            sfx_menu_confirm();
            D_0028EC00_as_Fade.state = 0;
            D_0028EC10_as_Fade.flag = 2;
            D_0028EC00_as_Fade.value = 0;
            g_menu_page = 8;
            D_0028EB54 = 0;
            g_menu_box_alpha = 0;
            D_0028EC10_as_Fade.step = 0;
            D_0028EC00_as_Fade.step++;
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

void func_002295F0(void) {
    switch (D_0028EC00_as_Fade.step) {
    case 0:
        func_00228E20();
        break;
    case 1:
        func_00228E50();
        break;
    case 2:
        func_00228E80();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_00229660(void) {
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
    u8 *item;

    count = D_00271502[0];
    func_00227440(&D_0028EC00_as_Fade);
    if (D_0028EC00_as_Fade.value == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3F34) == 0) {
            continue;
        }
        *(s32 *)(item + 0x3F2C) = alpha = D_0028EC00_as_Fade.value;
        x = *(s32 *)(item + 0x3F00);
        y = *(s32 *)(item + 0x3F04);
        z = *(s32 *)(item + 0x3F30);
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
                func_00229950(x, y, D_0028EC00_as_Fade.value, bright, 2);
            } else {
                glyph_queue_add(x, y, z, 0, bright, D_0028EC00_as_Fade.value, flag);
                flag = 0;
            }
        } else if (i == 9) {
            func_00229950(x, y, D_0028EC00_as_Fade.value, bright, 8);
        } else if (i == 7) {
            func_00229950(x, y, D_0028EC00_as_Fade.value, bright, 6);
        } else {
            glyph_queue_add(x, y, z, 0, bright, D_0028EC00_as_Fade.value, flag);
        }
        if (i == D_0028EC00_as_Fade.flag && flag != 0) {
            func_00224BA0(x, y, z, 0, bright, D_0028EC00_as_Fade.value, 1, 3);
        }
    }
}

void func_00229950(s32 x, s32 y, s32 alpha, s32 mode, s32 kind) {
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

void func_00229DC0(void) {
    func_00227310(&D_0028EBF8);
    func_00222260(0x13);
}

void func_00229DF0(void) {
    if (func_002273B0(&D_0028EBF8, 0x13) != 0) {
        g_menu_cursor = 1;
    }
}

void func_00229E20(void) {
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
    func_002273E0();
    skip = (s8)func_00221120(19);
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
    D_0028EBF8.flag = g_menu_cursor;
    if (confirm != 0) {
        switch (g_menu_cursor) {
        case 7:
            sfx_menu_confirm();
            memcpy(D_0068DEC8_as_s16_a, D_00270838, 12);
            break;
        case 8:
            sfx_menu_confirm();
            D_0028EBF8.state = 0;
            D_0028EC10_as_Fade.flag = 3;
            D_0028EBF8.value = 0;
            g_menu_page = 8;
            D_0028EB54 = 0;
            g_menu_box_alpha = 0;
            D_0028EC10_as_Fade.step = 0;
            D_0028EBF8.step += 1;
            break;
        }
    } else if (dir != 0) {
        item = g_menu_sim_param_value_tables[g_menu_cursor];
        if (!(0 > item)) {
            value = &D_0068DEC8_as_s16_a[item];
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

void func_0022A040(void) {
    switch (D_0028EBF8.step) {
    case 0:
        func_00229DC0();
        break;
    case 1:
        func_00229DF0();
        break;
    case 2:
        func_00229E20();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_0022A0B0(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 x;
    s32 y;
    s32 z;
    s32 i;
    s32 count;
    s8 index;
    s32 alpha;
    u8 *item;

    count = D_00271503[0];
    func_00227440(&D_0028EBF8);
    if (D_0028EBF8.value == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x42B4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x42AC) = alpha = D_0028EBF8.value;
        y = *(s32 *)(item + 0x4284);
        z = *(s32 *)(item + 0x42B0);
        x = *(s32 *)(item + 0x4280);
        reg_a0 = (u8 *)g_menu_sim_param_items[i];
        glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        y += strlen((const char *)reg_a0) * 8;
        reg_a0 = 0;
        index = g_menu_sim_param_value_tables[i];
        if (index == -1) {
            continue;
        }
        reg_a0 = (u8 *)g_menu_sim_param_values[index][D_0068DEC8_as_s16_a[index]];
        if (reg_a0 == 0) {
            continue;
        }
        glyph_queue_add(x, y, z, 0, 0x80, D_0028EBF8.value, 1);
        if (i == D_0028EBF8.flag) {
            func_00224BA0(x, y, z, 0, 0x80, D_0028EBF8.value, 1, 3);
        }
    }
}

void func_0022A260(void) {
    func_00227310(&D_0028EBD8_as_Fade);
    func_00222340(0xD);
    D_0028EBD8_as_Fade.flag = 0;
    g_menu_cursor = 1;
    D_0028EB54 = 0;
    g_menu_alpha = 0x40;
    D_0028EB04 = 2;
}

void func_0022A2B0(void) {
    if (func_00222530(0xD) != 0) {
        D_0028EBD8_as_Fade.step += 1;
    }
}

void func_0022A2E0(void) {
    s32 temp_a0;
    s32 var_a1;
    s32 var_s0;

    var_s0 = 0;
    func_002273E0();
    temp_a0 = g_pad_repeat[g_menu_pad];
    var_a1 = 0;
    if (temp_a0 & 0x8000) {
        sfx_menu_tick();
        D_0028EBD8_as_Fade.flag -= 1;
        if (D_0028EBD8_as_Fade.flag < 0) {
            D_0028EBD8_as_Fade.flag = 9;
        }
        var_a1 = 1;
    } else if (temp_a0 & 0x2000) {
        sfx_menu_tick();
        D_0028EBD8_as_Fade.flag += 1;
        if (D_0028EBD8_as_Fade.flag > 9) {
            D_0028EBD8_as_Fade.flag = 0;
        }
        var_a1 = 1;
    }
    if ((var_a1 == 0) && (g_pad_trigger[g_menu_pad] & 0x40)) {
        var_s0 = 1;
    }
    if (var_s0 != 0) {
        sfx_menu_confirm();
        D_0028EBD8_as_Fade.state = 0;
        D_0028EB04 = 1;
        D_0028EBD8_as_Fade.value = 0;
        D_0028EC18_as_Fade.flag = 4;
        D_0028EB54 = 0;
        g_menu_page = 7;
        g_menu_box_alpha = 0;
        g_menu_alpha = 0;
        D_0028EC18_as_Fade.step = 0;
        D_0028EBD8_as_Fade.step += 1;
    }
}

void func_0022A410(void) {
    switch (D_0028EBD8_as_Fade.step) {
    case 0:
        func_0022A260();
        break;
    case 1:
        func_0022A2B0();
        break;
    case 2:
        func_0022A2E0();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_0022A480(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    extern void text_queue_clear(void);
    extern void text_flush(void);
    s32 i;
    s32 x;
    s32 y;
    s32 z;
    s32 alpha;
    s32 count;
    u8 *item;

    func_00227440(&D_0028EBD8_as_Fade);
    if (D_0028EBD8_as_Fade.value == 0) {
        return;
    }
    count = D_002714FD[0];
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8_as_Fade.value;
        reg_a0 = (u8 *)g_menu_practice_ranking_text[i];
        x = *(s32 *)(item + 0x2D80);
        alpha = *(s32 *)(item + 0x2DAC);
        y = *(s32 *)(item + 0x2D84);
        z = *(s32 *)(item + 0x2DB0);
        if (alpha == 0) {
            continue;
        }
        if (i == 1) {
            func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
        }
        glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        if (i == 1) {
            reg_a0 = (u8 *)g_menu_round_names[D_0028EBD8_as_Fade.flag];
            glyph_queue_add(x, y + 0x70, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBD8_as_Fade.flag, 0);
    for (i = 3; i < 8; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8_as_Fade.value;
        reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
        y = *(s32 *)(item + 0x2D84) + 16;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBD8_as_Fade.flag, 1);
    for (i = 3; i < 8; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8_as_Fade.value;
        reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
        y = *(s32 *)(item + 0x2D84) + 0x80;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBD8_as_Fade.flag, 2);
    for (i = 9; i < 14; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8_as_Fade.value;
        reg_a0 = (u8 *)D_00684CA0 + (i - 9) * 11;
        y = *(s32 *)(item + 0x2D84) + 16;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBD8_as_Fade.flag, 3);
    for (i = 9; i < 14; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8_as_Fade.value;
        reg_a0 = (u8 *)D_00684CA0 + (i - 9) * 11;
        y = *(s32 *)(item + 0x2D84) + 0x80;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    g_menu_alpha = D_0028EBD8_as_Fade.value;
    reg_a0 = (u8 *)g_menu_cancel_text;
    func_002228D0(D_006880A0[0] - 10, D_006880A4[0] + 0x58);
    text_flush();
}

extern s8 D_0028EB64;

void func_0022A870(void) {
    switch (D_0028EB64) {                           /* irregular */
    case 0:
        func_0022A8F0(D_0028EB64);
        break;
    case 1:
        func_0022A930(D_0028EB64);
        break;
    case 2:
        func_0022A9A0(D_0028EB64);
        break;
    case 3:
        func_0022AA00(D_0028EB64);
        break;
    }
}

extern s8 D_0028EB10;
extern s8 D_0028EB34;
extern s32 D_0028EB9C;

void func_0022A8F0() {
    D_0028EB9C = 0;
    D_0028EB64 += 1;
    func_00222340(0xC);
    D_0028EB10 = 0;
    D_0028EB34 = 1;
}

extern s8 D_0028EADC;

void func_0022A930() {
    if (func_00222530(0xC) != 0) {
        D_0028EB64 += 1;
        if ((0 <= D_0028EADC) && (D_0028EADC < 5)) {
            g_menu_cursor = D_0028EADC + 3;
            D_0028EB54 = 1;
        } else {
            g_menu_cursor = -1;
            D_0028EB54 = 1;
        }
    }
}

void func_0022A9A0()
{
    extern void sfx_menu_confirm(void);
    if (g_pad_trigger[g_menu_pad] & 0x60) {
        sfx_menu_confirm();
        D_0028EB54 = 2;
        D_0028EB34 = 2;
        D_0028EB64 = D_0028EB64 + 1;
    }
}

extern s8 D_0028EACC;

void func_0022AA00() {
    if (D_0028EB34 == 0) {
        D_0028EACC = 0x51;
    }
}

extern s8 D_002714FC[];
extern u8 D_00684CD7[];
extern u16 D_006C58AC[];
extern u16 D_006C58AE[];

void func_0022AA20(void) {
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
    u8 *item;

    save = reg_a0;
    count = D_002714FC[0];
    switch (D_0028EB34) {
    case 0:
        break;
    case 1:
        D_0028EB9C += 4;
        if (D_0028EB9C >= 0x80) {
            D_0028EB34 = 0;
            D_0028EB9C = 0x80;
        }
        break;
    case 2:
        D_0028EB9C -= 4;
        if (D_0028EB9C <= 0) {
            D_0028EB9C = 0;
            D_0028EB34 = 0;
        }
        break;
    }
    page = D_006C58AE[0] + D_006C58AC[0] * 5;
    sel = D_006C58AA[0];
    func_0022AD20(page, sel);
    func_0022B1D0();
    glyph_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2A34) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2A2C) = D_0028EB9C;
        reg_a0 = (u8 *)g_menu_ranking_page_text[i];
        alpha = *(s32 *)(item + 0x2A2C);
        x = *(s32 *)(item + 0x2A00);
        y = *(s32 *)(item + 0x2A04);
        z = *(s32 *)(item + 0x2A30);
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
    g_menu_alpha = D_0028EB9C;
    reg_a0 = (u8 *)g_menu_confirm_cancel_text;
    func_002228D0(x - 10, 0x40);
    text_flush();
    reg_a0 = save;
}

extern s32 D_0028EAD8;
extern char D_00684CA0_as_char_a6_a11[6][11];
extern s32 D_00684CF0_as_s32_a_a4_a5[][4][5];

void func_0022AD20(s32 arg0, s32 arg1) {
    s32 i;
    s32 j;
    s32 v;
    s32 lead;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 11; j++) {
            D_00684CA0_as_char_a6_a11[i][j] = ' ';
        }
        D_00684CA0_as_char_a6_a11[i][10] = 0;
    }
    for (i = 0; i < 6; i++) {
        if (i == 5) {
            v = D_0028EAD8;
        } else {
            v = D_00684CF0_as_s32_a_a4_a5[arg0][arg1][i];
        }
        lead = 0;
        if (v >= 100000000) {
            D_00684CA0_as_char_a6_a11[i][0] = v / 100000000 + '0';
            v %= 100000000;
            lead = 1;
        }
        if (v >= 10000000) {
            D_00684CA0_as_char_a6_a11[i][1] = v / 10000000 + '0';
            v %= 10000000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][1] = '0';
        }
        if (v >= 1000000) {
            D_00684CA0_as_char_a6_a11[i][2] = v / 1000000 + '0';
            v %= 1000000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][2] = '0';
        }
        if (v >= 100000) {
            D_00684CA0_as_char_a6_a11[i][3] = v / 100000 + '0';
            v %= 100000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][3] = '0';
        }
        if (v >= 10000) {
            D_00684CA0_as_char_a6_a11[i][4] = v / 10000 + '0';
            v %= 10000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][4] = '0';
        }
        if (v >= 1000) {
            D_00684CA0_as_char_a6_a11[i][5] = v / 1000 + '0';
            v %= 1000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][5] = '0';
        }
        if (v >= 100) {
            D_00684CA0_as_char_a6_a11[i][6] = v / 100 + '0';
            v %= 100;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][6] = '0';
        }
        if (v >= 10) {
            D_00684CA0_as_char_a6_a11[i][7] = v / 10 + '0';
            v %= 10;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][7] = '0';
        }
        if (v > 0) {
            D_00684CA0_as_char_a6_a11[i][8] = v + '0';
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][8] = '0';
        }
        D_00684CA0_as_char_a6_a11[i][9] = '0';
    }
}

extern s16 D_00271784[];

void func_0022B1D0(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s32 x;

    switch (D_0028EB54) {
    case 0:
        break;
    case 1:
        g_menu_box_alpha += 4;
        if (g_menu_box_alpha >= 0x40) {
            D_0028EB54 = 0;
            g_menu_box_alpha = 0x40;
        }
        break;
    case 2:
        g_menu_box_alpha -= 4;
        if (g_menu_box_alpha <= 0) {
            g_menu_box_alpha = 0;
            D_0028EB54 = 0;
        }
        break;
    }
    if (g_menu_cursor != -1) {
        x = g_menu_item_positions_a[g_menu_cursor * 2];
        if (g_menu_box_alpha != 0) {
            gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, g_menu_box_alpha, 0xB4, 1, 1);
        }
    }
    if (g_menu_box_alpha != 0) {
        gfx_draw_color_box(D_00271784[0] - 8, 0, 0x12, 0xE0, 0x5A, g_menu_box_alpha, 0xB4, 1, 1);
    }
}


void func_0022B2F0(void) {
    if (g_replay_slots_from_disc == 0) {
        func_0022B4B0();
        return;
    }
    func_0022B540();
}

extern u8 D_0028ED30_as_u8_a8[8];
extern u16 D_0028ED40;
extern s32 D_0028ED44;
extern u16 D_0028ED48;
extern u16 D_0028ED4C;
extern s32 D_0028ED50;
extern u16 D_0028ED54;
extern u8 g_replay_watch_after_run;
extern u8 D_006A4C00[];


void func_0022B330(void) {
    extern void replay_file_pointers_decode(void *data);
    s32 count;
    s32 i;
    SaveBody *data;

    count = 0;
    for (i = 0; i < 6; i++) {
        if (D_0028ED30_as_u8_a8[i] == g_replay_file_loaded[0x38 + i]) {
            count++;
        }
    }
    if (count == 6) {
        data = (SaveBody *)D_006A4C00;
        delta_encode((u8 *)data);
        replay_file_pointers_decode(g_replay_file_loaded);
        printf("sco1up  [%x] -> [%x]\n", D_0028ED50, data->score1);
        printf("sco1cnt [%x] -> [%x]\n", D_0028ED54, data->count1);
        printf("sco1oku [%x] -> [%x]\n", D_0028ED4C, data->stage1);
        printf("sco2up  [%x] -> [%x]\n", D_0028ED44, data->score2);
        printf("sco2cnt [%x] -> [%x]\n", D_0028ED48, data->count2);
        printf("sco2oku [%x] -> [%x]\n", D_0028ED40, data->stage2);
        if (D_0028ED54 == data->count1 && D_0028ED50 == data->score1 &&
            D_0028ED4C == data->stage1 && D_0028ED48 == data->count2 &&
            D_0028ED44 == data->score2 && D_0028ED40 == data->stage2) {
            memcpy(g_replay_file, g_replay_file_loaded, 0x202E8);
            g_replay_watch_after_run = 1;
        }
    }
}

s32 func_0022C780();
extern u8 D_0028E378;
extern u8 D_0028EC4C;
extern s32 D_0028EC50;
extern s32 D_0028ECC4;
extern s32 D_0028ED0C;

s32 func_0022B4B0(void) {
    switch (D_0028EC50) {                           /* irregular */
    case 0:
        D_0028EC4C = 1;
        D_0028ED0C = 0;
        D_0028EC50 += 1;
        g_replay_watch_after_run = 0;
        D_0028E378 = 0xFF;
        /* fallthrough */
    case 1:
        func_0022C780();
        if (D_0028ED0C != 0) {
            D_0028ED0C = 0;
            D_0028EC50 = 0;
            D_0028EC4C = 0;
            if (D_0028ECC4 != 0) {
                func_0022B330();
            }
            return 1;
        }
    default:
        return 0;
    }
}

u8 func_00231840();
extern u8 D_0028EAB8;

s32 func_0022B540(void) {
    switch (D_0028EC50) {
    case 0:
        D_0028EC4C = 1;
        g_replay_watch_after_run = 0;
        D_0028EC50 += 1;
        D_0028E378 = 0xFF;
        /* fallthrough */
    case 1:
        D_0028EAB8 = func_00231840();
        if (D_0028EAB8 == 0xFF) {
            D_0028EC50 = 3;
        } else {
            D_0028EAB8 -= 1;
            D_0028EC50 += 1;
        }
        break;
    case 2:
        if (replay_disc_file_load(D_0028EAB8) != 0) {
            D_0028EC50 += 1;
            func_0022B330();
        }
        break;
    case 3:
        D_0028EC50 = 0;
        D_0028EC4C = 0;
        return 1;
    }
    return 0;
}

extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_p2_score_billions;
extern u16 g_p1_score_billions;
extern s32 g_p2_score_as_s32;
extern s32 g_p1_score_as_s32;

void func_0022B620(void) {
    D_0028ED54 = g_p1_score_digits;
    D_0028ED50 = g_p1_score_as_s32;
    D_0028ED4C = g_p1_score_billions;
    D_0028ED48 = g_p2_score_digits;
    D_0028ED44 = g_p2_score_as_s32;
    D_0028ED40 = g_p2_score_billions;
}

extern void replay_file_pointers_encode(void *data);
extern u8 D_0028E2B8[8];
extern u8 D_0028E368;
extern s32 D_0028EB8C;

s32 func_0022B660(void) {
    u8 *save = g_replay_file;
    s32 state;

    switch (state = D_0028EC50) {
    default:
        D_0028EC50 = state + 1;
        break;
    case 0:
        save[0x38] = D_0028E2B8[0];
        save[0x39] = D_0028E2B8[1];
        save[0x3A] = D_0028E2B8[2];
        save[0x3B] = D_0028E2B8[3];
        save[0x3C] = D_0028E2B8[4];
        save[0x3D] = D_0028E2B8[5];
        save[0x3E] = D_0028E2B8[6];
        save[0x3F] = D_0028E2B8[7];
        D_0028E378 = 0xFF;
        D_0028EC4C = 1;
        D_0028E368 = 0;
        memcpy(g_replay_file_loaded, save, 0x202E8);
        replay_file_pointers_encode(g_replay_file_loaded);
        func_0022B7A0((s32)D_006A4C00);
        replay_slots_reset();
        replay_slots_open(1, 2, 0);
        g_menu_alpha = 0;
        D_0028EB04 = 1;
        D_0028EB8C = 0;
        D_0028EC50++;
        break;
    case 1:
        if (replay_slots_update() == 0) {
            D_0028EC50++;
            D_0028EB04 = 2;
        }
        break;
    case 0x11:
        D_0028EC50 = 0;
        D_0028E368 = 1;
        D_0028EC4C = 0;
        return 1;
    }
    return 0;
}

void func_0022B7A0(s32 arg0) {
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

void func_0022B870(void) {
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

    if (D_0028EC50 != 0) {
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
        switch (D_0028EB04) {
        case 0:
            break;
        case 1:
            g_menu_alpha += 8;
            if (g_menu_alpha >= 0x80) {
                D_0028EB04 = 0;
                g_menu_alpha = 0x80;
            }
            break;
        case 2:
            g_menu_alpha -= 8;
            if (g_menu_alpha <= 0) {
                g_menu_alpha = 0;
                D_0028EB04 = 0;
            }
            break;
        }
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, g_menu_alpha / 2, 1, 1, 1);
        if (g_replay_mode == 1) {
            func_0022BA60();
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

extern s32 g_menu_save_file_help_as_s32;

void func_0022BA60(void) {
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
        if ((g_replay_slots_state_as_u8 != 0) && ((u32) (g_replay_slots_state_as_u8 - 1) > 1U) && ((u32) (g_replay_slots_state_as_u8 - 5) > 1U)) {
            reg_a0 = (u8 *)g_menu_save_file_help_as_s32;
            func_002228D0(0x36, 8);
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

s32 func_0022BB80(u8 *out)
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


extern Row g_replay_file_headers_as_Row_a[];
extern s16 g_replay_slot_infos_as_s16_a_a512[][512];

s32 replay_disc_headers_load(void) {
    s32 i;

    func_00236900();
    for (i = 0; i < 10; i++) {
        *(Row *)g_replay_slot_infos_as_s16_a_a512[i] = g_replay_file_headers_as_Row_a[i];
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


void func_0022BF60(void) {
    u8 temp_a0;

    temp_a0 = *(u8 *)(reg_a5 + 3);
    switch (temp_a0) {                              /* irregular */
    case 0:
        func_0022BFD0(temp_a0);
        break;
    case 1:
        func_0022C1F0(temp_a0);
        break;
    case 2:
        task_stop_self_entry(temp_a0);
        break;
    }
}

extern void text_layer_clear(void);
extern void func_00171910(void);
extern void text_palette_load(void);
extern void task_start(void);
extern u8 g_default_text_palette[];
extern u8 D_0028DE40[];
extern u8 D_0028DE44[];
extern u8 g_game_mode;
extern u8 g_game_frame_ran;
extern u8 D_0028E3F8_as_u8;
extern u8 D_0028E7B4;
extern u16 D_00684C80[];
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
extern u8 death_D_00290DBC;
extern u8 death_D_0029085C;
extern u8 death_D_00290850;
extern u32 death_D_00290DB8;
extern u32 death_D_00290DB4;
extern u16 g_p1_max_hits;
extern u16 g_p2_max_hits;
extern u16 g_loop;
#endif

void func_0022BFD0() {
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
    death_D_0029085C = 0;
    death_D_00290850 = 0;
    death_D_00290DBC = 0;
    g_game_frame_ran = 0;
    D_0028E3F8_as_u8 = 0;
    D_0028E368 = 0;
    if (death_D_00290DC0 != 0) {
        func_0022B620();
        reg_d0.h[0] = 10;
        death_D_00290DB8 = g_p1_max_hits;
        death_D_00290DB4 = g_p2_max_hits;
        task_start();
        *(u16 *)(reg_a0 + 4) = D_00684C80[6];
    }
    func_00171910();
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
    D_0028E3F8_as_u8 = 0;
    D_00684C80[5] = 1;
    D_00684C80[8] = 3;
    reg_d0.h[0] = 10;
    D_00684C80[7] = 0;
    D_0028E368 = 0;
    D_00684C80[10] = 0;
    task_start();
    *(u16 *)(reg_a0 + 4) = D_00684C80[6];
    func_00171910();
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
s32 func_00135110();
s32 func_001719A0();
s32 func_001719B0();
s32 func_001719D0();
s32 music_play_bgm2();
extern u8 g_pad_input_locked;
extern u8 D_0028E2C4;
extern u8 g_simulation_boss_start;
extern u8 D_0028E2D4;
extern u8 D_0028E2E4;
extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u8 g_setting_difficulty;
extern u16 g_score_panel_intro;
extern u16 g_loop;
extern u8 D_00684C88[];
extern u16 D_00684C8A[];
extern u16 D_00684C8C[];
extern u8 D_00684C8E[];
extern u8 D_00684C90[];
extern u16 D_00684C94[];
#ifdef DEATH_LABEL
s32 fade_reset();
extern u8 death_D_00290DC0;
extern u8 death_D_00290DBC;
extern u16 death_D_00290DB8_as_u16;
extern u16 death_D_00290DB4_as_u16;
extern u16 g_p1_max_hits;
extern u16 g_p2_max_hits;
#endif

void func_0022C1F0() {
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
    func_001719D0();
    switch (D_00684C94[0]) {                           /* irregular */
    default:
        D_00684C94[0] += 1;
        break;
    case 0:
        func_001719A0();
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
        D_0028E2E4 = 0;
        D_0028E2D4 = 0xFF;
        D_0028E2C4 = 0;
        g_setting_difficulty = D_00684C88[0];
        g_setting_extend = D_00684C90[0];
        g_setting_ship_stock = D_00684C8E[0];
        func_0022C450(D_00684C88[0]);
        g_pad_input_locked = 1;
#ifdef DEATH_LABEL
        if (death_D_00290DC0 != 0) {
            death_D_00290DBC = 1;
            g_p1_max_hits = death_D_00290DB8_as_u16;
            g_p2_max_hits = death_D_00290DB4_as_u16;
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
            func_00135110();
#ifdef DEATH_LABEL
            fade_reset();
#endif
            if (D_00684C8C[0] == 0) {
                music_play_bgm2();
            }
        }
        break;
    case MAIN_OR_DEATH_LABEL(19, 20):
        func_001719B0();
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

void func_0022C450() {
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
s8 death_D_00628F00[272];
#endif
#ifdef DEATH_LABEL
u8 D_0068DD10[112];
#else
u8 D_0068DD10[384];
#endif
s8 D_0068DD00[16];
s8 D_0068DCF0[16];
s8 D_0068DC40[176];
s8 D_0068DC30[16];
s8 D_0068DC20[16];
s8 D_0068DC10[16];
s32 D_006880A0[5852];
u8 D_00685010[12432];
s32 D_00684CF0[10][4][5];
u8 D_00684CA0[80];
u8 D_00684C90[16];
u16 D_00684C80[8];
