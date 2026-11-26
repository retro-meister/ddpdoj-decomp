#ifndef _WIN32
#define _FILE_OFFSET_BITS 64
#define _POSIX_C_SOURCE 200809L
#endif

#include "disc_image.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define disc_seek _fseeki64
#define disc_tell _ftelli64

static FILE *open_utf8(const char *path) {
    int count = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, path, -1, NULL, 0);
    if (count == 0) {
        return NULL;
    }
    wchar_t *wide = malloc((size_t)count * sizeof *wide);
    if (!wide) {
        return NULL;
    }
    FILE *file = NULL;
    if (MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, path, -1, wide, count)) {
        file = _wfopen(wide, L"rb");
    }
    free(wide);
    return file;
}
#else
#define disc_seek fseeko
#define disc_tell ftello

static FILE *open_utf8(const char *path) {
    return fopen(path, "rb");
}
#endif

enum { DISC_PATH_CAPACITY = 256, DISC_MAX_FILES = 16384, DISC_MAX_DEPTH = 16 };

typedef struct {
    char path[DISC_PATH_CAPACITY];
    DiscExtent extent;
} DiscFile;

struct DiscImage {
    FILE *file;
    uint64_t size;
    DiscFile *files;
    size_t file_count;
    size_t file_capacity;
};

static bool index_directory(DiscImage *image, DiscExtent directory, char *path, size_t prefix,
                            unsigned int depth, uint32_t *bytes_remaining);

static int compare_files(const void *left, const void *right) {
    return strcmp(((const DiscFile *)left)->path, ((const DiscFile *)right)->path);
}

bool disc_image_read(DiscImage *image, uint64_t offset, void *buffer, size_t size) {
    if (offset > image->size || size > image->size - offset) {
        return false;
    }
    return size == 0 ||
        (disc_seek(image->file, (int64_t)offset, SEEK_SET) == 0 &&
         fread(buffer, 1, size, image->file) == size);
}

/* ISO9660 writes both endian encodings into the same field. */
static bool read_dual(const uint8_t *field, unsigned int width, uint32_t *value) {
    uint32_t little = 0;
    uint32_t big = 0;
    for (unsigned int i = 0; i < width; ++i) {
        little |= (uint32_t)field[i] << (8 * i);
        big = (big << 8) | field[width + i];
    }
    *value = little;
    return little == big;
}

static uint64_t extent_offset(DiscExtent extent) {
    return (uint64_t)extent.lba * DISC_SECTOR_SIZE;
}

static bool record_extent(const DiscImage *image, const uint8_t *record, bool directory,
                          DiscExtent *extent) {
    DiscExtent result;
    if (record[1] || record[26] || record[27] || (record[25] & 0x80) ||
        ((record[25] & 2) != 0) != directory ||
        !read_dual(record + 2, 4, &result.lba) || !read_dual(record + 10, 4, &result.size)) {
        return false;
    }
    uint64_t offset = extent_offset(result);
    if (offset > image->size || result.size > image->size - offset) {
        return false;
    }
    *extent = result;
    return true;
}

DiscImage *disc_image_open(const char *path) {
    FILE *file = open_utf8(path);
    if (!file) {
        return NULL;
    }
    int64_t size = disc_seek(file, 0, SEEK_END) == 0 ? disc_tell(file) : -1;
    if (size < 0) {
        fclose(file);
        return NULL;
    }
    DiscImage image = {.file = file, .size = (uint64_t)size};
    uint8_t descriptor[DISC_SECTOR_SIZE];
    for (unsigned int sector = 16; sector < 256; ++sector) {
        if (!disc_image_read(&image, sector * DISC_SECTOR_SIZE, descriptor, sizeof descriptor) ||
            memcmp(descriptor + 1, "CD001\1", 6) != 0 || descriptor[0] == 255) {
            break;
        }
        if (descriptor[0] != 1) {
            continue;
        }
        uint32_t block_size;
        const uint8_t *root_record = descriptor + 156;
        DiscExtent root;
        if (!read_dual(descriptor + 128, 2, &block_size) || block_size != DISC_SECTOR_SIZE ||
            root_record[0] < 34 || !record_extent(&image, root_record, true, &root)) {
            break;
        }
        char directory_path[DISC_PATH_CAPACITY] = "";
        uint32_t directory_bytes_remaining = 16 * 1024 * 1024;
        if (!index_directory(&image, root, directory_path, 0, 0, &directory_bytes_remaining)) {
            break;
        }
        if (image.file_count == 0) {
            break;
        }
        qsort(image.files, image.file_count, sizeof *image.files, compare_files);
        DiscImage *result = malloc(sizeof *result);
        if (result) {
            *result = image;
            return result;
        }
        break;
    }
    free(image.files);
    fclose(file);
    return NULL;
}

void disc_image_close(DiscImage *image) {
    if (image) {
        fclose(image->file);
        free(image->files);
        free(image);
    }
}

static char ascii_upper(char value) {
    return value >= 'a' && value <= 'z' ? (char)(value - ('a' - 'A')) : value;
}

static size_t basename_size(const char *name, size_t length) {
    const char *version = memchr(name, ';', length);
    if (version) {
        length = (size_t)(version - name);
    }
    while (length > 0 && name[length - 1] == '.') {
        --length;
    }
    return length;
}

static bool append_name(char *path, size_t prefix, const char *name, size_t length) {
    length = basename_size(name, length);
    if (length == 0 || length >= DISC_PATH_CAPACITY - prefix) {
        return false;
    }
    for (size_t i = 0; i < length; ++i) {
        if (name[i] == '/' || name[i] == '\\' || name[i] == '\0') {
            return false;
        }
        path[prefix + i] = ascii_upper(name[i]);
    }
    path[prefix + length] = '\0';
    return true;
}

static bool index_file(DiscImage *image, const char *path, DiscExtent extent) {
    if (image->file_count == image->file_capacity) {
        if (image->file_capacity == DISC_MAX_FILES) {
            return false;
        }
        size_t capacity = image->file_capacity ? image->file_capacity * 2 : 64;
        DiscFile *files = realloc(image->files, capacity * sizeof *files);
        if (!files) {
            return false;
        }
        image->files = files;
        image->file_capacity = capacity;
    }
    DiscFile *file = &image->files[image->file_count++];
    strcpy(file->path, path);
    file->extent = extent;
    return true;
}

static bool index_directory(DiscImage *image, DiscExtent directory, char *path, size_t prefix,
                            unsigned int depth, uint32_t *bytes_remaining) {
    if (depth == DISC_MAX_DEPTH || directory.size == 0 || directory.size > *bytes_remaining) {
        return false;
    }
    *bytes_remaining -= directory.size;
    uint8_t block[DISC_SECTOR_SIZE];
    uint64_t offset = extent_offset(directory);
    uint32_t remaining = directory.size;
    while (remaining > 0) {
        size_t size = remaining < sizeof block ? remaining : sizeof block;
        if (!disc_image_read(image, offset, block, size)) {
            return false;
        }
        for (size_t pos = 0; pos < size && block[pos] != 0; pos += block[pos]) {
            const uint8_t *record = block + pos;
            if (record[0] < 34 || record[0] > size - pos || record[32] == 0 ||
                record[32] > record[0] - 33) {
                return false;
            }
            if (record[32] == 1 && record[33] < 2) {
                continue;
            }
            bool is_directory = (record[25] & 2) != 0;
            DiscExtent extent;
            if (!record_extent(image, record, is_directory, &extent) ||
                !append_name(path, prefix, (const char *)record + 33, record[32])) {
                return false;
            }
            if (is_directory) {
                size_t end = strlen(path);
                if (end == DISC_PATH_CAPACITY - 1) {
                    return false;
                }
                path[end] = '/';
                if (!index_directory(image, extent, path, end + 1, depth + 1, bytes_remaining)) {
                    return false;
                }
            } else if (!index_file(image, path, extent)) {
                return false;
            }
        }
        remaining -= (uint32_t)size;
        offset += size;
    }
    return true;
}

bool disc_image_find(DiscImage *image, const char *path, DiscExtent *extent) {
    if (strncmp(path, "cdrom0:", 7) == 0) {
        path += 7;
    }
    if (*path == '/' || *path == '\\') {
        ++path;
    }
    DiscFile key;
    size_t prefix = 0;
    for (;;) {
        size_t component_size = strcspn(path, "/\\");
        if (!append_name(key.path, prefix, path, component_size)) {
            return false;
        }
        if (path[component_size] == '\0') {
            break;
        }
        prefix = strlen(key.path);
        if (prefix == DISC_PATH_CAPACITY - 1) {
            return false;
        }
        key.path[prefix++] = '/';
        path += component_size + 1;
    }
    const DiscFile *file = bsearch(&key, image->files, image->file_count, sizeof *file, compare_files);
    if (!file || (file > image->files && compare_files(file - 1, file) == 0) ||
        (file + 1 < image->files + image->file_count && compare_files(file, file + 1) == 0)) {
        return false;
    }
    *extent = file->extent;
    return true;
}
