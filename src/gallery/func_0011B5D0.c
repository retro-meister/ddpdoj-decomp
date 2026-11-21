#include "common.h"

typedef struct {
    u8 retryCount;
    u8 spindleControl;
    u8 dataPattern;
    u8 padding;
} CdReadMode;

extern const char D_0012ADB8[];
extern u32 D_0012B304;
extern u32 D_001328C0[3];
extern u32 D_001328C4[3];

extern s32 func_0010DF08(s32 mode);
extern s32 func_0010E468(s32 mode);
extern s32 func_0010E720(u32 startSector, u32 sectorCount, void *destination, CdReadMode *readMode);
extern s32 func_0010E900(void);
extern void func_0010E998(void);
extern s32 func_00118268(const char *format, ...);

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
