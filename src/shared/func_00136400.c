#include "common.h"

s32 func_00135010();                            /* extern */
s32 func_00135420();                            /* extern */
s32 func_001362F0();                            /* extern */
s32 func_00136330();                            /* extern */
extern s16 D_0028DFC4_as_s16;
extern u16 D_0028E940;
extern u16 D_0028E944;

void func_00136400(void) {
    D_0028DFC4_as_s16 = 0;
    D_0028E944 = reg_d7.h[0];
    D_0028E940 = reg_d6.h[0];
    func_001362F0();
    func_00135010();
    func_00136330();
    func_00135420();
}
