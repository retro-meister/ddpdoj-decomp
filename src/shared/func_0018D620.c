#include "common.h"

extern void func_0018D010(s32 value);

extern s32 D_0028DF88;
extern s32 D_0028DF8C;

void func_0018D620(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0;
    func_0018D010(0x28);
}
