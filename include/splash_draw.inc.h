#ifndef DEATH_LABEL
void splash_image_draw(void) {
    if (g_splash_visible != 0) {
        g_quad_queue[0].x[0] = 0;
        g_quad_queue[0].z = 1;
        g_quad_queue[0].alpha = 0x80;
        g_quad_count = 1;
        g_quad_queue[0].tbp = 0x2240;
        g_quad_queue[0].cbp = 0x3836;
        g_quad_queue[0].color = 0x80;
        g_quad_queue[0].mode = 1;
        g_quad_queue[0].y[0] = 0;
        g_quad_queue[0].x[1] = 0x1C0;
        g_quad_queue[0].u[1] = 0x1C0;
        g_quad_queue[0].y[1] = 0xE0;
        g_quad_queue[0].v[1] = 0xE0;
        g_quad_queue[0].u[0] = 0;
        g_quad_queue[0].v[0] = 0;
        quad_flush();
    }
}
#endif
