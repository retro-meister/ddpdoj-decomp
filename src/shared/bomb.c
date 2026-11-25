#include "common.h"
#include "player.h"
#include "entity.h"

u16 spread_bomb_phase1_template[] = {
    0x4400, 0x1800, 0x1800, 0x1800, 0x1800, 0x0002, 0x0000, 0x0006,
    0x0008, 0x0009, 0x0001,
};

u16 spread_bomb_a_phase1_frames[] = {
    0xDC00, 0xE800, 0x0000, 0x0858, 0x24C0, 0x0006, 0xDC00, 0xE800,
    0x0000, 0x0859, 0x24C0, 0x0006, 0xDC00, 0xE800, 0x0000, 0x085A,
    0x24C0, 0x0006, 0xDC00, 0xE800, 0x0000, 0x085B, 0x24C0, 0x0006,
    0xFFFF,
};

u16 spread_bomb_b_phase1_frames[] = {
    0xDC00, 0xE800, 0x0000, 0x0868, 0x24C0, 0x0006, 0xDC00, 0xE800,
    0x0000, 0x0869, 0x24C0, 0x0006, 0xDC00, 0xE800, 0x0000, 0x086A,
    0x24C0, 0x0006, 0xDC00, 0xE800, 0x0000, 0x086B, 0x24C0, 0x0006,
    0xFFFF,
};

u16 spread_bomb_phase2_template[] = {
    0xE000, 0xE800, 0x22C0, 0x1E00, 0x1E00, 0x1E00, 0x1E00, 0x0100,
    0x0000, 0x0006, 0x000A, 0x000B, 0x0001, 0x001C, 0x0001, 0x0001,
    0x0006,
};

u16 spread_bomb_a_phase2_frames[] = {
    0x0000, 0x0863, 0x0000, 0x0862, 0x0000, 0x0861, 0x0000, 0x0860,
    0x0000, 0x085F, 0x0000, 0x085E, 0x0000, 0x085D, 0x0000, 0x085C,
};

u16 spread_bomb_b_phase2_frames[] = {
    0x0000, 0x0873, 0x0000, 0x0872, 0x0000, 0x0871, 0x0000, 0x0870,
    0x0000, 0x086F, 0x0000, 0x086E, 0x0000, 0x086D, 0x0000, 0x086C,
};

u16 spread_bomb_phase3_template[] = {
    0xE000, 0xE800, 0x22C0, 0x1400, 0x1400, 0x1400, 0x1400, 0x0010,
    0x0000, 0x0006, 0x000A, 0x000B, 0x0001, 0x0002,
};

u16 spread_bomb_a_phase3_frames[] = {
    0x0000, 0x0864, 0x0000, 0x0865, 0x0000, 0x0866, 0x0000, 0x0867,
    0xFFFF, 0xFFFF,
};

u16 spread_bomb_b_phase3_frames[] = {
    0x0000, 0x0874, 0x0000, 0x0875, 0x0000, 0x0876, 0x0000, 0x0877,
    0xFFFF, 0xFFFF,
};

u16 laser_bomb_a_base_frames[] = {
    0x0000, 0x0917, 0x0000, 0x0916, 0x0000, 0x0915,
};

u16 laser_bomb_a_muzzle_frames[] = {
    0x0000, 0x08F5, 0x0000, 0x08F4, 0x0000, 0x08F3,
};

u16 laser_bomb_a_tip_frames[] = {
    0x0000, 0x08F2, 0x0000, 0x08F1, 0x0000, 0x08F0,
};

u16 laser_bomb_a_impact_frames[] = {
    0x0000, 0x0904, 0x0000, 0x0903, 0x0000, 0x0902,
};

u16 laser_bomb_a_beam_frames[] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F,
};

u16 laser_bomb_a_beam_frame_07[] = {
    0x0000, 0x0888, 0x0000, 0x0880, 0x0000, 0x0878,
};

u16 laser_bomb_a_beam_frame_06[] = {
    0x0000, 0x0889, 0x0000, 0x0881, 0x0000, 0x0879,
};

u16 laser_bomb_a_beam_frame_05[] = {
    0x0000, 0x088A, 0x0000, 0x0882, 0x0000, 0x087A,
};

u16 laser_bomb_a_beam_frame_04[] = {
    0x0000, 0x088B, 0x0000, 0x0883, 0x0000, 0x087B,
};

u16 laser_bomb_a_beam_frame_03[] = {
    0x0000, 0x088C, 0x0000, 0x0884, 0x0000, 0x087C,
};

u16 laser_bomb_a_beam_frame_02[] = {
    0x0000, 0x088D, 0x0000, 0x0885, 0x0000, 0x087D,
};

u16 laser_bomb_a_beam_frame_01[] = {
    0x0000, 0x088E, 0x0000, 0x0886, 0x0000, 0x087E,
};

u16 laser_bomb_a_beam_frame_00[] = {
    0x0000, 0x088F, 0x0000, 0x0887, 0x0000, 0x087F,
};

u16 laser_bomb_a_beam_table[] = {
    0x0000, 0x0918, 0x0000, 0x08F0, 0x0000, 0x08F6, 0x0000, 0x0905,
    0x0008, 0x0009, 0x0000, 0x0919, 0x0000, 0x08F1, 0x0000, 0x08F7,
    0x0000, 0x0906, 0x0012, 0x0013, 0x0000, 0x091A, 0x0000, 0x08F2,
    0x0000, 0x08F8, 0x0000, 0x0907, 0x001C, 0x001D, 0x0000, 0x091B,
    0x0000, 0x08F0, 0x0000, 0x08F9, 0x0000, 0x0908, 0x0026, 0x0027,
    0x0000, 0x091C, 0x0000, 0x08F1, 0x0000, 0x08FA, 0x0000, 0x0909,
    0x0030, 0x0031, 0x0000, 0x091D, 0x0000, 0x08F2, 0x0000, 0x08FB,
    0x0000, 0x090A, 0x003A, 0x003B, 0x0000, 0x091E, 0x0000, 0x08F0,
    0x0000, 0x08FC, 0x0000, 0x090B, 0x0044, 0x0045, 0x0000, 0x091F,
    0x0000, 0x08F1, 0x0000, 0x08FD, 0x0000, 0x090C, 0x004E, 0x004F,
    0x0000, 0x0920, 0x0000, 0x08F2, 0x0000, 0x08FE, 0x0000, 0x090D,
    0x0058, 0x0059, 0x0000, 0x0921, 0x0000, 0x08F0, 0x0000, 0x08FF,
    0x0000, 0x090E, 0x0062, 0x0063, 0x0000, 0x0922, 0x0000, 0x08F1,
    0x0000, 0x0900, 0x0000, 0x090F, 0x006C, 0x006D, 0x0000, 0x0923,
    0x0000, 0x08F2, 0x0000, 0x0901, 0x0000, 0x0910, 0x0076, 0x0077,
    0xFFFF, 0xFFFF,
};

u16 laser_bomb_a_beam_row_00[] = {
    0x0000, 0x0897, 0x0000, 0x0896, 0x0000, 0x0895, 0x0000, 0x0894,
    0x0000, 0x0893, 0x0000, 0x0892, 0x0000, 0x0891, 0x0000, 0x0890,
};

u16 laser_bomb_a_beam_row_01[] = {
    0x0000, 0x0898, 0x0000, 0x089F, 0x0000, 0x089E, 0x0000, 0x089D,
    0x0000, 0x089C, 0x0000, 0x089B, 0x0000, 0x089A, 0x0000, 0x0899,
};

u16 laser_bomb_a_beam_row_02[] = {
    0x0000, 0x08A1, 0x0000, 0x08A0, 0x0000, 0x08A7, 0x0000, 0x08A6,
    0x0000, 0x08A5, 0x0000, 0x08A4, 0x0000, 0x08A3, 0x0000, 0x08A2,
};

u16 laser_bomb_a_beam_row_03[] = {
    0x0000, 0x08AA, 0x0000, 0x08A9, 0x0000, 0x08A8, 0x0000, 0x08AF,
    0x0000, 0x08AE, 0x0000, 0x08AD, 0x0000, 0x08AC, 0x0000, 0x08AB,
};

u16 laser_bomb_a_beam_row_04[] = {
    0x0000, 0x08B3, 0x0000, 0x08B2, 0x0000, 0x08B1, 0x0000, 0x08B0,
    0x0000, 0x08B7, 0x0000, 0x08B6, 0x0000, 0x08B5, 0x0000, 0x08B4,
};

u16 laser_bomb_a_beam_row_05[] = {
    0x0000, 0x08BC, 0x0000, 0x08BB, 0x0000, 0x08BA, 0x0000, 0x08B9,
    0x0000, 0x08B8, 0x0000, 0x08BF, 0x0000, 0x08BE, 0x0000, 0x08BD,
};

u16 laser_bomb_a_beam_row_06[] = {
    0x0000, 0x08C5, 0x0000, 0x08C4, 0x0000, 0x08C3, 0x0000, 0x08C2,
    0x0000, 0x08C1, 0x0000, 0x08C0, 0x0000, 0x08C7, 0x0000, 0x08C6,
};

u16 laser_bomb_a_beam_row_07[] = {
    0x0000, 0x08CE, 0x0000, 0x08CD, 0x0000, 0x08CC, 0x0000, 0x08CB,
    0x0000, 0x08CA, 0x0000, 0x08C9, 0x0000, 0x08C8, 0x0000, 0x08CF,
};

u16 laser_bomb_a_beam_row_08[] = {
    0x0000, 0x08D7, 0x0000, 0x08D6, 0x0000, 0x08D5, 0x0000, 0x08D4,
    0x0000, 0x08D3, 0x0000, 0x08D2, 0x0000, 0x08D1, 0x0000, 0x08D0,
};

u16 laser_bomb_a_beam_row_09[] = {
    0x0000, 0x08D8, 0x0000, 0x08DF, 0x0000, 0x08DE, 0x0000, 0x08DD,
    0x0000, 0x08DC, 0x0000, 0x08DB, 0x0000, 0x08DA, 0x0000, 0x08D9,
};

u16 laser_bomb_a_beam_row_10[] = {
    0x0000, 0x08E1, 0x0000, 0x08E0, 0x0000, 0x08E7, 0x0000, 0x08E6,
    0x0000, 0x08E5, 0x0000, 0x08E4, 0x0000, 0x08E3, 0x0000, 0x08E2,
};

u16 laser_bomb_a_beam_row_11[] = {
    0x0000, 0x08EA, 0x0000, 0x08E9, 0x0000, 0x08E8, 0x0000, 0x08EF,
    0x0000, 0x08EE, 0x0000, 0x08ED, 0x0000, 0x08EC, 0x0000, 0x08EB,
};

u16 laser_bomb_b_base_frames[] = {
    0x0000, 0x09C3, 0x0000, 0x09C2, 0x0000, 0x09C1,
};

u16 laser_bomb_b_muzzle_frames[] = {
    0x0000, 0x09A1, 0x0000, 0x09A0, 0x0000, 0x099F,
};

u16 laser_bomb_b_tip_frames[] = {
    0x0000, 0x099E, 0x0000, 0x099D, 0x0000, 0x099C,
};

u16 laser_bomb_b_impact_frames[] = {
    0x0000, 0x09B0, 0x0000, 0x09AF, 0x0000, 0x09AE,
};

u16 laser_bomb_b_beam_frames[] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F,
};

u16 laser_bomb_b_beam_frame_07[] = {
    0x0000, 0x0934, 0x0000, 0x092C, 0x0000, 0x0924,
};

u16 laser_bomb_b_beam_frame_06[] = {
    0x0000, 0x0935, 0x0000, 0x092D, 0x0000, 0x0925,
};

u16 laser_bomb_b_beam_frame_05[] = {
    0x0000, 0x0936, 0x0000, 0x092E, 0x0000, 0x0926,
};

u16 laser_bomb_b_beam_frame_04[] = {
    0x0000, 0x0937, 0x0000, 0x092F, 0x0000, 0x0927,
};

u16 laser_bomb_b_beam_frame_03[] = {
    0x0000, 0x0938, 0x0000, 0x0930, 0x0000, 0x0928,
};

u16 laser_bomb_b_beam_frame_02[] = {
    0x0000, 0x0939, 0x0000, 0x0931, 0x0000, 0x0929,
};

u16 laser_bomb_b_beam_frame_01[] = {
    0x0000, 0x093A, 0x0000, 0x0932, 0x0000, 0x092A,
};

u16 laser_bomb_b_beam_frame_00[] = {
    0x0000, 0x093B, 0x0000, 0x0933, 0x0000, 0x092B,
};

u16 laser_bomb_b_beam_table[] = {
    0x0000, 0x09C4, 0x0000, 0x099C, 0x0000, 0x09A2, 0x0000, 0x09B1,
    0x0008, 0x0009, 0x0000, 0x09C5, 0x0000, 0x099D, 0x0000, 0x09A3,
    0x0000, 0x09B2, 0x0012, 0x0013, 0x0000, 0x09C6, 0x0000, 0x099E,
    0x0000, 0x09A4, 0x0000, 0x09B3, 0x001C, 0x001D, 0x0000, 0x09C7,
    0x0000, 0x099C, 0x0000, 0x09A5, 0x0000, 0x09B4, 0x0026, 0x0027,
    0x0000, 0x09C8, 0x0000, 0x099D, 0x0000, 0x09A6, 0x0000, 0x09B5,
    0x0030, 0x0031, 0x0000, 0x09C9, 0x0000, 0x099E, 0x0000, 0x09A7,
    0x0000, 0x09B6, 0x003A, 0x003B, 0x0000, 0x09CA, 0x0000, 0x099C,
    0x0000, 0x09A8, 0x0000, 0x09B7, 0x0044, 0x0045, 0x0000, 0x09CB,
    0x0000, 0x099D, 0x0000, 0x09A9, 0x0000, 0x09B8, 0x004E, 0x004F,
    0x0000, 0x09CC, 0x0000, 0x099E, 0x0000, 0x09AA, 0x0000, 0x09B9,
    0x0058, 0x0059, 0x0000, 0x09CD, 0x0000, 0x099C, 0x0000, 0x09AB,
    0x0000, 0x09BA, 0x0062, 0x0063, 0x0000, 0x09CE, 0x0000, 0x099D,
    0x0000, 0x09AC, 0x0000, 0x09BB, 0x006C, 0x006D, 0x0000, 0x09CF,
    0x0000, 0x099E, 0x0000, 0x09AD, 0x0000, 0x09BC, 0x0076, 0x0077,
    0xFFFF, 0xFFFF,
};

u16 laser_bomb_b_beam_row_00[] = {
    0x0000, 0x0943, 0x0000, 0x0942, 0x0000, 0x0941, 0x0000, 0x0940,
    0x0000, 0x093F, 0x0000, 0x093E, 0x0000, 0x093D, 0x0000, 0x093C,
};

u16 laser_bomb_b_beam_row_01[] = {
    0x0000, 0x0944, 0x0000, 0x094B, 0x0000, 0x094A, 0x0000, 0x0949,
    0x0000, 0x0948, 0x0000, 0x0947, 0x0000, 0x0946, 0x0000, 0x0945,
};

u16 laser_bomb_b_beam_row_02[] = {
    0x0000, 0x094D, 0x0000, 0x094C, 0x0000, 0x0953, 0x0000, 0x0952,
    0x0000, 0x0951, 0x0000, 0x0950, 0x0000, 0x094F, 0x0000, 0x094E,
};

u16 laser_bomb_b_beam_row_03[] = {
    0x0000, 0x0956, 0x0000, 0x0955, 0x0000, 0x0954, 0x0000, 0x095B,
    0x0000, 0x095A, 0x0000, 0x0959, 0x0000, 0x0958, 0x0000, 0x0957,
};

u16 laser_bomb_b_beam_row_04[] = {
    0x0000, 0x095F, 0x0000, 0x095E, 0x0000, 0x095D, 0x0000, 0x095C,
    0x0000, 0x0963, 0x0000, 0x0962, 0x0000, 0x0961, 0x0000, 0x0960,
};

u16 laser_bomb_b_beam_row_05[] = {
    0x0000, 0x0968, 0x0000, 0x0967, 0x0000, 0x0966, 0x0000, 0x0965,
    0x0000, 0x0964, 0x0000, 0x096B, 0x0000, 0x096A, 0x0000, 0x0969,
};

u16 laser_bomb_b_beam_row_06[] = {
    0x0000, 0x0971, 0x0000, 0x0970, 0x0000, 0x096F, 0x0000, 0x096E,
    0x0000, 0x096D, 0x0000, 0x096C, 0x0000, 0x0973, 0x0000, 0x0972,
};

u16 laser_bomb_b_beam_row_07[] = {
    0x0000, 0x097A, 0x0000, 0x0979, 0x0000, 0x0978, 0x0000, 0x0977,
    0x0000, 0x0976, 0x0000, 0x0975, 0x0000, 0x0974, 0x0000, 0x097B,
};

u16 laser_bomb_b_beam_row_08[] = {
    0x0000, 0x0983, 0x0000, 0x0982, 0x0000, 0x0981, 0x0000, 0x0980,
    0x0000, 0x097F, 0x0000, 0x097E, 0x0000, 0x097D, 0x0000, 0x097C,
};

u16 laser_bomb_b_beam_row_09[] = {
    0x0000, 0x0984, 0x0000, 0x098B, 0x0000, 0x098A, 0x0000, 0x0989,
    0x0000, 0x0988, 0x0000, 0x0987, 0x0000, 0x0986, 0x0000, 0x0985,
};

u16 laser_bomb_b_beam_row_10[] = {
    0x0000, 0x098D, 0x0000, 0x098C, 0x0000, 0x0993, 0x0000, 0x0992,
    0x0000, 0x0991, 0x0000, 0x0990, 0x0000, 0x098F, 0x0000, 0x098E,
};

u16 laser_bomb_b_beam_row_11[] = {
    0x0000, 0x0996, 0x0000, 0x0995, 0x0000, 0x0994, 0x0000, 0x099B,
    0x0000, 0x099A, 0x0000, 0x0999, 0x0000, 0x0998, 0x0000, 0x0997,
};

u16 laser_bomb_template[] = {
    0xF200, 0xF200, 0x1070, 0x1200, 0x0E00, 0x0E00, 0x0E00, 0x0000,
    0x0078, 0x0006, 0x000A, 0x000B, 0x0000, 0x0008, 0x0008, 0x000F,
    0x0010, 0x0011, 0x0012, 0x8000, 0xF080, 0xF400, 0x0E60, 0x0E00,
    0x0E00, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0006, 0x001E, 0x001F,
    0x0000, 0x0008, 0x0008, 0x0000, 0x001C, 0x0000, 0x0000, 0x8000,
    0x0200, 0xF400, 0x0A60, 0x1600, 0xFE00, 0x0C00, 0x0C00, 0x0000,
    0x0000, 0x0006, 0x0032, 0x0033, 0x0000, 0x0008, 0x0008, 0x0000,
    0x0000, 0x0000, 0x0000, 0x8200, 0xF800, 0xF200, 0x0C70, 0x1000,
    0x0800, 0x0E00, 0x0E00, 0x0000, 0x0000, 0x0006, 0x0046, 0x0047,
    0x0000, 0x0008, 0x0008,
};

u16 laser_bomb_segment_template[] = {
    0x8000, 0xFE00, 0xF800, 0x0240, 0x0200, 0x0200, 0x0800, 0x0800,
    0x0006,
};

void spread_bomb_update(void);
void laser_bomb_update();
void laser_bomb_beam_draw(void);
void laser_bomb_beam_draw_fading(void);
void laser_bomb_tip_update(void);
void laser_bomb_muzzle_update(void);
void laser_bomb_impact_update(void);
void laser_bomb_beam_rebuild(void);
void laser_bomb_end(void);
void bomb_afterglow_end(void);
void bombs_clear(void);

extern u16 g_bomb_afterglow_timer;
extern u16 g_bomb_entities[];
extern u8 g_p2_options[];
extern u8 g_p1_options[];
extern u8 g_player2_as_u8_a[];
extern u8 g_player1_as_u8_a[];

void bombs_update(void) {
    u8 *sa5;

    reg_a6 = (u8 *)(g_bomb_entities);
    reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
    if ((s16) reg_d0.h[0] >= 0) {
        if (g_bomb_afterglow_timer != 0) {
            g_bomb_afterglow_timer -= 1;
            if (g_bomb_afterglow_timer == 0) {
                bomb_afterglow_end();
            }
        }
    } else {
        sa5 = (u8 *)(reg_a5);
        reg_a4 = (u8 *)g_p1_options;
        reg_a5 = (u8 *)g_player1_as_u8_a;
        if (ENTITY(reg_a6)->flags.sb[0] < 0) {
            reg_a4 = (u8 *)g_p2_options;
            reg_a5 = (u8 *)g_player2_as_u8_a;
        }
        reg_d0.h[0] &= 7;
        switch (reg_d0.h[0]) {
        case 3:
            goto block_1;
        }
        switch (reg_d0.h[0]) {
        case 0:
        case 2:
            spread_bomb_update();
            break;
        case 1:
        block_1:
            laser_bomb_update();
            break;
        }
        reg_a5 = sa5;
    }
}

typedef void (*Fn)();
s32 sfx_spread_bomb_a();
s32 sfx_spread_bomb_b();
s32 entity_draw_with_bombs();
s32 entity_draw_with_bombs_keep();
s32 sprite_draw_with_bombs_keep();
s32 rng_next_bit();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u16 g_frame_mod2;
extern u16 g_side_scroll_step[];
extern u8 g_bomb_entities_as_u8_a[];

void spread_bomb_update(void) {
    u8 temp;

    reg_d1.h[0] = g_side_scroll_step[0];
    ENTITY(reg_a6)->x.h -= reg_d1.h[0];
    temp = ENTITY(reg_a6)->flags.b[1];
    if (temp & 1) goto block_a;
    ENTITY(reg_a6)->flags.b[1] = (u8) (temp | 1);
    reg_a0 = (u8 *)spread_bomb_phase1_template;
    reg_a1 = (u8 *)(reg_a6 + 2);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 0xC;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 = (u8 *)sfx_spread_bomb_a;
    reg_a1 += 2;
    switch (ENTITY(reg_a6)->flags.b[0] & 2) { case 0: goto next_1; }
    reg_tmp.w = (u32) spread_bomb_b_phase1_frames;
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)sfx_spread_bomb_b;
next_1:
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
    if (reg_a5 != g_player1_as_u8_a) goto next_2;
    vibration_start_pad1(0xC8, 0x64);
    goto block_a;
next_2:
    vibration_start_pad2(0xC8, 0x64);
block_a:
    if (*(u16 *)(reg_a6 + 0x28) != 0) goto block_c;
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] += *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d4.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    sprite_draw_with_bombs_keep();
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x23);
    *(u8 *)(reg_a6 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts_2;
    *(u8 *)(reg_a6 + 0x23) = (u8) *(u8 *)(reg_a6 + 0x22);
    if (*(u16 *)reg_a0 == 0xFFFF) goto block_b;
    reg_tmp.w = (u32) reg_a0;
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
block_rts_2:
    return;
block_b:
    reg_a0 = (u8 *)spread_bomb_phase2_template;
    reg_a1 = (u8 *)(reg_a6 + 6);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    if (!(ENTITY(reg_a6)->flags.b[0] & 2)) goto block_c;
    reg_tmp.w = (u32) spread_bomb_b_phase2_frames;
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
block_c:
    if (*(u16 *)(reg_a6 + 0x28) != 1) goto block_e;
    reg_d1.w = 0x40;
    rng_next_bit();
    if (reg_d0.b[0] != 0) goto next_3;
    reg_d1.h[0] *= 0xFFFF;
next_3:
    ENTITY(reg_a6)->x.h += reg_d1.h[0];
    if (g_frame_mod2 != 0) goto block_rts;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!((s32) reg_tmp.h[0] < 4)) goto next_4;
    *(u16 *)(reg_a6 + 0x2A) -= 1;
    if (*(u16 *)(reg_a6 + 0x2A) == 0) goto block_d;
    *(u16 *)(reg_a6 + 0x24) = 0x1C;
next_4:
    entity_draw_with_bombs();
    return;
block_d:
    reg_a0 = (u8 *)spread_bomb_phase3_template;
    reg_a1 = (u8 *)(reg_a6 + 6);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    if (!(ENTITY(reg_a6)->flags.b[0] & 2)) goto block_e;
    reg_tmp.w = (u32) spread_bomb_b_phase3_frames;
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
block_e:
    temp = ENTITY(reg_a6)->flags.b[1];
    if (!(temp & 2)) goto next_5;
    ENTITY(reg_a6)->flags.b[1] = (u8) (temp & 0xFD);
    goto block_f;
next_5:
    ENTITY(reg_a6)->flags.b[1] = (u8) (temp | 2);
    return;
block_f:
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    entity_draw_with_bombs_keep();
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    if (reg_tmp.w == -1U) goto block_g;
    reg_tmp.w = (u32) reg_a0;
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
    return;
block_g:
    reg_a0 = (u8 *)g_player1_as_u8_a;
    reg_d1.w = 0;
    reg_a6 = (u8 *)g_bomb_entities_as_u8_a;
    if (ENTITY(reg_a6)->flags.sb[0] >= 0) goto next_6;
    reg_a0 = (u8 *)g_player2_as_u8_a;
    reg_d1.w = 2;
next_6:
    reg_d0.b[0] = *(u8 *)(reg_a0 + 0x38);
    if ((s32) *(u8 *)(reg_a0 + 0x1B) <= (s32) reg_d0.b[0]) goto next_7;
    *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
next_7:
    g_bomb_afterglow_timer = 0x28;
    bombs_clear();
block_rts:
    return;
}
s32 sfx_laser_bomb_a();
s32 sfx_laser_bomb_b();
s32 func_0020A270();
extern s16 g_bomb_afterglow_timer_as_s16;
extern u16 g_laser_bomb_sizzle;

void laser_bomb_update(arg3)
    u16 arg3;
{
    u8 *temp_a1;
    u8 *var_a2;
    s64 temp_v0;
    s64 temp_v0_2;
    s64 temp_v0_3;
    s64 temp_v0_4;
    u16 *var_a1;
    u16 var_a0;
    u16 var_a3;
    var_a3 = arg3;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 1;
    if (!(reg_tmp.b[0] & 1)) {
        reg_a0 = ((u8 *)laser_bomb_template);
        reg_a1 = (u8 *)(reg_a6 + 6);
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 0x7B0;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        var_a2 = (u8 *)(reg_a0 + 2);
        var_a1 = (u16 *)(reg_a1 + 2);
        reg_a0 = var_a2;
        reg_a1 = (u8 *)(var_a1);
        reg_d0.h[0] = *(u16 *)(reg_a5 + 2);
        reg_d0.h[0] += 0x7FFF + 0x7E01;
        *(u16 *)(reg_a6 + 0x7E2) = reg_d0.h[0];
        reg_a0 = (u8 *)sfx_laser_bomb_a;
        reg_d0.w = 0;
        g_laser_bomb_sizzle = reg_d0.h[0];
        if (ENTITY(reg_a6)->flags.b[0] & 2) {
            reg_tmp.w = (u32) laser_bomb_b_base_frames;
            ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
            reg_tmp.w = (u32) laser_bomb_b_beam_table;
            *(u16 *)(reg_a6 + 0x28) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x2A) = (u16) reg_tmp.h[0];
            reg_tmp.w = (u32) laser_bomb_b_beam_frames;
            *(u16 *)(reg_a6 + 0x2C) = (u16) reg_tmp.h[1];
            var_a3 = reg_tmp.h[0];
            *(u16 *)(reg_a6 + 0x2E) = var_a3;
            reg_tmp.w = (u32) laser_bomb_b_tip_frames;
            *(u16 *)(reg_a6 + 0x7FE) = (u16) reg_tmp.h[1];
            var_a2 = (u8 *) reg_tmp.h[0];
            *(u16 *)(reg_a6 + 0x800) = (u16) var_a2;
            reg_tmp.w = (u32) laser_bomb_b_muzzle_frames;
            *(u16 *)(reg_a6 + 0x82E) = (u16) reg_tmp.h[1];
            var_a1 = (u16 *) reg_tmp.h[0];
            *(u16 *)(reg_a6 + 0x830) = (u16) var_a1;
            reg_tmp.w = (u32) laser_bomb_b_impact_frames;
            *(u16 *)(reg_a6 + 0x85E) = (u16) reg_tmp.h[1];
            var_a0 = reg_tmp.h[0];
            *(u16 *)(reg_a6 + 0x860) = var_a0;
            reg_a0 = (u8 *)sfx_laser_bomb_b;
        }
        reg_call_target = (Fn)(reg_a0);
        reg_call_target();
        if (reg_a5 == g_player1_as_u8_a) {
            vibration_start_pad1(0xC8, 0x78);
        } else {
            vibration_start_pad2(0xC8, 0x78);
        }
    }
    reg_d0.h[1] = *(u16 *)(reg_a5 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x7E4) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x812) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x814) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x844) = (u16) reg_d0.h[0];
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        *(u16 *)(reg_a6 + 0x24) = (u16) *(u16 *)(reg_a6 + 0x26);
    }
    if (ENTITY(reg_a6)->hp.h == 0) {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
        reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
        reg_a0 = (u8 *) reg_tmp.w;
        ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x7FE);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x800);
        reg_a0 = (u8 *) reg_tmp.w;
        *(u16 *)(reg_a6 + 0x7EA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x7EC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x82E);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x830);
        reg_a0 = (u8 *) reg_tmp.w;
        *(u16 *)(reg_a6 + 0x81A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x81C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x85E);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x860);
        reg_a0 = (u8 *) reg_tmp.w;
        *(u16 *)(reg_a6 + 0x84A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x84C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->move.h -= 1;
        if (ENTITY(reg_a6)->move.h == 0) {
            ENTITY(reg_a6)->hp.h = 1U;
            goto block_40;
        }
block_36:
        laser_bomb_beam_draw();
        laser_bomb_tip_update();
        laser_bomb_muzzle_update();
        laser_bomb_impact_update();
        entity_draw_with_bombs();
        reg_a6 += 0x7E0;
        if (!(ENTITY(reg_a6)->flags.b[1] & 2)) {
            entity_draw_with_bombs();
        }
        reg_a6 += 0x30;
        entity_draw_with_bombs();
        reg_a6 += 0x30;
        if (!(ENTITY(reg_a6)->flags.b[1] & 2)) {
            entity_draw_with_bombs();
            reg_d0.w = 2;
            func_0020A270();
        }
        return;
    }
block_40:
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    if (reg_tmp.w != -1U) {
        ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x7EA) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x7EC) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x81A) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x81C) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x84A) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x84C) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x2C) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x2E) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_tmp.w = (u32) reg_a0;
        *(u16 *)(reg_a6 + 0x28) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a6 + 0x2A) = (u16) reg_tmp.h[0];
        laser_bomb_beam_rebuild();
        goto block_36;
    } else {
        g_bomb_afterglow_timer_as_s16 = 0x28;
        laser_bomb_end();
        bombs_clear();
    }
}
extern s32 g_laser_bomb_hit_entity;
extern u16 g_laser_bomb_hit_position;
extern u16 g_bomb_entities_1[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void laser_bomb_beam_draw(void) {
    reg_tmp.h[0] = W(0x80A);
    W(0x80A) -= 4;
    if ((s32) reg_tmp.h[0] >= 4) goto next_20;
    W(0x80A) = 0x1C;
next_20:
    reg_a3 = reg_a6;
    if (W(0x18) != 0) {
        laser_bomb_beam_draw_fading();
        return;
    }
    reg_d0.h[0] = W(0x80A);
    reg_tmp.h[1] = W(0x2C);
    reg_tmp.h[0] = W(0x2E);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d5.w = (u32) reg_a0;
    reg_d4.h[0] = W(0x24);
    reg_a0 += reg_d4.h[0];
    reg_d7.w = 0x28;
    reg_d6.w = 0;
    reg_a6 = (u8 *) g_bomb_entities_1;
    reg_a2 = (u8 *) laser_bomb_segment_template;
loop_40:
    if ((s16) W(0) < 0) goto next_100;
    if (reg_d6.h[0] != 0) goto next_190;
    reg_a1 = reg_a6;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    reg_d0.w += 0x06000000;
    *(u16 *)reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a0 + 0);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a0 + 2);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d5.h[1];
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d5.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_d6.w = 1;
    goto next_180;
next_100:
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
    reg_a1 = (u8 *) reg_tmp.w;
    W(0xA) = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a1;
    W(0xC) = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d0.h[0] = W(2);
    reg_d0.h[0] += 0x200;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x30);
    if (g_laser_bomb_hit_entity == 0) goto next_120;
    if (g_laser_bomb_hit_position < reg_d0.h[0]) goto next_140;
next_120:
    if ((s32) reg_d0.h[0] < 0x7800) goto next_160;
next_140:
    W(0) = 0;
    goto next_190;
next_160:
    reg_d0.h[0] += 0x200;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    W(2) = reg_d0.h[1];
    W(4) = reg_d0.h[0];
next_180:
    entity_draw_with_bombs_keep();
next_190:
    reg_a6 += 0x30;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_40;
    reg_a6 = reg_a3;
}

void laser_bomb_beam_draw_fading(void) {
    u32 base;

    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2C);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2E);
    reg_a0 = (u8 *)reg_tmp.w;
    base = (u32)(reg_a0 + *(u16 *)(reg_a6 + 0x80A));
    reg_d7.w = 0x28;
    reg_a6 = (u8 *)g_bomb_entities_1;
    reg_a0 = (u8 *)base;
    reg_a2 = (u8 *)laser_bomb_segment_template;
    reg_d6.w = 0;
loop_0:
    if ((s16)ENTITY(reg_a6)->flags.h < 0) goto next_0;
    if (reg_d6.h[0] != 0) goto next_6;
    reg_a1 = reg_a6;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    reg_d0.w += 0x06000000;
    *(u16 *)reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a0 + 2);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_d6.w = 1;
    reg_a2 += 2;
    reg_a1 += 2;
    goto next_5;
next_0:
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] += 0x200;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x30);
    if (g_laser_bomb_hit_entity != 0) goto next_1;
    if (*(u16 *)(reg_a3 + 0x868) == 0) goto next_2;
    if (*(u8 *)(reg_a3 + 1) & 0x40) goto next_2;
    if ((s32)*(u16 *)(reg_a3 + 0x842) < (s32)reg_d0.h[0]) goto next_3;
    goto next_2;
next_1:
    if ((s32)g_laser_bomb_hit_position < (s32)reg_d0.h[0]) goto next_3;
next_2:
    if ((s32)reg_d0.h[0] < 0x7800) goto next_4;
next_3:
    ENTITY(reg_a6)->flags.h = 0;
    goto next_6;
next_4:
    reg_d0.h[0] += 0x200;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    ENTITY(reg_a6)->y.h = reg_d0.h[1];
    ENTITY(reg_a6)->x.h = reg_d0.h[0];
next_5:
    entity_draw_with_bombs_keep();
next_6:
    reg_a6 += 0x30;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    reg_a6 = reg_a3;
}

void laser_bomb_tip_update(void) {
    reg_a0 = reg_a6;
    reg_a6 += 0x7E0;
    if (*(u16 *)(reg_a6 + 0x28) == 0) {
        if ((g_laser_bomb_hit_entity == 0) && ((*(u16 *)(reg_a0 + 0x868) == 0) || (*(u8 *)(reg_a0 + 1) & 0x40))) {
            ENTITY(reg_a6)->flags.b[1] &= 0xFD;
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] += 0x400;
            reg_d0.h[0] += *(u16 *)(reg_a5 + 0x30);
            ENTITY(reg_a6)->y.h = (u16) reg_d0.h[0];
            if ((s32) reg_d0.h[0] >= 0x7E00) {
                *(u16 *)(reg_a6 + 0x28) = 1U;
                goto block_6;
            }
        } else {
block_6:
            ENTITY(reg_a6)->flags.b[1] |= 2;
        }
    }
    reg_a6 -= 0x7E0;
}

void laser_bomb_muzzle_update(void) {
}

void laser_bomb_impact_update(void) {
    reg_a0 = reg_a6;
    reg_a6 += 0x840;
    reg_d1.h[0] = g_laser_bomb_hit_position;
    if (g_laser_bomb_hit_entity != 0) goto block_1;
    if (*(u16 *)(reg_a6 + 0x28) == 0) goto block_3;
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.b[0] = *(u8 *)(reg_a0 + 1);
    *(u8 *)(reg_a0 + 1) |= 0x20;
    if (reg_tmp.b[0] & 0x20) goto block_3;
    goto block_2;
block_1:
    *(u8 *)(reg_a0 + 1) &= 0xDF;
block_2:
    *(u8 *)(reg_a0 + 1) &= 0xBF;
    ENTITY(reg_a6)->flags.b[1] &= 0xFD;
    ENTITY(reg_a6)->y.h = reg_d1.h[0];
    *(u16 *)(reg_a6 + 0x28) = 1;
    goto block_4;
block_3:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 2;
    if (reg_tmp.b[0] & 2) goto block_4;
    *(u8 *)(reg_a0 + 0x7E1) &= 0xFD;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] += 0x400;
    if (*(u16 *)(reg_a0 + 0x18) == 0) goto skip_1;
    reg_d0.h[0] -= 0x800;
skip_1:
    *(u16 *)(reg_a0 + 0x7E2) = reg_d0.h[0];
    *(s16 *)(reg_a0 + 0x808) = 0;
    *(u8 *)(reg_a0 + 1) |= 0x40;
block_4:
    reg_a6 -= 0x840;
}


void laser_bomb_beam_rebuild(void) {
    reg_d7.w = 0x28;
    reg_a1 = (u8 *) g_bomb_entities_1;
    reg_d6.h[1] = *(u16 *) (reg_a5 + 2);
    reg_d6.h[0] = *(u16 *) (reg_a5 + 4);
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    reg_d6.h[0] += 0x600;
    reg_d6.h[0] -= *(u16 *) (reg_a5 + 0x30);
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    reg_d5.w = 0;
loop_20:
    if (reg_d5.h[0] == 0) goto next_40;
    *(u16 *) reg_a1 = 0;
    reg_a1 += 0x30;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_20;
    goto next_160;
next_40:
    reg_tmp.h[1] = *(u16 *) (reg_a6 + 0x2C);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x2E);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_a0 += *(u16 *) (reg_a6 + 0x80A);
    reg_a2 = (u8 *) laser_bomb_segment_template;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d6.h[1];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d6.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    reg_d6.h[0] += 0x400;
    if (g_laser_bomb_hit_entity != 0) goto next_80;
    if (*(u8 *) (reg_a6 + 0x841) & 2) goto next_60;
    if ((s32) *(u16 *) (reg_a6 + 0x842) > (s32) reg_d6.h[0]) goto next_120;
    *(u16 *) (reg_a6 + 0x842) = reg_d6.h[0];
    goto next_100;
next_60:
    if (*(u8 *) (reg_a6 + 0x7E1) & 2) goto next_80;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x7E2);
    reg_d0.h[0] += 0x800;
    if ((s32) reg_d0.h[0] > (s32) reg_d6.h[0]) goto next_120;
    goto next_100;
next_80:
    if (reg_d6.h[0] < 0x7800) goto next_120;
next_100:
    reg_d5.w = 1;
next_120:
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    *(u16 *) reg_a1 = *(u16 *) (reg_a0 + 0);
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) (reg_a0 + 2);
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_a1 -= 0x1E;
    *(u16 *) (reg_a6 + 0x80A) += 4;
    if (*(u16 *) (reg_a6 + 0x80A) != 0x20) goto next_140;
    *(u16 *) (reg_a6 + 0x80A) = 0;
next_140:
    reg_a1 += 0x30;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_20;
next_160:
    *(u16 *) (reg_a6 + 0x80A) = 0x1C;
}

s32 p1_laser_stop();                            /* extern */
s32 p2_laser_stop();                            /* extern */
extern s16 g_p2_laser_bomb_active_as_s16;
extern s16 g_p1_laser_bomb_active_as_s16;
extern s8 g_bomb_entities_as_s8_a[];

void laser_bomb_end(void) {
    reg_a6 = (u8 *)g_bomb_entities_as_s8_a;
    if (*(s8 *)reg_a6 >= 0) {
        reg_a0 = g_player1_as_u8_a;
        p1_laser_stop();
        g_p1_laser_bomb_active_as_s16 = 0;
        g_player1_as_u8_a[0] &= 0xBF;
    } else {
        reg_a0 = g_player2_as_u8_a;
        p2_laser_stop();
        g_p2_laser_bomb_active_as_s16 = 0;
        g_player2_as_u8_a[0] &= 0xBF;
    }
    *reg_a0 &= 0x7F;
    reg_d0.w = 0;
    g_laser_bomb_hit_entity = 0;
}

void bomb_afterglow_end(void) {
    reg_d0.w = 0;
    PLAYER(g_player1_as_u8_a)->state.b.invincible = reg_d0.b[0];
    PLAYER(g_player2_as_u8_a)->state.b.invincible = reg_d0.b[0];
}

s32 p1_chain_reset();
s32 p2_chain_reset();
extern u16 g_p2_combo_at_bomb;
extern u16 g_p1_combo_at_bomb;

void bombs_clear(void) {
    reg_d0.w = 0;
    if (g_p1_combo_at_bomb != 0) {
        p1_chain_reset();
    }
    if (g_p2_combo_at_bomb != 0) {
        p2_chain_reset();
    }
    reg_d7.w = 0x2C;
    g_p1_laser_bomb_active_as_s16 = 0;
    g_p2_laser_bomb_active_as_s16 = 0;
    reg_a0 = (u8 *)(g_bomb_entities);
    reg_d0.w = 0;
    g_player1_as_u8_a[0] &= 0xBF;
    g_player2_as_u8_a[0] &= 0xBF;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
