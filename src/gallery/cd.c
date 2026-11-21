#include "gallery/gallery.h"

extern const char D_0012ADB8[];
extern const char D_0012ADC8[];
extern const char D_0012ADD8[];
extern const char D_0012ADE8[];
extern s8 D_0012B2F0;
extern s8 D_0012B2F4;
extern u32 D_0012B2F8;
extern s8 D_0012B2FC;
extern u32 D_0012B304;
extern u32 D_001328C0[3];
extern u32 D_001328C4[3];

void cd_search_file(const char *value)
{
    s32 result;
    u32 retry;

    do {
        sceCdDiskReady(0);
        result = sceCdSearchFile(D_001328C0, value);
        retry = (u32)(result != 0);
        retry ^= 1;
    } while (retry != 0);
}

void cd_read_sync(void *destination, u32 byteCount, u32 startSector)
{
    sceCdRMode readMode;
    s32 error;

    D_001328C4[0] = byteCount;
    D_001328C0[0] = startSector;

    for (;;) {
        do {
            sceCdDiskReady(0);
            D_0012B304 = D_001328C4[0];
            readMode.trycount = 0;
            readMode.spindlctrl = 1;
            readMode.datapattern = 0;
        } while (!sceCdRead(D_001328C0[0], (D_001328C4[0] + 0x7FF) >> 11,
                                destination, &readMode));

        sceCdSync(0);
        error = sceCdGetError();
        if (error == 0) {
            break;
        }

        printf(D_0012ADB8, error);
        sceCdBreak();
    }
}

void cd_read_async(void *destination, s32 byteCount, u32 startSector)
{
    sceCdRMode readMode;
    s32 readError;

    switch (D_0012B2F0) {
    case 0:
        D_0012B2F4 = 1;
        D_0012B304 = 0;
        D_0012B2F0++;
        D_0012B2FC = 0;
        break;

    case 1:
        if (sceCdDiskReady(1) == 2) {
            D_0012B2F0++;
        } else {
            D_0012B2FC++;
            if (D_0012B2FC > 60) {
                sceCdBreak();
                D_0012B2FC = 0;
                printf(D_0012ADC8);
            }
        }
        break;

    case 2:
        D_0012B304 = byteCount;
        readMode.trycount = 0;
        readMode.spindlctrl = 1;
        readMode.datapattern = 0;
        if (sceCdRead(startSector, (byteCount + 2047) / 2048, destination, &readMode) != 0) {
            D_0012B2F0++;
        }
        break;

    case 3:
        if (sceCdSync(1) == 0) {
            readError = sceCdGetError();
            if (readError != 0) {
                printf(D_0012ADD8, (u32)readError);
                D_0012B2FC = 0;
                D_0012B2F0 = 1;
                sceCdBreak();
            } else {
                u32 totalBytesRead = *(const volatile u32 *)&D_0012B2F8;
                s32 completedByteCount = *(const volatile s32 *)&D_0012B304;

                D_0012B2F4 = 0;
                D_0012B2F0 = 0;
                D_0012B2F8 = totalBytesRead + completedByteCount;
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
    } while (!sceCdSearchFile(D_001328C0, path));

    for (;;) {
        do {
            sceCdDiskReady(0);
            D_0012B304 = D_001328C4[0];
            readMode.trycount = 0;
            readMode.spindlctrl = 1;
            readMode.datapattern = 0;
        } while (!sceCdRead(D_001328C0[0], (D_001328C4[0] + 0x7FF) >> 11,
                                destination, &readMode));

        sceCdSync(0);
        error = sceCdGetError();
        if (error == 0) {
            break;
        }

        printf(D_0012ADE8, error);
        sceCdBreak();
    }
}
