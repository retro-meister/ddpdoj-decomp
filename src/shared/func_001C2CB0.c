#include "common.h"

extern void *reg_a4_as_void_p;
extern void func_001C2D10(void);

void func_001C2CB0(void)
{
    *((u8 *)reg_a4_as_void_p + 0x03) = 0;
    *(u16 *)((u8 *)reg_a4_as_void_p + 0x06) = 0x1004;
    *(u16 *)((u8 *)reg_a4_as_void_p + 0x0C) = 0xFFFF;
    *(u16 *)((u8 *)reg_a4_as_void_p + 0x0E) = 1;
    *(u16 *)((u8 *)reg_a4_as_void_p + 0x10) = 0x0606;
    *(u16 *)((u8 *)reg_a4_as_void_p + 0x12) = 0;
    *((u8 *)reg_a4_as_void_p + 0x15) = 0x0C;
    *((u8 *)reg_a4_as_void_p + 0x14) = 0x0C;
    func_001C2D10();
}
