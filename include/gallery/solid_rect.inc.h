void gallery_draw_solid_rect(s32 xStart, s32 yStart, s32 xEnd, s32 yEnd,
                   s32 red, s32 green, s32 blue, s32 alpha, s32 blendMode)
{
    sceGifPacket packet;

    sceGifPkInit(&packet, g_gif_buf);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);

    if (blendMode == 0) {
        sceGifPkAddGsData(&packet, SCE_GS_SET_ALPHA(0, 1, 0, 1, 0));
    } else if (blendMode == 1) {
        sceGifPkAddGsData(&packet, SCE_GS_SET_ALPHA(0, 2, 0, 1, 0));
    } else {
        sceGifPkAddGsData(&packet, SCE_GS_SET_ALPHA(1, 0, 2, 2, 0x80));
    }

    sceGifPkAddGsData(&packet, SCE_GS_ALPHA_1);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 4));
    sceGifPkAddGsData(&packet, 0x5510ULL);
    sceGifPkAddGsData(&packet, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 0, 0, 1, 0, 1, 0, 0));
    sceGifPkAddGsData(&packet, SCE_GS_SET_RGBAQ(red, green, blue, alpha, 0x3F800000));
    sceGifPkAddGsData(&packet, SCE_GS_SET_XYZ2((s32)(((u32)xStart << 4) + 0x6C00U), (s32)(((u32)yStart << 3) + 0x7900U), 0));
    sceGifPkAddGsData(&packet, SCE_GS_SET_XYZ2((s32)(((u32)xEnd << 4) + 0x6C00U), (s32)(((u32)yEnd << 3) + 0x7900U), 0));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, g_gif_buf, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
