#include "pc_frame_regions.h"
#include <string.h>
#include "pc_arcade_address.h"

static const PcFrameRegion *const groups[] = {
    pc_system_regions, pc_game_flow_regions, pc_layer_regions, pc_screen_regions,
    pc_stage_sprites_regions, pc_graphics_regions, pc_stage_maps_regions,
    pc_attract_regions, pc_ship_select_regions, pc_menu_regions,
    pc_boss_regions, pc_input_regions, pc_palette_regions, pc_fade_regions, pc_collision_regions, pc_stage_clear_regions, pc_glyph_cache_regions, pc_sprite_queue_regions,
    pc_items_regions, pc_pickups_regions, pc_slowdown_regions,
};

size_t pc_frame_regions_size(void)
{
    size_t total = 0;
    for (size_t i = 0; i < sizeof(groups) / sizeof(groups[0]); ++i) {
        for (const PcFrameRegion *r = groups[i]; r->size; ++r) total += r->size;
    }
    return total;
}

bool pc_frame_regions_capture(void *buffer, size_t size)
{
    if (size != pc_frame_regions_size()) return false;
    unsigned char *next = buffer;
    for (size_t i = 0; i < sizeof(groups) / sizeof(groups[0]); ++i) {
        for (const PcFrameRegion *r = groups[i]; r->size; ++r) {
            if (r->image_pointer) {
                uintptr_t address;
                memcpy(&address, r->data, sizeof(address));
                if (address && !pc_arcade_address_contains(address)) return false;
                uint32_t slot = pc_arcade_address_encode(address);
                memcpy(next, &slot, sizeof(slot));
            } else memcpy(next, r->data, r->size);
            next += r->size;
        }
    }
    return true;
}

bool pc_frame_regions_restore(const void *buffer, size_t size)
{
    if (size != pc_frame_regions_size()) return false;
    const unsigned char *next = buffer;
    for (size_t i = 0; i < sizeof(groups) / sizeof(groups[0]); ++i) {
        for (const PcFrameRegion *r = groups[i]; r->size; ++r) {
            if (r->image_pointer) {
                uint32_t slot;
                memcpy(&slot, next, sizeof(slot));
                if (slot > pc_arcade_image_size) return false;
                uintptr_t address = pc_arcade_address_decode(slot);
                memcpy(r->data, &address, sizeof(address));
            } else memcpy(r->data, next, r->size);
            next += r->size;
        }
    }
    return true;
}
