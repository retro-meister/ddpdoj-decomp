#include "common.h"

typedef struct {
    u8 retryCount;
    u8 spindleControl;
    u8 dataPattern;
    u8 padding;
} CdReadMode;

extern const char D_0012ADC8[];
extern const char D_0012ADD8[];
extern s8 D_0012B2F0;
extern s8 D_0012B2F4;
extern u32 D_0012B2F8;
extern s8 D_0012B2FC;
extern s32 D_0012B304;

extern s32 func_0010DF08(s32 mode);
extern s32 func_0010E468(s32 mode);
extern s32 func_0010E720(u32 startSector, u32 sectorCount, void *destination, CdReadMode *readMode);
extern s32 func_0010E900(void);
extern s32 func_0010E998(void);
extern void func_00118268(const char *format, ...);

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
