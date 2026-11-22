#include "common.h"

extern Reg32 reg_d0;
extern Reg32 reg_d1;
extern s16 reg_d2;
extern s16 reg_d3;
extern s32 reg_d4;
extern void func_0011C4A0(void);

void func_001AC950(void) {
    reg_d0.h[0] = 0xD4;
    reg_d2 = 7;
    reg_d3 = 1;
    reg_d4 = 0x0404000A;
    reg_d1.h[0] = 0;
    func_0011C4A0();
}
