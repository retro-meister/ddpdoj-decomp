#include "common.h"

s32 func_00124F00(s32, s32, s32);
s32 func_0013AB50(void *);
s32 func_0018D560();
s32 func_001E58E0();
s32 func_002011A0();
extern u8 D_0026F670[];
extern u16 D_0028E4A2;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_001E8640(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0xBE))) == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0xB8))) = 0xFFFF;
        (*(u8 *)((u8 *)(reg_a6) + (0xBE))) = 1U;
        (*(u16 *)((u8 *)(reg_a6) + (0xA0))) = 0x8000;
        (*(s8 *)((u8 *)(reg_a6) + (0x14C))) = 0x13;
        reg_d0.w = 8;
        func_00124F00(0x13, 0x8000, 1);
        func_0018D560();
        reg_a1 = D_0026F670;
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
        func_001E58E0();
        func_002011A0();
        reg_d1.b[0] = reg_d0.b[0];
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
        reg_d3.h[0] = 0x10;
        reg_d0.h[0] = 0;
        func_0013AB50(reg_a6);
    }
}
