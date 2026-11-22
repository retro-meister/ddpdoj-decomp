#include "common.h"

extern u16 bcd_result;
extern void *D_0028E468;
extern u16 D_0028E49C;

void func_002021D0(void);

void func_002021B0(void) {
    u8 *base = (u8 *)D_0028E468;
    bcd_result = *(u16 *)(base + 0x2);
    D_0028E49C = *(u16 *)(base + 0x4);
    func_002021D0();
}
