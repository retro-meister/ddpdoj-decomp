#include "pc_frame_regions.h"
#include <string.h>

static const PcFrameRegion *const groups[] = {
    pc_system_regions, pc_game_flow_regions, pc_layer_regions, pc_screen_regions,
    pc_stage_sprites_regions, pc_graphics_regions, pc_stage_maps_regions,
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
            memcpy(next, r->data, r->size);
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
            memcpy(r->data, next, r->size);
            next += r->size;
        }
    }
    return true;
}
