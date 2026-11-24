#include "common.h"

extern s32 glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern s32 strlen(u8 *s);
extern u8 D_0028DDA4;
extern u8 D_0028DDA6;
extern s32 g_frame_counter;
extern u8 *reg_a0;

void func_00224BA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags) {
    u8 *text;
    s32 level;
    s32 alpha;

    text = reg_a0;
    level = (g_frame_counter & 0x3F) * 2;
    if (level < 0x3F) {
        level = 0x80 - level;
    }
    alpha = (arg5 * level) >> 7;
    if (flags & 1) {
        reg_a0 = &D_0028DDA4;
        glyph_queue_add(arg0, arg1 - 8, arg2, arg3, arg4, alpha, arg6);
    }
    if (flags & 2) {
        reg_a0 = &D_0028DDA6;
        glyph_queue_add(arg0, arg1 + strlen(text) * 8, arg2, arg3, arg4, alpha, arg6);
    }
    reg_a0 = text;
}
