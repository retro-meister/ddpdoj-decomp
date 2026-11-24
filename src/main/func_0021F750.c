#include "common.h"

s32 func_00212580(s32);                     /* extern */
extern s8 g_fade_state;
extern s8 D_0028EAA8;

void func_0021F750(void) {
    if (g_fade_state == 0) {
        switch (D_0028EAA8) {                       /* irregular */
        case 1:
            func_00212580(0);
            return;
        case 2:
            func_00212580(1);
            break;
        }
    }
}
