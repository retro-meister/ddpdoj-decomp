#include "gallery/gallery.h"

typedef struct {
    u32 archivePosition;
    u32 entryLocation;
} GalleryArchiveEntry;

const char g_gallery_archive_path[32] = "\\GALLERY\\GALLERY.DA;1";

static const char *g_grid_help_lines[2] __attribute__((section(".data"))) = {
    SJIS("方向キー、Ｌ１、Ｒ１ボタンで選択してください。"),
    SJIS("○ボタンで決定、×ボタンで終了できます。"),
};

static const char *g_exit_prompt_lines[4] = {
    SJIS("ギャラリーを終了しますか？"),
    0,
    0,
    0,
};

const u16 g_menu_dir_buttons[8] = {
    SCE_PADLup, SCE_PADLdown, SCE_PADLleft, SCE_PADLright, SCE_PADselect, 0, 0, 0,
};

const u16 g_menu_action_buttons[8] = {
    SCE_PADstart, SCE_PADRleft, SCE_PADRright, SCE_PADRup, SCE_PADRdown, 0, 0, 0,
};

const char *g_viewer_help_lines[8] = {
    SJIS("Ｒ１　　　次の絵に移動"),
    SJIS("Ｌ１　　　前の絵に移動"),
    SJIS("方向キー　スクロール"),
    SJIS("△　　　　ズーム切替"),
    SJIS("×　　　　戻る"),
    SJIS("スタート　メニュー表示切替"),
    0,
    0,
};

static const u8 g_now_loading_text[16] = "NOW LOADING";

static const Rect16 g_ui_sprite_uvs[6] = {
    { 0, 0, 374, 107 },
    { 0, 109, 512, 235 },
    { 1, 347, 491, 94 },
    { 99, 450, 95, 23 },
    { 216, 450, 36, 32 },
    { 270, 450, 36, 32 },
};

static const Rect16 g_ui_sprite_rects[6] = {
    { 128, -27, 502, 80 },
    { 0, 72, 640, 307 },
    { 14, 317, 627, 411 },
    { 218, 40, 411, 63 },
    { 172, 21, 208, 53 },
    { 424, 21, 459, 53 },
};

static s32 (*g_gallery_modes[8])(void) = {
    gallery_state_loading,
    gallery_state_fade_in,
    gallery_state_grid,
    gallery_state_viewer,
    gallery_state_exit,
    0,
    0,
    0,
};

static u8 g_gallery_image_order[0x90] = {
    12, 13, 14, 17, 18, 24, 30, 29, 28, 27, 26, 25,
    8, 7, 6, 4, 5, 16, 15, 11, 10, 33, 32, 31,
    19, 20, 21, 22, 23, 2, 0, 1, 3,
};
const char *g_archive_list[1] = { g_gallery_archive_path };

extern s32 g_thumb_pulse;
extern s32 g_cursor_pulse;
extern s32 g_selected_image_idx;
extern u32 g_frame_count;
extern GalleryArchiveEntry g_gallery_archive[1];
extern s32 g_archive_toc[0x200];
extern s8 g_image_viewed_flags[256];
extern s8 g_image_unlock_flags[0x100];

static inline u64 getTex0Cbp(u64 tex0)
{
    return (u64)((s32)((tex0 >> 37) & 0x3FFF));
}

void gallery_main(void)
{
    u32 archiveIndex;

    vram_clear_all();
    tex_upload_reset();
    font_init();
    sceGsResetGraph(0, 1, 2, 1);
    memset(&g_gs_dbuff, 0, sizeof(g_gs_dbuff));
    sceGsSetDefDBuffDc(&g_gs_dbuff, 0, 640, 224, 1, 0x31, 0);
    FlushCache(0);
    sceGsSyncV(0);
    sceGsPutDrawEnv(g_gs_dbuff.draw01);
    sceGsSyncPath(0, 0);
    sceGsPutDrawEnv(g_gs_dbuff.draw11);
    sceGsSyncPath(0, 0);
    iop_reboot_and_load_modules();
    pad_open_ports();
    g_dma_gif = sceDmaGetChan(2);
    pad_init_system();
    g_pad_dma_buf = g_pad_dma_area;
    *(volatile u32 *)0x10000010 = 0x83;
    sound_init_file_tables();

    archiveIndex = 0;
    do {
        cd_search_file(g_archive_list[archiveIndex]);
        g_gallery_archive[archiveIndex].archivePosition = g_cd_file.size;
        g_gallery_archive[archiveIndex].entryLocation = g_cd_file.lba;
    } while (++archiveIndex == 0);

    archiveIndex = 0;
    do {
        cd_read_sync((u8 *)g_archive_toc + archiveIndex * 0x800, 0x9C,
                      g_gallery_archive[archiveIndex].entryLocation);
    } while (++archiveIndex == 0);

    tex_upload_init_vram();
    font_upload_default_cluts();
    sceMcInit();
    mc_load_icons();
    sound_init();
    g_gallery = memalign(0x40, 0x885800);
    memset(g_gallery, 0, 0x5057C0);
    gallery_run_loop();
    free(g_gallery);
    gallery_exit_to_elf(0);
}

void gallery_run_loop(void)
{
    s32 entryIndex;
    s32 ready;
    s8 entryState;

    g_frame_count = 0;

    for (entryIndex = 0x20; entryIndex >= 0; entryIndex--) {
        g_image_unlock_flags[entryIndex] = 2;
    }

    for (entryIndex = 0; entryIndex < 0x100; entryIndex++) {
        entryState = g_image_unlock_flags[entryIndex];
        if (entryState != 0) {
            g_gallery->itemStatus[entryIndex] = entryState;
            g_gallery->itemThumbIds[entryIndex] = g_gallery_image_order[entryIndex];
        }
    }

    g_gallery->itemStatus[0x11] = 0;
    g_gallery->showHelp = 1;

    do {
        *(volatile u32 *)0x10000000 = 0;
        sceGsSwapDBuffDc(&g_gs_dbuff, g_frame_count);
        gallery_init_frame_gs();
        pad_update();

        if (*(volatile s8 *)&g_pads[2].analogX < 0) {
            g_pads[2].buttons |= SCE_PADLleft;
        }
        if (*(volatile s8 *)&g_pads[2].analogX > 0) {
            g_pads[2].buttons |= SCE_PADLright;
        }
        if (*(volatile s8 *)&g_pads[2].analogY < 0) {
            g_pads[2].buttons |= SCE_PADLup;
        }
        if (*(volatile s8 *)&g_pads[2].analogY > 0) {
            g_pads[2].buttons |= SCE_PADLdown;
        }

        gallery_tick_and_render();
        sound_update();
        pad_update_vibration();

        g_frame_count++;
        ready = !sceGsSyncV(0);

        if (g_frame_count & 1) {
            sceGsSetHalfOffset(g_gs_dbuff.draw11_env, 0x800, 0x800, (s16)ready);
            sceGsSetHalfOffset2(g_gs_dbuff.draw12, 0x800, 0x800, (s16)ready);
        } else {
            sceGsSetHalfOffset(g_gs_dbuff.draw01_env, 0x800, 0x800, (s16)ready);
            sceGsSetHalfOffset2(g_gs_dbuff.draw02, 0x800, 0x800, (s16)ready);
        }

        FlushCache(0);
        sceGsSyncPath(0, 0);
    } while (!g_gallery->exitRequested);

    g_gallery = 0;
}

void gallery_init_frame_gs(void)
{
    sceGifPacket packet;

    sceGifPkInit(&packet, g_gif_buf);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(5, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, SCE_GS_SET_TEXA(0x00, 0, 0x80));
    sceGifPkAddGsData(&packet, SCE_GS_TEXA);
    sceGifPkAddGsData(&packet, SCE_GS_SET_TEST(1, 7, 0, 0, 0, 0, 1, 1));
    sceGifPkAddGsData(&packet, SCE_GS_TEST_1);
    sceGifPkAddGsData(&packet, SCE_GS_SET_ZBUF(0, 0, 1));
    sceGifPkAddGsData(&packet, SCE_GS_ZBUF_1);
    sceGifPkAddGsData(&packet, 0ULL);
    sceGifPkAddGsData(&packet, SCE_GS_TEX1_1);
    sceGifPkAddGsData(&packet, SCE_GS_SET_ALPHA(0, 1, 0, 1, 0));
    sceGifPkAddGsData(&packet, SCE_GS_ALPHA_1);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, g_gif_buf, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

void gallery_tick_and_render(void)
{
    s32 overlayAdjustment;
    GalleryView *drawBuffer;
    s16 fadeState;
    s32 brightness;

    while (g_gallery_modes[g_gallery->mode]() != 0) {
    }

    if (g_gallery == 0) {
        return;
    }

    if (g_gallery->drawEnabled != 0) {
        gallery_draw_background(0x80);
        if (g_gallery->overlayEnabled != 0) {
            gallery_draw_grid_and_ui();
            overlayAdjustment = g_gallery->overlayAdjustment;
            if (overlayAdjustment != 0) {
                gallery_draw_background((u8)(0x80 - ((s16)overlayAdjustment)));
            }
        }
        if ((g_gallery->bufferPending != 0) && (viewer_update_and_draw(&g_gallery->sprites[g_gallery->activeBuffer ^ 1], 0) != 0)) {
            g_gallery->bufferPending = 0;
        }
        drawBuffer = g_gallery->curSprite;
        if (drawBuffer != 0) {
            viewer_update_and_draw(drawBuffer, 0);
        }
        drawBuffer = g_gallery->prevSprite;
        if (drawBuffer != 0) {
            viewer_update_and_draw(drawBuffer, 1);
        }
    }

    fadeState = g_gallery->fadeState;
    if (fadeState == 0) {
        brightness = 0xFF - ((g_gallery->timer * 8 > 0xFF) ? 0xFF : g_gallery->timer * 8);
        gallery_draw_solid_rect(0, 0, 640, 448, brightness, brightness, brightness, 0x80, 2);
    } else if (fadeState > 8) {
        brightness = (g_gallery->timer * 8 > 0xFF) ? 0xFF : g_gallery->timer * 8;
        gallery_draw_solid_rect(0, 0, 640, 448, brightness, brightness, brightness, 0x80, 2);
    }
}

s32 gallery_state_exit(void)
{
    s32 byteIndex;

    if (g_gallery->state == 0) {
        for (byteIndex = 0; byteIndex < sizeof(g_image_viewed_flags); byteIndex++) {
            g_image_viewed_flags[byteIndex] = 0;
        }

        g_gallery->fadeState = 9;
        g_gallery->timer = 0;
        g_gallery->state++;
    }

    if (g_gallery->timer < 32) {
        g_gallery->timer++;
        return 0;
    }

    g_gallery->exitRequested = 1;
    return 0;
}

s32 gallery_state_viewer(void)
{
    switch (g_gallery->state) {
    case 0:
        g_selected_image_idx = g_gallery->pageOffset + g_gallery->menu.selection;
        g_gallery->overlayEnabled = 0;
        g_gallery->curSprite = 0;
        g_gallery->prevSprite = 0;
        g_gallery->state++;

    case 1: {
        s32 fileId = g_gallery->itemThumbIds[g_selected_image_idx];
        if (fileId > 0x25) {
            fileId = 0;
        }
        g_gallery->currentThumbId = fileId;
        g_gallery->currentThumbId += 3;
        g_cd_async_busy = 1;
        g_cd_async_state = 0;
        g_gallery->state++;
    }

    case 2: {
        s32 fileId = g_gallery->currentThumbId;
        s32 offset = g_archive_toc[fileId + 1];
        s32 size = g_archive_toc[fileId + 2] - offset;
        if (offset != 0) {
            offset /= 0x800;
        }
        offset += g_gallery_archive[0].entryLocation;
        cd_read_async(g_gallery->readBuf, size, offset);
        if (g_cd_async_busy == 0) {
            g_gallery->state++;
        }
        break;
    }

    case 3: {
        u8 *buf = g_gallery->readBuf;
        s32 fileId = g_gallery->currentThumbId;
        s32 size = g_archive_toc[fileId + 2] - g_archive_toc[fileId + 1];
        s32 prev = buf[4];
        s32 i;
        for (i = 5; i < (size - 5); i++) {
            s32 cur = buf[i];
            buf[i] = cur - prev;
            prev = cur;
        }

        g_gallery->stepState = 0;
        g_gallery->state++;
        break;
    }

    case 4:
        if (lzss_decompress_step(g_gallery->decodeBuf, g_gallery->readBuf) != 0) {
            g_gallery->stepState = 0;
            g_gallery->state++;
        }
        break;

    case 5: {
        s32 slot = g_gallery->activeBuffer;
        if (bmp_upload_texture(&g_gallery->viewerTextures[slot], (slot * 0x1000) + 0x1788, (slot * 4) + 0x3788, g_gallery->decodeBuf, 0, 0) != 0) {
            g_gallery->state = 10;
        }
        break;
    }

    case 10:
        g_gallery->curSprite = &g_gallery->sprites[g_gallery->activeBuffer];
        g_gallery->prevSprite = g_gallery->curSprite;
        viewer_init_image(g_gallery->curSprite, &g_gallery->viewerTextures[g_gallery->activeBuffer], 0);
        if (g_gallery->isInitialized != 2) {
            g_gallery->curSprite->menuBox.alpha = 0;
        }
        g_gallery->state++;

    case 11: {
        s32 action = viewer_update_and_draw(g_gallery->curSprite, 2);
        if (action == 3) {
            g_gallery->curSprite = 0;
            g_gallery->prevSprite = 0;
            g_gallery->mode = GALLERY_MODE_GRID;
            g_gallery->state = 0;
        } else if (action != 0) {
            do {
                if (action == 1) {
                    g_selected_image_idx++;
                } else {
                    g_selected_image_idx += g_gallery->itemCount - 1;
                }
                g_selected_image_idx %= g_gallery->itemCount;
                if (g_selected_image_idx != 0) {
                    g_gallery->pageOffset = (g_selected_image_idx / 6) * 6;
                } else {
                    g_gallery->pageOffset = 0;
                }
                g_gallery->menu.selection = g_selected_image_idx % 6;
            } while (g_gallery->itemStatus[g_selected_image_idx] != 2);
            g_gallery->curSprite->state = 2;
            g_gallery->curSprite->timer = 0x80;
            g_gallery->bufferPending = 1;
            g_gallery->isInitialized = 2;
            g_gallery->activeBuffer ^= 1;
            g_gallery->curSprite = 0;
            g_gallery->state = 1;
        }
        break;
    }

    case 200:
        if (g_pads[2].trigger & SCE_PADRright) {
            g_gallery->mode = GALLERY_MODE_GRID;
            g_gallery->state = 0;
        }
        break;
    }

    return 0;
}

s32 gallery_state_grid(void)
{
    SpriteInfo atlasSprite;
    s32 thumbnailIndex;
    s32 previousCursor;
    s32 menuResult;

    switch (g_gallery->state) {
    case 0:
        g_gallery->isInitialized = 0;
        g_gallery->state = 3;

    case 3:
        g_gallery->stepState = 0;
        while (!bmp_upload_texture(&atlasSprite, 0x1788, 0x2788, g_gallery->textureBuffer, 0, 0)) {
        }

        for (thumbnailIndex = 0; thumbnailIndex < 37; thumbnailIndex++) {
            SpriteInfo *sprite = &g_gallery->allSprites[thumbnailIndex];
            *sprite = atlasSprite;
            sprite->tex0 = (sprite->tex0 & (~(((u64)0x3FFF) << 37))) | (getTex0Cbp(atlasSprite.tex0) << 37);
            sprite->u += (s16)((thumbnailIndex & 7) * 128);
            sprite->v += (s16)((thumbnailIndex >> 3) * 90);
            sprite->w = 128;
            sprite->h = 90;
        }

        g_gallery->timer = 0;
        g_gallery->overlayEnabled = 1;
        g_gallery->scrollX = 0x38;
        g_gallery->idleTimer = 0;
        for (g_gallery->slotIndex = 0; g_gallery->slotIndex < 6; g_gallery->slotIndex++) {
            s32 itemIndex = g_gallery->pageOffset + g_gallery->slotIndex;
            s32 thumbnailId;
            if (itemIndex >= g_gallery->itemCount) {
                break;
            }
            thumbnailId = g_gallery->itemThumbIds[itemIndex];
            if (thumbnailId > 37) {
                thumbnailId = 0;
            }
            g_gallery->currentThumbId = thumbnailId;
            g_gallery->pageSprites[g_gallery->slotIndex] = g_gallery->allSprites[g_gallery->currentThumbId];
            if (g_image_viewed_flags[g_gallery->currentThumbId] != 0) {
                g_gallery->slotFlags[g_gallery->slotIndex] = 4;
            } else {
                g_gallery->slotFlags[g_gallery->slotIndex] = 1;
            }
        }

        if (g_gallery->isInitialized == 0) {
            g_gallery->state = 10;
            return 1;
        }
        g_gallery->state = 19;
        break;

    case 10:
        g_gallery->overlayAdjustment = 0;
        g_gallery->state++;

    case 11:
        g_gallery->overlayAdjustment += 4;
        if (g_gallery->overlayAdjustment >= 0x80) {
            g_gallery->isInitialized = 1;
            g_gallery->overlayAdjustment = 0;
            g_gallery->state = 19;
        }
        break;

    case 19:
        g_gallery->idleTimer = 0;
        g_gallery->fadeState = 1;
        g_gallery->subState = 0;
        g_gallery->state++;

    case 20:
        previousCursor = g_gallery->menu.selection;
        menuResult = viewer_update_grid_cursor(&g_gallery->menu, &g_pads[2]);
        if (menuResult != 0) {
            if (menuResult < 0x100) {
                int directionButtons;
                g_gallery->idleTimer = 0;
                if (g_gallery->itemCount <= 6) {
                    break;
                }
                directionButtons = g_pads[2].buttons;
                if ((directionButtons & SCE_PADLleft) && ((previousCursor == 0) || (previousCursor == 3))) {
                    g_gallery->menu.selection = previousCursor + 2;
                    g_gallery->scrollDirection = -1;
                    g_gallery->pageOffset -= 6;
                    if (g_gallery->pageOffset < 0) {
                        g_gallery->pageOffset = ((g_gallery->itemCount - 1) / 6) * 6;
                    }
                    g_gallery->state = 29;
                    return 1;
                }
                if ((directionButtons & SCE_PADLright) && ((previousCursor == 2) || (previousCursor == 5))) {
                    g_gallery->menu.selection = previousCursor - 2;
                    g_gallery->scrollDirection = 1;
                    g_gallery->pageOffset += 6;
                    if (g_gallery->pageOffset >= g_gallery->itemCount) {
                        g_gallery->pageOffset = 0;
                    }
                    g_gallery->state = 29;
                    return 1;
                }
                sound_play_cursor_se();
            } else {
                s32 itemIndex = g_gallery->menu.selection + g_gallery->pageOffset;
                if ((itemIndex < g_gallery->itemCount) && (g_gallery->itemStatus[itemIndex] == 2)) {
                    sound_play_confirm_se();
                    g_gallery->exitMode = GALLERY_MODE_VIEWER;
                    g_gallery->state = 100;
                }
            }
        } else {
            u32 buttons = g_pads[2].trigger;
            if (buttons & SCE_PADRdown) {
                sound_play_confirm_se();
                g_gallery->state = 40;
                break;
            } else if (buttons & SCE_PADL1) {
                if (g_gallery->itemCount <= 6) {
                    break;
                }
                g_gallery->scrollDirection = -1;
                g_gallery->pageOffset -= 6;
                if (g_gallery->pageOffset < 0) {
                    g_gallery->pageOffset = ((g_gallery->itemCount - 1) / 6) * 6;
                }
                g_gallery->state = 29;
                return 1;
            } else if (buttons & SCE_PADR1) {
                if (g_gallery->itemCount <= 6) {
                    break;
                }
                g_gallery->scrollDirection = 1;
                g_gallery->pageOffset += 6;
                if (g_gallery->pageOffset >= g_gallery->itemCount) {
                    g_gallery->pageOffset = 0;
                }
                g_gallery->state = 29;
                return 1;
            }
        }
        g_gallery->timer++;
        break;

    case 29:
        g_gallery->timer = 0;
        g_gallery->idleTimer = 0;
        sound_play_page_se();
        g_gallery->fadeState = 2;
        g_gallery->countdown = 0x20;
        g_gallery->state = 30;

    case 30:
        g_gallery->timer++;
        g_gallery->scrollX -= (s16)(g_gallery->timer * g_gallery->scrollDirection);
        if ((--g_gallery->countdown) == 0) {
            g_gallery->state = 3;
        }
        break;

    case 40:
        g_gallery->dialogState = 1;
        g_gallery->fadeState = 2;
        g_gallery->countdown = 0x10;
        g_gallery->dialogChoice = 1;
        viewer_draw_yes_no_dialog(-1, 0, 0, 0);
        g_gallery->state++;

    case 41:
        if (g_pads[2].trigger & SCE_PADLleft) {
            if (menuResult = g_gallery->dialogChoice != 0) {
                sound_play_cursor_se();
            }
            g_gallery->dialogChoice = 0;
        }
        if (g_pads[2].trigger & SCE_PADLright) {
            if (g_gallery->dialogChoice != 1) {
                sound_play_cursor_se();
            }
            g_gallery->dialogChoice = 1;
        }
        if (g_pads[2].trigger & SCE_PADRright) {
            sound_play_confirm_se();
            if (g_gallery->dialogChoice == 0) {
                g_gallery->dialogState = -1;
                g_gallery->state = 100;
                g_gallery->exitMode = GALLERY_MODE_EXIT;
            } else {
                g_gallery->dialogState = 0;
                g_gallery->fadeState = 1;
                g_gallery->state = 20;
            }
        }
        if (g_pads[2].trigger & SCE_PADRdown) {
            sound_play_confirm_se();
            g_gallery->dialogState = 0;
            g_gallery->fadeState = 1;
            g_gallery->state = 20;
        }
        break;

    case 100:
        g_gallery->overlayAdjustment = 0x80;
        g_gallery->state++;

    case 101:
        g_gallery->overlayAdjustment -= 4;
        if (g_gallery->overlayAdjustment <= 0) {
            g_gallery->overlayEnabled = 0;
            g_gallery->mode = g_gallery->exitMode;
            g_gallery->state = 0;
        }
        break;
    }

    return 0;
}

s32 gallery_state_fade_in(void)
{
    if (g_gallery->state == 0) {
        g_gallery->fadeState = 0;
        g_gallery->timer = 0;
        g_gallery->state++;
    }

    if (++g_gallery->timer < 32) {
        return 0;
    }

    g_gallery->fadeState = 1;
    g_gallery->mode = GALLERY_MODE_GRID;
    g_gallery->state = 0;
    return 0;
}

s32 gallery_state_loading(void)
{
    sceGifPacket pkt;
    u32 i;
    s32 idx;
    s32 count;
    GalleryMenuState *menu;

    switch (g_gallery->state) {
    case 0:
        g_gallery->drawEnabled = 0;
        g_gallery->fadeState = 0;
        g_gallery->timer = 0;
        g_gallery->state++;
    case 1:
        tex_upload_step();
        if (g_cd_async_busy == 0) {
            g_gallery->state++;
        }
        break;
    case 2:
        if (gallery_load_ui_assets() != 0) {
            g_gallery->state++;
        }
        break;
    case 3:
        g_gallery->fadeState = 9;
        g_gallery->timer = 0;
        g_gallery->state++;
    case 4:
        if (g_gallery->timer >= 0x20) {
            g_gallery->fadeState = 0;
            g_gallery->timer = 0;
            g_gallery->state++;
        }
        break;
    case 5:
        g_gallery->state++;
        break;
    case 6:
        g_gallery->gridBox.x0 = 0x38;
        g_gallery->gridBox.x1 = 0x248;
        g_gallery->gridBox.y0 = 0x50;
        g_gallery->gridBox.y1 = 0x130;
        g_gallery->gridBox.r = 0x80;
        g_gallery->gridBox.g = 0x18;
        g_gallery->gridBox.b = 0x80;
        g_gallery->gridBox.a = 0x33;
        g_gallery->overlayEnabled = 0;
        g_gallery->cursorBox.r = 0x18;
        g_gallery->cursorBox.g = 0xFF;
        g_gallery->cursorBox.b = 0x30;
        g_gallery->cursorBox.a = 0x33;
        g_gallery->cursorBox.alpha = 0x80;

        menu = &g_gallery->menu;
        menu->selection = 0;
        menu->selectionCount = 6;
        menu->movementSteps[0] = -3;
        menu->movementSteps[1] = 3;
        menu->movementSteps[2] = -1;
        menu->movementSteps[3] = 1;
        menu->movementSteps[4] = 0;
        menu->actionEnabled[0] = 0;
        menu->actionEnabled[1] = 0;
        menu->actionEnabled[2] = 1;
        menu->actionEnabled[3] = 0;
        menu->actionEnabled[4] = 0;

        g_gallery->slotFlags[0] = 0;
        g_gallery->slotFlags[1] = 0;
        g_gallery->slotFlags[2] = 0;
        g_gallery->slotFlags[3] = 0;
        g_gallery->slotFlags[4] = 0;
        g_gallery->slotFlags[5] = 0;

        count = 0;
        for (idx = 0; idx < 0x100; idx++) {
            if (g_image_unlock_flags[idx] != 0) {
                count++;
            }
        }

        g_gallery->drawEnabled = 1;
        g_gallery->itemCount = count;
        g_gallery->pageOffset = 0;
        g_gallery->mode = GALLERY_MODE_FADE_IN;
        g_gallery->state = 0;
        break;
    }

    if (g_gallery->state < 5) {
        gallery_draw_solid_rect(0, 0, 0x280, 0x1C0, 0, 0, 0, 0x80, 0);
        sceGifPkInit(&pkt, g_gif_buf);
        sceGifPkReset(&pkt);
        sceGifPkAddGsData(&pkt, SCE_GIF_SET_TAG(2, 1, 0, 0, SCE_GIF_PACKED, 1));
        sceGifPkAddGsData(&pkt, SCE_GIF_PACKED_AD);
        sceGifPkAddGsData(&pkt, SCE_GS_SET_TEX0(0x1E40, 16, SCE_GS_PSMT4, 10, 10, 1, 0, 0x3830, SCE_GS_PSMCT16, 0, 0, 1));
        sceGifPkAddGsData(&pkt, SCE_GS_TEX0_1);
        sceGifPkAddGsData(&pkt, 0);
        sceGifPkAddGsData(&pkt, SCE_GS_TEX1_1);

        for (i = 0; i < 11; i++) {
            bmp_draw_ascii_char(&pkt, 0x180 + i * 16, 0x1A0, g_now_loading_text[i]);
        }

        for (i = 0; i < ((g_frame_count & 0x7F) >> 5); i++) {
            bmp_draw_ascii_char(&pkt, 0x180 + (i + 11) * 16, 0x1A0, '.');
        }

        sceGifPkTerminate(&pkt);
        FlushCache(0);
        sceDmaSendN(g_dma_gif, g_gif_buf, sceGifPkSize(&pkt));
        sceGsSyncPath(0, 0);

        if (g_gallery->timer < 0x20) {
            g_gallery->timer++;
        }
    }

    return 0;
}

s32 gallery_load_ui_assets(void)
{
    s32 iter[2];
    s32 size;
    s32 offset;
    u8 *buf;
    u32 k;

    switch (g_gallery->subState) {
    case 0:
        g_cd_async_busy = 1;
        g_cd_async_state = 0;
        g_gallery->subState++;

    case 1:
        offset = g_archive_toc[1];
        buf = g_gallery->readBuf;
        size = g_archive_toc[2] - offset;
        if (offset != 0) {
            offset /= 0x800;
        }
        offset += g_gallery_archive[0].entryLocation;
        cd_read_async(buf, size, offset);
        if (g_cd_async_busy == 0) {
            g_gallery->subState++;
        }
        break;

    case 2: {
        u8 *buf = g_gallery->readBuf;
        s32 size = g_archive_toc[2] - g_archive_toc[1];
        s32 prev = buf[4];
        s32 i;
        for (iter[1] = 5; iter[1] < (size - 5); iter[1]++) {
            s32 cur = buf[iter[1]];
            buf[iter[1]] = cur - prev;
            prev = cur;
        }

        g_gallery->stepState = 0;
        g_gallery->subState++;
        break;
    }

    case 3:
        if (lzss_decompress_step(g_gallery->decodeBuf, g_gallery->readBuf) != 0) {
            g_gallery->stepState = 0;
            g_gallery->subState++;
        }
        break;

    case 4:
        if (bmp_upload_texture(&g_gallery->bgSprite, 0x1180, 0x1780, g_gallery->decodeBuf, 0, 0) != 0) {
            g_gallery->subState = 10;
        }
        break;

    case 10:
        g_cd_async_state = 0;
        g_cd_async_busy = 1;
        g_gallery->subState++;

    case 11:
        offset = g_archive_toc[2];
        buf = g_gallery->readBuf;
        size = g_archive_toc[3] - offset;
        if (offset != 0) {
            offset /= 0x800;
        }
        offset += g_gallery_archive[0].entryLocation;
        cd_read_async(buf, size, offset);
        if (g_cd_async_busy == 0) {
            g_gallery->subState++;
        }
        break;

    case 12: {
        u8 *buf = g_gallery->readBuf;
        s32 size = g_archive_toc[3] - g_archive_toc[2];
        s32 prev = buf[4];
        s32 i;
        for (iter[1] = 5; iter[1] < (size - 5); iter[1]++) {
            s32 cur = buf[iter[1]];
            buf[iter[1]] = cur - prev;
            prev = cur;
        }

        g_gallery->stepState = 0;
        g_gallery->subState++;
        break;
    }

    case 13:
        if (lzss_decompress_step(g_gallery->decodeBuf, g_gallery->readBuf) != 0) {
            g_gallery->stepState = 0;
            g_gallery->subState++;
        }
        break;

    case 14:
        if (bmp_upload_texture(&g_gallery->uiAtlasSprite, 0x1380, 0x1784, g_gallery->decodeBuf, 0, 0) != 0) {
            g_gallery->subState = 20;
        }
        break;

    case 20:
        g_cd_async_state = 0;
        g_cd_async_busy = 1;
        g_gallery->subState++;

    case 21:
        offset = g_archive_toc[3];
        buf = g_gallery->readBuf;
        size = g_archive_toc[4] - offset;
        if (offset != 0) {
            offset /= 0x800;
        }
        offset += g_gallery_archive[0].entryLocation;
        cd_read_async(buf, size, offset);
        if (g_cd_async_busy == 0) {
            g_gallery->subState++;
        }
        break;

    case 22: {
        u8 *buf = g_gallery->readBuf;
        s32 size = g_archive_toc[4] - g_archive_toc[3];
        s32 prev = buf[4];
        s32 i;
        for (iter[1] = 5; iter[1] < (size - 5); iter[1]++) {
            s32 cur = buf[iter[1]];
            buf[iter[1]] = cur - prev;
            prev = cur;
        }

        g_gallery->stepState = 0;
        g_gallery->subState++;
        break;
    }

    case 23:
        if (lzss_decompress_step(g_gallery->textureBuffer, g_gallery->readBuf) != 0) {
            g_gallery->subState = 30;
        }
        break;

    case 30: {
        for (k = 0; k < 6; k++) {
            SpriteInfo *src = &g_gallery->uiAtlasSprite;
            s16 h = g_ui_sprite_uvs[k].h;
            s16 w = g_ui_sprite_uvs[k].w;
            s16 v = g_ui_sprite_uvs[k].v;
            s16 u = g_ui_sprite_uvs[k].u;
            SpriteInfo *dst = &g_gallery->uiSprites[k];
            *dst = *src;
            dst->tex0 = (dst->tex0 & (~(((u64)0x3FFF) << 37))) | (getTex0Cbp(src->tex0) << 37);
            dst->u += u;
            dst->v += v;
            dst->w = w;
            dst->h = h;
        }

        for (iter[1] = 0; ((u32)iter[1]) < 6; iter[1]++) {
            iter[0] = g_ui_sprite_rects[iter[1]].u;
            g_gallery->uiX0[iter[1]] = iter[0];
            g_gallery->uiY0[iter[1]] = g_ui_sprite_rects[iter[1]].v;
            g_gallery->uiX1[iter[1]] = g_ui_sprite_rects[iter[1]].w;
            g_gallery->uiY1[iter[1]] = g_ui_sprite_rects[iter[1]].h;
        }

        g_gallery->uiMode[4] = 2;
        g_gallery->uiMode[5] = 2;
        return 1;
    }
    }

    return 0;
}

void gallery_draw_background(u8 alpha)
{
    sceGifPacket packet;

    sceGifPkInit(&packet, g_gif_buf);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(3, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, g_gallery->bgSprite.tex0);
    sceGifPkAddGsData(&packet, SCE_GS_TEX0_1);
    sceGifPkAddGsData(&packet, SCE_GS_SET_TEX1(0, 0, 1, 1, 0, 0, 0));
    sceGifPkAddGsData(&packet, SCE_GS_TEX1_1);
    sceGifPkAddGsData(&packet, SCE_GS_SET_ALPHA(0, 1, 0, 1, 0));
    sceGifPkAddGsData(&packet, SCE_GS_ALPHA_1);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 6));
    sceGifPkAddGsData(&packet, 0x535310ULL);

    if (alpha == 0x80) {
        sceGifPkAddGsData(&packet, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 0, 0, 1, 0, 0));
    } else {
        sceGifPkAddGsData(&packet, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 1, 0, 1, 0, 0));
    }

    sceGifPkAddGsData(&packet, SCE_GS_SET_RGBAQ(0x80, 0x80, 0x80, alpha, 0x3F800000));
    sceGifPkAddGsData(&packet, SCE_GS_SET_UV(0, 0));
    sceGifPkAddGsData(&packet, SCE_GS_SET_XYZ2(0x6C00, 0x7900, 0));
    sceGifPkAddGsData(&packet, SCE_GS_SET_UV(512 << 4, 448 << 4));
    sceGifPkAddGsData(&packet, SCE_GS_SET_XYZ2((640 << 4) + 0x6C00, (448 << 3) + 0x7900, 0));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, g_gif_buf, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

void gallery_draw_grid_and_ui(void)
{
    sceGifPacket pkt;
    SpriteInfo *tex;
    s32 i;
    s32 col;
    s32 row;
    s32 idx;
    s32 mode;

    sceGifPkInit(&pkt, g_gif_buf);
    sceGifPkReset(&pkt);

    sceGifPkAddGsData(&pkt, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&pkt, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&pkt, SCE_GS_SET_TEX1(0, 0, 1, 1, 0, 0, 0));
    sceGifPkAddGsData(&pkt, SCE_GS_TEX1_1);

    for (i = 0; i < 6; i++) {
        tex = &g_gallery->uiSprites[i];

        sceGifPkAddGsData(&pkt, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
        sceGifPkAddGsData(&pkt, SCE_GIF_PACKED_AD);
        sceGifPkAddGsData(&pkt, tex->tex0);
        sceGifPkAddGsData(&pkt, SCE_GS_TEX0_1);

        sceGifPkAddGsData(&pkt, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 6));
        sceGifPkAddGsData(&pkt, 0x535310ULL);
        sceGifPkAddGsData(&pkt, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 0, 0, 1, 0, 0));

        if (g_gallery->uiMode[i] == 1) {
            u8 color = ((g_frame_count & 1) << 6) + 0x40;
            sceGifPkAddGsData(&pkt, SCE_GS_SET_RGBAQ(color, color, color, color, 0x3F800000));
        } else if (g_gallery->uiMode[i] == 2) {
            if (g_gallery->itemCount <= 6) {
                sceGifPkAddGsData(&pkt, SCE_GS_SET_RGBAQ(0, 0, 0, 0, 0x3F800000));
            } else {
                u8 pulse = (u8)(127.0f * sinf((3.1415927f * (f32)(g_frame_count & 0x3F)) / 64.0f));
                sceGifPkAddGsData(&pkt, SCE_GS_SET_RGBAQ(0x80, pulse, pulse, 0x80, 0x3F800000));
            }
        } else {
            sceGifPkAddGsData(&pkt, SCE_GS_SET_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000));
        }

        sceGifPkAddGsData(&pkt, SCE_GS_SET_UV(tex->u << 4, tex->v << 4));
        sceGifPkAddGsData(&pkt, SCE_GS_SET_XYZ2((g_gallery->uiX0[i] << 4) + 0x6C00, (g_gallery->uiY0[i] << 3) + 0x7900, 0));
        sceGifPkAddGsData(&pkt, SCE_GS_SET_UV((tex->u + tex->w) << 4, (tex->v + tex->h) << 4));
        sceGifPkAddGsData(&pkt, SCE_GS_SET_XYZ2((g_gallery->uiX1[i] << 4) + 0x6C00, (g_gallery->uiY1[i] << 3) + 0x7900, 0));
    }

    sceGifPkAddGsData(&pkt, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&pkt, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&pkt, 0ULL);
    sceGifPkAddGsData(&pkt, SCE_GS_TEX1_1);

    if ((g_gallery->timer & 0x20) == 0) {
        g_thumb_pulse = g_gallery->timer & 0x1F;
        if (g_thumb_pulse >= 0x10) {
            g_thumb_pulse = 0x1F - g_thumb_pulse;
        }
    }

    idx = 0;
    for (row = 0; row < 2; row++) {
        for (col = 0; col < 3; col++) {
            tex = &g_gallery->pageSprites[idx];

            if (idx >= g_gallery->slotIndex) {
                break;
            }

            sceGifPkAddGsData(&pkt, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
            sceGifPkAddGsData(&pkt, SCE_GIF_PACKED_AD);
            sceGifPkAddGsData(&pkt, tex->tex0);
            sceGifPkAddGsData(&pkt, SCE_GS_TEX0_1);

            sceGifPkAddGsData(&pkt, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 6));
            sceGifPkAddGsData(&pkt, 0x535310ULL);

            mode = g_gallery->slotFlags[idx];
            if (g_gallery->fadeState == 0 || g_gallery->fadeState == 2) {
                mode = g_gallery->fadeState;
            }

            switch (mode) {
            default:
                sceGifPkAddGsData(&pkt, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 0, 0, 1, 0, 0));
                sceGifPkAddGsData(&pkt, SCE_GS_SET_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000));
                break;
            case 0:
            case 2:
                sceGifPkAddGsData(&pkt, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 1, 0, 1, 0, 0));
                sceGifPkAddGsData(&pkt, SCE_GS_SET_RGBAQ(0x80, 0x80, 0x80, g_gallery->countdown << 2, 0x3F800000));
                break;
            case 4: {
                s32 bright = (g_thumb_pulse << 2) + 0x80;
                sceGifPkAddGsData(&pkt, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 1, 0, 1, 0, 0));
                sceGifPkAddGsData(&pkt, SCE_GS_SET_RGBAQ(bright, bright, bright, 0x80, 0x3F800000));
                break;
            }
            }

            sceGifPkAddGsData(&pkt, SCE_GS_SET_UV(tex->u << 4, tex->v << 4));
            sceGifPkAddGsData(
                &pkt,
                SCE_GS_SET_XYZ2(
                    ((g_gallery->scrollX + 0x38 + col * 0x90) << 4) + 0x6C00,
                    ((row * 0x6A + 0x5E) << 3) + 0x7900,
                    0
                )
            );
            sceGifPkAddGsData(&pkt, SCE_GS_SET_UV((tex->u + tex->w - 1) << 4, (tex->v + tex->h) << 4));
            sceGifPkAddGsData(
                &pkt,
                SCE_GS_SET_XYZ2(
                    ((tex->w + (g_gallery->scrollX + 0x38 + col * 0x90)) << 4) + 0x6C00,
                    ((tex->h + (row * 0x6A + 0x5E)) << 3) + 0x7900,
                    0
                )
            );
            idx++;
        }
    }

    sceGifPkAddGsData(&pkt, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&pkt, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&pkt, SCE_GS_SET_TEX1(0, 0, 1, 1, 0, 0, 0));
    sceGifPkAddGsData(&pkt, SCE_GS_TEX1_1);

    if (g_gallery->fadeState == 1) {
        if ((g_gallery->timer & 0x40) == 0) {
            g_cursor_pulse = g_gallery->timer & 0x3F;
            if (g_cursor_pulse >= 0x20) {
                g_cursor_pulse = 0x3F - g_cursor_pulse;
            }
        }

        sceGifPkAddGsData(&pkt, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
        sceGifPkAddGsData(&pkt, SCE_GIF_PACKED_AD);
        sceGifPkAddGsData(&pkt, SCE_GS_SET_ALPHA(0, 2, 0, 1, 0));
        sceGifPkAddGsData(&pkt, SCE_GS_ALPHA_1);

        sceGifPkAddGsData(&pkt, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 4));
        sceGifPkAddGsData(&pkt, 0x5510ULL);
        sceGifPkAddGsData(&pkt, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 0, 0, 1, 0, 1, 0, 0));
        sceGifPkAddGsData(&pkt, SCE_GS_SET_RGBAQ(0xC0, 0xC0, 0xC0, 0x60 - g_cursor_pulse * 2, 0x3F800000));
        sceGifPkAddGsData(
            &pkt,
            SCE_GS_SET_XYZ2(
                (((g_gallery->menu.selection % 3) * 0x90 + 0x70) << 4) + 0x6C00,
                (((g_gallery->menu.selection / 3) * 0x6A + 0x5E) << 3) + 0x7900,
                0
            )
        );
        sceGifPkAddGsData(
            &pkt,
            SCE_GS_SET_XYZ2(
                (((g_gallery->menu.selection % 3) * 0x90 + 0xF0) << 4) + 0x6C00,
                (((g_gallery->menu.selection / 3) * 0x6A + 0xB8) << 3) + 0x7900,
                0
            )
        );
    }

    sceGifPkTerminate(&pkt);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, g_gif_buf, sceGifPkSize(&pkt));
    sceGsSyncPath(0, 0);

    switch (g_gallery->dialogState) {
    case 0:
        sprite_clear_queue();
        for (i = 0; i < 2; i++) {
            sprite_queue_sjis_text(
                (s16)(g_gallery->uiX0[2] - 0x20),
                g_gallery->uiY0[2] + 0x13 + i * 0x18,
                g_grid_help_lines[i],
                0,
                0x18,
                0x18,
                0x80,
                0
            );
        }
        sprite_flush_rects();
        break;
    case 1:
        sprite_clear_queue();
        sprite_queue_sjis_text(
            (s16)(g_gallery->uiX0[2] - 0x20),
            g_gallery->uiY0[2] + 0x13,
            g_exit_prompt_lines[0],
            0,
            0x18,
            0x18,
            0x80,
            0
        );
        sprite_flush_rects();
        viewer_draw_yes_no_dialog(g_gallery->dialogChoice, 0x140, g_gallery->uiY0[2] + 0x33, 0x40);
        break;
    }
}

GalleryArchiveEntry g_gallery_archive[1] __attribute__((aligned(8)));
u32 g_frame_count;
s32 g_selected_image_idx;
s32 g_cursor_pulse;
s32 g_thumb_pulse;

s8 g_image_unlock_flags[0x100];
s8 g_image_viewed_flags[256];
s32 g_archive_toc[0x200];
