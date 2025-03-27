#include "raygl.h"
#include <cmath>
#include <stdint.h>

static uint32_t* framebuffer = nullptr;
static int fb_width = 800;
static int fb_height = 600;

void RayGL_SetFramebuffer(uint32_t* fb, int w, int h) {
    framebuffer = fb;
    fb_width = w;
    fb_height = h;
}

void RayGL_Clear(int r, int g, int b) {
    uint32_t color = (r << 16) | (g << 8) | b;
    for (int i = 0; i < fb_width * fb_height; ++i)
        framebuffer[i] = color;
}

void RayGL_SetPixel(int x, int y, int r, int g, int b) {
    if (x < 0 || y < 0 || x >= fb_width || y >= fb_height) return;
    framebuffer[y * fb_width + x] = (r << 16) | (g << 8) | b;
}

void RayGL_DrawRect(int x, int y, int w, int h, int r, int g, int b) {
    for (int i = 0; i < w; ++i)
        for (int j = 0; j < h; ++j)
            RayGL_SetPixel(x + i, y + j, r, g, b);
}

void RayGL_DrawLine(int x1, int y1, int x2, int y2, int r, int g, int b) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    while (true) {
        RayGL_SetPixel(x1, y1, r, g, b);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

void RayGL_DrawCircle(int x0, int y0, int radius, int r, int g, int b) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        RayGL_SetPixel(x0 + x, y0 + y, r, g, b);
        RayGL_SetPixel(x0 + y, y0 + x, r, g, b);
        RayGL_SetPixel(x0 - y, y0 + x, r, g, b);
        RayGL_SetPixel(x0 - x, y0 + y, r, g, b);
        RayGL_SetPixel(x0 - x, y0 - y, r, g, b);
        RayGL_SetPixel(x0 - y, y0 - x, r, g, b);
        RayGL_SetPixel(x0 + y, y0 - x, r, g, b);
        RayGL_SetPixel(x0 + x, y0 - y, r, g, b);
        y += 1;
        if (err <= 0) {
            err += 2 * y + 1;
        } else {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

void RayGL_DrawEllipse() {
    // TODO
}

void RayGL_DrawTriangle() {
    // TODO
}

void RayGL_FillRect() {
    // TODO
}

void RayGL_FillCircle() {
    // TODO
}

void RayGL_Present() {
    // handled by platform
}
