#ifndef DDPDOJ_COMMON_H
#define DDPDOJ_COMMON_H

#include "types.h"

#define SJIS(s) s

typedef union {
    u32 w;
    s32 sw;
    u16 h[2];
    s16 sh[2];
    u8 b[4];
    s8 sb[4];
} Reg32;

/* Virtual 68000 register bank (.sbss 0x0028E450..0x0028E4A8 in SLPS_252.33):
 *   reg_d0..reg_d7 (0x28E4A8 down to 0x28E48C), reg_tmp (0x28E488): 32-bit data/scratch Reg32
 *   reg_a0..reg_a6 (0x28E468 down to 0x28E450): 32-bit address registers (pointers)
 */
extern u16 rng_cursor;
extern Reg32 reg_d0;
extern Reg32 reg_d1;
extern Reg32 reg_tmp;
extern s8 rng_values[256];

#endif
