#ifndef DDPDOJ_COMMON_H
#define DDPDOJ_COMMON_H

#include "types.h"

#define SJIS(s) s

#ifndef NULL
#define NULL 0
#endif

/* A value that differs between the main game and the Death Label executable. */
#ifdef DEATH_LABEL
#define MAIN_OR_DEATH_LABEL(main, death) (death)
#else
#define MAIN_OR_DEATH_LABEL(main, death) (main)
#endif

typedef union {
    u32 w;
    s32 sw;
    u16 h[2];
    s16 sh[2];
    u8 b[4];
    s8 sb[4];
} Reg32;

/* 0x38-byte object slot; D_00685010 is Obj38[][16] (group stride 0x380) in SLPS_252.33. */
typedef struct {
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;
    u8 pad10[0x18];
    s32 timer;
    s32 unk2C;
    s32 id;
    s32 active;
} Obj38;

/* Virtual 68000 register bank (.sbss 0x0028E450..0x0028E4A8 in SLPS_252.33):
 *   reg_d0..reg_d7 (0x28E4A8 down to 0x28E48C), reg_tmp (0x28E488): 32-bit data/scratch Reg32
 *   reg_tmp1..reg_tmp7 (0x28E484 down to 0x28E46C): scratch for d1..d7 (exchanges, 32-bit intermediates)
 *   reg_a0..reg_a6 (0x28E468 down to 0x28E450): 32-bit address registers (pointers)
 *   reg_atmp (0x28E44C), then the slots routines keep registers in across calls (reg_save_d0.. down from
 *   0x28E428, reg_save_a0.. down from 0x28E444; three more such banks follow the registers), cond_flag (0x28E408)
 */
extern u16 rng_cursor;
extern Reg32 reg_d0;
extern Reg32 reg_d1;
extern Reg32 reg_d2;
extern Reg32 reg_d3;
extern Reg32 reg_d4;
extern Reg32 reg_d5;
extern Reg32 reg_d6;
extern Reg32 reg_d7;
extern Reg32 reg_tmp;
extern Reg32 reg_tmp1;
extern Reg32 reg_tmp2;
extern Reg32 reg_tmp3;
extern Reg32 reg_tmp4;
extern Reg32 reg_tmp5;
extern Reg32 reg_tmp6;
extern Reg32 reg_tmp7;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;
extern u8 *reg_atmp; /* scratch address register (exchanges) */

/*
 * Data tables hold addresses as two 16-bit words, high word first. The tables that point at code or at other
 * tables are filled in at start-up with this.
 */
#define STORE_POINTER(words, target) \
    reg_tmp.w = (u32)(target); \
    (words)[0] = reg_tmp.h[1]; \
    (words)[1] = reg_tmp.h[0]

/* The same store written without the scratch register. */
#define STORE_POINTER_DIRECT(words, target) \
    (words)[0] = ((u32)(target)) >> 16; \
    (words)[1] = ((u32)(target)) & 0xFFFF

/* The same for any other 32-bit value kept as two words. */
#define STORE_LONG(words, value) \
    reg_tmp.w = (u32)(value); \
    (words)[0] = reg_tmp.h[1]; \
    (words)[1] = reg_tmp.h[0]
extern s8 cond_flag; /* result of the last routine that reports through the condition codes */
extern void (*reg_call_target)(); /* 0x28E3F4: address of the routine an indirect call goes through */
extern s8 rng_values[256];

#endif
