#include "common.h"

s32 func_0022BB20();
s32 func_0023CEA0();
s32 func_0023D420();
extern s32 D_0028ED88;

void func_0023D4A0(u8 *arg0) {
    D_0028ED88 = 0;
    func_0023CEA0(arg0 + 0x400);
    func_0023D420(arg0 + 0x5934);
    (*(s32 *)((u8 *)(arg0) + (0x5CE4))) = func_0022BB20(arg0 + 0x400);
}
