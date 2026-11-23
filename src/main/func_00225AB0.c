#include "common.h"

s32 func_0022C6D0();
s32 func_00234EF0();
s32 func_00235890();
extern s32 D_0028EAD0;
extern s8 D_0028EB84;
extern s32 D_0028EC68;
extern s32 D_0028ECC4;
extern s32 D_0028ED0C;

void func_00225AB0(void) {
    switch (D_0028EC68) {                           /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        D_0028EAD0 = 0;
        D_0028EC68 += 1;
        D_0028ED0C = 0;
        /* fallthrough */
    case 1:                                         /* switch 1 */
        switch (D_0028EAD0) {                       /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            func_0022C6D0(0);
            if (D_0028ED0C != 0) {
                D_0028EAD0 += 1;
                break;
            }
            break;
        case 1:                                     /* switch 2 */
            D_0028ED0C = 0;
            if (D_0028ECC4 != 0) {
                func_00234EF0(D_0028EAD0);
                func_00235890();
            }
            D_0028EC68 += 1;
            break;
        }
        break;
    default:                                        /* switch 1 */
        D_0028EB84 = 2;
        break;
    }
}
