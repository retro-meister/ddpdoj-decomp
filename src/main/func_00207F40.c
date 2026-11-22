#include "common.h"

s32 func_00209200();                            /* extern */
extern s32 D_00267D70[];
extern s32 D_00267D90[];
extern s32 D_00267DB0[];
extern s32 D_00267DD0[];
extern s32 D_00267DF0[];
extern s32 D_00267E10[];
extern s32 D_00267E30[];
extern s32 D_00267E50[];
extern s32 D_00267E70[];
extern s32 *reg_a0;

void func_00207F40(void) {
    reg_a0 = D_00267D70;
    reg_d0.h[0] = 0;
    func_00209200();
    reg_a0 = D_00267D90;
    func_00209200();
    reg_a0 = D_00267DB0;
    func_00209200();
    reg_a0 = D_00267DD0;
    func_00209200();
    reg_a0 = D_00267DF0;
    func_00209200();
    reg_a0 = D_00267E10;
    func_00209200();
    reg_a0 = D_00267E30;
    func_00209200();
    reg_a0 = D_00267E50;
    func_00209200();
    reg_a0 = D_00267E70;
    func_00209200();
}
