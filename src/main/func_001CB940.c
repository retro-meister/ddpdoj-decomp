#include "common.h"

s32 func_00124F00(s32, s32, s32);
s32 func_0013AB50(void *);
s32 func_001CBA00();
s32 func_002011A0();
extern u8 D_0026CA80[];
extern u16 D_0028E4A2;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_001CB940(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x9E))) == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x98))) = 0xFFFF;
        (*(u8 *)((u8 *)(reg_a6) + (0x9E))) = 1U;
        (*(u16 *)((u8 *)(reg_a6) + (0x80))) = 0x8000;
        (*(s8 *)((u8 *)(reg_a6) + (0x12A))) = 0x12;
        reg_d0.w = 8;
        func_00124F00(0x12, 0x8000, 1);
        reg_a1 = D_0026CA80;
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
        func_001CBA00();
        func_002011A0();
        reg_d1.b[0] = reg_d0.b[0];
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
        reg_d3.h[0] = 8;
        reg_d0.h[0] = 0;
        func_0013AB50(reg_a6);
    }
}
