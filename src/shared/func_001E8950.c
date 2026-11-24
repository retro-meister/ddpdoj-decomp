#include "common.h"

s32 func_00171400();
s32 func_002021F0();
s32 func_00202500();
extern s16 *D_0028E44C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E8950(void) {
    s16 *temp_a0;
    u16 temp_a1;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
            D_0028E44C = (s16 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(D_0028E44C);
        }
        temp_a0 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
            if (0 > (s64)*(s16 *)reg_a1) {
                reg_a0 = (u8 *)(reg_a1);
                D_0028E44C = (s16 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
            temp_a1 = (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d3.w = (u32) temp_a1;
            (*(u16 *)((u8 *)(reg_a6) + (0x134))) = (u16) reg_d2.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x136))) = (u16) reg_d3.h[0];
            if (((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) && ((*(u8 *)((u8 *)(reg_a6) + (0x3F))) == 0)) {
                reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0x22)));
                reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0x24)));
                func_002021F0();
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3A)));
                func_00202500();
                (*(u16 *)((u8 *)(reg_a6) + (0x3A))) = (u16) reg_d1.h[0];
                func_00171400();
            }
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x134)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x136)));
            if (((*(u8 *)((u8 *)(reg_a6) + (0x5E))) == 0) && ((*(u8 *)((u8 *)(reg_a6) + (0x5F))) == 0)) {
                reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0x42)));
                reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0x44)));
                func_002021F0();
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
                func_00202500();
                (*(u16 *)((u8 *)(reg_a6) + (0x5A))) = (u16) reg_d1.h[0];
                func_00171400();
            }
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x134)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x136)));
            if (((*(u8 *)((u8 *)(reg_a6) + (0x7E))) == 0) && ((*(u8 *)((u8 *)(reg_a6) + (0x7F))) == 0)) {
                reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0x62)));
                reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0x64)));
                func_002021F0();
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x7A)));
                func_00202500();
                (*(u16 *)((u8 *)(reg_a6) + (0x7A))) = (u16) reg_d1.h[0];
                func_00171400();
            }
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x134)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x136)));
            if (((*(u8 *)((u8 *)(reg_a6) + (0x9E))) == 0) && ((*(u8 *)((u8 *)(reg_a6) + (0x9F))) == 0)) {
                reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0x82)));
                reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0x84)));
                func_002021F0();
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x9A)));
                func_00202500();
                (*(u16 *)((u8 *)(reg_a6) + (0x9A))) = (u16) reg_d1.h[0];
                func_00171400();
            }
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x134)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x136)));
            if (((*(u8 *)((u8 *)(reg_a6) + (0xBE))) == 0) && ((*(u8 *)((u8 *)(reg_a6) + (0xBF))) == 0)) {
                reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
                reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
                func_002021F0();
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xBA)));
                func_00202500();
                (*(u16 *)((u8 *)(reg_a6) + (0xBA))) = (u16) reg_d1.h[0];
                func_00171400();
            }
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x134)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x136)));
            if (((*(u8 *)((u8 *)(reg_a6) + (0xDE))) == 0) && ((*(u8 *)((u8 *)(reg_a6) + (0xDF))) == 0)) {
                reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0xC2)));
                reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0xC4)));
                func_002021F0();
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xDA)));
                func_00202500();
                (*(u16 *)((u8 *)(reg_a6) + (0xDA))) = (u16) reg_d1.h[0];
                func_00171400();
            }
        }
    }
}
