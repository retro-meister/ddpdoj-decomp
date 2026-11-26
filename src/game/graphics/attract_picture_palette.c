/* The palette of the attract demo's picture. */
#include "common.h"

u16 attract_picture_palette[16] = {
    0x00AD, 0x00F1, 0x0136, 0x013C, 0x019D, 0x09DB, 0x01DE, 0x061E,
    0x067E, 0x0EBE, 0x0EDE, 0x0B1F, 0x133F, 0x137F, 0x1FBF, 0x0000,
};

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

#ifdef DEATH_LABEL
PC_DATA_ALIAS(death_D_0026EE20, attract_picture_palette, 0x0);
#endif
#endif
