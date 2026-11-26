#include "gallery/gallery.h"

#ifdef DDPDOJ_PC
s32 g_cd_io_error;
#endif

void cd_search_file(const char *value)
{
    s32 result;
    u32 retry;

    do {
        sceCdDiskReady(0);
        result = sceCdSearchFile(&g_cd_file, value);
        retry = (u32)(result != 0);
        retry ^= 1;
    } while (retry != 0);
}

void cd_read_sync(void *destination, u32 byteCount, u32 startSector)
{
#ifdef DDPDOJ_PC
    sceCdRMode mode = { 0, SCECdSpinNom, SCECdSecS2048, 0 };
    g_cd_file.size = byteCount;
    g_cd_file.lsn = startSector;
    g_cd_last_read_size = byteCount;
    if (!sceCdRead(startSector, (byteCount + 0x7FF) >> 11, destination, &mode) ||
        sceCdSync(0) != 0 || sceCdGetError() != 0) {
        g_cd_io_error = 1;
    }
#else
    sceCdRMode readMode;
    s32 error;

    g_cd_file.size = byteCount;
    g_cd_file.lsn = startSector;

    for (;;) {
        do {
            sceCdDiskReady(0);
            g_cd_last_read_size = g_cd_file.size;
            readMode.trycount = 0;
            readMode.spindlctrl = SCECdSpinNom;
            readMode.datapattern = SCECdSecS2048;
        } while (!sceCdRead(g_cd_file.lsn, (g_cd_file.size + 0x7FF) >> 11,
                                destination, &readMode));

        sceCdSync(0);
        error = sceCdGetError();
        if (error == 0) {
            break;
        }

        printf("cd4 err[%x]\n", error);
        sceCdBreak();
    }
#endif
}

void cd_read_async(void *destination, s32 byteCount, u32 startSector)
{
    sceCdRMode readMode;
    s32 readError;

    switch (g_cd_async_state) {
    case 0:
        g_cd_async_busy = 1;
        g_cd_last_read_size = 0;
        g_cd_async_state++;
        g_cd_retry_timer = 0;
        break;

    case 1:
        if (sceCdDiskReady(1) == SCECdComplete) {
            g_cd_async_state++;
        } else {
            g_cd_retry_timer++;
            if (g_cd_retry_timer > 60) {
                sceCdBreak();
                g_cd_retry_timer = 0;
                printf("err cd break\n");
            }
        }
        break;

    case 2:
#ifdef DDPDOJ_PC
        if (byteCount <= 0 || (u32)byteCount >
            (destination == g_vram_load_buf ? 0x300000 : sizeof(((GalleryContext *)0)->readBuf))) {
            g_cd_io_error = 1;
            break;
        }
#endif
        g_cd_last_read_size = byteCount;
        readMode.trycount = 0;
        readMode.spindlctrl = SCECdSpinNom;
        readMode.datapattern = SCECdSecS2048;
        if (sceCdRead(startSector, (byteCount + 2047) / 2048, destination, &readMode) != 0) {
            g_cd_async_state++;
        }
        break;

    case 3:
        if (sceCdSync(1) == 0) {
            readError = sceCdGetError();
            if (readError != 0) {
#ifdef DDPDOJ_PC
                g_cd_io_error = 1;
#else
                printf("cd3 err[%x]\n", (u32)readError);
                g_cd_retry_timer = 0;
                g_cd_async_state = 1;
                sceCdBreak();
#endif
            } else {
                u32 totalBytesRead = *(const volatile u32 *)&g_cd_total_bytes_read;
                s32 completedByteCount = *(const volatile s32 *)&g_cd_last_read_size;

                g_cd_async_busy = 0;
                g_cd_async_state = 0;
                g_cd_total_bytes_read = totalBytesRead + completedByteCount;
            }
        }
        break;
    }
}

void cd_load_file(void *destination, const char *path)
{
    sceCdRMode readMode;
    s32 error;

    do {
        sceCdDiskReady(0);
    } while (!sceCdSearchFile(&g_cd_file, path));

    for (;;) {
        do {
            sceCdDiskReady(0);
            g_cd_last_read_size = g_cd_file.size;
            readMode.trycount = 0;
            readMode.spindlctrl = SCECdSpinNom;
            readMode.datapattern = SCECdSecS2048;
        } while (!sceCdRead(g_cd_file.lsn, (g_cd_file.size + 0x7FF) >> 11,
                                destination, &readMode));

        sceCdSync(0);
        error = sceCdGetError();
        if (error == 0) {
            break;
        }

        printf("cd1 err[%x]\n", error);
        sceCdBreak();
    }
}

u32 g_cd_last_read_size;
void *g_vram_load_buf;
s8 g_cd_retry_timer __attribute__((aligned(4)));
u32 g_cd_total_bytes_read;
s8 g_cd_async_busy __attribute__((aligned(4)));
s8 g_cd_async_state __attribute__((aligned(4)));

sceCdlFILE g_cd_file __attribute__((aligned(64)));
