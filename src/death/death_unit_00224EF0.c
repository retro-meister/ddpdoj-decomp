#include "common.h"

void death_func_00224F20(u8 index);
void death_func_00225090(u8 index);
void death_func_002251F0(u8 index);
void death_func_00225360(u8 index);
void death_func_00225500(u8 index);


void death_func_00224EF0(u8 index) {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x1B) = 6;
    death_func_00224F20(index);
}

typedef struct {
    s32 low;
    s32 high;
} Range;

s32 func_002010A0();
s32 func_00201C60();
s32 func_002024C0();
extern Range death_D_0028E490[];

void death_func_00224F20(u8 index) {
    func_00201C60();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < death_D_0028E490[index].low) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if (death_D_0028E490[index].high <= (s32) reg_d1.h[0]) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5e00) {
        if ((s32) reg_d1.h[0] >= 0x6200) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
}


void death_func_00225060(u8 index) {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x1B) = 2;
    death_func_00225090(index);
}

extern Range death_D_0028E4A0[];

void death_func_00225090(u8 index) {
    func_00201C60();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < death_D_0028E4A0[index].low) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if (death_D_0028E4A0[index].high <= (s32) reg_d1.h[0]) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5200) {
        if ((s32) reg_d1.h[0] >= 0x5600) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
}


void death_func_002251D0(u8 index) {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0) = reg_d0.b[0];
    death_func_002251F0(index);
}

extern Range death_D_0028E4B0[];

void death_func_002251F0(u8 index) {
    func_00201C60();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < death_D_0028E4B0[index].low) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if (death_D_0028E4B0[index].high <= (s32) reg_d1.h[0]) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x6200) {
        if ((s32) reg_d1.h[0] >= 0x6600) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
}


void death_func_00225330(u8 index) {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x1B) = 4;
    death_func_00225360(index);
}

extern Range death_D_0028E4C0[];

void death_func_00225360(u8 index) {
    func_00201C60();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < death_D_0028E4C0[index].low) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if (death_D_0028E4C0[index].high <= (s32) reg_d1.h[0]) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5e00) {
        if ((s32) reg_d1.h[0] >= 0x6200) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
}

s32 func_00201160();

void death_func_002254A0(u8 index) {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x1B) = 4;
    func_00201160();
    *(u8 *)(reg_a6 + 0x1A) = reg_d0.b[0];
    death_func_00225500(index);
}

extern Range death_D_0028E4D0[];

void death_func_00225500(u8 index) {
    func_00201C60();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < death_D_0028E4D0[index].low) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if (death_D_0028E4D0[index].high <= (s32) reg_d1.h[0]) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x4800) {
        if ((s32) reg_d1.h[0] >= 0x5000) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
}

extern u16 D_002BD440[];

void death_func_00225640(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_00224EF0(0);
    reg_a6 = save_a6;
}

void death_func_00225680(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_00224F20(0);
    reg_a6 = save_a6;
}

extern u16 D_0029C06C[];
extern u8 death_D_006901B0[];

void death_func_002256C0(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = death_D_006901B0;
    reg_a4 += 0x10;
    *(u16 *)(reg_a6 + 4) -= D_0029C06C[0];
    death_func_00224EF0(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}

void death_func_00225730(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = death_D_006901B0;
    reg_a4 += 0x10;
    *(u16 *)(reg_a6 + 4) -= D_0029C06C[0];
    death_func_00224F20(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}


void death_func_002257A0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_00225060(0);
    reg_a6 = save_a6;
}

void death_func_002257E0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_00225090(0);
    reg_a6 = save_a6;
}

void death_func_00225820(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = death_D_006901B0;
    reg_a4 += 0x10;
    *(u16 *)(reg_a6 + 4) -= D_0029C06C[0];
    death_func_00225060(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}

void death_func_00225890(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = death_D_006901B0;
    reg_a4 += 0x10;
    *(u16 *)(reg_a6 + 4) -= D_0029C06C[0];
    death_func_00225090(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}


void death_func_00225900(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_002251D0(0);
    reg_a6 = save_a6;
}

void death_func_00225940(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_002251F0(0);
    reg_a6 = save_a6;
}

void death_func_00225980(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = death_D_006901B0;
    reg_a4 += 0x10;
    *(u16 *)(reg_a6 + 4) -= D_0029C06C[0];
    death_func_002251D0(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}

void death_func_002259F0(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = death_D_006901B0;
    reg_a4 += 0x10;
    *(u16 *)(reg_a6 + 4) -= D_0029C06C[0];
    death_func_002251F0(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}


void death_func_00225A60(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_00225330(0);
    reg_a6 = save_a6;
}

void death_func_00225AA0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_00225360(0);
    reg_a6 = save_a6;
}

void death_func_00225AE0(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = death_D_006901B0;
    reg_a4 += 0x10;
    *(u16 *)(reg_a6 + 4) -= D_0029C06C[0];
    death_func_00225330(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}

void death_func_00225B50(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = death_D_006901B0;
    reg_a4 += 0x10;
    *(u16 *)(reg_a6 + 4) -= D_0029C06C[0];
    death_func_00225360(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}


void death_func_00225BC0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_002254A0(0);
    reg_a6 = save_a6;
}

void death_func_00225C00(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_00225500(0);
    reg_a6 = save_a6;
}

void death_func_00225C40(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = death_D_006901B0;
    reg_a4 += 0x10;
    *(u16 *)(reg_a6 + 4) -= D_0029C06C[0];
    death_func_002254A0(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}

void death_func_00225CB0(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = death_D_006901B0;
    reg_a4 += 0x10;
    *(u16 *)(reg_a6 + 4) -= D_0029C06C[0];
    death_func_00225500(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}

s32 func_001F3A10();

void death_func_00225D20(void) {
    death_func_00225640();
    death_func_002256C0();
    func_001F3A10();
}


void death_func_00225D50(void) {
    death_func_00225680();
    death_func_00225730();
    func_001F3A10();
}


void death_func_00225D80(void) {
    death_func_002257A0();
    death_func_00225820();
    func_001F3A10();
}


void death_func_00225DB0(void) {
    death_func_002257E0();
    death_func_00225890();
    func_001F3A10();
}


void death_func_00225DE0(void) {
    death_func_00225900();
    death_func_00225980();
    func_001F3A10();
}


void death_func_00225E10(void) {
    death_func_00225940();
    death_func_002259F0();
    func_001F3A10();
}


void death_func_00225E40(void) {
    death_func_00225A60();
    death_func_00225AE0();
    func_001F3A10();
}


void death_func_00225E70(void) {
    death_func_00225AA0();
    death_func_00225B50();
    func_001F3A10();
}


void death_func_00225EA0(void) {
    death_func_00225BC0();
    death_func_00225C40();
    func_001F3A10();
}


void death_func_00225ED0(void) {
    death_func_00225C00();
    death_func_00225CB0();
    func_001F3A10();
}
