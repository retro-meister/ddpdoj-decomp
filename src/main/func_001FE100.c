#include "common.h"

typedef struct FuncFe100Obj {
    u8 pad_00[0x46];
    s16 unk46;
    u8 pad_48[0x4];
    s16 unk4C;
} FuncFe100Obj;

extern FuncFe100Obj *D_0028E450;

void func_001FE100(void) {
    D_0028E450->unk46 = 1;
    D_0028E450->unk4C = 0;
}
