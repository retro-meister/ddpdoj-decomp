#pragma opt_propagation off
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef union {
    u32 w;
    u16 h[2];
    u8 b[4];
} Reg32;

extern Reg32 reg_d0;
extern Reg32 reg_d1;
extern Reg32 reg_d2;
extern Reg32 reg_d3;
extern Reg32 reg_d4;
extern Reg32 reg_d5;
extern Reg32 reg_d6;
extern Reg32 reg_d7;

void func_00201B30(void) {
    u32 d5, d4, d3, d2, d1, d0, d7, d6;

    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    reg_d4.w = d4;
    reg_d5.w = d5;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d6.w = d6;
    reg_d7.w = d7;
}
