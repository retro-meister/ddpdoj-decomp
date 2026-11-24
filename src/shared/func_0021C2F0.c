#include "common.h"

extern s32 D_0028EA7C;
extern s32 D_0028EA80;

extern void func_0021A170(void);
extern void func_0021C350(s32 index);

void func_0021C2F0(void)
{
    s32 index;

    if (D_0028EA7C != 0) {
        D_0028EA80 = 0;
        for (index = 0; index < D_0028EA7C; index++) {
            func_0021C350(index);
        }
        func_0021A170();
    }
}
