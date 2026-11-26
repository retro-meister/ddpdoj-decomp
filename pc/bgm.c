#include "pc_sound.h"
#include "disc_image.h"
#include "sfx.h"

#include <SDL3/SDL.h>

/* Retail D2 tracks alternate 0x200-byte left and right PCM16LE planes. */
enum { CHANNEL_BYTES = 0x200, PCM_BLOCK = CHANNEL_BYTES * 2, READ_BLOCKS = 8,
       QUEUE_LIMIT = PCM_BLOCK * 8, BGM_RATE = 48000 };

typedef struct {
    SDL_AudioStream *audio;
    Uint64 offset;
    Uint32 length;
    Uint32 cursor;
    unsigned generation;
    float volume;
    float master;
    bool loop;
    bool loaded;
    bool playing;
    bool failed;
} Track;

static struct {
    DiscImage *disc;
    SDL_Mutex *mutex;
    SDL_Thread *worker;
    Track tracks[2];
    bool stopping;
} music;

static void interleave_pcm(const Uint8 *raw, Sint16 *pcm, size_t bytes)
{
    for (size_t block = 0; block < bytes; block += PCM_BLOCK) {
        for (size_t sample = 0; sample < CHANNEL_BYTES / sizeof(Sint16); sample++) {
            for (size_t channel = 0; channel < 2; channel++) {
                const Uint8 *src = raw + block + channel * CHANNEL_BYTES + sample * sizeof(Sint16);
                pcm[block / sizeof(Sint16) + sample * 2 + channel] =
                    (Sint16)((Uint16)src[0] | ((Uint16)src[1] << 8));
            }
        }
    }
}

static void fill_track(Track *track)
{
    if (!track->loaded || track->failed || SDL_GetAudioStreamQueued(track->audio) >= QUEUE_LIMIT) return;
    if (track->cursor == track->length) {
        if (!track->loop) return;
        track->cursor = 0;
    }

    Uint8 raw[PCM_BLOCK * READ_BLOCKS];
    Sint16 pcm[sizeof(raw) / sizeof(Sint16)];
    Uint32 bytes = SDL_min(track->length - track->cursor, (Uint32)sizeof(raw));
    Uint64 offset = track->offset + track->cursor;
    unsigned generation = track->generation;
    SDL_UnlockMutex(music.mutex);
    bool ok = disc_image_read(music.disc, offset, raw, bytes);
    if (ok) interleave_pcm(raw, pcm, bytes);
    SDL_LockMutex(music.mutex);

    if (track->generation != generation) return;
    if (!ok || !SDL_PutAudioStreamData(track->audio, pcm, (int)bytes)) {
        track->failed = true;
        return;
    }
    track->cursor += bytes;
}

static int SDLCALL bgm_worker(void *unused)
{
    (void)unused;
    SDL_LockMutex(music.mutex);
    while (!music.stopping) {
        for (size_t i = 0; i < SDL_arraysize(music.tracks); i++) {
            Track *track = &music.tracks[i];
            fill_track(track);
            if (track->playing && !track->loop && track->cursor == track->length &&
                SDL_GetAudioStreamQueued(track->audio) == 0 &&
                SDL_GetAudioStreamAvailable(track->audio) == 0) {
                track->playing = false;
                SDL_PauseAudioStreamDevice(track->audio);
            }
        }
        SDL_UnlockMutex(music.mutex);
        SDL_Delay(4);
        SDL_LockMutex(music.mutex);
    }
    SDL_UnlockMutex(music.mutex);
    return 0;
}

bool pc_bgm_open(const char *iso_path)
{
    if (music.disc) return false;
    music.disc = disc_image_open(iso_path);
    if (!music.disc) return false;
    music.mutex = SDL_CreateMutex();
    SDL_AudioSpec spec = {.format = SDL_AUDIO_S16, .channels = 2, .freq = BGM_RATE};
    for (size_t i = 0; i < SDL_arraysize(music.tracks); i++) {
        Track *track = &music.tracks[i];
        track->audio = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, NULL, NULL);
        if (!track->audio) break;
        track->volume = 1.0f;
        track->master = 1.0f;
    }
    if (music.mutex && music.tracks[0].audio && music.tracks[1].audio) {
        music.worker = SDL_CreateThread(bgm_worker, "DaiOuJou music", NULL);
    }
    if (music.worker) return true;
    pc_bgm_close();
    return false;
}

void pc_bgm_close(void)
{
    if (!music.disc) return;
    if (music.worker) {
        SDL_LockMutex(music.mutex);
        music.stopping = true;
        SDL_UnlockMutex(music.mutex);
        SDL_WaitThread(music.worker, NULL);
    }
    for (size_t i = 0; i < SDL_arraysize(music.tracks); i++) {
        SDL_DestroyAudioStream(music.tracks[i].audio);
    }
    SDL_DestroyMutex(music.mutex);
    disc_image_close(music.disc);
    SDL_zero(music);
}

static void unload(Track *track)
{
    SDL_PauseAudioStreamDevice(track->audio);
    SDL_ClearAudioStream(track->audio);
    track->generation++;
    track->loaded = false;
    track->playing = false;
    track->failed = false;
}

static s32 music_command(Track *track, unsigned command, s32 first, s32 second)
{
    switch (command) {
    case 0x10:
    case 0x30:
        unload(track);
        return 0;
    case 0x60:
    case 0x110:
        track->playing = false;
        return SDL_PauseAudioStreamDevice(track->audio) ? 0 : -1;
    case 0x80:
    case 0xa0: {
        float gain = ((u32)first & 0x7fff) / (command == 0xa0 ? 16383.0f : 32767.0f);
        gain = SDL_min(gain, 1.0f);
        if (command == 0xa0) track->master = gain;
        else track->volume = gain;
        return SDL_SetAudioStreamGain(track->audio, track->master * track->volume) ? 0 : -1;
    }
    case 0x50:
    case 0x150:
        if (!track->loaded || track->failed) return -1;
        track->playing = SDL_ResumeAudioStreamDevice(track->audio);
        return track->playing ? 0 : -1;
    case 0x100:
        if (track->failed) return -1;
        return track->loaded && SDL_GetAudioStreamQueued(track->audio) > 0 ? 0 : 1;
    case 0x160:
        unload(track);
        if (first < PCM_BLOCK || second < 0) return -1;
        track->offset = (Uint64)second * DISC_SECTOR_SIZE;
        track->length = (Uint32)first - (Uint32)first % PCM_BLOCK;
        track->cursor = 0;
        track->loaded = true;
        return 0;
    case 0x80b0:
        return track->playing ? 0x1000 : 0;
    case 0x80c0:
        track->loop = first == 0;
        return 0;
    case 0x140: /* The worker starts buffering on 0x160. */
    case 0xe0:  /* Resume preparation is implicit in the desktop stream. */
    case 0x200: /* The stream is opened in stereo. */
    case 0x8000: /* IOP buffer size, managed by the desktop worker here. */
        return 0;
    default:
        return -1;
    }
}

s32 pc_sound_command(s32 command, s32 first, s32 second, s32 third)
{
    switch (command) {
    case 0x500:
        return pc_sfx_play((unsigned)first, (unsigned)second) ? 0 : -1;
    case 0x580:
        return pc_sfx_play_on_channel((unsigned)first, (unsigned)second, third) ? 0 : -1;
    case 0x510:
        pc_sfx_stop_channel(first);
        return 0;
    case 0x520:
    case 0x540:
        pc_sfx_stop_all();
        return 0;
    case 0x530:
        return 0; /* Both desktop players advance independently of game ticks. */
    }
    if (!music.worker) return -1;
    SDL_LockMutex(music.mutex);
    s32 result = music_command(&music.tracks[command & 1], (unsigned)command & ~1u, first, second);
    SDL_UnlockMutex(music.mutex);
    return result;
}
