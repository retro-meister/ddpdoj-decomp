#include "common.h"

s32 func_0022CF20();
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s8 D_0028ECE8_as_s8;
extern s8 D_0028ECF0_as_s8;
extern s8 D_0028ECFC_as_s8;
extern s32 D_0028ED20;
void func_0022D300(void) {
    func_0022CF20();
    D_0028ECE8_as_s8 = 0;
    D_0028EC70 = 0;
    D_0028EC74 = 0;
    D_0028ECF0_as_s8 = 0;
    if (D_0028ED20 == 0) {
        D_0028ECFC_as_s8 = 0xB;
    } else {
        if ((D_0028ED20 == 1) || (D_0028ED20 == 4) || (D_0028ED20 == 6) || (D_0028ED20 == 7)) {
            D_0028ECFC_as_s8 = 0x15;
        } else {
            D_0028ECFC_as_s8 = 0x29;
        }
    }
}
