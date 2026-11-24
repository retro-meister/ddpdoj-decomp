#include "common.h"

s32 func_0013EA00();
s32 func_001A7E90();
s32 func_001AA8F0();
s32 func_001AB920();
s32 func_001AB940();
s32 func_001AB9D0();
extern u8 D_0028E288;
extern u8 D_0028E370;
extern u16 D_0028E3B4;
extern u16 D_0028E5C0;
extern u16 D_0028E5C8;
extern u16 D_0028E5D0;
extern s8 D_0028E5DC_as_s8;
extern s8 D_0028E5DD_as_s8;
extern u16 D_0028E5EC;
extern u16 D_0028E5F4;
extern u16 D_0028E5FC;
extern u16 D_0028E6A0;
extern u16 D_0028E6B4;
extern s16 D_0028E6B8;
extern s16 D_0028E6C4;
extern u16 D_0028E6C8;
extern u16 D_0028E6DC;
extern u8 D_0028E855;
extern u8 D_0028EC4C;
extern u8 D_0029F261[];
void func_001A7D00(void) {
    u32 temp_a0;
    u32 temp_v1;

    if (D_0028E5FC == 0) {
        if (D_0028E5C8 == 0) {
            func_001AB9D0();
            return;
        }
        reg_d0.w = 0x11;
        temp_a0 = reg_d0.b[0];
        temp_v1 = temp_a0 & D_0029F261[0];
        reg_d0.b[0] = temp_v1;
        if (!(temp_v1 & 0xFF)) {
            D_0028E5FC = 1;
            func_001AB920();
            func_001AA8F0();
            if (D_0028E6C8 != 0) {
                D_0028E6C8 = D_0028E6DC;
            }
            reg_d0.h[0] = D_0028E5C0;
            D_0028E5EC += reg_d0.h[0];
            D_0028E5D0 = reg_d0.h[0];
            if (D_0028E5EC > 0xF) {
                D_0028E5EC = 0xF;
            }
            D_0028E5DD_as_s8 = 0;
            D_0028E5DC_as_s8 = 0;
            D_0028E5C0 = 0;
            func_0013EA00();
            goto block_9;
        }
    } else {
block_9:
        func_001AB940();
        if (D_0029F261[0] & 1) {
            func_001A7E90();
            return;
        }
        if (((s32) D_0028E6A0 >= 0x10) && (D_0028E6C8 != 0)) {
            D_0028E6B4 = D_0028E6C8;
            D_0028E6B8 = 0x78;
            D_0028E6C4 = 0x78;
        }
        if (!(D_0028E855 & 0x40) && (D_0028E3B4 == 0) && (D_0028EC4C == 0) && (D_0028E370 != 0)) {
            D_0028E5F4 -= 2;
            if ((s16) D_0028E5F4 < 0) {
                func_001A7E90();
                if (D_0028E288 == 0x78) {
                    D_0028E288 = 0xA;
                }
            }
        }
    }
}
