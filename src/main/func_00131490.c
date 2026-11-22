#include "common.h"

s32 func_00131460();                            /* extern */
s32 func_0020ECE0();                            /* extern */
s32 func_00236D50();                            /* extern */
extern s16 D_0028E3B4;
extern s16 D_0028E3B8;
extern s16 D_0028E3BC;
extern s16 D_0028E3C0;
extern s16 D_0028E3C4;
extern s16 D_0028E3CC;
extern s16 D_0028E3D0;
extern s16 D_0028E3D4;
extern s16 D_0028E3DC;
extern s16 D_0028E3E0;
extern s16 D_0028E3E4;
extern s16 D_0028E3E8;
extern s16 D_0028E3EC;
extern s16 D_0028E3F0;
extern s8 D_0028ED7C;
extern s8 D_0028ED80;

void func_00131490(void) {
    D_0028E3C4 = 0;
    D_0028E3F0 = 0;
    D_0028E3EC = 0;
    D_0028E3E8 = 0;
    D_0028E3E4 = 0;
    D_0028E3E0 = 0;
    D_0028E3DC = 0;
    rng_cursor = 0;
    D_0028E3D4 = 0;
    D_0028E3B4 = 0;
    func_0020ECE0();
    D_0028E3D0 = 0;
    D_0028E3CC = 0;
    D_0028ED80 = 0;
    D_0028ED7C = 0;
    func_00236D50();
    D_0028E3C0 = 0;
    D_0028E3BC = 0;
    D_0028E3B8 = 0;
    func_00131460();
}
