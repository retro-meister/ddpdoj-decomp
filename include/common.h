#ifndef DDPDOJ_COMMON_H
#define DDPDOJ_COMMON_H

#include "types.h"
#ifdef DDPDOJ_PC
#include "pc_arcade_address.h"
#endif

#define SJIS(s) s

/* Some matched callers carry unused values in C argument registers. */
#ifdef DDPDOJ_PC
#define ARCADE_REGISTER_CALL(routine, ...) routine()
#else
#define ARCADE_REGISTER_CALL(routine, ...) routine(__VA_ARGS__)
#endif

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

/* A pointer slot of a data table as the executable holds it: two words that each hold their own place in the
   table, which the start-up routines check before they put the address in. */
#define POINTER_SLOT(index) (index), (index) + 1

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

/* Full-width storage for saved address registers on the host. */
#ifdef DDPDOJ_PC
typedef uintptr_t ArcadeSavedAddress;
#else
typedef s32 ArcadeSavedAddress;
#endif

/* Convert the producers and consumers of a packed address together. */
#ifdef DDPDOJ_PC
#define ARCADE_ADDRESS_ENCODE(address) pc_arcade_address_encode((uintptr_t)(address))
#define ARCADE_ADDRESS_DECODE(type, slot) ((type)pc_arcade_address_decode((u32)(slot)))
#define ARCADE_POINTER_TABLE_AT(type, table, byte_offset) ((type)(table)[(byte_offset) / 4])
#define STORE_ARCADE_ADDRESS(words, target) STORE_LONG(words, ARCADE_ADDRESS_ENCODE(target))
#define STORE_ARCADE_ADDRESS_DIRECT(words, target) do { \
    u32 slot = ARCADE_ADDRESS_ENCODE(target); \
    (words)[0] = (u16)(slot >> 16); \
    (words)[1] = (u16)slot; \
} while (0)
#else
#define ARCADE_ADDRESS_ENCODE(address) ((u32)(address))
#define ARCADE_ADDRESS_DECODE(type, slot) ((type)(slot))
#define ARCADE_POINTER_TABLE_AT(type, table, byte_offset) (*(type *)((u8 *)(table) + (byte_offset)))
#define STORE_ARCADE_ADDRESS(words, target) STORE_POINTER(words, target)
#define STORE_ARCADE_ADDRESS_DIRECT(words, target) STORE_POINTER_DIRECT(words, target)
#endif
extern s8 cond_flag; /* result of the last routine that reports through the condition codes */
extern void (*reg_call_target)(); /* 0x28E3F4: address of the routine an indirect call goes through */
extern s8 rng_values[256];

#endif
