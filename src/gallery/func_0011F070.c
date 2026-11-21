#include "common.h"

extern u8 D_00129170[0x100];
extern u8 *D_0012B3D8;
extern s32 D_0012B438;
extern u8 D_001A4AE0[];
extern u8 D_001A4B40[];
extern u8 D_001A4BC0[];
extern u8 D_001A4CB0[];
extern u8 D_001A4D30[];
extern u32 D_001A5020[];
extern volatile s8 D_001A5032[];
extern volatile s8 D_001A5033[];
extern s8 D_001C0C40[0x100];

extern s32 func_00100D70(s32 mode);
extern void func_00100E08(s32 mode, s32 flags);
extern void func_00101488(void *packet, s32 x, s32 y, s16 ready);
extern void func_001016F0(void *packet, s32 x, s32 y, s16 ready);
extern void func_00101A60(void *packet, s32 frameCount);
extern void func_00103220(s32 mode);
extern void func_0011AE50(void);
extern void func_0011D880(void);
extern void func_0011E210(void);
extern void func_0011F300(void);
extern void func_0011F410(void);

void func_0011F070(void)
{
    s32 entryIndex;
    s32 ready;
    s8 entryState;

    D_0012B438 = 0;

    for (entryIndex = 0x20; entryIndex >= 0; entryIndex--) {
        D_001C0C40[entryIndex] = 2;
    }

    for (entryIndex = 0; entryIndex < 0x100; entryIndex++) {
        entryState = D_001C0C40[entryIndex];
        if (entryState != 0) {
            (D_0012B3D8 + entryIndex)[0x5055B8] = entryState;
            (D_0012B3D8 + entryIndex)[0x5056B8] = D_00129170[entryIndex];
        }
    }

    D_0012B3D8[0x5055C9] = 0;
    *(s32 *)(D_0012B3D8 + 0x505168) = 1;

    do {
        *(volatile u32 *)0x10000000 = 0;
        func_00101A60(D_001A4AE0, D_0012B438);
        func_0011F300();
        func_0011E210();

        if (D_001A5032[0] < 0) {
            D_001A5020[0] |= 0x8000;
        }
        if (D_001A5032[0] > 0) {
            D_001A5020[0] |= 0x2000;
        }
        if (D_001A5033[0] < 0) {
            D_001A5020[0] |= 0x1000;
        }
        if (D_001A5033[0] > 0) {
            D_001A5020[0] |= 0x4000;
        }

        func_0011F410();
        func_0011AE50();
        func_0011D880();

        D_0012B438++;
        ready = !func_00100D70(0);

        if (D_0012B438 & 1) {
            func_00101488(D_001A4CB0, 0x800, 0x800, (s16)ready);
            func_001016F0(D_001A4D30, 0x800, 0x800, (s16)ready);
        } else {
            func_00101488(D_001A4B40, 0x800, 0x800, (s16)ready);
            func_001016F0(D_001A4BC0, 0x800, 0x800, (s16)ready);
        }

        func_00103220(0);
        func_00100E08(0, 0);
    } while (!*(s32 *)(D_0012B3D8 + 0x505144));

    D_0012B3D8 = 0;
}
