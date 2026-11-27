#include "game_snapshot.h"
#include "combat_state.h"
#include "gs_texture.h"
#include "pc_frame_regions.h"
#include "pc_player_state.h"
#include "pc_replay_frame.h"
#include "pc_sound.h"
#include "pc_task_state.h"
#include "sfx.h"

typedef struct {
    PcPlayerState players;
    PcCombatPools combat;
    PcTaskState tasks;
    PcReplayFrame replay;
    PcMusicState music;
    PcSfxState sounds;
    u8 regions[];
} GameSnapshot;

static SDL_IOStream *capture(void)
{
    size_t regions = pc_frame_regions_size();
    size_t bytes = sizeof(GameSnapshot) + regions;
    GameSnapshot *state = SDL_calloc(1, bytes);
    if (!state) return NULL;
    pc_player_state_capture(&state->players);
    pc_combat_capture(&state->combat);
    pc_tasks_capture(&state->tasks);
    pc_replay_frame_capture(&state->replay);
    SDL_IOStream *stream = SDL_IOFromDynamicMem();
    bool ok = stream && pc_frame_regions_capture(state->regions, regions) &&
              pc_bgm_capture(&state->music) && pc_sfx_capture(&state->sounds) &&
              SDL_WriteIO(stream, state, bytes) == bytes && pc_gs_textures_save(stream);
    SDL_free(state);
    if (!ok) {
        if (stream) SDL_CloseIO(stream);
        return NULL;
    }
    return stream;
}

static void *stream_data(SDL_IOStream *stream)
{
    return SDL_GetPointerProperty(SDL_GetIOProperties(stream),
                                  SDL_PROP_IOSTREAM_DYNAMIC_MEMORY_POINTER, NULL);
}

bool pc_game_save(const char *path, GameMode mode, Uint64 build)
{
    SDL_IOStream *stream = capture();
    if (!stream) return false;
    bool ok = pc_state_slot_write(path, mode, build, stream_data(stream), (size_t)SDL_GetIOSize(stream));
    SDL_CloseIO(stream);
    return ok;
}

static bool restore(GameSnapshot *state, size_t bytes)
{
    size_t regions = pc_frame_regions_size();
    size_t fixed = sizeof(*state) + regions;
    if (bytes <= fixed) return SDL_SetError("Incomplete gameplay snapshot");
    SDL_IOStream *textures = SDL_IOFromConstMem((u8 *)state + fixed, bytes - fixed);
    if (!textures) return false;
    bool ok = pc_gs_textures_load(textures) && SDL_TellIO(textures) == SDL_GetIOSize(textures);
    SDL_CloseIO(textures);
    return ok && pc_combat_restore(&state->combat) && pc_tasks_restore(&state->tasks) &&
           pc_player_state_restore(&state->players) && pc_replay_frame_restore(&state->replay) &&
           pc_frame_regions_restore(state->regions, regions) &&
           pc_bgm_restore(&state->music) && pc_sfx_restore(&state->sounds);
}

bool pc_game_load(const char *path, GameMode mode, Uint64 build)
{
    size_t size;
    GameSnapshot *state = pc_state_slot_read(path, mode, build, &size);
    if (!state) return false;
    SDL_IOStream *backup = capture();
    bool ok = backup && restore(state, size);
    if (backup) {
        if (!ok) {
            bool recovered = restore(stream_data(backup), (size_t)SDL_GetIOSize(backup));
            SDL_SetError(recovered ? "Could not restore gameplay snapshot" : "Could not recover game state");
        }
        SDL_CloseIO(backup);
    }
    SDL_free(state);
    return ok;
}
