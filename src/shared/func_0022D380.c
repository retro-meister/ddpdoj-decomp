#include "common.h"

s32 func_0022CF20();                            /* extern */
s32 func_0022D240(s32);                     /* extern */
s32 func_00233F50();                            /* extern */
s32 func_00234430(s32);                         /* extern */
extern u16 D_0028EC9C;
extern s16 D_0028ECA0_as_s16;
extern u16 D_0028ECA4;
extern s8 D_0028ECBC;
extern s8 D_0028ECDC_as_s8;
extern u8 D_0028ECEC;
extern u8 D_0028ECF0;
extern s8 D_0028ECFC_as_s8;
extern s32 D_0028ED08;
extern s32 D_0028ED10;
extern s32 D_0028ED18;
extern s32 D_0028ED1C;
extern s32 D_0057CC78[];
void func_0022D380(void) {
    s32 temp_v0;
    s32 var_v1;

    if (D_0028ECBC != 0) {
        D_0028ECF0 = 0;
        D_0028ECFC_as_s8 = 2;
        return;
    }
    func_0022CF20();
    func_00234430(D_0028ED1C);
    switch (D_0028ECF0) {                           /* irregular */
    case 0:
        D_0028ECEC = 1;
        D_0028ECF0 += 1;
        D_0028ECA0_as_s16 = 0xCE;
        D_0028ECA4 = 0x144;
        /* fallthrough */
    case 1:
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            D_0028ECF0 = 3;
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 0xEA;
                D_0028ECDC_as_s8 = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC_as_s8 = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 0x144;
            }
        }
        break;
    case 2:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 1;
        } else {
            temp_v0 = D_0028EC9C - D_0028ECA4;
            var_v1 = temp_v0 >> 1;
            if (temp_v0 < 0) {
                var_v1 = (s32) (temp_v0 + 1) >> 1;
            }
            if (var_v1 == 0) {
                var_v1 = 1;
                if (D_0028ECEC == 0) {
                    var_v1 = -1;
                }
            }
            D_0028ECA4 += var_v1 & 0xFFFF;
        }
        break;
    case 3:
        D_0028ECF0 = 0;
        if (D_0028ECEC == 1) {
            D_0028ECF0 = 4;
        } else {
            D_0028ECFC_as_s8 = 2;
        }
        break;
    case 4:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    }
    func_00233F50();
}
