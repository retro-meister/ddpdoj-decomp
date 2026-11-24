#include "common.h"

void func_0011BEA0(void);
void func_0012FA50(void);
void func_0012FB00(void);
extern u32 D_00268FB0[];
extern u32 D_002B6D50[];
extern u8 *reg_a1;
extern u8 *reg_a2;

void func_0015B930(void) {
    u32 t1;

    func_0012FA50();
    func_0012FB00();
    func_0011BEA0();
    reg_tmp.w = 0;
    reg_a1 = (u8 *)D_00268FB0;
    reg_d6.w = 0xD;
    do {
        reg_a2 = (u8 *)D_002B6D50;
        reg_a2 += reg_tmp.w;
        reg_d7.w = 6;
    loop_1:
        reg_d4.w = *(u32 *)reg_a1;
        reg_a1 += 4;
        reg_d4.h[1] += 0xC00;
        *(u32 *)reg_a2 = reg_d4.w;
        reg_a2 += 0x100;
        t1 = reg_d7.h[0] - 1;
        reg_d7.h[0] = t1;
        if (((s64)((s64)(u16)t1 << 0x30) >> 0x30) >= 0) goto loop_1;
        reg_tmp.w += 4;
        reg_tmp.h[0] = reg_tmp.b[0];
    } while ((s16)(--reg_d6.h[0]) >= 0);
}
