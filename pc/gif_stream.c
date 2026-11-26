#include "gif_stream.h"
#include "sdk/eestruct.h"

#include <string.h>

static u64 read_word(const u8 *data)
{
    u64 word;
    memcpy(&word, data, sizeof(word));
    return word;
}

bool pc_gif_decode(const void *payload, size_t size, const PcGifSink *sink, void *context)
{
    const u8 *cursor = payload;
    if (size % 16 != 0 || (size != 0 && cursor == NULL)) {
        return false;
    }

    while (size != 0) {
        u64 tag = read_word(cursor);
        u64 descriptors = read_word(cursor + 8);
        unsigned loops = tag & 0x7FFF;
        unsigned format = (tag >> 58) & 3;
        unsigned registers = tag >> 60;
        if (registers == 0) {
            registers = 16;
        }
        cursor += 16;
        size -= 16;

        size_t entries = loops * registers;
        size_t data_size;
        switch (format) {
        case SCE_GIF_PACKED:
            data_size = entries * 16;
            break;
        case SCE_GIF_REGLIST:
            data_size = ((entries + 1) / 2) * 16;
            break;
        case SCE_GIF_IMAGE:
            data_size = loops * 16;
            break;
        default:
            return false;
        }
        if (data_size > size) {
            return false;
        }
        if (loops != 0 && format == SCE_GIF_PACKED && ((tag >> 46) & 1)) {
            sink->write_register(context, SCE_GS_PRIM, (tag >> 47) & 0x7FF);
        }

        if (format == SCE_GIF_IMAGE) {
            if (data_size != 0) {
                sink->write_image(context, cursor, data_size);
            }
        } else {
            size_t stride = format == SCE_GIF_REGLIST ? 8 : 16;
            for (size_t i = 0; i < entries; i++) {
                u8 descriptor = (descriptors >> ((i % registers) * 4)) & 0x0F;
                const u8 *entry = cursor + i * stride;
                if (descriptor == 0x0F) {
                    continue;
                }
                u64 value = read_word(entry);
                if (format == SCE_GIF_REGLIST) {
                    sink->write_register(context, descriptor, value);
                } else if (descriptor == SCE_GIF_PACKED_AD) {
                    sink->write_register(context, entry[8], value);
                } else {
                    sink->write_packed(context, descriptor, value, read_word(entry + 8));
                }
            }
        }

        cursor += data_size;
        size -= data_size;
    }
    return true;
}
