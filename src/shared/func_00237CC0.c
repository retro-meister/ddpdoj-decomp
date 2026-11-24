#include "common.h"

s32 func_00237AC0(u8);                          /* extern */
s32 func_00237D50(u8);                          /* extern */
extern u8 D_0028E290;
extern u8 D_0028ED6C;
extern s8 D_0028ED74;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;

void func_00237CC0(void) {
    if (D_0028E290 == 2) {
        D_0028ED74 = 2;
        D_0028ED6C = 0;
        D_0028ED7C = 0;
    }
    if (D_0028ED80 != 0) {
        D_0028ED6C = 0;
        return;
    }
    if (D_0028ED6C != 0) {
        D_0028ED6C = 0;
        switch (D_0028ED7C) {                       /* irregular */
        case 1:
            func_00237AC0(D_0028ED7C);
            return;
        case 2:
            func_00237D50(D_0028ED7C);
            break;
        }
    }
}
