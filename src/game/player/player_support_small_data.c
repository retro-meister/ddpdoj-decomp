/* Data of the player support unit, still to be merged into it. */
#include "common.h"

void sfx_p1_laser_a_stop();
void sfx_p1_laser_b_stop();
void sfx_p2_laser_a_stop();
void sfx_p2_laser_b_stop();

extern void *D_0028C5D8[2];
extern void *D_0028C5E0[2];
extern u16 D_0028C5E8[4];
extern u16 D_0028C5F0[4];

void *D_0028C5D8[2] = {
    sfx_p1_laser_a_stop,
    sfx_p1_laser_b_stop,
};

void *D_0028C5E0[2] = {
    sfx_p2_laser_a_stop,
    sfx_p2_laser_b_stop,
};

u16 D_0028C5E8[4] = {
    0x0000, 0x0001, 0x0007, 0x0002,
};

u16 D_0028C5F0[4] = {
    0x0000, 0x0001, 0x0008, 0x0002,
};
