#include "common.h"

s32 func_00129280();
s32 func_00129320();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0018D580();
s32 func_0019C470();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001F61B0();
s32 func_00201B80();
extern u8 D_00265620[];
extern u8 D_002656A0[];
extern u8 D_002656F0[];
extern u8 D_00265770[];
extern u8 D_002657B0[];
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F7C80(void) {
    u8 *temp_a1;
    s16 temp_a2;
    u16 temp_a0;
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
            reg_d0.w = 0x390;
            func_001A91A0();
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_a1 = (u8 *)D_002656A0;
            func_001F61B0();
            func_0018D580();
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
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
    if ((s32) reg_d0.w < 0x401) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
            reg_a0 = (u8 *)reg_tmp.w;
            (*(u16 *)((u8 *)(reg_a0) + (0))) = 0U;
            func_0014E290();
            return;
        }
        goto block_8;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_8:
    if (D_0028E8A0 == 0) {
        func_00201B80();
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) += 4;
            if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x1C))) >= 0x78) {
                (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 0U;
            }
            reg_a1 = (u8 *)D_002656F0;
            reg_a1 += (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
            reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_a1 = (u8 *)D_00265770;
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) != 0) {
                reg_a1 = (u8 *)D_002657B0;
                reg_d3.h[0] *= 0xFFFF;
            }
            temp_a1 = (u8 *)(reg_a1);
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
            temp_a2 = (s16) reg_d0.h[0];
            reg_d0.h[0] = (u16) (temp_a2 >> 1);
            reg_a1 = temp_a1 + reg_d0.h[0];
            temp_a0 = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_d1.h[0] = temp_a0;
            reg_d2.w += reg_d3.w;
            reg_d0.w = 0x10003;
            reg_d4.w = 0;
            reg_d3.w = 0;
            func_00129320();
            reg_d0.w = 0xFFFD0004;
            reg_d1.h[0] += 2;
            func_00129280();
            reg_d1.h[0] -= 4;
            func_00129280();
            reg_d1.h[0] += 3;
            reg_d0.w = 0xFFF90005;
            func_00129280();
            (*(u8 *)((u8 *)(reg_a5) + (0x24))) += 1;
            (*(u8 *)((u8 *)(reg_a5) + (0x24))) &= 1;
            (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
        }
    }
    reg_a0 = (unsigned char *)D_00265620;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d4.w = 0;
    reg_d1.w += 0xE200EA00;
    reg_d3.h[0] = 0x1EB0;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C470();
    reg_a0 = (unsigned char *)reg_a6;
    func_0014D220();
}
