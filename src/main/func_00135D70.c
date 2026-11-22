#include "common.h"

typedef struct {
    u8 pad0[3];
    u8 unk3;
} FlagByte3;

typedef struct {
    s16 unk0;
    s16 unk2;
} HalfPair;

extern FlagByte3 *D_0028E454;
extern HalfPair *D_0028E450;

void func_00135D70(void) {
    D_0028E454->unk3 = 2;
    D_0028E450->unk0 = 0;
    D_0028E450->unk2 = 0;
}
