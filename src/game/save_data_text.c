/* Text of the save data unit. */
#include "common.h"

#ifdef DEATH_LABEL
const s32 D_00289D70[2] = {
    17, 12,
};

const u16 D_00284BE8[4] = {
    0x0011, 0x0000, 0x003A, 0x0000,
};

const u16 D_00284BF0[4] = {
    0x0009, 0x0000, 0x003A, 0x0000,
};

const u16 D_00284BF8[4] = {
    0x0011, 0x0000, 0x0078, 0x0000,
};

const u16 D_00284C00[4] = {
    0x0011, 0x0000, 0x00A8, 0x0000,
};

const u16 D_00284C08[4] = {
    0x0009, 0x0000, 0x0078, 0x0000,
};

const u16 D_00284C10[4] = {
    0x0009, 0x0000, 0x00A8, 0x0000,
};

const char D_00289DA8[8] = "ATYPE";

const char D_00289DB0[8] = "BTYPE";

const char death_D_00284C28[8] = "SHOT";

const char death_D_00284C30[8] = "LASER";

const char death_D_00284C38[8] = "EXPERT";

const char death_D_00284C40[8] = "V-HARD";

const char D_00289DD8[8] = "NO.%02d";

const char D_00289DE0[8] = "NO DATA";

const char D_00289DE8[14] = "BROKEN DATA";

const char D_00289DF8[14] = "VERSION ERR";

const char D_00289E08[14] = "STG %d-%d";

const char D_00289E18[8] = "%s";

const char D_00289E20[8] = "%2d/%d";

const char D_00289E28[14] = "%2d:%02d";

const char D_00289E50[32] = "sco1up  [%x] -> [%x]\n";

const char D_00289E70[32] = "sco1cnt [%x] -> [%x]\n";

const char D_00289E90[32] = "sco1oku [%x] -> [%x]\n";

const char D_00289EB0[32] = "sco2up  [%x] -> [%x]\n";

const char D_00289ED0[32] = "sco2cnt [%x] -> [%x]\n";

const char D_00289EF0[32] = "sco2oku [%x] -> [%x]\n";

const char D_00289F10[32] = "repdat load start\n";

const char D_00289F30[32] = "repdat load end\n";
#else
const s32 D_00289D70[2] = {
    17, 12,
};

const u16 D_00289D78[4] = {
    0x0011, 0x0000, 0x003A, 0x0000,
};

const u16 D_00289D80[4] = {
    0x0009, 0x0000, 0x003A, 0x0000,
};

const u16 D_00289D88[4] = {
    0x0011, 0x0000, 0x0078, 0x0000,
};

const u16 D_00289D90[4] = {
    0x0011, 0x0000, 0x00A8, 0x0000,
};

const u16 D_00289D98[4] = {
    0x0009, 0x0000, 0x0078, 0x0000,
};

const u16 D_00289DA0[4] = {
    0x0009, 0x0000, 0x00A8, 0x0000,
};

const char D_00289DA8[8] = "ATYPE";

const char D_00289DB0[8] = "BTYPE";

const char D_00289DB8[8] = "SHOT";

const char D_00289DC0[8] = "LASER";

const char D_00289DC8[8] = "EXPERT";

const char D_00289DD0[8] = "V-HARD";

const char D_00289DD8[8] = "NO.%02d";

const char D_00289DE0[8] = "NO DATA";

const char D_00289DE8[14] = "BROKEN DATA";

const char D_00289DF8[14] = "VERSION ERR";

const char D_00289E08[14] = "STG %d-%d";

const char D_00289E18[8] = "%s";

const char D_00289E20[8] = "%2d/%d";

const char D_00289E28[14] = "%2d:%02d";

const char D_00289E38[14] = "----stage[%d]\n";

const char D_00289E50[32] = "sco1up  [%x] -> [%x]\n";

const char D_00289E70[32] = "sco1cnt [%x] -> [%x]\n";

const char D_00289E90[32] = "sco1oku [%x] -> [%x]\n";

const char D_00289EB0[32] = "sco2up  [%x] -> [%x]\n";

const char D_00289ED0[32] = "sco2cnt [%x] -> [%x]\n";

const char D_00289EF0[32] = "sco2oku [%x] -> [%x]\n";

const char D_00289F10[32] = "repdat load start\n";

const char D_00289F30[32] = "repdat load end\n";
#endif
