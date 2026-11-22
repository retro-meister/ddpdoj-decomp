#include "common.h"

extern u8 D_0026EEB0[];
extern u8 *reg_a0;
extern u8 *reg_a6;
extern void func_001DC160(void);

void func_001DC390(void) {
    u8 *object = reg_a6;
    u16 *table_entry;

    reg_a0 = D_0026EEB0;
    reg_a0 += *(u16 *)(object + 0x46);
    table_entry = (u16 *)reg_a0;
    reg_d2.h[1] = table_entry[0];
    reg_d2.h[0] = table_entry[1];
    reg_d1.h[1] = *(u16 *)(object + 0x42);
    reg_d1.h[0] = *(u16 *)(object + 0x44);
    reg_d1.w += 0xE800EC00U;
    reg_d3.h[0] = 0x18A0;
    reg_d4.h[0] = *(u16 *)(object + 0x5C);
    *(u8 *)&reg_d4 = object[0x146];
    func_001DC160();
}
