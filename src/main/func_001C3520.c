#include "common.h"

s32 func_001C3450();
extern u16 D_0026C250[];
extern u16 D_0026C252[];
extern u16 D_0026C254[];
extern u16 D_0026C256[];
extern u16 D_0026C260[];
extern u16 D_0026C262[];
extern u16 D_0026C264[];
extern u16 D_0026C266[];
extern Reg32 D_0028E480;
extern u16 D_0028E910;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C3520(void) {
    u16 t1;
    u16 t2;
    u16 t3;
    u16 t4;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        reg_d6.h[0] = 0x20;
        reg_d7.h[0] = 0x14;
        if (D_0028E910 != 0) {
            reg_d7.h[0] = 0x28;
        }
        reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
        t1 = *(u16 *)(reg_a6 + 4);
        reg_d2.h[0] = t1;
        D_0028E480.h[1] = D_0026C250[0];
        D_0028E480.h[0] = D_0026C252[0];
        reg_d2.w += D_0028E480.w;
        func_001C3450();
        reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
        t2 = *(u16 *)(reg_a6 + 4);
        reg_d2.h[0] = t2;
        D_0028E480.h[1] = D_0026C254[0];
        D_0028E480.h[0] = D_0026C256[0];
        reg_d2.w += D_0028E480.w;
        func_001C3450();
        reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
        t3 = *(u16 *)(reg_a6 + 4);
        reg_d2.h[0] = t3;
        D_0028E480.h[1] = D_0026C260[0];
        D_0028E480.h[0] = D_0026C262[0];
        reg_d2.w += D_0028E480.w;
        func_001C3450();
        reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
        t4 = *(u16 *)(reg_a6 + 4);
        reg_d2.h[0] = t4;
        D_0028E480.h[1] = D_0026C264[0];
        D_0028E480.h[0] = D_0026C266[0];
        reg_d2.w += D_0028E480.w;
        func_001C3450();
        *(u16 *)(reg_a4 + 6) -= 1;
        if (*(u16 *)(reg_a4 + 6) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}
