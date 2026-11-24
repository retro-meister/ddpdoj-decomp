#include "common.h"

s32 func_001058E8(s32);                     /* extern */
s32 func_00107208();                            /* extern */
s32 func_0010AEF8(s32 *);                       /* extern */
s32 func_0010E288(s32);                     /* extern */
s32 func_0010E568(s32);                     /* extern */
s32 func_0010E750(s32);                     /* extern */
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
    func_001058E8(0);
    func_0010E288(0);
    func_0010E750(2);
    do {

    } while (func_0010AEF8(D_00286F20) == 0);
    do {

    } while (sceSifSyncIop() == 0);
    func_001058E8(0);
    func_0010E288(0);
    func_0010E750(2);
    func_00107208();
    func_0010E568(0);
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
