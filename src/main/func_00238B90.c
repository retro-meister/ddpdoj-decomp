#include "common.h"

typedef struct {
    f32 v[4];
} Vec4;

typedef struct {
    s16 h[16];
} Row16;

typedef struct {
    u8 a[90];
    u8 b[90];
} Bank90;

typedef struct {
    u8 a[10];
    u8 b[10];
} Bank10;

typedef struct {
    u8 f0000[0xC08];
    u8 padC08[0xE];
    u8 fC16[98];
    u8 fC78[98];
    u8 fCDA[100];
    u8 fD3E[100];
    u8 fDA2[0xD80];
    u8 f1B22[0x600];
    u8 f2122[0x600];
    u8 f2722[0x20];
    u8 f2742[0x20];
    u8 f2762[0x20];
    u8 f2782[0x20];
    u8 f27A2[0x870];
    u8 pad3012[0x1A];
    s32 f302C[16];
    s32 f306C[16];
    s32 f30AC[16];
    s32 f30EC[16];
    u8 pad312C[0xF2];
    u8 f321E[0x48];
    u8 pad3266[0x4E];
    u8 f32B4[90];
    u8 f330E[90];
    u8 f3368[10];
    u8 f3372[10];
    u8 pad337C[0xDC];
    s32 f3458[16];
    s32 f3498[16];
    u8 pad34D8[0x39];
    s8 f3511[0x2000];
    Row16 f5512;
} Buf;

extern s32 printf(const char *format, ...);
extern char D_0028BF40[];
extern char D_0028BF58[];
extern char D_0028BF68[];
extern char D_0028BF78[];
extern char D_0028BF88[];
extern char D_0028BF98[];
extern u16 D_0028DFB4;
extern u16 D_0028DFB8;
extern u16 D_0028DFBC;
extern u16 D_0028DFC0;
extern u16 D_0028DFC4;
extern u16 D_0028DFC8;
extern u16 D_0028DFCC;
extern u16 D_0028DFD0;
extern u16 D_0028DFD4;
extern u16 D_0028DFD8;
extern u16 D_0028DFDC;
extern u16 D_0028DFE0;
extern u16 D_0028DFE4;
extern u16 D_0028DFE8;
extern u16 D_0028DFEC;
extern u16 D_0028DFF0;
extern s32 D_0028DFF4;
extern u16 D_0028DFF8;
extern u16 D_0028DFFC;
extern u16 D_0028E000;
extern u16 D_0028E004;
extern u16 D_0028E008;
extern u16 D_0028E00C;
extern u16 D_0028E010;
extern u16 D_0028E014;
extern u16 D_0028E018;
extern u16 D_0028E01C;
extern u16 D_0028E020;
extern u16 D_0028E024;
extern u16 D_0028E028;
extern u16 D_0028E02C;
extern u16 D_0028E030;
extern u16 D_0028E034;
extern u16 D_0028E038;
extern u16 D_0028E03C;
extern u16 D_0028E040;
extern u16 D_0028E044;
extern u16 D_0028E050;
extern u16 D_0028E054;
extern s32 D_0028E058;
extern s32 D_0028E05C;
extern u16 D_0028E060;
extern u16 D_0028E064;
extern u16 D_0028E068;
extern u16 D_0028E06C;
extern u16 D_0028E070;
extern u16 D_0028E074;
extern s32 D_0028E078[];
extern s32 D_0028E07C[];
extern s32 D_0028E080[];
extern s32 D_0028E084[];
extern u16 D_0028E088;
extern u8 D_0028E284;
extern u8 D_0028E288;
extern u8 D_0028E2EC;
extern u8 D_0028E304;
extern u8 D_0028E384;
extern u8 D_0028E388;
extern u8 D_0028E38C;
extern u16 D_0028E3DC;
extern u16 D_0028E3E0;
extern u16 D_0028E3E4;
extern u16 D_0028E3E8;
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern u16 D_0028E578;
extern u16 D_0028E57C;
extern u16 D_0028E580;
extern u16 D_0028E584;
extern u16 D_0028E588;
extern u16 D_0028E58C;
extern s32 D_0028E590;
extern s32 D_0028E594;
extern u16 D_0028E598;
extern u16 D_0028E59C;
extern u16 D_0028E5A0;
extern u16 D_0028E5A4;
extern u16 D_0028E5A8;
extern u16 D_0028E5AC;
extern u16 D_0028E5B0;
extern u16 D_0028E5B4;
extern u16 D_0028E5B8;
extern u16 D_0028E5BC;
extern u16 D_0028E5C0;
extern u16 D_0028E5C4;
extern u16 D_0028E5C8;
extern u16 D_0028E5CC;
extern u16 D_0028E5D0;
extern u16 D_0028E5D4;
extern u16 D_0028E5D8;
extern u16 D_0028E5DC;
extern u16 D_0028E5E0;
extern u16 D_0028E5E4;
extern u16 D_0028E5E8;
extern u16 D_0028E5EC;
extern u16 D_0028E5F0;
extern u16 D_0028E5F4;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u16 D_0028E600;
extern u16 D_0028E604;
extern u16 D_0028E608;
extern u16 D_0028E60C;
extern u16 D_0028E610;
extern u16 D_0028E614;
extern u16 D_0028E618;
extern u16 D_0028E61C;
extern s32 D_0028E620;
extern s32 D_0028E624;
extern u16 D_0028E628;
extern u16 D_0028E62C;
extern u16 D_0028E630;
extern u16 D_0028E634;
extern s32 D_0028E638;
extern s32 D_0028E63C;
extern u16 D_0028E640;
extern u16 D_0028E644;
extern u16 D_0028E648;
extern u16 D_0028E64C;
extern u16 D_0028E650;
extern u16 D_0028E654;
extern u16 D_0028E658;
extern u16 D_0028E65C;
extern u16 D_0028E660;
extern s32 D_0028E664;
extern s32 D_0028E668;
extern s32 D_0028E66C;
extern u16 D_0028E670;
extern u16 D_0028E674;
extern u16 D_0028E678;
extern u16 D_0028E67C;
extern u16 D_0028E680;
extern u16 D_0028E684;
extern u16 D_0028E688;
extern s32 D_0028E68C;
extern s32 D_0028E690;
extern u16 D_0028E694;
extern u16 D_0028E698;
extern u16 D_0028E69C;
extern u16 D_0028E6A0;
extern s32 D_0028E6A4;
extern s32 D_0028E6A8;
extern s32 D_0028E6AC;
extern u16 D_0028E6B0;
extern u16 D_0028E6B4;
extern u16 D_0028E6B8;
extern u16 D_0028E6BC;
extern u16 D_0028E6C0;
extern u16 D_0028E6C4;
extern u16 D_0028E6C8;
extern s32 D_0028E6CC;
extern s32 D_0028E6D0;
extern u16 D_0028E6D4;
extern u16 D_0028E6D8;
extern u16 D_0028E6DC;
extern u16 D_0028E6E0;
extern u16 D_0028E6E4;
extern s32 D_0028E6E8;
extern u16 D_0028E6EC;
extern s32 D_0028E6F0;
extern u16 D_0028E6F4;
extern u16 D_0028E6F8;
extern s32 D_0028E6FC;
extern u16 D_0028E700;
extern u16 D_0028E704;
extern u8 D_0028E708;
extern u8 D_0028E70C;
extern u16 D_0028E710;
extern s32 D_0028E714;
extern s32 D_0028E718;
extern s32 D_0028E71C;
extern u16 D_0028E728;
extern u16 D_0028E72C;
extern s32 D_0028E730;
extern s32 D_0028E734;
extern u16 D_0028E738;
extern u16 D_0028E73C;
extern s32 D_0028E740;
extern s32 D_0028E744;
extern u16 D_0028E748;
extern u16 D_0028E74C;
extern u16 D_0028E750;
extern u16 D_0028E754;
extern u16 D_0028E758;
extern u16 D_0028E75C;
extern s32 D_0028E760;
extern s32 D_0028E764;
extern s32 D_0028E768;
extern u16 D_0028E850;
extern u16 D_0028E854;
extern u16 D_0028E858;
extern u16 D_0028E85C;
extern u16 D_0028E860;
extern u16 D_0028E864;
extern u16 D_0028E868;
extern u16 D_0028E86C;
extern u16 D_0028E870;
extern u16 D_0028E874;
extern u16 D_0028E878;
extern u16 D_0028E87C;
extern u16 D_0028E880;
extern u16 D_0028E884;
extern u16 D_0028E888;
extern u16 D_0028E88C;
extern u16 D_0028E890;
extern u16 D_0028E894;
extern u16 D_0028E8A4;
extern u16 D_0028E8A8;
extern u16 D_0028E8AC;
extern u8 D_0028E8B0;
extern u8 D_0028E8B4;
extern u16 D_0028E8B8;
extern s32 D_0028E8BC;
extern u16 D_0028E8C0;
extern u16 D_0028E8C4;
extern u16 D_0028E8C8;
extern u16 D_0028E8CC;
extern u16 D_0028E8D0;
extern u16 D_0028E8D4;
extern u16 D_0028E8D8;
extern u16 D_0028E8DC;
extern u16 D_0028E8E0;
extern u16 D_0028E8E4;
extern u16 D_0028E8E8;
extern u16 D_0028E8EC;
extern u16 D_0028E8F0;
extern u16 D_0028E8F4;
extern u16 D_0028E8F8;
extern u16 D_0028E8FC;
extern u16 D_0028E900;
extern u16 D_0028E904;
extern u16 D_0028E908;
extern u16 D_0028E90C;
extern u16 D_0028E910;
extern u16 D_0028E914;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern u16 D_0028E920;
extern u16 D_0028E924;
extern u16 D_0028E928;
extern u16 D_0028E970;
extern u16 D_0028E974;
extern u16 D_0028E978;
extern u16 D_0028E97C;
extern u16 D_0028E980;
extern u16 D_0028E984;
extern u16 D_0028E988;
extern s16 D_0029C060[];
extern f32 D_0029CD80[];
extern u16 D_0029CD8C[];
extern f32 D_0029CD90[];
extern u16 D_0029CD9C[];
extern s32 D_0029CDA0[];
extern s32 D_0029CDE0[];
extern s32 D_0029CE20[];
extern s32 D_0029CE60[];
extern u8 D_0029CEA0[];
extern u8 D_0029D710[];
extern u8 D_0029D730[];
extern u8 D_0029D750[];
extern u8 D_0029D770[];
extern u8 D_0029D790[];
extern u8 D_0029DD90[];
extern u8 D_0029E390[];
extern u8 D_0029F110[];
extern u8 D_0029F180[];
extern u8 D_0029F1F0[];
extern u8 D_0029F1F1[];
extern u16 D_0029F210[];
extern u16 D_0029F212[];
extern u8 D_0029F214[];
extern u8 D_0029F215[];
extern u8 D_0029F260[];
extern u8 D_0029F261[];
extern u16 D_0029F280[];
extern u16 D_0029F282[];
extern u8 D_0029F284[];
extern u8 D_0029F285[];
extern s8 D_002B4D50[];
extern s32 D_002BAEB0[];
extern s32 D_002BAEF0[];
extern Bank10 D_002BAF30;
extern Bank90 D_002BAF50;
extern u8 D_002BF390[];
extern u8 D_002BF4F0[];
extern s16 D_006C58AA[];
extern u16 D_006C58B0[];
extern u16 D_006C58B2[];
extern u16 D_006C58B4[];
extern s16 D_006C58B6[];
extern s16 D_006C58B8[];
extern s16 D_006C58BA[];
extern u16 D_006C58BC[];
extern u16 D_006C58BE[];
extern u16 D_006C58C0[];
extern s16 D_006C58C2[];
extern u16 D_006C58C6[];
extern s16 D_006C58C8[];
extern s16 D_006C58CA[];
extern s16 D_006C58CC[];
extern s16 D_006C58CE[];
extern s16 D_006C58D0[];
extern u16 D_006C58D2[];
extern u16 D_006C58D4[];
extern s16 D_006C58D6[];
void func_00238B90(Buf *buf) {
    s32 i;
    s32 v;
    u8 *p = (u8 *)buf;

    printf(D_0028BF40, 0x5534);
    for (i = 0; i < 0xC08; i++) {
        buf->f0000[i] = D_002BF4F0[i];
    }
    *(u16 *)(p + 0xC08) = D_0028E988;
    *(u16 *)(p + 0xC0A) = D_0028E984;
    *(u16 *)(p + 0xC0C) = D_0028E980;
    *(u16 *)(p + 0xC0E) = D_0028E97C;
    *(u16 *)(p + 0xC10) = D_0028E978;
    *(u16 *)(p + 0xC12) = D_0028E974;
    *(u16 *)(p + 0xC14) = D_0028E970;
    for (i = 0; i < 98; i++) {
        buf->fC16[i] = D_0029F260[i];
        buf->fC78[i] = D_0029F1F0[i];
    }
    for (i = 0; i < 100; i++) {
        buf->fCDA[i] = D_0029F180[i];
        buf->fD3E[i] = D_0029F110[i];
    }
    for (i = 0; i < 0xD80; i++) {
        buf->fDA2[i] = D_0029E390[i];
    }
    for (i = 0; i < 0x600; i++) {
        buf->f1B22[i] = D_0029DD90[i];
        buf->f2122[i] = D_0029D790[i];
    }
    for (i = 0; i < 0x20; i++) {
        buf->f2722[i] = D_0029D770[i];
        buf->f2742[i] = D_0029D750[i];
    }
    for (i = 0; i < 0x20; i++) {
        buf->f2762[i] = D_0029D730[i];
        buf->f2782[i] = D_0029D710[i];
    }
    for (i = 0; i < 0x870; i++) {
        buf->f27A2[i] = D_0029CEA0[i];
    }
    *(u16 *)(p + 0x301A) = D_0028E088;
    *(s32 *)(p + 0x301C) = D_0028E080[0];
    *(s32 *)(p + 0x3024) = D_0028E078[0];
    *(s32 *)(p + 0x3020) = D_0028E084[0];
    *(s32 *)(p + 0x3028) = D_0028E07C[0];
    for (i = 0; i < 16; i++) {
        buf->f302C[i] = D_0029CE60[i];
        buf->f306C[i] = D_0029CE20[i];
        buf->f30AC[i] = D_0029CDE0[i];
        buf->f30EC[i] = D_0029CDA0[i];
    }
    *(Vec4 *)(p + 0x312C) = *(Vec4 *)D_0029CD90;
    *(Vec4 *)(p + 0x313C) = *(Vec4 *)D_0029CD80;
    *(u16 *)(p + 0x314C) = D_0028E074;
    *(u16 *)(p + 0x314E) = D_0028E070;
    *(u16 *)(p + 0x3150) = D_0028E06C;
    *(u16 *)(p + 0x3152) = D_0028E068;
    *(u16 *)(p + 0x3154) = D_0028E064;
    *(u16 *)(p + 0x3156) = D_0028E060;
    *(s32 *)(p + 0x3158) = D_0028E05C;
    *(s32 *)(p + 0x315C) = D_0028E058;
    *(u16 *)(p + 0x3160) = D_0028E054;
    *(u16 *)(p + 0x3162) = D_0028E050;
    *(u16 *)(p + 0x3164) = D_0028E044;
    *(u16 *)(p + 0x3166) = D_0028E040;
    *(u16 *)(p + 0x3168) = D_0028E03C;
    *(u16 *)(p + 0x316A) = D_0028E038;
    *(u16 *)(p + 0x316C) = D_0028E034;
    *(u16 *)(p + 0x316E) = D_0028E030;
    *(u16 *)(p + 0x3170) = D_0028E02C;
    *(u16 *)(p + 0x3172) = D_0028E028;
    *(u16 *)(p + 0x3174) = D_0028E024;
    *(u16 *)(p + 0x3176) = D_0028E020;
    *(u16 *)(p + 0x3178) = D_0028E01C;
    *(u16 *)(p + 0x317A) = D_0028E018;
    *(u16 *)(p + 0x317C) = D_0028E014;
    *(u16 *)(p + 0x317E) = D_0028E010;
    *(u16 *)(p + 0x3180) = D_0028E00C;
    *(u16 *)(p + 0x3182) = D_0028E008;
    *(u16 *)(p + 0x3184) = D_0028E004;
    *(u16 *)(p + 0x3186) = D_0028E000;
    *(u16 *)(p + 0x3188) = D_0028DFFC;
    *(u16 *)(p + 0x318A) = D_0028DFF8;
    *(s32 *)(p + 0x318C) = D_0028DFF4;
    *(u16 *)(p + 0x3190) = D_0028DFF0;
    *(u16 *)(p + 0x3192) = D_0028DFEC;
    *(u16 *)(p + 0x3194) = D_0028DFE8;
    *(u16 *)(p + 0x3196) = D_0028DFE4;
    *(u16 *)(p + 0x3198) = D_0028DFE0;
    *(u16 *)(p + 0x319A) = D_0028DFDC;
    *(u16 *)(p + 0x319C) = D_0028DFD8;
    *(u16 *)(p + 0x319E) = D_0028DFD4;
    *(u16 *)(p + 0x31A0) = D_0028DFD0;
    *(u16 *)(p + 0x31A2) = D_0028DFCC;
    *(u16 *)(p + 0x31A4) = D_0028DFC8;
    *(u16 *)(p + 0x31A6) = D_0028DFC4;
    *(u16 *)(p + 0x31A8) = D_0028DFC0;
    *(u16 *)(p + 0x31AA) = D_0028DFBC;
    *(u16 *)(p + 0x31AC) = D_0028DFB8;
    *(u16 *)(p + 0x31AE) = D_0028DFB4;
    *(u16 *)(p + 0x31B0) = D_0028E928;
    *(u16 *)(p + 0x31B2) = D_0028E924;
    *(u16 *)(p + 0x31B4) = D_0028E920;
    *(u16 *)(p + 0x31B6) = D_0028E91C;
    *(u16 *)(p + 0x31B8) = D_0028E918;
    *(u16 *)(p + 0x31BA) = D_0028E914;
    *(u16 *)(p + 0x31BC) = D_0028E910;
    *(u16 *)(p + 0x31BE) = D_0028E90C;
    *(u16 *)(p + 0x31C0) = D_0028E908;
    *(u16 *)(p + 0x31C2) = D_0028E904;
    *(u16 *)(p + 0x31C4) = D_0028E900;
    *(u16 *)(p + 0x31C6) = D_0028E8FC;
    *(u16 *)(p + 0x31C8) = D_0028E8F8;
    *(u16 *)(p + 0x31CA) = D_0028E8F4;
    *(u16 *)(p + 0x31CC) = D_0028E8F0;
    *(u16 *)(p + 0x31CE) = D_0028E8EC;
    *(u16 *)(p + 0x31D0) = D_0028E8E8;
    *(u16 *)(p + 0x31D2) = D_0028E8E4;
    *(u16 *)(p + 0x31D4) = D_0028E8E0;
    *(u16 *)(p + 0x31D6) = D_0028E8DC;
    *(u16 *)(p + 0x31D8) = D_0028E8D8;
    *(u16 *)(p + 0x31DA) = D_0028E8D4;
    *(u16 *)(p + 0x31DC) = D_0028E8D0;
    *(u16 *)(p + 0x31DE) = D_0028E8CC;
    *(u16 *)(p + 0x31E0) = D_0028E8C8;
    *(u16 *)(p + 0x31E2) = D_0028E8C4;
    *(u16 *)(p + 0x31E4) = D_0028E8C0;
    *(s32 *)(p + 0x31E8) = D_0028E8BC;
    *(u16 *)(p + 0x31EC) = D_0028E8B8;
    p[0x31EE] = D_0028E8B4;
    p[0x31EF] = D_0028E8B0;
    *(u16 *)(p + 0x31F0) = D_0028E8A8;
    *(u16 *)(p + 0x31F2) = D_0028E8A4;
    *(u16 *)(p + 0x31F4) = D_0028E8AC;
    *(u16 *)(p + 0x31FC) = D_0028E894;
    *(u16 *)(p + 0x31FE) = D_0028E890;
    *(u16 *)(p + 0x3200) = D_0028E88C;
    *(u16 *)(p + 0x3202) = D_0028E888;
    *(u16 *)(p + 0x3204) = D_0028E884;
    *(u16 *)(p + 0x3206) = D_0028E880;
    *(u16 *)(p + 0x3208) = D_0028E87C;
    *(u16 *)(p + 0x320A) = D_0028E878;
    *(u16 *)(p + 0x320C) = D_0028E874;
    *(u16 *)(p + 0x320E) = D_0028E870;
    *(u16 *)(p + 0x3210) = D_0028E86C;
    *(u16 *)(p + 0x3212) = D_0028E868;
    *(u16 *)(p + 0x3214) = D_0028E864;
    *(u16 *)(p + 0x3216) = D_0028E860;
    *(u16 *)(p + 0x3218) = D_0028E85C;
    *(u16 *)(p + 0x321A) = D_0028E858;
    *(u16 *)(p + 0x321C) = D_0028E854;
    for (i = 0; i < 0x48; i++) {
        buf->f321E[i] = D_002BF390[i];
    }
    *(u16 *)(p + 0x3266) = D_0028E850;
    *(s32 *)(p + 0x327C) = D_0028E768;
    *(s32 *)(p + 0x3280) = D_0028E764;
    *(s32 *)(p + 0x3284) = D_0028E760;
    *(u16 *)(p + 0x3288) = D_0028E75C;
    *(u16 *)(p + 0x328A) = D_0028E758;
    *(u16 *)(p + 0x328C) = D_0028E754;
    *(u16 *)(p + 0x328E) = D_0028E750;
    *(u16 *)(p + 0x3290) = D_0028E74C;
    *(u16 *)(p + 0x3292) = D_0028E748;
    *(s32 *)(p + 0x3294) = D_0028E744;
    *(s32 *)(p + 0x3298) = D_0028E740;
    *(u16 *)(p + 0x329C) = D_0028E73C;
    *(u16 *)(p + 0x329E) = D_0028E738;
    *(s32 *)(p + 0x32A0) = D_0028E734;
    *(s32 *)(p + 0x32A4) = D_0028E730;
    *(u16 *)(p + 0x32A8) = D_0028E72C;
    *(u16 *)(p + 0x32AA) = D_0028E728;
    *(s32 *)(p + 0x32AC) = D_0028E71C;
    *(s32 *)(p + 0x32B0) = D_0028E718;
    for (i = 0; i < 90; i++) {
        buf->f32B4[i] = D_002BAF50.a[i];
    }
    for (i = 0; i < 90; i++) {
        buf->f330E[i] = D_002BAF50.b[i];
    }
    for (i = 0; i < 10; i++) {
        buf->f3368[i] = D_002BAF30.a[i];
    }
    for (i = 0; i < 10; i++) {
        buf->f3372[i] = D_002BAF30.b[i];
    }
    *(s32 *)(p + 0x337C) = D_0028E714;
    *(u16 *)(p + 0x3380) = D_0028E710;
    p[0x3382] = D_0028E70C;
    p[0x3383] = D_0028E708;
    *(u16 *)(p + 0x3384) = D_0028E704;
    *(u16 *)(p + 0x3386) = D_0028E700;
    *(s32 *)(p + 0x3388) = D_0028E6FC;
    *(u16 *)(p + 0x338C) = D_0028E6F8;
    *(u16 *)(p + 0x338E) = D_0028E6F4;
    *(s32 *)(p + 0x3390) = D_0028E6F0;
    *(u16 *)(p + 0x3394) = D_0028E6EC;
    *(s32 *)(p + 0x3398) = D_0028E6E8;
    *(u16 *)(p + 0x339C) = D_0028E6E4;
    *(u16 *)(p + 0x339E) = D_0028E6E0;
    *(u16 *)(p + 0x33A0) = D_0028E6DC;
    *(u16 *)(p + 0x33A2) = D_0028E6D8;
    *(u16 *)(p + 0x33A4) = D_0028E6D4;
    *(s32 *)(p + 0x33A8) = D_0028E6D0;
    *(s32 *)(p + 0x33AC) = D_0028E6CC;
    *(u16 *)(p + 0x33B0) = D_0028E6C8;
    *(u16 *)(p + 0x33B2) = D_0028E6C4;
    *(u16 *)(p + 0x33B4) = D_0028E6C0;
    *(u16 *)(p + 0x33B6) = D_0028E6BC;
    *(u16 *)(p + 0x33B8) = D_0028E6B8;
    *(u16 *)(p + 0x33BA) = D_0028E6B4;
    *(u16 *)(p + 0x33BC) = D_0028E6B0;
    *(s32 *)(p + 0x33C0) = D_0028E6AC;
    *(s32 *)(p + 0x33C4) = D_0028E6A8;
    *(s32 *)(p + 0x33C8) = D_0028E6A4;
    *(u16 *)(p + 0x33CC) = D_0028E6A0;
    *(u16 *)(p + 0x33CE) = D_0028E69C;
    *(u16 *)(p + 0x33D0) = D_0028E698;
    *(u16 *)(p + 0x33D2) = D_0028E694;
    *(s32 *)(p + 0x33D4) = D_0028E690;
    *(s32 *)(p + 0x33D8) = D_0028E68C;
    *(u16 *)(p + 0x33DC) = D_0028E688;
    *(u16 *)(p + 0x33DE) = D_0028E684;
    *(u16 *)(p + 0x33E0) = D_0028E680;
    *(u16 *)(p + 0x33E2) = D_0028E67C;
    *(u16 *)(p + 0x33E4) = D_0028E678;
    *(u16 *)(p + 0x33E6) = D_0028E674;
    *(u16 *)(p + 0x33E8) = D_0028E670;
    *(s32 *)(p + 0x33EC) = D_0028E66C;
    *(s32 *)(p + 0x33F0) = D_0028E668;
    *(s32 *)(p + 0x33F4) = D_0028E664;
    *(u16 *)(p + 0x33F8) = D_0028E660;
    *(u16 *)(p + 0x33FA) = D_0028E65C;
    *(u16 *)(p + 0x33FC) = D_0028E658;
    *(u16 *)(p + 0x33FE) = D_0028E654;
    *(u16 *)(p + 0x3400) = D_0028E650;
    *(u16 *)(p + 0x3402) = D_0028E64C;
    *(u16 *)(p + 0x3404) = D_0028E648;
    *(u16 *)(p + 0x3406) = D_0028E644;
    *(u16 *)(p + 0x3408) = D_0028E640;
    *(s32 *)(p + 0x340C) = D_0028E63C;
    *(s32 *)(p + 0x3410) = D_0028E638;
    *(u16 *)(p + 0x3414) = D_0028E634;
    *(u16 *)(p + 0x3416) = D_0028E630;
    *(u16 *)(p + 0x3418) = D_0028E62C;
    *(u16 *)(p + 0x341A) = D_0028E628;
    *(s32 *)(p + 0x341C) = D_0028E624;
    *(s32 *)(p + 0x3420) = D_0028E620;
    *(u16 *)(p + 0x3424) = D_0028E61C;
    *(u16 *)(p + 0x3426) = D_0028E618;
    *(u16 *)(p + 0x3428) = D_0028E614;
    *(u16 *)(p + 0x342A) = D_0028E610;
    *(u16 *)(p + 0x342C) = D_0028E60C;
    *(u16 *)(p + 0x342E) = D_0028E608;
    *(u16 *)(p + 0x3430) = D_0028E604;
    *(u16 *)(p + 0x3432) = D_0028E600;
    *(u16 *)(p + 0x3434) = D_0028E5FC;
    *(u16 *)(p + 0x3436) = D_0028E5F8;
    *(u16 *)(p + 0x3438) = D_0028E5F4;
    *(u16 *)(p + 0x343A) = D_0028E5F0;
    *(u16 *)(p + 0x343C) = D_0028E5EC;
    *(u16 *)(p + 0x343E) = D_0028E5E8;
    *(u16 *)(p + 0x3440) = D_0028E5E4;
    *(u16 *)(p + 0x3442) = D_0028E5E0;
    *(u16 *)(p + 0x3444) = D_0028E5DC;
    *(u16 *)(p + 0x3446) = D_0028E5D8;
    *(u16 *)(p + 0x3448) = D_0028E5D4;
    *(u16 *)(p + 0x344A) = D_0028E5D0;
    *(u16 *)(p + 0x344C) = D_0028E5CC;
    *(u16 *)(p + 0x344E) = D_0028E5C8;
    *(u16 *)(p + 0x3450) = D_0028E5C4;
    *(u16 *)(p + 0x3452) = D_0028E5C0;
    *(u16 *)(p + 0x3454) = D_0028E5BC;
    for (i = 0; i < 16; i++) {
        buf->f3458[i] = D_002BAEF0[i];
    }
    for (i = 0; i < 16; i++) {
        buf->f3498[i] = D_002BAEB0[i];
    }
    *(u16 *)(p + 0x34D8) = D_0028E5B8;
    *(u16 *)(p + 0x34DA) = D_0028E5B4;
    *(u16 *)(p + 0x34DC) = D_0028E5B0;
    *(u16 *)(p + 0x34DE) = D_0028E5AC;
    *(u16 *)(p + 0x34E0) = D_0028E5A8;
    *(u16 *)(p + 0x34E2) = D_0028E5A4;
    *(u16 *)(p + 0x34E4) = D_0028E5A0;
    *(u16 *)(p + 0x34E6) = D_0028E59C;
    *(u16 *)(p + 0x34E8) = D_0028E598;
    *(s32 *)(p + 0x34EC) = D_0028E594;
    *(s32 *)(p + 0x34F0) = D_0028E590;
    *(u16 *)(p + 0x34F4) = D_0028E58C;
    *(u16 *)(p + 0x34F6) = D_0028E588;
    *(u16 *)(p + 0x34F8) = D_0028E584;
    *(u16 *)(p + 0x34FA) = D_0028E580;
    *(u16 *)(p + 0x34FC) = D_0028E57C;
    *(u16 *)(p + 0x34FE) = D_0028E578;
    p[0x350C] = D_0028E38C;
    p[0x350D] = D_0028E388;
    p[0x350E] = D_0028E384;
    p[0x350F] = D_0028E2EC;
    p[0x3510] = D_0028E304;
    *(u16 *)(p + 0x3500) = D_0028E3F0;
    *(u16 *)(p + 0x3502) = D_0028E3EC;
    *(u16 *)(p + 0x3504) = D_0028E3E8;
    *(u16 *)(p + 0x3506) = D_0028E3E4;
    *(u16 *)(p + 0x3508) = D_0028E3E0;
    *(u16 *)(p + 0x350A) = D_0028E3DC;
    *(Row16 *)(p + 0x5512) = *(Row16 *)D_0029C060;
    for (i = 0; i < 0x2000; i++) {
        buf->f3511[i] = D_002B4D50[i];
    }
    p[0x5532] = D_0028E288;
    p[0x5533] = D_0028E284;
    D_006C58D6[0] = 0xCB;
    D_006C58AA[0] = D_0028E38C;
    D_006C58C8[0] = D_0028E388;
    if (*(s16 *)D_0029F260 < 0) {
        D_006C58C6[0] = D_0028E8C4;
    } else {
        D_006C58C6[0] = D_0028E8C0;
    }
    D_006C58B8[0] = 0;
    D_006C58C2[0] = 1;
    D_006C58BA[0] = 0;
    D_006C58C0[0] = D_0028E904;
    if (*(s16 *)D_0029F260 < 0) {
        D_006C58D4[0] = D_0028E02C;
        if (D_006C58D4[0] > 8) {
            D_006C58D4[0] = 8;
        }
        v = D_0029F280[0];
        if (v != 0) {
            v /= 2;
        }
        D_006C58B2[0] = v;
        v = D_0029F282[0];
        if (v != 0) {
            v /= 2;
        }
        D_006C58B0[0] = v;
        D_006C58D2[0] = D_0028E5EC;
        if (D_0028E5E4 != 0) {
            v = (u16)D_0028E5E4 * 100 / 2400;
        } else {
            v = 0;
        }
        v += D_0028E5B8 * 100;
        D_006C58BE[0] = v;
        if (D_0028E5F4 != 0) {
            v = (u16)D_0028E5F4 * 100 / 2400;
        } else {
            v = 0;
        }
        D_006C58CC[0] = v;
        if (D_0028E5C8 != 0) {
            D_006C58CA[0] = 1;
            D_006C58BC[0] = D_0028E5D0;
        } else {
            D_006C58CA[0] = 0;
            D_006C58CC[0] = 0;
            D_006C58BC[0] = D_0028E5C0;
        }
        D_006C58B4[0] = D_0029F284[0];
        if (D_006C58B4[0] != 0) {
            D_006C58B4[0] -= 1;
        }
        D_006C58B6[0] = D_0029F285[0];
        if ((D_0029F260[0] & 2) && !(D_0029F261[0] & 0x40) && *(u16 *)D_0029CD90 != 0) {
            D_006C58B6[0] = 7;
        }
        if (*(u8 *)D_0029F260 & 2) {
            printf(D_0028BF58);
        } else {
            printf(D_0028BF68);
        }
        if (D_0029F261[0] & 0x40) {
            printf(D_0028BF78);
        } else {
            printf(D_0028BF88);
        }
        printf(D_0028BF98, *(u16 *)D_0029CD90);
        if (D_0029CD9C[0] != 0) {
            v = (u16)D_0029CD9C[0] - 1;
        } else {
            v = 0;
        }
        D_006C58D0[0] = v;
        if (D_0028E074 != 0) {
            v = (u16)D_0028E074 / 4;
        } else {
            v = 0;
        }
        D_006C58CE[0] = v;
    } else {
        D_006C58D4[0] = D_0028E028;
        if (D_006C58D4[0] > 8) {
            D_006C58D4[0] = 8;
        }
        v = D_0029F210[0];
        if (v != 0) {
            v /= 2;
        }
        D_006C58B2[0] = v;
        v = D_0029F212[0];
        if (v != 0) {
            v /= 2;
        }
        D_006C58B0[0] = v;
        D_006C58D2[0] = D_0028E5E8;
        if (D_0028E5E0 != 0) {
            v = (u16)D_0028E5E0 * 100 / 2400;
        } else {
            v = 0;
        }
        v += D_0028E5B4 * 100;
        D_006C58BE[0] = v;
        if (D_0028E5F0 != 0) {
            v = (u16)D_0028E5F0 * 100 / 2400;
        } else {
            v = 0;
        }
        D_006C58CC[0] = v;
        if (D_0028E5C4 != 0) {
            D_006C58CA[0] = 1;
            D_006C58BC[0] = D_0028E5CC;
        } else {
            D_006C58CA[0] = 0;
            D_006C58CC[0] = 0;
            D_006C58BC[0] = D_0028E5BC;
        }
        D_006C58B4[0] = D_0029F214[0];
        if (D_006C58B4[0] != 0) {
            D_006C58B4[0] -= 1;
        }
        D_006C58B6[0] = D_0029F215[0];
        if ((D_0029F1F0[0] & 2) && !(D_0029F1F1[0] & 0x40) && *(u16 *)D_0029CD80 != 0) {
            D_006C58B6[0] = 7;
        }
        if (*(u8 *)D_0029F1F0 & 2) {
            printf(D_0028BF58);
        } else {
            printf(D_0028BF68);
        }
        if (D_0029F1F1[0] & 0x40) {
            printf(D_0028BF78);
        } else {
            printf(D_0028BF88);
        }
        printf(D_0028BF98, *(u16 *)D_0029CD80);
        if (D_0029CD8C[0] != 0) {
            v = (u16)D_0029CD8C[0] - 1;
        } else {
            v = 0;
        }
        D_006C58D0[0] = v;
        if (D_0028E070 != 0) {
            v = (u16)D_0028E070 / 4;
        } else {
            v = 0;
        }
        D_006C58CE[0] = v;
    }
}
