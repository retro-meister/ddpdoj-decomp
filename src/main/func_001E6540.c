#include "common.h"

extern s8 D_0028E408;

s32 func_00124F00();
s32 func_00125410();
s32 func_00125440();
s32 func_0013A780();
s32 func_0013AB50();
s32 func_0013B2E0();
s32 func_0018D660();
s32 func_001E58E0();
s32 func_001E5A20();
s32 func_001E6B40();
s32 func_002010A0();
s32 func_002011A0();
extern u8 D_0026F320[];
extern u16 D_0026F350[];
extern u16 D_0026F3A0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E6540(s32 arg1) {
    s32 var_a1;
    u16 *temp_a1;
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_5;
    u16 temp_v1;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u32 var_a0;

    var_a1 = arg1;
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 4) {
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_a1 = (u8 *)(D_0026F350);
        func_001E58E0();
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_a1 = (u8 *)(D_0026F350);
        func_001E5A20();
        func_002010A0();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 2;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x10;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_d2.h[0] = temp_a0;
        reg_d2.w += 0xF8000400;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        func_0013AB50();
        func_002010A0();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 2;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0xF0;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_d2.h[0] = temp_a0_2;
        reg_d2.w += 0x01FFFA00;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        func_0013AB50();
        func_0018D660();
        var_a1 = 5;
        (*(u8 *)((u8 *)(reg_a4) + (3))) = 5U;
        (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x80U;
    }
    temp_a0_3 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_3 == 3) {
        func_00125440();
        if (D_0028E408 == 0) {
            reg_a0 = (u8 *)D_0026F320;
            func_0013B2E0();
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 4U;
        }
    }
    temp_a0_4 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_4 == 2) {
        func_001E6B40();
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
        (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
            reg_a1 = (u8 *)(D_0026F3A0);
            reg_a1 += (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            reg_d1.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            func_0013A780();
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            (*(u8 *)((u8 *)(reg_a0) + (0x1D))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d1.h[0];
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) *(u16 *)reg_a1;
            temp_a1 = (u16 *)(reg_a1 + 2);
            reg_a1 = (u8 *)(temp_a1);
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x22)));
            temp_a0_5 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a0_5;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            func_002010A0();
            reg_d0.b[0] += 0x10;
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d0.b[0];
            func_002011A0();
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a4) + (0xA))) += 0xC;
            if ((*(u16 *)((u8 *)(reg_a4) + (0xA))) == 0x48) {
                (*(u16 *)((u8 *)(reg_a4) + (0xA))) = 0U;
                (*(u16 *)((u8 *)(reg_a4) + (0xE))) -= 1;
                if ((*(u16 *)((u8 *)(reg_a4) + (0xE))) == 0) {
                    (*(u8 *)((u8 *)(reg_a4) + (3))) = 3U;
                    reg_d0.w = 9;
                    func_00124F00();
                    reg_d0.h[0] = 0x12;
                    func_00125410();
                    (*(u8 *)((u8 *)(reg_a4) + (7))) = 0xFF;
                    (*(u8 *)((u8 *)(reg_a4) + (9))) = 0xFF;
                }
            }
        }
    }
    var_a0 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if ((var_a0 == 1) && ((temp_v1 = (*(u16 *)((u8 *)(reg_a4) + (4))), var_a0 = (u32) (reg_a4 + 4), (temp_v1 == 0)) || (*(u16 *)var_a0 = (s16) (temp_v1 - 1), ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0)))) {
        func_001E6B40();
        var_a0 = (u32) (reg_a4);
        reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (0xD)));
        (*(u8 *)((u8 *)(var_a0) + (0xD))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
            reg_a1 = (u8 *)(D_0026F3A0);
            reg_a1 += (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            reg_d1.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            func_0013A780();
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            (*(u8 *)((u8 *)(reg_a0) + (0x1D))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d1.h[0];
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x22)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x24)));
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d0.b[0] += reg_d0.b[0];
            reg_d0.b[0] += reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a4) + (0xA))) += 0xC;
            var_a0 = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            if (var_a0 == 0x48) {
                (*(u16 *)((u8 *)(reg_a4) + (0xA))) = 0U;
                var_a0 = 8;
                (*(u16 *)((u8 *)(reg_a4) + (0xC))) = 0x606;
                (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
                (*(s16 *)((u8 *)(reg_a4) + (0x10))) = 8;
                (*(s16 *)((u8 *)(reg_a4) + (0x12))) = 0;
            }
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        func_001E6B40();
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) < 0) {
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
            reg_a1 = (u8 *)(D_0026F350);
            func_001E58E0();
            (*(s8 *)((u8 *)(reg_a4) + (7))) = 0;
            (*(s8 *)((u8 *)(reg_a4) + (9))) = 0;
            (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x50U;
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
            (*(s16 *)((u8 *)(reg_a4) + (0x10))) = 0x10;
            (*(s16 *)((u8 *)(reg_a4) + (0x12))) = 0;
        }
    }
}
