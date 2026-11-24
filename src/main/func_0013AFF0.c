#include "common.h"

void func_0013AF10(void);
void func_0013AF70(void);

void func_0013AFF0(void) {
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    reg_d7.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d0.h[0];
    func_0013AF10();
    reg_d2.h[0] = (s16)reg_d2.h[0] << 8;
    reg_d3.h[0] = (s16)reg_d3.h[0] << 8;
    reg_d4.h[0] = (s16)reg_d4.h[0] << 8;
    reg_d2.h[0] = (s16)reg_d2.h[0] >> 5;
    reg_d3.h[0] = (s16)reg_d3.h[0] >> 5;
    reg_d4.h[0] = (s16)reg_d4.h[0] >> 5;
    reg_d2.h[0] = (s16)reg_d2.h[0] * (s16)reg_d7.h[0];
    reg_d3.h[0] = (s16)reg_d3.h[0] * (s16)reg_d7.h[0];
    reg_d4.h[0] = (s16)reg_d4.h[0] * (s16)reg_d7.h[0];
    reg_d2.h[0] = (s16)reg_d2.h[0] >> 8;
    reg_d3.h[0] = (s16)reg_d3.h[0] >> 8;
    reg_d4.h[0] = (s16)reg_d4.h[0] >> 8;
    reg_d2.h[0] &= 0x7FFF;
    reg_d3.h[0] &= 0x7FFF;
    reg_d4.h[0] &= 0x7FFF;
    if ((s16)reg_d2.h[0] > 0x1F) {
        reg_d2.h[0] = 0x1F;
    }
    if ((s16)reg_d3.h[0] > 0x1F) {
        reg_d3.h[0] = 0x1F;
    }
    if ((s16)reg_d4.h[0] > 0x1F) {
        reg_d4.h[0] = 0x1F;
    }
    func_0013AF70();
    reg_d0.h[0] = reg_d1.h[0];
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}
