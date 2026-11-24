#include "common.h"
#include "entity.h"

void func_0016C620(void);

s32 func_0016C260();
s32 func_0019D230();
s32 entity_velocity();

void func_0016C4B0(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u32 temp_a1;

    if (*(u8 *)reg_a6 & 0x80) {
        func_0016C620();
        return;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    temp_a0 = *(u16 *)reg_a0;
    temp_a1 = reg_d1.w;
    reg_a0 += 2;
    reg_tmp1.h[1] = temp_a0;
    reg_tmp1.h[0] = *(u16 *)reg_a0;
    reg_d1.w = temp_a1 + (s32) reg_tmp1.w;
    reg_a0 += 2;
    temp_a0_2 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = temp_a0_2;
    reg_a0 += 2;
    reg_a0 += *(u16 *)(reg_a6 + 0xA);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d4.h[0] = 0x1D;
    func_0019D230();
    if (*(u8 *)(reg_a6 + 0xF) != 0) {
        *(u16 *)(reg_a6 + 2) += 0x20;
    } else {
        entity_velocity();
    }
    *(u8 *)(reg_a6 + 0xD) -= 1;
    if (*(u8 *)(reg_a6 + 0xD) == 0) {
        *(u8 *)(reg_a6 + 0xD) = (u8) *(u8 *)(reg_a6 + 0xC);
        *(u8 *)(reg_a6 + 0xF) = 0U;
        *(u16 *)(reg_a6 + 0xA) += 4;
        if ((s16) *(u16 *)(reg_a6 + 0xA) >= 0x78) {
            func_0016C260();
        }
    }
}

void func_0016C620(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u32 temp_a1;

    reg_tmp.h[1] = *(u16 *)(reg_a6 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    temp_a0 = *(u16 *)reg_a0;
    temp_a1 = reg_d1.w;
    reg_a0 += 2;
    reg_tmp1.h[1] = temp_a0;
    reg_tmp1.h[0] = *(u16 *)reg_a0;
    reg_d1.w = temp_a1 + (s32) reg_tmp1.w;
    reg_a0 += 2;
    temp_a0_2 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = temp_a0_2;
    reg_a0 += 2;
    reg_a0 += *(u16 *)(reg_a6 + 0xA);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d4.h[0] = 0x1D;
    func_0019D230();
    if (*(u8 *)(reg_a6 + 0xF) != 0) {
        *(u16 *)(reg_a6 + 2) += 0x20;
    } else {
        entity_velocity();
    }
    *(u8 *)(reg_a6 + 0xD) -= 1;
    if (*(u8 *)(reg_a6 + 0xD) == 0) {
        *(u8 *)(reg_a6 + 0xD) = (u8) *(u8 *)(reg_a6 + 0xC);
        *(u8 *)(reg_a6 + 0xF) = 0U;
        *(u16 *)(reg_a6 + 0xA) += 4;
        if ((s16) *(u16 *)(reg_a6 + 0xA) >= 0x44) {
            func_0016C260();
        }
    }
}

extern u8 D_0026B090[];
extern u16 D_0028E7B0;


void func_0016C770(void) {
    u32 save_d0;
    u32 save_d1;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] |= 0x8000;
    reg_a2 = *(u8 **)(D_0026B090 + (reg_d0.h[0] & ~3));
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = ENTITY(reg_a6)->y.h;
    reg_a0 += 2;
    *(u16 *)reg_a0 = ENTITY(reg_a6)->x.h;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    cond_flag = 0;
    reg_a2 += 2;
    reg_a0 += 2;
    D_0028E7B0 += 1;
}

extern u16 D_0028E7AC;

void func_0016CA20(void) {
    reg_a2 = (u8 *)D_0026B090;
    reg_d1.h[0] = reg_d0.h[0];
    reg_a2 = *(u8 **)(D_0026B090 + (reg_d0.h[0] & ~3));
    reg_d1.h[0] |= 0x8000;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d6.h[0];
    reg_a0 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xFFFF;
    reg_a0 += 2;
    reg_a2 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) D_0028E7AC;
    reg_a0 += 2;
    D_0028E7B0 += 1;
    D_0028E7AC += 0xC;
    if (D_0028E7AC == 0x9C) {
        D_0028E7AC = 0;
    } else if (D_0028E7AC == 0xA2) {
        D_0028E7AC = 6;
    }
}

void enemy_set_entity_count(s32 mode);

void func_0016CCD0(void) {
    enemy_set_entity_count(0);
}

s32 enemy_set_task_work();                            /* extern */
s32 enemy_init_entities();                            /* extern */
extern s32 D_0025B0E0[];
extern s32 D_0028CA00;
extern s32 *reg_a0_as_s32_p;

void func_0016CCE0(void) {
    reg_a0_as_s32_p = D_0025B0E0;
    enemy_init_entities();
    reg_a0_as_s32_p = &D_0028CA00;
    reg_d0.w = 1;
    enemy_set_task_work();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
}

s32 func_00137C10();                            /* extern */
s32 func_0016A8E0();                            /* extern */
s32 func_0016A9B0();                            /* extern */
s32 func_0019BE80();                            /* extern */
s32 func_00203670();                            /* extern */

void func_0016CD40(void) {
    s64 temp_v0_2;
    u16 temp_v0;

    func_00203670();
    temp_v0 = *(u16 *)(reg_a5 + 0x18);
    if (temp_v0 != 0) {
        *(u16 *)(reg_a5 + 0x18) = (u16) (temp_v0 - 1);
    } else {
        func_0016A8E0();
        if (reg_d0.w & 0x40) {
            func_00137C10();
            temp_v0_2 = (s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30;
            if ((temp_v0_2 < 5) && (temp_v0_2 >= 0)) {
                reg_d0.h[0] *= 4;
                func_0016A9B0();
            }
        }
    }
    func_0019BE80();
}
