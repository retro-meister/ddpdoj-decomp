#include "common.h"

extern void printf(const char *);

extern const char D_00275880[];
extern const char D_002758A0[];
extern const char D_002758C0[];
extern const char D_002758E0[];
extern const char D_00275900[];
extern const char D_00275920[];
extern const char D_00275940[];
extern const char D_00275960[];
extern const char D_00275980[];
extern const char D_002759A0[];
extern const char D_002759C0[];
extern const char D_002759E0[];
extern const char D_00275A00[];
extern const char D_00275A20[];
extern const char D_00275A40[];
extern const char D_00275A60[];
extern const char D_00275A80[];
extern const char D_00275AA0[];
extern const char D_00275AC0[];
extern const char D_00275AE0[];
extern const char D_00275B00[];
extern const char D_00275B20[];
extern const char D_00275B40[];
extern const char D_00275B60[];
extern const char D_00275B80[];
extern const char D_00275BA0[];
extern const char D_00275BC0[];

extern u16 D_00247080[];
extern u16 D_002610F0[];
extern u16 D_00261630[];
extern u16 D_0028C0D0[];
extern void func_001D5780(void);
extern void func_001D58F0(void);
extern void func_001D5CA0(void);
extern void func_001D60F0(void);
extern void func_001D6160(void);
extern void func_001D6410(void);
extern void func_001D6830(void);

extern u16 D_0026345E[];
extern u16 D_00263460[];
extern u16 D_00263598[];
extern u16 D_0026359A[];
extern u16 D_002635A6[];
extern u16 D_002635A8[];
extern u16 D_002635B4[];
extern u16 D_002635B6[];
extern u16 D_002635C0_as_u16_a[];
extern u16 D_002635C2[];
extern u16 D_002635C4[];
extern u16 D_002635C6[];
extern u16 D_002635C8[];
extern u16 D_002635CA[];
extern u16 D_002635CC[];
extern u16 D_002635CE[];
extern u16 D_002635D0[];
extern u16 D_002635D2[];
extern u16 D_002635D4[];
extern u16 D_002635D6[];
extern u16 D_002635D8[];
extern u16 D_002635DA[];
extern u16 D_002635F0[];
extern u16 D_002635F2[];
extern u16 D_002635F4[];
extern u16 D_002635F6[];
extern u16 D_002635F8[];
extern u16 D_002635FA[];
extern u16 D_002635FC[];
extern u16 D_002635FE[];
extern u16 D_00263600[];
extern u16 D_00263602[];
extern u16 D_00263604[];
extern u16 D_00263606[];
extern u16 D_00263608[];
extern u16 D_0026360A[];
extern u16 D_0026360C[];
extern u16 D_0026360E[];
extern u16 D_00263610_as_u16_a[];
extern u16 D_00263612[];
extern u16 D_00263614[];
extern u16 D_00263616[];
extern u16 D_00263618[];
extern u16 D_0026361A[];
extern u16 D_0026361C[];
extern u16 D_0026361E[];
extern u16 D_00263620[];
extern u16 D_00263622[];
extern u16 D_00263624[];
extern u16 D_00263626[];
extern u16 D_00263628[];
extern u16 D_0026362A[];
extern u16 D_0026362C[];
extern u16 D_0026362E[];

void func_00186CA0(void) {
    if (D_0026345E[0] != 0x67) {
        printf(D_00275880);
    }
    reg_tmp.w = (u32)D_0028C0D0;
    D_0026345E[0] = reg_tmp.h[1];
    D_00263460[0] = reg_tmp.h[0];
    if (D_00263598[0] != 0x4) {
        printf(D_002758A0);
    }
    reg_tmp.w = (u32)D_002610F0;
    D_00263598[0] = reg_tmp.h[1];
    D_0026359A[0] = reg_tmp.h[0];
    if (D_002635A6[0] != 0xb) {
        printf(D_002758C0);
    }
    reg_tmp.w = (u32)D_00261630;
    D_002635A6[0] = reg_tmp.h[1];
    D_002635A8[0] = reg_tmp.h[0];
    if (D_002635B4[0] != 0x12) {
        printf(D_002758E0);
    }
    reg_tmp.w = (u32)D_00247080;
    D_002635B4[0] = reg_tmp.h[1];
    D_002635B6[0] = reg_tmp.h[0];
    if (D_002635C0_as_u16_a[0] != 0x0) {
        printf(D_00275900);
    }
    reg_tmp.w = (u32)func_001D5780;
    D_002635C0_as_u16_a[0] = reg_tmp.h[1];
    D_002635C2[0] = reg_tmp.h[0];
    if (D_002635C4[0] != 0x2) {
        printf(D_00275920);
    }
    reg_tmp.w = (u32)func_001D58F0;
    D_002635C4[0] = reg_tmp.h[1];
    D_002635C6[0] = reg_tmp.h[0];
    if (D_002635C8[0] != 0x4) {
        printf(D_00275940);
    }
    reg_tmp.w = (u32)func_001D5CA0;
    D_002635C8[0] = reg_tmp.h[1];
    D_002635CA[0] = reg_tmp.h[0];
    if (D_002635CC[0] != 0x6) {
        printf(D_00275960);
    }
    reg_tmp.w = (u32)func_001D58F0;
    D_002635CC[0] = reg_tmp.h[1];
    D_002635CE[0] = reg_tmp.h[0];
    if (D_002635D0[0] != 0x8) {
        printf(D_00275980);
    }
    reg_tmp.w = (u32)func_001D5CA0;
    D_002635D0[0] = reg_tmp.h[1];
    D_002635D2[0] = reg_tmp.h[0];
    if (D_002635D4[0] != 0xa) {
        printf(D_002759A0);
    }
    reg_tmp.w = (u32)func_001D6410;
    D_002635D4[0] = reg_tmp.h[1];
    D_002635D6[0] = reg_tmp.h[0];
    if (D_002635D8[0] != 0xc) {
        printf(D_002759C0);
    }
    reg_tmp.w = (u32)func_001D6830;
    D_002635D8[0] = reg_tmp.h[1];
    D_002635DA[0] = reg_tmp.h[0];
    if (D_002635F0[0] != 0x0) {
        printf(D_002759E0);
    }
    reg_tmp.w = (u32)func_001D60F0;
    D_002635F0[0] = reg_tmp.h[1];
    D_002635F2[0] = reg_tmp.h[0];
    if (D_002635F4[0] != 0x2) {
        printf(D_00275A00);
    }
    reg_tmp.w = (u32)func_001D60F0;
    D_002635F4[0] = reg_tmp.h[1];
    D_002635F6[0] = reg_tmp.h[0];
    if (D_002635F8[0] != 0x4) {
        printf(D_00275A20);
    }
    reg_tmp.w = (u32)func_001D60F0;
    D_002635F8[0] = reg_tmp.h[1];
    D_002635FA[0] = reg_tmp.h[0];
    if (D_002635FC[0] != 0x6) {
        printf(D_00275A40);
    }
    reg_tmp.w = (u32)func_001D60F0;
    D_002635FC[0] = reg_tmp.h[1];
    D_002635FE[0] = reg_tmp.h[0];
    if (D_00263600[0] != 0x8) {
        printf(D_00275A60);
    }
    reg_tmp.w = (u32)func_001D60F0;
    D_00263600[0] = reg_tmp.h[1];
    D_00263602[0] = reg_tmp.h[0];
    if (D_00263604[0] != 0xa) {
        printf(D_00275A80);
    }
    reg_tmp.w = (u32)func_001D60F0;
    D_00263604[0] = reg_tmp.h[1];
    D_00263606[0] = reg_tmp.h[0];
    if (D_00263608[0] != 0xc) {
        printf(D_00275AA0);
    }
    reg_tmp.w = (u32)func_001D60F0;
    D_00263608[0] = reg_tmp.h[1];
    D_0026360A[0] = reg_tmp.h[0];
    if (D_0026360C[0] != 0xe) {
        printf(D_00275AC0);
    }
    reg_tmp.w = (u32)func_001D60F0;
    D_0026360C[0] = reg_tmp.h[1];
    D_0026360E[0] = reg_tmp.h[0];
    if (D_00263610_as_u16_a[0] != 0x0) {
        printf(D_00275AE0);
    }
    reg_tmp.w = (u32)func_001D6160;
    D_00263610_as_u16_a[0] = reg_tmp.h[1];
    D_00263612[0] = reg_tmp.h[0];
    if (D_00263614[0] != 0x2) {
        printf(D_00275B00);
    }
    reg_tmp.w = (u32)func_001D6160;
    D_00263614[0] = reg_tmp.h[1];
    D_00263616[0] = reg_tmp.h[0];
    if (D_00263618[0] != 0x4) {
        printf(D_00275B20);
    }
    reg_tmp.w = (u32)func_001D6160;
    D_00263618[0] = reg_tmp.h[1];
    D_0026361A[0] = reg_tmp.h[0];
    if (D_0026361C[0] != 0x6) {
        printf(D_00275B40);
    }
    reg_tmp.w = (u32)func_001D6160;
    D_0026361C[0] = reg_tmp.h[1];
    D_0026361E[0] = reg_tmp.h[0];
    if (D_00263620[0] != 0x8) {
        printf(D_00275B60);
    }
    reg_tmp.w = (u32)func_001D6160;
    D_00263620[0] = reg_tmp.h[1];
    D_00263622[0] = reg_tmp.h[0];
    if (D_00263624[0] != 0xa) {
        printf(D_00275B80);
    }
    reg_tmp.w = (u32)func_001D6160;
    D_00263624[0] = reg_tmp.h[1];
    D_00263626[0] = reg_tmp.h[0];
    if (D_00263628[0] != 0xc) {
        printf(D_00275BA0);
    }
    reg_tmp.w = (u32)func_001D6160;
    D_00263628[0] = reg_tmp.h[1];
    D_0026362A[0] = reg_tmp.h[0];
    if (D_0026362C[0] != 0xe) {
        printf(D_00275BC0);
    }
    reg_tmp.w = (u32)func_001D6160;
    D_0026362C[0] = reg_tmp.h[1];
    D_0026362E[0] = reg_tmp.h[0];
}
