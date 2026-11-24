#include "common.h"

typedef struct {
    u8 trycount;
    u8 spindlctrl;
    u8 datapattern;
    u8 pad;
} CdReadMode;

s32 func_0010E008(s32 mode);
s32 func_0010E568(s32 mode);
s32 func_0010E820(u32 sector, u32 count, void *destination, CdReadMode *mode);
s32 func_0010EA00(void);
s32 func_0010EA98(void);
s32 printf(const char *format, ...);
extern char D_00286F08[];
extern u32 D_0028E9CC;
typedef struct {
    u32 lsn;
    u32 size;
    char name[16];
    u8 date[8];
} CdFile;

extern CdFile D_002C0100;

void func_00216160(void *destination, u32 byteCount, u32 startSector)
{
    CdReadMode readMode;
    s32 error;

    D_002C0100.size = byteCount;
    D_002C0100.lsn = startSector;

    for (;;) {
        do {
            func_0010E568(0);
            D_0028E9CC = D_002C0100.size;
            readMode.trycount = 0;
            readMode.spindlctrl = 1;
            readMode.datapattern = 0;
        } while (!func_0010E820(D_002C0100.lsn, (D_002C0100.size + 0x7FF) >> 11, destination, &readMode));

        func_0010E008(0);
        error = func_0010EA00();
        if (error == 0) {
            break;
        }

        printf(D_00286F08, error);
        func_0010EA98();
    }
}
