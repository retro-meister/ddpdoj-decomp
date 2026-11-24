#include "common.h"

extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
extern s32 D_00271DC0[];
extern s32 D_00271DE0[];
extern s32 D_0028DDB8;
extern s32 D_0028ED10;
extern s32 D_0028ED1C;

void func_00234150(s32 arg0) {
    if (D_0028ED1C == 0) {
        func_0022C5E0(200, D_00271DC0[arg0], 0, 20, 14, D_0028ED10, 100);
    } else {
        func_0022C5E0(200, D_00271DE0[arg0], 0, 20, 14, D_0028ED10, 100);
    }
    func_0022C5E0(300, D_0028DDB8, 0, 20, 14, D_0028ED10, 100);
}
