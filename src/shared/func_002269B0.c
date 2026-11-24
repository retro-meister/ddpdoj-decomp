#include "common.h"

s32 func_0021D410();
s32 func_0022BE60();
s32 func_0023DBF0();
s32 memcpy();
extern s8 D_0028EB04;
extern s32 D_0028EB90;
extern s8 D_0028EC28;
extern u8 D_0028EC40;
extern u8 D_0028ED30;
extern u8 D_0028ED31;
extern u8 D_0028ED32;
extern u8 D_0028ED33;
extern u8 D_0028ED34;
extern u8 D_0028ED35;
extern u8 D_0028ED36;
extern u8 D_0028ED37;
extern u8 D_006A4800[];
extern u8 D_006C58A0[];
extern u8 D_006C58D8[];
extern u8 D_006C58D9[];
extern u8 D_006C58DA[];
extern u8 D_006C58DB[];
extern u8 D_006C58DC[];
extern u8 D_006C58DD[];
extern u8 D_006C58DE[];
extern u8 D_006C58DF[];
extern u8 D_006C5CA0[];
s32 func_002269B0(void) {
    if (func_0022BE60(D_0028EC40) != 0) {
        D_0028EC28 = *(s8 *)&D_0028EC40;
        D_0028EB04 = 1;
        D_0028EB90 = 0x40;
        memcpy(D_006C58A0, D_006A4800, 0x202E8);
        func_0021D410(D_006C5CA0);
        func_0023DBF0(D_006C58A0);
        D_0028ED30 = D_006C58D8[0];
        D_0028ED31 = D_006C58D9[0];
        D_0028ED32 = D_006C58DA[0];
        D_0028ED33 = D_006C58DB[0];
        D_0028ED34 = D_006C58DC[0];
        D_0028ED35 = D_006C58DD[0];
        D_0028ED36 = D_006C58DE[0];
        D_0028ED37 = D_006C58DF[0];
        return 3;
    }
    return 1;
}
