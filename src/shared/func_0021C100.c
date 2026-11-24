#include "common.h"

typedef struct {
    s16 x;
    s16 y;
    s16 page;
    s16 code;
    s16 z;
    s16 attr;
    s16 alpha;
    s16 pad;
} GlyphEntry;

extern u16 D_00269D60[];
extern s32 D_0028EA7C;
extern GlyphEntry D_0058E000[];
extern s8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0021C100(s32 x, s32 y, s32 z, s32 page, s32 alpha, s16 attr, s32 wide) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    s8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    s32 count;
    GlyphEntry *entry;
    u16 code;

    save_d0 = reg_d0.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_d1 = reg_d1.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_d2 = reg_d2.w;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    count = D_0028EA7C;
    while (1) {
        reg_d4.w = 0;
        reg_d4.sb[0] = *reg_a0;
        reg_a0++;
        if (reg_d4.w == 0) {
            break;
        }
        reg_d4.h[0] = reg_d4.b[0];
        if (wide) {
            reg_d4.h[0] -= 0x20;
            reg_a1 = (u8 *)D_00269D60;
            reg_d4.h[0] += reg_d4.h[0];
            reg_a1 += reg_d4.h[0];
            reg_d4.h[0] = *(u16 *)reg_a1;
        }
        entry = &D_0058E000[count];
        count++;
        entry->x = x;
        entry->y = y;
        entry->z = z;
        entry->page = page;
        entry->attr = attr;
        entry->alpha = alpha;
        code = reg_d4.h[0];
        entry->code = code;
        if (wide) {
            entry = &D_0058E000[count];
            count++;
            entry->x = x - 8;
            entry->y = y;
            entry->z = z;
            entry->page = page;
            entry->attr = attr;
            entry->alpha = alpha;
            entry->code = (s16)code + 0x10;
        }
        y += 8;
    }
    D_0028EA7C = count;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}
