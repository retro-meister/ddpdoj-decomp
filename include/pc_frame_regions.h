#ifndef DDPDOJ_PC_FRAME_REGIONS_H
#define DDPDOJ_PC_FRAME_REGIONS_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    void *data;
    size_t size;
} PcFrameRegion;

#define PC_FRAME_REGION(object) { &(object), sizeof(object) }
extern const PcFrameRegion pc_system_regions[], pc_game_flow_regions[];
extern const PcFrameRegion pc_layer_regions[], pc_screen_regions[];

size_t pc_frame_regions_size(void);
bool pc_frame_regions_capture(void *buffer, size_t size);
bool pc_frame_regions_restore(const void *buffer, size_t size);

#endif
