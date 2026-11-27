#ifndef DDPDOJ_ENDING_DATA_H
#define DDPDOJ_ENDING_DATA_H

#include "common.h"

#define ENDING_PAGE_END ((u8 *)-1)

/* The task stores its page cursor in units of four bytes, on both platforms. */
#define ENDING_POINTER_OFFSET(bytes) ((bytes) * (sizeof(void *) / 4))

#ifdef DDPDOJ_PC
static inline u32 ending_page_word(u8 **slot)
{
    return *slot == ENDING_PAGE_END ? (u32)-1 : ARCADE_ADDRESS_ENCODE(*slot);
}
#define ENDING_PAGE_WORD(slot) ending_page_word((u8 **)(slot))
#else
#define ENDING_PAGE_WORD(slot) (*(u32 *)(slot))
#endif

typedef struct {
    u16 *groups[6];
    u8 commands[88];
} EndingPictureFades;

typedef struct {
    u8 *fades[8];
    u8 text[0x270];
    u8 *doll_a_pages[8];
    u8 *doll_b_pages[8];
    u8 *doll_c_pages[6];
    u8 **dolls[6];
} EndingCommonData;

/* Each of these page lists precedes the text for the next ending. */
typedef struct {
    u8 *pages[12];
    u8 text[832];
} EndingDollBData;

typedef struct {
    u8 *pages[8];
    u8 text[592];
} EndingDollCData;

extern EndingPictureFades ending_picture_fades;
extern EndingCommonData ending_common;
extern EndingDollBData ending_doll_b;
extern EndingDollCData ending_doll_c;

#endif
