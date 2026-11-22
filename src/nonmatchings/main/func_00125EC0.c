#include "common.h"

extern u8 bcd_result;
void func_00125F00(void);

void func_00125EC0(void) {
    u16 low_byte = bcd_result;
    *(u16 *)&bcd_result = low_byte;
    *(u16 *)&bcd_result = (u16)(*(u16 *)&bcd_result << 2);
    func_00125F00();
}
