#include "common.h"

s32 func_0022C6A0();
s32 func_00235890();
extern s32 D_0028EAD4;
extern s8 D_0028EB84;
extern s32 D_0028EC6C;
extern s32 D_0028ED0C;

void func_00225A00(void) {
    switch (D_0028EC6C) {                           /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        D_0028EAD4 = 0;
        D_0028EC6C += 1;
        D_0028ED0C = 0;
        /* fallthrough */
    case 1:                                         /* switch 1 */
        switch (D_0028EAD4) {                       /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            func_0022C6A0(0);
            if (D_0028ED0C != 0) {
                func_00235890();
                D_0028EAD4 += 1;
                break;
            }
            break;
        case 1:                                     /* switch 2 */
            D_0028ED0C = 0;
            D_0028EC6C += 1;
            break;
        }
        break;
    default:                                        /* switch 1 */
        D_0028EB84 = 2;
        break;
    }
}
