#include "common.h"

extern void func_0011B830(void *destination, const char *path);
extern u32 D_0012B304;
extern u32 D_0012B388;
extern u32 D_0012B38C;
extern u32 D_0012B390;
extern u32 D_0012B394;
extern u32 D_0012B398;
extern u32 D_0012B39C;
extern u32 D_0012B3A0;
extern u32 D_0012B3A4;
extern u32 D_0012B3A8;
extern u32 D_0012B3AC;
extern u32 D_0012B3B0;
extern u32 D_0012B3B4;
extern u32 D_0012B3B8;
extern u32 D_0012B3BC;
extern u32 D_0012B3C0;
extern u32 D_0012B3C4;
extern u32 D_0012B3C8;
extern u32 D_0012B3CC;
extern u32 D_0012B3D0;
extern u32 D_0012B3D4;
extern u8 D_001B7AB0[];
extern u8 D_001AF2B0[];
extern const char D_001290E0[];
extern const char D_00129100[];

void func_0011EDF0(void) {
    func_0011B830(D_001B7AB0, D_001290E0);
    D_0012B3D0 = D_0012B304;
    func_0011B830(D_001AF2B0, D_00129100);

    *(u8 *)&D_0012B3D4 = 0;
    *(u8 *)&D_0012B3A8 = 1;
    *(u8 *)&D_0012B3A4 = 0;
    *(u8 *)&D_0012B3AC = 0;
    *(u8 *)&D_0012B39C = 0;
    *(u8 *)&D_0012B3A0 = 0;
    *(u8 *)&D_0012B3B0 = 0;
    *(u8 *)&D_0012B398 = 0;
    D_0012B390 = 0;
    D_0012B38C = 0;
    D_0012B388 = 0;
    D_0012B3BC = 0;
    D_0012B3C8 = 0;
    D_0012B3C4 = 0;
    D_0012B3C0 = 0;
    D_0012B3B8 = 0;
    D_0012B3B4 = 0;
    *(u8 *)&D_0012B394 = 0;
    D_0012B3CC = D_0012B304;
}
