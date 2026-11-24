#include "common.h"

s64 atoi();
s32 sprintf();
u8 func_00198170();
s32 func_00198280();
s32 memcpy();
s32 memset();
s32 printf();
extern u8 D_0027D810[];
extern u8 D_0027D820[];
extern u8 D_0027D830[];
extern u8 D_0027D840[];
extern u8 D_0027D850[];
extern u8 D_0027D860[];
extern u8 D_0027D870[];
extern u8 D_0027D880[];
extern u8 D_0027D890[];
extern u8 D_0027D8A0[];
extern u8 D_0027D8B0[];
extern u8 D_0027D8D0[];
extern u8 D_0027D8F0[];
extern u8 D_0028E290;
extern u8 D_0028E2BC;
extern s32 D_0028EAFC;
extern u8 D_002BADD0[];
extern u8 D_002BADF0[];
extern u8 D_002BB060_as_u8_a[];
extern u8 D_002BB100_as_u8_a[];
extern u8 D_002BB338_as_u8_a[];
extern u8 D_002BB348_as_u8_a[];
extern u8 D_002BB358_as_u8_a[];
extern u8 D_002BB368_as_u8_a[];
extern u8 D_002BB378_as_u8_a[];
extern u8 D_002BB388_as_u8_a[];
extern u8 D_002BB398_as_u8_a[];
extern u8 D_002BB3B0_as_u8_a[];
extern u8 D_002BB3F0_as_u8_a[];
void func_001984C0(void) {
    u32 save_d0;
    char str[0x28];
    u8 rec[14];
    u8 code[12];
    u32 score;
    u8 name[3];
    u16 val_fc;
    u16 val_fe;
    s32 i;
    u8 *p;
    s32 j;
    s32 i2;
    s32 k;
    s32 bits;
    s32 i1;
    s32 sum;
    u32 v0;
    u8 shift;
    u32 v3;
    u32 v4;
    u8 flags;
    u32 v1;
    u32 v2;
    u8 packed;
    u8 sw;
    u8 x;

    if (D_0028EAFC == 0xFF) return;
    save_d0 = reg_d0.w;
    for (j = 0; j < 14; j++) {
        rec[j] = 0;
    }
    flags = 0;
    score = ((u32 *)D_002BB3F0_as_u8_a)[D_0028EAFC];
    for (i = 0; i < 3; i++) {
        name[i] = ((u32 *)D_002BB3B0_as_u8_a)[D_0028EAFC * 3 + i];
    }
    v0 = ((u16 *)D_002BB388_as_u8_a)[D_0028EAFC];
    v1 = ((u16 *)D_002BB378_as_u8_a)[D_0028EAFC];
    v2 = ((u16 *)D_002BB368_as_u8_a)[D_0028EAFC];
    val_fc = ((u16 *)D_002BB338_as_u8_a)[D_0028EAFC];
    v3 = ((u16 *)D_002BB398_as_u8_a)[D_0028EAFC];
    val_fe = ((u16 *)D_002BB358_as_u8_a)[D_0028EAFC];
    v4 = ((u16 *)D_002BB348_as_u8_a)[D_0028EAFC];
    shift = (u32)D_0028E2BC & 3;
    if (shift == 0) {
        shift = (u8)(shift + 1);
    }
    printf(D_0027D810, D_0028EAFC);
    printf(D_0027D820, (u8)shift);
    printf(D_0027D830, val_fc);
    printf(D_0027D840, score);
    printf(D_0027D850, (u16)v0);
    v1 = (u16)(v1 >> 1);
    printf(D_0027D860, v1);
    v2 = (u16)(v2 >> 1);
    printf(D_0027D870, v2);
    printf(D_0027D880, (u16)v3);
    printf(D_0027D890, val_fe);
    printf(D_0027D8A0, (u16)v4);
    printf(D_0027D8B0, name[0], name[1], name[2]);
    packed = (s8)(v1 & 3) << 6;
    packed |= (s8)(v2 & 3) << 4;
    packed |= v0 & 7;
    if (D_0028E290 == 2) {
        flags |= 0x80;
    } else {
        flags = 0;
    }
    flags |= (v3 & 1) << 6;
    flags |= (v4 & 0xF) << 2;
    p = (u8 *)&score;
    rec[0] = p[0];
    rec[1] = p[1];
    rec[2] = p[2];
    rec[3] = p[3];
    rec[4] = packed;
    p = (u8 *)&val_fc;
    rec[5] = p[0];
    rec[6] = p[1];
    rec[8] = name[0];
    rec[9] = name[1];
    rec[10] = name[2];
    rec[7] = 0;
    rec[11] = 0;
    p = (u8 *)&val_fe;
    rec[12] = p[0];
    rec[13] = p[1];
    memset(code, 0, 12);
    memcpy(code, rec, 12);
    sum = 0;
    sprintf(str, D_0027D8D0, code[3], code[2], code[1], code[0]);
    sum += atoi(str);
    sprintf(str, D_0027D8F0, code[6], code[5]);
    sum += atoi(str);
    j = 2;
    bits = 0;
    for (i1 = 0; i1 < 4; i1++, j++) {
        if (code[11] & (1 << j)) {
            bits |= 1 << i1;
        }
    }
    code[0] = 0;
    code[1] = 0;
    code[2] = 0;
    code[3] = 0;
    sum += bits;
    k = 0;
    for (i2 = 0; i2 < 4; i2++) {
        for (j = 0; j < 8; j++, k++) {
            if (sum & (1 << k)) {
                code[i2] |= 1 << j;
            }
        }
    }
    code[5] = rec[12];
    code[6] = rec[13];
    sw = code[0];
    code[0] = code[8];
    code[8] = sw;
    sw = code[5];
    code[5] = code[10];
    code[10] = sw;
    for (i = 0; i < 12; i++) {
        code[i] = func_00198170(code[i], (s8)shift);
    }
    flags |= shift;
    code[11] = flags;
    x = 0;
    for (i = 0; i < 12; i++) {
        x ^= code[i];
    }
    code[7] = x;
    memset(D_002BADF0, 0, 12);
    memcpy(D_002BADF0, code, 12);
    func_00198280();
    if (D_0028E290 == 2) {
        memcpy(D_002BB060_as_u8_a + D_0028EAFC * 0x1E, D_002BADD0, 0x1E);
    } else {
        memcpy(D_002BB100_as_u8_a + D_0028EAFC * 0x1E, D_002BADD0, 0x1E);
    }
    reg_d0.w = save_d0;
}
