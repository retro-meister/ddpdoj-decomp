#include "common.h"

s32 func_001317E0();
s32 func_00133070();
s32 func_0013B920();
s32 func_0013C300();
s32 func_0013C350();
s32 func_00210C90();
s32 func_00210EA0();
s32 func_00211140();
s32 func_00211420();
s32 func_0022B660();
s32 func_002376F0();
s32 func_00237790();
extern u8 D_00269920[];
extern s8 D_0028E408;
extern u16 D_0028E4AA;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u8 D_0028ED7C;
extern u8 D_002BAE90[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00210D00() {
    u16 temp_a0;
    u16 temp_v1;

    reg_a6 = D_002BAE90;
    func_00211420();
    if ((*(u8 *)((u8 *)(reg_a5) + (3))) == 0) {
        func_00210C90();
        return;
    }
    temp_v1 = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    if (temp_v1 != 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) (temp_v1 - 1);
        return;
    }
    func_00210EA0();
    func_00211140();
    if ((*(u16 *)((u8 *)(reg_a6) + (0xE))) == 0) {
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
        if (temp_a0 != 0) {
            if ((temp_a0 != 1) || (func_00133070() == 0) || (func_0022B660() != 0)) {
                (*(u16 *)((u8 *)(reg_a6) + (0xC))) -= 1;
                if ((*(u16 *)((u8 *)(reg_a6) + (0xC))) == 0) {
                    reg_a0 = D_00269920;
                    func_0013B920();
                    (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) D_0028E4AA;
                    (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (u16) reg_d0.h[0];
                }
            }
        } else {
            D_0028E4AA = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
            func_0013C350();
            if (D_0028E408 == 0) {
                D_0028E4AA = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
                func_0013C300();
                if (D_0028ED7C == 2) {
                    if ((D_0028E910 == 1) && (D_0028E91C == 4)) {
                        func_002376F0();
                        return;
                    }
                    func_00237790();
                    return;
                }
                func_001317E0();
                (*(s16 *)((u8 *)(reg_a5) + (0))) = 0;
            }
        }
    }
}
