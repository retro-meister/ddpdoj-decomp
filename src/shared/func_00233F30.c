#include "common.h"

void overlay_queue_sjis_vertical(s64, s32);

void func_00233F30(s32 arg0, s64 arg1) {
    s64 delta = 0x1C0 - (s16)arg1;
    overlay_queue_sjis_vertical((s16)delta, arg0);
}
