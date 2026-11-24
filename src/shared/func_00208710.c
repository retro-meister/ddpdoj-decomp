#include "common.h"

void func_00209200(void);
extern u8 D_00267F28[];
extern u8 D_00267F38[];
extern u8 D_00267F50[];
extern u8 D_00267F60[];
extern u8 D_00267F70[];
extern u8 D_00267F88[];
extern u8 D_00267F98[];
extern u8 D_00267FB0[];
extern u8 D_00267FC8[];
extern u8 D_00267FD8[];
extern u8 *D_00268050[];
extern s8 D_0028DFA0;
extern u8 *reg_a0;

void func_00208710(void) {
    u8 **table;

    reg_a0 = (u8 *)D_00267F28;
    reg_d0.h[0] = 0;
    func_00209200();
    reg_a0 = (u8 *)D_00267F38;
    func_00209200();
    reg_a0 = (u8 *)D_00267F50;
    func_00209200();
    reg_a0 = (u8 *)D_00267F60;
    func_00209200();
    reg_a0 = (u8 *)D_00267F70;
    func_00209200();
    reg_a0 = (u8 *)D_00267F88;
    func_00209200();
    reg_a0 = (u8 *)D_00267F98;
    func_00209200();
    reg_a0 = (u8 *)D_00267FB0;
    func_00209200();
    reg_a0 = (u8 *)D_00267FC8;
    func_00209200();
    reg_a0 = (u8 *)D_00267FD8;
    func_00209200();
    table = D_00268050;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028DFA0;
    table += reg_d0.h[0];
    reg_a0 = *table;
    reg_d0.h[0] = 2;
    func_00209200();
}
