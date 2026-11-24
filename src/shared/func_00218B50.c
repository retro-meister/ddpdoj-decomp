#include "common.h"

extern s32 printf(const char *format, ...);
extern void sceCdBreak(void);
extern void func_0018DEE0(void);
extern void cd_read_async(u8 *dst, s32 a, s32 b);
extern void func_002182F0(void);
extern void func_0021C7B0(s32 size);
extern s32 func_0021C7E0(void);
extern char D_00287070[];
extern char D_00287090[];
extern u8 D_0028E350;
extern s16 D_0028E3FC;
extern u16 D_0028E91C;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern s32 D_0028EA58;
extern u8 *D_0028EA9C;
extern s32 D_0029CAB0[];
extern s32 D_0029CAB4[];
extern s32 D_0029CB50[];
extern s32 D_0029CB54[];
extern u8 D_002C4F80[];
extern u8 D_00587000[];

void func_00218B50(void) {
    u8 *buffer;

    buffer = D_0028EA9C + 0x5DC800;
    if (D_0028E91C != D_0028E3FC) {
    switch (D_0028E350) {
    case 0:
#ifdef DEATH_LABEL
        printf(D_00287070);
#else
        printf(D_00287070, D_0028E91C);
#endif
        func_0018DEE0();
        func_002182F0();
        D_0028E350++;
        break;
    case 1:
        D_0028E350++;
        if (g_cd_async_state != 0) {
            sceCdBreak();
        }
        g_cd_async_state = 0;
        g_cd_async_busy = 1;
        break;
    case 2:
        cd_read_async(D_00587000, D_0029CB50[D_0028E91C * 4], D_0029CB54[D_0028E91C * 4]);
        if (g_cd_async_busy != 0) {
            break;
        }
        g_cd_async_state = 0;
        g_cd_async_busy = 1;
        D_0028E350++;
    case 3:
        cd_read_async(D_002C4F80, D_0029CB50[(D_0028E91C * 2 + 1) * 2], D_0029CB54[(D_0028E91C * 2 + 1) * 2]);
        if (g_cd_async_busy != 0) {
            break;
        }
        g_cd_async_state = 0;
        g_cd_async_busy = 1;
        D_0028E350++;
    case 4:
        cd_read_async(buffer, D_0029CAB0[(D_0028E91C + 5) * 2], D_0029CAB4[(D_0028E91C + 5) * 2]);
        if (g_cd_async_busy != 0) {
            break;
        }
        D_0028EA58 = 0;
        g_cd_async_busy = 1;
        g_cd_async_state = 0;
        D_0028E350++;
        break;
    case 5:
        switch (D_0028EA58) {
        case 0:
            func_0021C7B0(0x14000);
            D_0028EA58++;
            break;
        }
        if (func_0021C7E0() != 0) {
            D_0028E350++;
        }
        break;
    case 6:
        printf(D_00287090);
        D_0028E350 = 0;
        D_0028E3FC = D_0028E91C;
        break;
    case 7:
        break;
    }
    } else {
        func_002182F0();
        D_0028E350 = 0;
    }
}
