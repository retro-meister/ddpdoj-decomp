#include "common.h"

s32 func_0022BB20(s32);                             /* extern */
s32 func_0023D6A0(s32);                         /* extern */
s32 func_0023DB80(s32);                         /* extern */
extern s32 D_0028ED3C;

void func_0023DBF0(s32 arg0) {
    D_0028ED3C = func_0022BB20(arg0 + 0x400);
    func_0023D6A0(arg0 + 0x400);
    func_0023DB80(arg0 + 0x5934);
}
