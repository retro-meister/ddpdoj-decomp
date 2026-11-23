#include "common.h"

s32 func_0018D4B0();
s32 func_0018D4C0();
s32 func_00224A30();
s32 func_00224A90();
s32 func_00237670();
s32 func_002376F0();
extern u16 D_0028E31C;
extern s8 D_0028E36C;
extern s8 D_0028EBC0;
extern s8 D_0028EBC4;
extern s8 D_0028EBD0;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u32 D_0057CC70[];
void func_00223AA0(void) {
    u32 buttons;

    buttons = D_0057CC70[D_0028E31C];
    if (buttons & 0x20) {
        if (D_0028EBC4 == 0) {
            if (D_0028ED80 == 0 && D_0028ED7C != 2) {
                func_00224A30();
            } else {
                func_0018D4B0();
                if (D_0028EBD0 == 7) {
                    func_002376F0();
                } else {
                    func_00224A90();
                    func_00237670();
                }
            }
        } else {
            func_0018D4B0();
            D_0028E36C = 3;
        }
        return;
    }
    if (buttons & 0x40) {
        func_0018D4B0();
        D_0028E36C = 3;
        return;
    }
    if ((buttons & 0x8000) && D_0028EBC4 == 1) {
        func_0018D4C0();
        D_0028EBC0 = 0;
        D_0028EBC4 = 0;
        return;
    }
    if ((buttons & 0x2000) && D_0028EBC4 == 0) {
        func_0018D4C0();
        D_0028EBC0 = 0;
        D_0028EBC4 = 1;
    }
}
