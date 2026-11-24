#include "common.h"

extern void func_002185B0(void);
extern void func_0021A170(void);
extern s32 D_0028EA70;
extern s32 D_0028EA80;

typedef struct {
    s16 f00, f02, f04, f06, f08, f0A, f0C, f0E;
    s16 f10, f12, f14, f16, f18, f1A, f1C, f1E;
    s16 f20, f22;
    s32 f24, f28;
    s16 f2C, f2E, f30, f32;
} Unk592000;

extern Unk592000 D_00592000[];

void func_00219860(void) {
    func_002185B0();
    D_00592000[0].f10 = 0;
    D_00592000[0].f20 = 0xA;
    D_00592000[0].f24 = 0x2240;
    D_00592000[0].f2C = 1;
    D_00592000[0].f28 = 0x3838;
    D_00592000[0].f30 = 0x80;
    D_00592000[0].f00 = 0x180;
    D_00592000[0].f08 = -0x58;
    D_00592000[0].f02 = 0x1B0;
    D_00592000[0].f0A = 0x148;
    D_00592000[0].f12 = 0x30;
    D_00592000[0].f1A = 0x1A0;
    D_00592000[0].f18 = 0;
    D_00592000[0].f2E = D_0028EA70;
    D_0028EA80 = 1;
    func_0021A170();
}
