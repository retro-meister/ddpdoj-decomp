#include "common.h"

void func_0022C730(void);
void func_0022CDB0(s32 arg0);
void func_00236900(void);
extern s32 D_0028ECC8;
extern s32 D_0028ECD0;
extern u8 D_0028ECE0;
extern s32 D_0028ED04;
extern s32 D_0028ED0C;

s32 func_00233DA0(void) {
    switch (D_0028ED04) {
    case 0:
        D_0028ED0C = 0;
        D_0028ED04 += 1;
        break;
    case 1:
        func_0022C730();
        if (D_0028ED0C != 0) {
            D_0028ED0C = 0;
            D_0028ECE0 = 30;
            D_0028ED04 += 1;
        }
        break;
    case 2:
        D_0028ECE0 -= 1;
        if ((s32)D_0028ECE0 <= 0) {
            D_0028ED04 += 1;
        }
        break;
    case 3:
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 4:
                D_0028ED04 = 0;
                break;
            case 1:
            case 2:
            case 3:
                func_00236900();
            default:
                D_0028ECE0 = 30;
                D_0028ED04 = 2;
                break;
            }
        }
        break;
    }
    return D_0028ED04 >= 2;
}
