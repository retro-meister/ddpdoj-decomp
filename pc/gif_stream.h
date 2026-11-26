#ifndef DDPDOJ_PC_GIF_STREAM_H
#define DDPDOJ_PC_GIF_STREAM_H

#include "types.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    void (*write_register)(void *context, u8 address, u64 value);
    void (*write_packed)(void *context, u8 descriptor, u64 low, u64 high);
    void (*write_image)(void *context, const void *pixels, size_t size);
} PcGifSink;

/* Accepts the complete DMA payload, which can contain multiple EOP tags. */
bool pc_gif_decode(const void *payload, size_t size, const PcGifSink *sink, void *context);

#endif
