#include "common.h"

extern s32 func_0018C600(s32, s32, s32);
extern void func_0018C8D0(s32);
s32 printf();
extern u8 D_00277F98[];
extern u8 D_0028DF98_as_u8;
extern u8 D_0028E364;
extern u16 D_0028E3C0;
extern s32 D_0029CA18_as_s32_a[];
extern s32 D_0029CA1C_as_s32_a[];
extern s32 D_0029CA20_as_s32_a[];
extern u8 D_0029CBF0[];
extern u8 D_0029CBF4[];

void func_0018DEF0(s32 arg0, s32 arg1) {
    if (D_0028E3C0 != 0) return;
    D_0028E364 = 0x46;
    D_0029CA18_as_s32_a[0] = 0;
    func_0018C600(0x100, 1, 0);
    func_0018C8D0(0);
    func_0018C600(0x200, 0, 0);
    printf(D_00277F98);
    func_0018C600(0x8000, 0x30000, 0);
    if (arg1 != 0) {
        func_0018C600(0x80C0, 2, 0);
    } else {
        func_0018C600(0x80C0, 0, 0);
    }
    func_0018C600(0x160, *(s32 *)(D_0029CBF0 + arg0 * 8), *(s32 *)(D_0029CBF4 + arg0 * 8));
    D_0029CA1C_as_s32_a[0] = 0x64;
    D_0029CA20_as_s32_a[0] = D_0029CA1C_as_s32_a[0];
    func_0018C600(0x80, 0x7FFF7FFF, 0);
    func_0018C600(0x140, 0, 0);
    D_0028DF98_as_u8 = 1;
}
