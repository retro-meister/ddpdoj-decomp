#include "common.h"

s32 func_002071C0();
extern u8 D_00269D10[];
extern u8 D_00269D20[];
extern u32 D_0028E83C;
extern u32 D_0028E840;
extern u32 D_0028E844;
extern u8 D_002BF390[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00135220(void) {
    u16 temp_a0;
    u16 temp_a1;
    reg_a0 = (u8 *)D_00269D10;
    reg_a6 = (u8 *)D_002BF390;
    reg_d7.w = 1;
    do {
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0)));
        (*(u16 *)((u8 *)(reg_a6) + (0xE))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (4)));
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (6)));
        (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (8)));
        (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0xA)));
        (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0xC)));
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0xE)));
        (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0;
        (*(s16 *)((u8 *)(reg_a6) + (0x1A))) = 0;
        (*(s16 *)((u8 *)(reg_a6) + (0x1C))) = 0;
        (*(s16 *)((u8 *)(reg_a6) + (0x1E))) = 0;
        (*(s16 *)((u8 *)(reg_a6) + (4))) = 0;
        (*(s16 *)((u8 *)(reg_a6) + (6))) = 0;
        (*(s16 *)((u8 *)(reg_a6) + (0x20))) = 0;
        (*(s16 *)((u8 *)(reg_a6) + (0x22))) = 0;
        reg_a0 = (u8 *)D_00269D20;
        reg_a6 += 0x24;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.h[0] = 0;
    func_002071C0();
    temp_a0 = reg_d0.h[1];
    reg_tmp.h[0] = temp_a0;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    D_0028E844 = reg_d0.w;
    reg_d0.h[0] = 4;
    func_002071C0();
    temp_a1 = reg_d0.h[1];
    reg_tmp.h[0] = temp_a1;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    D_0028E840 = reg_d0.w;
    (*(u8 *)((u8 *)(reg_a0) + (6))) = 0;
    reg_d0.h[0] = 4;
    func_002071C0();
    reg_tmp.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    D_0028E83C = reg_d0.w;
    (*(u8 *)((u8 *)(reg_a0) + (6))) = 1;
}
