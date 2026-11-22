#include "common.h"

extern u16 D_0028E4A2;
extern u16 D_0028E4A6;
extern void *reg_a5;
extern void *reg_a6;

extern void func_00170BE0(u32, u32, u32, void *);

void func_00164C30(void)
{
    const u16 *source = (const u16 *)reg_a6;
    const u16 *object = (const u16 *)reg_a5;
    u32 sourceY;
    u32 adjustedX;
    u32 spriteAttribute;

    D_0028E4A6 = source[1];
    reg_d1.h[0] = source[2];
    sourceY = reg_d1.h[0];
    D_0028E4A6 += 0xFC00;
    adjustedX = D_0028E4A6;
    reg_d1.h[0] = sourceY + 0xFB00;
    D_0028E4A6 = adjustedX + object[0x16];
    D_0028E4A2 = object[0x10];
    spriteAttribute = object[0x11];
    reg_d2.h[0] = spriteAttribute;
    reg_d3.h[0] = 0x428;
    reg_d4.h[0] = 0xD;
    func_00170BE0(spriteAttribute, adjustedX, sourceY, (void *)object);
}
