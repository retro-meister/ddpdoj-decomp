#include "common.h"

s32 fade_reset();                            /* extern */
s32 fade_start_in();                            /* extern */
s32 func_002184A0();                            /* extern */
extern s32 D_0028E98C;
extern s16 D_0028E990_as_s16;
extern s16 D_0028E994_as_s16;

void func_00122BE0(void) {
    D_0028E990_as_s16 = 0xF0;
    D_0028E98C = 0;
    D_0028E994_as_s16 = 0;
    func_002184A0();
    fade_reset();
    fade_start_in();
}
