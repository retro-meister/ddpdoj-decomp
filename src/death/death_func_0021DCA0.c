#include "common.h"

void death_func_0021D4B0(void);
void death_func_0021D210(void);
s32 printf(const char *format, ...);
extern char death_D_0028E438[];
extern u8 death_D_006901F0[];
extern u8 *reg_a6;

void death_func_0021DCA0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021D210();
    reg_a6 = save_a6;
    printf(death_D_0028E438);
}
