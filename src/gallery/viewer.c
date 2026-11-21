#include "gallery/gallery.h"

typedef struct {
    s32 selection;
    s32 selectionCount;
    s32 movementSteps[5];
    s32 actionEnabled[5];
    s32 heldFrames;
} GalleryMenuState;

typedef struct {
    u8 reserved[0x20];
    u32 heldButtons;
    u32 pressedButtons;
} GalleryMenuInput;

static const char g_dialog_yes[8] = SJIS("はい");
static const char g_dialog_slash[8] = SJIS("／");
static const char g_dialog_no[8] = SJIS("いいえ");
extern s32 g_dialog_selection;
extern s32 g_dialog_anim_step;

void viewer_draw_yes_no_dialog(s32 selection, s32 centerX, s32 y, s32 spacing)
{
    s32 highlightOffset;
    s32 glyphSize;

    if (selection < 0) {
        if (selection == -1) {
            g_dialog_selection = 1;
        } else {
            g_dialog_selection = 0;
        }
        g_dialog_anim_step = 4;
        return;
    }

    if (g_dialog_selection != selection) {
        g_dialog_selection = selection;
        g_dialog_anim_step = 0;
    }

    if (g_dialog_anim_step < 4) {
        g_dialog_anim_step += 2;
    }

    highlightOffset = 0;
    if (g_dialog_anim_step != 0) {
        highlightOffset = g_dialog_anim_step / 2;
    }
    glyphSize = g_dialog_anim_step + 24;

    sprite_clear_queue();

    if (g_dialog_selection == 0) {
        sprite_queue_sjis_text((s16)(centerX - spacing - 100 - highlightOffset),
                      (s16)(y - highlightOffset), g_dialog_yes, 4,
                      (u16)glyphSize, (u16)glyphSize, 128, 0);
        sprite_queue_sjis_text((s16)(centerX - 88), (s16)y, g_dialog_slash, 0, 24, 24, 128, 0);
        sprite_queue_sjis_text((s16)(centerX + spacing - 100), (s16)y,
                      g_dialog_no, 0, 24, 24, 128, 0);
    } else {
        sprite_queue_sjis_text((s16)(centerX - spacing - 100), (s16)y,
                      g_dialog_yes, 0, 24, 24, 128, 0);
        sprite_queue_sjis_text((s16)(centerX - 88), (s16)y, g_dialog_slash, 0, 24, 24, 128, 0);
        sprite_queue_sjis_text((s16)(centerX + spacing - 100 - highlightOffset),
                      (s16)(y - highlightOffset), g_dialog_no, 4,
                      (u16)glyphSize, (u16)glyphSize, 128, 0);
    }

    sprite_flush_rects();
}

s32 viewer_update_and_draw(GalleryView *view, s32 mode)
{
    sceGifPacket pkt;
    s32 ret;
    s32 alpha;
    s32 drawX;
    s32 drawY;
    s32 drawW;
    s32 drawH;
    s32 u;
    s32 v;
    s32 texW;
    s32 texH;
    s32 scale;
    s32 offX;
    s32 offY;
    s32 i;
    s32 bright;

    ret = 0;

    switch (mode) {
    case 2:
        if (view->state != 0) {
            break;
        }
        if (view->flags[0] && (g_pads[2].trigger & SCE_PADR1)) {
            sound_play_page_se();
            ret = 1;
        }
        if (view->flags[1] && (g_pads[2].trigger & SCE_PADL1)) {
            sound_play_page_se();
            ret = 2;
        }
        if (view->flags[4] && (g_pads[2].trigger & SCE_PADRdown)) {
            sound_play_confirm_se();
            ret = 3;
        }
        if (view->flags[2]) {
            if (*(volatile u32 *)&g_pads[2].buttons & SCE_PADLright) {
                view->panX -= 4;
                if (view->panX < view->minX) {
                    view->panX = view->minX;
                }
            }
            if (*(volatile u32 *)&g_pads[2].buttons & SCE_PADLleft) {
                view->panX += 4;
                if (view->panX + 0x280 > view->maxX) {
                    view->panX = view->maxX - 0x280;
                }
            }
            if (*(volatile u32 *)&g_pads[2].buttons & SCE_PADLdown) {
                view->panY -= 4;
                if (view->panY < view->minY) {
                    view->panY = view->minY;
                }
            }
            if (*(volatile u32 *)&g_pads[2].buttons & SCE_PADLup) {
                view->panY += 4;
                if (view->panY + 0x1C0 > view->maxY) {
                    view->panY = view->maxY - 0x1C0;
                }
            }
        }
        if (view->flags[3] && (g_pads[2].trigger & SCE_PADRup)) {
            view->flags[2] ^= 1;
            view->zoomed ^= 1;
            view->state = 3;
            view->timer = 0x10;
            sound_play_confirm_se();
        }
        if (g_pads[2].trigger & SCE_PADstart) {
            g_gallery->showHelp ^= 1;
            view->flags[5] = g_gallery->showHelp;
            if (g_gallery->showHelp) {
                view->state = 4;
            } else {
                view->state = 5;
            }
            sound_play_confirm_se();
        }
        break;

    case 0:
        alpha = 0x80;
        u = view->tex->u;
        v = view->tex->v;
        texW = view->tex->w;
        texH = view->tex->h;

        if (view->state == 1) {
            alpha = 0x80 - view->timer;
            if (view->title != 0) {
                view->titleBox.x0 = (view->timer * 0x500) / 0x80 + 0x10;
                view->titleBox.x1 = view->titleBox.x0 + strlen(view->title) * 0x10;
            }
            if (view->flags[5] && view->menuBox.alpha < 0x80) {
                view->menuBox.alpha += 4;
            }
            view->timer--;
            if (view->timer <= 0) {
                view->state = 0;
                view->timer = 0;
            }
        }

        if (view->state == 2) {
            alpha = view->timer;
            view->timer--;
            if (view->timer <= 0) {
                view->timer = 0;
                ret = 1;
                view->state = 0;
            }
        }

        if (view->state == 3) {
            if (view->zoomed) {
                scale = ((0x10 - view->timer) * 0x1000 + view->baseScale * view->timer) / 0x10;
                offX = (view->panX * (0x10 - view->timer)) / 0x10;
                offY = (view->panY * (0x10 - view->timer)) / 0x10;
            } else {
                scale = (view->timer * 0x1000 + view->baseScale * (0x10 - view->timer)) / 0x10;
                offX = (view->panX * view->timer) / 0x10;
                offY = (view->panY * view->timer) / 0x10;
            }
            drawX = (offX + 0x140) - ((view->tex->w * scale) >> 13);
            drawY = (offY + 0xE0) - ((view->tex->h * scale) >> 13);
            drawW = (view->tex->w * scale) >> 12;
            drawH = (view->tex->h * scale) >> 12;
            if (--view->timer == 0) {
                view->state = 0;
            }
        } else {
            if (view->zoomed) {
                s32 scaledW = view->tex->w * 0x1000;
                s32 scaledH = view->tex->h * 0x1000;
                drawW = scaledW >> 12;
                drawX = (view->panX + 0x140) - ((view->tex->w * 0x1000) >> 13);
                drawH = scaledH >> 12;
                drawY = (view->panY + 0xE0) - ((view->tex->h * 0x1000) >> 13);
            } else {
                drawX = 0x140 - ((view->tex->w * view->baseScale) >> 13);
                drawY = 0xE0 - ((view->tex->h * view->baseScale) >> 13);
                drawW = (view->tex->w * view->baseScale) >> 12;
                drawH = (view->tex->h * view->baseScale) >> 12;
            }
        }

        sceGifPkInit(&pkt, g_gif_buf);
        sceGifPkReset(&pkt);
        sceGifPkAddGsData(&pkt, 0x1000000000008003ULL);
        sceGifPkAddGsData(&pkt, 0xEULL);
        sceGifPkAddGsData(&pkt, view->tex->tex0);
        sceGifPkAddGsData(&pkt, 0x6ULL);
        sceGifPkAddGsData(&pkt, 0ULL);
        sceGifPkAddGsData(&pkt, 0x14ULL);
        sceGifPkAddGsData(&pkt, 0x44ULL);
        sceGifPkAddGsData(&pkt, 0x42ULL);
        sceGifPkAddGsData(&pkt, 0x6400000000008001ULL);
        sceGifPkAddGsData(&pkt, 0x535310ULL);
        sceGifPkAddGsData(&pkt, 0x156ULL);
        sceGifPkAddGsData(&pkt, ((u64)alpha << 24) | 0x3F80000000808080ULL);
        sceGifPkAddGsData(&pkt, (u64)(u << 4) | ((u64)(v << 4) << 16));
        sceGifPkAddGsData(&pkt, (u64)((drawX << 4) + 0x6C00) | ((u64)((drawY << 3) + 0x7900) << 16));
        sceGifPkAddGsData(&pkt, (u64)((u + texW) << 4) | ((u64)((v + texH) << 4) << 16));
        sceGifPkAddGsData(&pkt, (u64)(((drawX + drawW) << 4) + 0x6C00) | ((u64)(((drawY + drawH) << 3) + 0x7900) << 16));
        sceGifPkTerminate(&pkt);
        FlushCache(0);
        sceDmaSendN(g_dma_gif, g_gif_buf, sceGifPkSize(&pkt));
        sceGsSyncPath(0, 0);

        if (view->title != 0) {
            gallery_draw_solid_rect(
                view->titleBox.x0,
                view->titleBox.y0,
                view->titleBox.x1,
                view->titleBox.y1,
                view->titleBox.r,
                view->titleBox.g,
                view->titleBox.b,
                (view->titleBox.a * view->titleBox.alpha) >> 7,
                0
            );
            sprite_clear_queue();
            sprite_queue_sjis_text(
                (s16)(view->titleBox.x0 - 0x38),
                view->titleBox.y0 + 4,
                view->title,
                0,
                0x18,
                0x18,
                0x80,
                0
            );
            sprite_flush_rects();
        }
        break;

    case 1:
        if (view->state == 4) {
            view->menuBox.alpha += 4;
            if (view->menuBox.alpha == 0x80) {
                view->state = 0;
            }
        }
        if (view->state == 5) {
            view->menuBox.alpha -= 4;
            if (view->menuBox.alpha == 0) {
                view->state = 0;
            }
        }

        sprite_clear_queue();
        gallery_draw_solid_rect(
            view->menuBox.x0 + 8,
            view->menuBox.y0 + 0x10,
            view->menuBox.x1,
            view->menuBox.y1 - 8,
            view->menuBox.r,
            view->menuBox.g,
            view->menuBox.b,
            (view->menuBox.a * view->menuBox.alpha) >> 7,
            0
        );
        lzss_draw_frame_overlay(&view->menuBox);
        sprite_flush_quads();
        sprite_clear_queue();

        for (i = 0; i < 6; i++) {
            bright = view->flags[i] ? 0x80 : 0x40;
            sprite_queue_sjis_text(
                (s16)(view->menuBox.x0 - 0x28),
                view->menuBox.y0 + 0x18 + i * 0x18,
                g_viewer_help_lines[i],
                0,
                0x18,
                0x18,
                (bright * view->menuBox.alpha) >> 7,
                0
            );
        }

        sprite_flush_rects();
        break;
    }

    return ret;
}

void viewer_init_image(GalleryView *viewer, SpriteInfo *image, const char *title)
{
    memset(viewer, 0, sizeof(GalleryView));

    viewer->tex = image;
    viewer->title = title;
    viewer->state = 1;
    viewer->timer = 0x80;
    viewer->flags[0] = 1;
    viewer->flags[1] = 1;
    viewer->flags[2] = 0;
    viewer->flags[3] = 0;
    viewer->flags[4] = 1;
    viewer->flags[5] = g_gallery->showHelp;
    viewer->zoomed = 0;

    if (viewer->title != 0) {
        viewer->titleBox.y0 = 0x10;
        viewer->titleBox.x0 = 0x10;
        viewer->titleBox.x1 = strlen(title) * 0x10 + 0x10;
        viewer->titleBox.y1 = 0x30;
        viewer->titleBox.r = 0x36;
        viewer->titleBox.g = 0xCD;
        viewer->titleBox.b = 0x18;
        viewer->titleBox.a = 0x25;
        viewer->titleBox.alpha = 0x80;
    }

    viewer->menuBox.x0 = 0x90;
    viewer->menuBox.x1 = 0x1F0;
    viewer->menuBox.y0 = 0x80;
    viewer->menuBox.y1 = 0x140;
    viewer->menuBox.r = 1;
    viewer->menuBox.g = 1;
    viewer->menuBox.b = 0x40;
    viewer->menuBox.a = 0x40;
    if (viewer->flags[5] != 0) {
        viewer->menuBox.alpha = 0x80;
    }

    viewer->dispW = viewer->tex->w;
    viewer->dispH = viewer->tex->h;
    if (viewer->dispW > 640 || viewer->dispH > 448) {
        f32 ratioX = (f32)viewer->dispW / 640.0f;
        f32 ratioY = (f32)viewer->dispH / 448.0f;

        if (ratioX > ratioY) {
            viewer->dispW = 640;
            viewer->dispH = (u32)((f32)viewer->dispH / ratioX);
            viewer->baseScale = (s32)(4096.0f / ratioX);
        } else {
            viewer->dispW = (u32)((f32)viewer->dispW / ratioY);
            viewer->dispH = 448;
            viewer->baseScale = (s32)(4096.0f / ratioY);
        }
        viewer->flags[3] = 1;
    }

    viewer->dispX = (640 - viewer->dispW) / 2;
    viewer->dispY = (448 - viewer->dispH) / 2;
    viewer->minX = 320 - viewer->tex->w / 2;
    viewer->minY = 224 - viewer->tex->h / 2;
    viewer->maxX = viewer->minX + viewer->tex->w;
    viewer->maxY = viewer->minY + viewer->tex->h;
    viewer->panX = 0;
    viewer->panY = 0;

    if (viewer->tex->w == 1024) {
        viewer->tex->w--;
    }
    if (viewer->tex->h == 1024) {
        viewer->tex->h--;
    }
}

s32 viewer_update_grid_cursor(void *menuPtr, void *inputPtr)
{
    GalleryMenuState *menu = menuPtr;
    GalleryMenuInput *input = inputPtr;
    s32 heldFrames;
    s32 buttonIndex;

    if (input->heldButtons == 0) {
        menu->heldFrames = 0;
    } else {
        menu->heldFrames++;
    }

    heldFrames = menu->heldFrames;
    if (heldFrames != 1) {
        if (heldFrames <= 20) {
            goto checkMovement;
        }
        if ((heldFrames & 3) != 0) {
            goto checkMovement;
        }
    }

    input->pressedButtons =
        (input->pressedButtons & 0x0FFF) | (input->heldButtons & 0xF000);

checkMovement:
    for (buttonIndex = 0; buttonIndex < 5; buttonIndex++) {
        if (menu->movementSteps[buttonIndex] != 0 &&
            (input->pressedButtons & g_menu_dir_buttons[buttonIndex]) != 0) {
            menu->selection += menu->movementSteps[buttonIndex];
            if (menu->selection < 0) {
                menu->selection += menu->selectionCount;
                return -1;
            }
            if (menu->selection >= menu->selectionCount) {
                menu->selection -= menu->selectionCount;
                return -1;
            }
            return 1;
        }
    }

    for (buttonIndex = 0; buttonIndex < 5; buttonIndex++) {
        if (menu->actionEnabled[buttonIndex] != 0 &&
            (input->pressedButtons & g_menu_action_buttons[buttonIndex]) != 0) {
            return buttonIndex + 0x100;
        }
    }

    return 0;
}

s32 g_dialog_anim_step;
s32 g_dialog_selection;
GalleryContext *g_gallery;
