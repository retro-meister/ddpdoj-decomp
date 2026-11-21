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

typedef struct {
    s32 first;
    s32 second;
} GalleryEntry;

extern char D_00128D00[0x40];
extern char D_00128D40[0x40];
extern char D_00128D80[0x40];
extern char D_00128DC0[0x40];
extern char D_00128E00[0x40];
extern char D_00128E40[0x40];
extern char D_00128E80[0x40];
extern const char *D_00128E90[];
extern const char *D_00128ED0[];
extern const char *D_00128F00[];
extern char D_0012AD90[];
extern char D_0012ADA8[];
extern u16 D_0012B2D0;
extern s32 D_0012B2DC;
extern s32 D_0012B2E0;
extern s32 D_0012B2E4;
extern u8 D_0012B2E8;
extern s8 D_0012B2EC;
extern BgmFadeState D_001325D0[2];
extern s32 D_001325D4[4];
extern s32 D_001325D8[4];
extern s32 D_001325F4[4];
extern s32 D_001325F8[4];
extern s32 D_001325FC[4];
extern s32 D_00132600[4];
extern s32 D_0013261C[4];
extern GalleryEntry D_00132620[];
extern GalleryEntry D_001326C0[];
extern GalleryEntry D_00132760[];
extern s32 D_00132850[12];
extern s32 D_00132874[4];
extern s32 D_00132880[16];
extern s32 D_00132884[16];
extern s32 D_001328C0[3];
extern s32 D_001328C4[3];

extern void func_001057E8(u32 mode);
extern s32 func_00105F28(void *cd, u32 sid, u32 mode);
extern s32 func_001060F8(void *clientData, u32 rpcNumber, u32 sendMode, void *sendBuf, s32 sendSize, void *recvBuf, s32 recvSize, void *endFunc, void *endParam);
extern void func_00118268(const char *fmt, ...);
extern void func_0011B580(const char *source);

void func_0011AFD0(s32 selection);
void func_0011B1C0(void);

static inline s32 send_bgm_rpc(u32 cmd, s32 param1, s32 param2)
{
    if ((cmd & 0xFFF0) == 0x8020 || (cmd & 0xFFF0) == 0x0550 || (cmd & 0xFFF0) == 0x0560) {
        func_001060F8(D_00132850, cmd, 0, (void *)param1, 0x40, D_00132880, 0x40, 0, 0);
    } else {
        D_00132880[0] = param1;
        D_00132880[1] = param2;
        func_001060F8(D_00132850, cmd, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);
    }
    return D_00132880[0];
}

static inline void load_vag(u32 cmd, void *path)
{
    s32 p = (s32)path;
    func_001060F8(D_00132850, cmd, 0, (void *)p, 0x40, D_00132880, 0x40, 0, 0);
}

void func_0011A980(void)
{
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

void func_0011AE50(void)
{
    D_00132880[0] = 0;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0x530, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    if (D_0012B2EC != 0) {
        D_00132880[0] = 0;
        D_00132884[0] = 0;
        func_001060F8(D_00132850, 0x100, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

        if (D_00132880[0] == 0) {
            D_00132880[0] = 0;
            D_00132884[0] = 0;
            func_001060F8(D_00132850, 0x150, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);
            D_0012B2EC = 0;
            D_001325D0[0].unk00 = 0;
            D_001325D4[0] = 0;
        }
    }

    func_0011A980();
}

void func_0011AF60(void)
{
    func_0011B1C0();
}

void func_0011AF70(void)
{
    D_0012B2E0 = 0x94;
    D_0012B2DC = 6;
    func_0011AFD0(0x37);
}

void func_0011AF90(void)
{
    D_0012B2E0 = 0x80;
    D_0012B2DC = 6;
    func_0011AFD0(0x14);
}

void func_0011AFB0(void)
{
    D_0012B2E0 = 0xFF;
    D_0012B2DC = 6;
    func_0011AFD0(0x23);
}

void func_0011AFD0(s32 selection)
{
    s32 adjustedValue;
    s32 requestIndex;

    if (D_0012B2D0 == 0) {
        requestIndex = selection;
        if (selection != 0) {
            requestIndex--;
        }

        adjustedValue = D_0012B2E0;
        adjustedValue -= 30;
        if (adjustedValue < 0) {
            adjustedValue = 0;
        }

        if (selection == 2 || selection == 10 || selection == 18 ||
            selection == 45 || selection == 50 || selection == 37) {
            requestIndex |= 0x80;
        }

        D_00132880[0] = requestIndex;
        D_00132884[0] = adjustedValue;
        func_001060F8(D_00132850, 0x500, 0, D_00132880, 0x10,
                      D_00132880, 0x40, 0, 0);
        D_0012B2E4 = D_00132880[0];
    }
}

void func_0011B0B0(void)
{
    s32 index;
    const char **source;
    GalleryEntry *entry;

    index = 0;
    source = D_00128E90;
    entry = D_00132760;
    for (; index < 13; index++, source++, entry++) {
        func_0011B580(*source);
        entry->first = D_001328C4[0];
        entry->second = D_001328C0[0];
    }

    index = 0;
    source = D_00128ED0;
    entry = D_001326C0;
    for (; index < 10; index++, source++, entry++) {
        func_0011B580(*source);
        entry->first = D_001328C4[0];
        entry->second = D_001328C0[0];
    }

    index = 0;
    source = D_00128F00;
    entry = D_00132620;
    for (; index < 14; index++, source++, entry++) {
        func_0011B580(*source);
        entry->first = D_001328C4[0];
        entry->second = D_001328C0[0];
    }
}

void func_0011B1C0(void)
{
    func_001057E8(0);
    do {
        if (func_00105F28(D_00132850, 0x12345, 0) < 0) {
            while (1) {
            }
        }
    } while (D_00132874[0] == 0);

    D_001325D8[0] = 0;
    D_001325D0[0].unk00 = 1;
    D_001325F8[0] = 1;
    D_001325D4[0] = 1;
    D_001325FC[0] = 1;
    D_00132600[0] = 0;
    D_001325F4[0] = 0;
    D_0013261C[0] = 0;
    D_0012B2E4 = 0;
    D_00132880[0] = 0;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0xD0, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    D_00132880[0] = 0;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0x540, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    D_00132880[0] = 0x3FFF3FFF;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0xA0, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    D_00132880[0] = 0x3FFF3FFF;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0xA1, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    D_00132880[0] = 0x3FFF3FFF;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0x80, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    D_00132880[0] = 0x3FFF3FFF;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0x81, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    load_vag(0x550, D_00128D00);
    load_vag(0x560, D_00128D40);
    load_vag(0x560, D_00128D80);
    load_vag(0x560, D_00128DC0);
    load_vag(0x560, D_00128E00);
    load_vag(0x560, D_00128E40);
    load_vag(0x560, D_00128E80);
}
