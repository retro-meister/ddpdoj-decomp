#include "common.h"

s32 sceSifInitRpc(s32);                     /* extern */
s32 sceFsReset();                            /* extern */
s32 sceSifRebootIop(s32 *);                       /* extern */
s32 sceCdInit(s32);                     /* extern */
s32 sceCdDiskReady(s32);                     /* extern */
s32 sceCdMmode(s32);                     /* extern */
s32 printf(s32 *);                          /* extern */
s32 sceSifLoadModule(s32 *, s32, s32);  /* extern */
s32 sceSifSyncIop();                                /* extern */
extern s32 D_00286F20[];
extern s32 D_00286F40[];
extern s32 D_00286F60[];
extern s32 D_00286F80[];
extern s32 D_00286FA0[];
extern s32 D_00286FC0[];
extern s32 D_00286FE0[];
extern s32 D_00287000[];
extern s32 D_00287020[];

void func_00216250(void) {
    sceSifInitRpc(0);
    sceCdInit(0);
    sceCdMmode(2);
    do {

    } while (sceSifRebootIop(D_00286F20) == 0);
    do {

    } while (sceSifSyncIop() == 0);
    sceSifInitRpc(0);
    sceCdInit(0);
    sceCdMmode(2);
    sceFsReset();
    sceCdDiskReady(0);
    printf(D_00286F40);
    do {

    } while (sceSifLoadModule(D_00286F60, 0, 0) < 0);
    do {

    } while (sceSifLoadModule(D_00286F80, 0, 0) < 0);
    do {

    } while (sceSifLoadModule(D_00286FA0, 0, 0) < 0);
    do {

    } while (sceSifLoadModule(D_00286FC0, 0, 0) < 0);
    do {

    } while (sceSifLoadModule(D_00286FE0, 0, 0) < 0);
    do {

    } while (sceSifLoadModule(D_00287000, 0, 0) < 0);
    printf(D_00287020);
}
