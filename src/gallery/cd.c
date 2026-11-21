#include "common.h"

typedef struct {
    u8 retryCount;
    u8 spindleControl;
    u8 dataPattern;
    u8 padding;
} CdReadMode;

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

extern s32 func_0010DCE0(void *fileInfo, const char *path);
extern s32 func_0010DF08(s32 mode);
extern s32 func_0010E468(s32 mode);
extern s32 func_0010E720(u32 startSector, u32 sectorCount, void *destination, CdReadMode *readMode);
extern s32 func_0010E900(void);
extern void func_0010E998(void);
extern s32 func_00118268(const char *format, ...);

void func_0011B580(const char *value)
{
    s32 result;
    u32 retry;

    do {
        func_0010E468(0);
        result = func_0010DCE0(D_001328C0, value);
        retry = (u32)(result != 0);
        retry ^= 1;
    } while (retry != 0);
}

void func_0011B5D0(void *destination, u32 byteCount, u32 startSector)
{
    CdReadMode readMode;
    s32 error;

    D_001328C4[0] = byteCount;
    D_001328C0[0] = startSector;

    for (;;) {
        do {
            func_0010E468(0);
            D_0012B304 = D_001328C4[0];
            readMode.retryCount = 0;
            readMode.spindleControl = 1;
            readMode.dataPattern = 0;
        } while (!func_0010E720(D_001328C0[0], (D_001328C4[0] + 0x7FF) >> 11,
                                destination, &readMode));

        func_0010DF08(0);
        error = func_0010E900();
        if (error == 0) {
            break;
        }

        func_00118268(D_0012ADB8, error);
        func_0010E998();
    }
}

void func_0011B6B0(void *destination, s32 byteCount, u32 startSector)
{
    CdReadMode readMode;
    s32 readError;

    switch (D_0012B2F0) {
    case 0:
        D_0012B2F4 = 1;
        D_0012B304 = 0;
        D_0012B2F0++;
        D_0012B2FC = 0;
        break;

    case 1:
        if (func_0010E468(1) == 2) {
            D_0012B2F0++;
        } else {
            D_0012B2FC++;
            if (D_0012B2FC > 60) {
                func_0010E998();
                D_0012B2FC = 0;
                func_00118268(D_0012ADC8);
            }
        }
        break;

    case 2:
        D_0012B304 = byteCount;
        readMode.retryCount = 0;
        readMode.spindleControl = 1;
        readMode.dataPattern = 0;
        if (func_0010E720(startSector, (byteCount + 2047) / 2048, destination, &readMode) != 0) {
            D_0012B2F0++;
        }
        break;

    case 3:
        if (func_0010DF08(1) == 0) {
            readError = func_0010E900();
            if (readError != 0) {
                func_00118268(D_0012ADD8, (u32)readError);
                D_0012B2FC = 0;
                D_0012B2F0 = 1;
                func_0010E998();
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

void func_0011B830(void *destination, const char *path)
{
    CdReadMode readMode;
    s32 error;

    do {
        func_0010E468(0);
    } while (!func_0010DCE0(D_001328C0, path));

    for (;;) {
        do {
            func_0010E468(0);
            D_0012B304 = D_001328C4[0];
            readMode.retryCount = 0;
            readMode.spindleControl = 1;
            readMode.dataPattern = 0;
        } while (!func_0010E720(D_001328C0[0], (D_001328C4[0] + 0x7FF) >> 11,
                                destination, &readMode));

        func_0010DF08(0);
        error = func_0010E900();
        if (error == 0) {
            break;
        }

        func_00118268(D_0012ADE8, error);
        func_0010E998();
    }
}
