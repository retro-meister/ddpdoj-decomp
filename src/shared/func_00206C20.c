#include "common.h"

s32 func_00206910();                            /* extern */
s32 func_00206920();                            /* extern */
s32 func_00206960();                            /* extern */
s32 func_002069A0();                            /* extern */
s32 func_002069E0();                            /* extern */
s32 func_00206A20();                            /* extern */
s32 func_00206A60();                            /* extern */
s32 func_00206AA0();                            /* extern */
s32 func_00206AE0();                            /* extern */
s32 func_00206B20();                            /* extern */
s32 func_00206B60();                            /* extern */
s32 func_00206BA0();                            /* extern */
s32 func_00206BE0();                            /* extern */
extern s16 D_0028E220;

void func_00206C20(void) {
    D_0028E220 = 0;
    reg_d0.w = 0;
    func_00206920();
    reg_d0.w = 1;
    func_00206960();
    reg_d0.w = 1;
    func_002069A0();
    reg_d0.w = 1;
    func_002069E0();
    reg_d0.w = 1;
    func_00206A20();
    reg_d0.w = 0;
    func_00206A60();
    reg_d0.w = 0;
    func_00206AA0();
    reg_d0.w = 0;
    func_00206AE0();
    reg_d0.w = 0;
    func_00206B20();
    reg_d0.w = 0;
    func_00206B60();
    reg_d0.w = 0;
    func_00206BA0();
    reg_d0.w = 0;
    func_00206BE0();
    func_00206910();
}
