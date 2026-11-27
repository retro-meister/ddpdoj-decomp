#ifndef DDPDOJ_PC_SFX_H
#define DDPDOJ_PC_SFX_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

enum { PC_SFX_MIX_RATE = 44100 };

/* Load and decode the sound banks before entering the game loop. */
bool pc_sfx_load(const char *iso_path);
bool pc_sfx_open_device(void);
void pc_sfx_shutdown(void);

/* The low seven bits select the clip. Bit 7 enables its authored loop. */
bool pc_sfx_play(unsigned request, unsigned volume);
bool pc_sfx_play_on_channel(unsigned request, unsigned volume, int channel);
void pc_sfx_stop_channel(int channel);
void pc_sfx_stop_all(void);

typedef struct {
    uint32_t clip; /* Zero is silent, otherwise the bank index plus one. */
    uint32_t frame;
    uint32_t fraction;
    uint32_t volume;
    int32_t channel;
    uint32_t loop;
} PcVoiceState;

typedef struct {
    PcVoiceState voices[16];
    uint32_t next_voice;
} PcSfxState;

bool pc_sfx_capture(PcSfxState *state);
bool pc_sfx_restore(const PcSfxState *state);

/* Pull the same mixer output without an audio device. */
bool pc_sfx_render(float *mono, size_t frames);

#endif
