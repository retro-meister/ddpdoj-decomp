#include "common.h"

s32 func_0011BF30();
s32 func_0011C0B0();
s32 func_0011C3C0();
s32 func_00139930();
s32 func_0014C4B0();
s32 func_0014C7B0();
s32 func_0014CAD0();
void func_00170A50(s32, s32, s32);
extern u8 D_0028E284;
extern u8 D_0028E288;
extern s16 D_0028E580;
extern s16 D_0028E584;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u16 D_0028E8AC;
extern u16 D_0029C064[];
extern u16 D_0029C074[];
extern u16 D_0029C076[];
extern u16 D_0029C078[];
extern u16 D_0029C07A[];
extern u16 D_0029C07C[];
extern u16 D_0029C07E[];
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_001391B0(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    if (D_0028E8A0 == 0) {
        if (D_0028E288 != 0) {
            if ((D_0028E288 & 0xFF) < 0x3D) {
                D_0028E288 -= 1;
            }
            if (D_0028E288 == 0) {
                D_0028E584 = 0;
            }
        }
        if (D_0028E284 != 0) {
            if ((D_0028E284 & 0xFF) < 0x3D) {
                D_0028E284 -= 1;
            }
            if (D_0028E284 == 0) {
                D_0028E580 = 0;
            }
        }
        if (D_0029C076[0] != 0) {
            D_0029C076[0] = 0;
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = (u16) D_0029C078[0];
            (*(u16 *)((u8 *)(reg_a5) + (0x22))) = (u16) D_0029C07A[0];
        }
        func_00139930();
        func_0014CAD0();
        reg_d0.h[0] = D_0029C074[0];
        if (reg_d0.h[0] != 0) {
            D_0029C074[0] = 0;
            if (reg_d0.h[0] != 1) {
                (*(u16 *)((u8 *)(reg_a5) + (8))) = 0U;
            } else {
                (*(u16 *)((u8 *)(reg_a5) + (8))) = 1U;
            }
        }
        reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
        temp_a0 = (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
        reg_d1.w = 0;
        reg_d5.h[0] = temp_a0;
        reg_d1.h[0] = D_0029C064[0];
        reg_d0.w = 0;
        reg_d0.h[0] = reg_d6.h[0];
        reg_d5.h[0] += reg_d6.h[0];
        func_0011BF30();
        if ((s16)(reg_d5.h[0]) >= 0x200) {
            reg_d5.h[0] -= 0x200;
            if ((*(u16 *)((u8 *)(reg_a5) + (8))) == 0) {
                D_0028E8A8 += 1;
            }
        }
        (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = (u16) reg_d5.h[0];
        temp_a0_2 = reg_d5.h[0];
        D_0028E8AC = temp_a0_2;
        reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
        reg_d5.h[0] += reg_d6.h[0];
        if ((s16)(reg_d5.h[0]) >= 0x800) {
            reg_d5.h[0] -= 0x800;
            func_0014C7B0();
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0xA)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0xC)));
            reg_a0 = (u8 *)(reg_tmp.w);
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0xE)));
            reg_d6.w = 8;
            reg_d0.w = 0;
            do {
                reg_d4.w = *(u32 *)reg_a0;
                reg_a0 += 4;
                func_0011C3C0();
                reg_d0.h[0] += 1;
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_tmp.w = (u32)reg_a0;
            (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a5) + (0xC))) = (u16) reg_tmp.h[0];
            reg_d1.h[0] += 1;
            reg_d1.h[0] &= 0x3F;
            (*(u16 *)((u8 *)(reg_a5) + (0xE))) = (u16) reg_d1.h[0];
        }
        (*(u16 *)((u8 *)(reg_a5) + (0x20))) = (u16) reg_d5.h[0];
        D_0029C07C[0] = (*(u16 *)((u8 *)(reg_a5) + (0xE)));
        D_0029C07E[0] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
        reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x22)));
        reg_d1.w = 0;
        reg_d1.h[0] = D_0029C064[0];
        reg_d0.w = 0;
        reg_d0.h[0] = reg_d6.h[0];
        func_0011C0B0();
    }
    func_0014C4B0();
    func_00170A50(0, 0, 0);
}
