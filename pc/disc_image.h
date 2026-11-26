#ifndef DDPDOJ_PC_DISC_IMAGE_H
#define DDPDOJ_PC_DISC_IMAGE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

enum { DISC_SECTOR_SIZE = 2048 };

typedef struct DiscImage DiscImage;

typedef struct {
    uint32_t lba;
    uint32_t size;
} DiscExtent;

/* The path is UTF-8. Each image handle has its own read cursor. */
DiscImage *disc_image_open(const char *path);
void disc_image_close(DiscImage *image);
bool disc_image_find(DiscImage *image, const char *path, DiscExtent *extent);
bool disc_image_read(DiscImage *image, uint64_t offset, void *buffer, size_t size);

#endif
