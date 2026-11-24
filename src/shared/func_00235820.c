#include "common.h"

extern void func_0021B570(s8, s8);
extern void func_0021B840(s32, s32);
extern s32 D_00271C60[];
extern s32 D_00271C64[];
extern s8 D_0028E250;
extern s8 D_0028E254;
extern u16 D_0028E32C;
extern s8 D_0028E9EC;

void func_00235820(void)
{
    u16 selection;

    D_0028E9EC = 1;
    func_0021B570(D_0028E254, D_0028E250);

    selection = D_0028E32C;
    if (selection != 5) {
        s32 tableIndex = (selection & 0xFFFF) * 2;

        func_0021B840(D_00271C60[tableIndex], D_00271C64[tableIndex]);
    }
}
