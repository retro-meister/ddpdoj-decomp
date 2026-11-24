#ifndef DDPDOJ_CD_H
#define DDPDOJ_CD_H

#include "common.h"
#include "sdk/ps2sdk.h"

/* Size and first sector of a disc file, looked up once at boot. */
typedef struct {
    s32 size;
    u32 lba;
} CdFileEntry;

/* Indices into g_data_files. */
enum {
    DATA_FILE_FONT,           /* \DATA\FONT.GF */
    DATA_FILE_BULLET,         /* \SPRITE\BULLET.DAT */
    DATA_FILE_EXPLOSION,      /* \SPRITE\EXP.DAT */
    DATA_FILE_SPRITE_DATA,    /* \SPRITE\SPDAT.PRS */
    DATA_FILE_SPRITE_HEADER,  /* \SPRITE\SPHED.PRS */
    DATA_FILE_STAGE_SPRITES,  /* \SPRITE\ST1SP.PRS .. ST5SP.PRS */
    DATA_FILE_COMMON_TEX = 10, /* \DATA\DDON3_02.DAT */
    DATA_FILE_FRAME,          /* \DATA\WAKU.8 */
    DATA_FILE_ARIKA,          /* \DATA\ARIKA.8 */
    DATA_FILE_MAP,            /* \DATA\MAP2.8 */
#ifdef DEATH_LABEL
    DATA_FILE_DON,            /* \DATA\DON.8 */
    DATA_FILE_NOISE,          /* \DATA\NOIZU.8 */
#endif
    DATA_FILE_TABLE_SIZE = 20
};

extern sceCdlFILE g_cd_file; /* result of the last cd_search_file */
extern CdFileEntry g_replay_files[10];   /* \\REP\\SP00.DAT .. */
extern CdFileEntry g_data_files[DATA_FILE_TABLE_SIZE];
extern CdFileEntry g_stage_bg_files[20]; /* per stage: STnBG.PHD, STnBG.PRS */
extern CdFileEntry g_bgm_files[30];

void cd_read_async(void *destination, s32 byteCount, u32 startSector);
void cd_read_sync(void *destination, u32 byteCount, u32 startSector);
void cd_search_file(const char *path);

#endif
