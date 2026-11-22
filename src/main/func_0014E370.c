#include "common.h"

extern u16 *D_0028E454;
extern u16 D_0028E48C;

void func_0014E380(void);

void func_0014E370(void) {
    D_0028E48C = D_0028E454[2];
    func_0014E380();
}
