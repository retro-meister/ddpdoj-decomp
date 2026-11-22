#include "common.h"

s32 printf();
extern u8 D_0028BDB0[];
extern u8 D_0028BDD0[];
extern u8 D_0028BDF0[];
extern u8 D_0028BE00[];
extern u8 D_0028BE10[];
extern u8 D_0028BE20[];
extern u8 D_0028BE30[];
extern u8 D_0028BE40[];
extern u8 D_0028BE50[];
extern u8 D_0028BE70[];
extern u8 D_0028BE80[];
extern u8 D_0028BE90[];
extern u8 D_0028BEA0[];
void func_00236C50(u8 *arg0) {
    printf(D_0028BDB0, (*(u16 *)((u8 *)(arg0) + (2))), (*(u16 *)((u8 *)(arg0) + (4))));
    printf(D_0028BDD0, (*(u16 *)((u8 *)(arg0) + (6))), (*(u16 *)((u8 *)(arg0) + (8))));
    printf(D_0028BDF0, (*(u16 *)((u8 *)(arg0) + (0xA))));
    printf(D_0028BE00, (*(u16 *)((u8 *)(arg0) + (0xC))));
    printf(D_0028BE10, (*(u16 *)((u8 *)(arg0) + (0xE))));
    printf(D_0028BE20, (*(u16 *)((u8 *)(arg0) + (0x20))));
    printf(D_0028BE30, (*(u16 *)((u8 *)(arg0) + (0x14))));
    printf(D_0028BE40, (*(u16 *)((u8 *)(arg0) + (0x16))));
    printf(D_0028BE50, (*(u16 *)((u8 *)(arg0) + (0x1C))));
    printf(D_0028BE70, (*(u16 *)((u8 *)(arg0) + (0x1E))));
    printf(D_0028BE80, (*(u16 *)((u8 *)(arg0) + (0x18))));
    printf(D_0028BE90, (*(u16 *)((u8 *)(arg0) + (0x1A))));
    printf(D_0028BEA0, (*(u16 *)((u8 *)(arg0) + (0x24))));
}
