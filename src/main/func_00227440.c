#include "common.h"

typedef struct {
    s8 unk0;
    s8 state;
    s16 unk2;
    s16 value;
} Fade;

void func_00227440(Fade *fade) {
    switch (fade->state) {
    case 0:
        break;
    case 1:
        fade->value += 4;
        if (fade->value >= 0x80) {
            fade->value = 0x80;
            fade->state = 0;
        }
        break;
    case 2:
        fade->value -= 4;
        if (0 >= fade->value) {
            fade->value = 0;
            fade->state = 0;
        }
        break;
    }
}
