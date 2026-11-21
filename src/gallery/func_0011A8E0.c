#include "common.h"

extern void func_001057E8(s32);
extern void func_0010E188(s32);
extern void func_00105398(void);
extern void func_0010BDC8(const char *, s32, s32);

extern const char D_00128C40[];
extern const char D_00128C80[];
extern const char D_00128CC0[];

void func_0011A8E0(s32 destination) {
    func_001057E8(0);
    func_0010E188(0);
    func_00105398();

    if (destination == 0) {
        func_0010BDC8(D_00128C40, 0, 0);
    } else if (destination == 1) {
        func_0010BDC8(D_00128C80, 0, 0);
    } else {
        func_0010BDC8(D_00128CC0, 0, 0);
    }
}
