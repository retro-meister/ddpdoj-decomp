#include "common.h"

extern u16 *D_0028E468;
extern u16 D_0028E49C;
extern u16 bcd_result;

void func_00202780(void);

void func_00202760(void) {
    bcd_result = D_0028E468[1];
    D_0028E49C = D_0028E468[2];
    func_00202780();
}
