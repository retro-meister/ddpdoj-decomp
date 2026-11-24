#include "common.h"

void func_00209200(void);
extern u8 D_002679E0[];
extern u8 D_002679F8[];
extern u8 D_00267A10[];
extern u8 D_00267A30[];
extern u8 D_00267A50[];
extern u8 *D_00267AA0[];
extern s8 D_0028DFA0;
extern u8 *reg_a0;

void func_00207950(void) {
    u8 **table;

    reg_a0 = (u8 *)D_002679E0;
    reg_d0.h[0] = 0;
    func_00209200();
    reg_a0 = (u8 *)D_002679F8;
    func_00209200();
    reg_a0 = (u8 *)D_00267A10;
    func_00209200();
    reg_a0 = (u8 *)D_00267A30;
    func_00209200();
    reg_a0 = (u8 *)D_00267A50;
    func_00209200();
    table = D_00267AA0;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028DFA0;
    table += reg_d0.h[0];
    reg_a0 = *table;
    reg_d0.h[0] = 2;
    func_00209200();
}
