/* Tables of the sound requests. */
#include "common.h"


extern u8 g_se_vag_path_1[64];
extern u8 g_se_vag_path_2[64];
extern u8 g_se_vag_path_3[64];
extern u8 g_se_vag_path_4[64];
extern u8 g_se_vag_path_5[64];
extern u8 g_se_vag_path_6[64];
extern u8 g_se_vag_path_7[16];

u8 g_se_vag_path_1[64] = "\\DATA\\SE1.VAG;1";

u8 g_se_vag_path_2[64] = "\\DATA\\SE2.VAG;1";

u8 g_se_vag_path_3[64] = "\\DATA\\SE3.VAG;1";

u8 g_se_vag_path_4[64] = "\\DATA\\SE4.VAG;1";

u8 g_se_vag_path_5[64] = "\\DATA\\SE5.VAG;1";

u8 g_se_vag_path_6[64] = "\\DATA\\SE6.VAG;1";

u8 g_se_vag_path_7[16] = "\\DATA\\SE7.VAG;1";

/* The music files, by music number. */
char *g_bgm_file_paths[26] = {
    "\\BGM\\BGM1.D2;1",
    "\\BGM\\BGM2.D2;1",
    "\\BGM\\BGM3.D2;1",
    "\\BGM\\BGM4.D2;1",
    "\\BGM\\BGM5.D2;1",
    "\\BGM\\BGM6.D2;1",
    "\\BGM\\BGM7.D2;1",
    "\\BGM\\BGM8.D2;1",
    "\\BGM\\BGM9.D2;1",
    "\\BGM\\BGM10.D2;1",
    "\\BGM\\BGM11.D2;1",
    "\\BGM\\BGM12.D2;1",
    "\\BGM\\BGM13.D2;1",
    "\\BGM\\BGM21.D2;1",
    "\\BGM\\BGM22.D2;1",
    "\\BGM\\BGM23.D2;1",
    "\\BGM\\BGM24.D2;1",
    "\\BGM\\BGM25.D2;1",
    "\\BGM\\BGM26.D2;1",
    "\\BGM\\BGM27.D2;1",
    "\\BGM\\BGM28.D2;1",
    "\\BGM\\BGM29.D2;1",
    "\\BGM\\BGM30.D2;1",
    "\\BGM\\BGM31.D2;1",
    "\\BGM\\BGM32.D2;1",
    "\\BGM\\BGM33.D2;1",
};

/* Header and picture file of each stage's background. */
char *g_stage_bg_paths[10] = {
    "\\SPRITE\\ST1BG.PHD;1",
    "\\SPRITE\\ST1BG.PRS;1",
    "\\SPRITE\\ST2BG.PHD;1",
    "\\SPRITE\\ST2BG.PRS;1",
    "\\SPRITE\\ST3BG.PHD;1",
    "\\SPRITE\\ST3BG.PRS;1",
    "\\SPRITE\\ST4BG.PHD;1",
    "\\SPRITE\\ST4BG.PRS;1",
    "\\SPRITE\\ST5BG.PHD;1",
    "\\SPRITE\\ST5BG.PRS;1",
};

/* The font, sprite and data files loaded at start. */
#ifdef DEATH_LABEL
char *g_data_file_paths[16] = {
    "\\DATA\\FONT.GF;1",
    "\\SPRITE\\BULLET.DAT;1",
    "\\SPRITE\\EXP.DAT;1",
    "\\SPRITE\\SPDAT.PRS;1",
    "\\SPRITE\\SPHED.PRS;1",
    "\\SPRITE\\ST1SP.PRS;1",
    "\\SPRITE\\ST2SP.PRS;1",
    "\\SPRITE\\ST3SP.PRS;1",
    "\\SPRITE\\ST4SP.PRS;1",
    "\\SPRITE\\ST5SP.PRS;1",
    "\\DATA\\DDON3_02.DAT;1",
    "\\DATA\\WAKU.8;1",
    "\\DATA\\ARIKA.8;1",
    "\\DATA\\MAP2.8;1",
    "\\DATA\\DON.8;1",
    "\\DATA\\NOIZU.8;1",
};
#else
char *g_data_file_paths[14] = {
    "\\DATA\\FONT.GF;1",
    "\\SPRITE\\BULLET.DAT;1",
    "\\SPRITE\\EXP.DAT;1",
    "\\SPRITE\\SPDAT.PRS;1",
    "\\SPRITE\\SPHED.PRS;1",
    "\\SPRITE\\ST1SP.PRS;1",
    "\\SPRITE\\ST2SP.PRS;1",
    "\\SPRITE\\ST3SP.PRS;1",
    "\\SPRITE\\ST4SP.PRS;1",
    "\\SPRITE\\ST5SP.PRS;1",
    "\\DATA\\DDON3_02.DAT;1",
    "\\DATA\\WAKU.8;1",
    "\\DATA\\ARIKA.8;1",
    "\\DATA\\MAP2.8;1",
};
#endif

/* Files of the built-in replays. */
char *g_replay_file_paths[10] = {
    "\\REP\\SP00.DAT;1",
    "\\REP\\SP01.DAT;1",
    "\\REP\\SP02.DAT;1",
    "\\REP\\SP03.DAT;1",
    "\\REP\\SP04.DAT;1",
    "\\REP\\SP05.DAT;1",
    "\\REP\\SP06.DAT;1",
    "\\REP\\SP07.DAT;1",
    "\\REP\\SP08.DAT;1",
    "\\REP\\SP09.DAT;1",
};
