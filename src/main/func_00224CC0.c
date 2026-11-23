#include "common.h"

s32 func_0018D4B0();
s32 func_0018D4C0();
s32 func_0021B570();
extern s32 D_0028DC98;
extern s8 D_0028E250;
extern s8 D_0028E254;
extern u16 D_0028E31C;
extern s8 D_0028E36C;
extern s8 D_0028EAE0;
extern s8 D_0028EAE4;
extern s8 D_0028EB04;
extern s32 D_0028EB90;
extern u8 D_0057CC60[];
extern u8 D_0057CC70[];
void func_00224CC0(void) {
    s32 temp_v1;

    temp_v1 = *(u32 *)(D_0057CC70 + (D_0028E31C * 4));
    if (temp_v1 & 0x20) {
        func_0018D4B0();
        D_0028E254 = D_0028EAE4;
        D_0028E250 = D_0028EAE0;
        func_0021B570(D_0028E254, D_0028E250);
        D_0028EB90 = 0;
        D_0028E36C = 3;
        D_0028EB04 = 1;
        return;
    }
    if (temp_v1 & 0x40) {
        func_0018D4B0();
        func_0021B570(D_0028E254, D_0028E250);
        D_0028EB90 = 0;
        D_0028E36C = 3;
        D_0028EB04 = 1;
        return;
    }
    if (temp_v1 & 0x100) {
        func_0018D4B0();
        D_0028EAE4 = 0;
        D_0028EAE0 = 0;
        func_0021B570(*(volatile s8 *)&D_0028EAE4, 0);
    }
    if ((D_0028DC98 != 2) && (D_0028DC98 != 3)) {
        if ((*(u32 *)(D_0057CC60 + (D_0028E31C * 4)) & 0x4000) && (D_0028EAE4 > -8)) {
            func_0018D4C0();
            D_0028EAE4 -= 1;
        }
        if ((*(u32 *)(D_0057CC60 + (D_0028E31C * 4)) & 0x1000) && (D_0028EAE4 < 8)) {
            func_0018D4C0();
            D_0028EAE4 += 1;
        }
        if ((*(u32 *)(D_0057CC60 + (D_0028E31C * 4)) & 0x2000) && (D_0028EAE0 < 8)) {
            func_0018D4C0();
            D_0028EAE0 += 1;
        }
        if ((*(u32 *)(D_0057CC60 + (D_0028E31C * 4)) & 0x8000) && (D_0028EAE0 > -8)) {
            func_0018D4C0();
            D_0028EAE0 -= 1;
        }
    } else {
        if ((*(u32 *)(D_0057CC60 + (D_0028E31C * 4)) & 0x4000) && (D_0028EAE0 < 8)) {
            func_0018D4C0();
            D_0028EAE0 += 1;
        }
        if ((*(u32 *)(D_0057CC60 + (D_0028E31C * 4)) & 0x1000) && (D_0028EAE0 > -8)) {
            func_0018D4C0();
            D_0028EAE0 -= 1;
        }
        if ((*(u32 *)(D_0057CC60 + (D_0028E31C * 4)) & 0x2000) && (D_0028EAE4 < 8)) {
            func_0018D4C0();
            D_0028EAE4 += 1;
        }
        if ((*(u32 *)(D_0057CC60 + (D_0028E31C * 4)) & 0x8000) && (D_0028EAE4 > -8)) {
            func_0018D4C0();
            D_0028EAE4 -= 1;
        }
    }
    func_0021B570(D_0028EAE4, D_0028EAE0);
}
