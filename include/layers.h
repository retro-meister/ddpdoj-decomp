#ifndef DDPDOJ_LAYERS_H
#define DDPDOJ_LAYERS_H

#include "types.h"

/*
 * The two scrolling background planes (A and B) and the text plane of the arcade hardware, as the game code
 * drives them. Index 0 of each pair is y, index 1 is x; positions are in 1/64 pixel.
 */
extern u32 g_layer_a_position[];      /* whole pixels only */
extern u16 g_layer_a_shift[];         /* what the last scroll call moved the plane by, negated */
extern u16 g_layer_a_step_fraction[];
extern u32 g_layer_a_fraction[];      /* the part of a pixel not yet moved */
extern u16 g_layer_a_type;

extern u32 g_layer_b_position[];
extern u16 g_layer_b_shift[];
extern u16 g_layer_b_step_fraction[];
extern u32 g_layer_b_fraction[];
extern u16 g_layer_b_type;

/* Text plane cells to write at the end of the frame: pairs of cell address and value, ended by -1. */
#define DEFERRED_TEXT_CELLS 0x310

extern u32 g_deferred_text[];
extern u32 g_deferred_text_next[];    /* [0]: address of the next free pair */
extern u32 g_deferred_text_row_skip;

#endif
