#include "common.h"

s32 func_001ABF90();
s32 func_00200EE0();
s32 func_00201010();
extern u16 D_0028E024;
extern Reg32 D_0028E480;
extern u16 D_0028E5E4;
extern s16 D_0028E5FC;
extern u16 D_0028E648;
extern u16 D_0028E650;
extern u16 D_0028E6A0;
extern u16 D_0028E6C8;
extern u8 D_0028E855;

void func_00170DF0(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    s64 t;

    reg_d3.h[0] = D_0028E024;
    reg_d4.h[0] = D_0028E6C8;
    reg_d5.h[0] = D_0028E6A0;
    if (D_0028E855 & 2) {
        reg_d0.h[0] = D_0028E648;
        if ((s16) reg_d0.h[0] >= 0) {
            func_00200EE0();
            reg_d5.w = reg_d2.w;
            reg_d4.h[0] = D_0028E650;
        } else {
            reg_d4.w = 0;
        }
    }
    if ((D_0028E5FC == 0) && ((s16) reg_d4.h[0] != 0)) {
        t = (s64) ((s64) reg_d5.h[0] << 0x30) >> 0x30;
        if ((t != 0) && (t >= 0)) {
            save_d0 = reg_d0.w;
            save_d1 = reg_d1.w;
            save_d2 = reg_d2.w;
            save_d3 = reg_d3.w;
            save_d4 = reg_d4.w;
            save_d5 = reg_d5.w;
            if ((s32) (reg_d5.h[0] & 0xFFFF) > 0x200) {
                reg_d5.h[0] = 0x200;
            }
            reg_d0.h[0] = reg_d5.h[0];
            func_00201010();
            reg_d0.w = 0;
loop_11:
            D_0028E480.w = 0;
            reg_tmp.w = 0;
            reg_tmp.h[0] = 0x14;
            D_0028E480.h[0] = reg_d2.h[0];
            D_0028E480.w -= reg_tmp.w;
            reg_d2.h[0] -= 0x14;
            if (D_0028E480.h[1] == 0) {
                reg_d0.h[0] += 0x48;
                goto loop_11;
            }
            D_0028E5E4 += reg_d0.h[0];
            func_001ABF90();
            reg_d0.w = save_d0;
            reg_d1.w = save_d1;
            reg_d2.w = save_d2;
            reg_d3.w = save_d3;
            reg_d4.w = save_d4;
            reg_d5.w = save_d5;
        }
    }
}
