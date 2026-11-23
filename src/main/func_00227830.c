#include "common.h"

void func_002275C0(void);
void func_002275F0(void);
void func_00227640(void);
void func_00227680(void);
void func_002276C0(void);
extern u8 D_0028EC18;

void func_00227830(void) {
    switch (D_0028EC18) {
    case 10:
        func_00227640();
        break;
    case 0:
        func_002275C0();
        break;
    case 11:
        func_00227680();
        break;
    case 1:
        func_002275F0();
        break;
    case 2:
        func_002276C0();
        break;
    case 3:
        break;
    }
}
