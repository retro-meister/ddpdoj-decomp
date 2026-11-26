#include "common.h"
#include "fade.h"
#include "task.h"
#include "entity.h"
#include "sdk/ps2sdk.h"
#include "cd.h"
#include "replay.h"
#include "doll_select.h"

extern u16 g_credits_script[];
extern u16 ending_fade_in_table[];
extern u16 ending_fade_in_group_0[];
extern u16 ending_fade_in_group_1[];
extern u16 ending_fade_in_group_2[];
extern u16 ending_fade_in_group_3[];
extern u16 ending_fade_in_group_4[];
extern u16 scroll_event_routines[];
extern u16 scroll_sound_routines[];
extern u16 stage_map_palettes[];
extern u16 stage_maps[];
extern u16 stage5_boss_horn_shot_offsets[];

extern u16 bullet_type_setup_routines[];
extern u16 bullet_move_routines[];
extern u16 D_0024EBC0[];
extern u16 D_0024EDB0[];
extern u16 D_0024EF30[];
extern u16 debris_random_patterns[];
extern u16 spark_spans_by_laser_power[];
extern u16 spark_setup_laser[];
extern u16 join_select_p1_table[];
extern u16 join_select_p2_table[];
extern u16 stage5_boss_flash_palettes_a[];
extern u16 stage5_boss_flash_palettes_b[];
extern u16 stage5_boss_flash_palettes_c[];
extern u16 stage5_boss_fade_palettes_a[];
extern u16 stage5_boss_fade_palettes_b[];

void music_start_when_ready(void);
void sound_update_bgm_fade(void);
s32 password_conditions_check(void);
void password_make(void);
void name_entry_p1_update();
void name_entry_p2_update();
void name_entry_side_begin(void);
void name_entry_side_update(void);
void name_entry_side_done(void);
void name_entry_rank_find_p1(void);
void name_entry_rank_find_p2(void);
void name_entry_rank_find(void);
void name_entry_side_setup(void);
void name_entry_name_copy_to_own_ranks(void);
void name_entry_name_draw(void);
void name_entry_cursor_draw(void);
void name_entry_score_draw(void);
void name_entry_player_and_rank_draw(void);
void name_entry_letter_board_draw(void);
void name_entry_cover_draw_p1(void);
void name_entry_cover_draw_p2(void);
void name_entry_lever_input(void);
void name_entry_cursor_move(void);


extern u16 g_stage1_map[];
extern u16 g_stage1_map_palettes[];
extern u16 g_stage2_map[];
extern u16 g_stage2_map_palettes[];
extern u16 g_stage3_map[];
extern u16 g_stage3_map_palettes[];
extern u16 g_stage4_map[];
extern u16 g_stage4_map_palettes[];
extern u16 g_stage5_map[];
extern u16 g_stage5_map_palettes[];
extern u16 stage5_boss_flash_palettes_a_30[];
extern u16 stage5_boss_flash_palettes_a_33[];
extern u16 stage5_boss_flash_palettes_a_37[];
extern u16 stage5_boss_flash_palettes_a_40[];
extern u16 stage5_boss_flash_palettes_a_44[];
extern u16 stage5_boss_flash_palettes_a_47[];
extern u8 ending_fade_in_table_at_4[64];
extern u16 credits_text_01[];
extern u16 credits_text_02[];
extern u16 credits_text_03[];
extern u16 credits_text_04[];
extern u16 credits_text_05[];
extern u16 credits_text_07[];
extern u16 credits_text_08[];
extern u16 credits_text_25[];
extern u16 credits_text_09[];
extern u16 credits_text_10[];
extern u16 credits_text_11[];
extern u16 credits_text_12[];
extern u16 credits_text_13[];
extern u16 credits_text_15[];
extern u16 credits_text_16[];
extern u16 credits_text_17[];
extern u16 credits_text_20[];
extern u16 credits_text_22[];
extern u16 credits_text_23[];
extern u16 credits_text_26[];
extern u16 credits_text_27[];
extern u16 credits_text_28[];
extern u16 credits_text_29[];
extern u16 credits_text_31[];
extern u16 credits_text_32[];
extern u16 credits_text_33[];
extern u16 credits_text_24[];
extern u16 credits_text_30[];
extern u16 bullet_type_record_00[];
extern u16 bullet_type_record_01[];
extern u16 bullet_type_record_02[];
extern u16 bullet_type_record_03[];
extern u16 bullet_type_record_04[];
extern u16 bullet_type_record_05[];
extern u16 bullet_type_record_06[];
extern u16 bullet_type_record_07[];
extern u16 bullet_type_record_08[];
extern u16 bullet_type_record_09[];
extern u16 bullet_type_record_10[];
extern u16 bullet_type_record_11[];
extern u16 bullet_type_record_12[];
extern u16 bullet_type_record_13[];
extern u16 bullet_type_record_14[];
extern u16 bullet_type_record_15[];
extern u16 bullet_type_record_16[];
extern u16 bullet_type_record_17[];
extern u16 bullet_type_record_18[];
extern u16 bullet_type_record_19[];
extern u16 bullet_type_record_20[];
extern u16 bullet_type_record_21[];
extern u16 bullet_type_record_22[];
extern u16 bullet_type_record_23[];
extern u16 bullet_type_record_24[];
extern u16 bullet_type_record_25[];
extern u16 bullet_type_record_26[];
extern u16 bullet_type_record_27[];
extern u16 bullet_type_record_28[];
extern u16 bullet_type_record_29[];
extern u16 bullet_type_record_30[];
extern u16 bullet_type_record_31[];
extern u16 bullet_type_record_32[];
extern u16 bullet_type_record_33[];
extern u16 bullet_type_record_34[];
extern u16 bullet_type_record_35[];
extern u16 D_0024EBF0[];
extern u16 D_0024EC00[];
extern u16 D_0024EC10[];
extern u16 D_0024EC20[];
extern u16 D_0024EC30[];
extern u16 D_0024EC40[];
extern u16 D_0024EC50[];
extern u16 D_0024EC60[];
extern u16 D_0024EC70[];
extern u16 D_0024EDE0[];
extern u16 D_0024EDF0[];
extern u16 D_0024EE00[];
extern u16 D_0024EE10[];
extern u16 D_0024EE20[];
extern u16 D_0024EE30[];
extern u16 D_0024EE40[];
extern u16 D_0024EE50[];
extern u16 explosion_script_00[];
extern u16 explosion_script_01[];
extern u16 explosion_script_b_00[];
extern u16 explosion_script_b_01[];
extern u16 explosion_script_02[];
extern u16 explosion_script_03[];
extern u16 explosion_script_b_02[];
extern u16 explosion_script_b_03[];
extern u16 explosion_script_04[];
extern u16 explosion_script_05[];
extern u16 explosion_script_b_04[];
extern u16 explosion_script_b_05[];
extern u16 explosion_script_06[];
extern u16 explosion_script_07[];
extern u16 explosion_script_b_06[];
extern u16 explosion_script_b_07[];
extern u16 explosion_script_08[];
extern u16 explosion_script_09[];
extern u16 explosion_script_b_08[];
extern u16 explosion_script_b_09[];
extern u16 explosion_script_10[];
extern u16 explosion_script_11[];
extern u16 explosion_script_b_10[];
extern u16 explosion_script_b_11[];
extern u16 explosion_script_12[];
extern u16 explosion_script_13[];
extern u16 explosion_script_14[];
extern u16 explosion_script_15[];
extern u16 explosion_script_16[];
extern u16 explosion_script_17[];
extern u16 explosion_script_18[];
extern u16 explosion_script_19[];
extern u16 explosion_scripts_20[];
extern u16 explosion_scripts_21[];
extern u16 explosion_scripts_22[];
extern u16 explosion_scripts_23[];
extern u16 explosion_scripts_24[];
extern u16 explosion_scripts_25[];
extern u16 explosion_scripts_26[];
extern u16 explosion_scripts_27[];
extern u16 explosion_scripts_28[];
extern u16 explosion_scripts_29[];
extern u16 explosion_scripts_30[];
extern u16 explosion_scripts_31[];
extern u16 D_002506F0[];
extern u16 explosion_scripts_33[];
extern u16 debris_pattern_0[];
extern u16 debris_pattern_1[];
extern u16 debris_pattern_2[];
extern u16 debris_pattern_3[];
extern u16 debris_pattern_4[];
extern u16 spark_frames_small_0[];
extern u16 spark_frames_small_1[];
extern u16 spark_frames_small_2[];
extern u16 spark_frames_long_0[];
extern u16 spark_frames_long_1[];
extern u16 wreck_frames_00[];
extern u16 wreck_frames_01[];
extern u16 wreck_frames_02[];
extern u16 wreck_frames_03[];
extern u16 wreck_frames_04[];
extern u16 wreck_frames_05[];
extern u16 wreck_frames_06[];
extern u16 wreck_frames_07[];
extern u16 wreck_frames_08[];
extern u16 wreck_frames_09[];
extern u16 wreck_frames_10[];
extern u16 wreck_frames_11[];
extern u16 D_00251CE0[];
extern u16 D_00251D10[];
extern u16 D_00251D40[];
extern u16 D_00252020[];
extern u16 D_00252030[];
extern u16 D_00252040[];
extern u16 D_00252060[];
extern u16 D_00252070[];
extern u16 D_00252080[];
extern u16 D_00252090[];
extern u16 D_002520A0[];
extern u16 D_002520B0[];
extern u16 D_002520C0[];
extern u16 D_002520D0[];
extern u16 D_002520E0[];
extern u16 D_002520F0[];
extern u16 D_00252100[];
extern u16 D_00252110[];
extern u16 D_00252120[];
extern u16 D_00252130[];
extern u16 D_00252140[];
extern u16 D_00252150[];
extern u16 D_00252160[];
extern u16 D_00252170[];
extern u16 D_00252180[];
extern u16 D_00252190[];
extern u16 D_002521A0[];
extern u16 D_002521B0[];
extern u16 D_002521D0[];
extern u16 D_002521F0[];
extern u16 D_00252230[];
extern u16 D_00252240[];
extern u16 D_00252250[];
extern u16 D_00252268[];
extern u16 D_00252278[];
extern u16 D_00252290[];
extern u16 D_002522B0[];
extern u16 D_002522D0[];
extern u16 D_002522F0[];
extern u16 D_00252310[];
extern u16 stage1_scroll_palettes[];
extern u16 stage1_scroll_sounds[];
extern u16 stage1_scroll_events[];
extern u16 stage1_plane2_scroll_events[];
extern u16 stage2_scroll_palettes[];
extern u16 stage2_scroll_sounds[];
extern u16 stage2_scroll_events[];
extern u16 stage2_plane2_scroll_events[];
extern u16 stage3_scroll_palettes[];
extern u16 stage3_scroll_sounds[];
extern u16 stage3_scroll_events[];
extern u16 stage3_plane2_scroll_events[];
extern u16 stage4_scroll_palettes[];
extern u16 stage4_scroll_sounds[];
extern u16 stage4_scroll_events[];
extern u16 stage4_plane2_scroll_events[];
extern u16 stage5_scroll_palettes[];
extern u16 stage5_scroll_sounds[];
extern u16 stage5_scroll_events[];
extern u16 stage5_plane2_scroll_events[];
extern u16 name_entry_letter_table_at_0[];
extern u16 name_entry_letter_table_at_2[];
extern u16 name_entry_letter_table_at_4[];
extern u16 name_entry_letter_table_at_6[];
extern u16 name_entry_letter_table_at_8[];
extern u16 name_entry_letter_table_at_10[];
extern u16 name_entry_letter_table_at_12[];
extern u16 name_entry_letter_table_at_14[];
extern u16 name_entry_letter_table_at_16[];
extern u16 name_entry_letter_table_at_18[];
extern u16 name_entry_letter_table_at_20[];
extern u16 name_entry_letter_table_at_22[];
extern u16 name_entry_letter_table_at_24[];
extern u16 name_entry_letter_table_at_26[];
extern u16 name_entry_letter_table_at_28[];
extern u16 name_entry_letter_table_at_30[];
extern u16 name_entry_letter_table_at_32[];
extern u16 name_entry_letter_table_at_34[];
extern u16 name_entry_letter_table_at_36[];
extern u16 name_entry_letter_table_at_38[];
extern u16 name_entry_letter_table_at_40[];
extern u16 name_entry_letter_table_at_42[];
extern u16 name_entry_letter_table_at_44[];
extern u16 name_entry_letter_table_at_46[];
extern u16 name_entry_letter_table_at_48[];
extern u16 name_entry_letter_table_at_50[];
extern u16 name_entry_letter_table_at_52[];
extern u16 name_entry_letter_table_at_54[];
extern u8 D_0025FF70[];
extern u8 D_0025FFB0[];
extern u8 D_0025FFF0[];
extern u8 stage5_boss_flash_palettes_a_at_32[];
extern u8 stage5_boss_flash_palettes_a_at_39[];
extern u8 stage5_boss_flash_palettes_a_at_46[];
extern u8 D_002600F0[];
extern u8 stage5_boss_flash_palettes_b_at_11[];
extern u8 stage5_boss_flash_palettes_b_at_18[];
extern u16 stage2_scroll_palettes_at_33[];
extern u16 stage2_scroll_palettes_at_54[];
extern u16 stage2_palette_18[];
extern u16 stage1_palette_03[];
extern u16 stage1_palette_04[];
extern u16 stage1_palette_01[];
extern u16 stage1_palette_00[];
extern u16 stage1_palette_07[];
extern u16 stage5_scroll_palettes_at_51[];
extern u16 stage1_scroll_palettes_at_12[];
extern u16 stage4_scroll_palettes_at_39[];
extern u16 stage4_scroll_palettes_at_57[];
extern u16 stage3_palette_16[];
extern u16 stage3_scroll_palettes_at_48[];
extern u16 D_00260EB0[];
extern u16 D_00260EF0[];
extern u16 D_00260F30[];
extern u16 stage1_palette_13[];
extern u16 D_00260FF0[];
extern u16 stage1_palette_18[];
extern u8 D_002610B0[];
extern u16 D_002610F0[];
extern u16 D_00261130[];
extern u16 D_00261170[];
extern u16 D_002611B0[];
extern u16 D_002611F0[];
extern u16 stage1_scroll_palettes_at_60[];
extern u16 stage1_scroll_palettes_at_63[];
extern u16 stage1_scroll_palettes_at_48[];
extern u16 stage2_scroll_palettes_at_51[];
extern u16 stage2_scroll_palettes_at_60[];
extern u16 stage2_scroll_palettes_at_45[];
extern u16 stage2_scroll_palettes_at_63[];
extern u16 stage2_scroll_palettes_at_66[];
extern u16 stage2_scroll_palettes_at_69[];
extern u16 stage2_scroll_palettes_at_72[];
extern u16 stage2_scroll_palettes_at_75[];
extern u16 stage2_scroll_palettes_at_48[];
extern u16 stage2_scroll_palettes_at_57[];
extern u16 stage3_scroll_palettes_at_66[];
extern u16 stage3_scroll_palettes_at_69[];
extern u16 stage3_scroll_palettes_at_63[];
extern u16 stage3_midboss_flash_palettes_05[];
extern u16 stage3_scroll_palettes_at_57[];
extern u16 stage3_scroll_palettes_at_54[];
extern u8 stage4_scroll_palettes_at_48[];
extern u16 stage4_scroll_palettes_at_45[];
extern u16 stage4_scroll_palettes_at_51[];
extern u16 stage4_scroll_palettes_at_54[];
extern u16 stage4_scroll_palettes_at_63[];
extern u16 stage4_scroll_palettes_at_42[];
extern u16 stage5_scroll_palettes_at_45[];
extern u16 stage5_scroll_palettes_at_42[];
extern u16 stage5_scroll_palettes_at_54[];
extern u16 stage5_scroll_palettes_at_57[];
extern u16 D_00261D30[];
extern u16 D_00261D70[];
extern u16 stage1_palette_10[];
extern u8 name_entry_task_begin_table[];
extern u16 D_00261F30[];
extern u8 name_entry_task_begin_table_2[];
extern u8 name_entry_task_begin_table_3[];
extern u16 ending_fade_in_05[];
extern u16 ending_fade_in_09[];
extern u16 stage5_boss_horn_shot_offsets_at_6[];
extern u16 stage5_boss_horn_shot_offsets_at_4[];
extern u16 stage5_boss_horn_shot_offsets_at_2[];
extern u16 D_002644E0[];
extern u16 credits_text_00[];
extern u16 stage1_scroll_event_lists[];
extern u16 stage2_scroll_event_lists[];
extern u16 stage3_scroll_event_lists[];
extern u16 stage4_scroll_event_lists[];
extern u16 stage5_scroll_event_lists[];
extern u16 D_0028C680[];
extern u16 player_exhaust_sprites_01_at_0[];
extern u8 join_select_p2_table_at_8[16];
extern u8 join_select_p1_table_at_8[16];
extern void bullet_type_setup_00(void);
extern void bullet_type_setup_03(void);
extern void bullet_type_setup_17(void);
extern void bullet_type_setup_18(void);
extern void bullet_type_setup_19(void);
extern void bullet_type_setup_23(void);
extern void bullet_type_setup_27(void);
extern void bullet_type_setup_32(void);
extern void bullet_init_from_task(void);
extern void bullet_type_setup_30(void);
extern void bullet_type_setup_31(void);
extern void velocity_octant_negate_y_swap(void);
extern void velocity_octant_swap(void);
extern void velocity_octant_keep(void);
extern void velocity_octant_swap_negate_y(void);
extern void velocity_octant_negate_y(void);
extern void velocity_octant_swap_negate_both(void);
extern void velocity_octant_negate_both(void);
extern void velocity_octant_negate_x(void);
extern void bullet_move_type_00(void);
extern void bullet_move_type_01(void);
extern void bullet_move_type_02(void);
extern void bullet_move_type_03(void);
extern void bullet_move_type_04(void);
extern void bullet_move_type_05(void);
extern void bullet_move_type_06(void);
extern void bullet_move_type_07(void);
extern void bullet_move_type_08(void);
extern void bullet_move_type_09(void);
extern void bullet_move_type_10(void);
extern void bullet_move_type_11(void);
extern void bullet_move_type_12(void);
extern void bullet_move_type_13(void);
extern void bullet_move_type_16(void);
extern void bullet_move_type_17(void);
extern void bullet_move_type_18(void);
extern void bullet_move_type_19(void);
extern void bullet_move_type_20(void);
extern void bullet_move_type_21(void);
extern void bullet_move_type_22(void);
extern void bullet_move_type_23(void);
extern void bullet_move_type_24(void);
extern void bullet_move_type_25(void);
extern void bullet_move_type_26(void);
extern void bullet_move_type_27(void);
extern void bullet_move_type_28(void);
extern void bullet_move_type_29(void);
extern void bullet_move_type_30(void);
extern void bullet_move_type_31(void);
extern void bullet_move_type_32(void);
extern void bullet_move_type_33(void);
extern void bullet_move_type_34(void);
extern void bullet_move_type_35(void);
extern void p1_credit_spend_one(void);
extern void p2_credit_spend_one(void);
extern void scroll_event_palettes(void);
extern void scroll_event_map_loop(void);
extern void scroll_event_speed(void);
extern void scroll_event_line_hold(void);
extern void scroll_event_scenery(void);
extern void scroll_event_sounds(void);
extern void scroll_sound_call(void);
extern void scroll_sound_music_stop(void);
extern void scroll_sound_music_fade(void);
extern void scroll_event_flags(void);
extern void music_play_bgm3(void);
extern void music_play_bgm4(void);
extern void music_play_bgm5(void);
extern void music_play_bgm6(void);
extern void music_play_bgm7(void);
extern void music_play_bgm8(void);
extern u16 bullet_type_records[];
extern u16 explosion_scripts[];
extern u16 explosion_scripts_b[];
extern u16 D_00251AB0_as_u16_a[];
extern u16 D_00251AB4[];
extern u16 D_00251AC0_as_u16_a[];
extern u16 D_00251AC4[];
extern u16 D_00251CC0[];
extern u16 D_00252010[];
extern u16 D_00252050[];
extern u16 D_00252210[];
extern u16 D_00252220[];
extern u16 D_002526D2[];
extern u16 D_002526F2[];
extern u16 D_00252702[];
extern u16 D_00252722[];
extern u16 stage_scroll_event_lists[];
extern u16 D_0025BF98[];
extern u16 D_0025BFA6[];
extern u16 D_0025BFB4[];
extern u16 D_0025BFC2[];
extern u16 name_entry_letter_table[];
extern u16 select_panel_piece_2_draw_table_as_u16_a[];
extern u16 D_0028C14A[];

#ifdef DEATH_LABEL
extern u16 death_D_002506F0[];
extern u16 death_D_00250790[];
extern u16 death_D_00250A72[];
extern u16 death_D_00250B20[];
extern u16 g_credits_script_at_158[];
extern u16 g_credits_script_at_163[];
extern u16 g_credits_script_at_168[];
extern u16 death_D_00254778[];
extern u16 death_D_00254790[];
extern u16 death_D_002547A0[];
extern u16 death_D_002547B0[];
extern u16 death_D_002547C0[];
extern u16 death_D_0025495A[];
extern u16 death_D_00254964[];
extern u16 death_D_0025496E[];
extern u16 death_D_00254978[];
extern u16 death_D_00254982[];
extern void bullet_type_24_setup(void);
#endif

#ifdef DDPDOJ_PC
void debris_frame_addresses_init(void);
#endif

void checked_pointers_store(void) {
    extern void input_get_p1_held(void);
    extern void input_get_p2_held(void);
    extern void input_get_p1_pressed(void);
    extern void input_get_p2_pressed(void);
    if (((u16 *)bullet_type_setup_routines)[0] != 0x0) {
        printf("error! shot_para_tbl[0]\n");
    }
    STORE_POINTER_DIRECT(((u16 *)bullet_type_setup_routines), bullet_type_setup_00);
    if (bullet_type_setup_routines[2] != 0x2) {
        printf("error! shot_para_tbl[2]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 2, bullet_type_setup_00);
    if (bullet_type_setup_routines[4] != 0x4) {
        printf("error! shot_para_tbl[4]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 4, bullet_type_setup_00);
    if (bullet_type_setup_routines[6] != 0x6) {
        printf("error! shot_para_tbl[6]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 6, bullet_type_setup_03);
    if (bullet_type_setup_routines[8] != 0x8) {
        printf("error! shot_para_tbl[8]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 8, bullet_type_setup_03);
    if (bullet_type_setup_routines[10] != 0xa) {
        printf("error! shot_para_tbl[10]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 10, bullet_type_setup_03);
    if (bullet_type_setup_routines[12] != 0xc) {
        printf("error! shot_para_tbl[12]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 12, bullet_type_setup_03);
    if (bullet_type_setup_routines[14] != 0xe) {
        printf("error! shot_para_tbl[14]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 14, bullet_type_setup_00);
    if (bullet_type_setup_routines[16] != 0x10) {
        printf("error! shot_para_tbl[16]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 16, bullet_type_setup_00);
    if (bullet_type_setup_routines[18] != 0x12) {
        printf("error! shot_para_tbl[18]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 18, bullet_type_setup_00);
    if (bullet_type_setup_routines[20] != 0x14) {
        printf("error! shot_para_tbl[20]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 20, bullet_type_setup_00);
    if (bullet_type_setup_routines[22] != 0x16) {
        printf("error! shot_para_tbl[22]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 22, bullet_type_setup_00);
    if (bullet_type_setup_routines[24] != 0x18) {
        printf("error! shot_para_tbl[24]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 24, bullet_type_setup_00);
    if (bullet_type_setup_routines[26] != 0x1a) {
        printf("error! shot_para_tbl[26]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 26, bullet_type_setup_00);
    if (bullet_type_setup_routines[28] != 0x1c) {
        printf("error! shot_para_tbl[28]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 28, bullet_type_setup_00);
    if (bullet_type_setup_routines[30] != 0x1e) {
        printf("error! shot_para_tbl[30]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 30, bullet_type_setup_00);
    if (bullet_type_setup_routines[32] != 0x20) {
        printf("error! shot_para_tbl[32]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 32, bullet_type_setup_00);
    if (bullet_type_setup_routines[34] != 0x22) {
        printf("error! shot_para_tbl[34]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 34, bullet_type_setup_17);
    if (bullet_type_setup_routines[36] != 0x24) {
        printf("error! shot_para_tbl[36]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 36, bullet_type_setup_18);
    if (bullet_type_setup_routines[38] != 0x26) {
        printf("error! shot_para_tbl[38]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 38, bullet_type_setup_19);
    if (bullet_type_setup_routines[40] != 0x28) {
        printf("error! shot_para_tbl[40]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 40, bullet_type_setup_00);
    if (bullet_type_setup_routines[42] != 0x2a) {
        printf("error! shot_para_tbl[42]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 42, bullet_type_setup_00);
    if (bullet_type_setup_routines[44] != 0x2c) {
        printf("error! shot_para_tbl[44]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 44, bullet_type_setup_19);
    if (bullet_type_setup_routines[46] != 0x2e) {
        printf("error! shot_para_tbl[46]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 46, bullet_type_setup_23);
    if (bullet_type_setup_routines[48] != 0x30) {
        printf("error! shot_para_tbl[48]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 48, bullet_type_setup_23);
    if (bullet_type_setup_routines[50] != 0x32) {
        printf("error! shot_para_tbl[50]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 50, bullet_type_setup_00);
    if (bullet_type_setup_routines[52] != 0x34) {
        printf("error! shot_para_tbl[52]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 52, bullet_type_setup_00);
    if (bullet_type_setup_routines[54] != 0x36) {
        printf("error! shot_para_tbl[54]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 54, bullet_type_setup_27);
    if (bullet_type_setup_routines[56] != 0x38) {
        printf("error! shot_para_tbl[56]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 56, bullet_init_from_task);
    if (bullet_type_setup_routines[58] != 0x3a) {
        printf("error! shot_para_tbl[58]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 58, bullet_type_setup_00);
    if (bullet_type_setup_routines[60] != 0x3c) {
        printf("error! shot_para_tbl[60]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 60, bullet_type_setup_30);
    if (bullet_type_setup_routines[62] != 0x3e) {
        printf("error! shot_para_tbl[62]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 62, bullet_type_setup_31);
    if (bullet_type_setup_routines[64] != 0x40) {
        printf("error! shot_para_tbl[64]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 64, bullet_type_setup_32);
    if (bullet_type_setup_routines[66] != 0x42) {
        printf("error! shot_para_tbl[66]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 66, bullet_type_setup_00);
    if (bullet_type_setup_routines[68] != 0x44) {
        printf("error! shot_para_tbl[68]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 68, bullet_type_setup_00);
    if (bullet_type_setup_routines[70] != 0x46) {
        printf("error! shot_para_tbl[70]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 70, bullet_type_setup_03);
#ifdef DEATH_LABEL
    if (death_D_002506F0[0] != 0x48) {
        printf("error! shot_para_tbl[72]\n");
    }
    STORE_POINTER_DIRECT(death_D_002506F0, bullet_init_from_task);
#endif
    if (bullet_type_records[0] != 0x0) {
        printf("error! shot_tbl[0]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records, bullet_type_record_00);
    if (bullet_type_records[2] != 0x2) {
        printf("error! shot_tbl[2]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 2, bullet_type_record_01);
    if (bullet_type_records[4] != 0x4) {
        printf("error! shot_tbl[4]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 4, bullet_type_record_02);
    if (bullet_type_records[6] != 0x6) {
        printf("error! shot_tbl[6]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 6, bullet_type_record_03);
    if (bullet_type_records[8] != 0x8) {
        printf("error! shot_tbl[8]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 8, bullet_type_record_04);
    if (bullet_type_records[10] != 0xa) {
        printf("error! shot_tbl[10]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 10, bullet_type_record_05);
    if (bullet_type_records[12] != 0xc) {
        printf("error! shot_tbl[12]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 12, bullet_type_record_06);
    if (bullet_type_records[14] != 0xe) {
        printf("error! shot_tbl[14]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 14, bullet_type_record_07);
    if (bullet_type_records[16] != 0x10) {
        printf("error! shot_tbl[16]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 16, bullet_type_record_08);
    if (bullet_type_records[18] != 0x12) {
        printf("error! shot_tbl[18]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 18, bullet_type_record_09);
    if (bullet_type_records[20] != 0x14) {
        printf("error! shot_tbl[20]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 20, bullet_type_record_10);
    if (bullet_type_records[22] != 0x16) {
        printf("error! shot_tbl[22]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 22, bullet_type_record_11);
    if (bullet_type_records[24] != 0x18) {
        printf("error! shot_tbl[24]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 24, bullet_type_record_12);
    if (bullet_type_records[26] != 0x1a) {
        printf("error! shot_tbl[26]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 26, bullet_type_record_13);
    if (bullet_type_records[28] != 0x1c) {
        printf("error! shot_tbl[28]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 28, bullet_type_record_14);
    if (bullet_type_records[30] != 0x1e) {
        printf("error! shot_tbl[30]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 30, bullet_type_record_15);
    if (bullet_type_records[32] != 0x20) {
        printf("error! shot_tbl[32]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 32, bullet_type_record_16);
    if (bullet_type_records[34] != 0x22) {
        printf("error! shot_tbl[34]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 34, bullet_type_record_17);
    if (bullet_type_records[36] != 0x24) {
        printf("error! shot_tbl[36]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 36, bullet_type_record_18);
    if (bullet_type_records[38] != 0x26) {
        printf("error! shot_tbl[38]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 38, bullet_type_record_19);
    if (bullet_type_records[40] != 0x28) {
        printf("error! shot_tbl[40]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 40, bullet_type_record_20);
    if (bullet_type_records[42] != 0x2a) {
        printf("error! shot_tbl[42]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 42, bullet_type_record_21);
    if (bullet_type_records[44] != 0x2c) {
        printf("error! shot_tbl[44]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 44, bullet_type_record_22);
    if (bullet_type_records[46] != 0x2e) {
        printf("error! shot_tbl[46]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 46, bullet_type_record_23);
    if (bullet_type_records[48] != 0x30) {
        printf("error! shot_tbl[48]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 48, bullet_type_record_24);
    if (bullet_type_records[50] != 0x32) {
        printf("error! shot_tbl[50]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 50, bullet_type_record_25);
    if (bullet_type_records[52] != 0x34) {
        printf("error! shot_tbl[52]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 52, bullet_type_record_26);
    if (bullet_type_records[54] != 0x36) {
        printf("error! shot_tbl[54]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 54, bullet_type_record_27);
    if (bullet_type_records[56] != 0x38) {
        printf("error! shot_tbl[56]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 56, bullet_type_record_28);
    if (bullet_type_records[58] != 0x3a) {
        printf("error! shot_tbl[58]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 58, bullet_type_record_29);
    if (bullet_type_records[60] != 0x3c) {
        printf("error! shot_tbl[60]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 60, bullet_type_record_30);
    if (bullet_type_records[62] != 0x3e) {
        printf("error! shot_tbl[62]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 62, bullet_type_record_31);
    if (bullet_type_records[64] != 0x40) {
        printf("error! shot_tbl[64]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 64, bullet_type_record_32);
    if (bullet_type_records[66] != 0x42) {
        printf("error! shot_tbl[66]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 66, bullet_type_record_33);
    if (bullet_type_records[68] != 0x44) {
        printf("error! shot_tbl[68]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 68, bullet_type_record_34);
    if (bullet_type_records[70] != 0x46) {
        printf("error! shot_tbl[70]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_records + 70, bullet_type_record_35);
#ifdef DEATH_LABEL
    if (death_D_00250790[0] != 0x48) {
        printf("error! shot_tbl[72]\n");
    }
    STORE_POINTER_DIRECT(death_D_00250790, death_D_00250A72);
#endif
    if (((u16 *)bullet_move_routines)[0] != 0x0) {
        printf("error! bulljmp[0]\n");
    }
    STORE_POINTER_DIRECT(((u16 *)bullet_move_routines), bullet_move_type_00);
    if (bullet_move_routines[2] != 0x2) {
        printf("error! bulljmp[2]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 2, bullet_move_type_01);
    if (bullet_move_routines[4] != 0x4) {
        printf("error! bulljmp[4]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 4, bullet_move_type_02);
    if (bullet_move_routines[6] != 0x6) {
        printf("error! bulljmp[6]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 6, bullet_move_type_03);
    if (bullet_move_routines[8] != 0x8) {
        printf("error! bulljmp[8]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 8, bullet_move_type_04);
    if (bullet_move_routines[10] != 0xa) {
        printf("error! bulljmp[10]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 10, bullet_move_type_05);
    if (bullet_move_routines[12] != 0xc) {
        printf("error! bulljmp[12]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 12, bullet_move_type_06);
    if (bullet_move_routines[14] != 0xe) {
        printf("error! bulljmp[14]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 14, bullet_move_type_07);
    if (bullet_move_routines[16] != 0x10) {
        printf("error! bulljmp[16]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 16, bullet_move_type_08);
    if (bullet_move_routines[18] != 0x12) {
        printf("error! bulljmp[18]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 18, bullet_move_type_09);
    if (bullet_move_routines[20] != 0x14) {
        printf("error! bulljmp[20]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 20, bullet_move_type_10);
    if (bullet_move_routines[22] != 0x16) {
        printf("error! bulljmp[22]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 22, bullet_move_type_11);
    if (bullet_move_routines[24] != 0x18) {
        printf("error! bulljmp[24]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 24, bullet_move_type_12);
    if (bullet_move_routines[26] != 0x1a) {
        printf("error! bulljmp[26]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 26, bullet_move_type_13);
    if (bullet_move_routines[28] != 0x1c) {
        printf("error! bulljmp[28]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 28, bullet_move_type_10);
    if (bullet_move_routines[30] != 0x1e) {
        printf("error! bulljmp[30]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 30, bullet_move_type_10);
    if (bullet_move_routines[32] != 0x20) {
        printf("error! bulljmp[32]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 32, bullet_move_type_16);
    if (bullet_move_routines[34] != 0x22) {
        printf("error! bulljmp[34]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 34, bullet_move_type_17);
    if (bullet_move_routines[36] != 0x24) {
        printf("error! bulljmp[36]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 36, bullet_move_type_18);
    if (bullet_move_routines[38] != 0x26) {
        printf("error! bulljmp[38]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 38, bullet_move_type_19);
    if (bullet_move_routines[40] != 0x28) {
        printf("error! bulljmp[40]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 40, bullet_move_type_20);
    if (bullet_move_routines[42] != 0x2a) {
        printf("error! bulljmp[42]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 42, bullet_move_type_21);
    if (bullet_move_routines[44] != 0x2c) {
        printf("error! bulljmp[44]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 44, bullet_move_type_22);
    if (bullet_move_routines[46] != 0x2e) {
        printf("error! bulljmp[46]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 46, bullet_move_type_23);
    if (bullet_move_routines[48] != 0x30) {
        printf("error! bulljmp[48]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 48, bullet_move_type_24);
    if (bullet_move_routines[50] != 0x32) {
        printf("error! bulljmp[50]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 50, bullet_move_type_25);
    if (bullet_move_routines[52] != 0x34) {
        printf("error! bulljmp[52]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 52, bullet_move_type_26);
    if (bullet_move_routines[54] != 0x36) {
        printf("error! bulljmp[54]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 54, bullet_move_type_27);
    if (bullet_move_routines[56] != 0x38) {
        printf("error! bulljmp[56]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 56, bullet_move_type_28);
    if (bullet_move_routines[58] != 0x3a) {
        printf("error! bulljmp[58]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 58, bullet_move_type_29);
    if (bullet_move_routines[60] != 0x3c) {
        printf("error! bulljmp[60]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 60, bullet_move_type_30);
    if (bullet_move_routines[62] != 0x3e) {
        printf("error! bulljmp[62]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 62, bullet_move_type_31);
    if (bullet_move_routines[64] != 0x40) {
        printf("error! bulljmp[64]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 64, bullet_move_type_32);
    if (bullet_move_routines[66] != 0x42) {
        printf("error! bulljmp[66]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 66, bullet_move_type_33);
    if (bullet_move_routines[68] != 0x44) {
        printf("error! bulljmp[68]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 68, bullet_move_type_34);
    if (bullet_move_routines[70] != 0x46) {
        printf("error! bulljmp[70]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines + 70, bullet_move_type_35);
#ifdef DEATH_LABEL
    if (death_D_00250B20[0] != 0x48) {
        printf("error! bulljmp[72]\n");
    }
    STORE_POINTER_DIRECT(death_D_00250B20, bullet_type_24_setup);
#endif
    if (((u16 *)D_0024EBC0)[0] != 0x0) {
        printf("error! bull_n02tbl[0]\n");
    }
    STORE_POINTER_DIRECT(((u16 *)D_0024EBC0), D_0024EBF0);
    if (D_0024EBC0[2] != 0x2) {
        printf("error! bull_n02tbl[2]\n");
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 2, D_0024EC00);
    if (D_0024EBC0[4] != 0x4) {
        printf("error! bull_n02tbl[4]\n");
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 4, D_0024EC10);
    if (D_0024EBC0[6] != 0x6) {
        printf("error! bull_n02tbl[6]\n");
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 6, D_0024EC20);
    if (D_0024EBC0[8] != 0x8) {
        printf("error! bull_n02tbl[8]\n");
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 8, D_0024EC30);
    if (D_0024EBC0[10] != 0xa) {
        printf("error! bull_n02tbl[10]\n");
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 10, D_0024EC40);
    if (D_0024EBC0[12] != 0xc) {
        printf("error! bull_n02tbl[12]\n");
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 12, D_0024EC50);
    if (D_0024EBC0[14] != 0xe) {
        printf("error! bull_n02tbl[14]\n");
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 14, D_0024EC60);
    if (D_0024EBC0[16] != 0x10) {
        printf("error! bull_n02tbl[16]\n");
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 16, D_0024EC70);
    if (((u16 *)D_0024EDB0)[0] != 0x0) {
        printf("error! bull_n15tbl[0]\n");
    }
    STORE_POINTER_DIRECT(((u16 *)D_0024EDB0), D_0024EDE0);
    if (D_0024EDB0[2] != 0x2) {
        printf("error! bull_n15tbl[2]\n");
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 2, D_0024EDF0);
    if (D_0024EDB0[4] != 0x4) {
        printf("error! bull_n15tbl[4]\n");
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 4, D_0024EE00);
    if (D_0024EDB0[6] != 0x6) {
        printf("error! bull_n15tbl[6]\n");
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 6, D_0024EE10);
    if (D_0024EDB0[8] != 0x8) {
        printf("error! bull_n15tbl[8]\n");
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 8, D_0024EE20);
    if (D_0024EDB0[10] != 0xa) {
        printf("error! bull_n15tbl[10]\n");
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 10, D_0024EE30);
    if (D_0024EDB0[12] != 0xc) {
        printf("error! bull_n15tbl[12]\n");
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 12, D_0024EE40);
    if (D_0024EDB0[14] != 0xe) {
        printf("error! bull_n15tbl[14]\n");
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 14, D_0024EE50);
    if (D_0024EDB0[16] != 0x10) {
        printf("error! bull_n15tbl[16]\n");
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 16, D_0024EDE0);
    if (D_0024EF30[192] != 0x0) {
        printf("error! bull_spdjmp[0]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 192, velocity_octant_keep);
    if (D_0024EF30[196] != 0x4) {
        printf("error! bull_spdjmp[4]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 196, velocity_octant_swap);
    if (D_0024EF30[200] != 0x8) {
        printf("error! bull_spdjmp[8]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 200, velocity_octant_swap_negate_y);
    if (D_0024EF30[204] != 0xc) {
        printf("error! bull_spdjmp[12]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 204, velocity_octant_negate_y);
    if (D_0024EF30[208] != 0x10) {
        printf("error! bull_spdjmp[16]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 208, velocity_octant_negate_both);
    if (D_0024EF30[212] != 0x14) {
        printf("error! bull_spdjmp[20]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 212, velocity_octant_swap_negate_both);
    if (D_0024EF30[216] != 0x18) {
        printf("error! bull_spdjmp[24]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 216, velocity_octant_negate_y_swap);
    if (D_0024EF30[220] != 0x1c) {
        printf("error! bull_spdjmp[28]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 220, velocity_octant_negate_x);
    if (explosion_scripts[0] != 0x0) {
        printf("error! exp_tbl[0]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts, explosion_script_00);
    if (explosion_scripts[2] != 0x2) {
        printf("error! exp_tbl[2]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 2, explosion_script_01);
    if (explosion_scripts[4] != 0x4) {
        printf("error! exp_tbl[4]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 4, explosion_script_02);
    if (explosion_scripts[6] != 0x6) {
        printf("error! exp_tbl[6]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 6, explosion_script_03);
    if (explosion_scripts[8] != 0x8) {
        printf("error! exp_tbl[8]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 8, explosion_script_04);
    if (explosion_scripts[10] != 0xa) {
        printf("error! exp_tbl[10]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 10, explosion_script_05);
    if (explosion_scripts[12] != 0xc) {
        printf("error! exp_tbl[12]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 12, explosion_script_06);
    if (explosion_scripts[14] != 0xe) {
        printf("error! exp_tbl[14]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 14, explosion_script_07);
    if (explosion_scripts[16] != 0x10) {
        printf("error! exp_tbl[16]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 16, explosion_script_08);
    if (explosion_scripts[18] != 0x12) {
        printf("error! exp_tbl[18]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 18, explosion_script_09);
    if (explosion_scripts[20] != 0x14) {
        printf("error! exp_tbl[20]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 20, explosion_script_10);
    if (explosion_scripts[22] != 0x16) {
        printf("error! exp_tbl[22]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 22, explosion_script_11);
    if (explosion_scripts[24] != 0x18) {
        printf("error! exp_tbl[24]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 24, explosion_script_12);
    if (explosion_scripts[26] != 0x1a) {
        printf("error! exp_tbl[26]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 26, explosion_script_13);
    if (explosion_scripts[28] != 0x1c) {
        printf("error! exp_tbl[28]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 28, explosion_script_14);
    if (explosion_scripts[30] != 0x1e) {
        printf("error! exp_tbl[30]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 30, explosion_script_15);
    if (explosion_scripts[32] != 0x20) {
        printf("error! exp_tbl[32]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 32, explosion_script_16);
    if (explosion_scripts[34] != 0x22) {
        printf("error! exp_tbl[34]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 34, explosion_script_17);
    if (explosion_scripts[36] != 0x24) {
        printf("error! exp_tbl[36]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 36, explosion_script_18);
    if (explosion_scripts[38] != 0x26) {
        printf("error! exp_tbl[38]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 38, explosion_script_19);
    if (explosion_scripts[40] != 0x28) {
        printf("error! exp_tbl[40]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 40, explosion_scripts_20);
    if (explosion_scripts[42] != 0x2a) {
        printf("error! exp_tbl[42]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 42, explosion_scripts_21);
    if (explosion_scripts[44] != 0x2c) {
        printf("error! exp_tbl[44]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 44, explosion_scripts_22);
    if (explosion_scripts[46] != 0x2e) {
        printf("error! exp_tbl[46]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 46, explosion_scripts_23);
    if (explosion_scripts[48] != 0x30) {
        printf("error! exp_tbl[48]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 48, explosion_scripts_24);
    if (explosion_scripts[50] != 0x32) {
        printf("error! exp_tbl[50]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 50, explosion_scripts_25);
    if (explosion_scripts[52] != 0x34) {
        printf("error! exp_tbl[52]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 52, explosion_scripts_26);
    if (explosion_scripts[54] != 0x36) {
        printf("error! exp_tbl[54]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 54, explosion_scripts_27);
    if (explosion_scripts[56] != 0x38) {
        printf("error! exp_tbl[56]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 56, explosion_scripts_28);
    if (explosion_scripts[58] != 0x3a) {
        printf("error! exp_tbl[58]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 58, explosion_scripts_29);
    if (explosion_scripts[60] != 0x3c) {
        printf("error! exp_tbl[60]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 60, explosion_scripts_30);
    if (explosion_scripts[62] != 0x3e) {
        printf("error! exp_tbl[62]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 62, explosion_scripts_31);
    if (explosion_scripts[64] != 0x40) {
        printf("error! exp_tbl[64]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 64, D_002506F0);
    if (explosion_scripts[66] != 0x42) {
        printf("error! exp_tbl[66]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 66, explosion_scripts_33);
    if (explosion_scripts[68] != 0x44) {
        printf("error! exp_tbl[68]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 68, explosion_script_00);
    if (explosion_scripts[70] != 0x46) {
        printf("error! exp_tbl[70]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 70, explosion_script_01);
    if (explosion_scripts[72] != 0x48) {
        printf("error! exp_tbl[72]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 72, explosion_script_02);
    if (explosion_scripts[74] != 0x4a) {
        printf("error! exp_tbl[74]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 74, explosion_script_03);
    if (explosion_scripts[76] != 0x4c) {
        printf("error! exp_tbl[76]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 76, explosion_script_04);
    if (explosion_scripts[78] != 0x4e) {
        printf("error! exp_tbl[78]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 78, explosion_script_05);
    if (explosion_scripts[80] != 0x50) {
        printf("error! exp_tbl[80]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 80, explosion_script_06);
    if (explosion_scripts[82] != 0x52) {
        printf("error! exp_tbl[82]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 82, explosion_script_07);
    if (explosion_scripts[84] != 0x54) {
        printf("error! exp_tbl[84]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 84, explosion_script_08);
    if (explosion_scripts[86] != 0x56) {
        printf("error! exp_tbl[86]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 86, explosion_script_09);
    if (explosion_scripts[88] != 0x58) {
        printf("error! exp_tbl[88]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 88, explosion_script_10);
    if (explosion_scripts[90] != 0x5a) {
        printf("error! exp_tbl[90]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 90, explosion_script_11);
    if (explosion_scripts[92] != 0x5c) {
        printf("error! exp_tbl[92]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 92, explosion_script_12);
    if (explosion_scripts[94] != 0x5e) {
        printf("error! exp_tbl[94]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 94, explosion_script_13);
    if (explosion_scripts[96] != 0x60) {
        printf("error! exp_tbl[96]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 96, explosion_script_14);
    if (explosion_scripts[98] != 0x62) {
        printf("error! exp_tbl[98]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 98, explosion_script_15);
    if (explosion_scripts[100] != 0x64) {
        printf("error! exp_tbl[100]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 100, explosion_script_16);
    if (explosion_scripts[102] != 0x66) {
        printf("error! exp_tbl[102]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 102, explosion_script_17);
    if (explosion_scripts[104] != 0x68) {
        printf("error! exp_tbl[104]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 104, explosion_script_18);
    if (explosion_scripts[106] != 0x6a) {
        printf("error! exp_tbl[106]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 106, explosion_script_19);
    if (explosion_scripts[108] != 0x6c) {
        printf("error! exp_tbl[108]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 108, explosion_scripts_20);
    if (explosion_scripts[110] != 0x6e) {
        printf("error! exp_tbl[110]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 110, explosion_scripts_21);
    if (explosion_scripts[112] != 0x70) {
        printf("error! exp_tbl[112]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 112, explosion_scripts_22);
    if (explosion_scripts[114] != 0x72) {
        printf("error! exp_tbl[114]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 114, explosion_scripts_23);
    if (explosion_scripts[116] != 0x74) {
        printf("error! exp_tbl[116]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 116, explosion_scripts_24);
    if (explosion_scripts[118] != 0x76) {
        printf("error! exp_tbl[118]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 118, explosion_scripts_25);
    if (explosion_scripts[120] != 0x78) {
        printf("error! exp_tbl[120]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 120, explosion_scripts_26);
    if (explosion_scripts[122] != 0x7a) {
        printf("error! exp_tbl[122]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 122, explosion_scripts_27);
    if (explosion_scripts[124] != 0x7c) {
        printf("error! exp_tbl[124]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 124, explosion_scripts_28);
    if (explosion_scripts[126] != 0x7e) {
        printf("error! exp_tbl[126]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 126, explosion_scripts_29);
    if (explosion_scripts[128] != 0x80) {
        printf("error! exp_tbl[128]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 128, explosion_scripts_30);
    if (explosion_scripts[130] != 0x82) {
        printf("error! exp_tbl[130]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 130, explosion_scripts_31);
    if (explosion_scripts[132] != 0x84) {
        printf("error! exp_tbl[132]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 132, D_002506F0);
    if (explosion_scripts[134] != 0x86) {
        printf("error! exp_tbl[134]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts + 134, explosion_scripts_33);
    if (explosion_scripts_b[0] != 0x0) {
        printf("error! exp_tbl_80[0]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b, explosion_script_b_00);
    if (explosion_scripts_b[2] != 0x2) {
        printf("error! exp_tbl_80[2]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 2, explosion_script_b_01);
    if (explosion_scripts_b[4] != 0x4) {
        printf("error! exp_tbl_80[4]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 4, explosion_script_b_02);
    if (explosion_scripts_b[6] != 0x6) {
        printf("error! exp_tbl_80[6]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 6, explosion_script_b_03);
    if (explosion_scripts_b[8] != 0x8) {
        printf("error! exp_tbl_80[8]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 8, explosion_script_b_04);
    if (explosion_scripts_b[10] != 0xa) {
        printf("error! exp_tbl_80[10]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 10, explosion_script_b_05);
    if (explosion_scripts_b[12] != 0xc) {
        printf("error! exp_tbl_80[12]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 12, explosion_script_b_06);
    if (explosion_scripts_b[14] != 0xe) {
        printf("error! exp_tbl_80[14]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 14, explosion_script_b_07);
    if (explosion_scripts_b[16] != 0x10) {
        printf("error! exp_tbl_80[16]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 16, explosion_script_b_08);
    if (explosion_scripts_b[18] != 0x12) {
        printf("error! exp_tbl_80[18]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 18, explosion_script_b_09);
    if (explosion_scripts_b[20] != 0x14) {
        printf("error! exp_tbl_80[20]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 20, explosion_script_b_10);
    if (explosion_scripts_b[22] != 0x16) {
        printf("error! exp_tbl_80[22]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 22, explosion_script_b_11);
    if (explosion_scripts_b[24] != 0x18) {
        printf("error! exp_tbl_80[24]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 24, explosion_scripts_20);
    if (explosion_scripts_b[26] != 0x1a) {
        printf("error! exp_tbl_80[26]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 26, explosion_scripts_21);
    if (explosion_scripts_b[28] != 0x1c) {
        printf("error! exp_tbl_80[28]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 28, explosion_scripts_22);
    if (explosion_scripts_b[30] != 0x1e) {
        printf("error! exp_tbl_80[30]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 30, explosion_scripts_23);
    if (explosion_scripts_b[32] != 0x20) {
        printf("error! exp_tbl_80[32]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 32, explosion_scripts_24);
    if (explosion_scripts_b[34] != 0x22) {
        printf("error! exp_tbl_80[34]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 34, explosion_scripts_25);
    if (explosion_scripts_b[36] != 0x24) {
        printf("error! exp_tbl_80[36]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 36, explosion_scripts_26);
    if (explosion_scripts_b[38] != 0x26) {
        printf("error! exp_tbl_80[38]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 38, explosion_scripts_27);
    if (explosion_scripts_b[40] != 0x28) {
        printf("error! exp_tbl_80[40]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 40, explosion_scripts_20);
    if (explosion_scripts_b[42] != 0x2a) {
        printf("error! exp_tbl_80[42]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 42, explosion_scripts_21);
    if (explosion_scripts_b[44] != 0x2c) {
        printf("error! exp_tbl_80[44]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 44, explosion_scripts_22);
    if (explosion_scripts_b[46] != 0x2e) {
        printf("error! exp_tbl_80[46]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 46, explosion_scripts_23);
    if (explosion_scripts_b[48] != 0x30) {
        printf("error! exp_tbl_80[48]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 48, explosion_scripts_24);
    if (explosion_scripts_b[50] != 0x32) {
        printf("error! exp_tbl_80[50]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 50, explosion_scripts_25);
    if (explosion_scripts_b[52] != 0x34) {
        printf("error! exp_tbl_80[52]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 52, explosion_scripts_26);
    if (explosion_scripts_b[54] != 0x36) {
        printf("error! exp_tbl_80[54]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 54, explosion_scripts_27);
    if (explosion_scripts_b[56] != 0x38) {
        printf("error! exp_tbl_80[56]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 56, explosion_scripts_28);
    if (explosion_scripts_b[58] != 0x3a) {
        printf("error! exp_tbl_80[58]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 58, explosion_scripts_29);
    if (explosion_scripts_b[60] != 0x3c) {
        printf("error! exp_tbl_80[60]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 60, explosion_scripts_30);
    if (explosion_scripts_b[62] != 0x3e) {
        printf("error! exp_tbl_80[62]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 62, explosion_scripts_31);
    if (explosion_scripts_b[64] != 0x40) {
        printf("error! exp_tbl_80[64]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 64, D_002506F0);
    if (explosion_scripts_b[66] != 0x42) {
        printf("error! exp_tbl_80[66]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 66, explosion_scripts_33);
    if (explosion_scripts_b[68] != 0x44) {
        printf("error! exp_tbl_80[68]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 68, explosion_script_b_00);
    if (explosion_scripts_b[70] != 0x46) {
        printf("error! exp_tbl_80[70]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 70, explosion_script_b_01);
    if (explosion_scripts_b[72] != 0x48) {
        printf("error! exp_tbl_80[72]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 72, explosion_script_b_02);
    if (explosion_scripts_b[74] != 0x4a) {
        printf("error! exp_tbl_80[74]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 74, explosion_script_b_03);
    if (explosion_scripts_b[76] != 0x4c) {
        printf("error! exp_tbl_80[76]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 76, explosion_script_b_04);
    if (explosion_scripts_b[78] != 0x4e) {
        printf("error! exp_tbl_80[78]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 78, explosion_script_b_05);
    if (explosion_scripts_b[80] != 0x50) {
        printf("error! exp_tbl_80[80]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 80, explosion_script_b_06);
    if (explosion_scripts_b[82] != 0x52) {
        printf("error! exp_tbl_80[82]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 82, explosion_script_b_07);
    if (explosion_scripts_b[84] != 0x54) {
        printf("error! exp_tbl_80[84]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 84, explosion_script_b_08);
    if (explosion_scripts_b[86] != 0x56) {
        printf("error! exp_tbl_80[86]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 86, explosion_script_b_09);
    if (explosion_scripts_b[88] != 0x58) {
        printf("error! exp_tbl_80[88]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 88, explosion_script_b_10);
    if (explosion_scripts_b[90] != 0x5a) {
        printf("error! exp_tbl_80[90]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 90, explosion_script_b_11);
    if (explosion_scripts_b[92] != 0x5c) {
        printf("error! exp_tbl_80[92]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 92, explosion_scripts_20);
    if (explosion_scripts_b[94] != 0x5e) {
        printf("error! exp_tbl_80[94]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 94, explosion_scripts_21);
    if (explosion_scripts_b[96] != 0x60) {
        printf("error! exp_tbl_80[96]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 96, explosion_scripts_22);
    if (explosion_scripts_b[98] != 0x62) {
        printf("error! exp_tbl_80[98]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 98, explosion_scripts_23);
    if (explosion_scripts_b[100] != 0x64) {
        printf("error! exp_tbl_80[100]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 100, explosion_scripts_24);
    if (explosion_scripts_b[102] != 0x66) {
        printf("error! exp_tbl_80[102]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 102, explosion_scripts_25);
    if (explosion_scripts_b[104] != 0x68) {
        printf("error! exp_tbl_80[104]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 104, explosion_scripts_26);
    if (explosion_scripts_b[106] != 0x6a) {
        printf("error! exp_tbl_80[106]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 106, explosion_scripts_27);
    if (explosion_scripts_b[108] != 0x6c) {
        printf("error! exp_tbl_80[108]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 108, explosion_scripts_20);
    if (explosion_scripts_b[110] != 0x6e) {
        printf("error! exp_tbl_80[110]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 110, explosion_scripts_21);
    if (explosion_scripts_b[112] != 0x70) {
        printf("error! exp_tbl_80[112]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 112, explosion_scripts_22);
    if (explosion_scripts_b[114] != 0x72) {
        printf("error! exp_tbl_80[114]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 114, explosion_scripts_23);
    if (explosion_scripts_b[116] != 0x74) {
        printf("error! exp_tbl_80[116]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 116, explosion_scripts_24);
    if (explosion_scripts_b[118] != 0x76) {
        printf("error! exp_tbl_80[118]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 118, explosion_scripts_25);
    if (explosion_scripts_b[120] != 0x78) {
        printf("error! exp_tbl_80[120]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 120, explosion_scripts_26);
    if (explosion_scripts_b[122] != 0x7a) {
        printf("error! exp_tbl_80[122]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 122, explosion_scripts_27);
    if (explosion_scripts_b[124] != 0x7c) {
        printf("error! exp_tbl_80[124]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 124, explosion_scripts_28);
    if (explosion_scripts_b[126] != 0x7e) {
        printf("error! exp_tbl_80[126]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 126, explosion_scripts_29);
    if (explosion_scripts_b[128] != 0x80) {
        printf("error! exp_tbl_80[128]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 128, explosion_scripts_30);
    if (explosion_scripts_b[130] != 0x82) {
        printf("error! exp_tbl_80[130]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 130, explosion_scripts_31);
    if (explosion_scripts_b[132] != 0x84) {
        printf("error! exp_tbl_80[132]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 132, D_002506F0);
    if (explosion_scripts_b[134] != 0x86) {
        printf("error! exp_tbl_80[134]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(explosion_scripts_b + 134, explosion_scripts_33);
#ifdef DDPDOJ_PC
    debris_frame_addresses_init();
#else
    if (debris_pattern_0[67] != 0x3) {
        printf("error! hah_n00[3]\n");
    }
    STORE_POINTER_DIRECT(debris_pattern_0 + 67, debris_pattern_0);
    if (debris_pattern_1[67] != 0x3) {
        printf("error! hah_n01[3]\n");
    }
    STORE_POINTER_DIRECT(debris_pattern_1 + 67, debris_pattern_1);
    if (debris_pattern_2[67] != 0x3) {
        printf("error! hah_n02[3]\n");
    }
    STORE_POINTER_DIRECT(debris_pattern_2 + 67, debris_pattern_2);
    if (debris_pattern_3[67] != 0x3) {
        printf("error! hah_n03[3]\n");
    }
    STORE_POINTER_DIRECT(debris_pattern_3 + 67, debris_pattern_3);
    if (debris_pattern_4[67] != 0x3) {
        printf("error! hah_n04[3]\n");
    }
    STORE_POINTER_DIRECT(debris_pattern_4 + 67, debris_pattern_4);
#endif
    if (((u16 *)debris_random_patterns)[0] != 0x0) {
        printf("error! hah_random_tbl[0]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(((u16 *)debris_random_patterns), debris_pattern_0);
    if (debris_random_patterns[2] != 0x2) {
        printf("error! hah_random_tbl[2]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(debris_random_patterns + 2, debris_pattern_2);
    if (debris_random_patterns[4] != 0x4) {
        printf("error! hah_random_tbl[4]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(debris_random_patterns + 4, debris_pattern_3);
    if (debris_random_patterns[6] != 0x6) {
        printf("error! hah_random_tbl[6]\n");
    }
    STORE_ARCADE_ADDRESS_DIRECT(debris_random_patterns + 6, debris_pattern_4);
    if (spark_spans_by_laser_power[16] != 0x8) {
        printf("error! tili_a[8]\n");
    }
    STORE_POINTER_DIRECT(spark_spans_by_laser_power + 16, spark_frames_small_0);
    if (spark_spans_by_laser_power[32] != 0x8) {
        printf("error! tili_a2[8]\n");
    }
    STORE_POINTER_DIRECT(spark_spans_by_laser_power + 32, spark_frames_small_1);
    if (spark_spans_by_laser_power[48] != 0x8) {
        printf("error! tili_a3[8]\n");
    }
    STORE_POINTER_DIRECT(spark_spans_by_laser_power + 48, spark_frames_small_2);
    if (spark_setup_laser[8] != 0x8) {
        printf("error! tili_b[8]\n");
    }
    STORE_POINTER_DIRECT(spark_setup_laser + 8, spark_frames_long_0);
    if (spark_frames_long_1[80] != 0x8) {
        printf("error! tili_d1[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 80, spark_frames_long_1);
    if (spark_frames_long_1[96] != 0x8) {
        printf("error! tili_d2[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 96, spark_frames_long_1);
    if (spark_frames_long_1[112] != 0x8) {
        printf("error! tili_d3[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 112, spark_frames_long_1);
    if (spark_frames_long_1[128] != 0x8) {
        printf("error! tili_d4[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 128, spark_frames_long_1);
    if (spark_frames_long_1[144] != 0x8) {
        printf("error! tili_d5[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 144, spark_frames_long_1);
    if (spark_frames_long_1[160] != 0x8) {
        printf("error! tili_d6[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 160, spark_frames_long_1);
    if (spark_frames_long_1[176] != 0x8) {
        printf("error! tili_d7[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 176, spark_frames_long_1);
    if (spark_frames_long_1[192] != 0x8) {
        printf("error! tili_d8[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 192, spark_frames_long_1);
    if (spark_frames_long_1[208] != 0x8) {
        printf("error! tili_d9[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 208, spark_frames_long_1);
    if (spark_frames_long_1[224] != 0x8) {
        printf("error! tili_d10[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 224, spark_frames_long_1);
    if (spark_frames_long_1[240] != 0x8) {
        printf("error! tili_d11[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 240, spark_frames_long_1);
    if (spark_frames_long_1[256] != 0x8) {
        printf("error! tili_d12[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 256, spark_frames_long_1);
    if (spark_frames_long_1[272] != 0x8) {
        printf("error! tili_d13[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 272, spark_frames_long_1);
    if (spark_frames_long_1[288] != 0x8) {
        printf("error! tili_d14[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 288, spark_frames_long_1);
    if (spark_frames_long_1[304] != 0x8) {
        printf("error! tili_d15[8]\n");
    }
    STORE_POINTER_DIRECT(spark_frames_long_1 + 304, spark_frames_long_1);
    if (wreck_frames_11[16] != 0x8) {
        printf("error! zan_n0[8]\n");
    }
    STORE_POINTER_DIRECT(wreck_frames_11 + 16, wreck_frames_00);
    if (wreck_frames_11[18] != 0xa) {
        printf("error! zan_n0[10]\n");
    }
    STORE_POINTER_DIRECT(wreck_frames_11 + 18, wreck_frames_01);
    if (wreck_frames_11[20] != 0xc) {
        printf("error! zan_n0[12]\n");
    }
    STORE_POINTER_DIRECT(wreck_frames_11 + 20, wreck_frames_02);
    STORE_POINTER_DIRECT(wreck_frames_11 + 32, wreck_frames_03);
    if (wreck_frames_11[34] != 0xa) {
        printf("error! zan_n1[10]\n");
    }
    STORE_POINTER_DIRECT(wreck_frames_11 + 34, wreck_frames_04);
    if (wreck_frames_11[36] != 0xc) {
        printf("error! zan_n1[12]\n");
    }
    STORE_POINTER_DIRECT(wreck_frames_11 + 36, wreck_frames_05);
    if (wreck_frames_11[48] != 0x8) {
        printf("error! zan_n2[8]\n");
    }
    STORE_POINTER_DIRECT(wreck_frames_11 + 48, wreck_frames_06);
    if (wreck_frames_11[50] != 0xa) {
        printf("error! zan_n2[10]\n");
    }
    STORE_POINTER_DIRECT(wreck_frames_11 + 50, wreck_frames_07);
    if (wreck_frames_11[52] != 0xc) {
        printf("error! zan_n2[12]\n");
    }
    STORE_POINTER_DIRECT(wreck_frames_11 + 52, wreck_frames_08);
    if (wreck_frames_11[64] != 0x8) {
        printf("error! zan_n3[8]\n");
    }
    STORE_POINTER_DIRECT(wreck_frames_11 + 64, wreck_frames_09);
    if (wreck_frames_11[66] != 0xa) {
        printf("error! zan_n3[10]\n");
    }
    STORE_POINTER_DIRECT(wreck_frames_11 + 66, wreck_frames_10);
    if (wreck_frames_11[68] != 0xc) {
        printf("error! zan_n3[12]\n");
    }
    STORE_POINTER_DIRECT(wreck_frames_11 + 68, wreck_frames_11);
    if (ending_fade_in_table[4] != 0x4) {
        printf("error! end_fadein_tbl[4]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_table + 4, ((u16 *)ending_fade_in_table_at_4));
    if (ending_fade_in_table[11] != 0xb) {
        printf("error! end_fadein_tbl[11]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_table + 11, ending_fade_in_05);
    if (ending_fade_in_table[18] != 0x12) {
        printf("error! end_fadein_tbl[18]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_table + 18, ending_fade_in_09);
    if (ending_fade_in_group_0[4] != 0x4) {
        printf("error! end_fadein_g_tbl0[4]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_group_0 + 4, ending_fade_in_05);
    if (ending_fade_in_group_0[11] != 0xb) {
        printf("error! end_fadein_g_tbl0[11]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_group_0 + 11, ending_fade_in_09);
    if (ending_fade_in_group_1[4] != 0x4) {
        printf("error! end_fadein_g_tbl1[4]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_group_1 + 4, ending_fade_in_05);
    if (ending_fade_in_group_1[11] != 0xb) {
        printf("error! end_fadein_g_tbl1[11]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_group_1 + 11, ending_fade_in_09);
    if (ending_fade_in_group_2[4] != 0x4) {
        printf("error! end_fadein_g_tbl2[4]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_group_2 + 4, ending_fade_in_05);
    if (ending_fade_in_group_2[11] != 0xb) {
        printf("error! end_fadein_g_tbl2[11]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_group_2 + 11, ending_fade_in_09);
    if (ending_fade_in_group_3[4] != 0x4) {
        printf("error! end_fadein_g_tbl3[4]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_group_3 + 4, ending_fade_in_05);
    if (ending_fade_in_group_3[11] != 0xb) {
        printf("error! end_fadein_g_tbl3[11]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_group_3 + 11, ending_fade_in_09);
    if (ending_fade_in_group_4[4] != 0x4) {
        printf("error! end_fadein_g_tbl4[4]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_group_4 + 4, ending_fade_in_05);
    if (ending_fade_in_group_4[11] != 0xb) {
        printf("error! end_fadein_g_tbl4[11]\n");
    }
    STORE_POINTER_DIRECT(ending_fade_in_group_4 + 11, ending_fade_in_09);
    if (g_credits_script[3] != 0x3) {
        printf("error! stf_tbl[3]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 3, credits_text_00);
    if (g_credits_script[8] != 0x8) {
        printf("error! stf_tbl[8]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 8, credits_text_01);
    if (g_credits_script[13] != 0xd) {
        printf("error! stf_tbl[13]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 13, credits_text_02);
    if (g_credits_script[18] != 0x12) {
        printf("error! stf_tbl[18]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 18, credits_text_03);
    if (g_credits_script[23] != 0x17) {
        printf("error! stf_tbl[23]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 23, credits_text_04);
    if (g_credits_script[28] != 0x1c) {
        printf("error! stf_tbl[28]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 28, credits_text_05);
    if (g_credits_script[33] != 0x21) {
        printf("error! stf_tbl[33]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 33, credits_text_04);
    if (g_credits_script[38] != 0x26) {
        printf("error! stf_tbl[38]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 38, credits_text_07);
    if (g_credits_script[43] != 0x2b) {
        printf("error! stf_tbl[43]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 43, credits_text_08);
    if (g_credits_script[48] != 0x30) {
        printf("error! stf_tbl[48]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 48, credits_text_09);
    if (g_credits_script[53] != 0x35) {
        printf("error! stf_tbl[53]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 53, credits_text_10);
    if (g_credits_script[58] != 0x3a) {
        printf("error! stf_tbl[58]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 58, credits_text_11);
    if (g_credits_script[63] != 0x3f) {
        printf("error! stf_tbl[63]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 63, credits_text_12);
    if (g_credits_script[68] != 0x44) {
        printf("error! stf_tbl[68]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 68, credits_text_13);
    if (g_credits_script[73] != 0x49) {
        printf("error! stf_tbl[73]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 73, credits_text_10);
    if (g_credits_script[78] != 0x4e) {
        printf("error! stf_tbl[78]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 78, credits_text_15);
    if (g_credits_script[83] != 0x53) {
        printf("error! stf_tbl[83]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 83, credits_text_16);
    if (g_credits_script[88] != 0x58) {
        printf("error! stf_tbl[88]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 88, credits_text_17);
    if (g_credits_script[93] != 0x5d) {
        printf("error! stf_tbl[93]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 93, credits_text_16);
    if (g_credits_script[98] != 0x62) {
        printf("error! stf_tbl[98]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 98, credits_text_12);
    if (g_credits_script[103] != 0x67) {
        printf("error! stf_tbl[103]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 103, credits_text_20);
    if (g_credits_script[108] != 0x6c) {
        printf("error! stf_tbl[108]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 108, credits_text_12);
    if (g_credits_script[113] != 0x71) {
        printf("error! stf_tbl[113]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 113, credits_text_22);
    if (g_credits_script[118] != 0x76) {
        printf("error! stf_tbl[118]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 118, credits_text_23);
    if (g_credits_script[123] != 0x7b) {
        printf("error! stf_tbl[123]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 123, credits_text_24);
    if (g_credits_script[128] != 0x80) {
        printf("error! stf_tbl[128]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 128, credits_text_25);
    if (g_credits_script[133] != 0x85) {
        printf("error! stf_tbl[133]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 133, credits_text_26);
    if (g_credits_script[138] != 0x8a) {
        printf("error! stf_tbl[138]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 138, credits_text_27);
    if (g_credits_script[143] != 0x8f) {
        printf("error! stf_tbl[143]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 143, credits_text_28);
    if (g_credits_script[148] != 0x94) {
        printf("error! stf_tbl[148]\n");
    }
    STORE_POINTER_DIRECT(g_credits_script + 148, credits_text_29);
    if (g_credits_script[153] != 0x99) {
        printf("error! stf_tbl[153]\n");
    }
#ifdef DEATH_LABEL
    STORE_POINTER_DIRECT(g_credits_script + 153, credits_text_30);
    STORE_POINTER_DIRECT(g_credits_script + 158, g_credits_script_at_158);
    STORE_POINTER_DIRECT(g_credits_script + 163, g_credits_script_at_163);
    STORE_POINTER_DIRECT(g_credits_script + 168, g_credits_script_at_168);
    STORE_POINTER_DIRECT(death_D_0025495A, death_D_00254778);
    STORE_POINTER_DIRECT(death_D_00254964, death_D_00254790);
    STORE_POINTER_DIRECT(death_D_0025496E, death_D_002547A0);
    STORE_POINTER_DIRECT(death_D_00254978, death_D_002547B0);
    STORE_POINTER_DIRECT(death_D_00254982, death_D_002547C0);
#else
    STORE_POINTER_DIRECT(g_credits_script + 153, credits_text_30);
    STORE_POINTER_DIRECT(g_credits_script + 158, credits_text_31);
    STORE_POINTER_DIRECT(g_credits_script + 163, credits_text_32);
    STORE_POINTER_DIRECT(g_credits_script + 168, credits_text_33);
#endif
    if (scroll_event_routines[0] != 0x0) {
        printf("error! groevent_tbl[0]\n");
    }
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(scroll_event_palettes);
    ((u16 *)scroll_event_routines)[0] = reg_tmp.h[1];
    D_002526D2[0] = reg_tmp.h[0];
    if (scroll_event_routines[2] != 0x2) {
        printf("error! groevent_tbl[2]\n");
    }
    STORE_ARCADE_ADDRESS(scroll_event_routines + 2, scroll_event_map_loop);
    if (scroll_event_routines[4] != 0x4) {
        printf("error! groevent_tbl[4]\n");
    }
    STORE_ARCADE_ADDRESS(scroll_event_routines + 4, scroll_event_speed);
    if (scroll_event_routines[6] != 0x6) {
        printf("error! groevent_tbl[6]\n");
    }
    STORE_ARCADE_ADDRESS(scroll_event_routines + 6, scroll_event_line_hold);
    if (scroll_event_routines[8] != 0x8) {
        printf("error! groevent_tbl[8]\n");
    }
    STORE_ARCADE_ADDRESS(scroll_event_routines + 8, scroll_event_scenery);
    if (scroll_event_routines[10] != 0xa) {
        printf("error! groevent_tbl[10]\n");
    }
    STORE_ARCADE_ADDRESS(scroll_event_routines + 10, scroll_event_sounds);
    if (scroll_event_routines[12] != 0xc) {
        printf("error! groevent_tbl[12]\n");
    }
    STORE_ARCADE_ADDRESS(scroll_event_routines + 12, scroll_event_flags);
    if (scroll_sound_routines[0] != 0x0) {
        printf("error! gev_snd_proc_tbl[0]\n");
    }
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(scroll_sound_call);
    ((u16 *)scroll_sound_routines)[0] = reg_tmp.h[1];
    D_002526F2[0] = reg_tmp.h[0];
    if (scroll_sound_routines[2] != 0x2) {
        printf("error! gev_snd_proc_tbl[2]\n");
    }
    STORE_ARCADE_ADDRESS(scroll_sound_routines + 2, scroll_sound_music_stop);
    if (scroll_sound_routines[4] != 0x4) {
        printf("error! gev_snd_proc_tbl[4]\n");
    }
    STORE_ARCADE_ADDRESS(scroll_sound_routines + 4, scroll_sound_music_fade);
    if (stage_map_palettes[0] != 0x0) {
        printf("error! bg_pal_tbl[0]\n");
    }
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(g_stage1_map_palettes);
    ((u16 *)stage_map_palettes)[0] = reg_tmp.h[1];
    D_00252702[0] = reg_tmp.h[0];
    if (stage_map_palettes[2] != 0x2) {
        printf("error! bg_pal_tbl[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage_map_palettes + 2, g_stage2_map_palettes);
    if (stage_map_palettes[4] != 0x4) {
        printf("error! bg_pal_tbl[4]\n");
    }
    STORE_ARCADE_ADDRESS(stage_map_palettes + 4, g_stage3_map_palettes);
    if (stage_map_palettes[6] != 0x6) {
        printf("error! bg_pal_tbl[6]\n");
    }
    STORE_ARCADE_ADDRESS(stage_map_palettes + 6, g_stage4_map_palettes);
    if (stage_map_palettes[8] != 0x8) {
        printf("error! bg_pal_tbl[8]\n");
    }
    STORE_ARCADE_ADDRESS(stage_map_palettes + 8, g_stage5_map_palettes);
    if (stage_maps[0] != 0x0) {
        printf("error! stg_tbl[0]\n");
    }
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(g_stage1_map);
    ((u16 *)stage_maps)[0] = reg_tmp.h[1];
    D_00252722[0] = reg_tmp.h[0];
    if (stage_maps[2] != 0x2) {
        printf("error! stg_tbl[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage_maps + 2, g_stage2_map);
    if (stage_maps[4] != 0x4) {
        printf("error! stg_tbl[4]\n");
    }
    STORE_ARCADE_ADDRESS(stage_maps + 4, g_stage3_map);
    if (stage_maps[6] != 0x6) {
        printf("error! stg_tbl[6]\n");
    }
    STORE_ARCADE_ADDRESS(stage_maps + 6, g_stage4_map);
    if (stage_maps[8] != 0x8) {
        printf("error! stg_tbl[8]\n");
    }
    STORE_ARCADE_ADDRESS(stage_maps + 8, g_stage5_map);
    if (stage1_scroll_event_lists[0] != 0x0) {
        printf("error! gro_stg1_tbl[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_event_lists, stage1_scroll_events);
    if (stage1_scroll_event_lists[2] != 0x2) {
        printf("error! gro_stg1_tbl[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_event_lists + 2, stage1_plane2_scroll_events);
    if (stage2_scroll_event_lists[0] != 0x0) {
        printf("error! gro_stg2_tbl[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_event_lists, stage2_scroll_events);
    if (stage2_scroll_event_lists[2] != 0x2) {
        printf("error! gro_stg2_tbl[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_event_lists + 2, stage2_plane2_scroll_events);
    if (stage3_scroll_event_lists[0] != 0x0) {
        printf("error! gro_stg3_tbl[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_event_lists, stage3_scroll_events);
    if (stage3_scroll_event_lists[2] != 0x2) {
        printf("error! gro_stg3_tbl[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_event_lists + 2, stage3_plane2_scroll_events);
    if (stage4_scroll_event_lists[0] != 0x0) {
        printf("error! gro_stg4_tbl[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_event_lists, stage4_scroll_events);
    if (stage4_scroll_event_lists[2] != 0x2) {
        printf("error! gro_stg4_tbl[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_event_lists + 2, stage4_plane2_scroll_events);
    if (stage5_scroll_event_lists[0] != 0x0) {
        printf("error! gro_stg5_tbl[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_event_lists, stage5_scroll_events);
    if (stage5_scroll_event_lists[2] != 0x2) {
        printf("error! gro_stg5_tbl[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_event_lists + 2, stage5_plane2_scroll_events);
    if (stage_scroll_event_lists[0] != 0x0) {
        printf("error! gro_stg_tbl[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage_scroll_event_lists, stage1_scroll_event_lists);
    if (stage_scroll_event_lists[2] != 0x2) {
        printf("error! gro_stg_tbl[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage_scroll_event_lists + 2, stage2_scroll_event_lists);
    if (stage_scroll_event_lists[4] != 0x4) {
        printf("error! gro_stg_tbl[4]\n");
    }
    STORE_ARCADE_ADDRESS(stage_scroll_event_lists + 4, stage3_scroll_event_lists);
    if (stage_scroll_event_lists[6] != 0x6) {
        printf("error! gro_stg_tbl[6]\n");
    }
    STORE_ARCADE_ADDRESS(stage_scroll_event_lists + 6, stage4_scroll_event_lists);
    if (stage_scroll_event_lists[8] != 0x8) {
        printf("error! gro_stg_tbl[8]\n");
    }
    STORE_ARCADE_ADDRESS(stage_scroll_event_lists + 8, stage5_scroll_event_lists);
    if (stage1_scroll_palettes[0] != 0x0) {
        printf("error! avram_pal_tbl1[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes, stage1_palette_00);
    if (stage1_scroll_palettes[3] != 0x3) {
        printf("error! avram_pal_tbl1[3]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 3, stage1_palette_01);
    if (stage1_scroll_palettes[6] != 0x6) {
        printf("error! avram_pal_tbl1[6]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 6, stage1_palette_03);
    if (stage1_scroll_palettes[9] != 0x9) {
        printf("error! avram_pal_tbl1[9]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 9, stage1_palette_04);
    if (stage1_scroll_palettes[12] != 0xc) {
        printf("error! avram_pal_tbl1[12]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 12, stage1_scroll_palettes_at_12);
    if (stage1_scroll_palettes[15] != 0xf) {
        printf("error! avram_pal_tbl1[15]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 15, stage1_palette_07);
    if (stage1_scroll_palettes[18] != 0x12) {
        printf("error! avram_pal_tbl1[18]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 18, palette_black);
    if (stage1_scroll_palettes[21] != 0x15) {
        printf("error! avram_pal_tbl1[21]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 21, stage1_palette_10);
    if (stage1_scroll_palettes[24] != 0x18) {
        printf("error! avram_pal_tbl1[24]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 24, ((u16 *)D_002610B0));
    if (stage1_scroll_palettes[27] != 0x1b) {
        printf("error! avram_pal_tbl1[27]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 27, stage1_palette_13);
    if (stage1_scroll_palettes[30] != 0x1e) {
        printf("error! avram_pal_tbl1[30]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 30, D_00260FF0);
    if (stage1_scroll_palettes[33] != 0x21) {
        printf("error! avram_pal_tbl1[33]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 33, D_002610F0);
    if (stage1_scroll_palettes[36] != 0x24) {
        printf("error! avram_pal_tbl1[36]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 36, stage1_palette_18);
    if (stage1_scroll_palettes[39] != 0x27) {
        printf("error! avram_pal_tbl1[39]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 39, D_00261D70);
    if (stage1_scroll_palettes[42] != 0x2a) {
        printf("error! avram_pal_tbl1[42]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 42, D_00261170);
    if (stage1_scroll_palettes[45] != 0x2d) {
        printf("error! avram_pal_tbl1[45]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 45, D_00261130);
    if (stage1_scroll_palettes[48] != 0x30) {
        printf("error! avram_pal_tbl1[48]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 48, stage1_scroll_palettes_at_48);
    if (stage1_scroll_palettes[51] != 0x33) {
        printf("error! avram_pal_tbl1[51]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 51, D_002611B0);
    if (stage1_scroll_palettes[54] != 0x36) {
        printf("error! avram_pal_tbl1[54]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 54, D_002611F0);
    if (stage1_scroll_palettes[57] != 0x39) {
        printf("error! avram_pal_tbl1[57]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 57, stage1_palette_07);
    if (stage1_scroll_palettes[60] != 0x3c) {
        printf("error! avram_pal_tbl1[60]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 60, stage1_scroll_palettes_at_60);
    if (stage1_scroll_palettes[63] != 0x3f) {
        printf("error! avram_pal_tbl1[63]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_palettes + 63, stage1_scroll_palettes_at_63);
    if (stage1_scroll_sounds[4] != 0x4) {
        printf("error! avram_snd_tbl1[4]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_sounds + 4, music_play_bgm7);
    if (stage1_scroll_events[0] != 0x0) {
        printf("error! avram_tbl1[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_events, stage1_scroll_palettes);
    if (stage1_scroll_events[2] != 0x2) {
        printf("error! avram_tbl1[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage1_scroll_events + 2, stage1_scroll_sounds);
    if (stage2_scroll_palettes[0] != 0x0) {
        printf("error! avram_pal_tbl2[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes, palette_black);
    if (stage2_scroll_palettes[3] != 0x3) {
        printf("error! avram_pal_tbl2[3]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 3, stage1_palette_10);
    if (stage2_scroll_palettes[6] != 0x6) {
        printf("error! avram_pal_tbl2[6]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 6, ((u16 *)D_002610B0));
    if (stage2_scroll_palettes[9] != 0x9) {
        printf("error! avram_pal_tbl2[9]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 9, stage1_palette_13);
    if (stage2_scroll_palettes[12] != 0xc) {
        printf("error! avram_pal_tbl2[12]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 12, D_00260FF0);
    if (stage2_scroll_palettes[15] != 0xf) {
        printf("error! avram_pal_tbl2[15]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 15, D_002610F0);
    if (stage2_scroll_palettes[18] != 0x12) {
        printf("error! avram_pal_tbl2[18]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 18, stage1_palette_18);
    if (stage2_scroll_palettes[21] != 0x15) {
        printf("error! avram_pal_tbl2[21]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 21, D_00261D70);
    if (stage2_scroll_palettes[24] != 0x18) {
        printf("error! avram_pal_tbl2[24]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 24, stage1_palette_00);
    if (stage2_scroll_palettes[27] != 0x1b) {
        printf("error! avram_pal_tbl2[27]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 27, stage1_palette_01);
    if (stage2_scroll_palettes[30] != 0x1e) {
        printf("error! avram_pal_tbl2[30]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 30, stage1_palette_03);
    if (stage2_scroll_palettes[33] != 0x21) {
        printf("error! avram_pal_tbl2[33]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 33, stage2_scroll_palettes_at_33);
    if (stage2_scroll_palettes[36] != 0x24) {
        printf("error! avram_pal_tbl2[36]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 36, stage2_palette_18);
    if (stage2_scroll_palettes[39] != 0x27) {
        printf("error! avram_pal_tbl2[39]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 39, stage1_palette_07);
    if (stage2_scroll_palettes[42] != 0x2a) {
        printf("error! avram_pal_tbl2[42]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 42, stage1_palette_04);
    if (stage2_scroll_palettes[45] != 0x2d) {
        printf("error! avram_pal_tbl2[45]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 45, stage2_scroll_palettes_at_45);
    if (stage2_scroll_palettes[48] != 0x30) {
        printf("error! avram_pal_tbl2[48]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 48, stage2_scroll_palettes_at_48);
    if (stage2_scroll_palettes[51] != 0x33) {
        printf("error! avram_pal_tbl2[51]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 51, stage2_scroll_palettes_at_51);
    if (stage2_scroll_palettes[54] != 0x36) {
        printf("error! avram_pal_tbl2[54]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 54, stage2_scroll_palettes_at_54);
    if (stage2_scroll_palettes[57] != 0x39) {
        printf("error! avram_pal_tbl2[57]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 57, stage2_scroll_palettes_at_57);
    if (stage2_scroll_palettes[60] != 0x3c) {
        printf("error! avram_pal_tbl2[60]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 60, stage2_scroll_palettes_at_60);
    if (stage2_scroll_palettes[63] != 0x3f) {
        printf("error! avram_pal_tbl2[63]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 63, stage2_scroll_palettes_at_63);
    if (stage2_scroll_palettes[66] != 0x42) {
        printf("error! avram_pal_tbl2[66]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 66, stage2_scroll_palettes_at_66);
    if (stage2_scroll_palettes[69] != 0x45) {
        printf("error! avram_pal_tbl2[69]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 69, stage2_scroll_palettes_at_69);
    if (stage2_scroll_palettes[72] != 0x48) {
        printf("error! avram_pal_tbl2[72]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 72, stage2_scroll_palettes_at_72);
    if (stage2_scroll_palettes[75] != 0x4b) {
        printf("error! avram_pal_tbl2[75]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_palettes + 75, stage2_scroll_palettes_at_75);
    if (stage2_scroll_sounds[2] != 0x2) {
        printf("error! avram_snd_tbl2[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_sounds + 2, music_play_bgm3);
    if (stage2_scroll_sounds[8] != 0x8) {
        printf("error! avram_snd_tbl2[8]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_sounds + 8, music_play_bgm7);
    if (stage2_scroll_events[0] != 0x0) {
        printf("error! avram_tbl2[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_events, stage2_scroll_palettes);
    if (stage2_scroll_events[2] != 0x2) {
        printf("error! avram_tbl2[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage2_scroll_events + 2, stage2_scroll_sounds);
    if (stage3_scroll_palettes[0] != 0x0) {
        printf("error! avram_pal_tbl3[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes, palette_black);
    if (stage3_scroll_palettes[3] != 0x3) {
        printf("error! avram_pal_tbl3[3]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 3, stage1_palette_10);
    if (stage3_scroll_palettes[6] != 0x6) {
        printf("error! avram_pal_tbl3[6]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 6, ((u16 *)D_002610B0));
    if (stage3_scroll_palettes[9] != 0x9) {
        printf("error! avram_pal_tbl3[9]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 9, stage1_palette_13);
    if (stage3_scroll_palettes[12] != 0xc) {
        printf("error! avram_pal_tbl3[12]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 12, D_00260FF0);
    if (stage3_scroll_palettes[15] != 0xf) {
        printf("error! avram_pal_tbl3[15]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 15, D_002610F0);
    if (stage3_scroll_palettes[18] != 0x12) {
        printf("error! avram_pal_tbl3[18]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 18, stage1_palette_18);
    if (stage3_scroll_palettes[21] != 0x15) {
        printf("error! avram_pal_tbl3[21]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 21, D_00261D70);
    if (stage3_scroll_palettes[24] != 0x18) {
        printf("error! avram_pal_tbl3[24]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 24, stage1_palette_00);
    if (stage3_scroll_palettes[27] != 0x1b) {
        printf("error! avram_pal_tbl3[27]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 27, stage1_palette_01);
    if (stage3_scroll_palettes[30] != 0x1e) {
        printf("error! avram_pal_tbl3[30]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 30, stage1_palette_03);
    if (stage3_scroll_palettes[33] != 0x21) {
        printf("error! avram_pal_tbl3[33]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 33, stage3_palette_16);
    if (stage3_scroll_palettes[36] != 0x24) {
        printf("error! avram_pal_tbl3[36]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 36, stage2_palette_18);
    if (stage3_scroll_palettes[39] != 0x27) {
        printf("error! avram_pal_tbl3[39]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 39, stage1_palette_07);
    if (stage3_scroll_palettes[42] != 0x2a) {
        printf("error! avram_pal_tbl3[42]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 42, stage1_palette_04);
    if (stage3_scroll_palettes[45] != 0x2d) {
        printf("error! avram_pal_tbl3[45]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 45, stage1_palette_03);
    if (stage3_scroll_palettes[48] != 0x30) {
        printf("error! avram_pal_tbl3[48]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 48, stage3_scroll_palettes_at_48);
    if (stage3_scroll_palettes[51] != 0x33) {
        printf("error! avram_pal_tbl3[51]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 51, stage1_palette_01);
    if (stage3_scroll_palettes[54] != 0x36) {
        printf("error! avram_pal_tbl3[54]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 54, stage3_scroll_palettes_at_54);
    if (stage3_scroll_palettes[57] != 0x39) {
        printf("error! avram_pal_tbl3[57]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 57, stage3_scroll_palettes_at_57);
    if (stage3_scroll_palettes[60] != 0x3c) {
        printf("error! avram_pal_tbl3[60]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 60, stage3_midboss_flash_palettes_05);
    if (stage3_scroll_palettes[63] != 0x3f) {
        printf("error! avram_pal_tbl3[63]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 63, stage3_scroll_palettes_at_63);
    if (stage3_scroll_palettes[66] != 0x42) {
        printf("error! avram_pal_tbl3[66]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 66, stage3_scroll_palettes_at_66);
    if (stage3_scroll_palettes[69] != 0x45) {
        printf("error! avram_pal_tbl3[69]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_palettes + 69, stage3_scroll_palettes_at_69);
    if (stage3_scroll_sounds[2] != 0x2) {
        printf("error! avram_snd_tbl3[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_sounds + 2, music_play_bgm4);
    if (stage3_scroll_sounds[8] != 0x8) {
        printf("error! avram_snd_tbl3[8]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_sounds + 8, music_play_bgm7);
    if (stage3_scroll_events[0] != 0x0) {
        printf("error! avram_tbl3[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_events, stage3_scroll_palettes);
    if (stage3_scroll_events[2] != 0x2) {
        printf("error! avram_tbl3[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage3_scroll_events + 2, stage3_scroll_sounds);
    if (stage4_scroll_palettes[0] != 0x0) {
        printf("error! avram_pal_tbl4[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes, palette_black);
    if (stage4_scroll_palettes[3] != 0x3) {
        printf("error! avram_pal_tbl4[3]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 3, stage1_palette_10);
    if (stage4_scroll_palettes[6] != 0x6) {
        printf("error! avram_pal_tbl4[6]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 6, ((u16 *)D_002610B0));
    if (stage4_scroll_palettes[9] != 0x9) {
        printf("error! avram_pal_tbl4[9]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 9, stage1_palette_13);
    if (stage4_scroll_palettes[12] != 0xc) {
        printf("error! avram_pal_tbl4[12]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 12, D_00260FF0);
    if (stage4_scroll_palettes[15] != 0xf) {
        printf("error! avram_pal_tbl4[15]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 15, D_002610F0);
    if (stage4_scroll_palettes[18] != 0x12) {
        printf("error! avram_pal_tbl4[18]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 18, stage1_palette_18);
    if (stage4_scroll_palettes[21] != 0x15) {
        printf("error! avram_pal_tbl4[21]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 21, D_00261D70);
    if (stage4_scroll_palettes[24] != 0x18) {
        printf("error! avram_pal_tbl4[24]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 24, stage1_palette_00);
    if (stage4_scroll_palettes[27] != 0x1b) {
        printf("error! avram_pal_tbl4[27]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 27, stage1_palette_01);
    if (stage4_scroll_palettes[30] != 0x1e) {
        printf("error! avram_pal_tbl4[30]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 30, stage1_palette_03);
    if (stage4_scroll_palettes[33] != 0x21) {
        printf("error! avram_pal_tbl4[33]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 33, stage2_palette_18);
    if (stage4_scroll_palettes[36] != 0x24) {
        printf("error! avram_pal_tbl4[36]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 36, stage1_palette_07);
    if (stage4_scroll_palettes[39] != 0x27) {
        printf("error! avram_pal_tbl4[39]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 39, stage4_scroll_palettes_at_39);
    if (stage4_scroll_palettes[42] != 0x2a) {
        printf("error! avram_pal_tbl4[42]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 42, stage4_scroll_palettes_at_42);
    if (stage4_scroll_palettes[45] != 0x2d) {
        printf("error! avram_pal_tbl4[45]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 45, stage4_scroll_palettes_at_45);
    if (stage4_scroll_palettes[48] != 0x30) {
        printf("error! avram_pal_tbl4[48]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 48, ((u16 *)stage4_scroll_palettes_at_48));
    if (stage4_scroll_palettes[51] != 0x33) {
        printf("error! avram_pal_tbl4[51]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 51, stage4_scroll_palettes_at_51);
    if (stage4_scroll_palettes[54] != 0x36) {
        printf("error! avram_pal_tbl4[54]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 54, stage4_scroll_palettes_at_54);
    if (stage4_scroll_palettes[57] != 0x39) {
        printf("error! avram_pal_tbl4[57]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 57, stage4_scroll_palettes_at_57);
    if (stage4_scroll_palettes[60] != 0x3c) {
        printf("error! avram_pal_tbl4[60]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 60, stage4_scroll_palettes_at_39);
    if (stage4_scroll_palettes[63] != 0x3f) {
        printf("error! avram_pal_tbl4[63]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_palettes + 63, stage4_scroll_palettes_at_63);
    if (stage4_scroll_sounds[2] != 0x2) {
        printf("error! avram_snd_tbl4[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_sounds + 2, music_play_bgm5);
    if (stage4_scroll_sounds[8] != 0x8) {
        printf("error! avram_snd_tbl4[8]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_sounds + 8, music_play_bgm7);
    if (stage4_scroll_events[0] != 0x0) {
        printf("error! avram_tbl4[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_events, stage4_scroll_palettes);
    if (stage4_scroll_events[2] != 0x2) {
        printf("error! avram_tbl4[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage4_scroll_events + 2, stage4_scroll_sounds);
    if (stage5_scroll_palettes[0] != 0x0) {
        printf("error! avram_pal_tbl5[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes, palette_black);
    if (stage5_scroll_palettes[3] != 0x3) {
        printf("error! avram_pal_tbl5[3]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 3, stage1_palette_10);
    if (stage5_scroll_palettes[6] != 0x6) {
        printf("error! avram_pal_tbl5[6]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 6, ((u16 *)D_002610B0));
    if (stage5_scroll_palettes[9] != 0x9) {
        printf("error! avram_pal_tbl5[9]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 9, stage1_palette_13);
    if (stage5_scroll_palettes[12] != 0xc) {
        printf("error! avram_pal_tbl5[12]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 12, D_00260FF0);
    if (stage5_scroll_palettes[15] != 0xf) {
        printf("error! avram_pal_tbl5[15]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 15, D_002610F0);
    if (stage5_scroll_palettes[18] != 0x12) {
        printf("error! avram_pal_tbl5[18]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 18, stage1_palette_18);
    if (stage5_scroll_palettes[21] != 0x15) {
        printf("error! avram_pal_tbl5[21]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 21, D_00261D70);
    if (stage5_scroll_palettes[24] != 0x18) {
        printf("error! avram_pal_tbl5[24]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 24, stage1_palette_00);
    if (stage5_scroll_palettes[27] != 0x1b) {
        printf("error! avram_pal_tbl5[27]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 27, stage1_palette_01);
    if (stage5_scroll_palettes[30] != 0x1e) {
        printf("error! avram_pal_tbl5[30]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 30, stage1_palette_03);
    if (stage5_scroll_palettes[33] != 0x21) {
        printf("error! avram_pal_tbl5[33]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 33, stage2_palette_18);
    if (stage5_scroll_palettes[36] != 0x24) {
        printf("error! avram_pal_tbl5[36]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 36, stage1_palette_07);
    if (stage5_scroll_palettes[39] != 0x27) {
        printf("error! avram_pal_tbl5[39]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 39, stage3_palette_16);
    if (stage5_scroll_palettes[42] != 0x2a) {
        printf("error! avram_pal_tbl5[42]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 42, stage5_scroll_palettes_at_42);
    if (stage5_scroll_palettes[45] != 0x2d) {
        printf("error! avram_pal_tbl5[45]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 45, stage5_scroll_palettes_at_45);
    if (stage5_scroll_palettes[48] != 0x30) {
        printf("error! avram_pal_tbl5[48]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 48, stage1_palette_04);
    if (stage5_scroll_palettes[51] != 0x33) {
        printf("error! avram_pal_tbl5[51]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 51, stage5_scroll_palettes_at_51);
    if (stage5_scroll_palettes[54] != 0x36) {
        printf("error! avram_pal_tbl5[54]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 54, stage5_scroll_palettes_at_54);
    if (stage5_scroll_palettes[57] != 0x39) {
        printf("error! avram_pal_tbl5[57]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_palettes + 57, stage5_scroll_palettes_at_57);
    if (stage5_scroll_sounds[2] != 0x2) {
        printf("error! avram_snd_tbl5[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_sounds + 2, music_play_bgm6);
    if (stage5_scroll_sounds[8] != 0x8) {
        printf("error! avram_snd_tbl5[8]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_sounds + 8, music_play_bgm8);
    if (stage5_scroll_events[0] != 0x0) {
        printf("error! avram_tbl5[0]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_events, stage5_scroll_palettes);
    if (stage5_scroll_events[2] != 0x2) {
        printf("error! avram_tbl5[2]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_scroll_events + 2, stage5_scroll_sounds);
    if (D_0025BF98[0] != 0x4) {
        printf("error! name_fin_tbl[4]\n");
    }
    STORE_POINTER(D_0025BF98, D_00261F30);
    if (D_0025BFA6[0] != 0xb) {
        printf("error! name_fin_tbl[11]\n");
    }
    STORE_POINTER(D_0025BFA6, ((u16 *)name_entry_task_begin_table_2));
    if (D_0025BFB4[0] != 0x12) {
        printf("error! name_fin_tbl[18]\n");
    }
    STORE_POINTER(D_0025BFB4, ((u16 *)name_entry_task_begin_table_3));
    if (D_0025BFC2[0] != 0x19) {
        printf("error! name_fin_tbl[25]\n");
    }
    STORE_POINTER(D_0025BFC2, ((u16 *)name_entry_task_begin_table));
    if (name_entry_letter_table[0] != 0x0) {
        printf("error! nam_mozi_dir[0]\n");
    }
    STORE_POINTER(name_entry_letter_table, name_entry_letter_table_at_0);
    if (name_entry_letter_table[2] != 0x2) {
        printf("error! nam_mozi_dir[2]\n");
    }
    STORE_POINTER(name_entry_letter_table + 2, name_entry_letter_table_at_2);
    if (name_entry_letter_table[4] != 0x4) {
        printf("error! nam_mozi_dir[4]\n");
    }
    STORE_POINTER(name_entry_letter_table + 4, name_entry_letter_table_at_4);
    if (name_entry_letter_table[6] != 0x6) {
        printf("error! nam_mozi_dir[6]\n");
    }
    STORE_POINTER(name_entry_letter_table + 6, name_entry_letter_table_at_6);
    if (name_entry_letter_table[8] != 0x8) {
        printf("error! nam_mozi_dir[8]\n");
    }
    STORE_POINTER(name_entry_letter_table + 8, name_entry_letter_table_at_8);
    if (name_entry_letter_table[10] != 0xa) {
        printf("error! nam_mozi_dir[10]\n");
    }
    STORE_POINTER(name_entry_letter_table + 10, name_entry_letter_table_at_10);
    if (name_entry_letter_table[12] != 0xc) {
        printf("error! nam_mozi_dir[12]\n");
    }
    STORE_POINTER(name_entry_letter_table + 12, name_entry_letter_table_at_12);
    if (name_entry_letter_table[14] != 0xe) {
        printf("error! nam_mozi_dir[14]\n");
    }
    STORE_POINTER(name_entry_letter_table + 14, name_entry_letter_table_at_14);
    if (name_entry_letter_table[16] != 0x10) {
        printf("error! nam_mozi_dir[16]\n");
    }
    STORE_POINTER(name_entry_letter_table + 16, name_entry_letter_table_at_16);
    if (name_entry_letter_table[18] != 0x12) {
        printf("error! nam_mozi_dir[18]\n");
    }
    STORE_POINTER(name_entry_letter_table + 18, name_entry_letter_table_at_18);
    if (name_entry_letter_table[20] != 0x14) {
        printf("error! nam_mozi_dir[20]\n");
    }
    STORE_POINTER(name_entry_letter_table + 20, name_entry_letter_table_at_20);
    if (name_entry_letter_table[22] != 0x16) {
        printf("error! nam_mozi_dir[22]\n");
    }
    STORE_POINTER(name_entry_letter_table + 22, name_entry_letter_table_at_22);
    if (name_entry_letter_table[24] != 0x18) {
        printf("error! nam_mozi_dir[24]\n");
    }
    STORE_POINTER(name_entry_letter_table + 24, name_entry_letter_table_at_24);
    if (name_entry_letter_table[26] != 0x1a) {
        printf("error! nam_mozi_dir[26]\n");
    }
    STORE_POINTER(name_entry_letter_table + 26, name_entry_letter_table_at_26);
    if (name_entry_letter_table[28] != 0x1c) {
        printf("error! nam_mozi_dir[28]\n");
    }
    STORE_POINTER(name_entry_letter_table + 28, name_entry_letter_table_at_28);
    if (name_entry_letter_table[30] != 0x1e) {
        printf("error! nam_mozi_dir[30]\n");
    }
    STORE_POINTER(name_entry_letter_table + 30, name_entry_letter_table_at_30);
    if (name_entry_letter_table[32] != 0x20) {
        printf("error! nam_mozi_dir[32]\n");
    }
    STORE_POINTER(name_entry_letter_table + 32, name_entry_letter_table_at_32);
    if (name_entry_letter_table[34] != 0x22) {
        printf("error! nam_mozi_dir[34]\n");
    }
    STORE_POINTER(name_entry_letter_table + 34, name_entry_letter_table_at_34);
    if (name_entry_letter_table[36] != 0x24) {
        printf("error! nam_mozi_dir[36]\n");
    }
    STORE_POINTER(name_entry_letter_table + 36, name_entry_letter_table_at_36);
    if (name_entry_letter_table[38] != 0x26) {
        printf("error! nam_mozi_dir[38]\n");
    }
    STORE_POINTER(name_entry_letter_table + 38, name_entry_letter_table_at_38);
    if (name_entry_letter_table[40] != 0x28) {
        printf("error! nam_mozi_dir[40]\n");
    }
    STORE_POINTER(name_entry_letter_table + 40, name_entry_letter_table_at_40);
    if (name_entry_letter_table[42] != 0x2a) {
        printf("error! nam_mozi_dir[42]\n");
    }
    STORE_POINTER(name_entry_letter_table + 42, name_entry_letter_table_at_42);
    if (name_entry_letter_table[44] != 0x2c) {
        printf("error! nam_mozi_dir[44]\n");
    }
    STORE_POINTER(name_entry_letter_table + 44, name_entry_letter_table_at_44);
    if (name_entry_letter_table[46] != 0x2e) {
        printf("error! nam_mozi_dir[46]\n");
    }
    STORE_POINTER(name_entry_letter_table + 46, name_entry_letter_table_at_46);
    if (name_entry_letter_table[48] != 0x30) {
        printf("error! nam_mozi_dir[48]\n");
    }
    STORE_POINTER(name_entry_letter_table + 48, name_entry_letter_table_at_48);
    if (name_entry_letter_table[50] != 0x32) {
        printf("error! nam_mozi_dir[50]\n");
    }
    STORE_POINTER(name_entry_letter_table + 50, name_entry_letter_table_at_50);
    if (name_entry_letter_table[52] != 0x34) {
        printf("error! nam_mozi_dir[52]\n");
    }
    STORE_POINTER(name_entry_letter_table + 52, name_entry_letter_table_at_52);
    if (name_entry_letter_table[54] != 0x36) {
        printf("error! nam_mozi_dir[54]\n");
    }
    STORE_POINTER(name_entry_letter_table + 54, name_entry_letter_table_at_54);
    if (doll_select_p1.held[0] != 0x1) {
        printf("error! dollsel_data_1p[1]\n");
    }
    STORE_POINTER(doll_select_p1.held, input_get_p1_held);
    if (doll_select_p1.pressed[0] != 0x3) {
        printf("error! dollsel_data_1p[3]\n");
    }
    STORE_POINTER(doll_select_p1.pressed, input_get_p1_pressed);
    if (doll_select_p2.held[0] != 0x1) {
        printf("error! dollsel_data_2p[1]\n");
    }
    STORE_POINTER(doll_select_p2.held, input_get_p2_held);
    if (doll_select_p2.pressed[0] != 0x3) {
        printf("error! dollsel_data_2p[3]\n");
    }
    STORE_POINTER(doll_select_p2.pressed, input_get_p2_pressed);
    if (D_00251AB0_as_u16_a[1] != 0x1) {
        printf("error! figsel_data_1p[1]\n");
    }
    STORE_POINTER(D_00251AB0_as_u16_a + 1, input_get_p1_held);
    if (D_00251AB4[1] != 0x3) {
        printf("error! figsel_data_1p[3]\n");
    }
    STORE_POINTER(D_00251AB4 + 1, input_get_p1_pressed);
    if (D_00251AC0_as_u16_a[1] != 0x1) {
        printf("error! figsel_data_2p[1]\n");
    }
    STORE_POINTER(D_00251AC0_as_u16_a + 1, input_get_p2_held);
    if (D_00251AC4[1] != 0x3) {
        printf("error! figsel_data_2p[3]\n");
    }
    STORE_POINTER(D_00251AC4 + 1, input_get_p2_pressed);
    if (join_select_p1_table[2] != 0x2) {
        printf("error! sel_game_tbl_1p[2]\n");
    }
    STORE_POINTER(join_select_p1_table + 2, input_get_p1_held);
    if (join_select_p1_table[4] != 0x4) {
        printf("error! sel_game_tbl_1p[4]\n");
    }
    STORE_POINTER(join_select_p1_table + 4, input_get_p1_pressed);
    if (join_select_p1_table[6] != 0x6) {
        printf("error! sel_game_tbl_1p[6]\n");
    }
    STORE_POINTER(join_select_p1_table + 6, p1_credit_spend_one);
    if (join_select_p1_table[8] != 0x8) {
        printf("error! sel_game_tbl_1p[8]\n");
    }
    STORE_POINTER(join_select_p1_table + 8, ((u16 *)join_select_p1_table_at_8));
    if (join_select_p2_table[2] != 0x2) {
        printf("error! sel_game_tbl_2p[2]\n");
    }
    STORE_POINTER(join_select_p2_table + 2, input_get_p2_held);
    if (join_select_p2_table[4] != 0x4) {
        printf("error! sel_game_tbl_2p[4]\n");
    }
    STORE_POINTER(join_select_p2_table + 4, input_get_p2_pressed);
    if (join_select_p2_table[6] != 0x6) {
        printf("error! sel_game_tbl_2p[6]\n");
    }
    STORE_POINTER(join_select_p2_table + 6, p2_credit_spend_one);
    if (join_select_p2_table[8] != 0x8) {
        printf("error! sel_game_tbl_2p[8]\n");
    }
    STORE_POINTER(join_select_p2_table + 8, ((u16 *)join_select_p2_table_at_8));
    if (D_00251CC0[0] != 0x0) {
        printf("error! sel_win_kyok_tbl[0]\n");
    }
    STORE_POINTER(D_00251CC0, D_00251CE0);
    if (D_00251CC0[2] != 0x2) {
        printf("error! sel_win_kyok_tbl[2]\n");
    }
    STORE_POINTER(D_00251CC0 + 2, D_00260F30);
    if (D_00251CC0[4] != 0x4) {
        printf("error! sel_win_kyok_tbl[4]\n");
    }
    STORE_POINTER(D_00251CC0 + 4, D_00251D10);
    if (D_00251CC0[6] != 0x6) {
        printf("error! sel_win_kyok_tbl[6]\n");
    }
    STORE_POINTER(D_00251CC0 + 6, D_00260EF0);
    if (D_00251CC0[8] != 0x8) {
        printf("error! sel_win_kyok_tbl[8]\n");
    }
    STORE_POINTER(D_00251CC0 + 8, D_00251D40);
    if (D_00251CC0[10] != 0xa) {
        printf("error! sel_win_kyok_tbl[10]\n");
    }
    STORE_POINTER(D_00251CC0 + 10, D_00260EB0);
    if (select_panel_piece_2_draw_table_as_u16_a[0] != 0x0) {
        printf("error! subsel_fig_barner[0]\n");
    }
    STORE_POINTER(select_panel_piece_2_draw_table_as_u16_a, D_0028C680);
    if (D_0028C14A[1] != 0x2) {
        printf("error! subsel_fig_barner[2]\n");
    }
    STORE_POINTER(D_0028C14A + 1, player_exhaust_sprites_01_at_0);
    if (D_00252010[0] != 0x0) {
        printf("error! subsel_txt_chr_1p[0]\n");
    }
    STORE_POINTER(D_00252010, D_00252020);
    if (D_00252010[2] != 0x2) {
        printf("error! subsel_txt_chr_1p[2]\n");
    }
    STORE_POINTER(D_00252010 + 2, D_00252030);
    if (D_00252010[4] != 0x4) {
        printf("error! subsel_txt_chr_1p[4]\n");
    }
    STORE_POINTER(D_00252010 + 4, D_00252040);
    if (D_00252020[0] != 0x0) {
        printf("error! subsel_kyok_txt_1p[0]\n");
    }
    STORE_POINTER(D_00252020, D_00252090);
    if (D_00252020[2] != 0x2) {
        printf("error! subsel_kyok_txt_1p[2]\n");
    }
    STORE_POINTER(D_00252020 + 2, D_002520A0);
    if (D_00252020[4] != 0x4) {
        printf("error! subsel_kyok_txt_1p[4]\n");
    }
    STORE_POINTER(D_00252020 + 4, D_002520B0);
    if (D_00252030[0] != 0x0) {
        printf("error! subsel_setu_txt_1p[0]\n");
    }
    STORE_POINTER(D_00252030, D_002520C0);
    if (D_00252030[2] != 0x2) {
        printf("error! subsel_setu_txt_1p[2]\n");
    }
    STORE_POINTER(D_00252030 + 2, D_002520D0);
    if (D_00252030[4] != 0x4) {
        printf("error! subsel_setu_txt_1p[4]\n");
    }
    STORE_POINTER(D_00252030 + 4, D_002520E0);
    if (D_00252040[0] != 0x0) {
        printf("error! subsel_bom_txt_1p[0]\n");
    }
    STORE_POINTER(D_00252040, D_002520F0);
    if (D_00252040[2] != 0x2) {
        printf("error! subsel_bom_txt_1p[2]\n");
    }
    STORE_POINTER(D_00252040 + 2, D_00252100);
    if (D_00252040[4] != 0x4) {
        printf("error! subsel_bom_txt_1p[4]\n");
    }
    STORE_POINTER(D_00252040 + 4, D_00252110);
    if (D_00252050[0] != 0x0) {
        printf("error! subsel_txt_chr_2p[0]\n");
    }
    STORE_POINTER(D_00252050, D_00252060);
    if (D_00252050[2] != 0x2) {
        printf("error! subsel_txt_chr_2p[2]\n");
    }
    STORE_POINTER(D_00252050 + 2, D_00252070);
    if (D_00252050[4] != 0x4) {
        printf("error! subsel_txt_chr_2p[4]\n");
    }
    STORE_POINTER(D_00252050 + 4, D_00252080);
    if (D_00252060[0] != 0x0) {
        printf("error! subsel_kyok_txt_2p[0]\n");
    }
    STORE_POINTER(D_00252060, D_00252120);
    if (D_00252060[2] != 0x2) {
        printf("error! subsel_kyok_txt_2p[2]\n");
    }
    STORE_POINTER(D_00252060 + 2, D_00252130);
    if (D_00252060[4] != 0x4) {
        printf("error! subsel_kyok_txt_2p[4]\n");
    }
    STORE_POINTER(D_00252060 + 4, D_00252140);
    if (D_00252070[0] != 0x0) {
        printf("error! subsel_setu_txt_2p[0]\n");
    }
    STORE_POINTER(D_00252070, D_00252150);
    if (D_00252070[2] != 0x2) {
        printf("error! subsel_setu_txt_2p[2]\n");
    }
    STORE_POINTER(D_00252070 + 2, D_00252160);
    if (D_00252070[4] != 0x4) {
        printf("error! subsel_setu_txt_2p[4]\n");
    }
    STORE_POINTER(D_00252070 + 4, D_00252170);
    if (D_00252080[0] != 0x0) {
        printf("error! subsel_bom_txt_2p[0]\n");
    }
    STORE_POINTER(D_00252080, D_00252180);
    if (D_00252080[2] != 0x2) {
        printf("error! subsel_bom_txt_2p[2]\n");
    }
    STORE_POINTER(D_00252080 + 2, D_00252190);
    if (D_00252080[4] != 0x4) {
        printf("error! subsel_bom_txt_2p[4]\n");
    }
    STORE_POINTER(D_00252080 + 4, D_002521A0);
    if (D_002520C0[3] != 0x3) {
        printf("error! subsel_setu_txt_1p_a[3]\n");
    }
    STORE_POINTER(D_002520C0 + 3, D_002521B0);
    if (D_002520D0[3] != 0x3) {
        printf("error! subsel_setu_txt_1p_b[3]\n");
    }
    STORE_POINTER(D_002520D0 + 3, D_002521D0);
    if (D_002520E0[3] != 0x3) {
        printf("error! subsel_setu_txt_1p_c[3]\n");
    }
    STORE_POINTER(D_002520E0 + 3, D_002521F0);
    if (D_00252150[3] != 0x3) {
        printf("error! subsel_setu_txt_2p_a[3]\n");
    }
    STORE_POINTER(D_00252150 + 3, D_002521B0);
    if (D_00252160[3] != 0x3) {
        printf("error! subsel_setu_txt_2p_b[3]\n");
    }
    STORE_POINTER(D_00252160 + 3, D_002521D0);
    if (D_00252170[3] != 0x3) {
        printf("error! subsel_setu_txt_2p_c[3]\n");
    }
    STORE_POINTER(D_00252170 + 3, D_002521F0);
    if (D_00252210[0] != 0x0) {
        printf("error! subsel_att_chr_1p[0]\n");
    }
    STORE_POINTER(D_00252210, D_00252230);
    if (D_00252210[2] != 0x2) {
        printf("error! subsel_att_chr_1p[2]\n");
    }
    STORE_POINTER(D_00252210 + 2, D_00252240);
    if (D_00252210[4] != 0x4) {
        printf("error! subsel_att_chr_1p[4]\n");
    }
    STORE_POINTER(D_00252210 + 4, D_00252250);
    if (D_00252220[0] != 0x0) {
        printf("error! subsel_att_chr_2p[0]\n");
    }
    STORE_POINTER(D_00252220, D_00252268);
    if (D_00252220[2] != 0x2) {
        printf("error! subsel_att_chr_2p[2]\n");
    }
    STORE_POINTER(D_00252220 + 2, D_00252278);
    if (D_00252220[4] != 0x4) {
        printf("error! subsel_att_chr_2p[4]\n");
    }
    STORE_POINTER(D_00252220 + 4, D_00252290);
    if (D_00252230[3] != 0x3) {
        printf("error! subsel_att_chr_1p_a[3]\n");
    }
    STORE_POINTER(D_00252230 + 3, D_002522B0);
    if (D_00252240[3] != 0x3) {
        printf("error! subsel_att_chr_1p_b[3]\n");
    }
    STORE_POINTER(D_00252240 + 3, D_002522D0);
    if (D_00252250[3] != 0x3) {
        printf("error! subsel_att_chr_1p_c[3]\n");
    }
    STORE_POINTER(D_00252250 + 3, D_002522F0);
    if (D_00252250[8] != 0x8) {
        printf("error! subsel_att_chr_1p_c[8]\n");
    }
    STORE_POINTER(D_00252250 + 8, D_00252310);
    if (D_00252268[3] != 0x3) {
        printf("error! subsel_att_chr_2p_a[3]\n");
    }
    STORE_POINTER(D_00252268 + 3, D_002522B0);
    if (D_00252278[3] != 0x3) {
        printf("error! subsel_att_chr_2p_b[3]\n");
    }
    STORE_POINTER(D_00252278 + 3, D_002522D0);
    if (D_00252290[3] != 0x3) {
        printf("error! subsel_att_chr_2p_c[3]\n");
    }
    STORE_POINTER(D_00252290 + 3, D_002522F0);
    if (D_00252290[8] != 0x8) {
        printf("error! subsel_att_chr_2p_c[8]\n");
    }
    STORE_POINTER(D_00252290 + 8, D_00252310);
    if (stage5_boss_horn_shot_offsets[0] != 0x0) {
        printf("error! st5b_2_tsuno_sht_ofs_tbl[0]\n");
    }
    reg_tmp.w = (u32)D_002644E0;
    stage5_boss_horn_shot_offsets[0] = reg_tmp.h[1];
    stage5_boss_horn_shot_offsets[1] = reg_tmp.h[0];
    if (stage5_boss_horn_shot_offsets[2] != 0x2) {
        printf("error! st5b_2_tsuno_sht_ofs_tbl[2]\n");
    }
    STORE_POINTER(stage5_boss_horn_shot_offsets + 2, stage5_boss_horn_shot_offsets_at_2);
    if (stage5_boss_horn_shot_offsets[4] != 0x4) {
        printf("error! st5b_2_tsuno_sht_ofs_tbl[4]\n");
    }
    STORE_POINTER(stage5_boss_horn_shot_offsets + 4, stage5_boss_horn_shot_offsets_at_4);
    if (stage5_boss_horn_shot_offsets[6] != 0x6) {
        printf("error! st5b_2_tsuno_sht_ofs_tbl[6]\n");
    }
    STORE_POINTER(stage5_boss_horn_shot_offsets + 6, stage5_boss_horn_shot_offsets_at_6);
    if (stage5_boss_flash_palettes_a[4] != 0x4) {
        printf("error! st5b_mo1_flush_tbl[4]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 4, D_002610F0);
    if (stage5_boss_flash_palettes_a[11] != 0xb) {
        printf("error! st5b_mo1_flush_tbl[11]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 11, ((u16 *)D_0025FF70));
    if (stage5_boss_flash_palettes_a[18] != 0x12) {
        printf("error! st5b_mo1_flush_tbl[18]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 18, ((u16 *)D_0025FFB0));
    if (stage5_boss_flash_palettes_a[25] != 0x19) {
        printf("error! st5b_mo1_flush_tbl[25]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 25, ((u16 *)D_0025FFF0));
    if (stage5_boss_flash_palettes_a[32] != 0x20) {
        printf("error! st5b_mo1_flush_tbl[32]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 32, ((u16 *)stage5_boss_flash_palettes_a_at_32));
    if (stage5_boss_flash_palettes_a[39] != 0x27) {
        printf("error! st5b_mo1_flush_tbl[39]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 39, ((u16 *)stage5_boss_flash_palettes_a_at_39));
    if (stage5_boss_flash_palettes_a[46] != 0x2e) {
        printf("error! st5b_mo1_flush_tbl[46]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 46, ((u16 *)stage5_boss_flash_palettes_a_at_46));
    if (stage5_boss_flash_palettes_a[53] != 0x35) {
        printf("error! st5b_mo1_flush_tbl[53]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 53, ((u16 *)D_002600F0));
    if (stage5_boss_flash_palettes_a[60] != 0x3c) {
        printf("error! st5b_mo1_flush_tbl[60]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 60, stage5_boss_flash_palettes_a_30);
    if (stage5_boss_flash_palettes_a[67] != 0x43) {
        printf("error! st5b_mo1_flush_tbl[67]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 67, stage5_boss_flash_palettes_a_33);
    if (stage5_boss_flash_palettes_a[74] != 0x4a) {
        printf("error! st5b_mo1_flush_tbl[74]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 74, stage5_boss_flash_palettes_a_37);
    if (stage5_boss_flash_palettes_a[81] != 0x51) {
        printf("error! st5b_mo1_flush_tbl[81]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 81, stage5_boss_flash_palettes_a_40);
    if (stage5_boss_flash_palettes_a[88] != 0x58) {
        printf("error! st5b_mo1_flush_tbl[88]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 88, stage5_boss_flash_palettes_a_44);
    if (stage5_boss_flash_palettes_a[95] != 0x5f) {
        printf("error! st5b_mo1_flush_tbl[95]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_a + 95, stage5_boss_flash_palettes_a_47);
    if (stage5_boss_flash_palettes_b[4] != 0x4) {
        printf("error! st5b_mo3_flush_tbl[4]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_b + 4, D_002610F0);
    if (stage5_boss_flash_palettes_b[11] != 0xb) {
        printf("error! st5b_mo3_flush_tbl[11]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_b + 11, ((u16 *)stage5_boss_flash_palettes_b_at_11));
    if (stage5_boss_flash_palettes_b[18] != 0x12) {
        printf("error! st5b_mo3_flush_tbl[18]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_b + 18, ((u16 *)stage5_boss_flash_palettes_b_at_18));
    if (stage5_boss_flash_palettes_b[25] != 0x19) {
        printf("error! st5b_mo3_flush_tbl[25]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_b + 25, stage5_boss_flash_palettes_a_30);
    if (stage5_boss_flash_palettes_b[32] != 0x20) {
        printf("error! st5b_mo3_flush_tbl[32]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_b + 32, stage5_boss_flash_palettes_a_33);
    if (stage5_boss_flash_palettes_b[39] != 0x27) {
        printf("error! st5b_mo3_flush_tbl[39]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_b + 39, stage5_boss_flash_palettes_a_37);
    if (stage5_boss_flash_palettes_b[46] != 0x2e) {
        printf("error! st5b_mo3_flush_tbl[46]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_b + 46, stage5_boss_flash_palettes_a_40);
    if (stage5_boss_flash_palettes_b[53] != 0x35) {
        printf("error! st5b_mo3_flush_tbl[53]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_b + 53, stage5_boss_flash_palettes_a_44);
    if (stage5_boss_flash_palettes_b[60] != 0x3c) {
        printf("error! st5b_mo3_flush_tbl[60]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_b + 60, stage5_boss_flash_palettes_a_47);
    if (stage5_boss_flash_palettes_c[4] != 0x4) {
        printf("error! st5bflush0_tbl[4]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_c + 4, D_002610F0);
    if (stage5_boss_flash_palettes_c[11] != 0xb) {
        printf("error! st5bflush0_tbl[11]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_c + 11, stage5_boss_flash_palettes_a_30);
    if (stage5_boss_flash_palettes_c[18] != 0x12) {
        printf("error! st5bflush0_tbl[18]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_c + 18, stage5_boss_flash_palettes_a_33);
    if (stage5_boss_flash_palettes_c[25] != 0x19) {
        printf("error! st5bflush0_tbl[25]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_c + 25, stage5_boss_flash_palettes_a_37);
    if (stage5_boss_flash_palettes_c[32] != 0x20) {
        printf("error! st5bflush0_tbl[32]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_c + 32, stage5_boss_flash_palettes_a_40);
    if (stage5_boss_flash_palettes_c[39] != 0x27) {
        printf("error! st5bflush0_tbl[39]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_c + 39, stage5_boss_flash_palettes_a_44);
    if (stage5_boss_flash_palettes_c[46] != 0x2e) {
        printf("error! st5bflush0_tbl[46]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_flash_palettes_c + 46, stage5_boss_flash_palettes_a_47);
    if (stage5_boss_fade_palettes_a[3] != 0x3) {
        printf("error! st5bmd2_fade_tbl0[3]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_fade_palettes_a + 3, D_00261D30);
    if (stage5_boss_fade_palettes_a[9] != 0x9) {
        printf("error! st5bmd2_fade_tbl0[9]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_fade_palettes_a + 9, D_00261D30);
    if (stage5_boss_fade_palettes_b[4] != 0x4) {
        printf("error! st5b_siro_fade_tbl0[4]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_fade_palettes_b + 4, ((u16 *)D_0025FF70));
    if (stage5_boss_fade_palettes_b[11] != 0xb) {
        printf("error! st5b_siro_fade_tbl0[11]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_fade_palettes_b + 11, ((u16 *)D_0025FFB0));
    if (stage5_boss_fade_palettes_b[18] != 0x12) {
        printf("error! st5b_siro_fade_tbl0[18]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_fade_palettes_b + 18, ((u16 *)D_0025FFF0));
    if (stage5_boss_fade_palettes_b[25] != 0x19) {
        printf("error! st5b_siro_fade_tbl0[25]\n");
    }
    STORE_ARCADE_ADDRESS(stage5_boss_fade_palettes_b + 25, ((u16 *)D_002600F0));
}
