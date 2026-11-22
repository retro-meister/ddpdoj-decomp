#include "common.h"

extern Reg32 D_0028E484;
extern u16 D_0028E4A6;
extern s16 D_0028E8C0;

extern void func_001A53D0(void);
extern void func_001A8520(void);

void func_001A6BE0(void)
{
    u16 initialPosition;
    u32 savedD1;
    u16 savedD1Low;
    u32 offset;
    u32 position;

    if (D_0028E8C0 >= 0) {
        initialPosition = 0x2800;
        ((volatile Reg32 *)&reg_d1)->h[0] = 0x5BC0;
        savedD1 = ((volatile Reg32 *)&reg_d1)->w;
        savedD1Low = ((volatile Reg32 *)&reg_d1)->h[0];
        ((volatile Reg32 *)&reg_d2)->w = 0xE63;
        ((volatile Reg32 *)&reg_d3)->h[0] = 0x840;
        ((volatile Reg32 *)&reg_d4)->h[0] = 9;
        ((volatile Reg32 *)&reg_d1)->h[0] = initialPosition;
        offset = *(volatile u16 *)&reg_d6.h[0];
        position = *(volatile u16 *)&reg_d1.h[0];
        ((volatile Reg32 *)&D_0028E484)->w = savedD1;
        *(volatile u16 *)&D_0028E4A6 = savedD1Low;
        ((volatile Reg32 *)&reg_d1)->h[0] = position - offset;
        func_001A53D0();
        reg_d7.w = 0;
        func_001A8520();
        return;
    }
}
