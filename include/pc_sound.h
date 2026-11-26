#ifndef DDPDOJ_PC_SOUND_H
#define DDPDOJ_PC_SOUND_H

#include <stdbool.h>
#include "types.h"

/* Open an independent reader so the music worker cannot block game CD jobs. */
bool pc_bgm_open(const char *iso_path);
void pc_bgm_close(void);
s32 pc_sound_command(s32 command, s32 first, s32 second, s32 third);

#endif
