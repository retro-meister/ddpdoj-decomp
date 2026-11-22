#include "common.h"
extern u16 *D_0028E468;
extern u8 D_0029F260[];
void func_001278D0(void);
void func_001278A0(void) {
    *(u8 **)bcd_digits = D_0029F260;
    D_0028E468[18] = ((u16 *)bcd_digits)[1];
    D_0028E468[19] = ((u16 *)bcd_digits)[0];
    func_001278D0();
}
