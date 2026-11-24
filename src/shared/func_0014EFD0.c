#include "common.h"

extern u8 enemy_move_end_requested_as_u8;

void func_0014E290(void);

void func_0014EFD0(void) {
    enemy_move_end_requested_as_u8 = 1;
    func_0014E290();
}
