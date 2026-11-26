#ifndef DDPDOJ_PC_PLAYER_PALETTE_H
#define DDPDOJ_PC_PLAYER_PALETTE_H

struct PcPlayerPaletteTable {
    u16 *stage_palettes[5];
    u16 reserved[6];
    u16 ship_slots[2][4];
    void *ship_palettes[4][4];
};

extern struct PcPlayerPaletteTable stage_palettes_load_value;

#endif
