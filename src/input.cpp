#include "raygl.h"
#include <windows.h>

static bool key_state[256] = { false };
static POINT mouse_pos = {0};
static bool mouse_button[5] = { false };
static int scroll_delta = 0;

void RayGL_PollEvents() {
    MSG msg;
    while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            RayGL_Quit();
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    GetCursorPos(&mouse_pos);
    ScreenToClient(GetForegroundWindow(), &mouse_pos);
}

bool RayGL_KeyDown(int keycode) {
    return GetAsyncKeyState(keycode) & 0x8000;
}

bool RayGL_KeyPressed(int keycode) {
    return false; // TODO: implement history
}

bool RayGL_KeyReleased(int keycode) {
    return false; // TODO
}

bool RayGL_MouseDown(int button) {
    if (button >= 0 && button < 5)
        return GetAsyncKeyState(VK_LBUTTON + button) & 0x8000;
    return false;
}

int RayGL_GetMouseX() {
    return mouse_pos.x;
}

int RayGL_GetMouseY() {
    return mouse_pos.y;
}

void RayGL_SetCursorVisible(bool visible) {
    ShowCursor(visible);
}

bool RayGL_KeyCombo(const char* combo) {
    return false; // TODO: custom combo detection
}

int RayGL_GetScrollDelta() {
    return scroll_delta;
}
