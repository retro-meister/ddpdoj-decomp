#ifndef DDPDOJ_PC_FRAME_REGIONS_H
#define DDPDOJ_PC_FRAME_REGIONS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    void *data;
    size_t size;
    bool image_pointer;
} PcFrameRegion;

#define PC_FRAME_REGION(object) { &(object), sizeof(object), false }
#define PC_FRAME_POINTER(object) { &(object), sizeof(uint32_t), true }
extern const PcFrameRegion pc_system_regions[], pc_game_flow_regions[];
extern const PcFrameRegion pc_layer_regions[], pc_screen_regions[];

extern const PcFrameRegion pc_stage_sprites_regions[], pc_graphics_regions[], pc_stage_maps_regions[];

extern const PcFrameRegion pc_attract_regions[], pc_ship_select_regions[], pc_menu_regions[];

extern const PcFrameRegion pc_boss_regions[];
extern const PcFrameRegion pc_input_regions[];
extern const PcFrameRegion pc_palette_regions[];
extern const PcFrameRegion pc_fade_regions[];
extern const PcFrameRegion pc_collision_regions[];
extern const PcFrameRegion pc_stage_clear_regions[];

extern const PcFrameRegion pc_glyph_cache_regions[], pc_sprite_queue_regions[];

extern const PcFrameRegion pc_items_regions[], pc_pickups_regions[], pc_slowdown_regions[];

size_t pc_frame_regions_size(void);
bool pc_frame_regions_capture(void *buffer, size_t size);
bool pc_frame_regions_restore(const void *buffer, size_t size);

#endif
