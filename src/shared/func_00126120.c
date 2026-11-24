#include "common.h"

extern u8 *reg_a6;
void func_00125590(void);
void func_001257E0(void);
void func_00125930(void);
void func_00125A00(void);
void func_001260B0(void);

void func_00126120(void) {
    if ((u16)(reg_d1.h[0] &= 0x1800) != 0) {
        func_001260B0();
        return;
    }
    func_00125A00();
    func_00125930();
    if (0 <= (s64)*(s16 *)(reg_a6 + 2)) {
        func_00125590();
    } else {
        func_001257E0();
    }
}
