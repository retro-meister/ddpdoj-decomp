#include "common.h"

typedef struct {
    u32 archivePosition;
    u32 entryLocation;
} GalleryArchiveEntry;

extern const char *D_0012B200[1];
extern s32 D_0012B318;
extern void *D_0012B31C;
extern void *D_0012B3D8;
extern GalleryArchiveEntry D_0012B440[1];
extern u32 D_001328C0[];
extern u32 D_001328C4[];
extern u8 D_001A4AE0[0x330];
extern u8 D_001A4B30[0x170];
extern u8 D_001A4CA0[0x170];
extern u8 D_001A4E10[];
extern u8 D_001C0340[1][0x800];

extern void func_001001E0(s32, s32, s32, s32);
extern void func_00100C88(void *);
extern void func_00100D70(s32);
extern void func_00100E08(s32, s32);
extern void func_00101778(void *, s32, s32, s32, s32, s32, s32);
extern s32 func_00101C18(s32);
extern void func_00103220(s32);
extern void func_0010EA50(void);
extern void *func_001160A8(u32, u32);
extern void func_00116330(void *);
extern void *func_00117060(void *, s32, u32);
extern void func_0011A8E0(s32);
extern void func_0011AF60(void);
extern void func_0011B0B0(void);
extern void func_0011B580(const char *);
extern void func_0011B5D0(void *, s32, u32);
extern void func_0011CF30(void);
extern void func_0011D020(void);
extern void func_0011D170(void);
extern void func_0011D360(void);
extern void func_0011D9D0(void);
extern void func_0011E120(void);
extern void func_0011E830(void);
extern void func_0011E870(void);
extern void func_0011EDF0(void);
extern void func_0011F070(void);

void func_0011EE90(void)
{
    u32 archiveIndex;

    func_0011D9D0();
    func_0011D170();
    func_0011CF30();
    func_001001E0(0, 1, 2, 1);
    func_00117060(D_001A4AE0, 0, 0x330);
    func_00101778(D_001A4AE0, 0, 640, 224, 1, 0x31, 0);
    func_00103220(0);
    func_00100D70(0);
    func_00100C88(D_001A4B30);
    func_00100E08(0, 0);
    func_00100C88(D_001A4CA0);
    func_00100E08(0, 0);
    func_0011E870();
    func_0011E830();
    D_0012B318 = func_00101C18(2);
    func_0011E120();
    D_0012B31C = D_001A4E10;
    *(volatile u32 *)0x10000010 = 0x83;
    func_0011B0B0();

    archiveIndex = 0;
    do {
        func_0011B580(D_0012B200[archiveIndex]);
        D_0012B440[archiveIndex].archivePosition = D_001328C4[0];
        D_0012B440[archiveIndex].entryLocation = D_001328C0[0];
    } while (++archiveIndex == 0);

    archiveIndex = 0;
    do {
        func_0011B5D0(D_001C0340[archiveIndex], 0x9C,
                      D_0012B440[archiveIndex].entryLocation);
    } while (++archiveIndex == 0);

    func_0011D360();
    func_0011D020();
    func_0010EA50();
    func_0011EDF0();
    func_0011AF60();
    D_0012B3D8 = func_001160A8(0x40, 0x885800);
    func_00117060(D_0012B3D8, 0, 0x5057C0);
    func_0011F070();
    func_00116330(D_0012B3D8);
    func_0011A8E0(0);
}
