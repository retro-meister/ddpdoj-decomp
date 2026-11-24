#include "common.h"

s32 func_00129280();
s32 func_00129320();
s32 func_00129370();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0018D580();
s32 func_0019C470();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001F61B0();
s32 func_00201B80();
extern u8 D_002652B0[];
extern u8 D_00265330[];
extern u8 D_002653B0[];
extern u8 D_00265430[];
extern u8 D_002654B0[];
extern u16 D_0028E89C;
extern u16 D_0028E8A8;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F72B0(void) {
    u16 temp_a0;
    u16 temp_v1;
    u32 temp_v0;
    u8 *var_a0;

    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    var_a0 = (u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        func_001A9000();
        var_a0 = (u8 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x18)));
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) reg_d0.b[0];
        if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
            reg_d0.w = 0x350;
            func_001A91A0();
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_a1 = (u8 *)D_002654B0;
            func_001F61B0();
            func_0018D580();
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x22)));
            reg_a0 = (u8 *)reg_tmp.w;
            (*(u16 *)((u8 *)(reg_a0) + (0))) = 0U;
            func_0014E290();
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
block_4:
    reg_d0.w = 0;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x2001) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x22)));
            reg_a0 = (u8 *)reg_tmp.w;
            (*(u16 *)((u8 *)(reg_a0) + (0))) = 0U;
            func_0014E290();
            return;
        }
        goto block_8;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_8:
    func_00201B80();
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
        if (D_0028E89C == 0) {
            reg_a1 = (u8 *)D_00265430;
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) != 0) {
                reg_a1 = (u8 *)D_002653B0;
            }
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
            reg_a1 += reg_d0.h[0];
            temp_v1 = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_a1 = (u8 *)D_00265330;
            reg_d1.h[0] = temp_v1;
            reg_a1 += (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
            reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) != 0) {
                reg_d3.h[0] *= 0xFFFF;
            }
            reg_d0.w = 4;
            reg_d4.w = 0;
            temp_v0 = reg_d2.w + reg_d3.w;
            reg_d3.w = 0;
            reg_d2.w = temp_v0;
            func_00129280();
            reg_d0.w = 0xFFFC0005;
            func_00129370();
            if ((s32) D_0028E8A8 >= 0x268) {
                reg_d0.w = 0x40003;
                func_00129320();
            }
        }
        (*(u16 *)((u8 *)(reg_a5) + (0x1C))) += 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x1C))) >= 0x78) {
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 0U;
        }
    }
    reg_a0 = (unsigned char *)reg_a6;
    func_0014D220();
    reg_a0 = (unsigned char *)D_002652B0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0;
    reg_d4.w = 0;
    reg_d1.w += 0xF000F600;
    reg_d3.h[0] = 0x1050;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C470();
}
