#include "common.h"

void func_0021C100(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
s32 func_00227440();
extern u8 D_00270890[];
extern s8 D_002714F8[];
extern u8 D_0028EC10;
extern s16 D_0028EC14;
extern u8 D_00685010[];
extern u8 *reg_a0;

void func_002287E0(void) {
    s32 count;
    s32 i;
    s32 offset;
    s32 tableOffset;
    u8 *entry;

    count = D_002714F8[0];
    func_00227440(&D_0028EC10);
    if (D_0028EC14 == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        tableOffset = 0;
        do {
            entry = D_00685010 + offset;
            if (*(s32 *)(entry + 0x1C34) != 0) {
                s32 value = D_0028EC14;

                *(s32 *)(entry + 0x1C2C) = value;
                reg_a0 = *(u8 **)(D_00270890 + tableOffset);
                func_0021C100(*(s32 *)(entry + 0x1C00), *(s32 *)(entry + 0x1C04), *(s32 *)(entry + 0x1C30), 0, 0x80, value, 1);
            }
            i++;
            offset += 0x38;
            tableOffset += 4;
        } while (i < count);
    }
}
