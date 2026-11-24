#include "common.h"

typedef struct {
    s16 h[33];
} Row;

extern void func_00236900(void);
extern Row D_0068DF10[];
extern s16 D_006A0E50[][512];

s32 func_0022BC60(void) {
    s32 i;

    func_00236900();
    for (i = 0; i < 10; i++) {
        *(Row *)D_006A0E50[i] = D_0068DF10[i];
    }
    return 1;
}
