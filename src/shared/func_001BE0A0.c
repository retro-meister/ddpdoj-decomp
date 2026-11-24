#include "common.h"

s32 func_0014E290();
extern u32 D_00251720[];
extern u16 D_0028E3C0;
extern u16 D_0028E8A8;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u32 D_002B6D50[];
extern u32 D_002B6DF4[];
extern u32 D_002B6E0C[];
extern u8 *D_0028E484;
extern u8 *reg_a0;

void func_001BE0A0(void) {
    s32 flag;
    u32 *dst;
    u32 *src;
    u32 cnt;
    u32 cnt2;

    if (D_0028E8A8 == 0x105) {
        func_0014E290();
        return;
    }
    src = D_00251720;
    reg_a0 = (u8 *)(D_002B6E0C);
    reg_tmp.w = 0xBC;
    flag = D_0028ED80 == 1;
    if (flag == 0) {
        flag = D_0028ED7C == 2;
    }
    if ((flag != 0) || (D_0028E3C0 != 0)) {
        reg_a0 = (u8 *)(D_002B6DF4);
        reg_tmp.w = 0xA4;
    }
    reg_d6.w = 0x16;
loop_1:
    dst = (u32 *)(reg_a0);
    reg_d7.w = 8;
loop_2:
    reg_d4.w = *src;
    src += 1;
    reg_d4.h[1] += 0x800;
    *dst = reg_d4.w;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    dst += 64;
    if (((s64) ((s64) (u16) cnt << 0x30) >> 0x30) >= 0) {
        goto loop_2;
    }
    D_0028E484 = (u8 *)D_002B6D50;
    reg_tmp.w += 4;
    reg_tmp.w = (u32) reg_tmp.b[0];
    D_0028E484 += reg_tmp.w;
    reg_a0 = (u8 *)(D_0028E484);
    cnt2 = reg_d6.h[0] - 1;
    reg_d6.h[0] = cnt2;
    if (((s64) ((s64) (u16) cnt2 << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}
