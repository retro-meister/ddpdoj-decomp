#include "common.h"

extern s8 D_0028E408;

s32 func_00128AC0();
s32 func_00137C10();
s32 func_0013A780();
s32 func_00145D40();
s32 func_0014D220();
s32 func_0019BF00();
s32 func_001A9000();
s32 func_00201D10();
s32 func_00202180();
s32 func_002026F0();
s32 func_00202D50();
s32 func_00203670();
extern u16 D_0028E3F0;
extern u16 D_0028E8B8;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001627C0(void) {
    u8 *ptr;
    u32 save_d0, save_d1, save_d2, save_d3, save_d4, save_d5, save_d6, save_d7;
    u8 *save_a0, *save_a1, *save_a2, *save_a3, *save_a4, *save_a5, *save_a6;

    func_00202D50();
    if (D_0028E408 == 0) {
        reg_d0.w = 0x7F;
        reg_d0.h[0] &= D_0028E3F0;
        if (reg_d0.h[0] == 0) {
            reg_d0.w = 7;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            func_00202180();
            reg_d0.w = 0;
            func_00137C10();
            if ((s32) reg_d0.b[0] < 0x1B) {
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d4.w = (u32) reg_a6;
                reg_d3.w = 0;
                reg_d5.w = 0;
                func_00128AC0();
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d1.h[0] += 0x800;
                func_002026F0();
                reg_d0.w = 0;
                func_00137C10();
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d3.w = 0x800;
                reg_d4.w = (u32) reg_a6;
                reg_d5.w = 0;
            }
        }
    }
    func_00203670();
    reg_d1.w = 0x5C;
    ptr = (u8 *)(reg_a6 + 1);
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    if (reg_d1.b[0] == 0) {
        reg_d0.b[0] = 0;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
        if (((u32) reg_tmp.w < 0x1FFFFU) && (D_0028E8B8 == 0)) {
            reg_d0.w = 0x19;
        }
    } else {
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xA3;
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = 0;
        }
        reg_d0.b[0] ^= 0x1F;
        reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x18)));
        reg_d6.w = 0x7FFF;
        (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d6.h[0];
        ptr = (u8 *)(reg_a5);
        reg_d6.h[0] -= reg_d5.h[0];
        reg_tmp.h[1] = (*(u16 *)((u8 *)(ptr) + (0x18)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(ptr) + (0x1A)));
        reg_tmp.w -= reg_d6.w;
        (*(u16 *)((u8 *)(ptr) + (0x18))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = (u16) reg_tmp.h[0];
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
    func_0019BF00();
    reg_d0.w = 0x20;
    reg_d1.h[0] = D_0028E3F0;
    reg_d1.h[0] &= 0x7E;
    reg_d1.h[0] >>= 1;
    reg_d7.h[0] = reg_d1.h[0];
    func_00201D10();
    save_d0 = reg_d0.w; save_d1 = reg_d1.w; save_d2 = reg_d2.w; save_d3 = reg_d3.w;
    save_d4 = reg_d4.w; save_d5 = reg_d5.w; save_d6 = reg_d6.w; save_d7 = reg_d7.w;
    save_a0 = reg_a0; save_a1 = reg_a1; save_a2 = reg_a2; save_a3 = reg_a3;
    save_a4 = reg_a4; save_a5 = reg_a5; save_a6 = reg_a6;
    reg_d3.h[0] = reg_d7.h[0];
    reg_d1.h[0] = 0x12;
    reg_d0.h[0] = 0xE;
    reg_d5.h[0] = 0;
    func_00145D40();
    reg_d0.w = save_d0; reg_d1.w = save_d1; reg_d2.w = save_d2; reg_d3.w = save_d3;
    reg_d4.w = save_d4; reg_d5.w = save_d5; reg_d6.w = save_d6; reg_d7.w = save_d7;
    reg_a0 = save_a0; reg_a1 = save_a1; reg_a2 = save_a2; reg_a3 = save_a3;
    reg_a4 = save_a4; reg_a5 = save_a5; reg_a6 = save_a6;
    save_d0 = reg_d0.w; save_d1 = reg_d1.w; save_d2 = reg_d2.w; save_d3 = reg_d3.w;
    save_d4 = reg_d4.w; save_d5 = reg_d5.w; save_d6 = reg_d6.w; save_d7 = reg_d7.w;
    save_a0 = reg_a0; save_a1 = reg_a1; save_a2 = reg_a2; save_a3 = reg_a3;
    save_a4 = reg_a4; save_a5 = reg_a5; save_a6 = reg_a6;
    reg_d3.h[0] = reg_d2.h[0];
    reg_d1.h[0] = 0x11;
    reg_d0.h[0] = 0xE;
    reg_d5.h[0] = 0;
    func_00145D40();
    reg_d0.w = save_d0; reg_d1.w = save_d1; reg_d2.w = save_d2; reg_d3.w = save_d3;
    reg_d4.w = save_d4; reg_d5.w = save_d5; reg_d6.w = save_d6; reg_d7.w = save_d7;
    reg_a0 = save_a0; reg_a1 = save_a1; reg_a2 = save_a2; reg_a3 = save_a3;
    reg_a4 = save_a4; reg_a5 = save_a5; reg_a6 = save_a6;
    save_d0 = reg_d0.w; save_d1 = reg_d1.w; save_d2 = reg_d2.w; save_d3 = reg_d3.w;
    save_d4 = reg_d4.w; save_d5 = reg_d5.w; save_d6 = reg_d6.w; save_d7 = reg_d7.w;
    save_a0 = reg_a0; save_a1 = reg_a1; save_a2 = reg_a2; save_a3 = reg_a3;
    save_a4 = reg_a4; save_a5 = reg_a5; save_a6 = reg_a6;
    reg_d1.h[0] = 0x10;
    reg_d0.h[0] = 0xE;
    reg_d5.h[0] = 0;
    func_00145D40();
    reg_d0.w = save_d0; reg_d1.w = save_d1; reg_d2.w = save_d2; reg_d3.w = save_d3;
    reg_d4.w = save_d4; reg_d5.w = save_d5; reg_d6.w = save_d6; reg_d7.w = save_d7;
    reg_a0 = save_a0; reg_a1 = save_a1; reg_a2 = save_a2; reg_a3 = save_a3;
    reg_a4 = save_a4; reg_a5 = save_a5; reg_a6 = save_a6;
    reg_a0 = reg_a6;
    func_0014D220();
}
