#include "memory_card.h"
#include "sdk/libmc.h"

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

static void require(bool condition, const char *message)
{
    if (!condition) {
        fprintf(stderr, "%s (%s)\n", message, SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

static s32 finish(void)
{
    s32 result;
    require(sceMcSync(0, 0, &result) == 1, "Consume a card result");
    return result;
}

static SDL_EnumerationResult SDLCALL remove_entry(void *unused, const char *directory,
                                                   const char *name)
{
    (void)unused;
    char *path = NULL;
    require(SDL_asprintf(&path, "%s%s", directory, name) >= 0, "Build test cleanup path");
    SDL_PathInfo info;
    require(SDL_GetPathInfo(path, &info), "Inspect test cleanup path");
    if (info.type == SDL_PATHTYPE_DIRECTORY) {
        require(SDL_EnumerateDirectory(path, remove_entry, NULL), "Traverse test cleanup path");
    }
    require(SDL_RemovePath(path), "Remove a test card entry");
    SDL_free(path);
    return SDL_ENUM_CONTINUE;
}

int main(void)
{
    SDL_Time now;
    char *root = NULL;
    require(SDL_GetCurrentTime(&now) &&
            SDL_asprintf(&root, "memory-card-test-%" SDL_PRIs64, now) >= 0 &&
            pc_mc_open_storage(root), "Open test card storage");
    s32 type, blocks, formatted;
    require(sceMcGetInfo(0, 0, &type, &blocks, &formatted) == 0, "Queue card info");
    require(sceMcGetInfo(1, 0, NULL, NULL, NULL) != 0, "Reject overlapping card commands");
    require(finish() == 0 && type == 2 && blocks > 0 && formatted, "Read a formatted card");
    require(sceMcOpen(0, 0, "/../save", 0x203) != 0, "Reject parent traversal");

    char directory[] = "/BISLPS-25233REPLAY1";
    char path[] = "/BISLPS-25233REPLAY1/BISLPS-25233REPLAY1";
    char pattern[] = "/BISLPS-25233REPLAY1/*";
    static u8 replay[0x206ec], received[sizeof(replay)];
    for (size_t i = 0; i < sizeof(replay); ++i) replay[i] = (u8)(i * 23u + i / 256);
    require(sceMcMkdir(0, 0, directory) == 0 && finish() == 0, "Create a replay directory");
    require(sceMcOpen(0, 0, path, 0x203) == 0, "Queue replay creation");
    s32 fd = finish();
    require(fd >= 0 && sceMcWrite(fd, replay, sizeof(replay)) == 0 &&
            finish() == sizeof(replay), "Save a full PS2 replay payload");
    require(sceMcClose(fd) == 0 && finish() == 0, "Publish the replay");

    /* An exit before sceMcClose must leave the previous replay intact. */
    require(sceMcOpen(0, 0, path, 0x203) == 0, "Queue an overwrite");
    fd = finish();
    require(fd >= 0 && sceMcWrite(fd, replay, 4) == 0 && finish() == 4, "Write a partial replay");
    pc_mc_close_storage();
    require(pc_mc_open_storage(root), "Reopen the card on the next launch");

    u8 entries[5][64];
    require(sceMcGetDir(0, 0, pattern, 0, 5, entries) == 0 && finish() == 1,
            "List only the published replay");
    u32 file_size;
    SDL_memcpy(&file_size, entries[0] + 0x10, sizeof(file_size));
    require(file_size == sizeof(replay) &&
            SDL_strcmp((char *)entries[0] + 0x20, "BISLPS-25233REPLAY1") == 0,
            "Read the original directory-entry fields");
    require(sceMcOpen(0, 0, path, 3) == 0, "Queue a replay read");
    fd = finish();
    require(fd >= 0 && sceMcRead(fd, received, sizeof(received)) == 0 &&
            finish() == sizeof(received) && SDL_memcmp(replay, received, sizeof(replay)) == 0,
            "Recover the original bytes after an interrupted overwrite");
    require(sceMcClose(fd) == 0 && finish() == 0, "Close the replay");
    require(sceMcGetDir(1, 0, path, 0, 5, entries) == 0 && finish() == 0, "Keep the two cards separate");

    require(sceMcUnformat(0, 0) == 0 && finish() == 0, "Unformat the first card");
    require(sceMcGetInfo(0, 0, NULL, NULL, &formatted) == 0 && finish() == 0 && !formatted,
            "Report an unformatted card");
    require(sceMcFormat(0, 0) == 0 && finish() == 0, "Format the first card");
    require(sceMcGetDir(0, 0, path, 0, 5, entries) == 0 && finish() == 0,
            "Start with an empty card after format");
    pc_mc_close_storage();
    require(SDL_EnumerateDirectory(root, remove_entry, NULL) && SDL_RemovePath(root),
            "Remove temporary test storage");
    SDL_free(root);
    return EXIT_SUCCESS;
}
