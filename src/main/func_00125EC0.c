#include "common.h"

extern u16 bcd_result;
void func_00125F00(void);
void func_00125EC0(void) {
    bcd_result = (u8)bcd_result;
    bcd_result <<= 2;
    func_00125F00();
}
