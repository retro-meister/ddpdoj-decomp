/* Tables of the sprite lists. */
#include "common.h"

void multiply_d1_by_1();
void multiply_d1_by_10();
void multiply_d1_by_11();
void multiply_d1_by_12();
void multiply_d1_by_13();
void multiply_d1_by_14();
void multiply_d1_by_15();
void multiply_d1_by_16();
void multiply_d1_by_17();
void multiply_d1_by_18();
void multiply_d1_by_19();
void multiply_d1_by_2();
void multiply_d1_by_20();
void multiply_d1_by_21();
void multiply_d1_by_22();
void multiply_d1_by_23();
void multiply_d1_by_24();
void multiply_d1_by_25();
void multiply_d1_by_26();
void multiply_d1_by_27();
void multiply_d1_by_28();
void multiply_d1_by_29();
void multiply_d1_by_3();
void multiply_d1_by_30();
void multiply_d1_by_31();
void multiply_d1_by_4();
void multiply_d1_by_5();
void multiply_d1_by_6();
void multiply_d1_by_7();
void multiply_d1_by_8();
void multiply_d1_by_9();
void multiply_d7_by_1();
void multiply_d7_by_10();
void multiply_d7_by_11();
void multiply_d7_by_12();
void multiply_d7_by_13();
void multiply_d7_by_14();
void multiply_d7_by_15();
void multiply_d7_by_16();
void multiply_d7_by_17();
void multiply_d7_by_18();
void multiply_d7_by_19();
void multiply_d7_by_2();
void multiply_d7_by_20();
void multiply_d7_by_21();
void multiply_d7_by_22();
void multiply_d7_by_23();
void multiply_d7_by_24();
void multiply_d7_by_25();
void multiply_d7_by_26();
void multiply_d7_by_27();
void multiply_d7_by_28();
void multiply_d7_by_29();
void multiply_d7_by_3();
void multiply_d7_by_30();
void multiply_d7_by_31();
void multiply_d7_by_4();
void multiply_d7_by_5();
void multiply_d7_by_56();
void multiply_d7_by_6();
void multiply_d7_by_7();
void multiply_d7_by_8();
void multiply_d7_by_9();

extern void (*multiply_d1_routines[64])(void);
extern void (*multiply_d7_routines[64])(void);

void (*multiply_d1_routines[64])(void) = {
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_2,
    multiply_d1_by_3,
    multiply_d1_by_4,
    multiply_d1_by_5,
    multiply_d1_by_6,
    multiply_d1_by_7,
    multiply_d1_by_8,
    multiply_d1_by_9,
    multiply_d1_by_10,
    multiply_d1_by_11,
    multiply_d1_by_12,
    multiply_d1_by_13,
    multiply_d1_by_14,
    multiply_d1_by_15,
    multiply_d1_by_16,
    multiply_d1_by_17,
    multiply_d1_by_18,
    multiply_d1_by_19,
    multiply_d1_by_20,
    multiply_d1_by_21,
    multiply_d1_by_22,
    multiply_d1_by_23,
    multiply_d1_by_24,
    multiply_d1_by_25,
    multiply_d1_by_26,
    multiply_d1_by_27,
    multiply_d1_by_28,
    multiply_d1_by_29,
    multiply_d1_by_30,
    multiply_d1_by_31,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
    multiply_d1_by_1,
};

void (*multiply_d7_routines[64])(void) = {
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_2,
    multiply_d7_by_3,
    multiply_d7_by_4,
    multiply_d7_by_5,
    multiply_d7_by_6,
    multiply_d7_by_7,
    multiply_d7_by_8,
    multiply_d7_by_9,
    multiply_d7_by_10,
    multiply_d7_by_11,
    multiply_d7_by_12,
    multiply_d7_by_13,
    multiply_d7_by_14,
    multiply_d7_by_15,
    multiply_d7_by_16,
    multiply_d7_by_17,
    multiply_d7_by_18,
    multiply_d7_by_19,
    multiply_d7_by_20,
    multiply_d7_by_21,
    multiply_d7_by_22,
    multiply_d7_by_23,
    multiply_d7_by_24,
    multiply_d7_by_25,
    multiply_d7_by_26,
    multiply_d7_by_27,
    multiply_d7_by_28,
    multiply_d7_by_29,
    multiply_d7_by_30,
    multiply_d7_by_31,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_56,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
    multiply_d7_by_1,
};
