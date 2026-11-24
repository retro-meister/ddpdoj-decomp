#include "common.h"

void func_0012F9F0(void);
void func_0013BE50(void);
void func_0013C300(void);
void func_0013C350(void);
void func_0018DD80(void);
extern u8 D_00269820[];
extern s8 D_0028E408;
extern u32 D_0028E964;
extern u16 D_0028E968;
extern u16 D_0028E96C;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0012F7D0(void) {
    u32 sd0, sd1, sd2, sd3, sd4, sd5, sd6, sd7;
    u8 *sa0, *sa1, *sa2, *sa3, *sa4, *sa5, *sa6;

    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    sd2 = reg_d2.w;
    sd3 = reg_d3.w;
    sd4 = reg_d4.w;
    sd5 = reg_d5.w;
    sd6 = reg_d6.w;
    sd7 = reg_d7.w;
    sa0 = reg_a0;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa3 = reg_a3;
    sa4 = reg_a4;
    sa5 = reg_a5;
    sa6 = reg_a6;
    if (D_0028E96C == 0) {
        reg_d0.w = D_0028E964;
        func_0013C350();
        if (D_0028E408 == 0) {
            func_0013C300();
            D_0028E96C = 1;
            func_0018DD80();
        }
    }
    if (D_0028E96C == 1) {
        D_0028E968 -= 1;
        if (D_0028E968 == 0) {
            reg_a0 = (u8 *)D_00269820;
            func_0013BE50();
            D_0028E964 = reg_d0.w;
            D_0028E96C = 2;
        }
    }
    if (D_0028E96C == 2) {
        reg_d0.w = D_0028E964;
        func_0013C350();
        if (D_0028E408 == 0) {
            func_0013C300();
            goto block_1;
        }
    }
    func_0012F9F0();
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    D_0028E408 = 1;
    return;
block_1:
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    D_0028E408 = 0;
}
