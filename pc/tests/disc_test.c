#include "disc_image.h"
#include "cdvd.h"
#include "cd.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern s8 g_cd_async_busy;
extern u32 g_cd_total_bytes_read;

static void require(bool condition, const char *message) {
    if (!condition) {
        fprintf(stderr, "%s\n", message);
        exit(EXIT_FAILURE);
    }
}

static void write_dual(uint8_t *field, size_t width, uint32_t value) {
    for (size_t i = 0; i < width; ++i) {
        field[i] = field[2 * width - i - 1] = (uint8_t)(value >> (8 * i));
    }
}

static size_t write_record(uint8_t *record, const char *name, size_t length, DiscExtent extent,
                           bool directory) {
    size_t record_size = 33 + length + (length % 2 == 0);
    record[0] = (uint8_t)record_size;
    write_dual(record + 2, 4, extent.lba);
    write_dual(record + 10, 4, extent.size);
    record[25] = directory ? 2 : 0;
    record[32] = (uint8_t)length;
    memcpy(record + 33, name, length);
    return record_size;
}

static void write_fixture(const char *path, bool truncated_extent) {
    const DiscExtent root = {20, 2 * DISC_SECTOR_SIZE};
    const DiscExtent nested = {22, DISC_SECTOR_SIZE};
    uint8_t volume[24][DISC_SECTOR_SIZE] = {0};
    volume[16][0] = 1;
    memcpy(volume[16] + 1, "CD001\1", 6);
    write_dual(volume[16] + 128, 2, DISC_SECTOR_SIZE);
    write_record(volume[16] + 156, "\0", 1, root, true);
    write_record(volume[20], "\0", 1, root, true);
    write_record(volume[21], "DATA", 4, nested, true);
    write_record(volume[22], "FILE.BIN;1", 10, (DiscExtent){truncated_extent ? 24 : 23, 4}, false);
    memcpy(volume[23], "DOJ!", 4);
    FILE *file = fopen(path, "wb");
    require(file != NULL, "Could not create ISO fixture");
    require(fwrite(volume, sizeof volume, 1, file) == 1 && fclose(file) == 0,
            "Could not write ISO fixture");
}

static void check_fixture(const char *path) {
    write_fixture(path, false);
    DiscImage *image = disc_image_open(path);
    require(image != NULL, "Could not open ISO fixture");
    DiscExtent extent;
    require(disc_image_find(image, "cdrom0:\\data\\file.bin;1", &extent), "PS2 path must resolve");
    require(extent.lba == 23 && extent.size == 4, "File extent must match the directory record");
    char data[4];
    require(disc_image_read(image, (uint64_t)extent.lba * DISC_SECTOR_SIZE, data, sizeof data) &&
            memcmp(data, "DOJ!", sizeof data) == 0, "File contents must match");
    require(!disc_image_find(image, "DATA/MISSING", &extent), "Missing file must be rejected");
    require(!disc_image_read(image, 24 * DISC_SECTOR_SIZE - 1, data, sizeof data),
            "Out-of-image reads must be rejected");
    disc_image_close(image);
    require(pc_cdvd_mount(path), "Could not mount ISO fixture");
    require(!pc_cdvd_mount(path), "Mount must reject a second image");
    sceCdlFILE file;
    require(sceCdInit(0) && sceCdMmode(2) && sceCdDiskReady(1) == SCECdComplete,
            "The DVD drive must report ready after mounting");
    require(sceCdSearchFile(&file, "DATA/FILE.BIN") && file.lsn == 23 && file.size == 4,
            "The game CD API must see the indexed file");
    require(!sceCdSearchFile(&file, "DATA/MISSING"), "Missing PS2 file must return failure");
    uint8_t sector[DISC_SECTOR_SIZE];
    memset(sector, 0xA5, sizeof sector);
    for (int i = 0; i < 3; ++i) {
        cd_read_async(sector, 4, file.lsn);
        require(g_cd_async_busy, "The original loader must remain busy before the sync frame");
    }
    require(sceCdSync(0) == 0 && sceCdGetError() == 0, "Worker read must succeed");
    cd_read_async(sector, 4, file.lsn);
    require(!g_cd_async_busy && g_cd_total_bytes_read == 4 && memcmp(sector, "DOJ!", 4) == 0,
            "The original loader must publish a completed worker read");
    require(sector[4] == 0, "The worker transfers the entire sector");
    sceCdRMode mode = {.datapattern = SCECdSecS2048};
    require(sceCdRead(24, 1, sector, &mode) && sceCdSync(0) == 0 && sceCdGetError() != 0,
            "Out-of-image sector read must report an error");
    require(sceCdRead(23, 1, sector, &mode), "A valid read must still be accepted after an error");
    sceCdBreak();
    require(sceCdSync(1) == 0, "The destination must be reusable after a break");
    pc_cdvd_unmount();
    require(sceCdDiskReady(0) == 0 && !sceCdRead(23, 1, sector, &mode), "Unmount must clear the drive");

    write_fixture(path, true);
    require(disc_image_open(path) == NULL, "The index must reject an out-of-image extent");
    require(remove(path) == 0, "Could not remove ISO fixture");
    require(disc_image_open(path) == NULL, "Missing ISO must be rejected");
}

static void check_retail(const char *path, const char *baserom) {
    static const char *const targets[] = {"SLPS_252.33", "DEATH.ELF", "GALLERY.ELF"};
    static const char *const assets[] = {"\\DATA\\FONT.GF;1", "\\SPRITE\\SPHED.PRS;1",
                                         "\\GALLERY\\GALLERY.DA;1"};
    DiscImage *image = disc_image_open(path);
    require(image != NULL, "Could not open retail ISO");
    for (size_t i = 0; i < sizeof targets / sizeof targets[0]; ++i) {
        DiscExtent extent;
        require(disc_image_find(image, targets[i], &extent), targets[i]);
        char reference_path[4096];
        int length = snprintf(reference_path, sizeof reference_path, "%s/%s", baserom, targets[i]);
        require(length > 0 && (size_t)length < sizeof reference_path, "Reference path is too long");
        FILE *reference = fopen(reference_path, "rb");
        require(reference != NULL, reference_path);
        for (uint32_t position = 0; position < extent.size;) {
            uint8_t actual[DISC_SECTOR_SIZE];
            uint8_t expected[DISC_SECTOR_SIZE];
            uint32_t remaining = extent.size - position;
            size_t size = remaining < sizeof actual ? remaining : sizeof actual;
            uint64_t offset = (uint64_t)extent.lba * DISC_SECTOR_SIZE + position;
            require(disc_image_read(image, offset, actual, size), "Retail extent read failed");
            require(fread(expected, 1, size, reference) == size &&
                    memcmp(actual, expected, size) == 0, targets[i]);
            position += (uint32_t)size;
        }
        require(fgetc(reference) == EOF && !ferror(reference), "Retail extent length differs");
        fclose(reference);
    }
    require(pc_cdvd_mount(path), "Could not mount retail ISO in the game CD driver");
    for (size_t i = 0; i < sizeof assets / sizeof assets[0]; ++i) {
        DiscExtent extent;
        sceCdlFILE file;
        require(disc_image_find(image, assets[i], &extent) && sceCdSearchFile(&file, assets[i]),
                assets[i]);
        require(file.lsn == extent.lba && file.size == extent.size && file.size != 0,
                "The game drive must expose the original file's size and LBA");
        uint8_t actual[DISC_SECTOR_SIZE], expected[DISC_SECTOR_SIZE];
        cd_read_sync(actual, sizeof actual, file.lsn);
        require(disc_image_read(image, (uint64_t)extent.lba * DISC_SECTOR_SIZE, expected, sizeof expected)
                && memcmp(actual, expected, sizeof actual) == 0, assets[i]);
    }
    pc_cdvd_unmount();
    disc_image_close(image);
}

int main(int argc, char **argv) {
    if (argc == 3) {
        check_retail(argv[1], argv[2]);
    } else {
        check_fixture(argc == 2 ? argv[1] : "ddpdoj-disc-test.iso");
    }
    return 0;
}
