#include "common.h"

extern void func_0013BE50(void);
extern void func_0013C300(void);
extern void func_0013C350(void);
extern void func_001A42A0(void);
extern void func_00206D70(void);
extern void func_002071C0(void);
extern void func_00224A90(void);
extern s32 func_00225CD0(void);
extern void func_00237670(void);
extern void func_002377F0(void);
extern u8 D_0026B5F0[];
extern s8 D_0028E408;
extern s8 D_0028EACC;
extern u8 D_0028ED7C;
extern u32 D_0028ED84;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_00237870(void) {
    s32 step;
    s32 done;
    u8 *save_a0;
    u32 save_d0;

    save_a0 = reg_a0;
    save_d0 = reg_d0.w;
    step = *(u16 *)(reg_a5 + 6);
    done = 0;
    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_002377F0();
        return;
    }
    switch (step) {
    default:
        step++;
        break;
    case 0:
        reg_d0.w = D_0028ED84;
        func_0013C350();
        if (D_0028E408 == 0) {
            func_0013C300();
            step++;
        }
        break;
    case 1:
        switch (func_00225CD0()) {
        case 4:
            step = 200;
            break;
        case 1:
            step = 300;
            break;
        case 2:
            step = 400;
            break;
        }
        break;
    case 200:
    case 300:
    case 400:
        reg_a0 = (u8 *)D_0026B5F0;
        func_0013BE50();
        step++;
        D_0028ED84 = reg_d0.w;
        break;
    case 216:
    case 316:
    case 416:
        reg_d0.w = D_0028ED84;
        func_0013C350();
        if (D_0028E408 == 0) {
            func_0013C300();
            step++;
        }
        break;
    case 217:
    case 317:
        func_00206D70();
        func_00237670();
        if (step / 100 == 2) {
            D_0028ED7C = 2;
        } else {
            D_0028ED7C = 1;
        }
        done = 1;
        break;
    case 417:
        func_00206D70();
        func_00224A90();
        reg_d0.h[0] = 20;
        func_002071C0();
        done = 1;
        *(u8 *)(reg_a0 + 5) = 2;
        break;
    }
    func_001A42A0();
    if (done == 0) {
        *(u16 *)(reg_a5 + 6) = step;
    } else {
        D_0028EACC = 0;
    }
    reg_a0 = save_a0;
    reg_d0.w = save_d0;
}
