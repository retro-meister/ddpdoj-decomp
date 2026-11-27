#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"
#include "cd.h"
#include "arcade_sprite.h"
#include "gfx.h"

/* Compressed size of each stage's sprite file (STnSP.PRS). */
s32 g_stage_sprite_packed_size[5] = {
    1355321, 2475303, 2619780, 2787147, 1251844,
};

/* Position (u, v) in the bullet and explosion textures of the sprites that are kept there, by sprite number. */
u16 g_bullet_uv_0bbf[16][2] = {
    { 18, 354 }, { 18, 370 }, { 18, 386 }, { 18, 402 }, { 18, 418 }, { 18, 434 },
    { 18, 450 }, { 18, 466 }, { 50, 354 }, { 50, 370 }, { 50, 386 }, { 50, 402 },
    { 50, 418 }, { 50, 434 }, { 50, 450 }, { 50, 466 },
};

u16 g_bullet_uv_0bff[16][2] = {
    { 290, 290 }, { 290, 314 }, { 290, 338 }, { 290, 362 }, { 290, 386 }, { 290, 410 },
    { 290, 434 }, { 290, 458 }, { 322, 290 }, { 322, 314 }, { 322, 338 }, { 322, 362 },
    { 322, 386 }, { 322, 410 }, { 322, 434 }, { 322, 458 },
};

u16 g_bullet_uv_0140[399][2] = {
    { 2, 2 }, { 2, 10 }, { 2, 18 }, { 2, 26 }, { 2, 34 }, { 2, 42 },
    { 2, 50 }, { 2, 66 }, { 2, 82 }, { 2, 98 }, { 2, 114 }, { 2, 130 },
    { 2, 146 }, { 2, 162 }, { 2, 178 }, { 2, 194 }, { 2, 210 }, { 2, 226 },
    { 2, 242 }, { 2, 258 }, { 2, 274 }, { 2, 290 }, { 162, 66 }, { 162, 82 },
    { 162, 98 }, { 162, 114 }, { 162, 130 }, { 162, 146 }, { 162, 162 }, { 162, 178 },
    { 162, 194 }, { 162, 210 }, { 162, 226 }, { 162, 242 }, { 162, 258 }, { 162, 274 },
    { 162, 290 }, { 162, 306 }, { 162, 322 }, { 162, 338 }, { 178, 66 }, { 178, 82 },
    { 178, 98 }, { 178, 114 }, { 178, 130 }, { 178, 146 }, { 178, 162 }, { 178, 178 },
    { 178, 194 }, { 178, 210 }, { 178, 226 }, { 178, 242 }, { 178, 258 }, { 178, 274 },
    { 178, 290 }, { 178, 306 }, { 178, 322 }, { 178, 338 }, { 290, 2 }, { 290, 18 },
    { 290, 34 }, { 290, 50 }, { 290, 66 }, { 290, 82 }, { 290, 98 }, { 290, 114 },
    { 290, 130 }, { 290, 146 }, { 290, 162 }, { 290, 178 }, { 290, 194 }, { 290, 210 },
    { 290, 226 }, { 290, 242 }, { 290, 258 }, { 290, 274 }, { 322, 2 }, { 322, 18 },
    { 322, 34 }, { 322, 50 }, { 322, 66 }, { 322, 82 }, { 322, 98 }, { 322, 114 },
    { 322, 130 }, { 322, 146 }, { 322, 162 }, { 322, 178 }, { 322, 194 }, { 322, 210 },
    { 322, 226 }, { 322, 242 }, { 322, 258 }, { 322, 274 }, { 18, 98 }, { 18, 114 },
    { 18, 130 }, { 18, 146 }, { 18, 162 }, { 18, 178 }, { 18, 194 }, { 18, 210 },
    { 18, 226 }, { 18, 242 }, { 18, 258 }, { 18, 274 }, { 18, 290 }, { 18, 306 },
    { 18, 322 }, { 18, 338 }, { 18, 2 }, { 18, 18 }, { 18, 34 }, { 18, 50 },
    { 18, 66 }, { 18, 82 }, { 194, 2 }, { 194, 18 }, { 194, 34 }, { 194, 50 },
    { 194, 66 }, { 34, 2 }, { 34, 18 }, { 34, 34 }, { 34, 50 }, { 34, 66 },
    { 34, 82 }, { 50, 2 }, { 50, 18 }, { 50, 34 }, { 50, 50 }, { 50, 66 },
    { 50, 82 }, { 66, 2 }, { 66, 18 }, { 66, 34 }, { 66, 50 }, { 66, 66 },
    { 66, 82 }, { 354, 2 }, { 354, 26 }, { 354, 50 }, { 354, 74 }, { 354, 98 },
    { 354, 122 }, { 354, 146 }, { 354, 170 }, { 354, 194 }, { 354, 218 }, { 354, 242 },
    { 354, 266 }, { 354, 290 }, { 354, 314 }, { 386, 2 }, { 386, 26 }, { 386, 50 },
    { 386, 74 }, { 386, 98 }, { 386, 122 }, { 386, 146 }, { 386, 170 }, { 386, 194 },
    { 386, 218 }, { 386, 242 }, { 386, 266 }, { 386, 290 }, { 130, 2 }, { 130, 18 },
    { 130, 34 }, { 130, 50 }, { 130, 66 }, { 130, 82 }, { 130, 98 }, { 130, 114 },
    { 130, 130 }, { 130, 146 }, { 130, 162 }, { 130, 178 }, { 130, 194 }, { 130, 210 },
    { 130, 226 }, { 130, 242 }, { 130, 258 }, { 130, 274 }, { 130, 290 }, { 130, 306 },
    { 130, 322 }, { 130, 338 }, { 146, 66 }, { 146, 82 }, { 146, 98 }, { 146, 114 },
    { 146, 130 }, { 146, 146 }, { 146, 162 }, { 146, 178 }, { 146, 194 }, { 146, 210 },
    { 146, 226 }, { 146, 242 }, { 146, 258 }, { 146, 274 }, { 146, 290 }, { 146, 306 },
    { 146, 322 }, { 146, 338 }, { 82, 2 }, { 82, 18 }, { 82, 34 }, { 82, 50 },
    { 82, 66 }, { 82, 82 }, { 98, 2 }, { 98, 18 }, { 98, 34 }, { 98, 50 },
    { 98, 66 }, { 98, 82 }, { 114, 2 }, { 114, 18 }, { 114, 34 }, { 114, 50 },
    { 114, 66 }, { 114, 82 }, { 162, 2 }, { 162, 18 }, { 162, 34 }, { 162, 50 },
    { 418, 2 }, { 418, 26 }, { 418, 50 }, { 418, 74 }, { 418, 98 }, { 418, 122 },
    { 418, 146 }, { 418, 170 }, { 418, 194 }, { 418, 218 }, { 418, 242 }, { 418, 266 },
    { 418, 290 }, { 418, 314 }, { 450, 2 }, { 450, 26 }, { 450, 50 }, { 450, 74 },
    { 450, 98 }, { 450, 122 }, { 450, 146 }, { 450, 170 }, { 450, 194 }, { 450, 218 },
    { 450, 242 }, { 450, 266 }, { 450, 290 }, { 82, 98 }, { 82, 114 }, { 82, 130 },
    { 82, 146 }, { 82, 162 }, { 82, 178 }, { 82, 194 }, { 82, 210 }, { 82, 226 },
    { 82, 242 }, { 82, 258 }, { 82, 274 }, { 82, 290 }, { 82, 306 }, { 82, 322 },
    { 82, 338 }, { 50, 98 }, { 50, 114 }, { 50, 130 }, { 50, 146 }, { 50, 162 },
    { 50, 178 }, { 50, 194 }, { 50, 210 }, { 50, 226 }, { 50, 242 }, { 50, 258 },
    { 50, 274 }, { 50, 290 }, { 50, 306 }, { 50, 322 }, { 50, 338 }, { 226, 2 },
    { 226, 18 }, { 226, 34 }, { 226, 50 }, { 226, 66 }, { 226, 82 }, { 226, 98 },
    { 226, 114 }, { 226, 130 }, { 226, 146 }, { 226, 162 }, { 226, 178 }, { 226, 194 },
    { 226, 210 }, { 226, 226 }, { 226, 242 }, { 226, 258 }, { 226, 274 }, { 242, 2 },
    { 242, 18 }, { 242, 34 }, { 242, 50 }, { 242, 66 }, { 242, 82 }, { 242, 98 },
    { 242, 114 }, { 242, 130 }, { 242, 146 }, { 242, 162 }, { 242, 178 }, { 242, 194 },
    { 242, 210 }, { 242, 226 }, { 242, 242 }, { 242, 258 }, { 242, 274 }, { 258, 2 },
    { 258, 18 }, { 258, 34 }, { 258, 50 }, { 258, 66 }, { 258, 82 }, { 258, 98 },
    { 258, 114 }, { 258, 130 }, { 258, 146 }, { 258, 162 }, { 258, 178 }, { 258, 194 },
    { 258, 210 }, { 258, 226 }, { 258, 242 }, { 258, 258 }, { 258, 274 }, { 258, 290 },
    { 258, 306 }, { 226, 322 }, { 226, 338 }, { 226, 354 }, { 226, 370 }, { 226, 386 },
    { 226, 402 }, { 226, 418 }, { 226, 434 }, { 226, 450 }, { 226, 466 }, { 258, 322 },
    { 258, 338 }, { 258, 354 }, { 258, 370 }, { 258, 386 }, { 258, 402 }, { 258, 418 },
    { 258, 434 }, { 258, 450 }, { 258, 466 }, { 194, 82 }, { 194, 98 }, { 194, 114 },
    { 194, 130 }, { 194, 146 }, { 194, 162 }, { 194, 178 }, { 194, 194 }, { 194, 210 },
    { 194, 226 }, { 194, 242 }, { 194, 258 }, { 194, 274 }, { 194, 290 }, { 194, 306 },
    { 194, 322 }, { 194, 338 }, { 194, 354 }, { 210, 82 }, { 210, 98 }, { 210, 114 },
    { 210, 130 }, { 210, 146 }, { 210, 162 }, { 210, 178 }, { 210, 194 }, { 210, 210 },
    { 210, 226 }, { 210, 242 }, { 210, 258 }, { 210, 274 }, { 210, 290 }, { 210, 306 },
    { 210, 322 }, { 210, 338 }, { 210, 354 },
};

u16 g_bullet_uv_13e0[108][2] = {
    { 114, 98 }, { 114, 106 }, { 114, 114 }, { 114, 122 }, { 114, 130 }, { 114, 138 },
    { 114, 146 }, { 114, 154 }, { 114, 162 }, { 114, 170 }, { 114, 178 }, { 114, 186 },
    { 114, 194 }, { 114, 202 }, { 114, 210 }, { 114, 218 }, { 114, 226 }, { 114, 234 },
    { 114, 242 }, { 114, 250 }, { 114, 258 }, { 114, 266 }, { 114, 274 }, { 114, 282 },
    { 114, 290 }, { 114, 298 }, { 114, 306 }, { 114, 314 }, { 114, 322 }, { 114, 330 },
    { 114, 338 }, { 114, 346 }, { 114, 354 }, { 114, 362 }, { 114, 370 }, { 114, 378 },
    { 482, 2 }, { 482, 10 }, { 482, 18 }, { 482, 26 }, { 482, 34 }, { 482, 42 },
    { 482, 50 }, { 482, 58 }, { 482, 66 }, { 482, 74 }, { 482, 82 }, { 482, 90 },
    { 482, 98 }, { 482, 106 }, { 482, 114 }, { 482, 122 }, { 482, 130 }, { 482, 138 },
    { 482, 146 }, { 482, 154 }, { 482, 162 }, { 482, 170 }, { 482, 178 }, { 482, 186 },
    { 482, 194 }, { 482, 202 }, { 482, 210 }, { 482, 218 }, { 482, 226 }, { 482, 234 },
    { 482, 242 }, { 482, 250 }, { 482, 258 }, { 482, 266 }, { 482, 274 }, { 482, 282 },
    { 354, 338 }, { 354, 346 }, { 354, 354 }, { 354, 362 }, { 354, 370 }, { 354, 378 },
    { 354, 386 }, { 354, 394 }, { 354, 402 }, { 354, 410 }, { 354, 418 }, { 354, 426 },
    { 354, 434 }, { 354, 442 }, { 354, 450 }, { 354, 458 }, { 354, 466 }, { 354, 474 },
    { 354, 482 }, { 354, 490 }, { 370, 338 }, { 370, 346 }, { 370, 354 }, { 370, 362 },
    { 370, 370 }, { 370, 378 }, { 370, 386 }, { 370, 394 }, { 370, 402 }, { 370, 410 },
    { 370, 418 }, { 370, 426 }, { 370, 434 }, { 370, 442 }, { 370, 450 }, { 370, 458 },
};

u16 g_bullet_uv_1340[128][2] = {
    { 2, 354 }, { 2, 370 }, { 2, 386 }, { 2, 402 }, { 2, 418 }, { 2, 434 },
    { 2, 450 }, { 2, 466 }, { 2, 482 }, { 82, 354 }, { 82, 370 }, { 82, 386 },
    { 82, 402 }, { 82, 418 }, { 82, 434 }, { 82, 450 }, { 82, 466 }, { 82, 482 },
    { 98, 354 }, { 98, 370 }, { 98, 386 }, { 98, 402 }, { 98, 418 }, { 98, 434 },
    { 98, 450 }, { 98, 466 }, { 98, 482 }, { 226, 290 }, { 226, 306 }, { 242, 290 },
    { 242, 306 }, { 18, 482 }, { 386, 322 }, { 386, 338 }, { 386, 354 }, { 386, 370 },
    { 386, 386 }, { 386, 402 }, { 386, 418 }, { 386, 434 }, { 386, 450 }, { 386, 466 },
    { 386, 482 }, { 402, 322 }, { 402, 338 }, { 402, 354 }, { 402, 370 }, { 402, 386 },
    { 402, 402 }, { 402, 418 }, { 402, 434 }, { 402, 450 }, { 402, 466 }, { 402, 482 },
    { 418, 338 }, { 418, 354 }, { 418, 370 }, { 418, 386 }, { 418, 402 }, { 418, 418 },
    { 418, 434 }, { 418, 450 }, { 418, 466 }, { 418, 482 }, { 178, 354 }, { 178, 370 },
    { 178, 386 }, { 178, 402 }, { 178, 418 }, { 178, 434 }, { 178, 450 }, { 178, 466 },
    { 178, 482 }, { 194, 370 }, { 194, 386 }, { 194, 402 }, { 194, 418 }, { 194, 434 },
    { 194, 450 }, { 194, 466 }, { 194, 482 }, { 210, 370 }, { 210, 386 }, { 210, 402 },
    { 210, 418 }, { 210, 434 }, { 210, 450 }, { 210, 466 }, { 210, 482 }, { 114, 466 },
    { 114, 482 }, { 34, 482 }, { 50, 482 }, { 66, 482 }, { 226, 482 }, { 242, 482 },
    { 130, 354 }, { 130, 370 }, { 130, 386 }, { 130, 402 }, { 130, 418 }, { 130, 434 },
    { 130, 450 }, { 130, 466 }, { 130, 482 }, { 146, 354 }, { 146, 370 }, { 146, 386 },
    { 146, 402 }, { 146, 418 }, { 146, 434 }, { 146, 450 }, { 146, 466 }, { 146, 482 },
    { 162, 354 }, { 162, 370 }, { 162, 386 }, { 162, 402 }, { 162, 418 }, { 162, 434 },
    { 162, 450 }, { 162, 466 }, { 162, 482 }, { 114, 386 }, { 114, 402 }, { 114, 418 },
    { 114, 434 }, { 114, 450 },
};

u16 g_explosion_uv_11e2[24][2] = {
    { 2, 2 }, { 2, 42 }, { 2, 82 }, { 2, 122 }, { 2, 162 }, { 2, 202 },
    { 2, 242 }, { 2, 282 }, { 2, 322 }, { 2, 362 }, { 2, 402 }, { 2, 442 },
    { 66, 2 }, { 66, 42 }, { 66, 82 }, { 66, 122 }, { 66, 162 }, { 66, 202 },
    { 66, 242 }, { 66, 282 }, { 66, 322 }, { 66, 362 }, { 66, 402 }, { 66, 442 },
};

u16 g_explosion_uv_123e[12][2] = {
    { 130, 2 }, { 130, 42 }, { 130, 82 }, { 130, 122 }, { 130, 162 }, { 130, 202 },
    { 130, 242 }, { 130, 282 }, { 130, 322 }, { 130, 362 }, { 130, 402 }, { 130, 442 },
};

u16 g_explosion_uv_1286[24][2] = {
    { 802, 2 }, { 802, 26 }, { 802, 50 }, { 802, 74 }, { 802, 98 }, { 802, 122 },
    { 802, 146 }, { 802, 170 }, { 802, 194 }, { 802, 218 }, { 802, 242 }, { 802, 266 },
    { 194, 2 }, { 194, 42 }, { 194, 82 }, { 194, 122 }, { 194, 162 }, { 194, 202 },
    { 194, 242 }, { 194, 282 }, { 194, 322 }, { 194, 362 }, { 194, 402 }, { 194, 442 },
};

u16 g_explosion_uv_12ba[54][2] = {
    { 418, 2 }, { 418, 66 }, { 418, 130 }, { 418, 194 }, { 418, 258 }, { 418, 322 },
    { 514, 2 }, { 514, 66 }, { 514, 130 }, { 514, 194 }, { 514, 258 }, { 514, 322 },
    { 610, 2 }, { 610, 66 }, { 610, 130 }, { 610, 194 }, { 610, 258 }, { 610, 322 },
    { 706, 2 }, { 706, 66 }, { 706, 130 }, { 706, 194 }, { 706, 194 }, { 706, 194 },
    { 418, 386 }, { 418, 442 }, { 498, 386 }, { 498, 442 }, { 578, 386 }, { 578, 442 },
    { 658, 386 }, { 658, 442 }, { 738, 386 }, { 738, 442 }, { 706, 258 }, { 706, 314 },
    { 258, 2 }, { 258, 58 }, { 258, 114 }, { 258, 170 }, { 258, 226 }, { 258, 282 },
    { 258, 338 }, { 258, 394 }, { 258, 450 }, { 338, 2 }, { 338, 58 }, { 338, 114 },
    { 338, 170 }, { 338, 226 }, { 338, 282 }, { 338, 338 }, { 338, 394 }, { 338, 450 },
};

#ifdef DEATH_LABEL
extern u8 g_noise_file_buf[];
#endif

#ifdef DDPDOJ_PC
_Alignas(64) static u8 stage_buffer[0x885800];
#endif

void arcade_sprite_init(void) {
    u8 *buffer;

#ifdef DDPDOJ_PC
    _Alignas(64) static u8 upload_buffer[0x80000];
    _Alignas(64) static SpriteImage image_buffer[0x10000 / sizeof(SpriteImage)];
    _Alignas(64) static u8 pixel_buffer[0xC20000];
    _Alignas(64) static u8 frame_buffer[0x10800];
    buffer = upload_buffer;
#else
    buffer = memalign(0x40, 0x80000);
#endif
    cd_read_sync(buffer, g_data_files[DATA_FILE_BULLET].size, g_data_files[DATA_FILE_BULLET].lba);
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2640, 8, SCE_GS_PSMT8, 0, 0, 512, 512);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, buffer);
    sceGsSyncPath(0, 0);
    cd_read_sync(buffer, g_data_files[DATA_FILE_EXPLOSION].size, g_data_files[DATA_FILE_EXPLOSION].lba);
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2A40, 0x10, SCE_GS_PSMT8, 0, 0, 1024, 256);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, buffer);
    sceGsSyncPath(0, 0);
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2A40, 0x10, SCE_GS_PSMT8, 0, 256, 1024, 256);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, buffer + 0x40000);
    sceGsSyncPath(0, 0);
#ifdef DDPDOJ_PC
    g_sprite_images = image_buffer;
    g_sprite_pixels = pixel_buffer;
    g_stage_sprite_buf = stage_buffer;
    g_frame_file_buf = frame_buffer;
#else
    free(buffer);
    g_sprite_images = (SpriteImage *)memalign(0x40, 0x10000);
    g_sprite_pixels = memalign(0x40, 0xC20000);
    g_stage_sprite_buf = memalign(0x40, 0x885800);
    g_frame_file_buf = memalign(0x40, 0x10800);
#endif
    cd_read_sync(g_frame_file_buf, g_data_files[DATA_FILE_FRAME].size, g_data_files[DATA_FILE_FRAME].lba);
    g_clut_upload_cbp = 0x3834;
    clut_upload(g_frame_file_buf, 1, 1);
    cd_read_sync(g_splash_file_buf, g_data_files[MAIN_OR_DEATH_LABEL(DATA_FILE_ARIKA, DATA_FILE_DON)].size,
                 g_data_files[MAIN_OR_DEATH_LABEL(DATA_FILE_ARIKA, DATA_FILE_DON)].lba);
    g_clut_upload_cbp = 0x3836;
    clut_upload(g_splash_file_buf, 1, 1);
    cd_read_sync(g_stage_map_file_buf, g_data_files[DATA_FILE_MAP].size, g_data_files[DATA_FILE_MAP].lba);
    g_clut_upload_cbp = 0x3838;
    clut_upload(g_stage_map_file_buf, 1, 1);
#ifdef DEATH_LABEL
    cd_read_sync(g_noise_file_buf, g_data_files[DATA_FILE_NOISE].size, g_data_files[DATA_FILE_NOISE].lba);
    g_clut_upload_cbp = 0x383C;
    clut_upload(g_noise_file_buf, 1, 1);
#endif
}


void sprite_header_load_async(void) {
    cd_read_async(g_sprite_images, g_data_files[DATA_FILE_SPRITE_HEADER].size, g_data_files[DATA_FILE_SPRITE_HEADER].lba);
}



void sprite_pixels_load_async(void) {
    cd_read_async(g_sprite_pixels, g_data_files[DATA_FILE_SPRITE_DATA].size, g_data_files[DATA_FILE_SPRITE_DATA].lba);
}

extern u8 *g_unpack_src;
extern u8 *g_unpack_dst;
extern u8 *g_unpack_src_start;
extern s32 g_unpack_step;
extern s32 g_unpack_chunk_size;
void stage_sprite_unpack_begin(s32 value) {
    u8 *base = g_stage_sprite_buf;
    g_unpack_chunk_size = value;
    g_unpack_step = 0;
    g_unpack_dst = base;
    g_unpack_src_start = base + 0x5DC800;
    g_unpack_src = g_unpack_src_start;
}

extern u16 g_stage;

s32 stage_sprite_unpack_step(void) {
    u8 *src;
    s32 count;
    u8 code;

    g_unpack_step++;
    while (g_unpack_src - g_unpack_src_start < g_stage_sprite_packed_size[g_stage]) {
        code = *g_unpack_src;
        g_unpack_src++;
        if (code & 0x80) {
            count = *g_unpack_src;
            g_unpack_src++;
            src = g_unpack_dst - (code & 0x7F);
            for (; count >= 0; count--) {
                *g_unpack_dst = *src;
                g_unpack_dst++;
                src++;
            }
        } else if (code & 0x40) {
            src = g_unpack_dst - (code & 0x3F);
            *g_unpack_dst = src[0];
            g_unpack_dst++;
            *g_unpack_dst = src[1];
            g_unpack_dst++;
        } else {
            *g_unpack_dst = code;
            g_unpack_dst++;
        }
        if (g_unpack_dst - g_stage_sprite_buf > g_unpack_step * g_unpack_chunk_size) {
            return 0;
        }
    }
    return 1;
}


void arcade_sprite_draw(void) {
    s32 tu;
    u16 flags;
    s32 flip;
    s32 tv;
    ArcadeSprite *p;
    u32 *src;
    u32 *dst;
    s32 tbp;
    s32 count;
    s32 index;
    s32 mode;
    s32 prev;
    s32 palette;
    s32 buf;
    s32 id;
    u16 attr;
    s16 w;
    s16 h;
    s32 out;
    s32 in;
    u32 word;
    u32 fill;
    s32 n;
    s16 x;
    s16 y;
    s16 w2;
    s32 ex;
    s32 ybits;
    s32 ey;
    s32 dx;
    s32 dy;
    s32 sx;
    s32 sy;
    s32 scale;
    u8 *pkt;

    count = 0;
    p = g_arcade_sprites;
    prev = -1;
    buf = 0;
    while (1) {
        attr = p->attr;
        if ((p->x | p->y | attr | p->id | p->size) == 0) {
            break;
        }
        palette = ((attr >> 8) & 0x1F) * 4 + 0x3730;
        reg_tmp.sh[1] = attr & 0x7F;
        reg_tmp.h[0] = p->id;
        tu = 0x10;
        tbp = 0x2240;
        tv = tu;
        mode = 1;
        id = reg_tmp.w;
        if (id == 0x10AA || (u32)(id - 0x11C3) <= 2 || id == 0x11C6) {
            palette = 0x383A;
        }
        if (id >= 0x1F69) {
            id = 0;
        }
        index = id;
        w = g_sprite_images[index].w;
        h = g_sprite_images[index].h;
        if (id >= 0xBBF && id < 0xBCF) {
            tu = g_bullet_uv_0bbf[id - 0xBBF][0];
            tv = g_bullet_uv_0bbf[id - 0xBBF][1];
            tbp = 0x2640;
        } else if (id >= 0xBFF && id < 0xC0F) {
            tu = g_bullet_uv_0bff[id - 0xBFF][0];
            tv = g_bullet_uv_0bff[id - 0xBFF][1];
            tbp = 0x2640;
        } else if (id >= 0x140 && id < 0x2CF) {
            tu = g_bullet_uv_0140[id - 0x140][0];
            tv = g_bullet_uv_0140[id - 0x140][1];
            tbp = 0x2640;
        } else if (id >= 0x13E0 && id < 0x144C) {
            tu = g_bullet_uv_13e0[id - 0x13E0][0];
            tv = g_bullet_uv_13e0[id - 0x13E0][1];
            tbp = 0x2640;
        } else if (id >= 0x1340 && id < 0x13C0) {
            tu = g_bullet_uv_1340[id - 0x1340][0];
            tv = g_bullet_uv_1340[id - 0x1340][1];
            tbp = 0x2640;
        } else if (id >= 0x11E2 && id < 0x11FA) {
            tbp = 0x2A40;
            tu = g_explosion_uv_11e2[id - 0x11E2][0];
            tv = g_explosion_uv_11e2[id - 0x11E2][1];
            mode = 3;
        } else if (id >= 0x123E && id < 0x124A) {
            tbp = 0x2A40;
            tu = g_explosion_uv_123e[id - 0x123E][0];
            tv = g_explosion_uv_123e[id - 0x123E][1];
            mode = 3;
        } else if (id >= 0x1286 && id < 0x129E) {
            tbp = 0x2A40;
            tu = g_explosion_uv_1286[id - 0x1286][0];
            tv = g_explosion_uv_1286[id - 0x1286][1];
            mode = 3;
        } else if (id >= 0x12BA && id < 0x12F0) {
            tbp = 0x2A40;
            tu = g_explosion_uv_12ba[id - 0x12BA][0];
            tv = g_explosion_uv_12ba[id - 0x12BA][1];
            mode = 3;
        } else if (prev != id) {
            prev = id;
            if (id >= 0x195E) {
                sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, 8, 0x13, 0x10, 0x10, w, h);
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, g_stage_sprite_buf + g_sprite_images[index].offset);
            } else {
                src = (u32 *)(g_sprite_pixels + g_sprite_images[index].offset);
                out = 0;
                in = 0;
                dst = g_image_unpack_buf;
                if (!(src[0] & 0x80000000)) {
                    sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, 8, 0x13, 0x10, 0x10, w, h);
                    FlushCache(0);
                    sceGsExecLoadImage(&g_gs_load_image, src);
                } else {
                    do {
                        fill = src[in++];
                        word = fill;
                        if (!(word & 0x40000000)) {
                            dst[out++] = word & 0x1F1F1F1F;
                        } else {
                            fill = src[in++] & 0x1F1F1F1F;
                            for (n = word & 0x3FFF; n >= 0; n--) {
                                dst[out++] = fill;
                            }
                        }
                    } while (out < w * h / 4);
                    sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, 8, 0x13, 0x10, 0x10, w, h);
                    FlushCache(0);
                    sceGsExecLoadImage(&g_gs_load_image, dst);
                }
            }
            sceGsSyncPath(0, 0);
        }
        x = p->x & 0x7FF;
        y = p->y & 0x3FF;
        dy = p->size & 0x1FF;
        dx = ((p->size >> 9) & 0x3F) << 4;
        w2 = g_sprite_images[index].w;
        h = g_sprite_images[index].h;
        if (x & 0x400) {
            x |= 0xF800;
        }
        if (y & 0x100) {
            y |= 0xFE00;
        }
        ex = x;
        ey = y;
        sx = (p->x & 0xF800) >> 11;
        ybits = p->y & 0xF800;
        if (sx == 0 || (sy = ybits >> 11) == 0) {
            p++;
            continue;
        }
        if (sx != 16) {
            scale = g_sprite_zoom_table[sx];
            if (scale >= 10000) {
                dx = (dx * scale + 5000) / 10000;
            } else {
                dx = dx * scale / 10000 + 1;
            }
        }
        if (sy != 16) {
            scale = g_sprite_zoom_table[sy];
            if (scale >= 10000) {
                dy = (dy * scale + 5000) / 10000;
            } else {
                dy = dy * scale / 10000 + 1;
            }
        }
        flags = p->attr;
        flip = (flags >> 13) & 3;
        g_quad_queue[count].z = 10;
        g_quad_queue[count].alpha = 0x80;
        g_quad_queue[count].tbp = tbp;
        g_quad_queue[count].mode = mode;
        g_quad_queue[count].cbp = palette;
        g_quad_queue[count].color = 0x80;
        g_quad_queue[count].x[0] = ex;
        g_quad_queue[count].y[0] = ey;
        g_quad_queue[count].x[1] = ex + dx;
        g_quad_queue[count].y[1] = ey + dy;
        switch (flip) {
        case 0:
            g_quad_queue[count].u[0] = tu;
            g_quad_queue[count].v[0] = tv;
            g_quad_queue[count].u[1] = tu + w2;
            g_quad_queue[count].v[1] = tv + h;
            break;
        case 1:
            g_quad_queue[count].u[0] = tu + w2;
            g_quad_queue[count].v[0] = tv;
            g_quad_queue[count].u[1] = tu;
            g_quad_queue[count].v[1] = tv + h;
            break;
        case 2:
            g_quad_queue[count].u[0] = tu;
            g_quad_queue[count].v[0] = tv + h;
            g_quad_queue[count].u[1] = tu + w2;
            g_quad_queue[count].v[1] = tv;
            break;
        case 3:
            g_quad_queue[count].u[0] = tu + w2;
            g_quad_queue[count].v[0] = tv + h;
            g_quad_queue[count].u[1] = tu;
            g_quad_queue[count].v[1] = tv;
            break;
        }
        pkt = g_gif_buf[buf];
        quad_build_packet((Qword *)pkt, count, 1);
        sceGsSyncPath(0, 0);
        FlushCache(0);
        SEND_DMA_CHAIN(g_dma_gif, pkt, sizeof(g_gif_buf[0]));
        buf ^= 1;
        count++;
        p++;
    }
    g_quad_count = count;
}

#pragma push
#pragma global_optimizer off
typedef union {
    u64 d[2];
    unsigned __int128 q;
} GifTag;

extern void sceGifPkOpenGifTag(sceGifPacket *packet, unsigned __int128 tag);
extern void sceGifPkCloseGifTag(sceGifPacket *packet);
extern void sceGifPkAddGsAD(sceGifPacket *packet, s32 addr, u64 data);

GifTag g_frame_gif_tag = { { SCE_GIF_SET_TAG(0, 1, 0, 0, SCE_GIF_PACKED, 1), 0xE } };

void frame_image_draw(u16 alpha) {
    GifTag tag;
    sceGifPacket packet;
    u8 *buf;
    s32 c;
    u64 prim;

    tag = g_frame_gif_tag;
    buf = g_gif_buf[0];
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, 8, 0x13, 0, 0, 320, 208);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, g_frame_file_buf + 0x200);
    sceGsSyncPath(0, 0);
    sceGifPkInit(&packet, buf);
    sceGifPkReset(&packet);
    sceGifPkOpenGifTag(&packet, tag.q);
    sceGifPkAddGsAD(&packet, 8, 0);
    sceGifPkAddGsAD(&packet, 20, 0);
    sceGifPkAddGsAD(&packet, 71, 0x3000F);
    sceGifPkAddGsAD(&packet, 59, (u64)128 << 32);
    sceGifPkAddGsAD(&packet, 66, 68);
    sceGifPkAddGsAD(&packet, 63, 0);
    sceGifPkCloseGifTag(&packet);
    sceGifPkOpenGifTag(&packet, tag.q);
    prim = 0x65322240 | ((u64)0x20170686 << 32);
    sceGifPkAddGsAD(&packet, 6, prim);
    sceGifPkAddGsAD(&packet, 0, 70);
    sceGifPkAddGsAD(&packet, 1, (s64)(alpha / 2) << 24);
    sceGifPkAddGsAD(&packet, 4, 0x79087008);
    sceGifPkAddGsAD(&packet, 4, 0x87088C08);
    sceGifPkCloseGifTag(&packet);
    c = 0x80;
    sceGifPkOpenGifTag(&packet, tag.q);
    sceGifPkAddGsAD(&packet, 6, 0x65322240 | ((u64)0x20170686 << 32));
    sceGifPkAddGsAD(&packet, 0, 342);
    sceGifPkAddGsAD(&packet, 1, (s64)c | ((s64)c << 8) | (0x80 << 16) | ((u64)alpha << 24));
    sceGifPkAddGsAD(&packet, 3, 0);
    sceGifPkAddGsAD(&packet, 4, 0x79887408);
    sceGifPkAddGsAD(&packet, 3, 0x0D001400);
    sceGifPkAddGsAD(&packet, 4, 0x86888808);
    sceGifPkCloseGifTag(&packet);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buf, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
#pragma pop

SpriteImage *g_sprite_images;
u8 *g_sprite_pixels;
u8 *g_stage_sprite_buf;
u8 *g_frame_file_buf;
s32 g_unpack_chunk_size;
s32 g_unpack_step;
u8 *g_unpack_src_start;
u8 *g_unpack_dst;
u8 *g_unpack_src;

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

const PcFrameRegion pc_stage_sprites_regions[] = {
    PC_FRAME_REGION(stage_buffer),
    PC_FRAME_REGION(g_unpack_chunk_size),
    PC_FRAME_REGION(g_unpack_step),
    PC_FRAME_POINTER(g_unpack_src_start),
    PC_FRAME_POINTER(g_unpack_src),
    PC_FRAME_POINTER(g_unpack_dst),
    { NULL, 0 },
};
#endif
