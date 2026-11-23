#include "common.h"

void func_0018D4E0(void);
void func_0018D9B0(void);
void func_0018D9F0(void);
void func_0018DA30(void);

void func_0022D240(s32 arg0) {
    if (arg0 == 2) {
        func_0018DA30();
        return;
    }
    if (arg0 == 1) {
        func_0018D9F0();
    } else if (arg0 == 10) {
        func_0018D9B0();
    } else if (arg0 == 11) {
        func_0018D4E0();
    }
}
