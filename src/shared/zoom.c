#include "common.h"

extern s32 g_zoom_patterns[];
extern u16 g_arcade_zoom_port;
extern s32 g_arcade_zoom_table[];

/* Loads the sprite scaling patterns into the (emulated) arcade video registers and selects no scaling. */
void zoom_init(void)
{
    s32 *destination;
    s32 *source;

    destination = g_arcade_zoom_table;
    source = g_zoom_patterns;
    reg_d0.h[0] = 0xF;
    do {
        *destination = *source;
        source++;
        destination++;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.h[0] = 0x10;
    reg_d0.h[0] |= 0x200;
    g_arcade_zoom_port = reg_d0.h[0];
}
