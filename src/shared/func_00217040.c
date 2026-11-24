#include "common.h"

extern void func_0018DA30(void);
extern s16 D_0028E31C;
extern u8 D_0028E350;
extern u8 D_0028E364;
extern u8 D_0028E368;
extern u8 D_0028E36C;
extern u16 D_0028E3C0;
extern s8 D_0028EC24;
extern u8 D_0028ED58;
extern u8 D_0028ED7C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern s32 D_0057CC70[];
extern s32 D_0057CC74[];
extern s32 D_0057CC78[];

void func_00217040(void) {
    s32 state;
    s32 busy;
    s32 wait;

    state = D_0028E36C;
    if (state != 0) {
        return;
    }
    switch (D_0028E368) {
    case 0:
        goto block_rts;
    }
    busy = D_0028E350;
    if (busy != 0) {
        return;
    }
    if (D_0028E3C0 != 0) {
        return;
    }
    wait = D_0028E364;
    if (wait == 0xFF) {
        return;
    }
    if ((s8)wait > 0) {
        D_0028E364 = wait - 1;
        return;
    }
    D_0028E364 = 0;
    if (!(D_0057CC78[0] & 0x800)) {
        return;
    }
    if ((u8)busy != 0) {
        return;
    }
    if ((u8)state == 0xB) {
        return;
    }
    if (D_0028ED7C == 2) {
        if (!(D_0057CC70[D_0028EC24] & 0x800)) {
            return;
        }
        if (D_0028ED58 != 0 && D_0029F260[0] == 0 && D_0029F1F0[0] == 0) {
            return;
        }
        func_0018DA30();
        D_0028E36C = 1;
        D_0028E31C = D_0028EC24;
block_rts:
        return;
    }
    if ((D_0057CC70[0] & 0x800) && D_0029F260[0] < 0) {
        func_0018DA30();
        D_0028E31C = 0;
        D_0028E36C = 1;
        return;
    }
    if ((D_0057CC74[0] & 0x800) && D_0029F1F0[0] < 0) {
        func_0018DA30();
        D_0028E36C = 1;
        D_0028E31C = 1;
    }
}
