#include "common.h"

extern void func_0018D010(s32 code);

extern s32 D_0028DF8C;
extern s32 D_0028DF88;

void func_0018D600(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0;
    func_0018D010(0x27);
}
