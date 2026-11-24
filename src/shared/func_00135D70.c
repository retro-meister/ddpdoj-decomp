#include "common.h"

typedef struct {
    u8 pad0[3];
    u8 unk3;
} FlagByte3;

typedef struct {
    s16 unk0;
    s16 unk2;
} HalfPair;

extern FlagByte3 *reg_a5_as_FlagByte3_p;
extern HalfPair *reg_a6_as_HalfPair_p;

void func_00135D70(void) {
    reg_a5_as_FlagByte3_p->unk3 = 2;
    reg_a6_as_HalfPair_p->unk0 = 0;
    reg_a6_as_HalfPair_p->unk2 = 0;
}
