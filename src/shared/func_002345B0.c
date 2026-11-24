#include "common.h"

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
extern SaveBlock D_006C4EF0;

void func_002345B0(void) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 5; i++) {
        D_006C4EF0.a00[i] = D_002BB378[i];
        D_006C4EF0.a0A[i] = D_002BB368[i];
        D_006C4EF0.a14[i] = D_002BB398[i];
        D_006C4EF0.a1E[i] = D_002BB388[i];
        D_006C4EF0.a28[i] = D_002BB358[i];
        D_006C4EF0.a70[i] = D_002BB3F0[i];
        D_006C4EF0.a84[i] = D_002BB338[i];
        D_006C4EF0.a8E[i] = D_002BB348[i];
        D_006C4EF0.a98[i] = D_002BB2A8[i];
        D_006C4EF0.aA2[i] = D_002BB298[i];
        D_006C4EF0.aAC[i] = D_002BB2C8[i];
        D_006C4EF0.aB6[i] = D_002BB2B8[i];
        D_006C4EF0.aC0[i] = D_002BB288[i];
        D_006C4EF0.a108[i] = D_002BB320[i];
        D_006C4EF0.a11C[i] = D_002BB268[i];
        D_006C4EF0.a126[i] = D_002BB278[i];
    }
    for (i = 0; i < 15; i++) {
        D_006C4EF0.a34[i] = D_002BB3B0[i];
        D_006C4EF0.aCC[i] = D_002BB2E0[i];
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 30; j++) {
            D_006C4EF0.a130[i][j] = D_002BB100[i][j];
            D_006C4EF0.a1C6[i][j] = D_002BB060[i][j];
        }
    }
    if (D_0028E290 == 2) {
        for (i = 0; i < 5; i++) {
            D_006C4EF0.a00[i] = D_002BB1D8[i];
            D_006C4EF0.a0A[i] = D_002BB1C8[i];
            D_006C4EF0.a14[i] = D_002BB1F8[i];
            D_006C4EF0.a1E[i] = D_002BB1E8[i];
            D_006C4EF0.a28[i] = D_002BB1B8[i];
            D_006C4EF0.a70[i] = D_002BB250[i];
            D_006C4EF0.a84[i] = D_002BB198[i];
            D_006C4EF0.a8E[i] = D_002BB1A8[i];
            D_006C4EF0.a98[i] = D_002BB378[i];
            D_006C4EF0.aA2[i] = D_002BB368[i];
            D_006C4EF0.aAC[i] = D_002BB398[i];
            D_006C4EF0.aB6[i] = D_002BB388[i];
            D_006C4EF0.aC0[i] = D_002BB358[i];
            D_006C4EF0.a108[i] = D_002BB3F0[i];
            D_006C4EF0.a11C[i] = D_002BB338[i];
            D_006C4EF0.a126[i] = D_002BB348[i];
        }
        for (i = 0; i < 15; i++) {
            D_006C4EF0.a34[i] = D_002BB210[i];
            D_006C4EF0.aCC[i] = D_002BB3B0[i];
        }
    }
    D_006C4EF0.b25C = D_0028E39C;
    D_006C4EF0.b25D = D_0028E398;
    D_006C4EF0.b25E = D_0028E394;
    D_006C4EF0.b25F = D_0028E390;
    D_006C4EF0.b260 = D_0028E358;
    D_006C4EF0.b261 = D_0028E38C;
    D_006C4EF0.b262 = D_0028E388;
    D_006C4EF0.b263 = D_0028E384;
    D_006C4EF0.b264 = D_0028E380;
    D_006C4EF0.b265 = D_0028E37C;
    D_006C4EF0.b266 = D_0028E360;
    D_006C4EF0.b267 = D_0028E35C;
    D_006C4EF0.h268 = D_0028E32C;
    D_006C4EF0.b26A = D_0028E27C;
    D_006C4EF0.b26B = D_0028E278;
    D_006C4EF0.b274 = D_0028E254;
    D_006C4EF0.b275 = D_0028E250;
    D_006C4EF0.b276 = D_0028E258;
    D_006C4EF0.h278 = D_0028E300;
    D_006C4EF0.b59C = D_0028E2E0;
    D_006C4EF0.b59D = D_0028E2DC;
    D_006C4EF0.b59E = D_0028E2D8;
    D_006C4EF0.b59F = D_0028E354;
    D_006C4EF0.b5A0 = D_0028E28C;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                D_006C4EF0.a27C[i][j][k] = D_00684CF0[i][j][k];
            }
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            D_006C4EF0.a26C[i][j] = D_0028E270[i][j];
        }
    }
}
