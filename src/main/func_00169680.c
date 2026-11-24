#include "common.h"

void func_0012FAB0(void);
void func_001A2FA0(void);
void func_00206D70(void);
void func_002071C0(void);
void func_00236D50(void);
extern u8 D_00269140[];
extern u8 D_0028DE40[];
extern u8 D_0028DE44[];
extern u8 D_0028DE48[];
extern s8 D_0028E290;
extern s8 D_0028EC24;
extern u8 D_0028ED7C;
extern s16 D_0068DEC8[];
extern s16 D_0068DECA[];
extern s16 D_0068DECC[];
extern s16 D_0068DECE[];
extern s16 D_0068DED0[];
extern s16 D_0068DED2[];
extern s16 D_0068DED8[];
extern s16 D_0068DEDA[];
extern s16 D_0068DEDC[];
extern s16 D_0068DEDE[];
extern s16 D_0068DEE0[];
extern s16 D_0068DEF0[];
extern s16 D_0068DEF2[];
extern s16 D_0068DEF4[];
extern s16 D_0068DEF6[];
extern s16 D_0068DEF8[];
extern s16 D_0068DEFA[];
extern s16 D_0068DEFC[];
extern s16 D_0068DEFE[];
extern s16 D_0068DF00[];
extern s16 D_0068DF02[];
extern s16 D_0068DF04[];
extern s16 D_006E5BE2[];
extern s16 D_006E5BE4[];
extern s16 D_006E5BE6[];
extern s16 D_006E5BE8[];
extern s16 D_006E5BEA[];
extern s16 D_006E5BEC[];
extern s16 D_006E5BEE[];
extern s16 D_006E5BF0[];
extern s16 D_006E5BF2[];
extern s16 D_006E5BF4[];
extern s16 D_006E5BF6[];
extern s16 D_006E5BF8[];
extern s16 D_006E5BFA[];
extern s16 D_006E5BFC[];
extern s16 D_006E5BFE[];
extern s16 D_006E5C00[];
extern s16 D_006E5C02[];
extern s16 D_006E5C04[];
extern s16 D_006E5C06[];
extern s16 D_006E5C08[];
extern s16 D_006E5C0A[];
extern s16 D_006E5C0C[];
extern s16 D_006E5C0E[];
extern s16 D_006E5C10[];
extern s16 D_006E5C12[];
extern s16 D_006E5C14[];
extern u8 *reg_a0;

void func_00169680(void) {
    s32 a;
    s32 b;

    D_0028E290 = 0;
    func_00206D70();
    func_0012FAB0();
    reg_d0.w = 0;
    reg_a0 = (u8 *)D_00269140;
    func_001A2FA0();
    func_00236D50();
    a = D_0068DEDA[0];
    b = D_0068DEDC[0];
    if (D_0028EC24 == 0) {
        D_006E5BE2[0] = D_0028DE40[a];
        D_006E5BE4[0] = D_0028DE44[b];
    } else {
        D_006E5BE6[0] = D_0028DE40[a];
        D_006E5BE8[0] = D_0028DE44[b];
    }
    D_006E5C04[0] = 0;
    D_006E5BEA[0] = D_0068DED8[0];
    D_006E5BEC[0] = D_0068DF02[0] / 5;
    D_006E5BFE[0] = D_0068DF00[0];
    D_006E5BFC[0] = D_0068DEFE[0];
    D_006E5BF4[0] = D_0068DEF6[0];
    D_006E5BF6[0] = D_0068DEF8[0];
    D_006E5BF8[0] = D_0068DEF0[0];
    D_006E5BFA[0] = D_0068DEF2[0];
    D_006E5C00[0] = D_0068DEF4[0];
    D_006E5C02[0] = D_0068DF04[0];
    D_006E5C06[0] = D_0068DEDE[0];
    D_006E5C08[0] = D_0068DEE0[0];
    D_006E5C0A[0] = D_0068DEFA[0];
    D_006E5C0C[0] = D_0068DEFC[0];
    D_006E5C0E[0] = D_0068DEC8[0];
    D_006E5C10[0] = D_0068DECA[0];
    D_006E5C12[0] = D_0068DECC[0];
    D_006E5BEE[0] = D_0068DF02[0] % 5;
    D_006E5BF0[0] = D_0028DE48[D_0068DECE[0]];
    D_006E5BF2[0] = D_0028DE48[D_0068DED0[0]];
    D_006E5C14[0] = D_0068DED2[0];
    reg_d0.h[0] = 0x14;
    func_002071C0();
    if (D_0028ED7C == 2) {
        *(s8 *)(reg_a0 + 5) = 3;
        return;
    }
    *(s8 *)(reg_a0 + 5) = 0;
}
