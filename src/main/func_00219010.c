#include "common.h"

s32 func_00218990();
extern s32 D_0028EA78;
extern u16 D_002B2750[];
extern u8 D_0058D800[];
void func_00219010(void) {
    s32 var_v0;
    s32 var_v1;
    s16 *var_a0;
    u8 *var_a1;
    s16 *temp_a2;
    s32 var_a2;
    u8 *temp_a3;
    s16 temp_a3_3;
    s16 temp_t2;
    s32 var_t2;

    var_a0 = (s16 *)(D_002B2750);
    var_a1 = (u8 *)(D_0058D800);
    var_v0 = 0;
    do {
        var_v1 = 0;
        var_a2 = 0;
loop_2:
        temp_a3 = (u8 *)(var_a1 + var_a2);
        var_v1 += 8;
        var_a2 += 0x10;
        (*(s16 *)((u8 *)(temp_a3) + (0))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (0))) | 0x8000);
        (*(s16 *)((u8 *)(temp_a3) + (2))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (2))) | 0x8000);
        (*(s16 *)((u8 *)(temp_a3) + (4))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (4))) | 0x8000);
        (*(s16 *)((u8 *)(temp_a3) + (6))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (6))) | 0x8000);
        (*(s16 *)((u8 *)(temp_a3) + (8))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (8))) | 0x8000);
        (*(s16 *)((u8 *)(temp_a3) + (0xA))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (0xA))) | 0x8000);
        (*(s16 *)((u8 *)(temp_a3) + (0xC))) = (s16) ((*(s16 *)((u8 *)(var_a0) + (0xC))) | 0x8000);
        temp_t2 = (*(s16 *)((u8 *)(var_a0) + (0xE))) | 0x8000;
        var_a0 += 8;
        (*(s16 *)((u8 *)(temp_a3) + (0xE))) = temp_t2;
        if (var_v1 < 7) {
            goto loop_2;
        }
        var_t2 = var_v1 * 2;
        if (var_v1 < 0xF) {
            do {
                var_v1 += 1;
                *(s16 *)(var_a1 + var_t2) = *var_a0++ | 0x8000;
                var_t2 += 2;
            } while (var_v1 < 0xF);
        }
        temp_a3_3 = *var_a0;
        var_v0 += 1;
        temp_a2 = (s16 *)(var_a1 + (var_v1 * 2));
        *temp_a2 = temp_a3_3;
        var_a1 += 0x80;
        var_a0 += 1;
    } while (var_v0 < 0x10);
    D_0028EA78 = 0x37B0;
    func_00218990(D_0058D800, 0, 0x10);
}
