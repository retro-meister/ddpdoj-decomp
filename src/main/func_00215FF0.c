#include "common.h"

typedef struct {
    u8 trycount;
    u8 spindlctrl;
    u8 datapattern;
} CdReadMode;

s32 func_0010E008(s32 mode);
s32 func_0010E568(s32 mode);
s32 func_0010E820(u32 sector, u32 count, void *destination, CdReadMode *mode);
s32 func_0010EA00(void);
s32 func_0010EA98(void);
s32 printf(const char *format, ...);
extern char D_00286EE8[];
extern char D_00286EF8[];
extern s8 D_0028E9B8;
extern s8 D_0028E9BC;
extern u32 D_0028E9C0;
extern s8 D_0028E9C4;
extern u32 D_0028E9CC;

void func_00215FF0(void *destination, s32 byteCount, u32 startSector)
{
    CdReadMode readMode;
    s32 readError;

    switch (D_0028E9B8) {
    case 0:
        D_0028E9BC = 1;
        D_0028E9CC = 0;
        D_0028E9B8++;
        D_0028E9C4 = 0;
        break;

    case 1:
        if (func_0010E568(1) == 2) {
            D_0028E9B8++;
        } else {
            D_0028E9C4++;
            if (D_0028E9C4 > 60) {
                func_0010EA98();
                D_0028E9C4 = 0;
                printf(D_00286EE8);
            }
        }
        break;

    case 2:
        D_0028E9CC = byteCount;
        readMode.trycount = 0;
        readMode.spindlctrl = 1;
        readMode.datapattern = 0;
        if (func_0010E820(startSector, (byteCount + 2047) / 2048, destination, &readMode) != 0) {
            D_0028E9B8++;
        }
        break;

    case 3:
        if (func_0010E008(1) == 0) {
            readError = func_0010EA00();
            if (readError != 0) {
                printf(D_00286EF8, (u32)readError);
                D_0028E9C4 = 0;
                D_0028E9B8 = 1;
                func_0010EA98();
            } else {
                D_0028E9BC = 0;
                D_0028E9B8 = 0;
                D_0028E9C0 += D_0028E9CC;
            }
        }
        break;
    }
}
