#include "common.h"

s32 cd_load_file(s32 *, s32 *);        /* extern */
s32 func_0022D2C0();                            /* extern */
extern s32 D_00271D20[];
extern s32 D_00271D40[];
extern s32 g_cd_last_read_size_as_s32;
extern s8 D_0028ECD4;
extern s32 D_0028ED00;
extern s32 D_0028ED04;
extern s32 D_0028ED0C;
extern s32 D_0028ED10;
extern s32 D_0028ED14;
extern s32 D_0028ED18;
extern s32 D_0028ED24;
extern s32 D_0028ED28;
extern s32 D_0068E580_as_s32_a[];
extern s32 D_00696D80_as_s32_a[];

void func_0022C630(void) {
    cd_load_file(D_00696D80_as_s32_a, D_00271D20);
    D_0028ED28 = g_cd_last_read_size_as_s32;
    cd_load_file(D_0068E580_as_s32_a, D_00271D40);
    D_0028ED24 = g_cd_last_read_size_as_s32;
    func_0022D2C0();
    D_0028ED0C = 0;
    D_0028ED18 = 0;
    D_0028ED14 = 0;
    D_0028ED10 = 0;
    D_0028ED04 = 0;
    D_0028ED00 = 0;
    D_0028ECD4 = 0;
}
