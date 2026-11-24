#include "common.h"
#include "sdk/ps2sdk.h"

void func_0022C7B0(void);
void func_0022C870();
void func_0022C960(void);
void func_0022CC20();
void func_0022CC60();
void func_0022CFE0(void);
void func_0022D2C0(void);
void func_0022D300(void);
void func_0022D380(void);
void func_0022D550(void);
void func_0022DFF0(void);
void func_0022E180(void);
void func_0022E410(void);
void func_0022E6B0(void);
void func_0022E710(void);
void func_0022F070(void);
void func_0022FE40(void);
void func_00230010(void);
void func_00230230(void);
void func_00230840(void);
void func_00230CD0(void);
void func_00230FC0(void);
void func_00231520(void);
s32 func_00231840(void);
void func_002319B0(void);
void func_00232270(void);
void func_00232430(void);
void func_00232710(void);
void func_002329F0(void);
void func_00232BE0(void);
void func_00232DE0(void);
void func_00233BE0(void);
void func_00233EE0(void);
void func_00233F50(void);
void func_00234150(s32 arg0);
void func_00234200(void);
void func_00234230(void);
void func_00234250(s32 arg0, s32 arg1);
void func_002342D0(void);
void func_002342F0(s32 arg0);
void func_00234370(s32 index);
void func_002343A0(void);
void func_002343C0(void);
void func_002343E0(void);
void func_00234400(s32 index);
void func_00234430(s32 index);
void func_00234460(s32 arg0);
s32 func_00234580(s32 index);
void func_002345B0(void);
void func_00235820(void);
void func_00236680(void);
void func_00236900(void);

s32 overlay_flush();                            /* extern */
s32 frame_image_draw(s32);                         /* extern */
extern u8 D_0028E268;
extern s32 D_0028ED10;

void func_0022C5A0(void) {
    if ((D_0028E268 != 0) && (D_0028ED10 != 0)) {
        frame_image_draw(D_0028ED10 & 0xFFFF);
        overlay_flush();
    }
}

extern s32 reg_a0_as_s32;
extern void func_00222F90(s32 x, s32 y, s32 value);

void func_0022C5E0(s64 x, s32 workAddress, s32 unusedA2, s32 unusedA3,
                   s32 unusedT0, s32 value)
{
    s32 savedWorkAddress = reg_a0_as_s32;

    reg_a0_as_s32 = workAddress;
    func_00222F90(0x1C0 - (s16)x, 0x18, value & 0xFFFF);
    reg_a0_as_s32 = savedWorkAddress;
}

s32 cd_load_file(s32 *, s32 *);        /* extern */
extern s32 D_00271D20[];
extern s32 D_00271D40[];
extern s32 g_cd_last_read_size_as_s32;
extern s8 D_0028ECD4;
extern s32 D_0028ED00;
extern s32 D_0028ED04;
extern s32 D_0028ED0C;
extern s32 D_0028ED14;
extern s32 D_0028ED18;
extern s32 D_0028ED24;
extern s32 D_0028ED28;
extern s32 D_0068E580_as_s32_a[];
extern s32 D_00696D80_as_s32_a[];

void func_0022C630(void) {
    cd_load_file(D_00696D80_as_s32_a, D_00271D20);
    D_0028ED28 = g_cd_last_read_size_as_s32;
    cd_load_file(D_0068E580_as_s32_a, D_00271D40);
    D_0028ED24 = g_cd_last_read_size_as_s32;
    func_0022D2C0();
    D_0028ED0C = 0;
    D_0028ED18 = 0;
    D_0028ED14 = 0;
    D_0028ED10 = 0;
    D_0028ED04 = 0;
    D_0028ED00 = 0;
    D_0028ECD4 = 0;
}

extern s32 D_0028ED1C;
extern s32 D_0028ED20;
extern u8 D_0028ECBC_as_u8;


void func_0022C6A0(s32 value) {
    D_0028ED1C = value;
    D_0028ED20 = 0;
    D_0028ECBC_as_u8 = 0;
    func_0022C7B0();
}

extern s8 D_0028ECBC;

void func_0022C6B0(s32 arg0) {
    D_0028ED1C = arg0;
    D_0028ECBC = 1;
    D_0028ED20 = 0;
    func_0022C7B0();
}

void func_0022C6D0(s32 value) {
    D_0028ED1C = value;
    D_0028ED20 = 1;
    D_0028ECBC_as_u8 = 0;
    func_0022C7B0();
}

void func_0022C6F0(void) {
    D_0028ED20 = 4;
    D_0028ECBC_as_u8 = 1;
    func_0022C7B0();
}


void func_0022C710(void) {
    D_0028ED1C = 0;
    D_0028ED20 = 3;
    D_0028ECBC_as_u8 = 0;
    func_0022C7B0();
}

void func_0022C730(void) {
    D_0028ED20 = 6;
    D_0028ECBC = 1;
    D_0028ED1C = 0;
    func_0022C7B0();
}

void func_0022C750(s32 arg0) {
    D_0028ED1C = arg0;
    D_0028ED20 = 0;
    D_0028ECBC_as_u8 = 0;
    func_0022C7B0();
}

void func_0022C760(s32 arg0) {
    D_0028ED1C = arg0;
    D_0028ED20 = 1;
    D_0028ECBC_as_u8 = 1;
    func_0022C7B0();
}

void func_0022C780(void) {
    if (D_0028ED00 == 0) {
        D_0028ED1C = 0;
        D_0028ECD4 = 1;
        D_0028ED20 = 7;
        D_0028ECBC = 1;
    }
    func_0022C7B0();
}

s32 text_queue_clear_all();                            /* extern */
extern s32 D_0028ED08;

void func_0022C7B0(void) {
    text_queue_clear_all();
    switch (D_0028ED18) {                           /* irregular */
    case 0:
        func_0022C870(D_0028ED18);
        break;
    case 1:
        func_0022CC60(D_0028ED18);
        break;
    case 2:
        func_0022CC20(D_0028ED18);
        break;
    }
    if (D_0028ED08 == 0) {
        if (D_0028ED10 < 0x80) {
            D_0028ED10 += 8;
            return;
        }
        D_0028ED10 = 0x80;
        return;
    }
    if (D_0028ED10 > 0) {
        D_0028ED10 -= 8;
        return;
    }
    D_0028ED10 = 0;
}

extern s8 D_0028E268_as_s8;
extern s32 D_0028ECC0;
extern s32 D_0028ECC4;
extern s32 D_0028ECCC;
extern s8 D_0028ECD8_as_s8;
extern s8 D_0028ECF0_as_s8;
extern s8 D_0028ECFC_as_s8;
extern u32 D_0028ED20_as_u32;
extern s32 D_006A0E40_as_s32_a4[4];

void func_0022C870() {
    D_0028E268_as_s8 = 1;
    D_0028ED10 = 0;
    D_0028ED08 = 0;
    D_006A0E40_as_s32_a4[0] = 0;
    D_006A0E40_as_s32_a4[1] = 0;
    D_006A0E40_as_s32_a4[2] = 0;
    D_006A0E40_as_s32_a4[3] = 0;
    D_0028ED0C = 0;
    D_0028ECC4 = 0;
    D_0028ECC0 = 0;
    D_0028ECD8_as_s8 = 0;
    D_0028ECF0_as_s8 = 0;
    D_0028ECCC = 0;
    D_0028ED00 = 0;
    D_0028ED18 += 1;
    switch (D_0028ED20_as_u32) {
    case 0:
        D_0028ECFC_as_s8 = 0xA;
        func_002345B0();
        func_0022C960();
        break;
    case 1:
    case 4:
    case 6:
    case 7:
        D_0028ECFC_as_s8 = 0x14;
        break;
    case 2:
        D_0028ECFC_as_s8 = 0x28;
        break;
    case 3:
        D_0028ECFC_as_s8 = 0;
        break;
    case 5:
        D_0028ECFC_as_s8 = 0x46;
        break;
    case 8:
        D_0028ECFC_as_s8 = 0x50;
        break;
    }
}

extern u32 D_0028ED1C_as_u32;
extern s8 D_006A4800_as_s8_a[];
extern s32 D_006C4AE8[];
extern s8 D_006C4EF0_as_s8_a[];
extern s32 D_006C5494[];

void func_0022C960(void) {
    s32 size;
    s32 i;
    s8 *data;
    s32 sum;

    switch (D_0028ED1C_as_u32) {
    case 0:
        data = D_006C4EF0_as_s8_a;
        size = 0x5A4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        size = 0x202E8;
        data = D_006A4800_as_s8_a;
        break;
    }
    sum = 0;
    for (i = 0; i < size; i++) {
        sum ^= *data++;
    }
    printf("put flg[%d]size[%d]sum[%x]\n", D_0028ED1C_as_u32, size, sum);
    switch (D_0028ED1C_as_u32) {
    case 0:
        D_006C5494[0] = sum;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        D_006C4AE8[0] = sum;
        break;
    }
}


s32 func_0022CAB0(void) {
    s32 size;
    s32 i;
    s8 *data;
    s32 sum;
    s32 result;

    switch (D_0028ED1C_as_u32) {
    case 0:
        data = D_006C4EF0_as_s8_a;
        size = 0x5A4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        size = 0x202E8;
        data = D_006A4800_as_s8_a;
        break;
    }
    sum = 0;
    for (i = 0; i < size; i++) {
        sum ^= *data++;
    }
    printf("flg[%d]size[%d]sum[%x]\n", D_0028ED1C_as_u32, size, sum);
    result = 0;
    switch (D_0028ED1C_as_u32) {
    case 0:
        if (D_006C5494[0] != sum) {
            result = 1;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        if (D_006C4AE8[0] != sum) {
            result = 1;
        }
        break;
    }
    return result;
}


void func_0022CC20() {
    func_0022D2C0();
    D_0028E268_as_s8 = 0;
    D_0028ED0C = 1;
    D_0028ED18 = 0;
    D_0028ED14 = 0;
    D_0028ED00 = 0;
    D_0028ECD4 = 0;
}


void func_0022CC60() {
    func_0022CFE0();
}

extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s32 D_0028ECAC;
extern s32 D_0028ECB0;
extern u8 D_0028ECB4_as_u8;
extern s32 D_0028ECB8;

s32 func_0022CC70(s32 arg0) {
    s32 sceMcSync(s32, s32, s32 *);
    s32 sceMcGetInfo(s32, s32, s32 *, u8 *, s32 *);
    s32 result;
    s32 ret;
    s32 tries;

    tries = 0;
retry:
    D_0028ECAC = sceMcGetInfo(D_0028EC70, D_0028EC74, &D_0028ECB8, &D_0028ECB4_as_u8, &D_0028ECB0);
    if (D_0028ECAC != 0) {
        sceGsSyncV(0);
        sceMcSync(0, 0, &result);
        goto retry;
    }
    sceMcSync(0, 0, &result);
    ret = 0;
    switch (result) {
    case 0:
        if (D_0028ECB0 == 0) {
            ret = 1;
        }
        if (D_0028ECB8 != 2) {
            ret = 2;
        }
        break;
    case -1:
    case -2:
        ret = 4;
        break;
    default:
        ret = 3;
        break;
    }
    if (ret != 0 && (arg0 != 1 || ret != 4)) {
        sceGsSyncV(0);
        tries++;
        if (tries < 6) {
            goto retry;
        }
    }
    return ret;
}

extern s32 D_0028ECB4;
extern s32 D_0028ECC8;
extern s32 D_0028ECD0;

void func_0022CDB0(s32 arg0) {
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    s32 sceMcGetInfo(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 *arg4);
    s32 result;
    s32 error;

    switch (D_0028ECCC) {
    case 0:
        if (sceMcSync(1, 0, &result) != 0) {
            D_0028ECC8 = 0;
            D_0028ECD0 = 6;
            D_0028ECCC += 1;
        }
        break;
    case 1:
        D_0028ECAC = sceMcGetInfo(D_0028EC70, D_0028EC74, &D_0028ECB8, &D_0028ECB4, &D_0028ECB0);
        if (D_0028ECAC == 0) {
            D_0028ECCC += 1;
        }
        break;
    case 2:
        if (sceMcSync(1, 0, &result) != 0) {
            error = 0;
            switch (result) {
            case 0:
                if (D_0028ECB0 == 0) {
                    error = 1;
                }
                if (D_0028ECB8 != 2) {
                    error = 2;
                }
                break;
            case -1:
            case -2:
                error = 4;
                break;
            default:
                error = 3;
                break;
            }
            D_0028ECC8 = error;
            if ((error == 0) || ((arg0 == 1) && (error == 4))) {
                D_0028ECCC = 0;
                D_0028ECD0 = 0;
            } else {
                D_0028ECCC = 1;
                D_0028ECD0 -= 1;
                if (D_0028ECD0 <= 0) {
                    D_0028ECCC = 0;
                    D_0028ECD0 = 0;
                }
            }
        }
        break;
    }
}

extern char *D_00271E30[];
extern char *D_00271E50[];
extern char *D_0028DDC0[2];
extern u8 D_0028ECE8;
extern u16 D_0028ED10_as_u16;

void func_0022CF20(void) {
    void func_0022C5E0(s32 x, char *text, s32 a, s32 b, s32 c, s32 d, s32 e);
    if (D_0028ECBC != 0) {
        func_0022C5E0(0x64, D_00271E50[D_0028ED20], 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
    } else {
        func_0022C5E0(0x64, D_00271E30[D_0028ED20], 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
    }
    func_0022C5E0(0x78, D_0028DDC0[D_0028ECE8], 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
}

extern u8 D_0028ECFC;

void func_0022CFE0(void) {
    switch (D_0028ECFC) {
    case 0x0:
        func_0022D2C0();
        D_0028ECFC = 0x32;
        break;
    case 0x1:
        break;
    case 0x2:
        func_0022D300();
        break;
    case 0xA:
        func_0022D380();
        break;
    case 0xB:
        func_0022D550();
        break;
    case 0xC:
        func_0022DFF0();
        break;
    case 0xD:
        func_0022E410();
        break;
    case 0x10:
        func_0022E6B0();
        break;
    case 0x11:
        func_0022FE40();
        break;
    case 0x12:
        func_0022E180();
        break;
    case 0x14:
        func_00230010();
        break;
    case 0x15:
        func_00230230();
        break;
    case 0x16:
        func_00230840();
        break;
    case 0x17:
        func_00230CD0();
        break;
    case 0x19:
        func_00232270();
        break;
    case 0x1B:
        func_00231520();
        break;
    case 0x1E:
        func_00232430();
        break;
    case 0x1F:
        func_00232710();
        break;
    case 0x28:
        func_002329F0();
        break;
    case 0x29:
        func_00232BE0();
        break;
    case 0x32:
        func_00232DE0();
        break;
    case 0x46:
        func_00233BE0();
        break;
    case 0x50:
        func_00236680();
        break;
    }
}

void func_0018D4E0(void);
void func_0018D9B0(void);
void func_0018D9F0(void);
void func_0018DA30(void);

void func_0022D240(s32 arg0) {
    if (arg0 == 2) {
        func_0018DA30();
        return;
    }
    if (arg0 == 1) {
        func_0018D9F0();
    } else if (arg0 == 10) {
        func_0018D9B0();
    } else if (arg0 == 11) {
        func_0018D4E0();
    }
}

extern s8 D_0028ECE0_as_s8;
extern s8 D_0028ECE4_as_s8;
extern s8 D_0028ECE8_as_s8;
extern s8 D_0028ECEC_as_s8;
extern s8 D_0028ECF8_as_s8;
extern s8 D_0028ED38;

void func_0022D2C0(void) {
    D_0028ED38 = 0;
    D_0028ECE8_as_s8 = 0;
    D_0028ECEC_as_s8 = 1;
    D_0028ECF0_as_s8 = 0;
    D_0028ECE0_as_s8 = 0;
    D_0028ECE4_as_s8 = 0;
    D_0028ECF8_as_s8 = 0;
    D_0028ECD8_as_s8 = 0;
    D_0028ECD0 = 0;
    D_0028ECCC = 0;
    D_0028ECC8 = 0;
}

void func_0022D300(void) {
    func_0022CF20();
    D_0028ECE8_as_s8 = 0;
    D_0028EC70 = 0;
    D_0028EC74 = 0;
    D_0028ECF0_as_s8 = 0;
    if (D_0028ED20 == 0) {
        D_0028ECFC_as_s8 = 0xB;
    } else {
        if ((D_0028ED20 == 1) || (D_0028ED20 == 4) || (D_0028ED20 == 6) || (D_0028ED20 == 7)) {
            D_0028ECFC_as_s8 = 0x15;
        } else {
            D_0028ECFC_as_s8 = 0x29;
        }
    }
}

extern u16 D_0028EC9C;
extern s16 D_0028ECA0_as_s16;
extern u16 D_0028ECA4;
extern s8 D_0028ECDC_as_s8;
extern u8 D_0028ECEC;
extern u8 D_0028ECF0;
extern s32 D_0057CC78[];
void func_0022D380(void) {
    s32 temp_v0;
    s32 var_v1;

    if (D_0028ECBC != 0) {
        D_0028ECF0 = 0;
        D_0028ECFC_as_s8 = 2;
        return;
    }
    func_0022CF20();
    func_00234430(D_0028ED1C);
    switch (D_0028ECF0) {                           /* irregular */
    case 0:
        D_0028ECEC = 1;
        D_0028ECF0 += 1;
        D_0028ECA0_as_s16 = 0xCE;
        D_0028ECA4 = 0x144;
        /* fallthrough */
    case 1:
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            D_0028ECF0 = 3;
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 0xEA;
                D_0028ECDC_as_s8 = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC_as_s8 = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 0x144;
            }
        }
        break;
    case 2:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 1;
        } else {
            temp_v0 = D_0028EC9C - D_0028ECA4;
            var_v1 = temp_v0 >> 1;
            if (temp_v0 < 0) {
                var_v1 = (s32) (temp_v0 + 1) >> 1;
            }
            if (var_v1 == 0) {
                var_v1 = 1;
                if (D_0028ECEC == 0) {
                    var_v1 = -1;
                }
            }
            D_0028ECA4 += var_v1 & 0xFFFF;
        }
        break;
    case 3:
        D_0028ECF0 = 0;
        if (D_0028ECEC == 1) {
            D_0028ECF0 = 4;
        } else {
            D_0028ECFC_as_s8 = 2;
        }
        break;
    case 4:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    }
    func_00233F50();
}

extern s32 D_00271D60[];
extern s32 D_00271FE0_as_s32_a[];
extern u8 D_0028ECF8;
extern u8 D_0069F580[];

void func_0022D550(void) {
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    s32 sceMcGetDir(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5);
    s32 strcmp(const char *a, const char *b);
    s32 result;
    s32 missing;
    s32 i;
    s32 offset;
    s32 offset2;
    s32 j;
    u8 *entry;

    func_0022CF20();
    if ((D_0028ECF0 != 0) && ((D_0028ECF0 < 10) || (D_0028ECF0 > 60))) {
        func_00234230();
    }
    switch (D_0028ECF0) {
    case 0:
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 3:
            case 4:
                D_0028ECF0 = 20;
                break;
            default:
                D_0028ECF0 += 1;
                D_0028ECF8 = 60;
                break;
            }
        }
        break;
    case 1:
        if (D_0028ECF8 != 0) {
            D_0028ECF8 -= 1;
        } else {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 0:
                D_0028ECF0 += 1;
                D_0028ECF8 = 10;
                break;
            case 1:
                D_0028ECF0 = 0;
                D_0028ECFC = 30;
                break;
            case 2:
                D_0028ECF0 = 30;
                break;
            case 3:
            case 4:
                D_0028ECF0 = 20;
                break;
            }
        }
        break;
    case 3:
        if (sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FE0_as_s32_a[D_0028ED1C], 0, 5, D_0069F580) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 10;
        }
        break;
    case 4:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                if (D_0028ECB4 < D_00271D60[D_0028ED1C * 2]) {
                    D_0028ECF0 = 50;
                } else {
                    D_0028ECF0 = 0;
                    D_0028ECFC = 18;
                }
                break;
            }
            D_0028ECF0 += 1;
            D_0028ECF8 = 10;
        }
        break;
    case 5:
        missing = 1;
        for (i = 0, offset = 0; i < 5; i++, offset += 0x40) {
            if (D_0028ED1C == 0) {
                entry = D_0069F580 + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233") == 0) && (*(s32 *)(entry + 0x10) == 0x9A8)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 1) {
                entry = D_0069F580 + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY1") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 2) {
                entry = D_0069F580 + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY2") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 3) {
                entry = D_0069F580 + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY3") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 4) {
                entry = D_0069F580 + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY4") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 5) {
                entry = D_0069F580 + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY5") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 6) {
                entry = D_0069F580 + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY6") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 7) {
                entry = D_0069F580 + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY7") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 8) {
                entry = D_0069F580 + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY8") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 9) {
                entry = D_0069F580 + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY9") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 10) {
                entry = D_0069F580 + offset;
                if ((strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY10") == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
        }
        for (j = 0, offset2 = 0; j < 5; j++, offset2 += 0x40) {
            if (D_0028ED1C == 0) {
                entry = D_0069F580 + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233") == 0) {
                    printf("--net file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 1) {
                entry = D_0069F580 + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY1") == 0) {
                    printf("--replay1 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 2) {
                entry = D_0069F580 + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY2") == 0) {
                    printf("--replay2 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 3) {
                entry = D_0069F580 + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY3") == 0) {
                    printf("--replay3 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 4) {
                entry = D_0069F580 + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY4") == 0) {
                    printf("--replay4 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 5) {
                entry = D_0069F580 + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY5") == 0) {
                    printf("--replay5 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 6) {
                entry = D_0069F580 + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY6") == 0) {
                    printf("--replay6 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 7) {
                entry = D_0069F580 + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY7") == 0) {
                    printf("--replay7 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 8) {
                entry = D_0069F580 + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY8") == 0) {
                    printf("--replay8 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 9) {
                entry = D_0069F580 + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY9") == 0) {
                    printf("--replay9 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 10) {
                entry = D_0069F580 + offset2;
                if (strcmp((char *)entry + 0x20, (char *)"BISLPS-25233REPLAY10") == 0) {
                    printf("--replay10 file size[%d]--\n", *(s32 *)(entry + 0x10));
                }
            }
        }
        if (missing != 0) {
            D_0028ECF0 = 35;
        } else {
            D_0028ECF0 = 0;
            D_0028ECFC = 13;
        }
        break;
    case 40:
        D_0028ECF0 = 0;
        D_0028ECFC = 17;
        break;
    case 10:
        func_002342D0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 40;
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 40;
        }
        break;
    case 30:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 40;
        }
        break;
    case 35:
        if (D_0028ED1C == 0) {
            func_00234250(1, 0);
        } else {
            func_00234250(1, D_0028ED1C);
        }
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 40;
        }
        break;
    case 50:
        func_00234460(D_0028ED1C);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 40;
        }
        break;
    }
}

s32 sceMcMkdir(s32 arg0, s32 arg1, s32 arg2);
extern s32 D_00271FB0[];
extern u8 D_0028ECD8;

void func_0022DFF0(void) {
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    s32 result;

    func_0022CF20();
    if (D_0028ECF0 == 1) {
        func_00234150(0);
    }
    switch (D_0028ECF0) {
    case 0:
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 != 0) {
                D_0028ECF0 = 20;
                break;
            }
            D_0028ECC0 = 0;
            if (sceMcMkdir(D_0028EC70, D_0028EC74, D_00271FB0[D_0028ED1C]) == 0) {
                D_0028ECF0 += 1;
                break;
            }
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 30;
            }
        }
        break;
    case 1:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result == 0) {
                D_0028ECD8 = 0;
                D_0028ECFC = 16;
                D_0028ECF0 = 0;
            } else {
                D_0028ECF0 = 30;
            }
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 17;
        }
        break;
    case 30:
        func_002342D0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 17;
        }
        break;
    }
}

extern u16 D_0028ECA0;
extern u8 D_0028ECDC;
extern u8 D_0028ECE0;
extern u8 D_0028ECE4;

void func_0022E180(void) {
    s32 diff;
    s32 step;

    func_0022CF20();
    if ((D_0028ECF0 != 20) && (D_0028ECF0 != 0)) {
        func_00234580(D_0028ED1C);
        func_00233F50();
    }
    switch (D_0028ECF0) {
    case 0:
        D_0028ECEC = 1;
        D_0028ECE4 = 3;
        D_0028ECA0 = 206;
        D_0028ECA4 = 324;
        D_0028ECF0 += 1;
        D_0028ECE0 = 0;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        if (D_0028ECE0 > 60) {
            func_0022CDB0(1);
            if (D_0028ECD0 == 0) {
                D_0028ECE0 = 0;
                if (D_0028ECC8 != 0) {
                    D_0028ECF0 = 20;
                    break;
                }
            }
        } else {
            D_0028ECE0 += 1;
        }
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            D_0028ECF0 = 4;
            if (D_0028ECD0 == 0) {
                D_0028ECCC = 0;
            }
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 234;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 324;
            }
        }
        break;
    case 3:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 2;
            break;
        }
        diff = D_0028EC9C - D_0028ECA4;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (D_0028ECEC == 0) {
                step = -1;
            }
        }
        D_0028ECA4 += step;
        break;
    case 4:
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 != 0) {
                D_0028ECF0 = 20;
                break;
            }
            D_0028ECF0 = 0;
            if (D_0028ECEC == 1) {
                D_0028ECFC = 17;
            } else {
                D_0028ECFC = 12;
            }
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 17;
        }
        break;
    }
}


void func_0022E410(void) {
    s32 diff;
    s32 step;

    func_0022CF20();
    if ((D_0028ECF0 != 20) && (D_0028ECF0 != 0)) {
        func_00234400(D_0028ED1C);
        func_00233F50();
    }
    switch (D_0028ECF0) {
    case 0:
        D_0028ECEC = 1;
        D_0028ECE4 = 3;
        D_0028ECA0 = 206;
        D_0028ECA4 = 324;
        D_0028ECF0 += 1;
        D_0028ECE0 = 0;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        if (D_0028ECE0 > 60) {
            func_0022CDB0(1);
            if (D_0028ECD0 == 0) {
                D_0028ECE0 = 0;
                if (D_0028ECC8 != 0) {
                    D_0028ECF0 = 20;
                    break;
                }
            }
        } else {
            D_0028ECE0 += 1;
        }
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            D_0028ECF0 = 4;
            if (D_0028ECD0 == 0) {
                D_0028ECCC = 0;
            }
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 234;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 324;
            }
        }
        break;
    case 3:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 2;
            break;
        }
        diff = D_0028EC9C - D_0028ECA4;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (D_0028ECEC == 0) {
                step = -1;
            }
        }
        D_0028ECA4 += step;
        break;
    case 4:
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 != 0) {
                D_0028ECF0 = 20;
                break;
            }
            D_0028ECF0 = 0;
            if (D_0028ECEC == 1) {
                D_0028ECFC = 17;
            } else {
                D_0028ECD8 = 1;
                D_0028ECFC = 16;
            }
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 17;
        }
        break;
    }
}


void func_0022E6B0(void) {
    switch (D_0028ED1C_as_u32) {
    case 0:
        func_0022E710();
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        func_0022F070();
        break;
    }
}

typedef struct {
    char *name[3];
} NameSet;

s32 sceMcWrite(s32 arg0, void *arg1, s32 arg2);
char *strcpy(u8 *dst, const char *src);

extern char *D_00272010_as_char_p_a[];
extern u8 D_00272040[];
extern u8 D_00272080[];
extern u8 D_002720B0[];
extern u8 D_002720E0[];
extern s32 D_0028DE1C;
extern s32 D_0028ECA8;
extern u8 D_0068E1B0[];
extern s16 D_0068E1B6[];
extern s32 D_0068E1BC[];
extern u8 D_0068E1C0[];
extern u8 D_0068E200[];
extern u8 D_0068E230[];
extern u8 D_0068E260[];
extern u8 D_0068E270[];
extern u8 D_0068E2B4[];
extern u8 D_0068E2F4[];
extern u8 D_0068E334[];
extern u8 D_00696D80[];
extern u8 D_006C4EF0[];
void func_0022E710(void) {
    s32 sceMcOpen(s32 arg0, s32 arg1, void *arg2, s32 arg3);
    s32 sceMcClose(s32 arg0);
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 result;
    NameSet names = { "icon1.ico", "icon1.ico", "icon1.ico" };

    func_0022CF20();
    switch (D_0028ECF0) {   
    case 0x0:
        D_0028ECC0 = 0;
        D_0028ECF0 += 1;
        D_0028ECE4 = 0x3C;
        break;
    case 0x1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF8 = 0xA;
            if (D_0028ECD8 == 0) {
                D_0028ECF0 += 1;
            } else {
                D_0028ECF0 = 0x24;
            }
        }
        break;
    case 0x2:
        if (sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233/icon.sys", 0x203) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x3:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECA8 = result;
                D_0028ECF0 += 1;
            }
        }
        break;
    case 0x4:
        memset(D_0068E1B0, 0, 0x3C4);
        strcpy(D_0068E1B0, (char *)"PS2D");
        strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生ゲームデータ"));
        D_0068E1B6[0] = 0xE;
        D_0068E1BC[0] = 0x60;
        memcpy(D_0068E1C0, D_00272040, 0x40);
        memcpy(D_0068E200, D_00272080, 0x30);
        memcpy(D_0068E230, D_002720B0, 0x30);
        memcpy(D_0068E260, D_002720E0, 0x10);
        strcpy(D_0068E2B4, names.name[0]);
        strcpy(D_0068E2F4, names.name[1]);
        strcpy(D_0068E334, names.name[2]);
        D_0028ECF0 += 1;
        D_0028ECF8 = 0xA;
        break;
    case 0x5:
        if (sceMcWrite(D_0028ECA8, D_0068E1B0, 0x3C4) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x6:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    D_0028ECF0 = 0x30;
                } else {
                    D_0028ECF0 = 0x2D;
                }
            } else {
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0x7:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x8:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECF0 += 1;
            }
        }
        break;
    case 0x9:
        printf("icon1 start[%d]\n", D_0028ED28);
        D_0028ECF0 += 1;
        D_0028ECF8 = 0xA;
        break;
    case 0xA:
        if (sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233/icon1.ico", 0x203) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0xB:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECA8 = result;
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0xC:
        if (sceMcWrite(D_0028ECA8, D_00696D80, D_0028ED28) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0xD:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    D_0028ECF0 = 0x30;
                } else {
                    D_0028ECF0 = 0x2D;
                }
            } else {
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0xE:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0xF:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECF0 = 0x24;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0x24:
        if (sceMcOpen(D_0028EC70, D_0028EC74, D_00272010_as_char_p_a[D_0028ED1C], 0x203) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x25:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECA8 = result;
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0x26:
        if (sceMcWrite(D_0028ECA8, D_006C4EF0, 0x9A8) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x27:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    D_0028ECF0 = 0x30;
                } else {
                    D_0028ECF0 = 0x2D;
                }
            } else {
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0x28:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x29:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECF0 = 0x32;
                func_0022D240(0xA);
                D_0028ECF8 = 0x3C;
            }
        }
        break;
    case 0x32:
        func_0022C5E0(0xC8, D_0028DE1C, 0, 0x14, 0xE, D_0028ED10, 0x64);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 += 1;
        }
        break;
    case 0x33:
        D_0028ECC0 = 1;
        D_0028ECF0 += 1;
        break;
    case 0x34:
        D_0028ED08 = 1;
        if ((s32) D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 0x2D:
        func_0022D240(0xB);
        D_0028ECF0 += 1;
    case 0x2E:
        func_002342D0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 0x11;
        }
        break;
    case 0x30:
        func_0022D240(0xB);
        D_0028ECF0 += 1;
    case 0x31:
        func_00234460(0);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 0x11;
        }
        break;
    }
    if ((D_0028ECFC == 0x10) && ((s32) D_0028ECF0 < 0x2A)) {
        func_00234150(0);
    }
}

extern u8 D_0068E580[];
extern u8 D_006A4800[];
void func_0022F070(void) {
    s32 sceMcOpen(s32 arg0, s32 arg1, void *arg2, s32 arg3);
    s32 sceMcClose(s32 arg0);
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 ret;
    s32 result;
    NameSet names = { "icon1.ico", "icon1.ico", "icon1.ico" };

    func_0022CF20();
    switch (D_0028ECF0) {   
    case 0x0:
        D_0028ECC0 = 0;
        D_0028ECF0 += 1;
        D_0028ECE4 = 0x3C;
        break;
    case 0x1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF8 = 0xA;
            if (D_0028ECD8 == 0) {
                D_0028ECF0 += 1;
            } else {
                D_0028ECF0 = 0x24;
            }
        }
        break;
    case 0x2:
        if (D_0028ED1C == 1) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY1/icon.sys", 0x203);
        }
        if (D_0028ED1C == 2) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY2/icon.sys", 0x203);
        }
        if (D_0028ED1C == 3) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY3/icon.sys", 0x203);
        }
        if (D_0028ED1C == 4) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY4/icon.sys", 0x203);
        }
        if (D_0028ED1C == 5) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY5/icon.sys", 0x203);
        }
        if (D_0028ED1C == 6) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY6/icon.sys", 0x203);
        }
        if (D_0028ED1C == 7) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY7/icon.sys", 0x203);
        }
        if (D_0028ED1C == 8) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY8/icon.sys", 0x203);
        }
        if (D_0028ED1C == 9) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY9/icon.sys", 0x203);
        }
        if (D_0028ED1C == 10) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY10/icon.sys", 0x203);
        }
        if (ret == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x3:
        ret = sceMcSync(1, 0, &result);
        if (ret != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECA8 = result;
                D_0028ECF0 += 1;
            }
        }
        break;
    case 0x4:
        memset(D_0068E1B0, 0, 0x3C4);
        strcpy(D_0068E1B0, (char *)"PS2D");
        if (D_0028ED1C == 1) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ１"));
        }
        if (D_0028ED1C == 2) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ２"));
        }
        if (D_0028ED1C == 3) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ３"));
        }
        if (D_0028ED1C == 4) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ４"));
        }
        if (D_0028ED1C == 5) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ５"));
        }
        if (D_0028ED1C == 6) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ６"));
        }
        if (D_0028ED1C == 7) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ７"));
        }
        if (D_0028ED1C == 8) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ８"));
        }
        if (D_0028ED1C == 9) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ９"));
        }
        if (D_0028ED1C == 10) {
            strcpy(D_0068E270, (char *)SJIS("怒首領蜂大往生リプレイデータ１０"));
        }
        D_0068E1B6[0] = 0xE;
        D_0068E1BC[0] = 0x60;
        memcpy(D_0068E1C0, D_00272040, 0x40);
        memcpy(D_0068E200, D_00272080, 0x30);
        memcpy(D_0068E230, D_002720B0, 0x30);
        memcpy(D_0068E260, D_002720E0, 0x10);
        strcpy(D_0068E2B4, names.name[0]);
        strcpy(D_0068E2F4, names.name[1]);
        strcpy(D_0068E334, names.name[2]);
        D_0028ECF0 += 1;
        D_0028ECF8 = 0xA;
        break;
    case 0x5:
        if (sceMcWrite(D_0028ECA8, D_0068E1B0, 0x3C4) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x6:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    D_0028ECF0 = 0x30;
                } else {
                    D_0028ECF0 = 0x2D;
                }
            } else {
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0x7:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x8:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECF0 += 1;
            }
        }
        break;
    case 0x9:
        printf("icon1 start[%d]\n", D_0028ED24);
        D_0028ECF0 += 1;
        D_0028ECF8 = 0xA;
        break;
    case 0xA:
        if (D_0028ED1C == 1) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY1/icon1.ico", 0x203);
        }
        if (D_0028ED1C == 2) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY2/icon1.ico", 0x203);
        }
        if (D_0028ED1C == 3) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY3/icon1.ico", 0x203);
        }
        if (D_0028ED1C == 4) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY4/icon1.ico", 0x203);
        }
        if (D_0028ED1C == 5) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY5/icon1.ico", 0x203);
        }
        if (D_0028ED1C == 6) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY6/icon1.ico", 0x203);
        }
        if (D_0028ED1C == 7) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY7/icon1.ico", 0x203);
        }
        if (D_0028ED1C == 8) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY8/icon1.ico", 0x203);
        }
        if (D_0028ED1C == 9) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY9/icon1.ico", 0x203);
        }
        if (D_0028ED1C == 10) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, "/BISLPS-25233REPLAY10/icon1.ico", 0x203);
        }
        if (ret == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0xB:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECA8 = result;
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0xC:
        if (sceMcWrite(D_0028ECA8, D_0068E580, D_0028ED24) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0xD:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    D_0028ECF0 = 0x30;
                } else {
                    D_0028ECF0 = 0x2D;
                }
            } else {
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0xE:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0xF:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECF0 = 0x24;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0x24:
        if (sceMcOpen(D_0028EC70, D_0028EC74, D_00272010_as_char_p_a[D_0028ED1C], 0x203) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x25:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECA8 = result;
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0x26:
        if (sceMcWrite(D_0028ECA8, D_006A4800, 0x206EC) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x27:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    D_0028ECF0 = 0x30;
                } else {
                    D_0028ECF0 = 0x2D;
                }
            } else {
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0x28:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x29:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECF0 = 0x32;
                func_0022D240(0xA);
                D_0028ECF8 = 0x3C;
            }
        }
        break;
    case 0x32:
        func_0022C5E0(0xC8, D_0028DE1C, 0, 0x14, 0xE, D_0028ED10, 0x64);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 += 1;
        }
        break;
    case 0x33:
        D_0028ECC0 = 1;
        D_0028ECF0 += 1;
        break;
    case 0x34:
        D_0028ED08 = 1;
        if ((s32) D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 0x2D:
        func_0022D240(0xB);
        D_0028ECF0 += 1;
    case 0x2E:
        func_002342D0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 0x11;
        }
        break;
    case 0x30:
        func_0022D240(0xB);
        D_0028ECF0 += 1;
    case 0x31:
        func_00234460(D_0028ED1C);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 0x11;
        }
        break;
    }
    if ((D_0028ECFC == 0x10) && ((s32) D_0028ECF0 < 0x2A)) {
        func_00234150(0);
    }
}

extern s32 D_0028DE18;

void func_0022FE40(void) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 diff;
    s32 step;

    func_0022CF20();
    func_0022C5E0(200, D_0028DE18, 0, 20, 14, D_0028ED10, 100);
    switch (D_0028ECF0) {
    case 0:
        D_0028ECEC = 0;
        D_0028ECF0 += 1;
        D_0028ECA0 = 180;
        D_0028ECA4 = 214;
    case 1:
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            D_0028ECF0 = 3;
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 214;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 304;
            }
        }
        break;
    case 2:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 1;
            break;
        }
        diff = D_0028EC9C - D_0028ECA4;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (D_0028ECEC == 0) {
                step = -1;
            }
        }
        D_0028ECA4 += step;
        break;
    case 3:
        D_0028ECF0 = 0;
        if (D_0028ECEC == 1) {
            D_0028ECF0 = 4;
        } else {
            D_0028ECFC = 2;
        }
        break;
    case 4:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    }
    func_00233F50();
}


void func_00230010(void) {
    s32 diff;
    s32 step;

    if (D_0028ED20 == 4) {
        if (D_0028ECBC != 0) {
            D_0028ECF0 = 0;
            D_0028ECFC = 2;
            return;
        }
        func_0022CF20();
        func_00234370(11);
    } else {
        if (D_0028ECBC != 0) {
            D_0028ECF0 = 0;
            D_0028ECFC = 2;
            return;
        }
        func_0022CF20();
        func_00234370(D_0028ED1C);
    }
    switch (D_0028ECF0) {
    case 0:
        if (D_0028ED20 == 4) {
            D_0028ECEC = 1;
            D_0028ECA4 = 324;
        } else {
            D_0028ECEC = 1;
            D_0028ECA4 = 324;
        }
        D_0028ECA0 = 206;
        D_0028ECF0 += 1;
    case 1:
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            D_0028ECF0 = 0;
            if (D_0028ECEC == 1) {
                D_0028ECF0 = 3;
            } else {
                D_0028ECFC = 2;
            }
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 234;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 324;
            }
        }
        break;
    case 2:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 1;
            break;
        }
        diff = D_0028EC9C - D_0028ECA4;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (D_0028ECEC == 0) {
                step = -1;
            }
        }
        D_0028ECA4 += step;
        break;
    case 3:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    }
    func_00233F50();
}

extern s32 D_00272010[];
extern s32 D_0028EC90;
extern s32 D_0069F590[];

void func_00230230(void) {
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    s32 sceMcGetDir(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5);
    s32 result;
    s32 error;

    func_0022CF20();
    switch (D_0028ECF0) {
    case 0:
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 3:
            case 4:
                D_0028ECF0 = 20;
                break;
            default:
                D_0028ECF8 = 60;
                D_0028ECF0 += 1;
                break;
            }
        }
        break;
    case 1:
        func_00234230();
        if (D_0028ECF8 != 0) {
            D_0028ECF8 -= 1;
        } else {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        func_00234230();
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 0:
                D_0028ECF8 = 10;
                D_0028ECF0 += 1;
                if (D_0028ED20 == 4) {
                    D_0028ECF0 = 60;
                }
                if ((D_0028ED20 == 6) || (D_0028ED20 == 7)) {
                    D_0028ECF0 = 0;
                    D_0028ECFC = 27;
                }
                break;
            case 1:
                D_0028ECF0 = 40;
                break;
            case 2:
                D_0028ECF0 = 30;
                break;
            case 3:
            case 4:
                D_0028ECF0 = 20;
                break;
            }
        }
        break;
    case 3:
        if (sceMcGetDir(D_0028EC70, D_0028EC74, D_00272010[D_0028ED1C], 0, 99, D_0069F580) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 10;
        }
        break;
    case 4:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028ECF0 = 50;
            } else {
                D_0028ECF0 = 5;
            }
        }
        break;
    case 5:
        printf("--file size[%d]--\n", D_0069F590[0]);
        error = 0;
        if (D_0028ED1C == 0) {
            if (D_0069F590[0] != 2472) {
                error = 1;
            }
        }
        if (((u32)(D_0028ED1C - 1) <= 8) || (D_0028ED1C == 10)) {
            if (D_0069F590[0] != 0x206EC) {
                error = 1;
            }
        }
        if (error != 0) {
            D_0028ECF0 = 35;
        } else {
            D_0028ECF0 = 0;
            D_0028ECFC = 22;
        }
        break;
    case 9:
        if ((D_0028ED20 == 4) && (D_0028ECBC != 0)) {
            D_0028ECF0 = 67;
            break;
        }
        if (D_0028ECBC != 0) {
            D_0028ECF0 = 67;
        } else {
            D_0028ECF0 = 0;
            D_0028ECFC = 25;
        }
        break;
    case 60:
        D_0028EC90 = 0;
        if (sceMcGetDir(D_0028EC70, D_0028EC74, D_00272010[0], 0, 99, D_0069F580) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 10;
        }
        break;
    case 61:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC90 += 1;
            }
            D_0028ECF8 = 10;
            D_0028ECF0 += 1;
        }
        break;
    case 62:
        D_0028ECF8 = 180;
        D_0028ECF0 = 0;
        if (D_0028EC90 == 1) {
            D_0028ECF0 = 66;
        } else {
            D_0028ECFC = 23;
        }
        break;
    case 66:
        func_002342F0(11);
        if (D_0028ECBC != 0) {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 += 1;
            }
        } else {
            func_00233EE0();
            if (D_0057CC78[0] & 0x20) {
                D_0028ECF0 = 9;
            }
        }
        break;
    case 67:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 10:
        func_002343C0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 9;
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 9;
        }
        break;
    case 30:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 9;
        }
        break;
    case 35:
        if (D_0028ED1C == 0) {
            func_00234250(0, 0);
        } else {
            func_00234250(0, D_0028ED1C);
        }
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 9;
        }
        break;
    case 40:
        func_002343E0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 9;
        }
        break;
    case 50:
        func_002342F0(D_0028ED1C);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 9;
        }
        break;
    }
}

extern s32 D_0028EC94;
extern s32 D_0028EC98;
extern u8 D_0028ECD4_as_u8;

void func_00230840(void) {
    s32 sceMcOpen(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    s32 sceMcClose(s32 arg0);
    s32 sceMcRead(s32 arg0, void *arg1, s32 arg2);
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    s32 result;
    s32 status;

    func_0022CF20();
    switch (D_0028ECF0) {
    case 0:
        D_0028ECC4 = 0;
        D_0028ECF0 += 1;
        D_0028EC98 = 0;
        D_0028EC94 = 0x414;
        D_0028ECE4 = 60;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF8 = 10;
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        status = sceMcOpen(D_0028EC70, D_0028EC74, D_00272010[D_0028ED1C_as_u32], 3);
        if (status == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 30;
            }
        }
        break;
    case 3:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 30;
            } else {
                D_0028ECA8 = result;
                D_0028ECF8 = 10;
                D_0028ECF0 += 1;
            }
        }
        break;
    case 4:
        switch (D_0028ED1C_as_u32) {
        case 0:
            status = sceMcRead(D_0028ECA8, D_006C4EF0, 2472);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            status = sceMcRead(D_0028ECA8, D_006A4800, 0x206EC);
            break;
        }
        if (status == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 30;
            }
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &result) != 0) {
            D_0028ECF0 += 1;
            D_0028ECF8 = 10;
        }
        break;
    case 6:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 30;
            }
        }
        break;
    case 7:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 30;
            } else {
                D_0028ECF8 = 10;
                if (func_0022CAB0() == 0) {
                    D_0028ECF0 = 10;
                } else {
                    D_0028ECF0 = 30;
                }
            }
        }
        break;
    case 8:
        D_0028ECF0 = 10;
        break;
    case 9:
        sceMcSync(0, 0, &result);
        if (result < 0) {
            D_0028ECF0 = 30;
        } else {
            D_0028ECF0 += 1;
        }
        break;
    case 10:
        func_0022D240(10);
        D_0028ECF8 = 60;
        D_0028ECF0 += 1;
        break;
    case 11:
        func_002343A0();
        if (D_0028ECD4_as_u8 != 0) {
            D_0028ECF8 -= 1;
            if ((s32)D_0028ECF8 <= 0) {
                D_0028ECF0 += 1;
            }
        } else {
            func_00233EE0();
            if (D_0057CC78[0] & 0x20) {
                D_0028ECF0 += 1;
            }
        }
        break;
    case 12:
        D_0028ECC4 = 1;
        D_0028ECF0 += 1;
        break;
    case 13:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 30:
        func_0022D240(11);
        D_0028ECF0 += 1;
    case 31:
        func_002343C0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            if (D_0028ECBC != 0) {
                D_0028ECF0 = 13;
            } else {
                D_0028ECF0 = 0;
                D_0028ECFC = 25;
            }
        }
        break;
    }
    if ((D_0028ECF0 < 8) && (D_0028ECFC == 22)) {
        func_00234150(1);
    }
}

extern s32 D_006A0E40[];
extern s32 D_006A0E44[];
extern s32 D_006A0E48[];
extern s32 D_006A0E4C[];

void func_00230CD0(void) {
    s32 i;
    s32 count;

    func_0022CF20();
    switch (D_0028ED14) {
    case 0:
        D_006A0E40[0] = 0;
        D_0028ED14 += 1;
        D_006A0E44[0] = 0;
        D_0028ECE4 = 60;
        D_006A0E48[0] = 0;
        D_0028ECF0 = 0;
        D_006A0E4C[0] = 0;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ED14 += 1;
        }
        break;
    case 2:
        D_0028ED1C = 0;
        func_00230FC0();
        break;
    case 3:
        D_0028ED14 += 1;
        break;
    case 4:
        D_0028ED14 += 1;
        break;
    case 5:
        D_0028ED14 += 1;
        break;
    case 6:
        count = 0;
        for (i = 0; i < 4; i++) {
            if (D_006A0E40[i] != 0) {
                count++;
            }
        }
        if (count != 0) {
            func_0022D240(10);
            D_0028ED14 += 1;
            D_0028ECE4 = 60;
        } else {
            D_0028ED14 = 30;
        }
        break;
    case 7:
        func_002343A0();
        if (D_0028ECBC != 0) {
            D_0028ECE4 -= 1;
            if (D_0028ECE4 == 0) {
                D_0028ED14 = 10;
            }
        } else {
            func_00233EE0();
            if (D_0057CC78[0] & 0x20) {
                D_0028ED14 = 10;
            }
        }
        break;
    case 10:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 30:
        func_0022D240(11);
        D_0028ED14 += 1;
    case 31:
        func_002343C0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_006A0E40[0] = 0;
            D_006A0E44[0] = 0;
            D_006A0E48[0] = 0;
            D_006A0E4C[0] = 0;
            if (D_0028ECBC != 0) {
                D_0028ED14 = 10;
            } else {
                D_0028ED14 = 0;
                D_0028ECFC = 25;
                D_0028ECF0 = 0;
            }
        }
        break;
    case 35:
        func_0022D240(11);
        D_0028ED14 += 1;
    case 36:
        func_00234250(0, 0);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ED14 = 30;
        }
        break;
    }
    if ((D_0028ED14 < 6) && (D_0028ECFC == 23)) {
        func_00234150(2);
    }
}


void func_00230FC0(void) {
    s32 sceMcOpen(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    s32 sceMcClose(s32 arg0);
    s32 sceMcRead(s32 arg0, void *arg1, s32 arg2);
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    s32 sceMcGetDir(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5);
    s32 result;
    s32 error;
    s32 status;

    switch (D_0028ECF0) {
    case 0:
        D_006A0E40[D_0028ED1C] = 0;
        D_0028ECE4 = 10;
        D_0028ECF0 += 1;
        break;
    case 1:
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 3:
            case 4:
                D_0028ECF0 = 30;
                break;
            default:
                D_0028ECF8 = 10;
                D_0028ECF0 += 1;
                break;
            }
        }
        break;
    case 2:
        if (sceMcGetDir(D_0028EC70, D_0028EC74, D_00272010[D_0028ED1C], 0, 99, D_0069F580) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 20;
        }
        break;
    case 3:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028ECF0 = 20;
                break;
            }
            D_0028ECF0 += 1;
            D_0028ECF8 = 10;
        }
        break;
    case 4:
        if (sceMcOpen(D_0028EC70, D_0028EC74, D_00272010[D_0028ED1C], 3) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 20;
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 20;
                break;
            }
            printf("--file size[%d]--\n", D_0069F590[0]);
            D_0028ECF8 = 10;
            error = 0;
            if (D_0028ED1C == 0) {
                if (D_0069F590[0] != 2472) {
                    error = 1;
                }
            }
            if (error != 0) {
                D_0028ECF0 = 35;
                break;
            }
            D_0028ECF8 = 10;
            D_0028ECA8 = result;
            D_0028ECF0 += 1;
        }
        break;
    case 6:
        switch (D_0028ED1C) {
        case 0:
            status = sceMcRead(D_0028ECA8, D_006C4EF0, 2472);
            break;
        }
        if (status == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 30;
        }
        break;
    case 7:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 30;
                break;
            }
            D_0028ECF0 += 1;
            D_0028ECF8 = 10;
        }
        break;
    case 8:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 30;
        }
        break;
    case 9:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 30;
                break;
            }
            D_0028ECF8 = 10;
            if (func_0022CAB0() == 0) {
                D_0028ECF0 += 1;
                break;
            }
            printf("--chksum err--\n");
            D_0028ECF0 = 40;
        }
        break;
    case 10:
        D_0028ECF0 += 1;
        break;
    case 11:
        printf("kaku load ok[%d]\n", D_0028ED1C);
        D_006A0E40[D_0028ED1C] = 1;
        D_0028ECF0 = 0;
        D_0028ED14 += 1;
        break;
    case 20:
        printf("file nasi[%d]\n", D_0028ED1C);
        D_0028ECF0 = 0;
        D_0028ED14 += 1;
        break;
    case 30:
        printf("kaku load err[%d]\n", D_0028ED1C);
        D_0028ECF0 = 0;
        D_0028ED14 = 30;
        break;
    case 35:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 30;
        }
        break;
    case 36:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 30;
                break;
            }
            D_0028ECF0 = 0;
            D_0028ED14 = 35;
        }
        break;
    case 40:
        D_0028ECF0 = 0;
        D_0028ED14 = 35;
        break;
    }
}


void func_00231520(void) {
    s32 slot;

    func_0022CF20();
    switch (D_0028ED14) {
    case 0:
        func_00236900();
        D_0028ECF0 = 0;
        D_0028ECE4 = 2;
        D_0028ED14 += 1;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ED14 += 1;
        }
        break;
    case 2:
        D_0028ED1C = 1;
        func_002319B0();
        break;
    case 3:
        D_0028ED1C = 2;
        func_002319B0();
        break;
    case 4:
        D_0028ED1C = 3;
        func_002319B0();
        break;
    case 5:
        D_0028ED1C = 4;
        func_002319B0();
        break;
    case 6:
        D_0028ED1C = 5;
        func_002319B0();
        break;
    case 7:
        D_0028ED1C = 6;
        func_002319B0();
        break;
    case 8:
        D_0028ED1C = 7;
        func_002319B0();
        break;
    case 9:
        D_0028ED1C = 8;
        func_002319B0();
        break;
    case 10:
        D_0028ED1C = 9;
        func_002319B0();
        break;
    case 11:
        D_0028ED1C = 10;
        func_002319B0();
        break;
    case 12:
        if (D_0028ED20 == 7) {
            D_0028ED14 = 13;
        } else {
            D_0028ED14 = 20;
        }
        break;
    case 13:
        slot = func_00231840();
        if (slot == 0xFF) {
            D_0028ED14 = 20;
            break;
        }
        D_0028ED1C = slot;
        D_0028ED20 = 1;
        D_006A0E40[0] = 0;
        D_006A0E44[0] = 0;
        D_0028ECFC = 20;
        D_006A0E48[0] = 0;
        D_0028ECBC_as_u8 = 1;
        D_0028ED00 = 1;
        D_0028ED0C = 0;
        D_0028ECC4 = 0;
        D_0028ECC0 = 0;
        D_006A0E4C[0] = 0;
        D_0028ECD8 = 0;
        D_0028ECCC = 0;
        D_0028ECF0 = 0;
        printf("---next load file no[%d]\n", slot);
        break;
    case 20:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 30:
        func_0022D240(11);
        D_0028ED14 += 1;
    case 31:
        func_002343C0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            func_00236900();
            D_0028ED14 = 20;
        }
        break;
    }
    if ((D_0028ED14 < 12) && (D_0028ECFC == 27)) {
        func_00234230();
    }
}

extern u8 D_0028ED30;
extern u8 D_0028ED35;
extern u8 D_006A0E50[];
extern u8 D_006A0E88[];
extern u8 D_006A0E89[];
extern u8 D_006A0E8A[];
extern u8 D_006A0E8B[];
extern u8 D_006A0E8C[];
extern u8 D_006A0E8D[];

s32 func_00231840(void) {
    s32 i;
    s32 offset;
    u8 *save;
    s32 j;
    s32 count;
    s32 k;

    D_0028ED35 += 1;
    if (D_0028ED35 < 11) {
        printf("--next no[%d]\n", D_0028ED35);
        for (i = 0, offset = 0; i < 10; i++, offset += 0x400) {
            save = D_006A0E50 + offset;
            printf("[%d][%d][%d][%d][%d]-[%d] no[%d]\n", save[0x38], save[0x39], save[0x3A], save[0x3B], save[0x3C], save[0x3D], i);
            count = 0;
            if (*(u16 *)save == 1) {
                for (j = 0; j < 6; j++) {
                    if ((&D_0028ED30)[j] == save[j + 0x38]) {
                        count++;
                    }
                }
                if (count == 6) {
                    goto found;
                }
            }
        }
    }
    return 0xFF;
found:
    k = i << 10;
    printf("[%d][%d][%d][%d][%d]-[%d] no[%d]\n", D_006A0E88[k], D_006A0E89[k], D_006A0E8A[k], D_006A0E8B[k], D_006A0E8C[k], D_006A0E8D[k], i + 1);
    return i + 1;
}

extern u8 D_00271FE0[];
extern u8 D_00272010_as_u8_a[];
typedef struct {
    u8 pad0[0x10];
    s16 state;
    u8 pad12[0x34];
    u16 id;
    u8 pad48[0x3B8];
} Slot;
extern Slot D_006A0E40_as_Slot_a[];
void func_002319B0(void) {
    s32 sceMcOpen();
    s32 sceMcClose();
    s32 sceMcRead();
    s32 sceMcSync();
    s32 sceMcGetDir();
    s32 strcmp();
    s32 sp5C;
    s32 ok;
    s32 i;
    s32 off;
    u8 *entry;

    switch (D_0028ECF0) {
    case 0:
        D_0028ECE4 = 0xA;
        D_0028ECF0 += 1;
        break;
    case 1:
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 3:
            case 4:
                D_0028ECF0 = 0x1E;
                break;
            default:
                D_0028ECF8 = 0xA;
                D_0028ECF0 += 1;
                break;
            }
        } else {
            break;
        }
        break;
    case 2:
        if (sceMcGetDir(D_0028EC70, D_0028EC74, *(u32 *)(D_00271FE0 + (D_0028ED1C * 4)), 0, 5, D_0069F580) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 0x14;
            break;
        }
        break;
    case 3:
        if (sceMcSync(1, 0, &sp5C) != 0) {
            ok = 1;
            if (sp5C <= 0) {
                D_0028ECF0 = 0x14;
                break;
            }
            i = 0;
            off = 0;
            do {
                if (D_0028ED1C == 1) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY1") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 2) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY2") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 3) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY3") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 4) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY4") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 5) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY5") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 6) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY6") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 7) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY7") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 8) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY8") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 9) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY9") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 0xA) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((strcmp(entry + 0x20, (char *)"BISLPS-25233REPLAY10") == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                i += 1;
                off += 0x40;
            } while (i < 5);
            if (ok != 0) {
                D_0028ECF0 = 0x25;
                break;
            }
            D_0028ECF0 += 1;
            D_0028ECF8 = 0xA;
            break;
        }
        break;
    case 4:
        if (sceMcOpen(D_0028EC70, D_0028EC74, *(u32 *)(D_00272010_as_u8_a + (D_0028ED1C * 4)), 3) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 0x14;
            break;
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &sp5C) != 0) {
            if (sp5C < 0) {
                D_0028ECF0 = 0x14;
                break;
            }
            printf((const char *)"--file size[%d]--\n", D_0069F590[0]);
            D_0028ECF8 = 0xA;
            D_0028ECA8 = sp5C;
            D_0028ECF0 += 1;
            break;
        }
        break;
    case 6:
        if (sceMcRead(D_0028ECA8, D_006A0E50 + ((D_0028ED1C - 1) << 0xA), 0x400) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 0x1E;
            break;
        }
        break;
    case 7:
        if (sceMcSync(1, 0, &sp5C) != 0) {
            if (sp5C < 0) {
                D_0028ECF0 = 0x1E;
                break;
            }
            D_0028ECF0 += 1;
            D_0028ECF8 = 0xA;
            break;
        }
        break;
    case 8:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 0x1E;
            break;
        }
        break;
    case 9:
        if (sceMcSync(1, 0, &sp5C) != 0) {
            if (sp5C < 0) {
                D_0028ECF0 = 0x1E;
                break;
            }
            D_0028ECF8 = 0xA;
            D_0028ECF0 += 1;
            break;
        }
        break;
    case 10:
        off = D_0028ED1C - 1;
        ok = D_0028ED1C;
        D_006A0E40_as_Slot_a[off].state = 1;
        if (D_006A0E40_as_Slot_a[off].id == MAIN_OR_DEATH_LABEL(0xCB, 0x6E)) {
            printf("head load ok[%d]\n", ok);
        } else {
            D_006A0E40_as_Slot_a[off].state = 3;
            printf("--version err-[%d] [%d][%d]\n", ok, D_006A0E40_as_Slot_a[off].id, MAIN_OR_DEATH_LABEL(0xCB, 0x6E));
        }
        D_0028ECF0 = 0;
        D_0028ED14 += 1;
        break;
    case 20:
        printf("file nasi[%d]\n", D_0028ED1C);
        D_0028ECF0 = 0;
        D_0028ED14 += 1;
        break;
    case 30:
        printf("kaku load err[%d]\n", D_0028ED1C);
        D_0028ECF0 = 0;
        D_0028ED14 = 0x1E;
        break;
    case 35:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 0x1E;
            break;
        }
        break;
    case 36:
        if (sceMcSync(1, 0, &sp5C) != 0) {
            if (sp5C < 0) {
                D_0028ECF0 = 0x1E;
                break;
            }
            printf("--hason[%d]\n", D_0028ED1C);
            *(s16 *)(D_006A0E50 + ((D_0028ED1C - 1) << 0xA)) = 2;
            D_0028ECF0 = 0;
            D_0028ED14 += 1;
            break;
        }
        break;
    case 37:
        printf("--hason[%d]\n", D_0028ED1C);
        *(s16 *)(D_006A0E50 + ((D_0028ED1C - 1) << 0xA)) = 2;
        D_0028ECF0 = 0;
        D_0028ED14 += 1;
        break;
    }
}

extern s32 D_0028DE30;

void func_00232270(void) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 diff;
    s32 step;

    func_0022CF20();
    func_0022C5E0(200, D_0028DE30, 0, 20, 14, D_0028ED10, 100);
    switch (D_0028ECF0) {
    case 0:
        D_0028ECEC = 1;
        D_0028ECF0 += 1;
        D_0028ECA0 = 180;
        D_0028ECA4 = 304;
    case 1:
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            D_0028ECF0 = 0;
            if (D_0028ECEC == 1) {
                D_0028ECF0 = 3;
            } else {
                D_0028ECFC = 2;
            }
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 214;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 304;
            }
        }
        break;
    case 2:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 1;
            break;
        }
        diff = D_0028EC9C - D_0028ECA4;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (D_0028ECEC == 0) {
                step = -1;
            }
        }
        D_0028ECA4 += step;
        break;
    case 3:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    }
    func_00233F50();
}

extern s32 D_0028DDF8;

void func_00232430(void) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 diff;
    s32 step;

    func_0022CF20();
    if ((D_0028ECF0 != 20) && (D_0028ECF0 != 0)) {
        func_0022C5E0(200, (&D_0028DDF8)[D_0028ECE8], 0, 20, 14, D_0028ED10, 100);
        func_00233F50();
    }
    switch (D_0028ECF0) {
    case 0:
        D_0028ECEC = 1;
        D_0028ECE4 = 3;
        D_0028ECA0 = 210;
        D_0028ECA4 = 324;
        D_0028ECF0 += 1;
        D_0028ECE0 = 0;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        if (D_0028ECE0 > 60) {
            func_0022CDB0(1);
            if (D_0028ECD0 == 0) {
                D_0028ECE0 = 0;
                if ((D_0028ECC8 == 4) || (D_0028ECC8 == 3)) {
                    D_0028ECF0 = 20;
                    break;
                }
            }
        } else {
            D_0028ECE0 += 1;
        }
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            D_0028ECF0 = 4;
            if (D_0028ECD0 == 0) {
                D_0028ECCC = 0;
            }
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 234;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 324;
            }
        }
        break;
    case 3:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 2;
            break;
        }
        diff = D_0028EC9C - D_0028ECA4;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (D_0028ECEC == 0) {
                step = -1;
            }
        }
        D_0028ECA4 += step;
        break;
    case 4:
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            if ((D_0028ECC8 == 4) || (D_0028ECC8 == 3)) {
                D_0028ECF0 = 20;
                break;
            }
            D_0028ECF0 = 0;
            if (D_0028ECEC == 1) {
                D_0028ECFC = 17;
            } else {
                D_0028ECFC += 1;
            }
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 17;
        }
        break;
    }
}

s32 sceMcFormat(s32 arg0, s32 arg1);
extern s32 D_0028DE00;
extern s32 D_0028DE04;

void func_00232710(void) {
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    s32 sceMcGetInfo(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 *arg4);
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 result;

    func_0022CF20();
    if (D_0028ECF0 < 6) {
        func_00234150(3);
    }
    switch (D_0028ECF0) {
    case 0:
        D_0028ECE4 = 30;
        D_0028ECF0 += 1;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF8 = 10;
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        D_0028ECAC = sceMcGetInfo(D_0028EC70, D_0028EC74, &D_0028ECB8, &D_0028ECB4, &D_0028ECB0);
        if (D_0028ECAC == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 10;
        }
        break;
    case 3:
        if (sceMcSync(1, 0, &result) != 0) {
            switch (result) {
            case 0:
                D_0028ECF0 += 1;
                D_0028ECF8 = 10;
                break;
            default:
            case -1:
            case -2:
                D_0028ECF0 = 10;
                break;
            }
        }
        break;
    case 4:
        if (sceMcFormat(D_0028EC70, D_0028EC74) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 10;
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result == 0) {
                D_0028ECF0 += 1;
            } else {
                D_0028ECF0 = 10;
            }
        }
        break;
    case 6:
        func_0022C5E0(200, D_0028DE00, 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 += 1;
        }
        break;
    case 7:
        D_0028ECF0 = 0;
        D_0028ECFC = 11;
        break;
    case 10:
        func_0022C5E0(200, D_0028DE04, 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 7;
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 7;
        }
        break;
    }
}

extern s32 D_0028DDE8;

void func_002329F0(void) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 diff;
    s32 step;

    if (D_0028ECF0 != 20) {
        func_0022C5E0(200, D_0028DDE8, 0, 20, 14, D_0028ED10, 100);
        func_00233F50();
    }
    switch (D_0028ECF0) {
    case 0:
        D_0028ECEC = 1;
        D_0028ECA0 = 180;
        D_0028ECE4 = 3;
        D_0028ECA4 = 222;
        D_0028ECE0 = 70;
        D_0028ECF0 += 1;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            D_0028ECF0 = 0;
            if (D_0028ECEC == 1) {
                D_0028ECF0 = 4;
            } else {
                D_0028ECFC = 2;
            }
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 144;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 222;
            }
        }
        break;
    case 3:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 2;
            break;
        }
        diff = D_0028EC9C - D_0028ECA4;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (D_0028ECEC == 0) {
                step = -1;
            }
        }
        D_0028ECA4 += step;
        break;
    case 4:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    }
}

s32 sceMcUnformat(s32 arg0, s32 arg1);
extern s32 D_0028DDEC;
extern s32 D_0028DDF0;

void func_00232BE0(void) {
    s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 result;
    s32 status;

    func_0022CF20();
    switch (D_0028ECF0) {
    case 0:
        status = func_0022CC70(0);
        if ((status == 4) || (status == 3)) {
            D_0028ECF0 = 20;
        } else {
            D_0028ECF0 += 1;
        }
        break;
    case 1:
        if (sceMcUnformat(D_0028EC70, D_0028EC74) == 0) {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        func_00234150(4);
        if (sceMcSync(1, 0, &result) != 0) {
            if (result == 0) {
                D_0028ECF0 += 1;
            } else {
                D_0028ECF0 = 10;
            }
        }
        break;
    case 3:
        func_0022C5E0(200, D_0028DDEC, 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 += 1;
        }
        break;
    case 4:
        D_0028ECF0 = 5;
        break;
    case 5:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 10:
        func_0022C5E0(200, D_0028DDF0, 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 4;
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 4;
        }
        break;
    }
}

extern char *D_00271FB0_as_char_p_a[];
extern char *D_00271FB4[];
extern char *D_00271FB8[];
extern char *D_00271FBC[];
extern char *D_00271FC0[];
extern char *D_00271FC4[];
extern char *D_00271FC8[];
extern char *D_00271FCC[];
extern char *D_00271FD0[];
extern char *D_00271FD4[];
extern char *D_00271FD8[];
extern s32 D_0028DE08;
extern s32 D_0028DE0C;
extern s32 D_0028DE10;
extern s32 D_0028EC80;
extern s32 D_0028EC84;
extern s32 D_0028EC88;
extern u8 D_0028EC8C;
extern u8 D_0028EC8D;
extern u8 D_0028EC8E;
extern u8 D_0028EC8F;
extern u8 D_0028ECF4;

void func_00232DE0(void) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 sceMcSync(s32, s32, s32 *);
    s32 sceMcGetDir(s32, s32, char *, s32, s32, void *);
    s32 result;
    s32 diff;
    s32 step;

    if ((D_0028ECF0 == 3) || (D_0028ECF0 == 4) || (D_0028ECF0 == 30) || (D_0028ECF0 == 31)) {
        func_0022C5E0(120, D_0028DE08, 0, 20, 14, D_0028ED10, 100);
        func_00233F50();
    }
    if ((D_0028ECF0 == 11) || (D_0028ECF0 == 12) || (D_0028ECF0 == 40) || (D_0028ECF0 == 41)) {
        func_0022C5E0(120, D_0028DE0C, 0, 20, 14, D_0028ED10, 100);
        func_0022C5E0(240, D_0028DE10, 0, 20, 14, D_0028ED10, 100);
        func_00233F50();
    }
    switch (D_0028ECF0) {
    case 0:
        D_0028ECE4 = 60;
        D_0028ECF0 += 1;
        D_0028EC80 = 0;
        break;
    case 1:
        func_00234230();
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        func_00234230();
        D_0028EC70 = 0;
        D_0028EC74 = 0;
        D_0028ECF4 = 0;
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            if ((D_0028ECC8 == 3) || (D_0028ECC8 == 2)) {
                D_0028ECF4 |= 1;
            } else if (D_0028ECC8 == 1) {
                D_0028ECF4 |= 0x10;
            }
            if ((D_0028ECF4 & 0x10) == 0x10) {
                D_0028ECF0 = 20;
            } else if ((D_0028ECF4 & 1) != 1) {
                D_0028ECF0 = 50;
            } else {
                D_0028ECEC = 1;
                D_0028ECE0 = 0;
                D_0028ECA0 = 232;
                D_0028ECA4 = 324;
                D_0028ECF0 += 1;
            }
        }
        break;
    case 3:
        if (D_0028ECE0 > 60) {
            D_0028EC70 = 0;
            D_0028EC74 = 0;
            func_0022CDB0(1);
            if (D_0028ECD0 == 0) {
                if (D_0028ECC8 == 4) {
                    D_0028ECF0 = 0;
                    break;
                }
                D_0028ECE0 = 0;
            }
        } else {
            D_0028ECE0 += 1;
        }
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            if (D_0028ECD0 != 0) {
                D_0028ECF0 = 30;
            } else {
                D_0028ECF0 = 0;
                if (D_0028ECEC == 0) {
                    D_0028ECF0 = 5;
                }
            }
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 234;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 324;
            }
        }
        break;
    case 4:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 3;
        }
        diff = D_0028EC9C - D_0028ECA4;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (D_0028ECEC == 0) {
                step = -1;
            }
        }
        D_0028ECA4 += step;
        break;
    case 5:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 0x32:
        func_00234230();
        D_0028EC88 = 0;
        D_0028EC8C = 0;
        D_0028EC8D = 0;
        D_0028EC8E = 0;
        D_0028EC8F = 0;
        D_0028EC80 = 0;
        D_0028EC84 = 0;
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FB0_as_char_p_a[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x33:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC8D = 1;
                D_0028EC88 += D_00271D60[0];
            } else {
                D_0028EC80 = 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x34:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FB4[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x35:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x36:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FB8[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x37:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x38:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FBC[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x39:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x3A:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FC0[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x3B:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x3C:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FC4[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x3D:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x3E:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FC8[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x3F:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x40:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FCC[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x41:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x42:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FD0[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x43:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x44:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FD4[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x45:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x46:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FD8[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x47:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            printf("free[%d] size[%d] nasi[%d]\n", D_0028ECB4, D_0028EC88, D_0028EC84);
            if ((D_0028EC88 != 0) && (D_0028ECB4 < D_0028EC88)) {
                D_0028ECF4 = 0;
                D_0028ECF0 = 0x50;
            } else {
                D_0028ECF4 |= 4;
                D_0028ECF0 = 0x50;
            }
        }
        break;
    case 0x50:
        D_0028EC70 = 0;
        D_0028EC74 = 0;
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            if ((D_0028ECC8 == 2) || (D_0028ECC8 == 3) || (D_0028ECC8 == 4) || (D_0028ECC8 == 1)) {
                D_0028ECF0 = 0;
            } else {
                D_0028ECF0 = 10;
            }
        }
        break;
    case 10:
        if (D_0028ECF4 & 0xC) {
            D_0028ECF0 = 20;
            break;
        }
        D_0028ECE0 = 0;
        D_0028ECF0 += 1;
        D_0028ECEC = 1;
        D_0028ECA0 = 256;
        D_0028ECA4 = 324;
        break;
    case 11:
        if (D_0028ECE0 == 71) {
            D_0028ECE0 = 0;
        } else if (D_0028ECE0 > 60) {
            D_0028EC70 = 0;
            D_0028EC74 = 0;
            func_0022CDB0(1);
            if (D_0028ECD0 == 0) {
                if (D_0028ECC8 == 4) {
                    D_0028ECF0 = 0;
                    break;
                }
                D_0028ECE0 = 71;
            }
        } else {
            D_0028ECE0 += 1;
        }
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            if (D_0028ECD0 != 0) {
                D_0028ECF0 = 40;
            } else {
                D_0028ECF0 = 0;
                if (D_0028ECEC == 0) {
                    D_0028ECF0 = 21;
                }
            }
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 234;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 324;
            }
        }
        break;
    case 12:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 11;
            break;
        }
        diff = D_0028EC9C - D_0028ECA4;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (D_0028ECEC == 0) {
                step = -1;
            }
        }
        D_0028ECA4 += step;
        break;
    case 20:
        D_0028ECF0 = 21;
        break;
    case 21:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ED18 = 2;
            D_0028ECF0 = 0;
            if (D_0028EC80 != 0) {
                D_0028ECF4 |= 4;
            }
        }
        break;
    case 30:
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 == 4) {
                D_0028ECF0 = 0;
                break;
            }
            D_0028ECE0 = 0;
            D_0028ECF0 = 0;
            if (D_0028ECEC == 0) {
                D_0028ECF0 = 5;
            }
        }
        break;
    case 40:
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 == 4) {
                D_0028ECF0 = 0;
                break;
            }
            D_0028ECE0 = 0;
            D_0028ECF0 = 0;
            if (D_0028ECEC == 0) {
                D_0028ECF0 = 21;
            }
        }
        break;
    case 100:
        func_002343E0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 21;
        }
        break;
    }
}

extern s32 D_0028DE14;

void func_00233BE0(void) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    func_0022CF20();
    switch (D_0028ECF0) {
    case 0:
        D_0028ECC4 = 0;
        D_0028ECF0 += 1;
        D_0028ECE0 = 0;
        D_0028ECF8 = 60;
        break;
    case 1:
        func_00234230();
        if (D_0028ECF8 != 0) {
            D_0028ECF8 -= 1;
        } else {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        func_00234230();
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 2:
            case 3:
            case 4:
                func_0022D240(11);
                D_0028ECF0 = 20;
                break;
            default:
                D_0028ECC4 = 1;
                D_0028ECF0 += 1;
                break;
            }
        }
        break;
    case 3:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 20:
        if (D_0028ECE0 > 60) {
            D_0028EC70 = 0;
            D_0028EC74 = 0;
            func_0022CDB0(1);
            if (D_0028ECD0 == 0) {
                if (D_0028ECC8 == 4) {
                    D_0028ECF0 = 0;
                    break;
                }
                D_0028ECE0 = 0;
            }
        } else {
            D_0028ECE0 += 1;
        }
        func_0022C5E0(200, D_0028DE14, 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 3;
        }
        break;
    }
}


s32 func_00233DA0(void) {
    switch (D_0028ED04) {
    case 0:
        D_0028ED0C = 0;
        D_0028ED04 += 1;
        break;
    case 1:
        func_0022C730();
        if (D_0028ED0C != 0) {
            D_0028ED0C = 0;
            D_0028ECE0 = 30;
            D_0028ED04 += 1;
        }
        break;
    case 2:
        D_0028ECE0 -= 1;
        if ((s32)D_0028ECE0 <= 0) {
            D_0028ED04 += 1;
        }
        break;
    case 3:
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 4:
                D_0028ED04 = 0;
                break;
            case 1:
            case 2:
            case 3:
                func_00236900();
            default:
                D_0028ECE0 = 30;
                D_0028ED04 = 2;
                break;
            }
        }
        break;
    }
    return D_0028ED04 >= 2;
}

void func_00233EC0(void) {
    D_0028ED0C = 0;
    D_0028ED04 = 2;
    D_0028ECE0_as_s8 = 0x1E;
}

extern s32 D_0028DDD8;


void func_00233EE0(void)
{
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 displayValue = D_0028ED10_as_u16;
    s32 displayData = D_0028DDD8;

    func_0022C5E0(0x168, displayData, 0, 0x14, 0xE, displayValue, 0x64);
    if (D_0057CC78[0] & 0x20) {
        func_0022D240(2);
    }
}

void overlay_queue_sjis_vertical(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth);

void func_00233F30(s16 x, s16 y, char *text, u16 page, u16 w, u16 h, u16 alpha, u16 depth) {
    overlay_queue_sjis_vertical(0x1C0 - y, x, text, page, w, h, alpha, depth);
}

extern s32 sprintf(char *buf, const char *format, ...);
extern char *D_0028E9F8;

void func_00233F50(void) {
    s32 shrink;
    s32 color;
    s32 w;
    s32 h;

    if (D_0028ECDC < 4) {
        D_0028ECDC += 2;
    }
    color = D_0028ED10;
    shrink = 0;
    if (D_0028ECDC != 0) {
        shrink = (s32)(D_0028ECDC & 0xFF) / 2;
    }
    w = (D_0028ECDC & 0xFF) + 20;
    h = (D_0028ECDC & 0xFF) + 14;
    if (D_0028ECEC == 0) {
        sprintf(D_0028E9F8, SJIS("はい"));
        func_00233F30(48 - shrink, 364 - shrink, D_0028E9F8, 4, w, h, color, 100);
        sprintf(D_0028E9F8, SJIS("／"));
        func_00233F30(104, 364, D_0028E9F8, 0, 20, 14, color, 100);
        sprintf(D_0028E9F8, SJIS("いいえ"));
        func_00233F30(136, 364, D_0028E9F8, 0, 20, 14, color, 100);
    } else {
        sprintf(D_0028E9F8, SJIS("はい"));
        func_00233F30(48, 364, D_0028E9F8, 0, 20, 14, color, 100);
        sprintf(D_0028E9F8, SJIS("／"));
        func_00233F30(104, 364, D_0028E9F8, 0, 20, 14, color, 100);
        sprintf(D_0028E9F8, SJIS("いいえ"));
        func_00233F30(136 - shrink, 364 - shrink, D_0028E9F8, 4, w, h, color, 100);
    }
}

extern s32 D_00271DC0[];
extern s32 D_00271DE0[];
extern s32 D_0028DDB8;

void func_00234150(s32 arg0) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    if (D_0028ED1C == 0) {
        func_0022C5E0(200, D_00271DC0[arg0], 0, 20, 14, D_0028ED10, 100);
    } else {
        func_0022C5E0(200, D_00271DE0[arg0], 0, 20, 14, D_0028ED10, 100);
    }
    func_0022C5E0(300, D_0028DDB8, 0, 20, 14, D_0028ED10, 100);
}

extern s32 D_0028DDC8;


void func_00234200(void) {
    void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    func_0022C5E0(0xC8, (&D_0028DDC8)[D_0028ECE8], 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
}

extern s32 D_0028DDD0;
void func_00234230(void) {
    void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 t = D_0028ED10_as_u16;
    func_0022C5E0(0xC8, D_0028DDD0, 0, 0x14, 0xE, t, 0x64);
}

extern s32 D_00271E00[];
extern s32 D_0028DDD4;
void func_00234250(s32 arg0, s32 arg1) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    func_0022C5E0(0xB4, D_00271E00[arg1], 0, 0x14, 14, D_0028ED10_as_u16, 100);
    if (arg0 == 1) {
        s32 t = D_0028ED10_as_u16;
        func_0022C5E0(300, D_0028DDD4, 0, 0x14, 14, t, 100);
    }
}

extern s32 D_0028DE20;
void func_002342D0(void) {
    void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 t = D_0028ED10_as_u16;
    func_0022C5E0(0xC8, D_0028DE20, 0, 0x14, 0xE, t, 0x64);
}

extern s32 D_00271E80[];
extern s32 D_0028DDE0[2];

void func_002342F0(s32 arg0) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    func_0022C5E0(0xC8, D_0028DDE0[D_0028ECE8], 0, 0x14, 14, D_0028ED10_as_u16, 100);
    func_0022C5E0(0xF0, D_00271E80[arg0], 0, 0x14, 14, D_0028ED10_as_u16, 100);
}

extern s32 D_00271F70[];

void func_00234370(s32 index) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    func_0022C5E0(0xC8, D_00271F70[index], 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
}

extern s32 D_0028DE34;


void func_002343A0(void) {
    void func_0022C5E0(s32, s32, s32, s32, s32, s32, s32);
    func_0022C5E0(0xC8, D_0028DE34, 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
}

extern s32 D_0028DE38;


void func_002343C0(void) {
    void func_0022C5E0(s32, s32, s32, s32, s32, s32, s32);
    func_0022C5E0(0xC8, D_0028DE38, 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
}

extern s32 D_0028DE3C;
void func_002343E0(void) {
    void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s32 t = D_0028ED10_as_u16;
    func_0022C5E0(0xC8, D_0028DE3C, 0, 0x14, 0xE, t, 0x64);
}

extern s32 D_00271EE0[];


void func_00234400(s32 index) {
    void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    func_0022C5E0(0xC8, D_00271EE0[index], 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
}

extern s32 D_00271F10[];

void func_00234430(s32 index) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    func_0022C5E0(0xC8, D_00271F10[index], 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
}

s32 sprintf(char *buf, const char *format, ...);
extern s32 D_00271F40[];
extern s32 D_0028DE24;
extern s32 D_0028DE28;
extern s32 D_0028E9F8_as_s32;

void func_00234460(s32 arg0) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    func_0022C5E0(160, D_0028DE24, 0, 20, 14, D_0028ED10, 100);
    func_0022C5E0(220, D_00271F40[arg0], 0, 20, 14, D_0028ED10, 100);
    func_0022C5E0(260, (&D_0028DE28)[D_0028ECE8], 0, 20, 14, D_0028ED10, 100);
    if (arg0 == 0) {
        sprintf((char *)D_0028E9F8_as_s32, SJIS("　　　　 %2d "), D_00271D60[D_0028ED1C * 2]);
    } else {
        sprintf((char *)D_0028E9F8_as_s32, SJIS("　　　　%3d "), D_00271D60[D_0028ED1C * 2]);
    }
    func_0022C5E0(300, D_0028E9F8_as_s32, 0, 20, 14, D_0028ED10, 100);
}

extern s32 D_00271EB0[];

s32 func_00234580(s32 index) {
    s32 func_0022C5E0(s32, s32, s32, s32, s32, s32, s32);
    return func_0022C5E0(0xC8, D_00271EB0[index], 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
}

typedef struct {
    u16 a00[5];
    u16 a0A[5];
    u16 a14[5];
    u16 a1E[5];
    u16 a28[5];
    u8 pad32[2];
    s32 a34[15];
    s32 a70[5];
    u16 a84[5];
    u16 a8E[5];
    u16 a98[5];
    u16 aA2[5];
    u16 aAC[5];
    u16 aB6[5];
    u16 aC0[5];
    u8 padCA[2];
    s32 aCC[15];
    s32 a108[5];
    u16 a11C[5];
    u16 a126[5];
    u8 a130[5][30];
    u8 a1C6[5][30];
    u8 b25C;
    u8 b25D;
    u8 b25E;
    u8 b25F;
    u8 b260;
    u8 b261;
    u8 b262;
    u8 b263;
    u8 b264;
    u8 b265;
    u8 b266;
    u8 b267;
    u16 h268;
    u8 b26A;
    u8 b26B;
    u8 a26C[2][4];
    s8 b274;
    s8 b275;
    u8 b276;
    u8 pad277;
    u16 h278;
    u8 pad27A[2];
    s32 a27C[10][4][5];
    u8 b59C;
    u8 b59D;
    u8 b59E;
    u8 b59F;
    u8 b5A0;
} SaveBlock;

extern u8 D_0028E290;
extern u16 D_002BB198[5];
extern u16 D_002BB1A8[5];
extern u16 D_002BB1B8[5];
extern u16 D_002BB1C8[5];
extern u16 D_002BB1D8[5];
extern u16 D_002BB1E8[5];
extern u16 D_002BB1F8[5];
extern s32 D_002BB210[15];
extern s32 D_002BB250[5];
extern s8 D_0028E250;
extern s8 D_0028E254;
extern u8 D_0028E258;
extern u8 D_0028E270[2][4];
extern u8 D_0028E278;
extern u8 D_0028E27C;
extern u8 D_0028E28C;
extern u8 D_0028E2D8;
extern u8 D_0028E2DC;
extern u8 D_0028E2E0;
extern u16 D_0028E300;
extern u16 D_0028E32C;
extern u8 D_0028E354;
extern u8 D_0028E358;
extern u8 D_0028E35C;
extern u8 D_0028E360;
extern u8 D_0028E37C;
extern u8 D_0028E380;
extern u8 D_0028E384;
extern u8 D_0028E388;
extern u8 D_0028E38C;
extern u8 D_0028E390;
extern u8 D_0028E394;
extern u8 D_0028E398;
extern u8 D_0028E39C;
extern u8 D_002BB060[5][30];
extern u8 D_002BB100[5][30];
extern u16 D_002BB268[5];
extern u16 D_002BB278[5];
extern u16 D_002BB288[5];
extern u16 D_002BB298[5];
extern u16 D_002BB2A8[5];
extern u16 D_002BB2B8[5];
extern u16 D_002BB2C8[5];
extern s32 D_002BB2E0[15];
extern s32 D_002BB320[5];
extern u16 D_002BB338[5];
extern u16 D_002BB348[5];
extern u16 D_002BB358[5];
extern u16 D_002BB368[5];
extern u16 D_002BB378[5];
extern u16 D_002BB388[5];
extern u16 D_002BB398[5];
extern s32 D_002BB3B0[15];
extern s32 D_002BB3F0[5];
extern s32 D_00684CF0[10][4][5];

void func_002345B0(void) {
    extern SaveBlock D_006C4EF0_as_SaveBlock;
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 5; i++) {
        D_006C4EF0_as_SaveBlock.a00[i] = D_002BB378[i];
        D_006C4EF0_as_SaveBlock.a0A[i] = D_002BB368[i];
        D_006C4EF0_as_SaveBlock.a14[i] = D_002BB398[i];
        D_006C4EF0_as_SaveBlock.a1E[i] = D_002BB388[i];
        D_006C4EF0_as_SaveBlock.a28[i] = D_002BB358[i];
        D_006C4EF0_as_SaveBlock.a70[i] = D_002BB3F0[i];
        D_006C4EF0_as_SaveBlock.a84[i] = D_002BB338[i];
        D_006C4EF0_as_SaveBlock.a8E[i] = D_002BB348[i];
        D_006C4EF0_as_SaveBlock.a98[i] = D_002BB2A8[i];
        D_006C4EF0_as_SaveBlock.aA2[i] = D_002BB298[i];
        D_006C4EF0_as_SaveBlock.aAC[i] = D_002BB2C8[i];
        D_006C4EF0_as_SaveBlock.aB6[i] = D_002BB2B8[i];
        D_006C4EF0_as_SaveBlock.aC0[i] = D_002BB288[i];
        D_006C4EF0_as_SaveBlock.a108[i] = D_002BB320[i];
        D_006C4EF0_as_SaveBlock.a11C[i] = D_002BB268[i];
        D_006C4EF0_as_SaveBlock.a126[i] = D_002BB278[i];
    }
    for (i = 0; i < 15; i++) {
        D_006C4EF0_as_SaveBlock.a34[i] = D_002BB3B0[i];
        D_006C4EF0_as_SaveBlock.aCC[i] = D_002BB2E0[i];
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 30; j++) {
            D_006C4EF0_as_SaveBlock.a130[i][j] = D_002BB100[i][j];
            D_006C4EF0_as_SaveBlock.a1C6[i][j] = D_002BB060[i][j];
        }
    }
    if (D_0028E290 == 2) {
        for (i = 0; i < 5; i++) {
            D_006C4EF0_as_SaveBlock.a00[i] = D_002BB1D8[i];
            D_006C4EF0_as_SaveBlock.a0A[i] = D_002BB1C8[i];
            D_006C4EF0_as_SaveBlock.a14[i] = D_002BB1F8[i];
            D_006C4EF0_as_SaveBlock.a1E[i] = D_002BB1E8[i];
            D_006C4EF0_as_SaveBlock.a28[i] = D_002BB1B8[i];
            D_006C4EF0_as_SaveBlock.a70[i] = D_002BB250[i];
            D_006C4EF0_as_SaveBlock.a84[i] = D_002BB198[i];
            D_006C4EF0_as_SaveBlock.a8E[i] = D_002BB1A8[i];
            D_006C4EF0_as_SaveBlock.a98[i] = D_002BB378[i];
            D_006C4EF0_as_SaveBlock.aA2[i] = D_002BB368[i];
            D_006C4EF0_as_SaveBlock.aAC[i] = D_002BB398[i];
            D_006C4EF0_as_SaveBlock.aB6[i] = D_002BB388[i];
            D_006C4EF0_as_SaveBlock.aC0[i] = D_002BB358[i];
            D_006C4EF0_as_SaveBlock.a108[i] = D_002BB3F0[i];
            D_006C4EF0_as_SaveBlock.a11C[i] = D_002BB338[i];
            D_006C4EF0_as_SaveBlock.a126[i] = D_002BB348[i];
        }
        for (i = 0; i < 15; i++) {
            D_006C4EF0_as_SaveBlock.a34[i] = D_002BB210[i];
            D_006C4EF0_as_SaveBlock.aCC[i] = D_002BB3B0[i];
        }
    }
    D_006C4EF0_as_SaveBlock.b25C = D_0028E39C;
    D_006C4EF0_as_SaveBlock.b25D = D_0028E398;
    D_006C4EF0_as_SaveBlock.b25E = D_0028E394;
    D_006C4EF0_as_SaveBlock.b25F = D_0028E390;
    D_006C4EF0_as_SaveBlock.b260 = D_0028E358;
    D_006C4EF0_as_SaveBlock.b261 = D_0028E38C;
    D_006C4EF0_as_SaveBlock.b262 = D_0028E388;
    D_006C4EF0_as_SaveBlock.b263 = D_0028E384;
    D_006C4EF0_as_SaveBlock.b264 = D_0028E380;
    D_006C4EF0_as_SaveBlock.b265 = D_0028E37C;
    D_006C4EF0_as_SaveBlock.b266 = D_0028E360;
    D_006C4EF0_as_SaveBlock.b267 = D_0028E35C;
    D_006C4EF0_as_SaveBlock.h268 = D_0028E32C;
    D_006C4EF0_as_SaveBlock.b26A = D_0028E27C;
    D_006C4EF0_as_SaveBlock.b26B = D_0028E278;
    D_006C4EF0_as_SaveBlock.b274 = D_0028E254;
    D_006C4EF0_as_SaveBlock.b275 = D_0028E250;
    D_006C4EF0_as_SaveBlock.b276 = D_0028E258;
    D_006C4EF0_as_SaveBlock.h278 = D_0028E300;
    D_006C4EF0_as_SaveBlock.b59C = D_0028E2E0;
    D_006C4EF0_as_SaveBlock.b59D = D_0028E2DC;
    D_006C4EF0_as_SaveBlock.b59E = D_0028E2D8;
    D_006C4EF0_as_SaveBlock.b59F = D_0028E354;
    D_006C4EF0_as_SaveBlock.b5A0 = D_0028E28C;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                D_006C4EF0_as_SaveBlock.a27C[i][j][k] = D_00684CF0[i][j][k];
            }
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            D_006C4EF0_as_SaveBlock.a26C[i][j] = D_0028E270[i][j];
        }
    }
}

typedef struct {
    u16 a00[5];
    u16 a0A[5];
    u16 a14[5];
    u16 a1E[5];
    u16 a28[5];
    u8 pad32[2];
    s32 a34[15];
    s32 a70[5];
    u16 a84[5];
    u16 a8E[5];
    u16 a98[5];
    u16 aA2[5];
    u16 aAC[5];
    u16 aB6[5];
    u16 aC0[5];
    u8 padCA[2];
    s32 aCC[15];
    s32 a108[5];
    u16 a11C[5];
    u16 a126[5];
    u8 a130[5][30];
    u8 a1C6[5][30];
    u8 b25C;
    u8 b25D;
    u8 b25E;
    u8 b25F;
    u8 b260;
    u8 b261;
    u8 b262;
    u8 b263;
    u8 b264;
    u8 b265;
    u8 b266;
    u8 b267;
    u16 h268;
    u8 b26A;
    u8 b26B;
    u8 a26C[2][4];
    s8 b274;
    s8 b275;
    s8 b276;
    u8 pad277;
    s16 h278;
    u8 pad27A[2];
    s32 a27C[10][4][5];
    s8 b59C;
    s8 b59D;
    s8 b59E;
    s8 b59F;
    s8 b5A0;
} SaveBlock2;


extern void func_0021E1A0(void);

void func_00234EF0(void) {
    extern SaveBlock2 D_006C4EF0_as_SaveBlock;
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 5; i++) {
        D_002BB378[i] = D_006C4EF0_as_SaveBlock.a00[i];
        D_002BB368[i] = D_006C4EF0_as_SaveBlock.a0A[i];
        D_002BB398[i] = D_006C4EF0_as_SaveBlock.a14[i];
        D_002BB388[i] = D_006C4EF0_as_SaveBlock.a1E[i];
        D_002BB358[i] = D_006C4EF0_as_SaveBlock.a28[i];
        D_002BB3F0[i] = D_006C4EF0_as_SaveBlock.a70[i];
        D_002BB338[i] = D_006C4EF0_as_SaveBlock.a84[i];
        D_002BB348[i] = D_006C4EF0_as_SaveBlock.a8E[i];
        D_002BB1D8[i] = D_006C4EF0_as_SaveBlock.a00[i];
        D_002BB1C8[i] = D_006C4EF0_as_SaveBlock.a0A[i];
        D_002BB1F8[i] = D_006C4EF0_as_SaveBlock.a14[i];
        D_002BB1E8[i] = D_006C4EF0_as_SaveBlock.a1E[i];
        D_002BB1B8[i] = D_006C4EF0_as_SaveBlock.a28[i];
        D_002BB250[i] = D_006C4EF0_as_SaveBlock.a70[i];
        D_002BB198[i] = D_006C4EF0_as_SaveBlock.a84[i];
        D_002BB1A8[i] = D_006C4EF0_as_SaveBlock.a8E[i];
        D_002BB2A8[i] = D_006C4EF0_as_SaveBlock.a98[i];
        D_002BB298[i] = D_006C4EF0_as_SaveBlock.aA2[i];
        D_002BB2C8[i] = D_006C4EF0_as_SaveBlock.aAC[i];
        D_002BB2B8[i] = D_006C4EF0_as_SaveBlock.aB6[i];
        D_002BB288[i] = D_006C4EF0_as_SaveBlock.aC0[i];
        D_002BB320[i] = D_006C4EF0_as_SaveBlock.a108[i];
        D_002BB268[i] = D_006C4EF0_as_SaveBlock.a11C[i];
        D_002BB278[i] = D_006C4EF0_as_SaveBlock.a126[i];
    }
    for (i = 0; i < 15; i++) {
        D_002BB3B0[i] = D_006C4EF0_as_SaveBlock.a34[i];
        D_002BB2E0[i] = D_006C4EF0_as_SaveBlock.aCC[i];
        D_002BB210[i] = D_006C4EF0_as_SaveBlock.a34[i];
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 30; j++) {
            D_002BB100[i][j] = D_006C4EF0_as_SaveBlock.a130[i][j];
            D_002BB060[i][j] = D_006C4EF0_as_SaveBlock.a1C6[i][j];
        }
    }
    if (D_0028E290 == 2) {
        for (i = 0; i < 5; i++) {
            D_002BB378[i] = D_006C4EF0_as_SaveBlock.a98[i];
            D_002BB368[i] = D_006C4EF0_as_SaveBlock.aA2[i];
            D_002BB398[i] = D_006C4EF0_as_SaveBlock.aAC[i];
            D_002BB388[i] = D_006C4EF0_as_SaveBlock.aB6[i];
            D_002BB358[i] = D_006C4EF0_as_SaveBlock.aC0[i];
            D_002BB3F0[i] = D_006C4EF0_as_SaveBlock.a108[i];
            D_002BB338[i] = D_006C4EF0_as_SaveBlock.a11C[i];
            D_002BB348[i] = D_006C4EF0_as_SaveBlock.a126[i];
        }
        for (i = 0; i < 15; i++) {
            D_002BB3B0[i] = D_006C4EF0_as_SaveBlock.aCC[i];
        }
    }
    D_0028E39C = D_006C4EF0_as_SaveBlock.b25C;
    D_0028E398 = D_006C4EF0_as_SaveBlock.b25D;
    D_0028E394 = D_006C4EF0_as_SaveBlock.b25E;
    D_0028E390 = D_006C4EF0_as_SaveBlock.b25F;
    D_0028E358 = D_006C4EF0_as_SaveBlock.b260;
    D_0028E38C = D_006C4EF0_as_SaveBlock.b261;
    D_0028E388 = D_006C4EF0_as_SaveBlock.b262;
    D_0028E384 = D_006C4EF0_as_SaveBlock.b263;
    D_0028E380 = D_006C4EF0_as_SaveBlock.b264;
    D_0028E37C = D_006C4EF0_as_SaveBlock.b265;
    D_0028E360 = D_006C4EF0_as_SaveBlock.b266;
    D_0028E35C = D_006C4EF0_as_SaveBlock.b267;
    D_0028E32C = D_006C4EF0_as_SaveBlock.h268;
    D_0028E27C = D_006C4EF0_as_SaveBlock.b26A;
    D_0028E278 = D_006C4EF0_as_SaveBlock.b26B;
    D_0028E254 = D_006C4EF0_as_SaveBlock.b274;
    D_0028E250 = D_006C4EF0_as_SaveBlock.b275;
    D_0028E258 = D_006C4EF0_as_SaveBlock.b276;
    D_0028E300 = D_006C4EF0_as_SaveBlock.h278;
    D_0028E2E0 = D_006C4EF0_as_SaveBlock.b59C;
    D_0028E2DC = D_006C4EF0_as_SaveBlock.b59D;
    D_0028E2D8 = D_006C4EF0_as_SaveBlock.b59E;
    D_0028E354 = D_006C4EF0_as_SaveBlock.b59F;
    D_0028E28C = D_006C4EF0_as_SaveBlock.b5A0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                D_00684CF0[i][j][k] = D_006C4EF0_as_SaveBlock.a27C[i][j][k];
            }
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            D_0028E270[i][j] = D_006C4EF0_as_SaveBlock.a26C[i][j];
        }
    }
    func_0021E1A0();
    func_00235820();
}

extern void display_set_offset(s8, s8);
extern void func_0021B840(s32, s32);
extern s32 D_00271C60_as_s32_a[];
extern s32 D_00271C64_as_s32_a[];
extern s8 D_0028E9EC;

void func_00235820(void)
{
    u16 selection;

    D_0028E9EC = 1;
    display_set_offset(D_0028E254, D_0028E250);

    selection = D_0028E32C;
    if (selection != 5) {
        s32 tableIndex = (selection & 0xFFFF) * 2;

        func_0021B840(D_00271C60_as_s32_a[tableIndex], D_00271C64_as_s32_a[tableIndex]);
    }
}

extern s32 D_0028EC7C;

void func_00235890(void) {
    extern SaveBlock D_006A3E50;
    s32 i;
    s32 j;
    s32 k;

    D_0028EC7C = 0;
    for (i = 0; i < 5; i++) {
        D_006A3E50.a00[i] = D_002BB378[i];
        D_006A3E50.a0A[i] = D_002BB368[i];
        D_006A3E50.a14[i] = D_002BB398[i];
        D_006A3E50.a1E[i] = D_002BB388[i];
        D_006A3E50.a28[i] = D_002BB358[i];
        D_006A3E50.a70[i] = D_002BB3F0[i];
        D_006A3E50.a84[i] = D_002BB338[i];
        D_006A3E50.a8E[i] = D_002BB348[i];
        D_006A3E50.a98[i] = D_002BB2A8[i];
        D_006A3E50.aA2[i] = D_002BB298[i];
        D_006A3E50.aAC[i] = D_002BB2C8[i];
        D_006A3E50.aB6[i] = D_002BB2B8[i];
        D_006A3E50.aC0[i] = D_002BB288[i];
        D_006A3E50.a108[i] = D_002BB320[i];
        D_006A3E50.a11C[i] = D_002BB268[i];
        D_006A3E50.a126[i] = D_002BB278[i];
    }
    for (i = 0; i < 15; i++) {
        D_006A3E50.a34[i] = D_002BB3B0[i];
        D_006A3E50.aCC[i] = D_002BB2E0[i];
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 30; j++) {
            D_006A3E50.a130[i][j] = D_002BB100[i][j];
            D_006A3E50.a1C6[i][j] = D_002BB060[i][j];
        }
    }
    D_006A3E50.b25C = D_0028E39C;
    D_006A3E50.b25D = D_0028E398;
    D_006A3E50.b25E = D_0028E394;
    D_006A3E50.b25F = D_0028E390;
    D_006A3E50.b260 = D_0028E358;
    D_006A3E50.b261 = D_0028E38C;
    D_006A3E50.b262 = D_0028E388;
    D_006A3E50.b263 = D_0028E384;
    D_006A3E50.b264 = D_0028E380;
    D_006A3E50.b265 = D_0028E37C;
    D_006A3E50.b266 = D_0028E360;
    D_006A3E50.b267 = D_0028E35C;
    D_006A3E50.h268 = D_0028E32C;
    D_006A3E50.b26A = D_0028E27C;
    D_006A3E50.b26B = D_0028E278;
    D_006A3E50.b274 = D_0028E254;
    D_006A3E50.b275 = D_0028E250;
    D_006A3E50.b276 = D_0028E258;
    D_006A3E50.h278 = D_0028E300;
    D_006A3E50.b59C = D_0028E2E0;
    D_006A3E50.b59D = D_0028E2DC;
    D_006A3E50.b59E = D_0028E2D8;
    D_006A3E50.b59F = D_0028E354;
    D_006A3E50.b5A0 = D_0028E28C;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                D_006A3E50.a27C[i][j][k] = D_00684CF0[i][j][k];
            }
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            D_006A3E50.a26C[i][j] = D_0028E270[i][j];
        }
    }
}


s32 func_00235ED0(void) {
    extern SaveBlock2 D_006A3E50;
    s32 i;
    s32 j;
    s32 k;
    s32 stage;

    stage = 0;
    for (i = 0; i < 5; i++) {
        if (D_006A3E50.a00[i] != D_002BB378[i]) {
            printf("typhi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a0A[i] != D_002BB368[i]) {
            printf("kyohi chg[%d] [%d][%d]\n", i, D_006A3E50.a0A[i], D_002BB368[i]);
            goto fail;
        }
        if (D_006A3E50.a14[i] != D_002BB398[i]) {
            printf("roundhi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a1E[i] != D_002BB388[i]) {
            printf("areahi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a28[i] != D_002BB358[i]) {
            printf("gphi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a70[i] != D_002BB3F0[i]) {
            printf("scohi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a84[i] != D_002BB338[i]) {
            printf("okuhi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a8E[i] != D_002BB348[i]) {
            printf("cnthi chg\n", i);
            goto fail;
        }
        if (D_006A3E50.a98[i] != D_002BB2A8[i] || D_006A3E50.aA2[i] != D_002BB298[i] ||
            D_006A3E50.aAC[i] != D_002BB2C8[i] || D_006A3E50.aB6[i] != D_002BB2B8[i] ||
            D_006A3E50.aC0[i] != D_002BB288[i] || D_006A3E50.a108[i] != D_002BB320[i] ||
            D_006A3E50.a11C[i] != D_002BB268[i] || D_006A3E50.a126[i] != D_002BB278[i]) {
            goto fail;
        }
    }
    stage++;
    for (i = 0; i < 15; i++) {
        if (D_006A3E50.a34[i] != D_002BB3B0[i] || D_006A3E50.aCC[i] != D_002BB2E0[i]) {
            goto fail;
        }
    }
    stage++;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 30; j++) {
            if (D_006A3E50.a130[i][j] != D_002BB100[i][j] || D_006A3E50.a1C6[i][j] != D_002BB060[i][j]) {
                goto fail;
            }
        }
    }
    if (D_006A3E50.b25C != D_0028E39C) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b25D != D_0028E398) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b25E != D_0028E394) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b25F != D_0028E390) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b260 != D_0028E358) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b261 != D_0028E38C) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b262 != D_0028E388) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b263 != D_0028E384) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b264 != D_0028E380) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b265 != D_0028E37C) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b266 != D_0028E360) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b267 != D_0028E35C) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.h268 != D_0028E32C) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b26A != D_0028E27C) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b26B != D_0028E278) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b274 != D_0028E254) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b275 != D_0028E250) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b276 != D_0028E258) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.h278 != D_0028E300) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b59C != D_0028E2E0) {
        printf("com_bgm\n");
        goto fail;
    }
    stage++;
    if (D_006A3E50.b59D != D_0028E2DC) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b59E != D_0028E2D8) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b59F != D_0028E354) {
        goto fail;
    }
    stage++;
    if (D_006A3E50.b5A0 != D_0028E28C) {
        goto fail;
    }
    stage++;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                if (D_006A3E50.a27C[i][j][k] != D_00684CF0[i][j][k]) {
                    goto fail;
                }
            }
        }
    }
    stage++;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            if (D_006A3E50.a26C[i][j] != D_0028E270[i][j]) {
                goto fail;
            }
        }
    }
    printf("--Data Ok!--\n");
    return 0;
fail:
    printf("--Data Chg!-[%d]-\n", stage);
    return 1;
}


s32 func_002365A0(void) {
    if (D_0028E278 == 0) {
        D_0028EC7C = 10;
    }
    switch (D_0028EC7C) {
    case 0:
        if (func_00235ED0() != 0) {
            D_0028EC7C++;
        } else {
            D_0028EC7C = 10;
        }
        break;
    case 1:
        func_002345B0();
        D_0028ED0C = 0;
        D_0028EC7C++;
    case 2:
        func_0022C6B0(0);
        if (D_0028ED0C != 0) {
            D_0028ED0C = 0;
            D_0028EC7C = 10;
        }
        break;
    }
    if (D_0028EC7C == 10) {
        func_00235890();
        D_0028EC7C = 0;
        return 1;
    }
    return 0;
}

extern void func_0018D9B0(void);
extern s32 D_00271FA0[];
extern s32 D_00271FA4[];
extern s32 D_00271FA8[];
extern s16 D_0028E2FC_as_s16;
extern u32 D_0057CC78_as_u32_a[];

void func_00236680(void) {
    extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
    s16 pressed;

    switch (D_0028ECF0) {
    case 0:
        pressed = (s16)(s32)D_0028E300 ^ D_0028E2FC_as_s16;
        pressed &= (s16)D_0028E300;
        if (pressed == 0) {
            D_0028ECF0 = 99;
        } else {
            D_0028ECF0++;
        }
        break;
    case 1:
        if (pressed & 1) {
            func_0018D9B0();
            D_0028ECF0++;
        } else {
            D_0028ECF0 = 3;
        }
        break;
    case 2:
        func_0022C5E0(200, D_00271FA0[0], 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78_as_u32_a[0] & 0x20) {
            D_0028ECF0++;
        }
        break;
    case 3:
        if (pressed & 2) {
            func_0018D9B0();
            D_0028ECF0++;
        } else {
            D_0028ECF0 = 5;
        }
        break;
    case 4:
        func_0022C5E0(200, D_00271FA4[0], 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78_as_u32_a[0] & 0x20) {
            D_0028ECF0++;
        }
        break;
    case 5:
        if (pressed & 8) {
            func_0018D9B0();
            D_0028ECF0++;
        } else {
            D_0028ECF0 = 7;
        }
        break;
    case 6:
        func_0022C5E0(200, D_00271FA8[0], 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78_as_u32_a[0] & 0x20) {
            D_0028ECF0++;
        }
        break;
    case 7:
        D_0028ECF0 = 99;
        break;
    case 99:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    }
}

extern u16 D_0028E2FC;
extern s32 D_0028EC78;

s32 func_002368E0(void) {
    D_0028EC78 = 0;
    D_0028E2FC = D_0028E300;
    return 1;
}

void func_00236900(void)
{
    u8 *buffer;
    u8 *cursor;
    s32 blockIndex;
    s32 bytesCleared;
    s32 blockOffset;

    blockIndex = 0;
    blockOffset = 0;

    do {
        buffer = D_006A0E50;
        cursor = buffer + blockOffset;
        bytesCleared = 0;

        do {
            cursor[0] = 0;
            cursor[1] = 0;
            bytesCleared += 8;
            cursor[2] = 0;
            cursor[3] = 0;
            cursor[4] = 0;
            cursor[5] = 0;
            cursor[6] = 0;
            cursor[7] = 0;
            cursor += 8;
        } while (bytesCleared < 0x400);

        blockIndex += 1;
        blockOffset += 0x400;
    } while (blockIndex < 12);
}

extern u16 D_006A0E50_as_u16_a[];
extern u16 D_006A0E52[];
extern u16 D_006A0E54[];
extern u16 D_006A0E56[];
extern u16 D_006A0E58[];
extern u16 D_006A0E5A[];
extern u16 D_006A0E5C[];
extern u16 D_006A0E5E[];
extern u16 D_006A0E60[];
extern u16 D_006A0E62[];
extern u16 D_006A0E64[];
extern u16 D_006A0E66[];
extern u16 D_006A0E68[];
extern u16 D_006A0E6A[];
extern u16 D_006A0E6C[];
extern u16 D_006A0E6E[];
extern u16 D_006A0E70[];
extern u16 D_006A0E72[];
extern u16 D_006A0E76[];
extern u16 D_006A0E78[];
extern u16 D_006A0E7A[];
extern u16 D_006A0E7C[];
extern u16 D_006A0E7E[];
extern u16 D_006A0E80[];
extern u16 D_006A0E82[];
extern u16 D_006A0E86[];
extern u16 D_006A0E90[];
extern u16 D_006C58A0_as_u16_a[];
extern u16 D_006C58A2[];
extern u16 D_006C58A4[];
extern u16 D_006C58A6[];
extern u16 D_006C58A8[];
extern u16 D_006C58AA[];
extern u16 D_006C58AC[];
extern u16 D_006C58AE[];
extern u16 D_006C58B0[];
extern u16 D_006C58B2[];
extern u16 D_006C58B4[];
extern u16 D_006C58B6[];
extern u16 D_006C58B8[];
extern u16 D_006C58BA[];
extern u16 D_006C58BC[];
extern u16 D_006C58BE[];
extern u16 D_006C58C0[];
extern u16 D_006C58C2[];
extern u16 D_006C58C6[];
extern u16 D_006C58C8[];
extern u16 D_006C58CA[];
extern u16 D_006C58CC[];
extern u16 D_006C58CE[];
extern u16 D_006C58D0[];
extern u16 D_006C58D2[];
extern u16 D_006C58D6[];

void func_00236960(s32 slot) {
    s32 off;

    off = slot * 512;
    D_006A0E52[off] = D_006C58A2[0];
    D_006A0E54[off] = D_006C58A4[0];
    D_006A0E56[off] = D_006C58A6[0];
    D_006A0E58[off] = D_006C58A8[0];
    D_006A0E5A[off] = D_006C58AA[0];
    D_006A0E5C[off] = D_006C58AC[0];
    D_006A0E5E[off] = D_006C58AE[0];
    D_006A0E50_as_u16_a[off] = D_006C58A0_as_u16_a[0];
    D_006A0E60[off] = D_006C58B0[0];
    D_006A0E62[off] = D_006C58B2[0];
    D_006A0E6C[off] = D_006C58BC[0];
    D_006A0E6E[off] = D_006C58BE[0];
    D_006A0E70[off] = D_006C58C0[0];
    D_006A0E68[off] = D_006C58B8[0];
    D_006A0E6A[off] = D_006C58BA[0];
    D_006A0E64[off] = D_006C58B4[0];
    D_006A0E66[off] = D_006C58B6[0];
    D_006A0E72[off] = D_006C58C2[0];
    D_006A0E76[off] = D_006C58C6[0];
    D_006A0E78[off] = D_006C58C8[0];
    D_006A0E7A[off] = D_006C58CA[0];
    D_006A0E7C[off] = D_006C58CC[0];
    D_006A0E7E[off] = D_006C58CE[0];
    D_006A0E80[off] = D_006C58D0[0];
    D_006A0E82[off] = D_006C58D2[0];
    D_006A0E86[off] = D_006C58D6[0];
    D_006A0E50_as_u16_a[off] = 1;
    D_006A0E90[off] = 0;
}
