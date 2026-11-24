#include "common.h"

void func_0013E260(void);
void func_0013EE50(void);
void func_0013F120(void);
extern s8 D_0028E408;
extern u16 D_0028E5C0;
extern u16 D_0029CD90[];
extern u16 D_0029CD9C[];
extern u8 D_0029F260_as_u8_a[];
extern u8 D_0029F261[];
extern u8 D_0029F284[];
extern u8 D_0029F285[];

void func_0013E360(void) {
    reg_d6.b[0] = *(u8 *)(u32)D_0029F285;
    if (*(u8 *)(u32)D_0029F284 == reg_d6.b[0]) goto block_50;
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.b[0] += 1;
    *(u8 *)(u32)D_0029F285 = reg_d5.b[0];
    if (*(u8 *)(u32)D_0029F284 != reg_d5.b[0]) goto block_51;
    D_0029F261[0] &= 0xBF;
    D_0029F260_as_u8_a[0] |= 2;
    if (D_0029CD9C[0] == 0x63) goto block_end;
    D_0029CD90[0] += 0x16;
    D_0029CD9C[0] += 1;
    func_0013E260();
    func_0013F120();
    goto block_end;
block_51:
    if (D_0028E5C0 != 0) goto block_end;
    func_0013EE50();
block_end:
    D_0028E408 = 0;
    return;
block_50:
    if (D_0029CD9C[0] == 0x63) goto block_end;
    D_0029CD90[0] += 0x16;
    D_0029CD9C[0] += 1;
    reg_tmp.b[0] = *(u8 *)(u32)D_0029F261;
    *(u8 *)(u32)D_0029F261 &= 0xBF;
    if (reg_tmp.b[0] & 0x40) goto block_52;
    reg_tmp.b[0] = D_0029F260_as_u8_a[0];
    D_0029F260_as_u8_a[0] |= 2;
    if (reg_tmp.b[0] & 2) goto block_52;
    D_0029CD90[0] += 0x16;
    D_0029CD9C[0] += 1;
block_52:
    func_0013E260();
    func_0013F120();
    goto block_end;
}
