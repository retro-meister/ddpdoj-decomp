#include "common.h"

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 fadeMode;
    s32 curVol;
    s32 unk10;
    s32 targetVol;
    s32 curVolScaled;
    s32 stepVol;
    s32 timer;
    s32 unk24;
} BgmFadeState;

extern char D_0012AD90[];
extern char D_0012ADA8[];
extern u8 D_0012B2E8;
extern BgmFadeState D_001325D0[2];
extern s32 D_00132850[12];
extern s32 D_00132880[16];

extern s32 func_001060F8(void *clientData, u32 rpcNumber, u32 sendMode, void *sendBuf, s32 sendSize, void *recvBuf, s32 recvSize, void *endFunc, void *endParam);
extern void func_00118268(const char *fmt, ...);

static inline s32 send_bgm_rpc(u32 cmd, s32 param1, s32 param2) {
    if ((cmd & 0xFFF0) == 0x8020 || (cmd & 0xFFF0) == 0x0550 || (cmd & 0xFFF0) == 0x0560) {
        func_001060F8(D_00132850, cmd, 0, (void *)param1, 0x40, D_00132880, 0x40, 0, 0);
    } else {
        D_00132880[0] = param1;
        D_00132880[1] = param2;
        func_001060F8(D_00132850, cmd, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);
    }
    return D_00132880[0];
}

void func_0011A980(void) {
    s32 channel;
    s32 volume;

    for (channel = 0; channel < 2; channel++) {
        if (D_001325D0[channel].fadeMode == 0) {
            continue;
        }

        D_001325D0[channel].timer--;
        if (D_001325D0[channel].timer <= 0) {
            D_001325D0[channel].curVol = D_001325D0[channel].targetVol;
            func_00118268(D_0012AD90, D_001325D0[channel].curVol);

            if (D_001325D0[channel].fadeMode == 3) {
                D_0012B2E8 = 0;
            }

            if (D_001325D0[channel].fadeMode == 2) {
                if (send_bgm_rpc(channel | 0x80B0, 0, 0) & 0x1000) {
                    send_bgm_rpc(channel | 0x60, 0, 0);
                    D_001325D0[channel].unk04 = 1;
                    D_001325D0[channel].fadeMode = 0;
                }
                D_001325D0[channel].fadeMode = 0;
                func_00118268(D_0012ADA8);
                return;
            } else if (D_001325D0[channel].fadeMode == 4) {
                send_bgm_rpc(channel | 0x60, 0, 0);
                D_001325D0[channel].fadeMode = 0;
                return;
            } else {
                D_001325D0[channel].fadeMode = 0;
            }
        }

        if (D_001325D0[channel].curVol != D_001325D0[channel].targetVol) {
            if (D_001325D0[channel].curVol < D_001325D0[channel].targetVol) {
                D_001325D0[channel].curVolScaled += D_001325D0[channel].stepVol;
                D_001325D0[channel].curVol = D_001325D0[channel].curVolScaled / 100;
                if (D_001325D0[channel].curVol > D_001325D0[channel].targetVol) {
                    D_001325D0[channel].curVol = D_001325D0[channel].targetVol;
                }
            } else {
                D_001325D0[channel].curVolScaled -= D_001325D0[channel].stepVol;
                D_001325D0[channel].curVol = D_001325D0[channel].curVolScaled / 100;
                if (D_001325D0[channel].curVol < D_001325D0[channel].targetVol) {
                    D_001325D0[channel].curVol = D_001325D0[channel].targetVol;
                }
            }
        }

        volume = D_001325D0[channel].curVol;
        if (volume != 0) {
            volume = (volume * 0x7FFF) / 100;
        }
        {
            u32 cmd = channel | 0x80;
            s32 volParam = volume << 16;
            volParam |= volume;
            send_bgm_rpc(cmd, volParam, 0);
        }
    }
}
