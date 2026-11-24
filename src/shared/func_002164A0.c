#include "common.h"

s32 sceDmaGetChan();
s32 sceMcInit();
s32 func_0018C890();
s32 func_00212740();
s32 func_00216250();
s32 func_002163B0();
s32 func_002163F0();
s32 func_002171E0();
s32 func_00217930();
s32 func_00217A20();
s32 func_00218B00();
s32 func_0021A640();
s32 func_0021B680();
s32 func_0022C630();
extern s16 D_0028E3FC;
extern u8 D_0028E400;
extern u8 D_0028E9EC;
extern s32 D_0028E9F0;
extern s32 D_0028E9F4;
extern u8 *D_0028E9F8;
extern u8 D_0028EB00;
extern u8 D_00558780[];
extern u8 D_0057CB10[];
extern u8 D_00586FF0[];
void func_002164A0(void) {
    func_00216250();
    func_002163B0();
    func_002163F0();
    func_00217930();
    D_0028E9F4 = sceDmaGetChan(2);
    func_0021B680();
    func_0021A640(D_00586FF0, D_00558780, 0x12C0, 0x200, 0x100);
    func_002171E0();
    D_0028E9F8 = (u8 *)(D_0057CB10);
    *(s32 *)0x10000010 = 0x83;
    D_0028E3FC = 0xFF;
    D_0028E9F0 = 0;
    D_0028E400 = 0;
    D_0028E9EC = 0;
    D_0028EB00 = 0;
    func_00217A20();
    func_0018C890();
    func_00218B00();
    func_00212740();
    sceMcInit();
    func_0022C630();
}
