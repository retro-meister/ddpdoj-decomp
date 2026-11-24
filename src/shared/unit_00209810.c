#include "common.h"

void func_002099D0(void);

s32 func_0012FD00();                            /* extern */
s32 func_00208AD0();                            /* extern */
s32 func_00209200();                            /* extern */
s32 func_00209790();                            /* extern */
extern s32 D_00268360[];
extern s32 D_002683F0[];
extern s32 D_00268410[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern s32 *reg_a0_as_s32_p;

void func_00209810(void) {
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_00268360;
    func_00209200();
    reg_a0_as_s32_p = D_002683F0;
    func_00209200();
    reg_a0_as_s32_p = D_00268410;
    func_00209200();
    func_00209790();
    reg_d0.w = 0;
}

s32 func_00209200();
extern u8 D_00268380[];
extern u8 D_00268390[];
extern u8 D_002683A0[];
extern u8 D_002683C0[];
extern u8 D_002683D8[];
extern u8 D_00268430[];
extern u8 *reg_a0;

void func_00209880(void) {
    s32 temp_a0;

    reg_a0 = D_00268380;
    reg_d0.h[0] = 0;
    func_00209200();
    reg_a0 = D_00268390;
    func_00209200();
    reg_a0 = D_002683A0;
    func_00209200();
    reg_a0 = D_002683C0;
    func_00209200();
    reg_a0 = D_002683D8;
    func_00209200();
    reg_d0.w = 0;
    reg_d0.b[0] = (u8) D_0028DFA0;
    temp_a0 = reg_d0.h[0] * 4;
    reg_a0 = *(u8 **)((u8 *)D_00268430 + temp_a0);
    reg_d0.h[0] = 2;
    func_00209200();
}

extern u8 D_00268450[];
extern u8 D_002686B0[];
extern u8 D_0028E39C;

void func_00209920(void) {
    s32 func_002092F0();
    reg_a0 = (u8 *)D_00268450;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E39C;
    reg_d0.h[0] <<= 5;
    reg_a0 += reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x2A;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
    if (D_0028E39C != 0x11) {
        func_002099D0();
        return;
    }
    reg_a0 = (u8 *)D_002686B0;
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x29;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
}

extern s32 D_00268770[];

void func_002099D0(void) {
    void func_002092F0(void);
    reg_a0_as_s32_p = D_00268770;
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x29;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
}

extern u8 D_002686D0[];
extern u8 D_0028E398;

void func_00209A00(void)
{
    extern void func_002092F0(void);
    u8 *label;

    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E398;
    reg_a0 = D_002686D0;
    reg_d0.h[0] <<= 5;
    label = reg_a0 + reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x24;
    reg_d2.h[0] = reg_d7.h[0];
    reg_a0 = label;
    func_002092F0();
}

extern u8 D_0028E394;


void func_00209A50(void)
{
    extern void func_002092F0(void);
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E394;
    reg_d0.h[0] <<= 5;
    reg_a0 = D_002686D0;
    reg_a0 += reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x1E;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
}

extern u8 D_00268710[];
extern u8 D_0028E390;

void func_00209AA0(void) {
    extern void func_002092F0(void);
    reg_a0 = D_00268710;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E390;
    reg_d0.h[0] <<= 5;
    reg_a0 += reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x18;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
}

typedef void (*Fn)();

extern u8 D_00268790[];
extern u8 *jtbl_0028E3F4_as_u8_p;

void func_00209AF0(void) {
    s32 temp_a1;

    reg_d7.h[0] = 0;
    func_00209920();
    reg_d7.h[0] = 0;
    func_00209A00();
    reg_d7.h[0] = 0;
    func_00209A50();
    reg_d7.h[0] = 0;
    func_00209AA0();
    reg_d0.w = 0;
    reg_d0.b[0] = (u8) D_0028DFA0;
    temp_a1 = reg_d0.h[0] * 4;
    reg_d0.w = *(u32 *)(D_00268790 + temp_a1);
    if (reg_d0.w != -1U) {
        reg_a0 = (u8 *)reg_d0.w;
        reg_d7.h[0] = 2;
        jtbl_0028E3F4_as_u8_p = reg_a0;
        ((Fn)jtbl_0028E3F4_as_u8_p)();
    }
}
