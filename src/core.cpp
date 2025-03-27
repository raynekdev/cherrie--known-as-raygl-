#include "raygl.h"
#include <windows.h>

static bool running = true;

bool RayGL_Init(int width, int height, const char* title) {
    // Tu sa bude volať inicializácia z winplatform.cpp
    return true;
}

void RayGL_Shutdown() {
    // Cleanup systémov
}

void RayGL_RunMainLoop() {
    while (RayGL_IsRunning()) {
        RayGL_Clear(30, 30, 30);
        RayGL_DrawRect(100, 100, 200, 150, 255, 0, 0);
        RayGL_DrawLine(0, 0, 799, 599, 0, 255, 0);
        RayGL_DrawCircle(400, 300, 50, 0, 0, 255);
        RayGL_Present();
        RayGL_Sleep(16); // ~60 FPS
    }
}

bool RayGL_IsRunning() {
    return running;
}

void RayGL_Quit() {
    running = false;
}

void RayGL_SetTitle(const char* title) {
    // SetWindowText(hwnd, title); - bude doplnené podľa platformy
}
