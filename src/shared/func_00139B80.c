#include "common.h"

s32 func_0011F980();
s32 func_00125FA0();
s32 func_00129DB0();
s32 func_00136F30();
s32 func_00139B20();
s32 func_0013A020();
s32 func_0013CC60();
s32 func_0013D090();
s32 func_0013D560();
s32 func_0013D660();
s32 func_0013F380();
s32 func_00144D00();
s32 func_00144DA0();
s32 func_00144E40();
s32 func_00144EA0();
s32 func_00146760();
s32 func_001482C0();
s32 func_001488C0();
s32 func_0014DA50();
s32 func_0016AC30();
void func_00170A50(s32, s32, s32);
s32 func_0019FC70();
s32 func_001B8410();
s32 func_0020A540();
s32 func_0020BD10();
s32 func_0020BD60();
s32 func_00211670();
extern u16 D_0028E3EC;
extern u16 D_0028E5CC;
extern u16 D_0028E5D0;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u16 D_0028E910;
extern u16 D_0028E928;
extern u8 D_0029D750[];
extern u8 D_0029D770[];
extern u8 D_0029DCA0[];
extern u8 D_0029DD30[];
extern u8 D_0029E2A0[];
extern u8 D_0029E330[];
extern u8 D_0029E390[];
extern u8 D_0029EA50[];
extern u16 D_0029F1F0[];
extern u16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_00139B80(void) {
    u16 t1;
    u16 t2;

    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_00139B20();
        return;
    }
    func_00211670();
    func_00170A50(0x1F, 0x1F, 0x1F);
    func_0014DA50();
    func_00170A50(0, 0, 0);
    func_00136F30();
    func_00125FA0();
    func_0013A020();
    func_001B8410();
    func_00170A50(0x1F, 0, 0);
    func_0011F980();
    func_001488C0();
    func_0019FC70();
    func_00146760();
    func_001482C0();
    func_0020A540();
    func_0013CC60();
    func_00144E40();
    func_00144EA0();
    func_00144D00();
    func_00144DA0();
    func_00170A50(0x1F, 0, 0x1F);
    func_0016AC30();
    func_00170A50(0x1F, 0x1F, 0);
    func_0013D660();
    func_00129DB0();
    func_0013F380();
    func_0013D090();
    func_0013D560();
    func_00170A50(0, 0x1F, 0);
    if (D_0028E928 != 0) {
        reg_d4.h[0] = D_0029F260[0];
        if (D_0029F260[0] != 0) {
            reg_a0 = (u8 *)D_0029E390;
            reg_a1 = (u8 *)D_0029D770;
            reg_a2 = (u8 *)D_0029E2A0;
            reg_a3 = (u8 *)D_0029E330;
            reg_a4 = (u8 *)(D_0029F260);
            reg_d0.h[0] = 0x1000;
            t2 = D_0028E5FC;
            t1 = D_0028E5D0;
            reg_d1.h[0] = t2;
            reg_d2.h[0] = t1;
            if (D_0028E3EC == 0) {
                func_0020BD60();
                return;
            }
            goto next_1;
        }
        reg_d4.h[0] = D_0029F1F0[0];
        if (D_0029F1F0[0] != 0) {
            reg_a0 = (u8 *)D_0029EA50;
            reg_a1 = (u8 *)D_0029D750;
            reg_a2 = (u8 *)D_0029DCA0;
            reg_a3 = (u8 *)D_0029DD30;
            reg_a4 = (u8 *)(D_0029F1F0);
            reg_d0.h[0] = 0x800;
            t2 = D_0028E5F8;
            t1 = D_0028E5CC;
            reg_d1.h[0] = t2;
            reg_d2.h[0] = t1;
            if (D_0028E3EC != 0) {
                func_0020BD60();
                return;
            }
next_1:
            switch (D_0028E910) {
            case 0:
                break;
            default:
                func_0020BD10();
            }
        }
    } else {
        if (D_0028E3EC == 0) {
            reg_a0 = (u8 *)D_0029E390;
            reg_a1 = (u8 *)D_0029D770;
            reg_a2 = (u8 *)D_0029E2A0;
            reg_a3 = (u8 *)D_0029E330;
            reg_a4 = (u8 *)(D_0029F260);
            reg_d0.h[0] = 0x1000;
            reg_d1.h[0] = D_0028E5FC;
            reg_d2.h[0] = D_0028E5D0;
            func_0020BD60();
            return;
        }
        reg_a0 = (u8 *)D_0029EA50;
        reg_a1 = (u8 *)D_0029D750;
        reg_a2 = (u8 *)D_0029DCA0;
        reg_a3 = (u8 *)D_0029DD30;
        reg_a4 = (u8 *)(D_0029F1F0);
        reg_d0.h[0] = 0x800;
        reg_d1.h[0] = D_0028E5F8;
        reg_d2.h[0] = D_0028E5CC;
        func_0020BD60();
    }
}
