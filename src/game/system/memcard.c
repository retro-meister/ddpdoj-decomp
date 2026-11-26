#include "common.h"
#ifdef DDPDOJ_PC
#include "pc_replay_storage.h"
#endif
#include "sdk/ps2sdk.h"
#include "pad.h"
#ifdef DDPDOJ_PC
#include <stddef.h>

/* The native linker does not join the original 16-byte prefix and its
 * following storage into a memory-card directory table. */
static _Alignas(64) union {
    u8 bytes[99 * 64];
    struct {
        u8 timestamps[16];
        s32 size;
    } first;
} card_directory;
#define g_mc_dir card_directory.bytes
#define D_0069F590 (&card_directory.first.size)
#endif

/*
 * The unit's tables, in the order of the source: the order in which the text they mention lies in
 * `.rodata`.  Tables of up to eight bytes are in `.sdata`, the others in `.data`.  In the messages
 * "／" ends a line and "￥" the message.
 */
char g_mc_icon_cd_path_a[20] = "\\DATA\\DDON3_1.ICO;1";

char g_mc_icon_cd_path_b[20] = "\\DATA\\DDON3_2.ICO;1";

s32 g_mc_needed_kilobytes[22] = {
    0x28, 0x28, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA,
    0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA,
    0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA,
};

char *g_mc_msg_busy_game[5] = {
    SJIS("ゲームデータを／セーブしています＠"),
    SJIS("ゲームデータを／ロードしています＠"),
    SJIS("ゲームデータを／ロードしています＠"),
    SJIS("フォーマットをしていま／す＠"),
    SJIS("アンフォーマットしてい／ます＠"),
};

char *g_mc_msg_busy_replay[5] = {
    SJIS("リプレイデータを／セーブしています＠"),
    SJIS("リプレイデータを／ロードしています＠"),
    SJIS("リプレイデータを／ロードしています＠"),
    SJIS("フォーマットをしていま／す＠"),
    SJIS("アンフォーマットしてい／ます＠"),
};

char *g_mc_msg_do_not_remove = SJIS("メモリーカード（PS2）を／抜いたり、／電源を切ったり、／リセットしないで下さい。￥");

char *g_mc_msg_slot_name[2] = {
    SJIS("　MEMORY CARD差込口1　￥"),
    SJIS("　MEMORY CARD差込口2　￥"),
};

char *g_mc_msg_no_card[2] = {
    SJIS("メモリーカード（PS2）が／MEMORY CARD差込口1に／差されていません。￥"),
    SJIS("メモリーカード（PS2）が／MEMORY CARD差込口2に／差されていません。￥"),
};

char *g_mc_msg_checking = SJIS("メモリーカード（PS2）を／チェックしています。￥");

char *g_mc_msg_damaged[11] = {
    SJIS("現在保存されている／「ゲームデータ」は／破損しています。／“PlayStation 2”本体／ブラウザ画面にて／削除して下さい。￥"),
    SJIS("現在保存されている／「リプレイデータ」は／破損しています。／“PlayStation 2”本体／ブラウザ画面にて／削除して下さい。￥"),
    SJIS("現在保存されている／「リプレイデータ」は／破損しています。／“PlayStation 2”本体／ブラウザ画面にて／削除して下さい。￥"),
    SJIS("現在保存されている／「リプレイデータ」は／破損しています。／“PlayStation 2”本体／ブラウザ画面にて／削除して下さい。￥"),
    SJIS("現在保存されている／「リプレイデータ」は／破損しています。／“PlayStation 2”本体／ブラウザ画面にて／削除して下さい。￥"),
    SJIS("現在保存されている／「リプレイデータ」は／破損しています。／“PlayStation 2”本体／ブラウザ画面にて／削除して下さい。￥"),
    SJIS("現在保存されている／「リプレイデータ」は／破損しています。／“PlayStation 2”本体／ブラウザ画面にて／削除して下さい。￥"),
    SJIS("現在保存されている／「リプレイデータ」は／破損しています。／“PlayStation 2”本体／ブラウザ画面にて／削除して下さい。￥"),
    SJIS("現在保存されている／「リプレイデータ」は／破損しています。／“PlayStation 2”本体／ブラウザ画面にて／削除して下さい。￥"),
    SJIS("現在保存されている／「リプレイデータ」は／破損しています。／“PlayStation 2”本体／ブラウザ画面にて／削除して下さい。￥"),
    SJIS("現在保存されている／「リプレイデータ」は／破損しています。／“PlayStation 2”本体／ブラウザ画面にて／削除して下さい。￥"),
};

char *g_mc_msg_delete_to_save = SJIS("削除しないと／セーブできません。￥");

char *g_mc_msg_confirm_button = SJIS("　　　　　　　　確認○￥");

char *g_mc_msg_title[8] = {
    SJIS("　　　　セーブ　　　　￥"),
    SJIS("　　　　ロード　　　　￥"),
    SJIS(" 　アンフォーマット　 ￥"),
    SJIS("￥"),
    SJIS(" 　　オートロード　　 ￥"),
    SJIS("￥"),
    SJIS("￥"),
    SJIS("￥"),
};

char *g_mc_msg_title_auto[9] = {
    SJIS(" 　　オートセーブ　　 ￥"),
    SJIS("　　　　ロード　　　　￥"),
    SJIS("￥"),
    SJIS("￥"),
    SJIS(" 　　オートロード　　 ￥"),
    SJIS("￥"),
    SJIS("￥"),
    SJIS("￥"),
    SJIS("￥"),
};

char *g_mc_msg_on_card[2] = {
    SJIS("MEMORY CARD差込口1の／メモリーカード（PS2）に￥"),
    SJIS("MEMORY CARD差込口2の／メモリーカード（PS2）に￥"),
};

char *g_mc_msg_no_data[12] = {
    SJIS("ゲームデータが／存在しません。￥"),
    SJIS("リプレイデータが／存在しません。￥"),
    SJIS("リプレイデータが／存在しません。￥"),
    SJIS("リプレイデータが／存在しません。￥"),
    SJIS("リプレイデータが／存在しません。￥"),
    SJIS("リプレイデータが／存在しません。￥"),
    SJIS("リプレイデータが／存在しません。￥"),
    SJIS("リプレイデータが／存在しません。￥"),
    SJIS("リプレイデータが／存在しません。￥"),
    SJIS("リプレイデータが／存在しません。￥"),
    SJIS("リプレイデータが／存在しません。￥"),
    SJIS("ゲームデータが／存在しません。￥"),
};

char *g_mc_msg_unformat_ask = SJIS("アンフォーマットします／か？￥");

char *g_mc_msg_unformat_done = SJIS("アンフォーマットに成功／しました。￥");

char *g_mc_msg_unformat_failed = SJIS("アンフォーマットに失敗／しました。￥");

char *g_mc_msg_format_ask[2] = {
    SJIS("MEMORY CARD差込口1の／メモリーカード（PS2）は／フォーマットされており／ません。フォーマットを／行ないますか？￥"),
    SJIS("MEMORY CARD差込口2の／メモリーカード（PS2）は／フォーマットされており／ません。フォーマットを／行ないますか？￥"),
};

char *g_mc_msg_format_done = SJIS("フォーマットが／完了しました。￥");

char *g_mc_msg_format_failed = SJIS("フォーマットに／失敗しました。￥");

char *g_mc_msg_start_no_card = SJIS("MEMORY CARD差込口1に／メモリーカード（PS2）が／差されていません。／このゲームのデータを／セーブするには空き容量／ 40KB以上必要です。／このまま開始しますか？￥");

char *g_mc_msg_start_no_space = SJIS("メモリーカード（PS2）の／空き容量が／不足しています。／・ゲームデータ／(空き容量:40KB以上）￥");

char *g_mc_msg_start_without_save = SJIS("このままゲームを／開始すると、／ゲームデータを／セーブできません。／よろしいですか？￥");

char *g_mc_msg_no_card_no_system_data = SJIS("MEMORY CARD差込口1に／メモリーカード（PS2）が／差されていません。／このままでは／システムデータを／作成出来ません。￥");

char *g_mc_msg_save_ask[11] = {
    SJIS("ゲームデータの／セーブには40KB以上の／空き容量が必要です。／セーブしますか？￥"),
    SJIS("リプレイデータの／セーブには170KB以上の／空き容量が必要です。／セーブしますか？￥"),
    SJIS("リプレイデータの／セーブには170KB以上の／空き容量が必要です。／セーブしますか？￥"),
    SJIS("リプレイデータの／セーブには170KB以上の／空き容量が必要です。／セーブしますか？￥"),
    SJIS("リプレイデータの／セーブには170KB以上の／空き容量が必要です。／セーブしますか？￥"),
    SJIS("リプレイデータの／セーブには170KB以上の／空き容量が必要です。／セーブしますか？￥"),
    SJIS("リプレイデータの／セーブには170KB以上の／空き容量が必要です。／セーブしますか？￥"),
    SJIS("リプレイデータの／セーブには170KB以上の／空き容量が必要です。／セーブしますか？￥"),
    SJIS("リプレイデータの／セーブには170KB以上の／空き容量が必要です。／セーブしますか？￥"),
    SJIS("リプレイデータの／セーブには170KB以上の／空き容量が必要です。／セーブしますか？￥"),
    SJIS("リプレイデータの／セーブには170KB以上の／空き容量が必要です。／セーブしますか？￥"),
};

char *g_mc_msg_save_continue = SJIS("セーブを続けますか？￥");

char *g_mc_msg_save_done = SJIS("セーブが完了しました。￥");

char *g_mc_msg_save_failed = SJIS("セーブに失敗しました。￥");

char *g_mc_msg_overwrite_ask[11] = {
    SJIS("ゲームデータが／存在します。／上書きセーブしますか？￥"),
    SJIS("リプレイデータが／存在します。／上書きセーブしますか？￥"),
    SJIS("リプレイデータが／存在します。／上書きセーブしますか？￥"),
    SJIS("リプレイデータが／存在します。／上書きセーブしますか？￥"),
    SJIS("リプレイデータが／存在します。／上書きセーブしますか？￥"),
    SJIS("リプレイデータが／存在します。／上書きセーブしますか？￥"),
    SJIS("リプレイデータが／存在します。／上書きセーブしますか？￥"),
    SJIS("リプレイデータが／存在します。／上書きセーブしますか？￥"),
    SJIS("リプレイデータが／存在します。／上書きセーブしますか？￥"),
    SJIS("リプレイデータが／存在します。／上書きセーブしますか？￥"),
    SJIS("リプレイデータが／存在します。／上書きセーブしますか？￥"),
};

char *g_mc_msg_save_to_card_ask[11] = {
    SJIS("ゲームデータを、／メモリーカード（PS2）に／セーブしますか？￥"),
    SJIS("リプレイデータを、／メモリーカード（PS2）に／セーブしますか？￥"),
    SJIS("リプレイデータを、／メモリーカード（PS2）に／セーブしますか？￥"),
    SJIS("リプレイデータを、／メモリーカード（PS2）に／セーブしますか？￥"),
    SJIS("リプレイデータを、／メモリーカード（PS2）に／セーブしますか？￥"),
    SJIS("リプレイデータを、／メモリーカード（PS2）に／セーブしますか？￥"),
    SJIS("リプレイデータを、／メモリーカード（PS2）に／セーブしますか？￥"),
    SJIS("リプレイデータを、／メモリーカード（PS2）に／セーブしますか？￥"),
    SJIS("リプレイデータを、／メモリーカード（PS2）に／セーブしますか？￥"),
    SJIS("リプレイデータを、／メモリーカード（PS2）に／セーブしますか？￥"),
    SJIS("リプレイデータを、／メモリーカード（PS2）に／セーブしますか？￥"),
};

char *g_mc_msg_no_space = SJIS("メモリーカード（PS2）の／空き容量が／不足しています。￥");

char *g_mc_msg_to_save[11] = {
    SJIS("ゲームデータをセーブ／するには￥"),
    SJIS("リプレイデータをセーブ／するには￥"),
    SJIS("リプレイデータをセーブ／するには￥"),
    SJIS("リプレイデータをセーブ／するには￥"),
    SJIS("リプレイデータをセーブ／するには￥"),
    SJIS("リプレイデータをセーブ／するには￥"),
    SJIS("リプレイデータをセーブ／するには￥"),
    SJIS("リプレイデータをセーブ／するには￥"),
    SJIS("リプレイデータをセーブ／するには￥"),
    SJIS("リプレイデータをセーブ／するには￥"),
    SJIS("リプレイデータをセーブ／するには￥"),
};

char *g_mc_msg_needed_space[2] = {
    SJIS("MEMORY CARD差込口1の／メモリーカード（PS2）に／空き容量   KB以上が／必要です。￥"),
    SJIS("MEMORY CARD差込口2の／メモリーカード（PS2）に／空き容量   KB以上が／必要です。￥"),
};

char *g_mc_msg_load_ask[12] = {
    SJIS("ゲームデータを／メモリーカード（PS2）／からロードしますか？￥"),
    SJIS("リプレイデータを／メモリーカード（PS2）／からロードしますか？￥"),
    SJIS("リプレイデータを／メモリーカード（PS2）／からロードしますか？￥"),
    SJIS("リプレイデータを／メモリーカード（PS2）／からロードしますか？￥"),
    SJIS("リプレイデータを／メモリーカード（PS2）／からロードしますか？￥"),
    SJIS("リプレイデータを／メモリーカード（PS2）／からロードしますか？￥"),
    SJIS("リプレイデータを／メモリーカード（PS2）／からロードしますか？￥"),
    SJIS("リプレイデータを／メモリーカード（PS2）／からロードしますか？￥"),
    SJIS("リプレイデータを／メモリーカード（PS2）／からロードしますか？￥"),
    SJIS("リプレイデータを／メモリーカード（PS2）／からロードしますか？￥"),
    SJIS("リプレイデータを／メモリーカード（PS2）／からロードしますか？￥"),
    SJIS(" 　ゲームデータを／ メモリーカード（PS2）／ からロードしますか？￥"),
};

char *g_mc_msg_load_continue = SJIS("ロードを続けますか？￥");

char *g_mc_msg_load_done = SJIS("ロードが完了しました。￥");

char *g_mc_msg_load_failed = SJIS("ロードに失敗しました。￥");

char *g_mc_msg_not_formatted = SJIS("MEMORY CARD差込口1の／メモリーカード（PS2）は／フォーマットされて／いません。￥");

char *g_mc_msg_option_unlocked[4] = {
    SJIS("エクストラオプションに／START ROUND／が追加されました。￥"),
    SJIS("エクストラオプションに／HIT DISP／が追加されました。￥"),
    SJIS("エクストラオプションに／ROUND SET／が追加されました。￥"),
    SJIS("エクストラオプションに／BULLET／が追加されました。￥"),
};

char *g_mc_dir_names[11] = {
    "/BISLPS-25233",
    "/BISLPS-25233REPLAY1",
    "/BISLPS-25233REPLAY2",
    "/BISLPS-25233REPLAY3",
    "/BISLPS-25233REPLAY4",
    "/BISLPS-25233REPLAY5",
    "/BISLPS-25233REPLAY6",
    "/BISLPS-25233REPLAY7",
    "/BISLPS-25233REPLAY8",
    "/BISLPS-25233REPLAY9",
    "/BISLPS-25233REPLAY10",
};

char *g_mc_dir_patterns[11] = {
    "/BISLPS-25233/*",
    "/BISLPS-25233REPLAY1/*",
    "/BISLPS-25233REPLAY2/*",
    "/BISLPS-25233REPLAY3/*",
    "/BISLPS-25233REPLAY4/*",
    "/BISLPS-25233REPLAY5/*",
    "/BISLPS-25233REPLAY6/*",
    "/BISLPS-25233REPLAY7/*",
    "/BISLPS-25233REPLAY8/*",
    "/BISLPS-25233REPLAY9/*",
    "/BISLPS-25233REPLAY10/*",
};

char *g_mc_file_paths[11] = {
    "/BISLPS-25233/BISLPS-25233",
    "/BISLPS-25233REPLAY1/BISLPS-25233REPLAY1",
    "/BISLPS-25233REPLAY2/BISLPS-25233REPLAY2",
    "/BISLPS-25233REPLAY3/BISLPS-25233REPLAY3",
    "/BISLPS-25233REPLAY4/BISLPS-25233REPLAY4",
    "/BISLPS-25233REPLAY5/BISLPS-25233REPLAY5",
    "/BISLPS-25233REPLAY6/BISLPS-25233REPLAY6",
    "/BISLPS-25233REPLAY7/BISLPS-25233REPLAY7",
    "/BISLPS-25233REPLAY8/BISLPS-25233REPLAY8",
    "/BISLPS-25233REPLAY9/BISLPS-25233REPLAY9",
    "/BISLPS-25233REPLAY10/BISLPS-25233REPLAY10",
};

s32 g_mc_icon_bg_color[16] = {
    0x80, 0, 0, 0, 0, 0x80, 0, 0,
    0, 0, 0x80, 0, 0x80, 0x80, 0x80, 0,
};

float g_mc_icon_light_dir[12] = {
    0.0f, 1.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 1.0f, 0.0f,
};

float g_mc_icon_light_color[12] = {
    0.5f, 0.5f, 0.5f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
};

float g_mc_icon_ambient[4] = {
    0.2f, 0.2f, 0.2f, 0.0f,
};

void mc_operation_update(void);
void mc_operation_begin();
void mc_buffer_checksum_put(void);
void mc_operation_end();
void mc_task_update_entry();
void mc_task_update(void);
void mc_state_reset(void);
void mc_task_finish(void);
void mc_task_save_ask(void);
void mc_task_save_check_card(void);
void mc_task_make_directory(void);
void mc_task_save_confirm(void);
void mc_task_overwrite_ask(void);
void mc_task_write(void);
void mc_task_write_game(void);
void mc_task_write_replay(void);
void mc_task_save_continue_ask(void);
void mc_task_load_ask(void);
void mc_task_load_check_card(void);
void mc_task_read(void);
void mc_task_read_checked(void);
void mc_read_step(void);
void mc_task_replay_list(void);
s32 replay_slot_infos_next(void);
void mc_replay_headers_read(void);
void mc_task_load_continue_ask(void);
void mc_task_format_ask(void);
void mc_task_format(void);
void mc_task_unformat_ask(void);
void mc_task_unformat(void);
void mc_task_startup_check(void);
void mc_task_no_system_data(void);
void mc_confirm_button_draw(void);
void mc_choice_draw(void);
void mc_busy_message_draw(s32 arg0);
void mc_no_card_message_draw(void);
void mc_checking_message_draw(void);
void mc_damaged_message_draw(s32 arg0, s32 arg1);
void mc_save_failed_message_draw(void);
void mc_no_data_message_draw(s32 arg0);
void mc_load_ask_message_draw(s32 index);
void mc_load_done_message_draw(void);
void mc_load_failed_message_draw(void);
void mc_not_formatted_message_draw(void);
void mc_overwrite_ask_message_draw(s32 index);
void mc_save_to_card_ask_message_draw(s32 index);
void mc_no_space_message_draw(s32 arg0);
s32 mc_save_ask_message_draw(s32 index);
void save_block_from_settings(void);
void display_settings_apply(void);
void mc_task_option_unlocked(void);
void replay_slot_infos_clear(void);

s32 overlay_flush();                            /* extern */
s32 frame_image_draw(s32);                         /* extern */
extern u8 D_0028E268;
extern s32 D_0028ED10;

void mc_frame_draw(void) {
    if ((D_0028E268 != 0) && (D_0028ED10 != 0)) {
        frame_image_draw(D_0028ED10 & 0xFFFF);
        overlay_flush();
    }
}

extern void menu_text_queue_plain(s32 x, s32 y, s32 value);

#ifdef DDPDOJ_PC
void mc_message_draw(s32 x, char *text, s32 unusedA2, s32 unusedA3,
                     s32 unusedT0, s32 value, s32 unusedT2)
{
    u8 *saved_state_address = reg_a0;
#else
void mc_message_draw(s64 x, char *text, s32 unusedA2, s32 unusedA3,
                   s32 unusedT0, s32 value)
{
    s32 saved_state_address = (s32)reg_a0;
#endif

    reg_a0 = (u8 *)text;
    menu_text_queue_plain(0x1C0 - (s16)x, 0x18, value & 0xFFFF);
    reg_a0 = (u8 *)saved_state_address;
}

s32 cd_load_file(s32 *, s32 *);        /* extern */
extern u32 g_cd_last_read_size;
extern s8 D_0028ECD4;
extern s32 D_0028ED00;
extern s32 g_memcard_watch_step;
extern s32 D_0028ED0C;
extern s32 D_0028ED14;
extern s32 D_0028ED18;
extern s32 D_0028ED24;
extern s32 D_0028ED28;
extern u8 D_0068E580[];
extern u8 D_00696D80[];

void mc_init(void) {
    cd_load_file(((s32 *)D_00696D80), (s32 *)g_mc_icon_cd_path_a);
    D_0028ED28 = (s32)g_cd_last_read_size;
    cd_load_file(((s32 *)D_0068E580), (s32 *)g_mc_icon_cd_path_b);
    D_0028ED24 = (s32)g_cd_last_read_size;
    mc_state_reset();
    D_0028ED0C = 0;
    D_0028ED18 = 0;
    D_0028ED14 = 0;
    D_0028ED10 = 0;
    g_memcard_watch_step = 0;
    D_0028ED00 = 0;
    D_0028ECD4 = 0;
}

extern s32 g_mc_file;
extern s32 g_mc_operation;
extern s8 g_mc_auto;


void mc_save_update(s32 value) {
    g_mc_file = value;
    g_mc_operation = 0;
    g_mc_auto = 0;
    mc_operation_update();
}

extern s8 g_mc_auto;

void mc_autosave_update(s32 arg0) {
    g_mc_file = arg0;
    g_mc_auto = 1;
    g_mc_operation = 0;
    mc_operation_update();
}

void mc_load_update(s32 value) {
    g_mc_file = value;
    g_mc_operation = 1;
    g_mc_auto = 0;
    mc_operation_update();
}

void mc_autoload_update(void) {
    g_mc_operation = 4;
    g_mc_auto = 1;
    mc_operation_update();
}


void mc_startup_load_begin(void) {
    g_mc_file = 0;
    g_mc_operation = 3;
    g_mc_auto = 0;
    mc_operation_update();
}

void mc_watch_check_begin(void) {
    g_mc_operation = 6;
    g_mc_auto = 1;
    g_mc_file = 0;
    mc_operation_update();
}

void mc_replay_save_begin(s32 arg0) {
    g_mc_file = arg0;
    g_mc_operation = 0;
    g_mc_auto = 0;
    mc_operation_update();
}

void mc_replay_load_begin(s32 arg0) {
    g_mc_file = arg0;
    g_mc_operation = 1;
    g_mc_auto = 1;
    mc_operation_update();
}

void mc_replay_autosave_begin(void) {
    if (D_0028ED00 == 0) {
        g_mc_file = 0;
        D_0028ECD4 = 1;
        g_mc_operation = 7;
        g_mc_auto = 1;
    }
    mc_operation_update();
}

s32 text_queue_clear_all();                            /* extern */
extern s32 D_0028ED08;

void mc_operation_update(void) {
    text_queue_clear_all();
    switch (D_0028ED18) {                           /* irregular */
    case 0:
        mc_operation_begin(D_0028ED18);
        break;
    case 1:
        mc_task_update_entry(D_0028ED18);
        break;
    case 2:
        mc_operation_end(D_0028ED18);
        break;
    }
    if (D_0028ED08 == 0) {
        if (D_0028ED10 < 0x80) {
            D_0028ED10 += 8;
            return;
        }
        D_0028ED10 = 0x80;
        return;
    }
    if (D_0028ED10 > 0) {
        D_0028ED10 -= 8;
        return;
    }
    D_0028ED10 = 0;
}

extern s32 D_0028ECC0;
extern s32 D_0028ECC4;
extern s32 D_0028ECCC;
extern u8 D_0028ECD8;
extern u8 g_mc_step;
extern u8 g_mc_task;
extern s32 D_006A0E40[];

void mc_operation_begin() {
    D_0028E268 = 1;
    D_0028ED10 = 0;
    D_0028ED08 = 0;
    ((s32 *)D_006A0E40)[0] = 0;
    ((s32 *)D_006A0E40)[1] = 0;
    ((s32 *)D_006A0E40)[2] = 0;
    ((s32 *)D_006A0E40)[3] = 0;
    D_0028ED0C = 0;
    D_0028ECC4 = 0;
    D_0028ECC0 = 0;
    D_0028ECD8 = 0;
    g_mc_step = 0;
    D_0028ECCC = 0;
    D_0028ED00 = 0;
    D_0028ED18 += 1;
    switch ((u32)g_mc_operation) {
    case 0:
        g_mc_task = 0xA;
        save_block_from_settings();
        mc_buffer_checksum_put();
        break;
    case 1:
    case 4:
    case 6:
    case 7:
        g_mc_task = 0x14;
        break;
    case 2:
        g_mc_task = 0x28;
        break;
    case 3:
        g_mc_task = 0;
        break;
    case 5:
        g_mc_task = 0x46;
        break;
    case 8:
        g_mc_task = 0x50;
        break;
    }
}

#ifndef DDPDOJ_PC
extern u8 g_replay_file_loaded[];
#endif
extern s32 D_006C4AE8[];
extern u8 g_mc_save_buf[];
extern s32 D_006C5494[];

void mc_buffer_checksum_put(void) {
    s32 size;
    s32 i;
    s8 *data;
    s32 sum;

    switch ((u32)g_mc_file) {
    case 0:
        data = ((s8 *)g_mc_save_buf);
        size = 0x5A4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        size = 0x202E8;
        data = ((s8 *)g_replay_file_loaded);
        break;
    }
    sum = 0;
    for (i = 0; i < size; i++) {
        sum ^= *data++;
    }
    printf("put flg[%d]size[%d]sum[%x]\n", (u32)g_mc_file, size, sum);
    switch ((u32)g_mc_file) {
    case 0:
        D_006C5494[0] = sum;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        D_006C4AE8[0] = sum;
        break;
    }
}


s32 mc_buffer_checksum_check(void) {
    s32 size;
    s32 i;
    s8 *data;
    s32 sum;
    s32 result;

    switch ((u32)g_mc_file) {
    case 0:
        data = ((s8 *)g_mc_save_buf);
        size = 0x5A4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        size = 0x202E8;
        data = ((s8 *)g_replay_file_loaded);
        break;
    }
    sum = 0;
    for (i = 0; i < size; i++) {
        sum ^= *data++;
    }
    printf("flg[%d]size[%d]sum[%x]\n", (u32)g_mc_file, size, sum);
    result = 0;
    switch ((u32)g_mc_file) {
    case 0:
        if (D_006C5494[0] != sum) {
            result = 1;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        if (D_006C4AE8[0] != sum) {
            result = 1;
        }
        break;
    }
    return result;
}


void mc_operation_end() {
    mc_state_reset();
    D_0028E268 = 0;
    D_0028ED0C = 1;
    D_0028ED18 = 0;
    D_0028ED14 = 0;
    D_0028ED00 = 0;
    D_0028ECD4 = 0;
}


void mc_task_update_entry() {
    mc_task_update();
}

extern s32 g_mc_port;
extern s32 g_mc_slot;
extern s32 D_0028ECAC;
extern s32 D_0028ECB0;
extern s32 D_0028ECB4;
extern s32 D_0028ECB8;

s32 mc_card_info_wait(s32 arg0) {
    s32 sceMcSync(s32, s32, s32 *);
#ifndef DDPDOJ_PC
    s32 sceMcGetInfo(s32, s32, s32 *, u8 *, s32 *);
#endif
    s32 result;
    s32 ret;
    s32 tries;

    tries = 0;
retry:
#ifdef DDPDOJ_PC
    D_0028ECAC = sceMcGetInfo(g_mc_port, g_mc_slot, &D_0028ECB8, &D_0028ECB4, &D_0028ECB0);
#else
    D_0028ECAC = sceMcGetInfo(g_mc_port, g_mc_slot, &D_0028ECB8, &(*(u8 *)&D_0028ECB4), &D_0028ECB0);
#endif
    if (D_0028ECAC != 0) {
        sceGsSyncV(0);
        sceMcSync(0, 0, &result);
        goto retry;
    }
    sceMcSync(0, 0, &result);
    ret = 0;
    switch (result) {
    case 0:
        if (D_0028ECB0 == 0) {
            ret = 1;
        }
        if (D_0028ECB8 != 2) {
            ret = 2;
        }
        break;
    case -1:
    case -2:
        ret = 4;
        break;
    default:
        ret = 3;
        break;
    }
    if (ret != 0 && (arg0 != 1 || ret != 4)) {
        sceGsSyncV(0);
        tries++;
        if (tries < 6) {
            goto retry;
        }
    }
    return ret;
}

extern s32 D_0028ECB4;
extern s32 D_0028ECC8;
extern s32 D_0028ECD0;

void mc_card_present_poll(s32 arg0) {
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
#ifndef DDPDOJ_PC
    s32 sceMcGetInfo(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 *arg4);
#endif
    s32 result;
    s32 error;

    switch (D_0028ECCC) {
    case 0:
        if (sceMcSync(1, 0, &result) != 0) {
            D_0028ECC8 = 0;
            D_0028ECD0 = 6;
            D_0028ECCC += 1;
        }
        break;
    case 1:
        D_0028ECAC = sceMcGetInfo(g_mc_port, g_mc_slot, &D_0028ECB8, &D_0028ECB4, &D_0028ECB0);
        if (D_0028ECAC == 0) {
            D_0028ECCC += 1;
        }
        break;
    case 2:
        if (sceMcSync(1, 0, &result) != 0) {
            error = 0;
            switch (result) {
            case 0:
                if (D_0028ECB0 == 0) {
                    error = 1;
                }
                if (D_0028ECB8 != 2) {
                    error = 2;
                }
                break;
            case -1:
            case -2:
                error = 4;
                break;
            default:
                error = 3;
                break;
            }
            D_0028ECC8 = error;
            if ((error == 0) || ((arg0 == 1) && (error == 4))) {
                D_0028ECCC = 0;
                D_0028ECD0 = 0;
            } else {
                D_0028ECCC = 1;
                D_0028ECD0 -= 1;
                if (D_0028ECD0 <= 0) {
                    D_0028ECCC = 0;
                    D_0028ECD0 = 0;
                }
            }
        }
        break;
    }
}

extern u8 D_0028ECE8;

void mc_title_draw(void) {
#ifndef DDPDOJ_PC
    void mc_message_draw(s32 x, char *text, s32 a, s32 b, s32 c, s32 d, s32 e);
#endif
    if (g_mc_auto != 0) {
        mc_message_draw(0x64, g_mc_msg_title_auto[g_mc_operation], 0, 0x14, 0xE, (*(u16 *)&D_0028ED10), 0x64);
    } else {
        mc_message_draw(0x64, g_mc_msg_title[g_mc_operation], 0, 0x14, 0xE, (*(u16 *)&D_0028ED10), 0x64);
    }
    mc_message_draw(0x78, g_mc_msg_slot_name[D_0028ECE8], 0, 0x14, 0xE, (*(u16 *)&D_0028ED10), 0x64);
}

extern u8 g_mc_task;

void mc_task_update(void) {
    switch (g_mc_task) {
    case 0x0:
        mc_state_reset();
        g_mc_task = 0x32;
        break;
    case 0x1:
        break;
    case 0x2:
        mc_task_finish();
        break;
    case 0xA:
        mc_task_save_ask();
        break;
    case 0xB:
        mc_task_save_check_card();
        break;
    case 0xC:
        mc_task_make_directory();
        break;
    case 0xD:
        mc_task_overwrite_ask();
        break;
    case 0x10:
        mc_task_write();
        break;
    case 0x11:
        mc_task_save_continue_ask();
        break;
    case 0x12:
        mc_task_save_confirm();
        break;
    case 0x14:
        mc_task_load_ask();
        break;
    case 0x15:
        mc_task_load_check_card();
        break;
    case 0x16:
        mc_task_read();
        break;
    case 0x17:
        mc_task_read_checked();
        break;
    case 0x19:
        mc_task_load_continue_ask();
        break;
    case 0x1B:
        mc_task_replay_list();
        break;
    case 0x1E:
        mc_task_format_ask();
        break;
    case 0x1F:
        mc_task_format();
        break;
    case 0x28:
        mc_task_unformat_ask();
        break;
    case 0x29:
        mc_task_unformat();
        break;
    case 0x32:
        mc_task_startup_check();
        break;
    case 0x46:
        mc_task_no_system_data();
        break;
    case 0x50:
        mc_task_option_unlocked();
        break;
    }
}

void sfx_explosion_air_small(void);
void sfx_extend(void);
void sfx_countdown(void);
void sfx_confirm(void);

void menu_sfx_play(s32 arg0) {
    if (arg0 == 2) {
        sfx_confirm();
        return;
    }
    if (arg0 == 1) {
        sfx_countdown();
    } else if (arg0 == 10) {
        sfx_extend();
    } else if (arg0 == 11) {
        sfx_explosion_air_small();
    }
}

extern u8 g_memcard_watch_delay;
extern u8 D_0028ECE4;
extern u8 g_mc_choice;
extern u8 g_mc_wait;
extern s8 mc_state_reset_state;

void mc_state_reset(void) {
    mc_state_reset_state = 0;
    D_0028ECE8 = 0;
    g_mc_choice = 1;
    g_mc_step = 0;
    g_memcard_watch_delay = 0;
    D_0028ECE4 = 0;
    g_mc_wait = 0;
    D_0028ECD8 = 0;
    D_0028ECD0 = 0;
    D_0028ECCC = 0;
    D_0028ECC8 = 0;
}

void mc_task_finish(void) {
    mc_title_draw();
    D_0028ECE8 = 0;
    g_mc_port = 0;
    g_mc_slot = 0;
    g_mc_step = 0;
    if (g_mc_operation == 0) {
        g_mc_task = 0xB;
    } else {
        if ((g_mc_operation == 1) || (g_mc_operation == 4) || (g_mc_operation == 6) || (g_mc_operation == 7)) {
            g_mc_task = 0x15;
        } else {
            g_mc_task = 0x29;
        }
    }
}

extern u16 g_mc_cursor_target_x;
extern u16 D_0028ECA0;
extern u16 g_mc_cursor_x;
extern u8 D_0028ECDC;
extern u8 g_mc_choice;
extern u8 g_mc_step;
void mc_task_save_ask(void) {
    s32 temp_v0;
    s32 var_v1;

    if (g_mc_auto != 0) {
        g_mc_step = 0;
        g_mc_task = 2;
        return;
    }
    mc_title_draw();
    mc_save_to_card_ask_message_draw(g_mc_file);
    switch (g_mc_step) {                           /* irregular */
    case 0:
        g_mc_choice = 1;
        g_mc_step += 1;
        D_0028ECA0 = 0xCE;
        g_mc_cursor_x = 0x144;
        /* fallthrough */
    case 1:
        if (g_pad_trigger[2] & 0x20) {
            menu_sfx_play(2);
            g_mc_step = 3;
        } else {
            if ((g_mc_choice == 1) && (g_pad_trigger[2] & 0x8000)) {
                menu_sfx_play(1);
                g_mc_choice = 0;
                g_mc_cursor_target_x = 0xEA;
                D_0028ECDC = 0;
            }
            if ((g_mc_choice == 0) && (g_pad_trigger[2] & 0x2000)) {
                menu_sfx_play(1);
                D_0028ECDC = 0;
                g_mc_choice = 1;
                g_mc_cursor_target_x = 0x144;
            }
        }
        break;
    case 2:
        if (g_mc_cursor_target_x == g_mc_cursor_x) {
            g_mc_step = 1;
        } else {
            temp_v0 = g_mc_cursor_target_x - g_mc_cursor_x;
            var_v1 = temp_v0 >> 1;
            if (temp_v0 < 0) {
                var_v1 = (s32) (temp_v0 + 1) >> 1;
            }
            if (var_v1 == 0) {
                var_v1 = 1;
                if (g_mc_choice == 0) {
                    var_v1 = -1;
                }
            }
            g_mc_cursor_x += var_v1 & 0xFFFF;
        }
        break;
    case 3:
        g_mc_step = 0;
        if (g_mc_choice == 1) {
            g_mc_step = 4;
        } else {
            g_mc_task = 2;
        }
        break;
    case 4:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    }
    mc_choice_draw();
}
extern u8 g_mc_wait;
#ifndef DDPDOJ_PC
extern u8 g_mc_dir[];
#endif

void mc_task_save_check_card(void) {
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    s32 sceMcGetDir(s32 arg0, s32 arg1, char * arg2, s32 arg3, s32 arg4, void *arg5);
    s32 strcmp(const char *a, const char *b);
    s32 result;
    s32 missing;
    s32 i;
    s32 offset;
    s32 offset2;
    s32 j;
    u8 *entry;

    mc_title_draw();
    if ((g_mc_step != 0) && ((g_mc_step < 10) || (g_mc_step > 60))) {
        mc_checking_message_draw();
    }
    switch (g_mc_step) {
    case 0:
        mc_card_present_poll(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 3:
            case 4:
                g_mc_step = 20;
                break;
            default:
                g_mc_step += 1;
                g_mc_wait = 60;
                break;
            }
        }
        break;
    case 1:
        if (g_mc_wait != 0) {
            g_mc_wait -= 1;
        } else {
            g_mc_step += 1;
        }
        break;
    case 2:
        mc_card_present_poll(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 0:
                g_mc_step += 1;
                g_mc_wait = 10;
                break;
            case 1:
                g_mc_step = 0;
                g_mc_task = 30;
                break;
            case 2:
                g_mc_step = 30;
                break;
            case 3:
            case 4:
                g_mc_step = 20;
                break;
            }
        }
        break;
    case 3:
        if (sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_patterns[g_mc_file], 0, 5, g_mc_dir) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 10;
        }
        break;
    case 4:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                if (D_0028ECB4 < g_mc_needed_kilobytes[g_mc_file * 2]) {
                    g_mc_step = 50;
                } else {
                    g_mc_step = 0;
                    g_mc_task = 18;
                }
                break;
            }
            g_mc_step += 1;
            g_mc_wait = 10;
        }
        break;
    case 5:
        missing = 1;
        for (i = 0, offset = 0; i < 5; i++, offset += 0x40) {
            if (g_mc_file == 0) {
                entry = g_mc_dir + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233") == 0) && (*(s32 *)(entry + 0x10) == 0x9A8)) {
                    missing = 0;
                }
            }
            if (g_mc_file == 1) {
                entry = g_mc_dir + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY1") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (g_mc_file == 2) {
                entry = g_mc_dir + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY2") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (g_mc_file == 3) {
                entry = g_mc_dir + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY3") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (g_mc_file == 4) {
                entry = g_mc_dir + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY4") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (g_mc_file == 5) {
                entry = g_mc_dir + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY5") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (g_mc_file == 6) {
                entry = g_mc_dir + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY6") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (g_mc_file == 7) {
                entry = g_mc_dir + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY7") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (g_mc_file == 8) {
                entry = g_mc_dir + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY8") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (g_mc_file == 9) {
                entry = g_mc_dir + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY9") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (g_mc_file == 10) {
                entry = g_mc_dir + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY10") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
        }
        for (j = 0, offset2 = 0; j < 5; j++, offset2 += 0x40) {
            if (g_mc_file == 0) {
                entry = g_mc_dir + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233") == 0) {
                    printf("--net file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (g_mc_file == 1) {
                entry = g_mc_dir + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY1") == 0) {
                    printf("--replay1 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (g_mc_file == 2) {
                entry = g_mc_dir + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY2") == 0) {
                    printf("--replay2 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (g_mc_file == 3) {
                entry = g_mc_dir + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY3") == 0) {
                    printf("--replay3 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (g_mc_file == 4) {
                entry = g_mc_dir + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY4") == 0) {
                    printf("--replay4 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (g_mc_file == 5) {
                entry = g_mc_dir + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY5") == 0) {
                    printf("--replay5 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (g_mc_file == 6) {
                entry = g_mc_dir + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY6") == 0) {
                    printf("--replay6 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (g_mc_file == 7) {
                entry = g_mc_dir + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY7") == 0) {
                    printf("--replay7 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (g_mc_file == 8) {
                entry = g_mc_dir + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY8") == 0) {
                    printf("--replay8 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (g_mc_file == 9) {
                entry = g_mc_dir + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY9") == 0) {
                    printf("--replay9 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (g_mc_file == 10) {
                entry = g_mc_dir + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY10") == 0) {
                    printf("--replay10 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
        }
        if (missing != 0) {
            g_mc_step = 35;
        } else {
            g_mc_step = 0;
            g_mc_task = 13;
        }
        break;
    case 40:
        g_mc_step = 0;
        g_mc_task = 17;
        break;
    case 10:
        mc_save_failed_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 40;
        }
        break;
    case 20:
        mc_no_card_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 40;
        }
        break;
    case 30:
        mc_no_card_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 40;
        }
        break;
    case 35:
        if (g_mc_file == 0) {
            mc_damaged_message_draw(1, 0);
        } else {
            mc_damaged_message_draw(1, g_mc_file);
        }
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 40;
        }
        break;
    case 50:
        mc_no_space_message_draw(g_mc_file);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 40;
        }
        break;
    }
}

s32 sceMcMkdir(s32 arg0, s32 arg1, char * arg2);
extern u8 D_0028ECD8;

void mc_task_make_directory(void) {
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    s32 result;

    mc_title_draw();
    if (g_mc_step == 1) {
        mc_busy_message_draw(0);
    }
    switch (g_mc_step) {
    case 0:
        mc_card_present_poll(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 != 0) {
                g_mc_step = 20;
                break;
            }
            D_0028ECC0 = 0;
            if (sceMcMkdir(g_mc_port, g_mc_slot, g_mc_dir_names[g_mc_file]) == 0) {
                g_mc_step += 1;
                break;
            }
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 30;
            }
        }
        break;
    case 1:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result == 0) {
                D_0028ECD8 = 0;
                g_mc_task = 16;
                g_mc_step = 0;
            } else {
                g_mc_step = 30;
            }
        }
        break;
    case 20:
        mc_no_card_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 0;
            g_mc_task = 17;
        }
        break;
    case 30:
        mc_save_failed_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 0;
            g_mc_task = 17;
        }
        break;
    }
}

extern u16 D_0028ECA0;
extern u8 D_0028ECDC;
extern u8 g_memcard_watch_delay;
extern u8 D_0028ECE4;

void mc_task_save_confirm(void) {
    s32 diff;
    s32 step;

    mc_title_draw();
    if ((g_mc_step != 20) && (g_mc_step != 0)) {
        mc_save_ask_message_draw(g_mc_file);
        mc_choice_draw();
    }
    switch (g_mc_step) {
    case 0:
        g_mc_choice = 1;
        D_0028ECE4 = 3;
        D_0028ECA0 = 206;
        g_mc_cursor_x = 324;
        g_mc_step += 1;
        g_memcard_watch_delay = 0;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            g_mc_step += 1;
        }
        break;
    case 2:
        if (g_memcard_watch_delay > 60) {
            mc_card_present_poll(1);
            if (D_0028ECD0 == 0) {
                g_memcard_watch_delay = 0;
                if (D_0028ECC8 != 0) {
                    g_mc_step = 20;
                    break;
                }
            }
        } else {
            g_memcard_watch_delay += 1;
        }
        if (g_pad_trigger[2] & 0x20) {
            menu_sfx_play(2);
            g_mc_step = 4;
            if (D_0028ECD0 == 0) {
                D_0028ECCC = 0;
            }
        } else {
            if ((g_mc_choice == 1) && (g_pad_trigger[2] & 0x8000)) {
                menu_sfx_play(1);
                g_mc_choice = 0;
                g_mc_cursor_target_x = 234;
                D_0028ECDC = 0;
            }
            if ((g_mc_choice == 0) && (g_pad_trigger[2] & 0x2000)) {
                menu_sfx_play(1);
                D_0028ECDC = 0;
                g_mc_choice = 1;
                g_mc_cursor_target_x = 324;
            }
        }
        break;
    case 3:
        if (g_mc_cursor_target_x == g_mc_cursor_x) {
            g_mc_step = 2;
            break;
        }
        diff = g_mc_cursor_target_x - g_mc_cursor_x;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (g_mc_choice == 0) {
                step = -1;
            }
        }
        g_mc_cursor_x += step;
        break;
    case 4:
        mc_card_present_poll(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 != 0) {
                g_mc_step = 20;
                break;
            }
            g_mc_step = 0;
            if (g_mc_choice == 1) {
                g_mc_task = 17;
            } else {
                g_mc_task = 12;
            }
        }
        break;
    case 20:
        mc_no_card_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 0;
            g_mc_task = 17;
        }
        break;
    }
}


void mc_task_overwrite_ask(void) {
    s32 diff;
    s32 step;

    mc_title_draw();
    if ((g_mc_step != 20) && (g_mc_step != 0)) {
        mc_overwrite_ask_message_draw(g_mc_file);
        mc_choice_draw();
    }
    switch (g_mc_step) {
    case 0:
        g_mc_choice = 1;
        D_0028ECE4 = 3;
        D_0028ECA0 = 206;
        g_mc_cursor_x = 324;
        g_mc_step += 1;
        g_memcard_watch_delay = 0;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            g_mc_step += 1;
        }
        break;
    case 2:
        if (g_memcard_watch_delay > 60) {
            mc_card_present_poll(1);
            if (D_0028ECD0 == 0) {
                g_memcard_watch_delay = 0;
                if (D_0028ECC8 != 0) {
                    g_mc_step = 20;
                    break;
                }
            }
        } else {
            g_memcard_watch_delay += 1;
        }
        if (g_pad_trigger[2] & 0x20) {
            menu_sfx_play(2);
            g_mc_step = 4;
            if (D_0028ECD0 == 0) {
                D_0028ECCC = 0;
            }
        } else {
            if ((g_mc_choice == 1) && (g_pad_trigger[2] & 0x8000)) {
                menu_sfx_play(1);
                g_mc_choice = 0;
                g_mc_cursor_target_x = 234;
                D_0028ECDC = 0;
            }
            if ((g_mc_choice == 0) && (g_pad_trigger[2] & 0x2000)) {
                menu_sfx_play(1);
                D_0028ECDC = 0;
                g_mc_choice = 1;
                g_mc_cursor_target_x = 324;
            }
        }
        break;
    case 3:
        if (g_mc_cursor_target_x == g_mc_cursor_x) {
            g_mc_step = 2;
            break;
        }
        diff = g_mc_cursor_target_x - g_mc_cursor_x;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (g_mc_choice == 0) {
                step = -1;
            }
        }
        g_mc_cursor_x += step;
        break;
    case 4:
        mc_card_present_poll(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 != 0) {
                g_mc_step = 20;
                break;
            }
            g_mc_step = 0;
            if (g_mc_choice == 1) {
                g_mc_task = 17;
            } else {
                D_0028ECD8 = 1;
                g_mc_task = 16;
            }
        }
        break;
    case 20:
        mc_no_card_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 0;
            g_mc_task = 17;
        }
        break;
    }
}


void mc_task_write(void) {
    switch ((u32)g_mc_file) {
    case 0:
        mc_task_write_game();
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        mc_task_write_replay();
        break;
    }
}

typedef struct {
    char *name[3];
} NameSet;

s32 sceMcWrite(s32 arg0, void *arg1, s32 arg2);
#ifndef DDPDOJ_PC
char *strcpy(u8 *dst, const char *src);
#endif
extern s32 g_mc_fd;
extern u8 D_0068E1B0[];
extern s16 D_0068E1B6[];
extern s32 D_0068E1BC[];
extern u8 D_0068E1C0[];
extern u8 D_0068E200[];
extern u8 D_0068E230[];
extern u8 D_0068E260[];
extern u8 D_0068E270[];
extern u8 D_0068E2B4[];
extern u8 D_0068E2F4[];
extern u8 D_0068E334[];
extern u8 D_00696D80[];
extern u8 g_mc_save_buf[];
void mc_task_write_game(void) {
    s32 sceMcOpen(s32 arg0, s32 arg1, char *arg2, s32 arg3);
    s32 sceMcClose(s32 arg0);
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 result;
    NameSet names = { "icon1.ico", "icon1.ico", "icon1.ico" };

    mc_title_draw();
    switch (g_mc_step) {   
    case 0x0:
        D_0028ECC0 = 0;
        g_mc_step += 1;
        D_0028ECE4 = 0x3C;
        break;
    case 0x1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            g_mc_wait = 0xA;
            if (D_0028ECD8 == 0) {
                g_mc_step += 1;
            } else {
                g_mc_step = 0x24;
            }
        }
        break;
    case 0x2:
        if (sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233/icon.sys", 0x203) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0x3:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 0x2D;
            } else {
                g_mc_fd = result;
                g_mc_step += 1;
            }
        }
        break;
    case 0x4:
        memset(D_0068E1B0, 0, 0x3C4);
        strcpy(D_0068E1B0, (char *)"PS2D");
        strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生ゲームデータ"));
        D_0068E1B6[0] = 0xE;
        D_0068E1BC[0] = 0x60;
        memcpy(D_0068E1C0, g_mc_icon_bg_color, 0x40);
        memcpy(D_0068E200, g_mc_icon_light_dir, 0x30);
        memcpy(D_0068E230, g_mc_icon_light_color, 0x30);
        memcpy(D_0068E260, g_mc_icon_ambient, 0x10);
        strcpy(D_0068E2B4, names.name[0]);
        strcpy(D_0068E2F4, names.name[1]);
        strcpy(D_0068E334, names.name[2]);
        g_mc_step += 1;
        g_mc_wait = 0xA;
        break;
    case 0x5:
        if (sceMcWrite(g_mc_fd, D_0068E1B0, 0x3C4) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0x6:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    g_mc_step = 0x30;
                } else {
                    g_mc_step = 0x2D;
                }
            } else {
                g_mc_step += 1;
                g_mc_wait = 0xA;
            }
        }
        break;
    case 0x7:
        if (sceMcClose(g_mc_fd) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0x8:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 0x2D;
            } else {
                g_mc_step += 1;
            }
        }
        break;
    case 0x9:
        printf("icon1 start[%d]\n", D_0028ED28);
        g_mc_step += 1;
        g_mc_wait = 0xA;
        break;
    case 0xA:
        if (sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233/icon1.ico", 0x203) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0xB:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 0x2D;
            } else {
                g_mc_fd = result;
                g_mc_step += 1;
                g_mc_wait = 0xA;
            }
        }
        break;
    case 0xC:
        if (sceMcWrite(g_mc_fd, D_00696D80, D_0028ED28) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0xD:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    g_mc_step = 0x30;
                } else {
                    g_mc_step = 0x2D;
                }
            } else {
                g_mc_step += 1;
                g_mc_wait = 0xA;
            }
        }
        break;
    case 0xE:
        if (sceMcClose(g_mc_fd) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0xF:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 0x2D;
            } else {
                g_mc_step = 0x24;
                g_mc_wait = 0xA;
            }
        }
        break;
    case 0x24:
        if (sceMcOpen(g_mc_port, g_mc_slot, g_mc_file_paths[g_mc_file], 0x203) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0x25:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 0x2D;
            } else {
                g_mc_fd = result;
                g_mc_step += 1;
                g_mc_wait = 0xA;
            }
        }
        break;
    case 0x26:
        if (sceMcWrite(g_mc_fd, g_mc_save_buf, 0x9A8) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0x27:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    g_mc_step = 0x30;
                } else {
                    g_mc_step = 0x2D;
                }
            } else {
                g_mc_step += 1;
                g_mc_wait = 0xA;
            }
        }
        break;
    case 0x28:
        if (sceMcClose(g_mc_fd) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0x29:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 0x2D;
            } else {
                g_mc_step = 0x32;
                menu_sfx_play(0xA);
                g_mc_wait = 0x3C;
            }
        }
        break;
    case 0x32:
        mc_message_draw(0xC8, g_mc_msg_save_done, 0, 0x14, 0xE, D_0028ED10, 0x64);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step += 1;
        }
        break;
    case 0x33:
        D_0028ECC0 = 1;
        g_mc_step += 1;
        break;
    case 0x34:
        D_0028ED08 = 1;
        if ((s32) D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    case 0x2D:
        menu_sfx_play(0xB);
        g_mc_step += 1;
    case 0x2E:
        mc_save_failed_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 0;
            g_mc_task = 0x11;
        }
        break;
    case 0x30:
        menu_sfx_play(0xB);
        g_mc_step += 1;
    case 0x31:
        mc_no_space_message_draw(0);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 0;
            g_mc_task = 0x11;
        }
        break;
    }
    if ((g_mc_task == 0x10) && ((s32) g_mc_step < 0x2A)) {
        mc_busy_message_draw(0);
    }
}

extern u8 D_0068E580[];
#ifndef DDPDOJ_PC
extern u8 g_replay_file_loaded[];
#endif
void mc_task_write_replay(void) {
    s32 sceMcOpen(s32 arg0, s32 arg1, char *arg2, s32 arg3);
    s32 sceMcClose(s32 arg0);
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 ret;
    s32 result;
    NameSet names = { "icon1.ico", "icon1.ico", "icon1.ico" };

    mc_title_draw();
    switch (g_mc_step) {   
    case 0x0:
        D_0028ECC0 = 0;
        g_mc_step += 1;
        D_0028ECE4 = 0x3C;
        break;
    case 0x1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            g_mc_wait = 0xA;
            if (D_0028ECD8 == 0) {
                g_mc_step += 1;
            } else {
                g_mc_step = 0x24;
            }
        }
        break;
    case 0x2:
        if (g_mc_file == 1) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY1/icon.sys", 0x203);
        }
        if (g_mc_file == 2) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY2/icon.sys", 0x203);
        }
        if (g_mc_file == 3) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY3/icon.sys", 0x203);
        }
        if (g_mc_file == 4) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY4/icon.sys", 0x203);
        }
        if (g_mc_file == 5) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY5/icon.sys", 0x203);
        }
        if (g_mc_file == 6) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY6/icon.sys", 0x203);
        }
        if (g_mc_file == 7) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY7/icon.sys", 0x203);
        }
        if (g_mc_file == 8) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY8/icon.sys", 0x203);
        }
        if (g_mc_file == 9) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY9/icon.sys", 0x203);
        }
        if (g_mc_file == 10) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY10/icon.sys", 0x203);
        }
        if (ret == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0x3:
        ret = sceMcSync(1, 0, &result);
        if (ret != 0) {
            if (result < 0) {
                g_mc_step = 0x2D;
            } else {
                g_mc_fd = result;
                g_mc_step += 1;
            }
        }
        break;
    case 0x4:
        memset(D_0068E1B0, 0, 0x3C4);
        strcpy(D_0068E1B0, (char *)"PS2D");
        if (g_mc_file == 1) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ１"));
        }
        if (g_mc_file == 2) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ２"));
        }
        if (g_mc_file == 3) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ３"));
        }
        if (g_mc_file == 4) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ４"));
        }
        if (g_mc_file == 5) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ５"));
        }
        if (g_mc_file == 6) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ６"));
        }
        if (g_mc_file == 7) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ７"));
        }
        if (g_mc_file == 8) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ８"));
        }
        if (g_mc_file == 9) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ９"));
        }
        if (g_mc_file == 10) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ１０"));
        }
        D_0068E1B6[0] = 0xE;
        D_0068E1BC[0] = 0x60;
        memcpy(D_0068E1C0, g_mc_icon_bg_color, 0x40);
        memcpy(D_0068E200, g_mc_icon_light_dir, 0x30);
        memcpy(D_0068E230, g_mc_icon_light_color, 0x30);
        memcpy(D_0068E260, g_mc_icon_ambient, 0x10);
        strcpy(D_0068E2B4, names.name[0]);
        strcpy(D_0068E2F4, names.name[1]);
        strcpy(D_0068E334, names.name[2]);
        g_mc_step += 1;
        g_mc_wait = 0xA;
        break;
    case 0x5:
        if (sceMcWrite(g_mc_fd, D_0068E1B0, 0x3C4) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0x6:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    g_mc_step = 0x30;
                } else {
                    g_mc_step = 0x2D;
                }
            } else {
                g_mc_step += 1;
                g_mc_wait = 0xA;
            }
        }
        break;
    case 0x7:
        if (sceMcClose(g_mc_fd) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0x8:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 0x2D;
            } else {
                g_mc_step += 1;
            }
        }
        break;
    case 0x9:
        printf("icon1 start[%d]\n", D_0028ED24);
        g_mc_step += 1;
        g_mc_wait = 0xA;
        break;
    case 0xA:
        if (g_mc_file == 1) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY1/icon1.ico", 0x203);
        }
        if (g_mc_file == 2) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY2/icon1.ico", 0x203);
        }
        if (g_mc_file == 3) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY3/icon1.ico", 0x203);
        }
        if (g_mc_file == 4) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY4/icon1.ico", 0x203);
        }
        if (g_mc_file == 5) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY5/icon1.ico", 0x203);
        }
        if (g_mc_file == 6) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY6/icon1.ico", 0x203);
        }
        if (g_mc_file == 7) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY7/icon1.ico", 0x203);
        }
        if (g_mc_file == 8) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY8/icon1.ico", 0x203);
        }
        if (g_mc_file == 9) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY9/icon1.ico", 0x203);
        }
        if (g_mc_file == 10) {
            ret = sceMcOpen(g_mc_port, g_mc_slot, "/BISLPS-25233REPLAY10/icon1.ico", 0x203);
        }
        if (ret == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0xB:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 0x2D;
            } else {
                g_mc_fd = result;
                g_mc_step += 1;
                g_mc_wait = 0xA;
            }
        }
        break;
    case 0xC:
        if (sceMcWrite(g_mc_fd, D_0068E580, D_0028ED24) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0xD:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    g_mc_step = 0x30;
                } else {
                    g_mc_step = 0x2D;
                }
            } else {
                g_mc_step += 1;
                g_mc_wait = 0xA;
            }
        }
        break;
    case 0xE:
        if (sceMcClose(g_mc_fd) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0xF:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 0x2D;
            } else {
                g_mc_step = 0x24;
                g_mc_wait = 0xA;
            }
        }
        break;
    case 0x24:
        if (sceMcOpen(g_mc_port, g_mc_slot, g_mc_file_paths[g_mc_file], 0x203) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0x25:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 0x2D;
            } else {
                g_mc_fd = result;
                g_mc_step += 1;
                g_mc_wait = 0xA;
            }
        }
        break;
    case 0x26:
        if (sceMcWrite(g_mc_fd, g_replay_file_loaded, 0x206EC) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0x27:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    g_mc_step = 0x30;
                } else {
                    g_mc_step = 0x2D;
                }
            } else {
                g_mc_step += 1;
                g_mc_wait = 0xA;
            }
        }
        break;
    case 0x28:
        if (sceMcClose(g_mc_fd) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 0x2D;
            }
        }
        break;
    case 0x29:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 0x2D;
            } else {
                g_mc_step = 0x32;
                menu_sfx_play(0xA);
                g_mc_wait = 0x3C;
            }
        }
        break;
    case 0x32:
        mc_message_draw(0xC8, g_mc_msg_save_done, 0, 0x14, 0xE, D_0028ED10, 0x64);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step += 1;
        }
        break;
    case 0x33:
        D_0028ECC0 = 1;
        g_mc_step += 1;
        break;
    case 0x34:
        D_0028ED08 = 1;
        if ((s32) D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    case 0x2D:
        menu_sfx_play(0xB);
        g_mc_step += 1;
    case 0x2E:
        mc_save_failed_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 0;
            g_mc_task = 0x11;
        }
        break;
    case 0x30:
        menu_sfx_play(0xB);
        g_mc_step += 1;
    case 0x31:
        mc_no_space_message_draw(g_mc_file);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 0;
            g_mc_task = 0x11;
        }
        break;
    }
    if ((g_mc_task == 0x10) && ((s32) g_mc_step < 0x2A)) {
        mc_busy_message_draw(0);
    }
}


void mc_task_save_continue_ask(void) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 diff;
    s32 step;

    mc_title_draw();
    mc_message_draw(200, g_mc_msg_save_continue, 0, 20, 14, D_0028ED10, 100);
    switch (g_mc_step) {
    case 0:
        g_mc_choice = 0;
        g_mc_step += 1;
        D_0028ECA0 = 180;
        g_mc_cursor_x = 214;
    case 1:
        if (g_pad_trigger[2] & 0x20) {
            menu_sfx_play(2);
            g_mc_step = 3;
        } else {
            if ((g_mc_choice == 1) && (g_pad_trigger[2] & 0x8000)) {
                menu_sfx_play(1);
                g_mc_choice = 0;
                g_mc_cursor_target_x = 214;
                D_0028ECDC = 0;
            }
            if ((g_mc_choice == 0) && (g_pad_trigger[2] & 0x2000)) {
                menu_sfx_play(1);
                D_0028ECDC = 0;
                g_mc_choice = 1;
                g_mc_cursor_target_x = 304;
            }
        }
        break;
    case 2:
        if (g_mc_cursor_target_x == g_mc_cursor_x) {
            g_mc_step = 1;
            break;
        }
        diff = g_mc_cursor_target_x - g_mc_cursor_x;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (g_mc_choice == 0) {
                step = -1;
            }
        }
        g_mc_cursor_x += step;
        break;
    case 3:
        g_mc_step = 0;
        if (g_mc_choice == 1) {
            g_mc_step = 4;
        } else {
            g_mc_task = 2;
        }
        break;
    case 4:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    }
    mc_choice_draw();
}


void mc_task_load_ask(void) {
    s32 diff;
    s32 step;

    if (g_mc_operation == 4) {
        if (g_mc_auto != 0) {
            g_mc_step = 0;
            g_mc_task = 2;
            return;
        }
        mc_title_draw();
        mc_load_ask_message_draw(11);
    } else {
        if (g_mc_auto != 0) {
            g_mc_step = 0;
            g_mc_task = 2;
            return;
        }
        mc_title_draw();
        mc_load_ask_message_draw(g_mc_file);
    }
    switch (g_mc_step) {
    case 0:
        if (g_mc_operation == 4) {
            g_mc_choice = 1;
            g_mc_cursor_x = 324;
        } else {
            g_mc_choice = 1;
            g_mc_cursor_x = 324;
        }
        D_0028ECA0 = 206;
        g_mc_step += 1;
    case 1:
        if (g_pad_trigger[2] & 0x20) {
            menu_sfx_play(2);
            g_mc_step = 0;
            if (g_mc_choice == 1) {
                g_mc_step = 3;
            } else {
                g_mc_task = 2;
            }
        } else {
            if ((g_mc_choice == 1) && (g_pad_trigger[2] & 0x8000)) {
                menu_sfx_play(1);
                g_mc_choice = 0;
                g_mc_cursor_target_x = 234;
                D_0028ECDC = 0;
            }
            if ((g_mc_choice == 0) && (g_pad_trigger[2] & 0x2000)) {
                menu_sfx_play(1);
                D_0028ECDC = 0;
                g_mc_choice = 1;
                g_mc_cursor_target_x = 324;
            }
        }
        break;
    case 2:
        if (g_mc_cursor_target_x == g_mc_cursor_x) {
            g_mc_step = 1;
            break;
        }
        diff = g_mc_cursor_target_x - g_mc_cursor_x;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (g_mc_choice == 0) {
                step = -1;
            }
        }
        g_mc_cursor_x += step;
        break;
    case 3:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    }
    mc_choice_draw();
}

extern s32 mc_task_load_check_card_state;
#ifndef DDPDOJ_PC
extern s32 D_0069F590[];
#endif

void mc_task_load_check_card(void) {
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    s32 sceMcGetDir(s32 arg0, s32 arg1, char * arg2, s32 arg3, s32 arg4, void *arg5);
    s32 result;
    s32 error;

    mc_title_draw();
    switch (g_mc_step) {
    case 0:
        mc_card_present_poll(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 3:
            case 4:
                g_mc_step = 20;
                break;
            default:
                g_mc_wait = 60;
                g_mc_step += 1;
                break;
            }
        }
        break;
    case 1:
        mc_checking_message_draw();
        if (g_mc_wait != 0) {
            g_mc_wait -= 1;
        } else {
            g_mc_step += 1;
        }
        break;
    case 2:
        mc_checking_message_draw();
        mc_card_present_poll(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 0:
                g_mc_wait = 10;
                g_mc_step += 1;
                if (g_mc_operation == 4) {
                    g_mc_step = 60;
                }
                if ((g_mc_operation == 6) || (g_mc_operation == 7)) {
                    g_mc_step = 0;
                    g_mc_task = 27;
                }
                break;
            case 1:
                g_mc_step = 40;
                break;
            case 2:
                g_mc_step = 30;
                break;
            case 3:
            case 4:
                g_mc_step = 20;
                break;
            }
        }
        break;
    case 3:
        if (sceMcGetDir(g_mc_port, g_mc_slot, g_mc_file_paths[g_mc_file], 0, 99, g_mc_dir) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 10;
        }
        break;
    case 4:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                g_mc_step = 50;
            } else {
                g_mc_step = 5;
            }
        }
        break;
    case 5:
        printf("--file size[%d]--\n", D_0069F590[0]);
        error = 0;
        if (g_mc_file == 0) {
            if (D_0069F590[0] != 2472) {
                error = 1;
            }
        }
        if (((u32)(g_mc_file - 1) <= 8) || (g_mc_file == 10)) {
            if (D_0069F590[0] != 0x206EC) {
                error = 1;
            }
        }
        if (error != 0) {
            g_mc_step = 35;
        } else {
            g_mc_step = 0;
            g_mc_task = 22;
        }
        break;
    case 9:
        if ((g_mc_operation == 4) && (g_mc_auto != 0)) {
            g_mc_step = 67;
            break;
        }
        if (g_mc_auto != 0) {
            g_mc_step = 67;
        } else {
            g_mc_step = 0;
            g_mc_task = 25;
        }
        break;
    case 60:
        mc_task_load_check_card_state = 0;
        if (sceMcGetDir(g_mc_port, g_mc_slot, g_mc_file_paths[0], 0, 99, g_mc_dir) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 10;
        }
        break;
    case 61:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                mc_task_load_check_card_state += 1;
            }
            g_mc_wait = 10;
            g_mc_step += 1;
        }
        break;
    case 62:
        g_mc_wait = 180;
        g_mc_step = 0;
        if (mc_task_load_check_card_state == 1) {
            g_mc_step = 66;
        } else {
            g_mc_task = 23;
        }
        break;
    case 66:
        mc_no_data_message_draw(11);
        if (g_mc_auto != 0) {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step += 1;
            }
        } else {
            mc_confirm_button_draw();
            if (g_pad_trigger[2] & 0x20) {
                g_mc_step = 9;
            }
        }
        break;
    case 67:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    case 10:
        mc_load_failed_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 9;
        }
        break;
    case 20:
        mc_no_card_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 9;
        }
        break;
    case 30:
        mc_no_card_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 9;
        }
        break;
    case 35:
        if (g_mc_file == 0) {
            mc_damaged_message_draw(0, 0);
        } else {
            mc_damaged_message_draw(0, g_mc_file);
        }
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 9;
        }
        break;
    case 40:
        mc_not_formatted_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 9;
        }
        break;
    case 50:
        mc_no_data_message_draw(g_mc_file);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 9;
        }
        break;
    }
}

extern s32 mc_task_read_state;
extern s32 mc_task_read_state_2;

void mc_task_read(void) {
    s32 sceMcOpen(s32 arg0, s32 arg1, char * arg2, s32 arg3);
    s32 sceMcClose(s32 arg0);
    s32 sceMcRead(s32 arg0, void *arg1, s32 arg2);
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    s32 result;
    s32 status;

    mc_title_draw();
    switch (g_mc_step) {
    case 0:
        D_0028ECC4 = 0;
        g_mc_step += 1;
        mc_task_read_state_2 = 0;
        mc_task_read_state = 0x414;
        D_0028ECE4 = 60;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            g_mc_wait = 10;
            g_mc_step += 1;
        }
        break;
    case 2:
        status = sceMcOpen(g_mc_port, g_mc_slot, g_mc_file_paths[(u32)g_mc_file], 3);
        if (status == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 30;
            }
        }
        break;
    case 3:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 30;
            } else {
                g_mc_fd = result;
                g_mc_wait = 10;
                g_mc_step += 1;
            }
        }
        break;
    case 4:
        switch ((u32)g_mc_file) {
        case 0:
            status = sceMcRead(g_mc_fd, g_mc_save_buf, 2472);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            status = sceMcRead(g_mc_fd, g_replay_file_loaded, 0x206EC);
            break;
        }
        if (status == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 30;
            }
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &result) != 0) {
            g_mc_step += 1;
            g_mc_wait = 10;
        }
        break;
    case 6:
        if (sceMcClose(g_mc_fd) == 0) {
            g_mc_step += 1;
        } else {
            g_mc_wait -= 1;
            if (g_mc_wait == 0) {
                g_mc_step = 30;
            }
        }
        break;
    case 7:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 30;
            } else {
                g_mc_wait = 10;
                if (mc_buffer_checksum_check() == 0) {
                    g_mc_step = 10;
                } else {
                    g_mc_step = 30;
                }
            }
        }
        break;
    case 8:
        g_mc_step = 10;
        break;
    case 9:
        sceMcSync(0, 0, &result);
        if (result < 0) {
            g_mc_step = 30;
        } else {
            g_mc_step += 1;
        }
        break;
    case 10:
        menu_sfx_play(10);
        g_mc_wait = 60;
        g_mc_step += 1;
        break;
    case 11:
        mc_load_done_message_draw();
        if ((u8)D_0028ECD4 != 0) {
            g_mc_wait -= 1;
            if ((s32)g_mc_wait <= 0) {
                g_mc_step += 1;
            }
        } else {
            mc_confirm_button_draw();
            if (g_pad_trigger[2] & 0x20) {
                g_mc_step += 1;
            }
        }
        break;
    case 12:
        D_0028ECC4 = 1;
        g_mc_step += 1;
        break;
    case 13:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    case 30:
        menu_sfx_play(11);
        g_mc_step += 1;
    case 31:
        mc_load_failed_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            if (g_mc_auto != 0) {
                g_mc_step = 13;
            } else {
                g_mc_step = 0;
                g_mc_task = 25;
            }
        }
        break;
    }
    if ((g_mc_step < 8) && (g_mc_task == 22)) {
        mc_busy_message_draw(1);
    }
}

extern s32 D_006A0E40[];
extern s32 D_006A0E44[];
extern s32 D_006A0E48[];
extern s32 D_006A0E4C[];

void mc_task_read_checked(void) {
    s32 i;
    s32 count;

    mc_title_draw();
    switch (D_0028ED14) {
    case 0:
        D_006A0E40[0] = 0;
        D_0028ED14 += 1;
        D_006A0E44[0] = 0;
        D_0028ECE4 = 60;
        D_006A0E48[0] = 0;
        g_mc_step = 0;
        D_006A0E4C[0] = 0;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ED14 += 1;
        }
        break;
    case 2:
        g_mc_file = 0;
        mc_read_step();
        break;
    case 3:
        D_0028ED14 += 1;
        break;
    case 4:
        D_0028ED14 += 1;
        break;
    case 5:
        D_0028ED14 += 1;
        break;
    case 6:
        count = 0;
        for (i = 0; i < 4; i++) {
            if (D_006A0E40[i] != 0) {
                count++;
            }
        }
        if (count != 0) {
            menu_sfx_play(10);
            D_0028ED14 += 1;
            D_0028ECE4 = 60;
        } else {
            D_0028ED14 = 30;
        }
        break;
    case 7:
        mc_load_done_message_draw();
        if (g_mc_auto != 0) {
            D_0028ECE4 -= 1;
            if (D_0028ECE4 == 0) {
                D_0028ED14 = 10;
            }
        } else {
            mc_confirm_button_draw();
            if (g_pad_trigger[2] & 0x20) {
                D_0028ED14 = 10;
            }
        }
        break;
    case 10:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    case 30:
        menu_sfx_play(11);
        D_0028ED14 += 1;
    case 31:
        mc_load_failed_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            D_006A0E40[0] = 0;
            D_006A0E44[0] = 0;
            D_006A0E48[0] = 0;
            D_006A0E4C[0] = 0;
            if (g_mc_auto != 0) {
                D_0028ED14 = 10;
            } else {
                D_0028ED14 = 0;
                g_mc_task = 25;
                g_mc_step = 0;
            }
        }
        break;
    case 35:
        menu_sfx_play(11);
        D_0028ED14 += 1;
    case 36:
        mc_damaged_message_draw(0, 0);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            D_0028ED14 = 30;
        }
        break;
    }
    if ((D_0028ED14 < 6) && (g_mc_task == 23)) {
        mc_busy_message_draw(2);
    }
}


void mc_read_step(void) {
    s32 sceMcOpen(s32 arg0, s32 arg1, char * arg2, s32 arg3);
    s32 sceMcClose(s32 arg0);
    s32 sceMcRead(s32 arg0, void *arg1, s32 arg2);
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    s32 sceMcGetDir(s32 arg0, s32 arg1, char * arg2, s32 arg3, s32 arg4, void *arg5);
    s32 result;
    s32 error;
    s32 status;

    switch (g_mc_step) {
    case 0:
        D_006A0E40[g_mc_file] = 0;
        D_0028ECE4 = 10;
        g_mc_step += 1;
        break;
    case 1:
        mc_card_present_poll(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 3:
            case 4:
                g_mc_step = 30;
                break;
            default:
                g_mc_wait = 10;
                g_mc_step += 1;
                break;
            }
        }
        break;
    case 2:
        if (sceMcGetDir(g_mc_port, g_mc_slot, g_mc_file_paths[g_mc_file], 0, 99, g_mc_dir) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 20;
        }
        break;
    case 3:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                g_mc_step = 20;
                break;
            }
            g_mc_step += 1;
            g_mc_wait = 10;
        }
        break;
    case 4:
        if (sceMcOpen(g_mc_port, g_mc_slot, g_mc_file_paths[g_mc_file], 3) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 20;
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 20;
                break;
            }
            printf("--file size[%d]--\n", D_0069F590[0]);
            g_mc_wait = 10;
            error = 0;
            if (g_mc_file == 0) {
                if (D_0069F590[0] != 2472) {
                    error = 1;
                }
            }
            if (error != 0) {
                g_mc_step = 35;
                break;
            }
            g_mc_wait = 10;
            g_mc_fd = result;
            g_mc_step += 1;
        }
        break;
    case 6:
        switch (g_mc_file) {
        case 0:
            status = sceMcRead(g_mc_fd, g_mc_save_buf, 2472);
            break;
        }
        if (status == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 30;
        }
        break;
    case 7:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 30;
                break;
            }
            g_mc_step += 1;
            g_mc_wait = 10;
        }
        break;
    case 8:
        if (sceMcClose(g_mc_fd) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 30;
        }
        break;
    case 9:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 30;
                break;
            }
            g_mc_wait = 10;
            if (mc_buffer_checksum_check() == 0) {
                g_mc_step += 1;
                break;
            }
            printf("--chksum err--\n");
            g_mc_step = 40;
        }
        break;
    case 10:
        g_mc_step += 1;
        break;
    case 11:
        printf("kaku load ok[%d]\n", g_mc_file);
        D_006A0E40[g_mc_file] = 1;
        g_mc_step = 0;
        D_0028ED14 += 1;
        break;
    case 20:
        printf("file nasi[%d]\n", g_mc_file);
        g_mc_step = 0;
        D_0028ED14 += 1;
        break;
    case 30:
        printf("kaku load err[%d]\n", g_mc_file);
        g_mc_step = 0;
        D_0028ED14 = 30;
        break;
    case 35:
        if (sceMcClose(g_mc_fd) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 30;
        }
        break;
    case 36:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                g_mc_step = 30;
                break;
            }
            g_mc_step = 0;
            D_0028ED14 = 35;
        }
        break;
    case 40:
        g_mc_step = 0;
        D_0028ED14 = 35;
        break;
    }
}


void mc_task_replay_list(void) {
    s32 slot;

    mc_title_draw();
    switch (D_0028ED14) {
    case 0:
        replay_slot_infos_clear();
        g_mc_step = 0;
        D_0028ECE4 = 2;
        D_0028ED14 += 1;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ED14 += 1;
        }
        break;
    case 2:
        g_mc_file = 1;
        mc_replay_headers_read();
        break;
    case 3:
        g_mc_file = 2;
        mc_replay_headers_read();
        break;
    case 4:
        g_mc_file = 3;
        mc_replay_headers_read();
        break;
    case 5:
        g_mc_file = 4;
        mc_replay_headers_read();
        break;
    case 6:
        g_mc_file = 5;
        mc_replay_headers_read();
        break;
    case 7:
        g_mc_file = 6;
        mc_replay_headers_read();
        break;
    case 8:
        g_mc_file = 7;
        mc_replay_headers_read();
        break;
    case 9:
        g_mc_file = 8;
        mc_replay_headers_read();
        break;
    case 10:
        g_mc_file = 9;
        mc_replay_headers_read();
        break;
    case 11:
        g_mc_file = 10;
        mc_replay_headers_read();
        break;
    case 12:
        if (g_mc_operation == 7) {
            D_0028ED14 = 13;
        } else {
            D_0028ED14 = 20;
        }
        break;
    case 13:
        slot = replay_slot_infos_next();
        if (slot == 0xFF) {
            D_0028ED14 = 20;
            break;
        }
        g_mc_file = slot;
        g_mc_operation = 1;
        D_006A0E40[0] = 0;
        D_006A0E44[0] = 0;
        g_mc_task = 20;
        D_006A0E48[0] = 0;
        g_mc_auto = 1;
        D_0028ED00 = 1;
        D_0028ED0C = 0;
        D_0028ECC4 = 0;
        D_0028ECC0 = 0;
        D_006A0E4C[0] = 0;
        D_0028ECD8 = 0;
        D_0028ECCC = 0;
        g_mc_step = 0;
        printf("---next load file no[%d]\n", slot);
        break;
    case 20:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    case 30:
        menu_sfx_play(11);
        D_0028ED14 += 1;
    case 31:
        mc_load_failed_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            menu_sfx_play(2);
            replay_slot_infos_clear();
            D_0028ED14 = 20;
        }
        break;
    }
    if ((D_0028ED14 < 12) && (g_mc_task == 27)) {
        mc_checking_message_draw();
    }
}

extern u8 D_0028ED30;
extern u8 D_0028ED35;
extern u8 g_replay_slot_infos[];
extern u8 D_006A0E88[];
extern u8 D_006A0E89[];
extern u8 D_006A0E8A[];
extern u8 D_006A0E8B[];
extern u8 D_006A0E8C[];
extern u8 D_006A0E8D[];

s32 replay_slot_infos_next(void) {
    s32 i;
    s32 offset;
    u8 *save;
    s32 j;
    s32 count;
    s32 k;

    D_0028ED35 += 1;
    if (D_0028ED35 < 11) {
        printf("--next no[%d]\n", D_0028ED35);
        for (i = 0, offset = 0; i < 10; i++, offset += 0x400) {
            save = g_replay_slot_infos + offset;
            printf("[%d][%d][%d][%d][%d]-[%d] no[%d]\n", save[0x38], save[0x39], save[0x3A], save[0x3B], save[0x3C], save[0x3D], i);
            count = 0;
            if (*(u16 *)save == 1) {
                for (j = 0; j < 6; j++) {
                    if ((&D_0028ED30)[j] == save[j + 0x38]) {
                        count++;
                    }
                }
                if (count == 6) {
                    goto found;
                }
            }
        }
    }
    return 0xFF;
found:
    k = i << 10;
    printf("[%d][%d][%d][%d][%d]-[%d] no[%d]\n", D_006A0E88[k], D_006A0E89[k], D_006A0E8A[k], D_006A0E8B[k], D_006A0E8C[k], D_006A0E8D[k], i + 1);
    return i + 1;
}
typedef struct {
    u8 pad0[0x10];
    s16 state;
    u8 pad12[0x34];
    u16 id;
    u8 pad48[0x3B8];
} Slot;
extern Slot D_006A0E40_as_Slot_a[];
void mc_replay_headers_read(void) {
    s32 sceMcOpen();
    s32 sceMcClose();
    s32 sceMcRead();
    s32 sceMcSync();
    s32 sceMcGetDir();
    s32 strcmp();
    s32 sp5C;
    s32 ok;
    s32 i;
    s32 off;
    u8 *entry;

    switch (g_mc_step) {
    case 0:
        D_0028ECE4 = 0xA;
        g_mc_step += 1;
        break;
    case 1:
        mc_card_present_poll(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 3:
            case 4:
                g_mc_step = 0x1E;
                break;
            default:
                g_mc_wait = 0xA;
                g_mc_step += 1;
                break;
            }
        } else {
            break;
        }
        break;
    case 2:
        if (sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_patterns[g_mc_file], 0, 5, g_mc_dir) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 0x14;
            break;
        }
        break;
    case 3:
        if (sceMcSync(1, 0, &sp5C) != 0) {
            ok = 1;
            if (sp5C <= 0) {
                g_mc_step = 0x14;
                break;
            }
            i = 0;
            off = 0;
            do {
                if (g_mc_file == 1) {
                    entry = (u8 *)(g_mc_dir + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY1") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (g_mc_file == 2) {
                    entry = (u8 *)(g_mc_dir + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY2") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (g_mc_file == 3) {
                    entry = (u8 *)(g_mc_dir + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY3") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (g_mc_file == 4) {
                    entry = (u8 *)(g_mc_dir + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY4") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (g_mc_file == 5) {
                    entry = (u8 *)(g_mc_dir + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY5") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (g_mc_file == 6) {
                    entry = (u8 *)(g_mc_dir + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY6") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (g_mc_file == 7) {
                    entry = (u8 *)(g_mc_dir + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY7") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (g_mc_file == 8) {
                    entry = (u8 *)(g_mc_dir + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY8") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (g_mc_file == 9) {
                    entry = (u8 *)(g_mc_dir + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY9") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (g_mc_file == 0xA) {
                    entry = (u8 *)(g_mc_dir + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY10") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                i += 1;
                off += 0x40;
            } while (i < 5);
            if (ok != 0) {
                g_mc_step = 0x25;
                break;
            }
            g_mc_step += 1;
            g_mc_wait = 0xA;
            break;
        }
        break;
    case 4:
        if (sceMcOpen(g_mc_port, g_mc_slot, g_mc_file_paths[g_mc_file], 3) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 0x14;
            break;
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &sp5C) != 0) {
            if (sp5C < 0) {
                g_mc_step = 0x14;
                break;
            }
            printf((const char *)"--file size[%d]--\n", D_0069F590[0]);
            g_mc_wait = 0xA;
            g_mc_fd = sp5C;
            g_mc_step += 1;
            break;
        }
        break;
    case 6:
        if (sceMcRead(g_mc_fd, g_replay_slot_infos + ((g_mc_file - 1) << 0xA), 0x400) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 0x1E;
            break;
        }
        break;
    case 7:
        if (sceMcSync(1, 0, &sp5C) != 0) {
            if (sp5C < 0) {
                g_mc_step = 0x1E;
                break;
            }
            g_mc_step += 1;
            g_mc_wait = 0xA;
            break;
        }
        break;
    case 8:
        if (sceMcClose(g_mc_fd) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 0x1E;
            break;
        }
        break;
    case 9:
        if (sceMcSync(1, 0, &sp5C) != 0) {
            if (sp5C < 0) {
                g_mc_step = 0x1E;
                break;
            }
            g_mc_wait = 0xA;
            g_mc_step += 1;
            break;
        }
        break;
    case 10:
        off = g_mc_file - 1;
        ok = g_mc_file;
        D_006A0E40_as_Slot_a[off].state = 1;
        if (D_006A0E40_as_Slot_a[off].id == MAIN_OR_DEATH_LABEL(0xCB, 0x6E)) {
            printf("head load ok[%d]\n", ok);
        } else {
            D_006A0E40_as_Slot_a[off].state = 3;
            printf("--version err-[%d] [%d][%d]\n", ok, D_006A0E40_as_Slot_a[off].id, MAIN_OR_DEATH_LABEL(0xCB, 0x6E));
        }
        g_mc_step = 0;
        D_0028ED14 += 1;
        break;
    case 20:
        printf("file nasi[%d]\n", g_mc_file);
        g_mc_step = 0;
        D_0028ED14 += 1;
        break;
    case 30:
        printf("kaku load err[%d]\n", g_mc_file);
        g_mc_step = 0;
        D_0028ED14 = 0x1E;
        break;
    case 35:
        if (sceMcClose(g_mc_fd) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 0x1E;
            break;
        }
        break;
    case 36:
        if (sceMcSync(1, 0, &sp5C) != 0) {
            if (sp5C < 0) {
                g_mc_step = 0x1E;
                break;
            }
            printf("--hason[%d]\n", g_mc_file);
            *(s16 *)(g_replay_slot_infos + ((g_mc_file - 1) << 0xA)) = 2;
            g_mc_step = 0;
            D_0028ED14 += 1;
            break;
        }
        break;
    case 37:
        printf("--hason[%d]\n", g_mc_file);
        *(s16 *)(g_replay_slot_infos + ((g_mc_file - 1) << 0xA)) = 2;
        g_mc_step = 0;
        D_0028ED14 += 1;
        break;
    }
}


void mc_task_load_continue_ask(void) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 diff;
    s32 step;

    mc_title_draw();
    mc_message_draw(200, g_mc_msg_load_continue, 0, 20, 14, D_0028ED10, 100);
    switch (g_mc_step) {
    case 0:
        g_mc_choice = 1;
        g_mc_step += 1;
        D_0028ECA0 = 180;
        g_mc_cursor_x = 304;
    case 1:
        if (g_pad_trigger[2] & 0x20) {
            menu_sfx_play(2);
            g_mc_step = 0;
            if (g_mc_choice == 1) {
                g_mc_step = 3;
            } else {
                g_mc_task = 2;
            }
        } else {
            if ((g_mc_choice == 1) && (g_pad_trigger[2] & 0x8000)) {
                menu_sfx_play(1);
                g_mc_choice = 0;
                g_mc_cursor_target_x = 214;
                D_0028ECDC = 0;
            }
            if ((g_mc_choice == 0) && (g_pad_trigger[2] & 0x2000)) {
                menu_sfx_play(1);
                D_0028ECDC = 0;
                g_mc_choice = 1;
                g_mc_cursor_target_x = 304;
            }
        }
        break;
    case 2:
        if (g_mc_cursor_target_x == g_mc_cursor_x) {
            g_mc_step = 1;
            break;
        }
        diff = g_mc_cursor_target_x - g_mc_cursor_x;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (g_mc_choice == 0) {
                step = -1;
            }
        }
        g_mc_cursor_x += step;
        break;
    case 3:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    }
    mc_choice_draw();
}


void mc_task_format_ask(void) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 diff;
    s32 step;

    mc_title_draw();
    if ((g_mc_step != 20) && (g_mc_step != 0)) {
        mc_message_draw(200, g_mc_msg_format_ask[D_0028ECE8], 0, 20, 14, D_0028ED10, 100);
        mc_choice_draw();
    }
    switch (g_mc_step) {
    case 0:
        g_mc_choice = 1;
        D_0028ECE4 = 3;
        D_0028ECA0 = 210;
        g_mc_cursor_x = 324;
        g_mc_step += 1;
        g_memcard_watch_delay = 0;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            g_mc_step += 1;
        }
        break;
    case 2:
        if (g_memcard_watch_delay > 60) {
            mc_card_present_poll(1);
            if (D_0028ECD0 == 0) {
                g_memcard_watch_delay = 0;
                if ((D_0028ECC8 == 4) || (D_0028ECC8 == 3)) {
                    g_mc_step = 20;
                    break;
                }
            }
        } else {
            g_memcard_watch_delay += 1;
        }
        if (g_pad_trigger[2] & 0x20) {
            menu_sfx_play(2);
            g_mc_step = 4;
            if (D_0028ECD0 == 0) {
                D_0028ECCC = 0;
            }
        } else {
            if ((g_mc_choice == 1) && (g_pad_trigger[2] & 0x8000)) {
                menu_sfx_play(1);
                g_mc_choice = 0;
                g_mc_cursor_target_x = 234;
                D_0028ECDC = 0;
            }
            if ((g_mc_choice == 0) && (g_pad_trigger[2] & 0x2000)) {
                menu_sfx_play(1);
                D_0028ECDC = 0;
                g_mc_choice = 1;
                g_mc_cursor_target_x = 324;
            }
        }
        break;
    case 3:
        if (g_mc_cursor_target_x == g_mc_cursor_x) {
            g_mc_step = 2;
            break;
        }
        diff = g_mc_cursor_target_x - g_mc_cursor_x;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (g_mc_choice == 0) {
                step = -1;
            }
        }
        g_mc_cursor_x += step;
        break;
    case 4:
        mc_card_present_poll(1);
        if (D_0028ECD0 == 0) {
            if ((D_0028ECC8 == 4) || (D_0028ECC8 == 3)) {
                g_mc_step = 20;
                break;
            }
            g_mc_step = 0;
            if (g_mc_choice == 1) {
                g_mc_task = 17;
            } else {
                g_mc_task += 1;
            }
        }
        break;
    case 20:
        mc_no_card_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 0;
            g_mc_task = 17;
        }
        break;
    }
}

s32 sceMcFormat(s32 arg0, s32 arg1);

void mc_task_format(void) {
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
#ifndef DDPDOJ_PC
    s32 sceMcGetInfo(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 *arg4);
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 result;

    mc_title_draw();
    if (g_mc_step < 6) {
        mc_busy_message_draw(3);
    }
    switch (g_mc_step) {
    case 0:
        D_0028ECE4 = 30;
        g_mc_step += 1;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            g_mc_wait = 10;
            g_mc_step += 1;
        }
        break;
    case 2:
        D_0028ECAC = sceMcGetInfo(g_mc_port, g_mc_slot, &D_0028ECB8, &D_0028ECB4, &D_0028ECB0);
        if (D_0028ECAC == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 10;
        }
        break;
    case 3:
        if (sceMcSync(1, 0, &result) != 0) {
            switch (result) {
            case 0:
                g_mc_step += 1;
                g_mc_wait = 10;
                break;
            default:
            case -1:
            case -2:
                g_mc_step = 10;
                break;
            }
        }
        break;
    case 4:
        if (sceMcFormat(g_mc_port, g_mc_slot) == 0) {
            g_mc_step += 1;
            break;
        }
        g_mc_wait -= 1;
        if (g_mc_wait == 0) {
            g_mc_step = 10;
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result == 0) {
                g_mc_step += 1;
            } else {
                g_mc_step = 10;
            }
        }
        break;
    case 6:
        mc_message_draw(200, g_mc_msg_format_done, 0, 20, 14, D_0028ED10, 100);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step += 1;
        }
        break;
    case 7:
        g_mc_step = 0;
        g_mc_task = 11;
        break;
    case 10:
        mc_message_draw(200, g_mc_msg_format_failed, 0, 20, 14, D_0028ED10, 100);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 7;
        }
        break;
    case 20:
        mc_no_card_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 7;
        }
        break;
    }
}


void mc_task_unformat_ask(void) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 diff;
    s32 step;

    if (g_mc_step != 20) {
        mc_message_draw(200, g_mc_msg_unformat_ask, 0, 20, 14, D_0028ED10, 100);
        mc_choice_draw();
    }
    switch (g_mc_step) {
    case 0:
        g_mc_choice = 1;
        D_0028ECA0 = 180;
        D_0028ECE4 = 3;
        g_mc_cursor_x = 222;
        g_memcard_watch_delay = 70;
        g_mc_step += 1;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            g_mc_step += 1;
        }
        break;
    case 2:
        if (g_pad_trigger[2] & 0x20) {
            menu_sfx_play(2);
            g_mc_step = 0;
            if (g_mc_choice == 1) {
                g_mc_step = 4;
            } else {
                g_mc_task = 2;
            }
        } else {
            if ((g_mc_choice == 1) && (g_pad_trigger[2] & 0x8000)) {
                menu_sfx_play(1);
                g_mc_choice = 0;
                g_mc_cursor_target_x = 144;
                D_0028ECDC = 0;
            }
            if ((g_mc_choice == 0) && (g_pad_trigger[2] & 0x2000)) {
                menu_sfx_play(1);
                D_0028ECDC = 0;
                g_mc_choice = 1;
                g_mc_cursor_target_x = 222;
            }
        }
        break;
    case 3:
        if (g_mc_cursor_target_x == g_mc_cursor_x) {
            g_mc_step = 2;
            break;
        }
        diff = g_mc_cursor_target_x - g_mc_cursor_x;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (g_mc_choice == 0) {
                step = -1;
            }
        }
        g_mc_cursor_x += step;
        break;
    case 4:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    }
}

s32 sceMcUnformat(s32 arg0, s32 arg1);

void mc_task_unformat(void) {
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 result;
    s32 status;

    mc_title_draw();
    switch (g_mc_step) {
    case 0:
        status = mc_card_info_wait(0);
        if ((status == 4) || (status == 3)) {
            g_mc_step = 20;
        } else {
            g_mc_step += 1;
        }
        break;
    case 1:
        if (sceMcUnformat(g_mc_port, g_mc_slot) == 0) {
            g_mc_step += 1;
        }
        break;
    case 2:
        mc_busy_message_draw(4);
        if (sceMcSync(1, 0, &result) != 0) {
            if (result == 0) {
                g_mc_step += 1;
            } else {
                g_mc_step = 10;
            }
        }
        break;
    case 3:
        mc_message_draw(200, g_mc_msg_unformat_done, 0, 20, 14, D_0028ED10, 100);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step += 1;
        }
        break;
    case 4:
        g_mc_step = 5;
        break;
    case 5:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    case 10:
        mc_message_draw(200, g_mc_msg_unformat_failed, 0, 20, 14, D_0028ED10, 100);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 4;
        }
        break;
    case 20:
        mc_no_card_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 4;
        }
        break;
    }
}
extern s32 mc_task_startup_check_state;
extern s32 mc_task_startup_check_state_2;
extern s32 mc_task_startup_check_state_3;
extern u8 mc_task_startup_check_state_4;
extern u8 mc_task_startup_check_state_5;
extern u8 mc_task_startup_check_state_6;
extern u8 mc_task_startup_check_state_7;
extern u8 D_0028ECF4;

void mc_task_startup_check(void) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 sceMcSync(s32, s32, s32 *);
    s32 sceMcGetDir(s32, s32, char *, s32, s32, void *);
    s32 result;
    s32 diff;
    s32 step;

    if ((g_mc_step == 3) || (g_mc_step == 4) || (g_mc_step == 30) || (g_mc_step == 31)) {
        mc_message_draw(120, g_mc_msg_start_no_card, 0, 20, 14, D_0028ED10, 100);
        mc_choice_draw();
    }
    if ((g_mc_step == 11) || (g_mc_step == 12) || (g_mc_step == 40) || (g_mc_step == 41)) {
        mc_message_draw(120, g_mc_msg_start_no_space, 0, 20, 14, D_0028ED10, 100);
        mc_message_draw(240, g_mc_msg_start_without_save, 0, 20, 14, D_0028ED10, 100);
        mc_choice_draw();
    }
    switch (g_mc_step) {
    case 0:
        D_0028ECE4 = 60;
        g_mc_step += 1;
        mc_task_startup_check_state = 0;
        break;
    case 1:
        mc_checking_message_draw();
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            g_mc_step += 1;
        }
        break;
    case 2:
        mc_checking_message_draw();
        g_mc_port = 0;
        g_mc_slot = 0;
        D_0028ECF4 = 0;
        mc_card_present_poll(0);
        if (D_0028ECD0 == 0) {
            if ((D_0028ECC8 == 3) || (D_0028ECC8 == 2)) {
                D_0028ECF4 |= 1;
            } else if (D_0028ECC8 == 1) {
                D_0028ECF4 |= 0x10;
            }
            if ((D_0028ECF4 & 0x10) == 0x10) {
                g_mc_step = 20;
            } else if ((D_0028ECF4 & 1) != 1) {
                g_mc_step = 50;
            } else {
                g_mc_choice = 1;
                g_memcard_watch_delay = 0;
                D_0028ECA0 = 232;
                g_mc_cursor_x = 324;
                g_mc_step += 1;
            }
        }
        break;
    case 3:
        if (g_memcard_watch_delay > 60) {
            g_mc_port = 0;
            g_mc_slot = 0;
            mc_card_present_poll(1);
            if (D_0028ECD0 == 0) {
                if (D_0028ECC8 == 4) {
                    g_mc_step = 0;
                    break;
                }
                g_memcard_watch_delay = 0;
            }
        } else {
            g_memcard_watch_delay += 1;
        }
        if (g_pad_trigger[2] & 0x20) {
            menu_sfx_play(2);
            if (D_0028ECD0 != 0) {
                g_mc_step = 30;
            } else {
                g_mc_step = 0;
                if (g_mc_choice == 0) {
                    g_mc_step = 5;
                }
            }
        } else {
            if ((g_mc_choice == 1) && (g_pad_trigger[2] & 0x8000)) {
                menu_sfx_play(1);
                g_mc_choice = 0;
                g_mc_cursor_target_x = 234;
                D_0028ECDC = 0;
            }
            if ((g_mc_choice == 0) && (g_pad_trigger[2] & 0x2000)) {
                menu_sfx_play(1);
                D_0028ECDC = 0;
                g_mc_choice = 1;
                g_mc_cursor_target_x = 324;
            }
        }
        break;
    case 4:
        if (g_mc_cursor_target_x == g_mc_cursor_x) {
            g_mc_step = 3;
        }
        diff = g_mc_cursor_target_x - g_mc_cursor_x;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (g_mc_choice == 0) {
                step = -1;
            }
        }
        g_mc_cursor_x += step;
        break;
    case 5:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    case 0x32:
        mc_checking_message_draw();
        mc_task_startup_check_state_3 = 0;
        mc_task_startup_check_state_4 = 0;
        mc_task_startup_check_state_5 = 0;
        mc_task_startup_check_state_6 = 0;
        mc_task_startup_check_state_7 = 0;
        mc_task_startup_check_state = 0;
        mc_task_startup_check_state_2 = 0;
        sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_names[0], 0, 99, g_mc_dir);
        g_mc_step += 1;
        break;
    case 0x33:
        mc_checking_message_draw();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                mc_task_startup_check_state_5 = 1;
                mc_task_startup_check_state_3 += g_mc_needed_kilobytes[0];
            } else {
                mc_task_startup_check_state = 1;
            }
            g_mc_step += 1;
        }
        break;
    case 0x34:
        mc_checking_message_draw();
        sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_names[1], 0, 99, g_mc_dir);
        g_mc_step += 1;
        break;
    case 0x35:
        mc_checking_message_draw();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                mc_task_startup_check_state_2 += 1;
            }
            g_mc_step += 1;
        }
        break;
    case 0x36:
        mc_checking_message_draw();
        sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_names[2], 0, 99, g_mc_dir);
        g_mc_step += 1;
        break;
    case 0x37:
        mc_checking_message_draw();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                mc_task_startup_check_state_2 += 1;
            }
            g_mc_step += 1;
        }
        break;
    case 0x38:
        mc_checking_message_draw();
        sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_names[3], 0, 99, g_mc_dir);
        g_mc_step += 1;
        break;
    case 0x39:
        mc_checking_message_draw();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                mc_task_startup_check_state_2 += 1;
            }
            g_mc_step += 1;
        }
        break;
    case 0x3A:
        mc_checking_message_draw();
        sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_names[4], 0, 99, g_mc_dir);
        g_mc_step += 1;
        break;
    case 0x3B:
        mc_checking_message_draw();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                mc_task_startup_check_state_2 += 1;
            }
            g_mc_step += 1;
        }
        break;
    case 0x3C:
        mc_checking_message_draw();
        sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_names[5], 0, 99, g_mc_dir);
        g_mc_step += 1;
        break;
    case 0x3D:
        mc_checking_message_draw();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                mc_task_startup_check_state_2 += 1;
            }
            g_mc_step += 1;
        }
        break;
    case 0x3E:
        mc_checking_message_draw();
        sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_names[6], 0, 99, g_mc_dir);
        g_mc_step += 1;
        break;
    case 0x3F:
        mc_checking_message_draw();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                mc_task_startup_check_state_2 += 1;
            }
            g_mc_step += 1;
        }
        break;
    case 0x40:
        mc_checking_message_draw();
        sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_names[7], 0, 99, g_mc_dir);
        g_mc_step += 1;
        break;
    case 0x41:
        mc_checking_message_draw();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                mc_task_startup_check_state_2 += 1;
            }
            g_mc_step += 1;
        }
        break;
    case 0x42:
        mc_checking_message_draw();
        sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_names[8], 0, 99, g_mc_dir);
        g_mc_step += 1;
        break;
    case 0x43:
        mc_checking_message_draw();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                mc_task_startup_check_state_2 += 1;
            }
            g_mc_step += 1;
        }
        break;
    case 0x44:
        mc_checking_message_draw();
        sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_names[9], 0, 99, g_mc_dir);
        g_mc_step += 1;
        break;
    case 0x45:
        mc_checking_message_draw();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                mc_task_startup_check_state_2 += 1;
            }
            g_mc_step += 1;
        }
        break;
    case 0x46:
        mc_checking_message_draw();
        sceMcGetDir(g_mc_port, g_mc_slot, g_mc_dir_names[10], 0, 99, g_mc_dir);
        g_mc_step += 1;
        break;
    case 0x47:
        mc_checking_message_draw();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                mc_task_startup_check_state_2 += 1;
            }
            printf("free[%d] size[%d] nasi[%d]\n", D_0028ECB4, mc_task_startup_check_state_3, mc_task_startup_check_state_2);
            if ((mc_task_startup_check_state_3 != 0) && (D_0028ECB4 < mc_task_startup_check_state_3)) {
                D_0028ECF4 = 0;
                g_mc_step = 0x50;
            } else {
                D_0028ECF4 |= 4;
                g_mc_step = 0x50;
            }
        }
        break;
    case 0x50:
        g_mc_port = 0;
        g_mc_slot = 0;
        mc_card_present_poll(1);
        if (D_0028ECD0 == 0) {
            if ((D_0028ECC8 == 2) || (D_0028ECC8 == 3) || (D_0028ECC8 == 4) || (D_0028ECC8 == 1)) {
                g_mc_step = 0;
            } else {
                g_mc_step = 10;
            }
        }
        break;
    case 10:
        if (D_0028ECF4 & 0xC) {
            g_mc_step = 20;
            break;
        }
        g_memcard_watch_delay = 0;
        g_mc_step += 1;
        g_mc_choice = 1;
        D_0028ECA0 = 256;
        g_mc_cursor_x = 324;
        break;
    case 11:
        if (g_memcard_watch_delay == 71) {
            g_memcard_watch_delay = 0;
        } else if (g_memcard_watch_delay > 60) {
            g_mc_port = 0;
            g_mc_slot = 0;
            mc_card_present_poll(1);
            if (D_0028ECD0 == 0) {
                if (D_0028ECC8 == 4) {
                    g_mc_step = 0;
                    break;
                }
                g_memcard_watch_delay = 71;
            }
        } else {
            g_memcard_watch_delay += 1;
        }
        if (g_pad_trigger[2] & 0x20) {
            menu_sfx_play(2);
            if (D_0028ECD0 != 0) {
                g_mc_step = 40;
            } else {
                g_mc_step = 0;
                if (g_mc_choice == 0) {
                    g_mc_step = 21;
                }
            }
        } else {
            if ((g_mc_choice == 1) && (g_pad_trigger[2] & 0x8000)) {
                menu_sfx_play(1);
                g_mc_choice = 0;
                g_mc_cursor_target_x = 234;
                D_0028ECDC = 0;
            }
            if ((g_mc_choice == 0) && (g_pad_trigger[2] & 0x2000)) {
                menu_sfx_play(1);
                D_0028ECDC = 0;
                g_mc_choice = 1;
                g_mc_cursor_target_x = 324;
            }
        }
        break;
    case 12:
        if (g_mc_cursor_target_x == g_mc_cursor_x) {
            g_mc_step = 11;
            break;
        }
        diff = g_mc_cursor_target_x - g_mc_cursor_x;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (g_mc_choice == 0) {
                step = -1;
            }
        }
        g_mc_cursor_x += step;
        break;
    case 20:
        g_mc_step = 21;
        break;
    case 21:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ED18 = 2;
            g_mc_step = 0;
            if (mc_task_startup_check_state != 0) {
                D_0028ECF4 |= 4;
            }
        }
        break;
    case 30:
        mc_card_present_poll(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 == 4) {
                g_mc_step = 0;
                break;
            }
            g_memcard_watch_delay = 0;
            g_mc_step = 0;
            if (g_mc_choice == 0) {
                g_mc_step = 5;
            }
        }
        break;
    case 40:
        mc_card_present_poll(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 == 4) {
                g_mc_step = 0;
                break;
            }
            g_memcard_watch_delay = 0;
            g_mc_step = 0;
            if (g_mc_choice == 0) {
                g_mc_step = 21;
            }
        }
        break;
    case 100:
        mc_not_formatted_message_draw();
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 21;
        }
        break;
    }
}


void mc_task_no_system_data(void) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    mc_title_draw();
    switch (g_mc_step) {
    case 0:
        D_0028ECC4 = 0;
        g_mc_step += 1;
        g_memcard_watch_delay = 0;
        g_mc_wait = 60;
        break;
    case 1:
        mc_checking_message_draw();
        if (g_mc_wait != 0) {
            g_mc_wait -= 1;
        } else {
            g_mc_step += 1;
        }
        break;
    case 2:
        mc_checking_message_draw();
        mc_card_present_poll(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 2:
            case 3:
            case 4:
                menu_sfx_play(11);
                g_mc_step = 20;
                break;
            default:
                D_0028ECC4 = 1;
                g_mc_step += 1;
                break;
            }
        }
        break;
    case 3:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    case 20:
        if (g_memcard_watch_delay > 60) {
            g_mc_port = 0;
            g_mc_slot = 0;
            mc_card_present_poll(1);
            if (D_0028ECD0 == 0) {
                if (D_0028ECC8 == 4) {
                    g_mc_step = 0;
                    break;
                }
                g_memcard_watch_delay = 0;
            }
        } else {
            g_memcard_watch_delay += 1;
        }
        mc_message_draw(200, g_mc_msg_no_card_no_system_data, 0, 20, 14, D_0028ED10, 100);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step = 3;
        }
        break;
    }
}


s32 memcard_watch_update(void) {
    switch (g_memcard_watch_step) {
    case 0:
        D_0028ED0C = 0;
        g_memcard_watch_step += 1;
        break;
    case 1:
        mc_watch_check_begin();
        if (D_0028ED0C != 0) {
            D_0028ED0C = 0;
            g_memcard_watch_delay = 30;
            g_memcard_watch_step += 1;
        }
        break;
    case 2:
        g_memcard_watch_delay -= 1;
        if ((s32)g_memcard_watch_delay <= 0) {
            g_memcard_watch_step += 1;
        }
        break;
    case 3:
        mc_card_present_poll(1);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 4:
                g_memcard_watch_step = 0;
                break;
            case 1:
            case 2:
            case 3:
                replay_slot_infos_clear();
            default:
                g_memcard_watch_delay = 30;
                g_memcard_watch_step = 2;
                break;
            }
        }
        break;
    }
    return g_memcard_watch_step >= 2;
}

void memcard_watch_recheck(void) {
    D_0028ED0C = 0;
    g_memcard_watch_step = 2;
    g_memcard_watch_delay = 0x1E;
}



void mc_confirm_button_draw(void)
{
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 displayValue = (*(u16 *)&D_0028ED10);
    char *displayData = g_mc_msg_confirm_button;

    mc_message_draw(0x168, displayData, 0, 0x14, 0xE, displayValue, 0x64);
    if (g_pad_trigger[2] & 0x20) {
        menu_sfx_play(2);
    }
}

void overlay_queue_sjis_vertical(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth);

void mc_text_draw_vertical(s16 x, s16 y, char *text, u16 page, u16 w, u16 h, u16 alpha, u16 depth) {
    overlay_queue_sjis_vertical(0x1C0 - y, x, text, page, w, h, alpha, depth);
}

#ifndef DDPDOJ_PC
extern s32 sprintf(char *buf, const char *format, ...);
#endif
extern char *g_pad_dma_buf;

void mc_choice_draw(void) {
    s32 shrink;
    s32 color;
    s32 w;
    s32 h;

    if (D_0028ECDC < 4) {
        D_0028ECDC += 2;
    }
    color = D_0028ED10;
    shrink = 0;
    if (D_0028ECDC != 0) {
        shrink = (s32)(D_0028ECDC & 0xFF) / 2;
    }
    w = (D_0028ECDC & 0xFF) + 20;
    h = (D_0028ECDC & 0xFF) + 14;
    if (g_mc_choice == 0) {
        sprintf(g_pad_dma_buf, SJIS("はい"));
        mc_text_draw_vertical(48 - shrink, 364 - shrink, g_pad_dma_buf, 4, w, h, color, 100);
        sprintf(g_pad_dma_buf, SJIS("／"));
        mc_text_draw_vertical(104, 364, g_pad_dma_buf, 0, 20, 14, color, 100);
        sprintf(g_pad_dma_buf, SJIS("いいえ"));
        mc_text_draw_vertical(136, 364, g_pad_dma_buf, 0, 20, 14, color, 100);
    } else {
        sprintf(g_pad_dma_buf, SJIS("はい"));
        mc_text_draw_vertical(48, 364, g_pad_dma_buf, 0, 20, 14, color, 100);
        sprintf(g_pad_dma_buf, SJIS("／"));
        mc_text_draw_vertical(104, 364, g_pad_dma_buf, 0, 20, 14, color, 100);
        sprintf(g_pad_dma_buf, SJIS("いいえ"));
        mc_text_draw_vertical(136 - shrink, 364 - shrink, g_pad_dma_buf, 4, w, h, color, 100);
    }
}


void mc_busy_message_draw(s32 arg0) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    if (g_mc_file == 0) {
        mc_message_draw(200, g_mc_msg_busy_game[arg0], 0, 20, 14, D_0028ED10, 100);
    } else {
        mc_message_draw(200, g_mc_msg_busy_replay[arg0], 0, 20, 14, D_0028ED10, 100);
    }
    mc_message_draw(300, g_mc_msg_do_not_remove, 0, 20, 14, D_0028ED10, 100);
}



void mc_no_card_message_draw(void) {
#ifndef DDPDOJ_PC
    void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    mc_message_draw(0xC8, g_mc_msg_no_card[D_0028ECE8], 0, 0x14, 0xE, (*(u16 *)&D_0028ED10), 0x64);
}

void mc_checking_message_draw(void) {
#ifndef DDPDOJ_PC
    void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 t = (*(u16 *)&D_0028ED10);
    mc_message_draw(0xC8, g_mc_msg_checking, 0, 0x14, 0xE, t, 0x64);
}

void mc_damaged_message_draw(s32 arg0, s32 arg1) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    mc_message_draw(0xB4, g_mc_msg_damaged[arg1], 0, 0x14, 14, (*(u16 *)&D_0028ED10), 100);
    if (arg0 == 1) {
        s32 t = (*(u16 *)&D_0028ED10);
        mc_message_draw(300, g_mc_msg_delete_to_save, 0, 0x14, 14, t, 100);
    }
}

void mc_save_failed_message_draw(void) {
#ifndef DDPDOJ_PC
    void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 t = (*(u16 *)&D_0028ED10);
    mc_message_draw(0xC8, g_mc_msg_save_failed, 0, 0x14, 0xE, t, 0x64);
}


void mc_no_data_message_draw(s32 arg0) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    mc_message_draw(0xC8, g_mc_msg_on_card[D_0028ECE8], 0, 0x14, 14, (*(u16 *)&D_0028ED10), 100);
    mc_message_draw(0xF0, g_mc_msg_no_data[arg0], 0, 0x14, 14, (*(u16 *)&D_0028ED10), 100);
}


void mc_load_ask_message_draw(s32 index) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    mc_message_draw(0xC8, g_mc_msg_load_ask[index], 0, 0x14, 0xE, (*(u16 *)&D_0028ED10), 0x64);
}



void mc_load_done_message_draw(void) {
#ifndef DDPDOJ_PC
    void mc_message_draw(s32, char *, s32, s32, s32, s32, s32);
#endif
    mc_message_draw(0xC8, g_mc_msg_load_done, 0, 0x14, 0xE, (*(u16 *)&D_0028ED10), 0x64);
}



void mc_load_failed_message_draw(void) {
#ifndef DDPDOJ_PC
    void mc_message_draw(s32, char *, s32, s32, s32, s32, s32);
#endif
    mc_message_draw(0xC8, g_mc_msg_load_failed, 0, 0x14, 0xE, (*(u16 *)&D_0028ED10), 0x64);
}

void mc_not_formatted_message_draw(void) {
#ifndef DDPDOJ_PC
    void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s32 t = (*(u16 *)&D_0028ED10);
    mc_message_draw(0xC8, g_mc_msg_not_formatted, 0, 0x14, 0xE, t, 0x64);
}



void mc_overwrite_ask_message_draw(s32 index) {
#ifndef DDPDOJ_PC
    void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    mc_message_draw(0xC8, g_mc_msg_overwrite_ask[index], 0, 0x14, 0xE, (*(u16 *)&D_0028ED10), 0x64);
}


void mc_save_to_card_ask_message_draw(s32 index) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    mc_message_draw(0xC8, g_mc_msg_save_to_card_ask[index], 0, 0x14, 0xE, (*(u16 *)&D_0028ED10), 0x64);
}

#ifndef DDPDOJ_PC
s32 sprintf(char *buf, const char *format, ...);
#endif

void mc_no_space_message_draw(s32 arg0) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#define MC_PROMPT_BUFFER ((char *)(*(s32 *)&g_pad_dma_buf))
#else
#define MC_PROMPT_BUFFER g_pad_dma_buf
#endif
    mc_message_draw(160, g_mc_msg_no_space, 0, 20, 14, D_0028ED10, 100);
    mc_message_draw(220, g_mc_msg_to_save[arg0], 0, 20, 14, D_0028ED10, 100);
    mc_message_draw(260, g_mc_msg_needed_space[D_0028ECE8], 0, 20, 14, D_0028ED10, 100);
    if (arg0 == 0) {
        sprintf(MC_PROMPT_BUFFER, SJIS("　　　　 %2d "), g_mc_needed_kilobytes[g_mc_file * 2]);
    } else {
        sprintf(MC_PROMPT_BUFFER, SJIS("　　　　%3d "), g_mc_needed_kilobytes[g_mc_file * 2]);
    }
    mc_message_draw(300, MC_PROMPT_BUFFER, 0, 20, 14, D_0028ED10, 100);
#undef MC_PROMPT_BUFFER
}


s32 mc_save_ask_message_draw(s32 index) {
#ifdef DDPDOJ_PC
    mc_message_draw(0xC8, g_mc_msg_save_ask[index], 0, 0x14, 0xE, (u16)D_0028ED10, 0x64);
    return 0;
#else
    s32 mc_message_draw(s32, char *, s32, s32, s32, s32, s32);
    return mc_message_draw(0xC8, g_mc_msg_save_ask[index], 0, 0x14, 0xE, (*(u16 *)&D_0028ED10), 0x64);
#endif
}

typedef struct {
    u16 a00[5];
    u16 a0A[5];
    u16 a14[5];
    u16 a1E[5];
    u16 a28[5];
    u8 pad32[2];
    s32 a34[15];
    s32 a70[5];
    u16 a84[5];
    u16 a8E[5];
    u16 a98[5];
    u16 aA2[5];
    u16 aAC[5];
    u16 aB6[5];
    u16 aC0[5];
    u8 padCA[2];
    s32 aCC[15];
    s32 a108[5];
    u16 a11C[5];
    u16 a126[5];
    u8 a130[5][30];
    u8 a1C6[5][30];
    u8 b25C;
    u8 b25D;
    u8 b25E;
    u8 b25F;
    u8 b260;
    u8 b261;
    u8 b262;
    u8 b263;
    u8 b264;
    u8 b265;
    u8 b266;
    u8 b267;
    u16 h268;
    u8 b26A;
    u8 b26B;
    u8 a26C[2][4];
    s8 b274;
    s8 b275;
    u8 b276;
    u8 pad277;
    u16 h278;
    u8 pad27A[2];
    s32 a27C[10][4][5];
    u8 b59C;
    u8 b59D;
    u8 b59E;
    u8 b59F;
    u8 b5A0;
} SaveBlock;

#ifdef DDPDOJ_PC
_Static_assert(offsetof(SaveBlock, a34) == 0x34, "PS2 ranking layout");
_Static_assert(offsetof(SaveBlock, a26C) == 0x26C, "PS2 button mapping layout");
_Static_assert(offsetof(SaveBlock, a27C) == 0x27C, "PS2 simulation settings layout");
_Static_assert(offsetof(SaveBlock, b5A0) == 0x5A0, "PS2 options layout");
_Static_assert(sizeof(SaveBlock) <= 0x9A8, "Settings fit in the PS2 save payload");
static u8 settings_snapshot[0x9A8];
#endif

extern u8 g_game_mode;
extern u16 g_stored_ranking_score_tops[5];
extern u16 g_stored_ranking_continues[5];
extern u16 g_stored_ranking_hits[5];
extern u16 g_stored_ranking_power_styles[5];
extern u16 g_stored_ranking_ship_types[5];
extern u16 g_stored_ranking_stages[5];
extern u16 g_stored_ranking_loops[5];
extern s32 g_stored_ranking_names[15];
extern s32 g_stored_ranking_scores[5];
extern s8 g_display_offset_y;
extern s8 g_display_offset_x;
extern u8 D_0028E258;
extern u8 g_p1_btn_map_a[2][4];
extern u8 D_0028E278;
extern u8 g_pad_vib_enabled;
extern u8 g_stage_map_enabled;
extern u8 D_0028E2D8;
extern u8 g_screen_wide;
extern u8 g_bgm_alternate_set;
extern u16 D_0028E300;
extern u16 D_0028E32C;
extern u8 D_0028E354;
extern u8 D_0028E358;
extern u8 g_pad_vib_state_p2;
extern u8 g_pad_vib_state_p1;
extern u8 D_0028E37C;
extern u8 g_setting_rapid_fire;
extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u8 g_setting_difficulty;
extern u8 g_setting_chute_type;
extern u8 g_setting_demo_sound;
extern u8 g_setting_continue;
extern u8 g_setting_coin_mode;
extern u8 g_stored_ranking_texts[5][30];
extern u8 g_death_label_ranking_texts[5][30];
extern u16 g_death_label_ranking_score_tops[5];
extern u16 g_death_label_ranking_continues[5];
extern u16 g_death_label_ranking_hits[5];
extern u16 g_death_label_ranking_power_styles[5];
extern u16 g_death_label_ranking_ship_types[5];
extern u16 g_death_label_ranking_stages[5];
extern u16 g_death_label_ranking_loops[5];
extern s32 g_death_label_ranking_names[15];
extern s32 g_death_label_ranking_scores[5];
extern u16 g_ranking_score_tops[5];
extern u16 g_ranking_continues[5];
extern u16 g_ranking_hits[5];
extern u16 g_ranking_power_styles[5];
extern u16 g_ranking_ship_types[5];
extern u16 g_ranking_stages[5];
extern u16 g_ranking_loops[5];
extern s32 g_ranking_names[15];
extern s32 g_ranking_scores[5];
extern s32 D_00684CF0[10][4][5];

void save_block_from_settings(void) {
#ifdef DDPDOJ_PC
    SaveBlock g_mc_save_buf_as_SaveBlock;
    memcpy(&g_mc_save_buf_as_SaveBlock, g_mc_save_buf, sizeof(g_mc_save_buf_as_SaveBlock));
#else
    extern SaveBlock g_mc_save_buf_as_SaveBlock;
#endif
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 5; i++) {
        g_mc_save_buf_as_SaveBlock.a00[i] = g_ranking_ship_types[i];
        g_mc_save_buf_as_SaveBlock.a0A[i] = g_ranking_power_styles[i];
        g_mc_save_buf_as_SaveBlock.a14[i] = g_ranking_loops[i];
        g_mc_save_buf_as_SaveBlock.a1E[i] = g_ranking_stages[i];
        g_mc_save_buf_as_SaveBlock.a28[i] = g_ranking_hits[i];
        g_mc_save_buf_as_SaveBlock.a70[i] = g_ranking_scores[i];
        g_mc_save_buf_as_SaveBlock.a84[i] = g_ranking_score_tops[i];
        g_mc_save_buf_as_SaveBlock.a8E[i] = g_ranking_continues[i];
        g_mc_save_buf_as_SaveBlock.a98[i] = g_death_label_ranking_ship_types[i];
        g_mc_save_buf_as_SaveBlock.aA2[i] = g_death_label_ranking_power_styles[i];
        g_mc_save_buf_as_SaveBlock.aAC[i] = g_death_label_ranking_loops[i];
        g_mc_save_buf_as_SaveBlock.aB6[i] = g_death_label_ranking_stages[i];
        g_mc_save_buf_as_SaveBlock.aC0[i] = g_death_label_ranking_hits[i];
        g_mc_save_buf_as_SaveBlock.a108[i] = g_death_label_ranking_scores[i];
        g_mc_save_buf_as_SaveBlock.a11C[i] = g_death_label_ranking_score_tops[i];
        g_mc_save_buf_as_SaveBlock.a126[i] = g_death_label_ranking_continues[i];
    }
    for (i = 0; i < 15; i++) {
        g_mc_save_buf_as_SaveBlock.a34[i] = g_ranking_names[i];
        g_mc_save_buf_as_SaveBlock.aCC[i] = g_death_label_ranking_names[i];
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 30; j++) {
            g_mc_save_buf_as_SaveBlock.a130[i][j] = g_death_label_ranking_texts[i][j];
            g_mc_save_buf_as_SaveBlock.a1C6[i][j] = g_stored_ranking_texts[i][j];
        }
    }
    if (g_game_mode == 2) {
        for (i = 0; i < 5; i++) {
            g_mc_save_buf_as_SaveBlock.a00[i] = g_stored_ranking_ship_types[i];
            g_mc_save_buf_as_SaveBlock.a0A[i] = g_stored_ranking_power_styles[i];
            g_mc_save_buf_as_SaveBlock.a14[i] = g_stored_ranking_loops[i];
            g_mc_save_buf_as_SaveBlock.a1E[i] = g_stored_ranking_stages[i];
            g_mc_save_buf_as_SaveBlock.a28[i] = g_stored_ranking_hits[i];
            g_mc_save_buf_as_SaveBlock.a70[i] = g_stored_ranking_scores[i];
            g_mc_save_buf_as_SaveBlock.a84[i] = g_stored_ranking_score_tops[i];
            g_mc_save_buf_as_SaveBlock.a8E[i] = g_stored_ranking_continues[i];
            g_mc_save_buf_as_SaveBlock.a98[i] = g_ranking_ship_types[i];
            g_mc_save_buf_as_SaveBlock.aA2[i] = g_ranking_power_styles[i];
            g_mc_save_buf_as_SaveBlock.aAC[i] = g_ranking_loops[i];
            g_mc_save_buf_as_SaveBlock.aB6[i] = g_ranking_stages[i];
            g_mc_save_buf_as_SaveBlock.aC0[i] = g_ranking_hits[i];
            g_mc_save_buf_as_SaveBlock.a108[i] = g_ranking_scores[i];
            g_mc_save_buf_as_SaveBlock.a11C[i] = g_ranking_score_tops[i];
            g_mc_save_buf_as_SaveBlock.a126[i] = g_ranking_continues[i];
        }
        for (i = 0; i < 15; i++) {
            g_mc_save_buf_as_SaveBlock.a34[i] = g_stored_ranking_names[i];
            g_mc_save_buf_as_SaveBlock.aCC[i] = g_ranking_names[i];
        }
    }
    g_mc_save_buf_as_SaveBlock.b25C = g_setting_coin_mode;
    g_mc_save_buf_as_SaveBlock.b25D = g_setting_continue;
    g_mc_save_buf_as_SaveBlock.b25E = g_setting_demo_sound;
    g_mc_save_buf_as_SaveBlock.b25F = g_setting_chute_type;
    g_mc_save_buf_as_SaveBlock.b260 = D_0028E358;
    g_mc_save_buf_as_SaveBlock.b261 = g_setting_difficulty;
    g_mc_save_buf_as_SaveBlock.b262 = g_setting_extend;
    g_mc_save_buf_as_SaveBlock.b263 = g_setting_ship_stock;
    g_mc_save_buf_as_SaveBlock.b264 = g_setting_rapid_fire;
    g_mc_save_buf_as_SaveBlock.b265 = D_0028E37C;
    g_mc_save_buf_as_SaveBlock.b266 = g_pad_vib_state_p1;
    g_mc_save_buf_as_SaveBlock.b267 = g_pad_vib_state_p2;
    g_mc_save_buf_as_SaveBlock.h268 = D_0028E32C;
    g_mc_save_buf_as_SaveBlock.b26A = g_pad_vib_enabled;
    g_mc_save_buf_as_SaveBlock.b26B = D_0028E278;
    g_mc_save_buf_as_SaveBlock.b274 = g_display_offset_x;
    g_mc_save_buf_as_SaveBlock.b275 = g_display_offset_y;
    g_mc_save_buf_as_SaveBlock.b276 = D_0028E258;
    g_mc_save_buf_as_SaveBlock.h278 = D_0028E300;
    g_mc_save_buf_as_SaveBlock.b59C = g_bgm_alternate_set;
    g_mc_save_buf_as_SaveBlock.b59D = g_screen_wide;
    g_mc_save_buf_as_SaveBlock.b59E = D_0028E2D8;
    g_mc_save_buf_as_SaveBlock.b59F = D_0028E354;
    g_mc_save_buf_as_SaveBlock.b5A0 = g_stage_map_enabled;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                g_mc_save_buf_as_SaveBlock.a27C[i][j][k] = D_00684CF0[i][j][k];
            }
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            g_mc_save_buf_as_SaveBlock.a26C[i][j] = g_p1_btn_map_a[i][j];
        }
    }
#ifdef DDPDOJ_PC
    memcpy(g_mc_save_buf, &g_mc_save_buf_as_SaveBlock, sizeof(g_mc_save_buf_as_SaveBlock));
#endif
}

typedef struct {
    u16 a00[5];
    u16 a0A[5];
    u16 a14[5];
    u16 a1E[5];
    u16 a28[5];
    u8 pad32[2];
    s32 a34[15];
    s32 a70[5];
    u16 a84[5];
    u16 a8E[5];
    u16 a98[5];
    u16 aA2[5];
    u16 aAC[5];
    u16 aB6[5];
    u16 aC0[5];
    u8 padCA[2];
    s32 aCC[15];
    s32 a108[5];
    u16 a11C[5];
    u16 a126[5];
    u8 a130[5][30];
    u8 a1C6[5][30];
    u8 b25C;
    u8 b25D;
    u8 b25E;
    u8 b25F;
    u8 b260;
    u8 b261;
    u8 b262;
    u8 b263;
    u8 b264;
    u8 b265;
    u8 b266;
    u8 b267;
    u16 h268;
    u8 b26A;
    u8 b26B;
    u8 a26C[2][4];
    s8 b274;
    s8 b275;
    s8 b276;
    u8 pad277;
    s16 h278;
    u8 pad27A[2];
    s32 a27C[10][4][5];
    s8 b59C;
    s8 b59D;
    s8 b59E;
    s8 b59F;
    s8 b5A0;
} SaveBlock2;

#ifdef DDPDOJ_PC
_Static_assert(sizeof(SaveBlock2) == sizeof(SaveBlock), "PS2 save read and write layouts agree");
#endif

extern void menu_values_from_settings(void);

void save_block_to_settings(void) {
#ifdef DDPDOJ_PC
    SaveBlock2 g_mc_save_buf_as_SaveBlock;
    memcpy(&g_mc_save_buf_as_SaveBlock, g_mc_save_buf, sizeof(g_mc_save_buf_as_SaveBlock));
#else
    extern SaveBlock2 g_mc_save_buf_as_SaveBlock;
#endif
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 5; i++) {
        g_ranking_ship_types[i] = g_mc_save_buf_as_SaveBlock.a00[i];
        g_ranking_power_styles[i] = g_mc_save_buf_as_SaveBlock.a0A[i];
        g_ranking_loops[i] = g_mc_save_buf_as_SaveBlock.a14[i];
        g_ranking_stages[i] = g_mc_save_buf_as_SaveBlock.a1E[i];
        g_ranking_hits[i] = g_mc_save_buf_as_SaveBlock.a28[i];
        g_ranking_scores[i] = g_mc_save_buf_as_SaveBlock.a70[i];
        g_ranking_score_tops[i] = g_mc_save_buf_as_SaveBlock.a84[i];
        g_ranking_continues[i] = g_mc_save_buf_as_SaveBlock.a8E[i];
        g_stored_ranking_ship_types[i] = g_mc_save_buf_as_SaveBlock.a00[i];
        g_stored_ranking_power_styles[i] = g_mc_save_buf_as_SaveBlock.a0A[i];
        g_stored_ranking_loops[i] = g_mc_save_buf_as_SaveBlock.a14[i];
        g_stored_ranking_stages[i] = g_mc_save_buf_as_SaveBlock.a1E[i];
        g_stored_ranking_hits[i] = g_mc_save_buf_as_SaveBlock.a28[i];
        g_stored_ranking_scores[i] = g_mc_save_buf_as_SaveBlock.a70[i];
        g_stored_ranking_score_tops[i] = g_mc_save_buf_as_SaveBlock.a84[i];
        g_stored_ranking_continues[i] = g_mc_save_buf_as_SaveBlock.a8E[i];
        g_death_label_ranking_ship_types[i] = g_mc_save_buf_as_SaveBlock.a98[i];
        g_death_label_ranking_power_styles[i] = g_mc_save_buf_as_SaveBlock.aA2[i];
        g_death_label_ranking_loops[i] = g_mc_save_buf_as_SaveBlock.aAC[i];
        g_death_label_ranking_stages[i] = g_mc_save_buf_as_SaveBlock.aB6[i];
        g_death_label_ranking_hits[i] = g_mc_save_buf_as_SaveBlock.aC0[i];
        g_death_label_ranking_scores[i] = g_mc_save_buf_as_SaveBlock.a108[i];
        g_death_label_ranking_score_tops[i] = g_mc_save_buf_as_SaveBlock.a11C[i];
        g_death_label_ranking_continues[i] = g_mc_save_buf_as_SaveBlock.a126[i];
    }
    for (i = 0; i < 15; i++) {
        g_ranking_names[i] = g_mc_save_buf_as_SaveBlock.a34[i];
        g_death_label_ranking_names[i] = g_mc_save_buf_as_SaveBlock.aCC[i];
        g_stored_ranking_names[i] = g_mc_save_buf_as_SaveBlock.a34[i];
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 30; j++) {
            g_death_label_ranking_texts[i][j] = g_mc_save_buf_as_SaveBlock.a130[i][j];
            g_stored_ranking_texts[i][j] = g_mc_save_buf_as_SaveBlock.a1C6[i][j];
        }
    }
    if (g_game_mode == 2) {
        for (i = 0; i < 5; i++) {
            g_ranking_ship_types[i] = g_mc_save_buf_as_SaveBlock.a98[i];
            g_ranking_power_styles[i] = g_mc_save_buf_as_SaveBlock.aA2[i];
            g_ranking_loops[i] = g_mc_save_buf_as_SaveBlock.aAC[i];
            g_ranking_stages[i] = g_mc_save_buf_as_SaveBlock.aB6[i];
            g_ranking_hits[i] = g_mc_save_buf_as_SaveBlock.aC0[i];
            g_ranking_scores[i] = g_mc_save_buf_as_SaveBlock.a108[i];
            g_ranking_score_tops[i] = g_mc_save_buf_as_SaveBlock.a11C[i];
            g_ranking_continues[i] = g_mc_save_buf_as_SaveBlock.a126[i];
        }
        for (i = 0; i < 15; i++) {
            g_ranking_names[i] = g_mc_save_buf_as_SaveBlock.aCC[i];
        }
    }
    g_setting_coin_mode = g_mc_save_buf_as_SaveBlock.b25C;
    g_setting_continue = g_mc_save_buf_as_SaveBlock.b25D;
    g_setting_demo_sound = g_mc_save_buf_as_SaveBlock.b25E;
    g_setting_chute_type = g_mc_save_buf_as_SaveBlock.b25F;
    D_0028E358 = g_mc_save_buf_as_SaveBlock.b260;
    g_setting_difficulty = g_mc_save_buf_as_SaveBlock.b261;
    g_setting_extend = g_mc_save_buf_as_SaveBlock.b262;
    g_setting_ship_stock = g_mc_save_buf_as_SaveBlock.b263;
    g_setting_rapid_fire = g_mc_save_buf_as_SaveBlock.b264;
    D_0028E37C = g_mc_save_buf_as_SaveBlock.b265;
    g_pad_vib_state_p1 = g_mc_save_buf_as_SaveBlock.b266;
    g_pad_vib_state_p2 = g_mc_save_buf_as_SaveBlock.b267;
    D_0028E32C = g_mc_save_buf_as_SaveBlock.h268;
    g_pad_vib_enabled = g_mc_save_buf_as_SaveBlock.b26A;
    D_0028E278 = g_mc_save_buf_as_SaveBlock.b26B;
    g_display_offset_x = g_mc_save_buf_as_SaveBlock.b274;
    g_display_offset_y = g_mc_save_buf_as_SaveBlock.b275;
    D_0028E258 = g_mc_save_buf_as_SaveBlock.b276;
    D_0028E300 = g_mc_save_buf_as_SaveBlock.h278;
    g_bgm_alternate_set = g_mc_save_buf_as_SaveBlock.b59C;
    g_screen_wide = g_mc_save_buf_as_SaveBlock.b59D;
    D_0028E2D8 = g_mc_save_buf_as_SaveBlock.b59E;
    D_0028E354 = g_mc_save_buf_as_SaveBlock.b59F;
    g_stage_map_enabled = g_mc_save_buf_as_SaveBlock.b5A0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                D_00684CF0[i][j][k] = g_mc_save_buf_as_SaveBlock.a27C[i][j][k];
            }
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            g_p1_btn_map_a[i][j] = g_mc_save_buf_as_SaveBlock.a26C[i][j];
        }
    }
    menu_values_from_settings();
    display_settings_apply();
}

extern void display_set_offset(s8, s8);
extern void wallpaper_load(s32, s32);
extern s32 g_menu_wallpapers_as_s32_a[];
extern u8 D_00271C64[];
extern s8 g_display_reset_pending;

void display_settings_apply(void)
{
    u16 selection;

    g_display_reset_pending = 1;
    display_set_offset(g_display_offset_x, g_display_offset_y);

    selection = D_0028E32C;
    if (selection != 5) {
        s32 tableIndex = (selection & 0xFFFF) * 2;

        wallpaper_load(g_menu_wallpapers_as_s32_a[tableIndex], ((s32 *)D_00271C64)[tableIndex]);
    }
}

extern s32 D_0028EC7C;

void save_snapshot_take(void) {
#ifdef DDPDOJ_PC
    SaveBlock D_006A3E50 = {0};
#else
    extern SaveBlock D_006A3E50;
#endif
    s32 i;
    s32 j;
    s32 k;

    D_0028EC7C = 0;
    for (i = 0; i < 5; i++) {
        D_006A3E50.a00[i] = g_ranking_ship_types[i];
        D_006A3E50.a0A[i] = g_ranking_power_styles[i];
        D_006A3E50.a14[i] = g_ranking_loops[i];
        D_006A3E50.a1E[i] = g_ranking_stages[i];
        D_006A3E50.a28[i] = g_ranking_hits[i];
        D_006A3E50.a70[i] = g_ranking_scores[i];
        D_006A3E50.a84[i] = g_ranking_score_tops[i];
        D_006A3E50.a8E[i] = g_ranking_continues[i];
        D_006A3E50.a98[i] = g_death_label_ranking_ship_types[i];
        D_006A3E50.aA2[i] = g_death_label_ranking_power_styles[i];
        D_006A3E50.aAC[i] = g_death_label_ranking_loops[i];
        D_006A3E50.aB6[i] = g_death_label_ranking_stages[i];
        D_006A3E50.aC0[i] = g_death_label_ranking_hits[i];
        D_006A3E50.a108[i] = g_death_label_ranking_scores[i];
        D_006A3E50.a11C[i] = g_death_label_ranking_score_tops[i];
        D_006A3E50.a126[i] = g_death_label_ranking_continues[i];
    }
    for (i = 0; i < 15; i++) {
        D_006A3E50.a34[i] = g_ranking_names[i];
        D_006A3E50.aCC[i] = g_death_label_ranking_names[i];
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 30; j++) {
            D_006A3E50.a130[i][j] = g_death_label_ranking_texts[i][j];
            D_006A3E50.a1C6[i][j] = g_stored_ranking_texts[i][j];
        }
    }
    D_006A3E50.b25C = g_setting_coin_mode;
    D_006A3E50.b25D = g_setting_continue;
    D_006A3E50.b25E = g_setting_demo_sound;
    D_006A3E50.b25F = g_setting_chute_type;
    D_006A3E50.b260 = D_0028E358;
    D_006A3E50.b261 = g_setting_difficulty;
    D_006A3E50.b262 = g_setting_extend;
    D_006A3E50.b263 = g_setting_ship_stock;
    D_006A3E50.b264 = g_setting_rapid_fire;
    D_006A3E50.b265 = D_0028E37C;
    D_006A3E50.b266 = g_pad_vib_state_p1;
    D_006A3E50.b267 = g_pad_vib_state_p2;
    D_006A3E50.h268 = D_0028E32C;
    D_006A3E50.b26A = g_pad_vib_enabled;
    D_006A3E50.b26B = D_0028E278;
    D_006A3E50.b274 = g_display_offset_x;
    D_006A3E50.b275 = g_display_offset_y;
    D_006A3E50.b276 = D_0028E258;
    D_006A3E50.h278 = D_0028E300;
    D_006A3E50.b59C = g_bgm_alternate_set;
    D_006A3E50.b59D = g_screen_wide;
    D_006A3E50.b59E = D_0028E2D8;
    D_006A3E50.b59F = D_0028E354;
    D_006A3E50.b5A0 = g_stage_map_enabled;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                D_006A3E50.a27C[i][j][k] = D_00684CF0[i][j][k];
            }
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            D_006A3E50.a26C[i][j] = g_p1_btn_map_a[i][j];
        }
    }
#ifdef DDPDOJ_PC
    memcpy(settings_snapshot, &D_006A3E50, sizeof(D_006A3E50));
#endif
}


s32 save_snapshot_changed_check(void) {
#ifdef DDPDOJ_PC
    SaveBlock2 D_006A3E50;
    memcpy(&D_006A3E50, settings_snapshot, sizeof(D_006A3E50));
#else
    extern SaveBlock2 D_006A3E50;
#endif
    s32 i;
    s32 j;
    s32 k;
    s32 stage;

    stage = 0;
    for (i = 0; i < 5; i++) {
        if (D_006A3E50.a00[i] != g_ranking_ship_types[i]) {
            printf("typhi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a0A[i] != g_ranking_power_styles[i]) {
            printf("kyohi chg[%d] [%d][%d]\n", i, D_006A3E50.a0A[i], g_ranking_power_styles[i]);
            goto fail;
        }
        if (D_006A3E50.a14[i] != g_ranking_loops[i]) {
            printf("roundhi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a1E[i] != g_ranking_stages[i]) {
            printf("areahi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a28[i] != g_ranking_hits[i]) {
            printf("gphi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a70[i] != g_ranking_scores[i]) {
            printf("scohi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a84[i] != g_ranking_score_tops[i]) {
            printf("okuhi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a8E[i] != g_ranking_continues[i]) {
            printf("cnthi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a98[i] != g_death_label_ranking_ship_types[i] || D_006A3E50.aA2[i] != g_death_label_ranking_power_styles[i] ||
            D_006A3E50.aAC[i] != g_death_label_ranking_loops[i] || D_006A3E50.aB6[i] != g_death_label_ranking_stages[i] ||
            D_006A3E50.aC0[i] != g_death_label_ranking_hits[i] || D_006A3E50.a108[i] != g_death_label_ranking_scores[i] ||
            D_006A3E50.a11C[i] != g_death_label_ranking_score_tops[i] || D_006A3E50.a126[i] != g_death_label_ranking_continues[i]) {
            goto fail;
        }
    }
    stage++;
    for (i = 0; i < 15; i++) {
        if (D_006A3E50.a34[i] != g_ranking_names[i] || D_006A3E50.aCC[i] != g_death_label_ranking_names[i]) {
            goto fail;
        }
    }
    stage++;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 30; j++) {
            if (D_006A3E50.a130[i][j] != g_death_label_ranking_texts[i][j] || D_006A3E50.a1C6[i][j] != g_stored_ranking_texts[i][j]) {
                goto fail;
            }
        }
    }
    if (D_006A3E50.b25C != g_setting_coin_mode) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b25D != g_setting_continue) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b25E != g_setting_demo_sound) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b25F != g_setting_chute_type) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b260 != D_0028E358) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b261 != g_setting_difficulty) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b262 != g_setting_extend) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b263 != g_setting_ship_stock) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b264 != g_setting_rapid_fire) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b265 != D_0028E37C) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b266 != g_pad_vib_state_p1) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b267 != g_pad_vib_state_p2) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.h268 != D_0028E32C) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b26A != g_pad_vib_enabled) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b26B != D_0028E278) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b274 != g_display_offset_x) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b275 != g_display_offset_y) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b276 != D_0028E258) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.h278 != D_0028E300) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b59C != g_bgm_alternate_set) {
        printf("com_bgm\n");
        goto fail;
    }
    stage++;
    if (D_006A3E50.b59D != g_screen_wide) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b59E != D_0028E2D8) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b59F != D_0028E354) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b5A0 != g_stage_map_enabled) {
        goto fail;
    }
    stage++;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                if (D_006A3E50.a27C[i][j][k] != D_00684CF0[i][j][k]) {
                    goto fail;
                }
            }
        }
    }
    stage++;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            if (D_006A3E50.a26C[i][j] != g_p1_btn_map_a[i][j]) {
                goto fail;
            }
        }
    }
    printf("--Data Ok!--\n");
    return 0;
fail:
    printf("--Data Chg!-[%d]-\n", stage);
    return 1;
}


s32 autosave_update(void) {
    if (D_0028E278 == 0) {
        D_0028EC7C = 10;
    }
    switch (D_0028EC7C) {
    case 0:
        if (save_snapshot_changed_check() != 0) {
            D_0028EC7C++;
        } else {
            D_0028EC7C = 10;
        }
        break;
    case 1:
        save_block_from_settings();
        D_0028ED0C = 0;
        D_0028EC7C++;
    case 2:
        mc_autosave_update(0);
        if (D_0028ED0C != 0) {
            D_0028ED0C = 0;
            D_0028EC7C = 10;
        }
        break;
    }
    if (D_0028EC7C == 10) {
        save_snapshot_take();
        D_0028EC7C = 0;
        return 1;
    }
    return 0;
}

extern void sfx_extend(void);
extern u16 D_0028E2FC;

void mc_task_option_unlocked(void) {
#ifndef DDPDOJ_PC
    extern void mc_message_draw(s32, char *, s32, s32, s32, u16, s32);
#endif
    s16 pressed;

    switch (g_mc_step) {
    case 0:
        pressed = (s16)(s32)D_0028E300 ^ (s16)D_0028E2FC;
        pressed &= (s16)D_0028E300;
        if (pressed == 0) {
            g_mc_step = 99;
        } else {
            g_mc_step++;
        }
        break;
    case 1:
        if (pressed & 1) {
            sfx_extend();
            g_mc_step++;
        } else {
            g_mc_step = 3;
        }
        break;
    case 2:
        mc_message_draw(200, g_mc_msg_option_unlocked[0], 0, 20, 14, D_0028ED10, 100);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step++;
        }
        break;
    case 3:
        if (pressed & 2) {
            sfx_extend();
            g_mc_step++;
        } else {
            g_mc_step = 5;
        }
        break;
    case 4:
        mc_message_draw(200, g_mc_msg_option_unlocked[1], 0, 20, 14, D_0028ED10, 100);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step++;
        }
        break;
    case 5:
        if (pressed & 8) {
            sfx_extend();
            g_mc_step++;
        } else {
            g_mc_step = 7;
        }
        break;
    case 6:
        mc_message_draw(200, g_mc_msg_option_unlocked[2], 0, 20, 14, D_0028ED10, 100);
        mc_confirm_button_draw();
        if (g_pad_trigger[2] & 0x20) {
            g_mc_step++;
        }
        break;
    case 7:
        g_mc_step = 99;
        break;
    case 99:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            g_mc_step = 0;
            D_0028ED18 = 2;
        }
        break;
    }
}

extern u16 D_0028E2FC;
extern s32 D_0028EC78;

s32 unlock_notice_reset(void) {
    D_0028EC78 = 0;
    D_0028E2FC = D_0028E300;
    return 1;
}

void replay_slot_infos_clear(void)
{
    u8 *buffer;
    u8 *cursor;
    s32 blockIndex;
    s32 bytesCleared;
    s32 blockOffset;

    blockIndex = 0;
    blockOffset = 0;

    do {
        buffer = g_replay_slot_infos;
        cursor = buffer + blockOffset;
        bytesCleared = 0;

        do {
            cursor[0] = 0;
            cursor[1] = 0;
            bytesCleared += 8;
            cursor[2] = 0;
            cursor[3] = 0;
            cursor[4] = 0;
            cursor[5] = 0;
            cursor[6] = 0;
            cursor[7] = 0;
            cursor += 8;
        } while (bytesCleared < 0x400);

        blockIndex += 1;
        blockOffset += 0x400;
    } while (blockIndex < 12);
}

extern u16 D_006A0E52[];
extern u16 D_006A0E54[];
extern u16 D_006A0E56[];
extern u16 D_006A0E58[];
extern u16 D_006A0E5A[];
extern u16 D_006A0E5C[];
extern u16 D_006A0E5E[];
extern u16 D_006A0E60[];
extern u16 D_006A0E62[];
extern u16 D_006A0E64[];
extern u16 D_006A0E66[];
extern u16 D_006A0E68[];
extern u16 D_006A0E6A[];
extern u16 D_006A0E6C[];
extern u16 D_006A0E6E[];
extern u16 D_006A0E70[];
extern u16 D_006A0E72[];
extern u16 D_006A0E76[];
extern u16 D_006A0E78[];
extern u16 D_006A0E7A[];
extern u16 D_006A0E7C[];
extern u16 D_006A0E7E[];
extern u16 D_006A0E80[];
extern u16 D_006A0E82[];
extern u16 D_006A0E86[];
extern u16 replay_slot_info_fill_buffer[];
#ifndef DDPDOJ_PC
extern u8 g_replay_file[48];
extern u16 D_006C58A2[];
extern u16 D_006C58A4[];
extern u16 D_006C58A6[];
extern u16 D_006C58A8[];
extern u16 D_006C58AA[];
extern u16 D_006C58AC[];
extern u16 D_006C58AE[];
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
extern u16 D_006C58D6[];
#endif

void replay_slot_info_fill(s32 slot) {
    s32 off;

    off = slot * 512;
    D_006A0E52[off] = D_006C58A2[0];
    D_006A0E54[off] = D_006C58A4[0];
    D_006A0E56[off] = D_006C58A6[0];
    D_006A0E58[off] = D_006C58A8[0];
    D_006A0E5A[off] = D_006C58AA[0];
    D_006A0E5C[off] = D_006C58AC[0];
    D_006A0E5E[off] = D_006C58AE[0];
    ((u16 *)g_replay_slot_infos)[off] = ((u16 *)g_replay_file)[0];
    D_006A0E60[off] = D_006C58B0[0];
    D_006A0E62[off] = D_006C58B2[0];
    D_006A0E6C[off] = D_006C58BC[0];
    D_006A0E6E[off] = D_006C58BE[0];
    D_006A0E70[off] = D_006C58C0[0];
    D_006A0E68[off] = D_006C58B8[0];
    D_006A0E6A[off] = D_006C58BA[0];
    D_006A0E64[off] = D_006C58B4[0];
    D_006A0E66[off] = D_006C58B6[0];
    D_006A0E72[off] = D_006C58C2[0];
    D_006A0E76[off] = D_006C58C6[0];
    D_006A0E78[off] = D_006C58C8[0];
    D_006A0E7A[off] = D_006C58CA[0];
    D_006A0E7C[off] = D_006C58CC[0];
    D_006A0E7E[off] = D_006C58CE[0];
    D_006A0E80[off] = D_006C58D0[0];
    D_006A0E82[off] = D_006C58D2[0];
    D_006A0E86[off] = D_006C58D6[0];
    ((u16 *)g_replay_slot_infos)[off] = 1;
    replay_slot_info_fill_buffer[off] = 0;
}

/* .sbss (the compiler lays these out in reverse) */
s8 mc_state_reset_state;
u8 D_0028ED37;
u8 D_0028ED36;
u8 D_0028ED35;
u8 D_0028ED34;
u8 D_0028ED33;
u8 D_0028ED32;
u8 D_0028ED31;
u8 D_0028ED30 __attribute__((aligned(8)));
s32 D_0028ED28;
s32 D_0028ED24;
s32 g_mc_operation;
s32 g_mc_file;
s32 D_0028ED18;
s32 D_0028ED14;
s32 D_0028ED10;
s32 D_0028ED0C;
s32 D_0028ED08;
s32 g_memcard_watch_step;
s32 D_0028ED00;
u8 g_mc_task __attribute__((aligned(4)));
u8 g_mc_wait __attribute__((aligned(4)));
u8 D_0028ECF4 __attribute__((aligned(4)));
u8 g_mc_step __attribute__((aligned(4)));
u8 g_mc_choice __attribute__((aligned(4)));
u8 D_0028ECE8 __attribute__((aligned(4)));
u8 D_0028ECE4 __attribute__((aligned(4)));
u8 g_memcard_watch_delay __attribute__((aligned(4)));
u8 D_0028ECDC __attribute__((aligned(4)));
u8 D_0028ECD8 __attribute__((aligned(4)));
s8 D_0028ECD4;
s32 D_0028ECD0;
s32 D_0028ECCC;
s32 D_0028ECC8;
s32 D_0028ECC4;
s32 D_0028ECC0;
s8 g_mc_auto;
s32 D_0028ECB8;
s32 D_0028ECB4;
s32 D_0028ECB0;
s32 D_0028ECAC;
s32 g_mc_fd;
u16 g_mc_cursor_x __attribute__((aligned(4)));
u16 D_0028ECA0 __attribute__((aligned(4)));
u16 g_mc_cursor_target_x;
s32 mc_task_read_state_2;
s32 mc_task_read_state;
s32 mc_task_load_check_card_state;
u8 mc_task_startup_check_state_7;
u8 mc_task_startup_check_state_6;
u8 mc_task_startup_check_state_5;
u8 mc_task_startup_check_state_4;
s32 mc_task_startup_check_state_3;
s32 mc_task_startup_check_state_2;
s32 mc_task_startup_check_state;
s32 D_0028EC7C;
s32 D_0028EC78;
s32 g_mc_slot;
s32 g_mc_port;

/* .bss (the compiler lays these out in reverse) */
u8 g_mc_save_buf[2480];
#ifndef DDPDOJ_PC
u8 D_006A4C00[131824];
u8 g_replay_file_loaded[1024];
u8 D_006A3E50[2480];
#endif
u16 replay_slot_info_fill_buffer[6112];
#ifndef DDPDOJ_PC
s32 D_0069F590[1600];
u8 g_mc_dir[16];
#endif
#ifdef DEATH_LABEL
u8 D_00696D80[34864];
#else
u8 D_00696D80[34816];
#endif
u8 D_0068E580[34816];
u8 D_0068E270[784];
u8 D_0068E260[16];
u8 D_0068E230[48];
u8 D_0068E200[48];
u8 D_0068E1C0[64];
u8 D_0068E1B0[16];
