#ifndef DDPDOJ_PS2_TEXT_H
#define DDPDOJ_PS2_TEXT_H

#include "types.h"

/* A few arcade data records contain a word pointing into the PS2 text segment. */
#ifdef DDPDOJ_PC
#define PS2_TEXT_ADDRESS(offset) (0x00100000u + (offset))
#else
extern u8 text_start[];
#define PS2_TEXT_ADDRESS(offset) ((u32)(text_start + (offset)))
#endif

#endif
