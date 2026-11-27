#include "sfx.h"
#include "disc_image.h"

#include <SDL3/SDL.h>

enum {
    SOUND_COUNT = 56,
    VOICE_COUNT = SDL_arraysize(((PcSfxState *)0)->voices),
    VAG_HEADER_SIZE = 48,
    VAG_BLOCK_SIZE = 16,
    VAG_BLOCK_SAMPLES = 28,
    MAX_BANK_SIZE = 1024 * 1024,
};

typedef struct {
    Sint16 *pcm;
    unsigned frames;
    unsigned rate;
    unsigned loop_start;
    unsigned loop_end;
} Sound;

typedef struct {
    const Sound *sound;
    unsigned frame;
    unsigned fraction;
    unsigned volume;
    int channel;
    bool loop;
} Voice;

static Sound sounds[SOUND_COUNT];
static Voice voices[VOICE_COUNT];
static unsigned next_voice;
static SDL_AudioStream *playback;

static Uint32 read_le32(const Uint8 *data)
{
    return (Uint32)data[0] | ((Uint32)data[1] << 8) | ((Uint32)data[2] << 16) | ((Uint32)data[3] << 24);
}

static Uint32 read_be32(const Uint8 *data)
{
    return SDL_Swap32(read_le32(data));
}

/* Explicit rounding toward negative infinity for signed DSP shifts. */
static int floor_divide(int value, int divisor)
{
    return value >= 0 ? value / divisor : -((-value + divisor - 1) / divisor);
}

static bool decode_vag(Sound *sound, const Uint8 *data, size_t size)
{
    static const int coefficients[][2] = { {0, 0}, {60, 0}, {115, -52}, {98, -55}, {122, -60} };
    if (size < VAG_HEADER_SIZE || SDL_memcmp(data, "VAGp", 4) != 0) {
        return false;
    }
    unsigned length = read_be32(data + 12);
    unsigned rate = read_be32(data + 16);
    if (length != size - VAG_HEADER_SIZE || length == 0 || length % VAG_BLOCK_SIZE != 0 ||
        rate == 0 || rate > 192000) {
        return false;
    }
    unsigned frames = length / VAG_BLOCK_SIZE * VAG_BLOCK_SAMPLES;
    Sint16 *pcm = SDL_malloc((size_t)frames * sizeof(*pcm));
    if (!pcm) {
        return false;
    }

    unsigned written = 0;
    unsigned loop_start = 0;
    unsigned loop_end = 0;
    int previous = 0;
    int older = 0;
    for (size_t offset = VAG_HEADER_SIZE; offset < size; offset += VAG_BLOCK_SIZE) {
        const Uint8 *block = data + offset;
        unsigned filter = block[0] >> 4;
        unsigned shift = block[0] & 15;
        unsigned flags = block[1] & 7;
        if (flags == 7) {
            break;
        }
        if (filter >= SDL_arraysize(coefficients) || shift > 12) {
            SDL_free(pcm);
            return false;
        }
        if (flags & 4) {
            loop_start = written;
        }

        for (unsigned i = 0; i < VAG_BLOCK_SAMPLES; i++) {
            int nibble = (block[2 + i / 2] >> (i % 2 * 4)) & 15;
            if (nibble >= 8) {
                nibble -= 16;
            }
            int predicted = coefficients[filter][0] * previous + coefficients[filter][1] * older;
            int sample = floor_divide(nibble * 4096, 1 << shift) + floor_divide(predicted + 32, 64);
            sample = SDL_clamp(sample, -32768, 32767);
            pcm[written++] = (Sint16)sample;
            older = previous;
            previous = sample;
        }
        if (flags & 1) {
            if (flags & 2) {
                loop_end = written;
            }
            break;
        }
    }

    if (written == 0 || (loop_end && loop_start >= loop_end)) {
        SDL_free(pcm);
        return false;
    }
    *sound = (Sound){ pcm, written, rate, loop_start, loop_end };
    return true;
}

static bool load_bank(const Uint8 *bank, size_t length, unsigned *index)
{
    if (length < sizeof(Uint32)) {
        return false;
    }
    unsigned count = read_le32(bank);
    size_t header = (count + 1ULL) * sizeof(Uint32);
    if (count == 0 || count > SOUND_COUNT - *index || header > length) {
        return false;
    }
    for (unsigned i = 0; i < count; i++) {
        size_t offset = read_le32(bank + (i + 1) * 4);
        size_t end = i + 1 == count ? length : read_le32(bank + (i + 2) * 4);
        if (offset < header || end <= offset || end > length ||
            !decode_vag(&sounds[*index], bank + offset, end - offset)) {
            return false;
        }
        ++*index;
    }
    return true;
}

bool pc_sfx_load(const char *iso_path)
{
    if (sounds[0].pcm) {
        return SDL_SetError("Sound banks are already loaded");
    }
    DiscImage *disc = disc_image_open(iso_path);
    if (!disc) {
        return SDL_SetError("Unable to open the disc for sound banks");
    }
    unsigned clip = 0;
    for (unsigned bank = 1; bank <= 7; bank++) {
        char path[32];
        SDL_snprintf(path, sizeof(path), "DATA/SE%u.VAG", bank);
        DiscExtent extent;
        bool found = disc_image_find(disc, path, &extent) &&
                     extent.size >= sizeof(Uint32) && extent.size <= MAX_BANK_SIZE;
        Uint8 *data = found ? SDL_malloc(extent.size) : NULL;
        bool loaded = data && disc_image_read(disc, (Uint64)extent.lba * DISC_SECTOR_SIZE,
                                               data, extent.size) &&
                      load_bank(data, extent.size, &clip);
        SDL_free(data);
        if (!loaded) {
            disc_image_close(disc);
            pc_sfx_shutdown();
            return SDL_SetError("Unable to decode sound bank %s", path);
        }
    }
    disc_image_close(disc);
    if (clip != SOUND_COUNT) {
        pc_sfx_shutdown();
        return SDL_SetError("Expected %d sound effects, found %u", SOUND_COUNT, clip);
    }
    return true;
}

static void mix(float *mono, size_t frames)
{
    SDL_memset(mono, 0, frames * sizeof(*mono));
    for (unsigned i = 0; i < VOICE_COUNT; i++) {
        Voice *voice = &voices[i];
        const Sound *sound = voice->sound;
        if (!sound) {
            continue;
        }
        float gain = (float)voice->volume / (255.0f * 32768.0f);
        unsigned end = voice->loop ? sound->loop_end : sound->frames;
        for (size_t j = 0; j < frames; j++) {
            unsigned next_frame = voice->frame + 1;
            int sample = sound->pcm[voice->frame];
            if (voice->fraction) {
                unsigned next = next_frame < end ? next_frame :
                                voice->loop ? sound->loop_start : voice->frame;
                float fraction = (float)voice->fraction / PC_SFX_MIX_RATE;
                mono[j] += (sample + (sound->pcm[next] - sample) * fraction) * gain;
            } else {
                mono[j] += sample * gain;
            }
            voice->fraction += sound->rate;
            voice->frame += voice->fraction / PC_SFX_MIX_RATE;
            voice->fraction %= PC_SFX_MIX_RATE;
            if (voice->frame >= end) {
                if (!voice->loop) {
                    voice->sound = NULL;
                    break;
                }
                voice->frame = sound->loop_start + (voice->frame - end) % (end - sound->loop_start);
            }
        }
    }
    for (size_t i = 0; i < frames; i++) {
        mono[i] = SDL_clamp(mono[i], -1.0f, 1.0f);
    }
}

static void SDLCALL supply_audio(void *user, SDL_AudioStream *stream, int additional, int total)
{
    (void)user;
    (void)total;
    float buffer[256];
    size_t remaining = additional > 0 ? ((size_t)additional + sizeof(float) - 1) / sizeof(float) : 0;
    while (remaining) {
        size_t frames = SDL_min(remaining, SDL_arraysize(buffer));
        mix(buffer, frames);
        if (!SDL_PutAudioStreamData(stream, buffer, (int)(frames * sizeof(*buffer)))) {
            return;
        }
        remaining -= frames;
    }
}

bool pc_sfx_open_device(void)
{
    if (playback || !sounds[0].pcm) {
        return SDL_SetError("Playback requires one loaded sound bank set");
    }
    const SDL_AudioSpec input = { .format = SDL_AUDIO_F32, .channels = 1, .freq = PC_SFX_MIX_RATE };
    playback = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &input, supply_audio, NULL);
    if (!playback) {
        return false;
    }
    if (!SDL_ResumeAudioStreamDevice(playback)) {
        SDL_DestroyAudioStream(playback);
        playback = NULL;
        return false;
    }
    return true;
}

bool pc_sfx_play(unsigned request, unsigned volume)
{
    return pc_sfx_play_on_channel(request, volume, -1);
}

bool pc_sfx_play_on_channel(unsigned request, unsigned volume, int channel)
{
    unsigned index = request & 0x7F;
    if (request > 0xFF || index >= SOUND_COUNT || !sounds[index].pcm) {
        return false;
    }
    if (volume == 0) {
        return true;
    }
    if (playback && !SDL_LockAudioStream(playback)) {
        return false;
    }
    unsigned selected = next_voice;
    if (channel >= 0) {
        for (unsigned i = 0; i < VOICE_COUNT; i++) {
            if (voices[i].sound && voices[i].channel == channel) voices[i].sound = NULL;
        }
    }
    for (unsigned i = 0; i < VOICE_COUNT; i++) {
        unsigned candidate = (next_voice + i) % VOICE_COUNT;
        if (!voices[candidate].sound) {
            selected = candidate;
            break;
        }
    }
    const Sound *sound = &sounds[index];
    voices[selected] = (Voice){
        .sound = sound,
        .volume = SDL_min(volume, 255),
        .channel = channel,
        .loop = (request & 0x80) && sound->loop_end != 0,
    };
    next_voice = (selected + 1) % VOICE_COUNT;
    if (playback) {
        SDL_UnlockAudioStream(playback);
    }
    return true;
}

void pc_sfx_stop_channel(int channel)
{
    if (channel < 0 || (playback && !SDL_LockAudioStream(playback))) return;
    for (unsigned i = 0; i < VOICE_COUNT; i++) {
        if (voices[i].channel == channel) voices[i].sound = NULL;
    }
    if (playback) SDL_UnlockAudioStream(playback);
}

void pc_sfx_stop_all(void)
{
    if (playback && !SDL_LockAudioStream(playback)) {
        return;
    }
    SDL_zeroa(voices);
    next_voice = 0;
    if (playback) {
        SDL_ClearAudioStream(playback);
        SDL_UnlockAudioStream(playback);
    }
}

bool pc_sfx_capture(PcSfxState *state)
{
    if (playback && !SDL_LockAudioStream(playback)) return false;
    *state = (PcSfxState){ .next_voice = next_voice };
    for (unsigned i = 0; i < VOICE_COUNT; ++i) {
        const Voice *v = &voices[i];
        if (v->sound) {
            state->voices[i] = (PcVoiceState){
                .clip = (unsigned)(v->sound - sounds) + 1,
                .frame = v->frame, .fraction = v->fraction, .volume = v->volume,
                .channel = v->channel, .loop = v->loop,
            };
        }
    }
    if (playback) SDL_UnlockAudioStream(playback);
    return true;
}

bool pc_sfx_restore(const PcSfxState *state)
{
    if (state->next_voice >= VOICE_COUNT) return false;
    Voice restored[VOICE_COUNT] = {0};
    for (unsigned i = 0; i < VOICE_COUNT; ++i) {
        const PcVoiceState *v = &state->voices[i];
        if (!v->clip) continue;
        if (v->clip > SOUND_COUNT || v->volume > 255 || v->loop > 1 ||
            v->fraction >= PC_SFX_MIX_RATE) return false;
        const Sound *sound = &sounds[v->clip - 1];
        if (v->frame >= (v->loop ? sound->loop_end : sound->frames)) return false;
        restored[i] = (Voice){
            .sound = sound, .frame = v->frame, .fraction = v->fraction,
            .volume = v->volume, .channel = v->channel, .loop = v->loop,
        };
    }
    if (playback && !SDL_LockAudioStream(playback)) return false;
    bool ok = !playback || SDL_ClearAudioStream(playback);
    if (ok) {
        SDL_memcpy(voices, restored, sizeof(voices));
        next_voice = state->next_voice;
    }
    if (playback) SDL_UnlockAudioStream(playback);
    return ok;
}

bool pc_sfx_render(float *mono, size_t frames)
{
    if (playback || !mono || frames > SIZE_MAX / sizeof(*mono)) {
        return false;
    }
    mix(mono, frames);
    return true;
}

void pc_sfx_shutdown(void)
{
    if (playback) {
        SDL_DestroyAudioStream(playback);
        playback = NULL;
    }
    pc_sfx_stop_all();
    for (unsigned i = 0; i < SOUND_COUNT; i++) {
        SDL_free(sounds[i].pcm);
    }
    SDL_zeroa(sounds);
}
