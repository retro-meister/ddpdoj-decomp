#include "common.h"

extern s16 *work_reg_a4;
extern void func_001F30F0(void);

void func_001F30E0(void) {
    work_reg_a4[1] = 0x60;
    func_001F30F0();
}
