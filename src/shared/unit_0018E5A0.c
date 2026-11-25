#include "common.h"
#include "task.h"
#include "entity.h"
#include "sdk/ps2sdk.h"
#include "cd.h"
#include "replay.h"

extern u16 bullet_type_setup_routines[];
extern u16 bullet_move_routines[];
extern u16 D_0024EBC0[];
extern u16 D_0024EDB0[];
extern u16 D_0024EF30[];
extern u16 debris_random_patterns[];
extern u16 D_00250D20[];
extern u16 D_00250E00[];
extern u16 D_00251AE0[];
extern u16 D_00251B00[];
extern u16 D_00264C30[];
extern u16 D_00264D00[];
extern u16 D_00264E10[];
extern u16 D_00264E80[];
extern u16 D_00264EA0[];

void music_start_when_ready(void);
void sound_update_bgm_fade(void);
s32 func_001981F0(void);
void func_001984C0(void);
void func_00198C40();
void func_00198D90();
void func_00198EF0(void);
void func_00198F30(void);
void func_001994F0(void);
void func_00199540(void);
void func_00199550(void);
void func_00199560(void);
void func_00199710(void);
void func_00199970(void);
void func_00199A50(void);
void func_00199D50(void);
void func_0019A050(void);
void func_0019A2B0(void);
void func_0019A410(void);
void func_0019A520(void);
void func_0019A5B0(void);
void func_0019A640(void);
void func_0019A870(void);


extern u16 D_002420F0[];
extern u16 D_00244070[];
extern u16 D_00244A30[];
extern u16 D_002461D0[];
extern u16 D_00246C90[];
extern u16 D_00247080[];
extern u16 D_00247880[];
extern u16 D_00249610[];
extern u16 D_00249ED0[];
extern u16 D_0024C240[];
extern u16 D_0024CA40[];
extern u16 D_0024CA80[];
extern u16 D_0024CAC0[];
extern u16 D_0024CB00[];
extern u16 D_0024CB40[];
extern u16 D_0024CB80[];
extern u16 D_0024D030_as_u16_a[];
extern u16 D_0024E0A0[];
extern u16 D_0024E0B0[];
extern u16 D_0024E0C0[];
extern u16 D_0024E0D0[];
extern u16 D_0024E0E0[];
extern u16 D_0024E0F8[];
extern u16 D_0024E110[];
extern u16 D_0024E130[];
extern u16 D_0024E140[];
extern u16 D_0024E150[];
extern u16 D_0024E170[];
extern u16 D_0024E188[];
extern u16 D_0024E1A0[];
extern u16 D_0024E1B8[];
extern u16 D_0024E1C8[];
extern u16 D_0024E1E0[];
extern u16 D_0024E200[];
extern u16 D_0024E210[];
extern u16 D_0024E220[];
extern u16 D_0024E230[];
extern u16 D_0024E240[];
extern u16 D_0024E250[];
extern u16 D_0024E260[];
extern u16 D_0024E280[];
extern u16 D_0024E290[];
extern u16 D_0024E2A0[];
extern u16 D_0024E2B0[];
extern u16 D_0024E2C8[];
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
extern u16 D_00250260[];
extern u16 D_002502C0[];
extern u16 D_002502F0[];
extern u16 D_002503A0[];
extern u16 D_002503F0[];
extern u16 D_00250490[];
extern u16 D_002504D0[];
extern u16 D_00250570[];
extern u16 D_002505C0[];
extern u16 D_00250600[];
extern u16 D_00250620[];
extern u16 D_002506B0[];
extern u16 D_002506F0[];
extern u16 D_00250740[];
extern u16 debris_pattern_0[];
extern u16 debris_pattern_1[];
extern u16 debris_pattern_2[];
extern u16 debris_pattern_3[];
extern u16 debris_pattern_4[];
extern u16 D_00250DA0[];
extern u16 D_00250DC0[];
extern u16 D_00250DE0[];
extern u16 D_00250E20[];
extern u16 D_00250EB0[];
extern u16 D_002515C0[];
extern u16 D_002515D0[];
extern u16 D_002515E0[];
extern u16 D_002515F0[];
extern u16 D_00251600[];
extern u16 D_00251610[];
extern u16 D_00251620[];
extern u16 D_00251630[];
extern u16 D_00251640[];
extern u16 D_00251650[];
extern u16 D_00251660[];
extern u16 D_00251670[];
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
extern u16 stage1_palette_list[];
extern u16 stage1_music_list[];
extern u16 stage1_ground_setup[];
extern u16 D_00252990[];
extern u16 stage2_palette_list[];
extern u16 stage2_music_list[];
extern u16 stage2_ground_setup[];
extern u16 D_00252BB0[];
extern u16 stage3_palette_list[];
extern u16 stage3_music_list[];
extern u16 stage3_ground_setup[];
extern u16 D_00252D70[];
extern u16 stage4_palette_list[];
extern u16 stage4_music_list[];
extern u16 stage4_ground_setup[];
extern u16 D_00252F40[];
extern u16 stage5_palette_list[];
extern u16 stage5_music_list[];
extern u16 stage5_ground_setup[];
extern u16 D_00253160[];
extern u16 D_00255470[];
extern u16 D_0025C040[];
extern u16 D_0025C060[];
extern u16 D_0025C080[];
extern u16 D_0025C0A0[];
extern u16 D_0025C0C0[];
extern u16 D_0025C0E0[];
extern u16 D_0025C100[];
extern u16 D_0025C120[];
extern u16 D_0025C140[];
extern u16 D_0025C160[];
extern u16 D_0025C180[];
extern u16 D_0025C1A0[];
extern u16 D_0025C1C0[];
extern u16 D_0025C1E0[];
extern u16 D_0025C200[];
extern u16 D_0025C220[];
extern u16 D_0025C240[];
extern u16 D_0025C260[];
extern u16 D_0025C280[];
extern u16 D_0025C2A0[];
extern u16 D_0025C2C0[];
extern u16 D_0025C2E0[];
extern u16 D_0025C300[];
extern u16 D_0025C320[];
extern u16 D_0025C340[];
extern u16 D_0025C360[];
extern u16 D_0025C380[];
extern u16 D_0025C3A0[];
extern u16 D_0025FF70_as_u16_a[];
extern u16 D_0025FFB0_as_u16_a[];
extern u16 D_0025FFF0_as_u16_a[];
extern u16 D_00260030_as_u16_a[];
extern u16 D_00260070_as_u16_a[];
extern u16 D_002600B0_as_u16_a[];
extern u16 D_002600F0_as_u16_a[];
extern u16 D_00260130_as_u16_a[];
extern u16 D_00260170_as_u16_a[];
extern u16 D_00260570[];
extern u16 D_002605B0[];
extern u16 D_002605F0[];
extern u16 D_00260630[];
extern u16 D_00260670[];
extern u16 D_002606B0[];
extern u16 D_002606F0[];
extern u16 D_00260730[];
extern u16 D_00260770[];
extern u16 D_002607B0[];
extern u16 D_002607F0[];
extern u16 D_00260830[];
extern u16 D_002608B0[];
extern u16 D_002608F0[];
extern u16 D_00260EB0[];
extern u16 D_00260EF0[];
extern u16 D_00260F30[];
extern u16 D_00260FB0[];
extern u16 D_00260FF0[];
extern u16 D_00261030[];
extern u16 D_002610B0_as_u16_a[];
extern u16 D_002610F0[];
extern u16 D_00261130[];
extern u16 D_00261170[];
extern u16 D_002611B0[];
extern u16 D_002611F0[];
extern u16 D_00261230[];
extern u16 D_00261270[];
extern u16 D_002612B0[];
extern u16 D_002612F0[];
extern u16 D_00261330[];
extern u16 D_00261370[];
extern u16 D_002613B0[];
extern u16 D_002613F0[];
extern u16 D_00261430[];
extern u16 D_00261470[];
extern u16 D_002614B0[];
extern u16 D_002614F0[];
extern u16 D_00261530[];
extern u16 D_00261570[];
extern u16 D_002615B0[];
extern u16 D_002615F0[];
extern u16 D_00261630[];
extern u16 D_00261670[];
extern u16 D_002616B0[];
extern u16 D_00261730_as_u16_a[];
extern u16 D_00261930[];
extern u16 D_00261970[];
extern u16 D_002619B0[];
extern u16 D_002619F0[];
extern u16 D_00261A30[];
extern u16 D_00261A70[];
extern u16 D_00261AB0[];
extern u16 D_00261B30[];
extern u16 D_00261B70[];
extern u16 D_00261D30[];
extern u16 D_00261D70[];
extern u16 D_00261DB0[];
extern u16 D_00261EF0_as_u16_a[];
extern u16 D_00261F30[];
extern u16 D_00261F70_as_u16_a[];
extern u16 D_00261FB0_as_u16_a[];
extern u16 D_002624F0[];
extern u16 D_00262530[];
extern u16 D_002643F0[];
extern u16 D_00264440[];
extern u16 D_00264490[];
extern u16 D_002644E0[];
extern u16 D_0028C0A0[];
extern u16 stage1_ground_table[];
extern u16 stage2_ground_table[];
extern u16 stage3_ground_table[];
extern u16 stage4_ground_table[];
extern u16 stage5_ground_table[];
extern u16 D_0028C680[];
extern u16 D_0028C708[];
extern u16 D_0029BF30_as_u16_a[];
extern u16 D_0029BF40_as_u16_a[];
extern void bullet_type_setup_00(void);
extern void bullet_type_setup_03(void);
extern void bullet_type_setup_17(void);
extern void bullet_type_setup_18(void);
extern void bullet_type_setup_19(void);
extern void bullet_type_setup_23(void);
extern void bullet_type_setup_27(void);
extern void bullet_type_setup_32(void);
extern void func_00129B10(void);
extern void bullet_type_setup_30(void);
extern void bullet_type_setup_31(void);
extern void func_0012D940(void);
extern void func_0012D960(void);
extern void func_0012D980(void);
extern void func_0012D990(void);
extern void func_0012D9B0(void);
extern void func_0012D9D0(void);
extern void func_0012D9F0(void);
extern void func_0012DA10(void);
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
extern void func_00130270(void);
extern void func_001303A0(void);
extern void func_0014CC90(void);
extern void func_0014CD70(void);
extern void func_0014CEA0(void);
extern void func_0014CEE0(void);
extern void func_0014CF10(void);
extern void func_0014CF90(void);
extern void func_0014D0F0(void);
extern void func_0014D140(void);
extern void func_0014D150(void);
extern void func_0014D170(void);
extern void music_play_bgm3(void);
extern void music_play_bgm4(void);
extern void music_play_bgm5(void);
extern void music_play_bgm6(void);
extern void music_play_bgm7(void);
extern void music_play_bgm8(void);

extern u16 D_0024D0B8[];
extern u16 D_0024D0C6[];
extern u16 D_0024D0D4[];
extern u16 D_0024D238[];
extern u16 D_0024D246[];
extern u16 D_0024D258[];
extern u16 D_0024D266[];
extern u16 D_0024D278[];
extern u16 D_0024D286[];
extern u16 D_0024D298[];
extern u16 D_0024D2A6[];
extern u16 D_0024D2B8[];
extern u16 D_0024D2C6[];
extern u16 D_0024E2E6[];
extern u16 D_0024E2F0[];
extern u16 D_0024E2FA[];
extern u16 D_0024E304[];
extern u16 D_0024E30E[];
extern u16 D_0024E318[];
extern u16 D_0024E322[];
extern u16 D_0024E32C[];
extern u16 D_0024E336[];
extern u16 D_0024E340[];
extern u16 D_0024E34A[];
extern u16 D_0024E354[];
extern u16 D_0024E35E[];
extern u16 D_0024E368[];
extern u16 D_0024E372[];
extern u16 D_0024E37C[];
extern u16 D_0024E386[];
extern u16 D_0024E390[];
extern u16 D_0024E39A[];
extern u16 D_0024E3A4[];
extern u16 D_0024E3AE[];
extern u16 D_0024E3B8[];
extern u16 D_0024E3C2[];
extern u16 D_0024E3CC[];
extern u16 D_0024E3D6[];
extern u16 D_0024E3E0[];
extern u16 D_0024E3EA[];
extern u16 D_0024E3F4[];
extern u16 D_0024E3FE[];
extern u16 D_0024E408[];
extern u16 D_0024E412[];
extern u16 D_0024E41C[];
extern u16 D_0024E426[];
extern u16 D_0024E430[];
extern u16 bullet_type_setup_routines_as_u16_a[];
extern u16 bullet_type_records[];
extern u16 bullet_move_routines_as_u16_a[];
extern u16 D_0024EBC0_as_u16_a[];
extern u16 D_0024EDB0_as_u16_a[];
extern u16 explosion_scripts[];
extern u16 explosion_scripts_b[];
extern u16 debris_random_patterns_as_u16_a[];
extern u16 D_00251A80_as_u16_a[];
extern u16 D_00251A84[];
extern u16 D_00251A90_as_u16_a[];
extern u16 D_00251A94[];
extern u16 D_00251AB0_as_u16_a[];
extern u16 D_00251AB4[];
extern u16 D_00251AC0_as_u16_a[];
extern u16 D_00251AC4[];
extern u16 D_00251CC0[];
extern u16 D_00252010[];
extern u16 D_00252050[];
extern u16 D_00252210[];
extern u16 D_00252220[];
extern u16 D_002526D0_as_u16_a[];
extern u16 D_002526D2[];
extern u16 D_002526F0_as_u16_a[];
extern u16 D_002526F2[];
extern u16 D_00252700_as_u16_a[];
extern u16 D_00252702[];
extern u16 D_00252720_as_u16_a[];
extern u16 D_00252722[];
extern u16 stage_ground_tables[];
extern u16 D_0025BF98[];
extern u16 D_0025BFA6[];
extern u16 D_0025BFB4[];
extern u16 D_0025BFC2[];
extern u16 name_entry_letter_table[];
extern u16 D_002643E0_as_u16_a[];
extern u16 D_002643E2[];
extern u16 D_0028C148_as_u16_a[];
extern u16 D_0028C14A[];

#ifdef DEATH_LABEL
extern u16 death_D_002506F0[];
extern u16 death_D_00250790[];
extern u16 death_D_00250A72[];
extern u16 death_D_00250B20[];
extern u16 death_D_00254748[];
extern u16 death_D_00254758[];
extern u16 death_D_00254768[];
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
extern void death_func_0012E5B0(void);
#endif

void func_0018E5A0(void) {
    extern void input_get_p1_held(void);
    extern void input_get_p2_held(void);
    extern void input_get_p1_pressed(void);
    extern void input_get_p2_pressed(void);
    if (bullet_type_setup_routines_as_u16_a[0] != 0x0) {
        printf("error! shot_para_tbl[0]\n");
    }
    STORE_POINTER_DIRECT(bullet_type_setup_routines_as_u16_a, bullet_type_setup_00);
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
    STORE_POINTER_DIRECT(bullet_type_setup_routines + 56, func_00129B10);
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
    STORE_POINTER_DIRECT(death_D_002506F0, func_00129B10);
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
    if (bullet_move_routines_as_u16_a[0] != 0x0) {
        printf("error! bulljmp[0]\n");
    }
    STORE_POINTER_DIRECT(bullet_move_routines_as_u16_a, bullet_move_type_00);
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
    STORE_POINTER_DIRECT(death_D_00250B20, death_func_0012E5B0);
#endif
    if (D_0024EBC0_as_u16_a[0] != 0x0) {
        printf("error! bull_n02tbl[0]\n");
    }
    STORE_POINTER_DIRECT(D_0024EBC0_as_u16_a, D_0024EBF0);
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
    if (D_0024EDB0_as_u16_a[0] != 0x0) {
        printf("error! bull_n15tbl[0]\n");
    }
    STORE_POINTER_DIRECT(D_0024EDB0_as_u16_a, D_0024EDE0);
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
    STORE_POINTER_DIRECT(D_0024EF30 + 192, func_0012D980);
    if (D_0024EF30[196] != 0x4) {
        printf("error! bull_spdjmp[4]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 196, func_0012D960);
    if (D_0024EF30[200] != 0x8) {
        printf("error! bull_spdjmp[8]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 200, func_0012D990);
    if (D_0024EF30[204] != 0xc) {
        printf("error! bull_spdjmp[12]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 204, func_0012D9B0);
    if (D_0024EF30[208] != 0x10) {
        printf("error! bull_spdjmp[16]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 208, func_0012D9F0);
    if (D_0024EF30[212] != 0x14) {
        printf("error! bull_spdjmp[20]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 212, func_0012D9D0);
    if (D_0024EF30[216] != 0x18) {
        printf("error! bull_spdjmp[24]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 216, func_0012D940);
    if (D_0024EF30[220] != 0x1c) {
        printf("error! bull_spdjmp[28]\n");
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 220, func_0012DA10);
    if (explosion_scripts[0] != 0x0) {
        printf("error! exp_tbl[0]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts, explosion_script_00);
    if (explosion_scripts[2] != 0x2) {
        printf("error! exp_tbl[2]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 2, explosion_script_01);
    if (explosion_scripts[4] != 0x4) {
        printf("error! exp_tbl[4]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 4, explosion_script_02);
    if (explosion_scripts[6] != 0x6) {
        printf("error! exp_tbl[6]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 6, explosion_script_03);
    if (explosion_scripts[8] != 0x8) {
        printf("error! exp_tbl[8]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 8, explosion_script_04);
    if (explosion_scripts[10] != 0xa) {
        printf("error! exp_tbl[10]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 10, explosion_script_05);
    if (explosion_scripts[12] != 0xc) {
        printf("error! exp_tbl[12]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 12, explosion_script_06);
    if (explosion_scripts[14] != 0xe) {
        printf("error! exp_tbl[14]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 14, explosion_script_07);
    if (explosion_scripts[16] != 0x10) {
        printf("error! exp_tbl[16]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 16, explosion_script_08);
    if (explosion_scripts[18] != 0x12) {
        printf("error! exp_tbl[18]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 18, explosion_script_09);
    if (explosion_scripts[20] != 0x14) {
        printf("error! exp_tbl[20]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 20, explosion_script_10);
    if (explosion_scripts[22] != 0x16) {
        printf("error! exp_tbl[22]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 22, explosion_script_11);
    if (explosion_scripts[24] != 0x18) {
        printf("error! exp_tbl[24]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 24, explosion_script_12);
    if (explosion_scripts[26] != 0x1a) {
        printf("error! exp_tbl[26]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 26, explosion_script_13);
    if (explosion_scripts[28] != 0x1c) {
        printf("error! exp_tbl[28]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 28, explosion_script_14);
    if (explosion_scripts[30] != 0x1e) {
        printf("error! exp_tbl[30]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 30, explosion_script_15);
    if (explosion_scripts[32] != 0x20) {
        printf("error! exp_tbl[32]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 32, explosion_script_16);
    if (explosion_scripts[34] != 0x22) {
        printf("error! exp_tbl[34]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 34, explosion_script_17);
    if (explosion_scripts[36] != 0x24) {
        printf("error! exp_tbl[36]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 36, explosion_script_18);
    if (explosion_scripts[38] != 0x26) {
        printf("error! exp_tbl[38]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 38, explosion_script_19);
    if (explosion_scripts[40] != 0x28) {
        printf("error! exp_tbl[40]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 40, D_00250260);
    if (explosion_scripts[42] != 0x2a) {
        printf("error! exp_tbl[42]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 42, D_002502C0);
    if (explosion_scripts[44] != 0x2c) {
        printf("error! exp_tbl[44]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 44, D_002502F0);
    if (explosion_scripts[46] != 0x2e) {
        printf("error! exp_tbl[46]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 46, D_002503A0);
    if (explosion_scripts[48] != 0x30) {
        printf("error! exp_tbl[48]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 48, D_002503F0);
    if (explosion_scripts[50] != 0x32) {
        printf("error! exp_tbl[50]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 50, D_00250490);
    if (explosion_scripts[52] != 0x34) {
        printf("error! exp_tbl[52]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 52, D_002504D0);
    if (explosion_scripts[54] != 0x36) {
        printf("error! exp_tbl[54]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 54, D_00250570);
    if (explosion_scripts[56] != 0x38) {
        printf("error! exp_tbl[56]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 56, D_002505C0);
    if (explosion_scripts[58] != 0x3a) {
        printf("error! exp_tbl[58]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 58, D_00250600);
    if (explosion_scripts[60] != 0x3c) {
        printf("error! exp_tbl[60]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 60, D_00250620);
    if (explosion_scripts[62] != 0x3e) {
        printf("error! exp_tbl[62]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 62, D_002506B0);
    if (explosion_scripts[64] != 0x40) {
        printf("error! exp_tbl[64]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 64, D_002506F0);
    if (explosion_scripts[66] != 0x42) {
        printf("error! exp_tbl[66]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 66, D_00250740);
    if (explosion_scripts[68] != 0x44) {
        printf("error! exp_tbl[68]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 68, explosion_script_00);
    if (explosion_scripts[70] != 0x46) {
        printf("error! exp_tbl[70]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 70, explosion_script_01);
    if (explosion_scripts[72] != 0x48) {
        printf("error! exp_tbl[72]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 72, explosion_script_02);
    if (explosion_scripts[74] != 0x4a) {
        printf("error! exp_tbl[74]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 74, explosion_script_03);
    if (explosion_scripts[76] != 0x4c) {
        printf("error! exp_tbl[76]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 76, explosion_script_04);
    if (explosion_scripts[78] != 0x4e) {
        printf("error! exp_tbl[78]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 78, explosion_script_05);
    if (explosion_scripts[80] != 0x50) {
        printf("error! exp_tbl[80]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 80, explosion_script_06);
    if (explosion_scripts[82] != 0x52) {
        printf("error! exp_tbl[82]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 82, explosion_script_07);
    if (explosion_scripts[84] != 0x54) {
        printf("error! exp_tbl[84]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 84, explosion_script_08);
    if (explosion_scripts[86] != 0x56) {
        printf("error! exp_tbl[86]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 86, explosion_script_09);
    if (explosion_scripts[88] != 0x58) {
        printf("error! exp_tbl[88]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 88, explosion_script_10);
    if (explosion_scripts[90] != 0x5a) {
        printf("error! exp_tbl[90]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 90, explosion_script_11);
    if (explosion_scripts[92] != 0x5c) {
        printf("error! exp_tbl[92]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 92, explosion_script_12);
    if (explosion_scripts[94] != 0x5e) {
        printf("error! exp_tbl[94]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 94, explosion_script_13);
    if (explosion_scripts[96] != 0x60) {
        printf("error! exp_tbl[96]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 96, explosion_script_14);
    if (explosion_scripts[98] != 0x62) {
        printf("error! exp_tbl[98]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 98, explosion_script_15);
    if (explosion_scripts[100] != 0x64) {
        printf("error! exp_tbl[100]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 100, explosion_script_16);
    if (explosion_scripts[102] != 0x66) {
        printf("error! exp_tbl[102]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 102, explosion_script_17);
    if (explosion_scripts[104] != 0x68) {
        printf("error! exp_tbl[104]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 104, explosion_script_18);
    if (explosion_scripts[106] != 0x6a) {
        printf("error! exp_tbl[106]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 106, explosion_script_19);
    if (explosion_scripts[108] != 0x6c) {
        printf("error! exp_tbl[108]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 108, D_00250260);
    if (explosion_scripts[110] != 0x6e) {
        printf("error! exp_tbl[110]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 110, D_002502C0);
    if (explosion_scripts[112] != 0x70) {
        printf("error! exp_tbl[112]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 112, D_002502F0);
    if (explosion_scripts[114] != 0x72) {
        printf("error! exp_tbl[114]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 114, D_002503A0);
    if (explosion_scripts[116] != 0x74) {
        printf("error! exp_tbl[116]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 116, D_002503F0);
    if (explosion_scripts[118] != 0x76) {
        printf("error! exp_tbl[118]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 118, D_00250490);
    if (explosion_scripts[120] != 0x78) {
        printf("error! exp_tbl[120]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 120, D_002504D0);
    if (explosion_scripts[122] != 0x7a) {
        printf("error! exp_tbl[122]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 122, D_00250570);
    if (explosion_scripts[124] != 0x7c) {
        printf("error! exp_tbl[124]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 124, D_002505C0);
    if (explosion_scripts[126] != 0x7e) {
        printf("error! exp_tbl[126]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 126, D_00250600);
    if (explosion_scripts[128] != 0x80) {
        printf("error! exp_tbl[128]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 128, D_00250620);
    if (explosion_scripts[130] != 0x82) {
        printf("error! exp_tbl[130]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 130, D_002506B0);
    if (explosion_scripts[132] != 0x84) {
        printf("error! exp_tbl[132]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 132, D_002506F0);
    if (explosion_scripts[134] != 0x86) {
        printf("error! exp_tbl[134]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts + 134, D_00250740);
    if (explosion_scripts_b[0] != 0x0) {
        printf("error! exp_tbl_80[0]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b, explosion_script_b_00);
    if (explosion_scripts_b[2] != 0x2) {
        printf("error! exp_tbl_80[2]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 2, explosion_script_b_01);
    if (explosion_scripts_b[4] != 0x4) {
        printf("error! exp_tbl_80[4]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 4, explosion_script_b_02);
    if (explosion_scripts_b[6] != 0x6) {
        printf("error! exp_tbl_80[6]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 6, explosion_script_b_03);
    if (explosion_scripts_b[8] != 0x8) {
        printf("error! exp_tbl_80[8]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 8, explosion_script_b_04);
    if (explosion_scripts_b[10] != 0xa) {
        printf("error! exp_tbl_80[10]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 10, explosion_script_b_05);
    if (explosion_scripts_b[12] != 0xc) {
        printf("error! exp_tbl_80[12]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 12, explosion_script_b_06);
    if (explosion_scripts_b[14] != 0xe) {
        printf("error! exp_tbl_80[14]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 14, explosion_script_b_07);
    if (explosion_scripts_b[16] != 0x10) {
        printf("error! exp_tbl_80[16]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 16, explosion_script_b_08);
    if (explosion_scripts_b[18] != 0x12) {
        printf("error! exp_tbl_80[18]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 18, explosion_script_b_09);
    if (explosion_scripts_b[20] != 0x14) {
        printf("error! exp_tbl_80[20]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 20, explosion_script_b_10);
    if (explosion_scripts_b[22] != 0x16) {
        printf("error! exp_tbl_80[22]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 22, explosion_script_b_11);
    if (explosion_scripts_b[24] != 0x18) {
        printf("error! exp_tbl_80[24]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 24, D_00250260);
    if (explosion_scripts_b[26] != 0x1a) {
        printf("error! exp_tbl_80[26]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 26, D_002502C0);
    if (explosion_scripts_b[28] != 0x1c) {
        printf("error! exp_tbl_80[28]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 28, D_002502F0);
    if (explosion_scripts_b[30] != 0x1e) {
        printf("error! exp_tbl_80[30]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 30, D_002503A0);
    if (explosion_scripts_b[32] != 0x20) {
        printf("error! exp_tbl_80[32]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 32, D_002503F0);
    if (explosion_scripts_b[34] != 0x22) {
        printf("error! exp_tbl_80[34]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 34, D_00250490);
    if (explosion_scripts_b[36] != 0x24) {
        printf("error! exp_tbl_80[36]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 36, D_002504D0);
    if (explosion_scripts_b[38] != 0x26) {
        printf("error! exp_tbl_80[38]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 38, D_00250570);
    if (explosion_scripts_b[40] != 0x28) {
        printf("error! exp_tbl_80[40]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 40, D_00250260);
    if (explosion_scripts_b[42] != 0x2a) {
        printf("error! exp_tbl_80[42]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 42, D_002502C0);
    if (explosion_scripts_b[44] != 0x2c) {
        printf("error! exp_tbl_80[44]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 44, D_002502F0);
    if (explosion_scripts_b[46] != 0x2e) {
        printf("error! exp_tbl_80[46]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 46, D_002503A0);
    if (explosion_scripts_b[48] != 0x30) {
        printf("error! exp_tbl_80[48]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 48, D_002503F0);
    if (explosion_scripts_b[50] != 0x32) {
        printf("error! exp_tbl_80[50]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 50, D_00250490);
    if (explosion_scripts_b[52] != 0x34) {
        printf("error! exp_tbl_80[52]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 52, D_002504D0);
    if (explosion_scripts_b[54] != 0x36) {
        printf("error! exp_tbl_80[54]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 54, D_00250570);
    if (explosion_scripts_b[56] != 0x38) {
        printf("error! exp_tbl_80[56]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 56, D_002505C0);
    if (explosion_scripts_b[58] != 0x3a) {
        printf("error! exp_tbl_80[58]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 58, D_00250600);
    if (explosion_scripts_b[60] != 0x3c) {
        printf("error! exp_tbl_80[60]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 60, D_00250620);
    if (explosion_scripts_b[62] != 0x3e) {
        printf("error! exp_tbl_80[62]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 62, D_002506B0);
    if (explosion_scripts_b[64] != 0x40) {
        printf("error! exp_tbl_80[64]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 64, D_002506F0);
    if (explosion_scripts_b[66] != 0x42) {
        printf("error! exp_tbl_80[66]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 66, D_00250740);
    if (explosion_scripts_b[68] != 0x44) {
        printf("error! exp_tbl_80[68]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 68, explosion_script_b_00);
    if (explosion_scripts_b[70] != 0x46) {
        printf("error! exp_tbl_80[70]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 70, explosion_script_b_01);
    if (explosion_scripts_b[72] != 0x48) {
        printf("error! exp_tbl_80[72]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 72, explosion_script_b_02);
    if (explosion_scripts_b[74] != 0x4a) {
        printf("error! exp_tbl_80[74]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 74, explosion_script_b_03);
    if (explosion_scripts_b[76] != 0x4c) {
        printf("error! exp_tbl_80[76]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 76, explosion_script_b_04);
    if (explosion_scripts_b[78] != 0x4e) {
        printf("error! exp_tbl_80[78]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 78, explosion_script_b_05);
    if (explosion_scripts_b[80] != 0x50) {
        printf("error! exp_tbl_80[80]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 80, explosion_script_b_06);
    if (explosion_scripts_b[82] != 0x52) {
        printf("error! exp_tbl_80[82]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 82, explosion_script_b_07);
    if (explosion_scripts_b[84] != 0x54) {
        printf("error! exp_tbl_80[84]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 84, explosion_script_b_08);
    if (explosion_scripts_b[86] != 0x56) {
        printf("error! exp_tbl_80[86]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 86, explosion_script_b_09);
    if (explosion_scripts_b[88] != 0x58) {
        printf("error! exp_tbl_80[88]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 88, explosion_script_b_10);
    if (explosion_scripts_b[90] != 0x5a) {
        printf("error! exp_tbl_80[90]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 90, explosion_script_b_11);
    if (explosion_scripts_b[92] != 0x5c) {
        printf("error! exp_tbl_80[92]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 92, D_00250260);
    if (explosion_scripts_b[94] != 0x5e) {
        printf("error! exp_tbl_80[94]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 94, D_002502C0);
    if (explosion_scripts_b[96] != 0x60) {
        printf("error! exp_tbl_80[96]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 96, D_002502F0);
    if (explosion_scripts_b[98] != 0x62) {
        printf("error! exp_tbl_80[98]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 98, D_002503A0);
    if (explosion_scripts_b[100] != 0x64) {
        printf("error! exp_tbl_80[100]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 100, D_002503F0);
    if (explosion_scripts_b[102] != 0x66) {
        printf("error! exp_tbl_80[102]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 102, D_00250490);
    if (explosion_scripts_b[104] != 0x68) {
        printf("error! exp_tbl_80[104]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 104, D_002504D0);
    if (explosion_scripts_b[106] != 0x6a) {
        printf("error! exp_tbl_80[106]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 106, D_00250570);
    if (explosion_scripts_b[108] != 0x6c) {
        printf("error! exp_tbl_80[108]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 108, D_00250260);
    if (explosion_scripts_b[110] != 0x6e) {
        printf("error! exp_tbl_80[110]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 110, D_002502C0);
    if (explosion_scripts_b[112] != 0x70) {
        printf("error! exp_tbl_80[112]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 112, D_002502F0);
    if (explosion_scripts_b[114] != 0x72) {
        printf("error! exp_tbl_80[114]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 114, D_002503A0);
    if (explosion_scripts_b[116] != 0x74) {
        printf("error! exp_tbl_80[116]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 116, D_002503F0);
    if (explosion_scripts_b[118] != 0x76) {
        printf("error! exp_tbl_80[118]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 118, D_00250490);
    if (explosion_scripts_b[120] != 0x78) {
        printf("error! exp_tbl_80[120]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 120, D_002504D0);
    if (explosion_scripts_b[122] != 0x7a) {
        printf("error! exp_tbl_80[122]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 122, D_00250570);
    if (explosion_scripts_b[124] != 0x7c) {
        printf("error! exp_tbl_80[124]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 124, D_002505C0);
    if (explosion_scripts_b[126] != 0x7e) {
        printf("error! exp_tbl_80[126]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 126, D_00250600);
    if (explosion_scripts_b[128] != 0x80) {
        printf("error! exp_tbl_80[128]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 128, D_00250620);
    if (explosion_scripts_b[130] != 0x82) {
        printf("error! exp_tbl_80[130]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 130, D_002506B0);
    if (explosion_scripts_b[132] != 0x84) {
        printf("error! exp_tbl_80[132]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 132, D_002506F0);
    if (explosion_scripts_b[134] != 0x86) {
        printf("error! exp_tbl_80[134]\n");
    }
    STORE_POINTER_DIRECT(explosion_scripts_b + 134, D_00250740);
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
    if (debris_random_patterns_as_u16_a[0] != 0x0) {
        printf("error! hah_random_tbl[0]\n");
    }
    STORE_POINTER_DIRECT(debris_random_patterns_as_u16_a, debris_pattern_0);
    if (debris_random_patterns[2] != 0x2) {
        printf("error! hah_random_tbl[2]\n");
    }
    STORE_POINTER_DIRECT(debris_random_patterns + 2, debris_pattern_2);
    if (debris_random_patterns[4] != 0x4) {
        printf("error! hah_random_tbl[4]\n");
    }
    STORE_POINTER_DIRECT(debris_random_patterns + 4, debris_pattern_3);
    if (debris_random_patterns[6] != 0x6) {
        printf("error! hah_random_tbl[6]\n");
    }
    STORE_POINTER_DIRECT(debris_random_patterns + 6, debris_pattern_4);
    if (D_00250D20[16] != 0x8) {
        printf("error! tili_a[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250D20 + 16, D_00250DA0);
    if (D_00250D20[32] != 0x8) {
        printf("error! tili_a2[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250D20 + 32, D_00250DC0);
    if (D_00250D20[48] != 0x8) {
        printf("error! tili_a3[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250D20 + 48, D_00250DE0);
    if (D_00250E00[8] != 0x8) {
        printf("error! tili_b[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250E00 + 8, D_00250E20);
    if (D_00250EB0[80] != 0x8) {
        printf("error! tili_d1[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 80, D_00250EB0);
    if (D_00250EB0[96] != 0x8) {
        printf("error! tili_d2[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 96, D_00250EB0);
    if (D_00250EB0[112] != 0x8) {
        printf("error! tili_d3[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 112, D_00250EB0);
    if (D_00250EB0[128] != 0x8) {
        printf("error! tili_d4[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 128, D_00250EB0);
    if (D_00250EB0[144] != 0x8) {
        printf("error! tili_d5[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 144, D_00250EB0);
    if (D_00250EB0[160] != 0x8) {
        printf("error! tili_d6[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 160, D_00250EB0);
    if (D_00250EB0[176] != 0x8) {
        printf("error! tili_d7[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 176, D_00250EB0);
    if (D_00250EB0[192] != 0x8) {
        printf("error! tili_d8[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 192, D_00250EB0);
    if (D_00250EB0[208] != 0x8) {
        printf("error! tili_d9[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 208, D_00250EB0);
    if (D_00250EB0[224] != 0x8) {
        printf("error! tili_d10[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 224, D_00250EB0);
    if (D_00250EB0[240] != 0x8) {
        printf("error! tili_d11[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 240, D_00250EB0);
    if (D_00250EB0[256] != 0x8) {
        printf("error! tili_d12[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 256, D_00250EB0);
    if (D_00250EB0[272] != 0x8) {
        printf("error! tili_d13[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 272, D_00250EB0);
    if (D_00250EB0[288] != 0x8) {
        printf("error! tili_d14[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 288, D_00250EB0);
    if (D_00250EB0[304] != 0x8) {
        printf("error! tili_d15[8]\n");
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 304, D_00250EB0);
    if (D_00251670[16] != 0x8) {
        printf("error! zan_n0[8]\n");
    }
    STORE_POINTER_DIRECT(D_00251670 + 16, D_002515C0);
    if (D_00251670[18] != 0xa) {
        printf("error! zan_n0[10]\n");
    }
    STORE_POINTER_DIRECT(D_00251670 + 18, D_002515D0);
    if (D_00251670[20] != 0xc) {
        printf("error! zan_n0[12]\n");
    }
    STORE_POINTER_DIRECT(D_00251670 + 20, D_002515E0);
    STORE_POINTER_DIRECT(D_00251670 + 32, D_002515F0);
    if (D_00251670[34] != 0xa) {
        printf("error! zan_n1[10]\n");
    }
    STORE_POINTER_DIRECT(D_00251670 + 34, D_00251600);
    if (D_00251670[36] != 0xc) {
        printf("error! zan_n1[12]\n");
    }
    STORE_POINTER_DIRECT(D_00251670 + 36, D_00251610);
    if (D_00251670[48] != 0x8) {
        printf("error! zan_n2[8]\n");
    }
    STORE_POINTER_DIRECT(D_00251670 + 48, D_00251620);
    if (D_00251670[50] != 0xa) {
        printf("error! zan_n2[10]\n");
    }
    STORE_POINTER_DIRECT(D_00251670 + 50, D_00251630);
    if (D_00251670[52] != 0xc) {
        printf("error! zan_n2[12]\n");
    }
    STORE_POINTER_DIRECT(D_00251670 + 52, D_00251640);
    if (D_00251670[64] != 0x8) {
        printf("error! zan_n3[8]\n");
    }
    STORE_POINTER_DIRECT(D_00251670 + 64, D_00251650);
    if (D_00251670[66] != 0xa) {
        printf("error! zan_n3[10]\n");
    }
    STORE_POINTER_DIRECT(D_00251670 + 66, D_00251660);
    if (D_00251670[68] != 0xc) {
        printf("error! zan_n3[12]\n");
    }
    STORE_POINTER_DIRECT(D_00251670 + 68, D_00251670);
    if (D_0024D0B8[0] != 0x4) {
        printf("error! end_fadein_tbl[4]\n");
    }
    STORE_POINTER_DIRECT(D_0024D0B8, D_0024D030_as_u16_a);
    if (D_0024D0C6[0] != 0xb) {
        printf("error! end_fadein_tbl[11]\n");
    }
    STORE_POINTER_DIRECT(D_0024D0C6, D_002624F0);
    if (D_0024D0D4[0] != 0x12) {
        printf("error! end_fadein_tbl[18]\n");
    }
    STORE_POINTER_DIRECT(D_0024D0D4, D_00262530);
    if (D_0024D238[0] != 0x4) {
        printf("error! end_fadein_g_tbl0[4]\n");
    }
    STORE_POINTER_DIRECT(D_0024D238, D_002624F0);
    if (D_0024D246[0] != 0xb) {
        printf("error! end_fadein_g_tbl0[11]\n");
    }
    STORE_POINTER_DIRECT(D_0024D246, D_00262530);
    if (D_0024D258[0] != 0x4) {
        printf("error! end_fadein_g_tbl1[4]\n");
    }
    STORE_POINTER_DIRECT(D_0024D258, D_002624F0);
    if (D_0024D266[0] != 0xb) {
        printf("error! end_fadein_g_tbl1[11]\n");
    }
    STORE_POINTER_DIRECT(D_0024D266, D_00262530);
    if (D_0024D278[0] != 0x4) {
        printf("error! end_fadein_g_tbl2[4]\n");
    }
    STORE_POINTER_DIRECT(D_0024D278, D_002624F0);
    if (D_0024D286[0] != 0xb) {
        printf("error! end_fadein_g_tbl2[11]\n");
    }
    STORE_POINTER_DIRECT(D_0024D286, D_00262530);
    if (D_0024D298[0] != 0x4) {
        printf("error! end_fadein_g_tbl3[4]\n");
    }
    STORE_POINTER_DIRECT(D_0024D298, D_002624F0);
    if (D_0024D2A6[0] != 0xb) {
        printf("error! end_fadein_g_tbl3[11]\n");
    }
    STORE_POINTER_DIRECT(D_0024D2A6, D_00262530);
    if (D_0024D2B8[0] != 0x4) {
        printf("error! end_fadein_g_tbl4[4]\n");
    }
    STORE_POINTER_DIRECT(D_0024D2B8, D_002624F0);
    if (D_0024D2C6[0] != 0xb) {
        printf("error! end_fadein_g_tbl4[11]\n");
    }
    STORE_POINTER_DIRECT(D_0024D2C6, D_00262530);
    if (D_0024E2E6[0] != 0x3) {
        printf("error! stf_tbl[3]\n");
    }
    STORE_POINTER_DIRECT(D_0024E2E6, D_0028C0A0);
    if (D_0024E2F0[0] != 0x8) {
        printf("error! stf_tbl[8]\n");
    }
    STORE_POINTER_DIRECT(D_0024E2F0, D_0024E0A0);
    if (D_0024E2FA[0] != 0xd) {
        printf("error! stf_tbl[13]\n");
    }
    STORE_POINTER_DIRECT(D_0024E2FA, D_0024E0B0);
    if (D_0024E304[0] != 0x12) {
        printf("error! stf_tbl[18]\n");
    }
    STORE_POINTER_DIRECT(D_0024E304, D_0024E0C0);
    if (D_0024E30E[0] != 0x17) {
        printf("error! stf_tbl[23]\n");
    }
    STORE_POINTER_DIRECT(D_0024E30E, D_0024E0D0);
    if (D_0024E318[0] != 0x1c) {
        printf("error! stf_tbl[28]\n");
    }
    STORE_POINTER_DIRECT(D_0024E318, D_0024E0E0);
    if (D_0024E322[0] != 0x21) {
        printf("error! stf_tbl[33]\n");
    }
    STORE_POINTER_DIRECT(D_0024E322, D_0024E0D0);
    if (D_0024E32C[0] != 0x26) {
        printf("error! stf_tbl[38]\n");
    }
    STORE_POINTER_DIRECT(D_0024E32C, D_0024E0F8);
    if (D_0024E336[0] != 0x2b) {
        printf("error! stf_tbl[43]\n");
    }
    STORE_POINTER_DIRECT(D_0024E336, D_0024E110);
    if (D_0024E340[0] != 0x30) {
        printf("error! stf_tbl[48]\n");
    }
    STORE_POINTER_DIRECT(D_0024E340, D_0024E140);
    if (D_0024E34A[0] != 0x35) {
        printf("error! stf_tbl[53]\n");
    }
    STORE_POINTER_DIRECT(D_0024E34A, D_0024E150);
    if (D_0024E354[0] != 0x3a) {
        printf("error! stf_tbl[58]\n");
    }
    STORE_POINTER_DIRECT(D_0024E354, D_0024E170);
    if (D_0024E35E[0] != 0x3f) {
        printf("error! stf_tbl[63]\n");
    }
    STORE_POINTER_DIRECT(D_0024E35E, D_0024E188);
    if (D_0024E368[0] != 0x44) {
        printf("error! stf_tbl[68]\n");
    }
    STORE_POINTER_DIRECT(D_0024E368, D_0024E1A0);
    if (D_0024E372[0] != 0x49) {
        printf("error! stf_tbl[73]\n");
    }
    STORE_POINTER_DIRECT(D_0024E372, D_0024E150);
    if (D_0024E37C[0] != 0x4e) {
        printf("error! stf_tbl[78]\n");
    }
    STORE_POINTER_DIRECT(D_0024E37C, D_0024E1B8);
    if (D_0024E386[0] != 0x53) {
        printf("error! stf_tbl[83]\n");
    }
    STORE_POINTER_DIRECT(D_0024E386, D_0024E1C8);
    if (D_0024E390[0] != 0x58) {
        printf("error! stf_tbl[88]\n");
    }
    STORE_POINTER_DIRECT(D_0024E390, D_0024E1E0);
    if (D_0024E39A[0] != 0x5d) {
        printf("error! stf_tbl[93]\n");
    }
    STORE_POINTER_DIRECT(D_0024E39A, D_0024E1C8);
    if (D_0024E3A4[0] != 0x62) {
        printf("error! stf_tbl[98]\n");
    }
    STORE_POINTER_DIRECT(D_0024E3A4, D_0024E188);
    if (D_0024E3AE[0] != 0x67) {
        printf("error! stf_tbl[103]\n");
    }
    STORE_POINTER_DIRECT(D_0024E3AE, D_0024E200);
    if (D_0024E3B8[0] != 0x6c) {
        printf("error! stf_tbl[108]\n");
    }
    STORE_POINTER_DIRECT(D_0024E3B8, D_0024E188);
    if (D_0024E3C2[0] != 0x71) {
        printf("error! stf_tbl[113]\n");
    }
    STORE_POINTER_DIRECT(D_0024E3C2, D_0024E210);
    if (D_0024E3CC[0] != 0x76) {
        printf("error! stf_tbl[118]\n");
    }
    STORE_POINTER_DIRECT(D_0024E3CC, D_0024E220);
    if (D_0024E3D6[0] != 0x7b) {
        printf("error! stf_tbl[123]\n");
    }
    STORE_POINTER_DIRECT(D_0024E3D6, D_0024E2B0);
    if (D_0024E3E0[0] != 0x80) {
        printf("error! stf_tbl[128]\n");
    }
    STORE_POINTER_DIRECT(D_0024E3E0, D_0024E130);
    if (D_0024E3EA[0] != 0x85) {
        printf("error! stf_tbl[133]\n");
    }
    STORE_POINTER_DIRECT(D_0024E3EA, D_0024E230);
    if (D_0024E3F4[0] != 0x8a) {
        printf("error! stf_tbl[138]\n");
    }
    STORE_POINTER_DIRECT(D_0024E3F4, D_0024E240);
    if (D_0024E3FE[0] != 0x8f) {
        printf("error! stf_tbl[143]\n");
    }
    STORE_POINTER_DIRECT(D_0024E3FE, D_0024E250);
    if (D_0024E408[0] != 0x94) {
        printf("error! stf_tbl[148]\n");
    }
    STORE_POINTER_DIRECT(D_0024E408, D_0024E260);
    if (D_0024E412[0] != 0x99) {
        printf("error! stf_tbl[153]\n");
    }
#ifdef DEATH_LABEL
    STORE_POINTER_DIRECT(D_0024E412, D_0024E2C8);
    STORE_POINTER_DIRECT(D_0024E41C, death_D_00254748);
    STORE_POINTER_DIRECT(D_0024E426, death_D_00254758);
    STORE_POINTER_DIRECT(D_0024E430, death_D_00254768);
    STORE_POINTER_DIRECT(death_D_0025495A, death_D_00254778);
    STORE_POINTER_DIRECT(death_D_00254964, death_D_00254790);
    STORE_POINTER_DIRECT(death_D_0025496E, death_D_002547A0);
    STORE_POINTER_DIRECT(death_D_00254978, death_D_002547B0);
    STORE_POINTER_DIRECT(death_D_00254982, death_D_002547C0);
#else
    STORE_POINTER_DIRECT(D_0024E412, D_0024E2C8);
    STORE_POINTER_DIRECT(D_0024E41C, D_0024E280);
    STORE_POINTER_DIRECT(D_0024E426, D_0024E290);
    STORE_POINTER_DIRECT(D_0024E430, D_0024E2A0);
#endif
    if (D_002526D0_as_u16_a[0] != 0x0) {
        printf("error! groevent_tbl[0]\n");
    }
    reg_tmp.w = (u32)func_0014CC90;
    D_002526D0_as_u16_a[0] = reg_tmp.h[1];
    D_002526D2[0] = reg_tmp.h[0];
    if (D_002526D2[1] != 0x2) {
        printf("error! groevent_tbl[2]\n");
    }
    STORE_POINTER(D_002526D2 + 1, func_0014CD70);
    if (D_002526D2[3] != 0x4) {
        printf("error! groevent_tbl[4]\n");
    }
    STORE_POINTER(D_002526D2 + 3, func_0014CEA0);
    if (D_002526D2[5] != 0x6) {
        printf("error! groevent_tbl[6]\n");
    }
    STORE_POINTER(D_002526D2 + 5, func_0014CEE0);
    if (D_002526D2[7] != 0x8) {
        printf("error! groevent_tbl[8]\n");
    }
    STORE_POINTER(D_002526D2 + 7, func_0014CF10);
    if (D_002526D2[9] != 0xa) {
        printf("error! groevent_tbl[10]\n");
    }
    STORE_POINTER(D_002526D2 + 9, func_0014CF90);
    if (D_002526D2[11] != 0xc) {
        printf("error! groevent_tbl[12]\n");
    }
    STORE_POINTER(D_002526D2 + 11, func_0014D170);
    if (D_002526F0_as_u16_a[0] != 0x0) {
        printf("error! gev_snd_proc_tbl[0]\n");
    }
    reg_tmp.w = (u32)func_0014D0F0;
    D_002526F0_as_u16_a[0] = reg_tmp.h[1];
    D_002526F2[0] = reg_tmp.h[0];
    if (D_002526F2[1] != 0x2) {
        printf("error! gev_snd_proc_tbl[2]\n");
    }
    STORE_POINTER(D_002526F2 + 1, func_0014D140);
    if (D_002526F2[3] != 0x4) {
        printf("error! gev_snd_proc_tbl[4]\n");
    }
    STORE_POINTER(D_002526F2 + 3, func_0014D150);
    if (D_00252700_as_u16_a[0] != 0x0) {
        printf("error! bg_pal_tbl[0]\n");
    }
    reg_tmp.w = (u32)D_00244070;
    D_00252700_as_u16_a[0] = reg_tmp.h[1];
    D_00252702[0] = reg_tmp.h[0];
    if (D_00252702[1] != 0x2) {
        printf("error! bg_pal_tbl[2]\n");
    }
    STORE_POINTER(D_00252702 + 1, D_002461D0);
    if (D_00252702[3] != 0x4) {
        printf("error! bg_pal_tbl[4]\n");
    }
    STORE_POINTER(D_00252702 + 3, D_00247080);
    if (D_00252702[5] != 0x6) {
        printf("error! bg_pal_tbl[6]\n");
    }
    STORE_POINTER(D_00252702 + 5, D_00249610);
    if (D_00252702[7] != 0x8) {
        printf("error! bg_pal_tbl[8]\n");
    }
    STORE_POINTER(D_00252702 + 7, D_0024C240);
    if (D_00252720_as_u16_a[0] != 0x0) {
        printf("error! stg_tbl[0]\n");
    }
    reg_tmp.w = (u32)D_002420F0;
    D_00252720_as_u16_a[0] = reg_tmp.h[1];
    D_00252722[0] = reg_tmp.h[0];
    if (D_00252722[1] != 0x2) {
        printf("error! stg_tbl[2]\n");
    }
    STORE_POINTER(D_00252722 + 1, D_00244A30);
    if (D_00252722[3] != 0x4) {
        printf("error! stg_tbl[4]\n");
    }
    STORE_POINTER(D_00252722 + 3, D_00246C90);
    if (D_00252722[5] != 0x6) {
        printf("error! stg_tbl[6]\n");
    }
    STORE_POINTER(D_00252722 + 5, D_00247880);
    if (D_00252722[7] != 0x8) {
        printf("error! stg_tbl[8]\n");
    }
    STORE_POINTER(D_00252722 + 7, D_00249ED0);
    if (stage1_ground_table[0] != 0x0) {
        printf("error! gro_stg1_tbl[0]\n");
    }
    STORE_POINTER(stage1_ground_table, stage1_ground_setup);
    if (stage1_ground_table[2] != 0x2) {
        printf("error! gro_stg1_tbl[2]\n");
    }
    STORE_POINTER(stage1_ground_table + 2, D_00252990);
    if (stage2_ground_table[0] != 0x0) {
        printf("error! gro_stg2_tbl[0]\n");
    }
    STORE_POINTER(stage2_ground_table, stage2_ground_setup);
    if (stage2_ground_table[2] != 0x2) {
        printf("error! gro_stg2_tbl[2]\n");
    }
    STORE_POINTER(stage2_ground_table + 2, D_00252BB0);
    if (stage3_ground_table[0] != 0x0) {
        printf("error! gro_stg3_tbl[0]\n");
    }
    STORE_POINTER(stage3_ground_table, stage3_ground_setup);
    if (stage3_ground_table[2] != 0x2) {
        printf("error! gro_stg3_tbl[2]\n");
    }
    STORE_POINTER(stage3_ground_table + 2, D_00252D70);
    if (stage4_ground_table[0] != 0x0) {
        printf("error! gro_stg4_tbl[0]\n");
    }
    STORE_POINTER(stage4_ground_table, stage4_ground_setup);
    if (stage4_ground_table[2] != 0x2) {
        printf("error! gro_stg4_tbl[2]\n");
    }
    STORE_POINTER(stage4_ground_table + 2, D_00252F40);
    if (stage5_ground_table[0] != 0x0) {
        printf("error! gro_stg5_tbl[0]\n");
    }
    STORE_POINTER(stage5_ground_table, stage5_ground_setup);
    if (stage5_ground_table[2] != 0x2) {
        printf("error! gro_stg5_tbl[2]\n");
    }
    STORE_POINTER(stage5_ground_table + 2, D_00253160);
    if (stage_ground_tables[0] != 0x0) {
        printf("error! gro_stg_tbl[0]\n");
    }
    STORE_POINTER(stage_ground_tables, stage1_ground_table);
    if (stage_ground_tables[2] != 0x2) {
        printf("error! gro_stg_tbl[2]\n");
    }
    STORE_POINTER(stage_ground_tables + 2, stage2_ground_table);
    if (stage_ground_tables[4] != 0x4) {
        printf("error! gro_stg_tbl[4]\n");
    }
    STORE_POINTER(stage_ground_tables + 4, stage3_ground_table);
    if (stage_ground_tables[6] != 0x6) {
        printf("error! gro_stg_tbl[6]\n");
    }
    STORE_POINTER(stage_ground_tables + 6, stage4_ground_table);
    if (stage_ground_tables[8] != 0x8) {
        printf("error! gro_stg_tbl[8]\n");
    }
    STORE_POINTER(stage_ground_tables + 8, stage5_ground_table);
    if (stage1_palette_list[0] != 0x0) {
        printf("error! avram_pal_tbl1[0]\n");
    }
    STORE_POINTER(stage1_palette_list, D_002606F0);
    if (stage1_palette_list[3] != 0x3) {
        printf("error! avram_pal_tbl1[3]\n");
    }
    STORE_POINTER(stage1_palette_list + 3, D_002606B0);
    if (stage1_palette_list[6] != 0x6) {
        printf("error! avram_pal_tbl1[6]\n");
    }
    STORE_POINTER(stage1_palette_list + 6, D_00260630);
    if (stage1_palette_list[9] != 0x9) {
        printf("error! avram_pal_tbl1[9]\n");
    }
    STORE_POINTER(stage1_palette_list + 9, D_00260670);
    if (stage1_palette_list[12] != 0xc) {
        printf("error! avram_pal_tbl1[12]\n");
    }
    STORE_POINTER(stage1_palette_list + 12, D_002607B0);
    if (stage1_palette_list[15] != 0xf) {
        printf("error! avram_pal_tbl1[15]\n");
    }
    STORE_POINTER(stage1_palette_list + 15, D_00260730);
    if (stage1_palette_list[18] != 0x12) {
        printf("error! avram_pal_tbl1[18]\n");
    }
    STORE_POINTER(stage1_palette_list + 18, D_00255470);
    if (stage1_palette_list[21] != 0x15) {
        printf("error! avram_pal_tbl1[21]\n");
    }
    STORE_POINTER(stage1_palette_list + 21, D_00261DB0);
    if (stage1_palette_list[24] != 0x18) {
        printf("error! avram_pal_tbl1[24]\n");
    }
    STORE_POINTER(stage1_palette_list + 24, D_002610B0_as_u16_a);
    if (stage1_palette_list[27] != 0x1b) {
        printf("error! avram_pal_tbl1[27]\n");
    }
    STORE_POINTER(stage1_palette_list + 27, D_00260FB0);
    if (stage1_palette_list[30] != 0x1e) {
        printf("error! avram_pal_tbl1[30]\n");
    }
    STORE_POINTER(stage1_palette_list + 30, D_00260FF0);
    if (stage1_palette_list[33] != 0x21) {
        printf("error! avram_pal_tbl1[33]\n");
    }
    STORE_POINTER(stage1_palette_list + 33, D_002610F0);
    if (stage1_palette_list[36] != 0x24) {
        printf("error! avram_pal_tbl1[36]\n");
    }
    STORE_POINTER(stage1_palette_list + 36, D_00261030);
    if (stage1_palette_list[39] != 0x27) {
        printf("error! avram_pal_tbl1[39]\n");
    }
    STORE_POINTER(stage1_palette_list + 39, D_00261D70);
    if (stage1_palette_list[42] != 0x2a) {
        printf("error! avram_pal_tbl1[42]\n");
    }
    STORE_POINTER(stage1_palette_list + 42, D_00261170);
    if (stage1_palette_list[45] != 0x2d) {
        printf("error! avram_pal_tbl1[45]\n");
    }
    STORE_POINTER(stage1_palette_list + 45, D_00261130);
    if (stage1_palette_list[48] != 0x30) {
        printf("error! avram_pal_tbl1[48]\n");
    }
    STORE_POINTER(stage1_palette_list + 48, D_002612B0);
    if (stage1_palette_list[51] != 0x33) {
        printf("error! avram_pal_tbl1[51]\n");
    }
    STORE_POINTER(stage1_palette_list + 51, D_002611B0);
    if (stage1_palette_list[54] != 0x36) {
        printf("error! avram_pal_tbl1[54]\n");
    }
    STORE_POINTER(stage1_palette_list + 54, D_002611F0);
    if (stage1_palette_list[57] != 0x39) {
        printf("error! avram_pal_tbl1[57]\n");
    }
    STORE_POINTER(stage1_palette_list + 57, D_00260730);
    if (stage1_palette_list[60] != 0x3c) {
        printf("error! avram_pal_tbl1[60]\n");
    }
    STORE_POINTER(stage1_palette_list + 60, D_00261230);
    if (stage1_palette_list[63] != 0x3f) {
        printf("error! avram_pal_tbl1[63]\n");
    }
    STORE_POINTER(stage1_palette_list + 63, D_00261270);
    if (stage1_music_list[4] != 0x4) {
        printf("error! avram_snd_tbl1[4]\n");
    }
    STORE_POINTER(stage1_music_list + 4, music_play_bgm7);
    if (stage1_ground_setup[0] != 0x0) {
        printf("error! avram_tbl1[0]\n");
    }
    STORE_POINTER(stage1_ground_setup, stage1_palette_list);
    if (stage1_ground_setup[2] != 0x2) {
        printf("error! avram_tbl1[2]\n");
    }
    STORE_POINTER(stage1_ground_setup + 2, stage1_music_list);
    if (stage2_palette_list[0] != 0x0) {
        printf("error! avram_pal_tbl2[0]\n");
    }
    STORE_POINTER(stage2_palette_list, D_00255470);
    if (stage2_palette_list[3] != 0x3) {
        printf("error! avram_pal_tbl2[3]\n");
    }
    STORE_POINTER(stage2_palette_list + 3, D_00261DB0);
    if (stage2_palette_list[6] != 0x6) {
        printf("error! avram_pal_tbl2[6]\n");
    }
    STORE_POINTER(stage2_palette_list + 6, D_002610B0_as_u16_a);
    if (stage2_palette_list[9] != 0x9) {
        printf("error! avram_pal_tbl2[9]\n");
    }
    STORE_POINTER(stage2_palette_list + 9, D_00260FB0);
    if (stage2_palette_list[12] != 0xc) {
        printf("error! avram_pal_tbl2[12]\n");
    }
    STORE_POINTER(stage2_palette_list + 12, D_00260FF0);
    if (stage2_palette_list[15] != 0xf) {
        printf("error! avram_pal_tbl2[15]\n");
    }
    STORE_POINTER(stage2_palette_list + 15, D_002610F0);
    if (stage2_palette_list[18] != 0x12) {
        printf("error! avram_pal_tbl2[18]\n");
    }
    STORE_POINTER(stage2_palette_list + 18, D_00261030);
    if (stage2_palette_list[21] != 0x15) {
        printf("error! avram_pal_tbl2[21]\n");
    }
    STORE_POINTER(stage2_palette_list + 21, D_00261D70);
    if (stage2_palette_list[24] != 0x18) {
        printf("error! avram_pal_tbl2[24]\n");
    }
    STORE_POINTER(stage2_palette_list + 24, D_002606F0);
    if (stage2_palette_list[27] != 0x1b) {
        printf("error! avram_pal_tbl2[27]\n");
    }
    STORE_POINTER(stage2_palette_list + 27, D_002606B0);
    if (stage2_palette_list[30] != 0x1e) {
        printf("error! avram_pal_tbl2[30]\n");
    }
    STORE_POINTER(stage2_palette_list + 30, D_00260630);
    if (stage2_palette_list[33] != 0x21) {
        printf("error! avram_pal_tbl2[33]\n");
    }
    STORE_POINTER(stage2_palette_list + 33, D_00260570);
    if (stage2_palette_list[36] != 0x24) {
        printf("error! avram_pal_tbl2[36]\n");
    }
    STORE_POINTER(stage2_palette_list + 36, D_002605F0);
    if (stage2_palette_list[39] != 0x27) {
        printf("error! avram_pal_tbl2[39]\n");
    }
    STORE_POINTER(stage2_palette_list + 39, D_00260730);
    if (stage2_palette_list[42] != 0x2a) {
        printf("error! avram_pal_tbl2[42]\n");
    }
    STORE_POINTER(stage2_palette_list + 42, D_00260670);
    if (stage2_palette_list[45] != 0x2d) {
        printf("error! avram_pal_tbl2[45]\n");
    }
    STORE_POINTER(stage2_palette_list + 45, D_00261370);
    if (stage2_palette_list[48] != 0x30) {
        printf("error! avram_pal_tbl2[48]\n");
    }
    STORE_POINTER(stage2_palette_list + 48, D_002614F0);
    if (stage2_palette_list[51] != 0x33) {
        printf("error! avram_pal_tbl2[51]\n");
    }
    STORE_POINTER(stage2_palette_list + 51, D_002612F0);
    if (stage2_palette_list[54] != 0x36) {
        printf("error! avram_pal_tbl2[54]\n");
    }
    STORE_POINTER(stage2_palette_list + 54, D_002605B0);
    if (stage2_palette_list[57] != 0x39) {
        printf("error! avram_pal_tbl2[57]\n");
    }
    STORE_POINTER(stage2_palette_list + 57, D_00261530);
    if (stage2_palette_list[60] != 0x3c) {
        printf("error! avram_pal_tbl2[60]\n");
    }
    STORE_POINTER(stage2_palette_list + 60, D_00261330);
    if (stage2_palette_list[63] != 0x3f) {
        printf("error! avram_pal_tbl2[63]\n");
    }
    STORE_POINTER(stage2_palette_list + 63, D_002613B0);
    if (stage2_palette_list[66] != 0x42) {
        printf("error! avram_pal_tbl2[66]\n");
    }
    STORE_POINTER(stage2_palette_list + 66, D_002613F0);
    if (stage2_palette_list[69] != 0x45) {
        printf("error! avram_pal_tbl2[69]\n");
    }
    STORE_POINTER(stage2_palette_list + 69, D_00261430);
    if (stage2_palette_list[72] != 0x48) {
        printf("error! avram_pal_tbl2[72]\n");
    }
    STORE_POINTER(stage2_palette_list + 72, D_00261470);
    if (stage2_palette_list[75] != 0x4b) {
        printf("error! avram_pal_tbl2[75]\n");
    }
    STORE_POINTER(stage2_palette_list + 75, D_002614B0);
    if (stage2_music_list[2] != 0x2) {
        printf("error! avram_snd_tbl2[2]\n");
    }
    STORE_POINTER(stage2_music_list + 2, music_play_bgm3);
    if (stage2_music_list[8] != 0x8) {
        printf("error! avram_snd_tbl2[8]\n");
    }
    STORE_POINTER(stage2_music_list + 8, music_play_bgm7);
    if (stage2_ground_setup[0] != 0x0) {
        printf("error! avram_tbl2[0]\n");
    }
    STORE_POINTER(stage2_ground_setup, stage2_palette_list);
    if (stage2_ground_setup[2] != 0x2) {
        printf("error! avram_tbl2[2]\n");
    }
    STORE_POINTER(stage2_ground_setup + 2, stage2_music_list);
    if (stage3_palette_list[0] != 0x0) {
        printf("error! avram_pal_tbl3[0]\n");
    }
    STORE_POINTER(stage3_palette_list, D_00255470);
    if (stage3_palette_list[3] != 0x3) {
        printf("error! avram_pal_tbl3[3]\n");
    }
    STORE_POINTER(stage3_palette_list + 3, D_00261DB0);
    if (stage3_palette_list[6] != 0x6) {
        printf("error! avram_pal_tbl3[6]\n");
    }
    STORE_POINTER(stage3_palette_list + 6, D_002610B0_as_u16_a);
    if (stage3_palette_list[9] != 0x9) {
        printf("error! avram_pal_tbl3[9]\n");
    }
    STORE_POINTER(stage3_palette_list + 9, D_00260FB0);
    if (stage3_palette_list[12] != 0xc) {
        printf("error! avram_pal_tbl3[12]\n");
    }
    STORE_POINTER(stage3_palette_list + 12, D_00260FF0);
    if (stage3_palette_list[15] != 0xf) {
        printf("error! avram_pal_tbl3[15]\n");
    }
    STORE_POINTER(stage3_palette_list + 15, D_002610F0);
    if (stage3_palette_list[18] != 0x12) {
        printf("error! avram_pal_tbl3[18]\n");
    }
    STORE_POINTER(stage3_palette_list + 18, D_00261030);
    if (stage3_palette_list[21] != 0x15) {
        printf("error! avram_pal_tbl3[21]\n");
    }
    STORE_POINTER(stage3_palette_list + 21, D_00261D70);
    if (stage3_palette_list[24] != 0x18) {
        printf("error! avram_pal_tbl3[24]\n");
    }
    STORE_POINTER(stage3_palette_list + 24, D_002606F0);
    if (stage3_palette_list[27] != 0x1b) {
        printf("error! avram_pal_tbl3[27]\n");
    }
    STORE_POINTER(stage3_palette_list + 27, D_002606B0);
    if (stage3_palette_list[30] != 0x1e) {
        printf("error! avram_pal_tbl3[30]\n");
    }
    STORE_POINTER(stage3_palette_list + 30, D_00260630);
    if (stage3_palette_list[33] != 0x21) {
        printf("error! avram_pal_tbl3[33]\n");
    }
    STORE_POINTER(stage3_palette_list + 33, D_002608B0);
    if (stage3_palette_list[36] != 0x24) {
        printf("error! avram_pal_tbl3[36]\n");
    }
    STORE_POINTER(stage3_palette_list + 36, D_002605F0);
    if (stage3_palette_list[39] != 0x27) {
        printf("error! avram_pal_tbl3[39]\n");
    }
    STORE_POINTER(stage3_palette_list + 39, D_00260730);
    if (stage3_palette_list[42] != 0x2a) {
        printf("error! avram_pal_tbl3[42]\n");
    }
    STORE_POINTER(stage3_palette_list + 42, D_00260670);
    if (stage3_palette_list[45] != 0x2d) {
        printf("error! avram_pal_tbl3[45]\n");
    }
    STORE_POINTER(stage3_palette_list + 45, D_00260630);
    if (stage3_palette_list[48] != 0x30) {
        printf("error! avram_pal_tbl3[48]\n");
    }
    STORE_POINTER(stage3_palette_list + 48, D_002608F0);
    if (stage3_palette_list[51] != 0x33) {
        printf("error! avram_pal_tbl3[51]\n");
    }
    STORE_POINTER(stage3_palette_list + 51, D_002606B0);
    if (stage3_palette_list[54] != 0x36) {
        printf("error! avram_pal_tbl3[54]\n");
    }
    STORE_POINTER(stage3_palette_list + 54, D_002616B0);
    if (stage3_palette_list[57] != 0x39) {
        printf("error! avram_pal_tbl3[57]\n");
    }
    STORE_POINTER(stage3_palette_list + 57, D_00261670);
    if (stage3_palette_list[60] != 0x3c) {
        printf("error! avram_pal_tbl3[60]\n");
    }
    STORE_POINTER(stage3_palette_list + 60, D_00261630);
    if (stage3_palette_list[63] != 0x3f) {
        printf("error! avram_pal_tbl3[63]\n");
    }
    STORE_POINTER(stage3_palette_list + 63, D_002615F0);
    if (stage3_palette_list[66] != 0x42) {
        printf("error! avram_pal_tbl3[66]\n");
    }
    STORE_POINTER(stage3_palette_list + 66, D_00261570);
    if (stage3_palette_list[69] != 0x45) {
        printf("error! avram_pal_tbl3[69]\n");
    }
    STORE_POINTER(stage3_palette_list + 69, D_002615B0);
    if (stage3_music_list[2] != 0x2) {
        printf("error! avram_snd_tbl3[2]\n");
    }
    STORE_POINTER(stage3_music_list + 2, music_play_bgm4);
    if (stage3_music_list[8] != 0x8) {
        printf("error! avram_snd_tbl3[8]\n");
    }
    STORE_POINTER(stage3_music_list + 8, music_play_bgm7);
    if (stage3_ground_setup[0] != 0x0) {
        printf("error! avram_tbl3[0]\n");
    }
    STORE_POINTER(stage3_ground_setup, stage3_palette_list);
    if (stage3_ground_setup[2] != 0x2) {
        printf("error! avram_tbl3[2]\n");
    }
    STORE_POINTER(stage3_ground_setup + 2, stage3_music_list);
    if (stage4_palette_list[0] != 0x0) {
        printf("error! avram_pal_tbl4[0]\n");
    }
    STORE_POINTER(stage4_palette_list, D_00255470);
    if (stage4_palette_list[3] != 0x3) {
        printf("error! avram_pal_tbl4[3]\n");
    }
    STORE_POINTER(stage4_palette_list + 3, D_00261DB0);
    if (stage4_palette_list[6] != 0x6) {
        printf("error! avram_pal_tbl4[6]\n");
    }
    STORE_POINTER(stage4_palette_list + 6, D_002610B0_as_u16_a);
    if (stage4_palette_list[9] != 0x9) {
        printf("error! avram_pal_tbl4[9]\n");
    }
    STORE_POINTER(stage4_palette_list + 9, D_00260FB0);
    if (stage4_palette_list[12] != 0xc) {
        printf("error! avram_pal_tbl4[12]\n");
    }
    STORE_POINTER(stage4_palette_list + 12, D_00260FF0);
    if (stage4_palette_list[15] != 0xf) {
        printf("error! avram_pal_tbl4[15]\n");
    }
    STORE_POINTER(stage4_palette_list + 15, D_002610F0);
    if (stage4_palette_list[18] != 0x12) {
        printf("error! avram_pal_tbl4[18]\n");
    }
    STORE_POINTER(stage4_palette_list + 18, D_00261030);
    if (stage4_palette_list[21] != 0x15) {
        printf("error! avram_pal_tbl4[21]\n");
    }
    STORE_POINTER(stage4_palette_list + 21, D_00261D70);
    if (stage4_palette_list[24] != 0x18) {
        printf("error! avram_pal_tbl4[24]\n");
    }
    STORE_POINTER(stage4_palette_list + 24, D_002606F0);
    if (stage4_palette_list[27] != 0x1b) {
        printf("error! avram_pal_tbl4[27]\n");
    }
    STORE_POINTER(stage4_palette_list + 27, D_002606B0);
    if (stage4_palette_list[30] != 0x1e) {
        printf("error! avram_pal_tbl4[30]\n");
    }
    STORE_POINTER(stage4_palette_list + 30, D_00260630);
    if (stage4_palette_list[33] != 0x21) {
        printf("error! avram_pal_tbl4[33]\n");
    }
    STORE_POINTER(stage4_palette_list + 33, D_002605F0);
    if (stage4_palette_list[36] != 0x24) {
        printf("error! avram_pal_tbl4[36]\n");
    }
    STORE_POINTER(stage4_palette_list + 36, D_00260730);
    if (stage4_palette_list[39] != 0x27) {
        printf("error! avram_pal_tbl4[39]\n");
    }
    STORE_POINTER(stage4_palette_list + 39, D_002607F0);
    if (stage4_palette_list[42] != 0x2a) {
        printf("error! avram_pal_tbl4[42]\n");
    }
    STORE_POINTER(stage4_palette_list + 42, D_00261A30);
    if (stage4_palette_list[45] != 0x2d) {
        printf("error! avram_pal_tbl4[45]\n");
    }
    STORE_POINTER(stage4_palette_list + 45, D_00261930);
    if (stage4_palette_list[48] != 0x30) {
        printf("error! avram_pal_tbl4[48]\n");
    }
    STORE_POINTER(stage4_palette_list + 48, D_00261730_as_u16_a);
    if (stage4_palette_list[51] != 0x33) {
        printf("error! avram_pal_tbl4[51]\n");
    }
    STORE_POINTER(stage4_palette_list + 51, D_00261970);
    if (stage4_palette_list[54] != 0x36) {
        printf("error! avram_pal_tbl4[54]\n");
    }
    STORE_POINTER(stage4_palette_list + 54, D_002619B0);
    if (stage4_palette_list[57] != 0x39) {
        printf("error! avram_pal_tbl4[57]\n");
    }
    STORE_POINTER(stage4_palette_list + 57, D_00260830);
    if (stage4_palette_list[60] != 0x3c) {
        printf("error! avram_pal_tbl4[60]\n");
    }
    STORE_POINTER(stage4_palette_list + 60, D_002607F0);
    if (stage4_palette_list[63] != 0x3f) {
        printf("error! avram_pal_tbl4[63]\n");
    }
    STORE_POINTER(stage4_palette_list + 63, D_002619F0);
    if (stage4_music_list[2] != 0x2) {
        printf("error! avram_snd_tbl4[2]\n");
    }
    STORE_POINTER(stage4_music_list + 2, music_play_bgm5);
    if (stage4_music_list[8] != 0x8) {
        printf("error! avram_snd_tbl4[8]\n");
    }
    STORE_POINTER(stage4_music_list + 8, music_play_bgm7);
    if (stage4_ground_setup[0] != 0x0) {
        printf("error! avram_tbl4[0]\n");
    }
    STORE_POINTER(stage4_ground_setup, stage4_palette_list);
    if (stage4_ground_setup[2] != 0x2) {
        printf("error! avram_tbl4[2]\n");
    }
    STORE_POINTER(stage4_ground_setup + 2, stage4_music_list);
    if (stage5_palette_list[0] != 0x0) {
        printf("error! avram_pal_tbl5[0]\n");
    }
    STORE_POINTER(stage5_palette_list, D_00255470);
    if (stage5_palette_list[3] != 0x3) {
        printf("error! avram_pal_tbl5[3]\n");
    }
    STORE_POINTER(stage5_palette_list + 3, D_00261DB0);
    if (stage5_palette_list[6] != 0x6) {
        printf("error! avram_pal_tbl5[6]\n");
    }
    STORE_POINTER(stage5_palette_list + 6, D_002610B0_as_u16_a);
    if (stage5_palette_list[9] != 0x9) {
        printf("error! avram_pal_tbl5[9]\n");
    }
    STORE_POINTER(stage5_palette_list + 9, D_00260FB0);
    if (stage5_palette_list[12] != 0xc) {
        printf("error! avram_pal_tbl5[12]\n");
    }
    STORE_POINTER(stage5_palette_list + 12, D_00260FF0);
    if (stage5_palette_list[15] != 0xf) {
        printf("error! avram_pal_tbl5[15]\n");
    }
    STORE_POINTER(stage5_palette_list + 15, D_002610F0);
    if (stage5_palette_list[18] != 0x12) {
        printf("error! avram_pal_tbl5[18]\n");
    }
    STORE_POINTER(stage5_palette_list + 18, D_00261030);
    if (stage5_palette_list[21] != 0x15) {
        printf("error! avram_pal_tbl5[21]\n");
    }
    STORE_POINTER(stage5_palette_list + 21, D_00261D70);
    if (stage5_palette_list[24] != 0x18) {
        printf("error! avram_pal_tbl5[24]\n");
    }
    STORE_POINTER(stage5_palette_list + 24, D_002606F0);
    if (stage5_palette_list[27] != 0x1b) {
        printf("error! avram_pal_tbl5[27]\n");
    }
    STORE_POINTER(stage5_palette_list + 27, D_002606B0);
    if (stage5_palette_list[30] != 0x1e) {
        printf("error! avram_pal_tbl5[30]\n");
    }
    STORE_POINTER(stage5_palette_list + 30, D_00260630);
    if (stage5_palette_list[33] != 0x21) {
        printf("error! avram_pal_tbl5[33]\n");
    }
    STORE_POINTER(stage5_palette_list + 33, D_002605F0);
    if (stage5_palette_list[36] != 0x24) {
        printf("error! avram_pal_tbl5[36]\n");
    }
    STORE_POINTER(stage5_palette_list + 36, D_00260730);
    if (stage5_palette_list[39] != 0x27) {
        printf("error! avram_pal_tbl5[39]\n");
    }
    STORE_POINTER(stage5_palette_list + 39, D_002608B0);
    if (stage5_palette_list[42] != 0x2a) {
        printf("error! avram_pal_tbl5[42]\n");
    }
    STORE_POINTER(stage5_palette_list + 42, D_00261AB0);
    if (stage5_palette_list[45] != 0x2d) {
        printf("error! avram_pal_tbl5[45]\n");
    }
    STORE_POINTER(stage5_palette_list + 45, D_00261A70);
    if (stage5_palette_list[48] != 0x30) {
        printf("error! avram_pal_tbl5[48]\n");
    }
    STORE_POINTER(stage5_palette_list + 48, D_00260670);
    if (stage5_palette_list[51] != 0x33) {
        printf("error! avram_pal_tbl5[51]\n");
    }
    STORE_POINTER(stage5_palette_list + 51, D_00260770);
    if (stage5_palette_list[54] != 0x36) {
        printf("error! avram_pal_tbl5[54]\n");
    }
    STORE_POINTER(stage5_palette_list + 54, D_00261B30);
    if (stage5_palette_list[57] != 0x39) {
        printf("error! avram_pal_tbl5[57]\n");
    }
    STORE_POINTER(stage5_palette_list + 57, D_00261B70);
    if (stage5_music_list[2] != 0x2) {
        printf("error! avram_snd_tbl5[2]\n");
    }
    STORE_POINTER(stage5_music_list + 2, music_play_bgm6);
    if (stage5_music_list[8] != 0x8) {
        printf("error! avram_snd_tbl5[8]\n");
    }
    STORE_POINTER(stage5_music_list + 8, music_play_bgm8);
    if (stage5_ground_setup[0] != 0x0) {
        printf("error! avram_tbl5[0]\n");
    }
    STORE_POINTER(stage5_ground_setup, stage5_palette_list);
    if (stage5_ground_setup[2] != 0x2) {
        printf("error! avram_tbl5[2]\n");
    }
    STORE_POINTER(stage5_ground_setup + 2, stage5_music_list);
    if (D_0025BF98[0] != 0x4) {
        printf("error! name_fin_tbl[4]\n");
    }
    STORE_POINTER(D_0025BF98, D_00261F30);
    if (D_0025BFA6[0] != 0xb) {
        printf("error! name_fin_tbl[11]\n");
    }
    STORE_POINTER(D_0025BFA6, D_00261F70_as_u16_a);
    if (D_0025BFB4[0] != 0x12) {
        printf("error! name_fin_tbl[18]\n");
    }
    STORE_POINTER(D_0025BFB4, D_00261FB0_as_u16_a);
    if (D_0025BFC2[0] != 0x19) {
        printf("error! name_fin_tbl[25]\n");
    }
    STORE_POINTER(D_0025BFC2, D_00261EF0_as_u16_a);
    if (name_entry_letter_table[0] != 0x0) {
        printf("error! nam_mozi_dir[0]\n");
    }
    STORE_POINTER(name_entry_letter_table, D_0025C040);
    if (name_entry_letter_table[2] != 0x2) {
        printf("error! nam_mozi_dir[2]\n");
    }
    STORE_POINTER(name_entry_letter_table + 2, D_0025C060);
    if (name_entry_letter_table[4] != 0x4) {
        printf("error! nam_mozi_dir[4]\n");
    }
    STORE_POINTER(name_entry_letter_table + 4, D_0025C080);
    if (name_entry_letter_table[6] != 0x6) {
        printf("error! nam_mozi_dir[6]\n");
    }
    STORE_POINTER(name_entry_letter_table + 6, D_0025C0A0);
    if (name_entry_letter_table[8] != 0x8) {
        printf("error! nam_mozi_dir[8]\n");
    }
    STORE_POINTER(name_entry_letter_table + 8, D_0025C0C0);
    if (name_entry_letter_table[10] != 0xa) {
        printf("error! nam_mozi_dir[10]\n");
    }
    STORE_POINTER(name_entry_letter_table + 10, D_0025C0E0);
    if (name_entry_letter_table[12] != 0xc) {
        printf("error! nam_mozi_dir[12]\n");
    }
    STORE_POINTER(name_entry_letter_table + 12, D_0025C100);
    if (name_entry_letter_table[14] != 0xe) {
        printf("error! nam_mozi_dir[14]\n");
    }
    STORE_POINTER(name_entry_letter_table + 14, D_0025C120);
    if (name_entry_letter_table[16] != 0x10) {
        printf("error! nam_mozi_dir[16]\n");
    }
    STORE_POINTER(name_entry_letter_table + 16, D_0025C140);
    if (name_entry_letter_table[18] != 0x12) {
        printf("error! nam_mozi_dir[18]\n");
    }
    STORE_POINTER(name_entry_letter_table + 18, D_0025C160);
    if (name_entry_letter_table[20] != 0x14) {
        printf("error! nam_mozi_dir[20]\n");
    }
    STORE_POINTER(name_entry_letter_table + 20, D_0025C180);
    if (name_entry_letter_table[22] != 0x16) {
        printf("error! nam_mozi_dir[22]\n");
    }
    STORE_POINTER(name_entry_letter_table + 22, D_0025C1A0);
    if (name_entry_letter_table[24] != 0x18) {
        printf("error! nam_mozi_dir[24]\n");
    }
    STORE_POINTER(name_entry_letter_table + 24, D_0025C1C0);
    if (name_entry_letter_table[26] != 0x1a) {
        printf("error! nam_mozi_dir[26]\n");
    }
    STORE_POINTER(name_entry_letter_table + 26, D_0025C1E0);
    if (name_entry_letter_table[28] != 0x1c) {
        printf("error! nam_mozi_dir[28]\n");
    }
    STORE_POINTER(name_entry_letter_table + 28, D_0025C200);
    if (name_entry_letter_table[30] != 0x1e) {
        printf("error! nam_mozi_dir[30]\n");
    }
    STORE_POINTER(name_entry_letter_table + 30, D_0025C220);
    if (name_entry_letter_table[32] != 0x20) {
        printf("error! nam_mozi_dir[32]\n");
    }
    STORE_POINTER(name_entry_letter_table + 32, D_0025C240);
    if (name_entry_letter_table[34] != 0x22) {
        printf("error! nam_mozi_dir[34]\n");
    }
    STORE_POINTER(name_entry_letter_table + 34, D_0025C260);
    if (name_entry_letter_table[36] != 0x24) {
        printf("error! nam_mozi_dir[36]\n");
    }
    STORE_POINTER(name_entry_letter_table + 36, D_0025C280);
    if (name_entry_letter_table[38] != 0x26) {
        printf("error! nam_mozi_dir[38]\n");
    }
    STORE_POINTER(name_entry_letter_table + 38, D_0025C2A0);
    if (name_entry_letter_table[40] != 0x28) {
        printf("error! nam_mozi_dir[40]\n");
    }
    STORE_POINTER(name_entry_letter_table + 40, D_0025C2C0);
    if (name_entry_letter_table[42] != 0x2a) {
        printf("error! nam_mozi_dir[42]\n");
    }
    STORE_POINTER(name_entry_letter_table + 42, D_0025C2E0);
    if (name_entry_letter_table[44] != 0x2c) {
        printf("error! nam_mozi_dir[44]\n");
    }
    STORE_POINTER(name_entry_letter_table + 44, D_0025C300);
    if (name_entry_letter_table[46] != 0x2e) {
        printf("error! nam_mozi_dir[46]\n");
    }
    STORE_POINTER(name_entry_letter_table + 46, D_0025C320);
    if (name_entry_letter_table[48] != 0x30) {
        printf("error! nam_mozi_dir[48]\n");
    }
    STORE_POINTER(name_entry_letter_table + 48, D_0025C340);
    if (name_entry_letter_table[50] != 0x32) {
        printf("error! nam_mozi_dir[50]\n");
    }
    STORE_POINTER(name_entry_letter_table + 50, D_0025C360);
    if (name_entry_letter_table[52] != 0x34) {
        printf("error! nam_mozi_dir[52]\n");
    }
    STORE_POINTER(name_entry_letter_table + 52, D_0025C380);
    if (name_entry_letter_table[54] != 0x36) {
        printf("error! nam_mozi_dir[54]\n");
    }
    STORE_POINTER(name_entry_letter_table + 54, D_0025C3A0);
    if (D_00251A80_as_u16_a[1] != 0x1) {
        printf("error! dollsel_data_1p[1]\n");
    }
    reg_tmp.w = (u32)input_get_p1_held;
    D_00251A80_as_u16_a[1] = reg_tmp.h[1];
    D_00251A84[0] = reg_tmp.h[0];
    if (D_00251A84[1] != 0x3) {
        printf("error! dollsel_data_1p[3]\n");
    }
    STORE_POINTER(D_00251A84 + 1, input_get_p1_pressed);
    if (D_00251A90_as_u16_a[1] != 0x1) {
        printf("error! dollsel_data_2p[1]\n");
    }
    reg_tmp.w = (u32)input_get_p2_held;
    D_00251A90_as_u16_a[1] = reg_tmp.h[1];
    D_00251A94[0] = reg_tmp.h[0];
    if (D_00251A94[1] != 0x3) {
        printf("error! dollsel_data_2p[3]\n");
    }
    STORE_POINTER(D_00251A94 + 1, input_get_p2_pressed);
    if (D_00251AB0_as_u16_a[1] != 0x1) {
        printf("error! figsel_data_1p[1]\n");
    }
    reg_tmp.w = (u32)input_get_p1_held;
    D_00251AB0_as_u16_a[1] = reg_tmp.h[1];
    D_00251AB4[0] = reg_tmp.h[0];
    if (D_00251AB4[1] != 0x3) {
        printf("error! figsel_data_1p[3]\n");
    }
    STORE_POINTER(D_00251AB4 + 1, input_get_p1_pressed);
    if (D_00251AC0_as_u16_a[1] != 0x1) {
        printf("error! figsel_data_2p[1]\n");
    }
    reg_tmp.w = (u32)input_get_p2_held;
    D_00251AC0_as_u16_a[1] = reg_tmp.h[1];
    D_00251AC4[0] = reg_tmp.h[0];
    if (D_00251AC4[1] != 0x3) {
        printf("error! figsel_data_2p[3]\n");
    }
    STORE_POINTER(D_00251AC4 + 1, input_get_p2_pressed);
    if (D_00251AE0[2] != 0x2) {
        printf("error! sel_game_tbl_1p[2]\n");
    }
    STORE_POINTER(D_00251AE0 + 2, input_get_p1_held);
    if (D_00251AE0[4] != 0x4) {
        printf("error! sel_game_tbl_1p[4]\n");
    }
    STORE_POINTER(D_00251AE0 + 4, input_get_p1_pressed);
    if (D_00251AE0[6] != 0x6) {
        printf("error! sel_game_tbl_1p[6]\n");
    }
    STORE_POINTER(D_00251AE0 + 6, func_00130270);
    if (D_00251AE0[8] != 0x8) {
        printf("error! sel_game_tbl_1p[8]\n");
    }
    STORE_POINTER(D_00251AE0 + 8, D_0029BF40_as_u16_a);
    if (D_00251B00[2] != 0x2) {
        printf("error! sel_game_tbl_2p[2]\n");
    }
    STORE_POINTER(D_00251B00 + 2, input_get_p2_held);
    if (D_00251B00[4] != 0x4) {
        printf("error! sel_game_tbl_2p[4]\n");
    }
    STORE_POINTER(D_00251B00 + 4, input_get_p2_pressed);
    if (D_00251B00[6] != 0x6) {
        printf("error! sel_game_tbl_2p[6]\n");
    }
    STORE_POINTER(D_00251B00 + 6, func_001303A0);
    if (D_00251B00[8] != 0x8) {
        printf("error! sel_game_tbl_2p[8]\n");
    }
    STORE_POINTER(D_00251B00 + 8, D_0029BF30_as_u16_a);
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
    if (D_0028C148_as_u16_a[0] != 0x0) {
        printf("error! subsel_fig_barner[0]\n");
    }
    reg_tmp.w = (u32)D_0028C680;
    D_0028C148_as_u16_a[0] = reg_tmp.h[1];
    D_0028C14A[0] = reg_tmp.h[0];
    if (D_0028C14A[1] != 0x2) {
        printf("error! subsel_fig_barner[2]\n");
    }
    STORE_POINTER(D_0028C14A + 1, D_0028C708);
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
    if (D_002643E0_as_u16_a[0] != 0x0) {
        printf("error! st5b_2_tsuno_sht_ofs_tbl[0]\n");
    }
    reg_tmp.w = (u32)D_002644E0;
    D_002643E0_as_u16_a[0] = reg_tmp.h[1];
    D_002643E2[0] = reg_tmp.h[0];
    if (D_002643E2[1] != 0x2) {
        printf("error! st5b_2_tsuno_sht_ofs_tbl[2]\n");
    }
    STORE_POINTER(D_002643E2 + 1, D_00264490);
    if (D_002643E2[3] != 0x4) {
        printf("error! st5b_2_tsuno_sht_ofs_tbl[4]\n");
    }
    STORE_POINTER(D_002643E2 + 3, D_00264440);
    if (D_002643E2[5] != 0x6) {
        printf("error! st5b_2_tsuno_sht_ofs_tbl[6]\n");
    }
    STORE_POINTER(D_002643E2 + 5, D_002643F0);
    if (D_00264C30[4] != 0x4) {
        printf("error! st5b_mo1_flush_tbl[4]\n");
    }
    STORE_POINTER(D_00264C30 + 4, D_002610F0);
    if (D_00264C30[11] != 0xb) {
        printf("error! st5b_mo1_flush_tbl[11]\n");
    }
    STORE_POINTER(D_00264C30 + 11, D_0025FF70_as_u16_a);
    if (D_00264C30[18] != 0x12) {
        printf("error! st5b_mo1_flush_tbl[18]\n");
    }
    STORE_POINTER(D_00264C30 + 18, D_0025FFB0_as_u16_a);
    if (D_00264C30[25] != 0x19) {
        printf("error! st5b_mo1_flush_tbl[25]\n");
    }
    STORE_POINTER(D_00264C30 + 25, D_0025FFF0_as_u16_a);
    if (D_00264C30[32] != 0x20) {
        printf("error! st5b_mo1_flush_tbl[32]\n");
    }
    STORE_POINTER(D_00264C30 + 32, D_00260030_as_u16_a);
    if (D_00264C30[39] != 0x27) {
        printf("error! st5b_mo1_flush_tbl[39]\n");
    }
    STORE_POINTER(D_00264C30 + 39, D_00260070_as_u16_a);
    if (D_00264C30[46] != 0x2e) {
        printf("error! st5b_mo1_flush_tbl[46]\n");
    }
    STORE_POINTER(D_00264C30 + 46, D_002600B0_as_u16_a);
    if (D_00264C30[53] != 0x35) {
        printf("error! st5b_mo1_flush_tbl[53]\n");
    }
    STORE_POINTER(D_00264C30 + 53, D_002600F0_as_u16_a);
    if (D_00264C30[60] != 0x3c) {
        printf("error! st5b_mo1_flush_tbl[60]\n");
    }
    STORE_POINTER(D_00264C30 + 60, D_0024CA40);
    if (D_00264C30[67] != 0x43) {
        printf("error! st5b_mo1_flush_tbl[67]\n");
    }
    STORE_POINTER(D_00264C30 + 67, D_0024CA80);
    if (D_00264C30[74] != 0x4a) {
        printf("error! st5b_mo1_flush_tbl[74]\n");
    }
    STORE_POINTER(D_00264C30 + 74, D_0024CAC0);
    if (D_00264C30[81] != 0x51) {
        printf("error! st5b_mo1_flush_tbl[81]\n");
    }
    STORE_POINTER(D_00264C30 + 81, D_0024CB00);
    if (D_00264C30[88] != 0x58) {
        printf("error! st5b_mo1_flush_tbl[88]\n");
    }
    STORE_POINTER(D_00264C30 + 88, D_0024CB40);
    if (D_00264C30[95] != 0x5f) {
        printf("error! st5b_mo1_flush_tbl[95]\n");
    }
    STORE_POINTER(D_00264C30 + 95, D_0024CB80);
    if (D_00264D00[4] != 0x4) {
        printf("error! st5b_mo3_flush_tbl[4]\n");
    }
    STORE_POINTER(D_00264D00 + 4, D_002610F0);
    if (D_00264D00[11] != 0xb) {
        printf("error! st5b_mo3_flush_tbl[11]\n");
    }
    STORE_POINTER(D_00264D00 + 11, D_00260130_as_u16_a);
    if (D_00264D00[18] != 0x12) {
        printf("error! st5b_mo3_flush_tbl[18]\n");
    }
    STORE_POINTER(D_00264D00 + 18, D_00260170_as_u16_a);
    if (D_00264D00[25] != 0x19) {
        printf("error! st5b_mo3_flush_tbl[25]\n");
    }
    STORE_POINTER(D_00264D00 + 25, D_0024CA40);
    if (D_00264D00[32] != 0x20) {
        printf("error! st5b_mo3_flush_tbl[32]\n");
    }
    STORE_POINTER(D_00264D00 + 32, D_0024CA80);
    if (D_00264D00[39] != 0x27) {
        printf("error! st5b_mo3_flush_tbl[39]\n");
    }
    STORE_POINTER(D_00264D00 + 39, D_0024CAC0);
    if (D_00264D00[46] != 0x2e) {
        printf("error! st5b_mo3_flush_tbl[46]\n");
    }
    STORE_POINTER(D_00264D00 + 46, D_0024CB00);
    if (D_00264D00[53] != 0x35) {
        printf("error! st5b_mo3_flush_tbl[53]\n");
    }
    STORE_POINTER(D_00264D00 + 53, D_0024CB40);
    if (D_00264D00[60] != 0x3c) {
        printf("error! st5b_mo3_flush_tbl[60]\n");
    }
    STORE_POINTER(D_00264D00 + 60, D_0024CB80);
    if (D_00264E10[4] != 0x4) {
        printf("error! st5bflush0_tbl[4]\n");
    }
    STORE_POINTER(D_00264E10 + 4, D_002610F0);
    if (D_00264E10[11] != 0xb) {
        printf("error! st5bflush0_tbl[11]\n");
    }
    STORE_POINTER(D_00264E10 + 11, D_0024CA40);
    if (D_00264E10[18] != 0x12) {
        printf("error! st5bflush0_tbl[18]\n");
    }
    STORE_POINTER(D_00264E10 + 18, D_0024CA80);
    if (D_00264E10[25] != 0x19) {
        printf("error! st5bflush0_tbl[25]\n");
    }
    STORE_POINTER(D_00264E10 + 25, D_0024CAC0);
    if (D_00264E10[32] != 0x20) {
        printf("error! st5bflush0_tbl[32]\n");
    }
    STORE_POINTER(D_00264E10 + 32, D_0024CB00);
    if (D_00264E10[39] != 0x27) {
        printf("error! st5bflush0_tbl[39]\n");
    }
    STORE_POINTER(D_00264E10 + 39, D_0024CB40);
    if (D_00264E10[46] != 0x2e) {
        printf("error! st5bflush0_tbl[46]\n");
    }
    STORE_POINTER(D_00264E10 + 46, D_0024CB80);
    if (D_00264E80[3] != 0x3) {
        printf("error! st5bmd2_fade_tbl0[3]\n");
    }
    STORE_POINTER(D_00264E80 + 3, D_00261D30);
    if (D_00264E80[9] != 0x9) {
        printf("error! st5bmd2_fade_tbl0[9]\n");
    }
    STORE_POINTER(D_00264E80 + 9, D_00261D30);
    if (D_00264EA0[4] != 0x4) {
        printf("error! st5b_siro_fade_tbl0[4]\n");
    }
    STORE_POINTER(D_00264EA0 + 4, D_0025FF70_as_u16_a);
    if (D_00264EA0[11] != 0xb) {
        printf("error! st5b_siro_fade_tbl0[11]\n");
    }
    STORE_POINTER(D_00264EA0 + 11, D_0025FFB0_as_u16_a);
    if (D_00264EA0[18] != 0x12) {
        printf("error! st5b_siro_fade_tbl0[18]\n");
    }
    STORE_POINTER(D_00264EA0 + 18, D_0025FFF0_as_u16_a);
    if (D_00264EA0[25] != 0x19) {
        printf("error! st5b_siro_fade_tbl0[25]\n");
    }
    STORE_POINTER(D_00264EA0 + 25, D_002600F0_as_u16_a);
}


s32 text_layer_clear();
s32 music_play_bgm13();
s32 sprite_palette_load();
s32 func_001ACBA0();
s32 func_001ACC60();
s32 stage_map_reset();
extern u8 D_00261EF0[];
extern u8 D_00261F30_as_u8_a[];
extern u8 D_00261F70[];
extern u8 D_00261FB0[];
extern u16 D_0028E4B0;
extern u8 D_0028E8B4;
extern u16 g_two_player_seen;
extern s16 g_player2[];
extern s16 g_player1[];
extern u8 D_002BAE00[];

void func_00197F60() {
    stage_map_reset();
#ifndef DEATH_LABEL
    D_0028E4B0 = g_two_player_seen;
#endif
    text_layer_clear();
    *(s8 *)(reg_a5 + 3) = 1;
    memset(D_002BAE00, 0, 0x84);
    reg_a0 = (u8 *)D_00261F30_as_u8_a;
    reg_d0.h[0] = 2;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00261F70;
    reg_d0.h[0] = 3;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00261FB0;
    reg_d0.h[0] = 4;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00261EF0;
    reg_d0.h[0] = 5;
    sprite_palette_load();
    if (0 > g_player1[0]) {
        func_001ACBA0();
        if (cond_flag == 0) {
            D_0028E8B4 |= 1;
        }
    }
    if (0 > g_player2[0]) {
        func_001ACC60();
        if (cond_flag == 0) {
            D_0028E8B4 |= 2;
        }
    }
    *(u8 *)(reg_a5 + 4) = (u8) D_0028E8B4;
    if (*(u8 *)(reg_a5 + 4) != 0) {
        music_play_bgm13();
    }
}

s32 text_layer_clear();                            /* extern */
s32 func_00135ED0();                            /* extern */
s32 func_00137C20();                            /* extern */
s32 func_0013FD80();                            /* extern */
s32 sound_stop_effects();                            /* extern */
s32 text_palette_load();                            /* extern */
extern s32 test_palette_0_as_s32_a[];
extern u8 D_0028E258;
extern u8 D_0028E25C;
extern u8 g_game_mode;
extern s32 D_0028EAFC;

void func_001980A0() {
    func_0013FD80();
    func_00137C20();
    func_00135ED0();
    task_stop_self();
    sound_stop_effects();
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)test_palette_0_as_s32_a;
    text_palette_load();
    if ((s32) D_0028E258 < (s32) D_0028E25C) {
        D_0028E258 = D_0028E25C;
    }
    if (g_game_mode == 2) {
        func_001984C0();
    } else if (func_001981F0() != 0) {
        func_001984C0();
    } else {
        D_0028EAFC = 0xFF;
    }
    reg_d0.h[0] = TASK_ATTRACT;
    task_start();
    (*(s16 *)((u8 *)((s32 *)reg_a0) + (4))) = 0x12;
}

u8 func_00198170(s32 a, s32 b) {
    s8 i;
    s8 val = (s8)a;
    for (i = 0; i < (s8)b; i++) {
        s8 bit = (s8)(val & 1);
        val >>= 1;
        val &= 0x7F;
        if (bit) {
            val |= -0x80;
        }
    }
    return (u8)val;
}

extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u8 g_setting_difficulty;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;

s32 func_001981F0(void) {
    if ((g_setting_difficulty == 1) && (g_setting_extend == 0) && (g_setting_ship_stock == 0) && (g_game_mode == 0) && (g_p1_score_digits == 0) && (g_p2_score_digits == 0) && (MAIN_OR_DEATH_LABEL(D_0028E4B0, g_two_player_seen) != 3)) {
#ifdef DEATH_LABEL
        printf("-----pass word ok!!------\n");
#else
        printf("-----pass word ok!!---[%d]---\n", D_0028E4B0);
#endif
        return 1;
    }
    return 0;
}

s32 rand(void);
extern s8 D_0025C4A0[];
extern s32 D_0028E4AC;
extern u8 D_002BAD50[];
extern u8 D_002BAD63[];
extern u8 D_002BAD70[];
extern s8 D_002BADD0_as_s8_a[];
extern u8 D_002BADF0[];

s32 func_00198280(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 val;
    u8 ch;

    memset(D_002BAD70, 0, 0x60);
    k = 0;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 8; j++) {
            if (D_002BADF0[i] & (1 << j)) {
                D_002BAD70[k] = 1;
            }
            k++;
        }
    }
    memset(D_002BAD50, 0, 20);
    k = 0;
    for (i = 0; i < 20; i++) {
        val = 0;
        for (j = 0; j < 5; j++) {
            if (D_002BAD70[k] != 0) {
                val |= 1 << j;
            }
            k++;
        }
        D_002BAD50[i] = val;
    }
    for (i = 0; i < 4; i++) {
        if ((rand() % 2) != 0) {
            D_002BAD63[0] |= 1 << (i + 1);
        }
    }
    D_0028E4AC = 0;
    for (i = 0; D_0025C4A0[i] != -1; i++) {
        D_0028E4AC++;
    }
    memset(D_002BADD0_as_s8_a, 0, 30);
    for (i = 0; i < 20; i++) {
        ch = D_002BAD50[i];
        if ((((s32) ch < 0) || ((s32) ch >= D_0028E4AC)) ? 1 : 0) {
            printf((const char *)SJIS("error:変換された文字テーブル参照値が不正です。"));
            return 0;
        }
        D_002BADD0_as_s8_a[i] = D_0025C4A0[ch];
    }
    return 1;
}

s64 atoi();
s32 sprintf();
extern u8 D_0028E2BC;
extern u8 D_002BADD0[];
extern u8 D_002BB060_as_u8_a[];
extern u8 D_002BB100_as_u8_a[];
extern u8 D_002BB338_as_u8_a[];
extern u8 D_002BB348_as_u8_a[];
extern u8 D_002BB358_as_u8_a[];
extern u8 D_002BB368_as_u8_a[];
extern u8 D_002BB378_as_u8_a[];
extern u8 D_002BB388_as_u8_a[];
extern u8 D_002BB398_as_u8_a[];
extern u8 D_002BB3B0_as_u8_a[];
extern u8 D_002BB3F0_as_u8_a[];
void func_001984C0(void) {
    u32 save_d0;
    char str[0x28];
    u8 rec[14];
    u8 code[12];
    u32 score;
    u8 name[3];
    u16 val_fc;
    u16 val_fe;
    s32 i;
    u8 *p;
    s32 j;
    s32 i2;
    s32 k;
    s32 bits;
    s32 i1;
    s32 sum;
    u32 v0;
    u8 shift;
    u32 v3;
    u32 v4;
    u8 flags;
    u32 v1;
    u32 v2;
    u8 packed;
    u8 sw;
    u8 x;

    if (D_0028EAFC == 0xFF) return;
    save_d0 = reg_d0.w;
    for (j = 0; j < 14; j++) {
        rec[j] = 0;
    }
    flags = 0;
    score = ((u32 *)D_002BB3F0_as_u8_a)[D_0028EAFC];
    for (i = 0; i < 3; i++) {
        name[i] = ((u32 *)D_002BB3B0_as_u8_a)[D_0028EAFC * 3 + i];
    }
    v0 = ((u16 *)D_002BB388_as_u8_a)[D_0028EAFC];
    v1 = ((u16 *)D_002BB378_as_u8_a)[D_0028EAFC];
    v2 = ((u16 *)D_002BB368_as_u8_a)[D_0028EAFC];
    val_fc = ((u16 *)D_002BB338_as_u8_a)[D_0028EAFC];
    v3 = ((u16 *)D_002BB398_as_u8_a)[D_0028EAFC];
    val_fe = ((u16 *)D_002BB358_as_u8_a)[D_0028EAFC];
    v4 = ((u16 *)D_002BB348_as_u8_a)[D_0028EAFC];
    shift = (u32)D_0028E2BC & 3;
    if (shift == 0) {
        shift = (u8)(shift + 1);
    }
    printf("--no[%x]\n", D_0028EAFC);
    printf("--byou[%x]\n", (u8)shift);
    printf("--okuhi[%x]\n", val_fc);
    printf("--scohi[%x]\n", score);
    printf("--aerahi[%x]\n", (u16)v0);
    v1 = (u16)(v1 >> 1);
    printf("--typehi[%x]\n", v1);
    v2 = (u16)(v2 >> 1);
    printf("--kyokhi[%x]\n", v2);
    printf("--roundhi[%x]\n", (u16)v3);
    printf("--gphi[%x]\n", val_fe);
    printf("--cnthi[%x]\n", (u16)v4);
    printf("--name[%x][%x][%x]\n", name[0], name[1], name[2]);
    packed = (s8)(v1 & 3) << 6;
    packed |= (s8)(v2 & 3) << 4;
    packed |= v0 & 7;
    if (g_game_mode == 2) {
        flags |= 0x80;
    } else {
        flags = 0;
    }
    flags |= (v3 & 1) << 6;
    flags |= (v4 & 0xF) << 2;
    p = (u8 *)&score;
    rec[0] = p[0];
    rec[1] = p[1];
    rec[2] = p[2];
    rec[3] = p[3];
    rec[4] = packed;
    p = (u8 *)&val_fc;
    rec[5] = p[0];
    rec[6] = p[1];
    rec[8] = name[0];
    rec[9] = name[1];
    rec[10] = name[2];
    rec[7] = 0;
    rec[11] = 0;
    p = (u8 *)&val_fe;
    rec[12] = p[0];
    rec[13] = p[1];
    memset(code, 0, 12);
    memcpy(code, rec, 12);
    sum = 0;
    sprintf(str, (const char *)"%02x%02x%02x%02x0", code[3], code[2], code[1], code[0]);
    sum += atoi(str);
    sprintf(str, (const char *)"%02x%02x000000000", code[6], code[5]);
    sum += atoi(str);
    j = 2;
    bits = 0;
    for (i1 = 0; i1 < 4; i1++, j++) {
        if (code[11] & (1 << j)) {
            bits |= 1 << i1;
        }
    }
    code[0] = 0;
    code[1] = 0;
    code[2] = 0;
    code[3] = 0;
    sum += bits;
    k = 0;
    for (i2 = 0; i2 < 4; i2++) {
        for (j = 0; j < 8; j++, k++) {
            if (sum & (1 << k)) {
                code[i2] |= 1 << j;
            }
        }
    }
    code[5] = rec[12];
    code[6] = rec[13];
    sw = code[0];
    code[0] = code[8];
    code[8] = sw;
    sw = code[5];
    code[5] = code[10];
    code[10] = sw;
    for (i = 0; i < 12; i++) {
        code[i] = func_00198170(code[i], (s8)shift);
    }
    flags |= shift;
    code[11] = flags;
    x = 0;
    for (i = 0; i < 12; i++) {
        x ^= code[i];
    }
    code[7] = x;
    memset(D_002BADF0, 0, 12);
    memcpy(D_002BADF0, code, 12);
    func_00198280();
    if (g_game_mode == 2) {
        memcpy(D_002BB060_as_u8_a + D_0028EAFC * 0x1E, D_002BADD0, 0x1E);
    } else {
        memcpy(D_002BB100_as_u8_a + D_0028EAFC * 0x1E, D_002BADD0, 0x1E);
    }
    reg_d0.w = save_d0;
}


void func_00198B70(void) {
    u8 temp_a0;

    temp_a0 = *(u8 *)(reg_a5 + 3);
    if (temp_a0 == 0) {
        func_00197F60(temp_a0, reg_a5);
        return;
    }
    if (temp_a0 == 2) {
        func_001980A0(temp_a0, reg_a5);
        return;
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 4);
    if (reg_d0.b[0] == 0) {
        func_001980A0(reg_d0.b[0], reg_a5);
        return;
    }
    if (reg_d0.b[0] == 3) {
        func_00198C40(reg_d0.b[0], reg_a5);
        reg_d0.w = 3;
        func_00198D90();
        return;
    }
    if (reg_d0.w & 1) {
        func_00198C40(reg_d0.w, reg_a5);
        return;
    }
    if (reg_d0.w & 2) {
        func_00198D90(reg_d0.w, reg_a5);
    }
}

extern u16 D_002BAE80[];

void func_00198C40() {
    s32 input_get_p1_held();
    s32 input_get_p1_pressed();
    s32 temp_s6;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;

    reg_a4 = (u8 *)D_002BAE00;
    input_get_p1_held();
    *(u16 *)(reg_a4 + 0x34) = (u16) reg_d0.h[0];
    input_get_p1_pressed();
    *(u16 *)(reg_a4 + 0x36) = (u16) reg_d0.h[0];
    reg_d7.h[0] = *(u16 *)(reg_a4 + 2);
    if (reg_d7.h[0] != 0) {
        func_00198F30();
        return;
    }
    *(s16 *)(reg_a4 + 0x12) = 1;
    *(s16 *)(reg_a4 + 0x2C) = 0;
    *(s16 *)(reg_a4 + 0x2E) = 0;
    temp_s6 = (s32)reg_a0;
    temp_s0 = (s32)reg_a1;
    temp_s1 = (s32)reg_a2;
    temp_s2 = (s32)reg_a3;
    temp_s3 = (s32)reg_a4;
    temp_s4 = (s32)reg_a5;
    temp_s5 = (s32)reg_a6;
    func_00199540();
    if (cond_flag != 0) {
        reg_a0 = (u8 *)temp_s6;
        reg_a1 = (u8 *)temp_s0;
        reg_a2 = (u8 *)temp_s1;
        reg_a3 = (u8 *)temp_s2;
        reg_a4 = (u8 *)temp_s3;
        reg_a5 = (u8 *)temp_s4;
        reg_a6 = (u8 *)temp_s5;
        func_001994F0();
        return;
    }
    func_00199710();
    reg_a0 = (u8 *)temp_s6;
    reg_a1 = (u8 *)temp_s0;
    reg_a2 = (u8 *)temp_s1;
    reg_a3 = (u8 *)temp_s2;
    reg_a4 = (u8 *)temp_s3;
    reg_a5 = (u8 *)temp_s4;
    reg_a6 = (u8 *)temp_s5;
    if (D_002BAE80[0] != 0) {
        func_00198F30();
        return;
    }
    func_00198EF0();
}

extern u8 D_002BAE40[];

void func_00198D90() {
    s32 input_get_p2_held();
    s32 input_get_p2_pressed();
    s32 temp_s6;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;

    reg_a4 = (u8 *)D_002BAE40;
    input_get_p2_held();
    *(u16 *)(reg_a4 + 0x34) = (u16) reg_d0.h[0];
    input_get_p2_pressed();
    *(u16 *)(reg_a4 + 0x36) = (u16) reg_d0.h[0];
    reg_d7.h[0] = *(u16 *)(reg_a4 + 2);
    if (reg_d7.h[0] != 0) {
        func_00198F30();
        return;
    }
    *(s16 *)(reg_a4 + 0x12) = 2;
    *(s16 *)(reg_a4 + 0x2C) = 1;
    *(s16 *)(reg_a4 + 0x2E) = 0;
    temp_s6 = (s32)reg_a0;
    temp_s0 = (s32)reg_a1;
    temp_s1 = (s32)reg_a2;
    temp_s2 = (s32)reg_a3;
    temp_s3 = (s32)reg_a4;
    temp_s4 = (s32)reg_a5;
    temp_s5 = (s32)reg_a6;
    func_00199550();
    if (cond_flag != 0) {
        reg_a0 = (u8 *)temp_s6;
        reg_a1 = (u8 *)temp_s0;
        reg_a2 = (u8 *)temp_s1;
        reg_a3 = (u8 *)temp_s2;
        reg_a4 = (u8 *)temp_s3;
        reg_a5 = (u8 *)temp_s4;
        reg_a6 = (u8 *)temp_s5;
        func_001994F0();
        return;
    }
    func_00199710();
    reg_a0 = (u8 *)temp_s6;
    reg_a1 = (u8 *)temp_s0;
    reg_a2 = (u8 *)temp_s1;
    reg_a3 = (u8 *)temp_s2;
    reg_a4 = (u8 *)temp_s3;
    reg_a5 = (u8 *)temp_s4;
    reg_a6 = (u8 *)temp_s5;
    if (D_002BAE80[0] != 0) {
        func_00198F30();
        return;
    }
    func_00198EF0();
}

s32 func_0013B2E0();
extern u8 D_0025BF90[];
extern s16 D_002BAE80_as_s16_a[];

void func_00198EF0() {
    *(s16 *)(reg_a4 + 0x2E) = 1;
    D_002BAE80_as_s16_a[0] = 1;
    reg_a0 = D_0025BF90;
    func_0013B2E0();
    func_00198F30();
}

s32 func_0013BDE0();
s32 sfx_confirm();
extern u8 D_0025BD60[];
extern u8 D_0025BFD0[];
extern u16 D_002BAE82_as_u16_a[];

#define W(o) (*(u16 *)(reg_a4 + (o)))
#define L(p, o) (*(u32 *)((p) + (o)))

void func_00198F30(void) {
    u8 *ptr;

    if (W(0x2E) == 0) goto next_1;
    func_0019A410();
next_1:
    reg_d0.b[0] = reg_a5[4];
    if (reg_d0.b[0] != 3) {
        if (reg_d0.w & 1) {
            func_0019A5B0();
        } else if (reg_d0.w & 2) {
            func_0019A520();
        }
    }
    func_0019A050();
    func_0019A2B0();
    if (W(0x1E) == 0) goto block_count;
    func_00199A50();
    if (D_002BAE82_as_u16_a[0] != 0) return;
    if (W(0x2E) == 0) return;
    if (W(0x1E) != 0x30) goto next_4;
    W(0x1E) -= 1;
    reg_a0 = (u8 *)D_0025BFD0;
    func_0013BDE0();
    return;
next_4:
    W(0x1E) -= 1;
    if (W(0x1E) != 0) goto next_5;
    reg_a5[3] = 2;
    return;
next_5:
    if (W(0x1E) == 0x30) {
        reg_d2.w = 0x20;
    }
    return;
block_count:
    W(2) += 1;
    reg_d7.h[0] = W(2);
    if (reg_d7.h[0] >= 0x30) goto next_6;
    func_00199A50();
    return;
next_6:
    if (reg_d7.h[0] >= 0x738) goto block_fill;
    reg_d0.w = 0xF;
    reg_d0.h[0] &= W(0x36);
    if (reg_d0.h[0] != 0) goto next_7;
    if (reg_a4[0x21] == 0) goto next_8;
    reg_a4[0x20] -= 1;
    if (reg_a4[0x20] != 0) goto next_8;
    func_0019A870();
    goto next_8;
next_7:
    W(0x14) = 0;
    func_0019A640();
next_8:
    func_00199D50();
    func_00199A50();
    reg_d0.h[0] = W(0x36);
    if (!(reg_d0.w & 0x8000)) goto next_9;
    sfx_confirm();
    if (W(0x16) != 0) goto block_fill;
block_default:
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_a1 = reg_a0;
    ptr = reg_a1;
    L(ptr, 0) = 0xC;
    L(ptr, 4) = 0xC;
    L(ptr, 8) = 0x3C;
    reg_a1 = ptr + 0xC;
    W(0x16) = 3;
    goto block_copy;
next_9:
    reg_d0.h[0] = W(0x36);
    reg_d3.w = 0x20;
    reg_d3.h[0] &= reg_d0.h[0];
    if (reg_d3.h[0] != 0) goto next_12;
    reg_d0.h[0] &= 0x50;
    if (reg_d0.h[0] == 0) return;
    sfx_confirm();
    reg_d0.h[0] = W(0x18);
    if (reg_d0.h[0] < 27) goto next_13;
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
loop_10:
    reg_d0.w = 0x70;
loop_11:
    reg_d1.h[0] = W(0x16);
    L(reg_a0, reg_d1.h[0] * 4) = reg_d0.w;
    W(0x16) += 1;
    if (W(0x16) != 3) goto loop_11;
    goto block_check;
block_fill:
    reg_d0.h[0] = W(0x18);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = W(0x16);
    if (W(0x18) < 27) goto next_14;
    reg_d0.w = 0;
    goto block_default;
next_14:
    L(reg_a0, reg_d1.h[0] * 4) = reg_d0.w;
    W(0x16) += 1;
    if (W(0x16) != 3) goto loop_10;
    goto block_check;
next_12:
    reg_d1.w = 0;
    reg_d1.h[0] = W(0x16);
    if (reg_d1.h[0] == 0) return;
    W(0x16) -= 1;
    reg_d1.h[0] = W(0x16);
    reg_d0.w = 0;
    goto block_store;
next_13:
    reg_d1.h[0] = W(0x16);
    W(0x16) += 1;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
block_store:
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    L(reg_a0, reg_d1.h[0] * 4) = reg_d0.w;
    if (W(0x16) < 3) return;
block_check:
    reg_a1 = (u8 *)D_0025BD60;
loop_15:
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[1] = *(u16 *)(reg_a1 + 0);
    reg_d0.h[0] = *(u16 *)(reg_a1 + 2);
    if (reg_d0.w == 0xFFFFFFFF) goto block_copy;
    reg_tmp.w = L(reg_a0, 0);
    if (reg_tmp.w != reg_d0.w) goto next_16;
    reg_d0.h[1] = *(u16 *)(reg_a1 + 4);
    reg_d0.h[0] = *(u16 *)(reg_a1 + 6);
    reg_tmp.w = L(reg_a0, 4);
    if (reg_tmp.w != reg_d0.w) goto next_16;
    reg_d0.h[1] = *(u16 *)(reg_a1 + 8);
    reg_d0.h[0] = *(u16 *)(reg_a1 + 0xA);
    reg_tmp.w = L(reg_a0, 8);
    if (reg_tmp.w == reg_d0.w) goto block_default;
next_16:
    reg_a1 += 0xC;
    goto loop_15;
block_copy:
    func_00199970();
    reg_d1.h[0] = W(0x12);
    *(u8 *)D_002BAE82_as_u16_a &= ~(1 << reg_d1.sb[0]);
    W(0x1E) = 0x70;
    reg_d0.w = 0;
    W(0x1A) = reg_d0.h[1];
    W(0x1C) = reg_d0.h[0];
    func_00199A50();
}

void func_001994F0(void) {
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x2C);
    *(u8 *)(reg_a5 + 4) &= (~(1 << (s8) reg_d0.b[0]) & 0xFF);
    if (*(u8 *)(reg_a5 + 4) == 0) {
        *(s8 *)(reg_a5 + 3) = 2;
    }
}


void func_00199540(void) {
    reg_d0.w = 0xFF;
    func_00199560();
}

void func_00199550(void) {
    reg_d0.w = 0xFE;
    func_00199560();
}

extern u16 D_002BB338_as_u16_a[];
extern u16 D_002BB348_as_u16_a[];
extern u16 D_002BB358_as_u16_a[];
extern u16 D_002BB368_as_u16_a[];
extern u16 D_002BB378_as_u16_a[];
extern u16 D_002BB398_as_u16_a[];
extern s32 D_002BB3B0_as_s32_a[];


void func_00199560(void) {
    u32 tmp;

    cond_flag = 0;
    reg_d4.w = 4;
    reg_d1.w = 0;
    reg_a0 = (u8 *)D_002BB3B0_as_s32_a;
loop_1:
    if (*(u32 *)reg_a0 != reg_d0.w) {
        reg_a0 += 0xC;
        reg_d1.h[0] += 1;
        tmp = reg_d4.h[0] - 1;
        reg_d4.h[0] = tmp;
        if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
        reg_d0.w = 0;
        cond_flag = 1;
        reg_d0.h[0] -= 1;
        return;
    }
    reg_a2 = (u8 *)D_002BB348_as_u16_a;
    reg_d0.h[0] = reg_d1.h[0];
    reg_a3 = (u8 *)D_002BB338_as_u16_a;
    reg_a5 = (u8 *)D_002BB378_as_u16_a;
    reg_a6 = (u8 *)D_002BB368_as_u16_a;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a2 += reg_d0.h[0];
    reg_a3 += reg_d0.h[0];
    reg_a5 += reg_d0.h[0];
    reg_a6 += reg_d0.h[0];
    reg_d2.h[0] = *(u16 *)reg_a3;
    reg_tmp.w = reg_d2.w;
    reg_d2.h[1] = reg_tmp.h[0];
    reg_d2.h[0] = reg_tmp.h[1];
    reg_d2.h[0] = *(u16 *)reg_a2;
    reg_d3.h[0] = ENTITY(reg_a6)->flags.h;
    reg_tmp.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp.h[0];
    reg_d3.h[0] = reg_tmp.h[1];
    reg_d3.h[0] = *(u16 *)reg_a5;
    reg_a2 = (u8 *)D_002BB398_as_u16_a;
    reg_a3 = (u8 *)D_002BB358_as_u16_a;
    reg_a2 += reg_d0.h[0];
    reg_a3 += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *)D_002BB3F0_as_u8_a;
    reg_a1 += reg_d0.h[0];
}

#pragma push
#pragma opt_common_subs off
extern u8 D_0025BE50[];
extern u8 D_0025BE70[];
extern u8 D_002BAE82[];

void func_00199710(void) {
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a4 + 0x30) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x32) = (u16) reg_tmp.h[0];
    *(u16 *)(reg_a4 + 0xC) = (u16) *(u16 *)reg_a1;
    *(u16 *)(reg_a4 + 0xE) = (u16) *(u16 *)(reg_a1 + 2);
    *(u16 *)(reg_a4 + 0xA) = (u16) reg_d2.h[0];
    reg_tmp.w = reg_d2.w;
    reg_d2.h[1] = reg_tmp.h[0];
    reg_d2.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x10) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a4 + 0x38) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a4 + 0x3A) = (u16) reg_d3.h[0];
    reg_tmp.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp.h[0];
    reg_d3.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x3C) = (u16) reg_d3.h[0];
    reg_d0.w = 1;
    reg_a0 = (u8 *)((u32) D_0025BE50);
    if (*(u16 *)(reg_a4 + 0x2C) != 0) {
        reg_d0.w = 2;
        reg_a0 = (u8 *)((u32) D_0025BE70);
    }
    D_002BAE82[0] |= (1 << (s8) reg_d0.b[0]) & 0xFF;
    *(u16 *)(reg_a4 + 6) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 8) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x14) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x16) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x18) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x1E) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x20) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x22) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x24) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x26) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x28) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x2A) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
}
#pragma pop

extern u32 D_002BB3B0_as_u32_a[];

void func_00199970(void) {
    u32 t;
    u8 *p;
    u8 *q;

    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x2C);
    reg_d0.b[0] = ~(s8) reg_d0.b[0];
    reg_d5.w = 4;
    reg_a1 = (u8 *)(D_002BB3B0_as_u32_a);
loop_1:
    reg_tmp.w = *(u32 *)reg_a1;
    if (reg_tmp.w != reg_d0.w) goto next_2;
    reg_a2 = (u8 *)(reg_a0);
    reg_d7.h[0] = 2;
loop_2:
    p = reg_a2;
    q = reg_a1;
    *(u32 *)q = *(u32 *)p;
    reg_a1 = q + 4;
    reg_a2 = p + 4;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    goto next_3;
next_2:
    reg_a1 += 0xC;
next_3:
    t = reg_d5.h[0] - 1;
    reg_d5.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
}

s32 sprite_draw_layer4_keep();
s32 sprite_draw_layer4_zoom_keep();
extern u8 D_0025BF10[];

void func_00199A50(void) {
    u32 temp_a1;

    reg_d1.h[0] = 0x4840;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[0] = 0x380;
    reg_d1.h[1] = reg_tmp.h[0];
    if (*(u16 *)(reg_a4 + 0x2C) != 0) {
        reg_d1.h[0] = 0x2240;
    }
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = 4;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0x30);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x32);
    reg_a0 = (u8 *)(reg_tmp.w);
    reg_d7.h[0] = *(u16 *)(reg_a4 + 0x16);
    if (reg_d7.h[0] != 0) {
        reg_d7.h[0] -= 1;
        do {
            temp_a1 = *(u32 *)reg_a0;
            reg_d0.w = temp_a1;
            reg_a0 += 4;
            reg_a1 = (u8 *)D_0025BF10;
            reg_a1 += reg_d0.h[0];
            reg_d2.h[1] = *(u16 *)reg_a1;
            reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d6.w = 0x40004000;
            sprite_draw_layer4_zoom_keep();
            reg_d1.h[0] += 0x600;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    if (*(u16 *)(reg_a4 + 0x16) != 3) {
        reg_a1 = (u8 *)D_0025BF10;
        reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
        reg_d2.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
        sprite_draw_layer4_keep();
        if ((s32) *(u16 *)(reg_a4 + 0x16) < 2) {
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x3E);
            *(u16 *)(reg_a4 + 0x3E) += 4;
            if (reg_d0.h[0] == 0x68) {
                *(u16 *)(reg_a4 + 0x3E) = 0U;
            }
            reg_a1 = (u8 *)D_0025BF10;
            reg_d7.h[0] = 1;
            reg_d7.h[0] -= *(u16 *)(reg_a4 + 0x16);
            do {
                reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d1.h[0] += 0x600;
                reg_d6.w = 0x40004000;
                sprite_draw_layer4_zoom_keep();
                reg_d0.h[0] += 0x34;
                if ((s32) reg_d0.h[0] >= 0x6C) {
                    reg_d0.h[0] -= 0x6C;
                }
            } while ((s16)(--reg_d7.h[0]) >= 0);
        }
    }
}

s32 sprite_draw_layer2_keep();
s32 sprite_draw_layer3_keep();
extern u16 D_0025BE90[];
extern u16 D_0025BEA0[];
extern u16 D_0025BEB0[];
extern u16 D_0025BED0[];
extern u16 D_0025BEF0[];
extern u16 D_0025BF00[];

void func_00199D50(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a1_3;
    u16 temp_a2;
    u16 temp_a3;
    u16 temp_a3_2;
    u32 temp_a1;
    u32 temp_a1_2;
    u32 temp_a2_2;

    *(u8 *)(reg_a4 + 0x23) -= 1;
    if (0 > (s64)*(s8 *)(reg_a4 + 0x23)) {
        *(u8 *)(reg_a4 + 0x23) = (u8) *(u8 *)(reg_a4 + 0x22);
        *(u16 *)(reg_a4 + 0x24) -= 4;
        if (0 > (s16) *(u16 *)(reg_a4 + 0x24)) {
            *(u16 *)(reg_a4 + 0x24) = 0xCU;
        }
    }
    do {
        *(u8 *)(reg_a4 + 0x27) -= 1;
    } while (0 <= (s64)*(s8 *)(reg_a4 + 0x27));
    *(u8 *)(reg_a4 + 0x27) = (u8) *(u8 *)(reg_a4 + 0x26);
    *(u16 *)(reg_a4 + 0x28) -= 8;
    if (0 > (s16) *(u16 *)(reg_a4 + 0x28)) {
        *(u16 *)(reg_a4 + 0x28) = 0x18U;
    }
    reg_d7.h[1] = *(u16 *)(reg_a4 + 6);
    reg_d7.h[0] = *(u16 *)(reg_a4 + 8);
    reg_a0 = (u8 *)(D_0025BE90);
    reg_a1 = (u8 *)(D_0025BEB0);
    reg_a2 = (u8 *)(D_0025BEF0);
    if (*(u16 *)(reg_a4 + 0x2C) != 0) {
        reg_a0 = (u8 *)(D_0025BEA0);
        reg_a1 = (u8 *)(D_0025BED0);
        reg_a2 = (u8 *)(D_0025BF00);
    }
    reg_d4.h[0] = 5;
    reg_d1.w = reg_d7.w;
    temp_a1 = reg_d1.w;
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a2 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a2;
    reg_a2 += 2;
    reg_d1.w = temp_a1 + reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x28);
    reg_a1 += reg_d0.h[0];
    reg_d2.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    temp_a0 = *(u16 *)reg_a1;
    reg_d2.h[0] = temp_a0;
    reg_a1 += 2;
    reg_d3.h[0] = 0x3808;
    sprite_draw_layer2_keep();
    reg_d1.w = reg_d7.w;
    temp_a3 = *(u16 *)reg_a2;
    temp_a2_2 = reg_d1.w;
    reg_a2 += 2;
    reg_tmp.h[1] = temp_a3;
    temp_a3_2 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a3_2;
    reg_a2 += 2;
    temp_a1_2 = temp_a2_2 + reg_tmp.w;
    reg_d1.w = temp_a1_2;
    temp_a0_2 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d2.h[1] = temp_a0_2;
    temp_a0_3 = *(u16 *)reg_a1;
    reg_d2.h[0] = temp_a0_3;
    reg_a1 += 2;
    reg_d3.h[0] = 0x3C0;
    sprite_draw_layer2_keep();
    reg_d1.w = reg_d7.w;
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a1_3 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a1_3;
    reg_a2 += 2;
    reg_d1.w += reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x24);
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x620;
    sprite_draw_layer3_keep();
}

extern u16 D_0025C020[];

void func_0019A050(void) {
    u32 t;

    reg_d1.h[0] = 0x4040;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[0] = 0x1540;
    reg_d1.h[1] = reg_tmp.h[0];
    switch (*(u16 *)(reg_a4 + 0x2C)) {
    case 0:
        goto next_1;
    }
    reg_d1.h[0] = 0x3300;
next_1:
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 4;
    reg_a0 = (u8 *)(D_0025C020);
    reg_d2.w = 0xF;
    reg_d2.h[0] &= *(u16 *)(reg_a4 + 0xA);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.w += 0x147C;
    sprite_draw_layer4_keep();
    reg_d1.h[0] -= 0x200;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
    reg_d7.w = 7;
loop_1:
    reg_d2.w = 0xF;
    reg_d2.h[0] &= reg_d0.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.w += 0x147C;
    sprite_draw_layer4_keep();
    reg_d1.h[0] -= 0x200;
    reg_d0.w >>= 4;
    if (reg_d0.w == 0) goto next_2;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_2:
    reg_d7.h[0] -= 1;
    if (*(u16 *)(reg_a4 + 0x10) == 0) return;
    if (!(0 > (s16) reg_d7.h[0])) goto loop_1;
    reg_d2.w = 0xF;
    reg_d2.h[0] &= *(u16 *)(reg_a4 + 0x10);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.w += 0x147C;
    sprite_draw_layer4_keep();
}

extern u16 D_0025C000[];

void func_0019A2B0(void) {
    reg_d1.h[0] = 0x5200;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[0] = 0xC00;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d2.w = 0x144C;
    reg_d7.h[0] = 0x5200;
    reg_tmp.w = reg_d7.w;
    reg_d7.h[0] = 0x440;
    reg_d7.h[1] = reg_tmp.h[0];
    if (*(u16 *)(reg_a4 + 0x2C) == 0) goto next_1;
    reg_d1.h[0] = 0x2240;
    reg_d2.w = 0x144D;
    reg_d7.h[0] = 0x2D40;
next_1:
    reg_d3.h[0] = 0x228;
    reg_d4.h[0] = 5;
    sprite_draw_layer3_keep();
    reg_d1.w = reg_d7.w;
    reg_d2.h[0] = *(u16 *)(reg_a4 + 0x38);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)(D_0025C000);
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x218;
    reg_d4.h[0] = 4;
    sprite_draw_layer4_keep();
}

s32 sprite_draw_layer1();
s32 sprite_draw_layer3();
s32 sprite_draw_layer4();
void func_0019A410(void) {
    reg_d1.w = 0x2A001C00;
    reg_d1.w += 0xEE00EA00;
    reg_d2.w = 0x145A;
    reg_d3.h[0] = 0x12B0;
    reg_d4.h[0] = 4;
    sprite_draw_layer1();
    reg_d1.w = 0x38001C00;
    reg_d1.w += 0xC800E400;
    reg_d2.w = 0x1457;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 2;
    sprite_draw_layer3();
    reg_d1.w = 0x38001C00;
    reg_d1.w += 0xC800E400;
    reg_d2.w = 0x1486;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 3;
    sprite_draw_layer4();
    reg_d1.w = 0x62801C40;
    reg_d1.w += 0xFA00EA00;
    reg_d2.w = 0x1454;
    reg_d3.h[0] = 0x6B0;
    reg_d4.h[0] = 4;
    sprite_draw_layer4();
}

void func_0019A520(void) {
    reg_d1.w = 0x4E800C80;
    reg_d1.w += 0xF600F500;
    reg_d2.w = 0x1455;
    reg_d3.h[0] = 0xA58;
    reg_d4.h[0] = 3;
    sprite_draw_layer4();
    reg_d1.w = 0x42000D00;
    reg_d1.w += 0xFC00F500;
    reg_d2.w = 0x1456;
    reg_d3.h[0] = 0x458;
    reg_d4.h[0] = 3;
    sprite_draw_layer4();
}

void func_0019A5B0(void) {
    reg_d1.w = 0x4E802B80;
    reg_d1.w += 0xF600F500;
    reg_d2.w = 0x1455;
    reg_d3.h[0] = 0xA58;
    reg_d4.h[0] = 0x43;
    sprite_draw_layer4();
    reg_d1.w = 0x42002B00;
    reg_d1.w += 0xFC00F500;
    reg_d2.w = 0x1456;
    reg_d3.h[0] = 0x458;
    reg_d4.h[0] = 0x43;
    sprite_draw_layer4();
}


void func_0019A640(void) {
    if (*(u8 *)(reg_a4 + 0x21) == 1) {
        goto block_2;
    }
    if (!(reg_d0.w & 1)) {
        goto next_1;
    }
    *(u8 *)(reg_a4 + 0x21) = 1;
    *(u16 *)(reg_a4 + 0x2A) = 1;
    goto next_2;
next_1:
    if (!(reg_d0.w & 2)) {
        goto next_2;
    }
    *(u8 *)(reg_a4 + 0x21) = 1;
    *(u16 *)(reg_a4 + 0x2A) = 2;
next_2:
    if (!(reg_d0.w & 4)) {
        goto next_3;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 4;
    goto next_4;
next_3:
    if (!(reg_d0.w & 8)) {
        goto next_4;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 8;
next_4:
    if (*(u8 *)(reg_a4 + 0x21) == 2) {
        func_0019A870();
        return;
    }
    *(u8 *)(reg_a4 + 0x20) = 4;
    return;
block_2:
    *(u8 *)(reg_a4 + 0x20) -= 1;
    if (*(u8 *)(reg_a4 + 0x20) == 0) {
        func_0019A870();
        return;
    }
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x2A);
    if (reg_d1.h[0] == 1) {
        goto next_5;
    }
    if (reg_d1.h[0] != 2) {
        goto next_7;
    }
next_5:
    if (!(reg_d0.w & 4)) {
        goto next_6;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 4;
    func_0019A870();
    return;
next_6:
    if (!(reg_d0.w & 8)) {
        goto next_4;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 8;
    func_0019A870();
    return;
next_7:
    if (reg_d1.h[0] == 4) {
        goto next_8;
    }
    if (reg_d1.h[0] == 8) {
        goto next_8;
    }
block_rts:
    return;
next_8:
    if (!(reg_d0.w & 1)) {
        goto next_9;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 1;
    func_0019A870();
    return;
next_9:
    if (!(reg_d0.w & 2)) {
        goto block_rts;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 2;
    func_0019A870();
}

s32 sfx_cursor_move();
extern u16 D_0025C430[];

void func_0019A870(void) {
    u32 t;
    u32 t1;
    *(s8 *)(reg_a4 + 0x21) = 0;
    *(s8 *)(reg_a4 + 0x20) = 0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
    reg_a0 = (u8 *)(name_entry_letter_table);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    t = reg_d0.h[0];
    reg_tmp.h[1] = (t != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)t & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)t + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)t + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x2A);
    *(u16 *)(reg_a4 + 0x2A) = 0U;
    reg_d0.h[0] -= 1;
    if (!(0 > (s16)(reg_d0.h[0])) && ((reg_d0.h[0] & 0xFFFF) < 0xA)) {
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        t1 = reg_d0.h[0];
        if (!(0 > (s16)(t1))) {
            *(u16 *)(reg_a4 + 0x18) = t1;
            reg_a0 = (u8 *)(D_0025C430);
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            *(u16 *)(reg_a4 + 6) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
            *(u16 *)(reg_a4 + 8) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            sfx_cursor_move();
        }
    }
}
