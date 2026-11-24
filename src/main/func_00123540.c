#include "common.h"

void func_00123000(void);
void func_00123410(void);
void func_0013BE50(void);
void func_0013C300(void);
void func_0013C350(void);
extern u8 D_0024D340[];
extern s8 D_0028E408;
extern u16 D_00295E1C[];
extern u16 D_00295E1E_as_u16_a[];
extern u16 D_00295E20[];
extern u32 D_00295E24[];
extern u32 D_00295E28[];
extern u8 *reg_a0;
extern u8 *reg_a2;

void func_00123540(void) {
    if (reg_d0.h[0] == 0x8000) {
        D_00295E1E_as_u16_a[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        D_00295E1C[0] += 4;
        func_00123410();
    } else if (reg_d0.h[0] == 0x8001) {
        reg_tmp.h[1] = *(u16 *)reg_a2;
        reg_a2 += 2;
        reg_tmp.h[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        D_00295E1C[0] += 6;
        D_00295E28[0] = reg_tmp.w;
        func_00123410();
    } else if (reg_d0.h[0] == 0x8002) {
        reg_d1.h[0] = D_00295E20[0];
        if (*(u16 *)reg_a2 == reg_d1.h[0]) {
            D_00295E20[0] = 0;
            D_00295E1C[0] += 4;
            func_00123410();
            return;
        }
        D_00295E20[0] += 1;
        D_0028E408 = 1;
    } else if (reg_d0.h[0] == 0x8003) {
        reg_d0.w = D_00295E24[0];
        if (reg_d0.w == 0) {
            reg_d0.h[0] = *(u16 *)reg_a2;
            reg_a0 = (u8 *)D_0024D340;
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 += reg_d0.h[0];
            reg_a0 = *(u8 **)reg_a0;
            func_0013BE50();
            D_00295E24[0] = reg_d0.w;
            D_0028E408 = 1;
            return;
        }
        func_0013C350();
        if (D_0028E408 != 0) {
            D_0028E408 = 1;
            return;
        }
        func_0013C300();
        D_00295E24[0] = 0;
        D_00295E1C[0] += 4;
        func_00123410();
    } else if (reg_d0.h[0] == 0x8005) {
        reg_d0.h[0] = *(u16 *)reg_a2;
        reg_d1.h[0] = *(u16 *)(reg_a2 + 2);
        func_00123000();
        D_00295E1C[0] += 6;
        func_00123410();
    } else {
        D_0028E408 = 0;
    }
}
