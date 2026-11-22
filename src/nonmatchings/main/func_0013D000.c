#include "common.h"

extern u8 *D_0028E468;
extern u16 D_0028E4A6;
extern u16 D_0029F262[];
extern u16 D_0029F264[];
extern u8 D_002BAEF0[];
void func_0013D030(u16 value);

void func_0013D000(void) {
    u16 first_value = D_0029F262[0];

    D_0028E468 = D_002BAEF0;
    D_0028E4A6 = first_value;
    *(u16 *)&work_reg_1 = D_0029F264[0];
    func_0013D030(first_value);
}
