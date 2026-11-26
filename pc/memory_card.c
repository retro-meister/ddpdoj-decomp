#include "memory_card.h"
#include "sdk/libmc.h"

#include <SDL3/SDL.h>

enum { MC_ERROR = -4, MC_UNFORMATTED = -2, MC_FILE = 1 };

typedef enum {
    MC_INFO, MC_DIR, MC_MKDIR, MC_FORMAT, MC_UNFORMAT, MC_OPEN, MC_CLOSE, MC_READ, MC_WRITE
} Command;

typedef struct {
    Command command;
    s32 port;
    s32 slot;
    const char *path;
    s32 value;
    void *buffer;
    s32 *type;
    s32 *free_blocks;
    s32 *formatted;
} Request;

typedef struct {
    u8 dates[16];
    u32 size;
    u16 attributes;
    u8 reserved[10];
    char name[32];
} DirectoryEntry;

_Static_assert(sizeof(DirectoryEntry) == 64, "PS2 card directory entry");

static struct {
    char *root;
    SDL_Mutex *mutex;
    SDL_Condition *changed;
    SDL_Thread *worker;
    bool stopping;
    bool busy;
    bool ready;
    Request request;
    s32 result;
    SDL_IOStream *file;
    char *destination;
    char *temporary;
    bool write_failed;
} card;

/* The game uses a save directory and at most one file component. Require
 * those components to be plain names on POSIX and Windows. */
static bool card_path_valid(const char *path, bool directory_query)
{
    if (!path || *path++ != '/' || !*path) return false;
    unsigned length = 0;
    unsigned separators = 0;
    for (; *path; ++path) {
        if (*path == '/') {
            if (!length || ++separators > 1) return false;
            length = 0;
        } else if (*path == '*' && directory_query && separators == 1 && !length && !path[1]) {
            return true;
        } else if (SDL_isalnum((unsigned char)*path) || *path == '-' || *path == '_'
                   || (*path == '.' && length && separators == 1)) {
            if (++length > 31) return false;
        } else {
            return false;
        }
    }
    return length != 0 && path[-1] != '.';
}

static char *make_path(const char *prefix, const char *suffix)
{
    char *path = NULL;
    return SDL_asprintf(&path, "%s%s", prefix, suffix) < 0 ? NULL : path;
}

static bool get_info(const char *path, SDL_PathInfo *info)
{
    return SDL_GetPathInfo(path, info);
}

static void close_file(bool publish)
{
    if (card.file) {
        card.write_failed |= !SDL_CloseIO(card.file);
        card.file = NULL;
    }
    if (card.temporary) {
        if (publish && !card.write_failed) {
            card.write_failed = !SDL_RenamePath(card.temporary, card.destination);
        }
        if (!publish || card.write_failed) SDL_RemovePath(card.temporary);
    }
    SDL_free(card.temporary);
    SDL_free(card.destination);
    card.temporary = NULL;
    card.destination = NULL;
}

static s32 open_file(const char *path, s32 flags)
{
    if (card.file || (flags != 3 && flags != 0x203)) return MC_ERROR;
    card.write_failed = false;
    if (flags == 3) {
        card.file = SDL_IOFromFile(path, "rb");
    } else {
        SDL_Time now;
        if (!SDL_GetCurrentTime(&now)) return MC_ERROR;
        card.destination = SDL_strdup(path);
        SDL_asprintf(&card.temporary, "%s.write-%" SDL_PRIs64, path, now);
        if (card.destination && card.temporary) card.file = SDL_IOFromFile(card.temporary, "wb");
    }
    if (card.file) return MC_FILE;
    close_file(false);
    return MC_ERROR;
}

static bool record_entry(DirectoryEntry *entry, const char *path, const char *name)
{
    SDL_PathInfo info;
    if (SDL_strlen(name) >= sizeof(entry->name) || !get_info(path, &info)) return false;
    if (info.type != SDL_PATHTYPE_FILE && info.type != SDL_PATHTYPE_DIRECTORY) return false;
    entry->size = info.size > UINT32_MAX ? UINT32_MAX : (u32)info.size;
    entry->attributes = info.type == SDL_PATHTYPE_DIRECTORY ? 0x8427 : 0x8497;
    SDL_strlcpy(entry->name, name, sizeof(entry->name));
    return true;
}

typedef struct {
    DirectoryEntry *entries;
    s32 limit;
    s32 count;
} Listing;

static SDL_EnumerationResult SDLCALL list_entry(void *context, const char *directory, const char *name)
{
    Listing *listing = context;
    /* Temporary writes do not appear on the emulated card. */
    if (!SDL_strstr(name, ".write-")) {
        char *path = make_path(directory, name);
        if (!path) return SDL_ENUM_FAILURE;
        if (record_entry(&listing->entries[listing->count], path, name)) listing->count++;
        SDL_free(path);
    }
    return listing->count == listing->limit ? SDL_ENUM_SUCCESS : SDL_ENUM_CONTINUE;
}

static s32 read_directory(char *path, const Request *request)
{
    DirectoryEntry *entries = request->buffer;
    SDL_memset(entries, 0, sizeof(*entries) * (size_t)request->value);
    char *name = SDL_strrchr(path, '/') + 1;
    if (SDL_strcmp(name, "*") == 0) {
        *name = '\0';
        Listing listing = {entries, request->value, 0};
        return SDL_EnumerateDirectory(path, list_entry, &listing) ? listing.count : 0;
    }
    return record_entry(entries, path, name) ? 1 : 0;
}

/* A format removes the files from the emulated card. Keep the old card as
 * a sibling backup so the in-game operation cannot destroy an imported save. */
static s32 reset_card(const char *root, const char *marker, bool formatted)
{
    if (card.file) return MC_ERROR;
    SDL_PathInfo info;
    if (get_info(root, &info)) {
        char *backup = NULL;
        SDL_Time now;
        if (!SDL_GetCurrentTime(&now) ||
            SDL_asprintf(&backup, "%s.backup-%" SDL_PRIs64, root, now) < 0) return MC_ERROR;
        bool moved = SDL_RenamePath(root, backup);
        SDL_free(backup);
        if (!moved) return MC_ERROR;
    }
    return (formatted ? (!get_info(marker, NULL) || SDL_RemovePath(marker))
                      : SDL_CreateDirectory(marker)) ? 0 : MC_ERROR;
}

static s32 execute(const Request *request)
{
    switch (request->command) {
    case MC_CLOSE:
        if (!card.file || request->value != MC_FILE) return MC_ERROR;
        close_file(true);
        return card.write_failed ? MC_ERROR : 0;
    case MC_READ:
        if (!card.file || request->port != MC_FILE || card.temporary) return MC_ERROR;
        return (s32)SDL_ReadIO(card.file, request->buffer, (size_t)request->value);
    case MC_WRITE:
        if (!card.file || request->port != MC_FILE || !card.temporary) return MC_ERROR;
        if (SDL_WriteIO(card.file, request->buffer, (size_t)request->value) == (size_t)request->value) {
            return request->value;
        }
        card.write_failed = true;
        return MC_ERROR;
    default:
        break;
    }

    if (request->port < 0 || request->port > 1 || request->slot != 0) return -1;
    char *root = make_path(card.root, request->port == 0 ? "/card1" : "/card2");
    char *marker = root ? make_path(root, ".unformatted") : NULL;
    char *path = root && request->path ? make_path(root, request->path) : NULL;
    s32 result = MC_ERROR;
    if (!marker || (request->path && !path)) goto done;
    bool formatted = !get_info(marker, NULL);
    if (request->command == MC_INFO) {
        if (request->type) *request->type = 2;
        if (request->free_blocks) *request->free_blocks = 8192;
        if (request->formatted) *request->formatted = formatted;
        result = 0;
    } else if (request->command == MC_FORMAT || request->command == MC_UNFORMAT) {
        result = reset_card(root, marker, request->command == MC_FORMAT);
    } else if (!formatted) {
        result = MC_UNFORMATTED;
    } else if (request->command == MC_DIR) {
        result = read_directory(path, request);
    } else if (request->command == MC_MKDIR) {
        result = SDL_CreateDirectory(path) ? 0 : MC_ERROR;
    } else if (request->command == MC_OPEN) {
        result = open_file(path, request->value);
    }
done:
    SDL_free(path);
    SDL_free(marker);
    SDL_free(root);
    return result;
}

static int SDLCALL card_worker(void *unused)
{
    (void)unused;
    SDL_LockMutex(card.mutex);
    while (!card.stopping) {
        if (!card.busy || card.ready) {
            SDL_WaitCondition(card.changed, card.mutex);
            continue;
        }
        Request request = card.request;
        SDL_UnlockMutex(card.mutex);
        s32 result = execute(&request);
        SDL_LockMutex(card.mutex);
        card.result = result;
        card.ready = true;
        SDL_BroadcastCondition(card.changed);
    }
    SDL_UnlockMutex(card.mutex);
    return 0;
}

void pc_mc_close_storage(void)
{
    if (card.worker) {
        SDL_LockMutex(card.mutex);
        card.stopping = true;
        SDL_BroadcastCondition(card.changed);
        SDL_UnlockMutex(card.mutex);
        SDL_WaitThread(card.worker, NULL);
    }
    close_file(false);
    SDL_DestroyCondition(card.changed);
    SDL_DestroyMutex(card.mutex);
    SDL_free(card.root);
    SDL_zero(card);
}

bool pc_mc_open_storage(const char *root)
{
    if (card.worker || !root || !SDL_CreateDirectory(root)) return false;
    card.root = SDL_strdup(root);
    card.mutex = SDL_CreateMutex();
    card.changed = SDL_CreateCondition();
    if (card.root && card.mutex && card.changed) {
        card.worker = SDL_CreateThread(card_worker, "DaiOuJou card", NULL);
    }
    if (card.worker) return true;
    pc_mc_close_storage();
    return false;
}

s32 sceMcInit(void)
{
    if (card.worker) return 0;
    char *prefix = SDL_GetPrefPath("DaiOuJou", "DaiOuJou");
    char *root = prefix ? make_path(prefix, "cards") : NULL;
    bool opened = root && pc_mc_open_storage(root);
    SDL_free(root);
    SDL_free(prefix);
    return opened ? 0 : MC_ERROR;
}

static s32 submit(Request request)
{
    if (!card.worker) return MC_ERROR;
    SDL_LockMutex(card.mutex);
    if (card.busy) {
        SDL_UnlockMutex(card.mutex);
        return MC_ERROR;
    }
    card.request = request;
    card.busy = true;
    SDL_SignalCondition(card.changed);
    SDL_UnlockMutex(card.mutex);
    return 0;
}

s32 sceMcSync(s32 mode, s32 reserved, s32 *result)
{
    (void)reserved;
    if (!card.worker) return -1;
    SDL_LockMutex(card.mutex);
    while (card.busy && !card.ready && mode == 0) {
        SDL_WaitCondition(card.changed, card.mutex);
    }
    s32 status = card.busy ? 0 : -1;
    if (card.ready) {
        if (result) *result = card.result;
        card.busy = false;
        card.ready = false;
        status = 1;
    }
    SDL_UnlockMutex(card.mutex);
    return status;
}

s32 sceMcGetInfo(s32 port, s32 slot, s32 *type, s32 *free_blocks, s32 *formatted)
{
    return submit((Request){MC_INFO, port, slot, .type = type, .free_blocks = free_blocks,
                              .formatted = formatted});
}

s32 sceMcGetDir(s32 port, s32 slot, char *path, s32 mode, s32 count, void *entries)
{
    if (mode != 0 || count < 1 || count > 99 || !entries || !card_path_valid(path, true)) return MC_ERROR;
    return submit((Request){MC_DIR, port, slot, path, count, entries});
}

s32 sceMcMkdir(s32 port, s32 slot, char *path)
{
    return card_path_valid(path, false) ? submit((Request){MC_MKDIR, port, slot, path}) : MC_ERROR;
}

s32 sceMcOpen(s32 port, s32 slot, char *path, s32 flags)
{
    return card_path_valid(path, false) ? submit((Request){MC_OPEN, port, slot, path, flags}) : MC_ERROR;
}

s32 sceMcClose(s32 fd)
{
    return submit((Request){.command = MC_CLOSE, .value = fd});
}

s32 sceMcRead(s32 fd, void *buffer, s32 size)
{
    return size >= 0 && buffer ? submit((Request){.command = MC_READ, .port = fd,
                                                  .value = size, .buffer = buffer}) : MC_ERROR;
}

s32 sceMcWrite(s32 fd, void *buffer, s32 size)
{
    return size >= 0 && buffer ? submit((Request){.command = MC_WRITE, .port = fd,
                                                  .value = size, .buffer = buffer}) : MC_ERROR;
}

s32 sceMcFormat(s32 port, s32 slot)
{
    return submit((Request){MC_FORMAT, port, slot});
}

s32 sceMcUnformat(s32 port, s32 slot)
{
    return submit((Request){MC_UNFORMAT, port, slot});
}
