#include "state_slot.h"

static const Uint32 frame[] = { 901, 0x00512340, 0x8129, 0x6300 };

int main(int argc, char **argv)
{
    if (argc != 3) return 1;
    const char *path = argv[2];
    if (!SDL_strcmp(argv[1], "save")) {
        return !pc_state_slot_write(path, GAME_MODE_MAIN, 123, frame, sizeof(frame));
    }
    size_t size;
    Uint32 *data = pc_state_slot_read(path, GAME_MODE_MAIN, 123, &size);
    bool ok = data && size == sizeof(frame) && !SDL_memcmp(data, frame, size);
    SDL_free(data);
    if (!ok || pc_state_slot_read(path, GAME_MODE_DEATH_LABEL, 123, &size) ||
        pc_state_slot_read(path, GAME_MODE_MAIN, 124, &size)) return 1;
    SDL_IOStream *file = SDL_IOFromFile(path, "r+b");
    if (!file || SDL_SeekIO(file, -1, SDL_IO_SEEK_END) < 0 ||
        !SDL_WriteU8(file, 0xff) || !SDL_CloseIO(file)) return 1;
    if (pc_state_slot_read(path, GAME_MODE_MAIN, 123, &size) || size) return 1;
    return !SDL_RemovePath(path);
}
