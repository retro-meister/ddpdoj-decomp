#include "common.h"
#include "sdk/ps2sdk.h"
#include "pad.h"

void func_00226440(void);
void func_00226450(void);
void func_00226490(void);
void func_002264D0(void);
s32 func_00226620(void);
s32 func_00226700(void);

s32 func_00226830();
s32 func_00226850();
s32 func_00226890();
s32 func_002268A0();
s32 func_002269B0();
extern u8 D_0028EC30;
extern u8 D_0028EC3C_as_u8;

s32 func_00226260(void) {
    if (D_0028EC30 == 0) {
        switch (D_0028EC3C_as_u8) {
        case 0:
            return 0;
        case 1:
            func_00226440();
            break;
        case 2:
            func_00226450();
            break;
        case 3:
            func_00226490();
            break;
        case 4:
            func_002264D0();
            break;
        case 5:
            return func_00226620();
        case 6:
            return func_00226700();
        case 7:
            func_00226830();
            break;
        }
    } else {
        switch (D_0028EC3C_as_u8) {
        case 0:
            return 0;
        case 1:
            func_00226440();
            break;
        case 2:
            func_00226850();
            break;
        case 3:
            func_00226890();
            break;
        case 4:
            func_002268A0();
            break;
        case 5:
            printf("program error\n");
            break;
        case 6:
            return func_002269B0();
        case 7:
            func_00226830();
            break;
        }
    }
    return 1;
}

extern s8 D_0028EC3C;
extern s8 D_0028EC44;
extern s32 D_0028EC48;

void func_002263C0(void) {
    D_0028EC48 = 0;
    D_0028EC44 = 0;
    D_0028EC3C = 0;
}

extern s8 D_0028EC2C;
extern s8 D_0028EC30_as_s8;
extern s8 D_0028EC34_as_s8;

void func_002263D0(s8 arg0, s8 arg1, s8 arg2) {
    D_0028EC34_as_s8 = arg1;
    D_0028EC2C = arg0;
    D_0028EC3C = 1;
    D_0028EC30_as_s8 = arg2;
}

void func_002263F0(void) {
    D_0028EC3C = 7;
    D_0028EC44 = 2;
}

s32 func_00236900();                            /* extern */
extern s32 D_0028ED04;

void func_00226410(void) {
    D_0028ED04 = 0;
    func_00236900();
    D_0028EC3C = 2;
}

extern s8 D_0028EC40;


void func_00226440(void) {
    D_0028EC48 = 0;
    D_0028EC44 = 0;
    D_0028EC40 = 0;
    func_00226410();
}

s32 func_00233DA0();                                /* extern */
extern s8 D_0028EB04;
extern s32 D_0028EB90;

void func_00226450(void) {
    if (func_00233DA0() != 0) {
        D_0028EC3C = 3;
        D_0028EC44 = 1;
        D_0028EB90 = 0x40;
        D_0028EB04 = 1;
    }
}

s32 func_00233DA0();                                /* extern */

void func_00226490(void) {
    if (func_00233DA0() == 0) {
        func_00226410();
        return;
    }
    D_0028EC3C = 4;
}

s32 sfx_menu_confirm();
s32 sfx_menu_move();
s32 func_00233DA0();
extern u8 D_0028EC34;
extern s8 D_0028EC38_as_s8;
extern u8 D_006A0E50[];
void func_002264D0(void) {
    s32 temp_a0;
    s32 temp_a0_3;
    u16 temp_a0_2;

    if (func_00233DA0() == 0) {
        func_00226410();
        return;
    }
    temp_a0 = g_pad_trigger[D_0028EC34];
    if (temp_a0 & 0x40) {
        sfx_menu_confirm();
        func_002263F0();
    } else if (temp_a0 & 0x20) {
        D_0028EC38_as_s8 = 0;
        if (D_0028EC2C == 1) {
            D_0028EC3C = 5;
            sfx_menu_confirm();
        } else {
            temp_a0_2 = *(u16 *)(D_006A0E50 + (D_0028EC40 << 0xA));
            if ((temp_a0_2 != 0) && (temp_a0_2 != 3)) {
                D_0028EC3C = 6;
                sfx_menu_confirm();
            }
        }
    }
    temp_a0_3 = g_pad_repeat[D_0028EC34];
    if (temp_a0_3 & 0x1000) {
        sfx_menu_move();
        D_0028EC40 -= 1;
        if (0 > D_0028EC40) {
            D_0028EC40 = 9;
        }
    } else if (temp_a0_3 & 0x4000) {
        sfx_menu_move();
        D_0028EC40 += 1;
        if (D_0028EC40 >= 0xA) {
            D_0028EC40 = 0;
        }
    }
}

s32 func_0022C750();
s32 func_00233EC0();
s32 func_00236960();
extern s32 D_0028EABC;
extern u8 D_0028EC38;
extern s32 D_0028ECC0;
extern s32 D_0028ED0C;

s32 func_00226620(void) {
    switch (D_0028EC38) {
    case 0:
        D_0028ED0C = 0;
        D_0028EC38 += 1;
    case 1:
        func_0022C750(D_0028EC40 + 1);
        if (D_0028ED0C != 0) {
            func_00233EC0();
            D_0028ED0C = 0;
            D_0028ED04 = 0;
            D_0028EC38 += 1;
            D_0028EABC = D_0028ECC0;
            if (D_0028ECC0 != 0) {
                func_00236960(D_0028EC40);
            }
        }
        break;
    case 2:
        if (func_00233DA0() != 0) {
            D_0028EB04 = 1;
            D_0028EB90 = 0x40;
            D_0028EC3C = 4;
            D_0028EC38 = 0;
            if (D_0028EABC != 0) {
                return 2;
            }
        }
        break;
    }
    return 1;
}

s32 delta_encode(s32 *);                   /* extern */
s32 func_0022C760(s32);                         /* extern */
s32 func_00233EC0();                            /* extern */
s32 func_0023DBF0(s32 *);                   /* extern */
extern s8 D_0028EC28;
extern s32 D_0028ECC4;
extern u8 D_0028ED30;
extern u8 D_0028ED31;
extern u8 D_0028ED32;
extern u8 D_0028ED33;
extern u8 D_0028ED34;
extern u8 D_0028ED35;
extern u8 D_0028ED36;
extern u8 D_0028ED37;
extern s32 D_006A4800_as_s32_a[];
extern s32 D_006C58A0_as_s32_a[];
extern u8 D_006C58D8[];
extern u8 D_006C58D9[];
extern u8 D_006C58DA[];
extern u8 D_006C58DB[];
extern u8 D_006C58DC[];
extern u8 D_006C58DD[];
extern u8 D_006C58DE[];
extern u8 D_006C58DF[];
extern s32 D_006C5CA0_as_s32_a[];

s32 func_00226700(void) {
    switch (D_0028EC38) {                           /* irregular */
    case 0:
        D_0028ED0C = 0;
        D_0028EC38 += 1;
        /* fallthrough */
    case 1:
        func_0022C760(D_0028EC40 + 1);
        if (D_0028ED0C != 0) {
            func_00233EC0();
            D_0028EC3C = 4;
            D_0028ED0C = 0;
            D_0028EB04 = 1;
            D_0028EC38 = 0;
            D_0028EB90 = 0x40;
            D_0028EC28 = D_0028EC40;
            if (D_0028ECC4 != 0) {
                memcpy(D_006C58A0_as_s32_a, D_006A4800_as_s32_a, 0x202E8);
                delta_encode(D_006C5CA0_as_s32_a);
                func_0023DBF0(D_006C58A0_as_s32_a);
                D_0028ED30 = D_006C58D8[0];
                D_0028ED31 = D_006C58D9[0];
                D_0028ED32 = D_006C58DA[0];
                D_0028ED33 = D_006C58DB[0];
                D_0028ED34 = D_006C58DC[0];
                D_0028ED35 = D_006C58DD[0];
                D_0028ED36 = D_006C58DE[0];
                D_0028ED37 = D_006C58DF[0];
                return 3;
            }
        }
    default:
        return 1;
    }
}
