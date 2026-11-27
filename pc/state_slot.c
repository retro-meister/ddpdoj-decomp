#include "state_slot.h"

#ifdef _WIN32
#include <process.h>
#define process_id _getpid
#else
#include <unistd.h>
#define process_id getpid
#endif

static const char magic[] = "DDPSTATE";
enum { version = 1, header_size = 32, max_payload = 256 * 1024 * 1024 };

bool pc_state_slot_write(const char *path, GameMode mode, Uint64 build,
                         const void *data, size_t size)
{
    if (!data || !size || size > max_payload) return SDL_SetError("Invalid savestate size");
    char *temporary = NULL;
    if (SDL_asprintf(&temporary, "%s.%d.tmp", path, (int)process_id()) < 0) return false;
    SDL_IOStream *file = SDL_IOFromFile(temporary, "wb");
    bool ok = file && SDL_WriteIO(file, magic, 8) == 8 && SDL_WriteU32LE(file, version) &&
              SDL_WriteU32LE(file, mode) && SDL_WriteU64LE(file, build) &&
              SDL_WriteU32LE(file, (Uint32)size) && SDL_WriteU32LE(file, SDL_crc32(0, data, size)) &&
              SDL_WriteIO(file, data, size) == size;
    if (file && !SDL_CloseIO(file)) ok = false;
    if (ok) ok = SDL_RenamePath(temporary, path);
    if (!ok && file) SDL_RemovePath(temporary);
    SDL_free(temporary);
    return ok;
}

void *pc_state_slot_read(const char *path, GameMode mode, Uint64 build, size_t *size)
{
    *size = 0;
    SDL_IOStream *file = SDL_IOFromFile(path, "rb");
    if (!file) return NULL;
    char tag[8];
    Uint32 format, saved_mode, length, crc;
    Uint64 saved_build;
    void *data = NULL;
    if (SDL_ReadIO(file, tag, sizeof(tag)) != sizeof(tag) || SDL_memcmp(magic, tag, 8) ||
        !SDL_ReadU32LE(file, &format) || format != version ||
        !SDL_ReadU32LE(file, &saved_mode) || saved_mode != (Uint32)mode ||
        !SDL_ReadU64LE(file, &saved_build) || saved_build != build) {
        SDL_SetError("Savestate format, build or game mode does not match");
    } else if (!SDL_ReadU32LE(file, &length) || !SDL_ReadU32LE(file, &crc) ||
               !length || length > max_payload || SDL_GetIOSize(file) != (Sint64)length + header_size) {
        SDL_SetError("Invalid savestate length");
    } else if ((data = SDL_malloc(length)) != NULL) {
        if (SDL_ReadIO(file, data, length) == length && SDL_crc32(0, data, length) == crc) {
            *size = length;
        } else {
            SDL_free(data);
            data = NULL;
            SDL_SetError("Damaged savestate payload");
        }
    }
    SDL_CloseIO(file);
    return data;
}
