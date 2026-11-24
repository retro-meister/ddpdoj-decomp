#include "common.h"

typedef struct {
    s16 h[33];
} Row;

extern void func_00236900(void);
extern Row D_0068DF10_as_Row_a[];
extern s16 D_006A0E50_as_s16_a_a512[][512];

s32 func_0022BC60(void) {
    s32 i;

    func_00236900();
    for (i = 0; i < 10; i++) {
        *(Row *)D_006A0E50_as_s16_a_a512[i] = D_0068DF10_as_Row_a[i];
    }
    return 1;
}
