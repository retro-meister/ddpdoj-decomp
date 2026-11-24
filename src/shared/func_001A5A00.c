#include "common.h"

extern u16 D_0028E648;
extern u16 D_0028E6D8;

void func_001A5A00(void) {
    if (D_0028E6D8 != 0) {
        D_0028E6D8 -= 1;
        D_0028E648 += 1;
        if (D_0028E6D8 != 0) {
            D_0028E6D8 -= 1;
            D_0028E648 += 1;
            if (D_0028E6D8 != 0) {
                D_0028E6D8 -= 1;
                D_0028E648 += 1;
                if (D_0028E6D8 != 0) {
                    D_0028E648 += 1;
                    D_0028E6D8 -= 1;
                }
            }
        }
    }
}
