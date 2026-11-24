#include "common.h"

extern void func_0018C990(void);
extern void vibration_stop_all(void);
extern void vibration_suspend(void);
extern u16 D_0028E324;
extern u16 D_0028E328;
extern u8 D_0028E36C;
extern u16 D_0028E910;
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
#endif
extern u16 D_0028E91C;
extern s8 D_0028EB04;
extern s32 D_0028EB8C;
extern s32 D_0028EB90;
extern u8 D_0028EBBC;
extern s16 D_0028EBC8;
extern u8 D_0028EBCC;
extern u8 D_0028EBD0_as_u8;
extern u8 D_0028ED74;

void func_002234C0(void) {
    D_0028E36C++;
    D_0028EBC8 = 0;
    D_0028EB90 = 0;
    D_0028EBD0_as_u8 = 1;
    D_0028EBCC = 1;
    D_0028EB04 = 1;
    D_0028EB8C = 0;
    D_0028E324 = MAIN_OR_DEATH_LABEL(D_0028E910, death_D_00290DC0);
    D_0028E328 = D_0028E91C;
    if (D_0028E328 == 0) {
        D_0028E328 = 1;
    }
    D_0028EBBC = 0x28;
    vibration_suspend();
    vibration_stop_all();
    func_0018C990();
    if (D_0028ED74 == 1) {
        D_0028ED74 = 3;
    }
}
