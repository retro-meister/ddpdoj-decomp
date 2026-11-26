#include "sdk/libc.h"
#include "sdk/libcdvd.h"

extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern u32 g_cd_total_bytes_read;
extern s8 g_cd_retry_timer;
extern u32 g_cd_last_read_size;
extern sceCdlFILE g_cd_file;

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
        } while (!sceCdRead(g_cd_file.lsn, (g_cd_file.size + 0x7FF) >> 11, destination, &readMode));

        sceCdSync(0);
        error = sceCdGetError();
        if (error == 0) {
            break;
        }

        printf("cd1 err[%x]\n", error);
        sceCdBreak();
    }
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
                printf("cd3 err[%x]\n", (u32)readError);
                g_cd_retry_timer = 0;
                g_cd_async_state = 1;
                sceCdBreak();
            } else {
                g_cd_async_busy = 0;
                g_cd_async_state = 0;
                g_cd_total_bytes_read += g_cd_last_read_size;
            }
        }
        break;
    }
}

void cd_read_sync(void *destination, u32 byteCount, u32 startSector)
{
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
        } while (!sceCdRead(g_cd_file.lsn, (g_cd_file.size + 0x7FF) >> 11, destination, &readMode));

        sceCdSync(0);
        error = sceCdGetError();
        if (error == 0) {
            break;
        }

        printf("cd4 err[%x]\n", error);
        sceCdBreak();
    }
}

void cd_search_file(const char *path)
{
    do {
        sceCdDiskReady(0);
    } while (sceCdSearchFile(&g_cd_file, path) == 0);
}

#ifdef DDPDOJ_PC
u32 g_cd_last_read_size;
s8 g_cd_retry_timer;
u32 g_cd_total_bytes_read;
s8 g_cd_async_busy;
s8 g_cd_async_state;
sceCdlFILE g_cd_file;
#endif
