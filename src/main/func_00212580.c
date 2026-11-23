#include "common.h"

void func_001058E8(s32);
s32 func_0010E288(s32);
void func_00105498(void);
s32 func_0010BEC8(void *, s32, s32);
extern u8 D_0026F6C0[];
extern u8 D_0026F700[];
extern u8 D_0026F740[];

void func_00212580(s32 mode) {
    func_001058E8(0);
    func_0010E288(0);
    func_00105498();
    if (mode == 0) {
        func_0010BEC8(D_0026F6C0, 0, 0);
    } else if (mode == 1) {
        func_0010BEC8(D_0026F700, 0, 0);
    } else {
        func_0010BEC8(D_0026F740, 0, 0);
    }
}
