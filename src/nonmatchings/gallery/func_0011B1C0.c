#include "common.h"

extern void func_001057E8(u32 mode);
extern s32 func_00105F28(void *cd, u32 sid, u32 mode);
extern s32 func_001060F8(void *cd, u32 fno, u32 mode, void *send, s32 ssize, void *recv, s32 rsize, void *end_func, void *end_param);

extern char D_00128D00[0x40];
extern char D_00128D40[0x40];
extern char D_00128D80[0x40];
extern char D_00128DC0[0x40];
extern char D_00128E00[0x40];
extern char D_00128E40[0x40];
extern char D_00128E80[0x40];
extern s32 D_0012B2E4;
extern s32 D_001325D0[4];
extern s32 D_001325D4[4];
extern s32 D_001325D8[4];
extern s32 D_001325F4[4];
extern s32 D_001325F8[4];
extern s32 D_001325FC[4];
extern s32 D_00132600[4];
extern s32 D_0013261C[4];
extern u8 D_00132850[0x24];
extern s32 D_00132874[4];
extern s32 D_00132880[16];
extern s32 D_00132884[16];

static inline void load_vag(u32 cmd, void *path) {
    func_001060F8(D_00132850, cmd, 0, path, 0x40, D_00132880, 0x40, 0, 0);
}

void func_0011B1C0(void) {
    func_001057E8(0);
    do {
        if (func_00105F28(D_00132850, 0x12345, 0) < 0) {
            while (1) {
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
            }
        }
    } while (D_00132874[0] == 0);

    D_001325D8[0] = 0;
    D_001325D0[0] = 1;
    D_001325F8[0] = 1;
    D_001325D4[0] = 1;
    D_001325FC[0] = 1;
    D_00132600[0] = 0;
    D_001325F4[0] = 0;
    D_0013261C[0] = 0;
    D_0012B2E4 = 0;
    D_00132880[0] = 0;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0xD0, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    D_00132880[0] = 0;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0x540, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    D_00132880[0] = 0x3FFF3FFF;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0xA0, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    D_00132880[0] = 0x3FFF3FFF;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0xA1, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    D_00132880[0] = 0x3FFF3FFF;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0x80, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    D_00132880[0] = 0x3FFF3FFF;
    D_00132884[0] = 0;
    func_001060F8(D_00132850, 0x81, 0, D_00132880, 0x10, D_00132880, 0x40, 0, 0);

    load_vag(0x550, D_00128D00);
    load_vag(0x560, D_00128D40);
    load_vag(0x560, D_00128D80);
    load_vag(0x560, D_00128DC0);
    load_vag(0x560, D_00128E00);
    load_vag(0x560, D_00128E40);
    load_vag(0x560, D_00128E80);
}
