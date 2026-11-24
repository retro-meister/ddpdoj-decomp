#include "common.h"

extern s32 D_0028EAD8;
extern char D_00684CA0_as_char_a6_a11[6][11];
extern s32 D_00684CF0_as_s32_a_a4_a5[][4][5];

void func_0022AD20(s32 arg0, s32 arg1) {
    s32 i;
    s32 j;
    s32 v;
    s32 lead;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 11; j++) {
            D_00684CA0_as_char_a6_a11[i][j] = ' ';
        }
        D_00684CA0_as_char_a6_a11[i][10] = 0;
    }
    for (i = 0; i < 6; i++) {
        if (i == 5) {
            v = D_0028EAD8;
        } else {
            v = D_00684CF0_as_s32_a_a4_a5[arg0][arg1][i];
        }
        lead = 0;
        if (v >= 100000000) {
            D_00684CA0_as_char_a6_a11[i][0] = v / 100000000 + '0';
            v %= 100000000;
            lead = 1;
        }
        if (v >= 10000000) {
            D_00684CA0_as_char_a6_a11[i][1] = v / 10000000 + '0';
            v %= 10000000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][1] = '0';
        }
        if (v >= 1000000) {
            D_00684CA0_as_char_a6_a11[i][2] = v / 1000000 + '0';
            v %= 1000000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][2] = '0';
        }
        if (v >= 100000) {
            D_00684CA0_as_char_a6_a11[i][3] = v / 100000 + '0';
            v %= 100000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][3] = '0';
        }
        if (v >= 10000) {
            D_00684CA0_as_char_a6_a11[i][4] = v / 10000 + '0';
            v %= 10000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][4] = '0';
        }
        if (v >= 1000) {
            D_00684CA0_as_char_a6_a11[i][5] = v / 1000 + '0';
            v %= 1000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][5] = '0';
        }
        if (v >= 100) {
            D_00684CA0_as_char_a6_a11[i][6] = v / 100 + '0';
            v %= 100;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][6] = '0';
        }
        if (v >= 10) {
            D_00684CA0_as_char_a6_a11[i][7] = v / 10 + '0';
            v %= 10;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][7] = '0';
        }
        if (v > 0) {
            D_00684CA0_as_char_a6_a11[i][8] = v + '0';
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][8] = '0';
        }
        D_00684CA0_as_char_a6_a11[i][9] = '0';
    }
}
