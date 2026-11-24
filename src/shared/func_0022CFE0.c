#include "common.h"

void func_0022D2C0(void);
void func_0022D300(void);
void func_0022D380(void);
void func_0022D550(void);
void func_0022DFF0(void);
void func_0022E180(void);
void func_0022E410(void);
void func_0022E6B0(void);
void func_0022FE40(void);
void func_00230010(void);
void func_00230230(void);
void func_00230840(void);
void func_00230CD0(void);
void func_00231520(void);
void func_00232270(void);
void func_00232430(void);
void func_00232710(void);
void func_002329F0(void);
void func_00232BE0(void);
void func_00232DE0(void);
void func_00233BE0(void);
void func_00236680(void);
extern u8 D_0028ECFC;

void func_0022CFE0(void) {
    switch (D_0028ECFC) {
    case 0x0:
        func_0022D2C0();
        D_0028ECFC = 0x32;
        break;
    case 0x1:
        break;
    case 0x2:
        func_0022D300();
        break;
    case 0xA:
        func_0022D380();
        break;
    case 0xB:
        func_0022D550();
        break;
    case 0xC:
        func_0022DFF0();
        break;
    case 0xD:
        func_0022E410();
        break;
    case 0x10:
        func_0022E6B0();
        break;
    case 0x11:
        func_0022FE40();
        break;
    case 0x12:
        func_0022E180();
        break;
    case 0x14:
        func_00230010();
        break;
    case 0x15:
        func_00230230();
        break;
    case 0x16:
        func_00230840();
        break;
    case 0x17:
        func_00230CD0();
        break;
    case 0x19:
        func_00232270();
        break;
    case 0x1B:
        func_00231520();
        break;
    case 0x1E:
        func_00232430();
        break;
    case 0x1F:
        func_00232710();
        break;
    case 0x28:
        func_002329F0();
        break;
    case 0x29:
        func_00232BE0();
        break;
    case 0x32:
        func_00232DE0();
        break;
    case 0x46:
        func_00233BE0();
        break;
    case 0x50:
        func_00236680();
        break;
    }
}
