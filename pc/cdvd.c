#include "cdvd.h"
#include "disc_image.h"
#include "sdk/libcdvd.h"

#include <SDL3/SDL_mutex.h>
#include <SDL3/SDL_thread.h>
#include <SDL3/SDL_time.h>

static u8 clock_bcd(int value)
{
    return (u8)(((value / 10) << 4) | (value % 10));
}

s32 sceCdReadClock(sceCdCLOCK *clock)
{
    SDL_Time now;
    SDL_DateTime date;
    if (!SDL_GetCurrentTime(&now) || !SDL_TimeToDateTime(now, &date, true)) {
        *clock = (sceCdCLOCK){.stat = 1};
        return 0;
    }
    *clock = (sceCdCLOCK){
        .second = clock_bcd(date.second),
        .minute = clock_bcd(date.minute),
        .hour = clock_bcd(date.hour),
        .day = clock_bcd(date.day),
        .month = clock_bcd(date.month),
        .year = clock_bcd(date.year % 100),
    };
    return 1;
}

typedef struct {
    uint64_t offset;
    size_t size;
    void *destination;
} SectorRead;

typedef struct {
    DiscImage *image;
    SDL_Mutex *mutex;
    SDL_Condition *changed;
    SDL_Thread *thread;
    SectorRead request;
    bool busy;
    bool stopping;
    s32 error;
} CdDrive;

static CdDrive drive;

static int read_sectors(void *data) {
    CdDrive *cd = data;
    SDL_LockMutex(cd->mutex);
    while (!cd->stopping) {
        if (!cd->busy) {
            SDL_WaitCondition(cd->changed, cd->mutex);
            continue;
        }
        SectorRead request = cd->request;
        SDL_UnlockMutex(cd->mutex);
        bool read = disc_image_read(cd->image, request.offset, request.destination, request.size);
        SDL_LockMutex(cd->mutex);
        cd->error = read ? 0 : 1;
        cd->busy = false;
        SDL_BroadcastCondition(cd->changed);
    }
    SDL_UnlockMutex(cd->mutex);
    return 0;
}

bool pc_cdvd_mount(const char *iso_path) {
    if (drive.image) {
        return false;
    }
    drive.image = disc_image_open(iso_path);
    if (!drive.image) {
        return false;
    }
    drive.mutex = SDL_CreateMutex();
    drive.changed = SDL_CreateCondition();
    if (drive.mutex && drive.changed) {
        drive.thread = SDL_CreateThread(read_sectors, "DaiOuJou disc", &drive);
    }
    if (!drive.thread) {
        pc_cdvd_unmount();
        return false;
    }
    return true;
}

void pc_cdvd_unmount(void) {
    if (drive.thread) {
        SDL_LockMutex(drive.mutex);
        drive.stopping = true;
        SDL_BroadcastCondition(drive.changed);
        SDL_UnlockMutex(drive.mutex);
        SDL_WaitThread(drive.thread, NULL);
    }
    SDL_DestroyCondition(drive.changed);
    SDL_DestroyMutex(drive.mutex);
    disc_image_close(drive.image);
    drive = (CdDrive){0};
}

s32 sceCdSearchFile(sceCdlFILE *file, const char *name) {
    DiscExtent extent;
    if (!drive.image || !disc_image_find(drive.image, name, &extent)) {
        return 0;
    }
    *file = (sceCdlFILE){.lsn = extent.lba, .size = extent.size};
    return 1;
}

s32 sceCdInit(s32 init_mode) {
    return init_mode == SCECdINIT && drive.image != NULL;
}

s32 sceCdMmode(s32 media) {
    return media == 2 && drive.image != NULL;
}

s32 sceCdSync(s32 mode) {
    if (!drive.thread) {
        return 0;
    }
    SDL_LockMutex(drive.mutex);
    while (mode == 0 && drive.busy) {
        SDL_WaitCondition(drive.changed, drive.mutex);
    }
    bool busy = drive.busy;
    SDL_UnlockMutex(drive.mutex);
    return busy;
}

s32 sceCdDiskReady(s32 mode) {
    return drive.image && !sceCdSync(mode) ? SCECdComplete : 0;
}

s32 sceCdRead(u32 lbn, u32 sectors, void *buffer, sceCdRMode *mode) {
    uint64_t size = (uint64_t)sectors * DISC_SECTOR_SIZE;
    if (!drive.thread || !mode || mode->datapattern != SCECdSecS2048 ||
        size > SIZE_MAX || (size != 0 && !buffer)) {
        return 0;
    }
    SDL_LockMutex(drive.mutex);
    if (drive.busy) {
        SDL_UnlockMutex(drive.mutex);
        return 0;
    }
    drive.request = (SectorRead){
        .offset = (uint64_t)lbn * DISC_SECTOR_SIZE,
        .size = (size_t)size,
        .destination = buffer,
    };
    drive.error = 0;
    drive.busy = true;
    SDL_SignalCondition(drive.changed);
    SDL_UnlockMutex(drive.mutex);
    return 1;
}

s32 sceCdGetError(void) {
    if (!drive.thread) {
        return 1;
    }
    SDL_LockMutex(drive.mutex);
    s32 error = drive.error;
    SDL_UnlockMutex(drive.mutex);
    return error;
}

void sceCdBreak(void) {
    /* The caller can reuse the destination as soon as this returns. */
    sceCdSync(0);
}
