#include "common.h"

void func_001B9DE0(void);
void func_001BA0E0(void);


void func_001B93F0(void) {
    *(u16 *)(reg_a4 + 2) = 0xC0;
}

s32 func_001A3020();
extern u8 D_0025FA30[];

void func_001B9400() {
    s32 func_00124D90();
    *(u16 *)(reg_a4 + 2) -= 1;
    if ((s16) *(u16 *)(reg_a4 + 2) == 0) {
        reg_d0.w = 0;
        func_00124D90();
        reg_d0.h[0] = 0x13;
        reg_a0 = D_0025FA30;
        func_001A3020();
        *(s16 *)reg_a4 = 0;
    }
}

s32 func_001713B0();
extern u16 D_0026E8A0[];
extern u16 D_0026E8B0[];
extern u8 D_0028DC40[];
extern u8 D_0028DC48[];
extern u8 D_0028DC50[];

void func_001B9460(void) {
    s32 func_00124D90();
    reg_d0.w = 5;
    func_00124D90();
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x1000;
    func_001713B0();
    reg_d1.b[0] = *(D_0028DC48 + reg_d0.b[0]);
    reg_d1.b[0] += *(u8 *)(reg_a6 + 0x10D);
    if ((s32) reg_d1.b[0] >= 0x80) {
        reg_d1.b[0] = 0x80;
    }
    *(u8 *)(reg_a4 + 9) = (u8) reg_d1.b[0];
    reg_d1.b[0] = *(D_0028DC40 + reg_d0.b[0]);
    reg_d1.b[0] -= *(u8 *)(reg_a6 + 0x10A);
    if ((s8) reg_d1.b[0] < 3) {
        reg_d1.b[0] = 3;
    }
    *(s8 *)(reg_a4 + 7) = 0;
    *(u8 *)(reg_a4 + 6) = (u8) reg_d1.b[0];
    *(u8 *)(reg_a6 + 0x10D) += 2;
    if ((s32) *(u8 *)(reg_a6 + 0x10D) >= 0x80) {
        *(u8 *)(reg_a6 + 0x10D) = 0x80U;
    }
    *(u8 *)(reg_a6 + 0x10A) -= 1;
    if ((s8) *(u8 *)(reg_a6 + 0x10A) < 3) {
        *(u8 *)(reg_a6 + 0x10A) = 3U;
    }
    *(s16 *)(reg_a4 + 0xA) = 0x6000;
    *(s8 *)(reg_a4 + 0xD) = 1;
    *(s8 *)(reg_a4 + 0xC) = 4;
    func_001713B0();
    reg_d1.b[0] = *(D_0028DC50 + reg_d0.b[0]);
    *(u8 *)(reg_a4 + 0xA) = reg_d1.b[0];
    reg_a0 = (u8 *)(D_0026E8A0);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x10E);
    if ((s16) reg_d1.h[0] > 4) {
        reg_d1.h[0] = 4;
    }
    *(u16 *)(reg_a4 + 0xE) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a6 + 0x10E) += 1;
    if ((s16) *(u16 *)(reg_a6 + 0x10E) > 4) {
        *(u16 *)(reg_a6 + 0x10E) = 4U;
    }
    reg_a0 = (u8 *)(D_0026E8B0);
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x110);
    if ((s16) reg_d1.h[0] > 0x20) {
        reg_d1.h[0] = 0x20;
    }
    *(u16 *)(reg_a4 + 0x10) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a6 + 0x110) += 2;
    if ((s16) *(u16 *)(reg_a6 + 0x110) > 0x20) {
        *(u16 *)(reg_a6 + 0x110) = 0x20U;
    }
    *(s16 *)(reg_a4 + 0x12) = 0x2020;
}


s32 func_00124B20();
s32 func_001251C0();
s32 func_00125250();
s32 func_002010A0();
s32 func_002011D0();
extern u8 D_0028DC58[];

void func_001B9750(void) {
    u16 temp_a0_3;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_4;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        reg_d0.w = 1;
        func_00125250();
        if (cond_flag == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                *(u8 *)(reg_a4 + 3) = 1U;
                reg_d0.w = 1;
                func_001251C0();
                *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a4 + 6);
                *(u8 *)(reg_a0 + 5) = (u8) *(u8 *)(reg_a4 + 9);
                *(u16 *)(reg_a0 + 0xC) = (u16) *(u16 *)(reg_a6 + 0x108);
                *(u16 *)(reg_a6 + 0x108) += 2;
                if ((s16) *(u16 *)(reg_a6 + 0x108) > 0xC) {
                    *(u16 *)(reg_a6 + 0x108) = 0xCU;
                }
            }
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 1) {
        reg_d0.w = 3;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 4;
            func_00125250();
            if (cond_flag == 0) {
                reg_d0.w = 1;
                func_00125250();
                if (cond_flag == 0) {
                    *(u8 *)(reg_a4 + 3) = 2U;
                    func_002010A0();
                    reg_d0.b[0] += 0x20;
                    *(u8 *)(reg_a4 + 0x15) = (u8) reg_d0.b[0];
                } else {
                    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
                    *(u8 *)(reg_a4 + 0xB) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
                        reg_d0.w = 3;
                        if (*(s8 *)(reg_a4 + 0xD) < 0) {
                            reg_d0.w = 4;
                        }
                        func_001251C0();
                        *(s8 *)(reg_a0 + 3) = 4;
                        *(u8 *)(reg_a0 + 2) = 0;
                        *(u8 *)(reg_a4 + 0xD) *= -1;
                        if (*(s8 *)(reg_a4 + 0xD) >= 0) {
                            *(u16 *)(reg_a4 + 0xE) += 1;
                            if ((s16) *(u16 *)(reg_a4 + 0xE) > 4) {
                                *(u16 *)(reg_a4 + 0xE) = 4U;
                            }
                        }
                    }
                }
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_2 == 2) {
        *(u8 *)(reg_a4 + 0x15) -= 1;
        if ((s8) *(u8 *)(reg_a4 + 0x15) == 0) {
            reg_d0.w = 3;
            func_00125250();
            if (cond_flag == 0) {
                reg_d0.w = 4;
                func_00125250();
                if (cond_flag == 0) {
                    func_002011D0();
                    reg_d7.h[0] = reg_d0.h[0];
                    reg_d0.w = 3;
                    reg_d7.h[0] += 1;
                    func_001251C0();
                    *(s8 *)(reg_a0 + 3) = 8;
                    *(u8 *)(reg_a0 + 2) = (u8) reg_d7.b[0];
                    temp_a0_3 = *(u16 *)(reg_a4 + 0x10);
                    *(u16 *)(reg_a0 + 0x10) = temp_a0_3;
                    reg_d0.w = 4;
                    func_001251C0();
                    *(s8 *)(reg_a0 + 3) = 8;
                    *(u8 *)(reg_a0 + 2) = (u8) reg_d7.b[0];
                    *(u16 *)(reg_a0 + 0x10) = (u16) *(u16 *)(reg_a4 + 0x10);
                    *(u8 *)(reg_a4 + 3) = 3U;
                }
            }
        }
    }
    temp_a0_4 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_4 == 3) {
        reg_d0.w = 1;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 3;
            func_00125250();
            if (cond_flag == 0) {
                reg_d0.w = 4;
                func_00125250();
                if (cond_flag == 0) {
                    reg_a0 = (u8 *)D_0028DC58;
                    reg_a0 += *(u16 *)(reg_a6 + 0x106);
                    reg_d0.h[0] = *(u16 *)reg_a0;
                    if ((s16) reg_d0.h[0] < 0) {
                        reg_d7.w = 3;
                        func_002011D0();
                        if (reg_d0.b[0] == 0) {
                            reg_d7.w = 2;
                        }
                    } else {
                        *(u16 *)(reg_a6 + 0x106) += 2;
                    }
                    reg_d0.w = 3;
                    func_00124B20();
                    *(s16 *)reg_a4 = 0;
                }
            }
        }
    }
}


void func_001B9B30(void) {
    void func_00124D90(void);
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3E);
    reg_d0.b[0] += *(u8 *)(reg_a6 + 0x7E);
    if (reg_d0.b[0] == 2) {
        func_001B9DE0();
        return;
    }
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 6) = 0x2020;
    *(s16 *)(reg_a4 + 4) = 0x10;
    reg_d0.w = 8;
    func_00124D90();
}

s32 func_00124D80();
s32 func_00124F50();
s32 func_00125060();

void func_001B9BC0(void) {
    s32 func_00124D90();
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;

    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3E);
    reg_d0.b[0] += *(u8 *)(reg_a6 + 0x7E);
    if (reg_d0.b[0] == 2) {
        func_001B9DE0();
        return;
    }
    if (*(u8 *)(reg_a4 + 3) == 0) {
        func_00124D80();
        if (reg_d0.h[0] == 4) {
            reg_d0.w = 8;
            func_00124F50();
            reg_d0.w = 9;
            func_00124F50();
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 1) {
        reg_d0.w = 9;
        func_00125060();
        if (cond_flag == 0) {
            reg_d0.w = 8;
            func_00125060();
            if (cond_flag == 0) {
                *(s8 *)(reg_a4 + 2) = 1;
                *(u8 *)(reg_a4 + 3) = 2U;
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_2 == 2) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = 0xE;
            func_00124F50();
            *(u8 *)(reg_a4 + 3) = 3U;
        }
    }
    temp_a0_3 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_3 == 3) {
        reg_d0.w = 0xE;
        func_00125060();
        if (cond_flag == 0) {
            reg_d0.w = 0xC;
            func_00124F50();
            reg_d0.w = 0xD;
            func_00124F50();
            *(s8 *)(reg_a4 + 2) = 0;
            reg_d0.w = 5;
            func_00124D90();
            *(u8 *)(reg_a4 + 3) = 4U;
        }
    }
    temp_a0_4 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_4 == 4) {
        reg_d0.w = 2;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 0xC;
            func_00125060();
            if (cond_flag == 0) {
                reg_d0.w = 0xD;
                func_00125060();
                if (cond_flag == 0) {
                    reg_d0.w = 0xF;
                    func_00124F50();
                    func_001B9DE0();
                }
            }
        }
    }
}

s32 func_00124B20();                            /* extern */
extern s16 *reg_a4_as_s16_p;

void func_001B9DE0(void) {
    reg_d0.w = 1;
    func_00124B20();
    *reg_a4_as_s16_p = 0;
}


void func_001B9E10(void) {
    s32 func_00124D90();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3E);
    reg_d0.b[0] += *(u8 *)(reg_a6 + 0x7E);
    if (reg_d0.b[0] == 2) {
        func_001BA0E0();
        return;
    }
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 6) = 0x2020;
    reg_d0.w = 3;
    func_00124D90();
}

void func_001B9E90(void) {
    s32 func_00124D90();
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;

    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3E);
    reg_d0.b[0] += *(u8 *)(reg_a6 + 0x7E);
    if (reg_d0.b[0] == 2) {
        func_001BA0E0();
        return;
    }
    if (*(u8 *)(reg_a4 + 3) == 0) {
        func_00124D80();
        if (reg_d0.h[0] == 4) {
            reg_d0.w = 0x10;
            func_00124F50();
            reg_d0.w = 0x11;
            func_00124F50();
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 1) {
        reg_d0.w = 9;
        func_00125060();
        if (cond_flag == 0) {
            reg_d0.w = 8;
            func_00125060();
            if (cond_flag == 0) {
                *(s8 *)(reg_a4 + 2) = 1;
                *(u8 *)(reg_a4 + 3) = 2U;
                *(u16 *)(reg_a4 + 4) = 0x40U;
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_2 == 2) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = 8;
            func_001251C0();
            *(u8 *)(reg_a4 + 3) = 3U;
            *(u16 *)(reg_a4 + 4) = 0x40U;
            reg_d0.w = 0x12;
            func_00124F50();
            reg_d0.w = 0x13;
            func_00124F50();
        }
    }
    temp_a0_3 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_3 == 3) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) == 0) {
            reg_d7.w = 9;
            func_002011D0();
            if (reg_d0.b[0] == 0) {
                reg_d7.w = 0xA;
            }
            reg_d0.h[0] = reg_d7.h[0];
            *(u8 *)(reg_a4 + 3) = 4U;
            *(s8 *)(reg_a4 + 2) = 0;
            reg_d0.w = 5;
            func_00124D90();
        }
    }
    temp_a0_4 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_4 == 4) {
        reg_d0.w = 7;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 9;
            func_00125250();
            if (cond_flag == 0) {
                reg_d0.w = 0xA;
                func_00125250();
                if (cond_flag == 0) {
                    func_001BA0E0();
                }
            }
        }
    }
}

s32 func_00124B20();                            /* extern */

void func_001BA0E0(void) {
    reg_d0.w = 6;
    func_00124B20();
    *reg_a4_as_s16_p = 0;
}

void func_001BA110(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x80;
    *(s16 *)(reg_a4 + 6) = 0x40;
    *(s16 *)(reg_a4 + 8) = 0x404;
    *(s16 *)(reg_a4 + 0xA) = 0x6060;
    *(s16 *)(reg_a4 + 0xC) = 0x404;
}

void func_001BA160() {
    u8 temp_a0;
    u8 temp_a0_2;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) == 0) {
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 1) {
        reg_d0.w = 0xB;
        func_00125250();
        if (cond_flag == 0) {
            if (*(u8 *)(reg_a4 + 9) == 0) {
                *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
                *(u8 *)(reg_a4 + 3) = 2U;
            } else {
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
                *(u8 *)(reg_a4 + 7) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                    reg_d0.w = 0xB;
                    func_001251C0();
                    *(u8 *)(reg_a4 + 9) -= 1;
                }
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if ((temp_a0_2 == 2) && (reg_d0.w = 0xC, func_00125250(), (cond_flag == 0))) {
        if (*(u8 *)(reg_a4 + 0xD) == 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            *(u8 *)(reg_a4 + 3) = 1U;
            return;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
        *(u8 *)(reg_a4 + 0xB) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
            reg_d0.w = 0xC;
            func_001251C0();
            *(u8 *)(reg_a4 + 0xD) -= 1;
        }
    }
}

typedef struct WorkRegA4 {
    u8 pad0[3];
    u8 unk3;
    u16 unk4;
    u16 unk6;
} WorkRegA4;

extern WorkRegA4 *reg_a4_as_WorkRegA4_p;

void func_001BA2E0(void) {
    reg_a4_as_WorkRegA4_p->unk3 = 0;
    reg_a4_as_WorkRegA4_p->unk4 = 0x40;
    reg_a4_as_WorkRegA4_p->unk6 = 0x404;
}

void func_001BA310() {
    u8 temp_a0;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u8 *)(reg_a4 + 3) = 1U;
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 1) {
        reg_d0.w = 0;
        func_00125250();
        if (cond_flag == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                reg_d0.w = 0;
                func_001251C0();
            }
        }
    }
}

extern u16 D_0026E8C0[];

void func_001BA3A0(void) {
    s32 func_00124D90();
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x202;
    *(s8 *)(reg_a4 + 9) = 0xD;
    *(s16 *)(reg_a4 + 0xA) = 0x7050;
    *(s16 *)(reg_a4 + 0x14) = 0x2040;
    *(s8 *)(reg_a4 + 0x11) = 1;
    *(s8 *)(reg_a4 + 0x10) = 1;
    func_001713B0();
    reg_a0 = (u8 *)(D_0026E8C0);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a4 + 0xE) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x118);
    if ((s16) reg_d1.h[0] > 0x5) {
        reg_d1.h[0] = 5;
    }
    *(u16 *)(reg_a4 + 0xC) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a6 + 0x118) += 1;
    if ((s16) *(u16 *)(reg_a6 + 0x118) > 0x5) {
        *(u16 *)(reg_a6 + 0x118) = 5U;
    }
    reg_d0.w = 6;
    func_00124D90();
}

s32 func_00125120();
s32 func_00202140();
s32 func_00202500();

void func_001BA4D0(void) {
    u8 temp_a0;
    u8 temp_a0_2;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        func_00124D80();
        if (reg_d0.h[0] == 7) {
            reg_d0.w = 7;
            func_00125120();
            reg_d0.w = 0x14;
            func_00124F50();
            *(u16 *)(reg_a4 + 6) = 1U;
            reg_d1.w = 0x25;
            func_002011D0();
            if (reg_d0.b[0] != 0) {
                reg_d1.w = 0x1C;
                *(u16 *)(reg_a4 + 6) *= 0xFFFF;
            }
            func_002010A0();
            reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
            reg_d1.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a4 + 2) = (u8) reg_d1.b[0];
            *(u8 *)(reg_a4 + 3) = 2U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 2) {
        if (*(u8 *)(reg_a4 + 0x11) != 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0xA2);
                reg_d1.h[0] = *(u16 *)(reg_a6 + 0xA4);
                func_00202140();
                if (cond_flag == 0) {
                    if ((s8) reg_d1.b[0] > 0x27) {
                        reg_d1.w = 0x27;
                    }
                    if ((s8) reg_d1.b[0] < 0x19) {
                        reg_d1.w = 0x19;
                    }
                    reg_d0.w = 0;
                    reg_d1.h[0] = (u16) reg_d1.b[0];
                    reg_d0.h[0] = *(u16 *)(reg_a6 + 0xAC);
                    reg_d0.h[0] += 0x20;
                    func_00202500();
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d0.h[0] = (u16) reg_d0.b[0];
                    reg_d0.h[0] -= 0x20;
                    *(u16 *)(reg_a6 + 0xAC) = (u16) reg_d0.h[0];
                }
            }
        }
        reg_d0.w = 0xD;
        func_00125250();
        if (cond_flag == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
            *(u8 *)(reg_a4 + 0xB) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0xA) -= 8;
                *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
                reg_d0.w = 0xD;
                func_001251C0();
                *(u8 *)(reg_a0 + 5) = (u8) *(u8 *)(reg_a4 + 9);
                *(u8 *)(reg_a0 + 4) = (u8) *(u8 *)(reg_a4 + 0x10);
                *(u16 *)(reg_a0 + 6) = (u16) *(u16 *)(reg_a4 + 0xE);
                *(u8 *)(reg_a4 + 9) += 4;
                *(u8 *)(reg_a4 + 0x10) += 1;
                *(u16 *)(reg_a4 + 0xE) += 2;
                *(u8 *)(reg_a4 + 0x11) = 1U;
                *(u16 *)(reg_a4 + 6) *= 0xFFFF;
                *(u16 *)(reg_a4 + 0xC) -= 1;
                if ((s16) *(u16 *)(reg_a4 + 0xC) == 0) {
                    *(u16 *)(reg_a4 + 0x12) = 0x50U;
                    *(u8 *)(reg_a4 + 3) = 3U;
                }
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_2 == 3) {
        reg_d0.w = 0xD;
        func_00125250();
        if (cond_flag == 0) {
            *(u16 *)(reg_a4 + 0x12) -= 1;
            if ((s16) *(u16 *)(reg_a4 + 0x12) == 0) {
                reg_d0.w = 0xF;
                func_00124F50();
                reg_d0.w = 0x14;
                func_00125120();
                reg_d0.w = 7;
                func_00124F50();
                reg_d0.w = 2;
                func_00124B20();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}
