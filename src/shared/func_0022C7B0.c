#include "common.h"

s32 text_queue_clear_all();                            /* extern */
s32 func_0022C870(s32);                         /* extern */
s32 func_0022CC20(s32);                         /* extern */
s32 func_0022CC60(s32);                         /* extern */
extern s32 D_0028ED08;
extern s32 D_0028ED10;
extern s32 D_0028ED18;

void func_0022C7B0(void) {
    text_queue_clear_all();
    switch (D_0028ED18) {                           /* irregular */
    case 0:
        func_0022C870(D_0028ED18);
        break;
    case 1:
        func_0022CC60(D_0028ED18);
        break;
    case 2:
        func_0022CC20(D_0028ED18);
        break;
    }
    if (D_0028ED08 == 0) {
        if (D_0028ED10 < 0x80) {
            D_0028ED10 += 8;
            return;
        }
        D_0028ED10 = 0x80;
        return;
    }
    if (D_0028ED10 > 0) {
        D_0028ED10 -= 8;
        return;
    }
    D_0028ED10 = 0;
}
