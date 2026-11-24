#include "common.h"

s32 func_001AF010();
extern u16 D_0028E92C;
extern u16 D_0028E930;
extern u16 D_0028E934;
extern u16 D_0028E938;
extern u8 *reg_a5;

void func_001AF1A0() {
    reg_d6.h[0] = D_0028E938;
    reg_d7.h[0] = D_0028E930;
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
        reg_d6.h[0] = D_0028E934;
        reg_d7.h[0] = D_0028E92C;
    }
    reg_d5.w = 0;
    reg_d5.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
    func_001AF010();
    (*(u8 *)((u8 *)(reg_a5) + (0xF))) = (u8) reg_d6.b[0];
    (*(u8 *)((u8 *)(reg_a5) + (0xE))) = (u8) reg_d7.b[0];
}
