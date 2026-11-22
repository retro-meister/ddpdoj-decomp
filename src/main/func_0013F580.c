#include "common.h"

extern u8 D_0029CE20[];
extern u8 D_0029CDA0[];
extern u8 *D_0028E468;
extern u8 *D_0028E464;

void func_0013F5C0(void);

void func_0013F580(void) {
    D_0028E468 = D_0029CE20;
    D_0028E464 = D_0029CDA0;
    func_0013F5C0();
}
