#include "common.h"

s32 func_00124F00();
s32 func_0018D540();
s32 func_0018D560();
s32 func_001B26F0();
s32 func_001B2830();
extern u8 D_0026DBD0[];
extern u8 D_0026DC40[];
extern u16 D_0029C06C[];
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B29B0(void) {
    u32 temp_a1;
    u8 temp_a0;
    u8 temp_v1;

    reg_d0.h[0] = D_0029C06C[0];
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) (temp_a1 - reg_d0.h[0]);
    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0 == 2) {
        func_0018D540();
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_a1 = (u8 *)D_0026DC40;
        func_001B2830();
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
        (*(u8 *)((u8 *)(reg_a4) + (0xB))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0xB))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xA)));
            temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (0xA)));
            if (temp_v1 != 0) {
                (*(u8 *)((u8 *)(reg_a4) + (0xA))) = (u8) (temp_v1 - 1);
            }
            (*(u16 *)((u8 *)(reg_a4) + (0xC))) += 0x10;
            (*(u16 *)((u8 *)(reg_a6) + (0x46))) -= 0x800;
            (*(u16 *)((u8 *)(reg_a6) + (0x48))) -= 0x800;
            if (0 > (s16) (*(u16 *)((u8 *)(reg_a6) + (0x48)))) {
                reg_tmp.w = 0;
                (*(u16 *)((u8 *)(reg_a6) + (0x46))) = (u16) reg_tmp.h[1];
                (*(u16 *)((u8 *)(reg_a6) + (0x48))) = (u16) reg_tmp.h[0];
                (*(u16 *)((u8 *)(reg_a4) + (0xC))) = 0U;
                (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
                reg_d0.w = 0;
                func_00124F00();
            }
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        func_0018D560();
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_a1 = (u8 *)D_0026DBD0;
        func_001B26F0();
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) -= reg_d0.h[0];
}
