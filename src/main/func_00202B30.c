#include "common.h"

extern u16 *D_0028E468;
extern u16 D_0028E49C;
extern u16 bcd_result;
extern void func_00202B50(void);

void func_00202B30(void) {
    bcd_result = D_0028E468[1];
    D_0028E49C = D_0028E468[2];
    func_00202B50();
}
