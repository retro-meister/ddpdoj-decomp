#include "common.h"

typedef void (*Fn)();

s32 func_00124510();
s32 func_00124F00();
s32 func_00125410();
s32 func_00125440();
s32 func_0013A780();
s32 func_0013A9E0();
s32 func_0013AB50();
s32 func_0013B2E0();
s32 func_0018D540();
s32 func_0018D560();
s32 func_0018D660();
s32 func_001B26F0();
s32 func_001B2830();
s32 func_002010A0();
s32 func_002011A0();
extern u8 D_0026DD30[];
extern u16 D_0026DD50[];
extern u16 D_0026DDC0[];
extern u16 D_0026DE00[];
extern u16 D_0026DF00[];
extern u8 D_0026DF70[];
extern u8 D_0026DFC0[];
extern u8 D_0028E310;
extern s8 D_0028E408;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B3030(void) {
    u16 *temp_a3_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_6;
    u16 temp_a0_7;
    u16 temp_a1;
    u16 temp_a2;
    u16 temp_a3;
    u16 temp_v1;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_5;
    u8 *var_a1;

    var_a1 = (u8 *)(reg_a4);
    temp_a0 = (*(u8 *)((u8 *)(var_a1) + (3)));
    if (temp_a0 == 6) {
        (*(u16 *)((u8 *)(var_a1) + (0xA))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (0xA))) == 0) {
            func_00124510();
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
        return;
    }
    if ((*(u8 *)((u8 *)(var_a1) + (2))) & 2) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a1) + (7)));
        (*(u8 *)((u8 *)(var_a1) + (7))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
            reg_d0.w = 5;
            func_0013A780();
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
            (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x14;
            func_002010A0();
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            var_a1 = (u8 *)((void *) (*(u16 *)((u8 *)(reg_a6) + (4))));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) var_a1;
            reg_tmp.w = 0xF8000000;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) reg_tmp.h[0];
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (2))) & 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            reg_d0.w = 0x10;
            func_0013A780();
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
            (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x18;
            func_002010A0();
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a1;
            reg_tmp.w = 0xE8000400;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) reg_tmp.h[0];
            reg_d0.w = 0x10;
            func_0013A780();
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
            (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x14;
            func_002010A0();
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            var_a1 = (u8 *)((void *) (*(u16 *)((u8 *)(reg_a6) + (4))));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) var_a1;
            reg_tmp.w = 0xF3FFF800;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) reg_tmp.h[0];
        }
    }
    temp_a0_2 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_2 == 5) {
        func_0018D660();
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_a1 = (u8 *)(D_0026DF00);
        func_001B2830();
        func_002010A0();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x40;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d2.w += 0xF8000A00;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        func_0013A9E0();
        func_002010A0();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0xB0;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        reg_d2.w -= 0x800;
        func_0013A9E0();
        func_002010A0();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x80;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d2.w += 0xF4000000;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        func_0013A9E0();
        var_a1 = (u8 *)((void *)0x80);
        (*(u16 *)((u8 *)(reg_a4) + (0xA))) = 0x80U;
        (*(u8 *)((u8 *)(reg_a4) + (3))) = 6U;
    }
    temp_a0_5 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_5 == 4) {
        func_00125440();
        if (D_0028E408 == 0) {
            D_0028E310 = 0xA;
            reg_a0 = D_0026DFC0;
            func_0013B2E0();
            reg_d0.w = 2;
            func_00124F00();
            reg_d0.w = 4;
            func_00124F00();
            reg_d0.w = 5;
            func_00124F00();
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 5U;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 3) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x13)));
        (*(u8 *)((u8 *)(reg_a4) + (0x13))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0x13))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x12)));
            reg_a0 = D_0026DD30;
            temp_a0_6 = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
            reg_a0 += temp_a0_6;
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
            ((Fn)*(u32 *)((u8 *)D_0026DD30 + (reg_tmp.h[0] & ~3)))();
            (*(u16 *)((u8 *)(reg_a4) + (0x14))) += 4;
            (*(u16 *)((u8 *)(reg_a4) + (0x14))) &= 0x1F;
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
        (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
            reg_a1 = (u8 *)(D_0026DE00);
            reg_a1 += (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            func_0013A780();
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            (*(u8 *)((u8 *)(reg_a0) + (0x1D))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a3;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x800;
            (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = *(u16 *)reg_a1;
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a4) + (0xE))) += 0x10;
            if ((*(u16 *)((u8 *)(reg_a4) + (0xE))) == 0x100) {
                (*(u16 *)((u8 *)(reg_a4) + (0xE))) = 0U;
                (*(u8 *)((u8 *)(reg_a4) + (3))) = 4U;
                reg_d0.h[0] = 0x12;
                func_00125410();
                func_0018D560();
            }
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 2) {
        temp_v1 = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
        if (temp_v1 != 0) {
            (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) (temp_v1 - 1);
        } else {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x13)));
            (*(u8 *)((u8 *)(reg_a4) + (0x13))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (0x13))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x12)));
                reg_a0 = D_0026DD30;
                temp_a0_7 = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
                reg_a0 += temp_a0_7;
                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
                ((Fn)*(u32 *)((u8 *)D_0026DD30 + (reg_tmp.h[0] & ~3)))();
                (*(u16 *)((u8 *)(reg_a4) + (0x14))) += 4;
                (*(u16 *)((u8 *)(reg_a4) + (0x14))) &= 0x1F;
            }
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
                reg_a1 = (u8 *)(D_0026DE00);
                reg_a1 += (*(u16 *)((u8 *)(reg_a4) + (0xE)));
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                func_0013A780();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                (*(u8 *)((u8 *)(reg_a0) + (0x1D))) = (u8) reg_d0.b[0];
                (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) *(u16 *)reg_a1;
                temp_a3_2 = (u16 *)(reg_a1 + 2);
                reg_a1 = (u8 *)(temp_a3_2);
                (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
                temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a2;
                (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
                (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
                (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x800;
                (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = *(u16 *)reg_a1;
                reg_a1 += 2;
                (*(u16 *)((u8 *)(reg_a4) + (0x10))) += 1;
                (*(u16 *)((u8 *)(reg_a4) + (0x10))) &= 1;
                if ((*(u16 *)((u8 *)(reg_a4) + (0x10))) == 0) {
                    D_0028E310 = 0xA;
                    reg_a0 = D_0026DF70;
                    func_0013B2E0();
                    func_002011A0();
                    reg_d1.b[0] = reg_d0.b[0];
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_d3.h[0] = 0xC;
                    reg_d0.h[0] = 0;
                    func_0013AB50();
                    func_0018D540();
                }
                (*(u16 *)((u8 *)(reg_a4) + (0xE))) += 0x10;
                if ((*(u16 *)((u8 *)(reg_a4) + (0xE))) == 0x80) {
                    (*(u16 *)((u8 *)(reg_a4) + (0xE))) = 0U;
                    (*(u8 *)((u8 *)(reg_a4) + (3))) = 3U;
                    (*(u16 *)((u8 *)(reg_a4) + (0xC))) = 4;
                    (*(u8 *)((u8 *)(reg_a4) + (2))) = 0U;
                    (*(u16 *)((u8 *)(reg_a4) + (0x12))) = 0x808;
                }
            }
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 1) {
        (*(u16 *)((u8 *)(reg_a4) + (0xA))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (0xA))) == 0) {
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_a1 = (u8 *)(D_0026DDC0);
            func_001B26F0();
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
            (*(u16 *)((u8 *)(reg_a4) + (0xA))) = 0x80U;
            (*(u8 *)((u8 *)(reg_a4) + (2))) |= 2;
            reg_d0.w = 3;
            func_00124F00();
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        func_0018D560();
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_a1 = (u8 *)(D_0026DD50);
        func_001B26F0();
    }
}
