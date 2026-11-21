#include "common.h"

extern s32 bcd_result;
extern void func_00125F00(void);

void func_00125EF0(void) {
    bcd_result = 0;
    func_00125F00();
}
