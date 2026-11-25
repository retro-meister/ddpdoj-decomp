/* Data of the Death Label stage 5 boss modes. */
#include "common.h"

void death_func_00223950();
void death_func_00223980();
void death_func_00223A40();
void death_func_00223A70();
void death_func_00223B50();
void death_func_00223B70();
void death_func_00223C50();
void death_func_00223C90();
void death_func_00223D00();
void death_func_00223D40();

struct D0026a420Record { void *p0[10]; u16 w1[4]; };
extern struct D0026a420Record D_0026A420;

struct D0026a420Record D_0026A420 = {
    {
        death_func_00223950,
        death_func_00223980,
        death_func_00223A40,
        death_func_00223A70,
        death_func_00223B50,
        death_func_00223B70,
        death_func_00223C50,
        death_func_00223C90,
        death_func_00223D00,
        death_func_00223D40,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};
